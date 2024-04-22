#include "mk_sl_io_reader_file_portable.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"

#include <stdio.h>


#define mk_sl_io_reader_file_portable_is_valid(x) ((mk_lang_types_bool_t)((x) != mk_lang_null))


mk_lang_jumbo mk_lang_types_void_t mk_sl_io_reader_file_portable_open_n(mk_sl_io_reader_file_portable_pt const reader, mk_lang_types_pchar_pct const name, mk_lang_types_sint_pt const err) mk_lang_noexcept
{
	mk_sl_io_reader_file_portable_handle_t handle;

	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');
	mk_lang_assert(err);

	handle = fopen(name, "rb");
	if(handle)
	{
		reader->m_file_handle = handle;
		*err = mk_sl_io_reader_file_portable_err_e_ok;
	}
	else
	{
		*err = mk_sl_io_reader_file_portable_err_e_err;
	}
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_io_reader_file_portable_open_w(mk_sl_io_reader_file_portable_pt const reader, mk_lang_types_wchar_pct const name, mk_lang_types_sint_pt const err) mk_lang_noexcept
{
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2005 /* todo: sooner? */
	mk_sl_io_reader_file_portable_handle_t handle;

	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != L'\0');
	mk_lang_assert(err);

	handle = _wfopen(name, L"rb");
	if(handle)
	{
		reader->m_file_handle = handle;
		*err = mk_sl_io_reader_file_portable_err_e_ok;
	}
	else
	{
		*err = mk_sl_io_reader_file_portable_err_e_err;
	}
#else
	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != L'\0');
	mk_lang_assert(err);

	mk_lang_assert(mk_lang_false);
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_io_reader_file_portable_read(mk_sl_io_reader_file_portable_pt const reader, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const len, mk_lang_types_usize_pt const read, mk_lang_types_sint_pt const err) mk_lang_noexcept
{
	mk_lang_types_usize_t base_read;
	mk_lang_types_sint_t base_eof;
	mk_lang_types_sint_t base_err;

	mk_lang_assert(reader);
	mk_lang_assert(buf);
	mk_lang_assert(len >= 0);
	mk_lang_assert(read);
	mk_lang_assert(err);
	mk_lang_assert(mk_sl_io_reader_file_portable_is_valid(reader->m_file_handle));

	base_read = fread(buf, 1, len, reader->m_file_handle);
	if(base_read != 0)
	{
		*read = base_read;
		*err = mk_sl_io_reader_file_portable_err_e_ok;
	}
	else
	{
		base_eof = feof(reader->m_file_handle);
		if(base_eof == 0)
		{
			base_err = ferror(reader->m_file_handle);
			if(base_err == 0)
			{
				*read = base_read;
				*err = mk_sl_io_reader_file_portable_err_e_ok;
			}
			else
			{
				*err = mk_sl_io_reader_file_portable_err_e_err;
			}
		}
		else
		{
			*err = mk_sl_io_reader_file_portable_err_e_eof;
		}
	}
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_io_reader_file_portable_seek_rel(mk_sl_io_reader_file_portable_pt const reader, mk_lang_types_slong_t const offset, mk_lang_types_sint_pt const err) mk_lang_noexcept
{
	mk_lang_types_sint_t base_ret;

	mk_lang_assert(reader);
	mk_lang_assert(err);
	mk_lang_assert(mk_sl_io_reader_file_portable_is_valid(reader->m_file_handle));

	base_ret = fseek(reader->m_file_handle, offset, SEEK_CUR);
	*err = base_ret == 0 ? mk_sl_io_reader_file_portable_err_e_ok : mk_sl_io_reader_file_portable_err_e_err;
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_io_reader_file_portable_close(mk_sl_io_reader_file_portable_pt const reader) mk_lang_noexcept
{
	mk_lang_types_sint_t base_ret;

	mk_lang_assert(reader);
	mk_lang_assert(mk_sl_io_reader_file_portable_is_valid(reader->m_file_handle));

	base_ret = fclose(reader->m_file_handle);
	mk_lang_assert(base_ret == 0);
}
