#include "mk_lang_for_constants.h"


#if mk_lang_fora3_id == mk_lang_for_constants_bi
#define mk_lang_fora_bi_file "mk_lang_fora2.h"
#include "mk_lang_fora_bi.h"
#elif mk_lang_fora3_id == mk_lang_for_constants_bui
#define mk_lang_fora_bui_file "mk_lang_fora2.h"
#include "mk_lang_fora_bui.h"
#elif mk_lang_fora3_id == mk_lang_for_constants_bui2
#define mk_lang_fora_bui2_file "mk_lang_fora2.h"
#include "mk_lang_fora_bui2.h"
#elif mk_lang_fora3_id == mk_lang_for_constants_count
#define mk_lang_fora_count_file "mk_lang_fora2.h"
#include "mk_lang_fora_count.h"
#elif mk_lang_fora3_id == mk_lang_for_constants_count2
#define mk_lang_fora_count2_file "mk_lang_fora2.h"
#include "mk_lang_fora_count2.h"
#elif mk_lang_fora3_id == mk_lang_for_constants_endian
#define mk_lang_fora_endian_file "mk_lang_fora2.h"
#include "mk_lang_fora_endian.h"
#elif mk_lang_fora3_id == mk_lang_for_constants_divalg
#define mk_lang_fora_divalg_file "mk_lang_fora2.h"
#include "mk_lang_fora_divalg.h"
#endif
