include(`mk_lib_crypto_alg.m')dnl
#ifndef mk_include_guard_mk_lib_crypto_mode_ctr_n_c
#define mk_include_guard_mk_lib_crypto_mode_ctr_n_c
#include "mk_lib_crypto_mode_ctr_n.h"

mk_lib_crypto_alg_mm_for_all_nl(`#include "mk_lib_crypto_alg_$1.h"`'')dnl


mk_lib_crypto_alg_mm_for_all_sep_nl(`dnl
#define mk_lib_crypto_mode_ctr_n_t_name mk_lib_crypto_mode_ctr_$1_n1
#define mk_lib_crypto_mode_ctr_n_t_base_name mk_lib_crypto_alg_$1
#define mk_lib_crypto_mode_ctr_n_t_count 1
#include "mk_lib_crypto_mode_ctr_n_inl_filec.h"
#include "mk_lib_crypto_mode_ctr_n_inl_fileu.h"
')`'dnl


mk_lib_crypto_alg_mm_for_all_sep_nl(`dnl
#define mk_lib_crypto_mode_ctr_n_t_name mk_lib_crypto_mode_ctr_$1_n2
#define mk_lib_crypto_mode_ctr_n_t_base_name mk_lib_crypto_alg_$1
#define mk_lib_crypto_mode_ctr_n_t_count 2
#include "mk_lib_crypto_mode_ctr_n_inl_filec.h"
#include "mk_lib_crypto_mode_ctr_n_inl_fileu.h"
')`'dnl


mk_lib_crypto_alg_mm_for_all_sep_nl(`dnl
#define mk_lib_crypto_mode_ctr_n_t_name mk_lib_crypto_mode_ctr_$1_n4
#define mk_lib_crypto_mode_ctr_n_t_base_name mk_lib_crypto_alg_$1
#define mk_lib_crypto_mode_ctr_n_t_count 4
#include "mk_lib_crypto_mode_ctr_n_inl_filec.h"
#include "mk_lib_crypto_mode_ctr_n_inl_fileu.h"
')`'dnl


mk_lib_crypto_alg_mm_for_all_sep_nl(`dnl
#define mk_lib_crypto_mode_ctr_n_t_name mk_lib_crypto_mode_ctr_$1_n8
#define mk_lib_crypto_mode_ctr_n_t_base_name mk_lib_crypto_alg_$1
#define mk_lib_crypto_mode_ctr_n_t_count 8
#include "mk_lib_crypto_mode_ctr_n_inl_filec.h"
#include "mk_lib_crypto_mode_ctr_n_inl_fileu.h"
')`'dnl


mk_lib_crypto_alg_mm_for_all_sep_nl(`dnl
#define mk_lib_crypto_mode_ctr_n_t_name mk_lib_crypto_mode_ctr_$1_n16
#define mk_lib_crypto_mode_ctr_n_t_base_name mk_lib_crypto_alg_$1
#define mk_lib_crypto_mode_ctr_n_t_count 16
#include "mk_lib_crypto_mode_ctr_n_inl_filec.h"
#include "mk_lib_crypto_mode_ctr_n_inl_fileu.h"
')`'dnl


mk_lib_crypto_alg_mm_for_all_sep_nl(`dnl
#define mk_lib_crypto_mode_ctr_n_t_name mk_lib_crypto_mode_ctr_$1_n32
#define mk_lib_crypto_mode_ctr_n_t_base_name mk_lib_crypto_alg_$1
#define mk_lib_crypto_mode_ctr_n_t_count 32
#include "mk_lib_crypto_mode_ctr_n_inl_filec.h"
#include "mk_lib_crypto_mode_ctr_n_inl_fileu.h"
')`'dnl


mk_lib_crypto_alg_mm_for_all_sep_nl(`dnl
#define mk_lib_crypto_mode_ctr_n_t_name mk_lib_crypto_mode_ctr_$1_n64
#define mk_lib_crypto_mode_ctr_n_t_base_name mk_lib_crypto_alg_$1
#define mk_lib_crypto_mode_ctr_n_t_count 64
#include "mk_lib_crypto_mode_ctr_n_inl_filec.h"
#include "mk_lib_crypto_mode_ctr_n_inl_fileu.h"
')`'dnl


#endif
