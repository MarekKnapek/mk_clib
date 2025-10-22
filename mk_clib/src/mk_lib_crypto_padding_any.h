#ifndef mk_include_guard_mk_lib_crypto_padding_any_h
#define mk_include_guard_mk_lib_crypto_padding_any_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_sl_cui_uint8);


enum mk_lib_crypto_padding_any_id_e
{
	mk_lib_crypto_padding_any_id_e_iso9797pm2,
	mk_lib_crypto_padding_any_id_e_pkcs7,
	mk_lib_crypto_padding_any_id_e_dummy_end
};
typedef enum mk_lib_crypto_padding_any_id_e mk_lib_crypto_padding_any_id_t;


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_padding_any_pad(mk_lib_crypto_padding_any_id_t const id, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_sint_t const block_len, mk_lang_types_sint_t const free_space) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_padding_any_unpad(mk_lib_crypto_padding_any_id_t const id, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const block_len) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_crypto_padding_any.c"
#endif
#endif
