#ifndef mk_include_guard_mk_iip_cp_base_c
#define mk_include_guard_mk_iip_cp_base_c
#include "mk_iip_cp_base.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_sha1.h"
#include "mk_lib_iip_random.h"
#include "mk_sl_cui_uint8.h"


mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_base_dsa_generate_k(mk_lib_iip_integer_dsa_sha1_pri_single_pct const dsa_q, mk_lib_iip_integer_dsa_sha1_pri_single_pt const outk) mk_lang_noexcept
{
	union mk_iip_cp_dsa_generate_k_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_integer_dsa_sha1_pri_single_size_bytes_v];
		mk_lib_iip_integer_dsa_sha1_pri_single_t m_dsa_pri_cui_single;
	};
	typedef union mk_iip_cp_dsa_generate_k_data_u mk_iip_cp_dsa_generate_k_data_t;
	struct mk_iip_cp_dsa_generate_k_s
	{
		mk_iip_cp_dsa_generate_k_data_t m_data;
	};
	typedef struct mk_iip_cp_dsa_generate_k_s mk_iip_cp_dsa_generate_k_t;

	mk_iip_cp_dsa_generate_k_t storage;
	mk_lib_iip_integer_dsa_sha1_pri_single_t gcd;

	mk_lang_assert(dsa_q);
	mk_lang_assert(outk);

	do
	{
		do
		{
			mk_lib_iip_random_generate_uchars(&storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars));
			mk_lib_iip_integer_dsa_sha1_pri_single_from_buis_uchar_le(outk, &storage.m_data.m_uchars[0]);
		}while(/*!mk_iip_cp_base_dsa_key_pri_is_valid(dsa_q, outk)*/1);
		mk_lib_iip_integer_dsa_sha1_pri_single_gcd(dsa_q, outk, &gcd);
	}while(!(mk_lib_iip_integer_dsa_sha1_pri_single_is_one(&gcd)));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_base_dsa_sign_k_has_y(mk_iip_cp_base_dsa_key_pri_pct const pri, mk_lib_iip_integer_dsa_sha1_pri_single_pct const k, mk_sl_cui_uint8_pct const databuf, mk_lang_types_sint_t const datalen, mk_iip_cp_base_dsa_signature_pt const signature) mk_lang_noexcept
{
	mk_lib_crypto_hash_stream_sha1_t hasher mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_sha1_digest_t digest mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t m mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t dsa_q mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pub_single_t dsa_g mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pub_single_t dsa_p mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t r mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t ki mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t s mk_lang_constexpr_init;

	mk_lang_assert(pri);
	mk_lang_assert(k);
	mk_lang_assert(databuf);
	mk_lang_assert(datalen);
	mk_lang_assert(signature);

	mk_lib_crypto_hash_stream_sha1_init(&hasher);
	mk_lib_crypto_hash_stream_sha1_append_u8s(&hasher, databuf, datalen);
	mk_lib_crypto_hash_stream_sha1_finish(&hasher, &digest);
	mk_lib_iip_integer_dsa_sha1_pri_single_from_u8s_be(&m, &digest.m_data.m_uint8s[0]);
	mk_lib_iip_integer_dsa_sha1_pri_single_load_q(&dsa_q);
	mk_lib_iip_integer_dsa_sha1_pub_single_load_g(&dsa_g);
	mk_lib_iip_integer_dsa_sha1_pub_single_load_p(&dsa_p);
	mk_lib_iip_integer_dsa_sha1_pub_single_mod_pow_b(&dsa_g, k, &dsa_p, &dsa_q, &r);
	mk_lib_iip_integer_dsa_sha1_pri_single_mod_inv(k, &dsa_q, &ki);
	mk_lib_iip_integer_dsa_sha1_pri_single_mod_mul3_wrap_lo(&dsa_q,  &pri->m_data.m_val, &r, &s);
	mk_lib_iip_integer_dsa_sha1_pri_single_mod_add2_wrap_cid_cod(&dsa_q, &s, &m);
	mk_lib_iip_integer_dsa_sha1_pri_single_mod_mul2_wrap_lo(&dsa_q, &s, &ki);
	signature->m_data.m_rs.m_r = r;
	signature->m_data.m_rs.m_s = s;
}

mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_base_dsa_sign_k_has_n(mk_iip_cp_base_dsa_key_pri_pct const pri, mk_sl_cui_uint8_pct const databuf, mk_lang_types_sint_t const datalen, mk_iip_cp_base_dsa_signature_pt const signature) mk_lang_noexcept
{
	mk_lib_iip_integer_dsa_sha1_pri_single_t dsa_q;
	mk_lib_iip_integer_dsa_sha1_pri_single_t k;

	mk_lang_assert(pri);
	mk_lang_assert(databuf);
	mk_lang_assert(datalen);
	mk_lang_assert(signature);

	mk_lib_iip_integer_dsa_sha1_pri_single_load_q(&dsa_q);
	mk_iip_cp_base_dsa_generate_k(&dsa_q, &k);
	mk_iip_cp_base_dsa_sign_k_has_y(pri, &k, databuf, datalen, signature);
}


#endif
