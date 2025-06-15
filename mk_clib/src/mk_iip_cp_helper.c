#ifndef mk_include_guard_mk_iip_cp_helper_c
#define mk_include_guard_mk_iip_cp_helper_c
#include "mk_iip_cp_helper.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_sha2_256.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"
#include "mk_win_kernel_time.h"

#define mk_lang_memcpy_t_name mk_iip_cp_helper_memcpy_u8
#define mk_lang_memcpy_t_type mk_sl_cui_uint8_t
#include "mk_lang_memcpy_inl_filec.h"

#define mk_lang_bui_t_name mk_iip_cp_helper_bui
#define mk_lang_bui_t_base uint
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_t_name mk_iip_cp_helper_cui_sha256
#define mk_sl_cui_t_base mk_iip_cp_helper_bui
#define mk_sl_cui_t_count ((mk_lib_crypto_hash_block_sha2_256_digest_len * mk_lang_charbit) / mk_iip_cp_helper_bui_sizebits_d)
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"


#include <stdlib.h>


#define ____ 0xff

mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_iip_cp_helper_base64_alphabet[64] =
{
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
	'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
	'w', 'x', 'y', 'z', '0', '1', '2', '3',
	'4', '5', '6', '7', '8', '9', '-', '~',
};

mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_iip_cp_helper_base32_alphabet[32] =
{
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
	'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
	'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
	'y', 'z', '2', '3', '4', '5', '6', '7',
};

mk_lang_constexpr_static_inline mk_lang_types_uchar_t const mk_iip_cp_helper_base64_reverse[256] =
{
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
};

#undef ____


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_u8s_to_uchars(mk_sl_cui_uint8_pct const u8s, mk_lang_types_uchar_pt const ucs, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(u8s || len == 0);
	mk_lang_assert(ucs || len == 0);
	mk_lang_assert(len >= 0);

	n = len;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_to_bi_uchar(&u8s[i], &ucs[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_u8s_to_pchars(mk_sl_cui_uint8_pct const u8s, mk_lang_types_pchar_pt const pcs, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(u8s || len == 0);
	mk_lang_assert(pcs || len == 0);
	mk_lang_assert(len >= 0);

	n = len;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_to_bi_pchar(&u8s[i], &pcs[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_u8s_to_hex(mk_sl_cui_uint8_pct const u8s, mk_lang_types_pchar_pt const pcs, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(u8s || len == 0);
	mk_lang_assert(pcs || len == 0);
	mk_lang_assert(len >= 0);

	n = len;
	for(i = 0; i != n; ++i)
	{
		tlen = mk_sl_cui_uint8_to_str_hexf_n(&u8s[i], &pcs[i * mk_sl_cui_uint8_strlenhex_v], mk_sl_cui_uint8_strlenhex_v); mk_lang_assert(tlen == mk_sl_cui_uint8_strlenhex_v);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_uchars_to_u8s(mk_lang_types_uchar_pct const ucs, mk_sl_cui_uint8_pt const u8s, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(ucs || len == 0);
	mk_lang_assert(u8s || len == 0);
	mk_lang_assert(len >= 0);

	n = len;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_from_bi_uchar(&u8s[i], &ucs[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_sha256_to_pchars(mk_lib_crypto_hash_block_sha2_256_digest_pct const digest, mk_lang_types_pchar_pt const strbuf) mk_lang_noexcept
{
	mk_lang_types_uchar_t uchars[mk_lib_crypto_hash_block_sha2_256_digest_len] mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_sha256_t cui_sha256 mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(digest);
	mk_lang_assert(strbuf);

	mk_iip_cp_helper_u8s_to_uchars(&digest->m_uint8s[0], &uchars[0], mk_lib_crypto_hash_block_sha2_256_digest_len);
	mk_iip_cp_helper_cui_sha256_from_buis_uchar_be(&cui_sha256, &uchars[0]);
	len = mk_iip_cp_helper_cui_sha256_to_str_hexf_n(&cui_sha256, strbuf, mk_iip_cp_helper_cui_sha256_strlenhex_v); mk_lang_assert(len == mk_iip_cp_helper_cui_sha256_strlenhex_v);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_base64_u8s_to_pchars(mk_sl_cui_uint8_pct const databuf, mk_lang_types_sint_t const datalen, mk_lang_types_pchar_pt const strbuf, mk_lang_types_sint_pt const outlen) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in mk_lang_constexpr_init;
	mk_lang_types_pchar_pt out mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_uint_t tui mk_lang_constexpr_init;
	mk_lang_types_uint_t u mk_lang_constexpr_init;
	mk_lang_types_uint_t idx mk_lang_constexpr_init;

	mk_lang_assert(databuf || datalen == 0);
	mk_lang_assert(datalen >= 0);
	mk_lang_assert(strbuf || datalen == 0);
	mk_lang_assert(outlen);

	in = databuf;
	out = strbuf;
	n = datalen / 3;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_to_bi_uint(&in[0], &tui);
		u = tui;
		idx = (u >> 2) & (64 - 1);
		out[0] = mk_iip_cp_helper_base64_alphabet[idx];
		mk_sl_cui_uint8_to_bi_uint(&in[1], &tui);
		u <<= 8;
		u |= tui;
		idx = (u >> 4) & (64 - 1);
		out[1] = mk_iip_cp_helper_base64_alphabet[idx];
		mk_sl_cui_uint8_to_bi_uint(&in[2], &tui);
		u <<= 8;
		u |= tui;
		idx = (u >> 6) & (64 - 1);
		out[2] = mk_iip_cp_helper_base64_alphabet[idx];
		idx = u & (64 - 1);
		out[3] = mk_iip_cp_helper_base64_alphabet[idx];
		in += 3;
		out += 4;
	}
	n = datalen - n * 3;
	if(n == 1)
	{
		mk_sl_cui_uint8_to_bi_uint(&in[0], &tui);
		u = tui;
		idx = (u >> 2) & (64 - 1);
		out[0] = mk_iip_cp_helper_base64_alphabet[idx];
		u <<= 8;
		u |= tui;
		idx = (u >> 4) & (64 - 1);
		out[1] = mk_iip_cp_helper_base64_alphabet[idx];
		out[2] = '=';
		out[3] = '=';
	}
	else if(n == 2)
	{
		mk_sl_cui_uint8_to_bi_uint(&in[0], &tui);
		u = tui;
		idx = (u >> 2) & (64 - 1);
		out[0] = mk_iip_cp_helper_base64_alphabet[idx];
		mk_sl_cui_uint8_to_bi_uint(&in[1], &tui);
		u <<= 8;
		u |= tui;
		idx = (u >> 4) & (64 - 1);
		out[1] = mk_iip_cp_helper_base64_alphabet[idx];
		u <<= 8;
		u |= tui;
		idx = (u >> 6) & (64 - 1);
		out[2] = mk_iip_cp_helper_base64_alphabet[idx];
		out[3] = '=';
	}
	n = mk_lang_roundup_div(datalen, 3) * 4;
	*outlen = n;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_base64_pchars_to_u8s(mk_lang_types_pchar_pct const strbuf, mk_lang_types_sint_t const strlen, mk_sl_cui_uint8_pt const databuf, mk_lang_types_sint_pt const outlen) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;

	mk_lang_assert(strbuf || strlen == 0);
	mk_lang_assert(strlen >= 0);
	mk_lang_assert(strlen % 4 == 0);
	mk_lang_assert(databuf || strlen == 0);
	mk_lang_assert(outlen);

	if(strlen >= 1)
	{
		n = strlen / 4;
		for(i = 0; i != n - 1; ++i)
		{
			mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 0]))] != 0xff);
			mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 1]))] != 0xff);
			mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 2]))] != 0xff);
			mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 3]))] != 0xff);
			mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 0]))] >= 0);
			mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 1]))] >= 0);
			mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 2]))] >= 0);
			mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 3]))] >= 0);
			mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 0]))] < 64);
			mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 1]))] < 64);
			mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 2]))] < 64);
			mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 3]))] < 64);
			tul = 0;
			tul |= ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 0]))])) << (3 * 6)));
			tul |= ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 1]))])) << (2 * 6)));
			tul |= ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 2]))])) << (1 * 6)));
			tul |= ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 3]))])) << (0 * 6)));
			tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tul >> (2 * 8))) & ((mk_lang_types_ulong_t)(0xff)))))); mk_sl_cui_uint8_from_bi_uchar(&databuf[i * 3 + 0], &tuc);
			tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tul >> (1 * 8))) & ((mk_lang_types_ulong_t)(0xff)))))); mk_sl_cui_uint8_from_bi_uchar(&databuf[i * 3 + 1], &tuc);
			tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tul >> (0 * 8))) & ((mk_lang_types_ulong_t)(0xff)))))); mk_sl_cui_uint8_from_bi_uchar(&databuf[i * 3 + 2], &tuc);
		}
		mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 0]))] != 0xff);
		mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 1]))] != 0xff);
		mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 2]))] != 0xff || strbuf[i * 4 + 2] == '=');
		mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 3]))] != 0xff || strbuf[i * 4 + 3] == '=');
		mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 0]))] >= 0);
		mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 1]))] >= 0);
		mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 2]))] >= 0 || strbuf[i * 4 + 2] == '=');
		mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 3]))] >= 0 || strbuf[i * 4 + 3] == '=');
		mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 0]))] < 64);
		mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 1]))] < 64);
		mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 2]))] < 64 || strbuf[i * 4 + 2] == '=');
		mk_lang_assert(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 3]))] < 64 || strbuf[i * 4 + 3] == '=');
		mk_lang_assert(strbuf[i * 4 + 2] != '=' || strbuf[i * 4 + 3] == '=');
		tul = 0;
		tul |= ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 0]))])) << (3 * 6)));
		tul |= ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 1]))])) << (2 * 6)));
		tul |= (strbuf[i * 4 + 2] == '=') ? ((mk_lang_types_ulong_t)(0)) : ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 2]))])) << (1 * 6)));
		tul |= (strbuf[i * 4 + 3] == '=') ? ((mk_lang_types_ulong_t)(0)) : ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(mk_iip_cp_helper_base64_reverse[((mk_lang_types_uchar_t)(strbuf[i * 4 + 3]))])) << (0 * 6)));
		tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tul >> (2 * 8))) & ((mk_lang_types_ulong_t)(0xff)))))); mk_sl_cui_uint8_from_bi_uchar(&databuf[i * 3 + 0], &tuc);
		if(strbuf[i * 4 + 2] != '='){ tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tul >> (1 * 8))) & ((mk_lang_types_ulong_t)(0xff)))))); mk_sl_cui_uint8_from_bi_uchar(&databuf[i * 3 + 1], &tuc); }
		if(strbuf[i * 4 + 3] != '='){ tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tul >> (0 * 8))) & ((mk_lang_types_ulong_t)(0xff)))))); mk_sl_cui_uint8_from_bi_uchar(&databuf[i * 3 + 2], &tuc); }
		*outlen = ((strlen / 4) * 3) - ((strbuf[i * 4 + 3] == '=') ? 1 : 0) - ((strbuf[i * 4 + 2] == '=') ? 1 : 0);
	}
	else
	{
		*outlen = 0;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_base32_u8s_to_pchars(mk_sl_cui_uint8_pct const databuf, mk_lang_types_sint_t const datalen, mk_lang_types_pchar_pt const strbuf, mk_lang_types_sint_pt const outlen) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in mk_lang_constexpr_init;
	mk_lang_types_pchar_pt out mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tu32 mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_sint_t idx mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_sl_cui_uint8_t rest[5] mk_lang_constexpr_init;

	mk_lang_assert(databuf || datalen == 0);
	mk_lang_assert(datalen >= 0);
	mk_lang_assert(strbuf || datalen == 0);
	mk_lang_assert(outlen);

	in = databuf;
	out = strbuf;
	n = datalen / 5;
	for(i = 0; i != n; ++i)
	{
		mk_sl_uint_32_from_8_be(&tu32, &in[1]);
		mk_sl_cui_uint32_to_bi_ulong(&tu32, &tul);
		idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & (32 - 1)))));
		out[7] = mk_iip_cp_helper_base32_alphabet[idx];
		tul >>= 5;
		idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & (32 - 1)))));
		out[6] = mk_iip_cp_helper_base32_alphabet[idx];
		tul >>= 5;
		idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & (32 - 1)))));
		out[5] = mk_iip_cp_helper_base32_alphabet[idx];
		tul >>= 5;
		idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & (32 - 1)))));
		out[4] = mk_iip_cp_helper_base32_alphabet[idx];
		tul >>= 5;
		idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & (32 - 1)))));
		out[3] = mk_iip_cp_helper_base32_alphabet[idx];
		tul >>= 5;
		idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & (32 - 1)))));
		out[2] = mk_iip_cp_helper_base32_alphabet[idx];
		tul >>= 5;
		mk_sl_cui_uint8_to_bi_uchar(&in[0], &tuc);
		tul |= ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tuc)) << 2));
		idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & (32 - 1)))));
		out[1] = mk_iip_cp_helper_base32_alphabet[idx];
		tul >>= 5;
		idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & (32 - 1)))));
		out[0] = mk_iip_cp_helper_base32_alphabet[idx];
		in += 5;
		out += 8;
	}
	n = datalen - n * 5;
	if(n != 0)
	{
		for(i = 0; i != n; ++i)
		{
			rest[i] = in[i];
		}
		for(; i != mk_lang_countof(rest); ++i)
		{
			mk_sl_cui_uint8_set_zero(&rest[i]);
		}
		mk_sl_uint_32_from_8_be(&tu32, &rest[1]);
		mk_sl_cui_uint32_to_bi_ulong(&tu32, &tul);
		idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & (32 - 1)))));
		if(n * mk_lang_charbit >= 7 * 5){ out[7] = mk_iip_cp_helper_base32_alphabet[idx]; }
		tul >>= 5;
		idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & (32 - 1)))));
		if(n * mk_lang_charbit >= 6 * 5){ out[6] = mk_iip_cp_helper_base32_alphabet[idx]; }
		tul >>= 5;
		idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & (32 - 1)))));
		if(n * mk_lang_charbit >= 5 * 5){ out[5] = mk_iip_cp_helper_base32_alphabet[idx]; }
		tul >>= 5;
		idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & (32 - 1)))));
		if(n * mk_lang_charbit >= 4 * 5){ out[4] = mk_iip_cp_helper_base32_alphabet[idx]; }
		tul >>= 5;
		idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & (32 - 1)))));
		if(n * mk_lang_charbit >= 3 * 5){ out[3] = mk_iip_cp_helper_base32_alphabet[idx]; }
		tul >>= 5;
		idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & (32 - 1)))));
		if(n * mk_lang_charbit >= 2 * 5){ out[2] = mk_iip_cp_helper_base32_alphabet[idx]; }
		tul >>= 5;
		mk_sl_cui_uint8_to_bi_uchar(&rest[0], &tuc);
		tul |= ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tuc)) << 2));
		idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & (32 - 1)))));
		if(n * mk_lang_charbit >= 1 * 5){ out[1] = mk_iip_cp_helper_base32_alphabet[idx]; }
		tul >>= 5;
		idx = ((mk_lang_types_sint_t)(((mk_lang_types_ulong_t)(tul & (32 - 1)))));
		out[0] = mk_iip_cp_helper_base32_alphabet[idx];
	}
	n = mk_lang_roundup_div(datalen * mk_lang_charbit, 5);
	*outlen = n;
}

