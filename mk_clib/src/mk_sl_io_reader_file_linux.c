#ifndef mk_include_guard_mk_sl_io_reader_file_linux_c
#define mk_include_guard_mk_sl_io_reader_file_linux_c
#include "mk_sl_io_reader_file_linux.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_linux

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"

#include <fcntl.h> /* open */
#include <unistd.h> /* read lseek close */


#define mk_sl_io_reader_file_linux_is_valid(x) ((x) >= 0)


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_linux_open_n(mk_sl_io_reader_file_linux_pt const reader, mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	mk_sl_io_reader_file_linux_handle_t handle;

	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');

	handle = open(name, O_RDONLY | O_CLOEXEC); mk_lang_check_return(handle >= 0);
	reader->m_file_handle = handle;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_linux_open_w(mk_sl_io_reader_file_linux_pt const reader, mk_lang_types_wchar_pct const name) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != L'\0');

	mk_lang_assert(mk_lang_false);
	mk_lang_check_return(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_linux_read(mk_sl_io_reader_file_linux_pt const reader, mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_lang_types_sint_pt const read_) mk_lang_noexcept
{
	ssize_t r;

	mk_lang_assert(reader);
	mk_lang_assert(buf);
	mk_lang_assert(len >= 1);
	mk_lang_assert(read);
	mk_lang_assert(mk_sl_io_reader_file_linux_is_valid(reader->m_file_handle));

	r = read(reader->m_file_handle, buf, len); mk_lang_check_return(r >= 0);
	*read_ = ((mk_lang_types_sint_t)(r));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_linux_seek_rel(mk_sl_io_reader_file_linux_pt const reader, mk_lang_types_slong_t const offset) mk_lang_noexcept
{
	off_t r;

	mk_lang_assert(reader);
	mk_lang_assert(offset != 0);
	mk_lang_assert(mk_sl_io_reader_file_linux_is_valid(reader->m_file_handle));

	r = lseek(reader->m_file_handle, ((off_t)(offset)), SEEK_CUR); mk_lang_check_return(r != ((off_t)(-1)));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_linux_close(mk_sl_io_reader_file_linux_pt const reader) mk_lang_noexcept
{
	int r;

	mk_lang_assert(reader);
	mk_lang_assert(mk_sl_io_reader_file_linux_is_valid(reader->m_file_handle));

	r = close(reader->m_file_handle); mk_lang_check_return(r == 0);
	return 0;
}


#else
static void mk_sl_io_reader_file_linux_dummy(void);
#endif
#endif
