#ifndef include_guard_mk_win_kernel_heap
#define include_guard_mk_win_kernel_heap


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"
#include "mk_win_base.h"


enum mk_win_kernel_heap_create_flags_e
{
	mk_win_kernel_heap_create_flags_e_none                  = 0x00000000,
	mk_win_kernel_heap_create_flags_e_no_serialize          = 0x00000001,
	mk_win_kernel_heap_create_flags_e_generate_exceptions   = 0x00000004,
	mk_win_kernel_heap_create_flags_e_create_enable_execute = 0x00040000 /* todo since what version? */
};
typedef enum mk_win_kernel_heap_create_flags_e mk_win_kernel_heap_create_flags_t;

enum mk_win_kernel_heap_allocate_flags_e
{
	mk_win_kernel_heap_allocate_flags_e_none                = 0x00000000,
	mk_win_kernel_heap_allocate_flags_e_no_serialize        = 0x00000001,
	mk_win_kernel_heap_allocate_flags_e_generate_exceptions = 0x00000004,
	mk_win_kernel_heap_allocate_flags_e_zero_memory         = 0x00000008
};
typedef enum mk_win_kernel_heap_allocate_flags_e mk_win_kernel_heap_allocate_flags_t;

enum mk_win_kernel_heap_deallocate_flags_e
{
	mk_win_kernel_heap_deallocate_flags_e_none         = 0x00000000,
	mk_win_kernel_heap_deallocate_flags_e_no_serialize = 0x00000001
};
typedef enum mk_win_kernel_heap_deallocate_flags_e mk_win_kernel_heap_deallocate_flags_t;

enum mk_win_kernel_heap_reallocate_flags_e
{
	mk_win_kernel_heap_reallocate_flags_e_none                  = 0x00000000,
	mk_win_kernel_heap_reallocate_flags_e_no_serialize          = 0x00000001,
	mk_win_kernel_heap_reallocate_flags_e_generate_exceptions   = 0x00000004,
	mk_win_kernel_heap_reallocate_flags_e_zero_memory           = 0x00000008,
	mk_win_kernel_heap_reallocate_flags_e_realloc_in_place_only = 0x00000010
};
typedef enum mk_win_kernel_heap_reallocate_flags_e mk_win_kernel_heap_reallocate_flags_t;

enum mk_win_kernel_heap_size_flags_e
{
	mk_win_kernel_heap_size_flags_e_none         = 0x00000000,
	mk_win_kernel_heap_size_flags_e_no_serialize = 0x00000001
};
typedef enum mk_win_kernel_heap_size_flags_e mk_win_kernel_heap_size_flags_t;


mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_heap_get_process(void) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_heap_create(mk_win_kernel_heap_create_flags_t const flags, mk_lang_size_t const size_bytes_initial, mk_lang_size_t const size_bytes_max) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_heap_destroy(mk_win_base_handle_t const heap) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_void_lpt mk_win_kernel_heap_allocate(mk_win_base_handle_t const heap, mk_win_kernel_heap_allocate_flags_t const flags, mk_lang_size_t const size_bytes) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_heap_deallocate(mk_win_base_handle_t const heap, mk_win_kernel_heap_deallocate_flags_t const flags, mk_win_base_void_lpct const mem) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_void_lpt mk_win_kernel_heap_reallocate(mk_win_base_handle_t const heap, mk_win_kernel_heap_reallocate_flags_t const flags, mk_win_base_void_lpct const mem, mk_lang_size_t const size_bytes) mk_lang_noexcept;
mk_lang_jumbo mk_lang_size_t mk_win_kernel_heap_size(mk_win_base_handle_t const heap, mk_win_kernel_heap_size_flags_t const flags, mk_win_base_void_lpct const mem) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_heap.c"
#endif
#endif
