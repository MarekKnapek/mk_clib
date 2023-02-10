#ifndef mk_include_guard_lang_bui_fuzz
#define mk_include_guard_lang_bui_fuzz


#include "mk_lang_jumbo.h"
#include "mk_lang_sizet.h"


mk_lang_jumbo void mk_lang_bui_fuzz(unsigned char const* const data, mk_lang_size_t const size);


#if mk_lang_jumbo_want == 1
#include "mk_lang_bui_fuzz.c"
#endif
#endif
