#ifndef mk_include_guard_mk_sl_string_h
#define mk_include_guard_mk_sl_string_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_mallocator.h"


#define mk_sl_vector_t_name mk_sl_string
#define mk_sl_vector_t_element_type mk_lang_types_pchar_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocator
#define mk_sl_vector_t_element_eq mk_lang_types_pchar_eq
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_fileu.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_string_rw_add_and_remove_null_terminator(mk_sl_string_pt const string) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_string_ro_cmp_null_terminated(mk_sl_string_pct const a, mk_sl_string_pct const b, mk_lang_types_sint_pt const cmp) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_sl_string.c"
#endif
#endif
