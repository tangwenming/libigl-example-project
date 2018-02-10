////////////////////////////////////////////////////////////////////////////////
#include <imgui/imgui.h>
#include <vector>
#include <string>
////////////////////////////////////////////////////////////////////////////////

namespace ImGui {

static auto vector_getter = [](void* vec, int idx, const char** out_text) {
	auto& vector = *static_cast<std::vector<std::string>*>(vec);
	if (idx < 0 || idx >= static_cast<int>(vector.size())) { return false; }
	*out_text = vector.at(idx).c_str();
	return true;
};

inline bool Combo(const char* label, int* idx, std::vector<std::string>& values) {
	if (values.empty()) { return false; }
	return Combo(label, idx, vector_getter,
		static_cast<void*>(&values), values.size());
}

inline bool ListBox(const char* label, int* idx, std::vector<std::string>& values) {
	if (values.empty()) { return false; }
	return ListBox(label, idx, vector_getter,
		static_cast<void*>(&values), values.size());
}

} // namespace ImGui
