#include "mk_win_user_window.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"
#include "mk_win_base.h"
#include "mk_win_gdi_dc.h"
#include "mk_win_kernel_atom.h"
#include "mk_win_sal.h"
#include "mk_win_tstring.h"
#include "mk_win_unicode_api.h"
#include "mk_win_user_menu.h"


mk_win_base_dll_import mk_win_user_window_t mk_win_base_stdcall CreateWindowExA(mk_win_base_dword_t, mk_win_base_pchar_lpct, mk_win_base_pchar_lpct, mk_win_base_dword_t, int, int, int, int, mk_win_user_window_t, mk_win_user_menu_t, mk_win_base_instance_t, mk_win_base_void_lpt) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_uintptr_t mk_win_base_stdcall SetWindowLongA(mk_win_user_window_t, int, mk_win_base_uintptr_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_uintptr_t mk_win_base_stdcall SetWindowLongPtrA(mk_win_user_window_t, int, mk_win_base_uintptr_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_uintptr_t mk_win_base_stdcall GetWindowLongA(mk_win_user_window_t, int) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_uintptr_t mk_win_base_stdcall GetWindowLongPtrA(mk_win_user_window_t, int) mk_lang_noexcept;
mk_win_base_dll_import mk_win_user_window_lresult_t mk_win_base_stdcall DefWindowProcA(mk_win_user_window_t, mk_win_base_uint_t, mk_win_user_window_wparam_t, mk_win_user_window_lparam_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall PostMessageA(mk_win_user_window_t, mk_win_base_uint_t, mk_win_user_window_wparam_t, mk_win_user_window_lparam_t) mk_lang_noexcept;
mk_win_base_dll_import int mk_win_base_stdcall GetWindowTextA(mk_win_user_window_t, mk_win_base_pchar_lpt, int) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SetWindowTextA(mk_win_user_window_t, mk_win_base_pchar_lpct) mk_lang_noexcept;
mk_win_base_dll_import mk_win_user_window_lresult_t mk_win_base_stdcall CallWindowProcA(mk_win_user_window_wndproc_t, mk_win_user_window_t, mk_win_base_uint_t, mk_win_user_window_wparam_t, mk_win_user_window_lparam_t) mk_lang_noexcept;

mk_win_base_dll_import mk_win_user_window_t mk_win_base_stdcall CreateWindowExW(mk_win_base_dword_t, mk_win_base_wchar_lpct, mk_win_base_wchar_lpct, mk_win_base_dword_t, int, int, int, int, mk_win_user_window_t, mk_win_user_menu_t, mk_win_base_instance_t, mk_win_base_void_lpt) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_uintptr_t mk_win_base_stdcall SetWindowLongW(mk_win_user_window_t, int, mk_win_base_uintptr_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_uintptr_t mk_win_base_stdcall SetWindowLongPtrW(mk_win_user_window_t, int, mk_win_base_uintptr_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_uintptr_t mk_win_base_stdcall GetWindowLongW(mk_win_user_window_t, int) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_uintptr_t mk_win_base_stdcall GetWindowLongPtrW(mk_win_user_window_t, int) mk_lang_noexcept;
mk_win_base_dll_import mk_win_user_window_lresult_t mk_win_base_stdcall DefWindowProcW(mk_win_user_window_t, mk_win_base_uint_t, mk_win_user_window_wparam_t, mk_win_user_window_lparam_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall PostMessageW(mk_win_user_window_t, mk_win_base_uint_t, mk_win_user_window_wparam_t, mk_win_user_window_lparam_t) mk_lang_noexcept;
mk_win_base_dll_import int mk_win_base_stdcall GetWindowTextW(mk_win_user_window_t, mk_win_base_wchar_lpt, int) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SetWindowTextW(mk_win_user_window_t, mk_win_base_wchar_lpct) mk_lang_noexcept;
mk_win_base_dll_import mk_win_user_window_lresult_t mk_win_base_stdcall CallWindowProcW(mk_win_user_window_wndproc_t, mk_win_user_window_t, mk_win_base_uint_t, mk_win_user_window_wparam_t, mk_win_user_window_lparam_t) mk_lang_noexcept;

mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall ShowWindow(mk_win_user_window_t, int) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall UpdateWindow(mk_win_user_window_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetClientRect(mk_win_user_window_t, mk_win_base_rect_lpt) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetWindowRect(mk_win_user_window_t, mk_win_base_rect_lpt) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SetWindowPos(mk_win_user_window_t, mk_win_user_window_t, int, int, int, int, mk_win_base_uint_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_gdi_dc_t mk_win_base_stdcall BeginPaint(mk_win_user_window_t, mk_win_user_window_paint_lpt) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall EndPaint(mk_win_user_window_t, mk_win_user_window_paint_lpct) mk_lang_noexcept;
mk_win_base_dll_import mk_win_user_window_t mk_win_base_stdcall SetFocus(mk_win_user_window_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_user_window_t mk_win_base_stdcall GetParent(mk_win_user_window_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall ShowScrollBar(mk_win_user_window_t, int, mk_win_base_bool_t) mk_lang_noexcept;

mk_win_base_dll_import mk_win_user_window_t mk_win_base_stdcall GetDesktopWindow(void) mk_lang_noexcept;


mk_lang_jumbo mk_win_user_window_t mk_win_user_window_a_create_by_name(mk_win_base_dword_t const style_ex, mk_win_base_pchar_lpct const class_name, mk_win_base_pchar_lpct const window_name, mk_win_base_dword_t const style, int const x, int const y, int const width, int const height, mk_win_user_window_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept
{
	mk_win_user_window_t window;

	window = CreateWindowExA(style_ex, class_name, window_name, style, x, y, width, height, parent, menu, instance, param);
	return window;
}

mk_lang_jumbo mk_win_user_window_t mk_win_user_window_a_create_by_atom(mk_win_base_dword_t const style_ex, mk_win_kernel_atom_t const atom, mk_win_base_pchar_lpct const window_name, mk_win_base_dword_t const style, int const x, int const y, int const width, int const height, mk_win_user_window_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept
{
	return mk_win_user_window_a_create_by_name(style_ex, ((mk_win_base_pchar_lpct)(((mk_win_base_uintptr_t)(atom)))), window_name, style, x, y, width, height, parent, menu, instance, param);
}

mk_lang_jumbo mk_win_base_uintptr_t mk_win_user_window_a_set_data(mk_win_user_window_t const window, mk_win_user_window_data_idx_t const idx, mk_win_base_uintptr_t const new_data) mk_lang_noexcept
{
	mk_win_base_uintptr_t old_data;

	mk_lang_assert(window);

	#if mk_win_base_arch == mk_win_base_arch_32
	old_data = SetWindowLongA(window, ((int)(idx)), new_data);
	#elif mk_win_base_arch == mk_win_base_arch_64
	old_data = SetWindowLongPtrA(window, ((int)(idx)), new_data);
	#endif
	return old_data;
}

mk_lang_jumbo mk_win_base_uintptr_t mk_win_user_window_a_get_data(mk_win_user_window_t const window, mk_win_user_window_data_idx_t const idx) mk_lang_noexcept
{
	mk_win_base_uintptr_t data;

	mk_lang_assert(window);

	#if mk_win_base_arch == mk_win_base_arch_32
	data = GetWindowLongA(window, ((int)(idx)));
	#elif mk_win_base_arch == mk_win_base_arch_64
	data = GetWindowLongPtrA(window, ((int)(idx)));
	#endif
	return data;
}

mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_window_a_defproc(mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept
{
	mk_win_user_window_lresult_t lres;

	lres = DefWindowProcA(window, message, wparam, lparam);
	return lres;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_a_post(mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept
{
	mk_win_base_bool_t posted;

	posted = PostMessageA(window, message, wparam, lparam);
	return posted;
}

mk_lang_jumbo int mk_win_user_window_a_get_text(mk_win_user_window_t const window, mk_win_base_pchar_lpt const text, int const max_len) mk_lang_noexcept
{
	int len;

	len = GetWindowTextA(window, text, max_len);
	return len;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_a_set_text(mk_win_user_window_t const window, mk_win_base_pchar_lpct const text) mk_lang_noexcept
{
	mk_win_base_bool_t set;

	set = SetWindowTextA(window, text);
	return set;
}

mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_window_a_call_proc(mk_win_user_window_wndproc_t const proc, mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept
{
	mk_win_user_window_lresult_t lres;

	lres = CallWindowProcA(proc, window, message, wparam, lparam);
	return lres;
}


mk_lang_jumbo mk_win_user_window_t mk_win_user_window_w_create_by_name(mk_win_base_dword_t const style_ex, mk_win_base_wchar_lpct const class_name, mk_win_base_wchar_lpct const window_name, mk_win_base_dword_t const style, int const x, int const y, int const width, int const height, mk_win_user_window_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept
{
	mk_win_user_window_t window;

	window = CreateWindowExW(style_ex, class_name, window_name, style, x, y, width, height, parent, menu, instance, param);
	return window;
}

mk_lang_jumbo mk_win_user_window_t mk_win_user_window_w_create_by_atom(mk_win_base_dword_t const style_ex, mk_win_kernel_atom_t const atom, mk_win_base_wchar_lpct const window_name, mk_win_base_dword_t const style, int const x, int const y, int const width, int const height, mk_win_user_window_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept
{
	return mk_win_user_window_w_create_by_name(style_ex, ((mk_win_base_wchar_lpct)(((mk_win_base_uintptr_t)(atom)))), window_name, style, x, y, width, height, parent, menu, instance, param);
}

mk_lang_jumbo mk_win_base_uintptr_t mk_win_user_window_w_set_data(mk_win_user_window_t const window, mk_win_user_window_data_idx_t const idx, mk_win_base_uintptr_t const new_data) mk_lang_noexcept
{
	mk_win_base_uintptr_t old_data;

	mk_lang_assert(window);

	#if mk_win_base_arch == mk_win_base_arch_32
	old_data = SetWindowLongW(window, ((int)(idx)), new_data);
	#elif mk_win_base_arch == mk_win_base_arch_64
	old_data = SetWindowLongPtrW(window, ((int)(idx)), new_data);
	#endif
	return old_data;
}

mk_lang_jumbo mk_win_base_uintptr_t mk_win_user_window_w_get_data(mk_win_user_window_t const window, mk_win_user_window_data_idx_t const idx) mk_lang_noexcept
{
	mk_win_base_uintptr_t data;

	mk_lang_assert(window);

	#if mk_win_base_arch == mk_win_base_arch_32
	data = GetWindowLongW(window, ((int)(idx)));
	#elif mk_win_base_arch == mk_win_base_arch_64
	data = GetWindowLongPtrW(window, ((int)(idx)));
	#endif
	return data;
}

mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_window_w_defproc(mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept
{
	mk_win_user_window_lresult_t lres;

	lres = DefWindowProcW(window, message, wparam, lparam);
	return lres;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_w_post(mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept
{
	mk_win_base_bool_t posted;

	posted = PostMessageW(window, message, wparam, lparam);
	return posted;
}

mk_lang_jumbo int mk_win_user_window_w_get_text(mk_win_user_window_t const window, mk_win_base_wchar_lpt const text, int const max_len) mk_lang_noexcept
{
	int len;

	len = GetWindowTextW(window, text, max_len);
	return len;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_w_set_text(mk_win_user_window_t const window, mk_win_base_wchar_lpct const text) mk_lang_noexcept
{
	mk_win_base_bool_t set;

	set = SetWindowTextW(window, text);
	return set;
}

mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_window_w_call_proc(mk_win_user_window_wndproc_t const proc, mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept
{
	mk_win_user_window_lresult_t lres;

	lres = CallWindowProcW(proc, window, message, wparam, lparam);
	return lres;
}


mk_lang_jumbo mk_win_user_window_t mk_win_user_window_t_create_by_name(mk_win_base_dword_t const style_ex, mk_win_tstring_tchar_lpct const class_name, mk_win_tstring_tchar_lpct const window_name, mk_win_base_dword_t const style, int const x, int const y, int const width, int const height, mk_win_user_window_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_window_a_create_by_name(style_ex, class_name, window_name, style, x, y, width, height, parent, menu, instance, param);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_user_window_a_create_by_name(style_ex, mk_win_tstring_tstr_to_ansi_zt_nofail(class_name).m_str, mk_win_tstring_tstr_to_ansi_zt_nofail(window_name).m_str, style, x, y, width, height, parent, menu, instance, param);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_window_w_create_by_name(style_ex, class_name, window_name, style, x, y, width, height, parent, menu, instance, param);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_user_window_w_create_by_name(style_ex, mk_win_tstring_tstr_to_wide_zt_nofail(class_name).m_str, mk_win_tstring_tstr_to_wide_zt_nofail(window_name).m_str, style, x, y, width, height, parent, menu, instance, param);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_window_a_create_by_name(style_ex, class_name, window_name, style, x, y, width, height, parent, menu, instance, param);
		#else
			return mk_win_user_window_a_create_by_name(style_ex, mk_win_tstring_tstr_to_ansi_zt_nofail(class_name).m_str, mk_win_tstring_tstr_to_ansi_zt_nofail(window_name).m_str, style, x, y, width, height, parent, menu, instance, param);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_window_w_create_by_name(style_ex, class_name, window_name, style, x, y, width, height, parent, menu, instance, param);
		#else
			return mk_win_user_window_w_create_by_name(style_ex, mk_win_tstring_tstr_to_wide_zt_nofail(class_name).m_str, mk_win_tstring_tstr_to_wide_zt_nofail(window_name).m_str, style, x, y, width, height, parent, menu, instance, param);
		#endif
	}
#endif
}

mk_lang_jumbo mk_win_user_window_t mk_win_user_window_t_create_by_atom(mk_win_base_dword_t const style_ex, mk_win_kernel_atom_t const atom, mk_win_tstring_tchar_lpct const window_name, mk_win_base_dword_t const style, int const x, int const y, int const width, int const height, mk_win_user_window_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_window_a_create_by_atom(style_ex, atom, window_name, style, x, y, width, height, parent, menu, instance, param);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_user_window_a_create_by_atom(style_ex, atom, mk_win_tstring_tstr_to_ansi_zt_nofail(window_name).m_str, style, x, y, width, height, parent, menu, instance, param);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_window_w_create_by_atom(style_ex, atom, window_name, style, x, y, width, height, parent, menu, instance, param);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_user_window_w_create_by_atom(style_ex, atom, mk_win_tstring_tstr_to_wide_zt_nofail(window_name).m_str, style, x, y, width, height, parent, menu, instance, param);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_window_a_create_by_atom(style_ex, atom, window_name, style, x, y, width, height, parent, menu, instance, param);
		#else
			return mk_win_user_window_a_create_by_atom(style_ex, atom, mk_win_tstring_tstr_to_ansi_zt_nofail(window_name).m_str, style, x, y, width, height, parent, menu, instance, param);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_window_w_create_by_atom(style_ex, atom, window_name, style, x, y, width, height, parent, menu, instance, param);
		#else
			return mk_win_user_window_w_create_by_atom(style_ex, atom, mk_win_tstring_tstr_to_wide_zt_nofail(window_name).m_str, style, x, y, width, height, parent, menu, instance, param);
		#endif
	}
#endif
}

mk_lang_jumbo mk_win_base_uintptr_t mk_win_user_window_t_set_data(mk_win_user_window_t const window, mk_win_user_window_data_idx_t const idx, mk_win_base_uintptr_t const new_data) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_window_a_set_data(window, idx, new_data);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_user_window_a_set_data(window, idx, new_data);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_window_w_set_data(window, idx, new_data);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_user_window_w_set_data(window, idx, new_data);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_window_a_set_data(window, idx, new_data);
		#else
			return mk_win_user_window_a_set_data(window, idx, new_data);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_window_w_set_data(window, idx, new_data);
		#else
			return mk_win_user_window_w_set_data(window, idx, new_data);
		#endif
	}
#endif
}

mk_lang_jumbo mk_win_base_uintptr_t mk_win_user_window_t_get_data(mk_win_user_window_t const window, mk_win_user_window_data_idx_t const idx) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_window_a_get_data(window, idx);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_user_window_a_get_data(window, idx);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_window_w_get_data(window, idx);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_user_window_w_get_data(window, idx);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_window_a_get_data(window, idx);
		#else
			return mk_win_user_window_a_get_data(window, idx);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_window_w_get_data(window, idx);
		#else
			return mk_win_user_window_w_get_data(window, idx);
		#endif
	}
#endif
}

mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_window_t_defproc(mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_window_a_defproc(window, message, wparam, lparam);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_user_window_a_defproc(window, message, wparam, lparam);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_window_w_defproc(window, message, wparam, lparam);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_user_window_w_defproc(window, message, wparam, lparam);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_window_a_defproc(window, message, wparam, lparam);
		#else
			return mk_win_user_window_a_defproc(window, message, wparam, lparam);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_window_w_defproc(window, message, wparam, lparam);
		#else
			return mk_win_user_window_w_defproc(window, message, wparam, lparam);
		#endif
	}
#endif
}

mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_t_post(mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_window_a_post(window, message, wparam, lparam);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_user_window_a_post(window, message, wparam, lparam);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_window_w_post(window, message, wparam, lparam);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_user_window_w_post(window, message, wparam, lparam);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	return mk_win_user_window_w_post(window, message, wparam, lparam);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_window_a_post(window, message, wparam, lparam);
		#else
			return mk_win_user_window_a_post(window, message, wparam, lparam);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_window_w_post(window, message, wparam, lparam);
		#else
			return mk_win_user_window_w_post(window, message, wparam, lparam);
		#endif
	}
#endif
}

mk_lang_jumbo int mk_win_user_window_t_get_text(mk_win_user_window_t const window, mk_win_tstring_tchar_lpt const text, int const max_len) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_window_a_get_text(window, text, max_len);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	mk_win_base_pchar_lpt ansi;
	ansi = mk_win_tstring_allocate_ansi_nofail(max_len);
	return mk_win_tstring_ansi_to_tstr_buff_sz_nofail(ansi, mk_win_user_window_a_get_text(window, ansi, max_len) + 1, text, max_len).m_length_elements - 1;
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_window_w_get_text(window, text, max_len);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	mk_win_base_wchar_lpt wide;
	wide = mk_win_tstring_allocate_wide_nofail(max_len);
	return mk_win_tstring_wide_to_tstr_buff_sz_nofail(wide, mk_win_user_window_w_get_text(window, wide, max_len) + 1, text, max_len).m_length_elements - 1;
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_window_a_get_text(window, text, max_len);
		#else
			mk_win_base_pchar_lpt ansi;
			ansi = mk_win_tstring_allocate_ansi_nofail(max_len);
			return mk_win_tstring_ansi_to_tstr_buff_sz_nofail(ansi, mk_win_user_window_a_get_text(window, ansi, max_len) + 1, text, max_len).m_length_elements - 1;
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_window_w_get_text(window, text, max_len);
		#else
			mk_win_base_wchar_lpt wide;
			wide = mk_win_tstring_allocate_wide_nofail(max_len);
			return mk_win_tstring_wide_to_tstr_buff_sz_nofail(wide, mk_win_user_window_w_get_text(window, wide, max_len) + 1, text, max_len).m_length_elements - 1;
		#endif
	}
#endif
}

mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_t_set_text(mk_win_user_window_t const window, mk_win_tstring_tchar_lpct const text) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_window_a_set_text(window, text);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_user_window_a_set_text(window, mk_win_tstring_tstr_to_ansi_zt_nofail(text).m_str);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_window_w_set_text(window, text);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_user_window_w_set_text(window, mk_win_tstring_tstr_to_wide_zt_nofail(text).m_str);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_window_a_set_text(window, text);
		#else
			return mk_win_user_window_a_set_text(window, mk_win_tstring_tstr_to_ansi_zt_nofail(text).m_str);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_window_w_set_text(window, text);
		#else
			return mk_win_user_window_w_set_text(window, mk_win_tstring_tstr_to_wide_zt_nofail(text).m_str);
		#endif
	}
#endif
}

mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_window_t_call_proc(mk_win_user_window_wndproc_t const proc, mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_window_a_call_proc(proc, window, message, wparam, lparam);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_user_window_a_call_proc(proc, window, message, wparam, lparam);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_window_w_call_proc(proc, window, message, wparam, lparam);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_user_window_w_call_proc(proc, window, message, wparam, lparam);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_window_a_call_proc(proc, window, message, wparam, lparam);
		#else
			return mk_win_user_window_a_call_proc(proc, window, message, wparam, lparam);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_window_w_call_proc(proc, window, message, wparam, lparam);
		#else
			return mk_win_user_window_w_call_proc(proc, window, message, wparam, lparam);
		#endif
	}
#endif
}


mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_show(mk_win_user_window_t const window, mk_win_user_window_show_t const show) mk_lang_noexcept
{
	mk_win_base_bool_t shown;

	shown = ShowWindow(window, ((int)(show)));
	return shown;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_update(mk_win_user_window_t const window) mk_lang_noexcept
{
	mk_win_base_bool_t updated;

	updated = UpdateWindow(window);
	return updated;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_get_client_rect(mk_win_user_window_t const window, mk_win_base_rect_lpt const rect) mk_lang_noexcept
{
	mk_win_base_bool_t got;

	got = GetClientRect(window, rect);
	return got;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_get_rect(mk_win_user_window_t const window, mk_win_base_rect_lpt const rect) mk_lang_noexcept
{
	mk_win_base_bool_t got;

	got = GetWindowRect(window, rect);
	return got;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_set_pos(mk_win_user_window_t const window, mk_win_user_window_t const insert_after, int const x, int const y, int const width, int const height, mk_win_user_window_swp_t const flags) mk_lang_noexcept
{
	mk_win_base_bool_t set;

	set = SetWindowPos(window, insert_after, x, y, width, height, ((mk_win_base_uint_t)(flags)));
	return set;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_gdi_dc_t mk_win_user_window_begin_paint(mk_win_user_window_t const window, mk_win_user_window_paint_lpt const paint) mk_lang_noexcept
{
	mk_win_gdi_dc_t dc;

	dc = BeginPaint(window, paint);
	return dc;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_end_paint(mk_win_user_window_t const window, mk_win_user_window_paint_lpct const paint) mk_lang_noexcept
{
	mk_win_base_bool_t ended;

	ended = EndPaint(window, paint);
	return ended;
}

mk_lang_jumbo mk_win_user_window_t mk_win_user_window_set_focus(mk_win_user_window_t const window) mk_lang_noexcept
{
	mk_win_user_window_t prev;

	prev = SetFocus(window);
	return prev;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_window_t mk_win_user_window_get_parent(mk_win_user_window_t const window) mk_lang_noexcept
{
	mk_win_user_window_t parent;

	parent = GetParent(window);
	return parent;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_show_scrollbar(mk_win_user_window_t const window, mk_win_user_window_show_scrollbar_t const bar, mk_win_base_bool_t const show) mk_lang_noexcept
{
	mk_win_base_bool_t shown;

	shown = ShowScrollBar(window, ((int)(bar)), show);
	return shown;
}


mk_lang_nodiscard mk_lang_jumbo mk_win_user_window_t mk_win_user_window_get_desktop(void) mk_lang_noexcept
{
	mk_win_user_window_t desktop;

	desktop = GetDesktopWindow();
	return desktop;
}
