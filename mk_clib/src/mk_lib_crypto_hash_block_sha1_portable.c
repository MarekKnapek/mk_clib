#ifndef mk_include_guard_mk_lib_crypto_hash_block_sha1_portable_c
#define mk_include_guard_mk_lib_crypto_hash_block_sha1_portable_c
#include "mk_lib_crypto_hash_block_sha1_portable.h"

/* NIST FIPS PUB 180-1 */
/* NIST FIPS PUB 180-2 */
/* NIST FIPS PUB 180-3 */
/* NIST FIPS PUB 180-4 */

#include "mk_lang_alignas.h"
#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_pow2.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_bitops_bulk.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"


union mk_lib_crypto_hash_block_sha1_portable_block2_data_u
{
	mk_sl_cui_uint32_t m_u32s[16];
	mk_lib_crypto_hash_block_sha1_portable_block_t m_align;
};
typedef union mk_lib_crypto_hash_block_sha1_portable_block2_data_u mk_lib_crypto_hash_block_sha1_portable_block2_data_t;
struct mk_lib_crypto_hash_block_sha1_portable_block2_s
{
	mk_lang_alignas(mk_lib_crypto_hash_block_sha1_portable_block_len_v) mk_lib_crypto_hash_block_sha1_portable_block2_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_sha1_portable_block2_s mk_lib_crypto_hash_block_sha1_portable_block2_t;
typedef mk_lib_crypto_hash_block_sha1_portable_block2_t const mk_lib_crypto_hash_block_sha1_portable_block2_ct;
typedef mk_lib_crypto_hash_block_sha1_portable_block2_t* mk_lib_crypto_hash_block_sha1_portable_block2_pt;
typedef mk_lib_crypto_hash_block_sha1_portable_block2_t const* mk_lib_crypto_hash_block_sha1_portable_block2_pct;


mk_lang_constexpr_static_inline mk_sl_cui_uint32_t const mk_lib_crypto_hash_block_sha1_portable_k_init[5] =
{
	mk_sl_cui_uint32_c(0x67452301ul),
	mk_sl_cui_uint32_c(0xefcdab89ul),
	mk_sl_cui_uint32_c(0x98badcfeul),
	mk_sl_cui_uint32_c(0x10325476ul),
	mk_sl_cui_uint32_c(0xc3d2e1f0ul),
};
mk_lang_constexpr_static_inline mk_sl_cui_uint32_t const mk_lib_crypto_hash_block_sha1_portable_k_table[4] =
{
	mk_sl_cui_uint32_c(0x5a827999ul),
	mk_sl_cui_uint32_c(0x6ed9eba1ul),
	mk_sl_cui_uint32_c(0x8f1bbcdcul),
	mk_sl_cui_uint32_c(0xca62c1d6ul),
};


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha1_portable_ch(mk_sl_cui_uint32_prct const x, mk_sl_cui_uint32_prct const y, mk_sl_cui_uint32_prct const z, mk_sl_cui_uint32_prt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);
	mk_lang_assert(ret);
	mk_lang_assert(x != y);
	mk_lang_assert(x != z);
	mk_lang_assert(x != ret);
	mk_lang_assert(y != z);
	mk_lang_assert(y != ret);
	mk_lang_assert(z != ret);

	/* return (x & y) | ((~x) & z); */

	mk_sl_cui_uint32_and3(x, y, &ta);
	mk_sl_cui_uint32_not2(x, &tb);
	mk_sl_cui_uint32_and2(&tb, z);
	mk_sl_cui_uint32_or3(&ta, &tb, ret);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha1_portable_parity(mk_sl_cui_uint32_prct const x, mk_sl_cui_uint32_prct const y, mk_sl_cui_uint32_prct const z, mk_sl_cui_uint32_prt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);
	mk_lang_assert(ret);
	mk_lang_assert(x != y);
	mk_lang_assert(x != z);
	mk_lang_assert(x != ret);
	mk_lang_assert(y != z);
	mk_lang_assert(y != ret);
	mk_lang_assert(z != ret);

	/* return x ^ y ^ z; */

