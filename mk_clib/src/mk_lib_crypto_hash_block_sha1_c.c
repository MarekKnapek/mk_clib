#include "mk_lib_crypto_hash_block_sha1_c.h"

/* nist fips pub 180-1 */
/* nist fips pub 180-2 */
/* nist fips pub 180-3 */
/* nist fips pub 180-4 */

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


mk_lang_constexpr_static_inline mk_sl_cui_uint32_t const s_mk_lib_crypto_hash_block_sha1_c_init[5] =
{
	{{ 0x67452301ul }},
	{{ 0xefcdab89ul }},
	{{ 0x98badcfeul }},
	{{ 0x10325476ul }},
	{{ 0xc3d2e1f0ul }},
};
mk_lang_constexpr_static_inline mk_sl_cui_uint32_t const s_mk_lib_crypto_hash_block_sha1_c_table[4] =
{
	{{ 0x5a827999ul }},
	{{ 0x6ed9eba1ul }},
	{{ 0x8f1bbcdcul }},
	{{ 0xca62c1d6ul }},
};


mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_sha1_c_ch(mk_sl_cui_uint32_pct const x, mk_sl_cui_uint32_pct const y, mk_sl_cui_uint32_pct const z, mk_sl_cui_uint32_pt const ret) mk_lang_noexcept
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

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_sha1_c_parity(mk_sl_cui_uint32_pct const x, mk_sl_cui_uint32_pct const y, mk_sl_cui_uint32_pct const z, mk_sl_cui_uint32_pt const ret) mk_lang_noexcept
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

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_sha1_c_maj(mk_sl_cui_uint32_pct const x, mk_sl_cui_uint32_pct const y, mk_sl_cui_uint32_pct const z, mk_sl_cui_uint32_pt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;

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

	/* return (x & y) ^ (x & z) ^ (y & z); */

	mk_sl_cui_uint32_and3(x, y, &ta);
	mk_sl_cui_uint32_and3(x, z, &tb);
	mk_sl_cui_uint32_and3(y, z, &tc);
	mk_sl_cui_uint32_xor2(&ta, &tb);
	mk_sl_cui_uint32_xor3(&ta, &tc, ret);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_sha1_c_f(int const idx, mk_sl_cui_uint32_pct const x, mk_sl_cui_uint32_pct const y, mk_sl_cui_uint32_pct const z, mk_sl_cui_uint32_pt const ret) mk_lang_noexcept
{
	mk_lang_assert(idx >= 0 && idx < 80);
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

	switch(idx / 20)
	{
		case 0: mk_lib_crypto_hash_block_sha1_c_ch    (x, y, z, ret); break;
		case 1: mk_lib_crypto_hash_block_sha1_c_parity(x, y, z, ret); break;
		case 2: mk_lib_crypto_hash_block_sha1_c_maj   (x, y, z, ret); break;
		case 3: mk_lib_crypto_hash_block_sha1_c_parity(x, y, z, ret); break;
	}
}


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha1_c_init(mk_lib_crypto_hash_block_sha1_c_pt const sha1_c) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha1_c_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha1_c_digest_t) >= 20);

	mk_lang_assert(sha1_c);

	sha1_c->m_state[0] = s_mk_lib_crypto_hash_block_sha1_c_init[0];
	sha1_c->m_state[1] = s_mk_lib_crypto_hash_block_sha1_c_init[1];
	sha1_c->m_state[2] = s_mk_lib_crypto_hash_block_sha1_c_init[2];
	sha1_c->m_state[3] = s_mk_lib_crypto_hash_block_sha1_c_init[3];
	sha1_c->m_state[4] = s_mk_lib_crypto_hash_block_sha1_c_init[4];
	mk_sl_cui_uint64_set_zero(&sha1_c->m_len);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha1_c_append_blocks(mk_lib_crypto_hash_block_sha1_c_pt const sha1_c, mk_lib_crypto_hash_block_sha1_c_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_sl_cui_uint64_t tt mk_lang_constexpr_init;
	mk_sl_cui_uint32_t oldh[5] mk_lang_constexpr_init;
	mk_sl_cui_uint32_t h[5] mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt a mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt b mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt c mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt d mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt e mk_lang_constexpr_init;
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	mk_sl_cui_uint32_t w[80] mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t t mk_lang_constexpr_init;

	mk_lang_assert(sha1_c);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha1_c_block_len);

	mk_sl_cui_uint64_from_bi_usize(&tt, &nblocks);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&sha1_c->m_len, &tt));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&sha1_c->m_len, &tt);
	oldh[0] = sha1_c->m_state[0];
	oldh[1] = sha1_c->m_state[1];
	oldh[2] = sha1_c->m_state[2];
	oldh[3] = sha1_c->m_state[3];
	oldh[4] = sha1_c->m_state[4];
	a = &h[0];
	b = &h[1];
	c = &h[2];
	d = &h[3];
	e = &h[4];
	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		h[0] = oldh[0];
		h[1] = oldh[1];
		h[2] = oldh[2];
		h[3] = oldh[3];
		h[4] = oldh[4];
		for(i = 0; i != 16; ++i)
		{
			mk_sl_uint_32_from_8_be(&w[i], &pblocks[iblock].m_uint8s[i * 4]);
		}
		for(i = 16; i != 80; ++i)
		{
			/* w[i] = rotl(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1); */
			mk_sl_cui_uint32_xor3(&w[i -  3], &w[i -  8], &ta);
			mk_sl_cui_uint32_xor3(&w[i - 14], &w[i - 16], &tb);
			mk_sl_cui_uint32_xor2(&ta, &tb);
			mk_sl_cui_uint32_rotl3(&ta, 1, &w[i]);
		}
		for(i = 0; i != 80; ++i)
		{
			/* t = rotl(a, 5) + f(i, b, c, d) + e + k(i) + w[i]; */
			mk_sl_cui_uint32_rotl3(a, 5, &ta);
			mk_lib_crypto_hash_block_sha1_c_f(i, b, c, d, &tb);
			mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &tb);
			mk_sl_cui_uint32_add3_wrap_cid_cod(e, &w[i], &tb);
			mk_sl_cui_uint32_add2_wrap_cid_cod(&tb, &s_mk_lib_crypto_hash_block_sha1_c_table[i / 20]);
			mk_sl_cui_uint32_add3_wrap_cid_cod(&ta, &tb, &t);
			*e = *d;
			*d = *c;
			mk_sl_cui_uint32_rotl3(b, 30, c);
			*b = *a;
			*a = t;
		}
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[0], &h[0]);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[1], &h[1]);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[2], &h[2]);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[3], &h[3]);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[4], &h[4]);
	}
	sha1_c->m_state[0] = oldh[0];
	sha1_c->m_state[1] = oldh[1];
	sha1_c->m_state[2] = oldh[2];
	sha1_c->m_state[3] = oldh[3];
	sha1_c->m_state[4] = oldh[4];
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha1_c_finish(mk_lib_crypto_hash_block_sha1_c_pt const sha1_c, mk_lib_crypto_hash_block_sha1_c_block_pt const block, int const idx, mk_lib_crypto_hash_block_sha1_c_digest_pt const digest) mk_lang_noexcept
{
	unsigned ui mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tb mk_lang_constexpr_init;
	int rest mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(sha1_c);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_sha1_c_block_len);
	mk_lang_assert(digest);

	ui = mk_lib_crypto_hash_block_sha1_c_block_len;
	mk_sl_cui_uint64_from_bi_uint(&ta, &ui);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_mul(&sha1_c->m_len, &ta));
	mk_sl_cui_uint64_shl3(&sha1_c->m_len, 6, &ta);
	mk_sl_cui_uint64_from_bi_sint(&tb, &idx);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&ta, &tb));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&ta, &tb);
	ui = 8;
	mk_sl_cui_uint64_from_bi_uint(&tb, &ui);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_mul(&ta, &tb));
	mk_sl_cui_uint64_shl2(&ta, 3);
	ui = 0x80;
	mk_sl_cui_uint8_from_bi_uint(&block->m_uint8s[idx], &ui);
	rest = mk_lib_crypto_hash_block_sha1_c_block_len - idx - 1;
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
		mk_lib_crypto_hash_block_sha1_c_append_blocks(sha1_c, block, 1);
		for(i = 0; i != mk_lib_crypto_hash_block_sha1_c_block_len - 8; ++i)
		{
			mk_sl_cui_uint8_set_zero(&block->m_uint8s[i]);
		}
	}
	mk_sl_uint_64_to_8_be(&ta, &block->m_uint8s[mk_lib_crypto_hash_block_sha1_c_block_len - 8]);
	mk_lib_crypto_hash_block_sha1_c_append_blocks(sha1_c, block, 1);
	for(i = 0; i != 5; ++i)
	{
		mk_sl_uint_32_to_8_be(&sha1_c->m_state[i], &digest->m_uint8s[i * 4]);
	}
}
