#ifndef mk_include_guard_mk_lib_compress_deflate_c
#define mk_include_guard_mk_lib_compress_deflate_c
#include "mk_lib_compress_deflate.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_compress_deflate_pr_copy_from_input_buffer_if_possible(mk_lib_compress_deflate_pt const deflate, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t in_len mk_lang_constexpr_init;
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;
	mk_lang_types_sint_t avail mk_lang_constexpr_init;
	mk_lang_types_sint_t to_copy mk_lang_constexpr_init;

	mk_lang_assert(deflate);
	mk_lang_assert(data_in_buf || data_in_len == 0);
	mk_lang_assert(data_in_len >= 0);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_in_consumed);
	mk_lang_assert(data_out_consumed);
	mk_lang_assert(deflate->m_uncompressed_data_idx >= 0);
	mk_lang_assert(deflate->m_uncompressed_data_idx <= mk_lang_countof(deflate->m_uncompressed_data_buf.m_data.m_u8s));

	in_buf = data_in_buf;
	in_len = data_in_len;
	in_c = 0;
	out_c = 0;
	avail = mk_lang_countof(deflate->m_uncompressed_data_buf.m_data.m_u8s) - deflate->m_uncompressed_data_idx;
	to_copy = mk_lang_min(avail, in_len);
	mk_sl_cui_uint8_memcpy_fn(&deflate->m_uncompressed_data_buf.m_data.m_u8s[deflate->m_uncompressed_data_idx], in_buf, to_copy);
	deflate->m_uncompressed_data_idx += to_copy;
	in_c += to_copy;
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_compress_deflate_pr_compute_header_if_possible(mk_lib_compress_deflate_pt const deflate, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_uint16_t len mk_lang_constexpr_init;
	mk_sl_cui_uint16_t nlen mk_lang_constexpr_init;

	mk_lang_assert(deflate);
	mk_lang_assert(data_in_buf || data_in_len == 0);
	mk_lang_assert(data_in_len >= 0);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_in_consumed);
	mk_lang_assert(data_out_consumed);
	mk_lang_assert(deflate->m_uncompressed_data_idx >= 0);
	mk_lang_assert(deflate->m_uncompressed_data_idx <= mk_lang_countof(deflate->m_uncompressed_data_buf.m_data.m_u8s));

	in_c = 0;
	out_c = 0;
	if
	(
		(deflate->m_uncompressed_data_idx == mk_lang_countof(deflate->m_uncompressed_data_buf.m_data.m_u8s)) ||
		(deflate->m_finish_requested && !deflate->m_finished)
	)
	{
		if(!deflate->m_block_header_computed)
		{
			ptr = 0;
			if(deflate->m_finish_requested)
			{
				mk_sl_cui_uint8_set_one(&deflate->m_block_header_buf[ptr]); ptr += mk_sl_cui_uint8_size_bytes_v;
			}
			else
			{
				mk_sl_cui_uint8_set_zero(&deflate->m_block_header_buf[ptr]); ptr += mk_sl_cui_uint8_size_bytes_v;
			}
			mk_sl_cui_uint16_from_bi_sint(&len, &deflate->m_uncompressed_data_idx);
			mk_sl_uint_convert_16_8_le_to_sml(&len, &deflate->m_block_header_buf[ptr]); ptr += mk_sl_cui_uint16_size_bytes_v;
			mk_sl_cui_uint16_not2(&len, &nlen);
			mk_sl_uint_convert_16_8_le_to_sml(&nlen, &deflate->m_block_header_buf[ptr]);
			deflate->m_block_header_beg = 0;
			deflate->m_block_header_computed = mk_lang_true;
			if(deflate->m_finish_requested)
			{
				deflate->m_finished = mk_lang_true;
			}
		}
	}
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_compress_deflate_pr_copy_header_if_possible(mk_lib_compress_deflate_pt const deflate, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt out_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t out_len mk_lang_constexpr_init;
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;
	mk_lang_types_sint_t avail mk_lang_constexpr_init;
	mk_lang_types_sint_t to_copy mk_lang_constexpr_init;

	mk_lang_assert(deflate);
	mk_lang_assert(data_in_buf || data_in_len == 0);
	mk_lang_assert(data_in_len >= 0);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_in_consumed);
	mk_lang_assert(data_out_consumed);
	mk_lang_assert(deflate->m_uncompressed_data_idx >= 0);
	mk_lang_assert(deflate->m_uncompressed_data_idx <= mk_lang_countof(deflate->m_uncompressed_data_buf.m_data.m_u8s));
	mk_lang_assert(deflate->m_block_header_beg >= 0);
	mk_lang_assert(deflate->m_block_header_beg <= mk_lang_countof(deflate->m_block_header_buf));

	out_buf = data_out_buf;
	out_len = data_out_len;
	in_c = 0;
	out_c = 0;
	if
	(
		(deflate->m_uncompressed_data_idx == mk_lang_countof(deflate->m_uncompressed_data_buf.m_data.m_u8s)) ||
		(deflate->m_finish_requested && deflate->m_finished)
	)
	{
		if(deflate->m_block_header_computed)
		{
			avail = mk_lang_countof(deflate->m_block_header_buf) - deflate->m_block_header_beg;
			to_copy = mk_lang_min(avail, out_len);
			mk_sl_cui_uint8_memcpy_fn(out_buf, &deflate->m_block_header_buf[deflate->m_block_header_beg], to_copy);
			deflate->m_block_header_beg += to_copy;
			out_c += to_copy;
		}
	}
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_compress_deflate_pr_copy_compressed_if_possible(mk_lib_compress_deflate_pt const deflate, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt out_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t out_len mk_lang_constexpr_init;
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;
	mk_lang_types_sint_t avail mk_lang_constexpr_init;
	mk_lang_types_sint_t to_copy mk_lang_constexpr_init;

	mk_lang_assert(deflate);
	mk_lang_assert(data_in_buf || data_in_len == 0);
	mk_lang_assert(data_in_len >= 0);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_in_consumed);
	mk_lang_assert(data_out_consumed);
	mk_lang_assert(deflate->m_uncompressed_data_idx >= 0);
	mk_lang_assert(deflate->m_uncompressed_data_idx <= mk_lang_countof(deflate->m_uncompressed_data_buf.m_data.m_u8s));
	mk_lang_assert(deflate->m_uncompressed_data_beg >= 0);
	mk_lang_assert(deflate->m_uncompressed_data_beg <= mk_lang_countof(deflate->m_uncompressed_data_buf.m_data.m_u8s));
	mk_lang_assert(deflate->m_uncompressed_data_beg <= deflate->m_uncompressed_data_idx);
	mk_lang_assert(deflate->m_block_header_beg >= 0);
	mk_lang_assert(deflate->m_block_header_beg <= mk_lang_countof(deflate->m_block_header_buf));

	out_buf = data_out_buf;
	out_len = data_out_len;
	in_c = 0;
	out_c = 0;
	if
	(
		(deflate->m_uncompressed_data_idx == mk_lang_countof(deflate->m_uncompressed_data_buf.m_data.m_u8s)) ||
		(deflate->m_finish_requested && deflate->m_finished)
	)
	{
		if(deflate->m_block_header_computed && deflate->m_block_header_beg == mk_lang_countof(deflate->m_block_header_buf));
		{
			avail = deflate->m_uncompressed_data_idx - deflate->m_uncompressed_data_beg;
			to_copy = mk_lang_min(avail, out_len);
			mk_sl_cui_uint8_memcpy_fn(out_buf, &deflate->m_uncompressed_data_buf.m_data.m_u8s[deflate->m_uncompressed_data_beg], to_copy);
			deflate->m_uncompressed_data_beg += to_copy;
			out_c += to_copy;
		}
	}
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_compress_deflate_pr_reset_if_possible(mk_lib_compress_deflate_pt const deflate, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
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
	mk_lang_assert(deflate->m_uncompressed_data_idx >= 0);
	mk_lang_assert(deflate->m_uncompressed_data_idx <= mk_lang_countof(deflate->m_uncompressed_data_buf.m_data.m_u8s));
	mk_lang_assert(deflate->m_uncompressed_data_beg >= 0);
	mk_lang_assert(deflate->m_uncompressed_data_beg <= mk_lang_countof(deflate->m_uncompressed_data_buf.m_data.m_u8s));
	mk_lang_assert(deflate->m_uncompressed_data_beg <= deflate->m_uncompressed_data_idx);
	mk_lang_assert(deflate->m_block_header_beg >= 0);
	mk_lang_assert(deflate->m_block_header_beg <= mk_lang_countof(deflate->m_block_header_buf));

	in_c = 0;
	out_c = 0;
	if
	(
		(deflate->m_block_header_computed && deflate->m_block_header_beg == mk_lang_countof(deflate->m_block_header_buf)) &&
		(deflate->m_uncompressed_data_beg == deflate->m_uncompressed_data_idx)
	)
	{
		deflate->m_uncompressed_data_idx = 0;
		deflate->m_uncompressed_data_beg = 0;
		deflate->m_block_header_beg = 0;
		deflate->m_block_header_computed = mk_lang_false;
		deflate->m_finish_requested = mk_lang_false;
		deflate->m_finished = mk_lang_false;
	}
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_compress_deflate_init(mk_lib_compress_deflate_pt const deflate) mk_lang_noexcept
{
	mk_lang_assert(deflate);

	deflate->m_uncompressed_data_idx = 0;
	deflate->m_uncompressed_data_beg = 0;
	deflate->m_block_header_beg = 0;
	deflate->m_block_header_computed = mk_lang_false;
	deflate->m_finish_requested = mk_lang_false;
	deflate->m_finished = mk_lang_false;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_compress_deflate_append(mk_lib_compress_deflate_pt const deflate, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t in_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t out_len mk_lang_constexpr_init;
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;

	mk_lang_assert(deflate);
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
	mk_lib_compress_deflate_pr_copy_from_input_buffer_if_possible(deflate, in_buf, in_len, out_buf, out_len, &in_c, &out_c); in_buf += in_c; in_len -= in_c; out_buf += out_c; out_len -= out_c;
	mk_lib_compress_deflate_pr_compute_header_if_possible        (deflate, in_buf, in_len, out_buf, out_len, &in_c, &out_c); in_buf += in_c; in_len -= in_c; out_buf += out_c; out_len -= out_c;
	mk_lib_compress_deflate_pr_copy_header_if_possible           (deflate, in_buf, in_len, out_buf, out_len, &in_c, &out_c); in_buf += in_c; in_len -= in_c; out_buf += out_c; out_len -= out_c;
	mk_lib_compress_deflate_pr_copy_compressed_if_possible       (deflate, in_buf, in_len, out_buf, out_len, &in_c, &out_c); in_buf += in_c; in_len -= in_c; out_buf += out_c; out_len -= out_c;
	mk_lib_compress_deflate_pr_reset_if_possible                 (deflate, in_buf, in_len, out_buf, out_len, &in_c, &out_c); in_buf += in_c; in_len -= in_c; out_buf += out_c; out_len -= out_c;
	in_c = data_in_len - in_len;
	out_c = data_out_len - out_len;
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_compress_deflate_finish(mk_lib_compress_deflate_pt const deflate, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;

	mk_lang_assert(deflate);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_out_consumed);

	deflate->m_finish_requested = mk_lang_true;
	mk_lib_compress_deflate_append(deflate, mk_lang_null, 0, data_out_buf, data_out_len, &in_c, data_out_consumed); mk_lang_assert(in_c == 0);
}


#endif
