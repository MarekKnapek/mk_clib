#ifndef mk_include_guard_mk_lang_overlap
#define mk_include_guard_mk_lang_overlap


#include "mk_lang_bi.h"
#include "mk_lang_concat.h"
#include "mk_lang_for_constants.h"
#include "mk_lang_jumbo.h"


#define mk_lang_forb1_id mk_lang_for_constants_bi
#define mk_lang_forb_file "mk_lang_overlap_inl_fileh.h"
#define mk_lang_overlap_tn mk_lang_forb_bi_tn
#define mk_lang_overlap_tt mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_forb_bi_tn), _t)
#include "mk_lang_forb1.h"
#undef mk_lang_forb1_id
#undef mk_lang_forb_file
#undef mk_lang_overlap_tn
#undef mk_lang_overlap_tt


#if mk_lang_jumbo_want == 1
#include "mk_lang_overlap.c"
#endif
#endif
