include(`mk_mm_nl.m')dnl
include(`mk_lib_app_cryptor_mode_stream.m')dnl
#ifndef mk_include_guard_mk_lib_app_cryptor_mode_stream_h
#define mk_include_guard_mk_lib_app_cryptor_mode_stream_h


#include "mk_lang_jumbo.h"


mk_lib_app_cryptor_mode_stream_mm_for_all(`dnl
#include "mk_lib_crypto_mode_$1.h"
#define mk_lib_crypto_mode_stream_t_name mk_lib_app_cryptor_mode_stream_$1_$3
#define mk_lib_crypto_mode_stream_t_base_name mk_lib_crypto_mode_$1_$3
#include "mk_lib_crypto_mode_stream_inl_fileh.h"
#include "mk_lib_crypto_mode_stream_inl_fileu.h"
#define mk_lib_app_cryptor_mode_stream_$1_$3_iv_len_d (mk_lib_crypto_mode_$1_$3_iv_len_d)
#define mk_lib_app_cryptor_mode_stream_$1_$3_key_len_d (mk_lib_crypto_mode_$1_$3_key_len_d)
#define mk_lib_app_cryptor_mode_stream_$1_$3_msg_len_d (mk_lib_crypto_mode_$1_$3_msg_len_d)
mk_mm_nl()dnl
')dnl

#if mk_lang_jumbo_have
#include "mk_lib_app_cryptor_mode_stream.c"
#endif
#endif
