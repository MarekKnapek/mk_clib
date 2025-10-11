#ifndef mk_include_guard_mk_sl_io_writer_file_c
#define mk_include_guard_mk_sl_io_writer_file_c
#include "mk_sl_io_writer_file.h"

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
#include "mk_sl_io_writer_file_windows.h"
#define mk_sl_io_writer_file_base mk_sl_io_writer_file_windows
#elif mk_lang_platform_is_linux
#include "mk_sl_io_writer_file_linux.h"
#define mk_sl_io_writer_file_base mk_sl_io_writer_file_linux
#elif mk_lang_platform_is_posix_at_least_any
#include "mk_sl_io_writer_file_posix.h"
#define mk_sl_io_writer_file_base mk_sl_io_writer_file_posix
#elif mk_lang_platform_is_portable
#include "mk_sl_io_writer_file_portable.h"
#define mk_sl_io_writer_file_base mk_sl_io_writer_file_portable
#else
#error xxxxxxxxxx
#endif
#define mk_sl_io_writer_file_impl_rw_construct_void mk_lang_concat(mk_sl_io_writer_file_base, _rw_construct_void)
#define mk_sl_io_writer_file_impl_open_n            mk_lang_concat(mk_sl_io_writer_file_base, _open_n)
#define mk_sl_io_writer_file_impl_open_w            mk_lang_concat(mk_sl_io_writer_file_base, _open_w)
#define mk_sl_io_writer_file_impl_write             mk_lang_concat(mk_sl_io_writer_file_base, _write)
#define mk_sl_io_writer_file_impl_close             mk_lang_concat(mk_sl_io_writer_file_base, _close)
#define mk_sl_io_writer_file_impl_rw_reset          mk_lang_concat(mk_sl_io_writer_file_base, _rw_reset)
#define mk_sl_io_writer_file_impl_open_t mk_lang_concat(mk_lang_concat(mk_sl_io_writer_file_base, _open_), mk_lang_tchar_suffix)


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_rw_construct_void(mk_sl_io_writer_file_pt const writer) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(writer);

	ret = mk_sl_io_writer_file_impl_rw_construct_void(&writer->m_file_handle);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_open_n(mk_sl_io_writer_file_pt const writer, mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(writer);

	ret = mk_sl_io_writer_file_impl_open_n(&writer->m_file_handle, name);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_open_w(mk_sl_io_writer_file_pt const writer, mk_lang_types_wchar_pct const name) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(writer);

	ret = mk_sl_io_writer_file_impl_open_w(&writer->m_file_handle, name);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_open_t(mk_sl_io_writer_file_pt const writer, mk_lang_tchar_pct const name) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(writer);

	ret = mk_sl_io_writer_file_impl_open_t(&writer->m_file_handle, name);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_write(mk_sl_io_writer_file_pt const writer, mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_lang_types_sint_pt const written) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(writer);

	ret = mk_sl_io_writer_file_impl_write(&writer->m_file_handle, buf, len, written);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_close(mk_sl_io_writer_file_pt const writer) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(writer);

	ret = mk_sl_io_writer_file_impl_close(&writer->m_file_handle);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_rw_reset(mk_sl_io_writer_file_pt const writer) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(writer);

	ret = mk_sl_io_writer_file_impl_rw_reset(&writer->m_file_handle);
	return ret;
}


#endif
