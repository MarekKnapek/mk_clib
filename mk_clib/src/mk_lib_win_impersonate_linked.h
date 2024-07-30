#ifndef mk_include_guard_mk_lib_win_impersonate_linked
#define mk_include_guard_mk_lib_win_impersonate_linked


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_advapi_token.h"
#include "mk_win_base.h"


struct mk_lib_win_impersonate_linked_s
{
	mk_win_advapi_token_t m_token;
	mk_lang_types_bool_t m_is_thread;
	mk_lang_types_bool_t m_did;
};
typedef struct mk_lib_win_impersonate_linked_s mk_lib_win_impersonate_linked_t;
typedef mk_lib_win_impersonate_linked_t const mk_lib_win_impersonate_linked_ct;
typedef mk_lib_win_impersonate_linked_t* mk_lib_win_impersonate_linked_pt;
typedef mk_lib_win_impersonate_linked_t const* mk_lib_win_impersonate_linked_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_win_impersonate_linked_begin(mk_lib_win_impersonate_linked_pt const impersonate_linked) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_win_impersonate_linked_end(mk_lib_win_impersonate_linked_pct const impersonate_linked) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_win_impersonate_linked.c"
#endif
#endif
