#ifndef mk_include_guard_mk_sl_uint16
#define mk_include_guard_mk_sl_uint16


#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"


#if mk_lang_charbit == 8 && mk_lang_sizeof_bi_ushort_t == 2

#define mk_lang_bui_t_name mk_sl_cui_uint16_base_helper
#define mk_lang_bui_t_base ushort
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_fileh.h"
#undef mk_lang_bui_t_name
#undef mk_lang_bui_t_base
#undef mk_lang_bui_t_inline
#define mk_sl_cui_uint16_base_helper_sizebits_d (mk_lang_sizeof_bi_ushort_t * mk_lang_charbit)

#define mk_sl_cui_t_name mk_sl_cui_uint16
#define mk_sl_cui_t_base mk_sl_cui_uint16_base_helper
#define mk_sl_cui_t_count (16 / mk_sl_cui_uint16_base_helper_sizebits_d)
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#undef mk_sl_cui_t_name
#undef mk_sl_cui_t_base
#undef mk_sl_cui_t_count
#undef mk_sl_cui_t_endian
#undef mk_sl_cui_t_inline
#define mk_sl_cui_uint16_sizebits_d 16
#define mk_sl_cui_uint16_c(x) {{ ((mk_sl_cui_uint16_base_helper_t)(x)) }}

#endif


#if mk_lang_jumbo_want == 1
#include "mk_sl_uint16.c"
#endif
#endif
