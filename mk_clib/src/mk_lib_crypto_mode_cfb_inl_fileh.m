define(`mk_lib_crypto_mode_cfb_inl_defd_base_file_name', `mk_lang_concat(`mk_lib_crypto_alg_', mk_lib_crypto_mode_cfb_t_alg)')dnl
define(`mk_lib_crypto_mode_cfb_inl_defd_key_len_m', `mk_lang_concat(`mk_lib_crypto_mode_cfb_', mk_lib_crypto_mode_cfb_t_name, `_key_len_m')')dnl
define(`mk_lib_crypto_mode_cfb_inl_defd_msg_len_m', `mk_lang_concat(`mk_lib_crypto_mode_cfb_', mk_lib_crypto_mode_cfb_t_name, `_msg_len_m')')dnl
define(`mk_lib_crypto_mode_cfb_inl_defd_schedule_len_m', `mk_lang_concat(`mk_lib_crypto_mode_cfb_', mk_lib_crypto_mode_cfb_t_name, `_schedule_len_m')')dnl
define(`mk_lib_crypto_mode_cfb_inl_defd_iv_len_m', `mk_lang_concat(`mk_lib_crypto_mode_cfb_', mk_lib_crypto_mode_cfb_t_name, `_iv_len_m')')dnl
#include "mk_lang_alignas.h"
#include "mk_lang_alignof.h"
#include "mk_lang_charbit.h"
#include "mk_lang_max.h"
#include "mk_lang_types.h"
`#include' "mk_lib_crypto_mode_cfb_inl_defd_base_file_name.h"
#include "mk_sl_uint8.h"


#include "mk_lib_crypto_mode_cfb_inl_defd.h"


`#define' mk_lib_crypto_mode_cfb_inl_defd_key_len_m mk_lib_crypto_mode_cfb_inl_defd_alg_key_len_m
`#define' mk_lib_crypto_mode_cfb_inl_defd_msg_len_m (mk_lib_crypto_mode_cfb_t_sbits / mk_lang_charbit)
`#define' mk_lib_crypto_mode_cfb_inl_defd_schedule_len_m mk_lib_crypto_mode_cfb_inl_defd_alg_schedule_len_m
`#define' mk_lib_crypto_mode_cfb_inl_defd_iv_len_m mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_m
enum mk_lib_crypto_mode_cfb_inl_defd_key_len_e { mk_lib_crypto_mode_cfb_inl_defd_key_len_v = mk_lib_crypto_mode_cfb_inl_defd_key_len_m };
enum mk_lib_crypto_mode_cfb_inl_defd_msg_len_e { mk_lib_crypto_mode_cfb_inl_defd_msg_len_v = mk_lib_crypto_mode_cfb_inl_defd_msg_len_m };
enum mk_lib_crypto_mode_cfb_inl_defd_schedule_len_e { mk_lib_crypto_mode_cfb_inl_defd_schedule_len_v = mk_lib_crypto_mode_cfb_inl_defd_schedule_len_m };
enum mk_lib_crypto_mode_cfb_inl_defd_iv_len_e { mk_lib_crypto_mode_cfb_inl_defd_iv_len_v = mk_lib_crypto_mode_cfb_inl_defd_iv_len_m };


union mk_lib_crypto_mode_cfb_inl_defd_aligned_msg_u
{
	mk_lang_alignas(mk_lang_max(mk_lang_alignof(mk_lang_types_ulllong_t), mk_lib_crypto_mode_cfb_inl_defd_msg_len_m)) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_mode_cfb_inl_defd_msg_len_v];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_mode_cfb_inl_defd_aligned_msg_u mk_lib_crypto_mode_cfb_inl_defd_aligned_msg_t;

typedef mk_lib_crypto_mode_cfb_inl_defd_alg_key_t mk_lib_crypto_mode_cfb_inl_defd_key_t;
typedef mk_lib_crypto_mode_cfb_inl_defd_key_t const mk_lib_crypto_mode_cfb_inl_defd_key_ct;
typedef mk_lib_crypto_mode_cfb_inl_defd_key_t* mk_lib_crypto_mode_cfb_inl_defd_key_pt;
typedef mk_lib_crypto_mode_cfb_inl_defd_key_t const* mk_lib_crypto_mode_cfb_inl_defd_key_pct;

struct mk_lib_crypto_mode_cfb_inl_defd_msg_s
{
	mk_lib_crypto_mode_cfb_inl_defd_aligned_msg_t m_data;
};
typedef struct mk_lib_crypto_mode_cfb_inl_defd_msg_s mk_lib_crypto_mode_cfb_inl_defd_msg_t;
typedef mk_lib_crypto_mode_cfb_inl_defd_msg_t const mk_lib_crypto_mode_cfb_inl_defd_msg_ct;
typedef mk_lib_crypto_mode_cfb_inl_defd_msg_t* mk_lib_crypto_mode_cfb_inl_defd_msg_pt;
typedef mk_lib_crypto_mode_cfb_inl_defd_msg_t const* mk_lib_crypto_mode_cfb_inl_defd_msg_pct;

typedef mk_lib_crypto_mode_cfb_inl_defd_alg_msg_t mk_lib_crypto_mode_cfb_inl_defd_iv_t;
typedef mk_lib_crypto_mode_cfb_inl_defd_iv_t const mk_lib_crypto_mode_cfb_inl_defd_iv_ct;
typedef mk_lib_crypto_mode_cfb_inl_defd_iv_t* mk_lib_crypto_mode_cfb_inl_defd_iv_pt;
typedef mk_lib_crypto_mode_cfb_inl_defd_iv_t const* mk_lib_crypto_mode_cfb_inl_defd_iv_pct;

typedef mk_lib_crypto_mode_cfb_inl_defd_alg_schedule_t mk_lib_crypto_mode_cfb_inl_defd_schedule_t;
typedef mk_lib_crypto_mode_cfb_inl_defd_schedule_t const mk_lib_crypto_mode_cfb_inl_defd_schedule_ct;
typedef mk_lib_crypto_mode_cfb_inl_defd_schedule_t* mk_lib_crypto_mode_cfb_inl_defd_schedule_pt;
typedef mk_lib_crypto_mode_cfb_inl_defd_schedule_t const* mk_lib_crypto_mode_cfb_inl_defd_schedule_pct;

struct mk_lib_crypto_mode_cfb_inl_defd_s
{
	mk_lib_crypto_mode_cfb_inl_defd_iv_t m_iv;
};
typedef struct mk_lib_crypto_mode_cfb_inl_defd_s mk_lib_crypto_mode_cfb_inl_defd_t;
typedef mk_lib_crypto_mode_cfb_inl_defd_t const mk_lib_crypto_mode_cfb_inl_defd_ct;
typedef mk_lib_crypto_mode_cfb_inl_defd_t* mk_lib_crypto_mode_cfb_inl_defd_pt;
typedef mk_lib_crypto_mode_cfb_inl_defd_t const* mk_lib_crypto_mode_cfb_inl_defd_pct;


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_init(mk_lib_crypto_mode_cfb_inl_defd_pt const cfb, mk_lib_crypto_mode_cfb_inl_defd_iv_pct const iv) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_schedule_encrypt(mk_lib_crypto_mode_cfb_inl_defd_pt const cfb, mk_lib_crypto_mode_cfb_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_cfb_inl_defd_msg_pct const input, mk_lib_crypto_mode_cfb_inl_defd_msg_pt const output) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_schedule_decrypt(mk_lib_crypto_mode_cfb_inl_defd_pt const cfb, mk_lib_crypto_mode_cfb_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_cfb_inl_defd_msg_pct const input, mk_lib_crypto_mode_cfb_inl_defd_msg_pt const output) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_expand_enc(mk_lib_crypto_mode_cfb_inl_defd_key_pct const key, mk_lib_crypto_mode_cfb_inl_defd_schedule_pt const schedule) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_expand_dec(mk_lib_crypto_mode_cfb_inl_defd_key_pct const key, mk_lib_crypto_mode_cfb_inl_defd_schedule_pt const schedule) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_encrypt(mk_lib_crypto_mode_cfb_inl_defd_pt const cfb, mk_lib_crypto_mode_cfb_inl_defd_key_pct const key, mk_lib_crypto_mode_cfb_inl_defd_msg_pct const input, mk_lib_crypto_mode_cfb_inl_defd_msg_pt const output) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_decrypt(mk_lib_crypto_mode_cfb_inl_defd_pt const cfb, mk_lib_crypto_mode_cfb_inl_defd_key_pct const key, mk_lib_crypto_mode_cfb_inl_defd_msg_pct const input, mk_lib_crypto_mode_cfb_inl_defd_msg_pt const output) mk_lang_noexcept;


#include "mk_lib_crypto_mode_cfb_inl_defu.h"
