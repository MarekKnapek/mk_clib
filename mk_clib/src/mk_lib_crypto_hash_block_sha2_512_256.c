#include "mk_lib_crypto_hash_block_sha2_512_256.h"

/* nist fips pub 180-4 */

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_sha2_64bit.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint128.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


mk_lang_constexpr_static_inline mk_sl_cui_uint64_t const s_mk_lib_crypto_hash_block_sha2_512_256_init[8] =
{
	mk_sl_cui_uint64_c(0x22312194ul, 0xfc2bf72cul),
	mk_sl_cui_uint64_c(0x9f555fa3ul, 0xc84c64c2ul),
	mk_sl_cui_uint64_c(0x2393b86bul, 0x6f53b151ul),
	mk_sl_cui_uint64_c(0x96387719ul, 0x5940eabdul),
	mk_sl_cui_uint64_c(0x96283ee2ul, 0xa88effe3ul),
	mk_sl_cui_uint64_c(0xbe5e1e25ul, 0x53863992ul),
	mk_sl_cui_uint64_c(0x2b0199fcul, 0x2c85b8aaul),
	mk_sl_cui_uint64_c(0x0eb72ddcul, 0x81c52ca2ul),
};


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha2_512_256_init(mk_lib_crypto_hash_block_sha2_512_256_pt const sha2_512_256) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint128_t) == 16);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_512_256_block_t) == 128);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_512_256_digest_t) == 32);

	mk_lang_assert(sha2_512_256);

	mk_lib_crypto_hash_block_sha2_64bit_init(&sha2_512_256->m_64bit, s_mk_lib_crypto_hash_block_sha2_512_256_init);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha2_512_256_append_blocks(mk_lib_crypto_hash_block_sha2_512_256_pt const sha2_512_256, mk_lib_crypto_hash_block_sha2_512_256_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(sha2_512_256);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha2_512_256_block_len);

	mk_lib_crypto_hash_block_sha2_64bit_append_blocks(&sha2_512_256->m_64bit, pblocks, nblocks);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha2_512_256_finish(mk_lib_crypto_hash_block_sha2_512_256_pt const sha2_512_256, mk_lib_crypto_hash_block_sha2_512_256_block_pt const block, int const idx, mk_lib_crypto_hash_block_sha2_512_256_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_sha2_64bit_digest_t dgst mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(sha2_512_256);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_sha2_512_256_block_len);
	mk_lang_assert(digest);

	mk_lib_crypto_hash_block_sha2_64bit_finish(&sha2_512_256->m_64bit, block, idx, &dgst);
	for(i = 0; i != mk_lib_crypto_hash_block_sha2_512_256_digest_len; ++i)
	{
		digest->m_uint8s[i] = dgst.m_uint8s[i];
	}
}
