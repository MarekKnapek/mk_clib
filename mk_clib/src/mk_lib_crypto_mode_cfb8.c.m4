include(`mk_lib_crypto_alg.m')dnl
#ifndef mk_include_guard_mk_lib_crypto_mode_cfb8_c
#define mk_include_guard_mk_lib_crypto_mode_cfb8_c
#include "mk_lib_crypto_mode_cfb8.h"

mk_lib_crypto_alg_mm_for_all_nl(`#include "mk_lib_crypto_alg_$1.h"`'')dnl


mk_lib_crypto_alg_mm_for_all_sep_nl(`dnl
#define mk_lib_crypto_mode_cfb_t_name mk_lib_crypto_mode_cfb8_$1
#define mk_lib_crypto_mode_cfb_t_base_name mk_lib_crypto_alg_$1
#define mk_lib_crypto_mode_cfb_t_bits 8
#include "mk_lib_crypto_mode_cfb_inl_filec.h"
#include "mk_lib_crypto_mode_cfb_inl_fileu.h"
')`'dnl


#endif
