#ifndef mk_include_guard_mk_sl_random_lang_windows_cng_h
#define mk_include_guard_mk_sl_random_lang_windows_cng_h


#include "mk_lang_jumbo.h"
#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any


#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_sl_cui_uint8);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_lang_windows_cng_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_lang_windows_cng_deinit(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_lang_windows_cng_generate(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_sl_random_lang_windows_cng.c"
#endif
#endif
