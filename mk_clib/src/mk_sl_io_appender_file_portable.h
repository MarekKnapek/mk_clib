#ifndef mk_include_guard_mk_sl_io_appender_file_portable_h
#define mk_include_guard_mk_sl_io_appender_file_portable_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"

#include <stdio.h> /* FILE */

mk_lang_forward(mk_sl_cui_uint8);


typedef FILE* mk_sl_io_appender_file_portable_handle_t;

struct mk_sl_io_appender_file_portable_s
{
	mk_sl_io_appender_file_portable_handle_t m_file_handle;
};
typedef struct mk_sl_io_appender_file_portable_s mk_sl_io_appender_file_portable_t;
mk_lang_typedef(mk_sl_io_appender_file_portable);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_appender_file_portable_open_n(mk_sl_io_appender_file_portable_pt const appender, mk_lang_types_pchar_pct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_appender_file_portable_open_w(mk_sl_io_appender_file_portable_pt const appender, mk_lang_types_wchar_pct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_appender_file_portable_append(mk_sl_io_appender_file_portable_pt const appender, mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_lang_types_sint_pt const written) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_appender_file_portable_close(mk_sl_io_appender_file_portable_pt const appender) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_sl_io_appender_file_portable.c"
#endif
#endif
