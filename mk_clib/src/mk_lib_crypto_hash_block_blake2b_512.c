#include "mk_lib_crypto_hash_block_blake2b_512.h"

/* rfc 7693 */

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_blake2b_base.h"


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake2b_512_init(mk_lib_crypto_hash_block_blake2b_512_pt const blake2b_512) mk_lang_noexcept
{
	mk_lang_assert(blake2b_512);

	mk_lib_crypto_hash_block_blake2b_base_init(&blake2b_512->m_blake2b_512_base, mk_lib_crypto_hash_block_blake2b_512_digest_len, 0, 1, 1, 0, 0, 0, 0, 0, mk_lang_null, 0, mk_lang_null, 0);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake2b_512_append_blocks(mk_lib_crypto_hash_block_blake2b_512_pt const blake2b_512, mk_lib_crypto_hash_block_blake2b_512_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(blake2b_512);

	mk_lib_crypto_hash_block_blake2b_base_append_blocks(&blake2b_512->m_blake2b_512_base, pblocks, nblocks);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake2b_512_finish(mk_lib_crypto_hash_block_blake2b_512_pt const blake2b_512, mk_lib_crypto_hash_block_blake2b_512_block_pt const block, int const idx, mk_lib_crypto_hash_block_blake2b_512_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_assert(blake2b_512);

	mk_lib_crypto_hash_block_blake2b_base_finish(&blake2b_512->m_blake2b_512_base, block, idx, digest);
}
