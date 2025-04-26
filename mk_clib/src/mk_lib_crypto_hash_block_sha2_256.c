#ifndef mk_include_guard_mk_lib_crypto_hash_block_sha2_256_c
#define mk_include_guard_mk_lib_crypto_hash_block_sha2_256_c
#include "mk_lib_crypto_hash_block_sha2_256.h"

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
#include "mk_lib_crypto_hash_block_sha2_base_32bit.h"
#include "mk_sl_cui_uint8.h"


union mk_lib_crypto_hash_block_sha2_256_init_data_u
{
	mk_sl_cui_uint32_t m_uint32s[8];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_sha2_256_init_data_u mk_lib_crypto_hash_block_sha2_256_init_data_t;
struct mk_lib_crypto_hash_block_sha2_256_init_s
{
	mk_lang_alignas(sizeof(mk_lib_crypto_hash_block_sha2_256_init_data_t)) mk_lib_crypto_hash_block_sha2_256_init_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_sha2_256_init_s mk_lib_crypto_hash_block_sha2_256_init_t;


mk_lang_constexpr_static_inline mk_lib_crypto_hash_block_sha2_256_init_t const mk_lib_crypto_hash_block_sha2_256_k_init =
{{{
	mk_sl_cui_uint32_c(0x6a09e667ul),
	mk_sl_cui_uint32_c(0xbb67ae85ul),
	mk_sl_cui_uint32_c(0x3c6ef372ul),
	mk_sl_cui_uint32_c(0xa54ff53aul),
	mk_sl_cui_uint32_c(0x510e527ful),
	mk_sl_cui_uint32_c(0x9b05688cul),
	mk_sl_cui_uint32_c(0x1f83d9abul),
	mk_sl_cui_uint32_c(0x5be0cd19ul),
}}};


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_256_init(mk_lib_crypto_hash_block_sha2_256_pt const sha2_256) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_256_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_256_digest_t) == 32);

	mk_lang_assert(sha2_256);

	mk_lib_crypto_hash_block_sha2_base_32bit_init(&sha2_256->m_sha2_base_32bit, &mk_lib_crypto_hash_block_sha2_256_k_init.m_data.m_uint32s[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_256_append_blocks(mk_lib_crypto_hash_block_sha2_256_pt const sha2_256, mk_lib_crypto_hash_block_sha2_256_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(sha2_256);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha2_256_block_len_v);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lib_crypto_hash_block_sha2_base_32bit_append_blocks(&sha2_256->m_sha2_base_32bit, ((mk_lib_crypto_hash_block_sha2_base_32bit_block_pct)(pblocks)), nblocks);
	}
	else
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		mk_lang_types_usize_t i mk_lang_constexpr_init;
		mk_lib_crypto_hash_block_sha2_base_32bit_block_t sha2_base_32bit_block mk_lang_constexpr_init;
		n = nblocks;
		for(i = 0; i != n; ++i)
		{
			mk_lib_crypto_bitops_bulk_uint8_64_memcpy(&sha2_base_32bit_block.m_data.m_uint8s[0], &pblocks[i].m_data.m_uint8s[0]);
			mk_lib_crypto_hash_block_sha2_base_32bit_append_blocks(&sha2_256->m_sha2_base_32bit, &sha2_base_32bit_block, 1);
		}
		#include "mk_lang_warning_clang_pop.h"
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_256_finish(mk_lib_crypto_hash_block_sha2_256_pt const sha2_256, mk_lib_crypto_hash_block_sha2_256_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_sha2_256_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_assert(sha2_256);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_sha2_256_block_len_v);
	mk_lang_assert(digest);

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lib_crypto_hash_block_sha2_base_32bit_finish(&sha2_256->m_sha2_base_32bit, ((mk_lib_crypto_hash_block_sha2_base_32bit_block_pt)(block)), idx, ((mk_lib_crypto_hash_block_sha2_base_32bit_digest_pt)(digest)));
	}
	else
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
		mk_lib_crypto_hash_block_sha2_base_32bit_block_t sha2_base_32bit_block mk_lang_constexpr_init;
		mk_lib_crypto_hash_block_sha2_base_32bit_digest_t sha2_base_32bit_digest mk_lang_constexpr_init;
		mk_sl_cui_uint8_memcpy_fn(&sha2_base_32bit_block.m_data.m_uint8s[0], &block->m_data.m_uint8s[0], ((mk_lang_types_usize_t)(idx)));
		mk_lib_crypto_hash_block_sha2_base_32bit_finish(&sha2_256->m_sha2_base_32bit, &sha2_base_32bit_block, idx, &sha2_base_32bit_digest);
		mk_lib_crypto_bitops_bulk_uint8_32_memcpy(&digest->m_data.m_uint8s[0], &sha2_base_32bit_digest.m_data.m_uint8s[0]);
		#include "mk_lang_warning_clang_pop.h"
	}
}


#endif
