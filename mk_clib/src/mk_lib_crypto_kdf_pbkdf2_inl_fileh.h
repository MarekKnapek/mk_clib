#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


/* rfc 2898 */
/* pkcs #5 */


#include "mk_lib_crypto_kdf_pbkdf2_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_kdf_pbkdf2_inl_defd_fn_u8(mk_sl_cui_uint8_pct const password, int const password_len, mk_sl_cui_uint8_pct const salt, int const salt_len, mk_lang_types_ulong_t const cost, int const key_len, mk_sl_cui_uint8_pt const key) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_kdf_pbkdf2_inl_defd_fn(mk_lang_types_uchar_pct const password, int const password_len, mk_lang_types_uchar_pct const salt, int const salt_len, mk_lang_types_ulong_t const cost, int const key_len, mk_lang_types_uchar_pt const key) mk_lang_noexcept;


#include "mk_lib_crypto_kdf_pbkdf2_inl_defd.h"
