#include "mk_lib_crypto_hash_block_md4.h"

/* rfc1186 */
/* rfc1320 */

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


mk_lang_constexpr_static mk_sl_cui_uint32_t const s_mk_lib_crypto_hash_block_md4_init[4] =
{
	{{ 0x67452301ul }},
	{{ 0xefcdab89ul }},
	{{ 0x98badcfeul }},
	{{ 0x10325476ul }},
};
mk_lang_constexpr_static mk_sl_cui_uint32_t const s_mk_lib_crypto_hash_block_md4_round_2_constant = {{ 0x5a827999ul }};
mk_lang_constexpr_static mk_sl_cui_uint32_t const s_mk_lib_crypto_hash_block_md4_round_3_constant = {{ 0x6ed9eba1ul }};


mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_md4_f(mk_sl_cui_uint32_pct const x, mk_sl_cui_uint32_pct const y, mk_sl_cui_uint32_pct const z, mk_sl_cui_uint32_pt const ret) mk_lang_noexcept
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

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_md4_g(mk_sl_cui_uint32_pct const x, mk_sl_cui_uint32_pct const y, mk_sl_cui_uint32_pct const z, mk_sl_cui_uint32_pt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta;
	mk_sl_cui_uint32_t tb;
	mk_sl_cui_uint32_t tc;

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

	/* return (x & y) | (x & z) | (y & z); */

	mk_sl_cui_uint32_and3(x, y, &ta);
	mk_sl_cui_uint32_and3(x, z, &tb);
	mk_sl_cui_uint32_and3(y, z, &tc);
	mk_sl_cui_uint32_or2(&ta, &tb);
	mk_sl_cui_uint32_or3(&ta, &tc, ret);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_md4_h(mk_sl_cui_uint32_pct const x, mk_sl_cui_uint32_pct const y, mk_sl_cui_uint32_pct const z, mk_sl_cui_uint32_pt const ret) mk_lang_noexcept
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

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_md4_round_1(mk_sl_cui_uint32_pt const a, mk_sl_cui_uint32_pct const b, mk_sl_cui_uint32_pct const c, mk_sl_cui_uint32_pct const d, mk_lib_crypto_hash_block_md4_block_pct const x, int const k, int const s) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta;
	mk_sl_cui_uint32_t tb;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(x);
	mk_lang_assert(k >= 0 && k < 16);
	mk_lang_assert(s > 0 && s < 32);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(a != d);
	mk_lang_assert(b != c);
	mk_lang_assert(b != d);
	mk_lang_assert(c != d);

	/* a = rotl(a + f(b, c, d) + x[k], s); */

	mk_lib_crypto_hash_block_md4_f(b, c, d, &ta);
	mk_sl_uint_32_from_8_le(&tb, &x->m_uint8s[k * 4]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(a, &ta);
	mk_sl_cui_uint32_add2_wrap_cid_cod(a, &tb);
	mk_sl_cui_uint32_rotl2(a, s);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_md4_round_2(mk_sl_cui_uint32_pt const a, mk_sl_cui_uint32_pct const b, mk_sl_cui_uint32_pct const c, mk_sl_cui_uint32_pct const d, mk_lib_crypto_hash_block_md4_block_pct const x, int const k, int const s) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(x);
	mk_lang_assert(k >= 0 && k < 16);
	mk_lang_assert(s > 0 && s < 32);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(a != d);
	mk_lang_assert(b != c);
	mk_lang_assert(b != d);
	mk_lang_assert(c != d);

	/* a = rotl(a + g(b, c, d) + x[k] + 0x5a827999, s); */

	mk_lib_crypto_hash_block_md4_g(b, c, d, &ta);
	mk_sl_cui_uint32_add2_wrap_cid_cod(a, &ta);
	mk_sl_uint_32_from_8_le(&ta, &x->m_uint8s[k * 4]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(a, &ta);
	mk_sl_cui_uint32_add2_wrap_cid_cod(a, &s_mk_lib_crypto_hash_block_md4_round_2_constant);
	mk_sl_cui_uint32_rotl2(a, s);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_md4_round_3(mk_sl_cui_uint32_pt const a, mk_sl_cui_uint32_pct const b, mk_sl_cui_uint32_pct const c, mk_sl_cui_uint32_pct const d, mk_lib_crypto_hash_block_md4_block_pct const x, int const k, int const s) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta;
	mk_sl_cui_uint32_t tb;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(x);
	mk_lang_assert(k >= 0 && k < 16);
	mk_lang_assert(s > 0 && s < 32);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(a != d);
	mk_lang_assert(b != c);
	mk_lang_assert(b != d);
	mk_lang_assert(c != d);

	/* a = rotl(a + h(b, c, d) + x[k] + 0x6ed9eba1, s); */

	mk_lib_crypto_hash_block_md4_h(b, c, d, &ta);
	mk_sl_uint_32_from_8_le(&tb, &x->m_uint8s[k * 4]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(a, &ta);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&tb, &s_mk_lib_crypto_hash_block_md4_round_3_constant);
	mk_sl_cui_uint32_add2_wrap_cid_cod(a, &tb);
	mk_sl_cui_uint32_rotl2(a, s);
}


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_md4_init(mk_lib_crypto_hash_block_md4_pt const md4) mk_lang_noexcept
{
	mk_lang_assert(md4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_md4_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_md4_digest_t) == 16);

	md4->m_state[0] = s_mk_lib_crypto_hash_block_md4_init[0];
	md4->m_state[1] = s_mk_lib_crypto_hash_block_md4_init[1];
	md4->m_state[2] = s_mk_lib_crypto_hash_block_md4_init[2];
	md4->m_state[3] = s_mk_lib_crypto_hash_block_md4_init[3];
	mk_sl_cui_uint64_set_zero(&md4->m_len);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_md4_append_blocks(mk_lib_crypto_hash_block_md4_pt const md4, mk_lib_crypto_hash_block_md4_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint32_t oldh[4];
	mk_sl_cui_uint32_t h[4];
	mk_sl_cui_uint32_pt a;
	mk_sl_cui_uint32_pt b;
	mk_sl_cui_uint32_pt c;
	mk_sl_cui_uint32_pt d;
	mk_lang_types_usize_t iblock;

	mk_lang_assert(md4);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / 64);

	mk_sl_cui_uint64_from_bi_size(&ta, &nblocks);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&md4->m_len, &ta));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&md4->m_len, &ta);
	oldh[0] = md4->m_state[0];
	oldh[1] = md4->m_state[1];
	oldh[2] = md4->m_state[2];
	oldh[3] = md4->m_state[3];
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
		mk_lib_crypto_hash_block_md4_round_1(a, b, c, d, &pblocks[iblock],  0,  3);
		mk_lib_crypto_hash_block_md4_round_1(d, a, b, c, &pblocks[iblock],  1,  7);
		mk_lib_crypto_hash_block_md4_round_1(c, d, a, b, &pblocks[iblock],  2, 11);
		mk_lib_crypto_hash_block_md4_round_1(b, c, d, a, &pblocks[iblock],  3, 19);
		mk_lib_crypto_hash_block_md4_round_1(a, b, c, d, &pblocks[iblock],  4,  3);
		mk_lib_crypto_hash_block_md4_round_1(d, a, b, c, &pblocks[iblock],  5,  7);
		mk_lib_crypto_hash_block_md4_round_1(c, d, a, b, &pblocks[iblock],  6, 11);
		mk_lib_crypto_hash_block_md4_round_1(b, c, d, a, &pblocks[iblock],  7, 19);
		mk_lib_crypto_hash_block_md4_round_1(a, b, c, d, &pblocks[iblock],  8,  3);
		mk_lib_crypto_hash_block_md4_round_1(d, a, b, c, &pblocks[iblock],  9,  7);
		mk_lib_crypto_hash_block_md4_round_1(c, d, a, b, &pblocks[iblock], 10, 11);
		mk_lib_crypto_hash_block_md4_round_1(b, c, d, a, &pblocks[iblock], 11, 19);
		mk_lib_crypto_hash_block_md4_round_1(a, b, c, d, &pblocks[iblock], 12,  3);
		mk_lib_crypto_hash_block_md4_round_1(d, a, b, c, &pblocks[iblock], 13,  7);
		mk_lib_crypto_hash_block_md4_round_1(c, d, a, b, &pblocks[iblock], 14, 11);
		mk_lib_crypto_hash_block_md4_round_1(b, c, d, a, &pblocks[iblock], 15, 19);
		mk_lib_crypto_hash_block_md4_round_2(a, b, c, d, &pblocks[iblock],  0,  3);
		mk_lib_crypto_hash_block_md4_round_2(d, a, b, c, &pblocks[iblock],  4,  5);
		mk_lib_crypto_hash_block_md4_round_2(c, d, a, b, &pblocks[iblock],  8,  9);
		mk_lib_crypto_hash_block_md4_round_2(b, c, d, a, &pblocks[iblock], 12, 13);
		mk_lib_crypto_hash_block_md4_round_2(a, b, c, d, &pblocks[iblock],  1,  3);
		mk_lib_crypto_hash_block_md4_round_2(d, a, b, c, &pblocks[iblock],  5,  5);
		mk_lib_crypto_hash_block_md4_round_2(c, d, a, b, &pblocks[iblock],  9,  9);
		mk_lib_crypto_hash_block_md4_round_2(b, c, d, a, &pblocks[iblock], 13, 13);
		mk_lib_crypto_hash_block_md4_round_2(a, b, c, d, &pblocks[iblock],  2,  3);
		mk_lib_crypto_hash_block_md4_round_2(d, a, b, c, &pblocks[iblock],  6,  5);
		mk_lib_crypto_hash_block_md4_round_2(c, d, a, b, &pblocks[iblock], 10,  9);
		mk_lib_crypto_hash_block_md4_round_2(b, c, d, a, &pblocks[iblock], 14, 13);
		mk_lib_crypto_hash_block_md4_round_2(a, b, c, d, &pblocks[iblock],  3,  3);
		mk_lib_crypto_hash_block_md4_round_2(d, a, b, c, &pblocks[iblock],  7,  5);
		mk_lib_crypto_hash_block_md4_round_2(c, d, a, b, &pblocks[iblock], 11,  9);
		mk_lib_crypto_hash_block_md4_round_2(b, c, d, a, &pblocks[iblock], 15, 13);
		mk_lib_crypto_hash_block_md4_round_3(a, b, c, d, &pblocks[iblock],  0,  3);
		mk_lib_crypto_hash_block_md4_round_3(d, a, b, c, &pblocks[iblock],  8,  9);
		mk_lib_crypto_hash_block_md4_round_3(c, d, a, b, &pblocks[iblock],  4, 11);
		mk_lib_crypto_hash_block_md4_round_3(b, c, d, a, &pblocks[iblock], 12, 15);
		mk_lib_crypto_hash_block_md4_round_3(a, b, c, d, &pblocks[iblock],  2,  3);
		mk_lib_crypto_hash_block_md4_round_3(d, a, b, c, &pblocks[iblock], 10,  9);
		mk_lib_crypto_hash_block_md4_round_3(c, d, a, b, &pblocks[iblock],  6, 11);
		mk_lib_crypto_hash_block_md4_round_3(b, c, d, a, &pblocks[iblock], 14, 15);
		mk_lib_crypto_hash_block_md4_round_3(a, b, c, d, &pblocks[iblock],  1,  3);
		mk_lib_crypto_hash_block_md4_round_3(d, a, b, c, &pblocks[iblock],  9,  9);
		mk_lib_crypto_hash_block_md4_round_3(c, d, a, b, &pblocks[iblock],  5, 11);
		mk_lib_crypto_hash_block_md4_round_3(b, c, d, a, &pblocks[iblock], 13, 15);
		mk_lib_crypto_hash_block_md4_round_3(a, b, c, d, &pblocks[iblock],  3,  3);
		mk_lib_crypto_hash_block_md4_round_3(d, a, b, c, &pblocks[iblock], 11,  9);
		mk_lib_crypto_hash_block_md4_round_3(c, d, a, b, &pblocks[iblock],  7, 11);
		mk_lib_crypto_hash_block_md4_round_3(b, c, d, a, &pblocks[iblock], 15, 15);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[0], &h[0]);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[1], &h[1]);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[2], &h[2]);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[3], &h[3]);
	}
	md4->m_state[0] = oldh[0];
	md4->m_state[1] = oldh[1];
	md4->m_state[2] = oldh[2];
	md4->m_state[3] = oldh[3];
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_md4_finish(mk_lib_crypto_hash_block_md4_pt const md4, mk_lib_crypto_hash_block_md4_block_pt const block, int const idx, mk_lib_crypto_hash_block_md4_digest_pt const digest) mk_lang_noexcept
{
	unsigned ui;
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	int rest;
	int i;

	mk_lang_assert(md4);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < 64);

	ui = 64;
	mk_sl_cui_uint64_from_bi_uint(&ta, &ui);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_mul(&md4->m_len, &ta));
	mk_sl_cui_uint64_shl3(&md4->m_len, 6, &ta);
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
		mk_lib_crypto_hash_block_md4_append_blocks(md4, block, 1);
		for(i = 0; i != 64 - 8; ++i)
		{
			mk_sl_cui_uint8_set_zero(&block->m_uint8s[i]);
		}
	}
	mk_sl_uint_64_to_8_le(&ta, &block->m_uint8s[64 - 8]);
	mk_lib_crypto_hash_block_md4_append_blocks(md4, block, 1);
	for(i = 0; i != 4; ++i)
	{
		mk_sl_uint_32_to_8_le(&md4->m_state[i], &digest->m_uint8s[i * 4]);
	}
}
