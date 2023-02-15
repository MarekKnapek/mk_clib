#ifndef mk_include_guard_lang_bui_divmod
#define mk_include_guard_lang_bui_divmod


#include "mk_lang_bi.h"
#include "mk_lang_for_constants.h"


#define mk_lang_fora5_id mk_lang_for_constants_bui
#define mk_lang_fora4_id mk_lang_for_constants_count
#define mk_lang_fora3_id mk_lang_for_constants_count2
#define mk_lang_fora2_id mk_lang_for_constants_endian
#define mk_lang_fora1_id mk_lang_for_constants_divalg
#define mk_lang_fora_file "mk_lang_bui_divmod_inl_fileh.h"
#include "mk_lang_fora5.h"
#undef mk_lang_fora5_id
#undef mk_lang_fora4_id
#undef mk_lang_fora3_id
#undef mk_lang_fora2_id
#undef mk_lang_fora1_id
#undef mk_lang_fora_file


#if mk_lang_jumbo_want == 1
#include "mk_lang_bui_divmod.c"
#endif
#endif
