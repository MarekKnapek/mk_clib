#ifndef mk_include_guard_sl_cui
#define mk_include_guard_sl_cui


#include "mk_lang_jumbo.h"


#undef mk_sl_cui_inl_file /*todo msvc bug?*/
#define mk_sl_cui_inl_file 1
#include "mk_sl_cui_inl_types.h"


#if mk_lang_jumbo_want == 1
#include "mk_sl_cui.c"
#endif
#endif
