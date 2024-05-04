#ifndef mk_include_guard_mk_lib_crypto_alg_twofish_192
#define mk_include_guard_mk_lib_crypto_alg_twofish_192


#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"


#define mk_lib_crypto_alg_twofish_192_nr (16)
#define mk_lib_crypto_alg_twofish_192_key_len_m (192 / mk_lang_charbit)
#define mk_lib_crypto_alg_twofish_192_msg_len_m (128 / mk_lang_charbit)
#define mk_lib_crypto_alg_twofish_192_schedule_len_m (mk_lib_crypto_alg_twofish_192_key_len_m / (mk_lib_crypto_alg_twofish_192_msg_len_m / 2) * (32 / mk_lang_charbit) + 2 * mk_lib_crypto_alg_twofish_192_msg_len_m + 2 * mk_lib_crypto_alg_twofish_192_nr * (32 / mk_lang_charbit))


#define mk_lib_crypto_alg_twofish_base_t_name mk_lib_crypto_alg_twofish_192
#define mk_lib_crypto_alg_twofish_base_t_keylen 192
#include "mk_lib_crypto_alg_twofish_base_inl_fileh.h"
#undef mk_lib_crypto_alg_twofish_base_t_name
#undef mk_lib_crypto_alg_twofish_base_t_keylen


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_alg_twofish_192.c"
#endif
#endif
