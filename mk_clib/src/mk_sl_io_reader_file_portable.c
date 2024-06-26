#include "mk_sl_io_reader_file_portable.h"

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
#include "mk_sl_io_transaction_portable.h"
#include "mk_sl_uint8.h"

#include <stdio.h> /* fopen fclose fread fseek SEEK_CUR _wfopen */


#define mk_sl_io_reader_file_portable_is_valid(x) ((mk_lang_types_bool_t)((x) != mk_lang_null))


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_portable_open_n(mk_sl_io_reader_file_portable_pt const reader, mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	mk_sl_io_reader_file_portable_handle_t handle;

	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');

	handle = fopen(name, "rb"); mk_lang_check_return(handle);
	reader->m_file_handle = handle;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_portable_open_w(mk_sl_io_reader_file_portable_pt const reader, mk_lang_types_wchar_pct const name) mk_lang_noexcept
{
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2005 /* todo: sooner? */
	mk_sl_io_reader_file_portable_handle_t handle;

	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != L'\0');

	handle = _wfopen(name, L"rb"); mk_lang_check_return(handle);
	reader->m_file_handle = handle;
	return 0;
#else
	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != L'\0');

	mk_lang_assert(mk_lang_false);
	mk_lang_check_return(mk_lang_false);
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_portable_open_tx_n(mk_sl_io_reader_file_portable_pt const reader, mk_lang_types_pchar_pct const name, mk_sl_io_transaction_portable_pt const tx) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');
	mk_lang_assert(tx);

	mk_lang_check_return(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_portable_open_tx_w(mk_sl_io_reader_file_portable_pt const reader, mk_lang_types_wchar_pct const name, mk_sl_io_transaction_portable_pt const tx) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');
	mk_lang_assert(tx);

	mk_lang_check_return(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_portable_read(mk_sl_io_reader_file_portable_pt const reader, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const len, mk_lang_types_usize_pt const read) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(buf);
	mk_lang_assert(len >= 1);
	mk_lang_assert(read);
	mk_lang_assert(mk_sl_io_reader_file_portable_is_valid(reader->m_file_handle));

	*read = fread(buf, 1, len, reader->m_file_handle);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_portable_seek_rel(mk_sl_io_reader_file_portable_pt const reader, mk_lang_types_slong_t const offset) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(reader);
	mk_lang_assert(offset != 0);
	mk_lang_assert(mk_sl_io_reader_file_portable_is_valid(reader->m_file_handle));

	ret = fseek(reader->m_file_handle, offset, SEEK_CUR); mk_lang_check_return(ret == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_portable_close(mk_sl_io_reader_file_portable_pt const reader) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(reader);
	mk_lang_assert(mk_sl_io_reader_file_portable_is_valid(reader->m_file_handle));

	ret = fclose(reader->m_file_handle); mk_lang_check_return(ret == 0);
	return 0;
}
