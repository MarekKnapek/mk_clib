include(`mk_lang_concat.m')dnl
ifdef(`mk_lib_crypto_mode_ofb_t_name', `', `define(`mk_lib_crypto_mode_ofb_t_name', `mk_lib_crypto_mode_ofb_t_alg')')dnl
define(`mk_lib_crypto_mode_ofb_full_name', `mk_lang_concat(`mk_lib_crypto_mode_ofb_', mk_lib_crypto_mode_ofb_t_name)')dnl
define(`mk_lib_crypto_mode_ofb_include_guard', `mk_lang_concat(`mk_include_guard_', mk_lib_crypto_mode_ofb_full_name)')dnl
`#ifndef' mk_lib_crypto_mode_ofb_include_guard
`#define' mk_lib_crypto_mode_ofb_include_guard


/* NIST SP 800-38A */


`#define mk_lib_crypto_mode_ofb_t_name' mk_lib_crypto_mode_ofb_t_name
`#define mk_lib_crypto_mode_ofb_t_alg' mk_lib_crypto_mode_ofb_t_alg


#include "mk_lang_jumbo.h"


include(`mk_lib_crypto_mode_ofb_inl_fileh.m')dnl


#undef mk_lib_crypto_mode_ofb_t_name
#undef mk_lib_crypto_mode_ofb_t_alg


#if mk_lang_jumbo_want == 1
`#include' "mk_lib_crypto_mode_ofb_full_name.c"
#endif
#endif
