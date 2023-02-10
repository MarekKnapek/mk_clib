#include "mk_lang_bui_divmod_inl_lenb_default.h"
#include "mk_lang_endian.h"


#define mk_lang_bui_divmod_inl_endian mk_lang_endian_little
#include "mk_lang_bui_divmod_inl_endian.h"

#define mk_lang_bui_divmod_inl_endian mk_lang_endian_big
#include "mk_lang_bui_divmod_inl_endian.h"


#undef mk_lang_bui_divmod_inl_lenb_default


#undef mk_lang_bui_divmod_inl_lenb
