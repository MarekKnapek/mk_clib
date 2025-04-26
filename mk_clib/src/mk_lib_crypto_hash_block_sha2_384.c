#ifndef mk_include_guard_mk_lib_crypto_hash_block_sha2_384_c
#define mk_include_guard_mk_lib_crypto_hash_block_sha2_384_c
#include "mk_lib_crypto_hash_block_sha2_384.h"

/* NIST FIPS PUB 180-2 */
/* NIST FIPS PUB 180-3 */
/* NIST FIPS PUB 180-4 */

#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_bitops_bulk.h"
#include "mk_lib_crypto_hash_block_sha2_base_64bit.h"
#include "mk_sl_cui_uint128.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"


union mk_lib_crypto_hash_block_sha2_384_init_data_u
{
	mk_sl_cui_uint64_t m_uint64s[8];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_sha2_384_init_data_u mk_lib_crypto_hash_block_sha2_384_init_data_t;
struct mk_lib_crypto_hash_block_sha2_384_init_s
{
	mk_lang_alignas(sizeof(mk_lib_crypto_hash_block_sha2_384_init_data_t)) mk_lib_crypto_hash_block_sha2_384_init_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_sha2_384_init_s mk_lib_crypto_hash_block_sha2_384_init_t;


mk_lang_constexpr_static_inline mk_lib_crypto_hash_block_sha2_384_init_t const mk_lib_crypto_hash_block_sha2_384_k_init =
{{{
	mk_sl_cui_uint64_c(0xcbbb9d5dul, 0xc1059ed8ul),
	mk_sl_cui_uint64_c(0x629a292aul, 0x367cd507ul),
	mk_sl_cui_uint64_c(0x9159015aul, 0x3070dd17ul),
	mk_sl_cui_uint64_c(0x152fecd8ul, 0xf70e5939ul),
	mk_sl_cui_uint64_c(0x67332667ul, 0xffc00b31ul),
	mk_sl_cui_uint64_c(0x8eb44a87ul, 0x68581511ul),
	mk_sl_cui_uint64_c(0xdb0c2e0dul, 0x64f98fa7ul),
	mk_sl_cui_uint64_c(0x47b5481dul, 0xbefa4fa4ul),
}}};


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_384_init(mk_lib_crypto_hash_block_sha2_384_pt const sha2_384) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint128_t) == 16);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_384_block_t) == 128);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_384_digest_t) >= 48);

	mk_lang_assert(sha2_384);

	mk_lib_crypto_hash_block_sha2_base_64bit_init(&sha2_384->m_sha2_base_64bit, &mk_lib_crypto_hash_block_sha2_384_k_init.m_data.m_uint64s[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_384_append_blocks(mk_lib_crypto_hash_block_sha2_384_pt const sha2_384, mk_lib_crypto_hash_block_sha2_384_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(sha2_384);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha2_384_block_len_v);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lib_crypto_hash_block_sha2_base_64bit_append_blocks(&sha2_384->m_sha2_base_64bit, ((mk_lib_crypto_hash_block_sha2_base_64bit_block_pct)(pblocks)), nblocks);
	}
	else
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		mk_lang_types_usize_t i mk_lang_constexpr_init;
		mk_lib_crypto_hash_block_sha2_base_64bit_block_t sha2_base_64bit_block mk_lang_constexpr_init;
		n = nblocks;
		for(i = 0; i != n; ++i)
		{
			mk_lib_crypto_bitops_bulk_uint8_128_memcpy(&sha2_base_64bit_block.m_data.m_uint8s[0], &pblocks[i].m_data.m_uint8s[0]);
			mk_lib_crypto_hash_block_sha2_base_64bit_append_blocks(&sha2_384->m_sha2_base_64bit, &sha2_base_64bit_block, 1);
		}
		#include "mk_lang_warning_clang_pop.h"
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_384_finish(mk_lib_crypto_hash_block_sha2_384_pt const sha2_384, mk_lib_crypto_hash_block_sha2_384_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_sha2_384_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_sha2_base_64bit_digest_t sha2_base_64bit_digest mk_lang_constexpr_init;

	mk_lang_assert(sha2_384);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_sha2_384_block_len_v);
	mk_lang_assert(digest);

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lib_crypto_hash_block_sha2_base_64bit_finish(&sha2_384->m_sha2_base_64bit, ((mk_lib_crypto_hash_block_sha2_base_64bit_block_pt)(block)), idx, &sha2_base_64bit_digest);
	}
	else
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
		mk_lib_crypto_hash_block_sha2_base_64bit_block_t sha2_base_64bit_block mk_lang_constexpr_init;
		mk_sl_cui_uint8_memcpy_fn(&sha2_base_64bit_block.m_data.m_uint8s[0], &block->m_data.m_uint8s[0], ((mk_lang_types_usize_t)(idx)));
		mk_lib_crypto_hash_block_sha2_base_64bit_finish(&sha2_384->m_sha2_base_64bit, &sha2_base_64bit_block, idx, &sha2_base_64bit_digest);
		#include "mk_lang_warning_clang_pop.h"
	}
	mk_sl_cui_uint8_memcpy_fn(&digest->m_data.m_uint8s[0], &sha2_base_64bit_digest.m_data.m_uint8s[0], mk_lib_crypto_hash_block_sha2_384_digest_len_v);
}


#endif
