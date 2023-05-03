#include "mk_win_user_dialog.h"

#include "mk_lang_assert.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_base.h"
#include "mk_win_gdi.h"
#include "mk_win_gdi_font.h"
#include "mk_win_tstring.h"
#include "mk_win_unicode_api.h"
#include "mk_win_user_message.h"
#include "mk_win_user_window.h"



union mk_win_user_dialog_fonts_u
{
	mk_win_gdi_font_a_t m_a;
	mk_win_gdi_font_w_t m_w;
};
typedef union mk_win_user_dialog_fonts_u mk_win_user_dialog_fonts_t;
typedef mk_win_base_sintptr_t(mk_win_base_stdcall*mk_win_user_dialog_dlgproc_t)(mk_win_user_window_t, mk_win_base_uint_t, mk_win_user_window_wparam_t, mk_win_user_window_lparam_t) mk_lang_noexcept;


mk_win_base_dll_import mk_win_base_sintptr_t mk_win_base_stdcall DialogBoxIndirectParamA(mk_win_base_instance_t, mk_win_user_dialog_dlg_template_lpct, mk_win_user_window_t, mk_win_user_dialog_dlgproc_t, mk_win_user_window_lparam_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_sintptr_t mk_win_base_stdcall DialogBoxIndirectParamW(mk_win_base_instance_t, mk_win_user_dialog_dlg_template_lpct, mk_win_user_window_t, mk_win_user_dialog_dlgproc_t, mk_win_user_window_lparam_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_user_window_lresult_t mk_win_base_stdcall DefDlgProcW(mk_win_user_window_t, mk_win_base_uint_t, mk_win_user_window_wparam_t, mk_win_user_window_lparam_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall EndDialog(mk_win_user_window_t, mk_win_base_sintptr_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_user_window_t mk_win_base_stdcall GetDlgItem(mk_win_user_window_t, int) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetWindowRect(mk_win_user_window_t, mk_win_base_rect_lpt) mk_lang_noexcept;


mk_win_user_dialog_fonts_t g_mk_win_user_dialog_fonts;


static mk_lang_inline void* mk_win_user_dialog_round_up_s(void const* ptr, mk_win_base_size_t const size) mk_lang_noexcept;
static mk_lang_inline void* mk_win_user_dialog_round_up_i(void const* ptr, int const size) mk_lang_noexcept;
static mk_lang_inline void mk_win_user_dialog_get_font(mk_win_user_window_t const dialog);
static mk_win_base_sintptr_t mk_win_base_stdcall mk_win_user_dialog_dlgproc(mk_win_user_window_t const dialog, mk_win_base_uint_t const msg_uid, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_sintptr_t mk_win_user_dialog_a_indirect_param(mk_win_base_instance_t const instance, mk_win_user_dialog_dlg_template_lpct const dlg, mk_win_user_window_t const parent, mk_win_user_dialog_dlgproc_t const proc, mk_win_user_window_lparam_t const param) mk_lang_noexcept
{
	mk_win_base_sintptr_t res;

	res = DialogBoxIndirectParamA(instance, dlg, parent, proc, param);
	return res;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sintptr_t mk_win_user_dialog_a_indirect_param_ex(mk_win_base_instance_t const instance, mk_win_user_dialog_dlg_templateex_lpct const dlg, mk_win_user_window_t const parent, mk_win_user_dialog_dlgproc_t const proc, mk_win_user_window_lparam_t const param) mk_lang_noexcept
{
	mk_win_base_sintptr_t res;

	res = DialogBoxIndirectParamA(instance, ((mk_win_user_dialog_dlg_template_lpct)(dlg)), parent, proc, param);
	return res;
}


mk_lang_nodiscard mk_lang_jumbo mk_win_base_sintptr_t mk_win_user_dialog_w_indirect_param(mk_win_base_instance_t const instance, mk_win_user_dialog_dlg_template_lpct const dlg, mk_win_user_window_t const parent, mk_win_user_dialog_dlgproc_t const proc, mk_win_user_window_lparam_t const param) mk_lang_noexcept
{
	mk_win_base_sintptr_t res;

	res = DialogBoxIndirectParamW(instance, dlg, parent, proc, param);
	return res;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sintptr_t mk_win_user_dialog_w_indirect_param_ex(mk_win_base_instance_t const instance, mk_win_user_dialog_dlg_templateex_lpct const dlg, mk_win_user_window_t const parent, mk_win_user_dialog_dlgproc_t const proc, mk_win_user_window_lparam_t const param) mk_lang_noexcept
{
	mk_win_base_sintptr_t res;

	res = DialogBoxIndirectParamW(instance, ((mk_win_user_dialog_dlg_template_lpct)(dlg)), parent, proc, param);
	return res;
}


mk_lang_nodiscard mk_lang_jumbo mk_win_base_sintptr_t mk_win_user_dialog_t_indirect_param(mk_win_base_instance_t const instance, mk_win_user_dialog_dlg_template_lpct const dlg, mk_win_user_window_t const parent, mk_win_user_dialog_dlgproc_t const proc, mk_win_user_window_lparam_t const param) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_dialog_a_indirect_param(instance, dlg, parent, proc, param);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_user_dialog_a_indirect_param(instance, dlg, parent, proc, param);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_dialog_w_indirect_param(instance, dlg, parent, proc, param);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_user_dialog_w_indirect_param(instance, dlg, parent, proc, param);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_dialog_a_indirect_param(instance, dlg, parent, proc, param);
		#else
			return mk_win_user_dialog_a_indirect_param(instance, dlg, parent, proc, param);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_dialog_w_indirect_param(instance, dlg, parent, proc, param);
		#else
			return mk_win_user_dialog_w_indirect_param(instance, dlg, parent, proc, param);
		#endif
	}
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sintptr_t mk_win_user_dialog_t_indirect_param_ex(mk_win_base_instance_t const instance, mk_win_user_dialog_dlg_templateex_lpct const dlg, mk_win_user_window_t const parent, mk_win_user_dialog_dlgproc_t const proc, mk_win_user_window_lparam_t const param) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_dialog_a_indirect_param_ex(instance, dlg, parent, proc, param);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_user_dialog_a_indirect_param_ex(instance, dlg, parent, proc, param);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_dialog_w_indirect_param_ex(instance, dlg, parent, proc, param);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_user_dialog_w_indirect_param_ex(instance, dlg, parent, proc, param);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_dialog_a_indirect_param_ex(instance, dlg, parent, proc, param);
		#else
			return mk_win_user_dialog_a_indirect_param_ex(instance, dlg, parent, proc, param);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_dialog_w_indirect_param_ex(instance, dlg, parent, proc, param);
		#else
			return mk_win_user_dialog_w_indirect_param_ex(instance, dlg, parent, proc, param);
		#endif
	}
#endif
}


mk_lang_jumbo mk_win_base_bool_t mk_win_user_dialog_end(mk_win_user_window_t const dialog, mk_win_base_sintptr_t const result) mk_lang_noexcept
{
	mk_win_base_bool_t ended;

	ended = EndDialog(dialog, result);
	return ended;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_window_t mk_win_user_dialog_get_item(mk_win_user_window_t const dialog, int const ctrl_id) mk_lang_noexcept
{
	mk_win_user_window_t ctrl;

	ctrl = GetDlgItem(dialog, ctrl_id);
	return ctrl;
}



mk_lang_jumbo mk_win_user_dialog_two_ints_t mk_win_user_dialog_get_ctrl_size_any(mk_win_base_instance_t const instance, mk_win_base_word_t const ctrl_type, signed short int const width, signed short int const height) mk_lang_noexcept
{
	static mk_win_base_wchar_t const s_dlg_title[] = {0x0061, 0x0062, 0x0063, 0x0000}; /* L"abc" */
	static int const s_dlg_title_len = ((int)(sizeof(s_dlg_title) / sizeof(s_dlg_title[0])));
	static mk_win_base_wchar_t const s_ctrl_title[] = {0x0061, 0x0062, 0x0063, 0x0000}; /* L"abc" */
	static int const s_ctrl_title_len = ((int)(sizeof(s_ctrl_title) / sizeof(s_ctrl_title[0])));

	unsigned char template_buffer[1024];
	mk_win_user_dialog_dlg_template_pt dlg;
	mk_win_base_word_pt menu;
	mk_win_base_word_pt klass;
	mk_win_base_wchar_pt title;
	mk_win_user_dialog_itm_template_pt ctrl;
	mk_win_base_word_pt ctrl_atom;
	mk_win_base_word_pt ctrl_class;
	mk_win_base_wchar_pt ctrl_title;
	mk_win_base_word_pt ctrl_data;
	int i;
	mk_win_base_sintptr_t created;
	mk_win_user_dialog_two_ints_t ret;

	mk_lang_assert(instance);
	mk_lang_assert(width > 0);
	mk_lang_assert(height > 0);

	dlg = ((mk_win_user_dialog_dlg_template_pt)(mk_win_user_dialog_round_up_s(template_buffer, sizeof(mk_win_base_dword_t))));
	menu = ((mk_win_base_word_pt)(mk_win_user_dialog_round_up_s(dlg + 1, sizeof(mk_win_base_word_t))));
	klass = ((mk_win_base_word_pt)(mk_win_user_dialog_round_up_s(menu + 1, sizeof(mk_win_base_word_t))));
	title = ((mk_win_base_wchar_pt)(mk_win_user_dialog_round_up_s(klass + 1, sizeof(mk_win_base_wchar_t))));
	ctrl = ((mk_win_user_dialog_itm_template_pt)(mk_win_user_dialog_round_up_s(title + s_dlg_title_len, sizeof(mk_win_base_dword_t))));
	ctrl_atom = ((mk_win_base_word_pt)(mk_win_user_dialog_round_up_s(ctrl + 1, sizeof(mk_win_base_word_t))));
	ctrl_class = ((mk_win_base_word_pt)(mk_win_user_dialog_round_up_s(ctrl_atom + 1, sizeof(mk_win_base_word_t))));
	ctrl_title = ((mk_win_base_wchar_pt)(mk_win_user_dialog_round_up_s(ctrl_class + 1, sizeof(mk_win_base_wchar_t))));
	ctrl_data = ((mk_win_base_word_pt)(mk_win_user_dialog_round_up_s(ctrl_title + s_ctrl_title_len, sizeof(mk_win_base_word_t))));
	dlg->m_style = mk_win_user_window_style_e_overlappedwindow;
	dlg->m_style_ex = 0;
	dlg->m_count = 1;
	dlg->m_left = 10;
	dlg->m_top = 10;
	dlg->m_width = 100;
	dlg->m_height = 100;
	*menu = 0;
	*klass = 0;
	for(i = 0; i != s_dlg_title_len; ++i) title[i] = s_dlg_title[i];
	ctrl->m_style = mk_win_user_window_style_e_visible | mk_win_user_window_style_e_child;
	ctrl->m_style_ex = 0;
	ctrl->m_left = mk_win_user_dialog_space_dlg_margin;
	ctrl->m_top = mk_win_user_dialog_space_dlg_margin;
	ctrl->m_width = width;
	ctrl->m_height = height;
	ctrl->m_id = 0;
	*ctrl_atom = mk_win_user_dialog_class_is_atom;
	*ctrl_class = ctrl_type;
	for(i = 0; i != s_ctrl_title_len; ++i) ctrl_title[i] = s_ctrl_title[i];
	*ctrl_data = 0;
	created = DialogBoxIndirectParamW(instance, dlg, mk_win_base_null, &mk_win_user_dialog_dlgproc, 0);
	ret.m_a = ((int)(((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(created)) >> 16)) & ((mk_win_base_uintptr_t)(0xfffful))))));
	ret.m_b = ((int)(((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(created)) >>  0)) & ((mk_win_base_uintptr_t)(0xfffful))))));
	return ret;
}

