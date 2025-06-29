#ifndef mk_include_guard_mk_sl_io_appender_file_h
#define mk_include_guard_mk_sl_io_appender_file_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"

mk_lang_forward(mk_sl_cui_uint8);


#if mk_lang_platform_is_windows_at_least_any
#include "mk_sl_io_appender_file_windows.h"
typedef mk_sl_io_appender_file_windows_t mk_sl_io_appender_file_base_t;
#else
#include "mk_sl_io_appender_file_portable.h"
typedef mk_sl_io_appender_file_portable_t mk_sl_io_appender_file_base_t;
#endif


struct mk_sl_io_appender_file_s
{
	mk_sl_io_appender_file_base_t m_base;
};
typedef struct mk_sl_io_appender_file_s mk_sl_io_appender_file_t;
mk_lang_typedef(mk_sl_io_appender_file);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_appender_file_open_n(mk_sl_io_appender_file_pt const appender, mk_lang_types_pchar_pct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_appender_file_open_w(mk_sl_io_appender_file_pt const appender, mk_lang_types_wchar_pct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_appender_file_append(mk_sl_io_appender_file_pt const appender, mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_lang_types_sint_pt const written) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_appender_file_close(mk_sl_io_appender_file_pt const appender) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_sl_io_appender_file.c"
#endif
#endif
