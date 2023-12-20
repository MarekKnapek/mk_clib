#ifndef mk_include_guard_mk_win_kernel_memory_management
#define mk_include_guard_mk_win_kernel_memory_management


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


enum mk_win_kernel_memory_management_type_e
{
	mk_win_kernel_memory_management_type_e_coalesce_placeholders = 0x00000001ul,
	mk_win_kernel_memory_management_type_e_preserve_placeholder  = 0x00000002ul,
	mk_win_kernel_memory_management_type_e_commit                = 0x00001000ul,
	mk_win_kernel_memory_management_type_e_reserve               = 0x00002000ul,
	mk_win_kernel_memory_management_type_e_decommit              = 0x00004000ul,
	mk_win_kernel_memory_management_type_e_release               = 0x00008000ul,
	mk_win_kernel_memory_management_type_e_reset                 = 0x00080000ul,
	mk_win_kernel_memory_management_type_e_top_down              = 0x00100000ul,
	mk_win_kernel_memory_management_type_e_write_watch           = 0x00200000ul,
	mk_win_kernel_memory_management_type_e_physical              = 0x00400000ul,
	mk_win_kernel_memory_management_type_e_reset_undo            = 0x01000000ul,
	mk_win_kernel_memory_management_type_e_large_pages           = 0x20000000ul,
	mk_win_kernel_memory_management_type_e_dummy_end = 0
};
typedef enum mk_win_kernel_memory_management_type_e mk_win_kernel_memory_management_type_t;

enum mk_win_kernel_memory_management_protect_e
{
	mk_win_kernel_memory_management_protect_e_noaccess                   = 0x00000001ul,
	mk_win_kernel_memory_management_protect_e_readonly                   = 0x00000002ul,
	mk_win_kernel_memory_management_protect_e_readwrite                  = 0x00000004ul,
	mk_win_kernel_memory_management_protect_e_writecopy                  = 0x00000008ul,
	mk_win_kernel_memory_management_protect_e_execute                    = 0x00000010ul,
	mk_win_kernel_memory_management_protect_e_execute_read               = 0x00000020ul,
	mk_win_kernel_memory_management_protect_e_execute_readwrite          = 0x00000040ul,
	mk_win_kernel_memory_management_protect_e_execute_writecopy          = 0x00000080ul,
	mk_win_kernel_memory_management_protect_e_guard                      = 0x00000100ul,
	mk_win_kernel_memory_management_protect_e_nocache                    = 0x00000200ul,
	mk_win_kernel_memory_management_protect_e_writecombine               = 0x00000400ul,
	mk_win_kernel_memory_management_protect_e_graphics_noaccess          = 0x00000800ul,
	mk_win_kernel_memory_management_protect_e_graphics_readonly          = 0x00001000ul,
	mk_win_kernel_memory_management_protect_e_graphics_readwrite         = 0x00002000ul,
	mk_win_kernel_memory_management_protect_e_graphics_execute           = 0x00004000ul,
	mk_win_kernel_memory_management_protect_e_graphics_execute_read      = 0x00008000ul,
	mk_win_kernel_memory_management_protect_e_graphics_execute_readwrite = 0x00010000ul,
	mk_win_kernel_memory_management_protect_e_graphics_coherent          = 0x00020000ul,
	mk_win_kernel_memory_management_protect_e_graphics_nocache           = 0x00040000ul,
	mk_win_kernel_memory_management_protect_e_enclave_mask               = 0x10000000ul,
	mk_win_kernel_memory_management_protect_e_enclave_unvalidated        = 0x20000000ul,
	mk_win_kernel_memory_management_protect_e_targets_invalid            = 0x40000000ul,
	mk_win_kernel_memory_management_protect_e_targets_no_update          = 0x40000000ul,
	mk_win_kernel_memory_management_protect_e_revert_to_file_map         = 0x80000000ul,
	mk_win_kernel_memory_management_protect_e_enclave_thread_control     = 0x80000000ul,
	mk_win_kernel_memory_management_protect_e_enclave_decommit           = (mk_win_kernel_memory_management_protect_e_enclave_mask | 0ul),
	mk_win_kernel_memory_management_protect_e_enclave_ss_first           = (mk_win_kernel_memory_management_protect_e_enclave_mask | 1ul),
	mk_win_kernel_memory_management_protect_e_enclave_ss_rest            = (mk_win_kernel_memory_management_protect_e_enclave_mask | 2ul),
	mk_win_kernel_memory_management_protect_e_dummy_end = 0
};
typedef enum mk_win_kernel_memory_management_protect_e mk_win_kernel_memory_management_protect_t;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpt mk_win_kernel_memory_management_virtual_alloc(mk_win_base_void_lpct const base, mk_win_base_usize_t const size, mk_win_base_dword_t const type, mk_win_base_dword_t const protect) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_memory_management_virtual_free(mk_win_base_void_lpct const base, mk_win_base_usize_t const size, mk_win_base_dword_t const type) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_memory_management.c"
#endif
#endif
