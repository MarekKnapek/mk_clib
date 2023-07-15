#ifndef mk_include_guard_mk_clib_app_crypt
#define mk_include_guard_mk_clib_app_crypt


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"


mk_lang_nodiscard mk_lang_jumbo int mk_clib_app_crypt_args(int const argc, char const* const* const argv) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_clib_app_crypt.c"
#endif
#endif
