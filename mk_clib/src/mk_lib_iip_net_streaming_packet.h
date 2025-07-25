#ifndef mk_include_guard_mk_lib_iip_net_streaming_packet_h
#define mk_include_guard_mk_lib_iip_net_streaming_packet_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_types.h"
#include "mk_sl_cui_uint32.h"


mk_lang_forward(mk_sl_cui_uint8);


enum mk_lib_iip_net_streaming_packet_flag_e
{
	mk_lib_iip_net_streaming_packet_flag_e_none = 0,
	mk_lib_iip_net_streaming_packet_flag_e_synchronize              = 0x0001,
	mk_lib_iip_net_streaming_packet_flag_e_close                    = 0x0002,
	mk_lib_iip_net_streaming_packet_flag_e_reset                    = 0x0004,
	mk_lib_iip_net_streaming_packet_flag_e_signature_included       = 0x0008,
	mk_lib_iip_net_streaming_packet_flag_e_signature_requested      = 0x0010,
	mk_lib_iip_net_streaming_packet_flag_e_from_included            = 0x0020,
	mk_lib_iip_net_streaming_packet_flag_e_delay_requested          = 0x0040,
	mk_lib_iip_net_streaming_packet_flag_e_max_packet_size_included = 0x0080,
	mk_lib_iip_net_streaming_packet_flag_e_profile_interactive      = 0x0100,
	mk_lib_iip_net_streaming_packet_flag_e_echo                     = 0x0200,
	mk_lib_iip_net_streaming_packet_flag_e_no_ack                   = 0x0400,
	mk_lib_iip_net_streaming_packet_flag_e_offline_signature        = 0x0800,
	mk_lib_iip_net_streaming_packet_flag_e_future_flag_c            = 0x1000,
	mk_lib_iip_net_streaming_packet_flag_e_future_flag_d            = 0x2000,
	mk_lib_iip_net_streaming_packet_flag_e_future_flag_e            = 0x4000,
	mk_lib_iip_net_streaming_packet_flag_e_future_flag_f            = 0x8000,
	mk_lib_iip_net_streaming_packet_flag_e_dummy_end = -1
};
typedef enum mk_lib_iip_net_streaming_packet_flag_e mk_lib_iip_net_streaming_packet_flag_t;
mk_lang_typedef(mk_lib_iip_net_streaming_packet_flag);


#define mk_sl_fixed_vector_t_name mk_lib_iip_net_streaming_packet_nacks
#define mk_sl_fixed_vector_t_element_type mk_sl_cui_uint32_t
#define mk_sl_fixed_vector_t_capacity 0xff
#include "mk_sl_fixed_vector_inl_fileh.h"
#include "mk_sl_fixed_vector_inl_fileu.h"


#if defined DEBUG || defined _DEBUG
#define mk_lib_iip_net_streaming_packet_b32_has_extra_zero (1)
#else
#define mk_lib_iip_net_streaming_packet_b32_has_extra_zero (0)
#endif
struct mk_lib_iip_net_streaming_packet_b32_s
{
	mk_lang_types_pchar_t m_pchars[52 + mk_lib_iip_net_streaming_packet_b32_has_extra_zero];
};
typedef struct mk_lib_iip_net_streaming_packet_b32_s mk_lib_iip_net_streaming_packet_b32_t;
mk_lang_typedef(mk_lib_iip_net_streaming_packet_b32);

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_net_streaming_packet_options_s
{
	mk_sl_cui_uint8_pt m_buf;
	mk_lang_types_sint_t m_len;
	mk_lang_types_sint_t m_delay;
	mk_sl_cui_uint8_pt m_from_buf;
	mk_lang_types_sint_t m_from_len;
	mk_lib_iip_cp_types_remote_destination_t m_from;
	mk_lib_iip_net_streaming_packet_b32_t m_b32;
	mk_lang_types_sint_t m_max_packet_size;
	mk_lang_types_sint_t m_offline_signature;
};
typedef struct mk_lib_iip_net_streaming_packet_options_s mk_lib_iip_net_streaming_packet_options_t;
mk_lang_typedef(mk_lib_iip_net_streaming_packet_options);
#include "mk_lang_warning_msvc_pop.h"


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_net_streaming_packet_s
{
	mk_sl_cui_uint32_t m_send_stream_id;
	mk_sl_cui_uint32_t m_recv_stream_id;
	mk_sl_cui_uint32_t m_sequence_number;
	mk_sl_cui_uint32_t m_ack_through;
	mk_lib_iip_net_streaming_packet_nacks_t m_nacks;
	mk_lang_types_sint_t m_resend_delay;
	mk_lib_iip_net_streaming_packet_flag_t m_flags;
	mk_lib_iip_net_streaming_packet_options_t m_options;
	mk_sl_cui_uint8_pt m_signature_buf;
	mk_lang_types_sint_t m_signature_len;
	mk_sl_cui_uint8_pt m_payload_buf;
	mk_lang_types_sint_t m_payload_len;
};
typedef struct mk_lib_iip_net_streaming_packet_s mk_lib_iip_net_streaming_packet_t;
mk_lang_typedef(mk_lib_iip_net_streaming_packet);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_rw_construct(mk_lib_iip_net_streaming_packet_pt const packet) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_rw_parse(mk_lib_iip_net_streaming_packet_pt const packet, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_ro_serialize(mk_lib_iip_net_streaming_packet_pt const packet, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_ro_is_initial_in_stream(mk_lib_iip_net_streaming_packet_pct const packet, mk_lang_types_bool_pt const is) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_iip_net_streaming_packet.c"
#endif
#endif
