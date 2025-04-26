#ifndef mk_include_guard_mk_lib_crypto_hash_block_blake3_base_c
#define mk_include_guard_mk_lib_crypto_hash_block_blake3_base_c
#include "mk_lib_crypto_hash_block_blake3_base.h"

#include "mk_lang_alignas.h"
#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_pow2.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_bitops_bulk.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"


#define mk_lib_crypto_hash_block_blake3_base_half_len_d 32
#define mk_lib_crypto_hash_block_blake3_base_output_block_log2 6
#define mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk (mk_lib_crypto_hash_block_blake3_base_chunk_len / mk_lib_crypto_hash_block_blake3_base_block_len_d)

#define mk_lib_crypto_hash_block_blake3_base_flags_none   0
#define mk_lib_crypto_hash_block_blake3_base_flags_start  1
#define mk_lib_crypto_hash_block_blake3_base_flags_end    2
#define mk_lib_crypto_hash_block_blake3_base_flags_parent 4
#define mk_lib_crypto_hash_block_blake3_base_flags_root   8
enum mk_lib_crypto_hash_block_blake3_base_flags_e
{
	mk_lib_crypto_hash_block_blake3_base_flags_e_none   = mk_lib_crypto_hash_block_blake3_base_flags_none  ,
	mk_lib_crypto_hash_block_blake3_base_flags_e_start  = mk_lib_crypto_hash_block_blake3_base_flags_start ,
	mk_lib_crypto_hash_block_blake3_base_flags_e_end    = mk_lib_crypto_hash_block_blake3_base_flags_end   ,
	mk_lib_crypto_hash_block_blake3_base_flags_e_parent = mk_lib_crypto_hash_block_blake3_base_flags_parent,
	mk_lib_crypto_hash_block_blake3_base_flags_e_root   = mk_lib_crypto_hash_block_blake3_base_flags_root  ,
	mk_lib_crypto_hash_block_blake3_base_flags_e_dummy_end
};
typedef enum mk_lib_crypto_hash_block_blake3_base_flags_e mk_lib_crypto_hash_block_blake3_base_flags_t;


union mk_lib_crypto_hash_block_blake3_base_block2_data_u
{
	mk_sl_cui_uint32_t m_uint32s[16];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_blake3_base_block2_data_u mk_lib_crypto_hash_block_blake3_base_block2_data_t;
struct mk_lib_crypto_hash_block_blake3_base_block2_s
{
	mk_lang_alignas(sizeof(mk_lib_crypto_hash_block_blake3_base_block2_data_t)) mk_lib_crypto_hash_block_blake3_base_block2_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_blake3_base_block2_s mk_lib_crypto_hash_block_blake3_base_block2_t;
mk_lang_typedef(mk_lib_crypto_hash_block_blake3_base_block2);

#include "mk_lang_warning_msvc_push_c4820.h"
union mk_lib_crypto_hash_block_blake3_base_schedule_data_u
{
	mk_lang_types_uchar_t m_uchars[7][16];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_blake3_base_schedule_data_u mk_lib_crypto_hash_block_blake3_base_schedule_data_t;
struct mk_lib_crypto_hash_block_blake3_base_schedule_s
{
	mk_lang_alignas(mk_lang_pow2_roundup(sizeof(mk_lib_crypto_hash_block_blake3_base_schedule_data_t))) mk_lib_crypto_hash_block_blake3_base_schedule_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_blake3_base_schedule_s mk_lib_crypto_hash_block_blake3_base_schedule_t;
#include "mk_lang_warning_msvc_pop.h"


mk_lang_constexpr_static_inline mk_lib_crypto_hash_block_blake3_base_state_t const mk_lib_crypto_hash_block_blake3_base_k_init =
{{{
	mk_sl_cui_uint32_c(0x6a09e667),
	mk_sl_cui_uint32_c(0xbb67ae85),
	mk_sl_cui_uint32_c(0x3c6ef372),
	mk_sl_cui_uint32_c(0xa54ff53a),
	mk_sl_cui_uint32_c(0x510e527f),
	mk_sl_cui_uint32_c(0x9b05688c),
	mk_sl_cui_uint32_c(0x1f83d9ab),
	mk_sl_cui_uint32_c(0x5be0cd19),
}}};

mk_lang_constexpr_static_inline mk_lib_crypto_hash_block_blake3_base_schedule_t const mk_lib_crypto_hash_block_blake3_base_k_schedule =
{{{
	{  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15 },
	{  2,  6,  3, 10,  7,  0,  4, 13,  1, 11, 12,  5,  9, 14, 15,  8 },
	{  3,  4, 10, 12, 13,  2,  7, 14,  6,  5,  9,  0, 11, 15,  8,  1 },
	{ 10,  7, 12,  9, 14,  3, 13, 15,  4,  0, 11,  2,  5,  8,  1,  6 },
	{ 12, 13,  9, 11, 15, 10, 14,  8,  7,  2,  5,  3,  0,  1,  6,  4 },
	{  9, 14, 11,  5,  8, 12, 15,  1, 13,  3,  0, 10,  2,  6,  4,  7 },
	{ 11, 15,  5,  0,  1,  9,  8,  6, 14, 10,  2, 12,  3,  4,  7, 13 },
}}};


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_g(mk_lib_crypto_hash_block_blake3_base_block2_pt const v, mk_lib_crypto_hash_block_blake3_base_block_pct const block, mk_lang_types_sint_t const a, mk_lang_types_sint_t const b, mk_lang_types_sint_t const c, mk_lang_types_sint_t const d, mk_lang_types_sint_t const xi, mk_lang_types_sint_t const yi) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;

