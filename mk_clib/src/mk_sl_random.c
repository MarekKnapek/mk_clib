#ifndef mk_include_guard_mk_sl_random_c
#define mk_include_guard_mk_sl_random_c
#include "mk_sl_random.h"

#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


mk_lang_forward(mk_sl_cui_uint8);


#if mk_lang_platform_is_windows_at_least_any
#include "mk_sl_random_lang_windows_cng.h"
#define mk_sl_random_base mk_sl_random_lang_windows_cng
#elif mk_lang_version_has_macro_cplusplus && (mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_14)
#include "mk_sl_random_lang_cpp11.hpp"
#define mk_sl_random_base mk_sl_random_lang_cpp11
#elif mk_lang_version_has_macro_cplusplus
#include "mk_sl_random_lang_cpp98.hpp"
#define mk_sl_random_base mk_sl_random_lang_cpp98
#else
#include "mk_sl_random_lang_c89.h"
#define mk_sl_random_base mk_sl_random_lang_c89
#endif


#define mk_sl_random_impl_init mk_lang_concat(mk_sl_random_base, _init)
#define mk_sl_random_impl_deinit mk_lang_concat(mk_sl_random_base, _deinit)
#define mk_sl_random_impl_generate mk_lang_concat(mk_sl_random_base, _generate)


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