mk_lang_jumbo mk_win_user_dialog_two_ints_t mk_win_user_dialog_get_ctrl_size_anyex(mk_win_base_instance_t const instance, mk_win_base_word_t const ctrl_type, signed short int const width, signed short int const height) mk_lang_noexcept
{
	static mk_win_base_wchar_t const s_msshelldlg[] = L"MS Shell Dlg";
	static int const s_msshelldlg_len = ((int)(sizeof(s_msshelldlg) / sizeof(s_msshelldlg[0])));

	unsigned char template_buffer[1024];
	mk_win_user_dialog_dlg_templateex_pt dlg;
	int i;
	mk_win_user_dialog_itm_templateex_pt ctrl;
	mk_win_base_sintptr_t created;
	mk_win_user_dialog_two_ints_t ret;

	mk_lang_assert(instance);
	mk_lang_assert(width > 0);
	mk_lang_assert(height > 0);

	dlg = ((mk_win_user_dialog_dlg_templateex_pt)(mk_win_user_dialog_round_up_s(template_buffer, sizeof(mk_win_base_dword_t))));
	ctrl = ((mk_win_user_dialog_itm_templateex_pt)(mk_win_user_dialog_round_up_s(((mk_win_base_wchar_pct)(dlg + 1)) + (s_msshelldlg_len - 1), sizeof(mk_win_base_dword_t))));
	dlg->m_version = 1;
	dlg->m_signature = 0xffff;
  dlg->m_help_id = 0;
  dlg->m_style_ex = 0;
  dlg->m_style = mk_win_user_dialog_style_e_shellfont | mk_win_user_window_style_e_overlappedwindow;
  dlg->m_count = 1;
  dlg->m_x = 100;
  dlg->m_y = 200;
  dlg->m_width = 300;
  dlg->m_height = 400;
  dlg->m_menu = 0;
  dlg->m_class = 0;
  dlg->m_title = 0;
  dlg->m_point_size = 8;
  dlg->m_weight = mk_win_user_dialog_font_weight_e_normal;
  dlg->m_italic = 0;
  dlg->m_charset = mk_win_user_dialog_font_charset_e_default;
  for(i = 0; i != s_msshelldlg_len; ++i) (&(dlg->m_typeface))[i] = s_msshelldlg[i];
  ctrl->m_help_id = 0;
	ctrl->m_style_ex = 0;
	ctrl->m_style = mk_win_user_window_style_e_visible | mk_win_user_window_style_e_child;
	ctrl->m_left = mk_win_user_dialog_space_dlg_margin;
	ctrl->m_top = mk_win_user_dialog_space_dlg_margin;
	ctrl->m_width = width;
	ctrl->m_height = height;
	ctrl->m_id = 0;
	ctrl->m_class[0] = mk_win_user_dialog_class_is_atom;
	ctrl->m_class[1] = ctrl_type;
	ctrl->m_title = 0;
	ctrl->m_extra_count = 0;
	created = DialogBoxIndirectParamW(instance, ((mk_win_user_dialog_dlg_template_pt)(dlg)), mk_win_base_null, &mk_win_user_dialog_dlgproc, 0);
	ret.m_a = ((int)(((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(created)) >> 16)) & ((mk_win_base_uintptr_t)(0xfffful))))));
	ret.m_b = ((int)(((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(created)) >>  0)) & ((mk_win_base_uintptr_t)(0xfffful))))));
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpct mk_win_user_dialog_get_ctrl_font(void) mk_lang_noexcept
{
	mk_lang_assert(g_mk_win_user_dialog_fonts.m_w.m_facename[0] != L'\0');

	return &g_mk_win_user_dialog_fonts; /* todo better api */
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_dialog_two_ints_t mk_win_user_dialog_get_ctrl_size_margins(mk_win_base_instance_t const instance) mk_lang_noexcept
{
	return mk_win_user_dialog_get_ctrl_size_anyex(instance, mk_win_user_dialog_class_id_button, mk_win_user_dialog_space_dlg_margin, mk_win_user_dialog_space_dlg_margin);
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_dialog_two_ints_t mk_win_user_dialog_get_ctrl_size_related_unrelated(mk_win_base_instance_t const instance) mk_lang_noexcept
{
	return mk_win_user_dialog_get_ctrl_size_anyex(instance, mk_win_user_dialog_class_id_button, mk_win_user_dialog_space_related_ctrl, mk_win_user_dialog_space_unrelated_ctrl);
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_dialog_two_ints_t mk_win_user_dialog_get_ctrl_size_button(mk_win_base_instance_t const instance) mk_lang_noexcept
{
	return mk_win_user_dialog_get_ctrl_size_anyex(instance, mk_win_user_dialog_class_id_button, mk_win_user_dialog_size_button_w, mk_win_user_dialog_size_button_h);
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_dialog_two_ints_t mk_win_user_dialog_get_ctrl_size_edit(mk_win_base_instance_t const instance) mk_lang_noexcept
{
	return mk_win_user_dialog_get_ctrl_size_anyex(instance, mk_win_user_dialog_class_id_edit, mk_win_user_dialog_size_button_w, mk_win_user_dialog_size_edit1_h);
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_dialog_two_ints_t mk_win_user_dialog_get_ctrl_size_static(mk_win_base_instance_t const instance) mk_lang_noexcept
{
	return mk_win_user_dialog_get_ctrl_size_anyex(instance, mk_win_user_dialog_class_id_static, mk_win_user_dialog_size_button_w, mk_win_user_dialog_size_static_h);
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_dialog_two_ints_t mk_win_user_dialog_get_ctrl_size_progressbar(mk_win_base_instance_t const instance) mk_lang_noexcept
{
	return mk_win_user_dialog_get_ctrl_size_anyex(instance, mk_win_user_dialog_class_id_button, mk_win_user_dialog_size_progressa_w, mk_win_user_dialog_size_progress_h);
}


static mk_lang_inline void* mk_win_user_dialog_round_up_s(void const* ptr, mk_win_base_size_t const size) mk_lang_noexcept
{
	mk_lang_assert(ptr);
	mk_lang_assert(size > 0);

	return ((void*)(((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(((unsigned char const*)(ptr)))) + ((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(size)) - ((mk_win_base_uintptr_t)(1)))))) / ((mk_win_base_uintptr_t)(size)))) * ((mk_win_base_uintptr_t)(size))))));
}

