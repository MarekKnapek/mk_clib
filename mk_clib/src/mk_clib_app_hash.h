#ifndef mk_include_guard_mk_clib_app_hash_h
#define mk_include_guard_mk_clib_app_hash_h


#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_extern_c mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_hash_args(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_clib_app_hash.c"
#endif
#endif
