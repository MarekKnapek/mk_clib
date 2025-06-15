#ifndef mk_include_guard_mk_iip_cp_packet_tcp_h
#define mk_include_guard_mk_iip_cp_packet_tcp_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_struct.h"
#include "mk_lang_types.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"


#define mk_sl_fixed_vector2_t_name mk_iip_cp_packet_tcp_nacks
#define mk_sl_fixed_vector2_t_element mk_sl_cui_uint32_t
#define mk_sl_fixed_vector2_t_count 0xff
#include "mk_sl_fixed_vector2_inl_fileh.h"
#include "mk_sl_fixed_vector2_inl_fileu.h"

#define mk_sl_fixed_vector2_t_name mk_iip_cp_packet_tcp_buffer
#define mk_sl_fixed_vector2_t_element mk_sl_cui_uint8_t
#define mk_sl_fixed_vector2_t_count 0xffff + 1
#include "mk_sl_fixed_vector2_inl_fileh.h"
#include "mk_sl_fixed_vector2_inl_fileu.h"


mk_lang_struct_forward(mk_iip_cp_type_destination_with_cert);


enum mk_iip_cp_packet_tcp_flags_e
{
	mk_iip_cp_packet_tcp_flags_e_none = 0,
	mk_iip_cp_packet_tcp_flags_e_synchronize              = 0x0001,
	mk_iip_cp_packet_tcp_flags_e_close                    = 0x0002,
	mk_iip_cp_packet_tcp_flags_e_reset                    = 0x0004,
	mk_iip_cp_packet_tcp_flags_e_signature_included       = 0x0008,
	mk_iip_cp_packet_tcp_flags_e_signature_requested      = 0x0010,
	mk_iip_cp_packet_tcp_flags_e_from_included            = 0x0020,
	mk_iip_cp_packet_tcp_flags_e_delay_requested          = 0x0040,
	mk_iip_cp_packet_tcp_flags_e_max_packet_size_included = 0x0080,
	mk_iip_cp_packet_tcp_flags_e_profile_interactive      = 0x0100,
	mk_iip_cp_packet_tcp_flags_e_echo                     = 0x0200,
	mk_iip_cp_packet_tcp_flags_e_no_ack                   = 0x0400,
	mk_iip_cp_packet_tcp_flags_e_offline_signature        = 0x0800,
	mk_iip_cp_packet_tcp_flags_e_future_flag_c            = 0x1000,
	mk_iip_cp_packet_tcp_flags_e_future_flag_d            = 0x2000,
	mk_iip_cp_packet_tcp_flags_e_future_flag_e            = 0x4000,
	mk_iip_cp_packet_tcp_flags_e_future_flag_f            = 0x8000,
	mk_iip_cp_packet_tcp_flags_e_dummy_end = -1
};
typedef enum mk_iip_cp_packet_tcp_flags_e mk_iip_cp_packet_tcp_flags_t;


struct mk_iip_cp_packet_tcp_s
{
	mk_sl_cui_uint32_t m_local_stream_id;
	mk_sl_cui_uint32_t m_remote_stream_id;
	mk_sl_cui_uint32_t m_sequence_number;
	mk_sl_cui_uint32_t m_ack_through;
	mk_iip_cp_packet_tcp_nacks_t m_nacks;
	mk_lang_types_sint_t m_resend_delay;
	mk_iip_cp_packet_tcp_flags_t m_flags;
	mk_iip_cp_packet_tcp_buffer_t m_options_and_payload;
	mk_sl_cui_uint8_pct m_options_buf; /* mutable */
	mk_lang_types_sint_t m_options_len; /* mutable */
	mk_sl_cui_uint8_pct m_from_buf; /* mutable */
	mk_lang_types_sint_t m_from_len; /* mutable */
	mk_sl_cui_uint8_pct m_payload_buf; /* mutable */
	mk_lang_types_sint_t m_payload_len; /* mutable */
};
typedef struct mk_iip_cp_packet_tcp_s mk_iip_cp_packet_tcp_t;
mk_lang_struct_typedef(mk_iip_cp_packet_tcp);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_rw_construct(mk_iip_cp_packet_tcp_pt const packet) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_rw_destroy(mk_iip_cp_packet_tcp_pt const packet) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_rw_parse(mk_iip_cp_packet_tcp_pt const packet, mk_sl_cui_uint8_pct const databuf, mk_lang_types_sint_t const datalen, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const outlen) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_ro_serialize(mk_iip_cp_packet_tcp_pct const packet, mk_sl_cui_uint8_pt const databuf, mk_lang_types_sint_t const datalen, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const outlen) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_tcp_ro_has_flags_all(mk_iip_cp_packet_tcp_pct const packet, mk_iip_cp_packet_tcp_flags_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_tcp_ro_has_flags_any(mk_iip_cp_packet_tcp_pct const packet, mk_iip_cp_packet_tcp_flags_t const flags) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_sl_cui_uint8_pct mk_iip_cp_packet_tcp_ro_get_options_buf(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_ro_get_options_len(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_sl_cui_uint8_pct mk_iip_cp_packet_tcp_ro_get_payload_buf(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_ro_get_payload_len(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_tcp_ro_has_option_delay_requested(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_tcp_ro_has_option_from_included(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_tcp_ro_has_option_max_packet_size_included(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_tcp_ro_has_option_offline_signature(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_tcp_ro_has_option_signature_included(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_ro_get_option_delay_requested(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_ro_get_option_from_structured(mk_iip_cp_packet_tcp_pct const packet, mk_iip_cp_type_destination_with_cert_pt const from, mk_lang_types_sint_pt const outlen) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_sl_cui_uint8_pct mk_iip_cp_packet_tcp_ro_get_option_from_blob_buf(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_ro_get_option_from_blob_len(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_ro_get_option_max_packet_size(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept;
/* todo offline signature */
/* todo signature */

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_tcp_ro_is_valid(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_tcp_ro_is_initial_remote_syn(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept;


#if mk_lang_jumbo_have == 1
#include "mk_iip_cp_packet_tcp.c"
#endif
#endif
