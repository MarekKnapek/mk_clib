#include "mk_lib_crypto_xof_block_shake_256.h"

/* nist fips pub 202 */

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_sha3_base.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint8.h"

#define mk_lang_memset_t_name mk_lib_crypto_xof_block_shake_256_memset
#define mk_lang_memset_t_base mk_sl_cui_uint8
#include "mk_lang_memset_inl_fileh.h"
#include "mk_lang_memset_inl_filec.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_block_shake_256_mix_block(mk_lib_crypto_xof_block_shake_256_pt const shake_256, mk_lib_crypto_xof_block_shake_256_block_pct const block) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;

	mk_lang_static_assert((mk_lib_crypto_xof_block_shake_256_block_len % 8) == 0);

	mk_lang_assert(shake_256);
	mk_lang_assert(block);

	n = mk_lib_crypto_xof_block_shake_256_block_len / 8;
	for(i = 0; i != n; ++i)
	{
		mk_sl_uint_64_from_8_le(&ta, &block->m_uint8s[i * 8]);
		mk_sl_cui_uint64_xor2(&shake_256->m_sha3.m_uint64s[i], &ta);
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_shake_256_init(mk_lib_crypto_xof_block_shake_256_pt const shake_256) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_xof_block_shake_256_block_t) == 136);

	mk_lang_assert(shake_256);

	mk_lib_crypto_hash_block_sha3_base_init(&shake_256->m_sha3);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_shake_256_append_blocks(mk_lib_crypto_xof_block_shake_256_pt const shake_256, mk_lib_crypto_xof_block_shake_256_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;

	mk_lang_assert(shake_256);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_xof_block_shake_256_block_len);

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		mk_lib_crypto_xof_block_shake_256_mix_block(shake_256, &pblocks[iblock]);
		mk_lib_crypto_hash_block_sha3_base_f(&shake_256->m_sha3);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_shake_256_finish(mk_lib_crypto_xof_block_shake_256_pt const shake_256, mk_lib_crypto_xof_block_shake_256_block_pt const block, mk_lang_types_sint_t const idx) mk_lang_noexcept
{
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_lang_types_sint_t rest mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;

	mk_lang_static_assert((mk_lib_crypto_xof_block_shake_256_block_len % 8) == 0);

	mk_lang_assert(shake_256);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_xof_block_shake_256_block_len);

	tuc = 0x1f; mk_sl_cui_uint8_from_bi_uchar(&block->m_uint8s[idx], &tuc);
	rest = mk_lib_crypto_xof_block_shake_256_block_len - idx - 1;
	mk_sl_cui_uint8_set_zero(&tu8);
	mk_lib_crypto_xof_block_shake_256_memset_fn(&block->m_uint8s[idx + 1], &tu8, rest);
	tuc = 0x80; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc);
	mk_sl_cui_uint8_or2(&block->m_uint8s[mk_lib_crypto_xof_block_shake_256_block_len - 1], &tu8);
	mk_lib_crypto_xof_block_shake_256_mix_block(shake_256, block);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_shake_256_squeeze(mk_lib_crypto_xof_block_shake_256_pt const shake_256, mk_lang_types_usize_t const len, mk_sl_cui_uint8_pt const digest) mk_lang_noexcept
{
	#define bytes_per_word ((mk_lang_types_sint_t)(sizeof(mk_sl_cui_uint64_t) / sizeof(mk_sl_cui_uint8_t)))

	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out mk_lang_constexpr_init;
	mk_lang_types_usize_t nblocks mk_lang_constexpr_init;
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	mk_lang_types_sint_t nwords mk_lang_constexpr_init;
	mk_lang_types_sint_t iword mk_lang_constexpr_init;
	mk_sl_cui_uint8_t last_word[bytes_per_word] mk_lang_constexpr_init;
	mk_lang_types_sint_t nbytes mk_lang_constexpr_init;
	mk_lang_types_sint_t ibyte mk_lang_constexpr_init;

	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(mk_lib_crypto_xof_block_shake_256_block_len % bytes_per_word == 0);

	mk_lang_assert(shake_256);
	mk_lang_assert(len >= 0);
	mk_lang_assert(digest);

	rem = len;
	out = digest;
	nblocks = rem / mk_lib_crypto_xof_block_shake_256_block_len;
	rem = rem - nblocks * mk_lib_crypto_xof_block_shake_256_block_len;
	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		mk_lib_crypto_hash_block_sha3_base_f(&shake_256->m_sha3);
		nwords = mk_lib_crypto_xof_block_shake_256_block_len / bytes_per_word;
		for(iword = 0; iword != nwords; ++iword, out += bytes_per_word)
		{
			mk_sl_uint_64_to_8_le(&shake_256->m_sha3.m_uint64s[iword], out);
		}
	}
	mk_lang_assert(rem >= 0 && rem < mk_lib_crypto_xof_block_shake_256_block_len);
	if(rem != 0)
	{
		mk_lib_crypto_hash_block_sha3_base_f(&shake_256->m_sha3);
		nwords = ((mk_lang_types_sint_t)(rem)) / bytes_per_word;
		rem = rem - nwords * bytes_per_word;
		for(iword = 0; iword != nwords; ++iword, out += bytes_per_word)
		{
			mk_sl_uint_64_to_8_le(&shake_256->m_sha3.m_uint64s[iword], out);
		}
		mk_lang_assert(rem >= 0 && rem < bytes_per_word);
		if(rem != 0)
		{
			mk_sl_uint_64_to_8_le(&shake_256->m_sha3.m_uint64s[iword], &last_word[0]);
			nbytes = ((mk_lang_types_sint_t)(rem));
			for(ibyte = 0; ibyte != nbytes; ++ibyte)
			{
				out[ibyte] = last_word[ibyte];
			}
		}
	}

	#undef bytes_per_word
}
