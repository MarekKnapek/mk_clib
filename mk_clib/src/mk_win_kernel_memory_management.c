#include "mk_win_kernel_memory_management.h"

#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_lang_extern_c mk_win_base_dll_import mk_win_base_void_lpt mk_win_base_stdcall VirtualAlloc(mk_win_base_void_lpct, mk_win_base_usize_t, mk_win_base_dword_t, mk_win_base_dword_t) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall VirtualFree(mk_win_base_void_lpct, mk_win_base_usize_t, mk_win_base_dword_t) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpt mk_win_kernel_memory_management_virtual_alloc(mk_win_base_void_lpct const base, mk_win_base_usize_t const size, mk_win_base_dword_t const type, mk_win_base_dword_t const protect) mk_lang_noexcept
{
	mk_win_base_void_lpt address;

	address = VirtualAlloc(base, size, type, protect);
	return address;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_memory_management_virtual_free(mk_win_base_void_lpct const base, mk_win_base_usize_t const size, mk_win_base_dword_t const type) mk_lang_noexcept
{
	mk_win_base_bool_t freed;

	freed = VirtualFree(base, size, type);
	return freed;
}
