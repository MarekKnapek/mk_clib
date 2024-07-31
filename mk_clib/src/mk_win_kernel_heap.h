#ifndef mk_include_guard_mk_win_kernel_heap
#define mk_include_guard_mk_win_kernel_heap


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_win_base_make_handle(mk_win_kernel_heap)


enum mk_win_kernel_heap_options_create_e
{
	mk_win_kernel_heap_options_create_e_no_serialize        = ((mk_win_base_dword_t)(0x00000001ul)),
	mk_win_kernel_heap_options_create_e_generate_exceptions = ((mk_win_base_dword_t)(0x00000004ul)),
	mk_win_kernel_heap_options_create_e_enable_execute      = ((mk_win_base_dword_t)(0x00040000ul)),
	mk_win_kernel_heap_options_create_e_dummy_end
};
typedef enum mk_win_kernel_heap_options_create_e mk_win_kernel_heap_options_create_t;

enum mk_win_kernel_heap_options_alloc_e
{
	mk_win_kernel_heap_options_alloc_e_no_serialize        = ((mk_win_base_dword_t)(0x00000001ul)),
	mk_win_kernel_heap_options_alloc_e_generate_exceptions = ((mk_win_base_dword_t)(0x00000004ul)),
	mk_win_kernel_heap_options_alloc_e_zero_memory         = ((mk_win_base_dword_t)(0x00000008ul)),
	mk_win_kernel_heap_options_alloc_e_dummy_end
};
typedef enum mk_win_kernel_heap_options_alloc_e mk_win_kernel_heap_options_alloc_t;

enum mk_win_kernel_heap_options_free_e
{
	mk_win_kernel_heap_options_free_e_no_serialize = ((mk_win_base_dword_t)(0x00000001ul)),
	mk_win_kernel_heap_options_free_e_dummy_end
};
typedef enum mk_win_kernel_heap_options_free_e mk_win_kernel_heap_options_free_t;

enum mk_win_kernel_heap_options_realloc_e
{
	mk_win_kernel_heap_options_realloc_e_no_serialize        = ((mk_win_base_dword_t)(0x00000001ul)),
	mk_win_kernel_heap_options_realloc_e_generate_exceptions = ((mk_win_base_dword_t)(0x00000004ul)),
	mk_win_kernel_heap_options_realloc_e_zero_memory         = ((mk_win_base_dword_t)(0x00000008ul)),
	mk_win_kernel_heap_options_realloc_e_in_place_only       = ((mk_win_base_dword_t)(0x00000010ul)),
	mk_win_kernel_heap_options_realloc_e_dummy_end
};
typedef enum mk_win_kernel_heap_options_realloc_e mk_win_kernel_heap_options_realloc_t;


mk_lang_nodiscard mk_lang_jumbo mk_win_kernel_heap_t mk_win_kernel_heap_create(mk_win_base_dword_t const options, mk_win_base_usize_t const size_initial, mk_win_base_usize_t const size_max) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_heap_destroy(mk_win_kernel_heap_t const heap) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpt mk_win_kernel_heap_alloc(mk_win_kernel_heap_t const heap, mk_win_base_dword_t const flags, mk_win_base_usize_t const size) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_heap_free(mk_win_kernel_heap_t const heap, mk_win_base_dword_t const flags, mk_win_base_void_lpt const mem) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpt mk_win_kernel_heap_realloc(mk_win_kernel_heap_t const heap, mk_win_base_dword_t const flags, mk_win_base_void_lpt const mem, mk_win_base_usize_t const size) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_heap.c"
#endif
#endif
