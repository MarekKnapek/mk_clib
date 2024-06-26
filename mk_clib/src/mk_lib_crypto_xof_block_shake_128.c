#include "mk_lib_crypto_xof_block_shake_128.h"

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

#define mk_lang_memset_t_name mk_lib_crypto_xof_block_shake_128_memset
#define mk_lang_memset_t_type mk_sl_cui_uint8_t
#include "mk_lang_memset_inl_fileh.h"
#include "mk_lang_memset_inl_filec.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_block_shake_128_mix_block(mk_lib_crypto_xof_block_shake_128_pt const shake_128, mk_lib_crypto_xof_block_shake_128_block_pct const block) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;

	mk_lang_static_assert((mk_lib_crypto_xof_block_shake_128_block_len % 8) == 0);

	mk_lang_assert(shake_128);
	mk_lang_assert(block);

	n = mk_lib_crypto_xof_block_shake_128_block_len / 8;
	for(i = 0; i != n; ++i)
	{
		mk_sl_uint_64_from_8_le(&ta, &block->m_uint8s[i * 8]);
		mk_sl_cui_uint64_xor2(&shake_128->m_sha3.m_uint64s[i], &ta);
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_shake_128_init(mk_lib_crypto_xof_block_shake_128_pt const shake_128) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_xof_block_shake_128_block_t) == 168);

	mk_lang_assert(shake_128);

	mk_lib_crypto_hash_block_sha3_base_init(&shake_128->m_sha3);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_shake_128_append_blocks(mk_lib_crypto_xof_block_shake_128_pt const shake_128, mk_lib_crypto_xof_block_shake_128_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;

	mk_lang_assert(shake_128);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_xof_block_shake_128_block_len);

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		mk_lib_crypto_xof_block_shake_128_mix_block(shake_128, &pblocks[iblock]);
		mk_lib_crypto_hash_block_sha3_base_f(&shake_128->m_sha3);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_shake_128_finish(mk_lib_crypto_xof_block_shake_128_pt const shake_128, mk_lib_crypto_xof_block_shake_128_block_pt const block, mk_lang_types_sint_t const idx) mk_lang_noexcept
{
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_lang_types_sint_t rest mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;

	mk_lang_static_assert((mk_lib_crypto_xof_block_shake_128_block_len % 8) == 0);

	mk_lang_assert(shake_128);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_xof_block_shake_128_block_len);

	tuc = 0x1f; mk_sl_cui_uint8_from_bi_uchar(&block->m_uint8s[idx], &tuc);
	rest = mk_lib_crypto_xof_block_shake_128_block_len - idx - 1;
	mk_sl_cui_uint8_set_zero(&tu8);
	mk_lib_crypto_xof_block_shake_128_memset_fn(&block->m_uint8s[idx + 1], &tu8, rest);
	tuc = 0x80; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc);
	mk_sl_cui_uint8_or2(&block->m_uint8s[mk_lib_crypto_xof_block_shake_128_block_len - 1], &tu8);
	mk_lib_crypto_xof_block_shake_128_mix_block(shake_128, block);
	shake_128->m_idx = 0;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_shake_128_squeeze(mk_lib_crypto_xof_block_shake_128_pt const shake_128, mk_lang_types_usize_t const len, mk_sl_cui_uint8_pt const digest) mk_lang_noexcept
{
	#define bytes_per_word ((mk_lang_types_sint_t)(sizeof(mk_sl_cui_uint64_t) / sizeof(mk_sl_cui_uint8_t)))
	#define words_per_block ((mk_lang_types_sint_t)(mk_lib_crypto_xof_block_shake_128_block_len / bytes_per_word))

	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out mk_lang_constexpr_init;
	mk_lang_types_sint_t nfbytes mk_lang_constexpr_init;
	mk_lang_types_sint_t ifword mk_lang_constexpr_init;
	mk_sl_cui_uint8_t first_word[bytes_per_word] mk_lang_constexpr_init;
	mk_lang_types_sint_t ifbyte mk_lang_constexpr_init;
	mk_lang_types_sint_t nfwords mk_lang_constexpr_init;
	mk_lang_types_usize_t nblocks mk_lang_constexpr_init;
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	mk_lang_types_sint_t nwords mk_lang_constexpr_init;
	mk_lang_types_sint_t iword mk_lang_constexpr_init;
	mk_sl_cui_uint8_t last_word[bytes_per_word] mk_lang_constexpr_init;
	mk_lang_types_sint_t nbytes mk_lang_constexpr_init;
	mk_lang_types_sint_t ibyte mk_lang_constexpr_init;

	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert((mk_lang_types_sint_t)(sizeof(mk_sl_cui_uint64_t) % sizeof(mk_sl_cui_uint8_t)) == 0);
	mk_lang_static_assert(mk_lib_crypto_xof_block_shake_128_block_len % bytes_per_word == 0);

	mk_lang_assert(shake_128);
	mk_lang_assert(len >= 0);
	mk_lang_assert(digest);
	mk_lang_assert(shake_128->m_idx >= 0 && shake_128->m_idx < mk_lib_crypto_xof_block_shake_128_block_len);

	rem = len;
	out = digest;
	if(shake_128->m_idx != 0)
	{
		nfbytes = bytes_per_word - (shake_128->m_idx - ((shake_128->m_idx / bytes_per_word) * bytes_per_word));
		nfbytes = ((mk_lang_types_sint_t)(mk_lang_min(((mk_lang_types_usize_t)(nfbytes)), rem)));
		nfbytes = nfbytes % bytes_per_word;
		if(nfbytes != 0)
		{
			ifword = shake_128->m_idx / bytes_per_word;
			mk_sl_uint_64_to_8_le(&shake_128->m_sha3.m_uint64s[ifword], &first_word[0]);
			for(ifbyte = 0; ifbyte != nfbytes; ++ifbyte)
			{
				out[ifbyte] = first_word[shake_128->m_idx % bytes_per_word + ifbyte];
			}
			rem = rem - nfbytes;
			out = out + nfbytes;
			shake_128->m_idx = (shake_128->m_idx + nfbytes) % mk_lib_crypto_xof_block_shake_128_block_len;
		}
		nfwords = (mk_lib_crypto_xof_block_shake_128_block_len - shake_128->m_idx) / bytes_per_word;
		nfwords = ((mk_lang_types_sint_t)(mk_lang_min(((mk_lang_types_usize_t)(nfwords)), rem / bytes_per_word)));
		nfwords = nfwords % words_per_block;
		if(nfwords != 0 && shake_128->m_idx == 0)
		{
			mk_lib_crypto_hash_block_sha3_base_f(&shake_128->m_sha3);
		}
		for(ifword = 0; ifword != nfwords; ++ifword, out += bytes_per_word)
		{
			mk_sl_uint_64_to_8_le(&shake_128->m_sha3.m_uint64s[shake_128->m_idx / bytes_per_word + ifword], out);
		}
		rem = rem - nfwords * bytes_per_word;
		shake_128->m_idx = (shake_128->m_idx + nfwords * bytes_per_word) % mk_lib_crypto_xof_block_shake_128_block_len;
	}
	nblocks = rem / mk_lib_crypto_xof_block_shake_128_block_len;
	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		mk_lang_assert(shake_128->m_idx == 0);
		mk_lib_crypto_hash_block_sha3_base_f(&shake_128->m_sha3);
		nwords = mk_lib_crypto_xof_block_shake_128_block_len / bytes_per_word;
		for(iword = 0; iword != nwords; ++iword, out += bytes_per_word)
		{
			mk_sl_uint_64_to_8_le(&shake_128->m_sha3.m_uint64s[iword], out);
		}
	}
	rem = rem - nblocks * mk_lib_crypto_xof_block_shake_128_block_len;
	mk_lang_assert(rem >= 0 && rem < mk_lib_crypto_xof_block_shake_128_block_len);
	mk_lang_assert(rem < ((mk_lang_types_usize_t)(mk_lib_crypto_xof_block_shake_128_block_len - shake_128->m_idx)));
	if(rem != 0)
	{
		if(shake_128->m_idx == 0)
		{
			mk_lib_crypto_hash_block_sha3_base_f(&shake_128->m_sha3);
		}
		nwords = ((mk_lang_types_sint_t)(rem)) / bytes_per_word;
		for(iword = 0; iword != nwords; ++iword, out += bytes_per_word)
		{
			mk_sl_uint_64_to_8_le(&shake_128->m_sha3.m_uint64s[shake_128->m_idx / bytes_per_word + iword], out);
		}
		shake_128->m_idx = (shake_128->m_idx + nwords * bytes_per_word) % mk_lib_crypto_xof_block_shake_128_block_len;
		rem = rem - nwords * bytes_per_word;
		mk_lang_assert(rem >= 0 && rem < bytes_per_word);
		mk_lang_assert(rem < ((mk_lang_types_usize_t)(mk_lib_crypto_xof_block_shake_128_block_len - shake_128->m_idx)));
		if(rem != 0)
		{
			mk_sl_uint_64_to_8_le(&shake_128->m_sha3.m_uint64s[shake_128->m_idx / bytes_per_word], &last_word[0]);
			nbytes = ((mk_lang_types_sint_t)(rem));
			for(ibyte = 0; ibyte != nbytes; ++ibyte)
			{
				out[ibyte] = last_word[shake_128->m_idx % bytes_per_word + ibyte];
			}
			shake_128->m_idx = (shake_128->m_idx + rem) % mk_lib_crypto_xof_block_shake_128_block_len;
		}
	}

	#undef bytes_per_word
	#undef words_per_block
}
