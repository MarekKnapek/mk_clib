#ifndef mk_include_guard_mk_win_dll_kernel_memory_management_h
#define mk_include_guard_mk_win_dll_kernel_memory_management_h


#include "mk_lang_jumbo.h"
#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any


#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


#define mk_win_dll_kernel_memory_management_k_alloc_type_mem_commit      (    0x1000)
#define mk_win_dll_kernel_memory_management_k_alloc_type_mem_reserve     (    0x2000)
#define mk_win_dll_kernel_memory_management_k_alloc_type_mem_reset       (   0x80000)
#define mk_win_dll_kernel_memory_management_k_alloc_type_mem_top_down    (  0x100000)
#define mk_win_dll_kernel_memory_management_k_alloc_type_mem_write_watch (  0x200000)
#define mk_win_dll_kernel_memory_management_k_alloc_type_mem_physical    (  0x400000)
#define mk_win_dll_kernel_memory_management_k_alloc_type_mem_reset_undo  ( 0x1000000)
#define mk_win_dll_kernel_memory_management_k_alloc_type_mem_large_pages (0x20000000)

#define mk_win_dll_kernel_memory_management_k_dealloc_type_mem_coalesce_placeholders (       0x1)
#define mk_win_dll_kernel_memory_management_k_dealloc_type_mem_preserve_placeholder  (       0x2)
#define mk_win_dll_kernel_memory_management_k_dealloc_type_mem_decommit              (    0x4000)
#define mk_win_dll_kernel_memory_management_k_dealloc_type_mem_release               (    0x8000)

#define mk_win_dll_kernel_memory_management_k_protection_page_noaccess          (       0x1)
#define mk_win_dll_kernel_memory_management_k_protection_page_readonly          (       0x2)
#define mk_win_dll_kernel_memory_management_k_protection_page_readwrite         (       0x4)
#define mk_win_dll_kernel_memory_management_k_protection_page_writecopy         (       0x8)
#define mk_win_dll_kernel_memory_management_k_protection_page_execute           (      0x10)
#define mk_win_dll_kernel_memory_management_k_protection_page_execute_read      (      0x20)
#define mk_win_dll_kernel_memory_management_k_protection_page_execute_readwrite (      0x40)
#define mk_win_dll_kernel_memory_management_k_protection_page_execute_writecopy (      0x80)
#define mk_win_dll_kernel_memory_management_k_protection_page_guard             (     0x100)
#define mk_win_dll_kernel_memory_management_k_protection_page_nocache           (     0x200)
#define mk_win_dll_kernel_memory_management_k_protection_page_writecombine      (     0x400)
#define mk_win_dll_kernel_memory_management_k_protection_page_targets_invalid   (0x40000000)
#define mk_win_dll_kernel_memory_management_k_protection_page_targets_no_update (0x40000000)


mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpt mk_win_dll_kernel_memory_management_virtual_alloc(mk_win_base_void_lpt const address, mk_win_base_usize_t const size, mk_win_base_dword_t const type, mk_win_base_dword_t const protection) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_memory_management_virtual_free(mk_win_base_void_lpt const address, mk_win_base_usize_t const size, mk_win_base_dword_t const type) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_win_dll_kernel_memory_management.c"
#endif
#endif
