#include "mk_lib_crypto_hash_block_md2.h"

/* rfc1115 */
/* rfc1319 */

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


union mk_lib_crypto_hash_block_md2_aligned48_u
{
	mk_sl_cui_uint8_t m_uint8s[48];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_md2_aligned48_u mk_lib_crypto_hash_block_md2_aligned48_t;
typedef mk_lib_crypto_hash_block_md2_aligned48_t const mk_lib_crypto_hash_block_md2_aligned48_ct;
typedef mk_lib_crypto_hash_block_md2_aligned48_t* mk_lib_crypto_hash_block_md2_aligned48_pt;
typedef mk_lib_crypto_hash_block_md2_aligned48_t const* mk_lib_crypto_hash_block_md2_aligned48_pct;

union mk_lib_crypto_hash_block_md2_aligned256_u
{
	mk_sl_cui_uint8_t m_uint8s[0xff + 1];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_md2_aligned256_u mk_lib_crypto_hash_block_md2_aligned256_t;
typedef mk_lib_crypto_hash_block_md2_aligned256_t const mk_lib_crypto_hash_block_md2_aligned256_ct;
typedef mk_lib_crypto_hash_block_md2_aligned256_t* mk_lib_crypto_hash_block_md2_aligned256_pt;
typedef mk_lib_crypto_hash_block_md2_aligned256_t const* mk_lib_crypto_hash_block_md2_aligned256_pct;


mk_lang_constexpr_static mk_lib_crypto_hash_block_md2_aligned256_t const s_mk_lib_crypto_hash_block_md2_table =
{
	0x29, 0x2e, 0x43, 0xc9, 0xa2, 0xd8, 0x7c, 0x01, 0x3d, 0x36, 0x54, 0xa1, 0xec, 0xf0, 0x06, 0x13,
	0x62, 0xa7, 0x05, 0xf3, 0xc0, 0xc7, 0x73, 0x8c, 0x98, 0x93, 0x2b, 0xd9, 0xbc, 0x4c, 0x82, 0xca,
	0x1e, 0x9b, 0x57, 0x3c, 0xfd, 0xd4, 0xe0, 0x16, 0x67, 0x42, 0x6f, 0x18, 0x8a, 0x17, 0xe5, 0x12,
	0xbe, 0x4e, 0xc4, 0xd6, 0xda, 0x9e, 0xde, 0x49, 0xa0, 0xfb, 0xf5, 0x8e, 0xbb, 0x2f, 0xee, 0x7a,
	0xa9, 0x68, 0x79, 0x91, 0x15, 0xb2, 0x07, 0x3f, 0x94, 0xc2, 0x10, 0x89, 0x0b, 0x22, 0x5f, 0x21,
	0x80, 0x7f, 0x5d, 0x9a, 0x5a, 0x90, 0x32, 0x27, 0x35, 0x3e, 0xcc, 0xe7, 0xbf, 0xf7, 0x97, 0x03,
	0xff, 0x19, 0x30, 0xb3, 0x48, 0xa5, 0xb5, 0xd1, 0xd7, 0x5e, 0x92, 0x2a, 0xac, 0x56, 0xaa, 0xc6,
	0x4f, 0xb8, 0x38, 0xd2, 0x96, 0xa4, 0x7d, 0xb6, 0x76, 0xfc, 0x6b, 0xe2, 0x9c, 0x74, 0x04, 0xf1,
	0x45, 0x9d, 0x70, 0x59, 0x64, 0x71, 0x87, 0x20, 0x86, 0x5b, 0xcf, 0x65, 0xe6, 0x2d, 0xa8, 0x02,
	0x1b, 0x60, 0x25, 0xad, 0xae, 0xb0, 0xb9, 0xf6, 0x1c, 0x46, 0x61, 0x69, 0x34, 0x40, 0x7e, 0x0f,
	0x55, 0x47, 0xa3, 0x23, 0xdd, 0x51, 0xaf, 0x3a, 0xc3, 0x5c, 0xf9, 0xce, 0xba, 0xc5, 0xea, 0x26,
	0x2c, 0x53, 0x0d, 0x6e, 0x85, 0x28, 0x84, 0x09, 0xd3, 0xdf, 0xcd, 0xf4, 0x41, 0x81, 0x4d, 0x52,
	0x6a, 0xdc, 0x37, 0xc8, 0x6c, 0xc1, 0xab, 0xfa, 0x24, 0xe1, 0x7b, 0x08, 0x0c, 0xbd, 0xb1, 0x4a,
	0x78, 0x88, 0x95, 0x8b, 0xe3, 0x63, 0xe8, 0x6d, 0xe9, 0xcb, 0xd5, 0xfe, 0x3b, 0x00, 0x1d, 0x39,
	0xf2, 0xef, 0xb7, 0x0e, 0x66, 0x58, 0xd0, 0xe4, 0xa6, 0x77, 0x72, 0xf8, 0xeb, 0x75, 0x4b, 0x0a,
	0x31, 0x44, 0x50, 0xb4, 0x8f, 0xed, 0x1f, 0x1a, 0xdb, 0x99, 0x8d, 0x33, 0x9f, 0x11, 0x83, 0x14,
};


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_md2_init(mk_lib_crypto_hash_block_md2_pt const md2) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(md2);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_md2_block_t) == 16);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_md2_digest_t) == 16);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_md2_aligned48_t) == 48);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_md2_aligned256_t) == 256);

	for(i = 0; i != 16; ++i)
	{
		mk_sl_cui_uint8_set_zero(&md2->m_state.m_uint8s[i]);
	}
	for(i = 0; i != 16; ++i)
	{
		mk_sl_cui_uint8_set_zero(&md2->m_checksum.m_uint8s[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_md2_append_blocks(mk_lib_crypto_hash_block_md2_pt const md2, mk_lib_crypto_hash_block_md2_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_md2_aligned48_t x mk_lang_constexpr_init;
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	unsigned t mk_lang_constexpr_init;
	int j mk_lang_constexpr_init;
	int k mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;

	mk_lang_assert(md2);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / 16);

	for(i = 0; i != 16; ++i)
	{
		x.m_uint8s[0 * 16 + i] = md2->m_state.m_uint8s[i];
	}
	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		for(i = 0; i != 16; ++i)
		{
			x.m_uint8s[1 * 16 + i] = pblocks[iblock].m_uint8s[i];
		}
		for(i = 0; i != 16; ++i)
		{
			mk_sl_cui_uint8_xor3(&x.m_uint8s[0 * 16 + i], &x.m_uint8s[1 * 16 + i], &x.m_uint8s[2 * 16 + i]);
		}
		t = 0;
		for(j = 0; j != 18; ++j)
		{
			for(k = 0; k != 48; ++k)
			{
				mk_lang_assert(t >= 0x00 && t <= 0xff);
				mk_sl_cui_uint8_xor2(&x.m_uint8s[k], &s_mk_lib_crypto_hash_block_md2_table.m_uint8s[t]);
				mk_sl_cui_uint8_to_bi_uint(&x.m_uint8s[k], &t);
			}
			t = (t + j) & 0xff;
		}
		ta = md2->m_checksum.m_uint8s[15];
		for(j = 0; j != 16; ++j)
		{
			mk_sl_cui_uint8_xor2(&ta, &pblocks[iblock].m_uint8s[j]);
			mk_sl_cui_uint8_to_bi_uint(&ta, &t); mk_lang_assert(t >= 0x00 && t <= 0xff);
			mk_sl_cui_uint8_xor2(&md2->m_checksum.m_uint8s[j], &s_mk_lib_crypto_hash_block_md2_table.m_uint8s[t]);
			ta = md2->m_checksum.m_uint8s[j];
		}
	}
	for(i = 0; i != 16; ++i)
	{
		md2->m_state.m_uint8s[i] = x.m_uint8s[i];
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_md2_finish(mk_lib_crypto_hash_block_md2_pt const md2, mk_lib_crypto_hash_block_md2_block_pt const block, int const idx, mk_lib_crypto_hash_block_md2_digest_pt const digest) mk_lang_noexcept
{
	int rest mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(md2);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < 16);
	mk_lang_assert(digest);

	rest = 16 - idx;
	mk_sl_cui_uint8_from_bi_sint(&ta, &rest);
	for(i = 0; i != rest; ++i)
	{
		block->m_uint8s[idx + i] = ta;
	}
	mk_lib_crypto_hash_block_md2_append_blocks(md2, block, 1);
	mk_lib_crypto_hash_block_md2_append_blocks(md2, &md2->m_checksum, 1);
	for(i = 0; i != 16; ++i)
	{
		digest->m_uint8s[i] = md2->m_state.m_uint8s[i];
	}
}
