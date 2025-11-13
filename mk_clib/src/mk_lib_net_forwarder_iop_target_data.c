#ifndef mk_include_guard_mk_lib_net_forwarder_iop_target_data_c
#define mk_include_guard_mk_lib_net_forwarder_iop_target_data_c
#include "mk_lib_net_forwarder_iop_target_data.h"

#include "mk_lang_assert.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_iop_target_data_prrw_construct(mk_lib_net_forwarder_iop_target_data_pt const target, mk_lib_net_forwarder_iop_target_data_id_t const id) mk_lang_noexcept
{
	mk_lang_assert(target);
	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_net_forwarder_iop_target_data_id_e_dummy_end);

	target->m_id = ((mk_lang_types_uchar_t)(id));
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_forwarder_iop_target_data_rw_construct(mk_lib_net_forwarder_iop_target_data_pt const target, mk_lib_net_forwarder_iop_target_data_id_t const id) mk_lang_noexcept
{
	return mk_lib_net_forwarder_iop_target_data_prrw_construct(target, id);
}


#endif
