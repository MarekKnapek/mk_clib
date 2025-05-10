#ifndef mk_include_guard_mk_lib_fast_import_c
#define mk_include_guard_mk_lib_fast_import_c
#include "mk_lib_fast_import.h"

#include "mk_lang_string.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_str_len.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_sha1.h"
#include "mk_sl_cui_uint128.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_io_reader_file.h"
#include "mk_sl_io_writer_file.h"
#include "mk_sl_mallocator_lokal_arena.h"
#include "mk_sl_uint_more.h"
#include "mk_sl_mallocator_lokal_windows.h" /* todo */
#include "mk_win_dll_kernel_errors.h" /* todo */
#include "mk_win_dll_kernel_files.h" /* todo */

#define mk_sl_mallocator_lokal_t_name mk_lib_fast_import_mallocator_lokal
#define mk_sl_mallocator_lokal_t_base mk_sl_mallocator_lokal_windows
#define mk_sl_mallocator_lokal_t_constexpr_want 0
#include "mk_sl_mallocator_lokal_inl_fileh.h"
#include "mk_sl_mallocator_lokal_inl_filec.h"
#include "mk_sl_mallocator_lokal_inl_fileu.h"


/* adler32 */


#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"


struct mk_lib_adler32_s
{
	mk_sl_cui_uint32_t m_a;
	mk_sl_cui_uint32_t m_b;
};
typedef struct mk_lib_adler32_s mk_lib_adler32_t;
mk_lang_typedef(mk_lib_adler32);


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_adler32_init(mk_lib_adler32_pt const adler32) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_adler32_append(mk_lib_adler32_pt const adler32, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_adler32_finish(mk_lib_adler32_pt const adler32, mk_sl_cui_uint32_pt const digest) mk_lang_noexcept;


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_adler32_init(mk_lib_adler32_pt const adler32) mk_lang_noexcept
{
	mk_lang_assert(adler32);

	mk_sl_cui_uint32_set_one(&adler32->m_a);
	mk_sl_cui_uint32_set_zero(&adler32->m_b);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_adler32_block(mk_lib_adler32_pt const adler32, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct buf mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tcui8s[32 / 8] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tcui32 mk_lang_constexpr_init;
	mk_lang_types_uint_t prime mk_lang_constexpr_init;

	mk_lang_assert(adler32);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(data_len <= 4 * 1024);

	buf = data_buf;
	len = data_len;
	if(len != 0)
	{
		mk_sl_cui_uint8_memclr_fn(&tcui8s[0], mk_lang_countof(tcui8s));
		n = len;
		for(i = 0; i != n; ++i)
		{
			tcui8s[0] = buf[i];
			mk_sl_uint_convert_32_8_le_to_big(&tcui32, &tcui8s[0]);
			mk_lang_assert(!mk_sl_cui_uint32_would_overflow_add_cc(&adler32->m_a, &tcui32));
			mk_sl_cui_uint32_add2_wrap_cid_cod(&adler32->m_a, &tcui32);
			mk_lang_assert(!mk_sl_cui_uint32_would_overflow_add_cc(&adler32->m_b, &adler32->m_a));
			mk_sl_cui_uint32_add2_wrap_cid_cod(&adler32->m_b, &adler32->m_a);
		}
		prime = 65521u; mk_sl_cui_uint32_from_bi_uint(&tcui32, &prime);
		mk_sl_cui_uint32_mod2_wrap(&adler32->m_a, &tcui32);
		mk_sl_cui_uint32_mod2_wrap(&adler32->m_b, &tcui32);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_adler32_append(mk_lib_adler32_pt const adler32, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct buf mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(adler32);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);

	buf = data_buf;
	len = data_len;
	n = data_len / (4 * 1024);
	for(i = 0; i != n; ++i)
	{
		mk_lib_adler32_block(adler32, buf, 4 * 1024);
		buf += 4 * 1024;
		len -= 4 * 1024;
	}
	mk_lang_assert(len <= 4 * 1024);
	mk_lib_adler32_block(adler32, buf, len);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_adler32_finish(mk_lib_adler32_pt const adler32, mk_sl_cui_uint32_pt const digest) mk_lang_noexcept
{
	mk_sl_cui_uint32_t tcui32 mk_lang_constexpr_init;

	mk_lang_assert(adler32);
	mk_lang_assert(digest);

	mk_sl_cui_uint32_shl3(&adler32->m_b, mk_sl_cui_uint16_size_bits_v, &tcui32);
	mk_sl_cui_uint32_or2(&tcui32, &adler32->m_a);
	*digest = tcui32;
}


/* adler32 */


/* adler32b */


#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"


struct mk_lib_adler32b_s
{
	mk_lib_adler32_t m_adler32;
};
typedef struct mk_lib_adler32b_s mk_lib_adler32b_t;
mk_lang_typedef(mk_lib_adler32b);


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_adler32b_init(mk_lib_adler32b_pt const adler32b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_adler32b_append(mk_lib_adler32b_pt const adler32b, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_adler32b_finish(mk_lib_adler32b_pt const adler32b, mk_sl_cui_uint32_pt const digest) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_adler32b_init(mk_lib_adler32b_pt const adler32b) mk_lang_noexcept
{
	mk_lang_assert(adler32b);

	mk_lib_adler32_init(&adler32b->m_adler32);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_adler32b_append(mk_lib_adler32b_pt const adler32b, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	mk_lang_assert(adler32b);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);

	mk_lib_adler32_append(&adler32b->m_adler32, data_buf, data_len);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_adler32b_finish(mk_lib_adler32b_pt const adler32b, mk_sl_cui_uint32_pt const digest) mk_lang_noexcept
{
	mk_lang_assert(adler32b);
	mk_lang_assert(digest);

	mk_lib_adler32_finish(&adler32b->m_adler32, digest);
	return 0;
}


/* adler32b */


/* deflate */


#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"


enum mk_lib_deflate_block_non_compressed_header_len_e{ mk_lib_deflate_block_non_compressed_header_len_v = mk_sl_cui_uint8_size_bytes_v + mk_sl_cui_uint16_size_bytes_v + mk_sl_cui_uint16_size_bytes_v }; typedef enum mk_lib_deflate_block_non_compressed_header_len_e mk_lib_deflate_block_non_compressed_header_len_t;
enum mk_lib_deflate_uncompressed_data_len_max_e{ mk_lib_deflate_uncompressed_data_len_max_v = 16 * 1024 }; typedef enum mk_lib_deflate_uncompressed_data_len_max_e mk_lib_deflate_uncompressed_data_len_max_t;


union mk_lib_deflate_buf_data_u
{
	mk_lang_alignas(1024) mk_sl_cui_uint8_t m_u8s[mk_lib_deflate_uncompressed_data_len_max_v];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_deflate_buf_data_u mk_lib_deflate_buf_data_t;
struct mk_lib_deflate_buf_s
{
	mk_lib_deflate_buf_data_t m_data;
};
typedef struct mk_lib_deflate_buf_s mk_lib_deflate_buf_t;
mk_lang_typedef(mk_lib_deflate_buf);


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_deflate_s
{
	mk_lib_deflate_buf_t m_uncompressed_data_buf;
	mk_lang_types_sint_t m_uncompressed_data_idx;
	mk_lang_types_sint_t m_uncompressed_data_beg;
	mk_sl_cui_uint8_t m_block_header_buf[mk_lib_deflate_block_non_compressed_header_len_v];
	mk_lang_types_sint_t m_block_header_beg;
	mk_lang_types_bool_t m_block_header_computed;
	mk_lang_types_bool_t m_finish_requested;
	mk_lang_types_bool_t m_finished;
};
typedef struct mk_lib_deflate_s mk_lib_deflate_t;
mk_lang_typedef(mk_lib_deflate);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_deflate_init(mk_lib_deflate_pt const deflate) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_deflate_append(mk_lib_deflate_pt const deflate, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_deflate_finish(mk_lib_deflate_pt const deflate, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_deflate_init(mk_lib_deflate_pt const deflate) mk_lang_noexcept
{
	mk_lang_assert(deflate);

	deflate->m_uncompressed_data_idx = 0;
	deflate->m_uncompressed_data_beg = 0;
	deflate->m_block_header_beg = 0;
	deflate->m_block_header_computed = mk_lang_false;
	deflate->m_finish_requested = mk_lang_false;
	deflate->m_finished = mk_lang_false;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_deflate_pr_copy_from_input_buffer_if_possible(mk_lib_deflate_pt const deflate, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
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
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_deflate_pr_compute_header_if_possible(mk_lib_deflate_pt const deflate, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
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
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_deflate_pr_copy_header_if_possible(mk_lib_deflate_pt const deflate, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
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
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_deflate_pr_copy_compressed_if_possible(mk_lib_deflate_pt const deflate, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
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
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_deflate_pr_reset_if_possible(mk_lib_deflate_pt const deflate, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
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
	if(deflate->m_uncompressed_data_idx == mk_lang_countof(deflate->m_uncompressed_data_buf.m_data.m_u8s))
	{
		if(deflate->m_block_header_computed && deflate->m_block_header_beg == mk_lang_countof(deflate->m_block_header_buf));
		{
			if(deflate->m_uncompressed_data_beg == deflate->m_uncompressed_data_idx)
			{
				deflate->m_uncompressed_data_idx = 0;
				deflate->m_uncompressed_data_beg = 0;
				deflate->m_block_header_beg = 0;
				deflate->m_block_header_computed = mk_lang_false;
				deflate->m_finish_requested = mk_lang_false;
				deflate->m_finished = mk_lang_false;
			}
		}
	}
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_deflate_append(mk_lib_deflate_pt const deflate, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
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

	in_buf = data_in_buf;
	in_len = data_in_len;
	out_buf = data_out_buf;
	out_len = data_out_len;
	err = mk_lib_deflate_pr_copy_from_input_buffer_if_possible(deflate, in_buf, in_len, out_buf, out_len, &in_c, &out_c); mk_lang_check_rereturn(err);
	in_buf += in_c;
	in_len -= in_c;
	out_buf += out_c;
	out_len -= out_c;
	err = mk_lib_deflate_pr_compute_header_if_possible(deflate, in_buf, in_len, out_buf, out_len, &in_c, &out_c); mk_lang_check_rereturn(err);
	in_buf += in_c;
	in_len -= in_c;
	out_buf += out_c;
	out_len -= out_c;
	err = mk_lib_deflate_pr_copy_header_if_possible(deflate, in_buf, in_len, out_buf, out_len, &in_c, &out_c); mk_lang_check_rereturn(err);
	in_buf += in_c;
	in_len -= in_c;
	out_buf += out_c;
	out_len -= out_c;
	err = mk_lib_deflate_pr_copy_compressed_if_possible(deflate, in_buf, in_len, out_buf, out_len, &in_c, &out_c); mk_lang_check_rereturn(err);
	in_buf += in_c;
	in_len -= in_c;
	out_buf += out_c;
	out_len -= out_c;
	err = mk_lib_deflate_pr_reset_if_possible(deflate, in_buf, in_len, out_buf, out_len, &in_c, &out_c); mk_lang_check_rereturn(err);
	in_buf += in_c;
	in_len -= in_c;
	out_buf += out_c;
	out_len -= out_c;
	in_c = data_in_len - in_len;
	out_c = data_out_len - out_len;
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_deflate_finish(mk_lib_deflate_pt const deflate, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;

	mk_lang_assert(deflate);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_out_consumed);

	deflate->m_finish_requested = mk_lang_true;
	err = mk_lib_deflate_append(deflate, mk_lang_null, 0, data_out_buf, data_out_len, &in_c, data_out_consumed); mk_lang_check_rereturn(err);
	return 0;
}


/* deflate */


/* zlib */


#include "mk_sl_cui_uint16.h"
#include "mk_sl_uint_convert.h"


enum mk_lib_zlib_header_len_e{ mk_lib_zlib_header_len_v = mk_sl_cui_uint8_size_bytes_v + mk_sl_cui_uint8_size_bytes_v }; typedef enum mk_lib_zlib_header_len_e mk_lib_zlib_header_len_t;

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_zlib_s
{
	mk_lib_deflate_t m_deflate;
	mk_lib_adler32b_t m_adler32;
	mk_sl_cui_uint8_t m_stream_header_buf[mk_lib_zlib_header_len_v];
	mk_lang_types_sint_t m_stream_header_beg;
	mk_sl_cui_uint8_t m_stream_footer_buf[mk_sl_cui_uint32_size_bytes_v];
	mk_lang_types_sint_t m_stream_footer_beg;
	mk_lang_types_bool_t m_finish_requested;
	mk_lang_types_bool_t m_finished;
};
typedef struct mk_lib_zlib_s mk_lib_zlib_t;
mk_lang_typedef(mk_lib_zlib);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_zlib_init(mk_lib_zlib_pt const zlib) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_zlib_append(mk_lib_zlib_pt const zlib, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_zlib_finish(mk_lib_zlib_pt const zlib, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_zlib_init(mk_lib_zlib_pt const zlib) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_uchar_t cmf mk_lang_constexpr_init;
	mk_lang_types_uchar_t flg mk_lang_constexpr_init;
	mk_lang_types_uchar_t fcheck mk_lang_constexpr_init;
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;

	mk_lang_assert(zlib);

	err = mk_lib_deflate_init(&zlib->m_deflate); mk_lang_check_rereturn(err);
	err = mk_lib_adler32b_init(&zlib->m_adler32); mk_lang_check_rereturn(err);
	cmf = 0x78; /* 0x08 == compression method, deflate */ /* 0x70 == compression info, 32 kB */
	flg = 0x00; /* no dictionary, no compression */
	fcheck = ((mk_lang_types_uchar_t)(((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(31)) - ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)((((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(cmf)) << 8)) + ((mk_lang_types_ushort_t)(flg))))) % ((mk_lang_types_ushort_t)(31))))))));
	flg = flg | fcheck;
	ptr = 0;
	mk_sl_cui_uint8_from_bi_uchar(&zlib->m_stream_header_buf[ptr], &cmf); ptr += mk_sl_cui_uint8_size_bytes_v;
	mk_sl_cui_uint8_from_bi_uchar(&zlib->m_stream_header_buf[ptr], &flg); ptr += mk_sl_cui_uint8_size_bytes_v;
	zlib->m_stream_header_beg = 0;
	zlib->m_stream_footer_beg = 0;
	zlib->m_finish_requested = mk_lang_false;
	zlib->m_finished = mk_lang_false;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_zlib_append(mk_lib_zlib_pt const zlib, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t in_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t out_len mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;
	mk_lang_types_sint_t avail mk_lang_constexpr_init;
	mk_lang_types_sint_t to_copy mk_lang_constexpr_init;
	mk_sl_cui_uint32_t adler32 mk_lang_constexpr_init;

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
	in_c = 0;
	out_c = 0;
	{
		avail = mk_lang_countof(zlib->m_stream_header_buf) - zlib->m_stream_header_beg;
		to_copy = mk_lang_min(avail, out_len);
		mk_sl_cui_uint8_memcpy_fn(out_buf, &zlib->m_stream_header_buf[zlib->m_stream_header_beg], to_copy);
		zlib->m_stream_header_beg += to_copy;
		out_buf += to_copy;
		out_len -= to_copy;
	}
	{
		if(zlib->m_stream_header_beg == mk_lang_countof(zlib->m_stream_header_buf))
		{
			err = mk_lib_deflate_append(&zlib->m_deflate, in_buf, in_len, out_buf, out_len, &in_c, &out_c); mk_lang_check_rereturn(err);
			err = mk_lib_adler32b_append(&zlib->m_adler32, in_buf, in_c); mk_lang_check_rereturn(err);
			in_buf += in_c;
			in_len -= in_c;
			out_buf += out_c;
			out_len -= out_c;
		}
	}
	{
		if
		(
			(zlib->m_stream_header_beg == mk_lang_countof(zlib->m_stream_header_buf)) &&
			(zlib->m_finish_requested)
		)
		{
			err = mk_lib_deflate_finish(&zlib->m_deflate, out_buf, out_len, &out_c); mk_lang_check_rereturn(err);
			out_buf += out_c;
			out_len -= out_c;
			if(out_len != 0 && out_c == 0)
			{
				if(!zlib->m_finished)
				{
					zlib->m_finished = mk_lang_true;
					err = mk_lib_adler32b_finish(&zlib->m_adler32, &adler32); mk_lang_check_rereturn(err);
					mk_sl_uint_convert_32_8_be_to_sml(&adler32, &zlib->m_stream_footer_buf[0]);
					zlib->m_stream_footer_beg = 0;
				}
			}
		}
	}
	{
		if(zlib->m_finish_requested && zlib->m_finished)
		{
			avail = mk_lang_countof(zlib->m_stream_footer_buf) - zlib->m_stream_footer_beg;
			to_copy = mk_lang_min(avail, out_len);
			mk_sl_cui_uint8_memcpy_fn(out_buf, &zlib->m_stream_footer_buf[zlib->m_stream_footer_beg], to_copy);
			zlib->m_stream_footer_beg += to_copy;
			out_buf += to_copy;
			out_len -= to_copy;
		}
	}
	in_c = data_in_len - in_len;
	out_c = data_out_len - out_len;
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_zlib_finish(mk_lib_zlib_pt const zlib, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;

	mk_lang_assert(zlib);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_out_consumed);

	zlib->m_finish_requested = mk_lang_true;
	err = mk_lib_zlib_append(zlib, mk_lang_null, 0, data_out_buf, data_out_len, &in_c, data_out_consumed); mk_lang_check_rereturn(err);
	return 0;
}


/* zlib */


#define mk_lib_fast_import_k_buf_len 512
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_authorsp[] = "author ";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_blob[] = "blob\x0a";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_blobsp[] = "blob ";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_colon[] = ":";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_commitsp[] = "commit ";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_committersp[] = "committer ";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_data[] = "data ";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_dot_git[] = ".git";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_from_sp_colon[] = "from :";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_gtsp[] = "> ";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_heads[] = "refs/heads/";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_lf[] = "\x0a";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_mark_sp_colon[] = "mark :";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_msp[] = "M ";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_objects[] = "objects";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_resetsp[] = "reset ";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_sp[] = " ";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_splt[] = " <";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_fast_import_k_treesp[] = "tree ";


mk_lang_forward(mk_lib_fast_import);


#define mk_sl_vector_t_name mk_lib_fast_import_string
#define mk_sl_vector_t_element_type mk_lang_types_pchar_t
#define mk_sl_vector_t_mallocatorl mk_lib_fast_import_mallocator_lokal
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"

#define mk_sl_vector_t_name mk_lib_fast_import_binary_data
#define mk_sl_vector_t_element_type mk_sl_cui_uint8_t
#define mk_sl_vector_t_mallocatorl mk_lib_fast_import_mallocator_lokal
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_buffered_reader_s
{
	mk_sl_io_reader_file_t m_reader;
	mk_sl_cui_uint8_t m_data_buf[2 * mk_lib_fast_import_k_buf_len];
	mk_lang_types_sint_t m_data_len;
};
typedef struct mk_lib_fast_import_buffered_reader_s mk_lib_fast_import_buffered_reader_t;
mk_lang_typedef(mk_lib_fast_import_buffered_reader);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_blob_s
{
	mk_lib_fast_import_pt m_fi;
	mk_sl_cui_uint128_t m_mark;
	mk_lang_types_pchar_t m_mode_buf[mk_sl_cui_uint32_strlen_dec_v];
	mk_lang_types_sint_t m_mode_len;
	mk_lang_types_sint_t m_binary_len;
	mk_sl_cui_uint8_pt m_binary_buf;
	mk_lib_crypto_hash_stream_sha1_digest_t m_digest;
};
typedef struct mk_lib_fast_import_blob_s mk_lib_fast_import_blob_t;
mk_lang_typedef(mk_lib_fast_import_blob);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_file_modify_s
{
	mk_lib_fast_import_pt m_fi;
	mk_sl_cui_uint32_t m_mode;
	mk_sl_cui_uint128_t m_data_ref;
	mk_lib_fast_import_string_t m_path;
};
typedef struct mk_lib_fast_import_file_modify_s mk_lib_fast_import_file_modify_t;
mk_lang_typedef(mk_lib_fast_import_file_modify);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_file_op_s
{
	mk_lib_fast_import_pt m_fi;
	mk_lib_fast_import_file_modify_t m_file_modify;
};
typedef struct mk_lib_fast_import_file_op_s mk_lib_fast_import_file_op_t;
mk_lang_typedef(mk_lib_fast_import_file_op);
#include "mk_lang_warning_msvc_pop.h"

#define mk_sl_vector_t_name mk_lib_fast_import_file_ops
#define mk_sl_vector_t_element_type mk_lib_fast_import_file_op_t
#define mk_sl_vector_t_mallocatorl mk_lib_fast_import_mallocator_lokal
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_commit_s
{
	mk_lib_fast_import_pt m_fi;
	mk_lib_fast_import_string_t m_ref;
	mk_lang_types_bool_t m_has_mark;
	mk_sl_cui_uint128_t m_mark;
	mk_lib_fast_import_string_t m_author_name;
	mk_lib_fast_import_string_t m_author_email;
	mk_lib_fast_import_string_t m_author_timestamp;
	mk_lib_fast_import_string_t m_committer_name;
	mk_lib_fast_import_string_t m_committer_email;
	mk_lib_fast_import_string_t m_committer_timestamp;
	mk_lib_fast_import_binary_data_t m_message;
	mk_lib_fast_import_file_ops_t m_file_ops;
	mk_lib_fast_import_binary_data_t m_data;
	mk_lib_crypto_hash_stream_sha1_digest_t m_digest;
};
typedef struct mk_lib_fast_import_commit_s mk_lib_fast_import_commit_t;
mk_lang_typedef(mk_lib_fast_import_commit);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_reset_s
{
	mk_lib_fast_import_pt m_fi;
	mk_lib_fast_import_string_t m_ref;
	mk_sl_cui_uint128_t m_from;
};
typedef struct mk_lib_fast_import_reset_s mk_lib_fast_import_reset_t;
mk_lang_typedef(mk_lib_fast_import_reset);
#include "mk_lang_warning_msvc_pop.h"


#define mk_sl_tree_wavl_t_name mk_lib_fast_import_tree_by_mark
#define mk_sl_tree_wavl_t_element_type mk_lib_fast_import_blob_t
#define mk_sl_tree_wavl_t_elements_compare mk_lib_fast_import_blob_cmp
#define mk_sl_tree_wavl_t_mallocatorl_name mk_lib_fast_import_mallocator_lokal
#define mk_sl_tree_wavl_t_validate_want 0
#define mk_sl_tree_wavl_t_element_copy_construct mk_lib_fast_import_blob_copy_construct
#define mk_sl_tree_wavl_t_element_move_construct mk_lib_fast_import_blob_move_construct
#define mk_sl_tree_wavl_t_element_destruct mk_lib_fast_import_blob_destroy
#include "mk_sl_tree_wavl_inl_fileh.h"
#include "mk_sl_tree_wavl_inl_fileu.h"


mk_lang_forward(mk_lib_fast_import_tree);

enum mk_lib_fast_import_tree_node_id_e
{
	mk_lib_fast_import_tree_node_id_e_tree = 1001,
	mk_lib_fast_import_tree_node_id_e_blob = 1002,
	mk_lib_fast_import_tree_node_id_e_dummy_end
};
typedef enum mk_lib_fast_import_tree_node_id_e mk_lib_fast_import_tree_node_id_t;

union mk_lib_fast_import_tree_node_val_data_u
{
	mk_lib_fast_import_tree_pt m_tree;
	mk_lib_fast_import_blob_pt m_blob;
};
typedef union mk_lib_fast_import_tree_node_val_data_u mk_lib_fast_import_tree_node_val_data_t;
struct mk_lib_fast_import_tree_node_val_s
{
	mk_lib_fast_import_tree_node_val_data_t m_data;
};
typedef struct mk_lib_fast_import_tree_node_val_s mk_lib_fast_import_tree_node_val_t;
mk_lang_typedef(mk_lib_fast_import_tree_node_val);

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_tree_node_s
{
	mk_lib_fast_import_tree_node_id_t m_type;
	mk_lib_fast_import_tree_node_val_t m_val;
	mk_lib_fast_import_string_t m_name;
};
typedef struct mk_lib_fast_import_tree_node_s mk_lib_fast_import_tree_node_t;
mk_lang_typedef(mk_lib_fast_import_tree_node);
#include "mk_lang_warning_msvc_pop.h"

#define mk_sl_vector_t_name mk_lib_fast_import_tree_nodes
#define mk_sl_vector_t_element_type mk_lib_fast_import_tree_node_t
#define mk_sl_vector_t_mallocatorl mk_lib_fast_import_mallocator_lokal
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_tree_s
{
	mk_lib_fast_import_pt m_fi;
	mk_lang_types_pchar_t m_mode_buf[mk_sl_cui_uint32_strlen_dec_v];
	mk_lang_types_sint_t m_mode_len;
	mk_lib_fast_import_tree_nodes_t m_children;
	mk_lib_fast_import_binary_data_t m_data;
	mk_lang_types_bool_t m_digest_computed;
	mk_lib_crypto_hash_stream_sha1_digest_t m_digest_value;
};
typedef struct mk_lib_fast_import_tree_s mk_lib_fast_import_tree_t;
mk_lang_typedef(mk_lib_fast_import_tree);
#include "mk_lang_warning_msvc_pop.h"


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_s
{
	mk_lib_fast_import_mallocator_lokal_pt m_mallocator;
	mk_lib_fast_import_buffered_reader_t m_buffered_reader;
	mk_sl_cui_uint8_pt m_buf;
	mk_lang_types_sint_t m_len;
	mk_lib_fast_import_tree_by_mark_t m_marks;
	mk_lib_fast_import_string_t m_output_dir;
};
typedef struct mk_lib_fast_import_s mk_lib_fast_import_t;
mk_lang_typedef(mk_lib_fast_import);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_blob_cmp(mk_lib_fast_import_blob_pct const a, mk_lib_fast_import_blob_pct const b, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lang_types_sint_t c;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(cmp);

	c = mk_sl_cui_uint128_cmp(&a->m_mark, &b->m_mark);
	*cmp = c;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_blob_copy_construct(mk_lib_fast_import_blob_pt const dst, mk_lib_fast_import_blob_pct const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	dst->m_fi = src->m_fi;
	dst->m_mark = src->m_mark;
	dst->m_binary_len = src->m_binary_len;
	dst->m_binary_buf = src->m_binary_buf;
	dst->m_digest = src->m_digest;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_blob_move_construct(mk_lib_fast_import_blob_pt const dst, mk_lib_fast_import_blob_pt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	dst->m_fi = src->m_fi;
	dst->m_mark = src->m_mark;
	dst->m_binary_len = src->m_binary_len;
	dst->m_binary_buf = src->m_binary_buf;
	dst->m_digest = src->m_digest;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_blob_destroy(mk_lib_fast_import_blob_pt const x) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	err = mk_lib_fast_import_mallocator_lokal_deallocate(x->m_fi->m_mallocator, x->m_binary_buf, x->m_binary_len); mk_lang_check_rereturn(err);
	return 0;
}


#define mk_sl_tree_wavl_t_name mk_lib_fast_import_tree_by_mark
#define mk_sl_tree_wavl_t_element_type mk_lib_fast_import_blob_t
#define mk_sl_tree_wavl_t_elements_compare mk_lib_fast_import_blob_cmp
#define mk_sl_tree_wavl_t_mallocatorl_name mk_lib_fast_import_mallocator_lokal
#define mk_sl_tree_wavl_t_validate_want 0
#define mk_sl_tree_wavl_t_element_copy_construct mk_lib_fast_import_blob_copy_construct
#define mk_sl_tree_wavl_t_element_move_construct mk_lib_fast_import_blob_move_construct
#define mk_sl_tree_wavl_t_element_destruct mk_lib_fast_import_blob_destroy
#include "mk_sl_tree_wavl_inl_filec.h"
#include "mk_sl_tree_wavl_inl_fileu.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_commit_rw_construct(mk_lib_fast_import_commit_pt const commit, mk_lib_fast_import_pt const fi) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(commit);
	mk_lang_assert(fi);

	commit->m_fi = fi;
	err = mk_lib_fast_import_string_rw_construct(&commit->m_ref, fi->m_mallocator); mk_lang_check_rereturn(err);
	commit->m_has_mark = mk_lang_false;
	mk_sl_cui_uint128_set_zero(&commit->m_mark);
	err = mk_lib_fast_import_string_rw_construct(&commit->m_author_name, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_construct(&commit->m_author_email, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_construct(&commit->m_author_timestamp, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_construct(&commit->m_committer_name, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_construct(&commit->m_committer_email, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_construct(&commit->m_committer_timestamp, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_construct(&commit->m_message, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_file_ops_rw_construct(&commit->m_file_ops, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_construct(&commit->m_data, fi->m_mallocator); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_commit_rw_destroy(mk_lib_fast_import_commit_pt const commit) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(commit);

	err = mk_lib_fast_import_string_rw_destroy(&commit->m_ref); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_destroy(&commit->m_author_name); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_destroy(&commit->m_author_email); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_destroy(&commit->m_author_timestamp); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_destroy(&commit->m_committer_name); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_destroy(&commit->m_committer_email); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_destroy(&commit->m_committer_timestamp); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_destroy(&commit->m_message); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_file_ops_rw_destroy(&commit->m_file_ops); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_destroy(&commit->m_data); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_reset_rw_construct(mk_lib_fast_import_reset_pt const reset, mk_lib_fast_import_pt const fi) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(reset);
	mk_lang_assert(fi);

	reset->m_fi = fi;
	err = mk_lib_fast_import_string_rw_construct(&reset->m_ref, fi->m_mallocator); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_reset_rw_destroy(mk_lib_fast_import_reset_pt const reset) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(reset);

	err = mk_lib_fast_import_string_rw_destroy(&reset->m_ref); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_fi_pr_construct(mk_lib_fast_import_pt const fi) mk_lang_noexcept
{
	mk_lang_assert(fi);

	fi->m_mallocator = mk_lang_null;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_fi_pr_destroy(mk_lib_fast_import_pt const fi) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);

	err = mk_sl_io_reader_file_close(&fi->m_buffered_reader.m_reader); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_tree_by_mark_rw_destruct(&fi->m_marks); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_fi_pr_set_mallocator(mk_lib_fast_import_pt const fi, mk_lib_fast_import_mallocator_lokal_pt const mallocator) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(mallocator);
	mk_lang_assert(!fi->m_mallocator);

	fi->m_mallocator = mallocator;
	err = mk_lib_fast_import_string_rw_construct(&fi->m_output_dir, fi->m_mallocator); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_fi_pr_set_input_file(mk_lib_fast_import_pt const fi, mk_lang_types_pchar_pct const file_path) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(file_path);
	mk_lang_assert(file_path[0] != '\0');

	err = mk_lib_fast_import_tree_by_mark_rw_construct(&fi->m_marks, fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_sl_io_reader_file_open_n(&fi->m_buffered_reader.m_reader, file_path); mk_lang_check_rereturn(err);
	err = mk_sl_io_reader_file_read(&fi->m_buffered_reader.m_reader, &fi->m_buffered_reader.m_data_buf[0], mk_lang_countof(fi->m_buffered_reader.m_data_buf), &fi->m_buffered_reader.m_data_len); mk_lang_check_rereturn(err);
	fi->m_buf = &fi->m_buffered_reader.m_data_buf[0];
	fi->m_len = fi->m_buffered_reader.m_data_len;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_fi_pr_set_output_dir(mk_lib_fast_import_pt const fi, mk_lang_types_pchar_pct const dir_path) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(mk_lib_fast_import_string_ro_is_empty(&fi->m_output_dir));
	mk_lang_assert(dir_path);
	mk_lang_assert(dir_path[0] != '\0');

	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, dir_path, mk_lang_str_len_n(dir_path)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_save_blob_to_database_4(mk_sl_io_writer_file_pt const writer, mk_lib_zlib_pt const zlib) mk_lang_noexcept
{
	mk_lang_types_sint_t out_len;
	mk_sl_cui_uint8_t out_buf[4 * 1024];
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t out_c;
	mk_lang_types_sint_t w;

	mk_lang_assert(writer);
	mk_lang_assert(zlib);

	do
	{
		out_len = mk_lang_countof(out_buf);
		err = mk_lib_zlib_finish(zlib, &out_buf[0], out_len, &out_c); mk_lang_check_rereturn(err);
		err = mk_sl_io_writer_file_write(writer, &out_buf[0], out_c, &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == out_c);
	}while(out_c != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_save_blob_to_database_3(mk_sl_io_writer_file_pt const writer, mk_lib_zlib_pt const zlib, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_buf;
	mk_lang_types_sint_t in_len;
	mk_lang_types_sint_t out_len;
	mk_sl_cui_uint8_t out_buf[4 * 1024];
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t in_c;
	mk_lang_types_sint_t out_c;
	mk_lang_types_sint_t w;

	mk_lang_assert(writer);
	mk_lang_assert(zlib);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);

	in_buf = data_buf;
	in_len = data_len;
	while(in_len != 0)
	{
		out_len = mk_lang_countof(out_buf);
		err = mk_lib_zlib_append(zlib, in_buf, in_len, &out_buf[0], out_len, &in_c, &out_c); mk_lang_check_rereturn(err);
		err = mk_sl_io_writer_file_write(writer, &out_buf[0], out_c, &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == out_c);
		in_buf += in_c;
		in_len -= in_c;
	}

	/*err = mk_sl_io_writer_file_write(writer, &prefix[0], mk_lang_countof(prefix), &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == mk_lang_countof(prefix));
	err = mk_sl_io_writer_file_write(writer, &str_u8[0], in_len, &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == in_len);
	err = mk_sl_io_writer_file_write(writer, &zero, 1, &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == 1);
	err = mk_sl_io_writer_file_write(writer, blob->m_binary_buf, blob->m_binary_len, &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == blob->m_binary_len);*/
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_save_blob_to_database_2(mk_lib_fast_import_pt const fi, mk_sl_io_writer_file_pt const writer, mk_lib_fast_import_blob_pct const blob) mk_lang_noexcept
{
	mk_sl_cui_uint8_t prefix[mk_lang_countstr(mk_lib_fast_import_k_blobsp)];
	mk_lang_bui_uint_t bui;
	mk_lang_types_sint_t len;
	mk_lang_types_pchar_t str_pc[mk_lang_bui_uint_strlen_dec_v];
	mk_sl_cui_uint8_t str_u8[mk_lang_bui_uint_strlen_dec_v];
	mk_sl_cui_uint8_t zero;
	mk_lang_types_sint_t err;
	mk_lib_zlib_t zlib;

	mk_lang_assert(fi);
	mk_lang_assert(writer);
	mk_lang_assert(blob);
	mk_lang_assert(blob->m_binary_buf || blob->m_binary_len == 0);
	mk_lang_assert(blob->m_binary_len >= 0);

	((mk_lang_types_void_t)(fi));
	mk_sl_cui_uint8_from_bi_pchar_many(&prefix[0], &mk_lib_fast_import_k_blobsp[0], mk_lang_countof(prefix));
	bui = ((mk_lang_bui_uint_t)(blob->m_binary_len));
	len = mk_lang_bui_uint_to_str_dec_n(&bui, &str_pc[0], mk_lang_bui_uint_strlen_dec_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&str_u8[0], &str_pc[0], mk_lang_bui_uint_strlen_dec_v);
	mk_sl_cui_uint8_set_zero(&zero);
	err = mk_lib_zlib_init(&zlib); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_save_blob_to_database_3(writer, &zlib, &prefix[0], mk_lang_countof(prefix)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_save_blob_to_database_3(writer, &zlib, &str_u8[0], len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_save_blob_to_database_3(writer, &zlib, &zero, 1); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_save_blob_to_database_3(writer, &zlib, blob->m_binary_buf, blob->m_binary_len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_save_blob_to_database_4(writer, &zlib); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_save_blob_to_database(mk_lib_fast_import_pt const fi, mk_lib_fast_import_blob_pct const blob) mk_lang_noexcept
{
	mk_lang_types_pchar_t tpc;
	mk_lang_types_pchar_t str[mk_lib_crypto_hash_block_sha1_digest_len_v * mk_sl_cui_uint8_strlen_hex_v];
	mk_lang_types_usize_t old_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;
	mk_sl_io_writer_file_t writer;
	mk_win_base_bool_t b; /* todo */
	mk_win_base_dword_t gle; /* todo */

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(!mk_lib_fast_import_string_ro_is_empty(&fi->m_output_dir));
	mk_lang_assert(blob);

	old_len = mk_lib_fast_import_string_ro_size(&fi->m_output_dir);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &mk_lib_fast_import_k_dot_git[0], mk_lang_countstr(mk_lib_fast_import_k_dot_git)); mk_lang_check_rereturn(err);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &mk_lib_fast_import_k_objects[0], mk_lang_countstr(mk_lib_fast_import_k_objects)); mk_lang_check_rereturn(err);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	len = mk_sl_cui_uint8_to_str_hexf_n(&blob->m_digest.m_data.m_uint8s[0], &str[0], mk_sl_cui_uint8_strlen_hex_v); mk_lang_assert(len == mk_sl_cui_uint8_strlen_hex_v);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &str[0], mk_sl_cui_uint8_strlen_hex_v); mk_lang_check_rereturn(err);
	tpc = '\0';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	b = mk_win_dll_kernel_files_a_create_directory(mk_lib_fast_import_string_ro_data(&fi->m_output_dir), mk_win_base_null); mk_lang_check_return(b != 0 || (gle = mk_win_dll_kernel_errors_get_last()) == mk_win_dll_kernel_errors_id_e_already_exists); /* todo */
	err = mk_lib_fast_import_string_rw_pop_back_single(&fi->m_output_dir); mk_lang_check_rereturn(err);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	len = mk_sl_cui_uint8_to_str_hexf_many_n(&blob->m_digest.m_data.m_uint8s[1], mk_lib_crypto_hash_block_sha1_digest_len_v - 1, &str[0], mk_lang_countof(str)); mk_lang_assert(len == (mk_lib_crypto_hash_block_sha1_digest_len_v - 1) * mk_sl_cui_uint8_strlen_hex_v);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &str[0], (mk_lib_crypto_hash_block_sha1_digest_len_v - 1) * mk_sl_cui_uint8_strlen_hex_v); mk_lang_check_rereturn(err);
	tpc = '\0';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_open_n(&writer, mk_lib_fast_import_string_ro_data(&fi->m_output_dir)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_save_blob_to_database_2(fi, &writer, blob); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_resize_to(&fi->m_output_dir, old_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_compute_tree_len(mk_lib_fast_import_pt const fi, mk_lib_fast_import_file_ops_pct const tree, mk_lang_types_sint_pt const len) mk_lang_noexcept
{
	mk_lang_types_sint_t acc;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_fast_import_file_op_pct file;
	mk_lang_types_sint_t slen;
	mk_lang_types_pchar_t str[mk_sl_cui_uint32_strlen_dec_v];

	mk_lang_assert(fi);
	mk_lang_assert(tree);
	mk_lang_assert(len);

	((mk_lang_types_void_t)(fi));
	acc = 0;
	n = mk_lib_fast_import_file_ops_ro_size(tree);
	for(i = 0; i != n; ++i)
	{
		file = mk_lib_fast_import_file_ops_ro_at(tree, i); mk_lang_assert(file);
		slen = mk_sl_cui_uint32_to_str_dec_n(&file->m_file_modify.m_mode, &str[0], mk_lang_countof(str)); acc += slen;
		acc += 1; /* sp */
		acc += ((mk_lang_types_sint_t)(mk_lib_fast_import_string_ro_size(&file->m_file_modify.m_path)));
		acc += 1; /* nul */
		acc += mk_lib_crypto_hash_stream_sha1_digest_len_v; /* digest */
	}
	*len = acc;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_append_u8s(mk_lib_fast_import_pt const fi, mk_lib_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes, mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_buf;
	mk_lang_types_sint_t in_len;
	mk_sl_cui_uint8_pt out_buf;
	mk_sl_cui_uint8_t u8s[512];
	mk_lang_types_sint_t out_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t in_c;
	mk_lang_types_sint_t out_c;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);
	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);

	in_buf = buf;
	in_len = len;
	out_buf = &u8s[0];
	out_len = mk_lang_countof(u8s);
	do
	{
		err = mk_lib_zlib_append(zlib, in_buf, in_len, out_buf, out_len, &in_c, &out_c); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_binary_data_rw_push_back_copy_many(bytes, out_buf, out_c); mk_lang_check_rereturn(err);
		in_buf += in_c;
		in_len -= in_c;
	}while(in_len != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_append_pchars(mk_lib_fast_import_pt const fi, mk_lib_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes, mk_lang_types_pchar_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_sl_cui_uint8_t u8s[512];
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);
	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);

	if(len > mk_lang_countof(u8s))
	{
		mk_lang_check_todo();
	}
	mk_sl_cui_uint8_from_bi_pchar_many(&u8s[0], buf, len);
	err = mk_lib_fast_import_pr_tree_append_u8s(fi, zlib, bytes, &u8s[0], len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_finish(mk_lib_fast_import_pt const fi, mk_lib_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt out_buf;
	mk_sl_cui_uint8_t u8s[512];
	mk_lang_types_sint_t out_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t out_c;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);

	out_buf = &u8s[0];
	out_len = mk_lang_countof(u8s);
	do
	{
		err = mk_lib_zlib_finish(zlib, out_buf, out_len, &out_c); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_binary_data_rw_push_back_copy_many(bytes, out_buf, out_c); mk_lang_check_rereturn(err);
	}while(out_c != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_append_file_op_mode(mk_lib_fast_import_pt const fi, mk_lib_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes, mk_lib_fast_import_file_op_pct const file_op) mk_lang_noexcept
{
	mk_lang_types_sint_t slen;
	mk_lang_types_pchar_t str[mk_sl_cui_uint32_strlen_dec_v];
	mk_sl_cui_uint8_t u8s[mk_sl_cui_uint32_strlen_dec_v];
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);
	mk_lang_assert(file_op);

	slen = mk_sl_cui_uint32_to_str_dec_n(&file_op->m_file_modify.m_mode, &str[0], mk_lang_countof(str)); mk_lang_assert(slen >= 1); mk_lang_assert(slen <= mk_lang_countof(str));
	mk_sl_cui_uint8_from_bi_pchar_many(&u8s[0], &str[0], slen);
	err = mk_lib_fast_import_pr_tree_append_u8s(fi, zlib, bytes, &u8s[0], slen); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_append_file_op_sp(mk_lib_fast_import_pt const fi, mk_lib_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes, mk_lib_fast_import_file_op_pct const file_op) mk_lang_noexcept
{
	mk_lang_types_pchar_t tpc;
	mk_sl_cui_uint8_t u8s;
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);
	mk_lang_assert(file_op);

	tpc = ' ';
	mk_sl_cui_uint8_from_bi_pchar_many(&u8s, &tpc, 1);
	err = mk_lib_fast_import_pr_tree_append_u8s(fi, zlib, bytes, &u8s, 1); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_append_file_op_nul(mk_lib_fast_import_pt const fi, mk_lib_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes, mk_lib_fast_import_file_op_pct const file_op) mk_lang_noexcept
{
	mk_lang_types_pchar_t tpc;
	mk_sl_cui_uint8_t u8s;
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);
	mk_lang_assert(file_op);

	tpc = '\0';
	mk_sl_cui_uint8_from_bi_pchar_many(&u8s, &tpc, 1);
	err = mk_lib_fast_import_pr_tree_append_u8s(fi, zlib, bytes, &u8s, 1); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_append_file_op_name(mk_lib_fast_import_pt const fi, mk_lib_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes, mk_lib_fast_import_file_op_pct const file_op) mk_lang_noexcept
{
	mk_lang_types_usize_t u_file_name;
	mk_lang_types_sint_t i_file_name;
	mk_sl_cui_uint8_t u8s[512];
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);
	mk_lang_assert(file_op);

	u_file_name = mk_lib_fast_import_string_ro_size(&file_op->m_file_modify.m_path);
	i_file_name = ((mk_lang_types_sint_t)(u_file_name));
	if(i_file_name > mk_lang_countof(u8s))
	{
		mk_lang_check_todo();
	}
	mk_sl_cui_uint8_from_bi_pchar_many(&u8s[0], mk_lib_fast_import_string_ro_data(&file_op->m_file_modify.m_path), u_file_name);
	err = mk_lib_fast_import_pr_tree_append_u8s(fi, zlib, bytes, &u8s[0], i_file_name); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_file_find_digest(mk_lib_fast_import_pt const fi, mk_sl_cui_uint128_pct const file_ref, mk_lib_crypto_hash_stream_sha1_digest_pct* const digest) mk_lang_noexcept
{
	mk_lib_fast_import_blob_t blob;
	mk_lang_types_sint_t err;
	mk_lib_fast_import_tree_by_mark_node_pct node;

	mk_lang_assert(fi);
	mk_lang_assert(file_ref);
	mk_lang_assert(digest);

	blob.m_mark = *file_ref;
	err = mk_lib_fast_import_tree_by_mark_ro_find_node(&fi->m_marks, &blob, &node); mk_lang_check_rereturn(err);
	if(node)
	{
		*digest = &node->m_element.m_digest;
	}
	else
	{
		*digest = mk_lang_null;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_append_file_op_digest(mk_lib_fast_import_pt const fi, mk_lib_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes, mk_lib_fast_import_file_op_pct const file_op) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_crypto_hash_stream_sha1_digest_pct digest;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);
	mk_lang_assert(file_op);

	err = mk_lib_fast_import_pr_file_find_digest(fi, &file_op->m_file_modify.m_data_ref, &digest); mk_lang_check_rereturn(err); mk_lang_check_return(digest);
	err = mk_lib_fast_import_pr_tree_append_u8s(fi, zlib, bytes, &digest->m_data.m_uint8s[0], mk_lang_countof(digest->m_data.m_uint8s)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_append_file_op(mk_lib_fast_import_pt const fi, mk_lib_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes, mk_lib_fast_import_file_op_pct const file_op) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);
	mk_lang_assert(file_op);

	err = mk_lib_fast_import_pr_tree_append_file_op_mode(fi, zlib, bytes, file_op); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_tree_append_file_op_sp(fi, zlib, bytes, file_op); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_tree_append_file_op_name(fi, zlib, bytes, file_op); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_tree_append_file_op_nul(fi, zlib, bytes, file_op); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_tree_append_file_op_digest(fi, zlib, bytes, file_op); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_compute_tree_bytes(mk_lib_fast_import_pt const fi, mk_lib_fast_import_file_ops_pct const tree, mk_lib_fast_import_binary_data_pt const bytes) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;
	mk_lang_types_uint_t ulen;
	mk_lang_types_sint_t slen;
	mk_lang_types_pchar_t str[mk_lang_bui_uint_strlen_dec_v];
	mk_lang_types_sint_t size;
	mk_lang_types_pchar_t nul;
	mk_lib_zlib_t zlib;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_fast_import_file_op_pct file_op;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(!mk_lib_fast_import_string_ro_is_empty(&fi->m_output_dir));
	mk_lang_assert(tree);

	err = mk_lib_fast_import_binary_data_rw_clear(bytes); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_compute_tree_len(fi, tree, &len); mk_lang_check_rereturn(err); mk_lang_assert(len >= 1);
	ulen = ((mk_lang_types_uint_t)(len));
	slen = mk_lang_bui_uint_to_str_dec_n(&ulen, &str[0], mk_lang_countof(str)); mk_lang_assert(slen >= 1); mk_lang_assert(slen <= mk_lang_countof(str));
	nul = '\0';
	size = 0;
	size += 2; /* zlib header */
	size += 5; /* deflate block header */
	size += mk_lang_countstr(mk_lib_fast_import_k_treesp);
	size += slen;
	size += 1; /* nul */
	size += ulen;
	size += 4; /* zlib footer */
	err = mk_lib_fast_import_binary_data_rw_reserve_at_least(bytes, size); mk_lang_check_rereturn(err);
	err = mk_lib_zlib_init(&zlib); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_tree_append_pchars(fi, &zlib, bytes, &mk_lib_fast_import_k_treesp[0], mk_lang_countstr(mk_lib_fast_import_k_treesp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_tree_append_pchars(fi, &zlib, bytes, &str[0], slen); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_tree_append_pchars(fi, &zlib, bytes, &nul, 1); mk_lang_check_rereturn(err);
	n = mk_lib_fast_import_file_ops_ro_size(tree);
	for(i = 0; i != n; ++i)
	{
		file_op = mk_lib_fast_import_file_ops_ro_at(tree, i); mk_lang_assert(file_op);
		err = mk_lib_fast_import_pr_tree_append_file_op(fi, &zlib, bytes, file_op); mk_lang_check_rereturn(err);
	}
	err = mk_lib_fast_import_pr_tree_finish(fi, &zlib, bytes); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_free_binary_data(mk_lib_fast_import_blob_pt const blob) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(blob);

	err = mk_lib_fast_import_mallocator_lokal_deallocate(blob->m_fi->m_mallocator, blob->m_binary_buf, blob->m_binary_len); mk_lang_check_rereturn(err);
	blob->m_binary_buf = mk_lang_null;
	blob->m_binary_len = 0;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_string(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(str_buf);
	mk_lang_assert(str_len >= 1);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_false;
	if(l >= str_len)
	{
		b = mk_sl_cui_uint8_eq_pchar_many(&d[0], &str_buf[0], str_len);
	}
	if(b)
	{
		d += str_len;
		l -= str_len;
	}
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_number(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_sl_cui_uint128_pt const number) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t n;
	mk_lang_types_pchar_t str[mk_sl_cui_uint128_strlen_dec_v];
	mk_lang_types_sint_t len;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);
	mk_lang_assert(number);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_false;
	n = mk_lang_min(l, mk_lang_countof(str));
	if(n >= 1)
	{
		mk_sl_cui_uint8_to_bi_pchar_many(&d[0], &str[0], n);
		len = mk_sl_cui_uint128_from_str_dec_n(number, &str[0], n); mk_lang_assert(len <= n);
		if(len >= 1)
		{
			d += len;
			l -= len;
			b = mk_lang_true;
		}
	}
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_u32(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_sl_cui_uint32_pt const u32) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t n;
	mk_lang_types_pchar_t str[mk_sl_cui_uint32_strlen_dec_v];
	mk_lang_types_sint_t len;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);
	mk_lang_assert(u32);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_false;
	n = mk_lang_min(l, mk_lang_countof(str));
	if(n != 0)
	{
		mk_sl_cui_uint8_to_bi_pchar_many(&d[0], &str[0], n);
		len = mk_sl_cui_uint32_from_str_dec_n(u32, &str[0], n); mk_lang_assert(len <= n);
		if(len >= 1)
		{
			d += len;
			l -= len;
			b = mk_lang_true;
		}
	}
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_data_ref(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_sl_cui_uint128_pt const u128) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t n;
	mk_lang_types_pchar_t str[mk_sl_cui_uint128_strlen_dec_v];
	mk_lang_types_sint_t len;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);
	mk_lang_assert(u128);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_false;
	n = mk_lang_min(l, mk_lang_countof(str));
	if(n != 0)
	{
		mk_sl_cui_uint8_to_bi_pchar_many(&d[0], &str[0], n);
		len = mk_sl_cui_uint128_from_str_dec_n(u128, &str[0], n); mk_lang_assert(len <= n);
		if(len >= 1)
		{
			d += len;
			l -= len;
			b = mk_lang_true;
		}
	}
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_string_splt(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lib_fast_import_string_pt const string) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct str_buf;
	mk_lang_types_sint_t str_len;

	mk_lang_assert(data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(did);
	mk_lang_assert(string);
	mk_lang_assert(*data_buf || *data_len == 0);
	mk_lang_assert(*data_len >= 0);

	d = *data_buf;
	l = *data_len;
	n = l - mk_lang_countstr(mk_lib_fast_import_k_splt);
	for(i = 0; i != n; ++i)
	{
		if(mk_sl_cui_uint8_eq_pchar_many(&d[i], &mk_lib_fast_import_k_splt[0], mk_lang_countstr(mk_lib_fast_import_k_splt)))
		{
			break;
		}
	}
	b = i != n;
	if(b)
	{
		str_buf = ((mk_lang_types_pchar_pct)(&d[0]));
		str_len = i;
		err = mk_lib_fast_import_string_rw_clear(string); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_string_rw_push_back_copy_many(string, str_buf, str_len); mk_lang_check_rereturn(err);
		d += str_len + mk_lang_countstr(mk_lib_fast_import_k_splt);
		l -= str_len + mk_lang_countstr(mk_lib_fast_import_k_splt);
	}
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_string_gtsp(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lib_fast_import_string_pt const string) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct str_buf;
	mk_lang_types_sint_t str_len;

	mk_lang_assert(data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(did);
	mk_lang_assert(string);
	mk_lang_assert(*data_buf || *data_len == 0);
	mk_lang_assert(*data_len >= 0);

	d = *data_buf;
	l = *data_len;
	n = l - mk_lang_countstr(mk_lib_fast_import_k_gtsp);
	for(i = 0; i != n; ++i)
	{
		if(mk_sl_cui_uint8_eq_pchar_many(&d[i], &mk_lib_fast_import_k_gtsp[0], mk_lang_countstr(mk_lib_fast_import_k_gtsp)))
		{
			break;
		}
	}
	b = i != n;
	if(b)
	{
		str_buf = ((mk_lang_types_pchar_pct)(&d[0]));
		str_len = i;
		err = mk_lib_fast_import_string_rw_clear(string); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_string_rw_push_back_copy_many(string, str_buf, str_len); mk_lang_check_rereturn(err);
		d += str_len + mk_lang_countstr(mk_lib_fast_import_k_gtsp);
		l -= str_len + mk_lang_countstr(mk_lib_fast_import_k_gtsp);
	}
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_string_lf(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lib_fast_import_string_pt const string) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct str_buf;
	mk_lang_types_sint_t str_len;

	mk_lang_assert(data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(did);
	mk_lang_assert(string);
	mk_lang_assert(*data_buf || *data_len == 0);
	mk_lang_assert(*data_len >= 0);

	d = *data_buf;
	l = *data_len;
	n = l - mk_lang_countstr(mk_lib_fast_import_k_lf);
	for(i = 0; i != n; ++i)
	{
		if(mk_sl_cui_uint8_eq_pchar_many(&d[i], &mk_lib_fast_import_k_lf[0], mk_lang_countstr(mk_lib_fast_import_k_lf)))
		{
			break;
		}
	}
	b = i != n;
	if(b)
	{
		str_buf = ((mk_lang_types_pchar_pct)(&d[0]));
		str_len = i;
		err = mk_lib_fast_import_string_rw_clear(string); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_string_rw_push_back_copy_many(string, str_buf, str_len); mk_lang_check_rereturn(err);
		d += str_len + mk_lang_countstr(mk_lib_fast_import_k_lf);
		l -= str_len + mk_lang_countstr(mk_lib_fast_import_k_lf);
	}
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_binary_suffix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_lf[0], mk_lang_countstr(mk_lib_fast_import_k_lf), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_data_prefix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_data[0], mk_lang_countstr(mk_lib_fast_import_k_data), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_data_suffix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_lf[0], mk_lang_countstr(mk_lib_fast_import_k_lf), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_data_whole(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lang_types_sint_pt const binary_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;
	mk_sl_cui_uint128_t number;
	mk_lang_types_sint_t tsi;
	mk_sl_cui_uint128_t cui;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);
	mk_lang_assert(binary_len);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_true;
	if(b){ err = mk_lib_fast_import_st_do_data_prefix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_number(&d, &l, &b, &number); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_data_suffix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b)
	{
		tsi = mk_lang_limits_sint_max; mk_sl_cui_uint128_from_bi_sint(&cui, &tsi);
		mk_lang_check_return(mk_sl_cui_uint128_le(&number, &cui));
		mk_sl_cui_uint128_to_bi_sint(&number, binary_len);
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_mark_prefix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_mark_sp_colon[0], mk_lang_countstr(mk_lib_fast_import_k_mark_sp_colon), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_from_prefix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_from_sp_colon[0], mk_lang_countstr(mk_lib_fast_import_k_from_sp_colon), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_author_prefix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_authorsp[0], mk_lang_countstr(mk_lib_fast_import_k_authorsp), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_committer_prefix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_committersp[0], mk_lang_countstr(mk_lib_fast_import_k_committersp), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_mark_suffix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_lf[0], mk_lang_countstr(mk_lib_fast_import_k_lf), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_from_suffix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_lf[0], mk_lang_countstr(mk_lib_fast_import_k_lf), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_mark_whole(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_sl_cui_uint128_pt const mark) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);
	mk_lang_assert(mark);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_true;
	if(b){ err = mk_lib_fast_import_st_do_mark_prefix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_number(&d, &l, &b, mark); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_mark_suffix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_blob_prefix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_blob[0], mk_lang_countstr(mk_lib_fast_import_k_blob), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_commit_prefix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_commitsp[0], mk_lang_countstr(mk_lib_fast_import_k_commitsp), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_reset_prefix(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_resetsp[0], mk_lang_countstr(mk_lib_fast_import_k_resetsp), &b); mk_lang_check_rereturn(err);
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_blob_whole(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lib_fast_import_blob_pt const blob) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(data_buf);
	mk_lang_assert(*data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(*data_len >= 0);
	mk_lang_assert(did);
	mk_lang_assert(blob);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_true;
	if(b){ err = mk_lib_fast_import_st_do_blob_prefix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_mark_whole(&d, &l, &b, &blob->m_mark); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_data_whole(&d, &l, &b, &blob->m_binary_len); mk_lang_check_rereturn(err); }
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_ref_lf(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lib_fast_import_string_pt const ref) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_sl_cui_uint8_t cui;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct str_buf;
	mk_lang_types_sint_t str_len;

	mk_lang_assert(data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(did);
	mk_lang_assert(ref);
	mk_lang_assert(*data_buf || *data_len == 0);
	mk_lang_assert(*data_len >= 0);

	d = *data_buf;
	l = *data_len;
	mk_sl_cui_uint8_from_bi_pchar(&cui, &mk_lib_fast_import_k_lf[0]);
	n = l;
	for(i = 0; i != n; ++i)
	{
		if(mk_sl_cui_uint8_eq(&d[i], &cui))
		{
			break;
		}
	}
	b = i != n;
	if(b)
	{
		str_buf = ((mk_lang_types_pchar_pct)(&d[0]));
		str_len = i;
		err = mk_lib_fast_import_string_rw_clear(ref); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_string_rw_push_back_copy_many(ref, str_buf, str_len); mk_lang_check_rereturn(err);
		d += str_len + 1;
		l -= str_len + 1;
	}
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_mark_opt(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lang_types_bool_pt const mark_has, mk_sl_cui_uint128_pt const mark_val) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_bool_t b_old;
	mk_lang_types_sint_t err;

	mk_lang_assert(data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(did);
	mk_lang_assert(mark_has);
	mk_lang_assert(mark_val);
	mk_lang_assert(*data_buf || *data_len == 0);
	mk_lang_assert(*data_len >= 0);

	d = *data_buf;
	l = *data_len;
	err = mk_lib_fast_import_st_do_mark_prefix(&d, &l, &b); mk_lang_check_rereturn(err);
	b_old = b;
	b = mk_lang_true;
	if(b_old)
	{
		err = mk_lib_fast_import_st_do_number(&d, &l, &b, mark_val); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_st_do_mark_suffix(&d, &l, &b); mk_lang_check_rereturn(err);
		*mark_has = b;
	}
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_from_mark(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_sl_cui_uint128_pt const mark) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(did);
	mk_lang_assert(mark);
	mk_lang_assert(*data_buf || *data_len == 0);
	mk_lang_assert(*data_len >= 0);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_true;
	if(b){ err = mk_lib_fast_import_st_do_from_prefix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_number(&d, &l, &b, mark); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_from_suffix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_author(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lib_fast_import_string_pt const name, mk_lib_fast_import_string_pt const email, mk_lib_fast_import_string_pt const timestamp) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(did);
	mk_lang_assert(name);
	mk_lang_assert(email);
	mk_lang_assert(timestamp);
	mk_lang_assert(*data_buf || *data_len == 0);
	mk_lang_assert(*data_len >= 0);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_true;
	if(b){ err = mk_lib_fast_import_st_do_author_prefix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string_splt(&d, &l, &b, name); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string_gtsp(&d, &l, &b, email); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string_lf(&d, &l, &b, timestamp); mk_lang_check_rereturn(err); }
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_do_committer(mk_sl_cui_uint8_ppt const data_buf, mk_lang_types_sint_pt const data_len, mk_lang_types_bool_pt const did, mk_lib_fast_import_string_pt const name, mk_lib_fast_import_string_pt const email, mk_lib_fast_import_string_pt const timestamp) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(did);
	mk_lang_assert(name);
	mk_lang_assert(email);
	mk_lang_assert(timestamp);
	mk_lang_assert(*data_buf || *data_len == 0);
	mk_lang_assert(*data_len >= 0);

	d = *data_buf;
	l = *data_len;
	b = mk_lang_true;
	if(b){ err = mk_lib_fast_import_st_do_committer_prefix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string_splt(&d, &l, &b, name); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string_gtsp(&d, &l, &b, email); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string_lf(&d, &l, &b, timestamp); mk_lang_check_rereturn(err); }
	if(b)
	{
		*data_buf = d;
		*data_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_reread(mk_lib_fast_import_pt const fi) mk_lang_noexcept
{
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);

	if(fi->m_len <= mk_lib_fast_import_k_buf_len)
	{
		if(fi->m_len != 0)
		{
			mk_sl_cui_uint8_memmov_fn(&fi->m_buffered_reader.m_data_buf[0], fi->m_buf, fi->m_len);
		}
		rem = mk_lang_countof(fi->m_buffered_reader.m_data_buf) - fi->m_len;
		err = mk_sl_io_reader_file_read(&fi->m_buffered_reader.m_reader, &fi->m_buffered_reader.m_data_buf[fi->m_len], rem, &fi->m_buffered_reader.m_data_len); mk_lang_check_rereturn(err);
		fi->m_buf = &fi->m_buffered_reader.m_data_buf[0];
		fi->m_len = fi->m_len + fi->m_buffered_reader.m_data_len;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_binary_data_2(mk_lib_fast_import_pt const fi, mk_lang_types_sint_t const binary_len, mk_lib_fast_import_binary_data_pt const binary_data) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pt bin_buf;
	mk_lang_types_sint_t bin_len;
	mk_lang_types_sint_t to_copy;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(binary_len >= 0);
	mk_lang_assert(binary_data);

	err = mk_lib_fast_import_binary_data_rw_clear(binary_data); mk_lang_check_rereturn(err);
	if(binary_len != 0)
	{
		err = mk_lib_fast_import_binary_data_rw_reserve_at_least(binary_data, binary_len); mk_lang_check_rereturn(err);
		bin_buf = mk_lib_fast_import_binary_data_rw_data(binary_data); mk_lang_assert(bin_buf);
		bin_len = binary_len;
		do
		{
			to_copy = mk_lang_min(bin_len, fi->m_len);
			mk_sl_cui_uint8_memcpy_fn(bin_buf, fi->m_buf, to_copy);
			fi->m_buf += to_copy;
			fi->m_len -= to_copy;
			bin_buf += to_copy;
			bin_len -= to_copy;
			err = mk_lib_fast_import_pr_reread(fi); mk_lang_check_rereturn(err);
		}while(bin_len != 0);
		err = mk_lib_fast_import_binary_data_rw_resize_to(binary_data, binary_len); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_data_with_binary_data(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_binary_data_pt const binary_data) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t binary_len;
	mk_lang_types_sint_t err;

	b = mk_lang_true;
	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(did);
	mk_lang_assert(binary_data);

	d = fi->m_buf;
	l = fi->m_len;
	b = mk_lang_true;
	mk_lang_clobber(&binary_len);
	if(b){ err = mk_lib_fast_import_st_do_data_whole(&d, &l, &b, &binary_len); mk_lang_check_rereturn(err); mk_lang_assert(binary_len >= 0); }
	if(b){ fi->m_buf = d; fi->m_len = l; }
	if(b){ err = mk_lib_fast_import_pr_do_binary_data_2(fi, binary_len, binary_data); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_binary_suffix(&fi->m_buf, &fi->m_len, &b); mk_lang_check_rereturn(err); }
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_file_op_modify(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_file_modify_pt const file_op_modify) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(file_op_modify);

	err = mk_lib_fast_import_pr_reread(fi); mk_lang_check_rereturn(err);
	d = fi->m_buf;
	l = fi->m_len;
	b = mk_lang_true;
	file_op_modify->m_fi = fi;
	err = mk_lib_fast_import_string_rw_construct(&file_op_modify->m_path, fi->m_mallocator); mk_lang_check_rereturn(err);
	if(b){ err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_msp[0], mk_lang_countstr(mk_lib_fast_import_k_msp), &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_u32(&d, &l, &b, &file_op_modify->m_mode); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_sp[0], mk_lang_countstr(mk_lib_fast_import_k_sp), &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_colon[0], mk_lang_countstr(mk_lib_fast_import_k_colon), &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_data_ref(&d, &l, &b, &file_op_modify->m_data_ref); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string(&d, &l, &mk_lib_fast_import_k_sp[0], mk_lang_countstr(mk_lib_fast_import_k_sp), &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_string_lf(&d, &l, &b, &file_op_modify->m_path); mk_lang_check_rereturn(err); }
	if(!b)
	{
		err = mk_lib_fast_import_string_rw_destroy(&file_op_modify->m_path); mk_lang_check_rereturn(err);
	}
	if(b)
	{
		fi->m_buf = d;
		fi->m_len = l;
	}
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_file_op(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_file_op_pt const file_op) mk_lang_noexcept
{
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(file_op);

	b = mk_lang_false;
	if(!b){ err = mk_lib_fast_import_pr_do_file_op_modify(fi, &b, &file_op->m_file_modify); mk_lang_check_rereturn(err); }
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_file_ops(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_file_ops_pt const file_ops) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t b;
	mk_lib_fast_import_file_op_pt file_op;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(file_ops);

	err = mk_lib_fast_import_file_ops_rw_clear(file_ops); mk_lang_check_rereturn(err);
	b = mk_lang_true;
	while(b)
	{
		err = mk_lib_fast_import_file_ops_rw_reserve_additional(file_ops, 1); mk_lang_check_rereturn(err);
		file_op = mk_lib_fast_import_file_ops_rw_data(file_ops) + mk_lib_fast_import_file_ops_rw_size(file_ops);
		err = mk_lib_fast_import_pr_do_file_op(fi, &b, file_op); mk_lang_check_rereturn(err);
		if(b){ err = mk_lib_fast_import_file_ops_rw_resize_by(file_ops, 1); mk_lang_check_rereturn(err); }
	}
	*did = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_commit_whole(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_commit_pt const commit) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(commit);

	d = fi->m_buf;
	l = fi->m_len;
	b = mk_lang_true;
	if(b){ err = mk_lib_fast_import_st_do_commit_prefix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_ref_lf(&d, &l, &b, &commit->m_ref); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_mark_opt(&d, &l, &b, &commit->m_has_mark, &commit->m_mark); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_author(&d, &l, &b, &commit->m_author_name, &commit->m_author_email, &commit->m_author_timestamp); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_committer(&d, &l, &b, &commit->m_committer_name, &commit->m_committer_email, &commit->m_committer_timestamp); mk_lang_check_rereturn(err); }
	if(b){ fi->m_buf = d; fi->m_len = l; }
	if(b){ err = mk_lib_fast_import_pr_do_data_with_binary_data(fi, &b, &commit->m_message); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_do_file_ops(fi, &b, &commit->m_file_ops); mk_lang_check_rereturn(err); }
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_binary_data(mk_lib_fast_import_pt const fi, mk_lib_fast_import_blob_pt const blob) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_void_pt tvp;
	mk_sl_cui_uint8_pt binary_buf;
	mk_lang_types_sint_t binary_len;
	mk_lang_types_sint_t to_copy;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(blob);

	err = mk_lib_fast_import_mallocator_lokal_allocate(fi->m_mallocator, blob->m_binary_len, &tvp); mk_lang_check_rereturn(err);
	mk_lang_check_return(tvp);
	blob->m_binary_buf = ((mk_sl_cui_uint8_pt)(tvp));
	binary_buf = blob->m_binary_buf;
	binary_len = blob->m_binary_len;
	do
	{
		to_copy = mk_lang_min(binary_len, fi->m_len);
		mk_sl_cui_uint8_memcpy_fn(binary_buf, fi->m_buf, to_copy);
		fi->m_buf += to_copy;
		fi->m_len -= to_copy;
		binary_buf += to_copy;
		binary_len -= to_copy;
		err = mk_lib_fast_import_pr_reread(fi); mk_lang_check_rereturn(err);
	}while(binary_len != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_hash_anything(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_crypto_hash_stream_sha1_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_crypto_hash_stream_sha1_t hasher;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(digest);

	mk_lib_crypto_hash_stream_sha1_init(&hasher);
	mk_lib_crypto_hash_stream_sha1_append_u8s(&hasher, data_buf, data_len);
	mk_lib_crypto_hash_stream_sha1_finish(&hasher, digest);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_st_hash_blob(mk_lib_fast_import_blob_pt const blob) mk_lang_noexcept
{
	mk_sl_cui_uint8_t prefix[mk_lang_countstr(mk_lib_fast_import_k_blobsp)];
	mk_lang_bui_uint_t bui;
	mk_lang_types_sint_t len;
	mk_lang_types_pchar_t str_pc[mk_lang_bui_uint_strlen_dec_v];
	mk_sl_cui_uint8_t str_u8[mk_lang_bui_uint_strlen_dec_v];
	mk_sl_cui_uint8_t zero;
	mk_lib_crypto_hash_stream_sha1_t hasher;

	mk_lang_assert(blob);
	mk_lang_assert(blob->m_binary_buf || blob->m_binary_len == 0);
	mk_lang_assert(blob->m_binary_len >= 0);

	mk_sl_cui_uint8_from_bi_pchar_many(&prefix[0], &mk_lib_fast_import_k_blobsp[0], mk_lang_countof(prefix));
	bui = ((mk_lang_bui_uint_t)(blob->m_binary_len));
	len = mk_lang_bui_uint_to_str_dec_n(&bui, &str_pc[0], mk_lang_bui_uint_strlen_dec_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&str_u8[0], &str_pc[0], mk_lang_bui_uint_strlen_dec_v);
	mk_lib_crypto_hash_stream_sha1_init(&hasher);
	mk_lib_crypto_hash_stream_sha1_append_u8s(&hasher, &prefix[0], mk_lang_countof(prefix));
	mk_lib_crypto_hash_stream_sha1_append_u8s(&hasher, &str_u8[0], len);
	mk_lib_crypto_hash_stream_sha1_append_u8s(&hasher, blob->m_binary_buf, blob->m_binary_len);
	mk_lib_crypto_hash_stream_sha1_append_u8s(&hasher, &zero, 1);
	mk_lib_crypto_hash_stream_sha1_finish(&hasher, &blob->m_digest);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_construct(mk_lib_fast_import_tree_pt const tree, mk_lib_fast_import_pt const fi) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);
	mk_lang_assert(fi);

	tree->m_fi = fi;
	err = mk_lib_fast_import_tree_nodes_rw_construct(&tree->m_children, tree->m_fi->m_mallocator); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_construct(&tree->m_data, tree->m_fi->m_mallocator); mk_lang_check_rereturn(err);
	tree->m_digest_computed = mk_lang_false;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_destroy(mk_lib_fast_import_tree_pt const tree) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);

	err = mk_lib_fast_import_tree_nodes_rw_destroy(&tree->m_children); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_binary_data_rw_destroy(&tree->m_data); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_generic_find(mk_lang_types_pchar_pct const haystack_buf, mk_lang_types_sint_t const haystack_len, mk_lang_types_pchar_pct const needle) mk_lang_noexcept
{
	mk_lang_types_pchar_t nnn mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(haystack_buf || haystack_len == 0);
	mk_lang_assert(haystack_len >= 0);
	mk_lang_assert(needle);

	nnn = *needle;
	n = haystack_len;
	for(i = 0; i != n; ++i)
	{
		if(haystack_buf[i] == nnn)
		{
			break;
		}
	}
	return i;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_string_compare(mk_lib_fast_import_string_pct const a_str, mk_lang_types_pchar_pct const b_buf, mk_lang_types_sint_t const b_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pct a_buf;
	mk_lang_types_sint_t a_len;
	mk_lang_types_bool_t cmp;

	mk_lang_assert(a_str);
	mk_lang_assert(!mk_lib_fast_import_string_ro_is_empty(a_str));
	mk_lang_assert(b_buf);
	mk_lang_assert(b_len >= 1);

	a_buf = mk_lib_fast_import_string_ro_data(a_str); mk_lang_assert(a_buf);
	a_len = mk_lib_fast_import_string_ro_sise(a_str); mk_lang_assert(a_len >= 1);
	cmp = a_len == b_len;
	cmp = cmp && mk_lang_string_memcmp_pc_fn(a_buf, b_buf, a_len) == 0;
	return cmp;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_load_from_commit_3(mk_lib_fast_import_tree_pt const tree, mk_lib_fast_import_file_op_pct const file_op, mk_lang_types_pchar_pct const part_buf, mk_lang_types_sint_t const part_len, mk_lang_types_bool_t const is_last, mk_lib_fast_import_tree_ppt const curr) mk_lang_noexcept
{
	mk_lib_fast_import_tree_pt cr;
	mk_lang_types_sint_t count;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t tsi;
	mk_sl_cui_uint32_t tu32;
	mk_lib_fast_import_tree_node_pt child;
	mk_lang_types_sint_t err;
	mk_lang_types_void_pt mem;
	mk_lib_crypto_hash_stream_sha1_digest_pct digest;

	mk_lang_assert(tree);
	mk_lang_assert(file_op);
	mk_lang_assert(part_buf);
	mk_lang_assert(part_len >= 1);
	mk_lang_assert(is_last == mk_lang_false || is_last == mk_lang_true);
	mk_lang_assert(curr);
	mk_lang_assert(*curr);

	cr = *curr;
	count = mk_lib_fast_import_tree_nodes_rw_sise(&cr->m_children); mk_lang_assert(count >= 0);
	n = count;
	for(i = 0; i != n; ++i)
	{
		child = mk_lib_fast_import_tree_nodes_rw_at(&cr->m_children, i); mk_lang_assert(child);
		if(!is_last && child->m_type == mk_lib_fast_import_tree_node_id_e_tree)
		{
			if(mk_string_compare(&child->m_name, part_buf, part_len))
			{
				cr = child->m_val.m_data.m_tree;
				break;
			}
		}
	}
	if(cr == *curr)
	{
		err = mk_lib_fast_import_tree_nodes_rw_resize_by(&cr->m_children, 1); mk_lang_check_rereturn(err);
		if(is_last)
		{
			child = mk_lib_fast_import_tree_nodes_rw_back(&cr->m_children); mk_lang_assert(child);
			child->m_type = mk_lib_fast_import_tree_node_id_e_blob;
			err = mk_lib_fast_import_mallocator_lokal_allocate(cr->m_fi->m_mallocator, sizeof(*child->m_val.m_data.m_blob), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); child->m_val.m_data.m_blob = ((mk_lib_fast_import_blob_pt)(mem));
			err = mk_lib_fast_import_pr_file_find_digest(cr->m_fi, &file_op->m_file_modify.m_data_ref, &digest); mk_lang_check_rereturn(err); mk_lang_check_return(digest);
			child->m_val.m_data.m_blob->m_digest = *digest;
			child->m_val.m_data.m_blob->m_mode_len = mk_sl_cui_uint32_to_str_dec_n(&file_op->m_file_modify.m_mode, &child->m_val.m_data.m_blob->m_mode_buf[0], mk_lang_countof(child->m_val.m_data.m_blob->m_mode_buf));
			err = mk_lib_fast_import_string_rw_construct(&child->m_name, tree->m_fi->m_mallocator); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_string_rw_push_back_copy_many(&child->m_name, part_buf, part_len); mk_lang_check_rereturn(err);
		}
		else
		{
			child = mk_lib_fast_import_tree_nodes_rw_back(&cr->m_children); mk_lang_assert(child);
			child->m_type = mk_lib_fast_import_tree_node_id_e_tree;
			err = mk_lib_fast_import_mallocator_lokal_allocate(cr->m_fi->m_mallocator, sizeof(*child->m_val.m_data.m_tree), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); child->m_val.m_data.m_tree = ((mk_lib_fast_import_tree_pt)(mem));
			err = mk_lib_fast_import_tree_construct(child->m_val.m_data.m_tree, cr->m_fi); mk_lang_check_rereturn(err);
			tsi = 40000; mk_sl_cui_uint32_from_bi_sint(&tu32, &tsi); child->m_val.m_data.m_tree->m_mode_len = mk_sl_cui_uint32_to_str_dec_n(&tu32, &child->m_val.m_data.m_tree->m_mode_buf[0], mk_lang_countof(child->m_val.m_data.m_tree->m_mode_buf));
			err = mk_lib_fast_import_string_rw_construct(&child->m_name, tree->m_fi->m_mallocator); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_string_rw_push_back_copy_many(&child->m_name, part_buf, part_len); mk_lang_check_rereturn(err);
			cr = child->m_val.m_data.m_tree;
		}
	}
	*curr = cr;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_load_from_commit_2(mk_lib_fast_import_tree_pt const tree, mk_lib_fast_import_file_op_pct const file_op) mk_lang_noexcept
{
	mk_lang_types_pchar_t sep;
	mk_lib_fast_import_tree_pt curr;
	mk_lang_types_pchar_pct path_buf;
	mk_lang_types_sint_t path_len;
	mk_lang_types_sint_t pos;
	mk_lang_types_pchar_pct part_buf;
	mk_lang_types_sint_t part_len;
	mk_lang_types_bool_t is_last;
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);
	mk_lang_assert(file_op);

	sep = '/';
	curr = tree;
	path_buf = mk_lib_fast_import_string_ro_data(&file_op->m_file_modify.m_path);
	path_len = mk_lib_fast_import_string_ro_sise(&file_op->m_file_modify.m_path);
	for(;;)
	{
		pos = mk_generic_find(path_buf, path_len, &sep);
		part_buf = path_buf;
		part_len = pos;
		is_last = pos == path_len;
		err = mk_lib_fast_import_tree_load_from_commit_3(tree, file_op, part_buf, part_len, is_last, &curr); mk_lang_check_rereturn(err);
		if(is_last)
		{
			break;
		}
		else
		{
			path_buf += part_len + 1;
			path_len -= part_len + 1;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_tree_load_from_commit(mk_lib_fast_import_tree_pt const tree, mk_lib_fast_import_commit_pct const commit) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_fast_import_file_op_pct file_op;
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);
	mk_lang_assert(commit);

	n = mk_lib_fast_import_file_ops_ro_size(&commit->m_file_ops);
	for(i = 0; i != n; ++i)
	{
		file_op = mk_lib_fast_import_file_ops_ro_at(&commit->m_file_ops, i); mk_lang_assert(file_op);
		err = mk_lib_fast_import_tree_load_from_commit_2(tree, file_op); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_blob(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;
	mk_lib_fast_import_blob_t blob;
	mk_lib_fast_import_tree_by_mark_node_pct node;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(did);

	d = fi->m_buf;
	l = fi->m_len;
	b = mk_lang_true;
	blob.m_fi = fi;
	if(b){ err = mk_lib_fast_import_st_do_blob_whole(&d, &l, &b, &blob); mk_lang_check_rereturn(err); }
	if(b){ fi->m_buf = d; fi->m_len = l; }
	if(b){ err = mk_lib_fast_import_pr_do_binary_data(fi, &blob); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_binary_suffix(&fi->m_buf, &fi->m_len, &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_hash_blob(&blob); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_save_blob_to_database(fi, &blob); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_free_binary_data(&blob); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_tree_by_mark_rw_insert_element_move(&fi->m_marks, &blob, &node); mk_lang_check_rereturn(err); mk_lang_assert(node); }
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_extract_tree(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_commit_pct const commit, mk_lib_fast_import_tree_pt const tree) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(commit);
	mk_lang_assert(tree);
	mk_lang_assert(fi->m_mallocator);

	((mk_lang_types_void_t)(fi));
	err = mk_lib_fast_import_tree_load_from_commit(tree, commit); mk_lang_check_rereturn(err);
	*did = mk_lang_true;
	return 0;
}

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_fast_import_zlib_and_digest_s
{
	mk_lib_fast_import_pt m_fi;
	mk_lib_zlib_t m_zlib;
	mk_lib_crypto_hash_stream_sha1_t m_hasher;
	mk_lib_fast_import_binary_data_pt m_bytes;
	mk_lib_crypto_hash_stream_sha1_digest_pt m_digest;
};
typedef struct mk_lib_fast_import_zlib_and_digest_s mk_lib_fast_import_zlib_and_digest_t;
mk_lang_typedef(mk_lib_fast_import_zlib_and_digest);
#include "mk_lang_warning_msvc_pop.h"

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_zlib_and_digest_init(mk_lib_fast_import_zlib_and_digest_pt const zlib_and_digest, mk_lib_fast_import_pt const fi, mk_lib_fast_import_binary_data_pt const bytes, mk_lib_crypto_hash_stream_sha1_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(zlib_and_digest);
	mk_lang_assert(fi);
	mk_lang_assert(bytes);
	mk_lang_assert(digest);

	zlib_and_digest->m_fi = fi;
	err = mk_lib_zlib_init(&zlib_and_digest->m_zlib); mk_lang_check_rereturn(err);
	mk_lib_crypto_hash_stream_sha1_init(&zlib_and_digest->m_hasher);
	zlib_and_digest->m_bytes = bytes;
	zlib_and_digest->m_digest = digest;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_zlib_and_digest_append_u8s(mk_lib_fast_import_zlib_and_digest_pt const zlib_and_digest, mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_buf;
	mk_lang_types_sint_t in_len;
	mk_sl_cui_uint8_pt out_buf;
	mk_sl_cui_uint8_t u8s[512];
	mk_lang_types_sint_t out_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t in_c;
	mk_lang_types_sint_t out_c;

	mk_lang_assert(zlib_and_digest);
	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);

	in_buf = buf;
	in_len = len;
	out_buf = &u8s[0];
	out_len = mk_lang_countof(u8s);
	do
	{
		err = mk_lib_zlib_append(&zlib_and_digest->m_zlib, in_buf, in_len, out_buf, out_len, &in_c, &out_c); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_binary_data_rw_push_back_copy_many(zlib_and_digest->m_bytes, out_buf, out_c); mk_lang_check_rereturn(err);
		mk_lib_crypto_hash_stream_sha1_append_u8s(&zlib_and_digest->m_hasher, in_buf, in_c);
		in_buf += in_c;
		in_len -= in_c;
	}while(in_len != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_zlib_and_digest_append_pchars(mk_lib_fast_import_zlib_and_digest_pt const zlib_and_digest, mk_lang_types_pchar_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_sl_cui_uint8_t u8s[512];
	mk_lang_types_sint_t err;

	mk_lang_assert(zlib_and_digest);
	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);

	if(len > mk_lang_countof(u8s))
	{
		mk_lang_check_todo();
	}
	mk_sl_cui_uint8_from_bi_pchar_many(&u8s[0], buf, len);
	err = mk_lib_fast_import_zlib_and_digest_append_u8s(zlib_and_digest, &u8s[0], len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_zlib_and_digest_finish(mk_lib_fast_import_zlib_and_digest_pt const zlib_and_digest) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt out_buf;
	mk_sl_cui_uint8_t u8s[512];
	mk_lang_types_sint_t out_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t out_c;

	mk_lang_assert(zlib_and_digest);

	out_buf = &u8s[0];
	out_len = mk_lang_countof(u8s);
	do
	{
		err = mk_lib_zlib_finish(&zlib_and_digest->m_zlib, out_buf, out_len, &out_c); mk_lang_check_rereturn(err);
		err = mk_lib_fast_import_binary_data_rw_push_back_copy_many(zlib_and_digest->m_bytes, out_buf, out_c); mk_lang_check_rereturn(err);
	}while(out_c != 0);
	mk_lib_crypto_hash_stream_sha1_finish(&zlib_and_digest->m_hasher, zlib_and_digest->m_digest);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_zlib_append_u32_str(mk_lib_fast_import_pt const fi, mk_lib_zlib_pt const zlib, mk_lib_fast_import_binary_data_pt const bytes, mk_sl_cui_uint32_pct const u32) mk_lang_noexcept
{
	mk_lang_types_sint_t slen;
	mk_lang_types_pchar_t str[mk_sl_cui_uint32_strlen_dec_v];
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(zlib);
	mk_lang_assert(bytes);
	mk_lang_assert(u32);

	slen = mk_sl_cui_uint32_to_str_dec_n(u32, &str[0], mk_lang_countof(str)); mk_lang_assert(slen >= 1); mk_lang_assert(slen <= mk_lang_countof(str));
	err = mk_lib_fast_import_pr_tree_append_pchars(fi, zlib, bytes, &str[0], slen); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_write_to_database_2(mk_lib_fast_import_pt const fi, mk_sl_io_writer_file_pt const writer, mk_lib_fast_import_tree_pct const tree) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t w;

	mk_lang_assert(fi);
	mk_lang_assert(writer);
	mk_lang_assert(tree);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(!mk_lib_fast_import_string_ro_is_empty(&fi->m_output_dir));

	data_buf = mk_lib_fast_import_binary_data_ro_data(&tree->m_data);
	data_len = mk_lib_fast_import_binary_data_ro_sise(&tree->m_data);
	err = mk_sl_io_writer_file_write(writer, data_buf, data_len, &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == data_len);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_tree_write_to_database_1(mk_lib_fast_import_pt const fi, mk_lib_fast_import_tree_pt const tree) mk_lang_noexcept
{
	mk_lang_types_pchar_t tpc;
	mk_lang_types_pchar_t str[mk_lib_crypto_hash_block_sha1_digest_len_v * mk_sl_cui_uint8_strlen_hex_v];
	mk_lang_types_usize_t old_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;
	mk_sl_io_writer_file_t writer;
	mk_win_base_bool_t b; /* todo */
	mk_win_base_dword_t gle; /* todo */

	mk_lang_assert(fi);
	mk_lang_assert(tree);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(!mk_lib_fast_import_string_ro_is_empty(&fi->m_output_dir));

	old_len = mk_lib_fast_import_string_ro_size(&fi->m_output_dir);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &mk_lib_fast_import_k_dot_git[0], mk_lang_countstr(mk_lib_fast_import_k_dot_git)); mk_lang_check_rereturn(err);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &mk_lib_fast_import_k_objects[0], mk_lang_countstr(mk_lib_fast_import_k_objects)); mk_lang_check_rereturn(err);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	len = mk_sl_cui_uint8_to_str_hexf_n(&tree->m_digest_value.m_data.m_uint8s[0], &str[0], mk_sl_cui_uint8_strlen_hex_v); mk_lang_assert(len == mk_sl_cui_uint8_strlen_hex_v);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &str[0], mk_sl_cui_uint8_strlen_hex_v); mk_lang_check_rereturn(err);
	tpc = '\0';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	b = mk_win_dll_kernel_files_a_create_directory(mk_lib_fast_import_string_ro_data(&fi->m_output_dir), mk_win_base_null); mk_lang_check_return(b != 0 || (gle = mk_win_dll_kernel_errors_get_last()) == mk_win_dll_kernel_errors_id_e_already_exists); /* todo */
	err = mk_lib_fast_import_string_rw_pop_back_single(&fi->m_output_dir); mk_lang_check_rereturn(err);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	len = mk_sl_cui_uint8_to_str_hexf_many_n(&tree->m_digest_value.m_data.m_uint8s[1], mk_lib_crypto_hash_block_sha1_digest_len_v - 1, &str[0], mk_lang_countof(str)); mk_lang_assert(len == (mk_lib_crypto_hash_block_sha1_digest_len_v - 1) * mk_sl_cui_uint8_strlen_hex_v);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &str[0], (mk_lib_crypto_hash_block_sha1_digest_len_v - 1) * mk_sl_cui_uint8_strlen_hex_v); mk_lang_check_rereturn(err);
	tpc = '\0';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_open_n(&writer, mk_lib_fast_import_string_ro_data(&fi->m_output_dir)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_tree_write_to_database_2(fi, &writer, tree); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_resize_to(&fi->m_output_dir, old_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_depth_first(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_tree_pt const tree) mk_lang_noexcept
{
	mk_lang_types_sint_t sise;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_fast_import_tree_node_pt child;
	mk_lib_fast_import_tree_pt sub_tree;
	mk_lib_fast_import_blob_pt sub_blob;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t acc;
	mk_lang_types_pchar_t str_buf[mk_sl_cui_uint32_strlen_dec_v];
	mk_lang_types_sint_t str_len;
	mk_sl_cui_uint32_t u32;
	mk_lang_types_pchar_t nul;
	mk_lang_types_pchar_t sp;
	mk_lib_fast_import_zlib_and_digest_t zlib_and_digest;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(tree);

	acc = 0;
	sise = mk_lib_fast_import_tree_nodes_rw_sise(&tree->m_children);
	n = sise;
	for(i = 0; i != n; ++i)
	{
		child = mk_lib_fast_import_tree_nodes_rw_at(&tree->m_children, i); mk_lang_assert(child);
		if(child->m_type == mk_lib_fast_import_tree_node_id_e_tree)
		{
			sub_tree = child->m_val.m_data.m_tree; mk_lang_assert(sub_tree);
			err = mk_lib_fast_import_pr_depth_first(fi, did, sub_tree); mk_lang_check_rereturn(err);
		}
		if(child->m_type == mk_lib_fast_import_tree_node_id_e_tree)
		{
			sub_tree = child->m_val.m_data.m_tree;
			acc += sub_tree->m_mode_len;
			acc += 1; /* sp */
			acc += mk_lib_fast_import_string_ro_sise(&child->m_name);
			acc += 1; /* nul */
			acc += mk_lib_crypto_hash_stream_sha1_digest_len_v;
		}
		else if(child->m_type == mk_lib_fast_import_tree_node_id_e_blob)
		{
			sub_blob = child->m_val.m_data.m_blob;
			acc += sub_blob->m_mode_len;
			acc += 1; /* sp */
			acc += mk_lib_fast_import_string_ro_sise(&child->m_name);
			acc += 1; /* nul */
			acc += mk_lib_crypto_hash_stream_sha1_digest_len_v;
		}
		else
		{
			mk_lang_assert(mk_lang_runtime_bool_fn_false);
		}
	}
	mk_sl_cui_uint32_from_bi_sint(&u32, &acc);
	str_len = mk_sl_cui_uint32_to_str_dec_n(&u32, &str_buf[0], mk_lang_countof(str_buf));
	nul = '\0';
	sp = ' ';
	err = mk_lib_fast_import_zlib_and_digest_init(&zlib_and_digest, fi, &tree->m_data, &tree->m_digest_value); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &mk_lib_fast_import_k_treesp[0], mk_lang_countstr(mk_lib_fast_import_k_treesp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &str_buf[0], str_len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &nul, 1); mk_lang_check_rereturn(err);
	for(i = 0; i != n; ++i)
	{
		child = mk_lib_fast_import_tree_nodes_rw_at(&tree->m_children, i); mk_lang_assert(child);
		if(child->m_type == mk_lib_fast_import_tree_node_id_e_tree)
		{
			sub_tree = child->m_val.m_data.m_tree;
			err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &sub_tree->m_mode_buf[0], sub_tree->m_mode_len); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &sp, 1); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, mk_lib_fast_import_string_ro_data(&child->m_name), mk_lib_fast_import_string_ro_sise(&child->m_name)); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &nul, 1); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_zlib_and_digest_append_u8s(&zlib_and_digest, &sub_tree->m_digest_value.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha1_digest_len_v); mk_lang_check_rereturn(err);
		}
		else if(child->m_type == mk_lib_fast_import_tree_node_id_e_blob)
		{
			sub_blob = child->m_val.m_data.m_blob;
			err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &sub_blob->m_mode_buf[0], sub_blob->m_mode_len); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &sp, 1); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, mk_lib_fast_import_string_ro_data(&child->m_name), mk_lib_fast_import_string_ro_sise(&child->m_name)); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &nul, 1); mk_lang_check_rereturn(err);
			err = mk_lib_fast_import_zlib_and_digest_append_u8s(&zlib_and_digest, &sub_blob->m_digest.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha1_digest_len_v); mk_lang_check_rereturn(err);
		}
		else
		{
			mk_lang_assert(mk_lang_runtime_bool_fn_false);
		}
	}
	err = mk_lib_fast_import_zlib_and_digest_finish(&zlib_and_digest); mk_lang_check_rereturn(err);
	tree->m_digest_computed = mk_lang_true;
	err = mk_lib_fast_import_pr_tree_write_to_database_1(fi, tree); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_hash_tree(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_tree_pt const tree) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(tree);

	err = mk_lib_fast_import_pr_depth_first(fi, did, tree); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_commit_compute_len(mk_lib_fast_import_pt const fi, mk_lib_fast_import_commit_pct const commit, mk_lib_fast_import_tree_pct const tree, mk_lang_types_sint_pt const len) mk_lang_noexcept
{
	mk_lang_types_sint_t acc;

	mk_lang_assert(fi);
	mk_lang_assert(commit);
	mk_lang_assert(tree);
	mk_lang_assert(len);

	acc = 0;
	acc += mk_lang_countstr(mk_lib_fast_import_k_treesp);
	acc += mk_lib_crypto_hash_stream_sha1_digest_len_v * mk_sl_cui_uint8_strlen_hex_v;
	acc += 1; /* lf */
	acc += mk_lang_countstr(mk_lib_fast_import_k_authorsp);
	acc += mk_lib_fast_import_string_ro_sise(&commit->m_author_name);
	acc += mk_lang_countstr(mk_lib_fast_import_k_splt);
	acc += mk_lib_fast_import_string_ro_sise(&commit->m_author_email);
	acc += mk_lang_countstr(mk_lib_fast_import_k_gtsp);
	acc += mk_lib_fast_import_string_ro_sise(&commit->m_author_timestamp);
	acc += 1; /* lf */
	acc += mk_lang_countstr(mk_lib_fast_import_k_committersp);
	acc += mk_lib_fast_import_string_ro_sise(&commit->m_committer_name);
	acc += mk_lang_countstr(mk_lib_fast_import_k_splt);
	acc += mk_lib_fast_import_string_ro_sise(&commit->m_committer_email);
	acc += mk_lang_countstr(mk_lib_fast_import_k_gtsp);
	acc += mk_lib_fast_import_string_ro_sise(&commit->m_committer_timestamp);
	acc += 1; /* lf */
	acc += 1; /* lf */
	acc += mk_lib_fast_import_binary_data_ro_sise(&commit->m_message);
	*len = acc;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_write_object_to_database_2(mk_lib_fast_import_pt const fi, mk_sl_io_writer_file_pt const writer, mk_lib_fast_import_binary_data_pct const data) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct data_buf;
	mk_lang_types_sint_t data_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t w;

	mk_lang_assert(fi);
	mk_lang_assert(writer);
	mk_lang_assert(data);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(!mk_lib_fast_import_string_ro_is_empty(&fi->m_output_dir));

	data_buf = mk_lib_fast_import_binary_data_ro_data(data);
	data_len = mk_lib_fast_import_binary_data_ro_sise(data);
	err = mk_sl_io_writer_file_write(writer, data_buf, data_len, &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == data_len);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_write_object_to_database(mk_lib_fast_import_pt const fi, mk_lib_crypto_hash_stream_sha1_digest_pct const digest, mk_lib_fast_import_binary_data_pct const data) mk_lang_noexcept
{
	mk_lang_types_pchar_t tpc;
	mk_lang_types_pchar_t str[mk_lib_crypto_hash_block_sha1_digest_len_v * mk_sl_cui_uint8_strlen_hex_v];
	mk_lang_types_usize_t old_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;
	mk_sl_io_writer_file_t writer;
	mk_win_base_bool_t b; /* todo */
	mk_win_base_dword_t gle; /* todo */

	mk_lang_assert(fi);
	mk_lang_assert(digest);
	mk_lang_assert(data);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(!mk_lib_fast_import_string_ro_is_empty(&fi->m_output_dir));

	old_len = mk_lib_fast_import_string_ro_size(&fi->m_output_dir);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &mk_lib_fast_import_k_dot_git[0], mk_lang_countstr(mk_lib_fast_import_k_dot_git)); mk_lang_check_rereturn(err);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &mk_lib_fast_import_k_objects[0], mk_lang_countstr(mk_lib_fast_import_k_objects)); mk_lang_check_rereturn(err);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	len = mk_sl_cui_uint8_to_str_hexf_n(&digest->m_data.m_uint8s[0], &str[0], mk_sl_cui_uint8_strlen_hex_v); mk_lang_assert(len == mk_sl_cui_uint8_strlen_hex_v);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &str[0], mk_sl_cui_uint8_strlen_hex_v); mk_lang_check_rereturn(err);
	tpc = '\0';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	b = mk_win_dll_kernel_files_a_create_directory(mk_lib_fast_import_string_ro_data(&fi->m_output_dir), mk_win_base_null); mk_lang_check_return(b != 0 || (gle = mk_win_dll_kernel_errors_get_last()) == mk_win_dll_kernel_errors_id_e_already_exists); /* todo */
	err = mk_lib_fast_import_string_rw_pop_back_single(&fi->m_output_dir); mk_lang_check_rereturn(err);
	tpc = '\\';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	len = mk_sl_cui_uint8_to_str_hexf_many_n(&digest->m_data.m_uint8s[1], mk_lib_crypto_hash_block_sha1_digest_len_v - 1, &str[0], mk_lang_countof(str)); mk_lang_assert(len == (mk_lib_crypto_hash_block_sha1_digest_len_v - 1) * mk_sl_cui_uint8_strlen_hex_v);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &str[0], (mk_lib_crypto_hash_block_sha1_digest_len_v - 1) * mk_sl_cui_uint8_strlen_hex_v); mk_lang_check_rereturn(err);
	tpc = '\0';
	err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_open_n(&writer, mk_lib_fast_import_string_ro_data(&fi->m_output_dir)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_write_object_to_database_2(fi, &writer, data); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_resize_to(&fi->m_output_dir, old_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_commit_compute_data(mk_lib_fast_import_pt const fi, mk_lib_fast_import_commit_pt const commit, mk_lib_fast_import_tree_pct const tree, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint32_t tu32;
	mk_lang_types_pchar_t str_buf[mk_sl_cui_uint32_strlen_dec_v];
	mk_lang_types_sint_t str_len;
	mk_lang_types_pchar_t nul;
	mk_lang_types_pchar_t lf;
	mk_lib_fast_import_zlib_and_digest_t zlib_and_digest;
	mk_lang_types_pchar_t digest_str_buf[mk_lib_crypto_hash_stream_sha1_digest_len_v * mk_sl_cui_uint8_strlen_hex_v];
	mk_lang_types_sint_t digest_str_len;

	mk_lang_assert(fi);
	mk_lang_assert(commit);
	mk_lang_assert(tree);
	mk_lang_assert(len >= 1);

	mk_sl_cui_uint32_from_bi_sint(&tu32, &len);
	str_len = mk_sl_cui_uint32_to_str_dec_n(&tu32, &str_buf[0], mk_lang_countof(str_buf));
	nul = '\0';
	lf = '\x0a';
	digest_str_len = mk_sl_cui_uint8_to_str_hexf_many_n(&tree->m_digest_value.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha1_digest_len_v, &digest_str_buf[0], mk_lang_countof(digest_str_buf));
	err = mk_lib_fast_import_zlib_and_digest_init(&zlib_and_digest, fi, &commit->m_data, &commit->m_digest); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &mk_lib_fast_import_k_commitsp[0], mk_lang_countstr(mk_lib_fast_import_k_commitsp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &str_buf[0], str_len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &nul, 1); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &mk_lib_fast_import_k_treesp[0], mk_lang_countstr(mk_lib_fast_import_k_treesp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &digest_str_buf[0], digest_str_len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &lf, 1); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &mk_lib_fast_import_k_authorsp[0], mk_lang_countstr(mk_lib_fast_import_k_authorsp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, mk_lib_fast_import_string_ro_data(&commit->m_author_name), mk_lib_fast_import_string_ro_sise(&commit->m_author_name)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &mk_lib_fast_import_k_splt[0], mk_lang_countstr(mk_lib_fast_import_k_splt)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, mk_lib_fast_import_string_ro_data(&commit->m_author_email), mk_lib_fast_import_string_ro_sise(&commit->m_author_email)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &mk_lib_fast_import_k_gtsp[0], mk_lang_countstr(mk_lib_fast_import_k_gtsp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, mk_lib_fast_import_string_ro_data(&commit->m_author_timestamp), mk_lib_fast_import_string_ro_sise(&commit->m_author_timestamp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &lf, 1); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &mk_lib_fast_import_k_committersp[0], mk_lang_countstr(mk_lib_fast_import_k_committersp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, mk_lib_fast_import_string_ro_data(&commit->m_committer_name), mk_lib_fast_import_string_ro_sise(&commit->m_committer_name)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &mk_lib_fast_import_k_splt[0], mk_lang_countstr(mk_lib_fast_import_k_splt)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, mk_lib_fast_import_string_ro_data(&commit->m_committer_email), mk_lib_fast_import_string_ro_sise(&commit->m_committer_email)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &mk_lib_fast_import_k_gtsp[0], mk_lang_countstr(mk_lib_fast_import_k_gtsp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, mk_lib_fast_import_string_ro_data(&commit->m_committer_timestamp), mk_lib_fast_import_string_ro_sise(&commit->m_committer_timestamp)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &lf, 1); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_pchars(&zlib_and_digest, &lf, 1); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_append_u8s(&zlib_and_digest, mk_lib_fast_import_binary_data_ro_data(&commit->m_message), mk_lib_fast_import_binary_data_ro_sise(&commit->m_message)); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_zlib_and_digest_finish(&zlib_and_digest); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_commit_write_to_database_1(mk_lib_fast_import_pt const fi, mk_lib_fast_import_commit_pt const commit, mk_lib_fast_import_tree_pct const tree) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;

	mk_lang_assert(fi);
	mk_lang_assert(commit);
	mk_lang_assert(tree);

	err = mk_lib_fast_import_pr_commit_compute_len(fi, commit, tree, &len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_commit_compute_data(fi, commit, tree, len); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_pr_write_object_to_database(fi, &commit->m_digest, &commit->m_data); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_string_starts_with(mk_lib_fast_import_string_pct const a_str, mk_lang_types_pchar_pct const b_buf, mk_lang_types_sint_t const b_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pct a_buf;
	mk_lang_types_sint_t a_len;
	mk_lang_types_bool_t cmp;

	mk_lang_assert(a_str);
	mk_lang_assert(!mk_lib_fast_import_string_ro_is_empty(a_str));
	mk_lang_assert(b_buf);
	mk_lang_assert(b_len >= 1);

	a_buf = mk_lib_fast_import_string_ro_data(a_str); mk_lang_assert(a_buf);
	a_len = mk_lib_fast_import_string_ro_sise(a_str); mk_lang_assert(a_len >= 1);
	cmp = a_len >= b_len;
	cmp = cmp && mk_lang_string_memcmp_pc_fn(a_buf, b_buf, b_len) == 0;
	return cmp;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_update_branch(mk_lib_fast_import_pt const fi, mk_lib_fast_import_commit_pct const commit) mk_lang_noexcept
{
	mk_lang_types_pchar_t str_buf[mk_lib_crypto_hash_stream_sha1_digest_len_v * mk_sl_cui_uint8_strlen_hex_v];
	mk_sl_cui_uint8_t data_buf[mk_lib_crypto_hash_stream_sha1_digest_len_v * mk_sl_cui_uint8_strlen_hex_v];
	mk_lang_types_pchar_t tpc;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t str_len;
	mk_lang_types_usize_t old_len;
	mk_lang_types_sint_t w;
	mk_sl_io_writer_file_t writer;

	mk_lang_assert(fi);
	mk_lang_assert(commit);

	mk_lang_check_return(mk_string_starts_with(&commit->m_ref, &mk_lib_fast_import_k_heads[0], mk_lang_countstr(mk_lib_fast_import_k_heads)));

	old_len = mk_lib_fast_import_string_ro_size(&fi->m_output_dir);
	tpc = '\\'; err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, &mk_lib_fast_import_k_dot_git[0], mk_lang_countstr(mk_lib_fast_import_k_dot_git)); mk_lang_check_rereturn(err);
	tpc = '\\'; err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_push_back_copy_many(&fi->m_output_dir, mk_lib_fast_import_string_ro_data(&commit->m_ref), mk_lib_fast_import_string_ro_sise(&commit->m_ref)); mk_lang_check_rereturn(err);
	tpc = '\0'; err = mk_lib_fast_import_string_rw_push_back_copy_single(&fi->m_output_dir, &tpc); mk_lang_check_rereturn(err);

	err = mk_sl_io_writer_file_open_n(&writer, mk_lib_fast_import_string_ro_data(&fi->m_output_dir)); mk_lang_check_rereturn(err);

	str_len = mk_sl_cui_uint8_to_str_hexf_many_n(&commit->m_digest.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha1_digest_len_v, &str_buf[0], mk_lang_countof(str_buf));
	mk_sl_cui_uint8_from_bi_pchar_many(&data_buf[0], &str_buf[0], str_len);
	err = mk_sl_io_writer_file_write(&writer, data_buf, str_len, &w); mk_lang_check_rereturn(err); mk_lang_check_return(w == str_len);

	err = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_string_rw_resize_to(&fi->m_output_dir, old_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_commit(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;
	mk_lib_fast_import_commit_t commit;
	mk_lib_fast_import_tree_t tree;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(did);

	b = mk_lang_true;
	err = mk_lib_fast_import_commit_rw_construct(&commit, fi); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_tree_construct(&tree, fi); mk_lang_check_rereturn(err);
	if(b){ err = mk_lib_fast_import_pr_do_commit_whole(fi, &b, &commit); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_extract_tree(fi, &b, &commit, &tree); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_hash_tree(fi, &b, &tree); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_commit_write_to_database_1(fi, &commit, &tree); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_pr_update_branch(fi, &commit); mk_lang_check_rereturn(err); }
	err = mk_lib_fast_import_tree_destroy(&tree); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_commit_rw_destroy(&commit); mk_lang_check_rereturn(err);
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_reset_whole(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did, mk_lib_fast_import_reset_pt const reset) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt d;
	mk_lang_types_sint_t l;
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(did);
	mk_lang_assert(reset);

	d = fi->m_buf;
	l = fi->m_len;
	b = mk_lang_true;
	if(b){ err = mk_lib_fast_import_st_do_reset_prefix(&d, &l, &b); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_ref_lf(&d, &l, &b, &reset->m_ref); mk_lang_check_rereturn(err); }
	if(b){ err = mk_lib_fast_import_st_do_from_mark(&d, &l, &b, &reset->m_from); mk_lang_check_rereturn(err); }
	if(b){ fi->m_buf = d; fi->m_len = l; }
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_reset(mk_lib_fast_import_pt const fi, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;
	mk_lib_fast_import_reset_t reset;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);
	mk_lang_assert(did);

	b = mk_lang_true;
	err = mk_lib_fast_import_reset_rw_construct(&reset, fi); mk_lang_check_rereturn(err);
	if(b){ err = mk_lib_fast_import_pr_do_reset_whole(fi, &b, &reset); mk_lang_check_rereturn(err); }
	err = mk_lib_fast_import_reset_rw_destroy(&reset); mk_lang_check_rereturn(err);
	*did = b;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fast_import_pr_do_step(mk_lib_fast_import_pt const fi) mk_lang_noexcept
{
	mk_lang_types_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);

	b = mk_lang_false;
	if(!b){ err = mk_lib_fast_import_pr_do_blob(fi, &b); mk_lang_check_rereturn(err); }
	if(!b){ err = mk_lib_fast_import_pr_do_commit(fi, &b); mk_lang_check_rereturn(err); }
	if(!b){ err = mk_lib_fast_import_pr_do_reset(fi, &b); mk_lang_check_rereturn(err); }
	if(!b){ mk_lang_check_todo(); }
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_fast_import_pr_is_done(mk_lib_fast_import_pt const fi) mk_lang_noexcept
{
	mk_lang_types_bool_t b;

	mk_lang_assert(fi);
	mk_lang_assert(fi->m_mallocator);

	b = mk_lang_false;
	return b;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fast_import_run(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_fast_import_mallocator_lokal_t mallocator_lokal;
	mk_lib_fast_import_t fi;

	err = mk_lib_fast_import_mallocator_lokal_init(&mallocator_lokal); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_fi_pr_construct(&fi); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_fi_pr_set_mallocator(&fi, &mallocator_lokal); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_fi_pr_set_input_file(&fi, "c:\\dev\\mnt\\mkdisk\\dev\\repos\\da\\galaxy.fe"); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_fi_pr_set_output_dir(&fi, "c:\\dev\\mnt\\mkdisk\\dev\\repos\\da\\galaxy"); mk_lang_check_rereturn(err);
	do
	{
		err = mk_lib_fast_import_pr_do_step(&fi); mk_lang_check_rereturn(err);
	}while(!mk_lib_fast_import_pr_is_done(&fi));
	err = mk_lib_fast_import_fi_pr_destroy(&fi); mk_lang_check_rereturn(err);
	err = mk_lib_fast_import_mallocator_lokal_deinit(&mallocator_lokal); mk_lang_check_rereturn(err);
	return 0;
}


#endif
