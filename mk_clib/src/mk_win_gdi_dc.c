#include "mk_win_gdi_dc.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_gdi_object.h"


mk_win_base_dll_import mk_win_gdi_dc_t mk_win_base_stdcall CreateCompatibleDC(mk_win_gdi_dc_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall DeleteDC(mk_win_gdi_dc_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_gdi_object_t mk_win_base_stdcall SelectObject(mk_win_gdi_dc_t, mk_win_gdi_object_t) mk_lang_noexcept;
mk_win_base_dll_import int mk_win_base_stdcall SetBkMode(mk_win_gdi_dc_t, int) mk_lang_noexcept;
mk_win_base_dll_import int mk_win_base_stdcall FillRect(mk_win_gdi_dc_t, mk_win_base_rect_lpct, mk_win_user_brush_t) mk_lang_noexcept;
mk_win_base_dll_import int mk_win_base_stdcall FrameRect(mk_win_gdi_dc_t, mk_win_base_rect_lpct, mk_win_user_brush_t) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_gdi_dc_t mk_win_gdi_dc_create_compatible(mk_win_gdi_dc_t const dc) mk_lang_noexcept
{
	mk_win_gdi_dc_t cdc;

	cdc = CreateCompatibleDC(dc);
	return cdc;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_dc_delete(mk_win_gdi_dc_t const dc) mk_lang_noexcept
{
	mk_win_base_bool_t deleted;

	deleted = DeleteDC(dc);
	return deleted;
}

mk_lang_jumbo mk_win_gdi_object_t mk_win_gdi_dc_select_object(mk_win_gdi_dc_t const dc, mk_win_gdi_object_t const object) mk_lang_noexcept
{
	mk_win_gdi_object_t prev;

	prev = SelectObject(dc, object);
	return prev;
}

mk_lang_jumbo mk_win_gdi_dc_bk_mode_t mk_win_gdi_dc_set_bk_mode(mk_win_gdi_dc_t const dc, mk_win_gdi_dc_bk_mode_t const mode) mk_lang_noexcept
{
	mk_win_gdi_dc_bk_mode_t prev;

	prev = ((mk_win_gdi_dc_bk_mode_t)(SetBkMode(dc, ((int)(mode)))));
	return prev;
}

mk_lang_jumbo int mk_win_gdi_dc_fill_rect(mk_win_gdi_dc_t const dc, mk_win_base_rect_lpct const rect, mk_win_user_brush_t const brush) mk_lang_noexcept
{
	int filled;

	filled = FillRect(dc, rect, brush);
	return filled;
}

mk_lang_jumbo int mk_win_gdi_dc_frame_rect(mk_win_gdi_dc_t const dc, mk_win_base_rect_lpct const rect, mk_win_user_brush_t const brush) mk_lang_noexcept
{
	int framed;

	framed = FrameRect(dc, rect, brush);
	return framed;
}
