#include "mk_lib_crypto_hash_block_blake3.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_blake3_base.h"

#define mk_lang_memcpy_t_name mk_lib_crypto_hash_block_blake3_memcpy_u8
#define mk_lang_memcpy_t_type mk_sl_cui_uint8_t
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_init(mk_lib_crypto_hash_block_blake3_pt const blake3) mk_lang_noexcept
{
	mk_lang_assert(blake3);

	mk_lib_crypto_hash_block_blake3_base_init(&blake3->m_base);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_append_blocks(mk_lib_crypto_hash_block_blake3_pt const blake3, mk_lib_crypto_hash_block_blake3_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(blake3);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0 && nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_blake3_block_len);

	mk_lib_crypto_hash_block_blake3_base_append_blocks(&blake3->m_base, pblocks, nblocks);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_finish(mk_lib_crypto_hash_block_blake3_pt const blake3, mk_lib_crypto_hash_block_blake3_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_blake3_digest_pt const digest) mk_lang_noexcept
{
	mk_sl_cui_uint64_t seek mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_blake3_base_output_block_t output_block mk_lang_constexpr_init;

	mk_lang_assert(blake3);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx <= mk_lib_crypto_hash_block_blake3_block_len);
	mk_lang_assert(digest);

	mk_sl_cui_uint64_set_zero(&seek);
	mk_lib_crypto_hash_block_blake3_base_finish(&blake3->m_base, block, idx);
	mk_lib_crypto_hash_block_blake3_base_squeeze(&blake3->m_base, block, &seek, &output_block);
	mk_lib_crypto_hash_block_blake3_memcpy_u8_fn(&digest->m_uint8s[0], &output_block.m_uint8s[0], mk_lib_crypto_hash_block_blake3_digest_len);
}
