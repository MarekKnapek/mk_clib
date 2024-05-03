#ifndef mk_include_guard_mk_lib_crypto_alg_twofish_192
#define mk_include_guard_mk_lib_crypto_alg_twofish_192


#include "mk_lang_alignas.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_alg_twofish_192_nr (16)
#define mk_lib_crypto_alg_twofish_192_key_len_m (192 / mk_lang_charbit)
#define mk_lib_crypto_alg_twofish_192_msg_len_m (128 / mk_lang_charbit)
#define mk_lib_crypto_alg_twofish_192_schedule_len_m ((mk_lib_crypto_alg_twofish_192_key_len_m / (mk_lib_crypto_alg_twofish_192_msg_len_m / 2)) * (32 / mk_lang_charbit) + 2 * mk_lib_crypto_alg_twofish_192_msg_len_m + 2 * mk_lib_crypto_alg_twofish_192_nr * (32 / mk_lang_charbit))
enum mk_lib_crypto_alg_twofish_192_key_len_e { mk_lib_crypto_alg_twofish_192_key_len_v = mk_lib_crypto_alg_twofish_192_key_len_m };
enum mk_lib_crypto_alg_twofish_192_msg_len_e { mk_lib_crypto_alg_twofish_192_msg_len_v = mk_lib_crypto_alg_twofish_192_msg_len_m };
enum mk_lib_crypto_alg_twofish_192_schedule_len_e { mk_lib_crypto_alg_twofish_192_schedule_len_v = mk_lib_crypto_alg_twofish_192_schedule_len_m };


union mk_lib_crypto_alg_twofish_192_key_data_u
{
	mk_lang_alignas(mk_lib_crypto_alg_twofish_192_msg_len_v) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_alg_twofish_192_key_len_v];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_alg_twofish_192_key_data_u mk_lib_crypto_alg_twofish_192_key_data_t;

struct mk_lib_crypto_alg_twofish_192_key_s
{
	mk_lib_crypto_alg_twofish_192_key_data_t m_data;
};
typedef struct mk_lib_crypto_alg_twofish_192_key_s mk_lib_crypto_alg_twofish_192_key_t;
typedef mk_lib_crypto_alg_twofish_192_key_t const mk_lib_crypto_alg_twofish_192_key_ct;
typedef mk_lib_crypto_alg_twofish_192_key_t* mk_lib_crypto_alg_twofish_192_key_pt;
typedef mk_lib_crypto_alg_twofish_192_key_t const* mk_lib_crypto_alg_twofish_192_key_pct;


union mk_lib_crypto_alg_twofish_192_msg_data_u
{
	mk_lang_alignas(mk_lib_crypto_alg_twofish_192_msg_len_v) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_alg_twofish_192_msg_len_v];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_alg_twofish_192_msg_data_u mk_lib_crypto_alg_twofish_192_msg_data_t;

struct mk_lib_crypto_alg_twofish_192_msg_s
{
	mk_lib_crypto_alg_twofish_192_msg_data_t m_data;
};
typedef struct mk_lib_crypto_alg_twofish_192_msg_s mk_lib_crypto_alg_twofish_192_msg_t;
typedef mk_lib_crypto_alg_twofish_192_msg_t const mk_lib_crypto_alg_twofish_192_msg_ct;
typedef mk_lib_crypto_alg_twofish_192_msg_t* mk_lib_crypto_alg_twofish_192_msg_pt;
typedef mk_lib_crypto_alg_twofish_192_msg_t const* mk_lib_crypto_alg_twofish_192_msg_pct;


union mk_lib_crypto_alg_twofish_192_schedule_data_u
{
	mk_lang_alignas(mk_lib_crypto_alg_twofish_192_msg_len_v) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_alg_twofish_192_schedule_len_v];
	mk_lang_alignas(mk_lib_crypto_alg_twofish_192_msg_len_v) mk_sl_cui_uint32_t m_uint32s[mk_lib_crypto_alg_twofish_192_schedule_len_v / (32 / mk_lang_charbit)];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_alg_twofish_192_schedule_data_u mk_lib_crypto_alg_twofish_192_schedule_data_t;

struct mk_lib_crypto_alg_twofish_192_schedule_s
{
	mk_lib_crypto_alg_twofish_192_schedule_data_t m_data;
};
typedef struct mk_lib_crypto_alg_twofish_192_schedule_s mk_lib_crypto_alg_twofish_192_schedule_t;
typedef mk_lib_crypto_alg_twofish_192_schedule_t const mk_lib_crypto_alg_twofish_192_schedule_ct;
typedef mk_lib_crypto_alg_twofish_192_schedule_t* mk_lib_crypto_alg_twofish_192_schedule_pt;
typedef mk_lib_crypto_alg_twofish_192_schedule_t const* mk_lib_crypto_alg_twofish_192_schedule_pct;


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_twofish_192_schedule_encrypt(mk_lib_crypto_alg_twofish_192_schedule_pct const schedule, mk_lib_crypto_alg_twofish_192_msg_pct const input, mk_lib_crypto_alg_twofish_192_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_twofish_192_schedule_decrypt(mk_lib_crypto_alg_twofish_192_schedule_pct const schedule, mk_lib_crypto_alg_twofish_192_msg_pct const input, mk_lib_crypto_alg_twofish_192_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_twofish_192_expand_enc(mk_lib_crypto_alg_twofish_192_key_pct const key, mk_lib_crypto_alg_twofish_192_schedule_pt const schedule) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_twofish_192_expand_dec(mk_lib_crypto_alg_twofish_192_key_pct const key, mk_lib_crypto_alg_twofish_192_schedule_pt const schedule) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_twofish_192_encrypt(mk_lib_crypto_alg_twofish_192_key_pct const key, mk_lib_crypto_alg_twofish_192_msg_pct const input, mk_lib_crypto_alg_twofish_192_msg_pt const output) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_twofish_192_decrypt(mk_lib_crypto_alg_twofish_192_key_pct const key, mk_lib_crypto_alg_twofish_192_msg_pct const input, mk_lib_crypto_alg_twofish_192_msg_pt const output) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_alg_twofish_192.c"
#endif
#endif
