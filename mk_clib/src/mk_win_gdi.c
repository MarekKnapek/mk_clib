#include "mk_win_gdi.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_tstring.h"
#include "mk_win_unicode_api.h"


mk_win_base_dll_import int mk_win_base_stdcall GetObjectA(mk_win_base_handle_t, int, mk_win_base_void_lpt) mk_lang_noexcept;
mk_win_base_dll_import int mk_win_base_stdcall GetObjectW(mk_win_base_handle_t, int, mk_win_base_void_lpt) mk_lang_noexcept;


mk_lang_jumbo int mk_win_gdi_a_get_object(mk_win_base_handle_t const handle, int const size_bytes, mk_win_base_void_lpt const output) mk_lang_noexcept
{
	int ret;

	ret = GetObjectA(handle, size_bytes, output);
	return ret;
}

mk_lang_jumbo int mk_win_gdi_w_get_object(mk_win_base_handle_t const handle, int const size_bytes, mk_win_base_void_lpt const output) mk_lang_noexcept
{
	int ret;

	ret = GetObjectW(handle, size_bytes, output);
	return ret;
}

mk_lang_jumbo int mk_win_gdi_t_get_object(mk_win_base_handle_t const handle, int const size_bytes, mk_win_base_void_lpt const output) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_gdi_a_get_object(handle, size_bytes, output);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_gdi_a_get_object(handle, size_bytes, output);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_gdi_w_get_object(handle, size_bytes, output);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_gdi_w_get_object(handle, size_bytes, output);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_gdi_a_get_object(handle, size_bytes, output);
		#else
			return mk_win_gdi_a_get_object(handle, size_bytes, output);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_gdi_w_get_object(handle, size_bytes, output);
		#else
			return mk_win_gdi_w_get_object(handle, size_bytes, output);
		#endif
	}
#endif
}
