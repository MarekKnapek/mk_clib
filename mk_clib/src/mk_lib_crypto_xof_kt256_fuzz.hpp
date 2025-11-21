#ifndef mk_include_guard_mk_lib_crypto_xof_kt256_fuzz_hpp
#define mk_include_guard_mk_lib_crypto_xof_kt256_fuzz_hpp


#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t mk_lib_crypto_xof_kt256_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_crypto_xof_kt256_fuzz.cpp"
#endif
#endif
