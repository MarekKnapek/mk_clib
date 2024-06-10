#include "mk_lib_crypto_xof_block_blake3.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_blake3_base.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"

#define mk_lang_memcpy_t_name mk_lib_crypto_xof_block_blake3_memcpy_u8
#define mk_lang_memcpy_t_type mk_sl_cui_uint8_t
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_blake3_init(mk_lib_crypto_xof_block_blake3_pt const blake3) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_xof_block_blake3_block_t) == 64);

	mk_lang_assert(blake3);

	mk_lib_crypto_hash_block_blake3_base_init(&blake3->m_blake3);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_blake3_append_blocks(mk_lib_crypto_xof_block_blake3_pt const blake3, mk_lib_crypto_xof_block_blake3_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(blake3);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_xof_block_blake3_block_len);

	mk_lib_crypto_hash_block_blake3_base_append_blocks(&blake3->m_blake3, pblocks, nblocks);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_blake3_finish(mk_lib_crypto_xof_block_blake3_pt const blake3, mk_lib_crypto_xof_block_blake3_block_pt const block, mk_lang_types_sint_t const idx) mk_lang_noexcept
{
	mk_lang_assert(blake3);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_xof_block_blake3_block_len);

	mk_lib_crypto_hash_block_blake3_base_finish(&blake3->m_blake3, block, idx);
	blake3->m_block = *block;
	blake3->m_idx = 0;
	mk_sl_cui_uint64_set_zero(&blake3->m_seek);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_blake3_squeeze(mk_lib_crypto_xof_block_blake3_pt const blake3, mk_lang_types_usize_t const len, mk_sl_cui_uint8_pt const digest) mk_lang_noexcept
{
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out mk_lang_constexpr_init;
	mk_lang_types_usize_t copy mk_lang_constexpr_init;

	mk_lang_assert(blake3);
	mk_lang_assert(len >= 0);
	mk_lang_assert(digest);

	rem = len;
	out = digest;
	while(rem != 0)
	{
		if(blake3->m_idx == 0)
		{
			mk_lib_crypto_hash_block_blake3_base_squeeze(&blake3->m_blake3, &blake3->m_block, &blake3->m_seek, &blake3->m_output_block);
			mk_sl_cui_uint64_inc1(&blake3->m_seek);
		}
		copy = mk_lang_min(rem, ((mk_lang_types_usize_t)(mk_lib_crypto_hash_block_blake3_base_output_block_len - blake3->m_idx)));
		mk_lib_crypto_xof_block_blake3_memcpy_u8_fn(out, &blake3->m_output_block.m_uint8s[blake3->m_idx], copy);
		blake3->m_idx = (blake3->m_idx + copy) % mk_lib_crypto_hash_block_blake3_base_output_block_len;
		rem -= copy;
		out += copy;
	}
}
