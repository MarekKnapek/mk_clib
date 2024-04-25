#include "mk_sl_io_writer_file_portable.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"

#include <stdio.h> /* fopen fclose fwrite _wfopen */


#define mk_sl_io_writer_file_portable_is_valid(x) ((mk_lang_types_bool_t)((x) != mk_lang_null))


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_portable_open_n(mk_sl_io_writer_file_portable_pt const writer, mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	mk_sl_io_writer_file_portable_handle_t handle;

	mk_lang_assert(writer);
	mk_lang_assert(name && name[0] != '\0');

	handle = fopen(name, "wb"); mk_lang_check_return(handle);
	writer->m_file_handle = handle;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_portable_open_w(mk_sl_io_writer_file_portable_pt const writer, mk_lang_types_wchar_pct const name) mk_lang_noexcept
{
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2005 /* todo: sooner? */
	mk_sl_io_writer_file_portable_handle_t handle;

	mk_lang_assert(writer);
	mk_lang_assert(name && name[0] != L'\0');

	handle = _wfopen(name, L"wb"); mk_lang_check_return(handle);
	writer->m_file_handle = handle;
	return 0;
#else
	mk_lang_assert(writer);
	mk_lang_assert(name && name[0] != L'\0');

	mk_lang_assert(mk_lang_false);
	mk_lang_check_return(mk_lang_false);
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_portable_write(mk_sl_io_writer_file_portable_pt const writer, mk_sl_cui_uint8_pct const buf, mk_lang_types_usize_t const len, mk_lang_types_usize_pt const written) mk_lang_noexcept
{
	mk_lang_assert(writer);
	mk_lang_assert(buf);
	mk_lang_assert(len >= 1);
	mk_lang_assert(written);
	mk_lang_assert(mk_sl_io_writer_file_portable_is_valid(writer->m_file_handle));

	*written = fwrite(buf, 1, len, writer->m_file_handle);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_portable_close(mk_sl_io_writer_file_portable_pt const writer) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(writer);
	mk_lang_assert(mk_sl_io_writer_file_portable_is_valid(writer->m_file_handle));

	ret = fclose(writer->m_file_handle); mk_lang_check_return(ret == 0);
	return 0;
}
