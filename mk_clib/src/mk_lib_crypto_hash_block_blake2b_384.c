#include "mk_lib_crypto_hash_block_blake2b_384.h"

/* rfc 7693 */

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_blake2b_base.h"


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake2b_384_init(mk_lib_crypto_hash_block_blake2b_384_pt const blake2b_384) mk_lang_noexcept
{
	mk_lang_assert(blake2b_384);

	mk_lib_crypto_hash_block_blake2b_base_init(&blake2b_384->m_blake2b_384_base, mk_lib_crypto_hash_block_blake2b_384_digest_len, 0, 1, 1, 0, 0, 0, 0, 0, mk_lang_null, 0, mk_lang_null, 0);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake2b_384_append_blocks(mk_lib_crypto_hash_block_blake2b_384_pt const blake2b_384, mk_lib_crypto_hash_block_blake2b_384_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(blake2b_384);

	mk_lib_crypto_hash_block_blake2b_base_append_blocks(&blake2b_384->m_blake2b_384_base, pblocks, nblocks);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake2b_384_finish(mk_lib_crypto_hash_block_blake2b_384_pt const blake2b_384, mk_lib_crypto_hash_block_blake2b_384_block_pt const block, int const idx, mk_lib_crypto_hash_block_blake2b_384_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_blake2b_base_digest_t base_digest mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(blake2b_384);

	mk_lib_crypto_hash_block_blake2b_base_finish(&blake2b_384->m_blake2b_384_base, block, idx, &base_digest);
	for(i = 0; i != mk_lib_crypto_hash_block_blake2b_384_digest_len; ++i){ digest->m_uint8s[i] = base_digest.m_uint8s[i]; }
}
