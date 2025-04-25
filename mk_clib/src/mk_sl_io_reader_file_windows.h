#ifndef mk_include_guard_mk_sl_io_reader_file_windows_h
#define mk_include_guard_mk_sl_io_reader_file_windows_h


#include "mk_lang_jumbo.h"
#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any


#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"
#include "mk_win_base.h"


typedef mk_win_base_handle_t mk_sl_io_reader_file_windows_handle_t;

struct mk_sl_io_reader_file_windows_s
{
	mk_sl_io_reader_file_windows_handle_t m_file_handle;
};
typedef struct mk_sl_io_reader_file_windows_s mk_sl_io_reader_file_windows_t;
mk_lang_typedef(mk_sl_io_reader_file_windows);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_windows_open_n(mk_sl_io_reader_file_windows_pt const reader, mk_lang_types_pchar_pct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_windows_open_w(mk_sl_io_reader_file_windows_pt const reader, mk_lang_types_wchar_pct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_windows_read(mk_sl_io_reader_file_windows_pt const reader, mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_lang_types_sint_pt const read) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_windows_seek_rel(mk_sl_io_reader_file_windows_pt const reader, mk_lang_types_slong_t const offset) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_windows_close(mk_sl_io_reader_file_windows_pt const reader) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_sl_io_reader_file_windows.c"
#endif
#endif
