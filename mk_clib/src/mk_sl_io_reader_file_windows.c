#ifndef mk_include_guard_mk_sl_io_reader_file_windows_c
#define mk_include_guard_mk_sl_io_reader_file_windows_c
#include "mk_sl_io_reader_file_windows.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"
#include "mk_win_dll_advapi.h"
#include "mk_win_dll_kernel_errors.h"
#include "mk_win_dll_kernel_files.h"
#include "mk_win_dll_kernel_handle.h"


#define mk_sl_io_reader_file_windows_is_valid(x) (!mk_win_base_handle_is_invalid(x))


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_windows_open_n(mk_sl_io_reader_file_windows_pt const reader, mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	mk_sl_io_reader_file_windows_handle_t handle;

	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');

	handle = mk_win_dll_kernel_files_a_create_file(name, ((mk_win_base_dword_t)(mk_win_dll_advapi_right_generic_e_read)), mk_win_dll_kernel_files_share_e_read | mk_win_dll_kernel_files_share_e_delete, mk_win_base_null, mk_win_dll_kernel_files_create_e_open_existing, mk_win_dll_kernel_files_flag_e_none, mk_win_base_handle_get_null()); mk_lang_check_return(mk_sl_io_reader_file_windows_is_valid(handle));
	reader->m_file_handle = handle;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_windows_open_w(mk_sl_io_reader_file_windows_pt const reader, mk_lang_types_wchar_pct const name) mk_lang_noexcept
{
	mk_sl_io_reader_file_windows_handle_t handle;

	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != L'\0');

	handle = mk_win_dll_kernel_files_w_create_file(name, ((mk_win_base_dword_t)(mk_win_dll_advapi_right_generic_e_read)), mk_win_dll_kernel_files_share_e_read | mk_win_dll_kernel_files_share_e_delete, mk_win_base_null, mk_win_dll_kernel_files_create_e_open_existing, mk_win_dll_kernel_files_flag_e_none, mk_win_base_handle_get_null()); mk_lang_check_return(mk_sl_io_reader_file_windows_is_valid(handle));
	reader->m_file_handle = handle;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_windows_read(mk_sl_io_reader_file_windows_pt const reader, mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_lang_types_sint_pt const read) mk_lang_noexcept
{
	mk_win_base_bool_t ret;
	mk_win_base_dword_t r;

	mk_lang_assert(reader);
	mk_lang_assert(buf);
	mk_lang_assert(len >= 1);
	mk_lang_assert(read);
	mk_lang_assert(mk_sl_io_reader_file_windows_is_valid(reader->m_file_handle));

	ret = mk_win_dll_kernel_files_read_file(reader->m_file_handle, buf, ((mk_win_base_dword_t)(len)), &r, mk_win_base_null); mk_lang_check_return(ret != 0);
	*read = ((mk_lang_types_sint_t)(r));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_windows_seek_rel(mk_sl_io_reader_file_windows_pt const reader, mk_lang_types_slong_t const offset) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	mk_lang_assert(reader);
	mk_lang_assert(offset != 0);
	mk_lang_assert(mk_sl_io_reader_file_windows_is_valid(reader->m_file_handle));

	ret = mk_win_dll_kernel_files_set_file_pointer(reader->m_file_handle, ((mk_win_base_slong_t)(offset)), mk_win_base_null, mk_win_dll_kernel_files_move_method_e_current); mk_lang_check_return(ret != s_mk_win_dll_kernel_files_invalid_set_file_pointer || mk_win_dll_kernel_errors_get_last() == mk_win_dll_kernel_errors_id_e_success);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_windows_close(mk_sl_io_reader_file_windows_pt const reader) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	mk_lang_assert(reader);
	mk_lang_assert(mk_sl_io_reader_file_windows_is_valid(reader->m_file_handle));

	ret = mk_win_dll_kernel_handle_close(reader->m_file_handle); mk_lang_check_return(ret != 0);
	return 0;
}


#endif
#endif
