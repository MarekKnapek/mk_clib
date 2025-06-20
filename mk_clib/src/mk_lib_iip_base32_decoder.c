#ifndef mk_include_guard_mk_lib_iip_base32_decoder_c
#define mk_include_guard_mk_lib_iip_base32_decoder_c
#include "mk_lib_iip_base32_decoder.h"

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


union mk_lib_iip_base32_decoder_alphabet_data_u
{
	mk_lang_types_uchar_t m_uchars[0xff + 1];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_iip_base32_decoder_alphabet_data_u mk_lib_iip_base32_decoder_alphabet_data_t;
struct mk_lib_iip_base32_decoder_alphabet_s
{
	mk_lang_alignas(64) mk_lib_iip_base32_decoder_alphabet_data_t m_data;
};
typedef struct mk_lib_iip_base32_decoder_alphabet_s mk_lib_iip_base32_decoder_alphabet_t;


#include "mk_lang_warning_clang_push_reserved_macro_identifier.h"
#define ____ 0xff
mk_lang_constexpr_static_inline mk_lib_iip_base32_decoder_alphabet_t const mk_lib_iip_base32_decoder_k_alphabet =
{{{
	____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
	____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
	____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
	____, ____, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, ____, ____, ____, ____, ____, ____, ____, ____,
	____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
	____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
	____, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e,
	0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, ____, ____, ____, ____, ____,
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
#include "mk_lang_warning_clang_pop.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_base32_decoder_pr_no_check_block_40bits_middle(mk_lang_types_pchar_pct const str_buf, mk_sl_cui_uint8_pt const data_buf) mk_lang_noexcept
{
	mk_lang_types_pchar_pct in mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out mk_lang_constexpr_init;
	mk_lang_types_ushort_t tus mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;

	mk_lang_assert(str_buf);
	mk_lang_assert(data_buf);

	in = str_buf;
	out = data_buf;
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[0]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[1]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[2]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[3]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[4]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[5]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[6]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[7]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[0]))] >= 0);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[1]))] >= 0);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[2]))] >= 0);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[3]))] >= 0);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[4]))] >= 0);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[5]))] >= 0);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[6]))] >= 0);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[7]))] >= 0);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[0]))] < 32);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[1]))] < 32);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[2]))] < 32);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[3]))] < 32);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[4]))] < 32);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[5]))] < 32);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[6]))] < 32);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[7]))] < 32);
	tus = 0;
	tus = ((mk_lang_types_ushort_t)(tus | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[7]))])) << 0))));
	tus = ((mk_lang_types_ushort_t)(tus | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[6]))])) << 5))));
	tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ushort_t)(tus & ((mk_lang_types_ushort_t)(0x00ff))))));
	mk_sl_cui_uint8_from_bi_uchar(&out[4], &tuc);
	tus = ((mk_lang_types_ushort_t)(tus >> 8));
	tus = ((mk_lang_types_ushort_t)(tus | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[5]))])) << 2))));
	tus = ((mk_lang_types_ushort_t)(tus | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[4]))])) << 7))));
	tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ushort_t)(tus & ((mk_lang_types_ushort_t)(0x00ff))))));
	mk_sl_cui_uint8_from_bi_uchar(&out[3], &tuc);
	tus = ((mk_lang_types_ushort_t)(tus >> 8));
	tus = ((mk_lang_types_ushort_t)(tus | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[3]))])) << 4))));
	tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ushort_t)(tus & ((mk_lang_types_ushort_t)(0x00ff))))));
	mk_sl_cui_uint8_from_bi_uchar(&out[2], &tuc);
	tus = ((mk_lang_types_ushort_t)(tus >> 8));
	tus = ((mk_lang_types_ushort_t)(tus | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[2]))])) << 1))));
	tus = ((mk_lang_types_ushort_t)(tus | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[1]))])) << 6))));
	tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ushort_t)(tus & ((mk_lang_types_ushort_t)(0x00ff))))));
	mk_sl_cui_uint8_from_bi_uchar(&out[1], &tuc);
	tus = ((mk_lang_types_ushort_t)(tus >> 8));
	tus = ((mk_lang_types_ushort_t)(tus | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[0]))])) << 3))));
	mk_lang_assert(tus <= 0x00ff);
	tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ushort_t)(tus & ((mk_lang_types_ushort_t)(0x00ff))))));
	mk_sl_cui_uint8_from_bi_uchar(&out[0], &tuc);
	tus = ((mk_lang_types_ushort_t)(tus >> 8));
	mk_lang_assert(tus == 0x0000);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_base32_decoder_pr_no_check_block_40bits_final(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_sl_cui_uint8_pt const data_buf) mk_lang_noexcept
{
	mk_lang_types_pchar_pct in mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out mk_lang_constexpr_init;
	mk_lang_types_ushort_t tus mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;

	mk_lang_assert(str_buf);
	mk_lang_assert
	(
		(str_len == 2) ||
		(str_len == 4) ||
		(str_len == 5) ||
		(str_len == 7) ||
		0
	);
	mk_lang_assert(data_buf);

	in = str_buf;
	n = str_len;
	out = data_buf;
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[0]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[1]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[2]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[3]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[4]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[5]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[6]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[7]))] != 0xff);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[0]))] >= 0);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[1]))] >= 0);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[2]))] >= 0);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[3]))] >= 0);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[4]))] >= 0);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[5]))] >= 0);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[6]))] >= 0);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[7]))] >= 0);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[0]))] < 32);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[1]))] < 32);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[2]))] < 32);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[3]))] < 32);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[4]))] < 32);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[5]))] < 32);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[6]))] < 32);
	mk_lang_assert(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[7]))] < 32);
	tus = 0;
	mk_lang_assert(in[7] == 'a');
	tus = ((mk_lang_types_ushort_t)(tus | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[7]))])) << 0))));
	tus = ((mk_lang_types_ushort_t)(tus | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[6]))])) << 5))));
	tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ushort_t)(tus & ((mk_lang_types_ushort_t)(0x00ff))))));
	if(n * 5 >= 5 * 8){ mk_sl_cui_uint8_from_bi_uchar(&out[4], &tuc); } /* never taken */
	tus = ((mk_lang_types_ushort_t)(tus >> 8));
	tus = ((mk_lang_types_ushort_t)(tus | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[5]))])) << 2))));
	tus = ((mk_lang_types_ushort_t)(tus | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[4]))])) << 7))));
	tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ushort_t)(tus & ((mk_lang_types_ushort_t)(0x00ff))))));
	if(n * 5 >= 4 * 8){ mk_sl_cui_uint8_from_bi_uchar(&out[3], &tuc); }
	tus = ((mk_lang_types_ushort_t)(tus >> 8));
	tus = ((mk_lang_types_ushort_t)(tus | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[3]))])) << 4))));
	tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ushort_t)(tus & ((mk_lang_types_ushort_t)(0x00ff))))));
	if(n * 5 >= 3 * 8){ mk_sl_cui_uint8_from_bi_uchar(&out[2], &tuc); }
	tus = ((mk_lang_types_ushort_t)(tus >> 8));
	tus = ((mk_lang_types_ushort_t)(tus | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[2]))])) << 1))));
	tus = ((mk_lang_types_ushort_t)(tus | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[1]))])) << 6))));
	tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ushort_t)(tus & ((mk_lang_types_ushort_t)(0x00ff))))));
	if(n * 5 >= 2 * 8){ mk_sl_cui_uint8_from_bi_uchar(&out[1], &tuc); }
	tus = ((mk_lang_types_ushort_t)(tus >> 8));
	tus = ((mk_lang_types_ushort_t)(tus | ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(in[0]))])) << 3))));
	mk_lang_assert(tus <= 0x00ff);
	tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ushort_t)(tus & ((mk_lang_types_ushort_t)(0x00ff))))));
	if(n * 5 >= 1 * 8){ mk_sl_cui_uint8_from_bi_uchar(&out[0], &tuc); } /* always taken */
	tus = ((mk_lang_types_ushort_t)(tus >> 8));
	mk_lang_assert(tus == 0x0000);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_base32_decoder_pr_do_check_block_40bits_middle(mk_lang_types_pchar_pct const str_buf, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_bool_pt const success) mk_lang_noexcept
{
	mk_lang_types_bool_t gud mk_lang_constexpr_init;

	mk_lang_assert(str_buf);
	mk_lang_assert(data_buf);
	mk_lang_assert(success);

	gud = *success;
	if(gud)
	{
		gud = gud & (mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[0]))] != 0xff);
		gud = gud & (mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[1]))] != 0xff);
		gud = gud & (mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[2]))] != 0xff);
		gud = gud & (mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[3]))] != 0xff);
		gud = gud & (mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[4]))] != 0xff);
		gud = gud & (mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[5]))] != 0xff);
		gud = gud & (mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[6]))] != 0xff);
		gud = gud & (mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[7]))] != 0xff);
	}
	if(gud)
	{
		mk_lib_iip_base32_decoder_pr_no_check_block_40bits_middle(str_buf, data_buf);
	}
	*success = gud;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_base32_decoder_pr_do_check_block_40bits_final(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_bool_pt const success) mk_lang_noexcept
{
	mk_lang_types_bool_t gud mk_lang_constexpr_init;

	mk_lang_assert(str_buf);
	mk_lang_assert
	(
		(str_len == 2) ||
		(str_len == 4) ||
		(str_len == 5) ||
		(str_len == 7) ||
		0
	);
	mk_lang_assert(data_buf);

	gud = *success;
	if(gud)
	{
		gud = gud & (mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[0]))] != 0xff);
		gud = gud & (mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[1]))] != 0xff);
		gud = gud & (mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[2]))] != 0xff);
		gud = gud & (mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[3]))] != 0xff);
		gud = gud & (mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[4]))] != 0xff);
		gud = gud & (mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[5]))] != 0xff);
		gud = gud & (mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[6]))] != 0xff);
		gud = gud & (mk_lib_iip_base32_decoder_k_alphabet.m_data.m_uchars[((mk_lang_types_uchar_t)(str_buf[7]))] != 0xff);
	}
	if(gud)
	{
		mk_lib_iip_base32_decoder_pr_no_check_block_40bits_final(str_buf, str_len, data_buf);
	}
	*success = gud;
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_base32_decoder_no_check(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pct in mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_pchar_t zero mk_lang_constexpr_init;
	mk_lang_types_pchar_t rest[8] mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit == 8);

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(str_len <= mk_lang_limits_sint_max / 5);
	mk_lang_assert
	(
		((str_len - ((str_len / 8) * 8)) == 0) ||
		((str_len - ((str_len / 8) * 8)) == 2) ||
		((str_len - ((str_len / 8) * 8)) == 4) ||
		((str_len - ((str_len / 8) * 8)) == 5) ||
		((str_len - ((str_len / 8) * 8)) == 7) ||
		0
	);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(data_len >= (str_len * 5) / 8);
	mk_lang_assert(out_len);

	if(str_len != 0)
	{
		in = str_buf;
		out = data_buf;
		n = str_len / 8;
		for(i = 0; i != n; ++i)
		{
			mk_lib_iip_base32_decoder_pr_no_check_block_40bits_middle(in, out);
			in += 8;
			out += 5;
		}
		n = str_len - n * 8;
		if(n != 0)
		{
			mk_lang_assert
			(
				(n == 2) ||
				(n == 4) ||
				(n == 5) ||
				(n == 7) ||
				0
			);
			zero = 'a';
			mk_lang_string_memcpy_pc_fn(&rest[0], &in[0], ((mk_lang_types_usize_t)(n)));
			mk_lang_string_memset_pc_fn(&rest[n], &zero, mk_lang_countof(rest) - ((mk_lang_types_usize_t)(n)));
			in = &rest[0];
			mk_lib_iip_base32_decoder_pr_no_check_block_40bits_final(in, n, out);
		}
		*out_len = (str_len * 5) / 8;
	}
	else
	{
		*out_len = 0;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_base32_decoder_do_check(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_sint_pt const out_len, mk_lang_types_bool_pt const success) mk_lang_noexcept
{
	mk_lang_types_bool_t gud mk_lang_constexpr_init;
	mk_lang_types_pchar_pct in mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_pchar_t zero mk_lang_constexpr_init;
	mk_lang_types_pchar_t rest[8] mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit == 8);

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(str_len <= mk_lang_limits_sint_max / 5);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(data_len >= (str_len * 5) / 8);
	mk_lang_assert(out_len);
	mk_lang_assert(success);

	gud = mk_lang_true;
	if(gud)
	{
		gud =
		(
			((str_len - ((str_len / 8) * 8)) == 0) ||
			((str_len - ((str_len / 8) * 8)) == 2) ||
			((str_len - ((str_len / 8) * 8)) == 4) ||
			((str_len - ((str_len / 8) * 8)) == 5) ||
			((str_len - ((str_len / 8) * 8)) == 7) ||
			0
		);
	}
	if(gud)
	{
		if(str_len != 0)
		{
			in = str_buf;
			out = data_buf;
			n = str_len / 8;
			for(i = 0; i != n; ++i)
			{
				mk_lib_iip_base32_decoder_pr_do_check_block_40bits_middle(in, out, &gud);
				in += 8;
				out += 5;
			}
			n = str_len - n * 8;
			if(n != 0)
			{
				mk_lang_assert
				(
					(n == 2) ||
					(n == 4) ||
					(n == 5) ||
					(n == 7) ||
					0
				);
				zero = 'a';
				mk_lang_string_memcpy_pc_fn(&rest[0], &in[0], ((mk_lang_types_usize_t)(n)));
				mk_lang_string_memset_pc_fn(&rest[n], &zero, mk_lang_countof(rest) - ((mk_lang_types_usize_t)(n)));
				in = &rest[0];
				mk_lib_iip_base32_decoder_pr_do_check_block_40bits_final(in, n, out, &gud);
			}
			*out_len = (str_len * 5) / 8;
		}
		else
		{
			*out_len = 0;
		}
	}
	*success = gud;
}


#endif
