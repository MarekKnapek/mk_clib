#include "mk_win_user_window.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_user_base.h"
#include "mk_win_user_menu.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_base_wnd_t mk_win_base_stdcall CreateWindowA(mk_win_base_pchar_lpct const class_name, mk_win_base_pchar_lpct const window_name, mk_win_base_dword_t const style, mk_lang_types_sint_t const x, mk_lang_types_sint_t const y, mk_lang_types_sint_t const w, mk_lang_types_sint_t const h, mk_win_user_base_wnd_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_base_wnd_t mk_win_base_stdcall CreateWindowW(mk_win_base_wchar_lpct const class_name, mk_win_base_wchar_lpct const window_name, mk_win_base_dword_t const style, mk_lang_types_sint_t const x, mk_lang_types_sint_t const y, mk_lang_types_sint_t const w, mk_lang_types_sint_t const h, mk_win_user_base_wnd_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_base_wnd_t mk_win_base_stdcall CreateWindowExA(mk_win_base_dword_t const styleex, mk_win_base_pchar_lpct const class_name, mk_win_base_pchar_lpct const window_name, mk_win_base_dword_t const style, mk_lang_types_sint_t const x, mk_lang_types_sint_t const y, mk_lang_types_sint_t const w, mk_lang_types_sint_t const h, mk_win_user_base_wnd_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_base_wnd_t mk_win_base_stdcall CreateWindowExW(mk_win_base_dword_t const styleex, mk_win_base_wchar_lpct const class_name, mk_win_base_wchar_lpct const window_name, mk_win_base_dword_t const style, mk_lang_types_sint_t const x, mk_lang_types_sint_t const y, mk_lang_types_sint_t const w, mk_lang_types_sint_t const h, mk_win_user_base_wnd_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall ShowWindow(mk_win_user_base_wnd_t const wnd, mk_win_base_sint_t const show) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall UpdateWindow(mk_win_user_base_wnd_t const wnd) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall ShowScrollBar(mk_win_user_base_wnd_t const wnd, mk_win_base_sint_t const bar, mk_win_base_bool_t const show) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall EnableScrollBar(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const flags, mk_win_base_uint_t const arrows) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall SetScrollInfo(mk_win_user_base_wnd_t const wnd, mk_win_base_sint_t const bar, mk_win_user_window_scrollinfo_lpct const scrollinfo, mk_win_base_bool_t const redraw) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_base_lresult_t mk_win_base_stdcall DefWindowProcA(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const msg, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_base_lresult_t mk_win_base_stdcall DefWindowProcW(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const msg, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_uintptr_t mk_win_base_stdcall SetWindowLongW(mk_win_user_base_wnd_t const wnd, mk_win_base_sint_t const idx, mk_win_base_uintptr_t const newdata) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_uintptr_t mk_win_base_stdcall GetWindowLongW(mk_win_user_base_wnd_t const wnd, mk_win_base_sint_t const idx) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_uintptr_t mk_win_base_stdcall SetWindowLongPtrW(mk_win_user_base_wnd_t const wnd, mk_win_base_sint_t const idx, mk_win_base_uintptr_t const newdata) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_uintptr_t mk_win_base_stdcall GetWindowLongPtrW(mk_win_user_base_wnd_t const wnd, mk_win_base_sint_t const idx) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_base_lresult_t mk_win_base_stdcall SendMessageW(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const msg, mk_win_user_base_lparam_t const wparam, mk_win_user_base_lparam_t const lparam) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall PostMessageW(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const msg, mk_win_user_base_lparam_t const wparam, mk_win_user_base_lparam_t const lparam) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall InvalidateRgn(mk_win_user_base_wnd_t const wnd, mk_win_user_region_t const region, mk_win_base_bool_t const erase) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetClientRect(mk_win_user_base_wnd_t const wnd, mk_win_base_rect_lpt const rect) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_dc_t mk_win_base_stdcall GetDC(mk_win_user_base_wnd_t const wnd) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall ReleaseDC(mk_win_user_base_wnd_t const wnd, mk_win_user_dc_t const dc) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_dc_t mk_win_base_stdcall BeginPaint(mk_win_user_base_wnd_t const wnd, mk_win_user_base_ps_lpt const ps) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall EndPaint(mk_win_user_base_wnd_t const wnd, mk_win_user_base_ps_lpct const ps) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall AdjustWindowRectEx(mk_win_base_rect_lpt const rect, mk_win_base_dword_t const style, mk_win_base_bool_t const menu, mk_win_base_dword_t const styleex) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_wnd_t mk_win_user_window_a_create(mk_win_base_pchar_lpct const class_name, mk_win_base_pchar_lpct const window_name, mk_win_base_dword_t const style, mk_lang_types_sint_t const x, mk_lang_types_sint_t const y, mk_lang_types_sint_t const w, mk_lang_types_sint_t const h, mk_win_user_base_wnd_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept
{
	mk_win_user_base_wnd_t ret;

	ret = CreateWindowA(class_name, window_name, style, x, y, w, h, parent, menu, instance, param);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_wnd_t mk_win_user_window_w_create(mk_win_base_wchar_lpct const class_name, mk_win_base_wchar_lpct const window_name, mk_win_base_dword_t const style, mk_lang_types_sint_t const x, mk_lang_types_sint_t const y, mk_lang_types_sint_t const w, mk_lang_types_sint_t const h, mk_win_user_base_wnd_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept
{
	mk_win_user_base_wnd_t ret;

	ret = CreateWindowW(class_name, window_name, style, x, y, w, h, parent, menu, instance, param);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_wnd_t mk_win_user_window_a_createex(mk_win_base_dword_t const styleex, mk_win_base_pchar_lpct const class_name, mk_win_base_pchar_lpct const window_name, mk_win_base_dword_t const style, mk_lang_types_sint_t const x, mk_lang_types_sint_t const y, mk_lang_types_sint_t const w, mk_lang_types_sint_t const h, mk_win_user_base_wnd_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept
{
	mk_win_user_base_wnd_t ret;

	ret = CreateWindowExA(styleex, class_name, window_name, style, x, y, w, h, parent, menu, instance, param);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_wnd_t mk_win_user_window_w_createex(mk_win_base_dword_t const styleex, mk_win_base_wchar_lpct const class_name, mk_win_base_wchar_lpct const window_name, mk_win_base_dword_t const style, mk_lang_types_sint_t const x, mk_lang_types_sint_t const y, mk_lang_types_sint_t const w, mk_lang_types_sint_t const h, mk_win_user_base_wnd_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept
{
	mk_win_user_base_wnd_t ret;

	ret = CreateWindowExW(styleex, class_name, window_name, style, x, y, w, h, parent, menu, instance, param);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_show(mk_win_user_base_wnd_t const wnd, mk_win_base_sint_t const show) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = ShowWindow(wnd, show);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_update(mk_win_user_base_wnd_t const wnd) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = UpdateWindow(wnd);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_scrollbar_show(mk_win_user_base_wnd_t const wnd, mk_win_base_sint_t const bar, mk_win_base_bool_t const show) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = ShowScrollBar(wnd, bar, show);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_scrollbar_enable(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const flags, mk_win_base_uint_t const arrows) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = EnableScrollBar(wnd, flags, arrows);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_scrollbar_info_set(mk_win_user_base_wnd_t const wnd, mk_win_base_sint_t const bar, mk_win_user_window_scrollinfo_lpct const scrollinfo, mk_win_base_bool_t const redraw) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = SetScrollInfo(wnd, bar, scrollinfo, redraw);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_lresult_t mk_win_user_window_a_def_proc(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const msg, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam) mk_lang_noexcept
{
	mk_win_user_base_lresult_t ret;

	ret = DefWindowProcA(wnd, msg, wparam, lparam);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_lresult_t mk_win_user_window_w_def_proc(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const msg, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam) mk_lang_noexcept
{
	mk_win_user_base_lresult_t ret;

	ret = DefWindowProcW(wnd, msg, wparam, lparam);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_uintptr_t mk_win_user_window_w_data_set(mk_win_user_base_wnd_t const wnd, mk_win_base_sint_t const idx, mk_win_base_uintptr_t const newdata) mk_lang_noexcept
{
	mk_win_base_uintptr_t ret;

	#if mk_win_base_arch == mk_win_base_arch_32
	ret = SetWindowLongW(wnd, idx, newdata);
	#elif mk_win_base_arch == mk_win_base_arch_64
	ret = SetWindowLongPtrW(wnd, idx, newdata);
	#else
	#error xxxxxxxxxx
	#endif
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_uintptr_t mk_win_user_window_w_data_get(mk_win_user_base_wnd_t const wnd, mk_win_base_sint_t const idx) mk_lang_noexcept
{
	mk_win_base_uintptr_t ret;

	#if mk_win_base_arch == mk_win_base_arch_32
	ret = GetWindowLongW(wnd, idx);
	#elif mk_win_base_arch == mk_win_base_arch_64
	ret = GetWindowLongPtrW(wnd, idx);
	#else
	#error xxxxxxxxxx
	#endif
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_lresult_t mk_win_user_window_w_msg_send(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const msg, mk_win_user_base_lparam_t const wparam, mk_win_user_base_lparam_t const lparam) mk_lang_noexcept
{
	mk_win_user_base_lresult_t ret;

	ret = SendMessageW(wnd, msg, wparam, lparam);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_w_msg_post(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const msg, mk_win_user_base_lparam_t const wparam, mk_win_user_base_lparam_t const lparam) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = PostMessageW(wnd, msg, wparam, lparam);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_invalidate_region(mk_win_user_base_wnd_t const wnd, mk_win_user_region_t const region, mk_win_base_bool_t const erase) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = InvalidateRgn(wnd, region, erase);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_dc_t mk_win_user_window_dc_get_client(mk_win_user_base_wnd_t const wnd) mk_lang_noexcept
{
	mk_win_user_dc_t ret;

	ret = GetDC(wnd);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_get_rect_client(mk_win_user_base_wnd_t const wnd, mk_win_base_rect_lpt const rect) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = GetClientRect(wnd, rect);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_user_window_dc_release(mk_win_user_base_wnd_t const wnd, mk_win_user_dc_t const dc) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = ReleaseDC(wnd, dc);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_dc_t mk_win_user_window_paint_begin(mk_win_user_base_wnd_t const wnd, mk_win_user_base_ps_lpt const ps) mk_lang_noexcept
{
	mk_win_user_dc_t ret;

	ret = BeginPaint(wnd, ps);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_paint_end(mk_win_user_base_wnd_t const wnd, mk_win_user_base_ps_lpct const ps) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = EndPaint(wnd, ps);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_rect_adjust_ex(mk_win_base_rect_lpt const rect, mk_win_base_dword_t const style, mk_win_base_bool_t const menu, mk_win_base_dword_t const styleex) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = AdjustWindowRectEx(rect, style, menu, styleex);
	return ret;
}
