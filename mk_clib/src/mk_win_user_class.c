#include "mk_win_user_class.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_win_base.h"
#include "mk_win_user_base.h"
#include "mk_win_user_brush.h"
#include "mk_win_user_cursor.h"
#include "mk_win_user_icon.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_base_atom_t mk_win_base_stdcall RegisterClassA(mk_win_user_class_a_lpct const classa) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_base_atom_t mk_win_base_stdcall RegisterClassW(mk_win_user_class_w_lpct const classw) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_base_atom_t mk_win_base_stdcall RegisterClassExA(mk_win_user_class_exa_lpct const classexa) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_base_atom_t mk_win_base_stdcall RegisterClassExW(mk_win_user_class_exw_lpct const classexw) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall UnregisterClassA(mk_win_base_pchar_lpct const name, mk_win_base_instance_t const instance) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall UnregisterClassW(mk_win_base_wchar_lpct const name, mk_win_base_instance_t const instance) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_atom_t mk_win_user_class_register_a(mk_win_user_class_a_lpct const classa) mk_lang_noexcept
{
	mk_win_user_base_atom_t ret;

	ret = RegisterClassA(classa);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_atom_t mk_win_user_class_register_w(mk_win_user_class_w_lpct const classw) mk_lang_noexcept
{
	mk_win_user_base_atom_t ret;

	ret = RegisterClassW(classw);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_atom_t mk_win_user_class_register_exa(mk_win_user_class_exa_lpct const classexa) mk_lang_noexcept
{
	mk_win_user_base_atom_t ret;

	ret = RegisterClassExA(classexa);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_atom_t mk_win_user_class_register_exw(mk_win_user_class_exw_lpct const classexw) mk_lang_noexcept
{
	mk_win_user_base_atom_t ret;

	ret = RegisterClassExW(classexw);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_class_a_unregister(mk_win_base_pchar_lpct const name, mk_win_base_instance_t const instance) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = UnregisterClassA(name, instance);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_class_w_unregister(mk_win_base_wchar_lpct const name, mk_win_base_instance_t const instance) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = UnregisterClassW(name, instance);
	return ret;
}
