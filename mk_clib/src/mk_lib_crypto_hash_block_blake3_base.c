#include "mk_lib_crypto_hash_block_blake3_base.h"

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_pow2.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"

#define mk_lang_memset_t_name mk_lib_crypto_hash_block_blake3_base_memset_u8
#define mk_lang_memset_t_type mk_sl_cui_uint8_t
#include "mk_lang_memset_inl_fileh.h"
#include "mk_lang_memset_inl_filec.h"

#define mk_lang_memcpy_t_name mk_lib_crypto_hash_block_blake3_base_memcpy_u32
#define mk_lang_memcpy_t_type mk_sl_cui_uint32_t
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"


#define mk_lib_crypto_hash_block_blake3_base_output_block_log2 6
#define mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk (mk_lib_crypto_hash_block_blake3_base_chunk_len / mk_lib_crypto_hash_block_blake3_base_block_len)


#define mk_lib_crypto_hash_block_blake3_base_flags_none   0u
#define mk_lib_crypto_hash_block_blake3_base_flags_start  1u
#define mk_lib_crypto_hash_block_blake3_base_flags_end    2u
#define mk_lib_crypto_hash_block_blake3_base_flags_parent 4u
#define mk_lib_crypto_hash_block_blake3_base_flags_root   8u
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


union mk_lib_crypto_hash_block_blake3_base_v_u
{
	mk_lang_alignas(64) mk_sl_cui_uint32_t m_uint32s[16];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_blake3_base_v_u mk_lib_crypto_hash_block_blake3_base_v_t;
typedef mk_lib_crypto_hash_block_blake3_base_v_t const mk_lib_crypto_hash_block_blake3_base_v_ct;
typedef mk_lib_crypto_hash_block_blake3_base_v_t* mk_lib_crypto_hash_block_blake3_base_v_pt;
typedef mk_lib_crypto_hash_block_blake3_base_v_t const* mk_lib_crypto_hash_block_blake3_base_v_pct;

union mk_lib_crypto_hash_block_blake3_base_schedule_data_u
{
	mk_lang_alignas(mk_lang_pow2_roundup(7 * 16)) mk_lang_types_uchar_t m_uchars[7][16];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_blake3_base_schedule_data_u mk_lib_crypto_hash_block_blake3_base_schedule_data_t;

union mk_lib_crypto_hash_block_blake3_base_schedule_u
{
	mk_lib_crypto_hash_block_blake3_base_schedule_data_t m_data;
};
typedef union mk_lib_crypto_hash_block_blake3_base_schedule_u mk_lib_crypto_hash_block_blake3_base_schedule_t;
typedef mk_lib_crypto_hash_block_blake3_base_schedule_t const mk_lib_crypto_hash_block_blake3_base_schedule_ct;
typedef mk_lib_crypto_hash_block_blake3_base_schedule_t* mk_lib_crypto_hash_block_blake3_base_schedule_pt;
typedef mk_lib_crypto_hash_block_blake3_base_schedule_t const* mk_lib_crypto_hash_block_blake3_base_schedule_pct;


mk_lang_constexpr_static_inline mk_lib_crypto_hash_block_blake3_base_state_t const s_mk_lib_crypto_hash_block_blake3_base_init =
{{
	mk_sl_cui_uint32_c(0x6a09e667),
	mk_sl_cui_uint32_c(0xbb67ae85),
	mk_sl_cui_uint32_c(0x3c6ef372),
	mk_sl_cui_uint32_c(0xa54ff53a),
	mk_sl_cui_uint32_c(0x510e527f),
	mk_sl_cui_uint32_c(0x9b05688c),
	mk_sl_cui_uint32_c(0x1f83d9ab),
	mk_sl_cui_uint32_c(0x5be0cd19),
}};

mk_lang_constexpr_static_inline mk_lib_crypto_hash_block_blake3_base_schedule_t const s_mk_lib_crypto_hash_block_blake3_base_schedule =
{{{
	{  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15 },
	{  2,  6,  3, 10,  7,  0,  4, 13,  1, 11, 12,  5,  9, 14, 15,  8 },
	{  3,  4, 10, 12, 13,  2,  7, 14,  6,  5,  9,  0, 11, 15,  8,  1 },
	{ 10,  7, 12,  9, 14,  3, 13, 15,  4,  0, 11,  2,  5,  8,  1,  6 },
	{ 12, 13,  9, 11, 15, 10, 14,  8,  7,  2,  5,  3,  0,  1,  6,  4 },
	{  9, 14, 11,  5,  8, 12, 15,  1, 13,  3,  0, 10,  2,  6,  4,  7 },
	{ 11, 15,  5,  0,  1,  9,  8,  6, 14, 10,  2, 12,  3,  4,  7, 13 },
}}};


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_g(mk_lib_crypto_hash_block_blake3_base_v_pt const v, mk_lib_crypto_hash_block_blake3_base_block_pct const block, mk_lang_types_sint_t const a, mk_lang_types_sint_t const b, mk_lang_types_sint_t const c, mk_lang_types_sint_t const d, mk_lang_types_sint_t const xi, mk_lang_types_sint_t const yi) mk_lang_noexcept
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

