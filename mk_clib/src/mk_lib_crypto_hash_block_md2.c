#ifndef mk_include_guard_mk_lib_crypto_hash_block_md2_c
#define mk_include_guard_mk_lib_crypto_hash_block_md2_c
#include "mk_lib_crypto_hash_block_md2.h"

/* RFC 1115 */
/* RFC 1319 */

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_pow2.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_bitops_bulk.h"
#include "mk_sl_cui_uint8.h"


union mk_lib_crypto_hash_block_md2_x_data_u
{
	mk_lang_alignas(mk_lang_pow2_roundup(48)) mk_sl_cui_uint8_t m_uint8s[48];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_md2_x_data_u mk_lib_crypto_hash_block_md2_x_data_t;
struct mk_lib_crypto_hash_block_md2_x_s
{
	mk_lib_crypto_hash_block_md2_x_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_md2_x_s mk_lib_crypto_hash_block_md2_x_t;
typedef mk_lib_crypto_hash_block_md2_x_t const mk_lib_crypto_hash_block_md2_x_ct;
typedef mk_lib_crypto_hash_block_md2_x_t* mk_lib_crypto_hash_block_md2_x_pt;
typedef mk_lib_crypto_hash_block_md2_x_t const* mk_lib_crypto_hash_block_md2_x_pct;

union mk_lib_crypto_hash_block_md2_table_data_u
{
	mk_lang_alignas(0xff + 1) mk_sl_cui_uint8_t m_uint8s[0xff + 1];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_md2_table_data_u mk_lib_crypto_hash_block_md2_table_data_t;
struct mk_lib_crypto_hash_block_md2_table_s
{
	mk_lib_crypto_hash_block_md2_table_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_md2_table_s mk_lib_crypto_hash_block_md2_table_t;
typedef mk_lib_crypto_hash_block_md2_table_t const mk_lib_crypto_hash_block_md2_table_ct;
typedef mk_lib_crypto_hash_block_md2_table_t* mk_lib_crypto_hash_block_md2_table_pt;
typedef mk_lib_crypto_hash_block_md2_table_t const* mk_lib_crypto_hash_block_md2_table_pct;


mk_lang_constexpr_static_inline mk_lib_crypto_hash_block_md2_table_t const mk_lib_crypto_hash_block_md2_table =
{{{
	mk_sl_cui_uint8_c(0x29), mk_sl_cui_uint8_c(0x2e), mk_sl_cui_uint8_c(0x43), mk_sl_cui_uint8_c(0xc9), mk_sl_cui_uint8_c(0xa2), mk_sl_cui_uint8_c(0xd8), mk_sl_cui_uint8_c(0x7c), mk_sl_cui_uint8_c(0x01), mk_sl_cui_uint8_c(0x3d), mk_sl_cui_uint8_c(0x36), mk_sl_cui_uint8_c(0x54), mk_sl_cui_uint8_c(0xa1), mk_sl_cui_uint8_c(0xec), mk_sl_cui_uint8_c(0xf0), mk_sl_cui_uint8_c(0x06), mk_sl_cui_uint8_c(0x13),
	mk_sl_cui_uint8_c(0x62), mk_sl_cui_uint8_c(0xa7), mk_sl_cui_uint8_c(0x05), mk_sl_cui_uint8_c(0xf3), mk_sl_cui_uint8_c(0xc0), mk_sl_cui_uint8_c(0xc7), mk_sl_cui_uint8_c(0x73), mk_sl_cui_uint8_c(0x8c), mk_sl_cui_uint8_c(0x98), mk_sl_cui_uint8_c(0x93), mk_sl_cui_uint8_c(0x2b), mk_sl_cui_uint8_c(0xd9), mk_sl_cui_uint8_c(0xbc), mk_sl_cui_uint8_c(0x4c), mk_sl_cui_uint8_c(0x82), mk_sl_cui_uint8_c(0xca),
	mk_sl_cui_uint8_c(0x1e), mk_sl_cui_uint8_c(0x9b), mk_sl_cui_uint8_c(0x57), mk_sl_cui_uint8_c(0x3c), mk_sl_cui_uint8_c(0xfd), mk_sl_cui_uint8_c(0xd4), mk_sl_cui_uint8_c(0xe0), mk_sl_cui_uint8_c(0x16), mk_sl_cui_uint8_c(0x67), mk_sl_cui_uint8_c(0x42), mk_sl_cui_uint8_c(0x6f), mk_sl_cui_uint8_c(0x18), mk_sl_cui_uint8_c(0x8a), mk_sl_cui_uint8_c(0x17), mk_sl_cui_uint8_c(0xe5), mk_sl_cui_uint8_c(0x12),
	mk_sl_cui_uint8_c(0xbe), mk_sl_cui_uint8_c(0x4e), mk_sl_cui_uint8_c(0xc4), mk_sl_cui_uint8_c(0xd6), mk_sl_cui_uint8_c(0xda), mk_sl_cui_uint8_c(0x9e), mk_sl_cui_uint8_c(0xde), mk_sl_cui_uint8_c(0x49), mk_sl_cui_uint8_c(0xa0), mk_sl_cui_uint8_c(0xfb), mk_sl_cui_uint8_c(0xf5), mk_sl_cui_uint8_c(0x8e), mk_sl_cui_uint8_c(0xbb), mk_sl_cui_uint8_c(0x2f), mk_sl_cui_uint8_c(0xee), mk_sl_cui_uint8_c(0x7a),
	mk_sl_cui_uint8_c(0xa9), mk_sl_cui_uint8_c(0x68), mk_sl_cui_uint8_c(0x79), mk_sl_cui_uint8_c(0x91), mk_sl_cui_uint8_c(0x15), mk_sl_cui_uint8_c(0xb2), mk_sl_cui_uint8_c(0x07), mk_sl_cui_uint8_c(0x3f), mk_sl_cui_uint8_c(0x94), mk_sl_cui_uint8_c(0xc2), mk_sl_cui_uint8_c(0x10), mk_sl_cui_uint8_c(0x89), mk_sl_cui_uint8_c(0x0b), mk_sl_cui_uint8_c(0x22), mk_sl_cui_uint8_c(0x5f), mk_sl_cui_uint8_c(0x21),
	mk_sl_cui_uint8_c(0x80), mk_sl_cui_uint8_c(0x7f), mk_sl_cui_uint8_c(0x5d), mk_sl_cui_uint8_c(0x9a), mk_sl_cui_uint8_c(0x5a), mk_sl_cui_uint8_c(0x90), mk_sl_cui_uint8_c(0x32), mk_sl_cui_uint8_c(0x27), mk_sl_cui_uint8_c(0x35), mk_sl_cui_uint8_c(0x3e), mk_sl_cui_uint8_c(0xcc), mk_sl_cui_uint8_c(0xe7), mk_sl_cui_uint8_c(0xbf), mk_sl_cui_uint8_c(0xf7), mk_sl_cui_uint8_c(0x97), mk_sl_cui_uint8_c(0x03),
	mk_sl_cui_uint8_c(0xff), mk_sl_cui_uint8_c(0x19), mk_sl_cui_uint8_c(0x30), mk_sl_cui_uint8_c(0xb3), mk_sl_cui_uint8_c(0x48), mk_sl_cui_uint8_c(0xa5), mk_sl_cui_uint8_c(0xb5), mk_sl_cui_uint8_c(0xd1), mk_sl_cui_uint8_c(0xd7), mk_sl_cui_uint8_c(0x5e), mk_sl_cui_uint8_c(0x92), mk_sl_cui_uint8_c(0x2a), mk_sl_cui_uint8_c(0xac), mk_sl_cui_uint8_c(0x56), mk_sl_cui_uint8_c(0xaa), mk_sl_cui_uint8_c(0xc6),
	mk_sl_cui_uint8_c(0x4f), mk_sl_cui_uint8_c(0xb8), mk_sl_cui_uint8_c(0x38), mk_sl_cui_uint8_c(0xd2), mk_sl_cui_uint8_c(0x96), mk_sl_cui_uint8_c(0xa4), mk_sl_cui_uint8_c(0x7d), mk_sl_cui_uint8_c(0xb6), mk_sl_cui_uint8_c(0x76), mk_sl_cui_uint8_c(0xfc), mk_sl_cui_uint8_c(0x6b), mk_sl_cui_uint8_c(0xe2), mk_sl_cui_uint8_c(0x9c), mk_sl_cui_uint8_c(0x74), mk_sl_cui_uint8_c(0x04), mk_sl_cui_uint8_c(0xf1),
	mk_sl_cui_uint8_c(0x45), mk_sl_cui_uint8_c(0x9d), mk_sl_cui_uint8_c(0x70), mk_sl_cui_uint8_c(0x59), mk_sl_cui_uint8_c(0x64), mk_sl_cui_uint8_c(0x71), mk_sl_cui_uint8_c(0x87), mk_sl_cui_uint8_c(0x20), mk_sl_cui_uint8_c(0x86), mk_sl_cui_uint8_c(0x5b), mk_sl_cui_uint8_c(0xcf), mk_sl_cui_uint8_c(0x65), mk_sl_cui_uint8_c(0xe6), mk_sl_cui_uint8_c(0x2d), mk_sl_cui_uint8_c(0xa8), mk_sl_cui_uint8_c(0x02),
	mk_sl_cui_uint8_c(0x1b), mk_sl_cui_uint8_c(0x60), mk_sl_cui_uint8_c(0x25), mk_sl_cui_uint8_c(0xad), mk_sl_cui_uint8_c(0xae), mk_sl_cui_uint8_c(0xb0), mk_sl_cui_uint8_c(0xb9), mk_sl_cui_uint8_c(0xf6), mk_sl_cui_uint8_c(0x1c), mk_sl_cui_uint8_c(0x46), mk_sl_cui_uint8_c(0x61), mk_sl_cui_uint8_c(0x69), mk_sl_cui_uint8_c(0x34), mk_sl_cui_uint8_c(0x40), mk_sl_cui_uint8_c(0x7e), mk_sl_cui_uint8_c(0x0f),
	mk_sl_cui_uint8_c(0x55), mk_sl_cui_uint8_c(0x47), mk_sl_cui_uint8_c(0xa3), mk_sl_cui_uint8_c(0x23), mk_sl_cui_uint8_c(0xdd), mk_sl_cui_uint8_c(0x51), mk_sl_cui_uint8_c(0xaf), mk_sl_cui_uint8_c(0x3a), mk_sl_cui_uint8_c(0xc3), mk_sl_cui_uint8_c(0x5c), mk_sl_cui_uint8_c(0xf9), mk_sl_cui_uint8_c(0xce), mk_sl_cui_uint8_c(0xba), mk_sl_cui_uint8_c(0xc5), mk_sl_cui_uint8_c(0xea), mk_sl_cui_uint8_c(0x26),
	mk_sl_cui_uint8_c(0x2c), mk_sl_cui_uint8_c(0x53), mk_sl_cui_uint8_c(0x0d), mk_sl_cui_uint8_c(0x6e), mk_sl_cui_uint8_c(0x85), mk_sl_cui_uint8_c(0x28), mk_sl_cui_uint8_c(0x84), mk_sl_cui_uint8_c(0x09), mk_sl_cui_uint8_c(0xd3), mk_sl_cui_uint8_c(0xdf), mk_sl_cui_uint8_c(0xcd), mk_sl_cui_uint8_c(0xf4), mk_sl_cui_uint8_c(0x41), mk_sl_cui_uint8_c(0x81), mk_sl_cui_uint8_c(0x4d), mk_sl_cui_uint8_c(0x52),
	mk_sl_cui_uint8_c(0x6a), mk_sl_cui_uint8_c(0xdc), mk_sl_cui_uint8_c(0x37), mk_sl_cui_uint8_c(0xc8), mk_sl_cui_uint8_c(0x6c), mk_sl_cui_uint8_c(0xc1), mk_sl_cui_uint8_c(0xab), mk_sl_cui_uint8_c(0xfa), mk_sl_cui_uint8_c(0x24), mk_sl_cui_uint8_c(0xe1), mk_sl_cui_uint8_c(0x7b), mk_sl_cui_uint8_c(0x08), mk_sl_cui_uint8_c(0x0c), mk_sl_cui_uint8_c(0xbd), mk_sl_cui_uint8_c(0xb1), mk_sl_cui_uint8_c(0x4a),
	mk_sl_cui_uint8_c(0x78), mk_sl_cui_uint8_c(0x88), mk_sl_cui_uint8_c(0x95), mk_sl_cui_uint8_c(0x8b), mk_sl_cui_uint8_c(0xe3), mk_sl_cui_uint8_c(0x63), mk_sl_cui_uint8_c(0xe8), mk_sl_cui_uint8_c(0x6d), mk_sl_cui_uint8_c(0xe9), mk_sl_cui_uint8_c(0xcb), mk_sl_cui_uint8_c(0xd5), mk_sl_cui_uint8_c(0xfe), mk_sl_cui_uint8_c(0x3b), mk_sl_cui_uint8_c(0x00), mk_sl_cui_uint8_c(0x1d), mk_sl_cui_uint8_c(0x39),
	mk_sl_cui_uint8_c(0xf2), mk_sl_cui_uint8_c(0xef), mk_sl_cui_uint8_c(0xb7), mk_sl_cui_uint8_c(0x0e), mk_sl_cui_uint8_c(0x66), mk_sl_cui_uint8_c(0x58), mk_sl_cui_uint8_c(0xd0), mk_sl_cui_uint8_c(0xe4), mk_sl_cui_uint8_c(0xa6), mk_sl_cui_uint8_c(0x77), mk_sl_cui_uint8_c(0x72), mk_sl_cui_uint8_c(0xf8), mk_sl_cui_uint8_c(0xeb), mk_sl_cui_uint8_c(0x75), mk_sl_cui_uint8_c(0x4b), mk_sl_cui_uint8_c(0x0a),
	mk_sl_cui_uint8_c(0x31), mk_sl_cui_uint8_c(0x44), mk_sl_cui_uint8_c(0x50), mk_sl_cui_uint8_c(0xb4), mk_sl_cui_uint8_c(0x8f), mk_sl_cui_uint8_c(0xed), mk_sl_cui_uint8_c(0x1f), mk_sl_cui_uint8_c(0x1a), mk_sl_cui_uint8_c(0xdb), mk_sl_cui_uint8_c(0x99), mk_sl_cui_uint8_c(0x8d), mk_sl_cui_uint8_c(0x33), mk_sl_cui_uint8_c(0x9f), mk_sl_cui_uint8_c(0x11), mk_sl_cui_uint8_c(0x83), mk_sl_cui_uint8_c(0x14),
}}};


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_md2_init(mk_lib_crypto_hash_block_md2_pt const md2) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_md2_block_t) == 16);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_md2_digest_t) == 16);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_md2_x_t) >= 48);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_md2_table_t) == 256);

	mk_lang_assert(md2);

	mk_sl_cui_uint8_memclr_fn(&md2->m_state.m_data.m_uint8s[0], mk_lang_countof(md2->m_state.m_data.m_uint8s));
	mk_sl_cui_uint8_memclr_fn(&md2->m_checksum.m_data.m_uint8s[0], mk_lang_countof(md2->m_checksum.m_data.m_uint8s));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_md2_append_blocks(mk_lib_crypto_hash_block_md2_pt const md2, mk_lib_crypto_hash_block_md2_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_md2_x_t x mk_lang_constexpr_init;
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	mk_lang_types_uint_t t mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_lang_types_sint_t k mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(md2);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_md2_block_len_v);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_cui_uint8_memcpy_fn(&x.m_data.m_uint8s[0 * 16], &md2->m_state.m_data.m_uint8s[0], mk_lang_countof(md2->m_state.m_data.m_uint8s));
	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		mk_sl_cui_uint8_memcpy_fn(&x.m_data.m_uint8s[1 * 16], &pblocks[iblock].m_data.m_uint8s[0], mk_lang_countof(pblocks[iblock].m_data.m_uint8s));
		mk_lib_crypto_bitops_bulk_uint8_16_xor3(&x.m_data.m_uint8s[0 * 16], &x.m_data.m_uint8s[1 * 16], &x.m_data.m_uint8s[2 * 16]);
		t = 0;
		for(j = 0; j != 18; ++j)
		{
			for(k = 0; k != 48; ++k)
			{
				#include "mk_lang_warning_msvc_push_c4296.h"
				#include "mk_lang_warning_gcc_push_type_limits.h"
				mk_lang_assert(t >= 0x00 && t <= 0xff);
				#include "mk_lang_warning_gcc_pop.h"
				#include "mk_lang_warning_msvc_pop.h"
				mk_sl_cui_uint8_xor2(&x.m_data.m_uint8s[k], &mk_lib_crypto_hash_block_md2_table.m_data.m_uint8s[t]);
				mk_sl_cui_uint8_to_bi_uint(&x.m_data.m_uint8s[k], &t);
			}
			t = (t + ((mk_lang_types_uint_t)(j))) & 0xff;
		}
		ta = md2->m_checksum.m_data.m_uint8s[15];
		for(j = 0; j != 16; ++j)
		{
			mk_sl_cui_uint8_xor2(&ta, &pblocks[iblock].m_data.m_uint8s[j]);
			mk_sl_cui_uint8_to_bi_uint(&ta, &t);
			#include "mk_lang_warning_msvc_push_c4296.h"
			#include "mk_lang_warning_gcc_push_type_limits.h"
			mk_lang_assert(t >= 0x00 && t <= 0xff);
			#include "mk_lang_warning_gcc_pop.h"
			#include "mk_lang_warning_msvc_pop.h"
			mk_sl_cui_uint8_xor2(&md2->m_checksum.m_data.m_uint8s[j], &mk_lib_crypto_hash_block_md2_table.m_data.m_uint8s[t]);
			ta = md2->m_checksum.m_data.m_uint8s[j];
		}
	}
	mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&md2->m_state.m_data.m_uint8s[0], &x.m_data.m_uint8s[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_md2_finish(mk_lib_crypto_hash_block_md2_pt const md2, mk_lib_crypto_hash_block_md2_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_md2_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_types_sint_t rest mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;

	mk_lang_assert(md2);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_md2_block_len_v);
	mk_lang_assert(digest);

	rest = mk_lib_crypto_hash_block_md2_block_len_v - idx;
	mk_sl_cui_uint8_from_bi_sint(&ta, &rest);
	mk_sl_cui_uint8_memset_fn(&block->m_data.m_uint8s[idx], &ta, ((mk_lang_types_usize_t)(rest)));
	mk_lib_crypto_hash_block_md2_append_blocks(md2, block, 1);
	mk_lib_crypto_hash_block_md2_append_blocks(md2, &md2->m_checksum, 1);
	mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&digest->m_data.m_uint8s[0], &md2->m_state.m_data.m_uint8s[0]);
}


#endif
