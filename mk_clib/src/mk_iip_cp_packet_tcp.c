#ifndef mk_include_guard_mk_iip_cp_packet_tcp_c
#define mk_include_guard_mk_iip_cp_packet_tcp_c
#include "mk_iip_cp_packet_tcp.h"

#include "mk_iip_cp_type.h"
#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_struct.h"
#include "mk_lang_types.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"


#define mk_sl_fixed_vector2_t_name mk_iip_cp_packet_tcp_nacks
#define mk_sl_fixed_vector2_t_element mk_sl_cui_uint32_t
#define mk_sl_fixed_vector2_t_count 0xff
#include "mk_sl_fixed_vector2_inl_filec.h"
#include "mk_sl_fixed_vector2_inl_fileu.h"

#define mk_sl_fixed_vector2_t_name mk_iip_cp_packet_tcp_buffer
#define mk_sl_fixed_vector2_t_element mk_sl_cui_uint8_t
#define mk_sl_fixed_vector2_t_count 0xffff + 1
#include "mk_sl_fixed_vector2_inl_filec.h"
#include "mk_sl_fixed_vector2_inl_fileu.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_rw_construct(mk_iip_cp_packet_tcp_pt const packet) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(packet);

	((mk_lang_types_void_t)(packet->m_local_stream_id));
	((mk_lang_types_void_t)(packet->m_remote_stream_id));
	((mk_lang_types_void_t)(packet->m_sequence_number));
	((mk_lang_types_void_t)(packet->m_ack_through));
	err = mk_iip_cp_packet_tcp_nacks_rw_construct(&packet->m_nacks); mk_lang_check_rereturn(err);
	((mk_lang_types_void_t)(packet->m_resend_delay));
	((mk_lang_types_void_t)(packet->m_flags));
	err = mk_iip_cp_packet_tcp_buffer_rw_construct(&packet->m_options_and_payload); mk_lang_check_rereturn(err);
	packet->m_options_buf = mk_lang_null;
	packet->m_options_len = -1;
	packet->m_from_buf = mk_lang_null;
	packet->m_from_len = -1;
	packet->m_payload_buf = mk_lang_null;
	packet->m_payload_len = -1;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_rw_destroy(mk_iip_cp_packet_tcp_pt const packet) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(packet);

	((mk_lang_types_void_t)(packet->m_local_stream_id));
	((mk_lang_types_void_t)(packet->m_remote_stream_id));
	((mk_lang_types_void_t)(packet->m_sequence_number));
	((mk_lang_types_void_t)(packet->m_ack_through));
	err = mk_iip_cp_packet_tcp_nacks_rw_destroy(&packet->m_nacks); mk_lang_check_rereturn(err);
	((mk_lang_types_void_t)(packet->m_resend_delay));
	((mk_lang_types_void_t)(packet->m_flags));
	err = mk_iip_cp_packet_tcp_buffer_rw_destroy(&packet->m_options_and_payload); mk_lang_check_rereturn(err);
	((mk_lang_types_void_t)(packet->m_options_buf));
	((mk_lang_types_void_t)(packet->m_options_len));
	((mk_lang_types_void_t)(packet->m_from_buf));
	((mk_lang_types_void_t)(packet->m_from_len));
	((mk_lang_types_void_t)(packet->m_payload_buf));
	((mk_lang_types_void_t)(packet->m_payload_len));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_rw_parse(mk_iip_cp_packet_tcp_pt const packet, mk_sl_cui_uint8_pct const databuf, mk_lang_types_sint_t const datalen, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const outlen) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t nacks_count;
	mk_sl_cui_uint32_pt nacks_buf;
	mk_lang_types_sint_t i;
	mk_sl_cui_uint16_t tu16;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t options_len;
	mk_lang_types_sint_t options_and_payload_len;
	mk_sl_cui_uint8_pct options_and_payload_buf;

	mk_lang_assert(packet);
	mk_lang_assert(databuf || datalen == 0);
	mk_lang_assert(datalen >= 0);
	mk_lang_assert(gud);
	mk_lang_assert(outlen);

	err = mk_iip_cp_packet_tcp_rw_destroy(packet); mk_lang_check_rereturn(err);
	err = mk_iip_cp_packet_tcp_rw_construct(packet); mk_lang_check_rereturn(err);
	ptr = 0; rem = datalen;
	if(!(rem >= mk_sl_cui_uint32_sizebytes_v)){ *gud = mk_lang_false; return 0; } mk_sl_uint_32_from_8_be(&packet->m_local_stream_id, &databuf[ptr]); ptr += mk_sl_cui_uint32_sizebytes_v; rem -= mk_sl_cui_uint32_sizebytes_v;
	if(!(rem >= mk_sl_cui_uint32_sizebytes_v)){ *gud = mk_lang_false; return 0; } mk_sl_uint_32_from_8_be(&packet->m_remote_stream_id, &databuf[ptr]); ptr += mk_sl_cui_uint32_sizebytes_v; rem -= mk_sl_cui_uint32_sizebytes_v;
	if(!(rem >= mk_sl_cui_uint32_sizebytes_v)){ *gud = mk_lang_false; return 0; } mk_sl_uint_32_from_8_be(&packet->m_sequence_number, &databuf[ptr]); ptr += mk_sl_cui_uint32_sizebytes_v; rem -= mk_sl_cui_uint32_sizebytes_v;
	if(!(rem >= mk_sl_cui_uint32_sizebytes_v)){ *gud = mk_lang_false; return 0; } mk_sl_uint_32_from_8_be(&packet->m_ack_through, &databuf[ptr]); ptr += mk_sl_cui_uint32_sizebytes_v; rem -= mk_sl_cui_uint32_sizebytes_v;
	if(!(rem >= mk_sl_cui_uint8_sizebytes_v)){ *gud = mk_lang_false; return 0; } mk_sl_cui_uint8_to_bi_sint(&databuf[ptr], &nacks_count); ptr += mk_sl_cui_uint8_sizebytes_v; rem -= mk_sl_cui_uint8_sizebytes_v;
	err = mk_iip_cp_packet_tcp_nacks_rw_push_back_void_many(&packet->m_nacks, nacks_count); mk_lang_check_rereturn(err);
	nacks_buf = mk_iip_cp_packet_tcp_nacks_rw_data(&packet->m_nacks); mk_lang_assert(nacks_buf);
	for(i = 0; i != nacks_count; ++i)
	{
		if(!(rem >= mk_sl_cui_uint32_sizebytes_v)){ *gud = mk_lang_false; return 0; } mk_sl_uint_32_from_8_be(&nacks_buf[i], &databuf[ptr]); ptr += mk_sl_cui_uint32_sizebytes_v; rem -= mk_sl_cui_uint32_sizebytes_v;
	}
	if(!(rem >= mk_sl_cui_uint8_sizebytes_v)){ *gud = mk_lang_false; return 0; } mk_sl_cui_uint8_to_bi_sint(&databuf[ptr], &packet->m_resend_delay); ptr += mk_sl_cui_uint8_sizebytes_v; rem -= mk_sl_cui_uint8_sizebytes_v;
	if(!(rem >= mk_sl_cui_uint16_sizebytes_v)){ *gud = mk_lang_false; return 0; } mk_sl_uint_16_from_8_be(&tu16, &databuf[ptr]); ptr += mk_sl_cui_uint16_sizebytes_v; rem -= mk_sl_cui_uint16_sizebytes_v; mk_sl_cui_uint16_to_bi_sint(&tu16, &tsi); packet->m_flags = ((mk_iip_cp_packet_tcp_flags_t)(tsi));
	if(!(rem >= mk_sl_cui_uint16_sizebytes_v)){ *gud = mk_lang_false; return 0; } mk_sl_uint_16_from_8_be(&tu16, &databuf[ptr]); ptr += mk_sl_cui_uint16_sizebytes_v; rem -= mk_sl_cui_uint16_sizebytes_v; mk_sl_cui_uint16_to_bi_sint(&tu16, &options_len);
	options_and_payload_len = rem;
	if(!(rem >= options_len)){ *gud = mk_lang_false; return 0; } mk_iip_cp_packet_tcp_buffer_rw_push_back_many(&packet->m_options_and_payload, &databuf[ptr], rem); ptr += rem; rem -= rem;
	if(options_and_payload_len != 0)
	{
		options_and_payload_buf = mk_iip_cp_packet_tcp_buffer_ro_data(&packet->m_options_and_payload); mk_lang_assert(options_and_payload_buf);
		packet->m_options_buf = options_and_payload_buf;
		packet->m_options_len = options_len;
		packet->m_payload_buf = options_and_payload_buf + options_len;
		packet->m_payload_len = options_and_payload_len - options_len;
	}
	else
	{
		packet->m_options_buf = mk_lang_null;
		packet->m_options_len = 0;
		packet->m_payload_buf = mk_lang_null;
		packet->m_payload_len = 0;
	}
	*gud = mk_lang_true;
	*outlen = datalen - rem;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_ro_serialize(mk_iip_cp_packet_tcp_pct const packet, mk_sl_cui_uint8_pt const databuf, mk_lang_types_sint_t const datalen, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const outlen) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t nacks_count;
	mk_sl_cui_uint32_pct nacks_buf;
	mk_lang_types_sint_t i;
	mk_lang_types_ushort_t tus;
	mk_sl_cui_uint16_t tu16;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t options_and_payload_len;
	mk_sl_cui_uint8_pct options_and_payload_buf;

	mk_lang_assert(packet);
	mk_lang_assert(databuf || datalen == 0);
	mk_lang_assert(datalen >= 0);
	mk_lang_assert(gud);
	mk_lang_assert(outlen);
	mk_lang_assert(mk_iip_cp_packet_tcp_nacks_ro_size(&packet->m_nacks) >= 0x00);
	mk_lang_assert(mk_iip_cp_packet_tcp_nacks_ro_size(&packet->m_nacks) <= 0xff);

	ptr = 0; rem = datalen;
	if(!(rem >= mk_sl_cui_uint32_sizebytes_v)){ *gud = mk_lang_false; return 0; } mk_sl_uint_32_to_8_be(&packet->m_local_stream_id, &databuf[ptr]); ptr += mk_sl_cui_uint32_sizebytes_v; rem -= mk_sl_cui_uint32_sizebytes_v;
	if(!(rem >= mk_sl_cui_uint32_sizebytes_v)){ *gud = mk_lang_false; return 0; } mk_sl_uint_32_to_8_be(&packet->m_remote_stream_id, &databuf[ptr]); ptr += mk_sl_cui_uint32_sizebytes_v; rem -= mk_sl_cui_uint32_sizebytes_v;
	if(!(rem >= mk_sl_cui_uint32_sizebytes_v)){ *gud = mk_lang_false; return 0; } mk_sl_uint_32_to_8_be(&packet->m_sequence_number, &databuf[ptr]); ptr += mk_sl_cui_uint32_sizebytes_v; rem -= mk_sl_cui_uint32_sizebytes_v;
	if(!(rem >= mk_sl_cui_uint32_sizebytes_v)){ *gud = mk_lang_false; return 0; } mk_sl_uint_32_to_8_be(&packet->m_ack_through, &databuf[ptr]); ptr += mk_sl_cui_uint32_sizebytes_v; rem -= mk_sl_cui_uint32_sizebytes_v;
	nacks_count = ((mk_lang_types_sint_t)(mk_iip_cp_packet_tcp_nacks_ro_size(&packet->m_nacks)));
	if(!(rem >= mk_sl_cui_uint8_sizebytes_v)){ *gud = mk_lang_false; return 0; } mk_sl_cui_uint8_from_bi_sint(&databuf[ptr], &nacks_count); ptr += mk_sl_cui_uint8_sizebytes_v; rem -= mk_sl_cui_uint8_sizebytes_v;
	if(nacks_count != 0)
	{
		nacks_buf = mk_iip_cp_packet_tcp_nacks_ro_data(&packet->m_nacks); mk_lang_assert(nacks_buf);
		for(i = 0; i != nacks_count; ++i)
		{
			if(!(rem >= mk_sl_cui_uint32_sizebytes_v)){ *gud = mk_lang_false; return 0; } mk_sl_uint_32_to_8_be(&nacks_buf[i], &databuf[ptr]); ptr += mk_sl_cui_uint32_sizebytes_v; rem -= mk_sl_cui_uint32_sizebytes_v;
		}
	}
	if(!(rem >= mk_sl_cui_uint8_sizebytes_v)){ *gud = mk_lang_false; return 0; } mk_sl_cui_uint8_from_bi_sint(&databuf[ptr], &packet->m_resend_delay); ptr += mk_sl_cui_uint8_sizebytes_v; rem -= mk_sl_cui_uint8_sizebytes_v;
	if(!(rem >= mk_sl_cui_uint16_sizebytes_v)){ *gud = mk_lang_false; return 0; } tus = ((mk_lang_types_ushort_t)(packet->m_flags)); mk_sl_cui_uint16_from_bi_ushort(&tu16, &tus); mk_sl_uint_16_to_8_be(&tu16, &databuf[ptr]); ptr += mk_sl_cui_uint16_sizebytes_v; rem -= mk_sl_cui_uint16_sizebytes_v; mk_sl_cui_uint16_to_bi_sint(&tu16, &tsi);
	if(!(rem >= mk_sl_cui_uint16_sizebytes_v)){ *gud = mk_lang_false; return 0; } tus = ((mk_lang_types_ushort_t)(mk_iip_cp_packet_tcp_ro_get_options_len(packet))); mk_sl_cui_uint16_from_bi_ushort(&tu16, &tus); mk_sl_uint_16_to_8_be(&tu16, &databuf[ptr]); ptr += mk_sl_cui_uint16_sizebytes_v; rem -= mk_sl_cui_uint16_sizebytes_v;
	options_and_payload_len = ((mk_lang_types_sint_t)(mk_iip_cp_packet_tcp_buffer_ro_size(&packet->m_options_and_payload)));
	if(options_and_payload_len != 0)
	{
		options_and_payload_buf = mk_iip_cp_packet_tcp_buffer_ro_data(&packet->m_options_and_payload); mk_lang_assert(options_and_payload_buf);
		if(!(rem >= options_and_payload_len)){ *gud = mk_lang_false; return 0; } mk_sl_cui_uint8_memcpy(&databuf[ptr], &options_and_payload_buf[0], options_and_payload_len); ptr += rem; rem -= options_and_payload_len;
	}
	*gud = mk_lang_true;
	*outlen = datalen - rem;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_tcp_ro_has_flags_all(mk_iip_cp_packet_tcp_pct const packet, mk_iip_cp_packet_tcp_flags_t const flags) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	mk_lang_assert(packet);

	has = (packet->m_flags & flags) == flags;
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_tcp_ro_has_flags_any(mk_iip_cp_packet_tcp_pct const packet, mk_iip_cp_packet_tcp_flags_t const flags) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	mk_lang_assert(packet);

	has = (packet->m_flags & flags) != 0;
	return has;
}


