#include "mk_lib_crypto_hash_block_tiger2_128.h"

/* http://www.cs.technion.ac.il/~biham/Reports/Tiger/ */

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_tiger_base.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_tiger2_128_init(mk_lib_crypto_hash_block_tiger2_128_pt const tiger2_128) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_tiger2_128_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_tiger2_128_digest_t) == 16);

	mk_lang_assert(tiger2_128);

	mk_lib_crypto_hash_block_tiger_base_init(&tiger2_128->m_tiger);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_tiger2_128_append_blocks(mk_lib_crypto_hash_block_tiger2_128_pt const tiger2_128, mk_lib_crypto_hash_block_tiger2_128_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(tiger2_128);

	mk_lib_crypto_hash_block_tiger_base_append_blocks(&tiger2_128->m_tiger, pblocks, nblocks);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_tiger2_128_finish(mk_lib_crypto_hash_block_tiger2_128_pt const tiger2_128, mk_lib_crypto_hash_block_tiger2_128_block_pt const block, int const idx, mk_lib_crypto_hash_block_tiger2_128_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_tiger_base_digest_t base_digest mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(tiger2_128);

	mk_lib_crypto_hash_block_tiger_base_finish(&tiger2_128->m_tiger, mk_lang_true, block, idx, &base_digest);
	for(i = 0; i != mk_lib_crypto_hash_block_tiger2_128_digest_len; ++i)
	{
		digest->m_uint8s[i] = base_digest.m_uint8s[i];
	}
}
