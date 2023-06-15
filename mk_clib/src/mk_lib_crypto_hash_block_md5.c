#include "mk_lib_crypto_hash_block_md5.h"

/* rfc1321 */

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


mk_lang_constexpr_static mk_sl_cui_uint32_t const s_mk_lib_crypto_hash_block_md5_init[4] =
{
	{{ 0x67452301ul }},
	{{ 0xefcdab89ul }},
	{{ 0x98badcfeul }},
	{{ 0x10325476ul }},
};
mk_lang_constexpr_static mk_sl_cui_uint32_t const s_mk_lib_crypto_hash_block_md5_table[64] =
{
	{{ 0xd76aa478ul }}, {{ 0xe8c7b756ul }}, {{ 0x242070dbul }}, {{ 0xc1bdceeeul }},
	{{ 0xf57c0faful }}, {{ 0x4787c62aul }}, {{ 0xa8304613ul }}, {{ 0xfd469501ul }},
	{{ 0x698098d8ul }}, {{ 0x8b44f7aful }}, {{ 0xffff5bb1ul }}, {{ 0x895cd7beul }},
	{{ 0x6b901122ul }}, {{ 0xfd987193ul }}, {{ 0xa679438eul }}, {{ 0x49b40821ul }},
	{{ 0xf61e2562ul }}, {{ 0xc040b340ul }}, {{ 0x265e5a51ul }}, {{ 0xe9b6c7aaul }},
	{{ 0xd62f105dul }}, {{ 0x02441453ul }}, {{ 0xd8a1e681ul }}, {{ 0xe7d3fbc8ul }},
	{{ 0x21e1cde6ul }}, {{ 0xc33707d6ul }}, {{ 0xf4d50d87ul }}, {{ 0x455a14edul }},
	{{ 0xa9e3e905ul }}, {{ 0xfcefa3f8ul }}, {{ 0x676f02d9ul }}, {{ 0x8d2a4c8aul }},
	{{ 0xfffa3942ul }}, {{ 0x8771f681ul }}, {{ 0x6d9d6122ul }}, {{ 0xfde5380cul }},
	{{ 0xa4beea44ul }}, {{ 0x4bdecfa9ul }}, {{ 0xf6bb4b60ul }}, {{ 0xbebfbc70ul }},
	{{ 0x289b7ec6ul }}, {{ 0xeaa127faul }}, {{ 0xd4ef3085ul }}, {{ 0x04881d05ul }},
	{{ 0xd9d4d039ul }}, {{ 0xe6db99e5ul }}, {{ 0x1fa27cf8ul }}, {{ 0xc4ac5665ul }},
	{{ 0xf4292244ul }}, {{ 0x432aff97ul }}, {{ 0xab9423a7ul }}, {{ 0xfc93a039ul }},
	{{ 0x655b59c3ul }}, {{ 0x8f0ccc92ul }}, {{ 0xffeff47dul }}, {{ 0x85845dd1ul }},
	{{ 0x6fa87e4ful }}, {{ 0xfe2ce6e0ul }}, {{ 0xa3014314ul }}, {{ 0x4e0811a1ul }},
	{{ 0xf7537e82ul }}, {{ 0xbd3af235ul }}, {{ 0x2ad7d2bbul }}, {{ 0xeb86d391ul }},
};


mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_md5_f(mk_sl_cui_uint32_pct const x, mk_sl_cui_uint32_pct const y, mk_sl_cui_uint32_pct const z, mk_sl_cui_uint32_pt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta;
	mk_sl_cui_uint32_t tb;

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

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_md5_g(mk_sl_cui_uint32_pct const x, mk_sl_cui_uint32_pct const y, mk_sl_cui_uint32_pct const z, mk_sl_cui_uint32_pt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta;
	mk_sl_cui_uint32_t tb;

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

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_md5_h(mk_sl_cui_uint32_pct const x, mk_sl_cui_uint32_pct const y, mk_sl_cui_uint32_pct const z, mk_sl_cui_uint32_pt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta;

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

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_md5_i(mk_sl_cui_uint32_pct const x, mk_sl_cui_uint32_pct const y, mk_sl_cui_uint32_pct const z, mk_sl_cui_uint32_pt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta;

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

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_md5_round_1(mk_sl_cui_uint32_pt const a, mk_sl_cui_uint32_pct const b, mk_sl_cui_uint32_pct const c, mk_sl_cui_uint32_pct const d, mk_lib_crypto_hash_block_md5_block_pct const x, int const k, int const i, int const s) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta;
	mk_sl_cui_uint32_t tb;

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
	mk_sl_uint_32_from_8_le(&tb, &x->m_uint8s[k * 4]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, a);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&tb, &s_mk_lib_crypto_hash_block_md5_table[i]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &tb);
	mk_sl_cui_uint32_rotl2(&ta, s);
	mk_sl_cui_uint32_add3_wrap_cid_cod(b, &ta, a);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_md5_round_2(mk_sl_cui_uint32_pt const a, mk_sl_cui_uint32_pct const b, mk_sl_cui_uint32_pct const c, mk_sl_cui_uint32_pct const d, mk_lib_crypto_hash_block_md5_block_pct const x, int const k, int const i, int const s) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta;
	mk_sl_cui_uint32_t tb;

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
	mk_sl_uint_32_from_8_le(&tb, &x->m_uint8s[k * 4]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, a);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&tb, &s_mk_lib_crypto_hash_block_md5_table[i]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &tb);
	mk_sl_cui_uint32_rotl2(&ta, s);
	mk_sl_cui_uint32_add3_wrap_cid_cod(b, &ta, a);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_md5_round_3(mk_sl_cui_uint32_pt const a, mk_sl_cui_uint32_pct const b, mk_sl_cui_uint32_pct const c, mk_sl_cui_uint32_pct const d, mk_lib_crypto_hash_block_md5_block_pct const x, int const k, int const i, int const s) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta;
	mk_sl_cui_uint32_t tb;

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
	mk_sl_uint_32_from_8_le(&tb, &x->m_uint8s[k * 4]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, a);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&tb, &s_mk_lib_crypto_hash_block_md5_table[i]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &tb);
	mk_sl_cui_uint32_rotl2(&ta, s);
	mk_sl_cui_uint32_add3_wrap_cid_cod(b, &ta, a);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_md5_round_4(mk_sl_cui_uint32_pt const a, mk_sl_cui_uint32_pct const b, mk_sl_cui_uint32_pct const c, mk_sl_cui_uint32_pct const d, mk_lib_crypto_hash_block_md5_block_pct const x, int const k, int const i, int const s) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta;
	mk_sl_cui_uint32_t tb;

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
	mk_sl_uint_32_from_8_le(&tb, &x->m_uint8s[k * 4]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, a);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&tb, &s_mk_lib_crypto_hash_block_md5_table[i]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &tb);
	mk_sl_cui_uint32_rotl2(&ta, s);
	mk_sl_cui_uint32_add3_wrap_cid_cod(b, &ta, a);
}


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_md5_init(mk_lib_crypto_hash_block_md5_pt const md5) mk_lang_noexcept
{
	mk_lang_assert(md5);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_md5_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_md5_digest_t) == 16);

	md5->m_state[0] = s_mk_lib_crypto_hash_block_md5_init[0];
	md5->m_state[1] = s_mk_lib_crypto_hash_block_md5_init[1];
	md5->m_state[2] = s_mk_lib_crypto_hash_block_md5_init[2];
	md5->m_state[3] = s_mk_lib_crypto_hash_block_md5_init[3];
	mk_sl_cui_uint64_set_zero(&md5->m_len);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_md5_append_blocks(mk_lib_crypto_hash_block_md5_pt const md5, mk_lib_crypto_hash_block_md5_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint32_t oldh[4];
	mk_sl_cui_uint32_t h[4];
	mk_sl_cui_uint32_pt a;
	mk_sl_cui_uint32_pt b;
	mk_sl_cui_uint32_pt c;
	mk_sl_cui_uint32_pt d;
	mk_lang_types_usize_t iblock;

	mk_lang_assert(md5);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / 64);

	mk_sl_cui_uint64_from_bi_size(&ta, &nblocks);
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

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_md5_finish(mk_lib_crypto_hash_block_md5_pt const md5, mk_lib_crypto_hash_block_md5_block_pt const block, int const idx, mk_lib_crypto_hash_block_md5_digest_pt const digest) mk_lang_noexcept
{
	unsigned ui;
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	int rest;
	int i;

	mk_lang_assert(md5);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < 64);

	ui = 64;
	mk_sl_cui_uint64_from_bi_uint(&ta, &ui);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_mul(&md5->m_len, &ta));
	mk_sl_cui_uint64_shl3(&md5->m_len, 6, &ta);
	mk_sl_cui_uint64_from_bi_sint(&tb, &idx);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&ta, &tb));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&ta, &tb);
	ui = 8;
	mk_sl_cui_uint64_from_bi_uint(&tb, &ui);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_mul(&ta, &tb));
	mk_sl_cui_uint64_shl2(&ta, 3);
	ui = 0x80;
	mk_sl_cui_uint8_from_bi_uint(&block->m_uint8s[idx], &ui);
	rest = 64 - idx - 1;
	if(rest >= 8)
	{
		for(i = 0; i != rest - 8; ++i)
		{
			mk_sl_cui_uint8_set_zero(&block->m_uint8s[idx + 1 + i]);
		}
	}
	else
	{
		for(i = 0; i != rest; ++i)
		{
			mk_sl_cui_uint8_set_zero(&block->m_uint8s[idx + 1 + i]);
		}
		mk_lib_crypto_hash_block_md5_append_blocks(md5, block, 1);
		for(i = 0; i != 64 - 8; ++i)
		{
			mk_sl_cui_uint8_set_zero(&block->m_uint8s[i]);
		}
	}
	mk_sl_uint_64_to_8_le(&ta, &block->m_uint8s[64 - 8]);
	mk_lib_crypto_hash_block_md5_append_blocks(md5, block, 1);
	for(i = 0; i != 4; ++i)
	{
		mk_sl_uint_32_to_8_le(&md5->m_state[i], &digest->m_uint8s[i * 4]);
	}
}
