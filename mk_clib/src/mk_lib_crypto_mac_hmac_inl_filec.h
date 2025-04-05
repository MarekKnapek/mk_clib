#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


/* RFC 2104 */
/* FIPS PUB 198 */
/* FIPS PUB 198-1 */


#include "mk_lib_crypto_mac_hmac_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_inl_defd_init(mk_lib_crypto_mac_hmac_inl_defd_pt const hmac, mk_sl_cui_uint8_pct const key_buf, mk_lang_types_sint_t const key_len) mk_lang_noexcept
{
	enum ipad_e{ ipad_v = 0x36 };
	enum opad_e{ opad_v = 0x5c };

	mk_lib_crypto_mac_hmac_inl_defd_base_digest_t digest mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct k_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t k_len mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tui mk_lang_constexpr_init;

	mk_lang_assert(hmac);
	mk_lang_assert(key_buf || key_len == 0);
	mk_lang_assert(key_len >= 0);

	if(key_len < mk_lib_crypto_mac_hmac_inl_defd_base_digest_len_v)
	{
		/* warning */
	}
	if(key_len > mk_lib_crypto_mac_hmac_inl_defd_base_block_len_v)
	{
		mk_lib_crypto_mac_hmac_inl_defd_base_init(&hmac->m_base);
		mk_lib_crypto_mac_hmac_inl_defd_base_append_u8s(&hmac->m_base, key_buf, key_len);
		mk_lib_crypto_mac_hmac_inl_defd_base_finish(&hmac->m_base, &digest);
		k_buf = &digest.m_data.m_uint8s[0];
		k_len = mk_lib_crypto_mac_hmac_inl_defd_base_digest_len_v;
	}
	else
	{
		k_buf = key_buf;
		k_len = key_len;
	}
	tuc = ipad_v; mk_sl_cui_uint8_from_bi_uchar(&tui, &tuc);
	mk_sl_cui_uint8_memset_fn(&hmac->m_opad.m_data.m_uint8s[0], &tui, mk_lib_crypto_mac_hmac_inl_defd_base_block_len_v);
	mk_sl_cui_uint8_xor3_many_1(k_buf, &tui, k_len, &hmac->m_opad.m_data.m_uint8s[0]);
	mk_lib_crypto_mac_hmac_inl_defd_base_init(&hmac->m_base);
	mk_lib_crypto_mac_hmac_inl_defd_base_append_u8s(&hmac->m_base, &hmac->m_opad.m_data.m_uint8s[0], mk_lib_crypto_mac_hmac_inl_defd_base_block_len_v);
	tuc = opad_v; mk_sl_cui_uint8_from_bi_uchar(&tui, &tuc);
	mk_sl_cui_uint8_memset_fn(&hmac->m_opad.m_data.m_uint8s[0], &tui, mk_lib_crypto_mac_hmac_inl_defd_base_block_len_v);
	mk_sl_cui_uint8_xor3_many_1(k_buf, &tui, k_len, &hmac->m_opad.m_data.m_uint8s[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_inl_defd_append(mk_lib_crypto_mac_hmac_inl_defd_pt const hmac, mk_sl_cui_uint8_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(hmac);
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_lib_crypto_mac_hmac_inl_defd_base_append_u8s(&hmac->m_base, data, size);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_inl_defd_finish(mk_lib_crypto_mac_hmac_inl_defd_pt const hmac, mk_lib_crypto_mac_hmac_inl_defd_base_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_assert(hmac);
	mk_lang_assert(digest);

	mk_lib_crypto_mac_hmac_inl_defd_base_finish(&hmac->m_base, digest);
	mk_lib_crypto_mac_hmac_inl_defd_base_init(&hmac->m_base);
	mk_lib_crypto_mac_hmac_inl_defd_base_append_u8s(&hmac->m_base, &hmac->m_opad.m_data.m_uint8s[0], mk_lib_crypto_mac_hmac_inl_defd_base_block_len_v);
	mk_lib_crypto_mac_hmac_inl_defd_base_append_u8s(&hmac->m_base, &digest->m_data.m_uint8s[0], mk_lib_crypto_mac_hmac_inl_defd_base_digest_len_v);
	mk_lib_crypto_mac_hmac_inl_defd_base_finish(&hmac->m_base, digest);
}


#include "mk_lib_crypto_mac_hmac_inl_defu.h"
