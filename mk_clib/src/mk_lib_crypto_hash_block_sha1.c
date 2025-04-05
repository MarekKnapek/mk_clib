#ifndef mk_include_guard_mk_lib_crypto_hash_block_sha1_c
#define mk_include_guard_mk_lib_crypto_hash_block_sha1_c
#include "mk_lib_crypto_hash_block_sha1.h"

/* NIST FIPS PUB 180-1 */
/* NIST FIPS PUB 180-2 */
/* NIST FIPS PUB 180-3 */
/* NIST FIPS PUB 180-4 */

#include "mk_lang_alignof.h"
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
#include "mk_lang_types.h"
#include "mk_lib_crypto_bitops_bulk.h"
#include "mk_lib_crypto_hash_block_sha1_portable.h"
#include "mk_lib_crypto_hash_block_sha1_x86.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"


#define mk_lib_crypto_hash_block_sha1_test_ct \
( \
	( \
		mk_lang_msvc_ver >= mk_lang_msvc_ver_2015 || \
		mk_lang_compiler_is_at_least_gcc(11, 1) \
	) && \
	( \
		mk_lang_arch == mk_lang_arch_x8632 || \
		mk_lang_arch == mk_lang_arch_x8664 \
	) \
)
#define mk_lib_crypto_hash_block_sha1_test_rt \
( \
	!mk_lang_constexpr_is_constant_evaluated_test && \
	( \
		sizeof(mk_sl_cui_uint32_t) == sizeof(mk_lang_types_sint_t) && \
		sizeof(mk_sl_cui_uint32_t) == 4 && \
		mk_lang_alignof(mk_sl_cui_uint32_t) == 4 && \
		mk_lang_cpuid_has_sse2() && \
		mk_lang_cpuid_has_ssse3() && \
		mk_lang_cpuid_has_sse41() && \
		mk_lang_cpuid_has_sha() \
	) \
)


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha1_init(mk_lib_crypto_hash_block_sha1_pt const sha1) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha1_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha1_digest_t) >= 20);

	mk_lang_assert(sha1);

	#if mk_lib_crypto_hash_block_sha1_test_ct
	if(mk_lib_crypto_hash_block_sha1_test_rt && (((mk_lang_types_uintptr_t)(&sha1->m_state[0])) & 0xf) == 0)
	{
		mk_lib_crypto_hash_block_sha1_x86_init(((mk_lib_crypto_hash_block_sha1_x86_pt)(sha1)));
	}
	else
	#endif
	{
		mk_lib_crypto_hash_block_sha1_portable_t sha1_portable mk_lang_constexpr_init;
		mk_lib_crypto_hash_block_sha1_portable_init(&sha1_portable);
		mk_lib_crypto_bitops_bulk_uint32_5_memcpy(&sha1->m_state[0], &sha1_portable.m_state[0]);
		sha1->m_len = sha1_portable.m_len;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha1_append_blocks(mk_lib_crypto_hash_block_sha1_pt const sha1, mk_lib_crypto_hash_block_sha1_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(sha1);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha1_block_len_v);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	#if mk_lib_crypto_hash_block_sha1_test_ct
	if(mk_lib_crypto_hash_block_sha1_test_rt && (((mk_lang_types_uintptr_t)(&sha1->m_state[0])) & 0xf) == 0 && (((mk_lang_types_uintptr_t)(pblocks)) & 0xf) == 0)
	{
		mk_lib_crypto_hash_block_sha1_x86_append_blocks(((mk_lib_crypto_hash_block_sha1_x86_pt)(sha1)), ((mk_lib_crypto_hash_block_sha1_x86_block_pct)(pblocks)), nblocks);
	}
	else
	#endif
	{
		mk_lib_crypto_hash_block_sha1_portable_t sha1_portable mk_lang_constexpr_init;
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		mk_lang_types_usize_t i mk_lang_constexpr_init;
		mk_lib_crypto_hash_block_sha1_portable_block_t sha1_portable_block mk_lang_constexpr_init;
		mk_lib_crypto_bitops_bulk_uint32_5_memcpy(&sha1_portable.m_state[0], &sha1->m_state[0]);
		sha1_portable.m_len = sha1->m_len;
		n = nblocks;
		for(i = 0; i != n; ++i)
		{
			mk_lib_crypto_bitops_bulk_uint8_64_memcpy(&sha1_portable_block.m_data.m_uint8s[0], &pblocks[i].m_data.m_uint8s[0]);
			mk_lib_crypto_hash_block_sha1_portable_append_blocks(&sha1_portable, &sha1_portable_block, 1);
		}
		mk_lib_crypto_bitops_bulk_uint32_5_memcpy(&sha1->m_state[0], &sha1_portable.m_state[0]);
		sha1->m_len = sha1_portable.m_len;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha1_finish(mk_lib_crypto_hash_block_sha1_pt const sha1, mk_lib_crypto_hash_block_sha1_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_sha1_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_assert(sha1);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_sha1_block_len_v);
	mk_lang_assert(digest);

	#if mk_lib_crypto_hash_block_sha1_test_ct
	if(mk_lib_crypto_hash_block_sha1_test_rt && (((mk_lang_types_uintptr_t)(&sha1->m_state[0])) & 0xf) == 0 && (((mk_lang_types_uintptr_t)(block)) & 0xf) == 0)
	{
		mk_lib_crypto_hash_block_sha1_x86_finish(((mk_lib_crypto_hash_block_sha1_x86_pt)(sha1)), ((mk_lib_crypto_hash_block_sha1_x86_block_pt)(block)), idx, ((mk_lib_crypto_hash_block_sha1_x86_digest_pt)(digest)));
	}
	else
	#endif
	{
		mk_lib_crypto_hash_block_sha1_portable_t sha1_portable mk_lang_constexpr_init;
		mk_lib_crypto_hash_block_sha1_portable_block_t sha1_portable_block mk_lang_constexpr_init;
		mk_lib_crypto_hash_block_sha1_portable_digest_t sha1_portable_digest mk_lang_constexpr_init;
		mk_lib_crypto_bitops_bulk_uint32_5_memcpy(&sha1_portable.m_state[0], &sha1->m_state[0]);
		sha1_portable.m_len = sha1->m_len;
		mk_sl_cui_uint8_memcpy_fn(&sha1_portable_block.m_data.m_uint8s[0], &block->m_data.m_uint8s[0], ((mk_lang_types_usize_t)(idx)));
		mk_lib_crypto_hash_block_sha1_portable_finish(&sha1_portable, &sha1_portable_block, idx, &sha1_portable_digest);
		mk_lib_crypto_bitops_bulk_uint8_20_memcpy(&digest->m_data.m_uint8s[0], &sha1_portable_digest.m_data.m_uint8s[0]);
	}
}


#endif
