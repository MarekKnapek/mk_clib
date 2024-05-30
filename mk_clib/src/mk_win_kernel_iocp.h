#ifndef mk_include_guard_mk_win_kernel_iocp
#define mk_include_guard_mk_win_kernel_iocp


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


struct mk_win_kernel_files_overlapped_s;
typedef struct mk_win_kernel_files_overlapped_s mk_win_kernel_files_overlapped_t;
typedef mk_win_kernel_files_overlapped_t const mk_win_kernel_files_overlapped_ct;
typedef mk_win_kernel_files_overlapped_t* mk_win_kernel_files_overlapped_pt;
typedef mk_win_kernel_files_overlapped_t const* mk_win_kernel_files_overlapped_pct;
typedef mk_win_kernel_files_overlapped_t mk_win_base_far* mk_win_kernel_files_overlapped_lpt;
typedef mk_win_kernel_files_overlapped_t mk_win_base_far const* mk_win_kernel_files_overlapped_lpct;
typedef mk_win_kernel_files_overlapped_t mk_win_base_near* mk_win_kernel_files_overlapped_npt;
typedef mk_win_kernel_files_overlapped_t mk_win_base_near const* mk_win_kernel_files_overlapped_npct;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_iocp_create(mk_win_base_handle_t const file, mk_win_base_handle_t const existing_iocp, mk_win_base_usize_t const key, mk_win_base_dword_t const concurrency) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_iocp_get_status(mk_win_base_handle_t const iocp, mk_win_base_dword_lpt const bytes_transfered, mk_win_base_usize_lpt const key, mk_win_kernel_files_overlapped_lpt* const overlapped, mk_win_base_dword_t const timeout) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_iocp_post(mk_win_base_handle_t const iocp, mk_win_base_dword_t const bytes_transfered, mk_win_base_usize_t const key, mk_win_kernel_files_overlapped_lpt const overlapped) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_iocp.c"
#endif
#endif
