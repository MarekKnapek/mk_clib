#include "mk_sl_io_async_reader_file_windows.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"
#include "mk_win_base.h"
#include "mk_win_kernel_errors.h"
#include "mk_win_kernel_files.h"
#include "mk_win_kernel_handle.h"
#include "mk_win_ktmw32_transaction.h"


#if mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60
#define mk_sl_io_async_reader_file_windows_tx_has 1
#include "mk_sl_io_transaction_windows.h"
#elif mk_lang_platform == mk_lang_platform_windows || mk_lang_platform == mk_lang_platform_linux || mk_lang_platform == mk_lang_platform_portable
#define mk_sl_io_async_reader_file_windows_tx_has 0
#include "mk_sl_io_transaction_portable.h"
#else
#error xxxxxxxxxx todo
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_windows_open_n(mk_sl_io_async_reader_file_windows_pt const reader, mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	mk_win_base_handle_t file;

	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');

	file = mk_win_kernel_files_a_create_file(name, mk_win_advapi_base_right_generic_e_read, mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_delete, mk_win_base_null, mk_win_kernel_files_create_e_open_existing, ((mk_win_base_dword_t)(mk_win_kernel_files_attribute_e_normal)) | ((mk_win_base_dword_t)(mk_win_kernel_files_flag_e_sequential_scan | mk_win_kernel_files_flag_e_overlapped)), mk_win_base_handle_get_null()); mk_lang_check_return(file.m_data != mk_win_base_handle_invalid);
	reader->m_file = file;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_windows_open_w(mk_sl_io_async_reader_file_windows_pt const reader, mk_lang_types_wchar_pct const name) mk_lang_noexcept
{
	mk_win_base_handle_t file;

	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != L'\0');

	file = mk_win_kernel_files_w_create_file(name, mk_win_advapi_base_right_generic_e_read, mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_delete, mk_win_base_null, mk_win_kernel_files_create_e_open_existing, ((mk_win_base_dword_t)(mk_win_kernel_files_attribute_e_normal)) | ((mk_win_base_dword_t)(mk_win_kernel_files_flag_e_sequential_scan | mk_win_kernel_files_flag_e_overlapped)), mk_win_base_handle_get_null()); mk_lang_check_return(file.m_data != mk_win_base_handle_invalid);
	reader->m_file = file;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_windows_open_tx_n(mk_sl_io_async_reader_file_windows_pt const reader, mk_lang_types_pchar_pct const name, mk_sl_io_async_reader_file_windows_transaction_pt const tx) mk_lang_noexcept
{
#if mk_sl_io_async_reader_file_windows_tx_has
	mk_win_base_ushort_t mv;
	mk_win_base_handle_t file;

	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');
	mk_lang_assert(tx && tx->m_transaction.m_data);

	if(tx->m_transaction.m_data != mk_win_base_handle_invalid)
	{
		mv = mk_win_ktmw32_transaction_txfs_miniversion_view_e_committed;
		file = mk_win_ktmw32_transaction_a_create_file_transacted(name, mk_win_advapi_base_right_generic_e_read, mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_delete, mk_win_base_null, mk_win_kernel_files_create_e_open_existing, ((mk_win_base_dword_t)(mk_win_kernel_files_attribute_e_normal)) | ((mk_win_base_dword_t)(mk_win_kernel_files_flag_e_sequential_scan | mk_win_kernel_files_flag_e_overlapped)), mk_win_base_handle_get_null(), tx->m_transaction, &mv, mk_win_base_null); mk_lang_check_return(file.m_data != mk_win_base_handle_invalid);
		reader->m_file = file;
		return 0;
	}
	else
	{
		return mk_lang_check_line;
	}
#else
	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');
	mk_lang_assert(tx);

	((mk_lang_types_void_t)(reader));
	((mk_lang_types_void_t)(name));
	((mk_lang_types_void_t)(tx));
	return mk_lang_check_line;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_windows_open_tx_w(mk_sl_io_async_reader_file_windows_pt const reader, mk_lang_types_wchar_pct const name, mk_sl_io_async_reader_file_windows_transaction_pt const tx) mk_lang_noexcept
{
#if mk_sl_io_async_reader_file_windows_tx_has
	mk_win_base_ushort_t mv;
	mk_win_base_handle_t file;

	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');
	mk_lang_assert(tx && tx->m_transaction.m_data);

	if(tx->m_transaction.m_data != mk_win_base_handle_invalid)
	{
		mv = mk_win_ktmw32_transaction_txfs_miniversion_view_e_committed;
		file = mk_win_ktmw32_transaction_w_create_file_transacted(name, mk_win_advapi_base_right_generic_e_read, mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_delete, mk_win_base_null, mk_win_kernel_files_create_e_open_existing, ((mk_win_base_dword_t)(mk_win_kernel_files_attribute_e_normal)) | ((mk_win_base_dword_t)(mk_win_kernel_files_flag_e_sequential_scan | mk_win_kernel_files_flag_e_overlapped)), mk_win_base_handle_get_null(), tx->m_transaction, &mv, mk_win_base_null); mk_lang_check_return(file.m_data != mk_win_base_handle_invalid);
		reader->m_file = file;
		return 0;
	}
	else
	{
		return mk_lang_check_line;
	}
#else
	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');
	mk_lang_assert(tx);

	((mk_lang_types_void_t)(reader));
	((mk_lang_types_void_t)(name));
	((mk_lang_types_void_t)(tx));
	return mk_lang_check_line;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_windows_request_read(mk_sl_io_async_reader_file_windows_pt const reader, mk_sl_io_async_reader_file_iorp_windows_pt const iorp) mk_lang_noexcept
{
	mk_win_base_bool_t ret;
	mk_win_base_dword_t gle;

	mk_lang_assert(reader);
	mk_lang_assert(reader->m_file.m_data != mk_win_base_handle_invalid);
	mk_lang_assert(iorp);
	mk_lang_assert(iorp->m_buf || iorp->m_len == 0);

	ret = mk_win_kernel_files_read_file(reader->m_file, iorp->m_buf, iorp->m_len, mk_win_base_null, &iorp->m_overlapped); mk_lang_check_return((ret != mk_win_base_false) || ((gle = mk_win_kernel_errors_get_last()) == mk_win_kernel_errors_id_e_io_pending));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_windows_close(mk_sl_io_async_reader_file_windows_pt const reader) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	mk_lang_assert(reader);
	mk_lang_assert(reader->m_file.m_data != mk_win_base_handle_invalid);

	ret = mk_win_kernel_handle_close_handle(reader->m_file); mk_lang_check_return(ret != mk_win_base_false);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_windows_construct_void(mk_sl_io_async_reader_file_iorp_windows_pt const iorp) mk_lang_noexcept
{
	mk_lang_assert(iorp);

	iorp->m_buf = mk_lang_null;
	iorp->m_len = 0;
	iorp->m_overlapped.m_internal_lo = 0;
	iorp->m_overlapped.m_internal_hi = 0;
	iorp->m_overlapped.m_offset_lo = 0;
	iorp->m_overlapped.m_offset_hi = 0;
	iorp->m_overlapped.m_event = mk_win_base_handle_get_null();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_windows_construct_args(mk_sl_io_async_reader_file_iorp_windows_pt const iorp, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const len, mk_sl_cui_uint64_pct const pos) mk_lang_noexcept
{
	mk_lang_types_ulong_t tula;
	mk_lang_types_ulong_t tulb;
	mk_sl_cui_uint64_t ta;

	mk_lang_assert(iorp);
	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= ((mk_win_base_dword_t)(0)) && len <= ((mk_win_base_dword_t)(((mk_win_base_dword_t)(0)) - ((mk_win_base_dword_t)(1)))));
	mk_lang_assert(pos);

	mk_sl_cui_uint64_to_bi_ulong(pos, &tula); mk_sl_cui_uint64_shr3(pos, 32, &ta);
	mk_sl_cui_uint64_to_bi_ulong(&ta, &tulb);
	iorp->m_buf = buf;
	iorp->m_len = ((mk_win_base_dword_t)(len));
	iorp->m_overlapped.m_internal_lo = 0;
	iorp->m_overlapped.m_internal_hi = 0;
	iorp->m_overlapped.m_offset_lo = ((mk_win_base_dword_t)(tula));
	iorp->m_overlapped.m_offset_hi = ((mk_win_base_dword_t)(tulb));
	iorp->m_overlapped.m_event = mk_win_base_handle_get_null();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_windows_reconstruct(mk_sl_io_async_reader_file_iorp_windows_pt const iorp, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const len, mk_sl_cui_uint64_pct const pos) mk_lang_noexcept
{
	return mk_sl_io_async_reader_file_iorp_windows_construct_args(iorp, buf, len, pos);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_windows_buf(mk_sl_io_async_reader_file_iorp_windows_pt const iorp, mk_sl_cui_uint8_pt* const buf) mk_lang_noexcept
{
	mk_lang_assert(iorp);
	mk_lang_assert(buf);

	*buf = iorp->m_buf;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_windows_len(mk_sl_io_async_reader_file_iorp_windows_pt const iorp, mk_lang_types_usize_pt const len) mk_lang_noexcept
{
	mk_lang_assert(iorp);
	mk_lang_assert(len);

	*len = ((mk_lang_types_usize_t)(iorp->m_len));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_windows_pos(mk_sl_io_async_reader_file_iorp_windows_pt const iorp, mk_sl_cui_uint64_pt const pos) mk_lang_noexcept
{
	mk_lang_types_ulong_t tuls[2];

	mk_lang_assert(iorp);
	mk_lang_assert(pos);

	tuls[0] = ((mk_lang_types_ulong_t)(iorp->m_overlapped.m_offset_lo));
	tuls[1] = ((mk_lang_types_ulong_t)(iorp->m_overlapped.m_offset_hi));
	mk_sl_cui_uint64_from_buis_ulong_le(pos, &tuls[0]);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_windows_destroy(mk_sl_io_async_reader_file_iorp_windows_pt const iorp) mk_lang_noexcept
{
	mk_lang_assert(iorp);

	((mk_lang_types_void_t)(iorp));
	return 0;
}
