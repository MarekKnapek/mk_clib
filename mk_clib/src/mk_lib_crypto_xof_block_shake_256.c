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


mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_xof_block_shake_256_mix_block(mk_lib_crypto_xof_block_shake_256_pt const shake_256, mk_lib_crypto_xof_block_shake_256_block_pct const block) mk_lang_noexcept
{
	int n mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
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


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_xof_block_shake_256_init(mk_lib_crypto_xof_block_shake_256_pt const shake_256) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_xof_block_shake_256_block_t) == 136);
	mk_lang_static_assert(sizeof(mk_lib_crypto_xof_block_shake_256_digest_t) == sizeof(mk_lang_types_ulllong_t));

	mk_lang_assert(shake_256);

	mk_lib_crypto_hash_block_sha3_base_init(&shake_256->m_sha3);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_xof_block_shake_256_append_blocks(mk_lib_crypto_xof_block_shake_256_pt const shake_256, mk_lib_crypto_xof_block_shake_256_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
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

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_xof_block_shake_256_finish(mk_lib_crypto_xof_block_shake_256_pt const shake_256, mk_lib_crypto_xof_block_shake_256_block_pt const block, int const idx, mk_lang_types_usize_t const digest_len, mk_lib_crypto_xof_block_shake_256_digest_pt const digest) mk_lang_noexcept
{
	#define get_digest(d, i) (((d)[i / sizeof(mk_lang_types_ulllong_t)]).m_uint8s[i % sizeof(mk_lang_types_ulllong_t)])

	unsigned char uch mk_lang_constexpr_init;
	int rest mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_lang_types_usize_t out mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	int m mk_lang_constexpr_init;
	mk_lang_types_usize_t j mk_lang_constexpr_init;
	mk_sl_cui_uint8_t big[8] mk_lang_constexpr_init;

	mk_lang_static_assert((mk_lib_crypto_xof_block_shake_256_block_len % 8) == 0);

	mk_lang_assert(shake_256);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_xof_block_shake_256_block_len);
	mk_lang_assert(digest_len >= 1);
	mk_lang_assert(digest);

	uch = 0x1f;
	mk_sl_cui_uint8_from_bi_uchar(&block->m_uint8s[idx], &uch);
	rest = mk_lib_crypto_xof_block_shake_256_block_len - idx - 1;
	for(i = 0; i != rest; ++i)
	{
		mk_sl_cui_uint8_set_zero(&block->m_uint8s[idx + 1 + i]);
	}
	uch = 0x80;
	mk_sl_cui_uint8_from_bi_uchar(&ta, &uch);
	mk_sl_cui_uint8_or2(&block->m_uint8s[mk_lib_crypto_xof_block_shake_256_block_len - 1], &ta);
	mk_lib_crypto_xof_block_shake_256_mix_block(shake_256, block);
	rem = digest_len;
	out = 0;
	n = rem / mk_lib_crypto_xof_block_shake_256_block_len;
	for(j = 0; j != n; ++j)
	{
		mk_lib_crypto_hash_block_sha3_base_f(&shake_256->m_sha3);
		m = mk_lib_crypto_xof_block_shake_256_block_len / 8;
		for(i = 0; i != m; ++i, out += 8)
		{
			mk_sl_uint_64_to_8_le(&shake_256->m_sha3.m_uint64s[i], &get_digest(digest, out));
		}
	}
	rem -= n * mk_lib_crypto_xof_block_shake_256_block_len;
	mk_lang_assert(rem >= 0 && rem < mk_lib_crypto_xof_block_shake_256_block_len);
	if(rem != 0)
	{
		mk_lib_crypto_hash_block_sha3_base_f(&shake_256->m_sha3);
		m = ((int)(rem)) / 8;
		for(i = 0; i != m; ++i, out += 8)
		{
			mk_sl_uint_64_to_8_le(&shake_256->m_sha3.m_uint64s[i], &get_digest(digest, out));
		}
		rem -= m * 8;
		mk_lang_assert(rem >= 0 && rem < 8);
		mk_sl_uint_64_to_8_le(&shake_256->m_sha3.m_uint64s[i], big);
		m = ((int)(rem));
		for(i = 0; i != m; ++i, ++out)
		{
			get_digest(digest, out) = big[i];
		}
	}

	#undef get_digest
}
