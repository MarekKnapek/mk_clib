#ifndef mk_include_guard_mk_sl_cui_uint16_c
#define mk_include_guard_mk_sl_cui_uint16_c
#include "mk_sl_cui_uint16.h"

#include "mk_lang_charbit.h"
#include "mk_lang_endian.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"


#if mk_lang_charbit == 8 && mk_lang_sizeof_bi_ushort_t == 2

#define mk_lang_bui_t_name mk_sl_cui_uint16_zzz_base
#define mk_lang_bui_t_base ushort
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_filec.h"
#include "mk_lang_bui_inl_fileu.h"

#define mk_sl_cui_t_name mk_sl_cui_uint16
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint16_zzz_base
#define mk_sl_cui_t_count (16 / mk_sl_cui_uint16_zzz_base_size_bits_d)
#define mk_sl_cui_t_endian mk_lang_endian_native
#define mk_sl_cui_t_disable_big_div 0
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint16_zzz_base_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#else

#error xxxxxxxxxx

#endif


#endif