mk_lang_constexpr_static_inline mk_sl_cui_uint64_t const mk_iip_cp_helper_time_to_components_max = mk_sl_cui_uint64_c(0x000017d2ul, 0x5b8ae400ul);

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_time_to_components(mk_sl_cui_uint64_pct const time, mk_iip_cp_helper_time_components_pt const components) mk_lang_noexcept
{
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t s_since_unix mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tc mk_lang_constexpr_init;
	mk_lang_types_sint_t ms_in_s mk_lang_constexpr_init;
	mk_sl_cui_uint64_t d_since_unix_big mk_lang_constexpr_init;
	mk_lang_types_slong_t d_since_unix mk_lang_constexpr_init;
	mk_lang_types_slong_t s_in_d mk_lang_constexpr_init;
	mk_lang_types_slong_t m_in_d mk_lang_constexpr_init;
	mk_lang_types_slong_t s_in_m mk_lang_constexpr_init;
	mk_lang_types_slong_t h_in_d mk_lang_constexpr_init;
	mk_lang_types_slong_t m_in_h mk_lang_constexpr_init;
	mk_lang_types_slong_t d_since_c400_march mk_lang_constexpr_init;
	mk_lang_types_slong_t c400 mk_lang_constexpr_init;
	mk_lang_types_slong_t d_in_c400 mk_lang_constexpr_init;
	mk_lang_types_slong_t c100 mk_lang_constexpr_init;
	mk_lang_types_slong_t d_in_c100 mk_lang_constexpr_init;
	mk_lang_types_slong_t c4 mk_lang_constexpr_init;
	mk_lang_types_slong_t d_in_c4 mk_lang_constexpr_init;
	mk_lang_types_slong_t c1 mk_lang_constexpr_init;
	mk_lang_types_slong_t d_in_c4r mk_lang_constexpr_init;
	mk_lang_types_slong_t d_in_c1 mk_lang_constexpr_init;
	mk_lang_types_slong_t d_in_y mk_lang_constexpr_init;
	mk_lang_types_slong_t m_in_y mk_lang_constexpr_init;
	mk_lang_types_slong_t d_in_m mk_lang_constexpr_init;
	mk_lang_types_slong_t y mk_lang_constexpr_init;

	mk_lang_types_slong_t const c_d_in_c400 = 400l * 365l + 400l / 4l - 400l / 100l + 400l / 400l;
	mk_lang_types_slong_t const c_d_unix_to_c400_march = 10957l + 31l + 29l;
	mk_lang_types_slong_t const c_d_in_c100 = 100l * 365l + 100l / 4l - 100l / 100l;
	mk_lang_types_slong_t const c_d_in_c4 = 4l * 365l + 1l;
	mk_lang_types_slong_t const c_d_in_c1 = 1l * 365l + 0l;
	mk_lang_types_sint_t const c_lens[] = {31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29};

	mk_lang_assert(time);
	mk_lang_assert(components);

	if(mk_sl_cui_uint64_le(time, &mk_iip_cp_helper_time_to_components_max))
	{
		tsi = 1 * 1000; mk_sl_cui_uint64_from_bi_sint(&ta, &tsi);
		mk_sl_cui_uint64_divmod4_wrap(time, &ta, &s_since_unix, &tc);
		mk_sl_cui_uint64_to_bi_sint(&tc, &ms_in_s);

		tsi = 1 * 24 * 60 * 60; mk_sl_cui_uint64_from_bi_sint(&ta, &tsi);
		mk_sl_cui_uint64_divmod4_wrap(&s_since_unix, &ta, &d_since_unix_big, &tc);
		mk_sl_cui_uint64_to_bi_slong(&d_since_unix_big, &d_since_unix);
		mk_sl_cui_uint64_to_bi_slong(&tc, &s_in_d);

		m_in_d = s_in_d / (1 * 60);
		s_in_m = s_in_d % (1 * 60);

		h_in_d = m_in_d / (1 * 60);
		m_in_h = m_in_d % (1 * 60);

		d_since_c400_march = d_since_unix + (c_d_in_c400 - c_d_unix_to_c400_march);

		c400 = d_since_c400_march / c_d_in_c400;
		d_in_c400 = d_since_c400_march % c_d_in_c400;

		c100 = d_in_c400 / c_d_in_c100;
		d_in_c100 = d_in_c400 % c_d_in_c100;

		c4 = d_in_c100 / c_d_in_c4;
		d_in_c4 = d_in_c100 % c_d_in_c4;

		c1 = 0;
		d_in_c4r = d_in_c4;
		if(d_in_c4r > c_d_in_c1)
		{
			++c1;
			d_in_c4r -= c_d_in_c1;
			if(d_in_c4r > c_d_in_c1)
			{
				++c1;
				d_in_c4r -= c_d_in_c1;
				if(d_in_c4r > c_d_in_c1)
				{
					++c1;
					d_in_c4r -= c_d_in_c1;
				}
			}
		}
		d_in_c1 = d_in_c4r;
		d_in_y = d_in_c1;
		m_in_y = 0;
		while(d_in_y >= c_lens[m_in_y])
		{
			d_in_y -= c_lens[m_in_y];
			++m_in_y;
		}
		d_in_m = d_in_y + 1;
		m_in_y += 2;
		if(m_in_y >= 12)
		{
			m_in_y -= 12;
			++c1;
		}
		++m_in_y;
		y = 1600 + c400 * 400 + c100 * 100 + c4 * 4 + c1 * 1;
		if(m_in_y == 2 && d_in_m == 29 && !((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)))
		{
			d_in_m = 1;
			m_in_y = 3;
		}
		mk_lang_assert(y >= 1600 && y <= 2800);
		mk_lang_assert(m_in_y >= 1 && m_in_y <= 12);
		mk_lang_assert(d_in_m >= 1 && d_in_m <= 31); mk_lang_assert(d_in_m >= 1 && d_in_m <= c_lens[((m_in_y + 12) - 3) % 12]);
		mk_lang_assert(h_in_d >= 0 && h_in_d < 24);
		mk_lang_assert(m_in_h >= 0 && m_in_h < 60);
		mk_lang_assert(s_in_m >= 0 && s_in_m < 60);
		mk_lang_assert(ms_in_s >= 0 && ms_in_s < 1000);
		components->m_year = y;
		components->m_month = m_in_y;
		components->m_day = d_in_m;
		components->m_hour = h_in_d;
		components->m_minute = m_in_h;
		components->m_second = s_in_m;
		components->m_milli_second = ms_in_s;
	}
	else
	{
		components->m_year = 0;
		components->m_month = 0;
		components->m_day = 0;
		components->m_hour = 0;
		components->m_minute = 0;
		components->m_second = 0;
		components->m_milli_second = 0;
	}
}

mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_iip_cp_helper_time_to_text_fmt[] = "0000-00-00 00:00:00.000";

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_time_to_text(mk_sl_cui_uint64_pct const time, mk_lang_types_pchar_pt const strbuf, mk_lang_types_sint_t const strlen, mk_lang_types_sint_pt const outlen) mk_lang_noexcept
{
	mk_iip_cp_helper_time_components_t components mk_lang_constexpr_init;
	mk_lang_types_pchar_t buf[4] mk_lang_constexpr_init;
	mk_sl_cui_uint16_t ta mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(time);
	mk_lang_assert(strbuf || strlen == 0);
	mk_lang_assert(strlen >= 0);
	mk_lang_assert(outlen);

	if(strlen >= 23)
	{
		mk_iip_cp_helper_time_to_components(time, &components);
		mk_lang_string_memcpy_pc_fn(&strbuf[0], &mk_iip_cp_helper_time_to_text_fmt[0], mk_lang_countstr(mk_iip_cp_helper_time_to_text_fmt));
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_year)        ; len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_string_memcpy_pc_fn(&strbuf[ 0 + 4 - len], &buf[0], len);
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_month)       ; len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_string_memcpy_pc_fn(&strbuf[ 5 + 2 - len], &buf[0], len);
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_day)         ; len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_string_memcpy_pc_fn(&strbuf[ 8 + 2 - len], &buf[0], len);
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_hour)        ; len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_string_memcpy_pc_fn(&strbuf[11 + 2 - len], &buf[0], len);
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_minute)      ; len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_string_memcpy_pc_fn(&strbuf[14 + 2 - len], &buf[0], len);
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_second)      ; len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_string_memcpy_pc_fn(&strbuf[17 + 2 - len], &buf[0], len);
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_milli_second); len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_string_memcpy_pc_fn(&strbuf[20 + 3 - len], &buf[0], len);
		*outlen = 23;
	}
	else
	{
		*outlen = 0;
	}
}

mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_generate_random_u32(mk_sl_cui_uint32_pt const u32) mk_lang_noexcept
{
	union mk_iip_cp_helper_generate_random_u32_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_sl_cui_uint32_sizebytes_v];
		mk_sl_cui_uint32_t m_u32;
	};
	typedef union mk_iip_cp_helper_generate_random_u32_data_u mk_iip_cp_helper_generate_random_u32_data_t;
	struct mk_iip_cp_helper_generate_random_u32_s
	{
		mk_iip_cp_helper_generate_random_u32_data_t m_data;
	};
	typedef struct mk_iip_cp_helper_generate_random_u32_s mk_iip_cp_helper_generate_random_u32_t;

	mk_iip_cp_helper_generate_random_u32_t storage;

	mk_lang_assert(u32);

	do
	{
		storage.m_data.m_uchars[0] = ((mk_lang_types_uchar_t)(((mk_lang_types_uint_t)(rand())) & ((mk_lang_types_uint_t)(0xff))));
		storage.m_data.m_uchars[1] = ((mk_lang_types_uchar_t)(((mk_lang_types_uint_t)(rand())) & ((mk_lang_types_uint_t)(0xff))));
		storage.m_data.m_uchars[2] = ((mk_lang_types_uchar_t)(((mk_lang_types_uint_t)(rand())) & ((mk_lang_types_uint_t)(0xff))));
		storage.m_data.m_uchars[3] = ((mk_lang_types_uchar_t)(((mk_lang_types_uint_t)(rand())) & ((mk_lang_types_uint_t)(0xff))));
		mk_sl_cui_uint32_from_buis_uchar_le(u32, &storage.m_data.m_uchars[0]);
	}while(mk_sl_cui_uint32_is_zero(u32) || mk_sl_cui_uint32_is_max(u32));
}

mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_generate_random_u32_non_zero(mk_sl_cui_uint32_pt const u32) mk_lang_noexcept
{
	mk_lang_assert(u32);

	do
	{
		mk_iip_cp_helper_generate_random_u32(u32);
	}while(mk_sl_cui_uint32_is_zero(u32));
}

mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_generate_random_u8s(mk_sl_cui_uint8_pt const u8s, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_uchar_t tuc;

	mk_lang_assert(u8s || len == 0);
	mk_lang_assert(len >= 0);

	n = len;
	for(i = 0; i != n; ++i)
	{
		tuc = ((mk_lang_types_uchar_t)(((mk_lang_types_uint_t)(rand())) & ((mk_lang_types_uint_t)(0xff))));
		mk_sl_cui_uint8_from_bi_uchar(&u8s[i], &tuc);
	}
}

mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_generate_random_uchars(mk_lang_types_uchar_pt const ucs, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(ucs || len == 0);
	mk_lang_assert(len >= 0);

	n = len;
	for(i = 0; i != n; ++i)
	{
		ucs[i] = ((mk_lang_types_uchar_t)(((mk_lang_types_uint_t)(rand())) & ((mk_lang_types_uint_t)(0xff))));
	}
}

mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_get_time_now(mk_sl_cui_uint64_pt const time) mk_lang_noexcept
{
	mk_lang_types_ulong_t tul;
	mk_sl_cui_uint64_t tu64a;
	mk_sl_cui_uint64_t tu64b;
	mk_win_kernel_time_file_time_t file_time;
	mk_lang_types_uint_t tuis[2];

	mk_lang_assert(time);

	tul = 116444736ul; mk_sl_cui_uint64_from_bi_ulong(&tu64a, &tul);
	tul = 1000000000ul; mk_sl_cui_uint64_from_bi_ulong(&tu64b, &tul);
	mk_sl_cui_uint64_mul2_wrap_lo(&tu64a, &tu64b);
	mk_win_kernel_time_get_system_time_precise_as_file_time(&file_time);
	tuis[0] = ((mk_lang_types_uint_t)(file_time.m_lo));
	tuis[1] = ((mk_lang_types_uint_t)(file_time.m_hi));
	mk_sl_cui_uint64_from_buis_uint_le(&tu64b, &tuis[0]);
	mk_sl_cui_uint64_sub2_wrap_cid_cod(&tu64b, &tu64a);
	tul = 10000ul; mk_sl_cui_uint64_from_bi_ulong(&tu64a, &tul);
	mk_sl_cui_uint64_div3_wrap(&tu64b, &tu64a, time);
}


#define mk_sl_cui_t_name mk_iip_cp_helper_cui_elgamal_single
#define mk_sl_cui_t_base mk_iip_cp_helper_bui
#define mk_sl_cui_t_count ((256 * mk_lang_charbit) / mk_iip_cp_helper_bui_sizebits_d)
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"

#define mk_sl_cui_t_name mk_iip_cp_helper_cui_elgamal_double
#define mk_sl_cui_t_base mk_iip_cp_helper_bui
#define mk_sl_cui_t_count (((256 * mk_lang_charbit) / mk_iip_cp_helper_bui_sizebits_d) * 2)
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"

#define mk_sl_cui_t_name mk_iip_cp_helper_cui_dsa_pri_single
#define mk_sl_cui_t_base mk_iip_cp_helper_bui
#define mk_sl_cui_t_count ((20 * mk_lang_charbit) / mk_iip_cp_helper_bui_sizebits_d)
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"

#define mk_sl_cui_t_name mk_iip_cp_helper_cui_dsa_pri_double
#define mk_sl_cui_t_base mk_iip_cp_helper_bui
#define mk_sl_cui_t_count (((20 * mk_lang_charbit) / mk_iip_cp_helper_bui_sizebits_d) * 2)
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"

#define mk_sl_cui_t_name mk_iip_cp_helper_cui_dsa_pub_single
#define mk_sl_cui_t_base mk_iip_cp_helper_bui
#define mk_sl_cui_t_count ((128 * mk_lang_charbit) / mk_iip_cp_helper_bui_sizebits_d)
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"

#define mk_sl_cui_t_name mk_iip_cp_helper_cui_dsa_pub_double
#define mk_sl_cui_t_base mk_iip_cp_helper_bui
#define mk_sl_cui_t_count (((128 * mk_lang_charbit) / mk_iip_cp_helper_bui_sizebits_d) * 2)
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"


union mk_iip_cp_helper_elgamal_uchars_data_u
{
	mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_elgamal_single_sizebytes_v];
	mk_iip_cp_helper_cui_elgamal_single_t m_align;
};
typedef union mk_iip_cp_helper_elgamal_uchars_data_u mk_iip_cp_helper_elgamal_uchars_data_t;
struct mk_iip_cp_helper_elgamal_uchars_s
{
	mk_iip_cp_helper_elgamal_uchars_data_t m_data;
};
typedef struct mk_iip_cp_helper_elgamal_uchars_s mk_iip_cp_helper_elgamal_uchars_t;

union mk_iip_cp_helper_dsa_pri_uchars_data_u
{
	mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_dsa_pri_single_sizebytes_v];
	mk_iip_cp_helper_cui_dsa_pri_single_t m_align;
};
typedef union mk_iip_cp_helper_dsa_pri_uchars_data_u mk_iip_cp_helper_dsa_pri_uchars_data_t;
struct mk_iip_cp_helper_dsa_pri_uchars_s
{
	mk_iip_cp_helper_dsa_pri_uchars_data_t m_data;
};
typedef struct mk_iip_cp_helper_dsa_pri_uchars_s mk_iip_cp_helper_dsa_pri_uchars_t;

union mk_iip_cp_helper_dsa_pub_uchars_data_u
{
	mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_dsa_pub_single_sizebytes_v];
	mk_iip_cp_helper_cui_dsa_pub_single_t m_align;
};
typedef union mk_iip_cp_helper_dsa_pub_uchars_data_u mk_iip_cp_helper_dsa_pub_uchars_data_t;
struct mk_iip_cp_helper_dsa_pub_uchars_s
{
	mk_iip_cp_helper_dsa_pub_uchars_data_t m_data;
};
typedef struct mk_iip_cp_helper_dsa_pub_uchars_s mk_iip_cp_helper_dsa_pub_uchars_t;


mk_lang_constexpr_static_inline mk_iip_cp_helper_elgamal_uchars_t const mk_iip_cp_helper_elgamal_constant_p =
{{{
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc9, 0x0f, 0xda, 0xa2, 0x21, 0x68, 0xc2, 0x34,
	0xc4, 0xc6, 0x62, 0x8b, 0x80, 0xdc, 0x1c, 0xd1, 0x29, 0x02, 0x4e, 0x08, 0x8a, 0x67, 0xcc, 0x74,
	0x02, 0x0b, 0xbe, 0xa6, 0x3b, 0x13, 0x9b, 0x22, 0x51, 0x4a, 0x08, 0x79, 0x8e, 0x34, 0x04, 0xdd,
	0xef, 0x95, 0x19, 0xb3, 0xcd, 0x3a, 0x43, 0x1b, 0x30, 0x2b, 0x0a, 0x6d, 0xf2, 0x5f, 0x14, 0x37,
	0x4f, 0xe1, 0x35, 0x6d, 0x6d, 0x51, 0xc2, 0x45, 0xe4, 0x85, 0xb5, 0x76, 0x62, 0x5e, 0x7e, 0xc6,
	0xf4, 0x4c, 0x42, 0xe9, 0xa6, 0x37, 0xed, 0x6b, 0x0b, 0xff, 0x5c, 0xb6, 0xf4, 0x06, 0xb7, 0xed,
	0xee, 0x38, 0x6b, 0xfb, 0x5a, 0x89, 0x9f, 0xa5, 0xae, 0x9f, 0x24, 0x11, 0x7c, 0x4b, 0x1f, 0xe6,
	0x49, 0x28, 0x66, 0x51, 0xec, 0xe4, 0x5b, 0x3d, 0xc2, 0x00, 0x7c, 0xb8, 0xa1, 0x63, 0xbf, 0x05,
	0x98, 0xda, 0x48, 0x36, 0x1c, 0x55, 0xd3, 0x9a, 0x69, 0x16, 0x3f, 0xa8, 0xfd, 0x24, 0xcf, 0x5f,
	0x83, 0x65, 0x5d, 0x23, 0xdc, 0xa3, 0xad, 0x96, 0x1c, 0x62, 0xf3, 0x56, 0x20, 0x85, 0x52, 0xbb,
	0x9e, 0xd5, 0x29, 0x07, 0x70, 0x96, 0x96, 0x6d, 0x67, 0x0c, 0x35, 0x4e, 0x4a, 0xbc, 0x98, 0x04,
	0xf1, 0x74, 0x6c, 0x08, 0xca, 0x18, 0x21, 0x7c, 0x32, 0x90, 0x5e, 0x46, 0x2e, 0x36, 0xce, 0x3b,
	0xe3, 0x9e, 0x77, 0x2c, 0x18, 0x0e, 0x86, 0x03, 0x9b, 0x27, 0x83, 0xa2, 0xec, 0x07, 0xa2, 0x8f,
	0xb5, 0xc5, 0x5d, 0xf0, 0x6f, 0x4c, 0x52, 0xc9, 0xde, 0x2b, 0xcb, 0xf6, 0x95, 0x58, 0x17, 0x18,
	0x39, 0x95, 0x49, 0x7c, 0xea, 0x95, 0x6a, 0xe5, 0x15, 0xd2, 0x26, 0x18, 0x98, 0xfa, 0x05, 0x10,
	0x15, 0x72, 0x8e, 0x5a, 0x8a, 0xac, 0xaa, 0x68, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
}}};

mk_lang_constexpr_static_inline mk_iip_cp_helper_dsa_pri_uchars_t const mk_iip_cp_helper_dsa_pri_constant_q =
{{{
	0xa5, 0xdf, 0xc2, 0x8f, 0xef, 0x4c, 0xa1, 0xe2, 0x86, 0x74, 0x4c, 0xd8, 0xee, 0xd9, 0xd2, 0x9d, 0x68, 0x40, 0x46, 0xb7,
}}};

