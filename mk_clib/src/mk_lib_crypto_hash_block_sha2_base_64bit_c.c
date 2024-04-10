#include "mk_lib_crypto_hash_block_sha2_base_64bit_c.h"

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
#include "mk_sl_uint128.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


union mk_lib_crypto_hash_block_sha2_base_64bit_c_table_data_u
{
	mk_sl_cui_uint64_t m_uint64s[80];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_sha2_base_64bit_c_table_data_u mk_lib_crypto_hash_block_sha2_base_64bit_c_table_data_t;

struct mk_lib_crypto_hash_block_sha2_base_64bit_c_table_s
{
	mk_lang_alignas(64) mk_lib_crypto_hash_block_sha2_base_64bit_c_table_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_sha2_base_64bit_c_table_s mk_lib_crypto_hash_block_sha2_base_64bit_c_table_t;


mk_lang_constexpr_static_inline mk_lib_crypto_hash_block_sha2_base_64bit_c_table_t const s_mk_lib_crypto_hash_block_sha2_base_64bit_c_table =
{{{
	mk_sl_cui_uint64_c(0x428a2f98ul, 0xd728ae22ul), mk_sl_cui_uint64_c(0x71374491ul, 0x23ef65cdul), mk_sl_cui_uint64_c(0xb5c0fbcful, 0xec4d3b2ful), mk_sl_cui_uint64_c(0xe9b5dba5ul, 0x8189dbbcul),
	mk_sl_cui_uint64_c(0x3956c25bul, 0xf348b538ul), mk_sl_cui_uint64_c(0x59f111f1ul, 0xb605d019ul), mk_sl_cui_uint64_c(0x923f82a4ul, 0xaf194f9bul), mk_sl_cui_uint64_c(0xab1c5ed5ul, 0xda6d8118ul),
	mk_sl_cui_uint64_c(0xd807aa98ul, 0xa3030242ul), mk_sl_cui_uint64_c(0x12835b01ul, 0x45706fbeul), mk_sl_cui_uint64_c(0x243185beul, 0x4ee4b28cul), mk_sl_cui_uint64_c(0x550c7dc3ul, 0xd5ffb4e2ul),
	mk_sl_cui_uint64_c(0x72be5d74ul, 0xf27b896ful), mk_sl_cui_uint64_c(0x80deb1feul, 0x3b1696b1ul), mk_sl_cui_uint64_c(0x9bdc06a7ul, 0x25c71235ul), mk_sl_cui_uint64_c(0xc19bf174ul, 0xcf692694ul),
	mk_sl_cui_uint64_c(0xe49b69c1ul, 0x9ef14ad2ul), mk_sl_cui_uint64_c(0xefbe4786ul, 0x384f25e3ul), mk_sl_cui_uint64_c(0x0fc19dc6ul, 0x8b8cd5b5ul), mk_sl_cui_uint64_c(0x240ca1ccul, 0x77ac9c65ul),
	mk_sl_cui_uint64_c(0x2de92c6ful, 0x592b0275ul), mk_sl_cui_uint64_c(0x4a7484aaul, 0x6ea6e483ul), mk_sl_cui_uint64_c(0x5cb0a9dcul, 0xbd41fbd4ul), mk_sl_cui_uint64_c(0x76f988daul, 0x831153b5ul),
	mk_sl_cui_uint64_c(0x983e5152ul, 0xee66dfabul), mk_sl_cui_uint64_c(0xa831c66dul, 0x2db43210ul), mk_sl_cui_uint64_c(0xb00327c8ul, 0x98fb213ful), mk_sl_cui_uint64_c(0xbf597fc7ul, 0xbeef0ee4ul),
	mk_sl_cui_uint64_c(0xc6e00bf3ul, 0x3da88fc2ul), mk_sl_cui_uint64_c(0xd5a79147ul, 0x930aa725ul), mk_sl_cui_uint64_c(0x06ca6351ul, 0xe003826ful), mk_sl_cui_uint64_c(0x14292967ul, 0x0a0e6e70ul),
	mk_sl_cui_uint64_c(0x27b70a85ul, 0x46d22ffcul), mk_sl_cui_uint64_c(0x2e1b2138ul, 0x5c26c926ul), mk_sl_cui_uint64_c(0x4d2c6dfcul, 0x5ac42aedul), mk_sl_cui_uint64_c(0x53380d13ul, 0x9d95b3dful),
	mk_sl_cui_uint64_c(0x650a7354ul, 0x8baf63deul), mk_sl_cui_uint64_c(0x766a0abbul, 0x3c77b2a8ul), mk_sl_cui_uint64_c(0x81c2c92eul, 0x47edaee6ul), mk_sl_cui_uint64_c(0x92722c85ul, 0x1482353bul),
	mk_sl_cui_uint64_c(0xa2bfe8a1ul, 0x4cf10364ul), mk_sl_cui_uint64_c(0xa81a664bul, 0xbc423001ul), mk_sl_cui_uint64_c(0xc24b8b70ul, 0xd0f89791ul), mk_sl_cui_uint64_c(0xc76c51a3ul, 0x0654be30ul),
	mk_sl_cui_uint64_c(0xd192e819ul, 0xd6ef5218ul), mk_sl_cui_uint64_c(0xd6990624ul, 0x5565a910ul), mk_sl_cui_uint64_c(0xf40e3585ul, 0x5771202aul), mk_sl_cui_uint64_c(0x106aa070ul, 0x32bbd1b8ul),
	mk_sl_cui_uint64_c(0x19a4c116ul, 0xb8d2d0c8ul), mk_sl_cui_uint64_c(0x1e376c08ul, 0x5141ab53ul), mk_sl_cui_uint64_c(0x2748774cul, 0xdf8eeb99ul), mk_sl_cui_uint64_c(0x34b0bcb5ul, 0xe19b48a8ul),
	mk_sl_cui_uint64_c(0x391c0cb3ul, 0xc5c95a63ul), mk_sl_cui_uint64_c(0x4ed8aa4aul, 0xe3418acbul), mk_sl_cui_uint64_c(0x5b9cca4ful, 0x7763e373ul), mk_sl_cui_uint64_c(0x682e6ff3ul, 0xd6b2b8a3ul),
	mk_sl_cui_uint64_c(0x748f82eeul, 0x5defb2fcul), mk_sl_cui_uint64_c(0x78a5636ful, 0x43172f60ul), mk_sl_cui_uint64_c(0x84c87814ul, 0xa1f0ab72ul), mk_sl_cui_uint64_c(0x8cc70208ul, 0x1a6439ecul),
	mk_sl_cui_uint64_c(0x90befffaul, 0x23631e28ul), mk_sl_cui_uint64_c(0xa4506cebul, 0xde82bde9ul), mk_sl_cui_uint64_c(0xbef9a3f7ul, 0xb2c67915ul), mk_sl_cui_uint64_c(0xc67178f2ul, 0xe372532bul),
	mk_sl_cui_uint64_c(0xca273eceul, 0xea26619cul), mk_sl_cui_uint64_c(0xd186b8c7ul, 0x21c0c207ul), mk_sl_cui_uint64_c(0xeada7dd6ul, 0xcde0eb1eul), mk_sl_cui_uint64_c(0xf57d4f7ful, 0xee6ed178ul),
	mk_sl_cui_uint64_c(0x06f067aaul, 0x72176fbaul), mk_sl_cui_uint64_c(0x0a637dc5ul, 0xa2c898a6ul), mk_sl_cui_uint64_c(0x113f9804ul, 0xbef90daeul), mk_sl_cui_uint64_c(0x1b710b35ul, 0x131c471bul),
	mk_sl_cui_uint64_c(0x28db77f5ul, 0x23047d84ul), mk_sl_cui_uint64_c(0x32caab7bul, 0x40c72493ul), mk_sl_cui_uint64_c(0x3c9ebe0aul, 0x15c9bebcul), mk_sl_cui_uint64_c(0x431d67c4ul, 0x9c100d4cul),
	mk_sl_cui_uint64_c(0x4cc5d4beul, 0xcb3e42b6ul), mk_sl_cui_uint64_c(0x597f299cul, 0xfc657e2aul), mk_sl_cui_uint64_c(0x5fcb6fabul, 0x3ad6faecul), mk_sl_cui_uint64_c(0x6c44198cul, 0x4a475817ul),
}}};


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_c_ch(mk_sl_cui_uint64_pct const x, mk_sl_cui_uint64_pct const y, mk_sl_cui_uint64_pct const z, mk_sl_cui_uint64_pt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tb mk_lang_constexpr_init;

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

	mk_sl_cui_uint64_and3(x, y, &ta);
	mk_sl_cui_uint64_not2(x, &tb);
	mk_sl_cui_uint64_and2(&tb, z);
	mk_sl_cui_uint64_or3(&ta, &tb, ret);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_c_maj(mk_sl_cui_uint64_pct const x, mk_sl_cui_uint64_pct const y, mk_sl_cui_uint64_pct const z, mk_sl_cui_uint64_pt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tc mk_lang_constexpr_init;

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

	mk_sl_cui_uint64_and3(x, y, &ta);
	mk_sl_cui_uint64_and3(x, z, &tb);
	mk_sl_cui_uint64_and3(y, z, &tc);
	mk_sl_cui_uint64_xor2(&ta, &tb);
	mk_sl_cui_uint64_xor3(&ta, &tc, ret);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_c_sum0(mk_sl_cui_uint64_pct const x, mk_sl_cui_uint64_pt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tb mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(ret);
	mk_lang_assert(x != ret);

	/* return rotr(x, 28) ^ rotr(x, 34) ^ rotr(x, 39); */

	mk_sl_cui_uint64_rotr3(x, 28, &ta);
	mk_sl_cui_uint64_rotr3(x, 34, &tb);
	mk_sl_cui_uint64_xor2(&ta, &tb);
	mk_sl_cui_uint64_rotr3(x, 39, &tb);
	mk_sl_cui_uint64_xor3(&ta, &tb, ret);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_c_sum1(mk_sl_cui_uint64_pct const x, mk_sl_cui_uint64_pt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tb mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(ret);
	mk_lang_assert(x != ret);

	/* return rotr(x, 14) ^ rotr(x, 18) ^ rotr(x, 41); */

	mk_sl_cui_uint64_rotr3(x, 14, &ta);
	mk_sl_cui_uint64_rotr3(x, 18, &tb);
	mk_sl_cui_uint64_xor2(&ta, &tb);
	mk_sl_cui_uint64_rotr3(x, 41, &tb);
	mk_sl_cui_uint64_xor3(&ta, &tb, ret);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_c_sig0(mk_sl_cui_uint64_pct const x, mk_sl_cui_uint64_pt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tb mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(ret);
	mk_lang_assert(x != ret);

	/* return rotr(x, 1) ^ rotr(x, 8) ^ shr(x, 7); */

	mk_sl_cui_uint64_rotr3(x, 1, &ta);
	mk_sl_cui_uint64_rotr3(x, 8, &tb);
	mk_sl_cui_uint64_xor2(&ta, &tb);
	mk_sl_cui_uint64_shr3(x, 7, &tb);
	mk_sl_cui_uint64_xor3(&ta, &tb, ret);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_c_sig1(mk_sl_cui_uint64_pct const x, mk_sl_cui_uint64_pt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tb mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(ret);
	mk_lang_assert(x != ret);

	/* return rotr(x, 19) ^ rotr(x, 61) ^ shr(x, 6); */

	mk_sl_cui_uint64_rotr3(x, 19, &ta);
	mk_sl_cui_uint64_rotr3(x, 61, &tb);
	mk_sl_cui_uint64_xor2(&ta, &tb);
	mk_sl_cui_uint64_shr3(x, 6, &tb);
	mk_sl_cui_uint64_xor3(&ta, &tb, ret);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_c_init(mk_lib_crypto_hash_block_sha2_base_64bit_c_pt const sha2_base_64bit_c, mk_sl_cui_uint64_pct const iv) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint128_t) == 16);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_base_64bit_c_block_t) == 128);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_base_64bit_c_digest_t) == 64);

