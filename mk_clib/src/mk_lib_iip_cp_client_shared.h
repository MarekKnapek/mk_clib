#ifndef mk_include_guard_mk_lib_iip_cp_client_shared_h
#define mk_include_guard_mk_lib_iip_cp_client_shared_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_logger.h"


struct mk_lib_iip_cp_client_shared_s
{
	mk_lib_iip_logger_t m_logger;
};
typedef struct mk_lib_iip_cp_client_shared_s mk_lib_iip_cp_client_shared_t;
mk_lang_typedef(mk_lib_iip_cp_client_shared);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_shared_rw_construct(mk_lib_iip_cp_client_shared_pt const shared) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_shared_rw_destroy(mk_lib_iip_cp_client_shared_pt const shared) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_iip_cp_client_shared.c"
#endif
#endif
