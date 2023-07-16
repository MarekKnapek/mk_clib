#ifndef mk_include_guard_mk_lib_crypto_padding_pkcs7
#define mk_include_guard_mk_lib_crypto_padding_pkcs7


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


/* RFC 2315 */
/* PKCS #7 */


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_padding_pkcs7_pad(mk_sl_cui_uint8_pt const blocks, mk_lang_types_sint_t const content_len, mk_lang_types_sint_t const block_len) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_padding_pkcs7_unpad(mk_sl_cui_uint8_pct const block, mk_lang_types_sint_t const block_len, mk_lang_types_sint_pt const content_len) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_padding_pkcs7.c"
#endif
#endif
