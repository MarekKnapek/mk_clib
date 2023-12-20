#include "mk_win_kernel_heap.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall GetProcessHeap(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall HeapCreate(mk_win_base_dword_t, mk_win_base_usize_t, mk_win_base_usize_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall HeapDestroy(mk_win_base_handle_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_void_lpt mk_win_base_stdcall HeapAlloc(mk_win_base_handle_t, mk_win_base_dword_t, mk_win_base_usize_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall HeapFree(mk_win_base_handle_t, mk_win_base_dword_t, mk_win_base_void_lpct) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_usize_t mk_win_base_stdcall HeapSize(mk_win_base_handle_t, mk_win_base_dword_t, mk_win_base_void_lpct) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_void_lpt mk_win_base_stdcall HeapReAlloc(mk_win_base_handle_t, mk_win_base_dword_t, mk_win_base_void_lpct, mk_win_base_usize_t) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_heap_get_process(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_handle_t r;

	r = GetProcessHeap();
	return r;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_heap_create(mk_win_kernel_heap_create_flags_t const flags, mk_win_base_usize_t const size_bytes_initial, mk_win_base_usize_t const size_bytes_max) mk_lang_noexcept
{
	mk_win_base_handle_t r;

	r =  HeapCreate(((mk_win_base_dword_t)(flags)), size_bytes_initial, size_bytes_max);
	return r;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_heap_destroy(mk_win_base_handle_t const heap) mk_lang_noexcept
{
	mk_win_base_bool_t r;

	r = HeapDestroy(heap);
	return r;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpt mk_win_kernel_heap_allocate(mk_win_base_handle_t const heap, mk_win_kernel_heap_allocate_flags_t const flags, mk_win_base_usize_t const size_bytes) mk_lang_noexcept
{
	mk_win_base_void_lpt r;

	r = HeapAlloc(heap, ((mk_win_base_dword_t)(flags)), size_bytes);
	return r;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_heap_deallocate(mk_win_base_handle_t const heap, mk_win_kernel_heap_deallocate_flags_t const flags, mk_win_base_void_lpct const mem) mk_lang_noexcept
{
	mk_win_base_bool_t r;

	r = HeapFree(heap, ((mk_win_base_dword_t)(flags)), mem);
	return r;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpt mk_win_kernel_heap_reallocate(mk_win_base_handle_t const heap, mk_win_kernel_heap_reallocate_flags_t const flags, mk_win_base_void_lpct const mem, mk_win_base_usize_t const size_bytes) mk_lang_noexcept
{
	mk_win_base_void_lpt r;

	r = HeapReAlloc(heap, ((mk_win_base_dword_t)(flags)), mem, size_bytes);
	return r;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_usize_t mk_win_kernel_heap_size(mk_win_base_handle_t const heap, mk_win_kernel_heap_size_flags_t const flags, mk_win_base_void_lpct const mem) mk_lang_noexcept
{
	mk_win_base_usize_t r;

	r = HeapSize(heap, ((mk_win_base_dword_t)(flags)), mem);
	return r;
}
