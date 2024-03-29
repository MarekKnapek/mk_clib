#include "mk_lib_crypto_hash_block_sha2_512.h"

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
#include "mk_lib_crypto_hash_block_sha2_base_64bit.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint128.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


mk_lang_constexpr_static_inline mk_sl_cui_uint64_t const s_mk_lib_crypto_hash_block_sha2_512_init[8] =
{
	mk_sl_cui_uint64_c(0x6a09e667ul, 0xf3bcc908ul),
	mk_sl_cui_uint64_c(0xbb67ae85ul, 0x84caa73bul),
	mk_sl_cui_uint64_c(0x3c6ef372ul, 0xfe94f82bul),
	mk_sl_cui_uint64_c(0xa54ff53aul, 0x5f1d36f1ul),
	mk_sl_cui_uint64_c(0x510e527ful, 0xade682d1ul),
	mk_sl_cui_uint64_c(0x9b05688cul, 0x2b3e6c1ful),
	mk_sl_cui_uint64_c(0x1f83d9abul, 0xfb41bd6bul),
	mk_sl_cui_uint64_c(0x5be0cd19ul, 0x137e2179ul),
};


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha2_512_init(mk_lib_crypto_hash_block_sha2_512_pt const sha2_512) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint128_t) == 16);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_512_block_t) == 128);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_512_digest_t) == 64);

	mk_lang_assert(sha2_512);

	mk_lib_crypto_hash_block_sha2_base_64bit_init(&sha2_512->m_64bit, s_mk_lib_crypto_hash_block_sha2_512_init);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha2_512_append_blocks(mk_lib_crypto_hash_block_sha2_512_pt const sha2_512, mk_lib_crypto_hash_block_sha2_512_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(sha2_512);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha2_512_block_len);

	mk_lib_crypto_hash_block_sha2_base_64bit_append_blocks(&sha2_512->m_64bit, pblocks, nblocks);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha2_512_finish(mk_lib_crypto_hash_block_sha2_512_pt const sha2_512, mk_lib_crypto_hash_block_sha2_512_block_pt const block, int const idx, mk_lib_crypto_hash_block_sha2_512_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_assert(sha2_512);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_sha2_512_block_len);
	mk_lang_assert(digest);

	mk_lib_crypto_hash_block_sha2_base_64bit_finish(&sha2_512->m_64bit, block, idx, digest);
}
