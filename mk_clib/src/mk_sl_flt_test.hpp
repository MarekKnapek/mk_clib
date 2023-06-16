#ifndef mk_include_guard_mk_sl_flt_test
#define mk_include_guard_mk_sl_flt_test


#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"


mk_lang_extern_c void mk_sl_flt_test(void) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_flt_test.cpp"
#endif
#endif
