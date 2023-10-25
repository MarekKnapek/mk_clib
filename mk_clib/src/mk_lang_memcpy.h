#ifndef mk_include_guard_mk_lang_memcpy
#define mk_include_guard_mk_lang_memcpy


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"


mk_lang_jumbo void mk_lang_memcpy(void* const mk_lang_restrict dst, void const* const mk_lang_restrict src, mk_lang_types_usize_t const cnt) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lang_memcpy.c"
#endif
#endif
