#include "mk_lib_crypto_hash_block_sha2_base_32bit.h"

#include "mk_lang_alignof.h"
#include "mk_lang_arch.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_gnuc.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_sha2_c_base_32bit.h"
#include "mk_lib_crypto_hash_block_sha2_x86_base_32bit.h"
#include "mk_sl_uint32.h"


#define mk_lib_crypto_hash_block_sha2_base_32bit_conditions_1 \
( \
	(sizeof(mk_sl_cui_uint32_t) == sizeof(int)) && \
	(sizeof(mk_sl_cui_uint32_t) == 4) && \
	(mk_lang_alignof(mk_sl_cui_uint32_t) == 4) && \
	(mk_lang_cpuid_has_sse2()) && \
	(mk_lang_cpuid_has_ssse3()) && \
	(mk_lang_cpuid_has_sse41()) && \
	(mk_lang_cpuid_has_sha()) && \
	1 \
)
#define mk_lib_crypto_hash_block_sha2_base_32bit_conditions_2 ((((mk_lang_types_uintptr_t)(&sha2_base_32bit->m_data.m_sha2_x86_base_32bit.m_state[0])) & 0xf) == 0)
#define mk_lib_crypto_hash_block_sha2_base_32bit_conditions_3 ((((mk_lang_types_uintptr_t)(pblocks)) & 0xf) == 0)
#define mk_lib_crypto_hash_block_sha2_base_32bit_conditions_4 ((((mk_lang_types_uintptr_t)(block)) & 0xf) == 0)


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_32bit_init(mk_lib_crypto_hash_block_sha2_base_32bit_pt const sha2_base_32bit, mk_sl_cui_uint32_pct const iv) mk_lang_noexcept
{
	mk_lang_assert(sha2_base_32bit);

	#if (mk_lang_msvc_ver >= mk_lang_msvc_ver_2015 || mk_lang_gnuc_is_at_least(11, 1)) && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664)
	#if !mk_lang_constexpr_is_constant_evaluated
	if(mk_lib_crypto_hash_block_sha2_base_32bit_conditions_1 && mk_lib_crypto_hash_block_sha2_base_32bit_conditions_2)
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lib_crypto_hash_block_sha2_base_32bit_conditions_1 && mk_lib_crypto_hash_block_sha2_base_32bit_conditions_2)
	#endif
	{
		mk_lib_crypto_hash_block_sha2_x86_base_32bit_init(&sha2_base_32bit->m_data.m_sha2_x86_base_32bit, iv);
	}
	else
	#endif
	{
		mk_lib_crypto_hash_block_sha2_c_base_32bit_init(&sha2_base_32bit->m_data.m_sha2_c_base_32bit, iv);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_32bit_append_blocks(mk_lib_crypto_hash_block_sha2_base_32bit_pt const sha2_base_32bit, mk_lib_crypto_hash_block_sha2_base_32bit_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(sha2_base_32bit);

	#if (mk_lang_msvc_ver >= mk_lang_msvc_ver_2015 || mk_lang_gnuc_is_at_least(11, 1)) && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664)
	#if !mk_lang_constexpr_is_constant_evaluated
	if(mk_lib_crypto_hash_block_sha2_base_32bit_conditions_1 && mk_lib_crypto_hash_block_sha2_base_32bit_conditions_2 && mk_lib_crypto_hash_block_sha2_base_32bit_conditions_3)
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lib_crypto_hash_block_sha2_base_32bit_conditions_1 && mk_lib_crypto_hash_block_sha2_base_32bit_conditions_2 && mk_lib_crypto_hash_block_sha2_base_32bit_conditions_3)
	#endif
	{
		mk_lib_crypto_hash_block_sha2_x86_base_32bit_append_blocks(&sha2_base_32bit->m_data.m_sha2_x86_base_32bit, ((mk_lib_crypto_hash_block_sha2_x86_base_32bit_block_pct)(pblocks)), nblocks);
	}
	else
	#endif
	{
		mk_lib_crypto_hash_block_sha2_c_base_32bit_append_blocks(&sha2_base_32bit->m_data.m_sha2_c_base_32bit, pblocks, nblocks);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_32bit_finish(mk_lib_crypto_hash_block_sha2_base_32bit_pt const sha2_base_32bit, mk_lib_crypto_hash_block_sha2_base_32bit_block_pt const block, int const idx, mk_lib_crypto_hash_block_sha2_base_32bit_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_assert(sha2_base_32bit);

	#if (mk_lang_msvc_ver >= mk_lang_msvc_ver_2015 || mk_lang_gnuc_is_at_least(11, 1)) && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664)
	#if !mk_lang_constexpr_is_constant_evaluated
	if(mk_lib_crypto_hash_block_sha2_base_32bit_conditions_1 && mk_lib_crypto_hash_block_sha2_base_32bit_conditions_2 && mk_lib_crypto_hash_block_sha2_base_32bit_conditions_4)
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lib_crypto_hash_block_sha2_base_32bit_conditions_1 && mk_lib_crypto_hash_block_sha2_base_32bit_conditions_2 && mk_lib_crypto_hash_block_sha2_base_32bit_conditions_4)
	#endif
	{
		mk_lib_crypto_hash_block_sha2_x86_base_32bit_finish(&sha2_base_32bit->m_data.m_sha2_x86_base_32bit, ((mk_lib_crypto_hash_block_sha2_x86_base_32bit_block_pt)(block)), idx, ((mk_lib_crypto_hash_block_sha2_x86_base_32bit_digest_pt)(digest)));
	}
	else
	#endif
	{
		mk_lib_crypto_hash_block_sha2_c_base_32bit_finish(&sha2_base_32bit->m_data.m_sha2_c_base_32bit, block, idx, digest);
	}
}
