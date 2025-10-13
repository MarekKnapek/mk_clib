#ifndef mk_include_guard_mk_sl_io_directory_iterator_windows_c
#define mk_include_guard_mk_sl_io_directory_iterator_windows_c
#include "mk_sl_io_directory_iterator_windows.h"

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


mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_io_directory_iterator_windows_prrw_is_valid(mk_sl_io_directory_iterator_windows_handle_t const handle) mk_lang_noexcept
{
	mk_lang_types_bool_t is;

	is = !mk_win_base_handle_is_invalid(handle);
	return is;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_prrw_construct_void(mk_sl_io_directory_iterator_windows_pt const directory_iterator) mk_lang_noexcept
{
	mk_lang_assert(directory_iterator);

	directory_iterator->m_handle = mk_win_base_handle_get_invalid();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_prrw_construct(mk_sl_io_directory_iterator_windows_pt const directory_iterator, mk_lang_types_pchar_pct const path) mk_lang_noexcept
{
	mk_sl_io_directory_iterator_windows_handle_t handle;

	mk_lang_assert(directory_iterator);
	mk_lang_assert(path);
	mk_lang_assert(path[0] != '\0');

	handle = mk_win_dll_kernel_files_a_find_first_file(path, &directory_iterator->m_data); mk_lang_check_return(mk_sl_io_directory_iterator_windows_prrw_is_valid(handle));
	directory_iterator->m_handle = handle;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_prrw_destroy(mk_sl_io_directory_iterator_windows_pt const directory_iterator) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(directory_iterator);

	if(mk_sl_io_directory_iterator_windows_prrw_is_valid(directory_iterator->m_handle))
	{
		b = mk_win_dll_kernel_files_find_close(directory_iterator->m_handle); mk_lang_check_return(b != 0);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_prrw_reset(mk_sl_io_directory_iterator_windows_pt const directory_iterator) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(directory_iterator);

	err = mk_sl_io_directory_iterator_windows_prrw_destroy(directory_iterator); mk_lang_check_rereturn(err);
	err = mk_sl_io_directory_iterator_windows_prrw_construct_void(directory_iterator); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_prrw_get_name(mk_sl_io_directory_iterator_windows_pt const directory_iterator, mk_lang_types_pchar_ppct const name) mk_lang_noexcept
{
	mk_lang_assert(directory_iterator);
	mk_lang_assert(name);
	mk_lang_assert(mk_sl_io_directory_iterator_windows_prrw_is_valid(directory_iterator->m_handle));

	*name = &directory_iterator->m_data.m_name[0];
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_prrw_next(mk_sl_io_directory_iterator_windows_pt const directory_iterator) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_dword_t err;

	mk_lang_assert(directory_iterator);
	mk_lang_assert(mk_sl_io_directory_iterator_windows_prrw_is_valid(directory_iterator->m_handle));

	b = mk_win_dll_kernel_files_a_find_next_file(directory_iterator->m_handle, &directory_iterator->m_data); mk_lang_check_return((b != 0) || ((b == 0) && ((err = mk_win_dll_kernel_errors_get_last()) == mk_win_dll_kernel_errors_id_e_no_more_files)));
	directory_iterator->m_is_end = b == 0;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_prrw_is_end(mk_sl_io_directory_iterator_windows_pt const directory_iterator, mk_lang_types_bool_pt const is) mk_lang_noexcept
{
	mk_lang_assert(directory_iterator);
	mk_lang_assert(is);
	mk_lang_assert(mk_sl_io_directory_iterator_windows_prrw_is_valid(directory_iterator->m_handle));

	*is = directory_iterator->m_is_end;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_rw_construct_void(mk_sl_io_directory_iterator_windows_pt const directory_iterator) mk_lang_noexcept
{
	return mk_sl_io_directory_iterator_windows_prrw_construct_void(directory_iterator);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_rw_construct(mk_sl_io_directory_iterator_windows_pt const directory_iterator, mk_lang_types_pchar_pct const path) mk_lang_noexcept
{
	return mk_sl_io_directory_iterator_windows_prrw_construct(directory_iterator, path);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_rw_destroy(mk_sl_io_directory_iterator_windows_pt const directory_iterator) mk_lang_noexcept
{
	return mk_sl_io_directory_iterator_windows_prrw_destroy(directory_iterator);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_rw_reset(mk_sl_io_directory_iterator_windows_pt const directory_iterator) mk_lang_noexcept
{
	return mk_sl_io_directory_iterator_windows_prrw_reset(directory_iterator);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_rw_get_name(mk_sl_io_directory_iterator_windows_pt const directory_iterator, mk_lang_types_pchar_ppct const name) mk_lang_noexcept
{
	return mk_sl_io_directory_iterator_windows_prrw_get_name(directory_iterator, name);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_rw_next(mk_sl_io_directory_iterator_windows_pt const directory_iterator) mk_lang_noexcept
{
	return mk_sl_io_directory_iterator_windows_prrw_next(directory_iterator);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_rw_is_end(mk_sl_io_directory_iterator_windows_pt const directory_iterator, mk_lang_types_bool_pt const is) mk_lang_noexcept
{
	return mk_sl_io_directory_iterator_windows_prrw_is_end(directory_iterator, is);
}


#else
static void mk_sl_io_directory_iterator_windows_dummy(void){}
#endif
#endif
