#ifndef mk_include_guard_mk_sl_io_console
#define mk_include_guard_mk_sl_io_console


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_console_write_n(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_console_write_w(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_io_console.c"
#endif
#endif
