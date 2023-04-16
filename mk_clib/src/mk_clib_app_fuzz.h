#ifndef mk_include_guard_clib_app_fuzz
#define mk_include_guard_clib_app_fuzz


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"


mk_lang_jumbo int mk_clib_app_fuzz(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept;
mk_lang_jumbo mk_lang_size_t mk_clib_app_fuzz_mutate(unsigned char* const data, mk_lang_size_t const size, mk_lang_size_t const size_max, unsigned const seed) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_clib_app_fuzz.c"
#endif
#endif
