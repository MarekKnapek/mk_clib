#include "mk_sl_io_reader_file_windows.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_platform.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_sl_io_transaction_windows.h"
#include "mk_sl_uint8.h"
#include "mk_win_kernel_errors.h"
#include "mk_win_kernel_files.h"
#include "mk_win_kernel_handle.h"
#include "mk_win_ktmw32_transaction.h"


#if mk_lang_platform == mk_lang_platform_windows


#define mk_sl_io_reader_file_windows_is_valid(x) ((mk_lang_types_bool_t)((x).m_data != mk_lang_null))


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_windows_open_n(mk_sl_io_reader_file_windows_pt const reader, mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	mk_sl_io_reader_file_windows_handle_t handle;

	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');

	handle = mk_win_kernel_files_a_create_file(name, mk_win_advapi_base_right_generic_e_read, mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_delete, mk_win_base_null, mk_win_kernel_files_create_e_open_existing, mk_win_kernel_files_flag_e_sequential_scan, mk_win_base_handle_get_null()); mk_lang_check_return(handle.m_data != mk_win_base_handle_invalid);
	reader->m_file_handle = handle;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_windows_open_w(mk_sl_io_reader_file_windows_pt const reader, mk_lang_types_wchar_pct const name) mk_lang_noexcept
{
	mk_sl_io_reader_file_windows_handle_t handle;

	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != L'\0');

	handle = mk_win_kernel_files_w_create_file(name, mk_win_advapi_base_right_generic_e_read, mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_delete, mk_win_base_null, mk_win_kernel_files_create_e_open_existing, mk_win_kernel_files_flag_e_sequential_scan, mk_win_base_handle_get_null()); mk_lang_check_return(handle.m_data != mk_win_base_handle_invalid);
	reader->m_file_handle = handle;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_windows_open_tx_n(mk_sl_io_reader_file_windows_pt const reader, mk_lang_types_pchar_pct const name, mk_sl_io_transaction_windows_pt const tx) mk_lang_noexcept
{
	mk_win_base_ushort_t mv;
	mk_sl_io_reader_file_windows_handle_t handle;

	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');
	mk_lang_assert(tx && tx->m_transaction.m_data);

	mv = mk_win_ktmw32_transaction_txfs_miniversion_view_e_committed;
	handle = mk_win_ktmw32_transaction_a_create_file_transacted(name, mk_win_advapi_base_right_generic_e_read, mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_delete, mk_win_base_null, mk_win_kernel_files_create_e_open_existing, mk_win_kernel_files_flag_e_sequential_scan, mk_win_base_handle_get_null(), tx->m_transaction, &mv, mk_win_base_null); mk_lang_check_return(handle.m_data != mk_win_base_handle_invalid);
	reader->m_file_handle = handle;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_windows_open_tx_w(mk_sl_io_reader_file_windows_pt const reader, mk_lang_types_wchar_pct const name, mk_sl_io_transaction_windows_pt const tx) mk_lang_noexcept
{
	mk_win_base_ushort_t mv;
	mk_sl_io_reader_file_windows_handle_t handle;

	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');
	mk_lang_assert(tx && tx->m_transaction.m_data);

	mv = mk_win_ktmw32_transaction_txfs_miniversion_view_e_committed;
	handle = mk_win_ktmw32_transaction_w_create_file_transacted(name, mk_win_advapi_base_right_generic_e_read, mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_delete, mk_win_base_null, mk_win_kernel_files_create_e_open_existing, mk_win_kernel_files_flag_e_sequential_scan, mk_win_base_handle_get_null(), tx->m_transaction, &mv, mk_win_base_null); mk_lang_check_return(handle.m_data != mk_win_base_handle_invalid);
	reader->m_file_handle = handle;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_windows_read(mk_sl_io_reader_file_windows_pt const reader, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const len, mk_lang_types_usize_pt const read) mk_lang_noexcept
{
	mk_win_base_bool_t ret;
	mk_win_base_dword_t r;

	mk_lang_assert(reader);
	mk_lang_assert(buf);
	mk_lang_assert(len >= 1);
	mk_lang_assert(read);
	mk_lang_assert(mk_sl_io_reader_file_windows_is_valid(reader->m_file_handle));

	ret = mk_win_kernel_files_read_file(reader->m_file_handle, buf, ((mk_win_base_dword_t)(len)), &r, mk_win_base_null); mk_lang_check_return(ret != mk_win_base_false);
	*read = ((mk_lang_types_usize_t)(r));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_windows_seek_rel(mk_sl_io_reader_file_windows_pt const reader, mk_lang_types_slong_t const offset) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	mk_lang_assert(reader);
	mk_lang_assert(offset != 0);
	mk_lang_assert(mk_sl_io_reader_file_windows_is_valid(reader->m_file_handle));

	ret = mk_win_kernel_files_set_file_pointer(reader->m_file_handle, ((mk_win_base_slong_t)(offset)), mk_win_base_null, mk_win_kernel_files_move_method_e_current); mk_lang_check_return(ret != s_mk_win_kernel_files_invalid_set_file_pointer || mk_win_kernel_errors_get_last() != mk_win_kernel_errors_id_e_success);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_windows_close(mk_sl_io_reader_file_windows_pt const reader) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	mk_lang_assert(reader);
	mk_lang_assert(mk_sl_io_reader_file_windows_is_valid(reader->m_file_handle));

	ret = mk_win_kernel_handle_close_handle(reader->m_file_handle); mk_lang_check_return(ret != mk_win_base_false);
	return 0;
}


#else


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_portable_open_n(mk_sl_io_reader_file_portable_pt const reader, mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');

	mk_lang_check_return(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_portable_open_w(mk_sl_io_reader_file_portable_pt const reader, mk_lang_types_wchar_pct const name) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != L'\0');

	mk_lang_check_return(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_portable_read(mk_sl_io_reader_file_portable_pt const reader, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const len, mk_lang_types_usize_pt const read) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(buf);
	mk_lang_assert(len >= 1);
	mk_lang_assert(read);

	mk_lang_check_return(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_portable_seek_rel(mk_sl_io_reader_file_portable_pt const reader, mk_lang_types_slong_t const offset) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(offset != 0);

	mk_lang_check_return(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_portable_close(mk_sl_io_reader_file_portable_pt const reader) mk_lang_noexcept
{
	mk_lang_assert(reader);

	mk_lang_check_return(mk_lang_false);
	return 0;
}


#endif
