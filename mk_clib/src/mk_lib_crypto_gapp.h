#ifndef mk_include_guard_mk_lib_crypto_gapp
#define mk_include_guard_mk_lib_crypto_gapp


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


mk_lang_nodiscard mk_lang_jumbo int                   mk_lib_crypto_gapp_get_key_size_max (void)                            mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo int                   mk_lib_crypto_gapp_get_iv_size_max  (void)                            mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo int                   mk_lib_crypto_gapp_get_msg_size_max (void)                            mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_sl_cui_uint8_pt    mk_lib_crypto_gapp_get_data_addr    (void)                            mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_lib_crypto_gapp_get_data_size    (void)                            mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_gapp_get_names        (void)                            mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_gapp_init             (void)                            mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_gapp_encrypt_append   (mk_lang_types_usize_t const len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_gapp_decrypt_append   (mk_lang_types_usize_t const len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_gapp_encrypt_finish   (mk_lang_types_usize_t const len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_gapp_decrypt_finish   (mk_lang_types_usize_t const len) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_gapp.c"
#endif
#endif