	mk_sl_cui_uint32_xor3(x, y, &ta);
	mk_sl_cui_uint32_xor3(&ta, z, ret);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha1_portable_maj(mk_sl_cui_uint32_prct const x, mk_sl_cui_uint32_prct const y, mk_sl_cui_uint32_prct const z, mk_sl_cui_uint32_prt const ret) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);
	mk_lang_assert(ret);
	mk_lang_assert(x != y);
	mk_lang_assert(x != z);
	mk_lang_assert(x != ret);
	mk_lang_assert(y != z);
	mk_lang_assert(y != ret);
	mk_lang_assert(z != ret);

	/* return (x & y) ^ (x & z) ^ (y & z); */

	mk_sl_cui_uint32_and3(x, y, &ta);
	mk_sl_cui_uint32_and3(x, z, &tb);
	mk_sl_cui_uint32_and3(y, z, &tc);
	mk_sl_cui_uint32_xor2(&ta, &tb);
	mk_sl_cui_uint32_xor3(&ta, &tc, ret);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_sha1_portable_f(mk_lang_types_sint_t const idx, mk_sl_cui_uint32_prct const x, mk_sl_cui_uint32_prct const y, mk_sl_cui_uint32_prct const z, mk_sl_cui_uint32_prt const ret) mk_lang_noexcept
{
	mk_lang_assert(idx >= 0 && idx < 80);
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(z);
	mk_lang_assert(ret);
	mk_lang_assert(x != y);
	mk_lang_assert(x != z);
	mk_lang_assert(x != ret);
	mk_lang_assert(y != z);
	mk_lang_assert(y != ret);
	mk_lang_assert(z != ret);

	switch(idx / 20)
	{
		case 0: mk_lib_crypto_hash_block_sha1_portable_ch    (x, y, z, ret); break;
		case 1: mk_lib_crypto_hash_block_sha1_portable_parity(x, y, z, ret); break;
		case 2: mk_lib_crypto_hash_block_sha1_portable_maj   (x, y, z, ret); break;
		case 3: mk_lib_crypto_hash_block_sha1_portable_parity(x, y, z, ret); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha1_portable_init(mk_lib_crypto_hash_block_sha1_portable_pt const sha1_portable) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha1_portable_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha1_portable_digest_t) >= 20);

	mk_lang_assert(sha1_portable);

	mk_lib_crypto_bitops_bulk_uint32_5_memcpy(&sha1_portable->m_state[0], &mk_lib_crypto_hash_block_sha1_portable_k_init[0]);
	mk_sl_cui_uint64_set_zero(&sha1_portable->m_len);
}

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha1_portable_append_blocks(mk_lib_crypto_hash_block_sha1_portable_pt const sha1_portable, mk_lib_crypto_hash_block_sha1_portable_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_sl_cui_uint32_pt a mk_lang_constexpr_init;
	mk_sl_cui_uint32_t h[5] mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt b mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt c mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt d mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt e mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tt mk_lang_constexpr_init;
	mk_sl_cui_uint32_t old_state[5] mk_lang_constexpr_init;
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	mk_lang_types_sint_t ir mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_sha1_portable_block2_t w mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t t mk_lang_constexpr_init;

	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha1_portable_block2_t) == sizeof(mk_lib_crypto_hash_block_sha1_portable_block_t));
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_hash_block_sha1_portable_block2_t) == mk_lang_alignof(mk_lib_crypto_hash_block_sha1_portable_block_t));

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(sha1_portable);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha1_portable_block_len_v);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(nblocks != 0)
	{
		a = &h[0];
		b = &h[1];
		c = &h[2];
		d = &h[3];
		e = &h[4];
		mk_sl_cui_uint64_from_bi_usize(&tt, &nblocks);
		mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&sha1_portable->m_len, &tt));
		mk_sl_cui_uint64_add2_wrap_cid_cod(&sha1_portable->m_len, &tt);
		mk_lib_crypto_bitops_bulk_uint32_5_memcpy(&old_state[0], &sha1_portable->m_state[0]);
		for(iblock = 0; iblock != nblocks; ++iblock)
		{
			mk_lib_crypto_bitops_bulk_uint32_5_memcpy(&h[0], &old_state[0]);
			for(ir = 0; ir != 80; ++ir)
			{
				if(ir < 16)
				{
					mk_sl_uint_convert_32_8_be_to_big(&w.m_data.m_u32s[(ir - 0) % 16], &pblocks[iblock].m_data.m_uint8s[ir * mk_sl_cui_uint32_size_bytes_v]);
				}
				else if(ir >= 16)
				{
					/* w[i] = rotl(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1); */
					mk_sl_cui_uint32_xor3(&w.m_data.m_u32s[(ir -  3) % 16], &w.m_data.m_u32s[(ir -  8) % 16], &ta);
					mk_sl_cui_uint32_xor3(&w.m_data.m_u32s[(ir - 14) % 16], &w.m_data.m_u32s[(ir - 16) % 16], &tb);
					mk_sl_cui_uint32_xor2(&ta, &tb);
					mk_sl_cui_uint32_rotl3(&ta, 1, &w.m_data.m_u32s[(ir - 0) % 16]);
				}
				else
				{
					mk_lang_assert(mk_lang_false);
				}
				/* t = rotl(a, 5) + f(i, b, c, d) + e + k(i) + w[i]; */
				mk_sl_cui_uint32_rotl3(a, 5, &ta);
				mk_lib_crypto_hash_block_sha1_portable_f(ir, b, c, d, &tb);
				mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &tb);
				mk_sl_cui_uint32_add3_wrap_cid_cod(e, &w.m_data.m_u32s[(ir - 0) % 16], &tb);
				mk_sl_cui_uint32_add2_wrap_cid_cod(&tb, &mk_lib_crypto_hash_block_sha1_portable_k_table[ir / 20]);
				mk_sl_cui_uint32_add3_wrap_cid_cod(&ta, &tb, &t);
				*e = *d;
				*d = *c;
				mk_sl_cui_uint32_rotl3(b, 30, c);
				*b = *a;
				*a = t;
			}
			mk_lib_crypto_bitops_bulk_uint32_5_add2_wrap_cid_cod(&old_state[0], &h[0]);
		}
		mk_lib_crypto_bitops_bulk_uint32_5_memcpy(&sha1_portable->m_state[0], &old_state[0]);
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha1_portable_finish(mk_lib_crypto_hash_block_sha1_portable_pt const sha1_portable, mk_lib_crypto_hash_block_sha1_portable_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_sha1_portable_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tb mk_lang_constexpr_init;
	mk_lang_types_sint_t rest mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(sha1_portable);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_sha1_portable_block_len_v);
	mk_lang_assert(digest);

	ui = mk_lib_crypto_hash_block_sha1_portable_block_len_v; mk_sl_cui_uint64_from_bi_uint(&ta, &ui);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_mul(&sha1_portable->m_len, &ta));
	mk_sl_cui_uint64_shl3(&sha1_portable->m_len, 6, &ta);
	mk_sl_cui_uint64_from_bi_sint(&tb, &idx);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&ta, &tb));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&ta, &tb);
	ui = 8; mk_sl_cui_uint64_from_bi_uint(&tb, &ui);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_mul(&ta, &tb));
	mk_sl_cui_uint64_shl2(&ta, 3);

	ui = 0x80; mk_sl_cui_uint8_from_bi_uint(&block->m_data.m_uint8s[idx], &ui);
	rest = mk_lib_crypto_hash_block_sha1_portable_block_len_v - idx - 1;
	mk_lang_assert(rest >= 0 && rest <= mk_lib_crypto_hash_block_sha1_portable_block_len_v - 1);
	if(rest >= mk_sl_cui_uint64_size_bytes_v)
	{
		mk_sl_cui_uint8_memclr_fn(&block->m_data.m_uint8s[idx + 1], ((mk_lang_types_usize_t)(rest - mk_sl_cui_uint64_size_bytes_v)));
	}
	else
	{
		mk_sl_cui_uint8_memclr_fn(&block->m_data.m_uint8s[idx + 1], ((mk_lang_types_usize_t)(rest)));
		mk_lib_crypto_hash_block_sha1_portable_append_blocks(sha1_portable, block, 1);
		mk_sl_cui_uint8_memclr_fn(&block->m_data.m_uint8s[0], ((mk_lang_types_sint_t)(mk_lib_crypto_hash_block_sha1_portable_block_len_v)) - ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v)));
	}

	mk_sl_uint_convert_64_8_be_to_sml(&ta, &block->m_data.m_uint8s[((mk_lang_types_sint_t)(mk_lib_crypto_hash_block_sha1_portable_block_len_v)) - ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v))]);
	mk_lib_crypto_hash_block_sha1_portable_append_blocks(sha1_portable, block, 1);
	for(i = 0; i != mk_lang_countof(sha1_portable->m_state); ++i)
	{
		mk_sl_uint_convert_32_8_be_to_sml(&sha1_portable->m_state[i], &digest->m_data.m_uint8s[i * mk_sl_cui_uint32_size_bytes_v]);
	}
}
#include "mk_lang_warning_msvc_pop.h"


#endif
