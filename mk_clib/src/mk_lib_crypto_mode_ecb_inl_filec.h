#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_charbit.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_endian.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


/* NIST SP 800-38A */


#include "mk_lib_crypto_mode_ecb_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ecb_inl_defd_init(mk_lib_crypto_mode_ecb_inl_defd_pt const ecb) mk_lang_noexcept
{
	mk_lang_assert(ecb);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ecb_inl_defd_schedule_encrypt(mk_lib_crypto_mode_ecb_inl_defd_pt const ecb, mk_lib_crypto_mode_ecb_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_ecb_inl_defd_msg_pct const input, mk_lib_crypto_mode_ecb_inl_defd_msg_pt const output) mk_lang_noexcept
{
	((void)(ecb));
	mk_lib_crypto_mode_ecb_inl_defd_alg_schedule_encrypt(schedule, input, output);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ecb_inl_defd_schedule_decrypt(mk_lib_crypto_mode_ecb_inl_defd_pt const ecb, mk_lib_crypto_mode_ecb_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_ecb_inl_defd_msg_pct const input, mk_lib_crypto_mode_ecb_inl_defd_msg_pt const output) mk_lang_noexcept
{
	((void)(ecb));
	mk_lib_crypto_mode_ecb_inl_defd_alg_schedule_decrypt(schedule, input, output);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ecb_inl_defd_expand_enc(mk_lib_crypto_mode_ecb_inl_defd_key_pct const key, mk_lib_crypto_mode_ecb_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_mode_ecb_inl_defd_alg_expand_enc(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ecb_inl_defd_expand_dec(mk_lib_crypto_mode_ecb_inl_defd_key_pct const key, mk_lib_crypto_mode_ecb_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_mode_ecb_inl_defd_alg_expand_dec(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ecb_inl_defd_encrypt(mk_lib_crypto_mode_ecb_inl_defd_pt const ecb, mk_lib_crypto_mode_ecb_inl_defd_key_pct const key, mk_lib_crypto_mode_ecb_inl_defd_msg_pct const input, mk_lib_crypto_mode_ecb_inl_defd_msg_pt const output) mk_lang_noexcept
{
	((void)(ecb));
	mk_lib_crypto_mode_ecb_inl_defd_alg_encrypt(key, input, output);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ecb_inl_defd_decrypt(mk_lib_crypto_mode_ecb_inl_defd_pt const ecb, mk_lib_crypto_mode_ecb_inl_defd_key_pct const key, mk_lib_crypto_mode_ecb_inl_defd_msg_pct const input, mk_lib_crypto_mode_ecb_inl_defd_msg_pt const output) mk_lang_noexcept
{
	((void)(ecb));
	mk_lib_crypto_mode_ecb_inl_defd_alg_decrypt(key, input, output);
}


#undef ecb_t
#undef ecb_from_uchars
#undef ecb_inc
#undef ecb_to_uchars


#include "mk_lib_crypto_mode_ecb_inl_defu.h"


#undef mk_lib_crypto_mode_ecb_t_name
#undef mk_lib_crypto_mode_ecb_t_alg
