#ifndef mk_include_guard_mk_lib_crypto_xof_block_blake3_c
#define mk_include_guard_mk_lib_crypto_xof_block_blake3_c
#include "mk_lib_crypto_xof_block_blake3.h"

#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_bitops_bulk.h"
#include "mk_lib_crypto_hash_block_blake3_base.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_blake3_init(mk_lib_crypto_xof_block_blake3_pt const blake3) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_xof_block_blake3_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_xof_block_blake3_digest_t) == 64);

	mk_lang_assert(blake3);

	mk_sl_cui_uint64_set_zero(&blake3->m_seek);
	mk_lib_crypto_hash_block_blake3_base_init(&blake3->m_blake3_base);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_blake3_append_blocks(mk_lib_crypto_xof_block_blake3_pt const blake3, mk_lib_crypto_xof_block_blake3_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(blake3);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_xof_block_blake3_block_len_v);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_static_assert(sizeof(mk_lib_crypto_xof_block_blake3_block_t) == sizeof(mk_lib_crypto_hash_block_blake3_base_block_t));
		mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_xof_block_blake3_block_t) == mk_lang_alignof(mk_lib_crypto_hash_block_blake3_base_block_t));
		mk_lib_crypto_hash_block_blake3_base_append_blocks(&blake3->m_blake3_base, ((mk_lib_crypto_hash_block_blake3_base_block_pct)(pblocks)), nblocks);
	}
	else
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		mk_lang_types_usize_t i mk_lang_constexpr_init;
		mk_lib_crypto_hash_block_blake3_base_block_t base_block mk_lang_constexpr_init;
		n = nblocks;
		for(i = 0; i != n; ++i)
		{
			mk_lib_crypto_bitops_bulk_uint8_64_memcpy(&base_block.m_data.m_uint8s[0], &pblocks[i].m_data.m_uint8s[0]);
			mk_lib_crypto_hash_block_blake3_base_append_blocks(&blake3->m_blake3_base, &base_block, 1);
		}
		#include "mk_lang_warning_clang_pop.h"
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_blake3_finish(mk_lib_crypto_xof_block_blake3_pt const blake3, mk_lib_crypto_xof_block_blake3_block_pt const block, mk_lang_types_sint_t const idx) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(blake3);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx <= mk_lib_crypto_xof_block_blake3_block_len_v);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_static_assert(sizeof(mk_lib_crypto_xof_block_blake3_block_t) == sizeof(mk_lib_crypto_hash_block_blake3_base_block_t));
		mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_xof_block_blake3_block_t) == mk_lang_alignof(mk_lib_crypto_hash_block_blake3_base_block_t));
		mk_lib_crypto_hash_block_blake3_base_finish(&blake3->m_blake3_base, ((mk_lib_crypto_hash_block_blake3_base_block_pt)(block)), idx);
		blake3->m_block = *block;
	}
	else
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
		mk_lib_crypto_hash_block_blake3_base_block_t base_block mk_lang_constexpr_init;
		mk_sl_cui_uint8_memcpy_fn(&base_block.m_data.m_uint8s[0], &block->m_data.m_uint8s[0], ((mk_lang_types_usize_t)(idx)));
		mk_lib_crypto_hash_block_blake3_base_finish(&blake3->m_blake3_base, &base_block, idx);
		mk_lib_crypto_bitops_bulk_uint8_64_memcpy(&blake3->m_block.m_data.m_uint8s[0], &base_block.m_data.m_uint8s[0]);
		#include "mk_lang_warning_clang_pop.h"
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_blake3_squeeze_block(mk_lib_crypto_xof_block_blake3_pt const blake3, mk_lib_crypto_xof_block_blake3_digest_pt const digest) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(blake3);
	mk_lang_assert(digest);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_static_assert(sizeof(mk_lib_crypto_xof_block_blake3_digest_t) == sizeof(mk_lib_crypto_hash_block_blake3_base_digest_t));
		mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_xof_block_blake3_digest_t) == mk_lang_alignof(mk_lib_crypto_hash_block_blake3_base_digest_t));
		mk_lib_crypto_hash_block_blake3_base_squeeze_block(&blake3->m_blake3_base, ((mk_lib_crypto_hash_block_blake3_base_block_pt)(&blake3->m_block)), &blake3->m_seek, ((mk_lib_crypto_hash_block_blake3_base_digest_pt)(digest)));
	}
	else
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
		mk_lib_crypto_hash_block_blake3_base_block_t base_block mk_lang_constexpr_init;
		mk_lib_crypto_hash_block_blake3_base_digest_t base_digest mk_lang_constexpr_init;
		mk_lib_crypto_bitops_bulk_uint8_64_memcpy(&base_block.m_data.m_uint8s[0], &blake3->m_block.m_data.m_uint8s[0]);
		mk_lib_crypto_hash_block_blake3_base_squeeze_block(&blake3->m_blake3_base, &base_block, &blake3->m_seek, &base_digest);
		mk_lib_crypto_bitops_bulk_uint8_64_memcpy(&digest->m_data.m_uint8s[0], &base_digest.m_data.m_uint8s[0]);
		#include "mk_lang_warning_clang_pop.h"
	}
	mk_sl_cui_uint64_inc1(&blake3->m_seek);
}


#endif
