#ifndef mk_include_guard_lang_clamp
#define mk_include_guard_lang_clamp


#include "mk_lang_max.h"
#include "mk_lang_min.h"


#define mk_lang_clamp(x, lo, hi) mk_lang_min(mk_lang_max(lo, x), hi)


#endif
