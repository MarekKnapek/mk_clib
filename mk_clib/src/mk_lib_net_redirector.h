#ifndef mk_include_guard_mk_lib_net_redirector_h
#define mk_include_guard_mk_lib_net_redirector_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_lib_net_destination);
mk_lang_forward(mk_lib_net_redirector_impl);


struct mk_lib_net_redirector_s
{
	mk_lib_net_redirector_impl_pt m_impl;
};
typedef struct mk_lib_net_redirector_s mk_lib_net_redirector_t;
mk_lang_typedef(mk_lib_net_redirector);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_redirector_rw_construct(mk_lib_net_redirector_pt const redirector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_redirector_rw_destroy(mk_lib_net_redirector_pt const redirector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_redirector_rw_run(mk_lib_net_redirector_pt const redirector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_redirector_rw_request_stop(mk_lib_net_redirector_pt const redirector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_redirector_rw_add_redirect(mk_lib_net_redirector_pt const redirector, mk_lib_net_destination_pct const src, mk_lib_net_destination_pct const dst) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_net_redirector.c"
#endif
#endif
