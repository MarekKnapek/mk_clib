#ifndef mk_include_guard_mk_win_advapi_token
#define mk_include_guard_mk_win_advapi_token


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_win_advapi_security.h"
#include "mk_win_base.h"


mk_win_base_make_handle(mk_win_advapi_token)


enum mk_win_advapi_token_access_rights_e
{
	mk_win_advapi_token_access_rights_e_assign_primary    = 0x0001ul,
	mk_win_advapi_token_access_rights_e_duplicate         = 0x0002ul,
	mk_win_advapi_token_access_rights_e_impersonate       = 0x0004ul,
	mk_win_advapi_token_access_rights_e_query             = 0x0008ul,
	mk_win_advapi_token_access_rights_e_query_source      = 0x0010ul,
	mk_win_advapi_token_access_rights_e_adjust_privileges = 0x0020ul,
	mk_win_advapi_token_access_rights_e_adjust_groups     = 0x0040ul,
	mk_win_advapi_token_access_rights_e_adjust_default    = 0x0080ul,
	mk_win_advapi_token_access_rights_e_adjust_sessionid  = 0x0100ul,
	mk_win_advapi_token_access_rights_e_dummy_end
};
typedef enum mk_win_advapi_token_access_rights_e mk_win_advapi_token_access_rights_t;

enum mk_win_advapi_token_info_e
{
	mk_win_advapi_token_info_e_user = 1,
	mk_win_advapi_token_info_e_groups,
	mk_win_advapi_token_info_e_privileges,
	mk_win_advapi_token_info_e_owner,
	mk_win_advapi_token_info_e_primarygroup,
	mk_win_advapi_token_info_e_defaultdacl,
	mk_win_advapi_token_info_e_source,
	mk_win_advapi_token_info_e_type,
	mk_win_advapi_token_info_e_impersonationlevel,
	mk_win_advapi_token_info_e_statistics,
	mk_win_advapi_token_info_e_restrictedsids,
	mk_win_advapi_token_info_e_sessionid,
	mk_win_advapi_token_info_e_groupsandprivileges,
	mk_win_advapi_token_info_e_sessionreference,
	mk_win_advapi_token_info_e_sandboxinert,
	mk_win_advapi_token_info_e_auditpolicy,
	mk_win_advapi_token_info_e_origin,
	mk_win_advapi_token_info_e_elevationtype,
	mk_win_advapi_token_info_e_linkedtoken,
	mk_win_advapi_token_info_e_elevation,
	mk_win_advapi_token_info_e_hasrestrictions,
	mk_win_advapi_token_info_e_accessinformation,
	mk_win_advapi_token_info_e_virtualizationallowed,
	mk_win_advapi_token_info_e_virtualizationenabled,
	mk_win_advapi_token_info_e_integritylevel,
	mk_win_advapi_token_info_e_uiaccess,
	mk_win_advapi_token_info_e_mandatorypolicy,
	mk_win_advapi_token_info_e_logonsid,
	mk_win_advapi_token_info_e_isappcontainer,
	mk_win_advapi_token_info_e_capabilities,
	mk_win_advapi_token_info_e_appcontainersid,
	mk_win_advapi_token_info_e_appcontainernumber,
	mk_win_advapi_token_info_e_userclaimattributes,
	mk_win_advapi_token_info_e_deviceclaimattributes,
	mk_win_advapi_token_info_e_restricteduserclaimattributes,
	mk_win_advapi_token_info_e_restricteddeviceclaimattributes,
	mk_win_advapi_token_info_e_devicegroups,
	mk_win_advapi_token_info_e_restricteddevicegroups,
	mk_win_advapi_token_info_e_securityattributes,
	mk_win_advapi_token_info_e_isrestricted,
	mk_win_advapi_token_info_e_processtrustlevel,
	mk_win_advapi_token_info_e_privatenamespace,
	mk_win_advapi_token_info_e_singletonattributes,
	mk_win_advapi_token_info_e_bnoisolation,
	mk_win_advapi_token_info_e_childprocessflags,
	mk_win_advapi_token_info_e_islessprivilegedappcontainer,
	mk_win_advapi_token_info_e_issandboxed,
	mk_win_advapi_token_info_e_isappsilo,
	mk_win_advapi_token_info_e_dummy_end
};
typedef enum mk_win_advapi_token_info_e mk_win_advapi_token_info_t;

