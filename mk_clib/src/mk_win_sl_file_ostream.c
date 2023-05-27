#include "mk_win_sl_file_ostream.h"

#include "mk_lang_assert.h"
#include "mk_lang_exception.h"
#include "mk_win_sl_exception_gle.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_errors.h"
#include "mk_win_kernel_files.h"


mk_lang_jumbo void mk_win_sl_file_ostream_ro_destroy(mk_win_sl_file_ostream_pct const ostream) mk_lang_noexcept
{
	mk_lang_assert(ostream);
}


mk_lang_jumbo void mk_win_sl_file_ostream_rw_destroy(mk_win_sl_file_ostream_pt const ostream) mk_lang_noexcept
{
	mk_win_sl_file_ostream_ro_destroy(ostream);
}


mk_lang_jumbo void mk_win_sl_file_ostream_rw_construct(mk_win_sl_file_ostream_pt const ostream, mk_win_base_handle_t const handle) mk_lang_noexcept
{
	mk_lang_assert(ostream);
	mk_lang_assert(handle != s_mk_win_base_handle_invalid);

	ostream->m_handle = handle;
}

mk_lang_jumbo void mk_win_sl_file_ostream_rw_write(mk_win_sl_file_ostream_pt const ostream, mk_lang_exception_pt const ex, mk_lang_types_void_pct const source, mk_lang_types_usize_t const bytes_to_write, mk_lang_types_usize_pt const bytes_written) mk_lang_noexcept
{
	mk_win_base_bool_t write;
	mk_win_base_dword_t bytes_written_;

	mk_lang_assert(ostream);
	mk_lang_assert(ex);
	mk_lang_assert(bytes_to_write <= mk_win_base_limits_dword_max);

	write = mk_win_kernel_files_write_file(ostream->m_handle, source, ((mk_win_base_dword_t)(bytes_to_write)), &bytes_written_, mk_win_base_null);
	if(write == 0)
	{
		mk_win_sl_exception_gle_make_from_current(ex);
		return;
	}
	*bytes_written = ((mk_lang_types_usize_t)(bytes_written_));
}
