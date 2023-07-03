#ifndef mk_include_guard_mk_lib_crypto_kdf_pbkdf1
#define mk_include_guard_mk_lib_crypto_kdf_pbkdf1


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#define mk_lib_crypto_kdf_pbkdf1_type_m_md2 0
#define mk_lib_crypto_kdf_pbkdf1_type_m_md5 1
#define mk_lib_crypto_kdf_pbkdf1_type_m_sha1 2
enum mk_lib_crypto_kdf_pbkdf1_type_e
{
	mk_lib_crypto_kdf_pbkdf1_type_e_md2 = mk_lib_crypto_kdf_pbkdf1_type_m_md2,
	mk_lib_crypto_kdf_pbkdf1_type_e_md5 = mk_lib_crypto_kdf_pbkdf1_type_m_md5,
	mk_lib_crypto_kdf_pbkdf1_type_e_sha1 = mk_lib_crypto_kdf_pbkdf1_type_m_sha1,
	mk_lib_crypto_kdf_pbkdf1_type_e_dummy_end
};
typedef enum mk_lib_crypto_kdf_pbkdf1_type_e mk_lib_crypto_kdf_pbkdf1_type_t;


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_kdf_pbkdf1(mk_lib_crypto_kdf_pbkdf1_type_t const type, mk_lang_types_uchar_pct const password, int const password_len, mk_lang_types_uchar_pct const salt, mk_lang_types_ulong_t const cost, int const key_len, mk_lang_types_uchar_pt const key) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_kdf_pbkdf1.c"
#endif
#endif
