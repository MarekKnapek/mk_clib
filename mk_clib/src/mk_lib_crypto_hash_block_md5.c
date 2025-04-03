#ifndef mk_include_guard_mk_lib_crypto_hash_block_md5_c
#define mk_include_guard_mk_lib_crypto_hash_block_md5_c
#include "mk_lib_crypto_hash_block_md5.h"

/* RFC 1321 */

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"


mk_lang_constexpr_static_inline mk_sl_cui_uint32_t const mk_lib_crypto_hash_block_md5_s_init[4] =
{
	mk_sl_cui_uint32_c(0x67452301ul),
	mk_sl_cui_uint32_c(0xefcdab89ul),
	mk_sl_cui_uint32_c(0x98badcfeul),
	mk_sl_cui_uint32_c(0x10325476ul),
};
mk_lang_constexpr_static_inline mk_sl_cui_uint32_t const mk_lib_crypto_hash_block_md5_s_table[64] =
{
	mk_sl_cui_uint32_c(0xd76aa478ul), mk_sl_cui_uint32_c(0xe8c7b756ul), mk_sl_cui_uint32_c(0x242070dbul), mk_sl_cui_uint32_c(0xc1bdceeeul),
	mk_sl_cui_uint32_c(0xf57c0faful), mk_sl_cui_uint32_c(0x4787c62aul), mk_sl_cui_uint32_c(0xa8304613ul), mk_sl_cui_uint32_c(0xfd469501ul),
	mk_sl_cui_uint32_c(0x698098d8ul), mk_sl_cui_uint32_c(0x8b44f7aful), mk_sl_cui_uint32_c(0xffff5bb1ul), mk_sl_cui_uint32_c(0x895cd7beul),
	mk_sl_cui_uint32_c(0x6b901122ul), mk_sl_cui_uint32_c(0xfd987193ul), mk_sl_cui_uint32_c(0xa679438eul), mk_sl_cui_uint32_c(0x49b40821ul),
	mk_sl_cui_uint32_c(0xf61e2562ul), mk_sl_cui_uint32_c(0xc040b340ul), mk_sl_cui_uint32_c(0x265e5a51ul), mk_sl_cui_uint32_c(0xe9b6c7aaul),
	mk_sl_cui_uint32_c(0xd62f105dul), mk_sl_cui_uint32_c(0x02441453ul), mk_sl_cui_uint32_c(0xd8a1e681ul), mk_sl_cui_uint32_c(0xe7d3fbc8ul),
	mk_sl_cui_uint32_c(0x21e1cde6ul), mk_sl_cui_uint32_c(0xc33707d6ul), mk_sl_cui_uint32_c(0xf4d50d87ul), mk_sl_cui_uint32_c(0x455a14edul),
	mk_sl_cui_uint32_c(0xa9e3e905ul), mk_sl_cui_uint32_c(0xfcefa3f8ul), mk_sl_cui_uint32_c(0x676f02d9ul), mk_sl_cui_uint32_c(0x8d2a4c8aul),
	mk_sl_cui_uint32_c(0xfffa3942ul), mk_sl_cui_uint32_c(0x8771f681ul), mk_sl_cui_uint32_c(0x6d9d6122ul), mk_sl_cui_uint32_c(0xfde5380cul),
	mk_sl_cui_uint32_c(0xa4beea44ul), mk_sl_cui_uint32_c(0x4bdecfa9ul), mk_sl_cui_uint32_c(0xf6bb4b60ul), mk_sl_cui_uint32_c(0xbebfbc70ul),
	mk_sl_cui_uint32_c(0x289b7ec6ul), mk_sl_cui_uint32_c(0xeaa127faul), mk_sl_cui_uint32_c(0xd4ef3085ul), mk_sl_cui_uint32_c(0x04881d05ul),
	mk_sl_cui_uint32_c(0xd9d4d039ul), mk_sl_cui_uint32_c(0xe6db99e5ul), mk_sl_cui_uint32_c(0x1fa27cf8ul), mk_sl_cui_uint32_c(0xc4ac5665ul),
	mk_sl_cui_uint32_c(0xf4292244ul), mk_sl_cui_uint32_c(0x432aff97ul), mk_sl_cui_uint32_c(0xab9423a7ul), mk_sl_cui_uint32_c(0xfc93a039ul),
	mk_sl_cui_uint32_c(0x655b59c3ul), mk_sl_cui_uint32_c(0x8f0ccc92ul), mk_sl_cui_uint32_c(0xffeff47dul), mk_sl_cui_uint32_c(0x85845dd1ul),
	mk_sl_cui_uint32_c(0x6fa87e4ful), mk_sl_cui_uint32_c(0xfe2ce6e0ul), mk_sl_cui_uint32_c(0xa3014314ul), mk_sl_cui_uint32_c(0x4e0811a1ul),
	mk_sl_cui_uint32_c(0xf7537e82ul), mk_sl_cui_uint32_c(0xbd3af235ul), mk_sl_cui_uint32_c(0x2ad7d2bbul), mk_sl_cui_uint32_c(0xeb86d391ul),
};


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_md5_f(mk_sl_cui_uint32_prct const x, mk_sl_cui_uint32_prct const y, mk_sl_cui_uint32_prct const z, mk_sl_cui_uint32_prt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);
	mk_lang_assert(ret);
	mk_lang_assert(x != y);
	mk_lang_assert(x != z);
	mk_lang_assert(x != ret);
	mk_lang_assert(y != z);
	mk_lang_assert(y != ret);
	mk_lang_assert(z != ret);

	/* return (x & y) | ((~x) & z); */

	mk_sl_cui_uint32_and3(x, y, &ta);
	mk_sl_cui_uint32_not2(x, &tb);
	mk_sl_cui_uint32_and2(&tb, z);
	mk_sl_cui_uint32_or3(&ta, &tb, ret);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_md5_g(mk_sl_cui_uint32_prct const x, mk_sl_cui_uint32_prct const y, mk_sl_cui_uint32_prct const z, mk_sl_cui_uint32_prt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);
	mk_lang_assert(ret);
	mk_lang_assert(x != y);
	mk_lang_assert(x != z);
	mk_lang_assert(x != ret);
	mk_lang_assert(y != z);
	mk_lang_assert(y != ret);
	mk_lang_assert(z != ret);

	/* return (x & z) | (y & (~z)); */

	mk_sl_cui_uint32_and3(x, z, &ta);
	mk_sl_cui_uint32_not2(z, &tb);
	mk_sl_cui_uint32_and2(&tb, y);
	mk_sl_cui_uint32_or3(&ta, &tb, ret);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_md5_h(mk_sl_cui_uint32_prct const x, mk_sl_cui_uint32_prct const y, mk_sl_cui_uint32_prct const z, mk_sl_cui_uint32_prt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);
	mk_lang_assert(ret);
	mk_lang_assert(x != y);
	mk_lang_assert(x != z);
	mk_lang_assert(x != ret);
	mk_lang_assert(y != z);
	mk_lang_assert(y != ret);
	mk_lang_assert(z != ret);

	/* return x ^ y ^ z; */

	mk_sl_cui_uint32_xor3(x, y, &ta);
	mk_sl_cui_uint32_xor3(&ta, z, ret);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_md5_i(mk_sl_cui_uint32_prct const x, mk_sl_cui_uint32_prct const y, mk_sl_cui_uint32_prct const z, mk_sl_cui_uint32_prt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);
	mk_lang_assert(ret);
	mk_lang_assert(x != y);
	mk_lang_assert(x != z);
	mk_lang_assert(x != ret);
	mk_lang_assert(y != z);
	mk_lang_assert(y != ret);
	mk_lang_assert(z != ret);

	/* return y ^ (x | (~z)); */

	mk_sl_cui_uint32_not2(z, &ta);
	mk_sl_cui_uint32_or2(&ta, x);
	mk_sl_cui_uint32_xor3(y, &ta, ret);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_md5_round_1(mk_sl_cui_uint32_prt const a, mk_sl_cui_uint32_prct const b, mk_sl_cui_uint32_prct const c, mk_sl_cui_uint32_prct const d, mk_lib_crypto_hash_block_md5_block_pct const x, mk_lang_types_sint_t const k, mk_lang_types_sint_t const i, mk_lang_types_sint_t const s) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(x);
	mk_lang_assert(k >= 0 && k < 16);
	mk_lang_assert(i >= 0 && i < 64);
	mk_lang_assert(s > 0 && s < 32);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(a != d);
	mk_lang_assert(b != c);
	mk_lang_assert(b != d);
	mk_lang_assert(c != d);

	/* a = b + rotl(a + f(b, c, d) + x[k] + table[i], s); */

	mk_lib_crypto_hash_block_md5_f(b, c, d, &ta);
	mk_sl_uint_convert_32_8_le_to_big(&tb, &x->m_data.m_uint8s[k * 4]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, a);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&tb, &mk_lib_crypto_hash_block_md5_s_table[i]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &tb);
	mk_sl_cui_uint32_rotl2(&ta, s);
	mk_sl_cui_uint32_add3_wrap_cid_cod(b, &ta, a);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_md5_round_2(mk_sl_cui_uint32_prt const a, mk_sl_cui_uint32_prct const b, mk_sl_cui_uint32_prct const c, mk_sl_cui_uint32_prct const d, mk_lib_crypto_hash_block_md5_block_pct const x, mk_lang_types_sint_t const k, mk_lang_types_sint_t const i, mk_lang_types_sint_t const s) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(x);
	mk_lang_assert(k >= 0 && k < 16);
	mk_lang_assert(i >= 0 && i < 64);
	mk_lang_assert(s > 0 && s < 32);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(a != d);
	mk_lang_assert(b != c);
	mk_lang_assert(b != d);
	mk_lang_assert(c != d);

	/* a = b + rotl(a + g(b, c, d) + x[k] + table[i], s); */

	mk_lib_crypto_hash_block_md5_g(b, c, d, &ta);
	mk_sl_uint_convert_32_8_le_to_big(&tb, &x->m_data.m_uint8s[k * 4]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, a);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&tb, &mk_lib_crypto_hash_block_md5_s_table[i]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &tb);
	mk_sl_cui_uint32_rotl2(&ta, s);
	mk_sl_cui_uint32_add3_wrap_cid_cod(b, &ta, a);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_md5_round_3(mk_sl_cui_uint32_prt const a, mk_sl_cui_uint32_prct const b, mk_sl_cui_uint32_prct const c, mk_sl_cui_uint32_prct const d, mk_lib_crypto_hash_block_md5_block_pct const x, mk_lang_types_sint_t const k, mk_lang_types_sint_t const i, mk_lang_types_sint_t const s) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(x);
	mk_lang_assert(k >= 0 && k < 16);
	mk_lang_assert(i >= 0 && i < 64);
	mk_lang_assert(s > 0 && s < 32);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(a != d);
	mk_lang_assert(b != c);
	mk_lang_assert(b != d);
	mk_lang_assert(c != d);

	/* a = b + rotl(a + h(b, c, d) + x[k] + table[i], s); */

	mk_lib_crypto_hash_block_md5_h(b, c, d, &ta);
	mk_sl_uint_convert_32_8_le_to_big(&tb, &x->m_data.m_uint8s[k * 4]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, a);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&tb, &mk_lib_crypto_hash_block_md5_s_table[i]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &tb);
	mk_sl_cui_uint32_rotl2(&ta, s);
	mk_sl_cui_uint32_add3_wrap_cid_cod(b, &ta, a);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_md5_round_4(mk_sl_cui_uint32_prt const a, mk_sl_cui_uint32_prct const b, mk_sl_cui_uint32_prct const c, mk_sl_cui_uint32_prct const d, mk_lib_crypto_hash_block_md5_block_pct const x, mk_lang_types_sint_t const k, mk_lang_types_sint_t const i, mk_lang_types_sint_t const s) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(x);
	mk_lang_assert(k >= 0 && k < 16);
	mk_lang_assert(i >= 0 && i < 64);
	mk_lang_assert(s > 0 && s < 32);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(a != d);
	mk_lang_assert(b != c);
	mk_lang_assert(b != d);
	mk_lang_assert(c != d);

	/* a = b + rotl(a + i(b, c, d) + x[k] + table[i], s); */

	mk_lib_crypto_hash_block_md5_i(b, c, d, &ta);
	mk_sl_uint_convert_32_8_le_to_big(&tb, &x->m_data.m_uint8s[k * 4]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, a);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&tb, &mk_lib_crypto_hash_block_md5_s_table[i]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &tb);
	mk_sl_cui_uint32_rotl2(&ta, s);
	mk_sl_cui_uint32_add3_wrap_cid_cod(b, &ta, a);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_md5_init(mk_lib_crypto_hash_block_md5_pt const md5) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_md5_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_md5_digest_t) == 16);

	mk_lang_assert(md5);

	md5->m_state[0] = mk_lib_crypto_hash_block_md5_s_init[0];
	md5->m_state[1] = mk_lib_crypto_hash_block_md5_s_init[1];
	md5->m_state[2] = mk_lib_crypto_hash_block_md5_s_init[2];
	md5->m_state[3] = mk_lib_crypto_hash_block_md5_s_init[3];
	mk_sl_cui_uint64_set_zero(&md5->m_len);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_md5_append_blocks(mk_lib_crypto_hash_block_md5_pt const md5, mk_lib_crypto_hash_block_md5_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t oldh[4] mk_lang_constexpr_init;
	mk_sl_cui_uint32_t h[4] mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt a mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt b mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt c mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt d mk_lang_constexpr_init;
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(md5);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_md5_block_len_v);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_cui_uint64_from_bi_usize(&ta, &nblocks);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&md5->m_len, &ta));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&md5->m_len, &ta);
	oldh[0] = md5->m_state[0];
	oldh[1] = md5->m_state[1];
	oldh[2] = md5->m_state[2];
	oldh[3] = md5->m_state[3];
	a = &h[0];
	b = &h[1];
	c = &h[2];
	d = &h[3];
	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		h[0] = oldh[0];
		h[1] = oldh[1];
		h[2] = oldh[2];
		h[3] = oldh[3];
		mk_lib_crypto_hash_block_md5_round_1(a, b, c, d, &pblocks[iblock],  0,  0,  7);
		mk_lib_crypto_hash_block_md5_round_1(d, a, b, c, &pblocks[iblock],  1,  1, 12);
		mk_lib_crypto_hash_block_md5_round_1(c, d, a, b, &pblocks[iblock],  2,  2, 17);
		mk_lib_crypto_hash_block_md5_round_1(b, c, d, a, &pblocks[iblock],  3,  3, 22);
		mk_lib_crypto_hash_block_md5_round_1(a, b, c, d, &pblocks[iblock],  4,  4,  7);
		mk_lib_crypto_hash_block_md5_round_1(d, a, b, c, &pblocks[iblock],  5,  5, 12);
		mk_lib_crypto_hash_block_md5_round_1(c, d, a, b, &pblocks[iblock],  6,  6, 17);
		mk_lib_crypto_hash_block_md5_round_1(b, c, d, a, &pblocks[iblock],  7,  7, 22);
		mk_lib_crypto_hash_block_md5_round_1(a, b, c, d, &pblocks[iblock],  8,  8,  7);
		mk_lib_crypto_hash_block_md5_round_1(d, a, b, c, &pblocks[iblock],  9,  9, 12);
		mk_lib_crypto_hash_block_md5_round_1(c, d, a, b, &pblocks[iblock], 10, 10, 17);
		mk_lib_crypto_hash_block_md5_round_1(b, c, d, a, &pblocks[iblock], 11, 11, 22);
		mk_lib_crypto_hash_block_md5_round_1(a, b, c, d, &pblocks[iblock], 12, 12,  7);
		mk_lib_crypto_hash_block_md5_round_1(d, a, b, c, &pblocks[iblock], 13, 13, 12);
		mk_lib_crypto_hash_block_md5_round_1(c, d, a, b, &pblocks[iblock], 14, 14, 17);
		mk_lib_crypto_hash_block_md5_round_1(b, c, d, a, &pblocks[iblock], 15, 15, 22);
		mk_lib_crypto_hash_block_md5_round_2(a, b, c, d, &pblocks[iblock],  1, 16,  5);
		mk_lib_crypto_hash_block_md5_round_2(d, a, b, c, &pblocks[iblock],  6, 17,  9);
		mk_lib_crypto_hash_block_md5_round_2(c, d, a, b, &pblocks[iblock], 11, 18, 14);
		mk_lib_crypto_hash_block_md5_round_2(b, c, d, a, &pblocks[iblock],  0, 19, 20);
		mk_lib_crypto_hash_block_md5_round_2(a, b, c, d, &pblocks[iblock],  5, 20,  5);
		mk_lib_crypto_hash_block_md5_round_2(d, a, b, c, &pblocks[iblock], 10, 21,  9);
		mk_lib_crypto_hash_block_md5_round_2(c, d, a, b, &pblocks[iblock], 15, 22, 14);
		mk_lib_crypto_hash_block_md5_round_2(b, c, d, a, &pblocks[iblock],  4, 23, 20);
		mk_lib_crypto_hash_block_md5_round_2(a, b, c, d, &pblocks[iblock],  9, 24,  5);
		mk_lib_crypto_hash_block_md5_round_2(d, a, b, c, &pblocks[iblock], 14, 25,  9);
		mk_lib_crypto_hash_block_md5_round_2(c, d, a, b, &pblocks[iblock],  3, 26, 14);
		mk_lib_crypto_hash_block_md5_round_2(b, c, d, a, &pblocks[iblock],  8, 27, 20);
		mk_lib_crypto_hash_block_md5_round_2(a, b, c, d, &pblocks[iblock], 13, 28,  5);
		mk_lib_crypto_hash_block_md5_round_2(d, a, b, c, &pblocks[iblock],  2, 29,  9);
		mk_lib_crypto_hash_block_md5_round_2(c, d, a, b, &pblocks[iblock],  7, 30, 14);
		mk_lib_crypto_hash_block_md5_round_2(b, c, d, a, &pblocks[iblock], 12, 31, 20);
		mk_lib_crypto_hash_block_md5_round_3(a, b, c, d, &pblocks[iblock],  5, 32,  4);
		mk_lib_crypto_hash_block_md5_round_3(d, a, b, c, &pblocks[iblock],  8, 33, 11);
		mk_lib_crypto_hash_block_md5_round_3(c, d, a, b, &pblocks[iblock], 11, 34, 16);
		mk_lib_crypto_hash_block_md5_round_3(b, c, d, a, &pblocks[iblock], 14, 35, 23);
		mk_lib_crypto_hash_block_md5_round_3(a, b, c, d, &pblocks[iblock],  1, 36,  4);
		mk_lib_crypto_hash_block_md5_round_3(d, a, b, c, &pblocks[iblock],  4, 37, 11);
		mk_lib_crypto_hash_block_md5_round_3(c, d, a, b, &pblocks[iblock],  7, 38, 16);
		mk_lib_crypto_hash_block_md5_round_3(b, c, d, a, &pblocks[iblock], 10, 39, 23);
		mk_lib_crypto_hash_block_md5_round_3(a, b, c, d, &pblocks[iblock], 13, 40,  4);
		mk_lib_crypto_hash_block_md5_round_3(d, a, b, c, &pblocks[iblock],  0, 41, 11);
		mk_lib_crypto_hash_block_md5_round_3(c, d, a, b, &pblocks[iblock],  3, 42, 16);
		mk_lib_crypto_hash_block_md5_round_3(b, c, d, a, &pblocks[iblock],  6, 43, 23);
		mk_lib_crypto_hash_block_md5_round_3(a, b, c, d, &pblocks[iblock],  9, 44,  4);
		mk_lib_crypto_hash_block_md5_round_3(d, a, b, c, &pblocks[iblock], 12, 45, 11);
		mk_lib_crypto_hash_block_md5_round_3(c, d, a, b, &pblocks[iblock], 15, 46, 16);
		mk_lib_crypto_hash_block_md5_round_3(b, c, d, a, &pblocks[iblock],  2, 47, 23);
		mk_lib_crypto_hash_block_md5_round_4(a, b, c, d, &pblocks[iblock],  0, 48,  6);
		mk_lib_crypto_hash_block_md5_round_4(d, a, b, c, &pblocks[iblock],  7, 49, 10);
		mk_lib_crypto_hash_block_md5_round_4(c, d, a, b, &pblocks[iblock], 14, 50, 15);
		mk_lib_crypto_hash_block_md5_round_4(b, c, d, a, &pblocks[iblock],  5, 51, 21);
		mk_lib_crypto_hash_block_md5_round_4(a, b, c, d, &pblocks[iblock], 12, 52,  6);
		mk_lib_crypto_hash_block_md5_round_4(d, a, b, c, &pblocks[iblock],  3, 53, 10);
		mk_lib_crypto_hash_block_md5_round_4(c, d, a, b, &pblocks[iblock], 10, 54, 15);
		mk_lib_crypto_hash_block_md5_round_4(b, c, d, a, &pblocks[iblock],  1, 55, 21);
		mk_lib_crypto_hash_block_md5_round_4(a, b, c, d, &pblocks[iblock],  8, 56,  6);
		mk_lib_crypto_hash_block_md5_round_4(d, a, b, c, &pblocks[iblock], 15, 57, 10);
		mk_lib_crypto_hash_block_md5_round_4(c, d, a, b, &pblocks[iblock],  6, 58, 15);
		mk_lib_crypto_hash_block_md5_round_4(b, c, d, a, &pblocks[iblock], 13, 59, 21);
		mk_lib_crypto_hash_block_md5_round_4(a, b, c, d, &pblocks[iblock],  4, 60,  6);
		mk_lib_crypto_hash_block_md5_round_4(d, a, b, c, &pblocks[iblock], 11, 61, 10);
		mk_lib_crypto_hash_block_md5_round_4(c, d, a, b, &pblocks[iblock],  2, 62, 15);
		mk_lib_crypto_hash_block_md5_round_4(b, c, d, a, &pblocks[iblock],  9, 63, 21);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[0], &h[0]);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[1], &h[1]);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[2], &h[2]);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[3], &h[3]);
	}
	md5->m_state[0] = oldh[0];
	md5->m_state[1] = oldh[1];
	md5->m_state[2] = oldh[2];
	md5->m_state[3] = oldh[3];
}

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_md5_finish(mk_lib_crypto_hash_block_md5_pt const md5, mk_lib_crypto_hash_block_md5_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_md5_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tb mk_lang_constexpr_init;
	mk_lang_types_sint_t rest mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(md5);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_md5_block_len_v);
	mk_lang_assert(digest);

	ui = mk_lib_crypto_hash_block_md5_block_len_v; mk_sl_cui_uint64_from_bi_uint(&ta, &ui);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_mul(&md5->m_len, &ta));
	mk_sl_cui_uint64_shl3(&md5->m_len, 6, &ta);
	mk_sl_cui_uint64_from_bi_sint(&tb, &idx);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&ta, &tb));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&ta, &tb);
	ui = 8; mk_sl_cui_uint64_from_bi_uint(&tb, &ui);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_mul(&ta, &tb));
	mk_sl_cui_uint64_shl2(&ta, 3);

	ui = 0x80; mk_sl_cui_uint8_from_bi_uint(&block->m_data.m_uint8s[idx], &ui);
	rest = mk_lib_crypto_hash_block_md5_block_len_v - idx - 1;
	mk_lang_assert(rest >= 0 && rest <= mk_lib_crypto_hash_block_md5_block_len_v - 1);
	if(rest >= 8)
	{
		mk_sl_cui_uint8_memclr_fn(&block->m_data.m_uint8s[idx + 1], ((mk_lang_types_usize_t)(rest - 8)));
	}
	else
	{
		mk_sl_cui_uint8_memclr_fn(&block->m_data.m_uint8s[idx + 1], ((mk_lang_types_usize_t)(rest)));
		mk_lib_crypto_hash_block_md5_append_blocks(md5, block, 1);
		mk_sl_cui_uint8_memclr_fn(&block->m_data.m_uint8s[0], mk_lib_crypto_hash_block_md5_block_len_v - 8);
	}

	mk_sl_uint_convert_64_8_le_to_sml(&ta, &block->m_data.m_uint8s[mk_lib_crypto_hash_block_md5_block_len_v - 8]);
	mk_lib_crypto_hash_block_md5_append_blocks(md5, block, 1);
	for(i = 0; i != 4; ++i)
	{
		mk_sl_uint_convert_32_8_le_to_sml(&md5->m_state[i], &digest->m_data.m_uint8s[i * 4]);
	}
}
#include "mk_lang_warning_msvc_pop.h"


#endif
