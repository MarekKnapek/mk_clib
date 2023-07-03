#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#include "mk_lib_crypto_kdf_pbkdf1_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_kdf_pbkdf1_inl_defd_fn_u8(mk_sl_cui_uint8_pct const password, int const password_len, mk_sl_cui_uint8_pct const salt, mk_lang_types_ulong_t const cost, int const key_len, mk_sl_cui_uint8_pt const key) mk_lang_noexcept
{
	mk_lib_crypto_kdf_pbkdf1_inl_defd_hasher_t hasher mk_lang_constexpr_init;
	mk_lib_crypto_kdf_pbkdf1_inl_defd_digest_t digest mk_lang_constexpr_init;
	mk_lang_types_ulong_t it mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

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
	for(i = 0; i != key_len; ++i){ key[i] = digest.m_uint8s[i]; }
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_kdf_pbkdf1_inl_defd_fn(mk_lang_types_uchar_pct const password, int const password_len, mk_lang_types_uchar_pct const salt, mk_lang_types_ulong_t const cost, int const key_len, mk_lang_types_uchar_pt const key) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;
	mk_sl_cui_uint8_t pwd[mk_lib_crypto_kdf_pbkdf1_inl_defd_block_len] mk_lang_constexpr_init;
	mk_sl_cui_uint8_t slt[8] mk_lang_constexpr_init;
	mk_sl_cui_uint8_t k[mk_lib_crypto_kdf_pbkdf1_inl_defd_digest_len] mk_lang_constexpr_init;

	#if !mk_lang_constexpr_is_constant_evaluated
	if(1)
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#endif
	{
		mk_lib_crypto_kdf_pbkdf1_inl_defd_fn_u8(((mk_sl_cui_uint8_pct)(password)), password_len, ((mk_sl_cui_uint8_pct)(salt)), cost, key_len, ((mk_sl_cui_uint8_pt)(key)));
	}
	else
	{
		mk_lang_assert(password_len <= sizeof(pwd) / sizeof(pwd[0]));
		for(i = 0; i != password_len; ++i){ mk_sl_cui_uint8_from_bi_uchar(&pwd[i], &password[i]); }
		for(i = 0; i != 8; ++i){ mk_sl_cui_uint8_from_bi_uchar(&slt[i], &salt[i]); }
		mk_lib_crypto_kdf_pbkdf1_inl_defd_fn_u8(pwd, password_len, slt, cost, key_len, k);
		for(i = 0; i != key_len; ++i){ mk_sl_cui_uint8_to_bi_uchar(&k[i], &key[i]); }
	}
}


#include "mk_lib_crypto_kdf_pbkdf1_inl_defd.h"


#undef mk_lib_crypto_kdf_pbkdf1_t_name
