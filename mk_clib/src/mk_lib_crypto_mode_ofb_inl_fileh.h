#include "mk_lib_crypto_mode_ofb_inl_defd.h"


enum mk_lib_crypto_mode_ofb_inl_defd_key_len_e { mk_lib_crypto_mode_ofb_inl_defd_key_len_v = mk_lib_crypto_mode_ofb_inl_defd_alg_key_len_v };
enum mk_lib_crypto_mode_ofb_inl_defd_msg_len_e { mk_lib_crypto_mode_ofb_inl_defd_msg_len_v = mk_lib_crypto_mode_ofb_inl_defd_alg_msg_len_v };


typedef mk_lib_crypto_mode_ofb_inl_defd_alg_key_t mk_lib_crypto_mode_ofb_inl_defd_key_t;
typedef mk_lib_crypto_mode_ofb_inl_defd_key_t const mk_lib_crypto_mode_ofb_inl_defd_key_ct;
typedef mk_lib_crypto_mode_ofb_inl_defd_key_t* mk_lib_crypto_mode_ofb_inl_defd_key_pt;
typedef mk_lib_crypto_mode_ofb_inl_defd_key_t const* mk_lib_crypto_mode_ofb_inl_defd_key_pct;

typedef mk_lib_crypto_mode_ofb_inl_defd_alg_msg_t mk_lib_crypto_mode_ofb_inl_defd_msg_t;
typedef mk_lib_crypto_mode_ofb_inl_defd_msg_t const mk_lib_crypto_mode_ofb_inl_defd_msg_ct;
typedef mk_lib_crypto_mode_ofb_inl_defd_msg_t* mk_lib_crypto_mode_ofb_inl_defd_msg_pt;
typedef mk_lib_crypto_mode_ofb_inl_defd_msg_t const* mk_lib_crypto_mode_ofb_inl_defd_msg_pct;

struct mk_lib_crypto_mode_ofb_inl_defd_s
{
	mk_lib_crypto_mode_ofb_inl_defd_alg_msg_t m_iv;
};
typedef struct mk_lib_crypto_mode_ofb_inl_defd_s mk_lib_crypto_mode_ofb_inl_defd_t;
typedef mk_lib_crypto_mode_ofb_inl_defd_t const mk_lib_crypto_mode_ofb_inl_defd_ct;
typedef mk_lib_crypto_mode_ofb_inl_defd_t* mk_lib_crypto_mode_ofb_inl_defd_pt;
typedef mk_lib_crypto_mode_ofb_inl_defd_t const* mk_lib_crypto_mode_ofb_inl_defd_pct;


mk_lib_crypto_mode_ofb_inl_defd_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ofb_inl_defd_init(mk_lib_crypto_mode_ofb_inl_defd_pt const ofb, mk_lib_crypto_mode_ofb_inl_defd_alg_msg_pct const data) mk_lang_noexcept;
mk_lib_crypto_mode_ofb_inl_defd_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ofb_inl_defd_encrypt(mk_lib_crypto_mode_ofb_inl_defd_pt const ofb, mk_lib_crypto_mode_ofb_inl_defd_key_pct const key, mk_lib_crypto_mode_ofb_inl_defd_msg_pct const input, mk_lib_crypto_mode_ofb_inl_defd_msg_pt const output) mk_lang_noexcept;
mk_lib_crypto_mode_ofb_inl_defd_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ofb_inl_defd_decrypt(mk_lib_crypto_mode_ofb_inl_defd_pt const ofb, mk_lib_crypto_mode_ofb_inl_defd_key_pct const key, mk_lib_crypto_mode_ofb_inl_defd_msg_pct const input, mk_lib_crypto_mode_ofb_inl_defd_msg_pt const output) mk_lang_noexcept;


#include "mk_lib_crypto_mode_ofb_inl_defu.h"