#include "mk_lib_crypto_hash_block_sha2_512_224.h"

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


mk_lang_constexpr_static_inline mk_sl_cui_uint64_t const s_mk_lib_crypto_hash_block_sha2_512_224_init[8] =
{
	mk_sl_cui_uint64_c(0x8c3d37c8ul, 0x19544da2ul),
	mk_sl_cui_uint64_c(0x73e19966ul, 0x89dcd4d6ul),
	mk_sl_cui_uint64_c(0x1dfab7aeul, 0x32ff9c82ul),
	mk_sl_cui_uint64_c(0x679dd514ul, 0x582f9fcful),
	mk_sl_cui_uint64_c(0x0f6d2b69ul, 0x7bd44da8ul),
	mk_sl_cui_uint64_c(0x77e36f73ul, 0x04c48942ul),
	mk_sl_cui_uint64_c(0x3f9d85a8ul, 0x6a1d36c8ul),
	mk_sl_cui_uint64_c(0x1112e6adul, 0x91d692a1ul),
};


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha2_512_224_init(mk_lib_crypto_hash_block_sha2_512_224_pt const sha2_512_224) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint128_t) == 16);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_512_224_block_t) == 128);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_512_224_digest_t) >= 28);

	mk_lang_assert(sha2_512_224);

	mk_lib_crypto_hash_block_sha2_64bit_init(&sha2_512_224->m_64bit, s_mk_lib_crypto_hash_block_sha2_512_224_init);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha2_512_224_append_blocks(mk_lib_crypto_hash_block_sha2_512_224_pt const sha2_512_224, mk_lib_crypto_hash_block_sha2_512_224_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(sha2_512_224);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha2_512_224_block_len);

	mk_lib_crypto_hash_block_sha2_64bit_append_blocks(&sha2_512_224->m_64bit, pblocks, nblocks);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha2_512_224_finish(mk_lib_crypto_hash_block_sha2_512_224_pt const sha2_512_224, mk_lib_crypto_hash_block_sha2_512_224_block_pt const block, int const idx, mk_lib_crypto_hash_block_sha2_512_224_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_sha2_64bit_digest_t dgst mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(sha2_512_224);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < 128);
	mk_lang_assert(digest);

	mk_lib_crypto_hash_block_sha2_64bit_finish(&sha2_512_224->m_64bit, block, idx, &dgst);
	for(i = 0; i != 28; ++i)
	{
		digest->m_uint8s[i] = dgst.m_uint8s[i];
	}
}
