#pragma once

////////////////////////////////////////////////////////////////////////////////
#include <igl/viewer/Viewer.h>
#include <igl/viewer/ViewerPlugin.h>
#include <igl/igl_inline.h>
////////////////////////////////////////////////////////////////////////////////

class ImGuiMenu : public igl::viewer::ViewerPlugin {
protected:
	// Hidpi scaling to be used for text rendering.
	float m_HidpiScaling;

	// Ratio between the framebuffer size and the window size.
	// May be different from the hipdi scaling!
	float m_PixelRatio;

public:
	IGL_INLINE virtual void init(igl::viewer::Viewer *_viewer) override;

	IGL_INLINE virtual void reload_font(int font_size = 13);

	IGL_INLINE virtual void shutdown() override;

	IGL_INLINE virtual bool pre_draw() override;

	IGL_INLINE	virtual bool post_draw() override;

	IGL_INLINE virtual void post_resize(int width, int height) override;

	// Mouse IO
	IGL_INLINE virtual bool mouse_down(int button, int modifier) override;

	IGL_INLINE virtual bool mouse_up(int button, int modifier) override;

	IGL_INLINE virtual bool mouse_move(int mouse_x, int mouse_y) override;

	IGL_INLINE virtual bool mouse_scroll(float delta_y) override;

	// Keyboard IO
	IGL_INLINE virtual bool key_pressed(unsigned int key, int modifiers) override;

	IGL_INLINE virtual bool key_down(int key, int modifiers) override;

	IGL_INLINE virtual bool key_up(int key, int modifiers) override;

	// Draw menu
	IGL_INLINE virtual void draw_menu();

	IGL_INLINE void draw_viewer_menu();

	IGL_INLINE void draw_labels_menu();

	IGL_INLINE void draw_labels();

	IGL_INLINE void draw_text(Eigen::Vector3d pos, Eigen::Vector3d normal, const std::string &text);

	IGL_INLINE float pixel_ratio();

	IGL_INLINE float hidpi_scaling();

	float menu_scaling() { return m_HidpiScaling / m_PixelRatio; }
};

#ifndef IGL_STATIC_LIBRARY
#  include "ImGuiMenu.cpp"
#endif
