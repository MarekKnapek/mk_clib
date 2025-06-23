#ifndef mk_include_guard_mk_sl_random_c
#define mk_include_guard_mk_sl_random_c
#include "mk_sl_random.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


mk_lang_forward(mk_sl_cui_uint8);


#if mk_lang_version_has_macro_cplusplus
#include "mk_sl_random_lang_cpp.hpp"
#define mk_sl_random_impl_init mk_sl_random_lang_cpp_init
#define mk_sl_random_impl_deinit mk_sl_random_lang_cpp_deinit
#define mk_sl_random_impl_generate mk_sl_random_lang_cpp_generate
#else
#include "mk_sl_random_lang_c89.h"
#define mk_sl_random_impl_init mk_sl_random_lang_c89_init
#define mk_sl_random_impl_deinit mk_sl_random_lang_c89_deinit
#define mk_sl_random_impl_generate mk_sl_random_lang_c89_generate
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_init(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_sl_random_impl_init();
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_sl_random_impl_deinit();
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_generate(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	return mk_sl_random_impl_generate(data_buf, data_len);
}


#endif
