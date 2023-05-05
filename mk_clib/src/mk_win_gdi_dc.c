#include "mk_win_gdi_dc.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_gdi_object.h"
#include "mk_win_tstring.h"
#include "mk_win_unicode_api.h"


mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetTextExtentPoint32A(mk_win_gdi_dc_t, mk_win_base_pchar_lpct, int, mk_win_base_sizer_lpt) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall ExtTextOutA(mk_win_gdi_dc_t, int, int, mk_win_base_uint_t, mk_win_base_rect_lpct, mk_win_base_pchar_lpct, mk_win_base_uint_t, mk_win_base_sint_lpct) mk_lang_noexcept;

mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetTextExtentPoint32W(mk_win_gdi_dc_t, mk_win_base_wchar_lpct, int, mk_win_base_sizer_lpt) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall ExtTextOutW(mk_win_gdi_dc_t, int, int, mk_win_base_uint_t, mk_win_base_rect_lpct, mk_win_base_wchar_lpct, mk_win_base_uint_t, mk_win_base_sint_lpct) mk_lang_noexcept;

mk_win_base_dll_import mk_win_gdi_dc_t mk_win_base_stdcall CreateCompatibleDC(mk_win_gdi_dc_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall DeleteDC(mk_win_gdi_dc_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_gdi_object_t mk_win_base_stdcall SelectObject(mk_win_gdi_dc_t, mk_win_gdi_object_t) mk_lang_noexcept;
mk_win_base_dll_import int mk_win_base_stdcall SetBkMode(mk_win_gdi_dc_t, int) mk_lang_noexcept;
mk_win_base_dll_import int mk_win_base_stdcall FillRect(mk_win_gdi_dc_t, mk_win_base_rect_lpct, mk_win_user_brush_t) mk_lang_noexcept;
mk_win_base_dll_import int mk_win_base_stdcall FrameRect(mk_win_gdi_dc_t, mk_win_base_rect_lpct, mk_win_user_brush_t) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_dc_a_get_text_extent_point_32(mk_win_gdi_dc_t const dc, mk_win_base_pchar_lpct const text, int const text_len, mk_win_base_sizer_lpt const size) mk_lang_noexcept
{
	mk_win_base_bool_t got;

	got = GetTextExtentPoint32A(dc, text, text_len, size);
	return got;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_dc_a_ext_text_out(mk_win_gdi_dc_t const dc, int const x, int const y, mk_win_gdi_dc_ext_text_out_options_t const options, mk_win_base_rect_lpct const rect, mk_win_base_pchar_lpct const text, int const text_len, mk_win_base_sint_lpct const dx) mk_lang_noexcept
{
	mk_win_base_bool_t drawn;

	drawn = ExtTextOutA(dc, x, y, ((mk_win_base_uint_t)(options)), rect, text, text_len, dx);
	return drawn;
}


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_dc_w_get_text_extent_point_32(mk_win_gdi_dc_t const dc, mk_win_base_wchar_lpct const text, int const text_len, mk_win_base_sizer_lpt const size) mk_lang_noexcept
{
	mk_win_base_bool_t got;

	got = GetTextExtentPoint32W(dc, text, text_len, size);
	return got;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_dc_w_ext_text_out(mk_win_gdi_dc_t const dc, int const x, int const y, mk_win_gdi_dc_ext_text_out_options_t const options, mk_win_base_rect_lpct const rect, mk_win_base_wchar_lpct const text, int const text_len, mk_win_base_sint_lpct const dx) mk_lang_noexcept
{
	mk_win_base_bool_t drawn;

	drawn = ExtTextOutW(dc, x, y, ((mk_win_base_uint_t)(options)), rect, text, text_len, dx);
	return drawn;
}


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_dc_t_get_text_extent_point_32(mk_win_gdi_dc_t const dc, mk_win_tstring_tchar_lpct const text, int const text_len, mk_win_base_sizer_lpt const size) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_gdi_dc_a_get_text_extent_point_32(dc, text, text_len, size);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	mk_win_tstring_pstr_with_size_t ansi;
	ansi = mk_win_tstring_tstr_to_ansi_sz_nofail(text, text_len);
	return mk_win_gdi_dc_a_get_text_extent_point_32(dc, ansi.m_str, ansi.m_length_elements, size);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_gdi_dc_w_get_text_extent_point_32(dc, text, text_len, size);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	mk_win_tstring_wstr_with_size_t wide;
	wide = mk_win_tstring_tstr_to_wide_sz_nofail(text, text_len);
	return mk_win_gdi_dc_w_get_text_extent_point_32(dc, wide.m_str, wide.m_length_elements, size);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_gdi_dc_a_get_text_extent_point_32(dc, text, text_len, size);
		#else
			mk_win_tstring_pstr_with_size_t ansi;
			ansi = mk_win_tstring_tstr_to_ansi_sz_nofail(text, text_len);
			return mk_win_gdi_dc_a_get_text_extent_point_32(dc, ansi.m_str, ansi.m_length_elements, size);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_gdi_dc_w_get_text_extent_point_32(dc, text, text_len, size);
		#else
			mk_win_tstring_wstr_with_size_t wide;
			wide = mk_win_tstring_tstr_to_wide_sz_nofail(text, text_len);
			return mk_win_gdi_dc_w_get_text_extent_point_32(dc, wide.m_str, wide.m_length_elements, size);
		#endif
	}
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_dc_t_ext_text_out(mk_win_gdi_dc_t const dc, int const x, int const y, mk_win_gdi_dc_ext_text_out_options_t const options, mk_win_base_rect_lpct const rect, mk_win_tstring_tchar_lpct const text, int const text_len, mk_win_base_sint_lpct const dx) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_gdi_dc_a_ext_text_out(dc, x, y, options, rect, text, text_len, dx);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	mk_win_tstring_pstr_with_size_t ansi;
	ansi = mk_win_tstring_tstr_to_ansi_sz_nofail(text, text_len);
	return mk_win_gdi_dc_a_ext_text_out(dc, x, y, options, rect, ansi.m_str, ansi.m_length_elements, dx);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_gdi_dc_w_ext_text_out(dc, x, y, options, rect, text, text_len, dx);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	mk_win_tstring_wstr_with_size_t wide;
	wide = mk_win_tstring_tstr_to_wide_sz_nofail(text, text_len);
	return mk_win_gdi_dc_w_ext_text_out(dc, x, y, options, rect, wide.m_str, wide.m_length_elements, dx);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_gdi_dc_a_ext_text_out(dc, x, y, options, rect, text, text_len, dx);
		#else
			mk_win_tstring_pstr_with_size_t ansi;
			ansi = mk_win_tstring_tstr_to_ansi_sz_nofail(text, text_len);
			return mk_win_gdi_dc_a_ext_text_out(dc, x, y, options, rect, ansi.m_str, ansi.m_length_elements, dx);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_gdi_dc_w_ext_text_out(dc, x, y, options, rect, text, text_len, dx);
		#else
			mk_win_tstring_wstr_with_size_t wide;
			wide = mk_win_tstring_tstr_to_wide_sz_nofail(text, text_len);
			return mk_win_gdi_dc_w_ext_text_out(dc, x, y, options, rect, wide.m_str, wide.m_length_elements, dx);
		#endif
	}
#endif
}


mk_lang_nodiscard mk_lang_jumbo mk_win_gdi_dc_t mk_win_gdi_dc_create_compatible(mk_win_gdi_dc_t const dc) mk_lang_noexcept
{
	mk_win_gdi_dc_t cdc;

	cdc = CreateCompatibleDC(dc);
	return cdc;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_dc_delete(mk_win_gdi_dc_t const dc) mk_lang_noexcept
{
	mk_win_base_bool_t deleted;

	deleted = DeleteDC(dc);
	return deleted;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_gdi_object_t mk_win_gdi_dc_select_object(mk_win_gdi_dc_t const dc, mk_win_gdi_object_t const object) mk_lang_noexcept
{
	mk_win_gdi_object_t prev;

	prev = SelectObject(dc, object);
	return prev;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_gdi_dc_bk_mode_t mk_win_gdi_dc_set_bk_mode(mk_win_gdi_dc_t const dc, mk_win_gdi_dc_bk_mode_t const mode) mk_lang_noexcept
{
	mk_win_gdi_dc_bk_mode_t prev;

	prev = ((mk_win_gdi_dc_bk_mode_t)(SetBkMode(dc, ((int)(mode)))));
	return prev;
}

mk_lang_nodiscard mk_lang_jumbo int mk_win_gdi_dc_fill_rect(mk_win_gdi_dc_t const dc, mk_win_base_rect_lpct const rect, mk_win_user_brush_t const brush) mk_lang_noexcept
{
	int filled;

	filled = FillRect(dc, rect, brush);
	return filled;
}

mk_lang_nodiscard mk_lang_jumbo int mk_win_gdi_dc_frame_rect(mk_win_gdi_dc_t const dc, mk_win_base_rect_lpct const rect, mk_win_user_brush_t const brush) mk_lang_noexcept
{
	int framed;

	framed = FrameRect(dc, rect, brush);
	return framed;
}