enum mk_win_advapi_token_info_elevation_type_e
{
  mk_win_advapi_token_info_elevation_type_e_default = 1,
  mk_win_advapi_token_info_elevation_type_e_full,
  mk_win_advapi_token_info_elevation_type_e_limited,
	mk_win_advapi_token_info_elevation_type_e_dummy_end
};
typedef enum mk_win_advapi_token_info_elevation_type_e mk_win_advapi_token_info_elevation_type_t;


struct mk_win_advapi_token_privileges_s
{
	mk_win_base_dword_t m_count;
	mk_win_advapi_security_luid_and_attributes_t m_privileges[mk_win_base_anysize_array];
};
typedef struct mk_win_advapi_token_privileges_s mk_win_advapi_token_privileges_t;
typedef mk_win_advapi_token_privileges_t const mk_win_advapi_token_privileges_ct;
typedef mk_win_advapi_token_privileges_t* mk_win_advapi_token_privileges_pt;
typedef mk_win_advapi_token_privileges_t const* mk_win_advapi_token_privileges_pct;
typedef mk_win_advapi_token_privileges_t mk_win_base_far* mk_win_advapi_token_privileges_lpt;
typedef mk_win_advapi_token_privileges_t mk_win_base_far const* mk_win_advapi_token_privileges_lpct;
typedef mk_win_advapi_token_privileges_t mk_win_base_near* mk_win_advapi_token_privileges_npt;
typedef mk_win_advapi_token_privileges_t mk_win_base_near const* mk_win_advapi_token_privileges_npct;
typedef mk_win_advapi_token_privileges_t* mk_lang_restrict mk_win_advapi_token_privileges_prt;
typedef mk_win_advapi_token_privileges_t const* mk_lang_restrict mk_win_advapi_token_privileges_prct;
typedef mk_win_advapi_token_privileges_t mk_win_base_far* mk_lang_restrict mk_win_advapi_token_privileges_lprt;
typedef mk_win_advapi_token_privileges_t mk_win_base_far const* mk_lang_restrict mk_win_advapi_token_privileges_lprct;
typedef mk_win_advapi_token_privileges_t mk_win_base_near* mk_lang_restrict mk_win_advapi_token_privileges_nprt;
typedef mk_win_advapi_token_privileges_t mk_win_base_near const* mk_lang_restrict mk_win_advapi_token_privileges_nprct;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_token_open_process(mk_win_base_handle_t const process, mk_win_base_dword_t const desired_access, mk_win_advapi_token_pt const token) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_token_open_thread(mk_win_base_handle_t const thread, mk_win_base_dword_t const desired_access, mk_win_base_bool_t const open_as_self, mk_win_advapi_token_pt const token) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_token_get_info(mk_win_advapi_token_t const token, mk_win_base_dword_t const info_id, mk_win_base_void_lpt const info_buf, mk_win_base_dword_t const info_len, mk_win_base_dword_pt const written) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_token_adjust_token_privileges(mk_win_advapi_token_t const token, mk_win_base_bool_t const disable_all, mk_win_advapi_token_privileges_pct const new_state, mk_win_base_dword_t const old_len, mk_win_advapi_token_privileges_pt const old_state, mk_win_base_dword_pt const nwritten) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_token_set_thread(mk_win_base_handle_pct const thread, mk_win_advapi_token_t const token) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_token_impersonate(mk_win_advapi_token_t const token) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_advapi_token_revert_to_sef(mk_lang_types_void_t) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_advapi_token.c"
#endif
#endif
