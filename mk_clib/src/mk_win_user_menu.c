#include "mk_win_user_menu.h"

#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


/*mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_menu_t mk_win_base_stdcall LoadmenuA(mk_win_base_instance_t const instance, mk_win_base_pchar_lpct const name) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_menu_t mk_win_base_stdcall LoadmenuW(mk_win_base_instance_t const instance, mk_win_base_wchar_lpct const name) mk_lang_noexcept;*/


/*mk_lang_nodiscard mk_lang_jumbo mk_win_user_menu_t mk_win_user_menu_a_load(mk_win_base_instance_t const instance, mk_win_base_pchar_lpct const name) mk_lang_noexcept
{
	mk_win_user_menu_t ret;

	ret = LoadmenuA(instance, name);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_menu_t mk_win_user_menu_w_load(mk_win_base_instance_t const instance, mk_win_base_wchar_lpct const name) mk_lang_noexcept
{
	mk_win_user_menu_t ret;

	ret = LoadmenuW(instance, name);
	return ret;
}*/