static mk_lang_inline void* mk_win_user_dialog_round_up_i(void const* ptr, int const size) mk_lang_noexcept
{
	mk_lang_assert(ptr);
	mk_lang_assert(size > 0);

	return ((void*)(((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(((unsigned char const*)(ptr)))) + ((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(size)) - ((mk_win_base_uintptr_t)(1)))))) / ((mk_win_base_uintptr_t)(size)))) * ((mk_win_base_uintptr_t)(size))))));
}

static mk_lang_inline void mk_win_user_dialog_get_font(mk_win_user_window_t const dialog)
{
	mk_win_user_window_lresult_t font;
	mk_win_base_void_lpt output;
	int size_in;
	int size_out;

	mk_lang_assert(dialog);

	if(g_mk_win_user_dialog_fonts.m_w.m_facename[0] != L'\0')
	{
		return;
	}
	font = mk_win_user_message_t_send(dialog, mk_win_user_message_id_e_getfont, 0, 0);
	if(font == 0)
	{
		return;
	}
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	output = &g_mk_win_user_dialog_fonts.m_a;
	size_in = sizeof(g_mk_win_user_dialog_fonts.m_a);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	output = &g_mk_win_user_dialog_fonts.m_a;
	size_in = sizeof(g_mk_win_user_dialog_fonts.m_a);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	output = &g_mk_win_user_dialog_fonts.m_w;
	size_in = sizeof(g_mk_win_user_dialog_fonts.m_w);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	output = &g_mk_win_user_dialog_fonts.m_w;
	size_in = sizeof(g_mk_win_user_dialog_fonts.m_w);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			output = &g_mk_win_user_dialog_fonts.m_a;
			size_in = sizeof(g_mk_win_user_dialog_fonts.m_a);
		#else
			output = &g_mk_win_user_dialog_fonts.m_a;
			size_in = sizeof(g_mk_win_user_dialog_fonts.m_a);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			output = &g_mk_win_user_dialog_fonts.m_w;
			size_in = sizeof(g_mk_win_user_dialog_fonts.m_w);
		#else
			output = &g_mk_win_user_dialog_fonts.m_w;
			size_in = sizeof(g_mk_win_user_dialog_fonts.m_w);
		#endif
	}
