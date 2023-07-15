#define mk_lang_jumbo_want 1


#include "../../src/mk_lang_cpp.h"
#include "../../src/mk_lang_emscripten.h"
#include "../../src/mk_lang_noexcept.h"
#include "../../src/mk_lang_types.h"
#include "../../src/mk_lib_crypto_app.h"


mk_lang_extern_c mk_lang_emscripten_keepalive mk_lang_types_usize_t mkcc_get_data_addr   (void)                            mk_lang_noexcept { return mk_lib_crypto_app_get_data_addr_us ()    ; }
mk_lang_extern_c mk_lang_emscripten_keepalive mk_lang_types_usize_t mkcc_get_data_size   (void)                            mk_lang_noexcept { return mk_lib_crypto_app_get_data_size    ()    ; }
mk_lang_extern_c mk_lang_emscripten_keepalive mk_lang_types_ssize_t mkcc_get_names       (void)                            mk_lang_noexcept { return mk_lib_crypto_app_get_names        ()    ; }
mk_lang_extern_c mk_lang_emscripten_keepalive mk_lang_types_ssize_t mkcc_get_iv_size_max (void)                            mk_lang_noexcept { return mk_lib_crypto_app_get_iv_size_max  ()    ; }
mk_lang_extern_c mk_lang_emscripten_keepalive mk_lang_types_ssize_t mkcc_init            (void)                            mk_lang_noexcept { return mk_lib_crypto_app_init             ()    ; }
mk_lang_extern_c mk_lang_emscripten_keepalive mk_lang_types_ssize_t mkcc_encrypt_append  (mk_lang_types_usize_t const len) mk_lang_noexcept { return mk_lib_crypto_app_encrypt_append   (len) ; }
mk_lang_extern_c mk_lang_emscripten_keepalive mk_lang_types_ssize_t mkcc_encrypt_finish  (mk_lang_types_usize_t const len) mk_lang_noexcept { return mk_lib_crypto_app_encrypt_finish   (len) ; }
mk_lang_extern_c mk_lang_emscripten_keepalive mk_lang_types_ssize_t mkcc_decrypt_append  (mk_lang_types_usize_t const len) mk_lang_noexcept { return mk_lib_crypto_app_decrypt_append   (len) ; }
mk_lang_extern_c mk_lang_emscripten_keepalive mk_lang_types_ssize_t mkcc_decrypt_finish  (mk_lang_types_usize_t const len) mk_lang_noexcept { return mk_lib_crypto_app_decrypt_finish   (len) ; }
