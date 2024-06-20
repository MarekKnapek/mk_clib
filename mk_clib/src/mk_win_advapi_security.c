#include "mk_win_advapi_security.h"

#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall OpenProcessToken(mk_win_base_handle_t const process, mk_win_base_dword_t const desired_access, mk_win_base_handle_pt const token) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall LookupPrivilegeValueW(mk_win_base_wchar_lpct const system_name, mk_win_base_wchar_lpct const privilege_name, mk_win_base_luid_pt const luid) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall AdjustTokenPrivileges(mk_win_base_handle_t const token, mk_win_base_bool_t const disable_all, mk_win_advapi_security_token_privileges_pct const new_state, mk_win_base_dword_t const old_len, mk_win_advapi_security_token_privileges_pt const old_state, mk_win_base_dword_pt const nwritten) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_security_open_process_token(mk_win_base_handle_t const process, mk_win_base_dword_t const desired_access, mk_win_base_handle_pt const token) mk_lang_noexcept
{
	mk_win_base_bool_t r;

	r = OpenProcessToken(process, desired_access, token);
	return r;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_security_lookup_privilege_value_w(mk_win_base_wchar_lpct const system_name, mk_win_base_wchar_lpct const privilege_name, mk_win_base_luid_pt const luid) mk_lang_noexcept
{
	mk_win_base_bool_t r;

	r = LookupPrivilegeValueW(system_name, privilege_name, luid);
	return r;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_security_adjust_token_privileges(mk_win_base_handle_t const token, mk_win_base_bool_t const disable_all, mk_win_advapi_security_token_privileges_pct const new_state, mk_win_base_dword_t const old_len, mk_win_advapi_security_token_privileges_pt const old_state, mk_win_base_dword_pt const nwritten) mk_lang_noexcept
{
	mk_win_base_bool_t r;

	r = AdjustTokenPrivileges(token, disable_all, new_state, old_len, old_state, nwritten);
	return r;
}
