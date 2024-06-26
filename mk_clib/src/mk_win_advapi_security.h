#ifndef mk_include_guard_mk_win_advapi_security
#define mk_include_guard_mk_win_advapi_security


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


struct mk_win_advapi_security_luid_and_attributes_s
{
	mk_win_base_luid_t m_luid;
	mk_win_base_dword_t m_attributes;
};
typedef struct mk_win_advapi_security_luid_and_attributes_s mk_win_advapi_security_luid_and_attributes_t;
typedef mk_win_advapi_security_luid_and_attributes_t const mk_win_advapi_security_luid_and_attributes_ct;
typedef mk_win_advapi_security_luid_and_attributes_t* mk_win_advapi_security_luid_and_attributes_pt;
typedef mk_win_advapi_security_luid_and_attributes_t const* mk_win_advapi_security_luid_and_attributes_pct;
typedef mk_win_advapi_security_luid_and_attributes_t mk_win_base_far* mk_win_advapi_security_luid_and_attributes_lpt;
typedef mk_win_advapi_security_luid_and_attributes_t mk_win_base_far const* mk_win_advapi_security_luid_and_attributes_lpct;
typedef mk_win_advapi_security_luid_and_attributes_t mk_win_base_near* mk_win_advapi_security_luid_and_attributes_npt;
typedef mk_win_advapi_security_luid_and_attributes_t mk_win_base_near const* mk_win_advapi_security_luid_and_attributes_npct;
typedef mk_win_advapi_security_luid_and_attributes_t* mk_lang_restrict mk_win_advapi_security_luid_and_attributes_prt;
typedef mk_win_advapi_security_luid_and_attributes_t const* mk_lang_restrict mk_win_advapi_security_luid_and_attributes_prct;
typedef mk_win_advapi_security_luid_and_attributes_t mk_win_base_far* mk_lang_restrict mk_win_advapi_security_luid_and_attributes_lprt;
typedef mk_win_advapi_security_luid_and_attributes_t mk_win_base_far const* mk_lang_restrict mk_win_advapi_security_luid_and_attributes_lprct;
typedef mk_win_advapi_security_luid_and_attributes_t mk_win_base_near* mk_lang_restrict mk_win_advapi_security_luid_and_attributes_nprt;
typedef mk_win_advapi_security_luid_and_attributes_t mk_win_base_near const* mk_lang_restrict mk_win_advapi_security_luid_and_attributes_nprct;

struct mk_win_advapi_security_token_privileges_s
{
	mk_win_base_dword_t m_count;
	mk_win_advapi_security_luid_and_attributes_t m_privileges[mk_win_base_anysize_array];
};
typedef struct mk_win_advapi_security_token_privileges_s mk_win_advapi_security_token_privileges_t;
typedef mk_win_advapi_security_token_privileges_t const mk_win_advapi_security_token_privileges_ct;
typedef mk_win_advapi_security_token_privileges_t* mk_win_advapi_security_token_privileges_pt;
typedef mk_win_advapi_security_token_privileges_t const* mk_win_advapi_security_token_privileges_pct;
typedef mk_win_advapi_security_token_privileges_t mk_win_base_far* mk_win_advapi_security_token_privileges_lpt;
typedef mk_win_advapi_security_token_privileges_t mk_win_base_far const* mk_win_advapi_security_token_privileges_lpct;
typedef mk_win_advapi_security_token_privileges_t mk_win_base_near* mk_win_advapi_security_token_privileges_npt;
typedef mk_win_advapi_security_token_privileges_t mk_win_base_near const* mk_win_advapi_security_token_privileges_npct;
typedef mk_win_advapi_security_token_privileges_t* mk_lang_restrict mk_win_advapi_security_token_privileges_prt;
typedef mk_win_advapi_security_token_privileges_t const* mk_lang_restrict mk_win_advapi_security_token_privileges_prct;
typedef mk_win_advapi_security_token_privileges_t mk_win_base_far* mk_lang_restrict mk_win_advapi_security_token_privileges_lprt;
typedef mk_win_advapi_security_token_privileges_t mk_win_base_far const* mk_lang_restrict mk_win_advapi_security_token_privileges_lprct;
typedef mk_win_advapi_security_token_privileges_t mk_win_base_near* mk_lang_restrict mk_win_advapi_security_token_privileges_nprt;
typedef mk_win_advapi_security_token_privileges_t mk_win_base_near const* mk_lang_restrict mk_win_advapi_security_token_privileges_nprct;


enum mk_win_advapi_security_privilege_attribute_e
{
	mk_win_advapi_security_privilege_attribute_e_enabled_by_default = ((mk_win_base_dword_t)(0x00000001ul)),
	mk_win_advapi_security_privilege_attribute_e_enabled            = ((mk_win_base_dword_t)(0x00000002ul)),
	mk_win_advapi_security_privilege_attribute_e_removed            = ((mk_win_base_dword_t)(0x00000004ul)),
	mk_win_advapi_security_privilege_attribute_e_used_for_access    = ((mk_win_base_dword_t)(0x80000000ul)),
	mk_win_advapi_security_privilege_attribute_e_dummy_end = 0
};
typedef enum mk_win_advapi_security_privilege_attribute_e mk_win_advapi_security_privilege_attribute_t;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_security_open_process_token(mk_win_base_handle_t const process, mk_win_base_dword_t const desired_access, mk_win_base_handle_pt const token) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_security_lookup_privilege_value_a(mk_win_base_pchar_lpct const system_name, mk_win_base_pchar_lpct const privilege_name, mk_win_base_luid_pt const luid) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_security_lookup_privilege_value_w(mk_win_base_wchar_lpct const system_name, mk_win_base_wchar_lpct const privilege_name, mk_win_base_luid_pt const luid) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_security_adjust_token_privileges(mk_win_base_handle_t const token, mk_win_base_bool_t const disable_all, mk_win_advapi_security_token_privileges_pct const new_state, mk_win_base_dword_t const old_len, mk_win_advapi_security_token_privileges_pt const old_state, mk_win_base_dword_pt const nwritten) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_advapi_security.c"
#endif
#endif