mk_lang_constexpr_static_inline mk_iip_cp_helper_dsa_pub_uchars_t const mk_iip_cp_helper_dsa_pub_constant_g =
{{{
	0x0c, 0x1f, 0x4d, 0x27, 0xd4, 0x00, 0x93, 0xb4, 0x29, 0xe9, 0x62, 0xd7, 0x22, 0x38, 0x24, 0xe0,
	0xbb, 0xc4, 0x7e, 0x7c, 0x83, 0x2a, 0x39, 0x23, 0x6f, 0xc6, 0x83, 0xaf, 0x84, 0x88, 0x95, 0x81,
	0x07, 0x5f, 0xf9, 0x08, 0x2e, 0xd3, 0x23, 0x53, 0xd4, 0x37, 0x4d, 0x73, 0x01, 0xcd, 0xa1, 0xd2,
	0x3c, 0x43, 0x1f, 0x46, 0x98, 0x59, 0x9d, 0xda, 0x02, 0x45, 0x18, 0x24, 0xff, 0x36, 0x97, 0x52,
	0x59, 0x36, 0x47, 0xcc, 0x3d, 0xdc, 0x19, 0x7d, 0xe9, 0x85, 0xe4, 0x3d, 0x13, 0x6c, 0xdc, 0xfc,
	0x6b, 0xd5, 0x40, 0x9c, 0xd2, 0xf4, 0x50, 0x82, 0x11, 0x42, 0xa5, 0xe6, 0xf8, 0xeb, 0x1c, 0x3a,
	0xb5, 0xd0, 0x48, 0x4b, 0x81, 0x29, 0xfc, 0xf1, 0x7b, 0xce, 0x4f, 0x7f, 0x33, 0x32, 0x1c, 0x3c,
	0xb3, 0xdb, 0xb1, 0x4a, 0x90, 0x5e, 0x7b, 0x2b, 0x3e, 0x93, 0xbe, 0x47, 0x08, 0xcb, 0xcc, 0x82,
}}};

