#ifndef mk_include_guard_mk_lib_fast_import_h
#define mk_include_guard_mk_lib_fast_import_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fast_import_run(mk_lang_types_void_t) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_fast_import.c"
#endif
#endif
