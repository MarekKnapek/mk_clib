#ifndef mk_include_guard_mk_lib_compress_zlib_c
#define mk_include_guard_mk_lib_compress_zlib_c
#include "mk_lib_compress_zlib.h"

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
#include "mk_lib_compress_deflate.h"
#include "mk_lib_hash_adler32.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_compress_zlib_pr_copy_header_if_possible(mk_lib_compress_zlib_pt const zlib, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt out_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t out_len mk_lang_constexpr_init;
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;
	mk_lang_types_sint_t avail mk_lang_constexpr_init;
	mk_lang_types_sint_t to_copy mk_lang_constexpr_init;

	mk_lang_assert(zlib);
	mk_lang_assert(data_in_buf || data_in_len == 0);
	mk_lang_assert(data_in_len >= 0);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_in_consumed);
	mk_lang_assert(data_out_consumed);
	mk_lang_assert(zlib->m_stream_header_beg >= 0);
	mk_lang_assert(zlib->m_stream_header_beg <= mk_lang_countof(zlib->m_stream_header_buf));
	mk_lang_assert(zlib->m_stream_footer_beg >= 0);
	mk_lang_assert(zlib->m_stream_footer_beg <= mk_lang_countof(zlib->m_stream_footer_buf));
	mk_lang_assert(!(!zlib->m_finish_requested && zlib->m_finished));

	out_buf = data_out_buf;
	out_len = data_out_len;
	in_c = 0;
	out_c = 0;
	if((zlib->m_stream_header_beg != mk_lang_countof(zlib->m_stream_header_buf)))
	{
		avail = mk_lang_countof(zlib->m_stream_header_buf) - zlib->m_stream_header_beg;
		to_copy = mk_lang_min(avail, out_len);
		mk_sl_cui_uint8_memcpy_fn(out_buf, &zlib->m_stream_header_buf[zlib->m_stream_header_beg], to_copy);
		zlib->m_stream_header_beg += to_copy;
		out_c += to_copy;
	}
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_compress_zlib_pr_copy_from_input_buffer_if_possible(mk_lib_compress_zlib_pt const zlib, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t in_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out_buf mk_lang_constexpr_init;
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
	mk_lang_assert(zlib->m_stream_header_beg >= 0);
	mk_lang_assert(zlib->m_stream_header_beg <= mk_lang_countof(zlib->m_stream_header_buf));
	mk_lang_assert(zlib->m_stream_footer_beg >= 0);
	mk_lang_assert(zlib->m_stream_footer_beg <= mk_lang_countof(zlib->m_stream_footer_buf));
	mk_lang_assert(!(!zlib->m_finish_requested && zlib->m_finished));

	in_buf = data_in_buf;
	in_len = data_in_len;
	out_buf = data_out_buf;
	out_len = data_out_len;
	in_c = 0;
	out_c = 0;
	if(zlib->m_stream_header_beg == mk_lang_countof(zlib->m_stream_header_buf))
	{
		mk_lib_compress_deflate_append(&zlib->m_deflate, in_buf, in_len, out_buf, out_len, &in_c, &out_c);
		mk_lib_hash_adler32_append(&zlib->m_adler32, in_buf, in_c);
	}
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_compress_zlib_pr_finish_if_possible(mk_lib_compress_zlib_pt const zlib, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt out_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t out_len mk_lang_constexpr_init;
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;
	mk_sl_cui_uint32_t adler32 mk_lang_constexpr_init;

	mk_lang_assert(zlib);
	mk_lang_assert(data_in_buf || data_in_len == 0);
	mk_lang_assert(data_in_len >= 0);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_in_consumed);
	mk_lang_assert(data_out_consumed);
	mk_lang_assert(zlib->m_stream_header_beg >= 0);
	mk_lang_assert(zlib->m_stream_header_beg <= mk_lang_countof(zlib->m_stream_header_buf));
	mk_lang_assert(zlib->m_stream_footer_beg >= 0);
	mk_lang_assert(zlib->m_stream_footer_beg <= mk_lang_countof(zlib->m_stream_footer_buf));
	mk_lang_assert(!(!zlib->m_finish_requested && zlib->m_finished));

	out_buf = data_out_buf;
	out_len = data_out_len;
	in_c = 0;
	out_c = 0;
	if
	(
		(zlib->m_stream_header_beg == mk_lang_countof(zlib->m_stream_header_buf)) &&
		(zlib->m_finish_requested) &&
		(!zlib->m_finished)
	)
	{
		mk_lib_compress_deflate_finish(&zlib->m_deflate, out_buf, out_len, &out_c);
		if(out_len != 0 && out_c == 0)
		{
			mk_lib_hash_adler32_finish(&zlib->m_adler32, &adler32);
			mk_sl_uint_convert_32_8_be_to_sml(&adler32, &zlib->m_stream_footer_buf[0]);
			zlib->m_finished = mk_lang_true;
		}
	}
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_compress_zlib_pr_footer_if_possible(mk_lib_compress_zlib_pt const zlib, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt out_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t out_len mk_lang_constexpr_init;
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;
	mk_lang_types_sint_t out_c mk_lang_constexpr_init;
	mk_lang_types_sint_t avail mk_lang_constexpr_init;
	mk_lang_types_sint_t to_copy mk_lang_constexpr_init;

	mk_lang_assert(zlib);
	mk_lang_assert(data_in_buf || data_in_len == 0);
	mk_lang_assert(data_in_len >= 0);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_in_consumed);
	mk_lang_assert(data_out_consumed);
	mk_lang_assert(zlib->m_stream_header_beg >= 0);
	mk_lang_assert(zlib->m_stream_header_beg <= mk_lang_countof(zlib->m_stream_header_buf));
	mk_lang_assert(zlib->m_stream_footer_beg >= 0);
	mk_lang_assert(zlib->m_stream_footer_beg <= mk_lang_countof(zlib->m_stream_footer_buf));
	mk_lang_assert(!(!zlib->m_finish_requested && zlib->m_finished));

	out_buf = data_out_buf;
	out_len = data_out_len;
	in_c = 0;
	out_c = 0;
	if
	(
		(zlib->m_stream_header_beg == mk_lang_countof(zlib->m_stream_header_buf)) &&
		(zlib->m_finish_requested) &&
		(zlib->m_finished) &&
		(zlib->m_stream_footer_beg != mk_lang_countof(zlib->m_stream_footer_buf))
	)
	{
		avail = mk_lang_countof(zlib->m_stream_footer_buf) - zlib->m_stream_footer_beg;
		to_copy = mk_lang_min(avail, out_len);
		mk_sl_cui_uint8_memcpy_fn(out_buf, &zlib->m_stream_footer_buf[zlib->m_stream_footer_beg], to_copy);
		zlib->m_stream_footer_beg += to_copy;
		out_c += to_copy;
	}
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_compress_zlib_init(mk_lib_compress_zlib_pt const zlib) mk_lang_noexcept
{
	mk_lang_types_uchar_t cmf mk_lang_constexpr_init;
	mk_lang_types_uchar_t flg mk_lang_constexpr_init;
	mk_lang_types_uchar_t fcheck mk_lang_constexpr_init;
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;

	mk_lang_assert(zlib);

	mk_lib_compress_deflate_init(&zlib->m_deflate);
	mk_lib_hash_adler32_init(&zlib->m_adler32);
	zlib->m_stream_header_beg = 0;
	zlib->m_stream_footer_beg = 0;
	zlib->m_finish_requested = mk_lang_false;
	zlib->m_finished = mk_lang_false;

	cmf = 0x78; /* 0x08 == compression method, deflate */ /* 0x70 == compression info, 32 kB */
	flg = 0x00; /* no dictionary, no compression */
	fcheck = ((mk_lang_types_uchar_t)(((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(31)) - ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)((((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(cmf)) << 8)) + ((mk_lang_types_ushort_t)(flg))))) % ((mk_lang_types_ushort_t)(31))))))));
	flg = flg | fcheck;
	ptr = 0;
	mk_sl_cui_uint8_from_bi_uchar(&zlib->m_stream_header_buf[ptr], &cmf); ptr += mk_sl_cui_uint8_size_bytes_v;
	mk_sl_cui_uint8_from_bi_uchar(&zlib->m_stream_header_buf[ptr], &flg); ptr += mk_sl_cui_uint8_size_bytes_v;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_compress_zlib_append(mk_lib_compress_zlib_pt const zlib, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t in_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out_buf mk_lang_constexpr_init;
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
	mk_lib_compress_zlib_pr_copy_header_if_possible           (zlib, in_buf, in_len, out_buf, out_len, &in_c, &out_c); in_buf += in_c; in_len -= in_c; out_buf += out_c; out_len -= out_c;
	mk_lib_compress_zlib_pr_copy_from_input_buffer_if_possible(zlib, in_buf, in_len, out_buf, out_len, &in_c, &out_c); in_buf += in_c; in_len -= in_c; out_buf += out_c; out_len -= out_c;
	mk_lib_compress_zlib_pr_finish_if_possible                (zlib, in_buf, in_len, out_buf, out_len, &in_c, &out_c); in_buf += in_c; in_len -= in_c; out_buf += out_c; out_len -= out_c;
	mk_lib_compress_zlib_pr_footer_if_possible                (zlib, in_buf, in_len, out_buf, out_len, &in_c, &out_c); in_buf += in_c; in_len -= in_c; out_buf += out_c; out_len -= out_c;
	in_c = data_in_len - in_len;
	out_c = data_out_len - out_len;
	*data_in_consumed = in_c;
	*data_out_consumed = out_c;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_compress_zlib_finish(mk_lib_compress_zlib_pt const zlib, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t in_c mk_lang_constexpr_init;

	mk_lang_assert(zlib);
	mk_lang_assert(data_out_buf || data_out_len == 0);
	mk_lang_assert(data_out_len >= 0);
	mk_lang_assert(data_out_consumed);

	zlib->m_finish_requested = mk_lang_true;
	mk_lib_compress_zlib_append(zlib, mk_lang_null, 0, data_out_buf, data_out_len, &in_c, data_out_consumed);
}


#endif
