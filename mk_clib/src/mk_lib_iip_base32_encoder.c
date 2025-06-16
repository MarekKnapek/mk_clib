#ifndef mk_include_guard_mk_lib_iip_base32_encoder_c
#define mk_include_guard_mk_lib_iip_base32_encoder_c
#include "mk_lib_iip_base32_encoder.h"

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
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"


union mk_lib_iip_base32_encoder_alphabet_data_u
{
	mk_lang_types_pchar_t m_pchars[32];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_iip_base32_encoder_alphabet_data_u mk_lib_iip_base32_encoder_alphabet_data_t;
struct mk_lib_iip_base32_encoder_alphabet_s
{
	mk_lang_alignas(32) mk_lib_iip_base32_encoder_alphabet_data_t m_data;
};
typedef struct mk_lib_iip_base32_encoder_alphabet_s mk_lib_iip_base32_encoder_alphabet_t;


mk_lang_constexpr_static_inline mk_lib_iip_base32_encoder_alphabet_t const mk_lib_iip_base32_encoder_k_alphabet =
{{{
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
	'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
	'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
	'y', 'z', '2', '3', '4', '5', '6', '7',
}}};


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_base32_encoder_pr_block_40bits_middle(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_pchar_pt const str_buf) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in mk_lang_constexpr_init;
	mk_lang_types_pchar_pt out mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tu32 mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_sint_t idx mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;

	mk_lang_assert(data_buf);
	mk_lang_assert(str_buf);

