#include "mk_win_advapi_token.h"

#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_win_advapi_security.h"
#include "mk_win_base.h"


mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall OpenProcessToken(mk_win_base_handle_t const process, mk_win_base_dword_t const desired_access, mk_win_advapi_token_pt const token) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall OpenThreadToken(mk_win_base_handle_t const thread, mk_win_base_dword_t const desired_access, mk_win_base_bool_t const open_as_self, mk_win_advapi_token_pt const token) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetTokenInformation(mk_win_advapi_token_t const token, mk_win_base_dword_t const info_id, mk_win_base_void_lpt const info_buf, mk_win_base_dword_t const info_len, mk_win_base_dword_pt const written) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall AdjustTokenPrivileges(mk_win_advapi_token_t const token, mk_win_base_bool_t const disable_all, mk_win_advapi_token_privileges_pct const new_state, mk_win_base_dword_t const old_len, mk_win_advapi_token_privileges_pt const old_state, mk_win_base_dword_pt const nwritten) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SetThreadToken(mk_win_base_handle_pct const thread, mk_win_advapi_token_t const token) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall ImpersonateLoggedOnUser(mk_win_advapi_token_t const token) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall RevertToSelf(mk_lang_types_void_t) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_token_open_process(mk_win_base_handle_t const process, mk_win_base_dword_t const desired_access, mk_win_advapi_token_pt const token) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = OpenProcessToken(process, desired_access, token);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_token_open_thread(mk_win_base_handle_t const thread, mk_win_base_dword_t const desired_access, mk_win_base_bool_t const open_as_self, mk_win_advapi_token_pt const token) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = OpenThreadToken(thread, desired_access, open_as_self, token);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_token_get_info(mk_win_advapi_token_t const token, mk_win_base_dword_t const info_id, mk_win_base_void_lpt const info_buf, mk_win_base_dword_t const info_len, mk_win_base_dword_pt const written) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = GetTokenInformation(token, info_id, info_buf, info_len, written);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_token_adjust_token_privileges(mk_win_advapi_token_t const token, mk_win_base_bool_t const disable_all, mk_win_advapi_token_privileges_pct const new_state, mk_win_base_dword_t const old_len, mk_win_advapi_token_privileges_pt const old_state, mk_win_base_dword_pt const nwritten) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = AdjustTokenPrivileges(token, disable_all, new_state, old_len, old_state, nwritten);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_token_set_thread(mk_win_base_handle_pct const thread, mk_win_advapi_token_t const token) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = SetThreadToken(thread, token);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_token_impersonate(mk_win_advapi_token_t const token) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = ImpersonateLoggedOnUser(token);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_token_revert_to_sef(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = RevertToSelf();
	return ret;
}
