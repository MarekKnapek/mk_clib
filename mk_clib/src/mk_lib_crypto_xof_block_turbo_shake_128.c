#ifndef mk_include_guard_mk_lib_crypto_xof_block_turbo_shake_128_c
#define mk_include_guard_mk_lib_crypto_xof_block_turbo_shake_128_c
#include "mk_lib_crypto_xof_block_turbo_shake_128.h"

/* https://keccak.team/files/TurboSHAKE.pdf */

#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_sha3_base.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_block_turbo_shake_128_mix_block(mk_lib_crypto_xof_block_turbo_shake_128_pt const sha3_256, mk_lib_crypto_xof_block_turbo_shake_128_block_pct const block) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;

	mk_lang_static_assert((((mk_lang_types_sint_t)(mk_lib_crypto_xof_block_turbo_shake_128_block_len_v)) % ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v))) == 0);

	mk_lang_assert(sha3_256);
	mk_lang_assert(block);

	n = ((mk_lang_types_sint_t)(mk_lib_crypto_xof_block_turbo_shake_128_block_len_v)) / ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v));
	for(i = 0; i != n; ++i)
	{
		mk_sl_uint_convert_64_8_le_to_big(&ta, &block->m_data.m_uint8s[i * mk_sl_cui_uint64_size_bytes_v]);
		mk_sl_cui_uint64_xor2(&sha3_256->m_sha3_base.m_data.m_uint64s[i], &ta);
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_turbo_shake_128_init(mk_lib_crypto_xof_block_turbo_shake_128_pt const turbo_shake_128) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_xof_block_turbo_shake_128_block_t) == 168);
	mk_lang_static_assert(sizeof(mk_lib_crypto_xof_block_turbo_shake_128_digest_t) == 168);

	mk_lang_assert(turbo_shake_128);

	mk_lib_crypto_hash_block_sha3_base_init(&turbo_shake_128->m_sha3_base);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_turbo_shake_128_append_blocks(mk_lib_crypto_xof_block_turbo_shake_128_pt const turbo_shake_128, mk_lib_crypto_xof_block_turbo_shake_128_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(turbo_shake_128);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_xof_block_turbo_shake_128_block_len_v);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		mk_lib_crypto_xof_block_turbo_shake_128_mix_block(turbo_shake_128, &pblocks[iblock]);
		mk_lib_crypto_hash_block_sha3_base_f_turbo(&turbo_shake_128->m_sha3_base);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_turbo_shake_128_finish(mk_lib_crypto_xof_block_turbo_shake_128_pt const turbo_shake_128, mk_lib_crypto_xof_block_turbo_shake_128_block_pt const block, mk_lang_types_sint_t const idx) mk_lang_noexcept
{
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_lang_types_sint_t rest mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;

	mk_lang_assert(turbo_shake_128);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_xof_block_turbo_shake_128_block_len_v);

	tuc = 0x1f; mk_sl_cui_uint8_from_bi_uchar(&block->m_data.m_uint8s[idx], &tuc);
	rest = mk_lib_crypto_xof_block_turbo_shake_128_block_len_v - idx - 1;
	mk_sl_cui_uint8_memclr_fn(&block->m_data.m_uint8s[idx + 1], ((mk_lang_types_usize_t)(rest)));
	tuc = 0x80; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc);
	mk_sl_cui_uint8_xor2(&block->m_data.m_uint8s[mk_lib_crypto_xof_block_turbo_shake_128_block_len_v - 1], &tu8);
	mk_lib_crypto_xof_block_turbo_shake_128_mix_block(turbo_shake_128, block);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_turbo_shake_128_squeeze_block(mk_lib_crypto_xof_block_turbo_shake_128_pt const turbo_shake_128, mk_lib_crypto_xof_block_turbo_shake_128_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_xof_block_turbo_shake_128_block_len_v)) % ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v)) == 0);
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_xof_block_turbo_shake_128_block_len_v)) / ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v)) <= mk_lang_countof(turbo_shake_128->m_sha3_base.m_data.m_uint64s));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_xof_block_turbo_shake_128_block_len_v)) >= ((mk_lang_types_sint_t)(mk_lib_crypto_xof_block_turbo_shake_128_digest_len_v)));

	mk_lang_assert(turbo_shake_128);
	mk_lang_assert(digest);

	mk_lib_crypto_hash_block_sha3_base_f_turbo(&turbo_shake_128->m_sha3_base);
	n = ((mk_lang_types_sint_t)(mk_lib_crypto_xof_block_turbo_shake_128_block_len_v)) / ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v));
	mk_sl_uint_convert_64_8_le_to_sml_multi(&turbo_shake_128->m_sha3_base.m_data.m_uint64s[0], &digest->m_data.m_uint8s[0], ((mk_lang_types_usize_t)(n)));
}


#endif
