#include "mk_lib_crypto_kdf_pbkdf1.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_kdf_pbkdf1_md2.h"
#include "mk_lib_crypto_kdf_pbkdf1_md5.h"
#include "mk_lib_crypto_kdf_pbkdf1_sha1.h"


#define mk_lib_crypto_kdf_pbkdf1_check_type(type) \
( \
	((type) == mk_lib_crypto_kdf_pbkdf1_type_m_md2) || \
	((type) == mk_lib_crypto_kdf_pbkdf1_type_m_md5) || \
	((type) == mk_lib_crypto_kdf_pbkdf1_type_m_sha1) || \
	0 \
)

#define mk_lib_crypto_kdf_pbkdf1_check_key_len(type, key_len) \
( \
	(((type) == mk_lib_crypto_kdf_pbkdf1_type_m_md2) && ((key_len) <= 16)) || \
	(((type) == mk_lib_crypto_kdf_pbkdf1_type_m_md5) && ((key_len) <= 16)) || \
	(((type) == mk_lib_crypto_kdf_pbkdf1_type_m_sha1) && ((key_len) <= 20)) || \
	0 \
)


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_kdf_pbkdf1(mk_lib_crypto_kdf_pbkdf1_type_t const type, mk_lang_types_uchar_pct const password, int const password_len, mk_lang_types_uchar_pct const salt, mk_lang_types_ulong_t const cost, int const key_len, mk_lang_types_uchar_pt const key) mk_lang_noexcept
{
	mk_lang_assert(mk_lib_crypto_kdf_pbkdf1_check_type(type));
	mk_lang_assert(password || password_len == 0);
	mk_lang_assert(password_len >= 0);
	mk_lang_assert(salt);
	mk_lang_assert(cost >= 0);
	mk_lang_assert(mk_lib_crypto_kdf_pbkdf1_check_key_len(type, key_len));
	mk_lang_assert(key);

	switch(type)
	{
		case mk_lib_crypto_kdf_pbkdf1_type_e_md2: mk_lib_crypto_kdf_pbkdf1_md2(password, password_len, salt, cost, key_len, key); break;
		case mk_lib_crypto_kdf_pbkdf1_type_e_md5: mk_lib_crypto_kdf_pbkdf1_md5(password, password_len, salt, cost, key_len, key); break;
		case mk_lib_crypto_kdf_pbkdf1_type_e_sha1: mk_lib_crypto_kdf_pbkdf1_sha1(password, password_len, salt, cost, key_len, key); break;
	}
}


#undef mk_lib_crypto_kdf_pbkdf1_check_type
#undef mk_lib_crypto_kdf_pbkdf1_check_key_len
