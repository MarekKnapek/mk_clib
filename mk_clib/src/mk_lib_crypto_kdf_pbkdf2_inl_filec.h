#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_roundup.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"
#include "mk_sl_uint_more.h"


/* RFC 2898 */
/* PKCS #5 */


#include "mk_lib_crypto_kdf_pbkdf2_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_kdf_pbkdf2_inl_defd_fn(mk_sl_cui_uint8_pct const password_buf, mk_lang_types_sint_t const password_len, mk_sl_cui_uint8_pct const salt_buf, mk_lang_types_sint_t const salt_len, mk_lang_types_ulong_t const cost, mk_lang_types_sint_t const key_len, mk_sl_cui_uint8_pt const key_buf) mk_lang_noexcept
{
	union mk_lib_crypto_kdf_pbkdf2_inl_defd_convert_data_u
	{
		mk_sl_cui_uint8_t m_uint8s[((mk_lang_types_sint_t)(mk_sl_cui_uint32_size_bytes_v)) / ((mk_lang_types_sint_t)(mk_sl_cui_uint8_size_bytes_v))];
		mk_sl_cui_uint32_t m_uint32;
	};
	typedef union mk_lib_crypto_kdf_pbkdf2_inl_defd_convert_data_u mk_lib_crypto_kdf_pbkdf2_inl_defd_convert_data_t;
	struct mk_lib_crypto_kdf_pbkdf2_inl_defd_convert_s
	{
		mk_lib_crypto_kdf_pbkdf2_inl_defd_convert_data_t m_data;
	};
	typedef struct mk_lib_crypto_kdf_pbkdf2_inl_defd_convert_s mk_lib_crypto_kdf_pbkdf2_inl_defd_convert_t;

	mk_sl_cui_uint8_pt k_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t tn mk_lang_constexpr_init;
	mk_lang_types_sint_t rest mk_lang_constexpr_init;
	mk_lang_types_sint_t ti mk_lang_constexpr_init;
	mk_lang_types_sint_t block_idx mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tu32 mk_lang_constexpr_init;
	mk_lib_crypto_kdf_pbkdf2_inl_defd_convert_t counter mk_lang_constexpr_init;
	mk_lib_crypto_kdf_pbkdf2_inl_defd_base_t hasher mk_lang_constexpr_init;
	mk_lib_crypto_kdf_pbkdf2_inl_defd_base_digest_t digest_a mk_lang_constexpr_init;
	mk_lib_crypto_kdf_pbkdf2_inl_defd_base_digest_t digest_b mk_lang_constexpr_init;
	mk_lang_types_ulong_t ui mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;

	mk_lang_assert(password_buf || password_len == 0);
	mk_lang_assert(password_len >= 0);
	mk_lang_assert(salt_buf || salt_len == 0);
	mk_lang_assert(salt_len >= 0);
	mk_lang_assert(cost >= 1);
	mk_lang_assert(key_len >= 1);
	mk_lang_assert(mk_lang_roundup_div(((mk_lang_types_ulong_t)(key_len)), mk_lib_crypto_kdf_pbkdf2_inl_defd_base_digest_len_v) <= 0xfffffffful);
	mk_lang_assert(key_buf);

	k_buf = key_buf;
	tn = mk_lang_roundup_div(key_len, mk_lib_crypto_kdf_pbkdf2_inl_defd_base_digest_len_v);
	rest = key_len - ((key_len / mk_lib_crypto_kdf_pbkdf2_inl_defd_base_digest_len_v) * mk_lib_crypto_kdf_pbkdf2_inl_defd_base_digest_len_v);
	for(ti = 0; ti != tn; ++ti)
	{
		block_idx = ti + 1;
		mk_sl_cui_uint32_from_bi_sint(&tu32, &block_idx);
		mk_sl_uint_convert_32_8_be_to_sml(&tu32, &counter.m_data.m_uint8s[0]);
		mk_lib_crypto_kdf_pbkdf2_inl_defd_base_init(&hasher, password_buf, ((mk_lang_types_usize_t)(password_len)));
		mk_lib_crypto_kdf_pbkdf2_inl_defd_base_append(&hasher, salt_buf, ((mk_lang_types_usize_t)(salt_len)));
		mk_lib_crypto_kdf_pbkdf2_inl_defd_base_append(&hasher, &counter.m_data.m_uint8s[0], mk_lang_countof(counter.m_data.m_uint8s));
		mk_lib_crypto_kdf_pbkdf2_inl_defd_base_finish(&hasher, &digest_a);
		digest_b = digest_a;
		for(ui = 1; ui != cost; ++ui)
		{
			mk_lib_crypto_kdf_pbkdf2_inl_defd_base_init(&hasher, password_buf, ((mk_lang_types_usize_t)(password_len)));
			mk_lib_crypto_kdf_pbkdf2_inl_defd_base_append(&hasher, &digest_b.m_data.m_uint8s[0], mk_lib_crypto_kdf_pbkdf2_inl_defd_base_digest_len_v);
			mk_lib_crypto_kdf_pbkdf2_inl_defd_base_finish(&hasher, &digest_b);
			mk_sl_cui_uint8_xor2_many(&digest_a.m_data.m_uint8s[0], &digest_b.m_data.m_uint8s[0], mk_lib_crypto_kdf_pbkdf2_inl_defd_base_digest_len_v);
		}
		n = (((rest != 0) && (ti == tn - 1)) ? (rest) : (mk_lib_crypto_kdf_pbkdf2_inl_defd_base_digest_len_v));
		mk_sl_cui_uint8_memcpy_fn(&k_buf[0], &digest_a.m_data.m_uint8s[0], ((mk_lang_types_usize_t)(n)));
		k_buf += n;
	}
}


#include "mk_lib_crypto_kdf_pbkdf2_inl_defu.h"