	mk_lang_assert(sha2_base_64bit_c);

	sha2_base_64bit_c->m_hs[0] = iv[0];
	sha2_base_64bit_c->m_hs[1] = iv[1];
	sha2_base_64bit_c->m_hs[2] = iv[2];
	sha2_base_64bit_c->m_hs[3] = iv[3];
	sha2_base_64bit_c->m_hs[4] = iv[4];
	sha2_base_64bit_c->m_hs[5] = iv[5];
	sha2_base_64bit_c->m_hs[6] = iv[6];
	sha2_base_64bit_c->m_hs[7] = iv[7];
	mk_sl_cui_uint128_set_zero(&sha2_base_64bit_c->m_len);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_c_append_blocks(mk_lib_crypto_hash_block_sha2_base_64bit_c_pt const sha2_base_64bit_c, mk_lib_crypto_hash_block_sha2_base_64bit_c_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_sl_cui_uint128_t tt mk_lang_constexpr_init;
	mk_sl_cui_uint64_t oldh[8] mk_lang_constexpr_init;
	mk_sl_cui_uint64_t hh[8] mk_lang_constexpr_init;
	mk_sl_cui_uint64_pt a mk_lang_constexpr_init;
	mk_sl_cui_uint64_pt b mk_lang_constexpr_init;
	mk_sl_cui_uint64_pt c mk_lang_constexpr_init;
	mk_sl_cui_uint64_pt d mk_lang_constexpr_init;
	mk_sl_cui_uint64_pt e mk_lang_constexpr_init;
	mk_sl_cui_uint64_pt f mk_lang_constexpr_init;
	mk_sl_cui_uint64_pt g mk_lang_constexpr_init;
	mk_sl_cui_uint64_pt h mk_lang_constexpr_init;
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint64_t w[80] mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint64_t t1 mk_lang_constexpr_init;
	mk_sl_cui_uint64_t t2 mk_lang_constexpr_init;

	mk_lang_assert(sha2_base_64bit_c);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha2_base_64bit_c_block_len);

