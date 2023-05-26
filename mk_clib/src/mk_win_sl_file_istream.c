#include "mk_win_sl_file_istream.h"

#include "mk_lang_assert.h"
#include "mk_lang_exception.h"
#include "mk_win_sl_exception_gle.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_errors.h"
#include "mk_win_kernel_files.h"


mk_lang_jumbo void mk_win_sl_file_istream_ro_destroy(mk_win_sl_file_istream_pct const istream) mk_lang_noexcept
{
	mk_lang_assert(istream);
}


mk_lang_jumbo void mk_win_sl_file_istream_rw_destroy(mk_win_sl_file_istream_pt const istream) mk_lang_noexcept
{
	mk_win_sl_file_istream_ro_destroy(istream);
}


mk_lang_jumbo void mk_win_sl_file_istream_rw_construct(mk_win_sl_file_istream_pt const istream, mk_win_base_handle_t const handle) mk_lang_noexcept
{
	mk_lang_assert(istream);
	mk_lang_assert(handle != s_mk_win_base_handle_invalid);

	istream->m_handle = handle;
}

mk_lang_jumbo void mk_win_sl_file_istream_rw_read(mk_win_sl_file_istream_pt const istream, mk_lang_exception_pt const ex, mk_lang_types_void_pt const destination, mk_lang_types_usize_t const requested_bytes, mk_lang_types_usize_pt const read_bytes) mk_lang_noexcept
{
	mk_win_base_bool_t read;
	mk_win_base_dword_t read_bytes_;

	mk_lang_assert(istream);
	mk_lang_assert(ex);
	mk_lang_assert(requested_bytes <= mk_win_base_limits_dword_max);

	read = mk_win_kernel_files_read_file(istream->m_handle, destination, ((mk_win_base_dword_t)(requested_bytes)), &read_bytes_, mk_win_base_null);
	if(read == 0)
	{
		mk_win_sl_exception_gle_make_from_current(ex);
		return;
	}
	*read_bytes = ((mk_lang_types_usize_t)(read_bytes_));
}
