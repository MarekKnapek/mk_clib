#ifndef mk_include_guard_mk_lang_jumbo
#define mk_include_guard_mk_lang_jumbo


#if !defined mk_lang_jumbo_want
#if defined NDEBUG
#define mk_lang_jumbo_want 1
#else
#define mk_lang_jumbo_want 0
#endif
#endif

#if mk_lang_jumbo_want == 1
#include "mk_lang_inline.h"
#define mk_lang_jumbo static mk_lang_inline
#elif mk_lang_jumbo_want == 0
#include "mk_lang_inline.h"
#define mk_lang_jumbo mk_lang_inline
#endif


#endif
