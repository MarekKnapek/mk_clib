#ifndef mk_include_guard_mk_lang_check
#define mk_include_guard_mk_lang_check


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_check_if_failed_impl(mk_lang_bool_t const b) mk_lang_noexcept;


#define mk_lang_check_if_failed(x) mk_lang_check_if_failed_impl(!!!(x))


#if mk_lang_jumbo_want == 1
#include "mk_lang_check.c"
#endif
#endif
