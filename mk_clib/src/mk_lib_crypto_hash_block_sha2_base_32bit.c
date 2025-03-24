#ifndef mk_include_guard_mk_lib_crypto_hash_block_sha2_base_32bit_c
#define mk_include_guard_mk_lib_crypto_hash_block_sha2_base_32bit_c
#include "mk_lib_crypto_hash_block_sha2_base_32bit.h"

#include "mk_lang_arch.h"
#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_compiler.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_msvc.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_bitops_bulk.h"
#include "mk_lib_crypto_hash_block_sha2_base_32bit_portable.h"
#include "mk_lib_crypto_hash_block_sha2_base_32bit_x86.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"


#define mk_lib_crypto_hash_block_sha2_base_32bit_test_ct (mk_lang_msvc_ver >= mk_lang_msvc_ver_2015 || mk_lang_compiler_is_at_least_gcc(11, 1)) && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664)
#define mk_lib_crypto_hash_block_sha2_base_32bit_test_rt !mk_lang_constexpr_is_constant_evaluated_test && (mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_ssse3() && mk_lang_cpuid_has_sse41() && mk_lang_cpuid_has_sha())


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_32bit_init(mk_lib_crypto_hash_block_sha2_base_32bit_pt const sha2_base_32bit, mk_lang_static_param(mk_sl_cui_uint32_ct, iv, 8)) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_base_32bit_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_base_32bit_digest_t) == 32);

	mk_lang_assert(sha2_base_32bit);
	mk_lang_assert(iv);

	#if mk_lib_crypto_hash_block_sha2_base_32bit_test_ct
	if(mk_lib_crypto_hash_block_sha2_base_32bit_test_rt)
	{
		mk_lib_crypto_hash_block_sha2_base_32bit_x86_init(((mk_lib_crypto_hash_block_sha2_base_32bit_x86_pt)(sha2_base_32bit)), iv);
	}
	else
	#endif
	{
		mk_lib_crypto_hash_block_sha2_base_32bit_portable_t sha2_base_32bit_portable mk_lang_constexpr_init;
		mk_lib_crypto_hash_block_sha2_base_32bit_portable_init(&sha2_base_32bit_portable, iv);
		mk_lib_crypto_bitops_bulk_uint32_8_memcpy(&sha2_base_32bit->m_state[0], &sha2_base_32bit_portable.m_state[0]);
		sha2_base_32bit->m_len = sha2_base_32bit_portable.m_len;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_32bit_append_blocks(mk_lib_crypto_hash_block_sha2_base_32bit_pt const sha2_base_32bit, mk_lib_crypto_hash_block_sha2_base_32bit_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(sha2_base_32bit);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha2_base_32bit_block_len_v);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	#if mk_lib_crypto_hash_block_sha2_base_32bit_test_ct
	if(mk_lib_crypto_hash_block_sha2_base_32bit_test_rt)
	{
		mk_lib_crypto_hash_block_sha2_base_32bit_x86_append_blocks(((mk_lib_crypto_hash_block_sha2_base_32bit_x86_pt)(sha2_base_32bit)), ((mk_lib_crypto_hash_block_sha2_base_32bit_x86_block_pct)(pblocks)), nblocks);
	}
	else
	#endif
	{
		mk_lib_crypto_hash_block_sha2_base_32bit_portable_t sha2_base_32bit_portable mk_lang_constexpr_init;
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		mk_lang_types_usize_t i mk_lang_constexpr_init;
		mk_lib_crypto_hash_block_sha2_base_32bit_portable_block_t sha2_base_32bit_portable_block mk_lang_constexpr_init;
		mk_lib_crypto_bitops_bulk_uint32_8_memcpy(&sha2_base_32bit_portable.m_state[0], &sha2_base_32bit->m_state[0]);
		sha2_base_32bit_portable.m_len = sha2_base_32bit->m_len;
		n = nblocks;
		for(i = 0; i != n; ++i)
		{
			mk_lib_crypto_bitops_bulk_uint8_64_memcpy(&sha2_base_32bit_portable_block.m_data.m_uint8s[0], &pblocks[i].m_data.m_uint8s[0]);
			mk_lib_crypto_hash_block_sha2_base_32bit_portable_append_blocks(&sha2_base_32bit_portable, &sha2_base_32bit_portable_block, 1);
		}
		mk_lib_crypto_bitops_bulk_uint32_8_memcpy(&sha2_base_32bit->m_state[0], &sha2_base_32bit_portable.m_state[0]);
		sha2_base_32bit->m_len = sha2_base_32bit_portable.m_len;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_32bit_finish(mk_lib_crypto_hash_block_sha2_base_32bit_pt const sha2_base_32bit, mk_lib_crypto_hash_block_sha2_base_32bit_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_sha2_base_32bit_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_assert(sha2_base_32bit);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_sha2_base_32bit_block_len_v);
	mk_lang_assert(digest);

	#if mk_lib_crypto_hash_block_sha2_base_32bit_test_ct
	if(mk_lib_crypto_hash_block_sha2_base_32bit_test_rt)
	{
		mk_lib_crypto_hash_block_sha2_base_32bit_x86_finish(((mk_lib_crypto_hash_block_sha2_base_32bit_x86_pt)(sha2_base_32bit)), ((mk_lib_crypto_hash_block_sha2_base_32bit_x86_block_pt)(block)), idx, ((mk_lib_crypto_hash_block_sha2_base_32bit_x86_digest_pt)(digest)));
	}
	else
	#endif
	{
		mk_lib_crypto_hash_block_sha2_base_32bit_portable_t sha2_base_32bit_portable mk_lang_constexpr_init;
		mk_lib_crypto_hash_block_sha2_base_32bit_portable_block_t sha2_base_32bit_portable_block mk_lang_constexpr_init;
		mk_lib_crypto_hash_block_sha2_base_32bit_portable_digest_t sha2_base_32bit_portable_digest mk_lang_constexpr_init;
		mk_lib_crypto_bitops_bulk_uint32_8_memcpy(&sha2_base_32bit_portable.m_state[0], &sha2_base_32bit->m_state[0]);
		sha2_base_32bit_portable.m_len = sha2_base_32bit->m_len;
		mk_sl_cui_uint8_memcpy_fn(&sha2_base_32bit_portable_block.m_data.m_uint8s[0], &block->m_data.m_uint8s[0], ((mk_lang_types_usize_t)(idx)));
		mk_lib_crypto_hash_block_sha2_base_32bit_portable_finish(&sha2_base_32bit_portable, &sha2_base_32bit_portable_block, idx, &sha2_base_32bit_portable_digest);
		mk_lib_crypto_bitops_bulk_uint8_32_memcpy(&digest->m_data.m_uint8s[0], &sha2_base_32bit_portable_digest.m_data.m_uint8s[0]);
	}
}


#endif
