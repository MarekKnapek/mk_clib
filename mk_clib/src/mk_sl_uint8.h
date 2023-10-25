#ifndef mk_include_guard_mk_sl_uint8
#define mk_include_guard_mk_sl_uint8


#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"


#if mk_lang_charbit == 8 && mk_lang_sizeof_bi_uchar_t == 1

#define mk_lang_bui_t_name mk_sl_cui_uint8_base_helper
#define mk_lang_bui_t_base uchar
#include "mk_lang_bui_inl_fileh.h"
#undef mk_lang_bui_t_name
#undef mk_lang_bui_t_base
#define mk_sl_cui_uint8_base_helper_sizebits_d (mk_lang_sizeof_bi_uchar_t * mk_lang_charbit)

#define mk_sl_cui_t_name mk_sl_cui_uint8
#define mk_sl_cui_t_base mk_sl_cui_uint8_base_helper
#define mk_sl_cui_t_count (8 / mk_sl_cui_uint8_base_helper_sizebits_d)
#include "mk_sl_cui_inl_fileh.h"
#undef mk_sl_cui_t_name
#undef mk_sl_cui_t_base
#undef mk_sl_cui_t_count
#undef mk_sl_cui_t_endian
#define mk_sl_cui_uint8_sizebits_d 8
#define mk_sl_cui_uint8_c(x) {{ ((mk_sl_cui_uint8_base_helper_t)(x)) }}

#endif


#if mk_lang_jumbo_want == 1
#include "mk_sl_uint8.c"
#endif
#endif
