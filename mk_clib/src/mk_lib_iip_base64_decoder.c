#ifndef mk_include_guard_mk_lib_iip_base64_decoder_c
#define mk_include_guard_mk_lib_iip_base64_decoder_c
#include "mk_lib_iip_base64_decoder.h"

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


union mk_lib_iip_base64_decoder_alphabet_data_u
{
	mk_lang_types_uchar_t m_uchars[0xff + 1];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_iip_base64_decoder_alphabet_data_u mk_lib_iip_base64_decoder_alphabet_data_t;
struct mk_lib_iip_base64_decoder_alphabet_s
{
	mk_lang_alignas(64) mk_lib_iip_base64_decoder_alphabet_data_t m_data;
};
typedef struct mk_lib_iip_base64_decoder_alphabet_s mk_lib_iip_base64_decoder_alphabet_t;


#define ____ 0xff
mk_lang_constexpr_static_inline mk_lib_iip_base64_decoder_alphabet_t const mk_lib_iip_base64_decoder_k_alphabet =
{{{
	____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
	____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
	____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 0x3e, ____, ____,
	0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, ____, ____, ____, ____, ____, ____,
	____, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e,
	0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, ____, ____, ____, ____, ____,
	____, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
	0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, ____, ____, ____, 0x3f, ____,
	____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
	____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
	____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
	____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
	____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
	____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
	____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
	____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
}}};
#undef ____


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_base64_decoder_pr_no_check_block_24bits_middle(mk_lang_types_pchar_pct const str_buf, mk_sl_cui_uint8_pt const data_buf) mk_lang_noexcept
{
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;

	mk_lang_assert(str_buf);
	mk_lang_assert(data_buf);

	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[0]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[1]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[2]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[3]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[0]))] >= 0);
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[1]))] >= 0);
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[2]))] >= 0);
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[3]))] >= 0);
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[0]))] < 64);
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[1]))] < 64);
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[2]))] < 64);
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[3]))] < 64);
	tul = 0;
	tul |= ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[0]))])) << (3 * 6)));
	tul |= ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[1]))])) << (2 * 6)));
	tul |= ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[2]))])) << (1 * 6)));
	tul |= ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[3]))])) << (0 * 6)));
	tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tul >> (2 * 8))) & ((mk_lang_types_ulong_t)(0xff)))))); mk_sl_cui_uint8_from_bi_uchar(&data_buf[0], &tuc);
	tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tul >> (1 * 8))) & ((mk_lang_types_ulong_t)(0xff)))))); mk_sl_cui_uint8_from_bi_uchar(&data_buf[1], &tuc);
	tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tul >> (0 * 8))) & ((mk_lang_types_ulong_t)(0xff)))))); mk_sl_cui_uint8_from_bi_uchar(&data_buf[2], &tuc);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_base64_decoder_pr_no_check_block_24bits_final(mk_lang_types_pchar_pct const str_buf, mk_sl_cui_uint8_pt const data_buf) mk_lang_noexcept
{
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;

	mk_lang_assert(str_buf);
	mk_lang_assert(data_buf);

	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[0]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[1]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[2]))] != 0xff || str_buf[2] == '=');
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[3]))] != 0xff || str_buf[3] == '=');
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[0]))] >= 0);
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[1]))] >= 0);
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[2]))] >= 0 || str_buf[2] == '=');
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[3]))] >= 0 || str_buf[3] == '=');
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[0]))] < 64);
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[1]))] < 64);
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[2]))] < 64 || str_buf[2] == '=');
	mk_lang_assert(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[3]))] < 64 || str_buf[3] == '=');
	mk_lang_assert(str_buf[2] != '=' || str_buf[3] == '=');
	tul = 0;
	tul |= ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[0]))])) << (3 * 6)));
	tul |= ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[1]))])) << (2 * 6)));
	if(str_buf[2] != '='){ tul |= ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[2]))])) << (1 * 6))); }
	if(str_buf[3] != '='){ tul |= ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[3]))])) << (0 * 6))); }
	tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tul >> (2 * 8))) & ((mk_lang_types_ulong_t)(0xff)))))); mk_sl_cui_uint8_from_bi_uchar(&data_buf[0], &tuc);
	if(str_buf[2] != '='){ tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tul >> (1 * 8))) & ((mk_lang_types_ulong_t)(0xff)))))); mk_sl_cui_uint8_from_bi_uchar(&data_buf[1], &tuc); }
	if(str_buf[3] != '='){ tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tul >> (0 * 8))) & ((mk_lang_types_ulong_t)(0xff)))))); mk_sl_cui_uint8_from_bi_uchar(&data_buf[2], &tuc); }
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_base64_decoder_pr_do_check_block_24bits_middle(mk_lang_types_pchar_pct const str_buf, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_bool_pt const success) mk_lang_noexcept
{
	mk_lang_types_bool_t gud mk_lang_constexpr_init;

	mk_lang_assert(str_buf);
	mk_lang_assert(data_buf);
	mk_lang_assert(success);

	gud = *success;
	if(gud)
	{
		gud = gud & (mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[0]))] != 0xff);
		gud = gud & (mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[1]))] != 0xff);
		gud = gud & (mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[2]))] != 0xff);
		gud = gud & (mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[3]))] != 0xff);
	}
	if(gud)
	{
		mk_lib_iip_base64_decoder_pr_no_check_block_24bits_middle(str_buf, data_buf);
	}
	*success = gud;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_base64_decoder_pr_do_check_block_24bits_final(mk_lang_types_pchar_pct const str_buf, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_bool_pt const success) mk_lang_noexcept
{
	mk_lang_types_bool_t gud mk_lang_constexpr_init;

	mk_lang_assert(str_buf);
	mk_lang_assert(data_buf);
	mk_lang_assert(success);

	gud = *success;
	if(gud)
	{
		gud = gud & (mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[0]))] != 0xff);
		gud = gud & (mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[1]))] != 0xff);
		gud = gud & (mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[2]))] != 0xff || str_buf[2] == '=');
		gud = gud & (mk_lib_iip_base64_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[3]))] != 0xff || str_buf[3] == '=');
		gud = gud & (str_buf[2] != '=' || str_buf[3] == '=');
	}
	if(gud)
	{
		mk_lib_iip_base64_decoder_pr_no_check_block_24bits_final(str_buf, data_buf);
	}
	*success = gud;
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_base64_decoder_no_check(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pct in mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit == 8);

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(str_len % 4 == 0);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert
	(
		data_len >=
		(
			((str_len >= 1) ? (((str_len - 1) / 4) * 3) : (0)) +
			(((str_len >= 1) && (str_buf[str_len - 1] == '=')) ? (0) : (1)) +
			(((str_len >= 2) && (str_buf[str_len - 2] == '=')) ? (1) : (2))
		)
	);
	mk_lang_assert(out_len);

	if(str_len != 0)
	{
		in = str_buf;
		out = data_buf;
		n = (str_len - 1) / 4;
		for(i = 0; i != n; ++i)
		{
			mk_lib_iip_base64_decoder_pr_no_check_block_24bits_middle(in, out);
			in += 4;
			out += 3;
		}
		mk_lib_iip_base64_decoder_pr_no_check_block_24bits_final(in, out);
		*out_len =
			(((str_len - 1) / 4) * 3) +
			(((str_len >= 1) && (str_buf[str_len - 1] == '=')) ? (0) : (1)) +
			(((str_len >= 2) && (str_buf[str_len - 2] == '=')) ? (1) : (2));
	}
	else
	{
		*out_len = 0;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_base64_decoder_do_check(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_sint_pt const out_len, mk_lang_types_bool_pt const success) mk_lang_noexcept
{
	mk_lang_types_bool_t gud mk_lang_constexpr_init;
	mk_lang_types_pchar_pct in mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit == 8);

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(success);

	gud = mk_lang_true;
	gud = gud & (str_len % 4 == 0);
	gud = gud &
	(
		data_len >=
		(
			((str_len >= 1) ? (((str_len - 1) / 4) * 3) : (0)) +
			(((str_len >= 1) && (str_buf[str_len - 1] == '=')) ? (0) : (1)) +
			(((str_len >= 2) && (str_buf[str_len - 2] == '=')) ? (1) : (2))
		)
	);
	if(gud)
	{
		if(str_len != 0)
		{
			in = str_buf;
			out = data_buf;
			n = (str_len - 1) / 4;
			for(i = 0; i != n; ++i)
			{
				mk_lib_iip_base64_decoder_pr_do_check_block_24bits_middle(in, out, &gud);
				in += 4;
				out += 3;
			}
			mk_lib_iip_base64_decoder_pr_do_check_block_24bits_final(in, out, &gud);
			*out_len =
				(((str_len - 1) / 4) * 3) +
				(((str_len >= 1) && (str_buf[str_len - 1] == '=')) ? (0) : (1)) +
				(((str_len >= 2) && (str_buf[str_len - 2] == '=')) ? (1) : (2));
		}
		else
		{
			*out_len = 0;
		}
	}
	*success = gud;
}


#endif
