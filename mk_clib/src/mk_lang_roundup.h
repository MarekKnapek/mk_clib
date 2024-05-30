#ifndef mk_include_guard_mk_lang_roundup
#define mk_include_guard_mk_lang_roundup


#include "mk_lang_types.h"


#define mk_lang_roundup_size(a, b) ((a) + ((b) - 1))
#define mk_lang_roundup_roundup(a, b) ((mk_lang_roundup_size((a), (b)) / (b)) * (b))
#define mk_lang_roundup_align_ptr(a, b) ((mk_lang_types_void_pt)(mk_lang_roundup_roundup(((mk_lang_types_uintptr_t)((a))), (b))))


#endif
