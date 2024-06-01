#ifndef mk_include_guard_mk_lib_mt_thread_name
#define mk_include_guard_mk_lib_mt_thread_name


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_name_set(mk_lang_types_pchar_pct const name) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_thread_name.c"
#endif
#endif
