#ifndef mk_include_guard_mk_lib_crypto_hash_block_blake2s_base_c
#define mk_include_guard_mk_lib_crypto_hash_block_blake2s_base_c
#include "mk_lib_crypto_hash_block_blake2s_base.h"

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_bitops_bulk.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"


enum mk_lib_crypto_hash_block_blake2s_base_max_key_len_e { mk_lib_crypto_hash_block_blake2s_base_max_key_len_v = 32 }; typedef enum mk_lib_crypto_hash_block_blake2s_base_max_key_len_e mk_lib_crypto_hash_block_blake2s_base_max_key_len_t;
enum mk_lib_crypto_hash_block_blake2s_base_max_salt_len_e { mk_lib_crypto_hash_block_blake2s_base_max_salt_len_v = 8 }; typedef enum mk_lib_crypto_hash_block_blake2s_base_max_salt_len_e mk_lib_crypto_hash_block_blake2s_base_max_salt_len_t;
enum mk_lib_crypto_hash_block_blake2s_base_max_personalization_len_e { mk_lib_crypto_hash_block_blake2s_base_max_personalization_len_v = 8 }; typedef enum mk_lib_crypto_hash_block_blake2s_base_max_personalization_len_e mk_lib_crypto_hash_block_blake2s_base_max_personalization_len_t;


