#ifndef mk_include_guard_mk_sl_cui_uint256_c
#define mk_include_guard_mk_sl_cui_uint256_c
#include "mk_sl_cui_uint256.h"

#include "mk_lang_charbit.h"
#include "mk_lang_endian.h"


#define mk_lang_bui_t_name mk_sl_cui_uint256_zzz_base
#define mk_lang_bui_t_base mk_sl_cui_uint256_base_type_name
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_filec.h"
#include "mk_lang_bui_inl_fileu.h"
#define mk_sl_cui_uint256_zzz_base_size_bits_d (mk_sl_cui_uint256_base_sizeof * mk_lang_charbit)

#define mk_sl_cui_t_name mk_sl_cui_uint256
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint256_zzz_base
#define mk_sl_cui_t_count (256 / mk_sl_cui_uint256_zzz_base_size_bits_d)
#define mk_sl_cui_t_endian mk_lang_endian_native
#define mk_sl_cui_t_disable_big_div 0
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint256_zzz_base_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_lang_memall2_t_name mk_sl_cui_uint256
#define mk_lang_memall2_t_tn mk_sl_cui_uint256
#include "mk_lang_memall2_inl_filec.h"
#include "mk_lang_memall2_inl_fileu.h"


#endif
