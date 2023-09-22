#include "mk_lang_memcpy_obj.h"

#include "mk_lang_bi.h"
#include "mk_lang_concat.h"
#include "mk_lang_for_constants.h"


#define mk_lang_forb1_id mk_lang_for_constants_bi
#define mk_lang_forb_file "mk_lang_memcpy_obj_inl_filec.h"
#define mk_lang_memcpy_obj_tn_ mk_lang_forb_bi_tn
#define mk_lang_memcpy_obj_t_ mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_forb_bi_tn), _t)
#include "mk_lang_forb1.h"
#undef mk_lang_forb1_id
#undef mk_lang_forb_file
#undef mk_lang_memcpy_obj_tn_
#undef mk_lang_memcpy_obj_t_
