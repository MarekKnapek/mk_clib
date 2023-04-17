#include "mk_lang_range.h"

#include "mk_lang_bi.h"
#include "mk_lang_concat.h"
#include "mk_lang_for_constants.h"


#define mk_lang_fora1_id mk_lang_for_constants_bi
#define mk_lang_fora_file "mk_lang_range_inl_filec.h"
#define mk_lang_range_tn mk_lang_fora_bi_tn
#define mk_lang_range_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_range_tn), _t)
#include "mk_lang_fora1.h"
#undef mk_lang_fora1_id
#undef mk_lang_fora_file
#undef mk_lang_range_tn
#undef mk_lang_range_t
