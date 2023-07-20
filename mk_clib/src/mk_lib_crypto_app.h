#ifndef mk_include_guard_mk_lib_crypto_app
#define mk_include_guard_mk_lib_crypto_app


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_mode_cbc_aes_128.h"
#include "mk_lib_crypto_mode_cbc_aes_192.h"
#include "mk_lib_crypto_mode_cbc_aes_256.h"
#include "mk_lib_crypto_mode_cfb_128_aes_128.h"
#include "mk_lib_crypto_mode_cfb_128_aes_192.h"
#include "mk_lib_crypto_mode_cfb_128_aes_256.h"
#include "mk_lib_crypto_mode_cfb_8_aes_128.h"
#include "mk_lib_crypto_mode_cfb_8_aes_192.h"
#include "mk_lib_crypto_mode_cfb_8_aes_256.h"
#include "mk_lib_crypto_mode_ctr_be_aes_128.h"
#include "mk_lib_crypto_mode_ctr_be_aes_192.h"
#include "mk_lib_crypto_mode_ctr_be_aes_256.h"
#include "mk_lib_crypto_mode_ecb_aes_128.h"
#include "mk_lib_crypto_mode_ecb_aes_192.h"
#include "mk_lib_crypto_mode_ecb_aes_256.h"
#include "mk_lib_crypto_mode_ofb_aes_128.h"
#include "mk_lib_crypto_mode_ofb_aes_192.h"
#include "mk_lib_crypto_mode_ofb_aes_256.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_app_get_key_size_max_m 32
#define mk_lib_crypto_app_get_iv_size_max_m 16
#define mk_lib_crypto_app_get_msg_size_max_m 16


enum mk_lib_crypto_app_id_alg_e
{
	mk_lib_crypto_app_id_alg_e_aes_128,
	mk_lib_crypto_app_id_alg_e_aes_192,
	mk_lib_crypto_app_id_alg_e_aes_256,
	mk_lib_crypto_app_id_alg_e_dummy_end
};
typedef enum mk_lib_crypto_app_id_alg_e mk_lib_crypto_app_id_alg_t;
typedef mk_lib_crypto_app_id_alg_t const mk_lib_crypto_app_id_alg_ct;
typedef mk_lib_crypto_app_id_alg_t* mk_lib_crypto_app_id_alg_pt;
typedef mk_lib_crypto_app_id_alg_t const* mk_lib_crypto_app_id_alg_pct;

enum mk_lib_crypto_app_id_padding_e
{
	mk_lib_crypto_app_id_padding_e_pkcs7,
	mk_lib_crypto_app_id_padding_e_iso9797pm2,
	mk_lib_crypto_app_id_padding_e_dummy_end
};
typedef enum mk_lib_crypto_app_id_padding_e mk_lib_crypto_app_id_padding_t;
typedef mk_lib_crypto_app_id_padding_t const mk_lib_crypto_app_id_padding_ct;
typedef mk_lib_crypto_app_id_padding_t* mk_lib_crypto_app_id_padding_pt;
typedef mk_lib_crypto_app_id_padding_t const* mk_lib_crypto_app_id_padding_pct;

enum mk_lib_crypto_app_id_mode_e
{
	mk_lib_crypto_app_id_mode_e_cbc,
	mk_lib_crypto_app_id_mode_e_cfb_128,
	mk_lib_crypto_app_id_mode_e_cfb_8,
	mk_lib_crypto_app_id_mode_e_ctr_be,
	mk_lib_crypto_app_id_mode_e_ecb,
	mk_lib_crypto_app_id_mode_e_ofb,
	mk_lib_crypto_app_id_mode_e_dummy_end
};
typedef enum mk_lib_crypto_app_id_mode_e mk_lib_crypto_app_id_mode_t;
typedef mk_lib_crypto_app_id_mode_t const mk_lib_crypto_app_id_mode_ct;
typedef mk_lib_crypto_app_id_mode_t* mk_lib_crypto_app_id_mode_pt;
typedef mk_lib_crypto_app_id_mode_t const* mk_lib_crypto_app_id_mode_pct;

enum mk_lib_crypto_app_id_kdf_e
{
	mk_lib_crypto_app_id_kdf_e_pbkdf1_md2,
	mk_lib_crypto_app_id_kdf_e_pbkdf1_md5,
	mk_lib_crypto_app_id_kdf_e_pbkdf1_sha1,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2b_256,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2b_384,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2b_512,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2s_128,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2s_160,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2s_224,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2s_256,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_blake3,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_md2,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_md4,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_md5,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha0,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha1,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_224,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_256,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_384,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_512,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_512_224,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_512_256,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha3_224,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha3_256,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha3_384,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha3_512,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger2_128,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger2_160,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger2_192,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger_128,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger_160,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger_192,
	mk_lib_crypto_app_id_kdf_e_dummy_end
};
typedef enum mk_lib_crypto_app_id_kdf_e mk_lib_crypto_app_id_kdf_t;
typedef mk_lib_crypto_app_id_kdf_t const mk_lib_crypto_app_id_kdf_ct;
typedef mk_lib_crypto_app_id_kdf_t* mk_lib_crypto_app_id_kdf_pt;
typedef mk_lib_crypto_app_id_kdf_t const* mk_lib_crypto_app_id_kdf_pct;


