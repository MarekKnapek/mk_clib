#include "mk_lib_crypto_hash_block_blake2s_128.h"

/* rfc 7693 */

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_blake2s_base.h"


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake2s_128_init(mk_lib_crypto_hash_block_blake2s_128_pt const blake2s_128) mk_lang_noexcept
{
	mk_lang_assert(blake2s_128);

	mk_lib_crypto_hash_block_blake2s_base_init(&blake2s_128->m_blake2s_base, mk_lib_crypto_hash_block_blake2s_128_digest_len, 0, 1, 1, 0, 0, 0, 0, 0, mk_lang_null, 0, mk_lang_null, 0);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake2s_128_append_blocks(mk_lib_crypto_hash_block_blake2s_128_pt const blake2s_128, mk_lib_crypto_hash_block_blake2s_128_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(blake2s_128);

	mk_lib_crypto_hash_block_blake2s_base_append_blocks(&blake2s_128->m_blake2s_base, pblocks, nblocks);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake2s_128_finish(mk_lib_crypto_hash_block_blake2s_128_pt const blake2s_128, mk_lib_crypto_hash_block_blake2s_128_block_pt const block, int const idx, mk_lib_crypto_hash_block_blake2s_128_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_blake2s_base_digest_t base_digest mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(blake2s_128);

	mk_lib_crypto_hash_block_blake2s_base_finish(&blake2s_128->m_blake2s_base, block, idx, &base_digest);
	for(i = 0; i != mk_lib_crypto_hash_block_blake2s_128_digest_len; ++i){ digest->m_uint8s[i] = base_digest.m_uint8s[i]; }
}
