#include "mk_win_advapi_security.h"

#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall LookupPrivilegeValueA(mk_win_base_pchar_lpct const system_name, mk_win_base_pchar_lpct const privilege_name, mk_win_base_luid_pt const luid) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall LookupPrivilegeValueW(mk_win_base_wchar_lpct const system_name, mk_win_base_wchar_lpct const privilege_name, mk_win_base_luid_pt const luid) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_security_lookup_privilege_value_a(mk_win_base_pchar_lpct const system_name, mk_win_base_pchar_lpct const privilege_name, mk_win_base_luid_pt const luid) mk_lang_noexcept
{
	mk_win_base_bool_t r;

	r = LookupPrivilegeValueA(system_name, privilege_name, luid);
	return r;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_security_lookup_privilege_value_w(mk_win_base_wchar_lpct const system_name, mk_win_base_wchar_lpct const privilege_name, mk_win_base_luid_pt const luid) mk_lang_noexcept
{
	mk_win_base_bool_t r;

	r = LookupPrivilegeValueW(system_name, privilege_name, luid);
	return r;
}
