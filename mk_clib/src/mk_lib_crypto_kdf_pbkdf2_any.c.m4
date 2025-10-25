include(`mk_lib_crypto_kdf_pbkdf2.m')`'`'dnl
include(`mk_mm_nl.m')`'`'dnl
include(`mk_mm_tab.m')`'`'dnl
#ifndef mk_include_guard_mk_lib_crypto_kdf_pbkdf2_any_c
#define mk_include_guard_mk_lib_crypto_kdf_pbkdf2_any_c
#include "mk_lib_crypto_kdf_pbkdf2_any.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"

mk_lib_crypto_kdf_pbkdf2_mm_for_all(``#'`'include "mk_lib_crypto_kdf_pbkdf2_$1.h"mk_mm_nl()`'')dnl


mk_lang_forward(mk_sl_cui_uint8);


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_kdf_pbkdf2_any_fn(mk_lib_crypto_kdf_pbkdf2_any_id_t const id, mk_sl_cui_uint8_pct const password_buf, mk_lang_types_sint_t const password_len, mk_sl_cui_uint8_pct const salt_buf, mk_lang_types_sint_t const salt_len, mk_lang_types_ulong_t const cost, mk_lang_types_sint_t const key_len, mk_sl_cui_uint8_pt const key_buf) mk_lang_noexcept
{
	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_crypto_kdf_pbkdf2_any_id_e_dummy_end);

	switch(id)
	{
mk_lib_crypto_kdf_pbkdf2_mm_for_all(`mk_mm_tab()mk_mm_tab()case mk_lib_crypto_kdf_pbkdf2_any_id_e_$1: mk_lib_crypto_kdf_pbkdf2_$1_fn(password_buf, password_len, salt_buf, salt_len, cost, key_len, key_buf); break;mk_mm_nl()`'')dnl
		case mk_lib_crypto_kdf_pbkdf2_any_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
}


#endif
