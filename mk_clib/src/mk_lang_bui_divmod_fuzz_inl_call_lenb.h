#include "mk_lang_endian.h"


#define mk_lang_bui_divmod_fuzz_inl_call_endian mk_lang_endian_little
#include "mk_lang_bui_divmod_fuzz_inl_call_endian.h"

#define mk_lang_bui_divmod_fuzz_inl_call_endian mk_lang_endian_big
#include "mk_lang_bui_divmod_fuzz_inl_call_endian.h"


#undef mk_lang_bui_divmod_fuzz_inl_call_lenb
