#ifndef mk_include_guard_mk_sl_mallocator_arena_c
#define mk_include_guard_mk_sl_mallocator_arena_c
#include "mk_sl_mallocator_arena.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#define mk_sl_mallocator_arena_t_name mk_sl_mallocator_arena_ver1
#define mk_sl_mallocator_arena_t_size 4 * 64 * 1024
#define mk_sl_mallocator_arena_t_statistics_want mk_sl_mallocator_arena_statistics_have
#include "mk_sl_mallocator_arena_inl_filec.h"
#include "mk_sl_mallocator_arena_inl_fileu.h"

#define mk_sl_mallocator_arena_t_name mk_sl_mallocator_arena_ver2
#define mk_sl_mallocator_arena_t_size 2 * 1024 * 1024
#define mk_sl_mallocator_arena_t_statistics_want mk_sl_mallocator_arena_statistics_have
#include "mk_sl_mallocator_arena_inl_filec.h"
#include "mk_sl_mallocator_arena_inl_fileu.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_arena_init(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_sl_mallocator_arena_ver1_init();
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_arena_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_sl_mallocator_arena_ver1_deinit();
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_arena_allocate(mk_lang_types_usize_t const size_bytes, mk_lang_types_void_ppt const mem) mk_lang_noexcept
{
	return mk_sl_mallocator_arena_ver1_allocate(size_bytes, mem);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_arena_deallocate(mk_lang_types_void_pt const mem, mk_lang_types_usize_t const size_bytes) mk_lang_noexcept
{
	return mk_sl_mallocator_arena_ver1_deallocate(mem, size_bytes);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_arena_reallocate(mk_lang_types_void_pt const old_mem, mk_lang_types_usize_t const old_size_bytes, mk_lang_types_usize_t const new_size_bytes, mk_lang_types_void_ppt const new_mem) mk_lang_noexcept
{
	return mk_sl_mallocator_arena_ver1_reallocate(old_mem, old_size_bytes, new_size_bytes, new_mem);
}


mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_statistics_get_blocks_allocated(mk_sl_mallocator_arena_ver1_blocks_pt const blocks_allocated) mk_lang_noexcept
{
	mk_sl_mallocator_arena_ver1_statistics_get_blocks_allocated(blocks_allocated);
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_statistics_get_blocks_dealocated(mk_sl_mallocator_arena_ver1_blocks_pt const blocks_deallocated) mk_lang_noexcept
{
	mk_sl_mallocator_arena_ver1_statistics_get_blocks_dealocated(blocks_deallocated);
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_statistics_get_blocks_peak(mk_sl_mallocator_arena_ver1_blocks_pt const blocks_peak) mk_lang_noexcept
{
	mk_sl_mallocator_arena_ver1_statistics_get_blocks_peak(blocks_peak);
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_statistics_get_blocks_live(mk_sl_mallocator_arena_ver1_blocks_pt const blocks_live) mk_lang_noexcept
{
	mk_sl_mallocator_arena_ver1_statistics_get_blocks_live(blocks_live);
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_statistics_get_bytes_allocated(mk_sl_mallocator_arena_ver1_bytes_pt const bytes_allocated) mk_lang_noexcept
{
	mk_sl_mallocator_arena_ver1_statistics_get_bytes_allocated(bytes_allocated);
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_statistics_get_bytes_dealocated(mk_sl_mallocator_arena_ver1_bytes_pt const bytes_deallocated) mk_lang_noexcept
{
	mk_sl_mallocator_arena_ver1_statistics_get_bytes_dealocated(bytes_deallocated);
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_statistics_get_bytes_peak(mk_sl_mallocator_arena_ver1_bytes_pt const bytes_peak) mk_lang_noexcept
{
	mk_sl_mallocator_arena_ver1_statistics_get_bytes_peak(bytes_peak);
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_statistics_get_bytes_live(mk_sl_mallocator_arena_ver1_bytes_pt const bytes_live) mk_lang_noexcept
{
	mk_sl_mallocator_arena_ver1_statistics_get_bytes_live(bytes_live);
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_arena_statistics_get_all(mk_lang_static_param(mk_sl_mallocator_arena_ver1_blocks_t, blocks_all, 4), mk_lang_static_param(mk_sl_mallocator_arena_ver1_bytes_t, bytes_all, 4)) mk_lang_noexcept
{
	mk_sl_mallocator_arena_ver1_statistics_get_all(blocks_all, bytes_all);
}


#endif