	mk_sl_cui_uint128_from_bi_usize(&tt, &nblocks);
	mk_lang_assert(!mk_sl_cui_uint128_would_overflow_add_cc(&sha2_base_64bit_c->m_len, &tt));
	mk_sl_cui_uint128_add2_wrap_cid_cod(&sha2_base_64bit_c->m_len, &tt);
	oldh[0] = sha2_base_64bit_c->m_hs[0];
	oldh[1] = sha2_base_64bit_c->m_hs[1];
	oldh[2] = sha2_base_64bit_c->m_hs[2];
	oldh[3] = sha2_base_64bit_c->m_hs[3];
	oldh[4] = sha2_base_64bit_c->m_hs[4];
	oldh[5] = sha2_base_64bit_c->m_hs[5];
	oldh[6] = sha2_base_64bit_c->m_hs[6];
	oldh[7] = sha2_base_64bit_c->m_hs[7];
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
			mk_sl_uint_64_from_8_be(&w[i], &pblocks[iblock].m_uint8s[i * 8]);
		}
		for(i = 16; i != 80; ++i)
		{
			/* w[i] = sig1(w[i - 2]) + w[i - 7] + sig0(w[i - 15]) + w[i - 16]; */
			mk_lib_crypto_hash_block_sha2_base_64bit_c_sig1(&w[i - 2], &ta);
			mk_lib_crypto_hash_block_sha2_base_64bit_c_sig0(&w[i - 15], &tb);
			mk_sl_cui_uint64_add2_wrap_cid_cod(&ta, &w[i - 7]);
			mk_sl_cui_uint64_add2_wrap_cid_cod(&tb, &w[i - 16]);
			mk_sl_cui_uint64_add3_wrap_cid_cod(&ta, &tb, &w[i]);
		}
		for(i = 0; i != 80; ++i)
		{
			/* t1 = h + sum1(e) + ch(e, f, g) + table[i] + w[i]; */
			mk_lib_crypto_hash_block_sha2_base_64bit_c_sum1(e, &ta);
			mk_lib_crypto_hash_block_sha2_base_64bit_c_ch(e, f, g, &tb);
			mk_sl_cui_uint64_add2_wrap_cid_cod(&ta, h);
			mk_sl_cui_uint64_add2_wrap_cid_cod(&tb, &s_mk_lib_crypto_hash_block_sha2_base_64bit_c_table.m_data.m_uint64s[i]);
			mk_sl_cui_uint64_add2_wrap_cid_cod(&tb, &w[i]);
			mk_sl_cui_uint64_add3_wrap_cid_cod(&ta, &tb, &t1);
			/* t2 = sum0(a) + maj(a, b, c); */
			mk_lib_crypto_hash_block_sha2_base_64bit_c_sum0(a, &ta);
			mk_lib_crypto_hash_block_sha2_base_64bit_c_maj(a, b, c, &tb);
			mk_sl_cui_uint64_add3_wrap_cid_cod(&ta, &tb, &t2);
			*h = *g;
			*g = *f;
			*f = *e;
			mk_sl_cui_uint64_add3_wrap_cid_cod(d, &t1, e);
			*d = *c;
			*c = *b;
			*b = *a;
			mk_sl_cui_uint64_add3_wrap_cid_cod(&t1, &t2, a);
		}
		mk_sl_cui_uint64_add2_wrap_cid_cod(&oldh[0], &hh[0]);
		mk_sl_cui_uint64_add2_wrap_cid_cod(&oldh[1], &hh[1]);
		mk_sl_cui_uint64_add2_wrap_cid_cod(&oldh[2], &hh[2]);
		mk_sl_cui_uint64_add2_wrap_cid_cod(&oldh[3], &hh[3]);
		mk_sl_cui_uint64_add2_wrap_cid_cod(&oldh[4], &hh[4]);
		mk_sl_cui_uint64_add2_wrap_cid_cod(&oldh[5], &hh[5]);
		mk_sl_cui_uint64_add2_wrap_cid_cod(&oldh[6], &hh[6]);
		mk_sl_cui_uint64_add2_wrap_cid_cod(&oldh[7], &hh[7]);
	}
	sha2_base_64bit_c->m_hs[0] = oldh[0];
	sha2_base_64bit_c->m_hs[1] = oldh[1];
	sha2_base_64bit_c->m_hs[2] = oldh[2];
	sha2_base_64bit_c->m_hs[3] = oldh[3];
	sha2_base_64bit_c->m_hs[4] = oldh[4];
	sha2_base_64bit_c->m_hs[5] = oldh[5];
	sha2_base_64bit_c->m_hs[6] = oldh[6];
	sha2_base_64bit_c->m_hs[7] = oldh[7];
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_c_finish(mk_lib_crypto_hash_block_sha2_base_64bit_c_pt const sha2_base_64bit_c, mk_lib_crypto_hash_block_sha2_base_64bit_c_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_sha2_base_64bit_c_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_types_uint_t tui mk_lang_constexpr_init;
	mk_sl_cui_uint128_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint128_t tb mk_lang_constexpr_init;
	mk_lang_types_sint_t rest mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(sha2_base_64bit_c);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_sha2_base_64bit_c_block_len);
	mk_lang_assert(digest);

	tui = mk_lib_crypto_hash_block_sha2_base_64bit_c_block_len;
	mk_sl_cui_uint128_from_bi_uint(&ta, &tui);
	mk_lang_assert(!mk_sl_cui_uint128_would_overflow_mul(&sha2_base_64bit_c->m_len, &ta));
	mk_sl_cui_uint128_shl3(&sha2_base_64bit_c->m_len, 7, &ta);
	mk_sl_cui_uint128_from_bi_sint(&tb, &idx);
	mk_lang_assert(!mk_sl_cui_uint128_would_overflow_add_cc(&ta, &tb));
	mk_sl_cui_uint128_add2_wrap_cid_cod(&ta, &tb);
	tui = 8;
	mk_sl_cui_uint128_from_bi_uint(&tb, &tui);
	mk_lang_assert(!mk_sl_cui_uint128_would_overflow_mul(&ta, &tb));
	mk_sl_cui_uint128_shl2(&ta, 3);
	tui = 0x80;
	mk_sl_cui_uint8_from_bi_uint(&block->m_uint8s[idx], &tui);
	rest = mk_lib_crypto_hash_block_sha2_base_64bit_c_block_len - idx - 1;
	if(rest >= 16)
	{
		for(i = 0; i != rest - 16; ++i)
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
		mk_lib_crypto_hash_block_sha2_base_64bit_c_append_blocks(sha2_base_64bit_c, block, 1);
		for(i = 0; i != mk_lib_crypto_hash_block_sha2_base_64bit_c_block_len - 16; ++i)
		{
			mk_sl_cui_uint8_set_zero(&block->m_uint8s[i]);
		}
	}
	mk_sl_uint_128_to_8_be(&ta, &block->m_uint8s[mk_lib_crypto_hash_block_sha2_base_64bit_c_block_len - 16]);
	mk_lib_crypto_hash_block_sha2_base_64bit_c_append_blocks(sha2_base_64bit_c, block, 1);
	for(i = 0; i != 8; ++i)
	{
		mk_sl_uint_64_to_8_be(&sha2_base_64bit_c->m_hs[i], &digest->m_uint8s[i * 8]);
	}
}
