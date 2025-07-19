#ifndef mk_include_guard_mk_sl_random_lang_cpp98_hpp
#define mk_include_guard_mk_sl_random_lang_cpp98_hpp


#include "mk_lang_jumbo.h"
#include "mk_lang_version.h"
#if mk_lang_version_has_macro_cplusplus


#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_sl_cui_uint8);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_lang_cpp98_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_lang_cpp98_deinit(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_lang_cpp98_generate(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_sl_random_lang_cpp98.cpp"
#endif
#endif
