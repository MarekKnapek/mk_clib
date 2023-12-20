#include "mk_win_unicode_api.h"

#if mk_win_unicode_api == mk_win_unicode_api_both

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_cpp.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_sal.h"


struct mk_win_user_icon_handle_s; typedef struct mk_win_user_icon_handle_s mk_win_user_icon_handle_t; typedef mk_win_user_icon_handle_t const* mk_win_user_icon_t;
mk_lang_extern_c mk_win_base_dll_import mk_win_user_icon_t mk_win_base_stdcall LoadIconW(mk_win_sal_in_opt mk_win_base_instance_t, mk_win_sal_in mk_win_base_wchar_lpct) mk_lang_noexcept;


enum mk_win_unicode_api_is_wide_e
{
	mk_win_unicode_api_is_wide_e_not_tested,
	mk_win_unicode_api_is_wide_e_wide,
	mk_win_unicode_api_is_wide_e_ansi
};
typedef enum mk_win_unicode_api_is_wide_e mk_win_unicode_api_is_wide_t;


static mk_win_unicode_api_is_wide_t g_mk_win_unicode_api = mk_win_unicode_api_is_wide_e_not_tested;


static void mk_win_unicode_api_test(void) mk_lang_noexcept;


mk_lang_jumbo mk_lang_bool_t mk_win_unicode_api_is_wide(void) mk_lang_noexcept
{
	if(g_mk_win_unicode_api == mk_win_unicode_api_is_wide_e_not_tested)
	{
		mk_win_unicode_api_test();
	}
	mk_lang_assert(g_mk_win_unicode_api != mk_win_unicode_api_is_wide_e_not_tested);
	return g_mk_win_unicode_api == mk_win_unicode_api_is_wide_e_wide;
}


static mk_lang_inline void mk_win_unicode_api_test(void) mk_lang_noexcept
{
	mk_lang_assert(g_mk_win_unicode_api == mk_win_unicode_api_is_wide_e_not_tested);
	g_mk_win_unicode_api = LoadIconW(mk_win_base_instance_null, ((mk_win_base_wchar_lpct)(((mk_win_base_uintptr_t)(32512)))) /* mk_win_user_icon_id_e_application */) == mk_win_base_null ? mk_win_unicode_api_is_wide_e_ansi : mk_win_unicode_api_is_wide_e_wide;
}

#endif
