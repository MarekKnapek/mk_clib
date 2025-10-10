#ifndef mk_include_guard_mk_lib_crypto_alg_stream_c
#define mk_include_guard_mk_lib_crypto_alg_stream_c
#include "mk_lib_crypto_alg_stream.h"


define(`mk_lib_crypto_alg_stream_c_mm_one', `dnl
#define mk_lib_crypto_alg_stream_t_name mk_lib_crypto_alg_stream_$1
#define mk_lib_crypto_alg_stream_t_base_name mk_lib_crypto_alg_$1
#include "mk_lib_crypto_alg_stream_inl_filec.h"
#include "mk_lib_crypto_alg_stream_inl_fileu.h"


')dnl
define(`mk_lib_crypto_alg_stream_c_mm_many', `dnl
ifelse(`$#', `1', `', `dnl
mk_lib_crypto_alg_stream_c_mm_one($1)dnl
mk_lib_crypto_alg_stream_c_mm_many(shift($@))dnl
')`'dnl
')dnl
include(`mk_lib_crypto_alg_stream.m')dnl
mk_lib_crypto_alg_stream_c_mm_many(mk_lib_crypto_alg_stream_mm_half())dnl
dnl
dnl
#endif
