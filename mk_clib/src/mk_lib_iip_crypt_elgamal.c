#ifndef mk_include_guard_mk_lib_iip_crypt_elgamal_c
#define mk_include_guard_mk_lib_iip_crypt_elgamal_c
#include "mk_lib_iip_crypt_elgamal.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_integer.h"
#include "mk_lib_iip_random.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_crypt_elgamal_key_pri_generate_random(mk_lib_iip_crypt_elgamal_key_pri_pt const pri) mk_lang_noexcept
{
	union mk_lib_iip_crypt_elgamal_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_integer_elgamal_pri_single_size_bytes_v];
		mk_lib_iip_crypt_elgamal_key_pri_t m_elgamal_key_pri;
	};
	typedef union mk_lib_iip_crypt_elgamal_storage_data_u mk_lib_iip_crypt_elgamal_storage_data_t;
	struct mk_lib_iip_crypt_elgamal_storage_s
	{
		mk_lib_iip_crypt_elgamal_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_crypt_elgamal_storage_s mk_lib_iip_crypt_elgamal_storage_t;

	mk_lang_types_sint_t err;
	mk_lib_iip_crypt_elgamal_storage_t storage;

	mk_lang_assert(pri);

	err = mk_lib_iip_random_generate_uchars(&storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars)); mk_lang_check_rereturn(err);
	mk_lib_iip_integer_elgamal_pri_single_from_buis_uchar_le(&pri->m_data.m_val, &storage.m_data.m_uchars[0]);
	return 0;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_crypt_elgamal_key_pri_compute_public(mk_lib_iip_crypt_elgamal_key_pri_pct const pri, mk_lib_iip_crypt_elgamal_key_pub_pt const pub) mk_lang_noexcept
{
	mk_lib_iip_integer_elgamal_pub_single_t generator mk_lang_constexpr_init;
	mk_lib_iip_integer_elgamal_pub_single_t prime mk_lang_constexpr_init;
	mk_lib_iip_integer_elgamal_pub_single_t priv mk_lang_constexpr_init;

	mk_lang_assert(pri);
	mk_lang_assert(pub);

	mk_lib_iip_integer_elgamal_pub_single_set_two(&generator);
	mk_lib_iip_integer_elgamal_pub_single_load_p(&prime);
	mk_lib_iip_integer_elgamal_pri_single_to_pub_single(&pri->m_data.m_val, &priv);
	mk_lib_iip_integer_elgamal_pub_single_mod_pow(&generator, &priv, &prime, &pub->m_data.m_val);
}


#endif
