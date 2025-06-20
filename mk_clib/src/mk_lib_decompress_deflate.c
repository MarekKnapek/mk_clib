#ifndef mk_include_guard_mk_lib_decompress_deflate_c
#define mk_include_guard_mk_lib_decompress_deflate_c
#include "mk_lib_decompress_deflate.h"

#include "mk_lang_limits.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_decompress_deflate_pr_read_block_header(mk_lib_decompress_deflate_pt const deflate, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t in_len mk_lang_constexpr_init;
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;
	mk_lang_types_sint_t to_copy mk_lang_constexpr_init;

	mk_lang_assert(deflate);
	mk_lang_assert(data_in_buf || data_in_len == 0);
	mk_lang_assert(data_in_len >= 0);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_in_consumed);
	mk_lang_assert(data_out_consumed);
	mk_lang_assert(deflate->m_block_header_idx >= 0);
	mk_lang_assert(deflate->m_block_header_idx <= mk_lang_countof(deflate->m_block_header_buf));
	mk_lang_assert
	(
		(deflate->m_uncompressed_data_idx == mk_lang_limits_sint_min && deflate->m_uncompressed_data_len == mk_lang_limits_sint_min) ||
		(deflate->m_uncompressed_data_idx <= deflate->m_uncompressed_data_len)
	);

	in_buf = data_in_buf;
	in_len = data_in_len;
	in_c = 0;
	out_c = 0;
	if
	(
		(deflate->m_block_header_idx != mk_lang_countof(deflate->m_block_header_buf)) &&
		(!deflate->m_last_block)
	)
	{
		to_copy = mk_lang_countof(deflate->m_block_header_buf) - deflate->m_block_header_idx;
		to_copy = mk_lang_min(to_copy, in_len);
		mk_sl_cui_uint8_memcpy_fn(&deflate->m_block_header_buf[deflate->m_block_header_idx], in_buf, ((mk_lang_types_usize_t)(to_copy)));
		deflate->m_block_header_idx += to_copy;
		in_c += to_copy;
	}
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_decompress_deflate_pr_process_block_header(mk_lib_decompress_deflate_pt const deflate, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;
	mk_lang_types_sint_t byte_ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t bit_ptr mk_lang_constexpr_init;
	mk_sl_cui_uint8_t header mk_lang_constexpr_init;
	mk_sl_cui_uint8_t mask mk_lang_constexpr_init;
	mk_sl_cui_uint8_t bfinal mk_lang_constexpr_init;
	mk_sl_cui_uint8_t btype mk_lang_constexpr_init;
	mk_sl_cui_uint16_t len mk_lang_constexpr_init;
	mk_sl_cui_uint16_t nlen mk_lang_constexpr_init;
	mk_sl_cui_uint16_t tu16 mk_lang_constexpr_init;

	mk_lang_static_assert(sizeof(deflate->m_uncompressed_data_len) > mk_sl_cui_uint16_size_bytes_v);

	mk_lang_assert(deflate);
	mk_lang_assert(data_in_buf || data_in_len == 0);
	mk_lang_assert(data_in_len >= 0);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_in_consumed);
	mk_lang_assert(data_out_consumed);
	mk_lang_assert(deflate->m_block_header_idx >= 0);
	mk_lang_assert(deflate->m_block_header_idx <= mk_lang_countof(deflate->m_block_header_buf));
	mk_lang_assert
	(
		(deflate->m_uncompressed_data_idx == mk_lang_limits_sint_min && deflate->m_uncompressed_data_len == mk_lang_limits_sint_min) ||
		(deflate->m_uncompressed_data_idx <= deflate->m_uncompressed_data_len)
	);

	in_c = 0;
	out_c = 0;
	if(
		(deflate->m_block_header_idx == mk_lang_countof(deflate->m_block_header_buf)) &&
		(deflate->m_uncompressed_data_idx == mk_lang_limits_sint_min && deflate->m_uncompressed_data_len == mk_lang_limits_sint_min) &&
		(!deflate->m_last_block)
	)
	{
		byte_ptr = 0;
		bit_ptr = 0;
		header = deflate->m_block_header_buf[byte_ptr]; byte_ptr += mk_sl_cui_uint8_size_bytes_v;
		mk_sl_cui_uint8_set_mask(&mask, 1);
		mk_sl_cui_uint8_shr3(&header, bit_ptr, &bfinal);
		mk_sl_cui_uint8_and2(&bfinal, &mask);
		deflate->m_last_block = !mk_sl_cui_uint8_is_zero(&bfinal);
		bit_ptr += 1;
		mk_sl_cui_uint8_set_mask(&mask, 2);
		mk_sl_cui_uint8_shr3(&header, bit_ptr, &btype);
		mk_sl_cui_uint8_and2(&btype, &mask);
		mk_lang_check_return(mk_sl_cui_uint8_is_zero(&btype)); /* no compression */
		bit_ptr += 2;
		mk_sl_uint_convert_16_8_le_to_big(&len, &deflate->m_block_header_buf[byte_ptr]); byte_ptr += mk_sl_cui_uint16_size_bytes_v;
		mk_sl_uint_convert_16_8_le_to_big(&nlen, &deflate->m_block_header_buf[byte_ptr]); byte_ptr += mk_sl_cui_uint16_size_bytes_v;
		mk_sl_cui_uint16_not2(&len, &tu16);
		mk_lang_check_return(mk_sl_cui_uint16_eq(&nlen, &tu16));
		mk_sl_cui_uint16_to_bi_sint(&len, &deflate->m_uncompressed_data_len);
		deflate->m_uncompressed_data_idx = 0;
	}
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_decompress_deflate_pr_decompress_uncompressed(mk_lib_decompress_deflate_pt const deflate, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t in_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t out_len mk_lang_constexpr_init;
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;
	mk_lang_types_sint_t to_copy mk_lang_constexpr_init;

	mk_lang_assert(deflate);
	mk_lang_assert(data_in_buf || data_in_len == 0);
	mk_lang_assert(data_in_len >= 0);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_in_consumed);
	mk_lang_assert(data_out_consumed);
	mk_lang_assert(deflate->m_block_header_idx >= 0);
	mk_lang_assert(deflate->m_block_header_idx <= mk_lang_countof(deflate->m_block_header_buf));
	mk_lang_assert
	(
		(deflate->m_uncompressed_data_idx == mk_lang_limits_sint_min && deflate->m_uncompressed_data_len == mk_lang_limits_sint_min) ||
		(deflate->m_uncompressed_data_idx <= deflate->m_uncompressed_data_len)
	);

	in_buf = data_in_buf;
	in_len = data_in_len;
	out_buf = data_out_buf;
	out_len = data_out_len;
	in_c = 0;
	out_c = 0;
	if
	(
		(deflate->m_block_header_idx == mk_lang_countof(deflate->m_block_header_buf)) &&
		(deflate->m_uncompressed_data_idx != mk_lang_limits_sint_min && deflate->m_uncompressed_data_len != mk_lang_limits_sint_min) &&
		(deflate->m_uncompressed_data_idx != deflate->m_uncompressed_data_len)
	)
	{
		to_copy = deflate->m_uncompressed_data_len - deflate->m_uncompressed_data_idx;
		to_copy = mk_lang_min(to_copy, in_len);
		to_copy = mk_lang_min(to_copy, out_len);
		mk_sl_cui_uint8_memcpy_fn(out_buf, in_buf, ((mk_lang_types_usize_t)(to_copy)));
		deflate->m_uncompressed_data_idx += to_copy;
		in_c += to_copy;
		out_c += to_copy;
	}
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_decompress_deflate_pr_process_block_end(mk_lib_decompress_deflate_pt const deflate, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;

	mk_lang_assert(deflate);
	mk_lang_assert(data_in_buf || data_in_len == 0);
	mk_lang_assert(data_in_len >= 0);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_in_consumed);
	mk_lang_assert(data_out_consumed);
	mk_lang_assert(deflate->m_block_header_idx >= 0);
	mk_lang_assert(deflate->m_block_header_idx <= mk_lang_countof(deflate->m_block_header_buf));
	mk_lang_assert
	(
		(deflate->m_uncompressed_data_idx == mk_lang_limits_sint_min && deflate->m_uncompressed_data_len == mk_lang_limits_sint_min) ||
		(deflate->m_uncompressed_data_idx <= deflate->m_uncompressed_data_len)
	);

	in_c = 0;
	out_c = 0;
	if
	(
		(deflate->m_block_header_idx == mk_lang_countof(deflate->m_block_header_buf)) &&
		(deflate->m_uncompressed_data_idx != mk_lang_limits_sint_min && deflate->m_uncompressed_data_len != mk_lang_limits_sint_min) &&
		(deflate->m_uncompressed_data_idx == deflate->m_uncompressed_data_len)
	)
	{
		deflate->m_block_header_idx = 0;
		deflate->m_uncompressed_data_len = mk_lang_limits_sint_min;
		deflate->m_uncompressed_data_idx = mk_lang_limits_sint_min;
	}
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_decompress_deflate_init(mk_lib_decompress_deflate_pt const deflate) mk_lang_noexcept
{
	mk_lang_assert(deflate);

	#if defined DEBUG || defined _DEBUG
	mk_sl_cui_uint8_memclr_fn(&deflate->m_block_header_buf[0], mk_lang_countof(deflate->m_block_header_buf));
	#endif
	deflate->m_block_header_idx = 0;
	deflate->m_uncompressed_data_len = mk_lang_limits_sint_min;
	deflate->m_uncompressed_data_idx = mk_lang_limits_sint_min;
	deflate->m_last_block = mk_lang_false;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_decompress_deflate_append(mk_lib_decompress_deflate_pt const deflate, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t in_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t out_len mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;

	mk_lang_assert(deflate);
	mk_lang_assert(data_in_buf || data_in_len == 0);
	mk_lang_assert(data_in_len >= 0);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_in_consumed);
	mk_lang_assert(data_out_consumed);
	mk_lang_assert(deflate->m_block_header_idx >= 0);
	mk_lang_assert(deflate->m_block_header_idx <= mk_lang_countof(deflate->m_block_header_buf));
	mk_lang_assert
	(
		(deflate->m_uncompressed_data_idx == mk_lang_limits_sint_min && deflate->m_uncompressed_data_len == mk_lang_limits_sint_min) ||
		(deflate->m_uncompressed_data_idx <= deflate->m_uncompressed_data_len)
	);

	in_buf = data_in_buf;
	in_len = data_in_len;
	out_buf = data_out_buf;
	out_len = data_out_len;
	err = mk_lib_decompress_deflate_pr_read_block_header      (deflate, in_buf, in_len, out_buf, out_len, &in_c, &out_c); mk_lang_check_rereturn(err); in_buf += in_c; in_len -= in_c; out_buf += out_c; out_len -= out_c;
	err = mk_lib_decompress_deflate_pr_process_block_header   (deflate, in_buf, in_len, out_buf, out_len, &in_c, &out_c); mk_lang_check_rereturn(err); in_buf += in_c; in_len -= in_c; out_buf += out_c; out_len -= out_c;
	err = mk_lib_decompress_deflate_pr_decompress_uncompressed(deflate, in_buf, in_len, out_buf, out_len, &in_c, &out_c); mk_lang_check_rereturn(err); in_buf += in_c; in_len -= in_c; out_buf += out_c; out_len -= out_c;
	err = mk_lib_decompress_deflate_pr_process_block_end      (deflate, in_buf, in_len, out_buf, out_len, &in_c, &out_c); mk_lang_check_rereturn(err); in_buf += in_c; in_len -= in_c; out_buf += out_c; out_len -= out_c;
	in_c = data_in_len - in_len;
	out_c = data_out_len - out_len;
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lib_decompress_deflate_is_last(mk_lib_decompress_deflate_pt const deflate) mk_lang_noexcept
{
	mk_lang_assert(deflate);
	mk_lang_assert(deflate->m_block_header_idx >= 0);
	mk_lang_assert(deflate->m_block_header_idx <= mk_lang_countof(deflate->m_block_header_buf));
	mk_lang_assert
	(
		(deflate->m_uncompressed_data_idx == mk_lang_limits_sint_min && deflate->m_uncompressed_data_len == mk_lang_limits_sint_min) ||
		(deflate->m_uncompressed_data_idx <= deflate->m_uncompressed_data_len)
	);

	return deflate->m_last_block;
}


#endif