union mk_lib_crypto_hash_block_blake2s_base_state2_data_u
{
	mk_sl_cui_uint8_t m_uint8s[32];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_blake2s_base_state2_data_u mk_lib_crypto_hash_block_blake2s_base_state2_data_t;
struct mk_lib_crypto_hash_block_blake2s_base_state2_s
{
	mk_lang_alignas(sizeof(mk_lib_crypto_hash_block_blake2s_base_state2_data_t)) mk_lib_crypto_hash_block_blake2s_base_state2_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_blake2s_base_state2_s mk_lib_crypto_hash_block_blake2s_base_state2_t;
typedef mk_lib_crypto_hash_block_blake2s_base_state2_t const mk_lib_crypto_hash_block_blake2s_base_state2_ct;
typedef mk_lib_crypto_hash_block_blake2s_base_state2_t* mk_lib_crypto_hash_block_blake2s_base_state2_pt;
typedef mk_lib_crypto_hash_block_blake2s_base_state2_t const* mk_lib_crypto_hash_block_blake2s_base_state2_pct;

union mk_lib_crypto_hash_block_blake2s_base_v_data_u
{
	mk_sl_cui_uint32_t m_uint32s[16];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_blake2s_base_v_data_u mk_lib_crypto_hash_block_blake2s_base_v_data_t;
struct mk_lib_crypto_hash_block_blake2s_base_v_s
{
	mk_lang_alignas(sizeof(mk_lib_crypto_hash_block_blake2s_base_v_data_t)) mk_lib_crypto_hash_block_blake2s_base_v_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_blake2s_base_v_s mk_lib_crypto_hash_block_blake2s_base_v_t;
typedef mk_lib_crypto_hash_block_blake2s_base_v_t const mk_lib_crypto_hash_block_blake2s_base_v_ct;
typedef mk_lib_crypto_hash_block_blake2s_base_v_t* mk_lib_crypto_hash_block_blake2s_base_v_pt;
typedef mk_lib_crypto_hash_block_blake2s_base_v_t const* mk_lib_crypto_hash_block_blake2s_base_v_pct;

union mk_lib_crypto_hash_block_blake2s_base_init_data_u
{
	mk_sl_cui_uint32_t m_uint32s[8];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_blake2s_base_init_data_u mk_lib_crypto_hash_block_blake2s_base_init_data_t;
struct mk_lib_crypto_hash_block_blake2s_base_init_s
{
	mk_lang_alignas(sizeof(mk_lib_crypto_hash_block_blake2s_base_init_data_t)) mk_lib_crypto_hash_block_blake2s_base_init_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_blake2s_base_init_s mk_lib_crypto_hash_block_blake2s_base_init_t;


mk_lang_constexpr_static_inline mk_lib_crypto_hash_block_blake2s_base_init_t const mk_lib_crypto_hash_block_blake2s_base_k_init =
{{{
	mk_sl_cui_uint32_c(0x6a09e667ul),
	mk_sl_cui_uint32_c(0xbb67ae85ul),
	mk_sl_cui_uint32_c(0x3c6ef372ul),
	mk_sl_cui_uint32_c(0xa54ff53aul),
	mk_sl_cui_uint32_c(0x510e527ful),
	mk_sl_cui_uint32_c(0x9b05688cul),
	mk_sl_cui_uint32_c(0x1f83d9abul),
	mk_sl_cui_uint32_c(0x5be0cd19ul),
}}};

mk_lang_constexpr_static_inline mk_lang_types_uchar_t const mk_lib_crypto_hash_block_blake2s_base_k_sigma[10][16] =
{
	{  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, },
	{ 14, 10,  4,  8,  9, 15, 13,  6,  1, 12,  0,  2, 11,  7,  5,  3, },
	{ 11,  8, 12,  0,  5,  2, 15, 13, 10, 14,  3,  6,  7,  1,  9,  4, },
	{  7,  9,  3,  1, 13, 12, 11, 14,  2,  6,  5, 10,  4,  0, 15,  8, },
	{  9,  0,  5,  7,  2,  4, 10, 15, 14,  1, 11, 12,  6,  8,  3, 13, },
	{  2, 12,  6, 10,  0, 11,  8,  3,  4, 13,  7,  5, 15, 14,  1,  9, },
	{ 12,  5,  1, 15, 14, 13,  4, 10,  0,  7,  6,  3,  9,  2,  8, 11, },
	{ 13, 11,  7, 14, 12,  1,  3,  9,  5,  0, 15,  4,  8,  6,  2, 10, },
	{  6, 15, 14,  9, 11,  3,  0,  8, 12,  2, 13,  7,  1,  4, 10,  5, },
	{ 10,  2,  8,  4,  7,  6,  1,  5, 15, 11,  9, 14,  3, 12, 13,  0, },
};


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake2s_base_g(mk_lib_crypto_hash_block_blake2s_base_v_pt const v, mk_lib_crypto_hash_block_blake2s_base_block_pct const block, mk_lang_types_sint_t const a, mk_lang_types_sint_t const b, mk_lang_types_sint_t const c, mk_lang_types_sint_t const d, mk_lang_types_sint_t const xi, mk_lang_types_sint_t const yi) mk_lang_noexcept
{
	mk_sl_cui_uint32_t x mk_lang_constexpr_init;
	mk_sl_cui_uint32_t y mk_lang_constexpr_init;

	mk_lang_assert(v);
	mk_lang_assert(block);
	mk_lang_assert(a >= 0 && a < 16);
	mk_lang_assert(b >= 0 && b < 16);
	mk_lang_assert(c >= 0 && c < 16);
	mk_lang_assert(d >= 0 && d < 16);
	mk_lang_assert(xi >= 0 && xi < 16);
	mk_lang_assert(yi >= 0 && yi < 16);

	mk_sl_cui_uint32_add2_wrap_cid_cod(&v->m_data.m_uint32s[a], &v->m_data.m_uint32s[b]);
	mk_sl_uint_convert_32_8_le_to_big(&x, &block->m_data.m_uint8s[xi * mk_sl_cui_uint32_size_bytes_v]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&v->m_data.m_uint32s[a], &x);
	mk_sl_cui_uint32_xor2(&v->m_data.m_uint32s[d], &v->m_data.m_uint32s[a]);
	mk_sl_cui_uint32_rotr2(&v->m_data.m_uint32s[d], 16);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&v->m_data.m_uint32s[c], &v->m_data.m_uint32s[d]);
	mk_sl_cui_uint32_xor2(&v->m_data.m_uint32s[b], &v->m_data.m_uint32s[c]);
	mk_sl_cui_uint32_rotr2(&v->m_data.m_uint32s[b], 12);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&v->m_data.m_uint32s[a], &v->m_data.m_uint32s[b]);
	mk_sl_uint_convert_32_8_le_to_big(&y, &block->m_data.m_uint8s[yi * mk_sl_cui_uint32_size_bytes_v]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&v->m_data.m_uint32s[a], &y);
	mk_sl_cui_uint32_xor2(&v->m_data.m_uint32s[d], &v->m_data.m_uint32s[a]);
	mk_sl_cui_uint32_rotr2(&v->m_data.m_uint32s[d], 8);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&v->m_data.m_uint32s[c], &v->m_data.m_uint32s[d]);
	mk_sl_cui_uint32_xor2(&v->m_data.m_uint32s[b], &v->m_data.m_uint32s[c]);
	mk_sl_cui_uint32_rotr2(&v->m_data.m_uint32s[b], 7);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake2s_base_round(mk_lib_crypto_hash_block_blake2s_base_v_pt const v, mk_lib_crypto_hash_block_blake2s_base_block_pct const block, mk_lang_types_sint_t const i) mk_lang_noexcept
{
	mk_lang_assert(v);
	mk_lang_assert(block);
	mk_lang_assert(i >= 0 && i < 10);

	mk_lib_crypto_hash_block_blake2s_base_g(v, block, 0, 4,  8, 12, mk_lib_crypto_hash_block_blake2s_base_k_sigma[i][ 0], mk_lib_crypto_hash_block_blake2s_base_k_sigma[i][ 1]);
	mk_lib_crypto_hash_block_blake2s_base_g(v, block, 1, 5,  9, 13, mk_lib_crypto_hash_block_blake2s_base_k_sigma[i][ 2], mk_lib_crypto_hash_block_blake2s_base_k_sigma[i][ 3]);
	mk_lib_crypto_hash_block_blake2s_base_g(v, block, 2, 6, 10, 14, mk_lib_crypto_hash_block_blake2s_base_k_sigma[i][ 4], mk_lib_crypto_hash_block_blake2s_base_k_sigma[i][ 5]);
	mk_lib_crypto_hash_block_blake2s_base_g(v, block, 3, 7, 11, 15, mk_lib_crypto_hash_block_blake2s_base_k_sigma[i][ 6], mk_lib_crypto_hash_block_blake2s_base_k_sigma[i][ 7]);
	mk_lib_crypto_hash_block_blake2s_base_g(v, block, 0, 5, 10, 15, mk_lib_crypto_hash_block_blake2s_base_k_sigma[i][ 8], mk_lib_crypto_hash_block_blake2s_base_k_sigma[i][ 9]);
	mk_lib_crypto_hash_block_blake2s_base_g(v, block, 1, 6, 11, 12, mk_lib_crypto_hash_block_blake2s_base_k_sigma[i][10], mk_lib_crypto_hash_block_blake2s_base_k_sigma[i][11]);
	mk_lib_crypto_hash_block_blake2s_base_g(v, block, 2, 7,  8, 13, mk_lib_crypto_hash_block_blake2s_base_k_sigma[i][12], mk_lib_crypto_hash_block_blake2s_base_k_sigma[i][13]);
	mk_lib_crypto_hash_block_blake2s_base_g(v, block, 3, 4,  9, 14, mk_lib_crypto_hash_block_blake2s_base_k_sigma[i][14], mk_lib_crypto_hash_block_blake2s_base_k_sigma[i][15]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake2s_base_compress(mk_lib_crypto_hash_block_blake2s_base_pt const blake2s_base, mk_lib_crypto_hash_block_blake2s_base_block_pct const block, mk_lang_types_bool_t const last_block, mk_lang_types_bool_t const last_node) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_blake2s_base_v_t v mk_lang_constexpr_init;
	mk_sl_cui_uint32_t len[2] mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;

	mk_lang_assert(blake2s_base);
	mk_lang_assert(block);
	mk_lang_assert(last_block == mk_lang_false || last_block == mk_lang_true);
	mk_lang_assert(last_node == mk_lang_false || last_node == mk_lang_true);

	mk_sl_uint_convert_64_32_le_to_sml(&blake2s_base->m_len, &len[0]);
	mk_sl_cui_uint32_set_zero(&ta);
	mk_sl_cui_uint32_set_zero(&tb);
	if(last_block) mk_sl_cui_uint32_not1(&ta);
	if(last_node) mk_sl_cui_uint32_not1(&tb);
	mk_lib_crypto_bitops_bulk_uint32_8_memcpy(&v.m_data.m_uint32s[0], &blake2s_base->m_state[0]);
	v.m_data.m_uint32s[8] = mk_lib_crypto_hash_block_blake2s_base_k_init.m_data.m_uint32s[0];
	v.m_data.m_uint32s[9] = mk_lib_crypto_hash_block_blake2s_base_k_init.m_data.m_uint32s[1];
	v.m_data.m_uint32s[10] = mk_lib_crypto_hash_block_blake2s_base_k_init.m_data.m_uint32s[2];
	v.m_data.m_uint32s[11] = mk_lib_crypto_hash_block_blake2s_base_k_init.m_data.m_uint32s[3];
	mk_sl_cui_uint32_xor3(&mk_lib_crypto_hash_block_blake2s_base_k_init.m_data.m_uint32s[4], &len[0], &v.m_data.m_uint32s[12]);
	mk_sl_cui_uint32_xor3(&mk_lib_crypto_hash_block_blake2s_base_k_init.m_data.m_uint32s[5], &len[1], &v.m_data.m_uint32s[13]);
	mk_sl_cui_uint32_xor3(&mk_lib_crypto_hash_block_blake2s_base_k_init.m_data.m_uint32s[6], &ta, &v.m_data.m_uint32s[14]);
	mk_sl_cui_uint32_xor3(&mk_lib_crypto_hash_block_blake2s_base_k_init.m_data.m_uint32s[7], &tb, &v.m_data.m_uint32s[15]);
	for(i = 0; i != 10; ++i)
	{
		mk_lib_crypto_hash_block_blake2s_base_round(&v, block, i);
	}
	for(i = 0; i != 8; ++i)
	{
		mk_sl_cui_uint32_xor3(&v.m_data.m_uint32s[i + 0 * 8], &v.m_data.m_uint32s[i + 1 * 8], &ta);
		mk_sl_cui_uint32_xor2(&blake2s_base->m_state[i], &ta);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake2s_base_init_parameter_block(mk_lib_crypto_hash_block_blake2s_base_pt const blake2s_base, mk_lang_types_sint_t const digest_len, mk_lang_types_sint_t const key_len, mk_lang_types_sint_t const fanout, mk_lang_types_sint_t const max_depth, mk_lang_types_ulong_t const leaf_len, mk_lang_types_ulong_t const node_offset, mk_lang_types_ulong_t const xof_len, mk_lang_types_sint_t const node_depth, mk_lang_types_sint_t const inner_len, mk_lang_types_uchar_pct const salt_buf, mk_lang_types_sint_t const salt_len, mk_lang_types_uchar_pct const personalization_buf, mk_lang_types_sint_t const personalization_len) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_blake2s_base_state2_t state mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(blake2s_base);
	mk_lang_assert(digest_len >= 1 && digest_len <= mk_lib_crypto_hash_block_blake2s_base_digest_len_v);
	mk_lang_assert(key_len >= 0 && key_len <= mk_lib_crypto_hash_block_blake2s_base_max_key_len_v);
	mk_lang_assert(fanout >= 0 && fanout <= 0xff);
	mk_lang_assert(max_depth >= 1 && max_depth <= 0xff);
	mk_lang_assert(leaf_len >= 0 && leaf_len <= 0xfffffffful);
	mk_lang_assert(node_offset >= 0 && node_offset <= 0xfffffffful);
	mk_lang_assert(xof_len >= 0 && xof_len <= 0x0000fffful);
	mk_lang_assert(node_depth >= 0 && node_depth <= 0xff);
	mk_lang_assert(inner_len >= 0 && inner_len <= mk_lib_crypto_hash_block_blake2s_base_digest_len_v);
	mk_lang_assert(salt_buf || salt_len == 0);
	mk_lang_assert(salt_len >= 0 && salt_len <= mk_lib_crypto_hash_block_blake2s_base_max_salt_len_v);
	mk_lang_assert(personalization_buf || personalization_len == 0);
	mk_lang_assert(personalization_len >= 0 && personalization_len <= mk_lib_crypto_hash_block_blake2s_base_max_personalization_len_v);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_cui_uint8_from_bi_sint(&state.m_data.m_uint8s[0], &digest_len);
	mk_sl_cui_uint8_from_bi_sint(&state.m_data.m_uint8s[1], &key_len);
	mk_sl_cui_uint8_from_bi_sint(&state.m_data.m_uint8s[2], &fanout);
	mk_sl_cui_uint8_from_bi_sint(&state.m_data.m_uint8s[3], &max_depth);
	mk_sl_cui_uint32_from_bi_ulong(&ta, &leaf_len); mk_sl_uint_convert_32_8_le_to_sml(&ta, &state.m_data.m_uint8s[4]);
	mk_sl_cui_uint32_from_bi_ulong(&ta, &node_offset); mk_sl_uint_convert_32_8_le_to_sml(&ta, &state.m_data.m_uint8s[8]);
	mk_sl_cui_uint32_from_bi_ulong(&ta, &xof_len); mk_sl_uint_convert_32_8_le_to_sml(&ta, &state.m_data.m_uint8s[12]);
	mk_sl_cui_uint8_from_bi_sint(&state.m_data.m_uint8s[14], &node_depth);
	mk_sl_cui_uint8_from_bi_sint(&state.m_data.m_uint8s[15], &inner_len);
	for(i = 0; i != salt_len; ++i){ mk_sl_cui_uint8_from_bi_uchar(&state.m_data.m_uint8s[16 + i], &salt_buf[i]); }
	for(i = salt_len; i != mk_lib_crypto_hash_block_blake2s_base_max_salt_len_v; ++i){ mk_sl_cui_uint8_set_zero(&state.m_data.m_uint8s[16 + i]); }
	for(i = 0; i != personalization_len; ++i){ mk_sl_cui_uint8_from_bi_uchar(&state.m_data.m_uint8s[24 + i], &personalization_buf[i]); }
	for(i = personalization_len; i != mk_lib_crypto_hash_block_blake2s_base_max_personalization_len_v; ++i){ mk_sl_cui_uint8_set_zero(&state.m_data.m_uint8s[24 + i]); }
	for(i = 0; i != 8; ++i){ mk_sl_uint_convert_32_8_le_to_big(&tb, &state.m_data.m_uint8s[i * mk_sl_cui_uint32_size_bytes_v]); mk_sl_cui_uint32_xor2(&blake2s_base->m_state[i], &tb); }
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_blake2s_base_init(mk_lib_crypto_hash_block_blake2s_base_pt const blake2s_base, mk_lang_types_sint_t const digest_len, mk_lang_types_sint_t const key_len, mk_lang_types_sint_t const fanout, mk_lang_types_sint_t const max_depth, mk_lang_types_ulong_t const leaf_len, mk_lang_types_ulong_t const node_offset, mk_lang_types_ulong_t const xof_len, mk_lang_types_sint_t const node_depth, mk_lang_types_sint_t const inner_len, mk_lang_types_uchar_pct const salt_buf, mk_lang_types_sint_t const salt_len, mk_lang_types_uchar_pct const personalization_buf, mk_lang_types_sint_t const personalization_len) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_blake2s_base_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_blake2s_base_digest_t) == 32);

	mk_lang_assert(blake2s_base);

	mk_lib_crypto_bitops_bulk_uint32_8_memcpy(&blake2s_base->m_state[0], &mk_lib_crypto_hash_block_blake2s_base_k_init.m_data.m_uint32s[0]);
	mk_sl_cui_uint64_set_zero(&blake2s_base->m_len);
	mk_lib_crypto_hash_block_blake2s_base_init_parameter_block(blake2s_base, digest_len, key_len, fanout, max_depth, leaf_len, node_offset, xof_len, node_depth, inner_len, salt_buf, salt_len, personalization_buf, personalization_len);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_blake2s_base_append_blocks(mk_lib_crypto_hash_block_blake2s_base_pt const blake2s_base, mk_lib_crypto_hash_block_blake2s_base_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(blake2s_base);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_blake2s_base_block_len_v);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		tsi = mk_lib_crypto_hash_block_blake2s_base_block_len_v; mk_sl_cui_uint64_from_bi_sint(&ta, &tsi);
		mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&blake2s_base->m_len, &ta));
		mk_sl_cui_uint64_add2_wrap_cid_cod(&blake2s_base->m_len, &ta);
		mk_lib_crypto_hash_block_blake2s_base_compress(blake2s_base, &pblocks[iblock], mk_lang_false, mk_lang_false);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_blake2s_base_finish(mk_lib_crypto_hash_block_blake2s_base_pt const blake2s_base, mk_lib_crypto_hash_block_blake2s_base_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_blake2s_base_digest_pt const digest) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(blake2s_base);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx <= mk_lib_crypto_hash_block_blake2s_base_block_len_v);
	mk_lang_assert(digest);

	mk_sl_cui_uint64_from_bi_sint(&ta, &idx);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&blake2s_base->m_len, &ta));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&blake2s_base->m_len, &ta);
	mk_sl_cui_uint8_memclr_fn(&block->m_data.m_uint8s[idx], ((mk_lang_types_usize_t)(mk_lib_crypto_hash_block_blake2s_base_block_len_v - idx)));
	mk_lib_crypto_hash_block_blake2s_base_compress(blake2s_base, block, mk_lang_true, mk_lang_false);
	for(i = 0; i != mk_lang_countof(blake2s_base->m_state); ++i)
	{
		mk_sl_uint_convert_32_8_le_to_sml(&blake2s_base->m_state[i], &digest->m_data.m_uint8s[i * mk_sl_cui_uint32_size_bytes_v]);
	}
}


#endif
