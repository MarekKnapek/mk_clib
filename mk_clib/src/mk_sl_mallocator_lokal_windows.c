#ifndef mk_include_guard_mk_sl_mallocator_lokal_windows_c
#define mk_include_guard_mk_sl_mallocator_lokal_windows_c
#include "mk_sl_mallocator_lokal_windows.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any

#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_win_base.h"
#include "mk_win_dll_kernel_heap.h"

#define mk_sl_cui_t_name mk_sl_mallocator_lokal_windows_num_blocks
#define mk_sl_cui_t_base mk_lang_bui_usize
#define mk_sl_cui_t_count 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_sl_mallocator_lokal_windows_num_bytes
#define mk_sl_cui_t_base mk_lang_bui_usize
#define mk_sl_cui_t_count 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_init(mk_sl_mallocator_lokal_windows_pt const win) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_windows_statistics_have
	mk_lang_assert(win);

	mk_sl_mallocator_lokal_windows_num_blocks_set_zero(&win->m_statistics.m_blocks_allocated);
	mk_sl_mallocator_lokal_windows_num_blocks_set_zero(&win->m_statistics.m_blocks_deallocated);
	mk_sl_mallocator_lokal_windows_num_blocks_set_zero(&win->m_statistics.m_blocks_peak);
	mk_sl_mallocator_lokal_windows_num_bytes_set_zero(&win->m_statistics.m_bytes_allocated);
	mk_sl_mallocator_lokal_windows_num_bytes_set_zero(&win->m_statistics.m_bytes_deallocated);
	mk_sl_mallocator_lokal_windows_num_bytes_set_zero(&win->m_statistics.m_bytes_peak);
#else
	mk_lang_assert(win);
	((mk_lang_types_void_t)(win));
#endif
}

static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_deinit(mk_sl_mallocator_lokal_windows_pt const win) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_windows_statistics_have
	mk_sl_mallocator_lokal_windows_num_blocks_t blocks_live;
	mk_sl_mallocator_lokal_windows_num_bytes_t bytes_live;

	mk_lang_assert(win);

	mk_sl_mallocator_lokal_windows_statistics_get_blocks_live(win, &blocks_live);
	mk_sl_mallocator_lokal_windows_statistics_get_bytes_live(win, &bytes_live);
	mk_lang_assert(mk_sl_mallocator_lokal_windows_num_blocks_is_zero(&blocks_live));
	mk_lang_assert(mk_sl_mallocator_lokal_windows_num_bytes_is_zero(&bytes_live));
#else
	mk_lang_assert(win);
	((mk_lang_types_void_t)(win));
#endif
}

static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_update_peak(mk_sl_mallocator_lokal_windows_pt const win) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_windows_statistics_have
	mk_sl_mallocator_lokal_windows_num_blocks_t blocks_live;
	mk_sl_mallocator_lokal_windows_num_bytes_t bytes_live;

	mk_lang_assert(win);

	mk_sl_mallocator_lokal_windows_statistics_get_blocks_live(win, &blocks_live);
	if(mk_sl_mallocator_lokal_windows_num_blocks_gt(&blocks_live, &win->m_statistics.m_blocks_peak))
	{
		win->m_statistics.m_blocks_peak = blocks_live;
	}
	mk_sl_mallocator_lokal_windows_statistics_get_bytes_live(win, &bytes_live);
	if(mk_sl_mallocator_lokal_windows_num_bytes_gt(&bytes_live, &win->m_statistics.m_bytes_peak))
	{
		win->m_statistics.m_bytes_peak = bytes_live;
	}
#else
	mk_lang_assert(win);
	((mk_lang_types_void_t)(win));
#endif
}

static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_allocated(mk_sl_mallocator_lokal_windows_pt const win, mk_lang_types_usize_t const size_bytes) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_windows_statistics_have
	mk_sl_mallocator_lokal_windows_num_bytes_t bytes;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(win);
	mk_lang_assert(size_bytes >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_lokal_windows_num_blocks_inc1(&win->m_statistics.m_blocks_allocated);
	mk_sl_mallocator_lokal_windows_num_bytes_from_bi_usize(&bytes, &size_bytes);
	mk_sl_mallocator_lokal_windows_num_bytes_add2_wrap_cid_cod(&win->m_statistics.m_bytes_allocated, &bytes);
	mk_sl_mallocator_lokal_windows_statistics_update_peak(win);
#else
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(win);
	mk_lang_assert(size_bytes >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(win));
	((mk_lang_types_void_t)(size_bytes));
#endif
}

static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_deallocated(mk_sl_mallocator_lokal_windows_pt const win, mk_lang_types_usize_t const size_bytes) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_windows_statistics_have
	mk_sl_mallocator_lokal_windows_num_bytes_t bytes;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(win);
	mk_lang_assert(size_bytes >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_lokal_windows_num_blocks_inc1(&win->m_statistics.m_blocks_deallocated);
	mk_sl_mallocator_lokal_windows_num_bytes_from_bi_usize(&bytes, &size_bytes);
	mk_sl_mallocator_lokal_windows_num_bytes_add2_wrap_cid_cod(&win->m_statistics.m_bytes_deallocated, &bytes);
#else
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(win);
	mk_lang_assert(size_bytes >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(win));
	((mk_lang_types_void_t)(size_bytes));
#endif
}

