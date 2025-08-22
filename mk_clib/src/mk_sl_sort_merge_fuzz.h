#ifndef mk_include_guard_mk_sl_sort_merge_fuzz_h
#define mk_include_guard_mk_sl_sort_merge_fuzz_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_sort_merge_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_sl_sort_merge_fuzz.c"
#endif
#endif
