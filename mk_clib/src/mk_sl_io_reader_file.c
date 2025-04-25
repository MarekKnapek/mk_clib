#ifndef mk_include_guard_mk_sl_io_reader_file_c
#define mk_include_guard_mk_sl_io_reader_file_c
#include "mk_sl_io_reader_file.h"

#include "mk_lang_assert.h"
#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_tchar.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


#if mk_lang_platform_is_windows_at_least_any
#include "mk_sl_io_reader_file_windows.h"
#define mk_sl_io_reader_file_impl_open_n   mk_sl_io_reader_file_windows_open_n
#define mk_sl_io_reader_file_impl_open_w   mk_sl_io_reader_file_windows_open_w
#define mk_sl_io_reader_file_impl_read     mk_sl_io_reader_file_windows_read
#define mk_sl_io_reader_file_impl_seek_rel mk_sl_io_reader_file_windows_seek_rel
#define mk_sl_io_reader_file_impl_close    mk_sl_io_reader_file_windows_close
#elif mk_lang_platform_is_linux
#include "mk_sl_io_reader_file_linux.h"
#define mk_sl_io_reader_file_impl_open_n   mk_sl_io_reader_file_linux_open_n
#define mk_sl_io_reader_file_impl_open_w   mk_sl_io_reader_file_linux_open_w
#define mk_sl_io_reader_file_impl_read     mk_sl_io_reader_file_linux_read
#define mk_sl_io_reader_file_impl_seek_rel mk_sl_io_reader_file_linux_seek_rel
#define mk_sl_io_reader_file_impl_close    mk_sl_io_reader_file_linux_close
#elif mk_lang_platform_is_posix_at_least_any
#include "mk_sl_io_reader_file_posix.h"
#define mk_sl_io_reader_file_impl_open_n   mk_sl_io_reader_file_posix_open_n
#define mk_sl_io_reader_file_impl_open_w   mk_sl_io_reader_file_posix_open_w
#define mk_sl_io_reader_file_impl_read     mk_sl_io_reader_file_posix_read
#define mk_sl_io_reader_file_impl_seek_rel mk_sl_io_reader_file_posix_seek_rel
#define mk_sl_io_reader_file_impl_close    mk_sl_io_reader_file_posix_close
#elif mk_lang_platform_is_portable
#include "mk_sl_io_reader_file_portable.h"
#define mk_sl_io_reader_file_impl_open_n   mk_sl_io_reader_file_portable_open_n
#define mk_sl_io_reader_file_impl_open_w   mk_sl_io_reader_file_portable_open_w
#define mk_sl_io_reader_file_impl_read     mk_sl_io_reader_file_portable_read
#define mk_sl_io_reader_file_impl_seek_rel mk_sl_io_reader_file_portable_seek_rel
#define mk_sl_io_reader_file_impl_close    mk_sl_io_reader_file_portable_close
#else
#error xxxxxxxxxx
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_open_n(mk_sl_io_reader_file_pt const reader, mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(reader);

	ret = mk_sl_io_reader_file_impl_open_n(&reader->m_file_handle, name);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_open_w(mk_sl_io_reader_file_pt const reader, mk_lang_types_wchar_pct const name) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(reader);

	ret = mk_sl_io_reader_file_impl_open_w(&reader->m_file_handle, name);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_open_t(mk_sl_io_reader_file_pt const reader, mk_lang_tchar_pct const name) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(reader);

	ret = mk_lang_concat(mk_sl_io_reader_file_impl_open_, mk_lang_tchar_suffix)(&reader->m_file_handle, name);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_read(mk_sl_io_reader_file_pt const reader, mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_lang_types_sint_pt const read) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(reader);

	ret = mk_sl_io_reader_file_impl_read(&reader->m_file_handle, buf, len, read);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_seek_rel(mk_sl_io_reader_file_pt const reader, mk_lang_types_slong_t const offset) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(reader);

	ret = mk_sl_io_reader_file_impl_seek_rel(&reader->m_file_handle, offset);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_close(mk_sl_io_reader_file_pt const reader) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(reader);

	ret = mk_sl_io_reader_file_impl_close(&reader->m_file_handle);
	return ret;
}


#endif
