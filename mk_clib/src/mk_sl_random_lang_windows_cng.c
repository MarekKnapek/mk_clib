#ifndef mk_include_guard_mk_sl_random_lang_windows_cng_c
#define mk_include_guard_mk_sl_random_lang_windows_cng_c
#include "mk_sl_random_lang_windows_cng.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_win_dll_bcrypt.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_lang_windows_cng_init(mk_lang_types_void_t) mk_lang_noexcept
{
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_lang_windows_cng_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_lang_windows_cng_generate(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	mk_win_base_ntstatus_t st;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);

	st = mk_win_dll_bcrypt_gen_random(mk_win_dll_bcrypt_provider_get_null(), data_buf, data_len, mk_win_dll_bcrypt_k_flag_use_system_preferred_rng); mk_lang_check_return(st == 0);
	return 0;
}


#else
static void mk_sl_random_lang_windows_cng_dummy(void){}
#endif
#endif
