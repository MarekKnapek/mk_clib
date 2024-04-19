#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#include "mk_lib_crypto_kdf_pbkdf1_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_kdf_pbkdf1_inl_defd_fn(mk_sl_cui_uint8_pct const password, mk_lang_types_sint_t const password_len, mk_sl_cui_uint8_pct const salt, mk_lang_types_ulong_t const cost, mk_lang_types_sint_t const key_len, mk_sl_cui_uint8_pt const key) mk_lang_noexcept
{
	mk_lib_crypto_kdf_pbkdf1_inl_defd_hasher_t hasher mk_lang_constexpr_init;
	mk_lib_crypto_kdf_pbkdf1_inl_defd_digest_t digest mk_lang_constexpr_init;
	mk_lang_types_ulong_t it mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(password || password_len == 0);
	mk_lang_assert(password_len >= 0);
	mk_lang_assert(salt);
	mk_lang_assert(cost >= 1);
	mk_lang_assert(key_len <= mk_lib_crypto_kdf_pbkdf1_inl_defd_digest_len);
	mk_lang_assert(key);

	mk_lib_crypto_kdf_pbkdf1_inl_defd_hasher_init(&hasher);
	mk_lib_crypto_kdf_pbkdf1_inl_defd_hasher_append_u8(&hasher, password, ((mk_lang_types_usize_t)(password_len)));
	mk_lib_crypto_kdf_pbkdf1_inl_defd_hasher_append_u8(&hasher, salt, 8);
	mk_lib_crypto_kdf_pbkdf1_inl_defd_hasher_finish(&hasher, &digest);
	for(it = 1; it != cost; ++it)
	{
		mk_lib_crypto_kdf_pbkdf1_inl_defd_hasher_init(&hasher);
		mk_lib_crypto_kdf_pbkdf1_inl_defd_hasher_append_u8(&hasher, &digest.m_uint8s[0], mk_lib_crypto_kdf_pbkdf1_inl_defd_digest_len);
		mk_lib_crypto_kdf_pbkdf1_inl_defd_hasher_finish(&hasher, &digest);
	}
	for(i = 0; i != key_len; ++i)
	{
		key[i] = digest.m_uint8s[i];
	}
}


#include "mk_lib_crypto_kdf_pbkdf1_inl_defd.h"


#undef mk_lib_crypto_kdf_pbkdf1_t_name
