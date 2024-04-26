#ifndef mk_include_guard_mk_sl_io_reader_file
#define mk_include_guard_mk_sl_io_reader_file


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_os.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


#if mk_lang_os == mk_lang_os_windows
#include "mk_sl_io_reader_file_windows.h"
typedef mk_sl_io_reader_file_windows_t mk_sl_io_reader_file_handle_t;
#elif mk_lang_os == mk_lang_os_c
#include "mk_sl_io_reader_file_portable.h"
typedef mk_sl_io_reader_file_portable_t mk_sl_io_reader_file_handle_t;
#else
#error xxxxxxxxxx todo
#endif


struct mk_sl_io_reader_file_s
{
	mk_sl_io_reader_file_handle_t m_file_handle;
};
typedef struct mk_sl_io_reader_file_s mk_sl_io_reader_file_t;
typedef mk_sl_io_reader_file_t const mk_sl_io_reader_file_ct;
typedef mk_sl_io_reader_file_t* mk_sl_io_reader_file_pt;
typedef mk_sl_io_reader_file_t* mk_lang_restrict mk_sl_io_reader_file_prt;
typedef mk_sl_io_reader_file_t const* mk_sl_io_reader_file_pct;
typedef mk_sl_io_reader_file_t const* mk_lang_restrict mk_sl_io_reader_file_prct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_open_n(mk_sl_io_reader_file_pt const reader, mk_lang_types_pchar_pct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_open_w(mk_sl_io_reader_file_pt const reader, mk_lang_types_wchar_pct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_read(mk_sl_io_reader_file_pt const reader, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const len, mk_lang_types_usize_pt const read) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_seek_rel(mk_sl_io_reader_file_pt const reader, mk_lang_types_slong_t const offset) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_close(mk_sl_io_reader_file_pt const reader) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_io_reader_file.c"
#endif
#endif