	in = data_buf;
	out = str_buf;
	mk_sl_uint_convert_32_8_be_to_big(&tu32, &in[1]); mk_sl_cui_uint32_to_bi_ulong(&tu32, &tul);
	idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & ((mk_lang_types_ulong_t)(32 - 1))))));
	out[7] = mk_lib_iip_base32_encoder_k_alphabet.m_data.m_pchars[idx];
	tul >>= 5;
	idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & ((mk_lang_types_ulong_t)(32 - 1))))));
	out[6] = mk_lib_iip_base32_encoder_k_alphabet.m_data.m_pchars[idx];
	tul >>= 5;
	idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & ((mk_lang_types_ulong_t)(32 - 1))))));
	out[5] = mk_lib_iip_base32_encoder_k_alphabet.m_data.m_pchars[idx];
	tul >>= 5;
	idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & ((mk_lang_types_ulong_t)(32 - 1))))));
	out[4] = mk_lib_iip_base32_encoder_k_alphabet.m_data.m_pchars[idx];
	tul >>= 5;
	idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & ((mk_lang_types_ulong_t)(32 - 1))))));
	out[3] = mk_lib_iip_base32_encoder_k_alphabet.m_data.m_pchars[idx];
	tul >>= 5;
	idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & ((mk_lang_types_ulong_t)(32 - 1))))));
	out[2] = mk_lib_iip_base32_encoder_k_alphabet.m_data.m_pchars[idx];
	tul >>= 5;
	mk_sl_cui_uint8_to_bi_uchar(&in[0], &tuc);
	tul = ((mk_lang_types_ulong_t)(tul | ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tuc)) << 2))));
	idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & ((mk_lang_types_ulong_t)(32 - 1))))));
	out[1] = mk_lib_iip_base32_encoder_k_alphabet.m_data.m_pchars[idx];
	tul >>= 5;
	mk_lang_assert(tul <= 32 - 1);
	idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & ((mk_lang_types_ulong_t)(32 - 1))))));
	mk_lang_assert(idx == ((mk_lang_types_sint_t)(tul)));
	out[0] = mk_lib_iip_base32_encoder_k_alphabet.m_data.m_pchars[idx];
	tul >>= 5;
	mk_lang_assert(tul == 0);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_base32_encoder_pr_block_40bits_final(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_pchar_pt const str_buf) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_pchar_pt out mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tu32 mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_sint_t idx mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;

	mk_lang_assert(data_buf);
	mk_lang_assert(data_len >= 0 + 1);
	mk_lang_assert(data_len <= 5 - 1);
	mk_lang_assert(str_buf);

	in = data_buf;
	n = data_len;
	out = str_buf;
	mk_sl_uint_convert_32_8_be_to_big(&tu32, &in[1]); mk_sl_cui_uint32_to_bi_ulong(&tu32, &tul);
	idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & ((mk_lang_types_ulong_t)(32 - 1))))));
	if(n * 8 >= 7 * 5){ out[7] = mk_lib_iip_base32_encoder_k_alphabet.m_data.m_pchars[idx]; } /* never taken */
	tul >>= 5;
	idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & ((mk_lang_types_ulong_t)(32 - 1))))));
	if(n * 8 >= 6 * 5){ out[6] = mk_lib_iip_base32_encoder_k_alphabet.m_data.m_pchars[idx]; }
	tul >>= 5;
	idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & ((mk_lang_types_ulong_t)(32 - 1))))));
	if(n * 8 >= 5 * 5){ out[5] = mk_lib_iip_base32_encoder_k_alphabet.m_data.m_pchars[idx]; }
	tul >>= 5;
	idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & ((mk_lang_types_ulong_t)(32 - 1))))));
	if(n * 8 >= 4 * 5){ out[4] = mk_lib_iip_base32_encoder_k_alphabet.m_data.m_pchars[idx]; }
	tul >>= 5;
	idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & ((mk_lang_types_ulong_t)(32 - 1))))));
	if(n * 8 >= 3 * 5){ out[3] = mk_lib_iip_base32_encoder_k_alphabet.m_data.m_pchars[idx]; }
	tul >>= 5;
	idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & ((mk_lang_types_ulong_t)(32 - 1))))));
	if(n * 8 >= 2 * 5){ out[2] = mk_lib_iip_base32_encoder_k_alphabet.m_data.m_pchars[idx]; }
	tul >>= 5;
	mk_sl_cui_uint8_to_bi_uchar(&in[0], &tuc);
	tul = ((mk_lang_types_ulong_t)(tul | ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tuc)) << 2))));
	idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & ((mk_lang_types_ulong_t)(32 - 1))))));
	if(n * 8 >= 1 * 5){ out[1] = mk_lib_iip_base32_encoder_k_alphabet.m_data.m_pchars[idx]; }
	tul >>= 5;
	mk_lang_assert(tul <= 32 - 1);
	idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & ((mk_lang_types_ulong_t)(32 - 1))))));
	mk_lang_assert(idx == ((mk_lang_types_sint_t)(tul)));
	if(n * 8 >= 0 * 5){ out[0] = mk_lib_iip_base32_encoder_k_alphabet.m_data.m_pchars[idx]; } /* always taken */
	tul >>= 5;
	mk_lang_assert(tul == 0);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_base32_encoder_fn(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in mk_lang_constexpr_init;
	mk_lang_types_pchar_pt out mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint8_t rest[5] mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit == 8);

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(data_len <= (mk_lang_limits_sint_max - (5 - 1)) / 8);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(str_len >= mk_lang_roundup_div(data_len * 8, 5));
	mk_lang_assert(out_len);

	in = data_buf;
	out = str_buf;
	n = data_len / 5;
	for(i = 0; i != n; ++i)
	{
		mk_lib_iip_base32_encoder_pr_block_40bits_middle(in, out);
		in += 5;
		out += 8;
	}
	n = data_len - n * 5;
	if(n != 0)
	{
		mk_lang_assert(n > 0 && n < 5);
		mk_sl_cui_uint8_memcpy_fn(&rest[0], &in[0], n);
		mk_sl_cui_uint8_memclr_fn(&rest[n], mk_lang_countof(rest) - n);
		in = &rest[0];
		mk_lib_iip_base32_encoder_pr_block_40bits_final(in, n, out);
	}
	n = mk_lang_roundup_div(data_len * 8, 5);
	*out_len = n;
}


#endif
