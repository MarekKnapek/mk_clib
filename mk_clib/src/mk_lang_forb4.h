#include "mk_lang_for_constants.h"


#if mk_lang_forb4_id == mk_lang_for_constants_bi
#define mk_lang_forb_bi_file "mk_lang_forb3.h"
#include "mk_lang_forb_bi.h"
#elif mk_lang_forb4_id == mk_lang_for_constants_count
#define mk_lang_forb_count_file "mk_lang_forb3.h"
#include "mk_lang_forb_count.h"
#elif mk_lang_forb4_id == mk_lang_for_constants_count2
#define mk_lang_forb_count2_file "mk_lang_forb3.h"
#include "mk_lang_forb_count2.h"
#elif mk_lang_forb4_id == mk_lang_for_constants_endian
#define mk_lang_forb_endian_file "mk_lang_forb3.h"
#include "mk_lang_forb_endian.h"
#elif mk_lang_forb4_id == mk_lang_for_constants_divalg
#define mk_lang_forb_divalg_file "mk_lang_forb3.h"
#include "mk_lang_forb_divalg.h"
#endif