mk_lang_nodiscard mk_lang_jumbo mk_sl_cui_uint8_pct mk_iip_cp_packet_tcp_ro_get_options_buf(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct buf;

	mk_lang_assert(packet);

	buf = packet->m_options_buf;
	return buf;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_ro_get_options_len(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept
{
	mk_lang_types_sint_t len;

	mk_lang_assert(packet);

	len = packet->m_options_len;
	return len;
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_cui_uint8_pct mk_iip_cp_packet_tcp_ro_get_payload_buf(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct buf;

	mk_lang_assert(packet);

	buf = packet->m_payload_buf;
	return buf;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_ro_get_payload_len(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept
{
	mk_lang_types_sint_t len;

	mk_lang_assert(packet);

	len = packet->m_payload_len;
	return len;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_tcp_ro_has_option_delay_requested(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	mk_lang_assert(packet);

	has = (packet->m_flags & mk_iip_cp_packet_tcp_flags_e_delay_requested) != 0;
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_tcp_ro_has_option_from_included(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	mk_lang_assert(packet);

	has = (packet->m_flags & mk_iip_cp_packet_tcp_flags_e_from_included) != 0;
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_tcp_ro_has_option_max_packet_size_included(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	mk_lang_assert(packet);

	has = (packet->m_flags & mk_iip_cp_packet_tcp_flags_e_max_packet_size_included) != 0;
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_tcp_ro_has_option_offline_signature(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	mk_lang_assert(packet);

	has = (packet->m_flags & mk_iip_cp_packet_tcp_flags_e_offline_signature) != 0;
	return has;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_tcp_ro_has_option_signature_included(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept
{
	mk_lang_types_bool_t has;

	mk_lang_assert(packet);

	has = (packet->m_flags & mk_iip_cp_packet_tcp_flags_e_signature_included) != 0;
	return has;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_ro_get_option_delay_requested(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept
{
	mk_sl_cui_uint16_t tu16;
	mk_lang_types_sint_t delay;

	mk_lang_assert(packet);
	mk_lang_assert(mk_iip_cp_packet_tcp_ro_has_option_delay_requested(packet));
	mk_lang_assert(packet->m_options_len >= 0 + mk_sl_cui_uint16_sizebytes_v);
	mk_lang_assert(packet->m_options_buf);

	mk_sl_uint_16_from_8_be(&tu16, &packet->m_options_buf[0]);
	mk_sl_cui_uint16_to_bi_sint(&tu16, &delay);
	return delay;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_ro_get_option_from_structured(mk_iip_cp_packet_tcp_pct const packet, mk_iip_cp_type_destination_with_cert_pt const from, mk_lang_types_sint_pt const outlen) mk_lang_noexcept
{
	mk_lang_types_sint_t offset;
	mk_lang_types_sint_t options_rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t olen;

	mk_lang_assert(packet);
	mk_lang_assert(from);
	mk_lang_assert(outlen);
	mk_lang_assert(mk_iip_cp_packet_tcp_ro_has_option_from_included(packet));
	mk_lang_assert(packet->m_options_buf);

	offset = 0;
	if(mk_iip_cp_packet_tcp_ro_has_option_delay_requested(packet)){ offset += mk_sl_cui_uint16_sizebytes_v; }
	options_rem = packet->m_options_len - offset;
	err = mk_iip_cp_type_destination_with_cert_from_u8s(from, &packet->m_options_buf[offset], options_rem, &olen); mk_lang_check_rereturn(err);
	*outlen = olen;
	((mk_iip_cp_packet_tcp_pt)(packet))->m_from_buf = &packet->m_options_buf[offset]; /* mutable */
	((mk_iip_cp_packet_tcp_pt)(packet))->m_from_len = olen; /* mutable */
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_cui_uint8_pct mk_iip_cp_packet_tcp_ro_get_option_from_blob_buf(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_type_destination_with_cert_t structured;
	mk_lang_types_sint_t outlen;
	mk_sl_cui_uint8_pct buf;

	mk_lang_assert(packet);

	if(!packet->m_from_buf && packet->m_from_len == 0)
	{
		err = mk_iip_cp_packet_tcp_ro_get_option_from_structured(packet, &structured, &outlen); mk_lang_check_recrash(err); mk_lang_assert(outlen == packet->m_from_len);
	}
	mk_lang_assert(packet->m_from_buf);
	mk_lang_assert(packet->m_from_len != 0);
	buf = packet->m_from_buf;
	return buf;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_ro_get_option_from_blob_len(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_type_destination_with_cert_t structured;
	mk_lang_types_sint_t outlen;
	mk_lang_types_sint_t len;

	mk_lang_assert(packet);

	if(!packet->m_from_buf && packet->m_from_len == 0)
	{
		err = mk_iip_cp_packet_tcp_ro_get_option_from_structured(packet, &structured, &outlen); mk_lang_check_rereturn(err); mk_lang_assert(outlen == packet->m_from_len);
	}
	mk_lang_assert(packet->m_from_buf);
	mk_lang_assert(packet->m_from_len != 0);
	len = packet->m_from_len;
	return len;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_packet_tcp_ro_get_option_max_packet_size(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept
{
	mk_lang_types_sint_t offset;
	mk_lang_types_sint_t err;
	mk_iip_cp_type_destination_with_cert_t structured;
	mk_lang_types_sint_t options_rem;
	mk_sl_cui_uint16_t tu16;
	mk_lang_types_sint_t max_packet_size;

	mk_lang_assert(packet);
	mk_lang_assert(mk_iip_cp_packet_tcp_ro_has_option_max_packet_size_included(packet));

	offset = 0;
	if(mk_iip_cp_packet_tcp_ro_has_option_delay_requested(packet)){ offset += mk_sl_cui_uint16_sizebytes_v; }
	if(mk_iip_cp_packet_tcp_ro_has_option_from_included(packet)){ if(packet->m_from_len == -1){ err = mk_iip_cp_packet_tcp_ro_get_option_from_structured(packet, &structured, &((mk_iip_cp_packet_tcp_pt)(packet))->m_from_len); /* mutable */ mk_lang_check_rereturn(err); } offset += packet->m_from_len; }
	options_rem = packet->m_options_len - offset;
	mk_lang_assert(packet->m_options_len >= offset + mk_sl_cui_uint16_sizebytes_v);
	mk_sl_uint_16_from_8_be(&tu16, &packet->m_options_buf[offset]);
	mk_sl_cui_uint16_to_bi_sint(&tu16, &max_packet_size);
	return max_packet_size;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_tcp_ro_is_valid(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept
{
	mk_lang_types_bool_t is;

	mk_lang_assert(packet);

	is = !mk_iip_cp_packet_tcp_ro_has_flags_any(packet, ((mk_iip_cp_packet_tcp_flags_t)(mk_iip_cp_packet_tcp_flags_e_future_flag_c | mk_iip_cp_packet_tcp_flags_e_future_flag_d | mk_iip_cp_packet_tcp_flags_e_future_flag_e | mk_iip_cp_packet_tcp_flags_e_future_flag_f)));
	return is;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_tcp_ro_is_initial_remote_syn(mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept
{
	mk_lang_types_usize_t nacks_count;
	mk_lang_types_bool_t is;

	mk_lang_assert(packet);

	nacks_count = mk_iip_cp_packet_tcp_nacks_ro_size(&packet->m_nacks);
	is =
		mk_sl_cui_uint32_is_zero(&packet->m_local_stream_id) &&
		mk_sl_cui_uint32_is_zero(&packet->m_sequence_number) &&
		(nacks_count == 0 || nacks_count == 8) &&
		mk_iip_cp_packet_tcp_ro_has_flags_all(packet, ((mk_iip_cp_packet_tcp_flags_t)(
			mk_iip_cp_packet_tcp_flags_e_synchronize |
			mk_iip_cp_packet_tcp_flags_e_signature_included |
			mk_iip_cp_packet_tcp_flags_e_from_included |
			mk_iip_cp_packet_tcp_flags_e_max_packet_size_included |
			mk_iip_cp_packet_tcp_flags_e_no_ack |
			mk_iip_cp_packet_tcp_flags_e_none)));
	return is;
}


#endif
