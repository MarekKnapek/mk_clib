#include "mk_win_user_message.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_sal.h"
#include "mk_win_user_window.h"


mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetMessageA(mk_win_user_message_lpt, mk_win_user_window_t, mk_win_base_uint_t, mk_win_base_uint_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_user_window_lresult_t mk_win_base_stdcall DispatchMessageA(mk_win_user_message_lpct) mk_lang_noexcept;
mk_win_base_dll_import mk_win_user_window_lresult_t mk_win_base_stdcall SendMessageA(mk_win_user_window_t, mk_win_base_uint_t, mk_win_user_window_wparam_t, mk_win_user_window_lparam_t) mk_lang_noexcept;

mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetMessageW(mk_win_user_message_lpt, mk_win_user_window_t, mk_win_base_uint_t, mk_win_base_uint_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_user_window_lresult_t mk_win_base_stdcall DispatchMessageW(mk_win_user_message_lpct) mk_lang_noexcept;
mk_win_base_dll_import mk_win_user_window_lresult_t mk_win_base_stdcall SendMessageW(mk_win_user_window_t, mk_win_base_uint_t, mk_win_user_window_wparam_t, mk_win_user_window_lparam_t) mk_lang_noexcept;

mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall TranslateMessage(mk_win_user_message_lpct) mk_lang_noexcept;
mk_win_base_dll_import void mk_win_base_stdcall PostQuitMessage(int) mk_lang_noexcept;


mk_lang_jumbo mk_win_base_bool_t mk_win_user_message_a_get(mk_win_user_message_lpt const message, mk_win_user_window_t const window, mk_win_base_uint_t const id_min, mk_win_base_uint_t const id_max) mk_lang_noexcept
{
	mk_win_base_bool_t got;

	got = GetMessageA(message, window, id_min, id_max);
	return got;
}

mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_message_a_dispatch(mk_win_user_message_lpct const message) mk_lang_noexcept
{
	mk_win_user_window_lresult_t dispatched;

	dispatched = DispatchMessageA(message);
	return dispatched;
}

mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_message_a_send(mk_win_user_window_t const window, mk_win_base_uint_t const message_id, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept
{
	mk_win_user_window_lresult_t lres;

	lres = SendMessageA(window, message_id, wparam, lparam);
	return lres;
}


mk_lang_jumbo mk_win_base_bool_t mk_win_user_message_w_get(mk_win_user_message_lpt const message, mk_win_user_window_t const window, mk_win_base_uint_t const id_min, mk_win_base_uint_t const id_max) mk_lang_noexcept
{
	mk_win_base_bool_t got;

	got = GetMessageW(message, window, id_min, id_max);
	return got;
}

mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_message_w_dispatch(mk_win_user_message_lpct const message) mk_lang_noexcept
{
	mk_win_user_window_lresult_t dispatched;

	dispatched = DispatchMessageW(message);
	return dispatched;
}

mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_message_w_send(mk_win_user_window_t const window, mk_win_base_uint_t const message_id, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept
{
	mk_win_user_window_lresult_t lres;

	lres = SendMessageW(window, message_id, wparam, lparam);
	return lres;
}


mk_lang_jumbo mk_win_base_bool_t mk_win_user_message_t_get(mk_win_user_message_lpt const message, mk_win_user_window_t const window, mk_win_base_uint_t const id_min, mk_win_base_uint_t const id_max) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_message_a_get(message, window, id_min, id_max);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_user_message_a_get(message, window, id_min, id_max);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_message_w_get(message, window, id_min, id_max);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_user_message_w_get(message, window, id_min, id_max);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_message_a_get(message, window, id_min, id_max);
		#else
			return mk_win_user_message_a_get(message, window, id_min, id_max);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_message_w_get(message, window, id_min, id_max);
		#else
			return mk_win_user_message_w_get(message, window, id_min, id_max);
		#endif
	}
#endif
}

mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_message_t_dispatch(mk_win_user_message_lpct const message) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_message_a_dispatch(message);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_user_message_a_dispatch(message);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_message_w_dispatch(message);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_user_message_w_dispatch(message);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_message_a_dispatch(message);
		#else
			return mk_win_user_message_a_dispatch(message);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_message_w_dispatch(message);
		#else
			return mk_win_user_message_w_dispatch(message);
		#endif
	}
#endif
}

mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_message_t_send(mk_win_user_window_t const window, mk_win_base_uint_t const message_id, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_message_a_send(window, message_id, wparam, lparam);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_user_message_a_send(window, message_id, wparam, lparam);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_message_w_send(window, message_id, wparam, lparam);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_user_message_w_send(window, message_id, wparam, lparam);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_message_a_send(window, message_id, wparam, lparam);
		#else
			return mk_win_user_message_a_send(window, message_id, wparam, lparam);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_message_w_send(window, message_id, wparam, lparam);
		#else
			return mk_win_user_message_w_send(window, message_id, wparam, lparam);
		#endif
	}
#endif
}


mk_lang_jumbo mk_win_base_bool_t mk_win_user_message_translate(mk_win_user_message_lpct const message) mk_lang_noexcept
{
	mk_win_base_bool_t translated;

	translated = TranslateMessage(message);
	return translated;
}

mk_lang_jumbo void mk_win_user_message_post_quit(int const exit_code) mk_lang_noexcept
{
	PostQuitMessage(exit_code);
}
