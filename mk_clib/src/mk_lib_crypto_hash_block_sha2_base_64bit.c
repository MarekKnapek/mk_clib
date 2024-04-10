#include "mk_lib_crypto_hash_block_sha2_base_64bit.h"

#include "mk_lang_alignof.h"
#include "mk_lang_arch.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_gnuc.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_llong.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_sha2_base_64bit_c.h"
#include "mk_lib_crypto_hash_block_sha2_base_64bit_x86.h"
#include "mk_sl_uint64.h"


#define mk_lib_crypto_hash_block_sha2_base_64bit_conditions_common \
( \
	(mk_lang_llong_has) && \
	(sizeof(mk_sl_cui_uint64_t) == sizeof(mk_lang_ullong_t)) && \
	(sizeof(mk_sl_cui_uint64_t) == 8) && \
	(mk_lang_alignof(mk_sl_cui_uint64_t) == 8) && \
	((((mk_lang_types_uintptr_t)(&sha2_base_64bit->m_data.m_sha2_base_64bit_x86)) & 0x1f) == 0) && \
	(mk_lang_cpuid_has_sse2()) && \
	(mk_lang_cpuid_has_avx()) && \
	(mk_lang_cpuid_has_avx2()) && \
	(mk_lang_cpuid_has_sha512()) && \
	1 \
)

#define mk_lib_crypto_hash_block_sha2_base_64bit_conditions_init \
( \
	(mk_lib_crypto_hash_block_sha2_base_64bit_conditions_common) && \
	1 \
)

#define mk_lib_crypto_hash_block_sha2_base_64bit_conditions_append \
( \
	(mk_lib_crypto_hash_block_sha2_base_64bit_conditions_common) && \
	((((mk_lang_types_uintptr_t)(pblocks)) & 0x1f) == 0) && \
	1 \
)

#define mk_lib_crypto_hash_block_sha2_base_64bit_conditions_finish \
( \
	(mk_lib_crypto_hash_block_sha2_base_64bit_conditions_common) && \
	((((mk_lang_types_uintptr_t)(block)) & 0x1f) == 0) && \
	1 \
)


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_init(mk_lib_crypto_hash_block_sha2_base_64bit_pt const sha2_base_64bit, mk_sl_cui_uint64_pct const iv) mk_lang_noexcept
{
	mk_lang_assert(sha2_base_64bit);

	#if mk_lang_gnuc_is_at_least(14, 0) && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664)
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lib_crypto_hash_block_sha2_base_64bit_conditions_init)
	{
		mk_lib_crypto_hash_block_sha2_base_64bit_x86_init(&sha2_base_64bit->m_data.m_sha2_base_64bit_x86, iv);
	}
	else
	#endif
	{
		mk_lib_crypto_hash_block_sha2_base_64bit_c_init(&sha2_base_64bit->m_data.m_sha2_base_64bit_c, iv);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_append_blocks(mk_lib_crypto_hash_block_sha2_base_64bit_pt const sha2_base_64bit, mk_lib_crypto_hash_block_sha2_base_64bit_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(sha2_base_64bit);

	#if mk_lang_gnuc_is_at_least(14, 0) && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664)
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lib_crypto_hash_block_sha2_base_64bit_conditions_append)
	{
		mk_lib_crypto_hash_block_sha2_base_64bit_x86_append_blocks(&sha2_base_64bit->m_data.m_sha2_base_64bit_x86, ((mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_pct)(pblocks)), nblocks);
	}
	else
	#endif
	{
		mk_lib_crypto_hash_block_sha2_base_64bit_c_append_blocks(&sha2_base_64bit->m_data.m_sha2_base_64bit_c, pblocks, nblocks);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_finish(mk_lib_crypto_hash_block_sha2_base_64bit_pt const sha2_base_64bit, mk_lib_crypto_hash_block_sha2_base_64bit_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_sha2_base_64bit_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_assert(sha2_base_64bit);

	#if mk_lang_gnuc_is_at_least(14, 0) && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664)
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lib_crypto_hash_block_sha2_base_64bit_conditions_finish)
	{
		mk_lib_crypto_hash_block_sha2_base_64bit_x86_finish(&sha2_base_64bit->m_data.m_sha2_base_64bit_x86, ((mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_pt)(block)), idx, ((mk_lib_crypto_hash_block_sha2_base_64bit_x86_digest_pt)(digest)));
	}
	else
	#endif
	{
		mk_lib_crypto_hash_block_sha2_base_64bit_c_finish(&sha2_base_64bit->m_data.m_sha2_base_64bit_c, block, idx, digest);
	}
}
