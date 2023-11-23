#include "mk_lib_crypto_hash_block_sha2c_base_32bit.h"

#include "mk_lang_alignas.h"
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


struct mk_lib_crypto_hash_block_sha2c_base_table_data_s
{
	mk_sl_cui_uint32_t m_uint32s[16 * 4];
};
typedef struct mk_lib_crypto_hash_block_sha2c_base_table_data_s mk_lib_crypto_hash_block_sha2c_base_table_data_t;

struct mk_lib_crypto_hash_block_sha2c_base_table_s
{
	mk_lang_alignas(64) mk_lib_crypto_hash_block_sha2c_base_table_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_sha2c_base_table_s mk_lib_crypto_hash_block_sha2c_base_table_t;


mk_lang_constexpr_static_inline mk_lib_crypto_hash_block_sha2c_base_table_t const s_mk_lib_crypto_hash_block_sha2c_base_32bit_table =
{{{
	mk_sl_cui_uint32_c(0x428a2f98ul), mk_sl_cui_uint32_c(0x71374491ul), mk_sl_cui_uint32_c(0xb5c0fbcful), mk_sl_cui_uint32_c(0xe9b5dba5ul),
	mk_sl_cui_uint32_c(0x3956c25bul), mk_sl_cui_uint32_c(0x59f111f1ul), mk_sl_cui_uint32_c(0x923f82a4ul), mk_sl_cui_uint32_c(0xab1c5ed5ul),
	mk_sl_cui_uint32_c(0xd807aa98ul), mk_sl_cui_uint32_c(0x12835b01ul), mk_sl_cui_uint32_c(0x243185beul), mk_sl_cui_uint32_c(0x550c7dc3ul),
	mk_sl_cui_uint32_c(0x72be5d74ul), mk_sl_cui_uint32_c(0x80deb1feul), mk_sl_cui_uint32_c(0x9bdc06a7ul), mk_sl_cui_uint32_c(0xc19bf174ul),
	mk_sl_cui_uint32_c(0xe49b69c1ul), mk_sl_cui_uint32_c(0xefbe4786ul), mk_sl_cui_uint32_c(0x0fc19dc6ul), mk_sl_cui_uint32_c(0x240ca1ccul),
	mk_sl_cui_uint32_c(0x2de92c6ful), mk_sl_cui_uint32_c(0x4a7484aaul), mk_sl_cui_uint32_c(0x5cb0a9dcul), mk_sl_cui_uint32_c(0x76f988daul),
	mk_sl_cui_uint32_c(0x983e5152ul), mk_sl_cui_uint32_c(0xa831c66dul), mk_sl_cui_uint32_c(0xb00327c8ul), mk_sl_cui_uint32_c(0xbf597fc7ul),
	mk_sl_cui_uint32_c(0xc6e00bf3ul), mk_sl_cui_uint32_c(0xd5a79147ul), mk_sl_cui_uint32_c(0x06ca6351ul), mk_sl_cui_uint32_c(0x14292967ul),
	mk_sl_cui_uint32_c(0x27b70a85ul), mk_sl_cui_uint32_c(0x2e1b2138ul), mk_sl_cui_uint32_c(0x4d2c6dfcul), mk_sl_cui_uint32_c(0x53380d13ul),
	mk_sl_cui_uint32_c(0x650a7354ul), mk_sl_cui_uint32_c(0x766a0abbul), mk_sl_cui_uint32_c(0x81c2c92eul), mk_sl_cui_uint32_c(0x92722c85ul),
	mk_sl_cui_uint32_c(0xa2bfe8a1ul), mk_sl_cui_uint32_c(0xa81a664bul), mk_sl_cui_uint32_c(0xc24b8b70ul), mk_sl_cui_uint32_c(0xc76c51a3ul),
	mk_sl_cui_uint32_c(0xd192e819ul), mk_sl_cui_uint32_c(0xd6990624ul), mk_sl_cui_uint32_c(0xf40e3585ul), mk_sl_cui_uint32_c(0x106aa070ul),
	mk_sl_cui_uint32_c(0x19a4c116ul), mk_sl_cui_uint32_c(0x1e376c08ul), mk_sl_cui_uint32_c(0x2748774cul), mk_sl_cui_uint32_c(0x34b0bcb5ul),
	mk_sl_cui_uint32_c(0x391c0cb3ul), mk_sl_cui_uint32_c(0x4ed8aa4aul), mk_sl_cui_uint32_c(0x5b9cca4ful), mk_sl_cui_uint32_c(0x682e6ff3ul),
	mk_sl_cui_uint32_c(0x748f82eeul), mk_sl_cui_uint32_c(0x78a5636ful), mk_sl_cui_uint32_c(0x84c87814ul), mk_sl_cui_uint32_c(0x8cc70208ul),
	mk_sl_cui_uint32_c(0x90befffaul), mk_sl_cui_uint32_c(0xa4506cebul), mk_sl_cui_uint32_c(0xbef9a3f7ul), mk_sl_cui_uint32_c(0xc67178f2ul),
}}};


mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_sha2c_base_32bit_ch(mk_sl_cui_uint32_pct const x, mk_sl_cui_uint32_pct const y, mk_sl_cui_uint32_pct const z, mk_sl_cui_uint32_pt const ret) mk_lang_noexcept
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

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_sha2c_base_32bit_maj(mk_sl_cui_uint32_pct const x, mk_sl_cui_uint32_pct const y, mk_sl_cui_uint32_pct const z, mk_sl_cui_uint32_pt const ret) mk_lang_noexcept
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

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_sha2c_base_32bit_sum0(mk_sl_cui_uint32_pct const x, mk_sl_cui_uint32_pt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(ret);
	mk_lang_assert(x != ret);

	/* return rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22); */

	mk_sl_cui_uint32_rotr3(x, 2, &ta);
	mk_sl_cui_uint32_rotr3(x, 13, &tb);
	mk_sl_cui_uint32_xor2(&ta, &tb);
	mk_sl_cui_uint32_rotr3(x, 22, &tb);
	mk_sl_cui_uint32_xor3(&ta, &tb, ret);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_sha2c_base_32bit_sum1(mk_sl_cui_uint32_pct const x, mk_sl_cui_uint32_pt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(ret);
	mk_lang_assert(x != ret);

	/* return rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25); */

	mk_sl_cui_uint32_rotr3(x, 6, &ta);
	mk_sl_cui_uint32_rotr3(x, 11, &tb);
	mk_sl_cui_uint32_xor2(&ta, &tb);
	mk_sl_cui_uint32_rotr3(x, 25, &tb);
	mk_sl_cui_uint32_xor3(&ta, &tb, ret);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_sha2c_base_32bit_sig0(mk_sl_cui_uint32_pct const x, mk_sl_cui_uint32_pt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(ret);
	mk_lang_assert(x != ret);

	/* return rotr(x, 7) ^ rotr(x, 18) ^ shr(x, 3); */

	mk_sl_cui_uint32_rotr3(x, 7, &ta);
	mk_sl_cui_uint32_rotr3(x, 18, &tb);
	mk_sl_cui_uint32_xor2(&ta, &tb);
	mk_sl_cui_uint32_shr3(x, 3, &tb);
	mk_sl_cui_uint32_xor3(&ta, &tb, ret);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_sha2c_base_32bit_sig1(mk_sl_cui_uint32_pct const x, mk_sl_cui_uint32_pt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(ret);
	mk_lang_assert(x != ret);

	/* return rotr(x, 17) ^ rotr(x, 19) ^ shr(x, 10); */

	mk_sl_cui_uint32_rotr3(x, 17, &ta);
	mk_sl_cui_uint32_rotr3(x, 19, &tb);
	mk_sl_cui_uint32_xor2(&ta, &tb);
	mk_sl_cui_uint32_shr3(x, 10, &tb);
	mk_sl_cui_uint32_xor3(&ta, &tb, ret);
}


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha2c_base_32bit_init(mk_lib_crypto_hash_block_sha2c_base_32bit_pt const sha2_32bit, mk_sl_cui_uint32_pct const iv) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2c_base_32bit_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2c_base_32bit_digest_t) == 32);

	mk_lang_assert(sha2_32bit);

	sha2_32bit->m_state[0] = iv[0];
	sha2_32bit->m_state[1] = iv[1];
	sha2_32bit->m_state[2] = iv[2];
	sha2_32bit->m_state[3] = iv[3];
	sha2_32bit->m_state[4] = iv[4];
	sha2_32bit->m_state[5] = iv[5];
	sha2_32bit->m_state[6] = iv[6];
	sha2_32bit->m_state[7] = iv[7];
	mk_sl_cui_uint64_set_zero(&sha2_32bit->m_len);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha2c_base_32bit_append_blocks(mk_lib_crypto_hash_block_sha2c_base_32bit_pt const sha2_32bit, mk_lib_crypto_hash_block_sha2c_base_32bit_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_sl_cui_uint64_t tt mk_lang_constexpr_init;
	mk_sl_cui_uint32_t oldh[8] mk_lang_constexpr_init;
	mk_sl_cui_uint32_t hh[8] mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt a mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt b mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt c mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt d mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt e mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt f mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt g mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt h mk_lang_constexpr_init;
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	mk_sl_cui_uint32_t w[64] mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t t1 mk_lang_constexpr_init;
	mk_sl_cui_uint32_t t2 mk_lang_constexpr_init;

	mk_lang_assert(sha2_32bit);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha2c_base_32bit_block_len);

	mk_sl_cui_uint64_from_bi_usize(&tt, &nblocks);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&sha2_32bit->m_len, &tt));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&sha2_32bit->m_len, &tt);
	oldh[0] = sha2_32bit->m_state[0];
	oldh[1] = sha2_32bit->m_state[1];
	oldh[2] = sha2_32bit->m_state[2];
	oldh[3] = sha2_32bit->m_state[3];
	oldh[4] = sha2_32bit->m_state[4];
	oldh[5] = sha2_32bit->m_state[5];
	oldh[6] = sha2_32bit->m_state[6];
	oldh[7] = sha2_32bit->m_state[7];
	a = &hh[0];
	b = &hh[1];
	c = &hh[2];
	d = &hh[3];
	e = &hh[4];
	f = &hh[5];
	g = &hh[6];
	h = &hh[7];
	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		hh[0] = oldh[0];
		hh[1] = oldh[1];
		hh[2] = oldh[2];
		hh[3] = oldh[3];
		hh[4] = oldh[4];
		hh[5] = oldh[5];
		hh[6] = oldh[6];
		hh[7] = oldh[7];
		for(i = 0; i != 16; ++i)
		{
			mk_sl_uint_32_from_8_be(&w[i], &pblocks[iblock].m_uint8s[i * 4]);
		}
		for(i = 16; i != 64; ++i)
		{
			/* w[i] = sig1(w[i - 2]) + w[i - 7] + sig0(w[i - 15]) + w[i - 16]; */
			mk_lib_crypto_hash_block_sha2c_base_32bit_sig1(&w[i - 2], &ta);
			mk_lib_crypto_hash_block_sha2c_base_32bit_sig0(&w[i - 15], &tb);
			mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &w[i - 7]);
			mk_sl_cui_uint32_add2_wrap_cid_cod(&tb, &w[i - 16]);
			mk_sl_cui_uint32_add3_wrap_cid_cod(&ta, &tb, &w[i]);
		}
		for(i = 0; i != 64; ++i)
		{
			/* a = ch(e, f, g) + sum1(e) + wk + h + maj(a, b, c) + sum0(a) */
			/* t1 = h + sum1(e) + ch(e, f, g) + table[i] + w[i]; */
			mk_lib_crypto_hash_block_sha2c_base_32bit_sum1(e, &ta);
			mk_lib_crypto_hash_block_sha2c_base_32bit_ch(e, f, g, &tb);
			mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, h);
			mk_sl_cui_uint32_add2_wrap_cid_cod(&tb, &s_mk_lib_crypto_hash_block_sha2c_base_32bit_table.m_data.m_uint32s[i]);
			mk_sl_cui_uint32_add2_wrap_cid_cod(&tb, &w[i]);
			mk_sl_cui_uint32_add3_wrap_cid_cod(&ta, &tb, &t1);
			/* t2 = sum0(a) + maj(a, b, c); */
			mk_lib_crypto_hash_block_sha2c_base_32bit_sum0(a, &ta);
			mk_lib_crypto_hash_block_sha2c_base_32bit_maj(a, b, c, &tb);
			mk_sl_cui_uint32_add3_wrap_cid_cod(&ta, &tb, &t2);
			*h = *g;
			*g = *f;
			*f = *e;
			mk_sl_cui_uint32_add3_wrap_cid_cod(d, &t1, e);
			*d = *c;
			*c = *b;
			*b = *a;
			mk_sl_cui_uint32_add3_wrap_cid_cod(&t1, &t2, a);
		}
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[0], &hh[0]);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[1], &hh[1]);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[2], &hh[2]);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[3], &hh[3]);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[4], &hh[4]);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[5], &hh[5]);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[6], &hh[6]);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&oldh[7], &hh[7]);
	}
	sha2_32bit->m_state[0] = oldh[0];
	sha2_32bit->m_state[1] = oldh[1];
	sha2_32bit->m_state[2] = oldh[2];
	sha2_32bit->m_state[3] = oldh[3];
	sha2_32bit->m_state[4] = oldh[4];
	sha2_32bit->m_state[5] = oldh[5];
	sha2_32bit->m_state[6] = oldh[6];
	sha2_32bit->m_state[7] = oldh[7];
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha2c_base_32bit_finish(mk_lib_crypto_hash_block_sha2c_base_32bit_pt const sha2_32bit, mk_lib_crypto_hash_block_sha2c_base_32bit_block_pt const block, int const idx, mk_lib_crypto_hash_block_sha2c_base_32bit_digest_pt const digest) mk_lang_noexcept
{
	unsigned ui mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tb mk_lang_constexpr_init;
	int rest mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(sha2_32bit);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_sha2c_base_32bit_block_len);
	mk_lang_assert(digest);

	ui = mk_lib_crypto_hash_block_sha2c_base_32bit_block_len;
	mk_sl_cui_uint64_from_bi_uint(&ta, &ui);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_mul(&sha2_32bit->m_len, &ta));
	mk_sl_cui_uint64_shl3(&sha2_32bit->m_len, 6, &ta);
	mk_sl_cui_uint64_from_bi_sint(&tb, &idx);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&ta, &tb));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&ta, &tb);
	ui = 8;
	mk_sl_cui_uint64_from_bi_uint(&tb, &ui);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_mul(&ta, &tb));
	mk_sl_cui_uint64_shl2(&ta, 3);
	ui = 0x80;
	mk_sl_cui_uint8_from_bi_uint(&block->m_uint8s[idx], &ui);
	rest = mk_lib_crypto_hash_block_sha2c_base_32bit_block_len - idx - 1;
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
		mk_lib_crypto_hash_block_sha2c_base_32bit_append_blocks(sha2_32bit, block, 1);
		for(i = 0; i != mk_lib_crypto_hash_block_sha2c_base_32bit_block_len - 8; ++i)
		{
			mk_sl_cui_uint8_set_zero(&block->m_uint8s[i]);
		}
	}
	mk_sl_uint_64_to_8_be(&ta, &block->m_uint8s[mk_lib_crypto_hash_block_sha2c_base_32bit_block_len - 8]);
	mk_lib_crypto_hash_block_sha2c_base_32bit_append_blocks(sha2_32bit, block, 1);
	for(i = 0; i != 8; ++i)
	{
		mk_sl_uint_32_to_8_be(&sha2_32bit->m_state[i], &digest->m_uint8s[i * 4]);
	}
}
