#ifndef mk_include_guard_mk_sl_cui_uint64_h
#define mk_include_guard_mk_sl_cui_uint64_h


#include "mk_lang_charbit.h"
#include "mk_lang_endian.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"


#if mk_lang_charbit == 8 && mk_lang_sizeof_bi_ulong_t == 8

#define mk_lang_bui_t_name mk_sl_cui_uint64_zzz_base
#define mk_lang_bui_t_base ulong
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_fileu.h"
#define mk_sl_cui_uint64_zzz_base_size_bits_d (mk_lang_sizeof_bi_ulong_t * mk_lang_charbit)

#define mk_sl_cui_t_name mk_sl_cui_uint64
#define mk_sl_cui_t_base mk_sl_cui_uint64_zzz_base
#define mk_sl_cui_t_count (64 / mk_sl_cui_uint64_zzz_base_size_bits_d)
#define mk_sl_cui_t_endian mk_lang_endian_native
#define mk_sl_cui_t_disable_big_div 0
#define mk_sl_cui_t_base_size_bits_d mk_sl_cui_uint64_zzz_base_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_sl_cui_uint64_size_bits_d 64
#define mk_sl_cui_uint64_size_bytes_d (mk_sl_cui_uint64_size_bits_d / mk_lang_charbit)
#define mk_sl_cui_uint64_c(a, b) {{ ((mk_sl_cui_uint64_zzz_base_t)(((mk_sl_cui_uint64_zzz_base_t)(((mk_sl_cui_uint64_zzz_base_t)(a)) << 32)) | ((mk_sl_cui_uint64_zzz_base_t)(b)))) }}

#elif mk_lang_charbit == 8 && mk_lang_sizeof_bi_ullong_t == 8

#define mk_lang_bui_t_name mk_sl_cui_uint64_zzz_base
#define mk_lang_bui_t_base ullong
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_fileu.h"
#define mk_sl_cui_uint64_zzz_base_size_bits_d (mk_lang_sizeof_bi_ullong_t * mk_lang_charbit)

#define mk_sl_cui_t_name mk_sl_cui_uint64
#define mk_sl_cui_t_base mk_sl_cui_uint64_zzz_base
#define mk_sl_cui_t_count (64 / mk_sl_cui_uint64_zzz_base_size_bits_d)
#define mk_sl_cui_t_endian mk_lang_endian_native
#define mk_sl_cui_t_disable_big_div 0
#define mk_sl_cui_t_base_size_bits_d mk_sl_cui_uint64_zzz_base_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_sl_cui_uint64_size_bits_d 64
#define mk_sl_cui_uint64_size_bytes_d (mk_sl_cui_uint64_size_bits_d / mk_lang_charbit)
#define mk_sl_cui_uint64_c(a, b) {{ ((mk_sl_cui_uint64_zzz_base_t)(((mk_sl_cui_uint64_zzz_base_t)(((mk_sl_cui_uint64_zzz_base_t)(a)) << 32)) | ((mk_sl_cui_uint64_zzz_base_t)(b)))) }}

#elif mk_lang_charbit == 8 && mk_lang_sizeof_bi_uint_t == 4

#define mk_lang_bui_t_name mk_sl_cui_uint64_zzz_base
#define mk_lang_bui_t_base uint
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_fileu.h"
#define mk_sl_cui_uint64_zzz_base_size_bits_d (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)

#define mk_sl_cui_t_name mk_sl_cui_uint64
#define mk_sl_cui_t_base mk_sl_cui_uint64_zzz_base
#define mk_sl_cui_t_count (64 / mk_sl_cui_uint64_zzz_base_size_bits_d)
#define mk_sl_cui_t_endian mk_lang_endian_native
#define mk_sl_cui_t_disable_big_div 0
#define mk_sl_cui_t_base_size_bits_d mk_sl_cui_uint64_zzz_base_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_sl_cui_uint64_size_bits_d 64
#define mk_sl_cui_uint64_size_bytes_d (mk_sl_cui_uint64_size_bits_d / mk_lang_charbit)
#define mk_sl_cui_uint64_c(a, b) {{ ((mk_sl_cui_uint64_zzz_base_t)(b)), ((mk_sl_cui_uint64_zzz_base_t)(a)) }}

#elif mk_lang_charbit == 8 && mk_lang_sizeof_bi_ulong_t == 4

#define mk_lang_bui_t_name mk_sl_cui_uint64_zzz_base
#define mk_lang_bui_t_base ulong
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_fileu.h"
#define mk_sl_cui_uint64_zzz_base_size_bits_d (mk_lang_sizeof_bi_ulong_t * mk_lang_charbit)

#define mk_sl_cui_t_name mk_sl_cui_uint64
#define mk_sl_cui_t_base mk_sl_cui_uint64_zzz_base
#define mk_sl_cui_t_count (64 / mk_sl_cui_uint64_zzz_base_size_bits_d)
#define mk_sl_cui_t_endian mk_lang_endian_native
#define mk_sl_cui_t_disable_big_div 0
#define mk_sl_cui_t_base_size_bits_d mk_sl_cui_uint64_zzz_base_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_sl_cui_uint64_size_bits_d 64
#define mk_sl_cui_uint64_size_bytes_d (mk_sl_cui_uint64_size_bits_d / mk_lang_charbit)
#define mk_sl_cui_uint64_c(a, b) {{ ((mk_sl_cui_uint64_zzz_base_t)(b)), ((mk_sl_cui_uint64_zzz_base_t)(a)) }}

#else

#error xxxxxxxxxx

#endif


#if mk_lang_jumbo_have == 1
#include "mk_sl_cui_uint64.c"
#endif
#endif
