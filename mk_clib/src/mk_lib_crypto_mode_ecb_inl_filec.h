#include "mk_lang_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


/* NIST SP 800-38A */


#include "mk_lib_crypto_mode_ecb_inl_defd.h"


mk_lib_crypto_mode_ecb_inl_defd_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ecb_inl_defd_init(mk_lib_crypto_mode_ecb_inl_defd_pt const ecb) mk_lang_noexcept
{
	mk_lang_assert(ecb);
}

mk_lib_crypto_mode_ecb_inl_defd_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ecb_inl_defd_encrypt(mk_lib_crypto_mode_ecb_inl_defd_pt const ecb, mk_lib_crypto_mode_ecb_inl_defd_key_pct const key, mk_lib_crypto_mode_ecb_inl_defd_msg_pct const input, mk_lib_crypto_mode_ecb_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lang_assert(ecb);
	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_mode_ecb_inl_defd_alg_encrypt(key, input, output);
}

mk_lib_crypto_mode_ecb_inl_defd_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ecb_inl_defd_decrypt(mk_lib_crypto_mode_ecb_inl_defd_pt const ecb, mk_lib_crypto_mode_ecb_inl_defd_key_pct const key, mk_lib_crypto_mode_ecb_inl_defd_msg_pct const input, mk_lib_crypto_mode_ecb_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lang_assert(ecb);
	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_mode_ecb_inl_defd_alg_decrypt(key, input, output);
}


#include "mk_lib_crypto_mode_ecb_inl_defu.h"


#undef mk_lib_crypto_mode_ecb_t_name
#undef mk_lib_crypto_mode_ecb_t_alg
#undef mk_lib_crypto_mode_ecb_t_constexpr
