#ifndef mk_include_guard_mk_lib_crypto_mode_stream_c
#define mk_include_guard_mk_lib_crypto_mode_stream_c
#include "mk_lib_crypto_mode_stream.h"


define(`mk_lib_crypto_mode_stream_c_mm_one', `dnl
#include "mk_lib_crypto_mode_$1.h"
#define mk_lib_crypto_mode_stream_t_name mk_lib_crypto_mode_stream_$1_$2
#define mk_lib_crypto_mode_stream_t_base_name mk_lib_crypto_mode_$1_$2
#include "mk_lib_crypto_mode_stream_inl_filec.h"
#include "mk_lib_crypto_mode_stream_inl_fileu.h"


')dnl
define(`mk_lib_crypto_mode_stream_c_mm_many', `dnl
ifelse(`$#', `1', `', `dnl
mk_lib_crypto_mode_stream_c_mm_one($1, $2, $3)dnl
mk_lib_crypto_mode_stream_c_mm_many(shift(shift(shift($@))))dnl
')`'dnl
')dnl
include(`mk_lib_crypto_mode_stream.m')dnl
mk_lib_crypto_mode_stream_c_mm_many(mk_lib_crypto_mode_stream_mm_list())dnl
dnl
dnl
#endif
