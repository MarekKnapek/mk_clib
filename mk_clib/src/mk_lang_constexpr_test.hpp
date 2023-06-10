#ifndef mk_include_guard_mk_lang_constexpr_test
#define mk_include_guard_mk_lang_constexpr_test


#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"


mk_lang_extern_c void mk_lang_constexpr_test(void) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lang_constexpr_test.cpp"
#endif
#endif
