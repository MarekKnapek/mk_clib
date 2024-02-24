#ifndef mk_include_guard_mk_win_kernel_heap
#define mk_include_guard_mk_win_kernel_heap


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


enum mk_win_kernel_heap_create_flags_e
{
	mk_win_kernel_heap_create_flags_e_none                  = ((mk_win_base_dword_t)(0x00000000ul)),
	mk_win_kernel_heap_create_flags_e_no_serialize          = ((mk_win_base_dword_t)(0x00000001ul)),
	mk_win_kernel_heap_create_flags_e_generate_exceptions   = ((mk_win_base_dword_t)(0x00000004ul)),
	mk_win_kernel_heap_create_flags_e_create_enable_execute = ((mk_win_base_dword_t)(0x00040000ul)), /* todo since what version? */
	mk_win_kernel_heap_create_flags_e_dummy = 0
};
typedef enum mk_win_kernel_heap_create_flags_e mk_win_kernel_heap_create_flags_t;

enum mk_win_kernel_heap_allocate_flags_e
{
	mk_win_kernel_heap_allocate_flags_e_none                = ((mk_win_base_dword_t)(0x00000000ul)),
	mk_win_kernel_heap_allocate_flags_e_no_serialize        = ((mk_win_base_dword_t)(0x00000001ul)),
	mk_win_kernel_heap_allocate_flags_e_generate_exceptions = ((mk_win_base_dword_t)(0x00000004ul)),
	mk_win_kernel_heap_allocate_flags_e_zero_memory         = ((mk_win_base_dword_t)(0x00000008ul)),
	mk_win_kernel_heap_allocate_flags_e_dummy = 0
};
typedef enum mk_win_kernel_heap_allocate_flags_e mk_win_kernel_heap_allocate_flags_t;

enum mk_win_kernel_heap_deallocate_flags_e
{
	mk_win_kernel_heap_deallocate_flags_e_none         = ((mk_win_base_dword_t)(0x00000000ul)),
	mk_win_kernel_heap_deallocate_flags_e_no_serialize = ((mk_win_base_dword_t)(0x00000001ul)),
	mk_win_kernel_heap_deallocate_flags_e_dummy = 0
};
typedef enum mk_win_kernel_heap_deallocate_flags_e mk_win_kernel_heap_deallocate_flags_t;

enum mk_win_kernel_heap_reallocate_flags_e
{
	mk_win_kernel_heap_reallocate_flags_e_none                  = ((mk_win_base_dword_t)(0x00000000ul)),
	mk_win_kernel_heap_reallocate_flags_e_no_serialize          = ((mk_win_base_dword_t)(0x00000001ul)),
	mk_win_kernel_heap_reallocate_flags_e_generate_exceptions   = ((mk_win_base_dword_t)(0x00000004ul)),
	mk_win_kernel_heap_reallocate_flags_e_zero_memory           = ((mk_win_base_dword_t)(0x00000008ul)),
	mk_win_kernel_heap_reallocate_flags_e_realloc_in_place_only = ((mk_win_base_dword_t)(0x00000010ul)),
	mk_win_kernel_heap_reallocate_flags_e_dummy = 0
};
typedef enum mk_win_kernel_heap_reallocate_flags_e mk_win_kernel_heap_reallocate_flags_t;

enum mk_win_kernel_heap_size_flags_e
{
	mk_win_kernel_heap_size_flags_e_none         = ((mk_win_base_dword_t)(0x00000000ul)),
	mk_win_kernel_heap_size_flags_e_no_serialize = ((mk_win_base_dword_t)(0x00000001ul)),
	mk_win_kernel_heap_size_flags_e_dummy
};
typedef enum mk_win_kernel_heap_size_flags_e mk_win_kernel_heap_size_flags_t;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_heap_get_process(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_heap_create(mk_win_kernel_heap_create_flags_t const flags, mk_win_base_usize_t const size_bytes_initial, mk_win_base_usize_t const size_bytes_max) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_heap_destroy(mk_win_base_handle_t const heap) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpt mk_win_kernel_heap_allocate(mk_win_base_handle_t const heap, mk_win_kernel_heap_allocate_flags_t const flags, mk_win_base_usize_t const size_bytes) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_heap_deallocate(mk_win_base_handle_t const heap, mk_win_kernel_heap_deallocate_flags_t const flags, mk_win_base_void_lpct const mem) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpt mk_win_kernel_heap_reallocate(mk_win_base_handle_t const heap, mk_win_kernel_heap_reallocate_flags_t const flags, mk_win_base_void_lpct const mem, mk_win_base_usize_t const size_bytes) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_usize_t mk_win_kernel_heap_size(mk_win_base_handle_t const heap, mk_win_kernel_heap_size_flags_t const flags, mk_win_base_void_lpct const mem) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_heap.c"
#endif
#endif
