#ifndef mk_include_guard_mk_lib_iip_crypt_dsa_sha1_c
#define mk_include_guard_mk_lib_iip_crypt_dsa_sha1_c
#include "mk_lib_iip_crypt_dsa_sha1.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_sha1.h"
#include "mk_lib_iip_integer.h"
#include "mk_lib_iip_random.h"


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_crypt_dsa_sha1_key_pri_is_valid(mk_lib_iip_crypt_dsa_sha1_key_pri_pct const pri) mk_lang_noexcept
{
	mk_lib_iip_integer_dsa_sha1_pri_single_t q mk_lang_constexpr_init;
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(pri);

	mk_lib_iip_integer_dsa_sha1_pri_single_load_q(&q);
	ret = !mk_lib_iip_integer_dsa_sha1_pri_single_is_zero(&pri->m_data.m_val) && mk_lib_iip_integer_dsa_sha1_pri_single_lt(&pri->m_data.m_val, &q);
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_crypt_dsa_sha1_key_pri_pr_generate_random(mk_lib_iip_crypt_dsa_sha1_key_pri_pt const pri) mk_lang_noexcept
{
	union mk_lib_iip_crypt_dsa_sha1_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_integer_dsa_sha1_pri_single_size_bytes_v];
		mk_lib_iip_crypt_dsa_sha1_key_pri_t m_dsa_sha1_key_pri;
	};
	typedef union mk_lib_iip_crypt_dsa_sha1_storage_data_u mk_lib_iip_crypt_dsa_sha1_storage_data_t;
	struct mk_lib_iip_crypt_dsa_sha1_storage_s
	{
		mk_lib_iip_crypt_dsa_sha1_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_crypt_dsa_sha1_storage_s mk_lib_iip_crypt_dsa_sha1_storage_t;

	mk_lang_types_sint_t err;
	mk_lib_iip_crypt_dsa_sha1_storage_t storage;

	mk_lang_assert(pri);

	do
	{
		err = mk_lib_iip_random_generate_uchars(&storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars)); mk_lang_check_rereturn(err);
		mk_lib_iip_integer_dsa_sha1_pri_single_from_buis_uchar_le(&pri->m_data.m_val, &storage.m_data.m_uchars[0]); /* todo ne */
	}while(!mk_lib_iip_crypt_dsa_sha1_key_pri_is_valid(pri));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_crypt_dsa_sha1_key_pri_pr_generate_k(mk_lib_iip_crypt_dsa_sha1_key_pri_pt const k) mk_lang_noexcept
{
	mk_lib_iip_integer_dsa_sha1_pri_single_t q;
	mk_lang_types_sint_t err;
	mk_lib_iip_integer_dsa_sha1_pri_single_t gcd;

	mk_lang_assert(k);

	mk_lib_iip_integer_dsa_sha1_pri_single_load_q(&q);
	do
	{
		err = mk_lib_iip_crypt_dsa_sha1_key_pri_pr_generate_random(k); mk_lang_check_rereturn(err);
		mk_lib_iip_integer_dsa_sha1_pri_single_gcd(&q, &k->m_data.m_val, &gcd);
	}while(!mk_lib_iip_integer_dsa_sha1_pri_single_is_one(&gcd));
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_crypt_dsa_sha1_key_pri_generate_random_(mk_lib_iip_crypt_dsa_sha1_key_pri_pt const pri) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(pri);

	err = mk_lib_iip_crypt_dsa_sha1_key_pri_pr_generate_random(pri); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_crypt_dsa_sha1_key_pri_compute_public(mk_lib_iip_crypt_dsa_sha1_key_pri_pct const pri, mk_lib_iip_crypt_dsa_sha1_key_pub_pt const pub) mk_lang_noexcept
{
	mk_lib_iip_integer_dsa_sha1_pub_single_t generator mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pub_single_t prime mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pub_single_t priv mk_lang_constexpr_init;

	mk_lang_assert(pri);
	mk_lang_assert(pub);

	mk_lib_iip_integer_dsa_sha1_pub_single_load_g(&generator);
	mk_lib_iip_integer_dsa_sha1_pub_single_load_p(&prime);
	mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_single(&pri->m_data.m_val, &priv);
	mk_lib_iip_integer_dsa_sha1_pub_single_mod_pow_a(&generator, &priv, &prime, &pub->m_data.m_val);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_crypt_dsa_sha1_key_pri_sign_k(mk_lib_iip_crypt_dsa_sha1_key_pri_pct const pri, mk_lib_iip_crypt_dsa_sha1_key_pri_pct const k, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_crypt_dsa_sha1_signature_pt const signature) mk_lang_noexcept
{
	mk_lib_crypto_hash_stream_sha1_t hasher mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_sha1_digest_t digest mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t m mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t q mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pub_single_t g mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pub_single_t p mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t r mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t ki mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t s mk_lang_constexpr_init;

	mk_lang_assert(pri);
	mk_lang_assert(k);
	mk_lang_assert(data_buf);
	mk_lang_assert(data_len);
	mk_lang_assert(signature);
	mk_lang_assert(pri != k);
	mk_lang_assert(&pri->m_data.m_val != &signature->m_r);
	mk_lang_assert(&pri->m_data.m_val != &signature->m_s);
	mk_lang_assert(&k->m_data.m_val != &signature->m_r);
	mk_lang_assert(&k->m_data.m_val != &signature->m_s);
	mk_lang_assert(&signature->m_r != &signature->m_s);

	mk_lib_crypto_hash_stream_sha1_init(&hasher);
	mk_lib_crypto_hash_stream_sha1_append_u8s(&hasher, data_buf, ((mk_lang_types_usize_t)(data_len)));
	mk_lib_crypto_hash_stream_sha1_finish(&hasher, &digest);
	mk_lib_iip_integer_dsa_sha1_pri_single_from_u8s_be(&m, &digest.m_data.m_uint8s[0]);
	mk_lib_iip_integer_dsa_sha1_pri_single_load_q(&q);
	mk_lib_iip_integer_dsa_sha1_pub_single_load_g(&g);
	mk_lib_iip_integer_dsa_sha1_pub_single_load_p(&p);
	mk_lib_iip_integer_dsa_sha1_pub_single_mod_pow_b(&g, &k->m_data.m_val, &p, &q, &r);
	mk_lib_iip_integer_dsa_sha1_pri_single_mod_inv(&k->m_data.m_val, &q, &ki);
	mk_lib_iip_integer_dsa_sha1_pri_single_mod_mul3_wrap_lo(&q, &pri->m_data.m_val, &r, &s);
	mk_lib_iip_integer_dsa_sha1_pri_single_mod_add2_wrap_cid_cod(&q, &s, &m);
	mk_lib_iip_integer_dsa_sha1_pri_single_mod_mul2_wrap_lo(&q, &s, &ki);
	signature->m_r = r;
	signature->m_s = s;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_crypt_dsa_sha1_key_pri_sign_data(mk_lib_iip_crypt_dsa_sha1_key_pri_pct const pri, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_crypt_dsa_sha1_signature_pt const signature) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_crypt_dsa_sha1_key_pri_t k;

	mk_lang_assert(pri);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(signature);

	err = mk_lib_iip_crypt_dsa_sha1_key_pri_pr_generate_k(&k); mk_lang_check_rereturn(err);
	mk_lib_iip_crypt_dsa_sha1_key_pri_sign_k(pri, &k, data_buf, data_len, signature);
	return 0;
}


#endif
