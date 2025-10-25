include(`mk_lib_crypto_kdf_pbkdf2.m')dnl
include(`mk_mm_nl.m')dnl
include(`mk_mm_tab.m')dnl
#ifndef mk_include_guard_mk_lib_crypto_kdf_pbkdf2_any_h
#define mk_include_guard_mk_lib_crypto_kdf_pbkdf2_any_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_sl_cui_uint8);


enum mk_lib_crypto_kdf_pbkdf2_any_id_e
{
mk_lib_crypto_kdf_pbkdf2_mm_for_all(`mk_mm_tab()`'`'mk_lib_crypto_kdf_pbkdf2_any_id_e_$1,`'`'mk_mm_nl()`'')dnl
	mk_lib_crypto_kdf_pbkdf2_any_id_e_dummy_end
};
typedef enum mk_lib_crypto_kdf_pbkdf2_any_id_e mk_lib_crypto_kdf_pbkdf2_any_id_t;
mk_lang_typedef(mk_lib_crypto_kdf_pbkdf2_any_id);


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_kdf_pbkdf2_any_fn(mk_lib_crypto_kdf_pbkdf2_any_id_t const id, mk_sl_cui_uint8_pct const password_buf, mk_lang_types_sint_t const password_len, mk_sl_cui_uint8_pct const salt_buf, mk_lang_types_sint_t const salt_len, mk_lang_types_ulong_t const cost, mk_lang_types_sint_t const key_len, mk_sl_cui_uint8_pt const key_buf) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_crypto_kdf_pbkdf2_any.c"
#endif
#endif
