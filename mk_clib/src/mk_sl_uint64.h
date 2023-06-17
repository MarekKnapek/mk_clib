#ifndef mk_include_guard_mk_sl_uint64
#define mk_include_guard_mk_sl_uint64


#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_types.h"


#if mk_lang_charbit == 8 && mk_lang_sizeof_bi_ulong_t == 8

#define mk_lang_bui_name mk_sl_uint64_ulong
#define mk_lang_bui_type mk_lang_types_ulong_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_ulong_t
#include "mk_lang_bui_inl_fileh.h"
#undef mk_lang_bui_name
#undef mk_lang_bui_type
#undef mk_lang_bui_sizeof

#define mk_sl_cui_name uint64
#define mk_sl_cui_base_type mk_lang_types_ulong_t
#define mk_sl_cui_base_name mk_lang_bui_mk_sl_uint64_ulong
#define mk_sl_cui_base_bits 64
#define mk_sl_cui_count (64 / 64)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn ulong
#include "mk_sl_cui_inl_fileh.h"
#undef mk_sl_cui_name
#undef mk_sl_cui_base_type
#undef mk_sl_cui_base_name
#undef mk_sl_cui_base_bits
#undef mk_sl_cui_count
#undef mk_sl_cui_endian
#undef mk_sl_cui_base_is_bui
#undef mk_sl_cui_base_bui_tn
#define mk_sl_cui_uint64_c(a, b) {{ ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(a)) << 32)) | ((mk_lang_types_ulong_t)(b)))) }}

#elif mk_lang_charbit == 8 && mk_lang_sizeof_bi_ullong_t == 8

#define mk_lang_bui_name mk_sl_uint64_ullong
#define mk_lang_bui_type mk_lang_types_ullong_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_ullong_t
#include "mk_lang_bui_inl_fileh.h"
#undef mk_lang_bui_name
#undef mk_lang_bui_type
#undef mk_lang_bui_sizeof

#define mk_sl_cui_name uint64
#define mk_sl_cui_base_type mk_lang_types_ullong_t
#define mk_sl_cui_base_name mk_lang_bui_mk_sl_uint64_ullong
#define mk_sl_cui_base_bits 64
#define mk_sl_cui_count (64 / 64)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn ullong
#include "mk_sl_cui_inl_fileh.h"
#undef mk_sl_cui_name
#undef mk_sl_cui_base_type
#undef mk_sl_cui_base_name
#undef mk_sl_cui_base_bits
#undef mk_sl_cui_count
#undef mk_sl_cui_endian
#undef mk_sl_cui_base_is_bui
#undef mk_sl_cui_base_bui_tn
#define mk_sl_cui_uint64_c(a, b) {{ ((mk_lang_types_ullong_t)(((mk_lang_types_ullong_t)(((mk_lang_types_ullong_t)(a)) << 32)) | ((mk_lang_types_ullong_t)(b)))) }}

#elif mk_lang_charbit == 8 && mk_lang_sizeof_bi_uint_t == 4

#define mk_lang_bui_name mk_sl_uint64_uint
#define mk_lang_bui_type mk_lang_types_uint_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_uint_t
#include "mk_lang_bui_inl_fileh.h"
#undef mk_lang_bui_name
#undef mk_lang_bui_type
#undef mk_lang_bui_sizeof

#define mk_sl_cui_name uint64
#define mk_sl_cui_base_type mk_lang_types_uint_t
#define mk_sl_cui_base_name mk_lang_bui_mk_sl_uint64_uint
#define mk_sl_cui_base_bits 32
#define mk_sl_cui_count (64 / 32)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn uint
#include "mk_sl_cui_inl_fileh.h"
#undef mk_sl_cui_name
#undef mk_sl_cui_base_type
#undef mk_sl_cui_base_name
#undef mk_sl_cui_base_bits
#undef mk_sl_cui_count
#undef mk_sl_cui_endian
#undef mk_sl_cui_base_is_bui
#undef mk_sl_cui_base_bui_tn
#define mk_sl_cui_uint64_c(a, b) {{ ((mk_lang_types_uint_t)(b)), ((mk_lang_types_uint_t)(a)) }}

#elif mk_lang_charbit == 8 && mk_lang_sizeof_bi_ulong_t == 4

#define mk_lang_bui_name mk_sl_uint64_ulong
#define mk_lang_bui_type mk_lang_types_ulong_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_ulong_t
#include "mk_lang_bui_inl_fileh.h"
#undef mk_lang_bui_name
#undef mk_lang_bui_type
#undef mk_lang_bui_sizeof

#define mk_sl_cui_name uint64
#define mk_sl_cui_base_type mk_lang_types_ulong_t
#define mk_sl_cui_base_name mk_lang_bui_mk_sl_uint64_ulong
#define mk_sl_cui_base_bits 32
#define mk_sl_cui_count (64 / 32)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn ulong
#include "mk_sl_cui_inl_fileh.h"
#undef mk_sl_cui_name
#undef mk_sl_cui_base_type
#undef mk_sl_cui_base_name
#undef mk_sl_cui_base_bits
#undef mk_sl_cui_count
#undef mk_sl_cui_endian
#undef mk_sl_cui_base_is_bui
#undef mk_sl_cui_base_bui_tn
#define mk_sl_cui_uint64_c(a, b) {{ ((mk_lang_types_ulong_t)(b)), ((mk_lang_types_ulong_t)(a)) }}

#endif


#if mk_lang_jumbo_want == 1
#include "mk_sl_uint64.c"
#endif
#endif
