#include "mk_lang_concat.h"


#define mk_lib_crypto_kdf_pbkdf2_inl_defd_name mk_lib_crypto_kdf_pbkdf2_t_name

#define mk_lib_crypto_kdf_pbkdf2_inl_defd_fn mk_lang_concat(mk_lib_crypto_kdf_pbkdf2_, mk_lib_crypto_kdf_pbkdf2_inl_defd_name)

#define mk_lib_crypto_kdf_pbkdf2_inl_defd_block_len mk_lang_concat(mk_lang_concat(mk_lib_crypto_hash_block_, mk_lib_crypto_kdf_pbkdf2_inl_defd_name), _block_len)
#define mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_len mk_lang_concat(mk_lang_concat(mk_lib_crypto_hash_block_, mk_lib_crypto_kdf_pbkdf2_inl_defd_name), _digest_len)

#define mk_lib_crypto_kdf_pbkdf2_inl_defd_digest_t mk_lang_concat(mk_lang_concat(mk_lib_crypto_hash_block_, mk_lib_crypto_kdf_pbkdf2_inl_defd_name), _digest_t)

#define mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_t mk_lang_concat(mk_lang_concat(mk_lib_crypto_mac_hmac_, mk_lib_crypto_kdf_pbkdf2_inl_defd_name), _t)
#define mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_init mk_lang_concat(mk_lang_concat(mk_lib_crypto_mac_hmac_, mk_lib_crypto_kdf_pbkdf2_inl_defd_name), _init)
#define mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_append mk_lang_concat(mk_lang_concat(mk_lib_crypto_mac_hmac_, mk_lib_crypto_kdf_pbkdf2_inl_defd_name), _append)
#define mk_lib_crypto_kdf_pbkdf2_inl_defd_hasher_finish mk_lang_concat(mk_lang_concat(mk_lib_crypto_mac_hmac_, mk_lib_crypto_kdf_pbkdf2_inl_defd_name), _finish)