	mk_sl_uint_32_from_8_le(&ta, &block->m_uint8s[xi * 4]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &v->m_uint32s[b]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&v->m_uint32s[a], &ta);
	mk_sl_cui_uint32_xor2(&v->m_uint32s[d], &v->m_uint32s[a]);
	mk_sl_cui_uint32_rotr2(&v->m_uint32s[d], 16);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&v->m_uint32s[c], &v->m_uint32s[d]);
	mk_sl_cui_uint32_xor2(&v->m_uint32s[b], &v->m_uint32s[c]);
	mk_sl_cui_uint32_rotr2(&v->m_uint32s[b], 12);
	mk_sl_uint_32_from_8_le(&ta, &block->m_uint8s[yi * 4]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &v->m_uint32s[b]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&v->m_uint32s[a], &ta);
	mk_sl_cui_uint32_xor2(&v->m_uint32s[d], &v->m_uint32s[a]);
	mk_sl_cui_uint32_rotr2(&v->m_uint32s[d], 8);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&v->m_uint32s[c], &v->m_uint32s[d]);
	mk_sl_cui_uint32_xor2(&v->m_uint32s[b], &v->m_uint32s[c]);
	mk_sl_cui_uint32_rotr2(&v->m_uint32s[b], 7);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_round(mk_lib_crypto_hash_block_blake3_base_v_pt const v, mk_lib_crypto_hash_block_blake3_base_block_pct const block, mk_lang_types_sint_t const ir) mk_lang_noexcept
{
	#define schedule s_mk_lib_crypto_hash_block_blake3_base_schedule

	mk_lang_assert(v);
	mk_lang_assert(block);
	mk_lang_assert(ir >= 0 && ir < 7);

	mk_lib_crypto_hash_block_blake3_base_g(v, block, 0, 4,  8, 12, schedule.m_data.m_uchars[ir][ 0], schedule.m_data.m_uchars[ir][ 1]);
	mk_lib_crypto_hash_block_blake3_base_g(v, block, 1, 5,  9, 13, schedule.m_data.m_uchars[ir][ 2], schedule.m_data.m_uchars[ir][ 3]);
	mk_lib_crypto_hash_block_blake3_base_g(v, block, 2, 6, 10, 14, schedule.m_data.m_uchars[ir][ 4], schedule.m_data.m_uchars[ir][ 5]);
	mk_lib_crypto_hash_block_blake3_base_g(v, block, 3, 7, 11, 15, schedule.m_data.m_uchars[ir][ 6], schedule.m_data.m_uchars[ir][ 7]);
	mk_lib_crypto_hash_block_blake3_base_g(v, block, 0, 5, 10, 15, schedule.m_data.m_uchars[ir][ 8], schedule.m_data.m_uchars[ir][ 9]);
	mk_lib_crypto_hash_block_blake3_base_g(v, block, 1, 6, 11, 12, schedule.m_data.m_uchars[ir][10], schedule.m_data.m_uchars[ir][11]);
	mk_lib_crypto_hash_block_blake3_base_g(v, block, 2, 7,  8, 13, schedule.m_data.m_uchars[ir][12], schedule.m_data.m_uchars[ir][13]);
	mk_lib_crypto_hash_block_blake3_base_g(v, block, 3, 4,  9, 14, schedule.m_data.m_uchars[ir][14], schedule.m_data.m_uchars[ir][15]);

	#undef schedule
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_compress_block(mk_lib_crypto_hash_block_blake3_base_state_pct const state, mk_sl_cui_uint64_pct const chunk_idx, mk_lib_crypto_hash_block_blake3_base_flags_t const flags, mk_lib_crypto_hash_block_blake3_base_block_pct const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_blake3_base_v_pt const v) mk_lang_noexcept
{
	mk_lang_types_uint_t tui mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(state);
	mk_lang_assert(chunk_idx);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx <= mk_lib_crypto_hash_block_blake3_base_block_len);
	mk_lang_assert(v);

	mk_lib_crypto_hash_block_blake3_base_memcpy_u32_fn(&v->m_uint32s[0 * 8], &state->m_uint32s[0], 8);
	mk_lib_crypto_hash_block_blake3_base_memcpy_u32_fn(&v->m_uint32s[1 * 8], &s_mk_lib_crypto_hash_block_blake3_base_init.m_uint32s[0], 4);
	mk_sl_uint_64_to_32_le(chunk_idx, &v->m_uint32s[12]);
	mk_sl_cui_uint32_from_bi_sint(&v->m_uint32s[14], &idx);
	tui = ((mk_lang_types_uint_t)(flags)); mk_sl_cui_uint32_from_bi_uint(&v->m_uint32s[15], &tui);
	for(i = 0; i != 7; ++i)
	{
		mk_lib_crypto_hash_block_blake3_base_round(v, block, i);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_compress_block_and_mix(mk_lib_crypto_hash_block_blake3_base_state_pt const state, mk_sl_cui_uint64_pct const chunk_idx, mk_lib_crypto_hash_block_blake3_base_flags_t const flags, mk_lib_crypto_hash_block_blake3_base_block_pct const block, mk_lang_types_sint_t const idx) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_blake3_base_v_t v mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(state);
	mk_lang_assert(chunk_idx);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx <= mk_lib_crypto_hash_block_blake3_base_block_len);

	mk_lib_crypto_hash_block_blake3_base_compress_block(state, chunk_idx, flags, block, idx, &v);
	for(i = 0; i != 8; ++i)
	{
		mk_sl_cui_uint32_xor3(&v.m_uint32s[0 * 8 + i], &v.m_uint32s[1 * 8 + i], &state->m_uint32s[i]);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_compress_block_and_output(mk_lib_crypto_hash_block_blake3_base_state_pct const state, mk_sl_cui_uint64_pct const chunk_idx, mk_lib_crypto_hash_block_blake3_base_flags_t const flags, mk_lib_crypto_hash_block_blake3_base_block_pct const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_blake3_base_output_block_pt const output_block) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_blake3_base_v_t v mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;

	mk_lang_assert(state);
	mk_lang_assert(chunk_idx);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx <= mk_lib_crypto_hash_block_blake3_base_block_len);
	mk_lang_assert(output_block);

	mk_lib_crypto_hash_block_blake3_base_compress_block(state, chunk_idx, flags, block, idx, &v);
	for(i = 0; i != 8; ++i)
	{
		mk_sl_cui_uint32_xor3(&v.m_uint32s[0 * 8 + i], &v.m_uint32s[1 * 8 + i], &ta); mk_sl_uint_32_to_8_le(&ta, &output_block->m_uint8s[0 * 8 * 4 + i * 4]);
	}
	for(i = 0; i != 8; ++i)
	{
		mk_sl_cui_uint32_xor3(&v.m_uint32s[1 * 8 + i], &state->m_uint32s[i],    &ta); mk_sl_uint_32_to_8_le(&ta, &output_block->m_uint8s[1 * 8 * 4 + i * 4]);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_state_to_uint8s(mk_lib_crypto_hash_block_blake3_base_state_pct const state, mk_sl_cui_uint8_pt const uint8s) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(state);
	mk_lang_assert(uint8s);
	mk_lang_assert(mk_lang_constexpr_is_constant_evaluated_test || ((mk_lang_types_uintptr_t)(uint8s)) % sizeof(mk_sl_cui_uint32_t) == 0);

	for(i = 0; i != 8; ++i)
	{
		mk_sl_uint_32_to_8_le(&state->m_uint32s[i], &uint8s[i * 4]);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_chunk_compress(mk_sl_cui_uint64_pct const chunk_idx, mk_lib_crypto_hash_block_blake3_base_block_pct const pblocks, mk_lib_crypto_hash_block_blake3_base_state_pt const state) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_blake3_base_flags_t flags mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(chunk_idx);
	mk_lang_assert(pblocks);
	mk_lang_assert(state);

	flags = mk_lib_crypto_hash_block_blake3_base_flags_e_start;
	mk_lib_crypto_hash_block_blake3_base_compress_block_and_mix(state, chunk_idx, flags, &pblocks[0], mk_lib_crypto_hash_block_blake3_base_block_len);
	flags = mk_lib_crypto_hash_block_blake3_base_flags_e_none;
	for(i = 1; i != mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk - 1; ++i)
	{
		mk_lib_crypto_hash_block_blake3_base_compress_block_and_mix(state, chunk_idx, flags, &pblocks[i], mk_lib_crypto_hash_block_blake3_base_block_len);
	}
	flags = mk_lib_crypto_hash_block_blake3_base_flags_e_end;
	mk_lib_crypto_hash_block_blake3_base_compress_block_and_mix(state, chunk_idx, flags, &pblocks[mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk - 1], mk_lib_crypto_hash_block_blake3_base_block_len);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_merge(mk_lib_crypto_hash_block_blake3_base_pt const blake3_base) mk_lang_noexcept
{
	mk_sl_cui_uint64_t chunk_idx mk_lang_constexpr_init;
	mk_lang_types_sint_t chunk_count_ones mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_blake3_base_state_t state mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_blake3_base_flags_t flags mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_blake3_base_state_pct a mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_blake3_base_state_pct b mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_blake3_base_block_t block mk_lang_constexpr_init;

	mk_lang_assert(blake3_base);

	mk_sl_cui_uint64_set_zero(&chunk_idx);
	chunk_count_ones = mk_sl_cui_uint64_count_ones(&blake3_base->m_chunk_count);
	while(blake3_base->m_state_count > chunk_count_ones)
	{
		state = s_mk_lib_crypto_hash_block_blake3_base_init;
		flags = mk_lib_crypto_hash_block_blake3_base_flags_e_parent;
		a = &blake3_base->m_states.m_states[blake3_base->m_state_count - 2];
		b = &blake3_base->m_states.m_states[blake3_base->m_state_count - 1];
		for(i = 0; i != 8; ++i)
		{
			mk_sl_uint_32_to_8_le(&a->m_uint32s[i], &block.m_uint8s[0 * mk_lib_crypto_hash_block_blake3_base_digest_len + i * 4]);
		}
		for(i = 0; i != 8; ++i)
		{
			mk_sl_uint_32_to_8_le(&b->m_uint32s[i], &block.m_uint8s[1 * mk_lib_crypto_hash_block_blake3_base_digest_len + i * 4]);
		}
		mk_lib_crypto_hash_block_blake3_base_compress_block_and_mix(&state, &chunk_idx, flags, &block, mk_lib_crypto_hash_block_blake3_base_block_len);
		blake3_base->m_states.m_states[blake3_base->m_state_count - 2] = state;
		--blake3_base->m_state_count;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_chunk_finished(mk_lib_crypto_hash_block_blake3_base_pt const blake3_base, mk_lib_crypto_hash_block_blake3_base_state_pct const state) mk_lang_noexcept
{
	mk_lang_assert(blake3_base);
	mk_lang_assert(state);

	blake3_base->m_states.m_states[blake3_base->m_state_count] = *state;
	++blake3_base->m_state_count;
	mk_sl_cui_uint64_inc1(&blake3_base->m_chunk_count);
	mk_lib_crypto_hash_block_blake3_base_merge(blake3_base);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_init(mk_lib_crypto_hash_block_blake3_base_pt const blake3_base) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 8 / 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 32 / 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 64 / 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_blake3_base_block_t) == mk_lib_crypto_hash_block_blake3_base_block_len);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_blake3_base_digest_t) == mk_lib_crypto_hash_block_blake3_base_digest_len);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_blake3_base_output_block_t) == mk_lib_crypto_hash_block_blake3_base_output_block_len);
	mk_lang_static_assert(mk_lib_crypto_hash_block_blake3_base_chunk_len > mk_lib_crypto_hash_block_blake3_base_block_len);
	mk_lang_static_assert(mk_lib_crypto_hash_block_blake3_base_chunk_len % mk_lib_crypto_hash_block_blake3_base_block_len == 0);

	mk_lang_assert(blake3_base);

	blake3_base->m_state = s_mk_lib_crypto_hash_block_blake3_base_init;
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

	mk_lang_assert(blake3_base);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_blake3_base_block_len);

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
				mk_lib_crypto_hash_block_blake3_base_compress_block_and_mix(&blake3_base->m_state, &blake3_base->m_chunk_count, flags, &ptr[i], mk_lib_crypto_hash_block_blake3_base_block_len);
			}
			mk_lib_crypto_hash_block_blake3_base_chunk_finished(blake3_base, &blake3_base->m_state);
			blake3_base->m_state = s_mk_lib_crypto_hash_block_blake3_base_init;
			blake3_base->m_block_count = 0;
			ptr += free;
			rem -= free;
		}
		nchunks = rem / mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk;
		for(ichunk = 0; ichunk != nchunks; ++ichunk)
		{
			mk_lib_crypto_hash_block_blake3_base_chunk_compress(&blake3_base->m_chunk_count, &pblocks[ichunk * mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk], &blake3_base->m_state);
			mk_lib_crypto_hash_block_blake3_base_chunk_finished(blake3_base, &blake3_base->m_state);
			blake3_base->m_state = s_mk_lib_crypto_hash_block_blake3_base_init;
		}
		ptr += nchunks * mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk;
		rem -= nchunks * mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk;
	}
	mk_lang_assert(rem >= 0 && rem < mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk);
	mk_lang_assert(((mk_lang_types_sint_t)(rem)) + blake3_base->m_block_count >= 0 && ((mk_lang_types_sint_t)(rem)) + blake3_base->m_block_count < mk_lib_crypto_hash_block_blake3_base_blocks_per_chunk);
	first = blake3_base->m_block_count == 0;
	for(i = 0; i != ((mk_lang_types_sint_t)(rem)); ++i)
	{
		flags = mk_lib_crypto_hash_block_blake3_base_flags_e_none;
		flags = ((mk_lib_crypto_hash_block_blake3_base_flags_t)(flags | (first && i == 0 ? mk_lib_crypto_hash_block_blake3_base_flags_e_start : mk_lib_crypto_hash_block_blake3_base_flags_e_none)));
		mk_lib_crypto_hash_block_blake3_base_compress_block_and_mix(&blake3_base->m_state, &blake3_base->m_chunk_count, flags, &ptr[i], mk_lib_crypto_hash_block_blake3_base_block_len);
	}
	blake3_base->m_block_count += ((mk_lang_types_uchar_t)(((mk_lang_types_sint_t)(rem))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_finish(mk_lib_crypto_hash_block_blake3_base_pt const blake3_base, mk_lib_crypto_hash_block_blake3_base_block_pt const block, mk_lang_types_sint_t const idx) mk_lang_noexcept
{
	mk_sl_cui_uint64_t seek mk_lang_constexpr_init;
	mk_sl_cui_uint8_t u8zero mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_blake3_base_flags_t flags mk_lang_constexpr_init;
	mk_lang_types_sint_t idxb mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lib_crypto_hash_block_blake3_base_output_block_len >= mk_lib_crypto_hash_block_blake3_base_digest_len);

	mk_lang_assert(blake3_base);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx <= mk_lib_crypto_hash_block_blake3_base_block_len);

	mk_sl_cui_uint64_set_zero(&seek);
	mk_sl_cui_uint8_set_zero(&u8zero);
	mk_lib_crypto_hash_block_blake3_base_memset_u8_fn(&block->m_uint8s[idx], &u8zero, mk_lib_crypto_hash_block_blake3_base_block_len - idx);
	if(blake3_base->m_state_count != 0)
	{
		--blake3_base->m_state_count;
		flags = mk_lib_crypto_hash_block_blake3_base_flags_e_none;
		flags = ((mk_lib_crypto_hash_block_blake3_base_flags_t)(flags | (blake3_base->m_block_count == 0 ? mk_lib_crypto_hash_block_blake3_base_flags_e_start : mk_lib_crypto_hash_block_blake3_base_flags_e_none)));
		flags = ((mk_lib_crypto_hash_block_blake3_base_flags_t)(flags | mk_lib_crypto_hash_block_blake3_base_flags_e_end));
		mk_lib_crypto_hash_block_blake3_base_compress_block_and_mix(&blake3_base->m_state, &blake3_base->m_chunk_count, flags, block, idx);
		mk_lib_crypto_hash_block_blake3_base_state_to_uint8s(&blake3_base->m_state,                                  &block->m_uint8s[1 * mk_lib_crypto_hash_block_blake3_base_digest_len]);
		mk_lib_crypto_hash_block_blake3_base_state_to_uint8s(&blake3_base->m_states.m_states[blake3_base->m_state_count], &block->m_uint8s[0 * mk_lib_crypto_hash_block_blake3_base_digest_len]);
		while(blake3_base->m_state_count != 0)
		{
			--blake3_base->m_state_count;
			blake3_base->m_state = s_mk_lib_crypto_hash_block_blake3_base_init;
			flags = mk_lib_crypto_hash_block_blake3_base_flags_e_parent;
			mk_lib_crypto_hash_block_blake3_base_compress_block_and_mix(&blake3_base->m_state, &seek, flags, block, mk_lib_crypto_hash_block_blake3_base_block_len);
			mk_lib_crypto_hash_block_blake3_base_state_to_uint8s(&blake3_base->m_state,                                  &block->m_uint8s[1 * mk_lib_crypto_hash_block_blake3_base_digest_len]);
			mk_lib_crypto_hash_block_blake3_base_state_to_uint8s(&blake3_base->m_states.m_states[blake3_base->m_state_count], &block->m_uint8s[0 * mk_lib_crypto_hash_block_blake3_base_digest_len]);
		}
		blake3_base->m_state = s_mk_lib_crypto_hash_block_blake3_base_init;
		flags = mk_lib_crypto_hash_block_blake3_base_flags_e_parent;
		idxb = mk_lib_crypto_hash_block_blake3_base_block_len;
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

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_blake3_base_squeeze(mk_lib_crypto_hash_block_blake3_base_pt const blake3_base, mk_lib_crypto_hash_block_blake3_base_block_pt const block, mk_sl_cui_uint64_pct const seek, mk_lib_crypto_hash_block_blake3_base_output_block_pt const output_block) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lib_crypto_hash_block_blake3_base_output_block_len >= mk_lib_crypto_hash_block_blake3_base_digest_len);

	mk_lang_assert(blake3_base);
	mk_lang_assert(block);
	mk_lang_assert(seek);
	mk_lang_assert(output_block);

	mk_lib_crypto_hash_block_blake3_base_compress_block_and_output(&blake3_base->m_state, seek, ((mk_lib_crypto_hash_block_blake3_base_flags_t)(blake3_base->m_flags)), block, blake3_base->m_idx, output_block);
}
