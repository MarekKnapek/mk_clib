#ifndef mk_include_guard_mk_clib_app_cryptor_h
#define mk_include_guard_mk_clib_app_cryptor_h


#include "mk_lang_entry_point.h"
#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#if mk_lang_entry_point_have


mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t mk_clib_app_cryptor_peb(mk_lang_types_void_pt const peb) mk_lang_noexcept;


#else


mk_lang_extern_c mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_cryptor_args(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_clib_app_cryptor.c"
#endif
#endif
