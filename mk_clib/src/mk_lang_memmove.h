#ifndef mk_include_guard_mk_lang_memmove
#define mk_include_guard_mk_lang_memmove


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_jumbo void mk_lang_memmove(void* const dst, void const* const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lang_memmove.c"
#endif
#endif
