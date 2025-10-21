include(`mk_lib_crypto_alg.m')dnl
#ifndef mk_include_guard_mk_lib_crypto_mode_pcbc_h
#define mk_include_guard_mk_lib_crypto_mode_pcbc_h

#include "mk_lang_jumbo.h"

mk_lib_crypto_alg_mm_for_all_nl(`#include "mk_lib_crypto_alg_$1.h"`'')dnl


mk_lib_crypto_alg_mm_for_all_sep_nl(`dnl
#define mk_lib_crypto_mode_pcbc_t_name mk_lib_crypto_mode_pcbc_$1
#define mk_lib_crypto_mode_pcbc_t_base_name mk_lib_crypto_alg_$1
#include "mk_lib_crypto_mode_pcbc_inl_fileh.h"
#include "mk_lib_crypto_mode_pcbc_inl_fileu.h"
#define mk_lib_crypto_mode_pcbc_$1_iv_len_d (mk_lib_crypto_alg_$1_msg_len_d)
#define mk_lib_crypto_mode_pcbc_$1_msg_len_d (mk_lib_crypto_alg_$1_msg_len_d)
#define mk_lib_crypto_mode_pcbc_$1_key_len_d (mk_lib_crypto_alg_$1_key_len_d)
#define mk_lib_crypto_mode_pcbc_$1_schedule_len_d (mk_lib_crypto_alg_$1_schedule_len_d)
')`'dnl


#if mk_lang_jumbo_have
#include "mk_lib_crypto_mode_pcbc.c"
#endif
#endif
