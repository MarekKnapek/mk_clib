#include "mk_win_unicode_api.h"


#if mk_win_unicode_api == mk_win_unicode_api_both


#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_user_icon.h"


enum mk_win_unicode_api_is_wide_e
{
	mk_win_unicode_api_is_wide_e_unknown,
	mk_win_unicode_api_is_wide_e_wide,
	mk_win_unicode_api_is_wide_e_ansi
};
typedef enum mk_win_unicode_api_is_wide_e mk_win_unicode_api_is_wide_t;


static mk_win_unicode_api_is_wide_t g_mk_win_unicode_api = mk_win_unicode_api_is_wide_e_unknown;


static mk_lang_inline mk_lang_types_void_t mk_win_unicode_api_test(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_assert(g_mk_win_unicode_api == mk_win_unicode_api_is_wide_e_unknown);
	g_mk_win_unicode_api = mk_win_user_icon_w_load(mk_win_base_instance_get_null(), ((mk_win_base_wchar_lpct)(((mk_win_base_uintptr_t)(32512)))) /* mk_win_user_icon_id_e_application */).m_data == mk_win_base_null ? mk_win_unicode_api_is_wide_e_ansi : mk_win_unicode_api_is_wide_e_wide;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_win_unicode_api_is_wide(mk_lang_types_void_t) mk_lang_noexcept
{
	if(g_mk_win_unicode_api == mk_win_unicode_api_is_wide_e_unknown)
	{
		mk_win_unicode_api_test();
	}
	mk_lang_assert(g_mk_win_unicode_api != mk_win_unicode_api_is_wide_e_unknown);
	return g_mk_win_unicode_api == mk_win_unicode_api_is_wide_e_wide;
}


#endif
