#include "mk_win_gdi_font.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_tstring.h"
#include "mk_win_unicode_api.h"


mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateFontIndirectA(mk_win_gdi_font_a_lpct) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateFontIndirectW(mk_win_gdi_font_w_lpct) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_gdi_font_a_create_indirect(mk_win_gdi_font_a_lpct const font) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = CreateFontIndirectA(font);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_gdi_font_w_create_indirect(mk_win_gdi_font_w_lpct const font) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = CreateFontIndirectW(font);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_gdi_font_t_create_indirect(mk_win_base_void_lpct const font) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_gdi_font_a_create_indirect(((mk_win_gdi_font_a_lpct)(font)));
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_gdi_font_a_create_indirect(((mk_win_gdi_font_a_lpct)(font)));
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_gdi_font_w_create_indirect(((mk_win_gdi_font_w_lpct)(font)));
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_gdi_font_w_create_indirect(((mk_win_gdi_font_w_lpct)(font)));
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_gdi_font_a_create_indirect(((mk_win_gdi_font_a_lpct)(font)));
		#else
			return mk_win_gdi_font_a_create_indirect(((mk_win_gdi_font_a_lpct)(font)));
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_gdi_font_w_create_indirect(((mk_win_gdi_font_w_lpct)(font)));
		#else
			return mk_win_gdi_font_w_create_indirect(((mk_win_gdi_font_w_lpct)(font)));
		#endif
	}
#endif
}
