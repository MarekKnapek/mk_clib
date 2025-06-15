#ifndef mk_include_guard_mk_iip_cp_packet_base_h
#define mk_include_guard_mk_iip_cp_packet_base_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_struct.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


mk_lang_struct_forward(mk_iip_cp_type_buffer);


enum mk_iip_cp_packet_base_protocol_id_e
{
	mk_iip_cp_packet_base_protocol_id_e_streaming = 6,
	mk_iip_cp_packet_base_protocol_id_e_datagram = 17,
	mk_iip_cp_packet_base_protocol_id_e_raw = 18,
	mk_iip_cp_packet_base_protocol_id_e_dummy_end
};
typedef enum mk_iip_cp_packet_base_protocol_id_e mk_iip_cp_packet_base_protocol_id_t;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_base_is_compressed_ptr(mk_sl_cui_uint8_pct const databuf, mk_lang_types_sint_t const datalen) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_base_is_compressed_buf(mk_iip_cp_type_buffer_pct const data) mk_lang_noexcept;


#if mk_lang_jumbo_have == 1
#include "mk_iip_cp_packet_base.c"
#endif
#endif
