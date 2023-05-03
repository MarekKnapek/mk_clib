#include "mk_win_kernel_heap.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"
#include "mk_win_base.h"


mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall GetProcessHeap(void) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall HeapCreate(mk_win_base_dword_t, mk_lang_size_t, mk_lang_size_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall HeapDestroy(mk_win_base_handle_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_void_lpt mk_win_base_stdcall HeapAlloc(mk_win_base_handle_t, mk_win_base_dword_t, mk_lang_size_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall HeapFree(mk_win_base_handle_t, mk_win_base_dword_t, mk_win_base_void_lpct) mk_lang_noexcept;
mk_win_base_dll_import mk_lang_size_t mk_win_base_stdcall HeapSize(mk_win_base_handle_t, mk_win_base_dword_t, mk_win_base_void_lpct) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_void_lpt mk_win_base_stdcall HeapReAlloc(mk_win_base_handle_t, mk_win_base_dword_t, mk_win_base_void_lpct, mk_lang_size_t) mk_lang_noexcept;


mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_heap_get_process(void) mk_lang_noexcept
{
	mk_win_base_handle_t heap;

	heap = GetProcessHeap();
	return heap;
}

mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_heap_create(mk_win_kernel_heap_create_flags_t const flags, mk_lang_size_t const size_bytes_initial, mk_lang_size_t const size_bytes_max) mk_lang_noexcept
{
	mk_win_base_handle_t heap;

	heap =  HeapCreate(((mk_win_base_dword_t)(flags)), size_bytes_initial, size_bytes_max);
	return heap;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_heap_destroy(mk_win_base_handle_t const heap) mk_lang_noexcept
{
	mk_win_base_bool_t destroyed;

	mk_lang_assert(heap);
	mk_lang_assert(heap != mk_win_kernel_heap_get_process());

	destroyed = HeapDestroy(heap);
	mk_lang_assert(destroyed == mk_win_base_false || destroyed == mk_win_base_true);
	return destroyed;
}

mk_lang_jumbo mk_win_base_void_lpt mk_win_kernel_heap_allocate(mk_win_base_handle_t const heap, mk_win_kernel_heap_allocate_flags_t const flags, mk_lang_size_t const size_bytes) mk_lang_noexcept
{
	mk_win_base_void_lpt mem;

	mk_lang_assert(heap);
	mk_lang_assert(!(flags == mk_win_kernel_heap_allocate_flags_e_no_serialize && heap == mk_win_kernel_heap_get_process()));

	mem = HeapAlloc(heap, ((mk_win_base_dword_t)(flags)), size_bytes);
	return mem;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_heap_deallocate(mk_win_base_handle_t const heap, mk_win_kernel_heap_deallocate_flags_t const flags, mk_win_base_void_lpct const mem) mk_lang_noexcept
{
	mk_win_base_bool_t freed;

	mk_lang_assert(heap);
	mk_lang_assert(!(flags == mk_win_kernel_heap_deallocate_flags_e_no_serialize && heap == mk_win_kernel_heap_get_process()));

	freed = HeapFree(heap, ((mk_win_base_dword_t)(flags)), mem);
	mk_lang_assert(freed == mk_win_base_false || freed == mk_win_base_true);
	return freed;
}

mk_lang_jumbo mk_win_base_void_lpt mk_win_kernel_heap_reallocate(mk_win_base_handle_t const heap, mk_win_kernel_heap_reallocate_flags_t const flags, mk_win_base_void_lpct const mem, mk_lang_size_t const size_bytes) mk_lang_noexcept
{
	mk_win_base_void_lpt new_mem;

	mk_lang_assert(heap);
	mk_lang_assert(!(flags == mk_win_kernel_heap_reallocate_flags_e_no_serialize && heap == mk_win_kernel_heap_get_process()));
	mk_lang_assert(mem);

	new_mem = HeapReAlloc(heap, ((mk_win_base_dword_t)(flags)), mem, size_bytes);
	return new_mem;
}

mk_lang_jumbo mk_lang_size_t mk_win_kernel_heap_size(mk_win_base_handle_t const heap, mk_win_kernel_heap_size_flags_t const flags, mk_win_base_void_lpct const mem) mk_lang_noexcept
{
	mk_lang_size_t size_bytes;

	mk_lang_assert(heap);
	mk_lang_assert(!(flags == mk_win_kernel_heap_size_flags_e_no_serialize && heap == mk_win_kernel_heap_get_process()));

	size_bytes = HeapSize(heap, ((mk_win_base_dword_t)(flags)), mem);
	return size_bytes;
}
