#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


#include "mk_lib_crypto_mode_base_c_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_base_c_inl_defd_xor3(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pct const b, mk_sl_cui_uint8_pt const c) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	n = mk_lib_crypto_mode_base_c_inl_defd_len;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_xor3(&a[i], &b[i], &c[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_base_c_inl_defd_xor2(mk_sl_cui_uint8_pt const a, mk_sl_cui_uint8_pct const b) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_lib_crypto_mode_base_c_inl_defd_len;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_xor2(&a[i], &b[i]);
	}
}


#include "mk_lib_crypto_mode_base_c_inl_defu.h"


#undef mk_lib_crypto_mode_base_c_t_name
#undef mk_lib_crypto_mode_base_c_t_len
