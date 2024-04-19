#include "mk_lang_countof.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"
#include "mk_sl_uint.h"


/* RFC 2898 */
/* PKCS #5 */


#include "mk_lib_crypto_kdf_pbkdf2_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_kdf_pbkdf2_inl_defd_fn(mk_sl_cui_uint8_pct const password, mk_lang_types_sint_t const password_len, mk_sl_cui_uint8_pct const salt, mk_lang_types_sint_t const salt_len, mk_lang_types_ulong_t const cost, mk_lang_types_sint_t const key_len, mk_sl_cui_uint8_pt const key) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt k mk_lang_constexpr_init;
	mk_lang_types_sint_t tn mk_lang_constexpr_init;
	mk_lang_types_sint_t rest mk_lang_constexpr_init;
	mk_lang_types_sint_t ti mk_lang_constexpr_init;
	mk_lang_types_sint_t block_idx mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tu32 mk_lang_constexpr_init;
	mk_sl_cui_uint8_t cnt[4] mk_lang_constexpr_init;
	mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_t hasher mk_lang_constexpr_init;
	mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_t digest_a mk_lang_constexpr_init;
	mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_t digest_b mk_lang_constexpr_init;
	mk_lang_types_ulong_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;

	mk_lang_assert(password || password_len == 0);
	mk_lang_assert(password_len >= 0);
	mk_lang_assert(salt || salt_len == 0);
	mk_lang_assert(salt_len >= 0);
	mk_lang_assert(cost >= 1);
	mk_lang_assert(key_len >= 1);
	mk_lang_assert(mk_lang_div_roundup(((mk_lang_types_ulong_t)(key_len)), mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_len) <= 0xfffffffful);
	mk_lang_assert(key);

	k = key;
	tn = mk_lang_div_roundup(key_len, mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_len);
	rest = key_len - ((key_len / mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_len) * mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_len);
	for(ti = 0; ti != tn; ++ti)
	{
		block_idx = ti + 1;
		mk_sl_cui_uint32_from_bi_sint(&tu32, &block_idx);
		mk_sl_uint_32_to_8_be(&tu32, &cnt[0]);
		mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_init(&hasher, password, password_len);
		mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_append(&hasher, salt, salt_len);
		mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_append(&hasher, &cnt[0], mk_lang_countof(cnt));
		mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_finish(&hasher, &digest_a);
		digest_b = digest_a;
		for(ui = 1; ui != cost; ++ui)
		{
			mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_init(&hasher, password, password_len);
			mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_append(&hasher, &digest_b.m_uint8s[0], mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_len);
			mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_finish(&hasher, &digest_b);
			for(i = 0; i != mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_len; ++i)
			{
				mk_sl_cui_uint8_xor2(&digest_a.m_uint8s[i], &digest_b.m_uint8s[i]);
			}
		}
		n = (((rest != 0) && (ti == tn - 1)) ? (rest) : (mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_len));
		for(i = 0; i != n; ++i)
		{
			k[i] = digest_a.m_uint8s[i];
		}
		k += n;
	}
}


#include "mk_lib_crypto_kdf_pbkdf2_inl_defd.h"


#undef mk_lib_crypto_kdf_pbkdf2_t_name
