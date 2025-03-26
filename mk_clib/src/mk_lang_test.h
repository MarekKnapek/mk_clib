#ifndef mk_include_guard_mk_lang_test_h
#define mk_include_guard_mk_lang_test_h


#include "mk_lang_crash.h"
#include "mk_lang_debug_break.h"
#include "mk_lang_runtime_bool.h"


#define mk_lang_test(x) do{ if(!(x)){ mk_lang_debug_break(); mk_lang_crash(); } }while(mk_lang_runtime_bool_fn_false)


#endif