	mk_lang_assert(v);
	mk_lang_assert(block);
	mk_lang_assert(a >= 0 && a < 16);
	mk_lang_assert(b >= 0 && b < 16);
	mk_lang_assert(c >= 0 && c < 16);
	mk_lang_assert(d >= 0 && d < 16);
	mk_lang_assert(xi >= 0 && xi < 16);
	mk_lang_assert(yi >= 0 && yi < 16);

	mk_sl_uint_convert_32_8_le_to_big(&ta, &block->m_data.m_uint8s[xi * mk_sl_cui_uint32_size_bytes_v]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &v->m_data.m_uint32s[b]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&v->m_data.m_uint32s[a], &ta);
	mk_sl_cui_uint32_xor2(&v->m_data.m_uint32s[d], &v->m_data.m_uint32s[a]);
	mk_sl_cui_uint32_rotr2(&v->m_data.m_uint32s[d], 16);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&v->m_data.m_uint32s[c], &v->m_data.m_uint32s[d]);
	mk_sl_cui_uint32_xor2(&v->m_data.m_uint32s[b], &v->m_data.m_uint32s[c]);
	mk_sl_cui_uint32_rotr2(&v->m_data.m_uint32s[b], 12);
	mk_sl_uint_convert_32_8_le_to_big(&ta, &block->m_data.m_uint8s[yi * mk_sl_cui_uint32_size_bytes_v]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &v->m_data.m_uint32s[b]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&v->m_data.m_uint32s[a], &ta);
	mk_sl_cui_uint32_xor2(&v->m_data.m_uint32s[d], &v->m_data.m_uint32s[a]);
	mk_sl_cui_uint32_rotr2(&v->m_data.m_uint32s[d], 8);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&v->m_data.m_uint32s[c], &v->m_data.m_uint32s[d]);
	mk_sl_cui_uint32_xor2(&v->m_data.m_uint32s[b], &v->m_data.m_uint32s[c]);
	mk_sl_cui_uint32_rotr2(&v->m_data.m_uint32s[b], 7);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_round(mk_lib_crypto_hash_block_blake3_base_block2_pt const v, mk_lib_crypto_hash_block_blake3_base_block_pct const block, mk_lang_types_sint_t const ir) mk_lang_noexcept
{
	mk_lang_assert(v);
	mk_lang_assert(block);
	mk_lang_assert(ir >= 0 && ir < 7);

	mk_lib_crypto_hash_block_blake3_base_g(v, block, 0, 4,  8, 12, mk_lib_crypto_hash_block_blake3_base_k_schedule.m_data.m_uchars[ir][ 0], mk_lib_crypto_hash_block_blake3_base_k_schedule.m_data.m_uchars[ir][ 1]);
	mk_lib_crypto_hash_block_blake3_base_g(v, block, 1, 5,  9, 13, mk_lib_crypto_hash_block_blake3_base_k_schedule.m_data.m_uchars[ir][ 2], mk_lib_crypto_hash_block_blake3_base_k_schedule.m_data.m_uchars[ir][ 3]);
	mk_lib_crypto_hash_block_blake3_base_g(v, block, 2, 6, 10, 14, mk_lib_crypto_hash_block_blake3_base_k_schedule.m_data.m_uchars[ir][ 4], mk_lib_crypto_hash_block_blake3_base_k_schedule.m_data.m_uchars[ir][ 5]);
	mk_lib_crypto_hash_block_blake3_base_g(v, block, 3, 7, 11, 15, mk_lib_crypto_hash_block_blake3_base_k_schedule.m_data.m_uchars[ir][ 6], mk_lib_crypto_hash_block_blake3_base_k_schedule.m_data.m_uchars[ir][ 7]);
	mk_lib_crypto_hash_block_blake3_base_g(v, block, 0, 5, 10, 15, mk_lib_crypto_hash_block_blake3_base_k_schedule.m_data.m_uchars[ir][ 8], mk_lib_crypto_hash_block_blake3_base_k_schedule.m_data.m_uchars[ir][ 9]);
	mk_lib_crypto_hash_block_blake3_base_g(v, block, 1, 6, 11, 12, mk_lib_crypto_hash_block_blake3_base_k_schedule.m_data.m_uchars[ir][10], mk_lib_crypto_hash_block_blake3_base_k_schedule.m_data.m_uchars[ir][11]);
	mk_lib_crypto_hash_block_blake3_base_g(v, block, 2, 7,  8, 13, mk_lib_crypto_hash_block_blake3_base_k_schedule.m_data.m_uchars[ir][12], mk_lib_crypto_hash_block_blake3_base_k_schedule.m_data.m_uchars[ir][13]);
	mk_lib_crypto_hash_block_blake3_base_g(v, block, 3, 4,  9, 14, mk_lib_crypto_hash_block_blake3_base_k_schedule.m_data.m_uchars[ir][14], mk_lib_crypto_hash_block_blake3_base_k_schedule.m_data.m_uchars[ir][15]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_compress_block(mk_lib_crypto_hash_block_blake3_base_state_pct const state, mk_sl_cui_uint64_pct const chunk_idx, mk_lib_crypto_hash_block_blake3_base_flags_t const flags, mk_lib_crypto_hash_block_blake3_base_block_pct const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_blake3_base_block2_pt const v) mk_lang_noexcept
{
	mk_lang_types_uint_t tui mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(state);
	mk_lang_assert(chunk_idx);
	mk_lang_assert(flags >= 0x00 && flags <= 0x0f);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx <= mk_lib_crypto_hash_block_blake3_base_block_len_v);
	mk_lang_assert(v);

	mk_lib_crypto_bitops_bulk_uint32_8_memcpy(&v->m_data.m_uint32s[0 * 8], &state->m_data.m_uint32s[0]);
	mk_lib_crypto_bitops_bulk_uint32_4_memcpy(&v->m_data.m_uint32s[1 * 8], &mk_lib_crypto_hash_block_blake3_base_k_init.m_data.m_uint32s[0]);
	mk_sl_uint_convert_64_32_le_to_sml(chunk_idx, &v->m_data.m_uint32s[12]);
	mk_sl_cui_uint32_from_bi_sint(&v->m_data.m_uint32s[14], &idx);
	tui = ((mk_lang_types_uint_t)(flags)); mk_sl_cui_uint32_from_bi_uint(&v->m_data.m_uint32s[15], &tui);
	for(i = 0; i != 7; ++i)
	{
		mk_lib_crypto_hash_block_blake3_base_round(v, block, i);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_compress_block_and_mix(mk_lib_crypto_hash_block_blake3_base_state_pt const state, mk_sl_cui_uint64_pct const chunk_idx, mk_lib_crypto_hash_block_blake3_base_flags_t const flags, mk_lib_crypto_hash_block_blake3_base_block_pct const block, mk_lang_types_sint_t const idx) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_blake3_base_block2_t v mk_lang_constexpr_init;

	mk_lang_assert(state);
	mk_lang_assert(chunk_idx);
	mk_lang_assert(flags >= 0x00 && flags <= 0x0f);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx <= mk_lib_crypto_hash_block_blake3_base_block_len_v);

	mk_lib_crypto_hash_block_blake3_base_compress_block(state, chunk_idx, flags, block, idx, &v);
	mk_lib_crypto_bitops_bulk_uint32_8_xor3(&v.m_data.m_uint32s[0 * 8], &v.m_data.m_uint32s[1 * 8], &state->m_data.m_uint32s[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_chunk_compress(mk_sl_cui_uint64_pct const chunk_idx, mk_lib_crypto_hash_block_blake3_base_block_pct const pblocks, mk_lib_crypto_hash_block_blake3_base_state_pt const state) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_blake3_base_flags_t flags mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(chunk_idx);
	mk_lang_assert(pblocks);
	mk_lang_assert(state);

	flags = mk_lib_crypto_hash_block_blake3_base_flags_e_start;
	mk_lib_crypto_hash_block_blake3_base_compress_block_and_mix(state, chunk_idx, flags, &pblocks[0], mk_lib_crypto_hash_block_blake3_base_block_len_v);
	flags = mk_lib_crypto_hash_block_blake3_base_flags_e_none;
	for(i = 1; i != mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk - 1; ++i)
	{
		mk_lib_crypto_hash_block_blake3_base_compress_block_and_mix(state, chunk_idx, flags, &pblocks[i], mk_lib_crypto_hash_block_blake3_base_block_len_v);
	}
	flags = mk_lib_crypto_hash_block_blake3_base_flags_e_end;
	mk_lib_crypto_hash_block_blake3_base_compress_block_and_mix(state, chunk_idx, flags, &pblocks[mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk - 1], mk_lib_crypto_hash_block_blake3_base_block_len_v);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_merge(mk_lib_crypto_hash_block_blake3_base_pt const blake3_base) mk_lang_noexcept
{
	mk_sl_cui_uint64_t chunk_idx mk_lang_constexpr_init;
	mk_lang_types_sint_t chunk_count_ones mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_blake3_base_state_t state mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_blake3_base_flags_t flags mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_blake3_base_state_pct a mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_blake3_base_state_pct b mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_blake3_base_block_t block mk_lang_constexpr_init;

	mk_lang_assert(blake3_base);

	mk_sl_cui_uint64_set_zero(&chunk_idx);
	chunk_count_ones = mk_sl_cui_uint64_count_ones(&blake3_base->m_chunk_count);
	while(blake3_base->m_state_count > chunk_count_ones)
	{
		state = mk_lib_crypto_hash_block_blake3_base_k_init;
		flags = mk_lib_crypto_hash_block_blake3_base_flags_e_parent;
		a = &blake3_base->m_states.m_data.m_states[blake3_base->m_state_count - 2];
		b = &blake3_base->m_states.m_data.m_states[blake3_base->m_state_count - 1];
		mk_sl_uint_convert_32_8_le_to_sml_multi(&a->m_data.m_uint32s[0], &block.m_data.m_uint8s[0 * mk_lib_crypto_hash_block_blake3_base_half_len_d], mk_lang_countof(a->m_data.m_uint32s));
		mk_sl_uint_convert_32_8_le_to_sml_multi(&b->m_data.m_uint32s[0], &block.m_data.m_uint8s[1 * mk_lib_crypto_hash_block_blake3_base_half_len_d], mk_lang_countof(b->m_data.m_uint32s));
		mk_lib_crypto_hash_block_blake3_base_compress_block_and_mix(&state, &chunk_idx, flags, &block, mk_lib_crypto_hash_block_blake3_base_block_len_v);
		blake3_base->m_states.m_data.m_states[blake3_base->m_state_count - 2] = state;
		--blake3_base->m_state_count;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_chunk_finished(mk_lib_crypto_hash_block_blake3_base_pt const blake3_base, mk_lib_crypto_hash_block_blake3_base_state_pct const state) mk_lang_noexcept
{
	mk_lang_assert(blake3_base);
	mk_lang_assert(state);

	blake3_base->m_states.m_data.m_states[blake3_base->m_state_count] = *state;
	++blake3_base->m_state_count;
	mk_sl_cui_uint64_inc1(&blake3_base->m_chunk_count);
	mk_lib_crypto_hash_block_blake3_base_merge(blake3_base);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_init(mk_lib_crypto_hash_block_blake3_base_pt const blake3_base) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_blake3_base_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_blake3_base_digest_t) == 64);
	mk_lang_static_assert(mk_lib_crypto_hash_block_blake3_base_chunk_len > mk_lib_crypto_hash_block_blake3_base_block_len_d);
	mk_lang_static_assert(mk_lib_crypto_hash_block_blake3_base_chunk_len % mk_lib_crypto_hash_block_blake3_base_block_len_d == 0);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_blake3_base_block_t) == sizeof(mk_lib_crypto_hash_block_blake3_base_block2_t));
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_hash_block_blake3_base_block_t) == mk_lang_alignof(mk_lib_crypto_hash_block_blake3_base_block2_t));

	mk_lang_assert(blake3_base);

	blake3_base->m_state = mk_lib_crypto_hash_block_blake3_base_k_init;
	mk_sl_cui_uint64_set_zero(&blake3_base->m_chunk_count);
	blake3_base->m_block_count = 0;
	blake3_base->m_state_count = 0;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_append_blocks(mk_lib_crypto_hash_block_blake3_base_pt const blake3_base, mk_lib_crypto_hash_block_blake3_base_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_blake3_base_block_pct ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t free mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_blake3_base_flags_t flags mk_lang_constexpr_init;
	mk_lang_types_usize_t nchunks mk_lang_constexpr_init;
	mk_lang_types_usize_t ichunk mk_lang_constexpr_init;
	mk_lang_types_bool_t first mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(blake3_base);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_blake3_base_block_len_v);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	ptr = pblocks;
	rem = nblocks;
	free = mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk - blake3_base->m_block_count;
	if(rem >= ((mk_lang_types_usize_t)(free)))
	{
		if(blake3_base->m_block_count != 0)
		{
			for(i = 0; i != free; ++i)
			{
				flags = blake3_base->m_block_count + i == mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk - 1 ? mk_lib_crypto_hash_block_blake3_base_flags_e_end : mk_lib_crypto_hash_block_blake3_base_flags_e_none;
				mk_lib_crypto_hash_block_blake3_base_compress_block_and_mix(&blake3_base->m_state, &blake3_base->m_chunk_count, flags, &ptr[i], mk_lib_crypto_hash_block_blake3_base_block_len_v);
			}
			mk_lib_crypto_hash_block_blake3_base_chunk_finished(blake3_base, &blake3_base->m_state);
			blake3_base->m_state = mk_lib_crypto_hash_block_blake3_base_k_init;
			blake3_base->m_block_count = 0;
			ptr += ((mk_lang_types_usize_t)(free));
			rem -= ((mk_lang_types_usize_t)(free));
		}
		nchunks = rem / mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk;
		for(ichunk = 0; ichunk != nchunks; ++ichunk)
		{
			mk_lib_crypto_hash_block_blake3_base_chunk_compress(&blake3_base->m_chunk_count, &pblocks[ichunk * mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk], &blake3_base->m_state);
			mk_lib_crypto_hash_block_blake3_base_chunk_finished(blake3_base, &blake3_base->m_state);
			blake3_base->m_state = mk_lib_crypto_hash_block_blake3_base_k_init;
		}
		ptr += nchunks * mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk;
		rem -= nchunks * mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk;
	}
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(rem >= 0 && rem < mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"
	mk_lang_assert(((mk_lang_types_sint_t)(rem)) + blake3_base->m_block_count >= 0 && ((mk_lang_types_sint_t)(rem)) + blake3_base->m_block_count < mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk);
	first = blake3_base->m_block_count == 0;
	for(i = 0; i != ((mk_lang_types_sint_t)(rem)); ++i)
	{
		flags = mk_lib_crypto_hash_block_blake3_base_flags_e_none;
		flags = ((mk_lib_crypto_hash_block_blake3_base_flags_t)(flags | (first && i == 0 ? mk_lib_crypto_hash_block_blake3_base_flags_e_start : mk_lib_crypto_hash_block_blake3_base_flags_e_none)));
		mk_lib_crypto_hash_block_blake3_base_compress_block_and_mix(&blake3_base->m_state, &blake3_base->m_chunk_count, flags, &ptr[i], mk_lib_crypto_hash_block_blake3_base_block_len_v);
	}
	blake3_base->m_block_count += ((mk_lang_types_uchar_t)(((mk_lang_types_sint_t)(rem))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_finish(mk_lib_crypto_hash_block_blake3_base_pt const blake3_base, mk_lib_crypto_hash_block_blake3_base_block_pt const block, mk_lang_types_sint_t const idx) mk_lang_noexcept
{
	mk_sl_cui_uint64_t seek mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_blake3_base_flags_t flags mk_lang_constexpr_init;
	mk_lang_types_sint_t idxb mk_lang_constexpr_init;

	mk_lang_assert(blake3_base);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx <= mk_lib_crypto_hash_block_blake3_base_block_len_v);

	mk_sl_cui_uint64_set_zero(&seek);
	mk_sl_cui_uint8_memclr_fn(&block->m_data.m_uint8s[idx], ((mk_lang_types_usize_t)(mk_lib_crypto_hash_block_blake3_base_block_len_v - idx)));
	if(blake3_base->m_state_count != 0)
	{
		--blake3_base->m_state_count;
		flags = mk_lib_crypto_hash_block_blake3_base_flags_e_none;
		flags = ((mk_lib_crypto_hash_block_blake3_base_flags_t)(flags | (blake3_base->m_block_count == 0 ? mk_lib_crypto_hash_block_blake3_base_flags_e_start : mk_lib_crypto_hash_block_blake3_base_flags_e_none)));
		flags = ((mk_lib_crypto_hash_block_blake3_base_flags_t)(flags | mk_lib_crypto_hash_block_blake3_base_flags_e_end));
		mk_lib_crypto_hash_block_blake3_base_compress_block_and_mix(&blake3_base->m_state, &blake3_base->m_chunk_count, flags, block, idx);
		mk_sl_uint_convert_32_8_le_to_sml_multi(&blake3_base->m_state.m_data.m_uint32s[0],                                              &block->m_data.m_uint8s[1 * mk_lib_crypto_hash_block_blake3_base_half_len_d], mk_lang_countof(blake3_base->m_state.m_data.m_uint32s));
		mk_sl_uint_convert_32_8_le_to_sml_multi(&blake3_base->m_states.m_data.m_states[blake3_base->m_state_count].m_data.m_uint32s[0], &block->m_data.m_uint8s[0 * mk_lib_crypto_hash_block_blake3_base_half_len_d], mk_lang_countof(blake3_base->m_states.m_data.m_states[blake3_base->m_state_count].m_data.m_uint32s));
		while(blake3_base->m_state_count != 0)
		{
			--blake3_base->m_state_count;
			blake3_base->m_state = mk_lib_crypto_hash_block_blake3_base_k_init;
			flags = mk_lib_crypto_hash_block_blake3_base_flags_e_parent;
			mk_lib_crypto_hash_block_blake3_base_compress_block_and_mix(&blake3_base->m_state, &seek, flags, block, mk_lib_crypto_hash_block_blake3_base_block_len_v);
			mk_sl_uint_convert_32_8_le_to_sml_multi(&blake3_base->m_state.m_data.m_uint32s[0],                                              &block->m_data.m_uint8s[1 * mk_lib_crypto_hash_block_blake3_base_half_len_d], mk_lang_countof(blake3_base->m_state.m_data.m_uint32s));
			mk_sl_uint_convert_32_8_le_to_sml_multi(&blake3_base->m_states.m_data.m_states[blake3_base->m_state_count].m_data.m_uint32s[0], &block->m_data.m_uint8s[0 * mk_lib_crypto_hash_block_blake3_base_half_len_d], mk_lang_countof(blake3_base->m_states.m_data.m_states[blake3_base->m_state_count].m_data.m_uint32s));
		}
		blake3_base->m_state = mk_lib_crypto_hash_block_blake3_base_k_init;
		flags = mk_lib_crypto_hash_block_blake3_base_flags_e_parent;
		idxb = mk_lib_crypto_hash_block_blake3_base_block_len_v;
	}
	else
	{
		flags = mk_lib_crypto_hash_block_blake3_base_flags_e_none;
		flags = ((mk_lib_crypto_hash_block_blake3_base_flags_t)(flags | (blake3_base->m_block_count == 0 ? mk_lib_crypto_hash_block_blake3_base_flags_e_start : mk_lib_crypto_hash_block_blake3_base_flags_e_none)));
		flags = ((mk_lib_crypto_hash_block_blake3_base_flags_t)(flags | mk_lib_crypto_hash_block_blake3_base_flags_e_end));
		idxb = idx;
	}
	flags = ((mk_lib_crypto_hash_block_blake3_base_flags_t)(flags | mk_lib_crypto_hash_block_blake3_base_flags_e_root));
	blake3_base->m_flags = ((mk_lang_types_uchar_t)(flags));
	blake3_base->m_idx = ((mk_lang_types_uchar_t)(idxb));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_squeeze_block(mk_lib_crypto_hash_block_blake3_base_pt const blake3_base, mk_lib_crypto_hash_block_blake3_base_block_pct const block, mk_sl_cui_uint64_pct const seek, mk_lib_crypto_hash_block_blake3_base_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_blake3_base_block2_t v mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_blake3_base_block2_t v2 mk_lang_constexpr_init;

	mk_lang_assert(blake3_base);
	mk_lang_assert(block);
	mk_lang_assert(seek);
	mk_lang_assert(digest);

	mk_lib_crypto_hash_block_blake3_base_compress_block(&blake3_base->m_state, seek, ((mk_lib_crypto_hash_block_blake3_base_flags_t)(blake3_base->m_flags)), block, blake3_base->m_idx, &v);
	mk_lib_crypto_bitops_bulk_uint32_8_xor3(&v.m_data.m_uint32s[0 * 8], &v.m_data.m_uint32s[1 * 8], &v2.m_data.m_uint32s[0 * 8]);
	mk_lib_crypto_bitops_bulk_uint32_8_xor3(&v.m_data.m_uint32s[1 * 8], &blake3_base->m_state.m_data.m_uint32s[0], &v2.m_data.m_uint32s[1 * 8]);
	mk_sl_uint_convert_32_8_le_to_sml_multi(&v2.m_data.m_uint32s[0], &digest->m_data.m_uint8s[0], mk_lang_countof(v2.m_data.m_uint32s));
}


#endif
