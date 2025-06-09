#ifndef mk_include_guard_mk_lib_decompress_zlib_c
#define mk_include_guard_mk_lib_decompress_zlib_c
#include "mk_lib_decompress_zlib.h"

#include "mk_lang_check.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_decompress_deflate.h"
#include "mk_lib_hash_adler32.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_decompress_zlib_pr_read_block_header(mk_lib_decompress_zlib_pt const zlib, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t in_len mk_lang_constexpr_init;
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;
	mk_lang_types_sint_t to_copy mk_lang_constexpr_init;

	mk_lang_assert(zlib);
	mk_lang_assert(data_in_buf || data_in_len == 0);
	mk_lang_assert(data_in_len >= 0);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_in_consumed);
	mk_lang_assert(data_out_consumed);
	mk_lang_assert(zlib->m_stream_header_idx >= 0);
	mk_lang_assert(zlib->m_stream_header_idx <= mk_lang_countof(zlib->m_stream_header_buf));

	in_buf = data_in_buf;
	in_len = data_in_len;
	in_c = 0;
	out_c = 0;
	if(zlib->m_stream_header_idx != mk_lang_countof(zlib->m_stream_header_buf))
	{
		to_copy = mk_lang_countof(zlib->m_stream_header_buf) - zlib->m_stream_header_idx;
		to_copy = mk_lang_min(to_copy, in_len);
		mk_sl_cui_uint8_memcpy_fn(&zlib->m_stream_header_buf[zlib->m_stream_header_idx], in_buf, to_copy);
		zlib->m_stream_header_idx += to_copy;
		in_c += to_copy;
	}
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_decompress_zlib_pr_process_block_header(mk_lib_decompress_zlib_pt const zlib, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;
	mk_lang_types_sint_t byte_ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t bit_ptr mk_lang_constexpr_init;
	mk_sl_cui_uint8_t cmf mk_lang_constexpr_init;
	mk_sl_cui_uint8_t flg mk_lang_constexpr_init;
	mk_sl_cui_uint8_t mask mk_lang_constexpr_init;
	mk_sl_cui_uint8_t cm mk_lang_constexpr_init;
	mk_sl_cui_uint8_t info mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_uint8_t fcheck mk_lang_constexpr_init;
	mk_sl_cui_uint8_t fdict mk_lang_constexpr_init;
	mk_sl_cui_uint8_t flevel mk_lang_constexpr_init;

	mk_lang_assert(zlib);
	mk_lang_assert(data_in_buf || data_in_len == 0);
	mk_lang_assert(data_in_len >= 0);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_in_consumed);
	mk_lang_assert(data_out_consumed);
	mk_lang_assert(zlib->m_stream_header_idx >= 0);
	mk_lang_assert(zlib->m_stream_header_idx <= mk_lang_countof(zlib->m_stream_header_buf));

	in_c = 0;
	out_c = 0;
	if
	(
		(zlib->m_stream_header_idx == mk_lang_countof(zlib->m_stream_header_buf)) &&
		(!zlib->m_stream_header_processed)
	)
	{
		byte_ptr = 0;
		bit_ptr = 0;
		cmf = zlib->m_stream_header_buf[byte_ptr]; byte_ptr += mk_sl_cui_uint8_size_bytes_v;
		flg = zlib->m_stream_header_buf[byte_ptr]; byte_ptr += mk_sl_cui_uint8_size_bytes_v;
		mk_sl_cui_uint8_set_mask(&mask, 4);
		mk_sl_cui_uint8_shr3(&cmf, bit_ptr, &cm); bit_ptr += 4;
		mk_sl_cui_uint8_and2(&cm, &mask);
		mk_sl_cui_uint8_shr3(&cmf, bit_ptr, &info); bit_ptr += 4;
		mk_sl_cui_uint8_and2(&info, &mask);
		mk_sl_cui_uint8_to_bi_sint(&cm, &tsi); mk_lang_check_return(tsi == 8); /* deflate */
		mk_sl_cui_uint8_to_bi_sint(&info, &tsi); mk_lang_check_return(tsi <= 7); /* window size */
		bit_ptr = 0;
		mk_sl_cui_uint8_shr3(&flg, bit_ptr, &fcheck); bit_ptr += 5; mk_sl_cui_uint8_set_mask(&mask, 5); mk_sl_cui_uint8_and2(&fcheck, &mask); /* todo check check */
		mk_sl_cui_uint8_shr3(&flg, bit_ptr, &fdict); bit_ptr += 1; mk_sl_cui_uint8_set_mask(&mask, 1); mk_sl_cui_uint8_and2(&fdict, &mask); mk_lang_check_return(mk_sl_cui_uint8_is_zero(&fdict));
		mk_sl_cui_uint8_shr3(&flg, bit_ptr, &flevel); bit_ptr += 2; mk_sl_cui_uint8_set_mask(&mask, 2); mk_sl_cui_uint8_and2(&flevel, &mask);
		zlib->m_stream_header_processed = mk_lang_true;
	}
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_decompress_zlib_pr_inflate(mk_lib_decompress_zlib_pt const zlib, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t in_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t out_len mk_lang_constexpr_init;
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t inc mk_lang_constexpr_init;
	mk_lang_types_sint_t outc mk_lang_constexpr_init;

	mk_lang_assert(zlib);
	mk_lang_assert(data_in_buf || data_in_len == 0);
	mk_lang_assert(data_in_len >= 0);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_in_consumed);
	mk_lang_assert(data_out_consumed);
	mk_lang_assert(zlib->m_stream_header_idx >= 0);
	mk_lang_assert(zlib->m_stream_header_idx <= mk_lang_countof(zlib->m_stream_header_buf));

	in_buf = data_in_buf;
	in_len = data_in_len;
	out_buf = data_out_buf;
	out_len = data_out_len;
	in_c = 0;
	out_c = 0;
	if
	(
		(zlib->m_stream_header_idx == mk_lang_countof(zlib->m_stream_header_buf)) &&
		(zlib->m_stream_header_processed)
	)
	{
		err = mk_lib_decompress_deflate_append(&zlib->m_deflate, in_buf, in_len, out_buf, out_len, &inc, &outc); mk_lang_check_rereturn(err); in_c += inc; out_c += outc;
		mk_lib_hash_adler32_append(&zlib->m_adler32, out_buf, outc);
	}
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_decompress_zlib_pr_read_block_footer(mk_lib_decompress_zlib_pt const zlib, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t in_len mk_lang_constexpr_init;
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;
	mk_lang_types_sint_t to_copy mk_lang_constexpr_init;

	mk_lang_assert(zlib);
	mk_lang_assert(data_in_buf || data_in_len == 0);
	mk_lang_assert(data_in_len >= 0);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_in_consumed);
	mk_lang_assert(data_out_consumed);
	mk_lang_assert(zlib->m_stream_header_idx >= 0);
	mk_lang_assert(zlib->m_stream_header_idx <= mk_lang_countof(zlib->m_stream_header_buf));

	in_buf = data_in_buf;
	in_len = data_in_len;
	in_c = 0;
	out_c = 0;
	if(zlib->m_stream_footer_idx != mk_lang_countof(zlib->m_stream_footer_buf))
	{
		to_copy = mk_lang_countof(zlib->m_stream_footer_buf) - zlib->m_stream_footer_idx;
		to_copy = mk_lang_min(to_copy, in_len);
		mk_sl_cui_uint8_memcpy_fn(&zlib->m_stream_footer_buf[zlib->m_stream_footer_idx], in_buf, to_copy);
		zlib->m_stream_footer_idx += to_copy;
		in_c += to_copy;
	}
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_decompress_zlib_process_block_footer(mk_lib_decompress_zlib_pt const zlib, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;
	mk_sl_cui_uint32_t digest mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tu32 mk_lang_constexpr_init;

	mk_lang_assert(zlib);
	mk_lang_assert(data_in_buf || data_in_len == 0);
	mk_lang_assert(data_in_len >= 0);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_in_consumed);
	mk_lang_assert(data_out_consumed);
	mk_lang_assert(zlib->m_stream_header_idx >= 0);
	mk_lang_assert(zlib->m_stream_header_idx <= mk_lang_countof(zlib->m_stream_header_buf));

	in_c = 0;
	out_c = 0;
	if
	(
		(zlib->m_stream_footer_idx == mk_lang_countof(zlib->m_stream_footer_buf)) &&
		(!zlib->m_done)
	)
	{
		mk_lib_hash_adler32_finish(&zlib->m_adler32, &digest);
		mk_sl_uint_convert_32_8_be_to_big(&tu32, &zlib->m_stream_footer_buf[0]);
		mk_lang_check_return(mk_sl_cui_uint32_eq(&digest, &tu32));
		zlib->m_done = mk_lang_true;
	}
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_decompress_zlib_init(mk_lib_decompress_zlib_pt const zlib) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(zlib);

	#if defined DEBUG || defined _DEBUG
	mk_sl_cui_uint8_memclr_fn(&zlib->m_stream_header_buf[0], mk_lang_countof(zlib->m_stream_header_buf));
	#endif
	zlib->m_stream_header_idx = 0;
	zlib->m_stream_header_processed = mk_lang_false;
	err = mk_lib_decompress_deflate_init(&zlib->m_deflate); mk_lang_check_rereturn(err);
	mk_lib_hash_adler32_init(&zlib->m_adler32);
	#if defined DEBUG || defined _DEBUG
	mk_sl_cui_uint8_memclr_fn(&zlib->m_stream_footer_buf[0], mk_lang_countof(zlib->m_stream_footer_buf));
	#endif
	zlib->m_stream_footer_idx = 0;
	zlib->m_done = mk_lang_false;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_decompress_zlib_append(mk_lib_decompress_zlib_pt const zlib, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t in_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t out_len mk_lang_constexpr_init;
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;

	mk_lang_assert(zlib);
	mk_lang_assert(data_in_buf || data_in_len == 0);
	mk_lang_assert(data_in_len >= 0);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_in_consumed);
	mk_lang_assert(data_out_consumed);

	in_buf = data_in_buf;
	in_len = data_in_len;
	out_buf = data_out_buf;
	out_len = data_out_len;
	err = mk_lib_decompress_zlib_pr_read_block_header   (zlib, in_buf, in_len, out_buf, out_len, &in_c, &out_c); mk_lang_check_rereturn(err); in_buf += in_c; in_len -= in_c; out_buf += out_c; out_len -= out_c;
	err = mk_lib_decompress_zlib_pr_process_block_header(zlib, in_buf, in_len, out_buf, out_len, &in_c, &out_c); mk_lang_check_rereturn(err); in_buf += in_c; in_len -= in_c; out_buf += out_c; out_len -= out_c;
	err = mk_lib_decompress_zlib_pr_inflate             (zlib, in_buf, in_len, out_buf, out_len, &in_c, &out_c); mk_lang_check_rereturn(err); in_buf += in_c; in_len -= in_c; out_buf += out_c; out_len -= out_c;
	if(in_len != 0 && out_len != 0 && in_c == 0 && out_c == 0 && mk_lib_decompress_deflate_is_last(&zlib->m_deflate))
	{
		err = mk_lib_decompress_zlib_pr_read_block_footer(zlib, in_buf, in_len, out_buf, out_len, &in_c, &out_c); mk_lang_check_rereturn(err); in_buf += in_c; in_len -= in_c; out_buf += out_c; out_len -= out_c;
		err = mk_lib_decompress_zlib_process_block_footer(zlib, in_buf, in_len, out_buf, out_len, &in_c, &out_c); mk_lang_check_rereturn(err); in_buf += in_c; in_len -= in_c; out_buf += out_c; out_len -= out_c;
	}
	in_c = data_in_len - in_len;
	out_c = data_out_len - out_len;
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
	return 0;
}


#endif
