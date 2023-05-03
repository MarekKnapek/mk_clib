#include "mk_win_user_cursor.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_sal.h"
#include "mk_win_tstring.h"
#include "mk_win_unicode_api.h"


mk_win_base_dll_import mk_win_user_cursor_t mk_win_base_stdcall LoadCursorA(mk_win_sal_in_opt mk_win_base_instance_t, mk_win_sal_in mk_win_base_pchar_lpct) mk_lang_noexcept;
mk_win_base_dll_import mk_win_user_cursor_t mk_win_base_stdcall LoadCursorW(mk_win_sal_in_opt mk_win_base_instance_t, mk_win_sal_in mk_win_base_wchar_lpct) mk_lang_noexcept;


mk_lang_jumbo mk_win_user_cursor_t mk_win_user_cursor_a_load_by_name(mk_win_base_instance_t const instance, mk_win_base_pchar_lpct const name) mk_lang_noexcept
{
	mk_win_user_cursor_t cursor;

	cursor = LoadCursorA(instance, name);
	return cursor;
}

mk_lang_jumbo mk_win_user_cursor_t mk_win_user_cursor_a_load_by_id(mk_win_user_cursor_id_t const id) mk_lang_noexcept
{
	mk_win_user_cursor_t cursor;

	cursor = LoadCursorA(mk_lang_null, ((mk_win_base_pchar_lpct)(((mk_win_base_uintptr_t)(id)))));
	return cursor;
}


mk_lang_jumbo mk_win_user_cursor_t mk_win_user_cursor_w_load_by_name(mk_win_base_instance_t const instance, mk_win_base_wchar_lpct const name) mk_lang_noexcept
{
	mk_win_user_cursor_t cursor;

	cursor = LoadCursorW(instance, name);
	return cursor;
}

mk_lang_jumbo mk_win_user_cursor_t mk_win_user_cursor_w_load_by_id(mk_win_user_cursor_id_t const id) mk_lang_noexcept
{
	mk_win_user_cursor_t cursor;

	cursor = LoadCursorW(mk_lang_null, ((mk_win_base_wchar_lpct)(((mk_win_base_uintptr_t)(id)))));
	return cursor;
}


mk_lang_jumbo mk_win_user_cursor_t mk_win_user_cursor_t_load_by_name(mk_win_base_instance_t const instance, mk_win_tstring_tchar_lpct const name) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_cursor_a_load_by_name(instance, name);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_user_cursor_a_load_by_name(instance, mk_win_tstring_tstr_to_ansi_zt_nofail(name).m_str);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_cursor_w_load_by_name(instance, name);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_user_cursor_w_load_by_name(instance, mk_win_tstring_tstr_to_wide_zt_nofail(name).m_str);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_cursor_a_load_by_name(instance, name);
		#else
			return mk_win_user_cursor_a_load_by_name(instance, mk_win_tstring_tstr_to_ansi_zt_nofail(name).m_str);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_cursor_w_load_by_name(instance, name);
		#else
			return mk_win_user_cursor_w_load_by_name(instance, mk_win_tstring_tstr_to_wide_zt_nofail(name).m_str);
		#endif
	}
#endif
}

mk_lang_jumbo mk_win_user_cursor_t mk_win_user_cursor_t_load_by_id(mk_win_user_cursor_id_t const id) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_cursor_a_load_by_id(id);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_user_cursor_a_load_by_id(id);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_cursor_w_load_by_id(id);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_user_cursor_w_load_by_id(id);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_cursor_a_load_by_id(id);
		#else
			return mk_win_user_cursor_a_load_by_id(id);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_cursor_w_load_by_id(id);
		#else
			return mk_win_user_cursor_w_load_by_id(id);
		#endif
	}
#endif
}