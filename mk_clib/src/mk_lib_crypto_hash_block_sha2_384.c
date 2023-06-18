#include "mk_lib_crypto_hash_block_sha2_384.h"

/* nist fips pub 180-2 */
/* nist fips pub 180-3 */
/* nist fips pub 180-4 */

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_sha2_64bit.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint128.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


mk_lang_constexpr_static_inline mk_sl_cui_uint64_t const s_mk_lib_crypto_hash_block_sha2_384_init[8] =
{
	mk_sl_cui_uint64_c(0xcbbb9d5dul, 0xc1059ed8ul),
	mk_sl_cui_uint64_c(0x629a292aul, 0x367cd507ul),
	mk_sl_cui_uint64_c(0x9159015aul, 0x3070dd17ul),
	mk_sl_cui_uint64_c(0x152fecd8ul, 0xf70e5939ul),
	mk_sl_cui_uint64_c(0x67332667ul, 0xffc00b31ul),
	mk_sl_cui_uint64_c(0x8eb44a87ul, 0x68581511ul),
	mk_sl_cui_uint64_c(0xdb0c2e0dul, 0x64f98fa7ul),
	mk_sl_cui_uint64_c(0x47b5481dul, 0xbefa4fa4ul),
};


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha2_384_init(mk_lib_crypto_hash_block_sha2_384_pt const sha2_384) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint128_t) == 16);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_384_block_t) == 128);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_384_digest_t) == 48);

	mk_lang_assert(sha2_384);

	mk_lib_crypto_hash_block_sha2_64bit_init(&sha2_384->m_64bit, s_mk_lib_crypto_hash_block_sha2_384_init);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha2_384_append_blocks(mk_lib_crypto_hash_block_sha2_384_pt const sha2_384, mk_lib_crypto_hash_block_sha2_384_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(sha2_384);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha2_384_block_len);

	mk_lib_crypto_hash_block_sha2_64bit_append_blocks(&sha2_384->m_64bit, pblocks, nblocks);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha2_384_finish(mk_lib_crypto_hash_block_sha2_384_pt const sha2_384, mk_lib_crypto_hash_block_sha2_384_block_pt const block, int const idx, mk_lib_crypto_hash_block_sha2_384_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_sha2_64bit_digest_t dgst mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(sha2_384);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < 128);
	mk_lang_assert(digest);

	mk_lib_crypto_hash_block_sha2_64bit_finish(&sha2_384->m_64bit, block, idx, &dgst);
	for(i = 0; i != 48; ++i)
	{
		digest->m_uint8s[i] = dgst.m_uint8s[i];
	}
}
