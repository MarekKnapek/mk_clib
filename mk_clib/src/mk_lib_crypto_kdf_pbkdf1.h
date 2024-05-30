#ifndef mk_include_guard_mk_lib_crypto_kdf_pbkdf1
#define mk_include_guard_mk_lib_crypto_kdf_pbkdf1


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_kdf_pbkdf1_type_m_md2  0
#define mk_lib_crypto_kdf_pbkdf1_type_m_md5  1
#define mk_lib_crypto_kdf_pbkdf1_type_m_sha1 2
enum mk_lib_crypto_kdf_pbkdf1_type_e
{
	mk_lib_crypto_kdf_pbkdf1_type_e_md2  = mk_lib_crypto_kdf_pbkdf1_type_m_md2 ,
	mk_lib_crypto_kdf_pbkdf1_type_e_md5  = mk_lib_crypto_kdf_pbkdf1_type_m_md5 ,
	mk_lib_crypto_kdf_pbkdf1_type_e_sha1 = mk_lib_crypto_kdf_pbkdf1_type_m_sha1,
	mk_lib_crypto_kdf_pbkdf1_type_e_dummy_end
};
typedef enum mk_lib_crypto_kdf_pbkdf1_type_e mk_lib_crypto_kdf_pbkdf1_type_t;


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_kdf_pbkdf1(mk_lib_crypto_kdf_pbkdf1_type_t const type, mk_sl_cui_uint8_pct const password, mk_lang_types_sint_t const password_len, mk_lang_static_param(mk_sl_cui_uint8_ct, salt, 8), mk_lang_types_ulong_t const cost, mk_lang_types_sint_t const key_len, mk_sl_cui_uint8_pt const key) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_kdf_pbkdf1.c"
#endif
#endif
