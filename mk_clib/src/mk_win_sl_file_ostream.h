#ifndef mk_include_guard_mk_win_sl_file_ostream
#define mk_include_guard_mk_win_sl_file_ostream


#include "mk_lang_exception.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


struct mk_win_sl_file_ostream_s
{
	mk_win_base_handle_t m_handle;
};
typedef struct mk_win_sl_file_ostream_s mk_win_sl_file_ostream_t;
typedef mk_win_sl_file_ostream_t const mk_win_sl_file_ostream_ct;
typedef mk_win_sl_file_ostream_t* mk_win_sl_file_ostream_pt;
typedef mk_win_sl_file_ostream_t const* mk_win_sl_file_ostream_pct;


mk_lang_jumbo void mk_win_sl_file_ostream_ro_destroy(mk_win_sl_file_ostream_pct const ostream) mk_lang_noexcept;

mk_lang_jumbo void mk_win_sl_file_ostream_rw_destroy(mk_win_sl_file_ostream_pt const ostream) mk_lang_noexcept;

mk_lang_jumbo void mk_win_sl_file_ostream_rw_construct(mk_win_sl_file_ostream_pt const ostream, mk_win_base_handle_t const handle) mk_lang_noexcept;
mk_lang_jumbo void mk_win_sl_file_ostream_rw_write(mk_win_sl_file_ostream_pt const ostream, mk_lang_exception_pt const ex, mk_lang_types_void_pct const source, mk_lang_types_usize_t const bytes_to_write, mk_lang_types_usize_pt const bytes_written) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_sl_file_ostream.c"
#endif
#endif
