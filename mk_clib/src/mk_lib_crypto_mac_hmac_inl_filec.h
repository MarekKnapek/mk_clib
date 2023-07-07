#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


/* RFC 2104 */
/* FIPS PUB 198 */
/* FIPS PUB 198-1 */


#include "mk_lib_crypto_mac_hmac_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mac_hmac_inl_defd_init(mk_lib_crypto_mac_hmac_inl_defd_pt const hmac, mk_sl_cui_uint8_pct const key, int const key_len) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_sl_cui_uint8_t const s_ipad = mk_sl_cui_uint8_c(0x36);
	mk_lang_constexpr_static mk_sl_cui_uint8_t const s_opad = mk_sl_cui_uint8_c(0x5c);

	mk_lib_crypto_mac_hmac_inl_defd_base_digest_t digest;
	mk_sl_cui_uint8_pct k;
	int k_len;
	int i;

	mk_lang_assert(hmac);
	mk_lang_assert(key || key_len == 0);
	mk_lang_assert(key_len >= 0);

	if(key_len < mk_lib_crypto_mac_hmac_inl_defd_base_digest_len)
	{
		/* warning */
	}
	if(key_len > mk_lib_crypto_mac_hmac_inl_defd_base_block_len)
	{
		mk_lib_crypto_mac_hmac_inl_defd_base_init(&hmac->m_base);
		mk_lib_crypto_mac_hmac_inl_defd_base_append(&hmac->m_base, key, key_len);
		mk_lib_crypto_mac_hmac_inl_defd_base_finish(&hmac->m_base, &digest);
		k = &digest.m_uint8s[0];
		k_len = mk_lib_crypto_mac_hmac_inl_defd_base_digest_len;
	}
	else
	{
		k = key;
		k_len = key_len;
	}
	for(i = 0; i != k_len; ++i){ mk_sl_cui_uint8_xor3(&key[i], &s_ipad, &hmac->m_opad.m_uint8s[i]); }
	for(i = k_len; i != mk_lib_crypto_mac_hmac_inl_defd_base_block_len; ++i){ hmac->m_opad.m_uint8s[i] = s_ipad; }
	mk_lib_crypto_mac_hmac_inl_defd_base_init(&hmac->m_base);
	mk_lib_crypto_mac_hmac_inl_defd_base_append(&hmac->m_base, &hmac->m_opad.m_uint8s[0], mk_lib_crypto_mac_hmac_inl_defd_base_block_len);
	for(i = 0; i != k_len; ++i){ mk_sl_cui_uint8_xor3(&key[i], &s_opad, &hmac->m_opad.m_uint8s[i]); }
	for(i = k_len; i != mk_lib_crypto_mac_hmac_inl_defd_base_block_len; ++i){ hmac->m_opad.m_uint8s[i] = s_opad; }
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mac_hmac_inl_defd_append(mk_lib_crypto_mac_hmac_inl_defd_pt const hmac, mk_sl_cui_uint8_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_assert(hmac);
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lib_crypto_mac_hmac_inl_defd_base_append(&hmac->m_base, data, size);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mac_hmac_inl_defd_finish(mk_lib_crypto_mac_hmac_inl_defd_pt const hmac, mk_lib_crypto_mac_hmac_inl_defd_base_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_assert(hmac);
	mk_lang_assert(digest);

	mk_lib_crypto_mac_hmac_inl_defd_base_finish(&hmac->m_base, digest);
	mk_lib_crypto_mac_hmac_inl_defd_base_init(&hmac->m_base);
	mk_lib_crypto_mac_hmac_inl_defd_base_append(&hmac->m_base, &hmac->m_opad.m_uint8s[0], mk_lib_crypto_mac_hmac_inl_defd_base_block_len);
	mk_lib_crypto_mac_hmac_inl_defd_base_append(&hmac->m_base, &digest->m_uint8s[0], mk_lib_crypto_mac_hmac_inl_defd_base_digest_len);
	mk_lib_crypto_mac_hmac_inl_defd_base_finish(&hmac->m_base, digest);
}


#include "mk_lib_crypto_mac_hmac_inl_defd.h"


#undef mk_lib_crypto_mac_hmac_t_name
