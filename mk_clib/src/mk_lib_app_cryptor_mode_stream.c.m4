include(`mk_mm_nl.m')dnl
include(`mk_lib_app_cryptor_mode_stream.m')dnl
#ifndef mk_include_guard_mk_lib_app_cryptor_mode_stream_c
#define mk_include_guard_mk_lib_app_cryptor_mode_stream_c
#include "mk_lib_app_cryptor_mode_stream.h"


mk_lib_app_cryptor_mode_stream_mm_for_all(`dnl
#include "mk_lib_crypto_mode_$1.h"
#define mk_lib_crypto_mode_stream_t_name mk_lib_app_cryptor_mode_stream_$1_$3
#define mk_lib_crypto_mode_stream_t_base_name mk_lib_crypto_mode_$1_$3
#include "mk_lib_crypto_mode_stream_inl_filec.h"
#include "mk_lib_crypto_mode_stream_inl_fileu.h"
mk_mm_nl()dnl
')dnl

#endif
