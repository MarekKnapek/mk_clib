#include "mk_win_user_dc.h"

#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_user_base.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_dc_t mk_win_base_stdcall CreateCompatibleDC(mk_win_user_dc_t const dc) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_base_colorref_t mk_win_base_stdcall SetTextColor(mk_win_user_dc_t const dc, mk_win_user_base_colorref_t const color) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_base_colorref_t mk_win_base_stdcall SetBkColor(mk_win_user_dc_t const dc, mk_win_user_base_colorref_t const color) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall DeleteDC(mk_win_user_dc_t const dc) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall DrawTextW(mk_win_user_dc_t const dc, mk_win_base_wchar_lpct const text, mk_win_base_sint_t const len, mk_win_base_rect_lpt const rect, mk_win_base_uint_t const flags) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall FillRect(mk_win_user_dc_t const dc, mk_win_base_rect_lpct const rect, mk_win_user_brush_t const brush) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_base_gdi_obj_t mk_win_base_stdcall SelectObject(mk_win_user_dc_t const dc, mk_win_user_base_gdi_obj_t const gdi_obj) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_bitmap_t mk_win_base_stdcall CreateCompatibleBitmap(mk_win_user_dc_t const dc, mk_win_base_sint_t const width, mk_win_base_sint_t const height) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall DeleteObject(mk_win_user_base_gdi_obj_t const gdi_obj) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall BitBlt(mk_win_user_dc_t const dst, mk_win_base_sint_t const dst_x, mk_win_base_sint_t const dst_y, mk_win_base_sint_t const width, mk_win_base_sint_t const height, mk_win_user_dc_t const src, mk_win_base_sint_t const src_x, mk_win_base_sint_t const src_y, mk_win_base_dword_t const rop) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_user_dc_t mk_win_user_dc_create_compatible(mk_win_user_dc_t const dc) mk_lang_noexcept
{
	mk_win_user_dc_t ret;

	ret = CreateCompatibleDC(dc);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_colorref_t mk_win_user_dc_set_text_color(mk_win_user_dc_t const dc, mk_win_user_base_colorref_t const color) mk_lang_noexcept
{
	mk_win_user_base_colorref_t ret;

	ret = SetTextColor(dc, color);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_colorref_t mk_win_user_dc_set_bk_color(mk_win_user_dc_t const dc, mk_win_user_base_colorref_t const color) mk_lang_noexcept
{
	mk_win_user_base_colorref_t ret;

	ret = SetBkColor(dc, color);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_dc_delete(mk_win_user_dc_t const dc) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = DeleteDC(dc);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_user_dc_draw_text_w(mk_win_user_dc_t const dc, mk_win_base_wchar_lpct const text, mk_win_base_sint_t const len, mk_win_base_rect_lpt const rect, mk_win_base_uint_t const flags) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = DrawTextW(dc, text, len, rect, flags);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_user_dc_fill_rect(mk_win_user_dc_t const dc, mk_win_base_rect_lpct const rect, mk_win_user_brush_t const brush) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = FillRect(dc, rect, brush);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_bitmap_t mk_win_user_dc_select_bitmap(mk_win_user_dc_t const dc, mk_win_user_bitmap_t const bitmap) mk_lang_noexcept
{
	mk_win_user_base_gdi_obj_t gdi_obj;
	mk_win_user_bitmap_t ret;

	gdi_obj = mk_win_user_base_gdi_obj_from(bitmap.m_data);
	gdi_obj = SelectObject(dc, gdi_obj);
	ret = mk_win_user_bitmap_from(gdi_obj.m_data);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_bitmap_t mk_win_user_bitmap_create_compatible(mk_win_user_dc_t const dc, mk_win_base_sint_t const width, mk_win_base_sint_t const height) mk_lang_noexcept
{
	mk_win_user_bitmap_t ret;

	ret = CreateCompatibleBitmap(dc, width, height);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_gdi_obj_delete(mk_win_user_base_gdi_obj_t const gdi_obj) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = DeleteObject(gdi_obj);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t bitblast(mk_win_user_dc_t const dst, mk_win_base_sint_t const dst_x, mk_win_base_sint_t const dst_y, mk_win_base_sint_t const width, mk_win_base_sint_t const height, mk_win_user_dc_t const src, mk_win_base_sint_t const src_x, mk_win_base_sint_t const src_y, mk_win_base_dword_t const rop) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = BitBlt(dst, dst_x, dst_y, width, height, src, src_x, src_y, rop);
	return ret;
}
