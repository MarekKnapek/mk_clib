#ifndef mk_include_guard_mk_lib_iip_crypt_dsa_sha1_h
#define mk_include_guard_mk_lib_iip_crypt_dsa_sha1_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_integer.h"


union mk_lib_iip_crypt_dsa_sha1_key_pri_data_u
{
	mk_lib_iip_integer_dsa_sha1_pri_single_t m_val;
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_iip_crypt_dsa_sha1_key_pri_data_u mk_lib_iip_crypt_dsa_sha1_key_pri_data_t;
struct mk_lib_iip_crypt_dsa_sha1_key_pri_s
{
	mk_lib_iip_crypt_dsa_sha1_key_pri_data_t m_data;
};
typedef struct mk_lib_iip_crypt_dsa_sha1_key_pri_s mk_lib_iip_crypt_dsa_sha1_key_pri_t;
mk_lang_typedef(mk_lib_iip_crypt_dsa_sha1_key_pri);

union mk_lib_iip_crypt_dsa_sha1_key_pub_data_u
{
	mk_lib_iip_integer_dsa_sha1_pub_single_t m_val;
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_iip_crypt_dsa_sha1_key_pub_data_u mk_lib_iip_crypt_dsa_sha1_key_pub_data_t;
struct mk_lib_iip_crypt_dsa_sha1_key_pub_s
{
	mk_lib_iip_crypt_dsa_sha1_key_pub_data_t m_data;
};
typedef struct mk_lib_iip_crypt_dsa_sha1_key_pub_s mk_lib_iip_crypt_dsa_sha1_key_pub_t;
mk_lang_typedef(mk_lib_iip_crypt_dsa_sha1_key_pub);


mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_crypt_dsa_sha1_key_pri_generate_random(mk_lib_iip_crypt_dsa_sha1_key_pri_pt const pri) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_crypt_dsa_sha1_key_pri_compute_public(mk_lib_iip_crypt_dsa_sha1_key_pri_pct const pri, mk_lib_iip_crypt_dsa_sha1_key_pub_pt const pub) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_iip_crypt_dsa_sha1.c"
#endif
#endif
