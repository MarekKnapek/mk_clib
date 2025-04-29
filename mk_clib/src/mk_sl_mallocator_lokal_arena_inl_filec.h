#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_offsetof.h"
#include "mk_lang_roundup.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_sl_cui_uint8.h"


#include "mk_sl_mallocator_lokal_arena_inl_defd.h"


#define mk_sl_cui_t_name mk_sl_mallocator_lokal_arena_inl_defd_num_blocks_name
#define mk_sl_cui_t_base mk_lang_bui_usize
#define mk_sl_cui_t_count 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_name
#define mk_sl_cui_t_base mk_lang_bui_usize
#define mk_sl_cui_t_count 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_sl_mallocator_lokal_arena_inl_defd_num_words_name
#define mk_sl_cui_t_base mk_lang_bui_usize
#define mk_sl_cui_t_count 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_lang_memall2_t_name mk_sl_mallocator_lokal_arena_inl_defd_num_words_name
#define mk_lang_memall2_t_tn mk_sl_mallocator_lokal_arena_inl_defd_num_words_name
#include "mk_lang_memall2_inl_fileh.h"
#include "mk_lang_memall2_inl_filec.h"
#include "mk_lang_memall2_inl_fileu.h"
#define mk_sl_uint_convert_t_name mk_sl_mallocator_lokal_arena_inl_defd_convert_name
#define mk_sl_uint_convert_t_big_tn mk_sl_mallocator_lokal_arena_inl_defd_num_words_name
#define mk_sl_uint_convert_t_sml_tn mk_sl_cui_uint8
#define mk_sl_uint_convert_t_endian mk_lang_endian_native
#include "mk_sl_uint_convert_inl_fileh.h"
#include "mk_sl_uint_convert_inl_filec.h"
#include "mk_sl_uint_convert_inl_fileu.h"


enum mk_sl_mallocator_lokal_arena_inl_defd_size_total_u { mk_sl_mallocator_lokal_arena_inl_defd_size_total_v = mk_sl_mallocator_lokal_arena_inl_defd_size_total_d }; typedef enum mk_sl_mallocator_lokal_arena_inl_defd_size_total_u mk_sl_mallocator_lokal_arena_inl_defd_size_total_t;
enum mk_sl_mallocator_lokal_arena_inl_defd_size_usable_u { mk_sl_mallocator_lokal_arena_inl_defd_size_usable_v = mk_sl_mallocator_lokal_arena_inl_defd_size_usable_d }; typedef enum mk_sl_mallocator_lokal_arena_inl_defd_size_usable_u mk_sl_mallocator_lokal_arena_inl_defd_size_usable_t;
enum mk_sl_mallocator_lokal_arena_inl_defd_words_u { mk_sl_mallocator_lokal_arena_inl_defd_words_v = mk_sl_mallocator_lokal_arena_inl_defd_words_d }; typedef enum mk_sl_mallocator_lokal_arena_inl_defd_words_u mk_sl_mallocator_lokal_arena_inl_defd_words_t;
enum mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_u { mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v = mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_d }; typedef enum mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_u mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_t;
enum mk_sl_mallocator_lokal_arena_inl_defd_blocks_usable_u { mk_sl_mallocator_lokal_arena_inl_defd_blocks_usable_v = mk_sl_mallocator_lokal_arena_inl_defd_blocks_usable_d }; typedef enum mk_sl_mallocator_lokal_arena_inl_defd_blocks_usable_u mk_sl_mallocator_lokal_arena_inl_defd_blocks_usable_t;
enum mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_u { mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v = mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_d }; typedef enum mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_u mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_t;

struct mk_sl_mallocator_lokal_arena_inl_defd_free_block_s
{
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t m_next;
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t m_prev;
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t m_blocks_allocated;
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t m_bytes_allocated;
};
typedef struct mk_sl_mallocator_lokal_arena_inl_defd_free_block_s mk_sl_mallocator_lokal_arena_inl_defd_free_block_t;
mk_lang_typedef(mk_sl_mallocator_lokal_arena_inl_defd_free_block);

