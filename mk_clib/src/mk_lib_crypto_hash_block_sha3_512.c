#ifndef mk_include_guard_mk_lib_crypto_hash_block_sha3_512_c
#define mk_include_guard_mk_lib_crypto_hash_block_sha3_512_c
#include "mk_lib_crypto_hash_block_sha3_512.h"

/* NIST FIPS PUB 202 */

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_sha3_base.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha3_512_mix_block(mk_lib_crypto_hash_block_sha3_512_pt const sha3_512, mk_lib_crypto_hash_block_sha3_512_block_pct const block) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;

	mk_lang_static_assert((((mk_lang_types_sint_t)(mk_lib_crypto_hash_block_sha3_512_block_len_v)) % ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v))) == 0);

	mk_lang_assert(sha3_512);
	mk_lang_assert(block);

	n = ((mk_lang_types_sint_t)(mk_lib_crypto_hash_block_sha3_512_block_len_v)) / ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v));
	for(i = 0; i != n; ++i)
	{
		mk_sl_uint_convert_64_8_le_to_big(&ta, &block->m_data.m_uint8s[i * mk_sl_cui_uint64_size_bytes_v]);
		mk_sl_cui_uint64_xor2(&sha3_512->m_sha3_base.m_data.m_uint64s[i], &ta);
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha3_512_init(mk_lib_crypto_hash_block_sha3_512_pt const sha3_512) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha3_512_block_t) == 72);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha3_512_digest_t) == 64);

	mk_lang_assert(sha3_512);

	mk_lib_crypto_hash_block_sha3_base_init(&sha3_512->m_sha3_base);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha3_512_append_blocks(mk_lib_crypto_hash_block_sha3_512_pt const sha3_512, mk_lib_crypto_hash_block_sha3_512_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(sha3_512);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha3_512_block_len_v);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		mk_lib_crypto_hash_block_sha3_512_mix_block(sha3_512, &pblocks[iblock]);
		mk_lib_crypto_hash_block_sha3_base_f(&sha3_512->m_sha3_base);
	}
}

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha3_512_finish(mk_lib_crypto_hash_block_sha3_512_pt const sha3_512, mk_lib_crypto_hash_block_sha3_512_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_sha3_512_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt d mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t m mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	#if (mk_lib_crypto_hash_block_sha3_512_block_len_d % mk_lib_crypto_hash_block_sha3_512_digest_len_d) % mk_sl_cui_uint64_size_bytes_d >= mk_sl_cui_uint8_size_bytes_d
	mk_sl_cui_uint8_t tu8s[mk_sl_cui_uint64_size_bytes_v] mk_lang_constexpr_init;
	#endif

	mk_lang_assert(sha3_512);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_sha3_512_block_len_v);
	mk_lang_assert(digest);

	tuc = 0x06; mk_sl_cui_uint8_from_bi_uchar(&block->m_data.m_uint8s[idx], &tuc);
	rem = mk_lib_crypto_hash_block_sha3_512_block_len_v - idx - 1;
	mk_sl_cui_uint8_memclr_fn(&block->m_data.m_uint8s[idx + 1], ((mk_lang_types_usize_t)(rem)));
	tuc = 0x80; mk_sl_cui_uint8_from_bi_uchar(&ta, &tuc);
	mk_sl_cui_uint8_or2(&block->m_data.m_uint8s[mk_lib_crypto_hash_block_sha3_512_block_len_v - 1], &ta);

	mk_lib_crypto_hash_block_sha3_512_append_blocks(sha3_512, block, 1);

	d = &digest->m_data.m_uint8s[0];
	rem = mk_lib_crypto_hash_block_sha3_512_digest_len_v;
	n = mk_lang_min(mk_lib_crypto_hash_block_sha3_512_block_len_v, rem);
	m = n / mk_sl_cui_uint64_size_bytes_v;
	for(i = 0; i != m; ++i)
	{
		mk_sl_uint_convert_64_8_le_to_sml(&sha3_512->m_sha3_base.m_data.m_uint64s[i], &d[i * mk_sl_cui_uint64_size_bytes_v]);
	}
	d += m * mk_sl_cui_uint64_size_bytes_v;
	rem -= m * mk_sl_cui_uint64_size_bytes_v;
	#if mk_lib_crypto_hash_block_sha3_512_digest_len_d > mk_lib_crypto_hash_block_sha3_512_block_len_d && mk_lib_crypto_hash_block_sha3_512_digest_len_d % mk_lib_crypto_hash_block_sha3_512_block_len_d >= mk_sl_cui_uint64_size_bytes_d
	mk_lang_assert(rem >= mk_sl_cui_uint64_size_bytes_v && rem < mk_lib_crypto_hash_block_sha3_512_block_len_v);
	while(rem >= mk_sl_cui_uint64_size_bytes_v)
	{
		mk_lib_crypto_hash_block_sha3_base_f(&sha3_512->m_sha3_base);
		n = mk_lang_min(mk_lib_crypto_hash_block_sha3_512_block_len_v, rem);
		m = n / mk_sl_cui_uint64_size_bytes_v;
		for(i = 0; i != m; ++i)
		{
			mk_sl_uint_convert_64_8_le_to_sml(&sha3_512->m_sha3_base.m_data.m_uint64s[i], &d[i * mk_sl_cui_uint64_size_bytes_v]);
		}
		d += m * mk_sl_cui_uint64_size_bytes_v;
		rem -= m * mk_sl_cui_uint64_size_bytes_v;
	}
	#endif
	#if (mk_lib_crypto_hash_block_sha3_512_block_len_d % mk_lib_crypto_hash_block_sha3_512_digest_len_d) % mk_sl_cui_uint64_size_bytes_d >= mk_sl_cui_uint8_size_bytes_d
	mk_lang_assert(rem >= 1 && rem < mk_sl_cui_uint64_size_bytes_v);
	if(m * mk_sl_cui_uint64_size_bytes_v == n)
	{
		mk_lib_crypto_hash_block_sha3_base_f(&sha3_512->m_sha3_base);
	}
	mk_sl_uint_convert_64_8_le_to_sml(&sha3_512->m_sha3_base.m_data.m_uint64s[i], &tu8s[0]);
	mk_sl_cui_uint8_memcpy_fn(&d[0], &tu8s[0], ((mk_lang_types_usize_t)(rem)));
	#endif
}
#include "mk_lang_warning_msvc_pop.h"


#endif
