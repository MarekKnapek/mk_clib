#ifndef mk_include_guard_mk_lib_crypto_hash_block_sha2_512_c
#define mk_include_guard_mk_lib_crypto_hash_block_sha2_512_c
#include "mk_lib_crypto_hash_block_sha2_512.h"

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
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"


union mk_lib_crypto_hash_block_sha2_512_init_data_u
{
	mk_sl_cui_uint64_t m_uint64s[8];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_sha2_512_init_data_u mk_lib_crypto_hash_block_sha2_512_init_data_t;
struct mk_lib_crypto_hash_block_sha2_512_init_s
{
	mk_lang_alignas(sizeof(mk_lib_crypto_hash_block_sha2_512_init_data_t)) mk_lib_crypto_hash_block_sha2_512_init_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_sha2_512_init_s mk_lib_crypto_hash_block_sha2_512_init_t;


mk_lang_constexpr_static_inline mk_lib_crypto_hash_block_sha2_512_init_t const mk_lib_crypto_hash_block_sha2_512_k_init =
{{{
	mk_sl_cui_uint64_c(0x6a09e667ul, 0xf3bcc908ul),
	mk_sl_cui_uint64_c(0xbb67ae85ul, 0x84caa73bul),
	mk_sl_cui_uint64_c(0x3c6ef372ul, 0xfe94f82bul),
	mk_sl_cui_uint64_c(0xa54ff53aul, 0x5f1d36f1ul),
	mk_sl_cui_uint64_c(0x510e527ful, 0xade682d1ul),
	mk_sl_cui_uint64_c(0x9b05688cul, 0x2b3e6c1ful),
	mk_sl_cui_uint64_c(0x1f83d9abul, 0xfb41bd6bul),
	mk_sl_cui_uint64_c(0x5be0cd19ul, 0x137e2179ul),
}}};


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_512_init(mk_lib_crypto_hash_block_sha2_512_pt const sha2_512) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint128_t) == 16);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_512_block_t) == 128);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_512_digest_t) == 64);

	mk_lang_assert(sha2_512);

	mk_lib_crypto_hash_block_sha2_base_64bit_init(&sha2_512->m_sha2_base_64bit, &mk_lib_crypto_hash_block_sha2_512_k_init.m_data.m_uint64s[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_512_append_blocks(mk_lib_crypto_hash_block_sha2_512_pt const sha2_512, mk_lib_crypto_hash_block_sha2_512_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(sha2_512);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha2_512_block_len_v);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lib_crypto_hash_block_sha2_base_64bit_append_blocks(&sha2_512->m_sha2_base_64bit, ((mk_lib_crypto_hash_block_sha2_base_64bit_block_pct)(pblocks)), nblocks);
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
			mk_lib_crypto_hash_block_sha2_base_64bit_append_blocks(&sha2_512->m_sha2_base_64bit, &sha2_base_64bit_block, 1);
		}
		#include "mk_lang_warning_clang_pop.h"
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_512_finish(mk_lib_crypto_hash_block_sha2_512_pt const sha2_512, mk_lib_crypto_hash_block_sha2_512_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_sha2_512_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_assert(sha2_512);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_sha2_512_block_len_v);
	mk_lang_assert(digest);

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lib_crypto_hash_block_sha2_base_64bit_finish(&sha2_512->m_sha2_base_64bit, ((mk_lib_crypto_hash_block_sha2_base_64bit_block_pt)(block)), idx, ((mk_lib_crypto_hash_block_sha2_base_64bit_digest_pt)(digest)));
	}
	else
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
		mk_lib_crypto_hash_block_sha2_base_64bit_block_t sha2_base_64bit_block mk_lang_constexpr_init;
		mk_lib_crypto_hash_block_sha2_base_64bit_digest_t sha2_base_64bit_digest mk_lang_constexpr_init;
		mk_sl_cui_uint8_memcpy_fn(&sha2_base_64bit_block.m_data.m_uint8s[0], &block->m_data.m_uint8s[0], ((mk_lang_types_usize_t)(idx)));
		mk_lib_crypto_hash_block_sha2_base_64bit_finish(&sha2_512->m_sha2_base_64bit, &sha2_base_64bit_block, idx, &sha2_base_64bit_digest);
		mk_lib_crypto_bitops_bulk_uint8_64_memcpy(&digest->m_data.m_uint8s[0], &sha2_base_64bit_digest.m_data.m_uint8s[0]);
		#include "mk_lang_warning_clang_pop.h"
	}
}


#endif
