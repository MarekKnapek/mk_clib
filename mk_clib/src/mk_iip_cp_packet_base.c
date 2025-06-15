#ifndef mk_include_guard_mk_iip_cp_packet_base_c
#define mk_include_guard_mk_iip_cp_packet_base_c
#include "mk_iip_cp_packet_base.h"

#include "mk_iip_cp_type.h"
#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_struct.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_base_is_compressed_ptr(mk_sl_cui_uint8_pct const databuf, mk_lang_types_sint_t const datalen) mk_lang_noexcept
{
	mk_lang_types_bool_t is;
	mk_lang_types_uchar_t tuc;

	mk_lang_assert(databuf || datalen == 0);
	mk_lang_assert(datalen >= 0);

	is =
		datalen >= 10 &&
		(mk_sl_cui_uint8_to_bi_uchar(&databuf[0], &tuc), tuc == 0x1f) &&
		(mk_sl_cui_uint8_to_bi_uchar(&databuf[1], &tuc), tuc == 0x8b) &&
		(mk_sl_cui_uint8_to_bi_uchar(&databuf[2], &tuc), tuc == 0x08) &&
		mk_lang_true;
	return is;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_packet_base_is_compressed_buf(mk_iip_cp_type_buffer_pct const data) mk_lang_noexcept
{
	mk_lang_types_bool_t is;

	is = mk_iip_cp_packet_base_is_compressed_ptr(&data->m_buf[0], data->m_len);
	return is;
}


#endif
