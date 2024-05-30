#include "mk_win_kernel_iocp.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_files.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateIoCompletionPort(mk_win_base_handle_t const file, mk_win_base_handle_t const existing_iocp, mk_win_base_usize_t const key, mk_win_base_dword_t const concurrency) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetQueuedCompletionStatus(mk_win_base_handle_t const iocp, mk_win_base_dword_lpt const bytes_transfered, mk_win_base_usize_lpt const key, mk_win_kernel_files_overlapped_lpt* const overlapped, mk_win_base_dword_t const timeout) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall PostQueuedCompletionStatus(mk_win_base_handle_t const iocp, mk_win_base_dword_t const bytes_transfered, mk_win_base_usize_t const key, mk_win_kernel_files_overlapped_lpt const overlapped) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_iocp_create(mk_win_base_handle_t const file, mk_win_base_handle_t const existing_iocp, mk_win_base_usize_t const key, mk_win_base_dword_t const concurrency) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = CreateIoCompletionPort(file, existing_iocp, key, concurrency);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_iocp_get_status(mk_win_base_handle_t const iocp, mk_win_base_dword_lpt const bytes_transfered, mk_win_base_usize_lpt const key, mk_win_kernel_files_overlapped_lpt* const overlapped, mk_win_base_dword_t const timeout) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = GetQueuedCompletionStatus(iocp, bytes_transfered, key, overlapped, timeout);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_iocp_post(mk_win_base_handle_t const iocp, mk_win_base_dword_t const bytes_transfered, mk_win_base_usize_t const key, mk_win_kernel_files_overlapped_lpt const overlapped) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = PostQueuedCompletionStatus(iocp, bytes_transfered, key, overlapped);
	return ret;
}
