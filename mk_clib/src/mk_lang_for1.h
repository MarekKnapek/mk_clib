#include "mk_lang_for_constants.h"


#if mk_lang_for1 == mk_lang_for_constants_bi
#define mk_lang_for_bi mk_lang_for
#include "mk_lang_for_bi.h"
#elif mk_lang_for1 == mk_lang_for_constants_bui
#define mk_lang_for_bui mk_lang_for
#include "mk_lang_for_bui.h"
#elif mk_lang_for1 == mk_lang_for_constants_endian
#define mk_lang_for_endian mk_lang_for
#include "mk_lang_for_endian.h"
#endif
