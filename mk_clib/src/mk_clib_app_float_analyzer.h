#ifndef mk_include_guard_mk_clib_app_float_analyzer
#define mk_include_guard_mk_clib_app_float_analyzer


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_float_analyzer(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_clib_app_float_analyzer.c"
#endif
#endif
