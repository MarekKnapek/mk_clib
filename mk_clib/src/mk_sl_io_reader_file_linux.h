#ifndef mk_include_guard_mk_sl_io_reader_file_linux_h
#define mk_include_guard_mk_sl_io_reader_file_linux_h


#include "mk_lang_jumbo.h"
#include "mk_lang_platform.h"
#if mk_lang_platform_is_linux


#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


typedef mk_lang_types_sint_t mk_sl_io_reader_file_linux_handle_t;

struct mk_sl_io_reader_file_linux_s
{
	mk_sl_io_reader_file_linux_handle_t m_file_handle;
};
typedef struct mk_sl_io_reader_file_linux_s mk_sl_io_reader_file_linux_t;
mk_lang_typedef(mk_sl_io_reader_file_linux);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_linux_open_n(mk_sl_io_reader_file_linux_pt const reader, mk_lang_types_pchar_pct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_linux_open_w(mk_sl_io_reader_file_linux_pt const reader, mk_lang_types_wchar_pct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_linux_read(mk_sl_io_reader_file_linux_pt const reader, mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_lang_types_sint_pt const read) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_linux_seek_rel(mk_sl_io_reader_file_linux_pt const reader, mk_lang_types_slong_t const offset) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_linux_close(mk_sl_io_reader_file_linux_pt const reader) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_sl_io_reader_file_linux.c"
#endif
#endif
