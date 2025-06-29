#ifndef mk_include_guard_mk_lib_iip_cp_client_shared_c
#define mk_include_guard_mk_lib_iip_cp_client_shared_c
#include "mk_lib_iip_cp_client_shared.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_logger.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_shared_prrw_construct(mk_lib_iip_cp_client_shared_pt const shared) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(shared);

	err = mk_lib_iip_logger_rw_construct(&shared->m_logger, "out.html"); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_shared_prrw_destroy(mk_lib_iip_cp_client_shared_pt const shared) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(shared);

	err = mk_lib_iip_logger_rw_destroy(&shared->m_logger); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_shared_rw_construct(mk_lib_iip_cp_client_shared_pt const shared) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_shared_prrw_construct(shared);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_shared_rw_destroy(mk_lib_iip_cp_client_shared_pt const shared) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_shared_prrw_destroy(shared);
}


#endif
