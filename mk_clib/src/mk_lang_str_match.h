#ifndef mk_include_guard_mk_lang_str_match_h
#define mk_include_guard_mk_lang_str_match_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_tchar.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lang_str_match_n(mk_lang_types_pchar_pct const str_a_buf, mk_lang_types_sint_t const str_a_len, mk_lang_types_pchar_pct const str_b_buf, mk_lang_types_sint_t const str_b_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lang_str_match_w(mk_lang_types_wchar_pct const str_a_buf, mk_lang_types_sint_t const str_a_len, mk_lang_types_pchar_pct const str_b_buf, mk_lang_types_sint_t const str_b_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lang_str_match_t(mk_lang_tchar_pct const str_a_buf, mk_lang_types_sint_t const str_a_len, mk_lang_types_pchar_pct const str_b_buf, mk_lang_types_sint_t const str_b_len) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lang_str_match.c"
#endif
#endif
