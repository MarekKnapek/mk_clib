#ifndef mk_include_guard_mk_win_sl_file_istream
#define mk_include_guard_mk_win_sl_file_istream


#include "mk_lang_exception.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


struct mk_win_sl_file_istream_s
{
	mk_win_base_handle_t m_handle;
};
typedef struct mk_win_sl_file_istream_s mk_win_sl_file_istream_t;
typedef mk_win_sl_file_istream_t const mk_win_sl_file_istream_ct;
typedef mk_win_sl_file_istream_t* mk_win_sl_file_istream_pt;
typedef mk_win_sl_file_istream_t const* mk_win_sl_file_istream_pct;


mk_lang_jumbo void mk_win_sl_file_istream_ro_destroy(mk_win_sl_file_istream_pct const istream) mk_lang_noexcept;

mk_lang_jumbo void mk_win_sl_file_istream_rw_destroy(mk_win_sl_file_istream_pt const istream) mk_lang_noexcept;

mk_lang_jumbo void mk_win_sl_file_istream_rw_construct(mk_win_sl_file_istream_pt const istream, mk_win_base_handle_t const handle) mk_lang_noexcept;
mk_lang_jumbo void mk_win_sl_file_istream_rw_read(mk_win_sl_file_istream_pt const istream, mk_lang_exception_pt const ex, mk_lang_types_void_pt const destination, mk_lang_types_usize_t const requested_bytes, mk_lang_types_usize_pt const read_bytes) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_sl_file_istream.c"
#endif
#endif
