#ifndef mk_include_guard_mk_lib_crypto_hash_block_tiger2_128_c
#define mk_include_guard_mk_lib_crypto_hash_block_tiger2_128_c
#include "mk_lib_crypto_hash_block_tiger2_128.h"

/* http://www.cs.technion.ac.il/~biham/Reports/Tiger/ */

#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_bitops_bulk.h"
#include "mk_lib_crypto_hash_block_tiger_base.h"
#include "mk_sl_cui_uint8.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_tiger2_128_init(mk_lib_crypto_hash_block_tiger2_128_pt const tiger2_128) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_tiger2_128_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_tiger2_128_digest_t) == 16);

	mk_lang_assert(tiger2_128);

	mk_lib_crypto_hash_block_tiger_base_init(&tiger2_128->m_tiger_base);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_tiger2_128_append_blocks(mk_lib_crypto_hash_block_tiger2_128_pt const tiger2_128, mk_lib_crypto_hash_block_tiger2_128_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_tiger2_128_block_t) == sizeof(mk_lib_crypto_hash_block_tiger_base_block_t));
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_hash_block_tiger2_128_block_t) == mk_lang_alignof(mk_lib_crypto_hash_block_tiger_base_block_t));

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(tiger2_128);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_tiger2_128_block_len_v);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lib_crypto_hash_block_tiger_base_append_blocks(&tiger2_128->m_tiger_base, ((mk_lib_crypto_hash_block_tiger_base_block_pct)(pblocks)), nblocks);
	}
	else
	{
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		mk_lang_types_usize_t i mk_lang_constexpr_init;
		mk_lib_crypto_hash_block_tiger_base_block_t tiger_base_block mk_lang_constexpr_init;
		n = nblocks;
		for(i = 0; i != n; ++i)
		{
			mk_lib_crypto_bitops_bulk_uint8_64_memcpy(&tiger_base_block.m_data.m_uint8s[0], &pblocks[i].m_data.m_uint8s[0]);
			mk_lib_crypto_hash_block_tiger_base_append_blocks(&tiger2_128->m_tiger_base, &tiger_base_block, 1);
		}
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_tiger2_128_finish(mk_lib_crypto_hash_block_tiger2_128_pt const tiger2_128, mk_lib_crypto_hash_block_tiger2_128_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_tiger2_128_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_tiger_base_digest_t base_digest mk_lang_constexpr_init;

	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_tiger2_128_block_t) == sizeof(mk_lib_crypto_hash_block_tiger_base_block_t));
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_hash_block_tiger2_128_block_t) == mk_lang_alignof(mk_lib_crypto_hash_block_tiger_base_block_t));

	mk_lang_assert(tiger2_128);

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lib_crypto_hash_block_tiger_base_finish(&tiger2_128->m_tiger_base, mk_lang_true, ((mk_lib_crypto_hash_block_tiger_base_block_pt)(block)), idx, &base_digest);
	}
	else
	{
		mk_lib_crypto_hash_block_tiger_base_block_t tiger_base_block mk_lang_constexpr_init;
		mk_sl_cui_uint8_memcpy_fn(&tiger_base_block.m_data.m_uint8s[0], &block->m_data.m_uint8s[0], ((mk_lang_types_usize_t)(idx)));
		mk_lib_crypto_hash_block_tiger_base_finish(&tiger2_128->m_tiger_base, mk_lang_true, &tiger_base_block, idx, &base_digest);
	}
	mk_sl_cui_uint8_memcpy_fn(&digest->m_data.m_uint8s[0], &base_digest.m_data.m_uint8s[0], mk_lib_crypto_hash_block_tiger2_128_digest_len_v);
}


#endif
