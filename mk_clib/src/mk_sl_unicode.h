#ifndef mk_include_guard_mk_sl_unicode_h
#define mk_include_guard_mk_sl_unicode_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_sl_cui_uint8);


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_unicode_utf16_wchar_to_utf8_u8(mk_lang_types_wchar_pct const utf16_buf, mk_lang_types_sint_t const utf16_len, mk_sl_cui_uint8_pt const utf8_buf, mk_lang_types_sint_t const utf8_len, mk_lang_types_sint_pt const utf16_constumed, mk_lang_types_sint_pt const utf8_consumed) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_sl_unicode.c"
#endif
#endif
