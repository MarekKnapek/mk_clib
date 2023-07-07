#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


/* rfc 2898 */
/* pkcs #5 */


#include "mk_lib_crypto_kdf_pbkdf2_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_kdf_pbkdf2_inl_defd_fn_u8(mk_sl_cui_uint8_pct const password, int const password_len, mk_sl_cui_uint8_pct const salt, int const salt_len, mk_lang_types_ulong_t const cost, int const key_len, mk_sl_cui_uint8_pt const key) mk_lang_noexcept
{
	union int_u
	{
		mk_sl_cui_uint8_t m_uint8s[4];
		mk_lang_types_ulong_t m_align;
	};
	typedef union int_u int_t;

	mk_sl_cui_uint8_pt k mk_lang_constexpr_init;
	int tn mk_lang_constexpr_init;
	int rest mk_lang_constexpr_init;
	int ti mk_lang_constexpr_init;
	int block_idx mk_lang_constexpr_init;
	mk_lang_types_uchar_t uc mk_lang_constexpr_init;
	int_t cnt mk_lang_constexpr_init;
	mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_t hasher mk_lang_constexpr_init;
	mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_t digest_a mk_lang_constexpr_init;
	mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_t digest_b mk_lang_constexpr_init;
	mk_lang_types_ulong_t ui mk_lang_constexpr_init;
	int n mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(password || password_len == 0);
	mk_lang_assert(password_len >= 0);
	mk_lang_assert(salt || salt_len == 0);
	mk_lang_assert(salt_len >= 0);
	mk_lang_assert(cost >= 1);
	mk_lang_assert(key_len >= 1);
	mk_lang_assert(mk_lang_div_roundup(key_len, mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_len) <= 0xfffffffful);
	mk_lang_assert(key);

	k = key;
	tn = mk_lang_div_roundup(key_len, mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_len);
	rest = key_len - ((key_len / mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_len) * mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_len);
	for(ti = 0; ti != tn; ++ti)
	{
		block_idx = ti + 1;
		uc = ((mk_lang_types_uchar_t)(((unsigned)(((unsigned)(((unsigned)(block_idx)) >> (0 * 8))) & 0xff)))); mk_sl_cui_uint8_from_bi_uchar(&cnt.m_uint8s[4 - 1 - 0], &uc);
		uc = ((mk_lang_types_uchar_t)(((unsigned)(((unsigned)(((unsigned)(block_idx)) >> (1 * 8))) & 0xff)))); mk_sl_cui_uint8_from_bi_uchar(&cnt.m_uint8s[4 - 1 - 1], &uc);
		uc = ((mk_lang_types_uchar_t)(((unsigned)(((unsigned)(((unsigned)(block_idx)) >> (2 * 8))) & 0xff)))); mk_sl_cui_uint8_from_bi_uchar(&cnt.m_uint8s[4 - 1 - 2], &uc);
		uc = ((mk_lang_types_uchar_t)(((unsigned)(((unsigned)(((unsigned)(block_idx)) >> (3 * 8))) & 0xff)))); mk_sl_cui_uint8_from_bi_uchar(&cnt.m_uint8s[4 - 1 - 3], &uc);
		mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_init(&hasher, password, password_len);
		mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_append(&hasher, salt, salt_len);
		mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_append(&hasher, &cnt.m_uint8s[0], 4);
		mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_finish(&hasher, &digest_a);
		digest_b = digest_a;
		for(ui = 1; ui != cost; ++ui)
		{
			mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_init(&hasher, password, password_len);
			mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_append(&hasher, &digest_b.m_uint8s[0], mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_len);
			mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_finish(&hasher, &digest_b);
			for(i = 0; i != mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_len; ++i){ mk_sl_cui_uint8_xor2(&digest_a.m_uint8s[i], &digest_b.m_uint8s[i]); }
		}
		n = rest != 0 && ti == tn - 1 ? rest : mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_len;
		for(i = 0; i != n; ++i){ k[i] = digest_a.m_uint8s[i]; }
		k += n;
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_kdf_pbkdf2_inl_defd_fn(mk_lang_types_uchar_pct const password, int const password_len, mk_lang_types_uchar_pct const salt, int const salt_len, mk_lang_types_ulong_t const cost, int const key_len, mk_lang_types_uchar_pt const key) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;
	mk_sl_cui_uint8_t pwd[mk_lib_crypto_kdf_pbkdf2_inl_defd_block_len] mk_lang_constexpr_init;
	mk_sl_cui_uint8_t slt[mk_lib_crypto_kdf_pbkdf2_inl_defd_block_len] mk_lang_constexpr_init;
	mk_sl_cui_uint8_t k[mk_lib_crypto_kdf_pbkdf2_inl_defd_block_len] mk_lang_constexpr_init;

	mk_lang_assert(password_len <= sizeof(pwd) / sizeof(pwd[0]));
	mk_lang_assert(salt_len <= sizeof(slt) / sizeof(slt[0]));
	mk_lang_assert(key_len <= sizeof(k) / sizeof(k[0]));

	#if !mk_lang_constexpr_is_constant_evaluated
	if(1)
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#endif
	{
		mk_lib_crypto_kdf_pbkdf2_inl_defd_fn_u8(((mk_sl_cui_uint8_pct)(password)), password_len, ((mk_sl_cui_uint8_pct)(salt)), salt_len, cost, key_len, ((mk_sl_cui_uint8_pt)(key)));
	}
	else
	{
		for(i = 0; i != password_len; ++i){ mk_sl_cui_uint8_from_bi_uchar(&pwd[i], &password[i]); }
		for(i = 0; i != salt_len; ++i){ mk_sl_cui_uint8_from_bi_uchar(&slt[i], &salt[i]); }
		for(i = 0; i != key_len; ++i){ mk_sl_cui_uint8_to_bi_uchar(&k[i], &key[i]); }
		mk_lib_crypto_kdf_pbkdf2_inl_defd_fn_u8(pwd, password_len, slt, salt_len, cost, key_len, k);
	}
}


#include "mk_lib_crypto_kdf_pbkdf2_inl_defd.h"


#undef mk_lib_crypto_kdf_pbkdf2_t_name
