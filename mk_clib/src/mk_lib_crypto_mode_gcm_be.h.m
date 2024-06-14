include(`mk_lang_concat.m')dnl
ifdef(`mk_lib_crypto_mode_gcm_be_t_name', `', `define(`mk_lib_crypto_mode_gcm_be_t_name', `mk_lib_crypto_mode_gcm_be_t_alg')')dnl
define(`mk_lib_crypto_mode_gcm_be_full_name', `mk_lang_concat(`mk_lib_crypto_mode_gcm_be_', mk_lib_crypto_mode_gcm_be_t_name)')dnl
define(`mk_lib_crypto_mode_gcm_be_include_guard', `mk_lang_concat(`mk_include_guard_', mk_lib_crypto_mode_gcm_be_full_name)')dnl
define(`mk_lib_crypto_mode_gcm_be_inl_defd_base_file_name', `mk_lang_concat(`mk_lib_crypto_alg_', mk_lib_crypto_mode_gcm_be_t_alg)')dnl
define(`mk_lib_crypto_mode_gcm_be_inl_defd_ctr_file_name', `mk_lang_concat(`mk_lib_crypto_mode_ctr_be_', mk_lib_crypto_mode_gcm_be_t_alg)')dnl
define(`mk_lib_crypto_mode_gcm_be_inl_defd_key_len_m', `mk_lang_concat(`mk_lib_crypto_mode_gcm_be_', mk_lib_crypto_mode_gcm_be_t_name, `_key_len_m')')dnl
define(`mk_lib_crypto_mode_gcm_be_inl_defd_msg_len_m', `mk_lang_concat(`mk_lib_crypto_mode_gcm_be_', mk_lib_crypto_mode_gcm_be_t_name, `_msg_len_m')')dnl
define(`mk_lib_crypto_mode_gcm_be_inl_defd_schedule_len_m', `mk_lang_concat(`mk_lib_crypto_mode_gcm_be_', mk_lib_crypto_mode_gcm_be_t_name, `_schedule_len_m')')dnl
define(`mk_lib_crypto_mode_gcm_be_inl_defd_iv_len_m', `mk_lang_concat(`mk_lib_crypto_mode_gcm_be_', mk_lib_crypto_mode_gcm_be_t_name, `_iv_len_m')')dnl
`#'ifndef mk_lib_crypto_mode_gcm_be_include_guard
`#'define mk_lib_crypto_mode_gcm_be_include_guard


/* NIST SP 800-38D */


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_ghash.h"
`#include' "mk_lib_crypto_mode_gcm_be_inl_defd_base_file_name.h"
`#include' "mk_lib_crypto_mode_gcm_be_inl_defd_ctr_file_name.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


#if defined mk_lib_crypto_mode_gcm_be_debug_want && (mk_lib_crypto_mode_gcm_be_debug_want) == 1
#define mk_lib_crypto_mode_gcm_be_debug 1
#elif defined mk_lib_crypto_mode_gcm_be_debug_want && (mk_lib_crypto_mode_gcm_be_debug_want) == 0
#define mk_lib_crypto_mode_gcm_be_debug 0
#elif !defined mk_lib_crypto_mode_gcm_be_debug_want
#if defined NDEBUG
#define mk_lib_crypto_mode_gcm_be_debug 0
#else
#define mk_lib_crypto_mode_gcm_be_debug 1
#endif
#else
#error xxxxxxxxxx
#endif


`#define mk_lib_crypto_mode_gcm_be_t_name' mk_lib_crypto_mode_gcm_be_t_name
`#define mk_lib_crypto_mode_gcm_be_t_alg' mk_lib_crypto_mode_gcm_be_t_alg
#include "mk_lib_crypto_mode_gcm_be_inl_defd.h"


`#define' mk_lib_crypto_mode_gcm_be_inl_defd_key_len_m mk_lib_crypto_mode_gcm_be_inl_defd_alg_key_len_m
`#define' mk_lib_crypto_mode_gcm_be_inl_defd_msg_len_m mk_lib_crypto_mode_gcm_be_inl_defd_alg_msg_len_m
`#define' mk_lib_crypto_mode_gcm_be_inl_defd_schedule_len_m mk_lib_crypto_mode_gcm_be_inl_defd_alg_schedule_len_m
enum mk_lib_crypto_mode_gcm_be_inl_defd_key_len_e { mk_lib_crypto_mode_gcm_be_inl_defd_key_len_v = mk_lib_crypto_mode_gcm_be_inl_defd_key_len_m };
enum mk_lib_crypto_mode_gcm_be_inl_defd_msg_len_e { mk_lib_crypto_mode_gcm_be_inl_defd_msg_len_v = mk_lib_crypto_mode_gcm_be_inl_defd_msg_len_m };
enum mk_lib_crypto_mode_gcm_be_inl_defd_schedule_len_e { mk_lib_crypto_mode_gcm_be_inl_defd_schedule_len_v = mk_lib_crypto_mode_gcm_be_inl_defd_schedule_len_m };


struct mk_lib_crypto_mode_gcm_be_inl_defd_key_s
{
	mk_lib_crypto_mode_gcm_be_inl_defd_alg_key_t m_data;
};
typedef struct mk_lib_crypto_mode_gcm_be_inl_defd_key_s mk_lib_crypto_mode_gcm_be_inl_defd_key_t;
typedef mk_lib_crypto_mode_gcm_be_inl_defd_key_t const mk_lib_crypto_mode_gcm_be_inl_defd_key_ct;
typedef mk_lib_crypto_mode_gcm_be_inl_defd_key_t* mk_lib_crypto_mode_gcm_be_inl_defd_key_pt;
typedef mk_lib_crypto_mode_gcm_be_inl_defd_key_t const* mk_lib_crypto_mode_gcm_be_inl_defd_key_pct;

struct mk_lib_crypto_mode_gcm_be_inl_defd_msg_s
{
	mk_lib_crypto_mode_gcm_be_inl_defd_alg_msg_t m_data;
};
typedef struct mk_lib_crypto_mode_gcm_be_inl_defd_msg_s mk_lib_crypto_mode_gcm_be_inl_defd_msg_t;
typedef mk_lib_crypto_mode_gcm_be_inl_defd_msg_t const mk_lib_crypto_mode_gcm_be_inl_defd_msg_ct;
typedef mk_lib_crypto_mode_gcm_be_inl_defd_msg_t* mk_lib_crypto_mode_gcm_be_inl_defd_msg_pt;
typedef mk_lib_crypto_mode_gcm_be_inl_defd_msg_t const* mk_lib_crypto_mode_gcm_be_inl_defd_msg_pct;

struct mk_lib_crypto_mode_gcm_be_inl_defd_schedule_s
{
	mk_lib_crypto_mode_gcm_be_inl_defd_alg_schedule_t m_data;
};
typedef struct mk_lib_crypto_mode_gcm_be_inl_defd_schedule_s mk_lib_crypto_mode_gcm_be_inl_defd_schedule_t;
typedef mk_lib_crypto_mode_gcm_be_inl_defd_schedule_t const mk_lib_crypto_mode_gcm_be_inl_defd_schedule_ct;
typedef mk_lib_crypto_mode_gcm_be_inl_defd_schedule_t* mk_lib_crypto_mode_gcm_be_inl_defd_schedule_pt;
typedef mk_lib_crypto_mode_gcm_be_inl_defd_schedule_t const* mk_lib_crypto_mode_gcm_be_inl_defd_schedule_pct;


struct mk_lib_crypto_mode_gcm_be_inl_defd_s
{
	mk_lib_crypto_mode_gcm_be_inl_defd_schedule_t m_schedule;
	mk_lib_crypto_mode_gcm_be_inl_defd_ctr_t m_ctr;
	mk_lib_crypto_hash_block_ghash_t m_ghash;
	mk_sl_cui_uint64_t m_aad_len;
	mk_sl_cui_uint64_t m_ct_len;
	mk_lib_crypto_hash_block_ghash_block_t m_gblock;
	mk_lib_crypto_mode_gcm_be_inl_defd_alg_msg_t m_ctr_0_ct;
	#if mk_lib_crypto_mode_gcm_be_debug
	mk_lang_types_bool_t m_iv_finished;
	mk_lang_types_bool_t m_aad_finished;
	mk_lang_types_bool_t m_pt_finished;
	#endif
};
typedef struct mk_lib_crypto_mode_gcm_be_inl_defd_s mk_lib_crypto_mode_gcm_be_inl_defd_t;
typedef mk_lib_crypto_mode_gcm_be_inl_defd_t const mk_lib_crypto_mode_gcm_be_inl_defd_ct;
typedef mk_lib_crypto_mode_gcm_be_inl_defd_t* mk_lib_crypto_mode_gcm_be_inl_defd_pt;
typedef mk_lib_crypto_mode_gcm_be_inl_defd_t const* mk_lib_crypto_mode_gcm_be_inl_defd_pct;


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_finish_enc(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be, mk_sl_cui_uint8_pct const input, mk_sl_cui_uint8_pt const output, mk_lang_types_usize_t const len, mk_lib_crypto_mode_gcm_be_inl_defd_msg_pt const tag) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_finish_dec(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be, mk_sl_cui_uint8_pct const input, mk_sl_cui_uint8_pt const output, mk_lang_types_usize_t const len, mk_lib_crypto_mode_gcm_be_inl_defd_msg_pt const tag) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_encrypt(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be, mk_lib_crypto_mode_gcm_be_inl_defd_msg_pct const input, mk_lib_crypto_mode_gcm_be_inl_defd_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_decrypt(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be, mk_lib_crypto_mode_gcm_be_inl_defd_msg_pct const input, mk_lib_crypto_mode_gcm_be_inl_defd_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_aad_append(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be, mk_sl_cui_uint8_pct const aad, mk_lang_types_usize_t const len) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_aad_finish(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_iv_append(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be, mk_sl_cui_uint8_pct const iv, mk_lang_types_usize_t const len) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_iv_finish(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_expand_enc(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be, mk_lib_crypto_mode_gcm_be_inl_defd_key_pct const key) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_expand_dec(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be, mk_lib_crypto_mode_gcm_be_inl_defd_key_pct const key) mk_lang_noexcept;


#include "mk_lib_crypto_mode_gcm_be_inl_defu.h"


#if mk_lang_jumbo_want == 1
`#'include "mk_lib_crypto_mode_gcm_be_full_name.c"
#endif
#endif
