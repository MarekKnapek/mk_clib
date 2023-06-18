#include "mk_lib_crypto_hash_block_sha2_256.h"

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
#include "mk_lib_crypto_hash_block_sha2_32bit.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


mk_lang_constexpr_static_inline mk_sl_cui_uint32_t const s_mk_lib_crypto_hash_block_sha2_256_init[8] =
{
	{{ 0x6a09e667ul }},
	{{ 0xbb67ae85ul }},
	{{ 0x3c6ef372ul }},
	{{ 0xa54ff53aul }},
	{{ 0x510e527ful }},
	{{ 0x9b05688cul }},
	{{ 0x1f83d9abul }},
	{{ 0x5be0cd19ul }},
};


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha2_256_init(mk_lib_crypto_hash_block_sha2_256_pt const sha2_256) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_256_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_256_digest_t) == 32);

	mk_lang_assert(sha2_256);

	mk_lib_crypto_hash_block_sha2_32bit_init(&sha2_256->m_32bit, s_mk_lib_crypto_hash_block_sha2_256_init);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha2_256_append_blocks(mk_lib_crypto_hash_block_sha2_256_pt const sha2_256, mk_lib_crypto_hash_block_sha2_256_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(sha2_256);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha2_256_block_len);

	mk_lib_crypto_hash_block_sha2_32bit_append_blocks(&sha2_256->m_32bit, pblocks, nblocks);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha2_256_finish(mk_lib_crypto_hash_block_sha2_256_pt const sha2_256, mk_lib_crypto_hash_block_sha2_256_block_pt const block, int const idx, mk_lib_crypto_hash_block_sha2_256_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_assert(sha2_256);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_sha2_256_block_len);
	mk_lang_assert(digest);

	mk_lib_crypto_hash_block_sha2_32bit_finish(&sha2_256->m_32bit, block, idx, digest);
}
