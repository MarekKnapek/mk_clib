#ifndef mk_include_guard_mk_lib_text_encoding
#define mk_include_guard_mk_lib_text_encoding


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_text_encoding_wide_to_utf8(mk_lang_types_wchar_pct const wide_str, mk_lang_types_sint_t const wide_len, mk_lang_types_pchar_pt const utf8_str, mk_lang_types_sint_t const utf8_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_text_encoding.c"
#endif
#endif
