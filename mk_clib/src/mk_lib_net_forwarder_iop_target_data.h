#ifndef mk_include_guard_mk_lib_net_forwarder_iop_target_data_h
#define mk_include_guard_mk_lib_net_forwarder_iop_target_data_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


enum mk_lib_net_forwarder_iop_target_data_id_e
{
	mk_lib_net_forwarder_iop_target_data_id_e_listener,
	mk_lib_net_forwarder_iop_target_data_id_e_client,
	mk_lib_net_forwarder_iop_target_data_id_e_connector,
	mk_lib_net_forwarder_iop_target_data_id_e_dummy_end
};
typedef enum mk_lib_net_forwarder_iop_target_data_id_e mk_lib_net_forwarder_iop_target_data_id_t;
mk_lang_typedef(mk_lib_net_forwarder_iop_target_data_id);


struct mk_lib_net_forwarder_iop_target_data_s
{
	mk_lang_types_uchar_t m_id;
};
typedef struct mk_lib_net_forwarder_iop_target_data_s mk_lib_net_forwarder_iop_target_data_t;
mk_lang_typedef(mk_lib_net_forwarder_iop_target_data);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_forwarder_iop_target_data_rw_construct(mk_lib_net_forwarder_iop_target_data_pt const target, mk_lib_net_forwarder_iop_target_data_id_t const id) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_net_forwarder_iop_target_data.c"
#endif
#endif
