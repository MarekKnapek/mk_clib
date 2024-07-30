#include "mk_win_kernel_heap.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_kernel_heap_t mk_win_base_stdcall HeapCreate(mk_win_base_dword_t const options, mk_win_base_usize_t const size_initial, mk_win_base_usize_t const size_max) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall HeapDestroy(mk_win_kernel_heap_t const heap) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_void_lpt mk_win_base_stdcall HeapAlloc(mk_win_kernel_heap_t const heap, mk_win_base_dword_t const flags, mk_win_base_usize_t const size) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall HeapFree(mk_win_kernel_heap_t const heap, mk_win_base_dword_t const flags, mk_win_base_void_lpt const mem) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_void_lpt mk_win_base_stdcall HeapReAlloc(mk_win_kernel_heap_t const heap, mk_win_base_dword_t const flags, mk_win_base_void_lpt const mem, mk_win_base_usize_t const size) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_kernel_heap_t mk_win_kernel_heap_create(mk_win_base_dword_t const options, mk_win_base_usize_t const size_initial, mk_win_base_usize_t const size_max) mk_lang_noexcept
{
	mk_win_kernel_heap_t ret;

	ret = HeapCreate(options, size_initial, size_max);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_heap_destroy(mk_win_kernel_heap_t const heap) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = HeapDestroy(heap);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpt mk_win_kernel_heap_alloc(mk_win_kernel_heap_t const heap, mk_win_base_dword_t const flags, mk_win_base_usize_t const size) mk_lang_noexcept
{
	mk_win_base_void_lpt ret;

	ret = HeapAlloc(heap, flags, size);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_heap_free(mk_win_kernel_heap_t const heap, mk_win_base_dword_t const flags, mk_win_base_void_lpt const mem) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = HeapFree(heap, flags, mem);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpt mk_win_kernel_heap_realloc(mk_win_kernel_heap_t const heap, mk_win_base_dword_t const flags, mk_win_base_void_lpt const mem, mk_win_base_usize_t const size) mk_lang_noexcept
{
	mk_win_base_void_lpt ret;

	ret = HeapReAlloc(heap, flags, mem, size);
	return ret;
}
