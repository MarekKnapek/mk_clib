#ifndef mk_include_guard_mk_lib_iip_base64_encoder_c
#define mk_include_guard_mk_lib_iip_base64_encoder_c
#include "mk_lib_iip_base64_encoder.h"

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_roundup.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


union mk_lib_iip_base64_encoder_alphabet_data_u
{
	mk_lang_types_pchar_t m_pchars[64];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_iip_base64_encoder_alphabet_data_u mk_lib_iip_base64_encoder_alphabet_data_t;
struct mk_lib_iip_base64_encoder_alphabet_s
{
	mk_lang_alignas(64) mk_lib_iip_base64_encoder_alphabet_data_t m_data;
};
typedef struct mk_lib_iip_base64_encoder_alphabet_s mk_lib_iip_base64_encoder_alphabet_t;


mk_lang_constexpr_static_inline mk_lib_iip_base64_encoder_alphabet_t const mk_lib_iip_base64_encoder_k_alphabet =
{{{
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
	'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
	'w', 'x', 'y', 'z', '0', '1', '2', '3',
	'4', '5', '6', '7', '8', '9', '-', '~',
}}};


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_base64_encoder_pr_block_24bits_middle(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_pchar_pt const str_buf) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in mk_lang_constexpr_init;
	mk_lang_types_pchar_pt out mk_lang_constexpr_init;
	mk_lang_types_uint_t ta mk_lang_constexpr_init;
	mk_lang_types_uint_t tb mk_lang_constexpr_init;
	mk_lang_types_uint_t idx mk_lang_constexpr_init;

	mk_lang_assert(data_buf);
	mk_lang_assert(str_buf);

	in = data_buf;
	out = str_buf;
	mk_sl_cui_uint8_to_bi_uint(&in[0], &ta);
	idx = (ta >> 2) & (64 - 1);
	out[0] = mk_lib_iip_base64_encoder_k_alphabet.m_data.m_pchars[idx];
	mk_sl_cui_uint8_to_bi_uint(&in[1], &tb);
	ta <<= 8;
	ta |= tb;
	idx = (ta >> 4) & (64 - 1);
	out[1] = mk_lib_iip_base64_encoder_k_alphabet.m_data.m_pchars[idx];
	mk_sl_cui_uint8_to_bi_uint(&in[2], &tb);
	ta <<= 8;
	ta |= tb;
	idx = (ta >> 6) & (64 - 1);
	out[2] = mk_lib_iip_base64_encoder_k_alphabet.m_data.m_pchars[idx];
	idx = ((mk_lang_types_sint_t)(ta & ((mk_lang_types_uint_t)(64 - 1))));
	out[3] = mk_lib_iip_base64_encoder_k_alphabet.m_data.m_pchars[idx];
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_base64_encoder_pr_block_24bits_final(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_pchar_pt const str_buf) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_pchar_pt out mk_lang_constexpr_init;
	mk_lang_types_uint_t ta mk_lang_constexpr_init;
	mk_lang_types_uint_t tb mk_lang_constexpr_init;
	mk_lang_types_sint_t idx mk_lang_constexpr_init;

	mk_lang_assert(data_buf);
	mk_lang_assert(data_len >= 0 + 1);
	mk_lang_assert(data_len <= 3 - 1);
	mk_lang_assert(str_buf);

	in = data_buf;
	n = data_len;
	out = str_buf;
	mk_sl_cui_uint8_to_bi_uint(&in[0], &ta);
	idx = ((mk_lang_types_sint_t)((ta >> 2) & (64 - 1)));
	out[0] = mk_lib_iip_base64_encoder_k_alphabet.m_data.m_pchars[idx];
	if(n == 1)
	{
		ta <<= 4;
		idx = ((mk_lang_types_sint_t)(ta & (64 - 1)));
		out[1] = mk_lib_iip_base64_encoder_k_alphabet.m_data.m_pchars[idx];
		out[2] = '=';
		out[3] = '=';
	}
	else if(n == 2)
	{
		mk_sl_cui_uint8_to_bi_uint(&in[1], &tb);
		ta <<= 8;
		ta |= tb;
		idx = ((mk_lang_types_sint_t)((ta >> 4) & (64 - 1)));
		out[1] = mk_lib_iip_base64_encoder_k_alphabet.m_data.m_pchars[idx];
		ta <<= 2;
		idx = ((mk_lang_types_sint_t)(ta & (64 - 1)));
		out[2] = mk_lib_iip_base64_encoder_k_alphabet.m_data.m_pchars[idx];
		out[3] = '=';
	}
	else
	{
		mk_lang_assert_false();
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_base64_encoder_fn(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in mk_lang_constexpr_init;
	mk_lang_types_pchar_pt out mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit == 8);

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(data_len <= (((mk_lang_limits_sint_max / 4) * 3) - (3 - 1)));
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(str_len >= mk_lang_roundup_div(data_len, 3) * 4);
	mk_lang_assert(out_len);

	in = data_buf;
	out = str_buf;
	n = data_len / 3;
	for(i = 0; i != n; ++i)
	{
		mk_lib_iip_base64_encoder_pr_block_24bits_middle(in, out);
		in += 3;
		out += 4;
	}
	n = data_len - n * 3;
	if(n != 0)
	{
		mk_lang_assert(n > 0 && n < 3);
		mk_lib_iip_base64_encoder_pr_block_24bits_final(in, n, out);
	}
	n = mk_lang_roundup_div(data_len, 3) * 4;
	*out_len = n;
}


#endif
