/**************************************************************************************/
//   Copyright (C) 2009-2012 Marilyn Dafa
//   This file is part of the "Overdrive Engine".
//   For conditions of distribution and use, see copyright notice in config.h
/**************************************************************************************/
#ifndef RADIO_H_INCLUDE
#define RADIO_H_INCLUDE
#include "Color.h"
#include "Texture.h"
#include "Font.h"
#include "Widget.h"
namespace o2d{
	class O2D_API c_radio:public c_widget
	{
	private:
		c_string m_normal_img;
		c_string m_pressed_img;
		c_string m_disable_img;
		c_rect m_nimg_rect[UC_NUM];
		c_rect m_pimg_rect[UC_NUM];
		c_rect m_dimg_rect[UC_NUM];
		c_rect m_nimg_zoom_region;
		c_rect m_pimg_zoom_region;
		c_rect m_dimg_zoom_region;
		c_string m_text;
		e_text_alignment m_v_align;
		e_text_alignment m_h_align;
		c_rect m_stencil_rect;
		c_string m_stencil_img;
		u32 m_txt_color;
		s32 m_state;
		bool m_enable;
	SIGNALS:
		c_signal<void , bool> _sig_state_change;
	public:
		c_radio(c_widget* parent_, const c_widget::s_widget_property& property_);
		virtual ~c_radio();
	public:
		inline bool is_enable() const {return m_enable;}
		inline bool is_pushed() const {return m_state == 1;}
		inline const c_string& get_normal_image() const {return m_normal_img;}
		inline const c_string& get_pressed_image() const {return m_pressed_img;}
		inline const c_string& get_disable_image() const {return m_disable_img;}
		inline const c_string& get_text() const {return m_text;}
		inline u32 get_text_clr() const {return m_txt_color;}
		inline e_text_alignment get_text_valign() const {return m_v_align;}
		inline e_text_alignment get_text_halign() const {return m_h_align;}
	public:
		void set_enable(bool enable_);
		void set_pushed(bool pushed_);
		void set_text(const c_string& str_);
		void set_text_color(const c_color& color_);
		void set_text_align(e_text_alignment ha_, e_text_alignment va_);
		void set_normal_image(const c_string& name_);
		void set_pressed_image(const c_string& name_);
		void set_disable_image(const c_string& name_);
		void set_nor_fragment(const c_float2& anc_, const c_float2& dim_);
		void set_pre_fragment(const c_float2& anc_, const c_float2& dim_);
		void set_dis_fragment(const c_float2& anc_, const c_float2& dim_);
		void set_stencil_image(const c_string& img_);
	protected:
		void _zoom_update(const c_float2& v1_, const c_float2& v2_);
		void _on_touch_start();
		void _on_touch_finish();
		void _redraw();
	};
}
#endif