mk_lang_constexpr_static_inline mk_iip_cp_helper_dsa_pub_uchars_t const mk_iip_cp_helper_dsa_pub_constant_p =
{{{
	0x9c, 0x05, 0xb2, 0xaa, 0x96, 0x0d, 0x9b, 0x97, 0xb8, 0x93, 0x19, 0x63, 0xc9, 0xcc, 0x9e, 0x8c,
	0x30, 0x26, 0xe9, 0xb8, 0xed, 0x92, 0xfa, 0xd0, 0xa6, 0x9c, 0xc8, 0x86, 0xd5, 0xbf, 0x80, 0x15,
	0xfc, 0xad, 0xae, 0x31, 0xa0, 0xad, 0x18, 0xfa, 0xb3, 0xf0, 0x1b, 0x00, 0xa3, 0x58, 0xde, 0x23,
	0x76, 0x55, 0xc4, 0x96, 0x4a, 0xfa, 0xa2, 0xb3, 0x37, 0xe9, 0x6a, 0xd3, 0x16, 0xb9, 0xfb, 0x1c,
	0xc5, 0x64, 0xb5, 0xae, 0xc5, 0xb6, 0x9a, 0x9f, 0xf6, 0xc3, 0xe4, 0x54, 0x87, 0x07, 0xfe, 0xf8,
	0x50, 0x3d, 0x91, 0xdd, 0x86, 0x02, 0xe8, 0x67, 0xe6, 0xd3, 0x5d, 0x22, 0x35, 0xc1, 0x86, 0x9c,
	0xe2, 0x47, 0x9c, 0x3b, 0x9d, 0x54, 0x01, 0xde, 0x04, 0xe0, 0x72, 0x7f, 0xb3, 0x3d, 0x65, 0x11,
	0x28, 0x5d, 0x4c, 0xf2, 0x95, 0x38, 0xd9, 0xe3, 0xb6, 0x05, 0x1f, 0x5b, 0x22, 0xcc, 0x1c, 0x93,
}}};


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_elgamal_single_load_p(mk_iip_cp_helper_cui_elgamal_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_iip_cp_helper_cui_elgamal_single_from_buis_uchar_be(x, &mk_iip_cp_helper_elgamal_constant_p.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_elgamal_single_to_double(mk_iip_cp_helper_cui_elgamal_single_pct const a, mk_iip_cp_helper_cui_elgamal_double_pt const b) mk_lang_noexcept
{
	union mk_iip_cp_helper_cui_elgamal_single_to_double_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_elgamal_double_sizebytes_v];
		mk_iip_cp_helper_cui_elgamal_single_t m_single;
		mk_iip_cp_helper_cui_elgamal_double_t m_double;
	};
	typedef union mk_iip_cp_helper_cui_elgamal_single_to_double_data_u mk_iip_cp_helper_cui_elgamal_single_to_double_data_t;
	struct mk_iip_cp_helper_cui_elgamal_single_to_double_s
	{
		mk_iip_cp_helper_cui_elgamal_single_to_double_data_t m_data;
	};
	typedef struct mk_iip_cp_helper_cui_elgamal_single_to_double_s mk_iip_cp_helper_cui_elgamal_single_to_double_t;

	mk_lang_types_uchar_t zero mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_elgamal_single_to_double_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_iip_cp_helper_cui_elgamal_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	zero = 0; mk_lang_string_memset_uc_fn(&storage.m_data.m_uchars[mk_iip_cp_helper_cui_elgamal_single_sizebytes_v], &zero, ((mk_lang_types_sint_t)(mk_iip_cp_helper_cui_elgamal_double_sizebytes_v)) - ((mk_lang_types_sint_t)(mk_iip_cp_helper_cui_elgamal_single_sizebytes_v)));
	mk_iip_cp_helper_cui_elgamal_double_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_elgamal_double_to_single(mk_iip_cp_helper_cui_elgamal_double_pct const a, mk_iip_cp_helper_cui_elgamal_single_pt const b) mk_lang_noexcept
{
	union mk_iip_cp_helper_cui_elgamal_double_to_single_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_elgamal_double_sizebytes_v];
		mk_iip_cp_helper_cui_elgamal_double_t m_double;
		mk_iip_cp_helper_cui_elgamal_single_t m_single;
	};
	typedef union mk_iip_cp_helper_cui_elgamal_double_to_single_data_u mk_iip_cp_helper_cui_elgamal_double_to_single_data_t;
	struct mk_iip_cp_helper_cui_elgamal_double_to_single_s
	{
		mk_iip_cp_helper_cui_elgamal_double_to_single_data_t m_data;
	};
	typedef struct mk_iip_cp_helper_cui_elgamal_double_to_single_s mk_iip_cp_helper_cui_elgamal_double_to_single_t;

	mk_iip_cp_helper_cui_elgamal_double_to_single_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_iip_cp_helper_cui_elgamal_double_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_iip_cp_helper_cui_elgamal_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_elgamal_single_mod_pow(mk_iip_cp_helper_cui_elgamal_single_prct const base, mk_iip_cp_helper_cui_elgamal_single_prct const exponent, mk_iip_cp_helper_cui_elgamal_single_prct const modulus, mk_iip_cp_helper_cui_elgamal_single_prt const result) mk_lang_noexcept
{
	mk_iip_cp_helper_cui_elgamal_double_t dbase mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_elgamal_double_t dmodulus mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_elgamal_double_t dresult mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_elgamal_single_t sexponent mk_lang_constexpr_init;

	mk_lang_assert(base);
	mk_lang_assert(exponent);
	mk_lang_assert(modulus);
	mk_lang_assert(result);
	mk_lang_assert(base != exponent);
	mk_lang_assert(base != modulus);
	mk_lang_assert(base != result);
	mk_lang_assert(exponent != modulus);
	mk_lang_assert(exponent != result);
	mk_lang_assert(modulus != result);

	mk_iip_cp_helper_cui_elgamal_single_to_double(base, &dbase);
	mk_iip_cp_helper_cui_elgamal_single_to_double(modulus, &dmodulus);
	mk_iip_cp_helper_cui_elgamal_double_set_one(&dresult);
	mk_iip_cp_helper_cui_elgamal_single_assign(&sexponent, exponent);
	while(!mk_iip_cp_helper_cui_elgamal_single_is_zero(&sexponent))
	{
		if(mk_iip_cp_helper_cui_elgamal_single_has_lsb(&sexponent))
		{
			mk_iip_cp_helper_cui_elgamal_double_mul2_wrap_lo(&dresult, &dbase);
			mk_iip_cp_helper_cui_elgamal_double_mod2_wrap(&dresult, &dmodulus);
		}
		mk_iip_cp_helper_cui_elgamal_single_shr2(&sexponent, 1);
		mk_iip_cp_helper_cui_elgamal_double_mul2_wrap_lo(&dbase, &dbase);
		mk_iip_cp_helper_cui_elgamal_double_mod2_wrap(&dbase, &dmodulus);
	}
	mk_iip_cp_helper_cui_elgamal_double_to_single(&dresult, result);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_elgamal_double_load_p(mk_iip_cp_helper_cui_elgamal_double_pt const x) mk_lang_noexcept
{
	mk_iip_cp_helper_cui_elgamal_single_t elgamal_single mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_iip_cp_helper_cui_elgamal_single_load_p(&elgamal_single);
	mk_iip_cp_helper_cui_elgamal_single_to_double(&elgamal_single, x);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pri_single_load_q(mk_iip_cp_helper_cui_dsa_pri_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_iip_cp_helper_cui_dsa_pri_single_from_buis_uchar_be(x, &mk_iip_cp_helper_dsa_pri_constant_q.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pri_single_from_u8s_be(mk_iip_cp_helper_cui_dsa_pri_single_pt const x, mk_sl_cui_uint8_pct const u8s) mk_lang_noexcept
{
	union mk_iip_cp_helper_cui_dsa_pri_single_from_u8s_be_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_dsa_pri_single_sizebytes_v];
		mk_iip_cp_helper_cui_dsa_pri_single_t m_dsa_pri_cui_single;
	};
	typedef union mk_iip_cp_helper_cui_dsa_pri_single_from_u8s_be_data_u mk_iip_cp_helper_cui_dsa_pri_single_from_u8s_be_data_t;
	struct mk_iip_cp_helper_cui_dsa_pri_single_from_u8s_be_s
	{
		mk_iip_cp_helper_cui_dsa_pri_single_from_u8s_be_data_t m_data;
	};
	typedef struct mk_iip_cp_helper_cui_dsa_pri_single_from_u8s_be_s mk_iip_cp_helper_cui_dsa_pri_single_from_u8s_be_t;

	mk_iip_cp_helper_cui_dsa_pri_single_from_u8s_be_t storage mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(u8s);

	mk_iip_cp_helper_u8s_to_uchars(&u8s[0], &storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars));
	mk_iip_cp_helper_cui_dsa_pri_single_from_buis_uchar_be(x, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pri_single_to_double(mk_iip_cp_helper_cui_dsa_pri_single_pct const a, mk_iip_cp_helper_cui_dsa_pri_double_pt const b) mk_lang_noexcept
{
	union mk_iip_cp_helper_cui_dsa_pri_single_to_double_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_dsa_pri_double_sizebytes_v];
		mk_iip_cp_helper_cui_dsa_pri_single_t m_single;
		mk_iip_cp_helper_cui_dsa_pri_double_t m_double;
	};
	typedef union mk_iip_cp_helper_cui_dsa_pri_single_to_double_data_u mk_iip_cp_helper_cui_dsa_pri_single_to_double_data_t;
	struct mk_iip_cp_helper_cui_dsa_pri_single_to_double_s
	{
		mk_iip_cp_helper_cui_dsa_pri_single_to_double_data_t m_data;
	};
	typedef struct mk_iip_cp_helper_cui_dsa_pri_single_to_double_s mk_iip_cp_helper_cui_dsa_pri_single_to_double_t;

	mk_lang_types_uchar_t zero mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_to_double_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_iip_cp_helper_cui_dsa_pri_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	zero = 0; mk_lang_string_memset_uc_fn(&storage.m_data.m_uchars[mk_iip_cp_helper_cui_dsa_pri_single_sizebytes_v], &zero, ((mk_lang_types_sint_t)(mk_iip_cp_helper_cui_dsa_pri_double_sizebytes_v)) - ((mk_lang_types_sint_t)(mk_iip_cp_helper_cui_dsa_pri_single_sizebytes_v)));
	mk_iip_cp_helper_cui_dsa_pri_double_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pri_single_to_pub_double(mk_iip_cp_helper_cui_dsa_pri_single_pct const a, mk_iip_cp_helper_cui_dsa_pub_double_pt const b) mk_lang_noexcept
{
	union mk_iip_cp_helper_cui_dsa_pri_single_to_pub_double_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_dsa_pub_double_sizebytes_v];
		mk_iip_cp_helper_cui_dsa_pri_single_t m_pri_single;
		mk_iip_cp_helper_cui_dsa_pub_double_t m_pub_double;
	};
	typedef union mk_iip_cp_helper_cui_dsa_pri_single_to_pub_double_data_u mk_iip_cp_helper_cui_dsa_pri_single_to_pub_double_data_t;
	struct mk_iip_cp_helper_cui_dsa_pri_single_to_pub_double_s
	{
		mk_iip_cp_helper_cui_dsa_pri_single_to_pub_double_data_t m_data;
	};
	typedef struct mk_iip_cp_helper_cui_dsa_pri_single_to_pub_double_s mk_iip_cp_helper_cui_dsa_pri_single_to_pub_double_t;

	mk_lang_types_uchar_t zero mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_to_pub_double_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_iip_cp_helper_cui_dsa_pri_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	zero = 0; mk_lang_string_memset_uc_fn(&storage.m_data.m_uchars[mk_iip_cp_helper_cui_dsa_pri_single_sizebytes_v], &zero, ((mk_lang_types_sint_t)(mk_iip_cp_helper_cui_dsa_pub_double_sizebytes_v)) - ((mk_lang_types_sint_t)(mk_iip_cp_helper_cui_dsa_pri_single_sizebytes_v)));
	mk_iip_cp_helper_cui_dsa_pub_double_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pri_single_mod_mul3_wrap_lo(mk_iip_cp_helper_cui_dsa_pri_single_prct const m, mk_iip_cp_helper_cui_dsa_pri_single_prct const a, mk_iip_cp_helper_cui_dsa_pri_single_prct const b, mk_iip_cp_helper_cui_dsa_pri_single_prt const c) mk_lang_noexcept
{
	mk_iip_cp_helper_cui_dsa_pri_double_t mm mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_double_t aa mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_double_t bb mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_double_t cc mk_lang_constexpr_init;

	mk_lang_assert(m);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(m != a);
	mk_lang_assert(m != b);
	mk_lang_assert(m != c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);

	mk_iip_cp_helper_cui_dsa_pri_single_to_double(m, &mm);
	mk_iip_cp_helper_cui_dsa_pri_single_to_double(a, &aa);
	mk_iip_cp_helper_cui_dsa_pri_single_to_double(b, &bb);
	mk_iip_cp_helper_cui_dsa_pri_double_mul3_wrap_lo(&aa, &bb, &cc);
	mk_iip_cp_helper_cui_dsa_pri_double_mod2_wrap(&cc, &mm);
	mk_iip_cp_helper_cui_dsa_pri_double_to_single(&cc, c);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pri_single_mod_add2_wrap_cid_cod(mk_iip_cp_helper_cui_dsa_pri_single_prct const m, mk_iip_cp_helper_cui_dsa_pri_single_prt const a, mk_iip_cp_helper_cui_dsa_pri_single_prct const b) mk_lang_noexcept
{
	mk_iip_cp_helper_cui_dsa_pri_double_t mm mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_double_t aa mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_double_t bb mk_lang_constexpr_init;

	mk_lang_assert(m);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(m != a);
	mk_lang_assert(m != b);
	mk_lang_assert(a != b);

	mk_iip_cp_helper_cui_dsa_pri_single_to_double(m, &mm);
	mk_iip_cp_helper_cui_dsa_pri_single_to_double(a, &aa);
	mk_iip_cp_helper_cui_dsa_pri_single_to_double(b, &bb);
	mk_iip_cp_helper_cui_dsa_pri_double_add2_wrap_cid_cod(&aa, &bb);
	mk_iip_cp_helper_cui_dsa_pri_double_mod2_wrap(&aa, &mm);
	mk_iip_cp_helper_cui_dsa_pri_double_to_single(&aa, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pri_single_mod_mul2_wrap_lo(mk_iip_cp_helper_cui_dsa_pri_single_prct const m, mk_iip_cp_helper_cui_dsa_pri_single_prt const a, mk_iip_cp_helper_cui_dsa_pri_single_prct const b) mk_lang_noexcept
{
	mk_iip_cp_helper_cui_dsa_pri_double_t mm mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_double_t aa mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_double_t bb mk_lang_constexpr_init;

	mk_lang_assert(m);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(m != a);
	mk_lang_assert(m != b);
	mk_lang_assert(a != b);

	mk_iip_cp_helper_cui_dsa_pri_single_to_double(m, &mm);
	mk_iip_cp_helper_cui_dsa_pri_single_to_double(a, &aa);
	mk_iip_cp_helper_cui_dsa_pri_single_to_double(b, &bb);
	mk_iip_cp_helper_cui_dsa_pri_double_mul2_wrap_lo(&aa, &bb);
	mk_iip_cp_helper_cui_dsa_pri_double_mod2_wrap(&aa, &mm);
	mk_iip_cp_helper_cui_dsa_pri_double_to_single(&aa, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pri_double_to_single(mk_iip_cp_helper_cui_dsa_pri_double_pct const a, mk_iip_cp_helper_cui_dsa_pri_single_pt const b) mk_lang_noexcept
{
	union mk_iip_cp_helper_cui_dsa_pri_double_to_single_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_dsa_pri_double_sizebytes_v];
		mk_iip_cp_helper_cui_dsa_pri_double_t m_double;
		mk_iip_cp_helper_cui_dsa_pri_single_t m_single;
	};
	typedef union mk_iip_cp_helper_cui_dsa_pri_double_to_single_data_u mk_iip_cp_helper_cui_dsa_pri_double_to_single_data_t;
	struct mk_iip_cp_helper_cui_dsa_pri_double_to_single_s
	{
		mk_iip_cp_helper_cui_dsa_pri_double_to_single_data_t m_data;
	};
	typedef struct mk_iip_cp_helper_cui_dsa_pri_double_to_single_s mk_iip_cp_helper_cui_dsa_pri_double_to_single_t;

	mk_iip_cp_helper_cui_dsa_pri_double_to_single_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_iip_cp_helper_cui_dsa_pri_double_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_iip_cp_helper_cui_dsa_pri_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pri_single_to_pub_single(mk_iip_cp_helper_cui_dsa_pri_single_pct const a, mk_iip_cp_helper_cui_dsa_pub_single_pt const b) mk_lang_noexcept
{
	union mk_iip_cp_helper_cui_dsa_pri_single_to_pub_single_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_dsa_pub_single_sizebytes_v];
		mk_iip_cp_helper_cui_dsa_pri_single_t m_pri_single;
		mk_iip_cp_helper_cui_dsa_pub_single_t m_pub_single;
	};
	typedef union mk_iip_cp_helper_cui_dsa_pri_single_to_pub_single_data_u mk_iip_cp_helper_cui_dsa_pri_single_to_pub_single_data_t;
	struct mk_iip_cp_helper_cui_dsa_pri_single_to_pub_single_s
	{
		mk_iip_cp_helper_cui_dsa_pri_single_to_pub_single_data_t m_data;
	};
	typedef struct mk_iip_cp_helper_cui_dsa_pri_single_to_pub_single_s mk_iip_cp_helper_cui_dsa_pri_single_to_pub_single_t;

	mk_lang_types_uchar_t zero mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_to_pub_single_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_iip_cp_helper_cui_dsa_pri_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	zero = 0; mk_lang_string_memset_uc_fn(&storage.m_data.m_uchars[mk_iip_cp_helper_cui_dsa_pri_single_sizebytes_v], &zero, ((mk_lang_types_sint_t)(mk_iip_cp_helper_cui_dsa_pub_single_sizebytes_v)) - ((mk_lang_types_sint_t)(mk_iip_cp_helper_cui_dsa_pri_single_sizebytes_v)));
	mk_iip_cp_helper_cui_dsa_pub_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_helper_cui_dsa_pri_single_is_negative(mk_iip_cp_helper_cui_dsa_pri_single_pct const x) mk_lang_noexcept
{
	mk_iip_cp_helper_cui_dsa_pri_single_t ta mk_lang_constexpr_init;
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_iip_cp_helper_cui_dsa_pri_single_shr3(x, mk_iip_cp_helper_cui_dsa_pri_single_sizebits_v - 1, &ta);
	ret = !mk_iip_cp_helper_cui_dsa_pri_single_is_zero(&ta);
	return ret;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pri_single_flip_sign_1(mk_iip_cp_helper_cui_dsa_pri_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_iip_cp_helper_cui_dsa_pri_single_not1(x);
	mk_iip_cp_helper_cui_dsa_pri_single_inc1(x);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pri_single_gcd(mk_iip_cp_helper_cui_dsa_pri_single_prct const a, mk_iip_cp_helper_cui_dsa_pri_single_prct const b, mk_iip_cp_helper_cui_dsa_pri_single_prt const c) mk_lang_noexcept
{
	mk_iip_cp_helper_cui_dsa_pri_single_t ta mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_t tb mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_t tc mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_pt pa mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_pt pb mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_pt pc mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_pt qa mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_pt qb mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_pt qc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);

	ta = *a;
	tb = *b;
	pa = &ta;
	pb = &tb;
	pc = &tc;
	while(!mk_iip_cp_helper_cui_dsa_pri_single_is_zero(pb))
	{
		mk_iip_cp_helper_cui_dsa_pri_single_mod3_wrap(pa, pb, pc);
		qa = pa;
		qb = pb;
		qc = pc;
		pa = qb;
		pb = qc;
		pc = qa;
	}
	*c = *pa;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pri_single_mul3_signed(mk_iip_cp_helper_cui_dsa_pri_single_prct const a, mk_iip_cp_helper_cui_dsa_pri_single_prct const b, mk_iip_cp_helper_cui_dsa_pri_single_prt const c) mk_lang_noexcept
{
	mk_iip_cp_helper_cui_dsa_pri_single_t ta mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_t tb mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_t tc mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);

	ta = *a;
	tb = *b;
	ba = mk_iip_cp_helper_cui_dsa_pri_single_is_negative(&ta);
	bb = mk_iip_cp_helper_cui_dsa_pri_single_is_negative(&tb);
	if(ba){ mk_iip_cp_helper_cui_dsa_pri_single_flip_sign_1(&ta); }
	if(bb){ mk_iip_cp_helper_cui_dsa_pri_single_flip_sign_1(&tb); }
	mk_iip_cp_helper_cui_dsa_pri_single_mul3_wrap_lo(&ta, &tb, &tc);
	if((ba && !bb) || (!ba && bb)){ mk_iip_cp_helper_cui_dsa_pri_single_flip_sign_1(&tc); }
	*c = tc;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pri_single_mod_inv(mk_iip_cp_helper_cui_dsa_pri_single_pct const a, mk_iip_cp_helper_cui_dsa_pri_single_pct const modulus, mk_iip_cp_helper_cui_dsa_pri_single_pt const res_out) mk_lang_noexcept
{
	mk_iip_cp_helper_cui_dsa_pri_single_t mz mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_t y mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_t x mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_t one mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_t aa mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_t mm mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_t q mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_t t mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_t ta mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(modulus);
	mk_lang_assert(res_out);
	mk_lang_assert((mk_iip_cp_helper_cui_dsa_pri_single_gcd(a, modulus, &aa), mk_iip_cp_helper_cui_dsa_pri_single_is_one(&aa)));

	mz = *modulus;
	mk_iip_cp_helper_cui_dsa_pri_single_set_zero(&y);
	mk_iip_cp_helper_cui_dsa_pri_single_set_one(&x);
	if(mk_iip_cp_helper_cui_dsa_pri_single_is_one(&mz))
	{
		mk_iip_cp_helper_cui_dsa_pri_single_set_zero(res_out);
	}
	else
	{
		mk_iip_cp_helper_cui_dsa_pri_single_set_one(&one);
		aa = *a;
		mm = *modulus;
		while(mk_iip_cp_helper_cui_dsa_pri_single_gt(&aa, &one))
		{
			mk_iip_cp_helper_cui_dsa_pri_single_div3_wrap(&aa, &mm, &q);
			mk_iip_cp_helper_cui_dsa_pri_single_mod3_wrap(&aa, &mm, &ta);
			aa = mm;
			mm = ta;
			t = y;
			mk_iip_cp_helper_cui_dsa_pri_single_mul3_signed(&q, &y, &ta);
			mk_iip_cp_helper_cui_dsa_pri_single_sub3_wrap_cid_cod(&x, &ta, &y);
			x = t;
		}
		if(mk_iip_cp_helper_cui_dsa_pri_single_is_negative(&x))
		{
			mk_iip_cp_helper_cui_dsa_pri_single_add2_wrap_cid_cod(&x, &mz);
		}
		*res_out = x;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pri_double_load_q(mk_iip_cp_helper_cui_dsa_pri_double_pt const x) mk_lang_noexcept
{
	mk_iip_cp_helper_cui_dsa_pri_single_t dsa_pri_single mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_iip_cp_helper_cui_dsa_pri_single_load_q(&dsa_pri_single);
	mk_iip_cp_helper_cui_dsa_pri_single_to_double(&dsa_pri_single, x);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pub_single_load_g(mk_iip_cp_helper_cui_dsa_pub_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_iip_cp_helper_cui_dsa_pub_single_from_buis_uchar_be(x, &mk_iip_cp_helper_dsa_pub_constant_g.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pub_single_load_p(mk_iip_cp_helper_cui_dsa_pub_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_iip_cp_helper_cui_dsa_pub_single_from_buis_uchar_be(x, &mk_iip_cp_helper_dsa_pub_constant_p.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pub_single_to_double(mk_iip_cp_helper_cui_dsa_pub_single_pct const a, mk_iip_cp_helper_cui_dsa_pub_double_pt const b) mk_lang_noexcept
{
	union mk_iip_cp_helper_cui_dsa_pub_single_to_double_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_dsa_pub_double_sizebytes_v];
		mk_iip_cp_helper_cui_dsa_pub_single_t m_single;
		mk_iip_cp_helper_cui_dsa_pub_double_t m_double;
	};
	typedef union mk_iip_cp_helper_cui_dsa_pub_single_to_double_data_u mk_iip_cp_helper_cui_dsa_pub_single_to_double_data_t;
	struct mk_iip_cp_helper_cui_dsa_pub_single_to_double_s
	{
		mk_iip_cp_helper_cui_dsa_pub_single_to_double_data_t m_data;
	};
	typedef struct mk_iip_cp_helper_cui_dsa_pub_single_to_double_s mk_iip_cp_helper_cui_dsa_pub_single_to_double_t;

	mk_lang_types_uchar_t zero mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pub_single_to_double_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_iip_cp_helper_cui_dsa_pub_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	zero = 0; mk_lang_string_memset_uc_fn(&storage.m_data.m_uchars[mk_iip_cp_helper_cui_dsa_pub_single_sizebytes_v], &zero, ((mk_lang_types_sint_t)(mk_iip_cp_helper_cui_dsa_pub_double_sizebytes_v)) - ((mk_lang_types_sint_t)(mk_iip_cp_helper_cui_dsa_pub_single_sizebytes_v)));
	mk_iip_cp_helper_cui_dsa_pub_double_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pub_single_to_pri_single(mk_iip_cp_helper_cui_dsa_pub_single_pct const a, mk_iip_cp_helper_cui_dsa_pri_single_pt const b) mk_lang_noexcept
{
	union mk_iip_cp_helper_cui_dsa_pub_single_to_pri_single_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_dsa_pub_single_sizebytes_v];
		mk_iip_cp_helper_cui_dsa_pub_single_t m_pub_single;
		mk_iip_cp_helper_cui_dsa_pri_single_t m_pri_single;
	};
	typedef union mk_iip_cp_helper_cui_dsa_pub_single_to_pri_single_data_u mk_iip_cp_helper_cui_dsa_pub_single_to_pri_single_data_t;
	struct mk_iip_cp_helper_cui_dsa_pub_single_to_pri_single_s
	{
		mk_iip_cp_helper_cui_dsa_pub_single_to_pri_single_data_t m_data;
	};
	typedef struct mk_iip_cp_helper_cui_dsa_pub_single_to_pri_single_s mk_iip_cp_helper_cui_dsa_pub_single_to_pri_single_t;

	mk_iip_cp_helper_cui_dsa_pub_single_to_pri_single_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_iip_cp_helper_cui_dsa_pub_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_iip_cp_helper_cui_dsa_pri_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pub_double_to_single(mk_iip_cp_helper_cui_dsa_pub_double_pct const a, mk_iip_cp_helper_cui_dsa_pub_single_pt const b) mk_lang_noexcept
{
	union mk_iip_cp_helper_cui_dsa_pub_double_to_single_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_dsa_pub_double_sizebytes_v];
		mk_iip_cp_helper_cui_dsa_pub_double_t m_double;
		mk_iip_cp_helper_cui_dsa_pub_single_t m_single;
	};
	typedef union mk_iip_cp_helper_cui_dsa_pub_double_to_single_data_u mk_iip_cp_helper_cui_dsa_pub_double_to_single_data_t;
	struct mk_iip_cp_helper_cui_dsa_pub_double_to_single_s
	{
		mk_iip_cp_helper_cui_dsa_pub_double_to_single_data_t m_data;
	};
	typedef struct mk_iip_cp_helper_cui_dsa_pub_double_to_single_s mk_iip_cp_helper_cui_dsa_pub_double_to_single_t;

	mk_iip_cp_helper_cui_dsa_pub_double_to_single_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_iip_cp_helper_cui_dsa_pub_double_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_iip_cp_helper_cui_dsa_pub_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pub_double_to_pri_single(mk_iip_cp_helper_cui_dsa_pub_double_pct const a, mk_iip_cp_helper_cui_dsa_pri_single_pt const b) mk_lang_noexcept
{
	union mk_iip_cp_helper_cui_dsa_pub_double_to_pri_single_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_dsa_pub_double_sizebytes_v];
		mk_iip_cp_helper_cui_dsa_pub_double_t m_pub_double;
		mk_iip_cp_helper_cui_dsa_pri_single_t m_pri_single;
	};
	typedef union mk_iip_cp_helper_cui_dsa_pub_double_to_pri_single_data_u mk_iip_cp_helper_cui_dsa_pub_double_to_pri_single_data_t;
	struct mk_iip_cp_helper_cui_dsa_pub_double_to_pri_single_s
	{
		mk_iip_cp_helper_cui_dsa_pub_double_to_pri_single_data_t m_data;
	};
	typedef struct mk_iip_cp_helper_cui_dsa_pub_double_to_pri_single_s mk_iip_cp_helper_cui_dsa_pub_double_to_pri_single_t;

	mk_iip_cp_helper_cui_dsa_pub_double_to_pri_single_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_iip_cp_helper_cui_dsa_pub_double_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_iip_cp_helper_cui_dsa_pri_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pub_single_mod_pow_a(mk_iip_cp_helper_cui_dsa_pub_single_prct const base, mk_iip_cp_helper_cui_dsa_pub_single_prct const exponent, mk_iip_cp_helper_cui_dsa_pub_single_prct const modulus, mk_iip_cp_helper_cui_dsa_pub_single_prt const result) mk_lang_noexcept
{
	mk_iip_cp_helper_cui_dsa_pub_double_t dbase mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pub_double_t dmodulus mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pub_double_t dresult mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pub_single_t sexponent mk_lang_constexpr_init;

	mk_lang_assert(base);
	mk_lang_assert(exponent);
	mk_lang_assert(modulus);
	mk_lang_assert(result);
	mk_lang_assert(base != exponent);
	mk_lang_assert(base != modulus);
	mk_lang_assert(base != result);
	mk_lang_assert(exponent != modulus);
	mk_lang_assert(exponent != result);
	mk_lang_assert(modulus != result);

	mk_iip_cp_helper_cui_dsa_pub_single_to_double(base, &dbase);
	mk_iip_cp_helper_cui_dsa_pub_single_to_double(modulus, &dmodulus);
	mk_iip_cp_helper_cui_dsa_pub_double_set_one(&dresult);
	mk_iip_cp_helper_cui_dsa_pub_single_assign(&sexponent, exponent);
	while(!mk_iip_cp_helper_cui_dsa_pub_single_is_zero(&sexponent))
	{
		if(mk_iip_cp_helper_cui_dsa_pub_single_has_lsb(&sexponent))
		{
			mk_iip_cp_helper_cui_dsa_pub_double_mul2_wrap_lo(&dresult, &dbase);
			mk_iip_cp_helper_cui_dsa_pub_double_mod2_wrap(&dresult, &dmodulus);
		}
		mk_iip_cp_helper_cui_dsa_pub_single_shr2(&sexponent, 1);
		mk_iip_cp_helper_cui_dsa_pub_double_mul2_wrap_lo(&dbase, &dbase);
		mk_iip_cp_helper_cui_dsa_pub_double_mod2_wrap(&dbase, &dmodulus);
	}
	mk_iip_cp_helper_cui_dsa_pub_double_to_single(&dresult, result);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pub_single_mod_pow_b(mk_iip_cp_helper_cui_dsa_pub_single_prct const base, mk_iip_cp_helper_cui_dsa_pri_single_prct const exponent, mk_iip_cp_helper_cui_dsa_pub_single_prct const modulus_a, mk_iip_cp_helper_cui_dsa_pri_single_prct const modulus_b, mk_iip_cp_helper_cui_dsa_pri_single_prt const result) mk_lang_noexcept
{
	mk_iip_cp_helper_cui_dsa_pub_double_t dbase mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pub_double_t dmodulusa mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pub_double_t dresult mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pri_single_t sexponent mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pub_single_t sresult mk_lang_constexpr_init;
	mk_iip_cp_helper_cui_dsa_pub_single_t smodulusb mk_lang_constexpr_init;

	mk_lang_assert(base);
	mk_lang_assert(exponent);
	mk_lang_assert(modulus_a);
	mk_lang_assert(modulus_b);
	mk_lang_assert(result);
	/*mk_lang_assert(base != exponent);*/
	mk_lang_assert(base != modulus_a);
	/*mk_lang_assert(base != modulus_b);*/
	/*mk_lang_assert(base != result);*/
	/*mk_lang_assert(exponent != modulus_a);*/
	mk_lang_assert(exponent != modulus_b);
	mk_lang_assert(exponent != result);
	/*mk_lang_assert(modulus_a != modulus_b);*/
	/*mk_lang_assert(modulus_a != result);*/
	mk_lang_assert(modulus_b != result);

	mk_iip_cp_helper_cui_dsa_pub_single_to_double(base, &dbase);
	mk_iip_cp_helper_cui_dsa_pub_single_to_double(modulus_a, &dmodulusa);
	mk_iip_cp_helper_cui_dsa_pub_double_set_one(&dresult);
	mk_iip_cp_helper_cui_dsa_pri_single_assign(&sexponent, exponent);
	while(!mk_iip_cp_helper_cui_dsa_pri_single_is_zero(&sexponent))
	{
		if(mk_iip_cp_helper_cui_dsa_pri_single_has_lsb(&sexponent))
		{
			mk_iip_cp_helper_cui_dsa_pub_double_mul2_wrap_lo(&dresult, &dbase);
			mk_iip_cp_helper_cui_dsa_pub_double_mod2_wrap(&dresult, &dmodulusa);
		}
		mk_iip_cp_helper_cui_dsa_pri_single_shr2(&sexponent, 1);
		mk_iip_cp_helper_cui_dsa_pub_double_mul2_wrap_lo(&dbase, &dbase);
		mk_iip_cp_helper_cui_dsa_pub_double_mod2_wrap(&dbase, &dmodulusa);
	}
	mk_iip_cp_helper_cui_dsa_pub_double_to_single(&dresult, &sresult);
	mk_iip_cp_helper_cui_dsa_pri_single_to_pub_single(modulus_b, &smodulusb);
	mk_iip_cp_helper_cui_dsa_pub_single_mod2_wrap(&sresult, &smodulusb);
	mk_iip_cp_helper_cui_dsa_pub_single_to_pri_single(&sresult, result);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pub_double_load_g(mk_iip_cp_helper_cui_dsa_pub_double_pt const x) mk_lang_noexcept
{
	mk_iip_cp_helper_cui_dsa_pub_single_t dsa_pub_single mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_iip_cp_helper_cui_dsa_pub_single_load_g(&dsa_pub_single);
	mk_iip_cp_helper_cui_dsa_pub_single_to_double(&dsa_pub_single, x);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_helper_cui_dsa_pub_double_load_p(mk_iip_cp_helper_cui_dsa_pub_double_pt const x) mk_lang_noexcept
{
	mk_iip_cp_helper_cui_dsa_pub_single_t dsa_pub_single mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_iip_cp_helper_cui_dsa_pub_single_load_p(&dsa_pub_single);
	mk_iip_cp_helper_cui_dsa_pub_single_to_double(&dsa_pub_single, x);
}


#endif
