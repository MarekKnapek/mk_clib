#include "mk_sl_io_writer_file_windows.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"
#include "mk_win_kernel_errors.h"
#include "mk_win_kernel_files.h"
#include "mk_win_kernel_handle.h"


#define mk_sl_io_writer_file_windows_is_valid(x) ((mk_lang_types_bool_t)((x).m_data != mk_lang_null))


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_windows_open_n(mk_sl_io_writer_file_windows_pt const writer, mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	mk_sl_io_writer_file_windows_handle_t handle;

	mk_lang_assert(writer);
	mk_lang_assert(name && name[0] != '\0');

	handle = mk_win_kernel_files_a_create_file(name, mk_win_advapi_base_right_generic_e_write, mk_win_kernel_files_share_e_delete, mk_win_base_null, mk_win_kernel_files_create_e_create_always, mk_win_kernel_files_attribute_e_normal, mk_win_base_handle_get_null()); mk_lang_check_return(handle.m_data != mk_win_base_handle_invalid);
	writer->m_file_handle = handle;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_windows_open_w(mk_sl_io_writer_file_windows_pt const writer, mk_lang_types_wchar_pct const name) mk_lang_noexcept
{
	mk_sl_io_writer_file_windows_handle_t handle;

	mk_lang_assert(writer);
	mk_lang_assert(name && name[0] != L'\0');

	handle = mk_win_kernel_files_w_create_file(name, mk_win_advapi_base_right_generic_e_write, mk_win_kernel_files_share_e_delete, mk_win_base_null, mk_win_kernel_files_create_e_create_always, mk_win_kernel_files_attribute_e_normal, mk_win_base_handle_get_null()); mk_lang_check_return(handle.m_data != mk_win_base_handle_invalid);
	writer->m_file_handle = handle;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_windows_write(mk_sl_io_writer_file_windows_pt const writer, mk_sl_cui_uint8_pct const buf, mk_lang_types_usize_t const len, mk_lang_types_usize_pt const written) mk_lang_noexcept
{
	mk_win_base_bool_t ret;
	mk_win_base_dword_t w;

	mk_lang_assert(writer);
	mk_lang_assert(buf);
	mk_lang_assert(len >= 1);
	mk_lang_assert(written);
	mk_lang_assert(mk_sl_io_writer_file_windows_is_valid(writer->m_file_handle));

	ret = mk_win_kernel_files_write_file(writer->m_file_handle, buf, ((mk_win_base_dword_t)(len)), &w, mk_win_base_null); mk_lang_check_return(ret != mk_win_base_false);
	*written = ((mk_lang_types_usize_t)(w));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_windows_close(mk_sl_io_writer_file_windows_pt const writer) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	mk_lang_assert(writer);
	mk_lang_assert(mk_sl_io_writer_file_windows_is_valid(writer->m_file_handle));

	ret = mk_win_kernel_handle_close_handle(writer->m_file_handle); mk_lang_check_return(ret != mk_win_base_false);
	return 0;
}