union mk_sl_mallocator_lokal_arena_inl_defd_bitmap_data_u
{
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t m_words[mk_sl_mallocator_lokal_arena_inl_defd_words_v];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_sl_mallocator_lokal_arena_inl_defd_bitmap_data_u mk_sl_mallocator_lokal_arena_inl_defd_bitmap_data_t;
struct mk_sl_mallocator_lokal_arena_inl_defd_bitmap_s
{
	mk_sl_mallocator_lokal_arena_inl_defd_bitmap_data_t m_data;
};
typedef struct mk_sl_mallocator_lokal_arena_inl_defd_bitmap_s mk_sl_mallocator_lokal_arena_inl_defd_bitmap_t;
mk_lang_typedef(mk_sl_mallocator_lokal_arena_inl_defd_bitmap);


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_statistics_init(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_arena_inl_defd_statistics_want
	mk_lang_assert(arena);

	mk_sl_mallocator_lokal_arena_inl_defd_num_blocks_set_zero(&arena->m_statistics.m_blocks_allocated);
	mk_sl_mallocator_lokal_arena_inl_defd_num_blocks_set_zero(&arena->m_statistics.m_blocks_deallocated);
	mk_sl_mallocator_lokal_arena_inl_defd_num_blocks_set_zero(&arena->m_statistics.m_blocks_peak);
	mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_set_zero(&arena->m_statistics.m_bytes_allocated);
	mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_set_zero(&arena->m_statistics.m_bytes_deallocated);
	mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_set_zero(&arena->m_statistics.m_bytes_peak);
#else
	mk_lang_assert(arena);

	((mk_lang_types_void_t)(arena));
#endif
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_statistics_deinit(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_arena_inl_defd_statistics_want
	mk_sl_mallocator_lokal_arena_inl_defd_num_blocks_t blocks_live;
	mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_t bytes_live;

	mk_lang_assert(arena);

	mk_sl_mallocator_lokal_arena_inl_defd_num_blocks_sub3_wrap_cid_cod(&arena->m_statistics.m_blocks_allocated, &arena->m_statistics.m_blocks_deallocated, &blocks_live);
	mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_sub3_wrap_cid_cod(&arena->m_statistics.m_bytes_allocated, &arena->m_statistics.m_bytes_deallocated, &bytes_live);
	mk_lang_assert(mk_sl_mallocator_lokal_arena_inl_defd_num_blocks_is_zero(&blocks_live));
	mk_lang_assert(mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_is_zero(&bytes_live));
#else
	mk_lang_assert(arena);

	((mk_lang_types_void_t)(arena));
#endif
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_statistics_update_peak(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_arena_inl_defd_statistics_want
	mk_sl_mallocator_lokal_arena_inl_defd_num_blocks_t blocks_live;
	mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_t bytes_live;

	mk_lang_assert(arena);

	mk_sl_mallocator_lokal_arena_inl_defd_num_blocks_sub3_wrap_cid_cod(&arena->m_statistics.m_blocks_allocated, &arena->m_statistics.m_blocks_deallocated, &blocks_live);
	if(mk_sl_mallocator_lokal_arena_inl_defd_num_blocks_gt(&blocks_live, &arena->m_statistics.m_blocks_peak))
	{
		arena->m_statistics.m_blocks_peak = blocks_live;
	}
	mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_sub3_wrap_cid_cod(&arena->m_statistics.m_bytes_allocated, &arena->m_statistics.m_bytes_deallocated, &bytes_live);
	if(mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_gt(&bytes_live, &arena->m_statistics.m_bytes_peak))
	{
		arena->m_statistics.m_bytes_peak = bytes_live;
	}
#else
	mk_lang_assert(arena);

	((mk_lang_types_void_t)(arena));
#endif
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_statistics_on_allocated(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_types_usize_t const size_bytes) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_arena_inl_defd_statistics_want
	mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_t bytes;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(size_bytes >= 0);
	mk_lang_assert(size_bytes <= mk_sl_mallocator_lokal_arena_inl_defd_size_usable_v);
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_lokal_arena_inl_defd_num_blocks_inc1(&arena->m_statistics.m_blocks_allocated);
	mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_from_bi_usize(&bytes, &size_bytes);
	mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_add2_wrap_cid_cod(&arena->m_statistics.m_bytes_allocated, &bytes);
	mk_sl_mallocator_lokal_arena_inl_defd_statistics_update_peak(arena);
#else
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(size_bytes >= 0);
	mk_lang_assert(size_bytes <= mk_sl_mallocator_lokal_arena_inl_defd_size_usable_v);
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(arena));
	((mk_lang_types_void_t)(size_bytes));
#endif
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_statistics_on_deallocated(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_types_usize_t const size_bytes) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_arena_inl_defd_statistics_want
	mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_t bytes;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(size_bytes >= 0);
	mk_lang_assert(size_bytes <= mk_sl_mallocator_lokal_arena_inl_defd_size_usable_v);
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_lokal_arena_inl_defd_num_blocks_inc1(&arena->m_statistics.m_blocks_deallocated);
	mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_from_bi_usize(&bytes, &size_bytes);
	mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_add2_wrap_cid_cod(&arena->m_statistics.m_bytes_deallocated, &bytes);
#else
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(size_bytes >= 0);
	mk_lang_assert(size_bytes <= mk_sl_mallocator_lokal_arena_inl_defd_size_usable_v);
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(arena));
	((mk_lang_types_void_t)(size_bytes));
#endif
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_statistics_on_reallocated(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_types_usize_t const old_size_bytes, mk_lang_types_usize_t const new_size_bytes) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_arena_inl_defd_statistics_want
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(old_size_bytes >= 0);
	mk_lang_assert(new_size_bytes >= 0);
	mk_lang_assert(old_size_bytes <= mk_sl_mallocator_lokal_arena_inl_defd_size_usable_v);
	mk_lang_assert(new_size_bytes <= mk_sl_mallocator_lokal_arena_inl_defd_size_usable_v);
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_lokal_arena_inl_defd_statistics_on_allocated(arena, new_size_bytes);
	mk_sl_mallocator_lokal_arena_inl_defd_statistics_on_deallocated(arena, old_size_bytes);
#else
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(old_size_bytes >= 0);
	mk_lang_assert(new_size_bytes >= 0);
	mk_lang_assert(old_size_bytes <= mk_sl_mallocator_lokal_arena_inl_defd_size_usable_v);
	mk_lang_assert(new_size_bytes <= mk_sl_mallocator_lokal_arena_inl_defd_size_usable_v);
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(arena));
	((mk_lang_types_void_t)(old_size_bytes));
	((mk_lang_types_void_t)(new_size_bytes));
#endif
}


mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_load(mk_sl_mallocator_lokal_arena_inl_defd_pct const arena, mk_lang_types_usize_t const block_idx, mk_sl_mallocator_lokal_arena_inl_defd_free_block_pt const free_block) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_mem_pct mem mk_lang_constexpr_init;
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	mk_lang_assert(free_block);
	#include "mk_lang_warning_msvc_pop.h"

	mem = &arena->m_mem;
	byte_idx = block_idx * mk_sl_mallocator_lokal_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_lokal_arena_inl_defd_convert_to_big(&free_block->m_next, ptr + mk_lang_offsetof(mk_sl_mallocator_lokal_arena_inl_defd_free_block_t, m_next));
	mk_sl_mallocator_lokal_arena_inl_defd_convert_to_big(&free_block->m_prev, ptr + mk_lang_offsetof(mk_sl_mallocator_lokal_arena_inl_defd_free_block_t, m_prev));
	mk_sl_mallocator_lokal_arena_inl_defd_convert_to_big(&free_block->m_blocks_allocated, ptr + mk_lang_offsetof(mk_sl_mallocator_lokal_arena_inl_defd_free_block_t, m_blocks_allocated));
	mk_sl_mallocator_lokal_arena_inl_defd_convert_to_big(&free_block->m_bytes_allocated, ptr + mk_lang_offsetof(mk_sl_mallocator_lokal_arena_inl_defd_free_block_t, m_bytes_allocated));
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_store(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_types_usize_t const block_idx, mk_sl_mallocator_lokal_arena_inl_defd_free_block_pct const free_block) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_mem_pt mem mk_lang_constexpr_init;
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	mk_lang_assert(free_block);
	#include "mk_lang_warning_msvc_pop.h"

	mem = &arena->m_mem;
	byte_idx = block_idx * mk_sl_mallocator_lokal_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_lokal_arena_inl_defd_convert_to_sml(&free_block->m_next, ptr + mk_lang_offsetof(mk_sl_mallocator_lokal_arena_inl_defd_free_block_t, m_next));
	mk_sl_mallocator_lokal_arena_inl_defd_convert_to_sml(&free_block->m_prev, ptr + mk_lang_offsetof(mk_sl_mallocator_lokal_arena_inl_defd_free_block_t, m_prev));
	mk_sl_mallocator_lokal_arena_inl_defd_convert_to_sml(&free_block->m_blocks_allocated, ptr + mk_lang_offsetof(mk_sl_mallocator_lokal_arena_inl_defd_free_block_t, m_blocks_allocated));
	mk_sl_mallocator_lokal_arena_inl_defd_convert_to_sml(&free_block->m_bytes_allocated, ptr + mk_lang_offsetof(mk_sl_mallocator_lokal_arena_inl_defd_free_block_t, m_bytes_allocated));
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_next_load(mk_sl_mallocator_lokal_arena_inl_defd_pct const arena, mk_lang_types_usize_t const block_idx, mk_sl_mallocator_lokal_arena_inl_defd_num_words_pt const next) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_mem_pct mem mk_lang_constexpr_init;
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	mk_lang_assert(next);
	#include "mk_lang_warning_msvc_pop.h"

	mem = &arena->m_mem;
	byte_idx = block_idx * mk_sl_mallocator_lokal_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_lokal_arena_inl_defd_convert_to_big(next, ptr + mk_lang_offsetof(mk_sl_mallocator_lokal_arena_inl_defd_free_block_t, m_next));
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_next_store(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_types_usize_t const block_idx, mk_sl_mallocator_lokal_arena_inl_defd_num_words_pct const next) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_mem_pt mem mk_lang_constexpr_init;
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	mk_lang_assert(next);
	#include "mk_lang_warning_msvc_pop.h"

	mem = &arena->m_mem;
	byte_idx = block_idx * mk_sl_mallocator_lokal_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_lokal_arena_inl_defd_convert_to_sml(next, ptr + mk_lang_offsetof(mk_sl_mallocator_lokal_arena_inl_defd_free_block_t, m_next));
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_prev_load(mk_sl_mallocator_lokal_arena_inl_defd_pct const arena, mk_lang_types_usize_t const block_idx, mk_sl_mallocator_lokal_arena_inl_defd_num_words_pt const prev) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_mem_pct mem mk_lang_constexpr_init;
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	mk_lang_assert(prev);
	#include "mk_lang_warning_msvc_pop.h"

	mem = &arena->m_mem;
	byte_idx = block_idx * mk_sl_mallocator_lokal_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_lokal_arena_inl_defd_convert_to_big(prev, ptr + mk_lang_offsetof(mk_sl_mallocator_lokal_arena_inl_defd_free_block_t, m_prev));
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_prev_store(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_types_usize_t const block_idx, mk_sl_mallocator_lokal_arena_inl_defd_num_words_pct const prev) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_mem_pt mem mk_lang_constexpr_init;
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	mk_lang_assert(prev);
	#include "mk_lang_warning_msvc_pop.h"

	mem = &arena->m_mem;
	byte_idx = block_idx * mk_sl_mallocator_lokal_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_lokal_arena_inl_defd_convert_to_sml(prev, ptr + mk_lang_offsetof(mk_sl_mallocator_lokal_arena_inl_defd_free_block_t, m_prev));
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_blocks_allocated_load(mk_sl_mallocator_lokal_arena_inl_defd_pct const arena, mk_sl_mallocator_lokal_arena_inl_defd_num_words_pt const blocks_allocated) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_mem_pct mem mk_lang_constexpr_init;
	mk_lang_types_usize_t block_idx mk_lang_constexpr_init;
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;

	mk_lang_assert(arena);
	mk_lang_assert(blocks_allocated);

	mem = &arena->m_mem;
	block_idx = mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v - 1;
	byte_idx = block_idx * mk_sl_mallocator_lokal_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_lokal_arena_inl_defd_convert_to_big(blocks_allocated, ptr + mk_lang_offsetof(mk_sl_mallocator_lokal_arena_inl_defd_free_block_t, m_blocks_allocated));
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_blocks_allocated_store(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_sl_mallocator_lokal_arena_inl_defd_num_words_pct const blocks_allocated) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_mem_pt mem mk_lang_constexpr_init;
	mk_lang_types_usize_t block_idx mk_lang_constexpr_init;
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;

	mk_lang_assert(arena);
	mk_lang_assert(blocks_allocated);

	mem = &arena->m_mem;
	block_idx = mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v - 1;
	byte_idx = block_idx * mk_sl_mallocator_lokal_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_lokal_arena_inl_defd_convert_to_sml(blocks_allocated, ptr + mk_lang_offsetof(mk_sl_mallocator_lokal_arena_inl_defd_free_block_t, m_blocks_allocated));
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_bytes_allocated_load(mk_sl_mallocator_lokal_arena_inl_defd_pct const arena, mk_sl_mallocator_lokal_arena_inl_defd_num_words_pt const bytes_allocated) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_mem_pct mem mk_lang_constexpr_init;
	mk_lang_types_usize_t block_idx mk_lang_constexpr_init;
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;

	mk_lang_assert(arena);
	mk_lang_assert(bytes_allocated);

	mem = &arena->m_mem;
	block_idx = mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v - 1;
	byte_idx = block_idx * mk_sl_mallocator_lokal_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_lokal_arena_inl_defd_convert_to_big(bytes_allocated, ptr + mk_lang_offsetof(mk_sl_mallocator_lokal_arena_inl_defd_free_block_t, m_bytes_allocated));
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_bytes_allocated_store(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_sl_mallocator_lokal_arena_inl_defd_num_words_pct const bytes_allocated) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_mem_pt mem mk_lang_constexpr_init;
	mk_lang_types_usize_t block_idx mk_lang_constexpr_init;
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;

	mk_lang_assert(arena);
	mk_lang_assert(bytes_allocated);

	mem = &arena->m_mem;
	block_idx = mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v - 1;
	byte_idx = block_idx * mk_sl_mallocator_lokal_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_lokal_arena_inl_defd_convert_to_sml(bytes_allocated, ptr + mk_lang_offsetof(mk_sl_mallocator_lokal_arena_inl_defd_free_block_t, m_bytes_allocated));
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_mallocator_lokal_arena_inl_defd_mem_get_next_block_idx(mk_sl_mallocator_lokal_arena_inl_defd_pct const arena, mk_lang_types_usize_t const block_idx) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t next_block_idx_num mk_lang_constexpr_init;
	mk_lang_types_usize_t next_block_idx_us mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_next_load(arena, block_idx, &next_block_idx_num);
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_to_bi_usize(&next_block_idx_num, &next_block_idx_us);
	next_block_idx_us = block_idx + 1 + next_block_idx_us;
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(next_block_idx_us >= 0);
	mk_lang_assert(next_block_idx_us < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"
	return next_block_idx_us;
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_set_next_block_idx(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_types_usize_t const block_idx, mk_lang_types_usize_t const next_block_idx) mk_lang_noexcept
{
	mk_lang_types_usize_t dif_us mk_lang_constexpr_init;
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t dif_num mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	mk_lang_assert(next_block_idx >= 0);
	mk_lang_assert(next_block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"

	dif_us = next_block_idx - block_idx - 1;
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_from_bi_usize(&dif_num, &dif_us);
	mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_next_store(arena, block_idx, &dif_num);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_mallocator_lokal_arena_inl_defd_mem_get_prev_block_idx(mk_sl_mallocator_lokal_arena_inl_defd_pct const arena, mk_lang_types_usize_t const block_idx) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t prev_block_idx_num mk_lang_constexpr_init;
	mk_lang_types_usize_t prev_block_idx_us mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_prev_load(arena, block_idx, &prev_block_idx_num);
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_to_bi_usize(&prev_block_idx_num, &prev_block_idx_us);
	prev_block_idx_us = block_idx - 1 - prev_block_idx_us;
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(prev_block_idx_us >= 0);
	mk_lang_assert(prev_block_idx_us < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"
	return prev_block_idx_us;
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_set_prev_block_idx(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_types_usize_t const block_idx, mk_lang_types_usize_t const prev_block_idx) mk_lang_noexcept
{
	mk_lang_types_usize_t dif_us mk_lang_constexpr_init;
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t dif_num mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	mk_lang_assert(prev_block_idx >= 0);
	mk_lang_assert(prev_block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"

	dif_us = block_idx - prev_block_idx - 1;
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_from_bi_usize(&dif_num, &dif_us);
	mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_prev_store(arena, block_idx, &dif_num);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_mallocator_lokal_arena_inl_defd_mem_get_blocks_allocated(mk_sl_mallocator_lokal_arena_inl_defd_pct const arena) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t blocks_allocated_num mk_lang_constexpr_init;
	mk_lang_types_usize_t blocks_allocated_us mk_lang_constexpr_init;

	mk_lang_assert(arena);

	mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_blocks_allocated_load(arena, &blocks_allocated_num);
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_to_bi_usize(&blocks_allocated_num, &blocks_allocated_us);
	return blocks_allocated_us;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_mallocator_lokal_arena_inl_defd_mem_get_blocks_free(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena) mk_lang_noexcept
{
	mk_lang_types_usize_t blocks_total mk_lang_constexpr_init;
	mk_lang_types_usize_t blocks_wasted mk_lang_constexpr_init;
	mk_lang_types_usize_t blocks_allocated mk_lang_constexpr_init;
	mk_lang_types_usize_t blocks_free mk_lang_constexpr_init;

	mk_lang_assert(arena);

	blocks_total = mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v;
	blocks_wasted = mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v;
	blocks_allocated = mk_sl_mallocator_lokal_arena_inl_defd_mem_get_blocks_allocated(arena);
	blocks_free = blocks_total - blocks_wasted - blocks_allocated;
	return blocks_free;
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_blocks_allocated_inc_by(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_types_usize_t const amount) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t blocks_allocated mk_lang_constexpr_init;
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t tmp mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(amount >= 0);
	mk_lang_assert(amount <= mk_sl_mallocator_lokal_arena_inl_defd_mem_get_blocks_free(arena));
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_blocks_allocated_load(arena, &blocks_allocated);
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_from_bi_usize(&tmp, &amount);
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_add2_wrap_cid_cod(&blocks_allocated, &tmp);
	mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_blocks_allocated_store(arena, &blocks_allocated);
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_blocks_allocated_dec_by(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_types_usize_t const amount) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t blocks_allocated mk_lang_constexpr_init;
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t tmp mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(amount >= 0);
	mk_lang_assert(amount <= mk_sl_mallocator_lokal_arena_inl_defd_mem_get_blocks_allocated(arena));
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_blocks_allocated_load(arena, &blocks_allocated);
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_from_bi_usize(&tmp, &amount);
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_sub2_wrap_cid_cod(&blocks_allocated, &tmp);
	mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_blocks_allocated_store(arena, &blocks_allocated);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_mallocator_lokal_arena_inl_defd_mem_get_bytes_allocated(mk_sl_mallocator_lokal_arena_inl_defd_pct const arena) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t bytes_allocated_num mk_lang_constexpr_init;
	mk_lang_types_usize_t bytes_allocated_us mk_lang_constexpr_init;

	mk_lang_assert(arena);

	mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_bytes_allocated_load(arena, &bytes_allocated_num);
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_to_bi_usize(&bytes_allocated_num, &bytes_allocated_us);
	return bytes_allocated_us;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_mallocator_lokal_arena_inl_defd_mem_get_bytes_free(mk_sl_mallocator_lokal_arena_inl_defd_pct const arena) mk_lang_noexcept
{
	mk_lang_types_usize_t bytes_total;
	mk_lang_types_usize_t bytes_wasted;
	mk_lang_types_usize_t bytes_allocated;
	mk_lang_types_usize_t bytes_free;

	mk_lang_assert(arena);

	bytes_total = mk_sl_mallocator_lokal_arena_inl_defd_size;
	bytes_wasted = ((mk_lang_types_usize_t)(mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v)) * ((mk_lang_types_usize_t)(mk_sl_mallocator_lokal_arena_inl_defd_block_v));
	bytes_allocated = mk_sl_mallocator_lokal_arena_inl_defd_mem_get_bytes_allocated(arena);
	bytes_free = bytes_total - bytes_wasted - bytes_allocated;
	return bytes_free;
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_bytes_allocated_inc_by(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_types_usize_t const amount) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t bytes_allocated mk_lang_constexpr_init;
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t tmp mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(amount >= 0);
	mk_lang_assert(amount <= mk_sl_mallocator_lokal_arena_inl_defd_mem_get_bytes_free(arena));
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_bytes_allocated_load(arena, &bytes_allocated);
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_from_bi_usize(&tmp, &amount);
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_add2_wrap_cid_cod(&bytes_allocated, &tmp);
	mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_bytes_allocated_store(arena, &bytes_allocated);
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_bytes_allocated_dec_by(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_types_usize_t const amount) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t bytes_allocated mk_lang_constexpr_init;
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t tmp mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(amount >= 0);
	mk_lang_assert(amount <= mk_sl_mallocator_lokal_arena_inl_defd_mem_get_bytes_allocated(arena));
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_bytes_allocated_load(arena, &bytes_allocated);
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_from_bi_usize(&tmp, &amount);
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_sub2_wrap_cid_cod(&bytes_allocated, &tmp);
	mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_bytes_allocated_store(arena, &bytes_allocated);
}


mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_load(mk_sl_mallocator_lokal_arena_inl_defd_pct const arena, mk_sl_mallocator_lokal_arena_inl_defd_bitmap_pt const bitmap) mk_lang_noexcept
{
	mk_lang_assert(arena);
	mk_lang_assert(bitmap);

	mk_sl_mallocator_lokal_arena_inl_defd_convert_to_big_multi(&bitmap->m_data.m_words[0], &arena->m_mem.m_data.m_u8s[0], mk_sl_mallocator_lokal_arena_inl_defd_words_v);
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_store(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_sl_mallocator_lokal_arena_inl_defd_bitmap_pct const bitmap) mk_lang_noexcept
{
	mk_lang_assert(arena);
	mk_lang_assert(bitmap);

	mk_sl_mallocator_lokal_arena_inl_defd_convert_to_sml_multi(&bitmap->m_data.m_words[0], &arena->m_mem.m_data.m_u8s[0], mk_sl_mallocator_lokal_arena_inl_defd_words_v);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_is_block_free(mk_sl_mallocator_lokal_arena_inl_defd_bitmap_pct const bitmap, mk_lang_types_usize_t const block_idx) mk_lang_noexcept
{
	mk_lang_types_usize_t idx_big mk_lang_constexpr_init;
	mk_lang_types_usize_t idx_sml mk_lang_constexpr_init;
	mk_lang_types_bool_t is_allocated mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(bitmap);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"

	idx_big = block_idx / mk_sl_mallocator_lokal_arena_inl_defd_num_words_size_bits_v;
	idx_sml = block_idx % mk_sl_mallocator_lokal_arena_inl_defd_num_words_size_bits_v;
	is_allocated = mk_sl_mallocator_lokal_arena_inl_defd_num_words_is_bit(&bitmap->m_data.m_words[idx_big], ((mk_lang_types_sint_t)(idx_sml)));
	return !is_allocated;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_is_blocks_free(mk_sl_mallocator_lokal_arena_inl_defd_bitmap_pct const bitmap, mk_lang_types_usize_t const block_idx, mk_lang_types_usize_t const blocks_count) mk_lang_noexcept
{
	mk_lang_types_bool_t is_free mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(bitmap);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx <= mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	mk_lang_assert(blocks_count >= 0);
	mk_lang_assert(blocks_count < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"

	is_free = mk_lang_true;
	if(blocks_count != 0)
	{
		is_free = mk_lang_false;
		if(!(block_idx == mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v || block_idx + blocks_count >= mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v))
		{
			n = blocks_count;
			for(i = 0; i != n; ++i)
			{
				if(!mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_is_block_free(bitmap, block_idx + i))
				{
					break;
				}
			}
			is_free = i == n;
		}
	}
	return is_free;
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_mark_block_free(mk_sl_mallocator_lokal_arena_inl_defd_bitmap_pt const bitmap, mk_lang_types_usize_t const block_idx) mk_lang_noexcept
{
	mk_lang_types_usize_t idx_big mk_lang_constexpr_init;
	mk_lang_types_usize_t idx_sml mk_lang_constexpr_init;
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t tmp mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(bitmap);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"

	idx_big = block_idx / mk_sl_mallocator_lokal_arena_inl_defd_num_words_size_bits_v;
	idx_sml = block_idx % mk_sl_mallocator_lokal_arena_inl_defd_num_words_size_bits_v;
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_set_bit(&tmp, ((mk_lang_types_sint_t)(idx_sml)));
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_not1(&tmp);
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_and2(&bitmap->m_data.m_words[idx_big], &tmp);
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_mark_block_allocated(mk_sl_mallocator_lokal_arena_inl_defd_bitmap_pt const bitmap, mk_lang_types_usize_t const block_idx) mk_lang_noexcept
{
	mk_lang_types_usize_t idx_big mk_lang_constexpr_init;
	mk_lang_types_usize_t idx_sml mk_lang_constexpr_init;
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t tmp mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(bitmap);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"

	idx_big = block_idx / mk_sl_mallocator_lokal_arena_inl_defd_num_words_size_bits_v;
	idx_sml = block_idx % mk_sl_mallocator_lokal_arena_inl_defd_num_words_size_bits_v;
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_set_bit(&tmp, ((mk_lang_types_sint_t)(idx_sml)));
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_or2(&bitmap->m_data.m_words[idx_big], &tmp);
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_mark_blocks_free(mk_sl_mallocator_lokal_arena_inl_defd_bitmap_pt const bitmap, mk_lang_types_usize_t const block_idx, mk_lang_types_usize_t const blocks_count) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(bitmap);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	mk_lang_assert(blocks_count >= 0);
	mk_lang_assert(blocks_count <= mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v - block_idx);
	#include "mk_lang_warning_msvc_pop.h"

	n = blocks_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_mark_block_free(bitmap, block_idx + i);
	}
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_mark_blocks_allocated(mk_sl_mallocator_lokal_arena_inl_defd_bitmap_pt const bitmap, mk_lang_types_usize_t const block_idx, mk_lang_types_usize_t const blocks_count) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(bitmap);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
	mk_lang_assert(blocks_count >= 0);
	mk_lang_assert(blocks_count <= mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v - block_idx);
	#include "mk_lang_warning_msvc_pop.h"

	n = blocks_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_mark_block_allocated(bitmap, block_idx + i);
	}
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_mallocator_lokal_arena_inl_defd_mem_verify(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_arena_inl_defd_verify_want
	mk_lang_types_usize_t blocks_free mk_lang_constexpr_init;
	mk_sl_mallocator_lokal_arena_inl_defd_bitmap_t bitmap mk_lang_constexpr_init;
	mk_lang_types_usize_t start_idx mk_lang_constexpr_init;
	mk_lang_types_usize_t block_idx mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_usize_t next mk_lang_constexpr_init;
	mk_lang_types_usize_t prev mk_lang_constexpr_init;

	mk_lang_assert(arena);

	blocks_free = mk_sl_mallocator_lokal_arena_inl_defd_mem_get_blocks_free(arena);
	if(blocks_free != 0)
	{
		mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_load(arena, &bitmap);
		start_idx = mk_sl_mallocator_lokal_arena_inl_defd_mem_get_next_block_idx(arena, mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v - 1);
		block_idx = start_idx;
		n = blocks_free;
		for(i = 0; i != n; ++i)
		{
			mk_lang_assert(mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_is_block_free(&bitmap, block_idx));
			next = mk_sl_mallocator_lokal_arena_inl_defd_mem_get_next_block_idx(arena, block_idx);
			prev = mk_sl_mallocator_lokal_arena_inl_defd_mem_get_prev_block_idx(arena, next);
			mk_lang_assert(prev == block_idx);
			mk_lang_assert(next != start_idx || i == n - 1);
			block_idx = next;
		}
		mk_lang_assert(block_idx == start_idx);
	}
	return mk_lang_true;
#else
	mk_lang_assert(mem);
	((mk_lang_types_void_t)(mem));
	return mk_lang_true;
#endif
}


mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_block_disconnect(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_types_usize_t const block_idx) mk_lang_noexcept
{
	mk_lang_types_usize_t old_next mk_lang_constexpr_init;
	mk_lang_types_usize_t old_prev mk_lang_constexpr_init;
	mk_lang_types_usize_t old_start mk_lang_constexpr_init;

	mk_lang_assert(arena);
	mk_lang_assert(block_idx >= mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v);
	mk_lang_assert(block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);

	old_next = mk_sl_mallocator_lokal_arena_inl_defd_mem_get_next_block_idx(arena, block_idx);
	old_prev = mk_sl_mallocator_lokal_arena_inl_defd_mem_get_prev_block_idx(arena, block_idx);
	mk_sl_mallocator_lokal_arena_inl_defd_mem_set_next_block_idx(arena, old_prev, old_next);
	mk_sl_mallocator_lokal_arena_inl_defd_mem_set_prev_block_idx(arena, old_next, old_prev);
	old_start = mk_sl_mallocator_lokal_arena_inl_defd_mem_get_next_block_idx(arena, mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v - 1);
	if(block_idx == old_start)
	{
		mk_sl_mallocator_lokal_arena_inl_defd_mem_set_next_block_idx(arena, mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v - 1, old_next);
	}
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_block_reconnect(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_types_usize_t const block_idx) mk_lang_noexcept
{
	mk_lang_types_usize_t old_start mk_lang_constexpr_init;
	mk_lang_types_usize_t old_next mk_lang_constexpr_init;
	mk_lang_types_usize_t old_prev mk_lang_constexpr_init;

	mk_lang_assert(arena);
	mk_lang_assert(block_idx >= mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v);
	mk_lang_assert(block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);

	old_start = mk_sl_mallocator_lokal_arena_inl_defd_mem_get_next_block_idx(arena, mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v - 1);
	old_next = mk_sl_mallocator_lokal_arena_inl_defd_mem_get_next_block_idx(arena, old_start);
	old_prev = mk_sl_mallocator_lokal_arena_inl_defd_mem_get_prev_block_idx(arena, old_next);
	mk_sl_mallocator_lokal_arena_inl_defd_mem_set_next_block_idx(arena, block_idx, old_next);
	mk_sl_mallocator_lokal_arena_inl_defd_mem_set_prev_block_idx(arena, block_idx, old_prev);
	mk_sl_mallocator_lokal_arena_inl_defd_mem_set_prev_block_idx(arena, old_next, block_idx);
	mk_sl_mallocator_lokal_arena_inl_defd_mem_set_next_block_idx(arena, old_prev, block_idx);
	mk_sl_mallocator_lokal_arena_inl_defd_mem_set_next_block_idx(arena, mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v - 1, block_idx);
}


mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_init(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_free_block_t free_block mk_lang_constexpr_init;
	mk_sl_mallocator_lokal_arena_inl_defd_bitmap_t bitmap mk_lang_constexpr_init;
	mk_lang_types_sint_t blocks_allocated mk_lang_constexpr_init;
	mk_lang_types_sint_t words_allocated mk_lang_constexpr_init;
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t full mk_lang_constexpr_init;
	mk_lang_types_sint_t rest mk_lang_constexpr_init;
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_t num mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(arena);

	mk_sl_cui_uint8_memclr_fn(&arena->m_mem.m_data.m_u8s[0], ((mk_lang_types_usize_t)(mk_sl_mallocator_lokal_arena_inl_defd_words_v)) * ((mk_lang_types_usize_t)(mk_sl_mallocator_lokal_arena_inl_defd_num_words_size_bytes_v)));
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_set_zero(&free_block.m_next);
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_set_zero(&free_block.m_prev);
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_set_zero(&free_block.m_blocks_allocated);
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_set_zero(&free_block.m_bytes_allocated);
	mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_store(arena, mk_sl_mallocator_lokal_arena_ver1_blocks_wasted_v - 1, &free_block);
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_set_zero(&num);
	n = mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v;
	for(i = 0; i != n; ++i)
	{
		mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_next_store(arena, i, &num);
		mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_prev_store(arena, i, &num);
	}
	mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_load(arena, &bitmap);
	blocks_allocated = mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v;
	words_allocated = blocks_allocated / mk_sl_mallocator_lokal_arena_inl_defd_num_words_size_bits_v;
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_set_max(&full);
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_memset_fn(&bitmap.m_data.m_words[0], &full, ((mk_lang_types_usize_t)(words_allocated)));
	rest = blocks_allocated - words_allocated * mk_sl_mallocator_lokal_arena_inl_defd_num_words_size_bits_v;
	mk_sl_mallocator_lokal_arena_inl_defd_num_words_set_mask(&bitmap.m_data.m_words[words_allocated], rest);
	mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_store(arena, &bitmap);
	mk_sl_mallocator_lokal_arena_inl_defd_mem_set_next_block_idx(arena, mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v - 1, mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v);
	mk_sl_mallocator_lokal_arena_inl_defd_mem_set_prev_block_idx(arena, mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v, mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v - 1);
	mk_lang_assert(mk_sl_mallocator_lokal_arena_inl_defd_mem_verify(arena));
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_mem_deinit(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena) mk_lang_noexcept
{
	mk_lang_assert(arena);
	mk_lang_assert(mk_sl_mallocator_lokal_arena_inl_defd_mem_verify(arena));
	mk_lang_assert(mk_sl_mallocator_lokal_arena_inl_defd_mem_get_blocks_free(arena) == ((mk_lang_types_usize_t)(mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v)) - ((mk_lang_types_usize_t)(mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v)));
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_allocate_blocks(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_types_usize_t const blocks_count, mk_sl_cui_uint8_ppt const blocks_ptr) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ret mk_lang_constexpr_init;
	mk_sl_mallocator_lokal_arena_inl_defd_bitmap_t bitmap mk_lang_constexpr_init;
	mk_lang_types_usize_t start_idx mk_lang_constexpr_init;
	mk_lang_types_usize_t block_idx mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(blocks_count >= 0);
	mk_lang_assert(blocks_count <= ((mk_lang_types_usize_t)(mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v)) - ((mk_lang_types_usize_t)(mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v)));
	mk_lang_assert(blocks_ptr);
	mk_lang_assert(mk_sl_mallocator_lokal_arena_inl_defd_mem_verify(arena));
	#include "mk_lang_warning_msvc_pop.h"

	ret = mk_lang_null;
	if(blocks_count > 0 && blocks_count <= mk_sl_mallocator_lokal_arena_inl_defd_mem_get_blocks_free(arena))
	{
		mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_load(arena, &bitmap);
		start_idx = mk_sl_mallocator_lokal_arena_inl_defd_mem_get_next_block_idx(arena, mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v - 1);
		block_idx = start_idx;
		for(;;)
		{
			mk_lang_assert(mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_is_block_free(&bitmap, block_idx));
			if(mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_is_blocks_free(&bitmap, block_idx + 1, blocks_count - 1))
			{
				ret = &arena->m_mem.m_data.m_u8s[block_idx * mk_sl_mallocator_lokal_arena_inl_defd_block_v];
				break;
			}
			block_idx = mk_sl_mallocator_lokal_arena_inl_defd_mem_get_next_block_idx(arena, block_idx);
			if(block_idx == start_idx)
			{
				break;
			}
		}
		if(ret)
		{
			mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_mark_blocks_allocated(&bitmap, block_idx, blocks_count);
			n = blocks_count;
			for(i = 0; i != n; ++i)
			{
				mk_sl_mallocator_lokal_arena_inl_defd_mem_block_disconnect(arena, block_idx + i);
			}
			mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_blocks_allocated_inc_by(arena, blocks_count);
			mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_store(arena, &bitmap);
		}
	}
	mk_lang_assert(mk_sl_mallocator_lokal_arena_inl_defd_mem_verify(arena));
	*blocks_ptr = ret;
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_deallocate_blocks(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_sl_cui_uint8_pct const blocks_ptr, mk_lang_types_usize_t const blocks_count) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_arena_inl_defd_bitmap_t bitmap mk_lang_constexpr_init;
	mk_lang_types_usize_t block_idx mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_usize_t idx mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(blocks_ptr || blocks_count == 0);
	mk_lang_assert(blocks_count >= 0);
	mk_lang_assert(blocks_count <= mk_sl_mallocator_lokal_arena_inl_defd_mem_get_blocks_free(arena));
	mk_lang_assert(mk_sl_mallocator_lokal_arena_inl_defd_mem_verify(arena));
	#include "mk_lang_warning_msvc_pop.h"

	if(blocks_count != 0)
	{
		mk_lang_assert(((mk_lang_types_uintptr_t)(blocks_ptr)) % mk_sl_mallocator_lokal_arena_inl_defd_block_v == 0);
		block_idx = ((mk_lang_types_usize_t)(((mk_lang_types_uintptr_t)(blocks_ptr - &arena->m_mem.m_data.m_u8s[0])) / mk_sl_mallocator_lokal_arena_inl_defd_block_v));
		#include "mk_lang_warning_msvc_push_c4296.h"
		mk_lang_assert(block_idx >= 0);
		mk_lang_assert(block_idx < mk_sl_mallocator_lokal_arena_inl_defd_blocks_total_v);
		#include "mk_lang_warning_msvc_pop.h"
		mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_load(arena, &bitmap);
		mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_mark_blocks_free(&bitmap, block_idx, blocks_count);
		mk_sl_mallocator_lokal_arena_inl_defd_mem_bitmap_store(arena, &bitmap);
		n = blocks_count;
		for(i = 0; i != n; ++i)
		{
			idx = (n - 1) - i;
			mk_sl_mallocator_lokal_arena_inl_defd_mem_block_reconnect(arena, block_idx + idx);
		}
		mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_blocks_allocated_dec_by(arena, blocks_count);
	}
	mk_lang_assert(mk_sl_mallocator_lokal_arena_inl_defd_mem_verify(arena));
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_reallocate_blocks(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_sl_cui_uint8_pct const old_blocks_ptr, mk_lang_types_usize_t const old_blocks_count, mk_lang_types_usize_t const new_blocks_count, mk_sl_cui_uint8_ppt const new_blocks_ptr) mk_lang_noexcept
{
	((void)(arena));
	((void)(old_blocks_ptr));
	((void)(old_blocks_count));
	((void)(new_blocks_count));
	((void)(new_blocks_ptr));
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_allocate_bytes(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_types_usize_t const bytes_count, mk_sl_cui_uint8_ppt const bytes_ptr) mk_lang_noexcept
{
	mk_lang_types_usize_t blocks_count mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt blocks_ptr mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(bytes_count >= 0);
	mk_lang_assert(bytes_count < ((mk_lang_types_usize_t)(mk_sl_mallocator_lokal_arena_inl_defd_size)) - ((mk_lang_types_usize_t)(mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v)) * ((mk_lang_types_usize_t)(mk_sl_mallocator_lokal_arena_inl_defd_block_v)));
	mk_lang_assert(bytes_ptr);
	mk_lang_assert(mk_sl_mallocator_lokal_arena_inl_defd_mem_verify(arena));
	#include "mk_lang_warning_msvc_pop.h"

	blocks_count = mk_lang_roundup_div(bytes_count, mk_sl_mallocator_lokal_arena_inl_defd_block_v);
	mk_sl_mallocator_lokal_arena_inl_defd_allocate_blocks(arena, blocks_count, &blocks_ptr);
	if(blocks_ptr)
	{
		mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_bytes_allocated_inc_by(arena, bytes_count);
	}
	*bytes_ptr = blocks_ptr;
	mk_lang_assert(mk_sl_mallocator_lokal_arena_inl_defd_mem_verify(arena));
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_deallocate_bytes(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_sl_cui_uint8_pct const bytes_ptr, mk_lang_types_usize_t const bytes_count) mk_lang_noexcept
{
	mk_lang_types_usize_t blocks_count mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(bytes_ptr || bytes_count == 0);
	mk_lang_assert(bytes_count >= 0);
	mk_lang_assert(bytes_count <= mk_sl_mallocator_lokal_arena_inl_defd_mem_get_bytes_allocated(arena));
	mk_lang_assert(mk_sl_mallocator_lokal_arena_inl_defd_mem_verify(arena));
	#include "mk_lang_warning_msvc_pop.h"

	if(bytes_count != 0)
	{
		blocks_count = mk_lang_roundup_div(bytes_count, mk_sl_mallocator_lokal_arena_inl_defd_block_v);
		mk_sl_mallocator_lokal_arena_inl_defd_deallocate_blocks(arena, bytes_ptr, blocks_count);
		mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_bytes_allocated_dec_by(arena, bytes_count);
	}
	mk_lang_assert(mk_sl_mallocator_lokal_arena_inl_defd_mem_verify(arena));
}

mk_lang_constexpr mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_reallocate_bytes(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_sl_cui_uint8_pct const old_bytes_ptr, mk_lang_types_usize_t const old_bytes_count, mk_lang_types_usize_t const new_bytes_count, mk_sl_cui_uint8_ppt const new_bytes_ptr) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt bytes_ptr mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(old_bytes_count >= 0);
	mk_lang_assert(old_bytes_count <= mk_sl_mallocator_lokal_arena_inl_defd_mem_get_bytes_allocated(arena));
	mk_lang_assert(old_bytes_ptr || old_bytes_count == 0);
	mk_lang_assert(new_bytes_count >= 0);
	mk_lang_assert(new_bytes_count < ((mk_lang_types_usize_t)(mk_sl_mallocator_lokal_arena_inl_defd_size)) - ((mk_lang_types_usize_t)(mk_sl_mallocator_lokal_arena_inl_defd_blocks_wasted_v)) * ((mk_lang_types_usize_t)(mk_sl_mallocator_lokal_arena_inl_defd_block_v)));
	mk_lang_assert(new_bytes_ptr);
	mk_lang_assert(mk_sl_mallocator_lokal_arena_inl_defd_mem_verify(arena));
	#include "mk_lang_warning_msvc_pop.h"

	if(old_bytes_count / mk_sl_mallocator_lokal_arena_inl_defd_block_v == new_bytes_count / mk_sl_mallocator_lokal_arena_inl_defd_block_v)
	{
		mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_bytes_allocated_dec_by(arena, old_bytes_count);
		mk_sl_mallocator_lokal_arena_inl_defd_mem_free_block_bytes_allocated_inc_by(arena, new_bytes_count);
		*new_bytes_ptr = ((mk_sl_cui_uint8_pt)(old_bytes_ptr));
	}
	else
	{
		mk_sl_mallocator_lokal_arena_inl_defd_allocate_bytes(arena, new_bytes_count, &bytes_ptr);
		if(bytes_ptr)
		{
			mk_sl_cui_uint8_memcpy_fn(bytes_ptr, old_bytes_ptr, old_bytes_count);
			mk_sl_mallocator_lokal_arena_inl_defd_deallocate_bytes(arena, old_bytes_ptr, old_bytes_count);
		}
		*new_bytes_ptr = bytes_ptr;
	}
	mk_lang_assert(mk_sl_mallocator_lokal_arena_inl_defd_mem_verify(arena));
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_lokal_arena_inl_defd_init(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena) mk_lang_noexcept
{
	mk_lang_assert(arena);

	mk_sl_mallocator_lokal_arena_inl_defd_mem_init(arena);
	mk_sl_mallocator_lokal_arena_inl_defd_statistics_init(arena);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_lokal_arena_inl_defd_deinit(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena) mk_lang_noexcept
{
	mk_lang_assert(arena);

	mk_sl_mallocator_lokal_arena_inl_defd_statistics_deinit(arena);
	mk_sl_mallocator_lokal_arena_inl_defd_mem_deinit(arena);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_lokal_arena_inl_defd_allocate(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_types_usize_t const size_bytes, mk_lang_types_void_ppt const mem) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt bytes_ptr;
	mk_lang_types_void_pt m;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(size_bytes >= 0);
	mk_lang_assert(mem || size_bytes == 0);
	#include "mk_lang_warning_msvc_pop.h"

	if(size_bytes != 0)
	{
		mk_sl_mallocator_lokal_arena_inl_defd_allocate_bytes(arena, size_bytes, &bytes_ptr);
		m = ((mk_lang_types_void_pt)(bytes_ptr));
		if(m)
		{
			#if mk_sl_mallocator_lokal_arena_inl_defd_statistics_want
			mk_sl_mallocator_lokal_arena_inl_defd_statistics_on_allocated(arena, size_bytes);
			#endif
		}
		*mem = m;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_lokal_arena_inl_defd_deallocate(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_types_void_pct const mem, mk_lang_types_usize_t const size_bytes) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct bytes_ptr;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(arena);
	mk_lang_assert(mem || size_bytes == 0);
	mk_lang_assert(size_bytes >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	if(size_bytes != 0)
	{
		bytes_ptr = ((mk_sl_cui_uint8_pct)(mem));
		mk_sl_mallocator_lokal_arena_inl_defd_deallocate_bytes(arena, bytes_ptr, size_bytes);
		#if mk_sl_mallocator_lokal_arena_inl_defd_statistics_want
		mk_sl_mallocator_lokal_arena_inl_defd_statistics_on_deallocated(arena, size_bytes);
		#endif
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_lokal_arena_inl_defd_reallocate(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_types_void_pct const old_mem, mk_lang_types_usize_t const old_size_bytes, mk_lang_types_usize_t const new_size_bytes, mk_lang_types_void_ppt const new_mem) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct old_bytes;
	mk_sl_cui_uint8_pt bytes_ptr;
	mk_lang_types_void_pt m;

	mk_lang_assert(arena);
	mk_lang_assert(old_mem);
	mk_lang_assert(old_size_bytes >= 1);
	mk_lang_assert(new_size_bytes >= 1);
	mk_lang_assert(new_mem);

	old_bytes = ((mk_sl_cui_uint8_pct)(old_mem));
	mk_sl_mallocator_lokal_arena_inl_defd_reallocate_bytes(arena, old_bytes, old_size_bytes, new_size_bytes, &bytes_ptr);
	m = ((mk_lang_types_void_pt)(bytes_ptr));
	if(m)
	{
		#if mk_sl_mallocator_lokal_arena_inl_defd_statistics_want
		mk_sl_mallocator_lokal_arena_inl_defd_statistics_on_reallocated(arena, old_size_bytes, new_size_bytes);
		#endif
	}
	*new_mem = m;
	return 0;
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_statistics_get_blocks_allocated(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_sl_mallocator_lokal_arena_inl_defd_num_blocks_pt const blocks_allocated) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_arena_inl_defd_statistics_want
	mk_lang_assert(arena);
	mk_lang_assert(blocks_allocated);

	*blocks_allocated = arena->m_statistics.m_blocks_allocated;
#else
	mk_lang_assert(blocks_allocated);
	((mk_lang_types_void_t)(blocks_allocated));
#endif
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_statistics_get_blocks_dealocated(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_sl_mallocator_lokal_arena_inl_defd_num_blocks_pt const blocks_deallocated) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_arena_inl_defd_statistics_want
	mk_lang_assert(arena);
	mk_lang_assert(blocks_deallocated);

	*blocks_deallocated = arena->m_statistics.m_blocks_deallocated;
#else
	mk_lang_assert(blocks_deallocated);
	((mk_lang_types_void_t)(blocks_deallocated));
#endif
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_statistics_get_blocks_peak(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_sl_mallocator_lokal_arena_inl_defd_num_blocks_pt const blocks_peak) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_arena_inl_defd_statistics_want
	mk_lang_assert(arena);
	mk_lang_assert(blocks_peak);

	*blocks_peak = arena->m_statistics.m_blocks_peak;
#else
	mk_lang_assert(blocks_peak);
	((mk_lang_types_void_t)(blocks_peak));
#endif
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_statistics_get_blocks_live(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_sl_mallocator_lokal_arena_inl_defd_num_blocks_pt const blocks_live) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_arena_inl_defd_statistics_want
	mk_lang_assert(arena);
	mk_lang_assert(blocks_live);

	mk_sl_mallocator_lokal_arena_inl_defd_num_blocks_sub3_wrap_cid_cod(&arena->m_statistics.m_blocks_allocated, &arena->m_statistics.m_blocks_deallocated, blocks_live);
#else
	mk_lang_assert(blocks_live);
	((mk_lang_types_void_t)(blocks_live));
#endif
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_statistics_get_bytes_allocated(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_pt const bytes_allocated) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_arena_inl_defd_statistics_want
	mk_lang_assert(arena);
	mk_lang_assert(bytes_allocated);

	*bytes_allocated = arena->m_statistics.m_bytes_allocated;
#else
	mk_lang_assert(bytes_allocated);
	((mk_lang_types_void_t)(bytes_allocated));
#endif
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_statistics_get_bytes_dealocated(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_pt const bytes_deallocated) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_arena_inl_defd_statistics_want
	mk_lang_assert(arena);
	mk_lang_assert(bytes_deallocated);

	*bytes_deallocated = arena->m_statistics.m_bytes_deallocated;
#else
	mk_lang_assert(bytes_deallocated);
	((mk_lang_types_void_t)(bytes_deallocated));
#endif
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_statistics_get_bytes_peak(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_pt const bytes_peak) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_arena_inl_defd_statistics_want
	mk_lang_assert(arena);
	mk_lang_assert(bytes_peak);

	*bytes_peak = arena->m_statistics.m_bytes_peak;
#else
	mk_lang_assert(bytes_peak);
	((mk_lang_types_void_t)(bytes_peak));
#endif
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_statistics_get_bytes_live(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_pt const bytes_live) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_arena_inl_defd_statistics_want
	mk_lang_assert(arena);
	mk_lang_assert(bytes_live);

	mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_sub3_wrap_cid_cod(&arena->m_statistics.m_bytes_allocated, &arena->m_statistics.m_bytes_deallocated, bytes_live);
#else
	mk_lang_assert(bytes_live);
	((mk_lang_types_void_t)(bytes_live));
#endif
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_arena_inl_defd_statistics_get_all(mk_sl_mallocator_lokal_arena_inl_defd_pt const arena, mk_lang_static_param(mk_sl_mallocator_lokal_arena_inl_defd_num_blocks_t, blocks_all, 4), mk_lang_static_param(mk_sl_mallocator_lokal_arena_inl_defd_num_bytes_t, bytes_all, 4)) mk_lang_noexcept
{
	mk_lang_assert(arena);
	mk_lang_assert(blocks_all);
	mk_lang_assert(bytes_all);

	mk_sl_mallocator_lokal_arena_inl_defd_statistics_get_blocks_allocated(arena, &blocks_all[0]);
	mk_sl_mallocator_lokal_arena_inl_defd_statistics_get_blocks_dealocated(arena, &blocks_all[1]);
	mk_sl_mallocator_lokal_arena_inl_defd_statistics_get_blocks_peak(arena, &blocks_all[2]);
	mk_sl_mallocator_lokal_arena_inl_defd_statistics_get_blocks_live(arena, &blocks_all[3]);
	mk_sl_mallocator_lokal_arena_inl_defd_statistics_get_bytes_allocated(arena, &bytes_all[0]);
	mk_sl_mallocator_lokal_arena_inl_defd_statistics_get_bytes_dealocated(arena, &bytes_all[1]);
	mk_sl_mallocator_lokal_arena_inl_defd_statistics_get_bytes_peak(arena, &bytes_all[2]);
	mk_sl_mallocator_lokal_arena_inl_defd_statistics_get_bytes_live(arena, &bytes_all[3]);
}


#include "mk_sl_mallocator_lokal_arena_inl_defu.h"
