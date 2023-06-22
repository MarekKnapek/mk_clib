#include "mk_lib_crypto_hash_block_sha3_512.h"

/* nist fips pub 202 */

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_sha3_base.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_sha3_512_mix_block(mk_lib_crypto_hash_block_sha3_512_pt const sha3_512, mk_lib_crypto_hash_block_sha3_512_block_pct const block) mk_lang_noexcept
{
	int n mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;

	mk_lang_static_assert((mk_lib_crypto_hash_block_sha3_512_block_len % 8) == 0);

	mk_lang_assert(sha3_512);
	mk_lang_assert(block);

	n = mk_lib_crypto_hash_block_sha3_512_block_len / 8;
	for(i = 0; i != n; ++i)
	{
		mk_sl_uint_64_from_8_le(&ta, &block->m_uint8s[i * 8]);
		mk_sl_cui_uint64_xor2(&sha3_512->m_sha3.m_uint64s[i], &ta);
	}
}


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha3_512_init(mk_lib_crypto_hash_block_sha3_512_pt const sha3_512) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha3_512_block_t) == 72);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha3_512_digest_t) == 64);

	mk_lang_assert(sha3_512);

	mk_lib_crypto_hash_block_sha3_base_init(&sha3_512->m_sha3);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha3_512_append_blocks(mk_lib_crypto_hash_block_sha3_512_pt const sha3_512, mk_lib_crypto_hash_block_sha3_512_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;

	mk_lang_assert(sha3_512);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha3_512_block_len);

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		mk_lib_crypto_hash_block_sha3_512_mix_block(sha3_512, &pblocks[iblock]);
		mk_lib_crypto_hash_block_sha3_base_f(&sha3_512->m_sha3);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha3_512_finish(mk_lib_crypto_hash_block_sha3_512_pt const sha3_512, mk_lib_crypto_hash_block_sha3_512_block_pt const block, int const idx, mk_lib_crypto_hash_block_sha3_512_digest_pt const digest) mk_lang_noexcept
{
	#define digest_smol ((mk_lib_crypto_hash_block_sha3_512_digest_len % 8) != 0)

	unsigned char uch mk_lang_constexpr_init;
	int rest mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt d mk_lang_constexpr_init;
	int rem mk_lang_constexpr_init;
	int n mk_lang_constexpr_init;
	int m mk_lang_constexpr_init;
	#if digest_smol
	mk_sl_cui_uint8_t digest_big[mk_lang_div_roundup(mk_lib_crypto_hash_block_sha3_512_digest_len, 8) * 8] mk_lang_constexpr_init;
	#endif

	mk_lang_assert(sha3_512);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_sha3_512_block_len);
	mk_lang_assert(digest);

	uch = 0x06;
	mk_sl_cui_uint8_from_bi_uchar(&block->m_uint8s[idx], &uch);
	rest = mk_lib_crypto_hash_block_sha3_512_block_len - idx - 1;
	for(i = 0; i != rest; ++i)
	{
		mk_sl_cui_uint8_set_zero(&block->m_uint8s[idx + 1 + i]);
	}
	uch = 0x80;
	mk_sl_cui_uint8_from_bi_uchar(&ta, &uch);
	mk_sl_cui_uint8_or2(&block->m_uint8s[mk_lib_crypto_hash_block_sha3_512_block_len - 1], &ta);
	mk_lib_crypto_hash_block_sha3_512_append_blocks(sha3_512, block, 1);
	#if digest_smol
	d = digest_big;
	#else
	d = digest->m_uint8s;
	#endif
	rem = mk_lib_crypto_hash_block_sha3_512_digest_len;
	n = mk_lang_min(mk_lib_crypto_hash_block_sha3_512_block_len, rem);
	m = mk_lang_div_roundup(n, 8);
	for(i = 0; i != m; ++i)
	{
		mk_sl_uint_64_to_8_le(&sha3_512->m_sha3.m_uint64s[i], &d[i * 8]);
	}
	d += m * 8;
	rem -= m * 8;
	while(rem > 0)
	{
		mk_lib_crypto_hash_block_sha3_base_f(&sha3_512->m_sha3);
		n = mk_lang_min(mk_lib_crypto_hash_block_sha3_512_block_len, rem);
		m = mk_lang_div_roundup(n, 8);
		for(i = 0; i != m; ++i)
		{
			mk_sl_uint_64_to_8_le(&sha3_512->m_sha3.m_uint64s[i], &d[i * 8]);
		}
		d += m * 8;
		rem -= m * 8;
	}
	#if digest_smol
	for(i = 0; i != mk_lib_crypto_hash_block_sha3_512_digest_len; ++i)
	{
		digest->m_uint8s[i] = digest_big[i];
	}
	#endif

	#undef digest_smol
}
