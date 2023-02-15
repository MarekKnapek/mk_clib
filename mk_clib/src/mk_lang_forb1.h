#include "mk_lang_for_constants.h"


#if mk_lang_forb1_id == mk_lang_for_constants_bi
#define mk_lang_forb_bi_file mk_lang_forb_file
#include "mk_lang_forb_bi.h"
#elif mk_lang_forb1_id == mk_lang_for_constants_bui
#define mk_lang_forb_bui_file mk_lang_forb_file
#include "mk_lang_forb_bui.h"
#elif mk_lang_forb1_id == mk_lang_for_constants_count
#define mk_lang_forb_count_file mk_lang_forb_file
#include "mk_lang_forb_count.h"
#elif mk_lang_forb1_id == mk_lang_for_constants_endian
#define mk_lang_forb_endian_file mk_lang_forb_file
#include "mk_lang_forb_endian.h"
#endif
