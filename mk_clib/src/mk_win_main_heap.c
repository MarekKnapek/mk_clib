#include "mk_win_main_heap.h"

#include "mk_lang_assert.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_heap.h"


static mk_win_base_handle_t g_mk_win_main_heap;


mk_lang_jumbo mk_lang_types_void_t mk_win_main_heap_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_assert(!g_mk_win_main_heap.m_data);

	g_mk_win_main_heap = mk_win_kernel_heap_create(mk_win_kernel_heap_create_flags_e_none, 0, 0); mk_lang_assert(g_mk_win_main_heap.m_data);
}

mk_lang_jumbo mk_lang_types_void_t mk_win_main_heap_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_bool_t destroyed;

	mk_lang_assert(g_mk_win_main_heap.m_data);

	destroyed = mk_win_kernel_heap_destroy(g_mk_win_main_heap); mk_lang_assert(destroyed != 0);
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpt mk_win_main_heap_allocate(mk_win_kernel_heap_allocate_flags_t const flags, mk_win_base_usize_t const size_bytes) mk_lang_noexcept
{
	mk_win_base_void_lpt r;

	mk_lang_assert(g_mk_win_main_heap.m_data);

	r = mk_win_kernel_heap_allocate(g_mk_win_main_heap, flags, size_bytes);
	return r;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_main_heap_deallocate(mk_win_kernel_heap_deallocate_flags_t const flags, mk_win_base_void_lpct const mem) mk_lang_noexcept
{
	mk_win_base_bool_t r;

	mk_lang_assert(g_mk_win_main_heap.m_data);

	r = mk_win_kernel_heap_deallocate(g_mk_win_main_heap, flags, mem);
	return r;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpt mk_win_main_heap_reallocate(mk_win_kernel_heap_reallocate_flags_t const flags, mk_win_base_void_lpct const mem, mk_win_base_usize_t const size_bytes) mk_lang_noexcept
{
	mk_win_base_void_lpt r;

	mk_lang_assert(g_mk_win_main_heap.m_data);

	r = mk_win_kernel_heap_reallocate(g_mk_win_main_heap, flags, mem, size_bytes);
	return r;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_usize_t mk_win_main_heap_size(mk_win_kernel_heap_size_flags_t const flags, mk_win_base_void_lpct const mem) mk_lang_noexcept
{
	mk_win_base_usize_t r;

	mk_lang_assert(g_mk_win_main_heap.m_data);

	r = mk_win_kernel_heap_size(g_mk_win_main_heap, flags, mem);
	return r;
}
