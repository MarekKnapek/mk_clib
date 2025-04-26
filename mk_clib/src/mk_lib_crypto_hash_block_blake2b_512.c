#ifndef mk_include_guard_mk_lib_crypto_hash_block_blake2b_512_c
#define mk_include_guard_mk_lib_crypto_hash_block_blake2b_512_c
#include "mk_lib_crypto_hash_block_blake2b_512.h"

/* RFC 7693 */

#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_bitops_bulk.h"
#include "mk_lib_crypto_hash_block_blake2b_base.h"
#include "mk_sl_cui_uint8.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_blake2b_512_init(mk_lib_crypto_hash_block_blake2b_512_pt const blake2b_512) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_blake2b_512_block_t) == 128);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_blake2b_512_digest_t) == 64);

	mk_lang_assert(blake2b_512);

	mk_lib_crypto_hash_block_blake2b_base_init(&blake2b_512->m_blake2b_base, mk_lib_crypto_hash_block_blake2b_512_digest_len_v, 0, 1, 1, 0, 0, 0, 0, 0, mk_lang_null, 0, mk_lang_null, 0);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_blake2b_512_append_blocks(mk_lib_crypto_hash_block_blake2b_512_pt const blake2b_512, mk_lib_crypto_hash_block_blake2b_512_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(blake2b_512);

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_blake2b_512_block_t) == sizeof(mk_lib_crypto_hash_block_blake2b_base_block_t));
		mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_hash_block_blake2b_512_block_t) == mk_lang_alignof(mk_lib_crypto_hash_block_blake2b_base_block_t));
		mk_lib_crypto_hash_block_blake2b_base_append_blocks(&blake2b_512->m_blake2b_base, ((mk_lib_crypto_hash_block_blake2b_base_block_pct)(pblocks)), nblocks);
	}
	else
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		mk_lang_types_usize_t i mk_lang_constexpr_init;
		mk_lib_crypto_hash_block_blake2b_base_block_t base_block mk_lang_constexpr_init;
		n = nblocks;
		for(i = 0; i != n; ++i)
		{
			mk_lib_crypto_bitops_bulk_uint8_128_memcpy(&base_block.m_data.m_uint8s[0], &pblocks[i].m_data.m_uint8s[0]);
			mk_lib_crypto_hash_block_blake2b_base_append_blocks(&blake2b_512->m_blake2b_base, &base_block, 1);
		}
		#include "mk_lang_warning_clang_pop.h"
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_blake2b_512_finish(mk_lib_crypto_hash_block_blake2b_512_pt const blake2b_512, mk_lib_crypto_hash_block_blake2b_512_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_blake2b_512_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_blake2b_base_digest_t base_digest mk_lang_constexpr_init;

	mk_lang_assert(blake2b_512);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx <= mk_lib_crypto_hash_block_blake2b_512_block_len_v);
	mk_lang_assert(digest);

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_blake2b_512_block_t) == sizeof(mk_lib_crypto_hash_block_blake2b_base_block_t));
		mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_hash_block_blake2b_512_block_t) == mk_lang_alignof(mk_lib_crypto_hash_block_blake2b_base_block_t));
		mk_lib_crypto_hash_block_blake2b_base_finish(&blake2b_512->m_blake2b_base, ((mk_lib_crypto_hash_block_blake2b_base_block_pt)(block)), idx, &base_digest);
	}
	else
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
		mk_lib_crypto_hash_block_blake2b_base_block_t base_block mk_lang_constexpr_init;
		mk_sl_cui_uint8_memcpy_fn(&base_block.m_data.m_uint8s[0], &block->m_data.m_uint8s[0], ((mk_lang_types_usize_t)(idx)));
		mk_lib_crypto_hash_block_blake2b_base_finish(&blake2b_512->m_blake2b_base, &base_block, idx, &base_digest);
		#include "mk_lang_warning_clang_pop.h"
	}
	mk_sl_cui_uint8_memcpy_fn(&digest->m_data.m_uint8s[0], &base_digest.m_data.m_uint8s[0], mk_lib_crypto_hash_block_blake2b_512_digest_len_v);
}


#endif