#endif
	size_out = mk_win_gdi_t_get_object(((mk_win_base_handle_t)(font)), size_in, output);
	mk_lang_assert(size_out != 0);
	mk_lang_assert(size_out <= size_in);
}

static mk_win_base_sintptr_t mk_win_base_stdcall mk_win_user_dialog_dlgproc(mk_win_user_window_t const dialog, mk_win_base_uint_t const msg_uid, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept
{
	mk_win_user_message_id_t msg_id;
	mk_win_user_window_t ctrl;
	mk_win_base_bool_t got;
	mk_win_base_rect_t rect;
	mk_win_base_sintptr_t end;
	mk_win_base_bool_t ended;
	mk_win_base_sintptr_t ret;

	mk_lang_assert(dialog);
	((void)(wparam));
	((void)(lparam));

	msg_id = ((mk_win_user_message_id_t)(msg_uid));
	if(msg_id == mk_win_user_message_id_e_initdialog)
	{
		ctrl = GetDlgItem(dialog, 0);
		mk_lang_assert(ctrl);
		got = GetWindowRect(ctrl, &rect);
		mk_lang_assert(got != 0);
		end =
			((mk_win_base_sintptr_t)
			(
				((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(rect.m_right - rect.m_left)) & ((mk_win_base_uintptr_t)(0xfffful)))) << 16)) |
				((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(rect.m_bottom - rect.m_top)) & ((mk_win_base_uintptr_t)(0xfffful)))) <<  0))
			));
		mk_win_user_dialog_get_font(dialog);
		ended = EndDialog(dialog, end);
		mk_lang_assert(ended != 0);
	}
	ret = 0;
	return ret;
}