union mk_lib_crypto_app_aligned_key_u
{
	mk_lib_crypto_mode_cbc_aes_128_key_t     m_cbc_aes_128     ;
	mk_lib_crypto_mode_cbc_aes_192_key_t     m_cbc_aes_192     ;
	mk_lib_crypto_mode_cbc_aes_256_key_t     m_cbc_aes_256     ;
	mk_lib_crypto_mode_cfb_128_aes_128_key_t m_cfb_128_aes_128 ;
	mk_lib_crypto_mode_cfb_128_aes_192_key_t m_cfb_128_aes_192 ;
	mk_lib_crypto_mode_cfb_128_aes_256_key_t m_cfb_128_aes_256 ;
	mk_lib_crypto_mode_cfb_8_aes_128_key_t   m_cfb_8_aes_128   ;
	mk_lib_crypto_mode_cfb_8_aes_192_key_t   m_cfb_8_aes_192   ;
	mk_lib_crypto_mode_cfb_8_aes_256_key_t   m_cfb_8_aes_256   ;
	mk_lib_crypto_mode_ctr_be_aes_128_key_t  m_ctr_be_aes_128  ;
	mk_lib_crypto_mode_ctr_be_aes_192_key_t  m_ctr_be_aes_192  ;
	mk_lib_crypto_mode_ctr_be_aes_256_key_t  m_ctr_be_aes_256  ;
	mk_lib_crypto_mode_ecb_aes_128_key_t     m_ecb_aes_128     ;
	mk_lib_crypto_mode_ecb_aes_192_key_t     m_ecb_aes_192     ;
	mk_lib_crypto_mode_ecb_aes_256_key_t     m_ecb_aes_256     ;
	mk_lib_crypto_mode_ofb_aes_128_key_t     m_ofb_aes_128     ;
	mk_lib_crypto_mode_ofb_aes_192_key_t     m_ofb_aes_192     ;
	mk_lib_crypto_mode_ofb_aes_256_key_t     m_ofb_aes_256     ;
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_app_aligned_key_u mk_lib_crypto_app_aligned_key_t;

struct mk_lib_crypto_app_key_s
{
	mk_lib_crypto_app_aligned_key_t m_data;
};
typedef struct mk_lib_crypto_app_key_s mk_lib_crypto_app_key_t;

union mk_lib_crypto_app_aligned_mode_u
{
	mk_lib_crypto_mode_cbc_aes_128_t     m_cbc_aes_128     ;
	mk_lib_crypto_mode_cbc_aes_192_t     m_cbc_aes_192     ;
	mk_lib_crypto_mode_cbc_aes_256_t     m_cbc_aes_256     ;
	mk_lib_crypto_mode_cfb_128_aes_128_t m_cfb_128_aes_128 ;
	mk_lib_crypto_mode_cfb_128_aes_192_t m_cfb_128_aes_192 ;
	mk_lib_crypto_mode_cfb_128_aes_256_t m_cfb_128_aes_256 ;
	mk_lib_crypto_mode_cfb_8_aes_128_t   m_cfb_8_aes_128   ;
	mk_lib_crypto_mode_cfb_8_aes_192_t   m_cfb_8_aes_192   ;
	mk_lib_crypto_mode_cfb_8_aes_256_t   m_cfb_8_aes_256   ;
	mk_lib_crypto_mode_ctr_be_aes_128_t  m_ctr_be_aes_128  ;
	mk_lib_crypto_mode_ctr_be_aes_192_t  m_ctr_be_aes_192  ;
	mk_lib_crypto_mode_ctr_be_aes_256_t  m_ctr_be_aes_256  ;
	mk_lib_crypto_mode_ecb_aes_128_t     m_ecb_aes_128     ;
	mk_lib_crypto_mode_ecb_aes_192_t     m_ecb_aes_192     ;
	mk_lib_crypto_mode_ecb_aes_256_t     m_ecb_aes_256     ;
	mk_lib_crypto_mode_ofb_aes_128_t     m_ofb_aes_128     ;
	mk_lib_crypto_mode_ofb_aes_192_t     m_ofb_aes_192     ;
	mk_lib_crypto_mode_ofb_aes_256_t     m_ofb_aes_256     ;
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_app_aligned_mode_u mk_lib_crypto_app_aligned_mode_t;

struct mk_lib_crypto_app_mode_s
{
	mk_lib_crypto_app_aligned_mode_t m_data;
};
typedef struct mk_lib_crypto_app_mode_s mk_lib_crypto_app_mode_t;

union mk_lib_crypto_app_aligned_msg_u
{
	mk_lib_crypto_mode_cbc_aes_128_msg_t     m_cbc_aes_128     ;
	mk_lib_crypto_mode_cbc_aes_192_msg_t     m_cbc_aes_192     ;
	mk_lib_crypto_mode_cbc_aes_256_msg_t     m_cbc_aes_256     ;
	mk_lib_crypto_mode_cfb_128_aes_128_msg_t m_cfb_128_aes_128 ;
	mk_lib_crypto_mode_cfb_128_aes_192_msg_t m_cfb_128_aes_192 ;
	mk_lib_crypto_mode_cfb_128_aes_256_msg_t m_cfb_128_aes_256 ;
	mk_lib_crypto_mode_cfb_8_aes_128_msg_t   m_cfb_8_aes_128   ;
	mk_lib_crypto_mode_cfb_8_aes_192_msg_t   m_cfb_8_aes_192   ;
	mk_lib_crypto_mode_cfb_8_aes_256_msg_t   m_cfb_8_aes_256   ;
	mk_lib_crypto_mode_ctr_be_aes_128_msg_t  m_ctr_be_aes_128  ;
	mk_lib_crypto_mode_ctr_be_aes_192_msg_t  m_ctr_be_aes_192  ;
	mk_lib_crypto_mode_ctr_be_aes_256_msg_t  m_ctr_be_aes_256  ;
	mk_lib_crypto_mode_ecb_aes_128_msg_t     m_ecb_aes_128     ;
	mk_lib_crypto_mode_ecb_aes_192_msg_t     m_ecb_aes_192     ;
	mk_lib_crypto_mode_ecb_aes_256_msg_t     m_ecb_aes_256     ;
	mk_lib_crypto_mode_ofb_aes_128_msg_t     m_ofb_aes_128     ;
	mk_lib_crypto_mode_ofb_aes_192_msg_t     m_ofb_aes_192     ;
	mk_lib_crypto_mode_ofb_aes_256_msg_t     m_ofb_aes_256     ;
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_app_aligned_msg_u mk_lib_crypto_app_aligned_msg_t;

struct mk_lib_crypto_app_msg_s
{
	mk_lib_crypto_app_aligned_msg_t m_data;
};
typedef struct mk_lib_crypto_app_msg_s mk_lib_crypto_app_msg_t;
typedef mk_lib_crypto_app_msg_t const mk_lib_crypto_app_msg_ct;
typedef mk_lib_crypto_app_msg_t* mk_lib_crypto_app_msg_pt;
typedef mk_lib_crypto_app_msg_t const* mk_lib_crypto_app_msg_pct;

union mk_lib_crypto_app_aligned_buffer_u
{
	mk_sl_cui_uint8_t m_uint8s[1 * 1024 * 1024 + mk_lib_crypto_app_get_msg_size_max_m];
	mk_lib_crypto_app_msg_t m_msg;
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_app_aligned_buffer_u mk_lib_crypto_app_aligned_buffer_t;

struct mk_lib_crypto_app_buffer_s
{
	mk_lib_crypto_app_aligned_buffer_t m_data;
};
typedef struct mk_lib_crypto_app_buffer_s mk_lib_crypto_app_buffer_t;


struct mk_lib_crypto_app_s
{
	mk_lib_crypto_app_id_alg_t m_id_alg;
	mk_lib_crypto_app_id_padding_t m_id_padding;
	mk_lib_crypto_app_id_mode_t m_id_mode;
	mk_lib_crypto_app_key_t m_key;
	mk_lib_crypto_app_mode_t m_mode;
	mk_lib_crypto_app_buffer_t m_buffer;
};
typedef struct mk_lib_crypto_app_s mk_lib_crypto_app_t;
typedef mk_lib_crypto_app_t const mk_lib_crypto_app_ct;
typedef mk_lib_crypto_app_t* mk_lib_crypto_app_pt;
typedef mk_lib_crypto_app_t const* mk_lib_crypto_app_pct;


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_cui_uint8_pt    mk_lib_crypto_app_get_data_addr  (mk_lib_crypto_app_pt const app)                                  mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_lib_crypto_app_get_data_size  (mk_lib_crypto_app_pt const app)                                  mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_app_get_names      (mk_lib_crypto_app_pt const app)                                  mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_app_init           (mk_lib_crypto_app_pt const app)                                  mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_app_encrypt_append (mk_lib_crypto_app_pt const app, mk_lang_types_usize_t const len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_app_encrypt_finish (mk_lib_crypto_app_pt const app, mk_lang_types_usize_t const len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_app_decrypt_append (mk_lib_crypto_app_pt const app, mk_lang_types_usize_t const len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_app_decrypt_finish (mk_lib_crypto_app_pt const app, mk_lang_types_usize_t const len) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_app.c"
#endif
#endif