static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_reallocated(mk_sl_mallocator_lokal_windows_pt const win, mk_lang_types_usize_t const old_size_bytes, mk_lang_types_usize_t const new_size_bytes) mk_lang_noexcept
{
	mk_sl_mallocator_lokal_windows_statistics_allocated(win, new_size_bytes);
	mk_sl_mallocator_lokal_windows_statistics_deallocated(win, old_size_bytes);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_lokal_windows_init(mk_sl_mallocator_lokal_windows_pt const win) mk_lang_noexcept
{
	mk_lang_assert(win);

	mk_sl_mallocator_lokal_windows_statistics_init(win);
	win->m_heap = mk_win_dll_kernel_heap_create(mk_win_dll_kernel_heap_options_create_e_none, 0, 0); mk_lang_check_return(!mk_win_dll_kernel_heap_is_null(win->m_heap));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_lokal_windows_deinit(mk_sl_mallocator_lokal_windows_pt const win) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(win);
	mk_lang_assert(!mk_win_dll_kernel_heap_is_null(win->m_heap));

	mk_sl_mallocator_lokal_windows_statistics_deinit(win);
	b = mk_win_dll_kernel_heap_destroy(win->m_heap); mk_lang_check_return(b != 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_lokal_windows_allocate(mk_sl_mallocator_lokal_windows_pt const win, mk_lang_types_usize_t const size_bytes, mk_lang_types_void_ppt const mem) mk_lang_noexcept
{
	mk_lang_types_void_pt m;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(win);
	mk_lang_assert(!mk_win_dll_kernel_heap_is_null(win->m_heap));
	mk_lang_assert(size_bytes >= 0);
	mk_lang_assert(mem || size_bytes == 0);
	#include "mk_lang_warning_msvc_pop.h"

	if(size_bytes != 0)
	{
		m = mk_win_dll_kernel_heap_alloc(win->m_heap, mk_win_dll_kernel_heap_options_alloc_e_none, size_bytes);
		if(m)
		{
			mk_sl_mallocator_lokal_windows_statistics_allocated(win, size_bytes);
		}
		*mem = m;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_lokal_windows_deallocate(mk_sl_mallocator_lokal_windows_pt const win, mk_lang_types_void_pct const mem, mk_lang_types_usize_t const size_bytes) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(win);
	mk_lang_assert(!mk_win_dll_kernel_heap_is_null(win->m_heap));
	mk_lang_assert(mem || size_bytes == 0);
	mk_lang_assert(size_bytes >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	if(size_bytes != 0)
	{
		b = mk_win_dll_kernel_heap_free(win->m_heap, mk_win_dll_kernel_heap_options_free_e_none, ((mk_lang_types_void_pt)(mem))); mk_lang_check_return(b != 0);
		mk_sl_mallocator_lokal_windows_statistics_deallocated(win, size_bytes);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_lokal_windows_reallocate(mk_sl_mallocator_lokal_windows_pt const win, mk_lang_types_void_pct const old_mem, mk_lang_types_usize_t const old_size_bytes, mk_lang_types_usize_t const new_size_bytes, mk_lang_types_void_ppt const new_mem) mk_lang_noexcept
{
	mk_lang_types_void_pt m;

	mk_lang_assert(win);
	mk_lang_assert(!mk_win_dll_kernel_heap_is_null(win->m_heap));
	mk_lang_assert(old_mem);
	mk_lang_assert(old_size_bytes >= 1);
	mk_lang_assert(new_size_bytes >= 1);
	mk_lang_assert(new_mem);

	m = mk_win_dll_kernel_heap_realloc(win->m_heap, mk_win_dll_kernel_heap_options_realloc_e_none, ((mk_lang_types_void_pt)(old_mem)), new_size_bytes);
	if(m)
	{
		mk_sl_mallocator_lokal_windows_statistics_reallocated(win, old_size_bytes, new_size_bytes);
	}
	*new_mem = m;
	return 0;
}


mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_get_blocks_allocated(mk_sl_mallocator_lokal_windows_pt const win, mk_sl_mallocator_lokal_windows_num_blocks_pt const blocks_allocated) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_windows_statistics_have
	mk_lang_assert(win);
	mk_lang_assert(blocks_allocated);

	*blocks_allocated = win->m_statistics.m_blocks_allocated;
#else
	mk_lang_assert(win);
	mk_lang_assert(blocks_allocated);
	((mk_lang_types_void_t)(win));
	((mk_lang_types_void_t)(blocks_allocated));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_get_blocks_dealocated(mk_sl_mallocator_lokal_windows_pt const win, mk_sl_mallocator_lokal_windows_num_blocks_pt const blocks_deallocated) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_windows_statistics_have
	mk_lang_assert(win);
	mk_lang_assert(blocks_deallocated);

	*blocks_deallocated = win->m_statistics.m_blocks_deallocated;
#else
	mk_lang_assert(win);
	mk_lang_assert(blocks_deallocated);
	((mk_lang_types_void_t)(win));
	((mk_lang_types_void_t)(blocks_deallocated));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_get_blocks_peak(mk_sl_mallocator_lokal_windows_pt const win, mk_sl_mallocator_lokal_windows_num_blocks_pt const blocks_peak) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_windows_statistics_have
	mk_lang_assert(win);
	mk_lang_assert(blocks_peak);

	*blocks_peak = win->m_statistics.m_blocks_peak;
#else
	mk_lang_assert(win);
	mk_lang_assert(blocks_peak);
	((mk_lang_types_void_t)(win));
	((mk_lang_types_void_t)(blocks_peak));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_get_blocks_live(mk_sl_mallocator_lokal_windows_pt const win, mk_sl_mallocator_lokal_windows_num_blocks_pt const blocks_live) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_windows_statistics_have
	mk_lang_assert(win);
	mk_lang_assert(blocks_live);

	mk_sl_mallocator_lokal_windows_num_blocks_sub3_wrap_cid_cod(&win->m_statistics.m_blocks_allocated, &win->m_statistics.m_blocks_deallocated, blocks_live);
#else
	mk_lang_assert(win);
	mk_lang_assert(blocks_live);
	((mk_lang_types_void_t)(win));
	((mk_lang_types_void_t)(blocks_live));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_get_bytes_allocated(mk_sl_mallocator_lokal_windows_pt const win, mk_sl_mallocator_lokal_windows_num_bytes_pt const bytes_allocated) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_windows_statistics_have
	mk_lang_assert(win);
	mk_lang_assert(bytes_allocated);

	*bytes_allocated = win->m_statistics.m_bytes_allocated;
#else
	mk_lang_assert(win);
	mk_lang_assert(bytes_allocated);
	((mk_lang_types_void_t)(win));
	((mk_lang_types_void_t)(bytes_allocated));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_get_bytes_dealocated(mk_sl_mallocator_lokal_windows_pt const win, mk_sl_mallocator_lokal_windows_num_bytes_pt const bytes_deallocated) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_windows_statistics_have
	mk_lang_assert(win);
	mk_lang_assert(bytes_deallocated);

	*bytes_deallocated = win->m_statistics.m_bytes_deallocated;
#else
	mk_lang_assert(win);
	mk_lang_assert(bytes_deallocated);
	((mk_lang_types_void_t)(win));
	((mk_lang_types_void_t)(bytes_deallocated));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_get_bytes_peak(mk_sl_mallocator_lokal_windows_pt const win, mk_sl_mallocator_lokal_windows_num_bytes_pt const bytes_peak) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_windows_statistics_have
	mk_lang_assert(win);
	mk_lang_assert(bytes_peak);

	*bytes_peak = win->m_statistics.m_bytes_peak;
#else
	mk_lang_assert(win);
	mk_lang_assert(bytes_peak);
	((mk_lang_types_void_t)(win));
	((mk_lang_types_void_t)(bytes_peak));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_get_bytes_live(mk_sl_mallocator_lokal_windows_pt const win, mk_sl_mallocator_lokal_windows_num_bytes_pt const bytes_live) mk_lang_noexcept
{
#if mk_sl_mallocator_lokal_windows_statistics_have
	mk_lang_assert(win);
	mk_lang_assert(bytes_live);

	mk_sl_mallocator_lokal_windows_num_bytes_sub3_wrap_cid_cod(&win->m_statistics.m_bytes_allocated, &win->m_statistics.m_bytes_deallocated, bytes_live);
#else
	mk_lang_assert(win);
	mk_lang_assert(bytes_live);
	((mk_lang_types_void_t)(win));
	((mk_lang_types_void_t)(bytes_live));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_get_all(mk_sl_mallocator_lokal_windows_pt const win, mk_lang_static_param(mk_sl_mallocator_lokal_windows_num_blocks_t, blocks_all, 4), mk_lang_static_param(mk_sl_mallocator_lokal_windows_num_bytes_t, bytes_all, 4)) mk_lang_noexcept
{
	mk_lang_assert(win);
	mk_lang_assert(blocks_all);
	mk_lang_assert(bytes_all);

	mk_sl_mallocator_lokal_windows_statistics_get_blocks_allocated(win, &blocks_all[0]);
	mk_sl_mallocator_lokal_windows_statistics_get_blocks_dealocated(win, &blocks_all[1]);
	mk_sl_mallocator_lokal_windows_statistics_get_blocks_peak(win, &blocks_all[2]);
	mk_sl_mallocator_lokal_windows_statistics_get_blocks_live(win, &blocks_all[3]);
	mk_sl_mallocator_lokal_windows_statistics_get_bytes_allocated(win, &bytes_all[0]);
	mk_sl_mallocator_lokal_windows_statistics_get_bytes_dealocated(win, &bytes_all[1]);
	mk_sl_mallocator_lokal_windows_statistics_get_bytes_peak(win, &bytes_all[2]);
	mk_sl_mallocator_lokal_windows_statistics_get_bytes_live(win, &bytes_all[3]);
}


#else
static void mk_sl_mallocator_lokal_windows_dummy(void){}
#endif
#endif
