#ifndef mk_include_guard_mk_lib_crypto_alg_serpent_h
#define mk_include_guard_mk_lib_crypto_alg_serpent_h


#include "mk_lang_alignas.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_serpent_base.h"
#include "mk_sl_cui_uint8.h"


#define mk_lib_crypto_alg_serpent_nr 32
#define mk_lib_crypto_alg_serpent_key_len_d (256 / mk_lang_charbit)
#define mk_lib_crypto_alg_serpent_msg_len_d (128 / mk_lang_charbit)
#define mk_lib_crypto_alg_serpent_schedule_len_d ((1 + mk_lib_crypto_alg_serpent_nr) * mk_lib_crypto_alg_serpent_msg_len_d)
enum mk_lib_crypto_alg_serpent_key_len_e { mk_lib_crypto_alg_serpent_key_len_v = mk_lib_crypto_alg_serpent_key_len_d };
enum mk_lib_crypto_alg_serpent_msg_len_e { mk_lib_crypto_alg_serpent_msg_len_v = mk_lib_crypto_alg_serpent_msg_len_d };
enum mk_lib_crypto_alg_serpent_schedule_len_e { mk_lib_crypto_alg_serpent_schedule_len_v = mk_lib_crypto_alg_serpent_schedule_len_d };


union mk_lib_crypto_alg_serpent_key_data_u
{
	mk_lib_crypto_alg_serpent_base_key_t m_base;
	mk_lang_alignas(mk_lib_crypto_alg_serpent_key_len_v) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_alg_serpent_key_len_v];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_alg_serpent_key_data_u mk_lib_crypto_alg_serpent_key_data_t;
struct mk_lib_crypto_alg_serpent_key_s
{
	mk_lib_crypto_alg_serpent_key_data_t m_data;
};
typedef struct mk_lib_crypto_alg_serpent_key_s mk_lib_crypto_alg_serpent_key_t;
mk_lang_typedef(mk_lib_crypto_alg_serpent_key);

union mk_lib_crypto_alg_serpent_msg_data_u
{
	mk_lib_crypto_alg_serpent_base_msg_t m_base;
	mk_lang_alignas(mk_lib_crypto_alg_serpent_msg_len_v) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_alg_serpent_msg_len_v];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_alg_serpent_msg_data_u mk_lib_crypto_alg_serpent_msg_data_t;
struct mk_lib_crypto_alg_serpent_msg_s
{
	mk_lib_crypto_alg_serpent_msg_data_t m_data;
};
typedef struct mk_lib_crypto_alg_serpent_msg_s mk_lib_crypto_alg_serpent_msg_t;
mk_lang_typedef(mk_lib_crypto_alg_serpent_msg);

union mk_lib_crypto_alg_serpent_schedule_data_u
{
	mk_lib_crypto_alg_serpent_base_schedule_t m_base;
	mk_lib_crypto_alg_serpent_msg_t m_msgs[1 + mk_lib_crypto_alg_serpent_nr];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_alg_serpent_schedule_data_u mk_lib_crypto_alg_serpent_schedule_data_t;
struct mk_lib_crypto_alg_serpent_schedule_s
{
	mk_lib_crypto_alg_serpent_schedule_data_t m_data;
};
typedef struct mk_lib_crypto_alg_serpent_schedule_s mk_lib_crypto_alg_serpent_schedule_t;
mk_lang_typedef(mk_lib_crypto_alg_serpent_schedule);


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_serpent_schedule_encrypt(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_serpent_schedule_decrypt(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_serpent_expand_enc(mk_lib_crypto_alg_serpent_key_pct const key, mk_lib_crypto_alg_serpent_schedule_pt const schedule) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_serpent_expand_dec(mk_lib_crypto_alg_serpent_key_pct const key, mk_lib_crypto_alg_serpent_schedule_pt const schedule) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_serpent_encrypt(mk_lib_crypto_alg_serpent_key_pct const key, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_serpent_decrypt(mk_lib_crypto_alg_serpent_key_pct const key, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_crypto_alg_serpent.c"
#endif
#endif
