include(`mk_lib_crypto_alg.m')dnl
#ifndef mk_include_guard_mk_lib_crypto_mode_ctr_n_h
#define mk_include_guard_mk_lib_crypto_mode_ctr_n_h

#include "mk_lang_jumbo.h"

mk_lib_crypto_alg_mm_for_all_nl(`#include "mk_lib_crypto_alg_$1.h"`'')dnl


mk_lib_crypto_alg_mm_for_all_sep_nl(`dnl
#define mk_lib_crypto_mode_ctr_n_t_name mk_lib_crypto_mode_ctr_$1_n1
#define mk_lib_crypto_mode_ctr_n_t_base_name mk_lib_crypto_alg_$1
#define mk_lib_crypto_mode_ctr_n_t_count 1
#include "mk_lib_crypto_mode_ctr_n_inl_fileh.h"
#include "mk_lib_crypto_mode_ctr_n_inl_fileu.h"
#define mk_lib_crypto_mode_ctr_$1_n1_iv_len_d (mk_lib_crypto_alg_$1_msg_len_d)
#define mk_lib_crypto_mode_ctr_$1_n1_msg_len_d (mk_lib_crypto_alg_$1_msg_len_d)
#define mk_lib_crypto_mode_ctr_$1_n1_key_len_d (mk_lib_crypto_alg_$1_key_len_d)
#define mk_lib_crypto_mode_ctr_$1_n1_schedule_len_d (mk_lib_crypto_alg_$1_schedule_len_d)
')`'dnl


mk_lib_crypto_alg_mm_for_all_sep_nl(`dnl
#define mk_lib_crypto_mode_ctr_n_t_name mk_lib_crypto_mode_ctr_$1_n2
#define mk_lib_crypto_mode_ctr_n_t_base_name mk_lib_crypto_alg_$1
#define mk_lib_crypto_mode_ctr_n_t_count 2
#include "mk_lib_crypto_mode_ctr_n_inl_fileh.h"
#include "mk_lib_crypto_mode_ctr_n_inl_fileu.h"
#define mk_lib_crypto_mode_ctr_$1_n2_iv_len_d (mk_lib_crypto_alg_$1_msg_len_d)
#define mk_lib_crypto_mode_ctr_$1_n2_msg_len_d (mk_lib_crypto_alg_$1_msg_len_d)
#define mk_lib_crypto_mode_ctr_$1_n2_key_len_d (mk_lib_crypto_alg_$1_key_len_d)
#define mk_lib_crypto_mode_ctr_$1_n2_schedule_len_d (mk_lib_crypto_alg_$1_schedule_len_d)
')`'dnl


mk_lib_crypto_alg_mm_for_all_sep_nl(`dnl
#define mk_lib_crypto_mode_ctr_n_t_name mk_lib_crypto_mode_ctr_$1_n4
#define mk_lib_crypto_mode_ctr_n_t_base_name mk_lib_crypto_alg_$1
#define mk_lib_crypto_mode_ctr_n_t_count 4
#include "mk_lib_crypto_mode_ctr_n_inl_fileh.h"
#include "mk_lib_crypto_mode_ctr_n_inl_fileu.h"
#define mk_lib_crypto_mode_ctr_$1_n4_iv_len_d (mk_lib_crypto_alg_$1_msg_len_d)
#define mk_lib_crypto_mode_ctr_$1_n4_msg_len_d (mk_lib_crypto_alg_$1_msg_len_d)
#define mk_lib_crypto_mode_ctr_$1_n4_key_len_d (mk_lib_crypto_alg_$1_key_len_d)
#define mk_lib_crypto_mode_ctr_$1_n4_schedule_len_d (mk_lib_crypto_alg_$1_schedule_len_d)
')`'dnl


mk_lib_crypto_alg_mm_for_all_sep_nl(`dnl
#define mk_lib_crypto_mode_ctr_n_t_name mk_lib_crypto_mode_ctr_$1_n8
#define mk_lib_crypto_mode_ctr_n_t_base_name mk_lib_crypto_alg_$1
#define mk_lib_crypto_mode_ctr_n_t_count 8
#include "mk_lib_crypto_mode_ctr_n_inl_fileh.h"
#include "mk_lib_crypto_mode_ctr_n_inl_fileu.h"
#define mk_lib_crypto_mode_ctr_$1_n8_iv_len_d (mk_lib_crypto_alg_$1_msg_len_d)
#define mk_lib_crypto_mode_ctr_$1_n8_msg_len_d (mk_lib_crypto_alg_$1_msg_len_d)
#define mk_lib_crypto_mode_ctr_$1_n8_key_len_d (mk_lib_crypto_alg_$1_key_len_d)
#define mk_lib_crypto_mode_ctr_$1_n8_schedule_len_d (mk_lib_crypto_alg_$1_schedule_len_d)
')`'dnl


mk_lib_crypto_alg_mm_for_all_sep_nl(`dnl
#define mk_lib_crypto_mode_ctr_n_t_name mk_lib_crypto_mode_ctr_$1_n16
#define mk_lib_crypto_mode_ctr_n_t_base_name mk_lib_crypto_alg_$1
#define mk_lib_crypto_mode_ctr_n_t_count 16
#include "mk_lib_crypto_mode_ctr_n_inl_fileh.h"
#include "mk_lib_crypto_mode_ctr_n_inl_fileu.h"
#define mk_lib_crypto_mode_ctr_$1_n16_iv_len_d (mk_lib_crypto_alg_$1_msg_len_d)
#define mk_lib_crypto_mode_ctr_$1_n16msg_len_d (mk_lib_crypto_alg_$1_msg_len_d)
#define mk_lib_crypto_mode_ctr_$1_n16key_len_d (mk_lib_crypto_alg_$1_key_len_d)
#define mmk_lib_crypto_mode_ct_$1r_n16schedule_len_d (mk_lib_crypto_alg_$1_schedule_len_d)
')`'dnl


mk_lib_crypto_alg_mm_for_all_sep_nl(`dnl
#define mk_lib_crypto_mode_ctr_n_t_name mk_lib_crypto_mode_ctr_$1_n32
#define mk_lib_crypto_mode_ctr_n_t_base_name mk_lib_crypto_alg_$1
#define mk_lib_crypto_mode_ctr_n_t_count 32
#include "mk_lib_crypto_mode_ctr_n_inl_fileh.h"
#include "mk_lib_crypto_mode_ctr_n_inl_fileu.h"
#define mk_lib_crypto_mode_ctr_$1_n32_iv_len_d (mk_lib_crypto_alg_$1_msg_len_d)
#define mk_lib_crypto_mode_ctr_$1_n32msg_len_d (mk_lib_crypto_alg_$1_msg_len_d)
#define mk_lib_crypto_mode_ctr_$1_n32key_len_d (mk_lib_crypto_alg_$1_key_len_d)
#define mmk_lib_crypto_mode_ct_$1r_n32schedule_len_d (mk_lib_crypto_alg_$1_schedule_len_d)
')`'dnl


mk_lib_crypto_alg_mm_for_all_sep_nl(`dnl
#define mk_lib_crypto_mode_ctr_n_t_name mk_lib_crypto_mode_ctr_$1_n64
#define mk_lib_crypto_mode_ctr_n_t_base_name mk_lib_crypto_alg_$1
#define mk_lib_crypto_mode_ctr_n_t_count 64
#include "mk_lib_crypto_mode_ctr_n_inl_fileh.h"
#include "mk_lib_crypto_mode_ctr_n_inl_fileu.h"
#define mk_lib_crypto_mode_ctr_$1_n64_iv_len_d (mk_lib_crypto_alg_$1_msg_len_d)
#define mk_lib_crypto_mode_ctr_$1_n64msg_len_d (mk_lib_crypto_alg_$1_msg_len_d)
#define mk_lib_crypto_mode_ctr_$1_n64key_len_d (mk_lib_crypto_alg_$1_key_len_d)
#define mmk_lib_crypto_mode_ct_$1r_n64schedule_len_d (mk_lib_crypto_alg_$1_schedule_len_d)
')`'dnl


#if mk_lang_jumbo_have
#include "mk_lib_crypto_mode_ctr_n.c"
#endif
#endif
