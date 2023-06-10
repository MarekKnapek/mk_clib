#ifndef mk_include_guard_mk_sl_cui
#define mk_include_guard_mk_sl_cui


#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_for_constants.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"


#define mk_lang_fora3_id mk_lang_for_constants_bui
#define mk_lang_fora2_id mk_lang_for_constants_count
#define mk_lang_fora1_id mk_lang_for_constants_endian
#define mk_lang_fora_file "mk_sl_cui_inl_fileh.h"
#define mk_sl_cui_for_bui mk_lang_fora_bui
#define mk_sl_cui_for_count mk_lang_fora_count
#define mk_sl_cui_for_endian mk_lang_fora_endian
#include "mk_lang_fora3.h"
#undef mk_lang_fora3_id
#undef mk_lang_fora2_id
#undef mk_lang_fora1_id
#undef mk_lang_fora_file
#undef mk_sl_cui_for_bui
#undef mk_sl_cui_for_count
#undef mk_sl_cui_for_endian


#if mk_lang_jumbo_want == 1
#include "mk_sl_cui.c"
#endif
#endif
