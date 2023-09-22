#ifndef mk_include_guard_mk_lib_crypto_alg_aes_base
#define mk_include_guard_mk_lib_crypto_alg_aes_base


#include "mk_sl_uint8.h"
#include "mk_lang_types.h"
#include "mk_lang_charbit.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_alignas.h"


#define mk_lib_crypto_alg_aes_base_word_bits 32
#define mk_lib_crypto_alg_aes_base_word_bytes (mk_lib_crypto_alg_aes_base_word_bits / mk_lang_charbit)
#define mk_lib_crypto_alg_aes_base_msg_bits 128
#define mk_lib_crypto_alg_aes_base_msg_words (mk_lib_crypto_alg_aes_base_msg_bits / mk_lib_crypto_alg_aes_base_word_bits)
#define mk_lib_crypto_alg_aes_base_msg_len_d (mk_lib_crypto_alg_aes_base_msg_bits / mk_lang_charbit)


enum mk_lib_crypto_alg_aes_base_msg_len_e { mk_lib_crypto_alg_aes_base_msg_len_v = mk_lib_crypto_alg_aes_base_msg_len_d };


union mk_lib_crypto_alg_aes_base_aligned_msg_u
{
	mk_lang_alignas(mk_lib_crypto_alg_aes_base_msg_len_v) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_alg_aes_base_msg_len_v];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_alg_aes_base_aligned_msg_u mk_lib_crypto_alg_aes_base_aligned_msg_t;

struct mk_lib_crypto_alg_aes_base_msg_s
{
	mk_lib_crypto_alg_aes_base_aligned_msg_t m_data;
};
typedef struct mk_lib_crypto_alg_aes_base_msg_s mk_lib_crypto_alg_aes_base_msg_t;
typedef mk_lib_crypto_alg_aes_base_msg_t const mk_lib_crypto_alg_aes_base_msg_ct;
typedef mk_lib_crypto_alg_aes_base_msg_t* mk_lib_crypto_alg_aes_base_msg_pt;
typedef mk_lib_crypto_alg_aes_base_msg_t const* mk_lib_crypto_alg_aes_base_msg_pct;

union mk_lib_crypto_alg_aes_base_aligned_word_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_alg_aes_base_word_bytes];
	mk_lang_types_ulong_t m_align;
};
typedef union mk_lib_crypto_alg_aes_base_aligned_word_u mk_lib_crypto_alg_aes_base_aligned_word_t;

struct mk_lib_crypto_alg_aes_base_word_s
{
	mk_lib_crypto_alg_aes_base_aligned_word_t m_data;
};
typedef struct mk_lib_crypto_alg_aes_base_word_s mk_lib_crypto_alg_aes_base_word_t;
typedef mk_lib_crypto_alg_aes_base_word_t const mk_lib_crypto_alg_aes_base_word_ct;
typedef mk_lib_crypto_alg_aes_base_word_t* mk_lib_crypto_alg_aes_base_word_pt;
typedef mk_lib_crypto_alg_aes_base_word_t const* mk_lib_crypto_alg_aes_base_word_pct;


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_sub_byte(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_inv_sub_byte(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_sub_bytes(mk_lib_crypto_alg_aes_base_msg_pct const a, mk_lib_crypto_alg_aes_base_msg_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_inv_sub_bytes(mk_lib_crypto_alg_aes_base_msg_pct const a, mk_lib_crypto_alg_aes_base_msg_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_shift_rows(mk_lib_crypto_alg_aes_base_msg_pct const a, mk_lib_crypto_alg_aes_base_msg_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_inv_shift_rows(mk_lib_crypto_alg_aes_base_msg_pct const a, mk_lib_crypto_alg_aes_base_msg_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_mul_1(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_mul_2(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_mul_3(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_mul_4(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_mul_8(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_mul_9(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_mul_b(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_mul_d(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_mul_e(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_mix_columns(mk_lib_crypto_alg_aes_base_msg_pct const a, mk_lib_crypto_alg_aes_base_msg_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_inv_mix_columns(mk_lib_crypto_alg_aes_base_msg_pct const a, mk_lib_crypto_alg_aes_base_msg_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_add_key2(mk_lib_crypto_alg_aes_base_msg_pt const a, mk_lib_crypto_alg_aes_base_msg_pct const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_add_key3(mk_lib_crypto_alg_aes_base_msg_pct const a, mk_lib_crypto_alg_aes_base_msg_pct const b, mk_lib_crypto_alg_aes_base_msg_pt const c) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_rot_word(mk_lib_crypto_alg_aes_base_word_pct const a, mk_lib_crypto_alg_aes_base_word_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_sub_word(mk_lib_crypto_alg_aes_base_word_pct const a, mk_lib_crypto_alg_aes_base_word_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_base_xor_word(mk_lib_crypto_alg_aes_base_word_pct const a, mk_sl_cui_uint8_pct const b, mk_lib_crypto_alg_aes_base_word_pt const c, mk_sl_cui_uint8_pt const d) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_alg_aes_base.c"
#endif
#endif
