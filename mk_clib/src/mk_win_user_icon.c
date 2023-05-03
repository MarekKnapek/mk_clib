#include "mk_win_user_icon.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_sal.h"
#include "mk_win_tstring.h"
#include "mk_win_unicode_api.h"


mk_win_base_dll_import mk_win_user_icon_t mk_win_base_stdcall LoadIconA(mk_win_sal_in_opt mk_win_base_instance_t, mk_win_sal_in mk_win_base_pchar_lpct) mk_lang_noexcept;
mk_win_base_dll_import mk_win_user_icon_t mk_win_base_stdcall LoadIconW(mk_win_sal_in_opt mk_win_base_instance_t, mk_win_sal_in mk_win_base_wchar_lpct) mk_lang_noexcept;


mk_lang_jumbo mk_win_user_icon_t mk_win_user_icon_a_load_by_name(mk_win_base_instance_t const instance, mk_win_base_pchar_lpct const name) mk_lang_noexcept
{
	mk_win_user_icon_t icon;

	icon = LoadIconA(instance, name);
	return icon;
}

mk_lang_jumbo mk_win_user_icon_t mk_win_user_icon_a_load_by_id(mk_win_base_instance_t const instance, mk_win_user_icon_id_t const id) mk_lang_noexcept
{
	mk_win_user_icon_t icon;

	icon = LoadIconA(instance, ((mk_win_base_pchar_lpct)(((mk_win_base_uintptr_t)(id)))));
	return icon;
}


mk_lang_jumbo mk_win_user_icon_t mk_win_user_icon_w_load_by_name(mk_win_base_instance_t const instance, mk_win_base_wchar_lpct const name) mk_lang_noexcept
{
	mk_win_user_icon_t icon;

	icon = LoadIconW(instance, name);
	return icon;
}

mk_lang_jumbo mk_win_user_icon_t mk_win_user_icon_w_load_by_id(mk_win_base_instance_t const instance, mk_win_user_icon_id_t const id) mk_lang_noexcept
{
	mk_win_user_icon_t icon;

	icon = LoadIconW(instance, ((mk_win_base_wchar_lpct)(((mk_win_base_uintptr_t)(id)))));
	return icon;
}


mk_lang_jumbo mk_win_user_icon_t mk_win_user_icon_t_load_by_name(mk_win_base_instance_t const instance, mk_win_tstring_tchar_lpct const name) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_icon_a_load_by_name(instance, name);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_user_icon_a_load_by_name(instance, mk_win_tstring_tstr_to_ansi_zt_nofail(name).m_str);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_icon_w_load_by_name(instance, name);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_user_icon_w_load_by_name(instance, mk_win_tstring_tstr_to_wide_zt_nofail(name).m_str);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_icon_a_load_by_name(instance, name);
		#else
			return mk_win_user_icon_a_load_by_name(instance, mk_win_tstring_tstr_to_ansi_zt_nofail(name).m_str);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_icon_w_load_by_name(instance, name);
		#else
			return mk_win_user_icon_w_load_by_name(instance, mk_win_tstring_tstr_to_wide_zt_nofail(name).m_str);
		#endif
	}
#endif
}

mk_lang_jumbo mk_win_user_icon_t mk_win_user_icon_t_load_by_id(mk_win_base_instance_t const instance, mk_win_user_icon_id_t const id) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_icon_a_load_by_id(instance, id);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_user_icon_a_load_by_id(instance, id);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_icon_w_load_by_id(instance, id);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_user_icon_w_load_by_id(instance, id);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_icon_a_load_by_id(instance, id);
		#else
			return mk_win_user_icon_a_load_by_id(instance, id);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_icon_w_load_by_id(instance, id);
		#else
			return mk_win_user_icon_w_load_by_id(instance, id);
		#endif
	}
#endif
}
