#include "mk_lib_crypto_hash_block_streebog_256.h"

/* http://tc26.ru/research/polozhenie/GOST_R_34_11-2012_eng.pdf */

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_streebog_base.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


typedef mk_lib_crypto_hash_block_streebog_base_aligned64b_t mk_lib_crypto_hash_block_streebog_256_block2_t;
typedef mk_lib_crypto_hash_block_streebog_256_block2_t const mk_lib_crypto_hash_block_streebog_256_block2_ct;
typedef mk_lib_crypto_hash_block_streebog_256_block2_t* mk_lib_crypto_hash_block_streebog_256_block2_pt;
typedef mk_lib_crypto_hash_block_streebog_256_block2_t const* mk_lib_crypto_hash_block_streebog_256_block2_pct;


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_256_init(mk_lib_crypto_hash_block_streebog_256_pt const streebog_256) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_sl_cui_uint64_t const s_init = mk_sl_cui_uint64_c(0x01010101ul, 0x01010101ul);

	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_streebog_256_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_streebog_256_block2_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_streebog_256_digest_t) == 32);

	mk_lang_assert(streebog_256);

	for(i = 0; i != 8; ++i)
	{
		streebog_256->m_base.m_h.m_uint64s[i] = s_init;
	}
	mk_lib_crypto_hash_block_streebog_base_block2_set_zero(&streebog_256->m_base.m_n);
	mk_lib_crypto_hash_block_streebog_base_block2_set_zero(&streebog_256->m_base.m_s);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_256_append_blocks(mk_lib_crypto_hash_block_streebog_256_pt const streebog_256, mk_lib_crypto_hash_block_streebog_256_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(streebog_256);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_streebog_256_block_len);

	mk_lib_crypto_hash_block_streebog_base_append_blocks(&streebog_256->m_base, pblocks, nblocks);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_256_finish(mk_lib_crypto_hash_block_streebog_256_pt const streebog_256, mk_lib_crypto_hash_block_streebog_256_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_streebog_256_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(streebog_256);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_streebog_256_block_len);
	mk_lang_assert(digest);

	mk_lib_crypto_hash_block_streebog_base_stage_3(&streebog_256->m_base, block, idx);
	for(i = 0; i != 4; ++i)
	{
		mk_sl_uint_64_to_8_le(&streebog_256->m_base.m_h.m_uint64s[4 + i], &digest->m_uint8s[i * 8]);
	}
}
