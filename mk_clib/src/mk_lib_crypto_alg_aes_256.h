#ifndef mk_include_guard_mk_lib_crypto_alg_aes_256
#define mk_include_guard_mk_lib_crypto_alg_aes_256


#include "mk_lang_alignas.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


/* NIST FIPS PUB 197 */


#define mk_lib_crypto_alg_aes_256_key_len_m (256 / 8)
#define mk_lib_crypto_alg_aes_256_msg_len_m (128 / 8)
enum mk_lib_crypto_alg_aes_256_key_len_e { mk_lib_crypto_alg_aes_256_key_len_v = mk_lib_crypto_alg_aes_256_key_len_m };
enum mk_lib_crypto_alg_aes_256_msg_len_e { mk_lib_crypto_alg_aes_256_msg_len_v = mk_lib_crypto_alg_aes_256_msg_len_m };


union mk_lib_crypto_alg_aes_256_aligned_key_u
{
	mk_lang_alignas(mk_lib_crypto_alg_aes_256_key_len_m) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_alg_aes_256_key_len_v];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_alg_aes_256_aligned_key_u mk_lib_crypto_alg_aes_256_aligned_key_t;

union mk_lib_crypto_alg_aes_256_aligned_msg_u
{
	mk_lang_alignas(mk_lib_crypto_alg_aes_256_msg_len_m) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_alg_aes_256_msg_len_v];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_alg_aes_256_aligned_msg_u mk_lib_crypto_alg_aes_256_aligned_msg_t;

struct mk_lib_crypto_alg_aes_256_key_s
{
	mk_lib_crypto_alg_aes_256_aligned_key_t m_data;
};
typedef struct mk_lib_crypto_alg_aes_256_key_s mk_lib_crypto_alg_aes_256_key_t;
typedef mk_lib_crypto_alg_aes_256_key_t const mk_lib_crypto_alg_aes_256_key_ct;
typedef mk_lib_crypto_alg_aes_256_key_t* mk_lib_crypto_alg_aes_256_key_pt;
typedef mk_lib_crypto_alg_aes_256_key_t const* mk_lib_crypto_alg_aes_256_key_pct;

struct mk_lib_crypto_alg_aes_256_msg_s
{
	mk_lib_crypto_alg_aes_256_aligned_msg_t m_data;
};
typedef struct mk_lib_crypto_alg_aes_256_msg_s mk_lib_crypto_alg_aes_256_msg_t;
typedef mk_lib_crypto_alg_aes_256_msg_t const mk_lib_crypto_alg_aes_256_msg_ct;
typedef mk_lib_crypto_alg_aes_256_msg_t* mk_lib_crypto_alg_aes_256_msg_pt;
typedef mk_lib_crypto_alg_aes_256_msg_t const* mk_lib_crypto_alg_aes_256_msg_pct;


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_256_portable_encrypt(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_256_portable_decrypt(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept;

mk_lang_jumbo void mk_lib_crypto_alg_aes_256_accelerated_encrypt(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept;
mk_lang_jumbo void mk_lib_crypto_alg_aes_256_accelerated_decrypt(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept;

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_256_encrypt(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_256_decrypt(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_alg_aes_256.c"
#endif
#endif
