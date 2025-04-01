#ifndef mk_include_guard_mk_lang_roundup_h
#define mk_include_guard_mk_lang_roundup_h


#include "mk_lang_types.h"


#define mk_lang_roundup_add(a, b) ((a) + ((b) - 1))
#define mk_lang_roundup_div(a, b) (mk_lang_roundup_add((a), (b)) / (b))
#define mk_lang_roundup_mul(a, b) (mk_lang_roundup_div((a), (b)) * (b))
#define mk_lang_roundup_align(a, b) (mk_lang_roundup_mul(((mk_lang_types_uintptr_t)((a))), (b)))


#endif
