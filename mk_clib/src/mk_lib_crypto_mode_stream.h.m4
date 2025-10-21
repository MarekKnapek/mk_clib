#ifndef mk_include_guard_mk_lib_crypto_mode_stream_h
#define mk_include_guard_mk_lib_crypto_mode_stream_h


#include "mk_lang_jumbo.h"


define(`mk_lib_crypto_mode_stream_h_mm_one', `dnl
#include "mk_lib_crypto_mode_$1.h"
#define mk_lib_crypto_mode_stream_t_name mk_lib_crypto_mode_stream_$1_$2
#define mk_lib_crypto_mode_stream_t_base_name mk_lib_crypto_mode_$1_$2
#include "mk_lib_crypto_mode_stream_inl_fileh.h"
#include "mk_lib_crypto_mode_stream_inl_fileu.h"
#define mk_lib_crypto_mode_stream_$1_$2_iv_len_d (mk_lib_crypto_mode_$1_$2_iv_len_d)
#define mk_lib_crypto_mode_stream_$1_$2_key_len_d (mk_lib_crypto_mode_$1_$2_key_len_d)
#define mk_lib_crypto_mode_stream_$1_$2_msg_len_d (mk_lib_crypto_mode_$1_$2_msg_len_d)


')dnl
define(`mk_lib_crypto_mode_stream_h_mm_many', `dnl
ifelse(`$#', `1', `', `dnl
mk_lib_crypto_mode_stream_h_mm_one($1, $2, $3)dnl
mk_lib_crypto_mode_stream_h_mm_many(shift(shift(shift($@))))dnl
')`'dnl
')dnl
include(`mk_lib_crypto_mode_stream.m')dnl
mk_lib_crypto_mode_stream_h_mm_many(mk_lib_crypto_mode_stream_mm_list())dnl
dnl
dnl
#if mk_lang_jumbo_have
#include "mk_lib_crypto_mode_stream.c"
#endif
#endif
