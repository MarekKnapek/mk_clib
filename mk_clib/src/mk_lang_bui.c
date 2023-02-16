#include "mk_lang_bui.h"

#include "mk_lang_bi.h"
#include "mk_lang_for_constants.h"


#define mk_lang_fora1_id mk_lang_for_constants_bui
#define mk_lang_fora_file "mk_lang_bui_inl_filec.h"
#define mk_lang_bui_for_bui mk_lang_fora_bui
#include "mk_lang_fora1.h"
#undef mk_lang_fora1_id
#undef mk_lang_fora_file
#undef mk_lang_bui_for_bui
