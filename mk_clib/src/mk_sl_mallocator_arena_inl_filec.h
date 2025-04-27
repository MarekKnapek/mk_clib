#include "mk_lang_assert.h"
#include "mk_lang_alignas.h"
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


#include "mk_sl_mallocator_arena_inl_defd.h"


#define mk_sl_cui_t_name mk_sl_mallocator_arena_inl_defd_num_blocks_name
#define mk_sl_cui_t_base mk_lang_bui_usize
#define mk_sl_cui_t_count 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_sl_mallocator_arena_inl_defd_num_bytes_name
#define mk_sl_cui_t_base mk_lang_bui_usize
#define mk_sl_cui_t_count 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


struct mk_sl_mallocator_arena_inl_defd_statistics_s
{
	mk_sl_mallocator_arena_inl_defd_num_blocks_t m_blocks_allocated;
	mk_sl_mallocator_arena_inl_defd_num_blocks_t m_blocks_deallocated;
	mk_sl_mallocator_arena_inl_defd_num_blocks_t m_blocks_peak;
	mk_sl_mallocator_arena_inl_defd_num_bytes_t m_bytes_allocated;
	mk_sl_mallocator_arena_inl_defd_num_bytes_t m_bytes_deallocated;
	mk_sl_mallocator_arena_inl_defd_num_bytes_t m_bytes_peak;
};
typedef struct mk_sl_mallocator_arena_inl_defd_statistics_s mk_sl_mallocator_arena_inl_defd_statistics_t;
mk_lang_typedef(mk_sl_mallocator_arena_inl_defd_statistics);


#define mk_sl_cui_t_name mk_sl_mallocator_arena_inl_defd_num_words_name
#define mk_sl_cui_t_base mk_lang_bui_usize
#define mk_sl_cui_t_count 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_lang_memall2_t_name mk_sl_mallocator_arena_inl_defd_num_words_name
#define mk_lang_memall2_t_tn mk_sl_mallocator_arena_inl_defd_num_words_name
#include "mk_lang_memall2_inl_fileh.h"
#include "mk_lang_memall2_inl_filec.h"
#include "mk_lang_memall2_inl_fileu.h"

#define mk_sl_uint_convert_t_name mk_sl_mallocator_arena_inl_defd_convert_name
#define mk_sl_uint_convert_t_big_tn mk_sl_mallocator_arena_inl_defd_num_words_name
#define mk_sl_uint_convert_t_sml_tn mk_sl_cui_uint8
#define mk_sl_uint_convert_t_endian mk_lang_endian_native
#include "mk_sl_uint_convert_inl_fileh.h"
#include "mk_sl_uint_convert_inl_filec.h"
#include "mk_sl_uint_convert_inl_fileu.h"


struct mk_sl_mallocator_arena_inl_defd_free_block_s
{
	mk_sl_mallocator_arena_inl_defd_num_words_t m_next;
	mk_sl_mallocator_arena_inl_defd_num_words_t m_prev;
	mk_sl_mallocator_arena_inl_defd_num_words_t m_blocks_allocated;
	mk_sl_mallocator_arena_inl_defd_num_words_t m_bytes_allocated;
};
typedef struct mk_sl_mallocator_arena_inl_defd_free_block_s mk_sl_mallocator_arena_inl_defd_free_block_t;
mk_lang_typedef(mk_sl_mallocator_arena_inl_defd_free_block);

#define mk_sl_mallocator_arena_inl_defd_block_d 64
enum mk_sl_mallocator_arena_inl_defd_block_u { mk_sl_mallocator_arena_inl_defd_block_v = mk_sl_mallocator_arena_inl_defd_block_d }; typedef enum mk_sl_mallocator_arena_inl_defd_block_u mk_sl_mallocator_arena_inl_defd_block_t;

#define mk_sl_mallocator_arena_inl_defd_blocks_total_d (mk_sl_mallocator_arena_inl_defd_size / mk_sl_mallocator_arena_inl_defd_block_v)
enum mk_sl_mallocator_arena_inl_defd_blocks_total_u { mk_sl_mallocator_arena_inl_defd_blocks_total_v = mk_sl_mallocator_arena_inl_defd_blocks_total_d }; typedef enum mk_sl_mallocator_arena_inl_defd_blocks_total_u mk_sl_mallocator_arena_inl_defd_blocks_total_t;

#define mk_sl_mallocator_arena_inl_defd_words_d ((mk_sl_mallocator_arena_inl_defd_size / mk_sl_mallocator_arena_inl_defd_block_v) / mk_sl_mallocator_arena_inl_defd_num_words_size_bits_v)
enum mk_sl_mallocator_arena_inl_defd_words_u { mk_sl_mallocator_arena_inl_defd_words_v = mk_sl_mallocator_arena_inl_defd_words_d }; typedef enum mk_sl_mallocator_arena_inl_defd_words_u mk_sl_mallocator_arena_inl_defd_words_t;

#define mk_sl_mallocator_arena_inl_defd_blocks_wasted_d mk_lang_roundup_div(((mk_lang_types_usize_t)(mk_sl_mallocator_arena_inl_defd_words_v)) * ((mk_lang_types_usize_t)(mk_sl_mallocator_arena_inl_defd_num_words_size_bytes_v)) + sizeof(mk_sl_mallocator_arena_inl_defd_free_block_t), ((mk_lang_types_usize_t)(mk_sl_mallocator_arena_inl_defd_block_v)))
enum mk_sl_mallocator_arena_inl_defd_blocks_wasted_u { mk_sl_mallocator_arena_inl_defd_blocks_wasted_v = mk_sl_mallocator_arena_inl_defd_blocks_wasted_d }; typedef enum mk_sl_mallocator_arena_inl_defd_blocks_wasted_u mk_sl_mallocator_arena_inl_defd_blocks_wasted_t;

struct mk_sl_mallocator_arena_inl_defd_bitmap_s
{
	mk_sl_mallocator_arena_inl_defd_num_words_t m_words[mk_sl_mallocator_arena_inl_defd_words_v];
};
typedef struct mk_sl_mallocator_arena_inl_defd_bitmap_s mk_sl_mallocator_arena_inl_defd_bitmap_t;
mk_lang_typedef(mk_sl_mallocator_arena_inl_defd_bitmap);

union mk_sl_mallocator_arena_inl_defd_mem_data_u
{
	mk_lang_alignas(mk_sl_mallocator_arena_inl_defd_block_v) mk_sl_cui_uint8_t m_u8s[mk_sl_mallocator_arena_inl_defd_size];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_sl_mallocator_arena_inl_defd_mem_data_u mk_sl_mallocator_arena_inl_defd_mem_data_t;
struct mk_sl_mallocator_arena_inl_defd_mem_s
{
	mk_sl_mallocator_arena_inl_defd_mem_data_t m_data;
};
typedef struct mk_sl_mallocator_arena_inl_defd_mem_s mk_sl_mallocator_arena_inl_defd_mem_t;
mk_lang_typedef(mk_sl_mallocator_arena_inl_defd_mem);


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_sl_mallocator_arena_inl_defd_s
{
	#if mk_sl_mallocator_arena_inl_defd_statistics_want
	mk_sl_mallocator_arena_inl_defd_statistics_t m_statistics;
	#endif
	mk_sl_mallocator_arena_inl_defd_mem_t m_mem;
};
typedef struct mk_sl_mallocator_arena_inl_defd_s mk_sl_mallocator_arena_inl_defd_t;
mk_lang_typedef(mk_sl_mallocator_arena_inl_defd);
#include "mk_lang_warning_msvc_pop.h"


static mk_sl_mallocator_arena_inl_defd_t mk_sl_mallocator_arena_inl_defd_g;


static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_statistics_init(mk_sl_mallocator_arena_inl_defd_statistics_pt const statistics) mk_lang_noexcept
{
#if mk_sl_mallocator_arena_inl_defd_statistics_want
	mk_lang_assert(statistics);

	mk_sl_mallocator_arena_inl_defd_num_blocks_set_zero(&statistics->m_blocks_allocated);
	mk_sl_mallocator_arena_inl_defd_num_blocks_set_zero(&statistics->m_blocks_deallocated);
	mk_sl_mallocator_arena_inl_defd_num_blocks_set_zero(&statistics->m_blocks_peak);
	mk_sl_mallocator_arena_inl_defd_num_bytes_set_zero(&statistics->m_bytes_allocated);
	mk_sl_mallocator_arena_inl_defd_num_bytes_set_zero(&statistics->m_bytes_deallocated);
	mk_sl_mallocator_arena_inl_defd_num_bytes_set_zero(&statistics->m_bytes_peak);
#else
	mk_lang_assert(statistics);
	((mk_lang_types_void_t)(statistics));
#endif
}

static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_statistics_deinit(mk_sl_mallocator_arena_inl_defd_statistics_pt const statistics) mk_lang_noexcept
{
#if mk_sl_mallocator_arena_inl_defd_statistics_want
	mk_lang_assert(statistics);

	mk_sl_mallocator_arena_inl_defd_num_blocks_t blocks_live;
	mk_sl_mallocator_arena_inl_defd_num_bytes_t bytes_live;

	((mk_lang_types_void_t)(statistics));
	mk_sl_mallocator_arena_inl_defd_statistics_get_blocks_live(&blocks_live);
	mk_sl_mallocator_arena_inl_defd_statistics_get_bytes_live(&bytes_live);
	mk_lang_assert(mk_sl_mallocator_arena_inl_defd_num_blocks_is_zero(&blocks_live));
	mk_lang_assert(mk_sl_mallocator_arena_inl_defd_num_bytes_is_zero(&bytes_live));
#else
	mk_lang_assert(statistics);
	((mk_lang_types_void_t)(statistics));
#endif
}

static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_statistics_update_peak(mk_sl_mallocator_arena_inl_defd_statistics_pt const statistics) mk_lang_noexcept
{
#if mk_sl_mallocator_arena_inl_defd_statistics_want
	mk_lang_assert(statistics);

	mk_sl_mallocator_arena_inl_defd_num_blocks_t blocks_live;
	mk_sl_mallocator_arena_inl_defd_num_bytes_t bytes_live;

	mk_sl_mallocator_arena_inl_defd_statistics_get_blocks_live(&blocks_live);
	if(mk_sl_mallocator_arena_inl_defd_num_blocks_gt(&blocks_live, &statistics->m_blocks_peak))
	{
		statistics->m_blocks_peak = blocks_live;
	}
	mk_sl_mallocator_arena_inl_defd_statistics_get_bytes_live(&bytes_live);
	if(mk_sl_mallocator_arena_inl_defd_num_bytes_gt(&bytes_live, &statistics->m_bytes_peak))
	{
		statistics->m_bytes_peak = bytes_live;
	}
#else
	((mk_lang_types_void_t)(statistics));
#endif
}

static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_statistics_allocated(mk_sl_mallocator_arena_inl_defd_statistics_pt const statistics, mk_lang_types_usize_t const size_bytes) mk_lang_noexcept
{
#if mk_sl_mallocator_arena_inl_defd_statistics_want
	mk_sl_mallocator_arena_inl_defd_num_bytes_t bytes;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(statistics);
	mk_lang_assert(size_bytes >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_arena_inl_defd_num_blocks_inc1(&statistics->m_blocks_allocated);
	mk_sl_mallocator_arena_inl_defd_num_bytes_from_bi_usize(&bytes, &size_bytes);
	mk_sl_mallocator_arena_inl_defd_num_bytes_add2_wrap_cid_cod(&statistics->m_bytes_allocated, &bytes);
	mk_sl_mallocator_arena_inl_defd_statistics_update_peak(statistics);
#else
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(statistics);
	mk_lang_assert(size_bytes >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(statistics));
	((mk_lang_types_void_t)(size_bytes));
#endif
}

static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_statistics_deallocated(mk_sl_mallocator_arena_inl_defd_statistics_pt const statistics, mk_lang_types_usize_t const size_bytes) mk_lang_noexcept
{
#if mk_sl_mallocator_arena_inl_defd_statistics_want
	mk_sl_mallocator_arena_inl_defd_num_bytes_t bytes;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(statistics);
	mk_lang_assert(size_bytes >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_arena_inl_defd_num_blocks_inc1(&statistics->m_blocks_deallocated);
	mk_sl_mallocator_arena_inl_defd_num_bytes_from_bi_usize(&bytes, &size_bytes);
	mk_sl_mallocator_arena_inl_defd_num_bytes_add2_wrap_cid_cod(&statistics->m_bytes_deallocated, &bytes);
#else
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(statistics);
	mk_lang_assert(size_bytes >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(statistics));
	((mk_lang_types_void_t)(size_bytes));
#endif
}

static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_statistics_reallocated(mk_sl_mallocator_arena_inl_defd_statistics_pt const statistics, mk_lang_types_usize_t const old_size_bytes, mk_lang_types_usize_t const new_size_bytes) mk_lang_noexcept
{
	mk_lang_assert(statistics);

	mk_sl_mallocator_arena_inl_defd_statistics_allocated(statistics, new_size_bytes);
	mk_sl_mallocator_arena_inl_defd_statistics_deallocated(statistics, old_size_bytes);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_free_block_load(mk_sl_mallocator_arena_inl_defd_mem_pct const mem, mk_lang_types_usize_t const block_idx, mk_sl_mallocator_arena_inl_defd_free_block_pt const free_block) mk_lang_noexcept
{
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	mk_lang_assert(free_block);
	#include "mk_lang_warning_msvc_pop.h"

	byte_idx = block_idx * mk_sl_mallocator_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_arena_inl_defd_convert_to_big(&free_block->m_next, ptr + mk_lang_offsetof(mk_sl_mallocator_arena_inl_defd_free_block_t, m_next));
	mk_sl_mallocator_arena_inl_defd_convert_to_big(&free_block->m_prev, ptr + mk_lang_offsetof(mk_sl_mallocator_arena_inl_defd_free_block_t, m_prev));
	mk_sl_mallocator_arena_inl_defd_convert_to_big(&free_block->m_blocks_allocated, ptr + mk_lang_offsetof(mk_sl_mallocator_arena_inl_defd_free_block_t, m_blocks_allocated));
	mk_sl_mallocator_arena_inl_defd_convert_to_big(&free_block->m_bytes_allocated, ptr + mk_lang_offsetof(mk_sl_mallocator_arena_inl_defd_free_block_t, m_bytes_allocated));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_free_block_store(mk_sl_mallocator_arena_inl_defd_mem_pt const mem, mk_lang_types_usize_t const block_idx, mk_sl_mallocator_arena_inl_defd_free_block_pct const free_block) mk_lang_noexcept
{
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	mk_lang_assert(free_block);
	#include "mk_lang_warning_msvc_pop.h"

	byte_idx = block_idx * mk_sl_mallocator_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_arena_inl_defd_convert_to_sml(&free_block->m_next, ptr + mk_lang_offsetof(mk_sl_mallocator_arena_inl_defd_free_block_t, m_next));
	mk_sl_mallocator_arena_inl_defd_convert_to_sml(&free_block->m_prev, ptr + mk_lang_offsetof(mk_sl_mallocator_arena_inl_defd_free_block_t, m_prev));
	mk_sl_mallocator_arena_inl_defd_convert_to_sml(&free_block->m_blocks_allocated, ptr + mk_lang_offsetof(mk_sl_mallocator_arena_inl_defd_free_block_t, m_blocks_allocated));
	mk_sl_mallocator_arena_inl_defd_convert_to_sml(&free_block->m_bytes_allocated, ptr + mk_lang_offsetof(mk_sl_mallocator_arena_inl_defd_free_block_t, m_bytes_allocated));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_free_block_next_load(mk_sl_mallocator_arena_inl_defd_mem_pct const mem, mk_lang_types_usize_t const block_idx, mk_sl_mallocator_arena_inl_defd_num_words_pt const next) mk_lang_noexcept
{
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	mk_lang_assert(next);
	#include "mk_lang_warning_msvc_pop.h"

	byte_idx = block_idx * mk_sl_mallocator_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_arena_inl_defd_convert_to_big(next, ptr + mk_lang_offsetof(mk_sl_mallocator_arena_inl_defd_free_block_t, m_next));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_free_block_next_store(mk_sl_mallocator_arena_inl_defd_mem_pt const mem, mk_lang_types_usize_t const block_idx, mk_sl_mallocator_arena_inl_defd_num_words_pct const next) mk_lang_noexcept
{
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	mk_lang_assert(next);
	#include "mk_lang_warning_msvc_pop.h"

	byte_idx = block_idx * mk_sl_mallocator_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_arena_inl_defd_convert_to_sml(next, ptr + mk_lang_offsetof(mk_sl_mallocator_arena_inl_defd_free_block_t, m_next));
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_mallocator_arena_inl_defd_mem_get_next_block_idx(mk_sl_mallocator_arena_inl_defd_mem_pct const mem, mk_lang_types_usize_t const block_idx) mk_lang_noexcept
{
	mk_sl_mallocator_arena_inl_defd_num_words_t next_block_idx_num mk_lang_constexpr_init;
	mk_lang_types_usize_t next_block_idx_us mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_arena_inl_defd_mem_free_block_next_load(mem, block_idx, &next_block_idx_num);
	mk_sl_mallocator_arena_inl_defd_num_words_to_bi_usize(&next_block_idx_num, &next_block_idx_us);
	next_block_idx_us = block_idx + 1 + next_block_idx_us;
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(next_block_idx_us >= 0);
	mk_lang_assert(next_block_idx_us < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"
	return next_block_idx_us;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_set_next_block_idx(mk_sl_mallocator_arena_inl_defd_mem_pt const mem, mk_lang_types_usize_t const block_idx, mk_lang_types_usize_t const next_block_idx) mk_lang_noexcept
{
	mk_lang_types_usize_t dif_us mk_lang_constexpr_init;
	mk_sl_mallocator_arena_inl_defd_num_words_t dif_num mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	mk_lang_assert(next_block_idx >= 0);
	mk_lang_assert(next_block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"

	dif_us = next_block_idx - block_idx - 1;
	mk_sl_mallocator_arena_inl_defd_num_words_from_bi_usize(&dif_num, &dif_us);
	mk_sl_mallocator_arena_inl_defd_mem_free_block_next_store(mem, block_idx, &dif_num);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_free_block_prev_load(mk_sl_mallocator_arena_inl_defd_mem_pct const mem, mk_lang_types_usize_t const block_idx, mk_sl_mallocator_arena_inl_defd_num_words_pt const prev) mk_lang_noexcept
{
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	mk_lang_assert(prev);
	#include "mk_lang_warning_msvc_pop.h"

	byte_idx = block_idx * mk_sl_mallocator_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_arena_inl_defd_convert_to_big(prev, ptr + mk_lang_offsetof(mk_sl_mallocator_arena_inl_defd_free_block_t, m_prev));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_free_block_prev_store(mk_sl_mallocator_arena_inl_defd_mem_pt const mem, mk_lang_types_usize_t const block_idx, mk_sl_mallocator_arena_inl_defd_num_words_pct const prev) mk_lang_noexcept
{
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	mk_lang_assert(prev);
	#include "mk_lang_warning_msvc_pop.h"

	byte_idx = block_idx * mk_sl_mallocator_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_arena_inl_defd_convert_to_sml(prev, ptr + mk_lang_offsetof(mk_sl_mallocator_arena_inl_defd_free_block_t, m_prev));
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_mallocator_arena_inl_defd_mem_get_prev_block_idx(mk_sl_mallocator_arena_inl_defd_mem_pct const mem, mk_lang_types_usize_t const block_idx) mk_lang_noexcept
{
	mk_sl_mallocator_arena_inl_defd_num_words_t prev_block_idx_num mk_lang_constexpr_init;
	mk_lang_types_usize_t prev_block_idx_us mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_arena_inl_defd_mem_free_block_prev_load(mem, block_idx, &prev_block_idx_num);
	mk_sl_mallocator_arena_inl_defd_num_words_to_bi_usize(&prev_block_idx_num, &prev_block_idx_us);
	prev_block_idx_us = block_idx - 1 - prev_block_idx_us;
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(prev_block_idx_us >= 0);
	mk_lang_assert(prev_block_idx_us < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"
	return prev_block_idx_us;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_set_prev_block_idx(mk_sl_mallocator_arena_inl_defd_mem_pt const mem, mk_lang_types_usize_t const block_idx, mk_lang_types_usize_t const prev_block_idx) mk_lang_noexcept
{
	mk_lang_types_usize_t dif_us mk_lang_constexpr_init;
	mk_sl_mallocator_arena_inl_defd_num_words_t dif_num mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	mk_lang_assert(prev_block_idx >= 0);
	mk_lang_assert(prev_block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"

	dif_us = block_idx - prev_block_idx - 1;
	mk_sl_mallocator_arena_inl_defd_num_words_from_bi_usize(&dif_num, &dif_us);
	mk_sl_mallocator_arena_inl_defd_mem_free_block_prev_store(mem, block_idx, &dif_num);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_free_block_blocks_allocated_load(mk_sl_mallocator_arena_inl_defd_mem_pct const mem, mk_sl_mallocator_arena_inl_defd_num_words_pt const blocks_allocated) mk_lang_noexcept
{
	mk_lang_types_usize_t block_idx mk_lang_constexpr_init;
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;

	mk_lang_assert(mem);
	mk_lang_assert(blocks_allocated);

	block_idx = mk_sl_mallocator_arena_inl_defd_blocks_wasted_v - 1;
	byte_idx = block_idx * mk_sl_mallocator_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_arena_inl_defd_convert_to_big(blocks_allocated, ptr + mk_lang_offsetof(mk_sl_mallocator_arena_inl_defd_free_block_t, m_blocks_allocated));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_free_block_blocks_allocated_store(mk_sl_mallocator_arena_inl_defd_mem_pt const mem, mk_sl_mallocator_arena_inl_defd_num_words_pct const blocks_allocated) mk_lang_noexcept
{
	mk_lang_types_usize_t block_idx mk_lang_constexpr_init;
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;

	mk_lang_assert(mem);
	mk_lang_assert(blocks_allocated);

	block_idx = mk_sl_mallocator_arena_inl_defd_blocks_wasted_v - 1;
	byte_idx = block_idx * mk_sl_mallocator_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_arena_inl_defd_convert_to_sml(blocks_allocated, ptr + mk_lang_offsetof(mk_sl_mallocator_arena_inl_defd_free_block_t, m_blocks_allocated));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_free_block_bytes_allocated_load(mk_sl_mallocator_arena_inl_defd_mem_pct const mem, mk_sl_mallocator_arena_inl_defd_num_words_pt const bytes_allocated) mk_lang_noexcept
{
	mk_lang_types_usize_t block_idx mk_lang_constexpr_init;
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;

	mk_lang_assert(mem);
	mk_lang_assert(bytes_allocated);

	block_idx = mk_sl_mallocator_arena_inl_defd_blocks_wasted_v - 1;
	byte_idx = block_idx * mk_sl_mallocator_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_arena_inl_defd_convert_to_big(bytes_allocated, ptr + mk_lang_offsetof(mk_sl_mallocator_arena_inl_defd_free_block_t, m_bytes_allocated));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_free_block_bytes_allocated_store(mk_sl_mallocator_arena_inl_defd_mem_pt const mem, mk_sl_mallocator_arena_inl_defd_num_words_pct const bytes_allocated) mk_lang_noexcept
{
	mk_lang_types_usize_t block_idx mk_lang_constexpr_init;
	mk_lang_types_usize_t byte_idx mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;

	mk_lang_assert(mem);
	mk_lang_assert(bytes_allocated);

	block_idx = mk_sl_mallocator_arena_inl_defd_blocks_wasted_v - 1;
	byte_idx = block_idx * mk_sl_mallocator_arena_inl_defd_block_v;
	ptr = &mem->m_data.m_u8s[byte_idx];
	mk_sl_mallocator_arena_inl_defd_convert_to_sml(bytes_allocated, ptr + mk_lang_offsetof(mk_sl_mallocator_arena_inl_defd_free_block_t, m_bytes_allocated));
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_mallocator_arena_inl_defd_mem_get_blocks_allocated(mk_sl_mallocator_arena_inl_defd_mem_pct const mem) mk_lang_noexcept
{
	mk_sl_mallocator_arena_inl_defd_num_words_t blocks_allocated_num mk_lang_constexpr_init;
	mk_lang_types_usize_t blocks_allocated_us mk_lang_constexpr_init;

	mk_lang_assert(mem);

	mk_sl_mallocator_arena_inl_defd_mem_free_block_blocks_allocated_load(mem, &blocks_allocated_num);
	mk_sl_mallocator_arena_inl_defd_num_words_to_bi_usize(&blocks_allocated_num, &blocks_allocated_us);
	return blocks_allocated_us;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_mallocator_arena_inl_defd_mem_get_blocks_free(mk_sl_mallocator_arena_inl_defd_mem_pct const mem) mk_lang_noexcept
{
	mk_lang_types_usize_t blocks_total;
	mk_lang_types_usize_t blocks_wasted;
	mk_lang_types_usize_t blocks_allocated;
	mk_lang_types_usize_t blocks_free;

	mk_lang_assert(mem);

	blocks_total = mk_sl_mallocator_arena_inl_defd_blocks_total_v;
	blocks_wasted = mk_sl_mallocator_arena_inl_defd_blocks_wasted_v;
	blocks_allocated = mk_sl_mallocator_arena_inl_defd_mem_get_blocks_allocated(mem);
	blocks_free = blocks_total - blocks_wasted - blocks_allocated;
	return blocks_free;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_mallocator_arena_inl_defd_mem_get_bytes_allocated(mk_sl_mallocator_arena_inl_defd_mem_pct const mem) mk_lang_noexcept
{
	mk_sl_mallocator_arena_inl_defd_num_words_t bytes_allocated_num mk_lang_constexpr_init;
	mk_lang_types_usize_t bytes_allocated_us mk_lang_constexpr_init;

	mk_lang_assert(mem);

	mk_sl_mallocator_arena_inl_defd_mem_free_block_bytes_allocated_load(mem, &bytes_allocated_num);
	mk_sl_mallocator_arena_inl_defd_num_words_to_bi_usize(&bytes_allocated_num, &bytes_allocated_us);
	return bytes_allocated_us;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_mallocator_arena_inl_defd_mem_get_bytes_free(mk_sl_mallocator_arena_inl_defd_mem_pct const mem) mk_lang_noexcept
{
	mk_lang_types_usize_t bytes_total;
	mk_lang_types_usize_t bytes_wasted;
	mk_lang_types_usize_t bytes_allocated;
	mk_lang_types_usize_t bytes_free;

	mk_lang_assert(mem);

	bytes_total = mk_sl_mallocator_arena_inl_defd_size;
	bytes_wasted = ((mk_lang_types_usize_t)(mk_sl_mallocator_arena_inl_defd_blocks_wasted_v)) * ((mk_lang_types_usize_t)(mk_sl_mallocator_arena_inl_defd_block_v));
	bytes_allocated = mk_sl_mallocator_arena_inl_defd_mem_get_bytes_allocated(mem);
	bytes_free = bytes_total - bytes_wasted - bytes_allocated;
	return bytes_free;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_free_block_blocks_allocated_inc_by(mk_sl_mallocator_arena_inl_defd_mem_pt const mem, mk_lang_types_usize_t const amount) mk_lang_noexcept
{
	mk_sl_mallocator_arena_inl_defd_num_words_t blocks_allocated mk_lang_constexpr_init;
	mk_sl_mallocator_arena_inl_defd_num_words_t tmp mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem);
	mk_lang_assert(amount >= 0);
	mk_lang_assert(amount <= mk_sl_mallocator_arena_inl_defd_mem_get_blocks_free(mem));
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_arena_inl_defd_mem_free_block_blocks_allocated_load(mem, &blocks_allocated);
	mk_sl_mallocator_arena_inl_defd_num_words_from_bi_usize(&tmp, &amount);
	mk_sl_mallocator_arena_inl_defd_num_words_add2_wrap_cid_cod(&blocks_allocated, &tmp);
	mk_sl_mallocator_arena_inl_defd_mem_free_block_blocks_allocated_store(mem, &blocks_allocated);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_free_block_blocks_allocated_dec_by(mk_sl_mallocator_arena_inl_defd_mem_pt const mem, mk_lang_types_usize_t const amount) mk_lang_noexcept
{
	mk_sl_mallocator_arena_inl_defd_num_words_t blocks_allocated mk_lang_constexpr_init;
	mk_sl_mallocator_arena_inl_defd_num_words_t tmp mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem);
	mk_lang_assert(amount >= 0);
	mk_lang_assert(amount <= mk_sl_mallocator_arena_inl_defd_mem_get_blocks_allocated(mem));
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_arena_inl_defd_mem_free_block_blocks_allocated_load(mem, &blocks_allocated);
	mk_sl_mallocator_arena_inl_defd_num_words_from_bi_usize(&tmp, &amount);
	mk_sl_mallocator_arena_inl_defd_num_words_sub2_wrap_cid_cod(&blocks_allocated, &tmp);
	mk_sl_mallocator_arena_inl_defd_mem_free_block_blocks_allocated_store(mem, &blocks_allocated);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_free_block_bytes_allocated_inc_by(mk_sl_mallocator_arena_inl_defd_mem_pt const mem, mk_lang_types_usize_t const amount) mk_lang_noexcept
{
	mk_sl_mallocator_arena_inl_defd_num_words_t bytes_allocated mk_lang_constexpr_init;
	mk_sl_mallocator_arena_inl_defd_num_words_t tmp mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem);
	mk_lang_assert(amount >= 0);
	mk_lang_assert(amount <= mk_sl_mallocator_arena_inl_defd_mem_get_bytes_free(mem));
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_arena_inl_defd_mem_free_block_bytes_allocated_load(mem, &bytes_allocated);
	mk_sl_mallocator_arena_inl_defd_num_words_from_bi_usize(&tmp, &amount);
	mk_sl_mallocator_arena_inl_defd_num_words_add2_wrap_cid_cod(&bytes_allocated, &tmp);
	mk_sl_mallocator_arena_inl_defd_mem_free_block_bytes_allocated_store(mem, &bytes_allocated);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_free_block_bytes_allocated_dec_by(mk_sl_mallocator_arena_inl_defd_mem_pt const mem, mk_lang_types_usize_t const amount) mk_lang_noexcept
{
	mk_sl_mallocator_arena_inl_defd_num_words_t bytes_allocated mk_lang_constexpr_init;
	mk_sl_mallocator_arena_inl_defd_num_words_t tmp mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem);
	mk_lang_assert(amount >= 0);
	mk_lang_assert(amount <= mk_sl_mallocator_arena_inl_defd_mem_get_bytes_allocated(mem));
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_arena_inl_defd_mem_free_block_bytes_allocated_load(mem, &bytes_allocated);
	mk_sl_mallocator_arena_inl_defd_num_words_from_bi_usize(&tmp, &amount);
	mk_sl_mallocator_arena_inl_defd_num_words_sub2_wrap_cid_cod(&bytes_allocated, &tmp);
	mk_sl_mallocator_arena_inl_defd_mem_free_block_bytes_allocated_store(mem, &bytes_allocated);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_bitmap_load(mk_sl_mallocator_arena_inl_defd_mem_pct const mem, mk_sl_mallocator_arena_inl_defd_bitmap_pt const bitmap) mk_lang_noexcept
{
	mk_lang_assert(mem);
	mk_lang_assert(bitmap);

	mk_sl_mallocator_arena_inl_defd_convert_to_big_multi(&bitmap->m_words[0], &mem->m_data.m_u8s[0], mk_sl_mallocator_arena_inl_defd_words_v);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_bitmap_store(mk_sl_mallocator_arena_inl_defd_mem_pt const mem, mk_sl_mallocator_arena_inl_defd_bitmap_pct const bitmap) mk_lang_noexcept
{
	mk_lang_assert(mem);
	mk_lang_assert(bitmap);

	mk_sl_mallocator_arena_inl_defd_convert_to_sml_multi(&bitmap->m_words[0], &mem->m_data.m_u8s[0], mk_sl_mallocator_arena_inl_defd_words_v);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_mallocator_arena_inl_defd_mem_bitmap_is_block_free(mk_sl_mallocator_arena_inl_defd_bitmap_pct const bitmap, mk_lang_types_usize_t const block_idx) mk_lang_noexcept
{
	mk_lang_types_usize_t idx_big mk_lang_constexpr_init;
	mk_lang_types_usize_t idx_sml mk_lang_constexpr_init;
	mk_lang_types_bool_t is_allocated mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(bitmap);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"

	idx_big = block_idx / mk_sl_mallocator_arena_inl_defd_num_words_size_bits_v;
	idx_sml = block_idx % mk_sl_mallocator_arena_inl_defd_num_words_size_bits_v;
	is_allocated = mk_sl_mallocator_arena_inl_defd_num_words_is_bit(&bitmap->m_words[idx_big], ((mk_lang_types_sint_t)(idx_sml)));
	return !is_allocated;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_mallocator_arena_inl_defd_mem_bitmap_is_blocks_free(mk_sl_mallocator_arena_inl_defd_bitmap_pct const bitmap, mk_lang_types_usize_t const block_idx, mk_lang_types_usize_t const blocks_count) mk_lang_noexcept
{
	mk_lang_types_bool_t is_free mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(bitmap);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx <= mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	mk_lang_assert(blocks_count >= 0);
	mk_lang_assert(blocks_count < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"

	is_free = mk_lang_true;
	if(blocks_count != 0)
	{
		is_free = mk_lang_false;
		if(!(block_idx == mk_sl_mallocator_arena_inl_defd_blocks_total_v || block_idx + blocks_count >= mk_sl_mallocator_arena_inl_defd_blocks_total_v))
		{
			n = blocks_count;
			for(i = 0; i != n; ++i)
			{
				if(!mk_sl_mallocator_arena_inl_defd_mem_bitmap_is_block_free(bitmap, block_idx + i))
				{
					break;
				}
			}
			is_free = i == n;
		}
	}
	return is_free;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_bitmap_mark_block_free(mk_sl_mallocator_arena_inl_defd_bitmap_pt const bitmap, mk_lang_types_usize_t const block_idx) mk_lang_noexcept
{
	mk_lang_types_usize_t idx_big mk_lang_constexpr_init;
	mk_lang_types_usize_t idx_sml mk_lang_constexpr_init;
	mk_sl_mallocator_arena_inl_defd_num_words_t tmp mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(bitmap);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"

	idx_big = block_idx / mk_sl_mallocator_arena_inl_defd_num_words_size_bits_v;
	idx_sml = block_idx % mk_sl_mallocator_arena_inl_defd_num_words_size_bits_v;
	mk_sl_mallocator_arena_inl_defd_num_words_set_bit(&tmp, ((mk_lang_types_sint_t)(idx_sml)));
	mk_sl_mallocator_arena_inl_defd_num_words_not1(&tmp);
	mk_sl_mallocator_arena_inl_defd_num_words_and2(&bitmap->m_words[idx_big], &tmp);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_bitmap_mark_blocks_free(mk_sl_mallocator_arena_inl_defd_bitmap_pt const bitmap, mk_lang_types_usize_t const block_idx, mk_lang_types_usize_t const blocks_count) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(bitmap);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	mk_lang_assert(blocks_count >= 0);
	mk_lang_assert(blocks_count <= mk_sl_mallocator_arena_inl_defd_blocks_total_v - block_idx);
	#include "mk_lang_warning_msvc_pop.h"

	n = blocks_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_mallocator_arena_inl_defd_mem_bitmap_mark_block_free(bitmap, block_idx + i);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_bitmap_mark_block_allocated(mk_sl_mallocator_arena_inl_defd_bitmap_pt const bitmap, mk_lang_types_usize_t const block_idx) mk_lang_noexcept
{
	mk_lang_types_usize_t idx_big mk_lang_constexpr_init;
	mk_lang_types_usize_t idx_sml mk_lang_constexpr_init;
	mk_sl_mallocator_arena_inl_defd_num_words_t tmp mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(bitmap);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	#include "mk_lang_warning_msvc_pop.h"

	idx_big = block_idx / mk_sl_mallocator_arena_inl_defd_num_words_size_bits_v;
	idx_sml = block_idx % mk_sl_mallocator_arena_inl_defd_num_words_size_bits_v;
	mk_sl_mallocator_arena_inl_defd_num_words_set_bit(&tmp, ((mk_lang_types_sint_t)(idx_sml)));
	mk_sl_mallocator_arena_inl_defd_num_words_or2(&bitmap->m_words[idx_big], &tmp);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_bitmap_mark_blocks_allocated(mk_sl_mallocator_arena_inl_defd_bitmap_pt const bitmap, mk_lang_types_usize_t const block_idx, mk_lang_types_usize_t const blocks_count) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(bitmap);
	mk_lang_assert(block_idx >= 0);
	mk_lang_assert(block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
	mk_lang_assert(blocks_count >= 0);
	mk_lang_assert(blocks_count <= mk_sl_mallocator_arena_inl_defd_blocks_total_v - block_idx);
	#include "mk_lang_warning_msvc_pop.h"

	n = blocks_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_mallocator_arena_inl_defd_mem_bitmap_mark_block_allocated(bitmap, block_idx + i);
	}
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_mallocator_arena_inl_defd_mem_verify(mk_sl_mallocator_arena_inl_defd_mem_pt const mem) mk_lang_noexcept
{
#if mk_sl_mallocator_arena_inl_defd_verify_want
	mk_lang_types_usize_t blocks_free mk_lang_constexpr_init;
	mk_sl_mallocator_arena_inl_defd_bitmap_t bitmap mk_lang_constexpr_init;
	mk_lang_types_usize_t start_idx mk_lang_constexpr_init;
	mk_lang_types_usize_t block_idx mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_usize_t next mk_lang_constexpr_init;
	mk_lang_types_usize_t prev mk_lang_constexpr_init;

	mk_lang_assert(mem);

	blocks_free = mk_sl_mallocator_arena_inl_defd_mem_get_blocks_free(mem);
	if(blocks_free != 0)
	{
		mk_sl_mallocator_arena_inl_defd_mem_bitmap_load(mem, &bitmap);
		start_idx = mk_sl_mallocator_arena_inl_defd_mem_get_next_block_idx(mem, mk_sl_mallocator_arena_inl_defd_blocks_wasted_v - 1);
		block_idx = start_idx;
		n = blocks_free;
		for(i = 0; i != n; ++i)
		{
			mk_lang_assert(mk_sl_mallocator_arena_inl_defd_mem_bitmap_is_block_free(&bitmap, block_idx));
			next = mk_sl_mallocator_arena_inl_defd_mem_get_next_block_idx(mem, block_idx);
			prev = mk_sl_mallocator_arena_inl_defd_mem_get_prev_block_idx(mem, next);
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

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_block_disconnect(mk_sl_mallocator_arena_inl_defd_mem_pt const mem, mk_lang_types_usize_t const block_idx) mk_lang_noexcept
{
	mk_lang_types_usize_t old_next mk_lang_constexpr_init;
	mk_lang_types_usize_t old_prev mk_lang_constexpr_init;
	mk_lang_types_usize_t old_start mk_lang_constexpr_init;

	mk_lang_assert(mem);
	mk_lang_assert(block_idx >= mk_sl_mallocator_arena_inl_defd_blocks_wasted_v);
	mk_lang_assert(block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);

	old_next = mk_sl_mallocator_arena_inl_defd_mem_get_next_block_idx(mem, block_idx);
	old_prev = mk_sl_mallocator_arena_inl_defd_mem_get_prev_block_idx(mem, block_idx);
	mk_sl_mallocator_arena_inl_defd_mem_set_next_block_idx(mem, old_prev, old_next);
	mk_sl_mallocator_arena_inl_defd_mem_set_prev_block_idx(mem, old_next, old_prev);
	old_start = mk_sl_mallocator_arena_inl_defd_mem_get_next_block_idx(mem, mk_sl_mallocator_arena_inl_defd_blocks_wasted_v - 1);
	if(block_idx == old_start)
	{
		mk_sl_mallocator_arena_inl_defd_mem_set_next_block_idx(mem, mk_sl_mallocator_arena_inl_defd_blocks_wasted_v - 1, old_next);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_block_reconnect(mk_sl_mallocator_arena_inl_defd_mem_pt const mem, mk_lang_types_usize_t const block_idx) mk_lang_noexcept
{
	mk_lang_types_usize_t old_start mk_lang_constexpr_init;
	mk_lang_types_usize_t old_next mk_lang_constexpr_init;
	mk_lang_types_usize_t old_prev mk_lang_constexpr_init;

	mk_lang_assert(mem);
	mk_lang_assert(block_idx >= mk_sl_mallocator_arena_inl_defd_blocks_wasted_v);
	mk_lang_assert(block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);

	old_start = mk_sl_mallocator_arena_inl_defd_mem_get_next_block_idx(mem, mk_sl_mallocator_arena_inl_defd_blocks_wasted_v - 1);
	old_next = mk_sl_mallocator_arena_inl_defd_mem_get_next_block_idx(mem, old_start);
	old_prev = mk_sl_mallocator_arena_inl_defd_mem_get_prev_block_idx(mem, old_next);
	mk_sl_mallocator_arena_inl_defd_mem_set_next_block_idx(mem, block_idx, old_next);
	mk_sl_mallocator_arena_inl_defd_mem_set_prev_block_idx(mem, block_idx, old_prev);
	mk_sl_mallocator_arena_inl_defd_mem_set_prev_block_idx(mem, old_next, block_idx);
	mk_sl_mallocator_arena_inl_defd_mem_set_next_block_idx(mem, old_prev, block_idx);
	mk_sl_mallocator_arena_inl_defd_mem_set_next_block_idx(mem, mk_sl_mallocator_arena_inl_defd_blocks_wasted_v - 1, block_idx);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_init(mk_sl_mallocator_arena_inl_defd_mem_pt const mem) mk_lang_noexcept
{
	mk_sl_mallocator_arena_inl_defd_bitmap_t bitmap mk_lang_constexpr_init;
	mk_lang_types_sint_t blocks_allocated mk_lang_constexpr_init;
	mk_lang_types_sint_t words_allocated mk_lang_constexpr_init;
	mk_sl_mallocator_arena_inl_defd_num_words_t full mk_lang_constexpr_init;
	mk_lang_types_sint_t rest mk_lang_constexpr_init;
	mk_sl_mallocator_arena_inl_defd_num_words_t num mk_lang_constexpr_init;

	mk_lang_assert(mem);

	mk_sl_mallocator_arena_inl_defd_mem_bitmap_load(mem, &bitmap);
	blocks_allocated = mk_sl_mallocator_arena_inl_defd_blocks_wasted_v;
	words_allocated = blocks_allocated / mk_sl_mallocator_arena_inl_defd_num_words_size_bits_v;
	mk_sl_mallocator_arena_inl_defd_num_words_set_max(&full);
	mk_sl_mallocator_arena_inl_defd_num_words_memset_fn(&bitmap.m_words[0], &full, ((mk_lang_types_usize_t)(words_allocated)));
	rest = blocks_allocated - words_allocated * mk_sl_mallocator_arena_inl_defd_num_words_size_bits_v;
	mk_sl_mallocator_arena_inl_defd_num_words_set_mask(&bitmap.m_words[words_allocated], rest);
	mk_sl_mallocator_arena_inl_defd_mem_bitmap_store(mem, &bitmap);
	mk_sl_mallocator_arena_inl_defd_mem_free_block_next_load(mem, mk_sl_mallocator_arena_inl_defd_blocks_total_v - 1, &num);
	if(mk_sl_mallocator_arena_inl_defd_num_words_is_zero(&num))
	{
		mk_sl_mallocator_arena_inl_defd_mem_set_next_block_idx(mem, mk_sl_mallocator_arena_inl_defd_blocks_total_v - 1, mk_sl_mallocator_arena_inl_defd_blocks_wasted_v);
		mk_sl_mallocator_arena_inl_defd_mem_set_prev_block_idx(mem, mk_sl_mallocator_arena_inl_defd_blocks_wasted_v, mk_sl_mallocator_arena_inl_defd_blocks_total_v - 1);
	}
	mk_lang_assert(mk_sl_mallocator_arena_inl_defd_mem_verify(mem));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_mem_deinit(mk_sl_mallocator_arena_inl_defd_mem_pt const mem) mk_lang_noexcept
{
	mk_lang_assert(mem);
	mk_lang_assert(mk_sl_mallocator_arena_inl_defd_mem_verify(mem));
	mk_lang_assert(mk_sl_mallocator_arena_inl_defd_mem_get_blocks_free(mem) == ((mk_lang_types_usize_t)(mk_sl_mallocator_arena_inl_defd_blocks_total_v)) - ((mk_lang_types_usize_t)(mk_sl_mallocator_arena_inl_defd_blocks_wasted_v)));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_allocate_blocks(mk_sl_mallocator_arena_inl_defd_mem_pt const mem, mk_lang_types_usize_t const blocks_count, mk_sl_cui_uint8_ppt const blocks_ptr) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ret mk_lang_constexpr_init;
	mk_sl_mallocator_arena_inl_defd_bitmap_t bitmap mk_lang_constexpr_init;
	mk_lang_types_usize_t start_idx mk_lang_constexpr_init;
	mk_lang_types_usize_t block_idx mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem);
	mk_lang_assert(blocks_count >= 0);
	mk_lang_assert(blocks_count <= ((mk_lang_types_usize_t)(mk_sl_mallocator_arena_inl_defd_blocks_total_v)) - ((mk_lang_types_usize_t)(mk_sl_mallocator_arena_inl_defd_blocks_wasted_v)));
	mk_lang_assert(blocks_ptr);
	mk_lang_assert(mk_sl_mallocator_arena_inl_defd_mem_verify(mem));
	#include "mk_lang_warning_msvc_pop.h"

	ret = mk_lang_null;
	if(blocks_count > 0 && blocks_count <= mk_sl_mallocator_arena_inl_defd_mem_get_blocks_free(mem))
	{
		mk_sl_mallocator_arena_inl_defd_mem_bitmap_load(mem, &bitmap);
		start_idx = mk_sl_mallocator_arena_inl_defd_mem_get_next_block_idx(mem, mk_sl_mallocator_arena_inl_defd_blocks_wasted_v - 1);
		block_idx = start_idx;
		for(;;)
		{
			mk_lang_assert(mk_sl_mallocator_arena_inl_defd_mem_bitmap_is_block_free(&bitmap, block_idx));
			if(mk_sl_mallocator_arena_inl_defd_mem_bitmap_is_blocks_free(&bitmap, block_idx + 1, blocks_count - 1))
			{
				ret = &mem->m_data.m_u8s[block_idx * mk_sl_mallocator_arena_inl_defd_block_v];
				break;
			}
			block_idx = mk_sl_mallocator_arena_inl_defd_mem_get_next_block_idx(mem, block_idx);
			if(block_idx == start_idx)
			{
				break;
			}
		}
		if(ret)
		{
			mk_sl_mallocator_arena_inl_defd_mem_bitmap_mark_blocks_allocated(&bitmap, block_idx, blocks_count);
			n = blocks_count;
			for(i = 0; i != n; ++i)
			{
				mk_sl_mallocator_arena_inl_defd_mem_block_disconnect(mem, block_idx + i);
			}
			mk_sl_mallocator_arena_inl_defd_mem_free_block_blocks_allocated_inc_by(mem, blocks_count);
			mk_sl_mallocator_arena_inl_defd_mem_bitmap_store(mem, &bitmap);
		}
	}
	mk_lang_assert(mk_sl_mallocator_arena_inl_defd_mem_verify(mem));
	*blocks_ptr = ret;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_deallocate_blocks(mk_sl_mallocator_arena_inl_defd_mem_pt const mem, mk_sl_cui_uint8_pct const blocks_ptr, mk_lang_types_usize_t const blocks_count) mk_lang_noexcept
{
	mk_sl_mallocator_arena_inl_defd_bitmap_t bitmap mk_lang_constexpr_init;
	mk_lang_types_usize_t block_idx mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_usize_t idx mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem);
	mk_lang_assert(blocks_ptr || blocks_count == 0);
	mk_lang_assert(blocks_count >= 0);
	mk_lang_assert(blocks_count <= mk_sl_mallocator_arena_inl_defd_mem_get_blocks_free(mem));
	mk_lang_assert(mk_sl_mallocator_arena_inl_defd_mem_verify(mem));
	#include "mk_lang_warning_msvc_pop.h"

	if(blocks_count != 0)
	{
		mk_lang_assert(((mk_lang_types_uintptr_t)(blocks_ptr)) % mk_sl_mallocator_arena_inl_defd_block_v == 0);
		block_idx = ((mk_lang_types_usize_t)(((mk_lang_types_uintptr_t)(blocks_ptr - &mem->m_data.m_u8s[0])) / mk_sl_mallocator_arena_inl_defd_block_v));
		#include "mk_lang_warning_msvc_push_c4296.h"
		mk_lang_assert(block_idx >= 0);
		mk_lang_assert(block_idx < mk_sl_mallocator_arena_inl_defd_blocks_total_v);
		#include "mk_lang_warning_msvc_pop.h"
		mk_sl_mallocator_arena_inl_defd_mem_bitmap_load(mem, &bitmap);
		mk_sl_mallocator_arena_inl_defd_mem_bitmap_mark_blocks_free(&bitmap, block_idx, blocks_count);
		mk_sl_mallocator_arena_inl_defd_mem_bitmap_store(mem, &bitmap);
		n = blocks_count;
		for(i = 0; i != n; ++i)
		{
			idx = (n - 1) - i;
			mk_sl_mallocator_arena_inl_defd_mem_block_reconnect(mem, block_idx + idx);
		}
		mk_sl_mallocator_arena_inl_defd_mem_free_block_blocks_allocated_dec_by(mem, blocks_count);
	}
	mk_lang_assert(mk_sl_mallocator_arena_inl_defd_mem_verify(mem));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_allocate_bytes(mk_sl_mallocator_arena_inl_defd_mem_pt const mem, mk_lang_types_usize_t const bytes_count, mk_sl_cui_uint8_ppt const bytes_ptr) mk_lang_noexcept
{
	mk_lang_types_usize_t blocks_count;
	mk_sl_cui_uint8_pt blocks_ptr;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem);
	mk_lang_assert(bytes_count >= 0);
	mk_lang_assert(bytes_count < ((mk_lang_types_usize_t)(mk_sl_mallocator_arena_inl_defd_size)) - ((mk_lang_types_usize_t)(mk_sl_mallocator_arena_inl_defd_blocks_wasted_v)) * ((mk_lang_types_usize_t)(mk_sl_mallocator_arena_inl_defd_block_v)));
	mk_lang_assert(bytes_ptr);
	mk_lang_assert(mk_sl_mallocator_arena_inl_defd_mem_verify(mem));
	#include "mk_lang_warning_msvc_pop.h"

	blocks_count = mk_lang_roundup_div(bytes_count, mk_sl_mallocator_arena_inl_defd_block_v);
	mk_sl_mallocator_arena_inl_defd_allocate_blocks(mem, blocks_count, &blocks_ptr);
	if(blocks_ptr)
	{
		mk_sl_mallocator_arena_inl_defd_mem_free_block_bytes_allocated_inc_by(mem, bytes_count);
	}
	*bytes_ptr = blocks_ptr;
	mk_lang_assert(mk_sl_mallocator_arena_inl_defd_mem_verify(mem));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_deallocate_bytes(mk_sl_mallocator_arena_inl_defd_mem_pt const mem, mk_sl_cui_uint8_pct const bytes_ptr, mk_lang_types_usize_t const bytes_count) mk_lang_noexcept
{
	mk_lang_types_usize_t blocks_count mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem);
	mk_lang_assert(bytes_ptr || bytes_count == 0);
	mk_lang_assert(bytes_count >= 0);
	mk_lang_assert(bytes_count <= mk_sl_mallocator_arena_inl_defd_mem_get_bytes_allocated(mem));
	mk_lang_assert(mk_sl_mallocator_arena_inl_defd_mem_verify(mem));
	#include "mk_lang_warning_msvc_pop.h"

	if(bytes_count != 0)
	{
		blocks_count = mk_lang_roundup_div(bytes_count, mk_sl_mallocator_arena_inl_defd_block_v);
		mk_sl_mallocator_arena_inl_defd_deallocate_blocks(mem, bytes_ptr, blocks_count);
		mk_sl_mallocator_arena_inl_defd_mem_free_block_bytes_allocated_dec_by(mem, bytes_count);
	}
	mk_lang_assert(mk_sl_mallocator_arena_inl_defd_mem_verify(mem));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_reallocate_bytes(mk_sl_mallocator_arena_inl_defd_mem_pt const mem, mk_sl_cui_uint8_pct const old_bytes_ptr, mk_lang_types_usize_t const old_bytes_count, mk_lang_types_usize_t const new_bytes_count, mk_sl_cui_uint8_ppt const new_bytes_ptr) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt bytes_ptr mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem);
	mk_lang_assert(old_bytes_count >= 0);
	mk_lang_assert(old_bytes_count <= mk_sl_mallocator_arena_inl_defd_mem_get_bytes_allocated(mem));
	mk_lang_assert(old_bytes_ptr || old_bytes_count == 0);
	mk_lang_assert(new_bytes_count >= 0);
	mk_lang_assert(new_bytes_count < ((mk_lang_types_usize_t)(mk_sl_mallocator_arena_inl_defd_size)) - ((mk_lang_types_usize_t)(mk_sl_mallocator_arena_inl_defd_blocks_wasted_v)) * ((mk_lang_types_usize_t)(mk_sl_mallocator_arena_inl_defd_block_v)));
	mk_lang_assert(new_bytes_ptr);
	mk_lang_assert(mk_sl_mallocator_arena_inl_defd_mem_verify(mem));
	#include "mk_lang_warning_msvc_pop.h"

	if(old_bytes_count / mk_sl_mallocator_arena_inl_defd_block_v == new_bytes_count / mk_sl_mallocator_arena_inl_defd_block_v)
	{
		mk_sl_mallocator_arena_inl_defd_mem_free_block_bytes_allocated_dec_by(mem, old_bytes_count);
		mk_sl_mallocator_arena_inl_defd_mem_free_block_bytes_allocated_inc_by(mem, new_bytes_count);
		*new_bytes_ptr = ((mk_sl_cui_uint8_pt)(old_bytes_ptr));
	}
	else
	{
		mk_sl_mallocator_arena_inl_defd_allocate_bytes(mem, new_bytes_count, &bytes_ptr);
		if(bytes_ptr)
		{
			mk_sl_cui_uint8_memcpy_fn(bytes_ptr, old_bytes_ptr, old_bytes_count);
			mk_sl_mallocator_arena_inl_defd_deallocate_bytes(mem, old_bytes_ptr, old_bytes_count);
		}
		*new_bytes_ptr = bytes_ptr;
	}
	mk_lang_assert(mk_sl_mallocator_arena_inl_defd_mem_verify(mem));
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_arena_inl_defd_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_sl_mallocator_arena_inl_defd_mem_init(&mk_sl_mallocator_arena_inl_defd_g.m_mem);
	#if mk_sl_mallocator_arena_inl_defd_statistics_want
	mk_sl_mallocator_arena_inl_defd_statistics_init(&mk_sl_mallocator_arena_inl_defd_g.m_statistics);
	#endif
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_arena_inl_defd_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	#if mk_sl_mallocator_arena_inl_defd_statistics_want
	mk_sl_mallocator_arena_inl_defd_statistics_deinit(&mk_sl_mallocator_arena_inl_defd_g.m_statistics);
	#endif
	mk_sl_mallocator_arena_inl_defd_mem_deinit(&mk_sl_mallocator_arena_inl_defd_g.m_mem);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_arena_inl_defd_allocate(mk_lang_types_usize_t const size_bytes, mk_lang_types_void_ppt const mem) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt bytes_ptr;
	mk_lang_types_void_pt m;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(size_bytes >= 0);
	mk_lang_assert(mem || size_bytes == 0);
	#include "mk_lang_warning_msvc_pop.h"

	if(size_bytes != 0)
	{
		mk_sl_mallocator_arena_inl_defd_allocate_bytes(&mk_sl_mallocator_arena_inl_defd_g.m_mem, size_bytes, &bytes_ptr);
		m = ((mk_lang_types_void_pt)(bytes_ptr));
		if(m)
		{
			#if mk_sl_mallocator_arena_inl_defd_statistics_want
			mk_sl_mallocator_arena_inl_defd_statistics_allocated(&mk_sl_mallocator_arena_inl_defd_g.m_statistics, size_bytes);
			#endif
		}
		*mem = m;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_arena_inl_defd_deallocate(mk_lang_types_void_pct const mem, mk_lang_types_usize_t const size_bytes) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct bytes_ptr;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem || size_bytes == 0);
	mk_lang_assert(size_bytes >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	if(size_bytes != 0)
	{
		bytes_ptr = ((mk_sl_cui_uint8_pct)(mem));
		mk_sl_mallocator_arena_inl_defd_deallocate_bytes(&mk_sl_mallocator_arena_inl_defd_g.m_mem, bytes_ptr, size_bytes);
		#if mk_sl_mallocator_arena_inl_defd_statistics_want
		mk_sl_mallocator_arena_inl_defd_statistics_deallocated(&mk_sl_mallocator_arena_inl_defd_g.m_statistics, size_bytes);
		#endif
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_arena_inl_defd_reallocate(mk_lang_types_void_pct const old_mem, mk_lang_types_usize_t const old_size_bytes, mk_lang_types_usize_t const new_size_bytes, mk_lang_types_void_ppt const new_mem) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct old_bytes;
	mk_sl_cui_uint8_pt bytes_ptr;
	mk_lang_types_void_pt m;

	mk_lang_assert(old_mem);
	mk_lang_assert(old_size_bytes >= 1);
	mk_lang_assert(new_size_bytes >= 1);
	mk_lang_assert(new_mem);

	old_bytes = ((mk_sl_cui_uint8_pct)(old_mem));
	mk_sl_mallocator_arena_inl_defd_reallocate_bytes(&mk_sl_mallocator_arena_inl_defd_g.m_mem, old_bytes, old_size_bytes, new_size_bytes, &bytes_ptr);
	m = ((mk_lang_types_void_pt)(bytes_ptr));
	if(m)
	{
		#if mk_sl_mallocator_arena_inl_defd_statistics_want
		mk_sl_mallocator_arena_inl_defd_statistics_reallocated(&mk_sl_mallocator_arena_inl_defd_g.m_statistics, old_size_bytes, new_size_bytes);
		#endif
	}
	*new_mem = m;
	return 0;
}


mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_statistics_get_blocks_allocated(mk_sl_mallocator_arena_inl_defd_num_blocks_pt const blocks_allocated) mk_lang_noexcept
{
#if mk_sl_mallocator_arena_inl_defd_statistics_want
	mk_lang_assert(blocks_allocated);

	*blocks_allocated = mk_sl_mallocator_arena_inl_defd_g.m_statistics.m_blocks_allocated;
#else
	mk_lang_assert(blocks_allocated);
	((mk_lang_types_void_t)(blocks_allocated));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_statistics_get_blocks_dealocated(mk_sl_mallocator_arena_inl_defd_num_blocks_pt const blocks_deallocated) mk_lang_noexcept
{
#if mk_sl_mallocator_arena_inl_defd_statistics_want
	mk_lang_assert(blocks_deallocated);

	*blocks_deallocated = mk_sl_mallocator_arena_inl_defd_g.m_statistics.m_blocks_deallocated;
#else
	mk_lang_assert(blocks_deallocated);
	((mk_lang_types_void_t)(blocks_deallocated));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_statistics_get_blocks_peak(mk_sl_mallocator_arena_inl_defd_num_blocks_pt const blocks_peak) mk_lang_noexcept
{
#if mk_sl_mallocator_arena_inl_defd_statistics_want
	mk_lang_assert(blocks_peak);

	*blocks_peak = mk_sl_mallocator_arena_inl_defd_g.m_statistics.m_blocks_peak;
#else
	mk_lang_assert(blocks_peak);
	((mk_lang_types_void_t)(blocks_peak));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_statistics_get_blocks_live(mk_sl_mallocator_arena_inl_defd_num_blocks_pt const blocks_live) mk_lang_noexcept
{
#if mk_sl_mallocator_arena_inl_defd_statistics_want
	mk_lang_assert(blocks_live);

	mk_sl_mallocator_arena_inl_defd_num_blocks_sub3_wrap_cid_cod(&mk_sl_mallocator_arena_inl_defd_g.m_statistics.m_blocks_allocated, &mk_sl_mallocator_arena_inl_defd_g.m_statistics.m_blocks_deallocated, blocks_live);
#else
	mk_lang_assert(blocks_live);
	((mk_lang_types_void_t)(blocks_live));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_statistics_get_bytes_allocated(mk_sl_mallocator_arena_inl_defd_num_bytes_pt const bytes_allocated) mk_lang_noexcept
{
#if mk_sl_mallocator_arena_inl_defd_statistics_want
	mk_lang_assert(bytes_allocated);

	*bytes_allocated = mk_sl_mallocator_arena_inl_defd_g.m_statistics.m_bytes_allocated;
#else
	mk_lang_assert(bytes_allocated);
	((mk_lang_types_void_t)(bytes_allocated));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_statistics_get_bytes_dealocated(mk_sl_mallocator_arena_inl_defd_num_bytes_pt const bytes_deallocated) mk_lang_noexcept
{
#if mk_sl_mallocator_arena_inl_defd_statistics_want
	mk_lang_assert(bytes_deallocated);

	*bytes_deallocated = mk_sl_mallocator_arena_inl_defd_g.m_statistics.m_bytes_deallocated;
#else
	mk_lang_assert(bytes_deallocated);
	((mk_lang_types_void_t)(bytes_deallocated));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_statistics_get_bytes_peak(mk_sl_mallocator_arena_inl_defd_num_bytes_pt const bytes_peak) mk_lang_noexcept
{
#if mk_sl_mallocator_arena_inl_defd_statistics_want
	mk_lang_assert(bytes_peak);

	*bytes_peak = mk_sl_mallocator_arena_inl_defd_g.m_statistics.m_bytes_peak;
#else
	mk_lang_assert(bytes_peak);
	((mk_lang_types_void_t)(bytes_peak));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_statistics_get_bytes_live(mk_sl_mallocator_arena_inl_defd_num_bytes_pt const bytes_live) mk_lang_noexcept
{
#if mk_sl_mallocator_arena_inl_defd_statistics_want
	mk_lang_assert(bytes_live);

	mk_sl_mallocator_arena_inl_defd_num_bytes_sub3_wrap_cid_cod(&mk_sl_mallocator_arena_inl_defd_g.m_statistics.m_bytes_allocated, &mk_sl_mallocator_arena_inl_defd_g.m_statistics.m_bytes_deallocated, bytes_live);
#else
	mk_lang_assert(bytes_live);
	((mk_lang_types_void_t)(bytes_live));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_inl_defd_statistics_get_all(mk_lang_static_param(mk_sl_mallocator_arena_inl_defd_num_blocks_t, blocks_all, 4), mk_lang_static_param(mk_sl_mallocator_arena_inl_defd_num_bytes_t, bytes_all, 4)) mk_lang_noexcept
{
	mk_lang_assert(blocks_all);
	mk_lang_assert(bytes_all);

	mk_sl_mallocator_arena_inl_defd_statistics_get_blocks_allocated(&blocks_all[0]);
	mk_sl_mallocator_arena_inl_defd_statistics_get_blocks_dealocated(&blocks_all[1]);
	mk_sl_mallocator_arena_inl_defd_statistics_get_blocks_peak(&blocks_all[2]);
	mk_sl_mallocator_arena_inl_defd_statistics_get_blocks_live(&blocks_all[3]);
	mk_sl_mallocator_arena_inl_defd_statistics_get_bytes_allocated(&bytes_all[0]);
	mk_sl_mallocator_arena_inl_defd_statistics_get_bytes_dealocated(&bytes_all[1]);
	mk_sl_mallocator_arena_inl_defd_statistics_get_bytes_peak(&bytes_all[2]);
	mk_sl_mallocator_arena_inl_defd_statistics_get_bytes_live(&bytes_all[3]);
}


#include "mk_sl_mallocator_arena_inl_defu.h"
