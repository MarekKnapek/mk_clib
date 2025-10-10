#ifndef mk_include_guard_mk_lib_crypto_alg_serpent_base_h
#define mk_include_guard_mk_lib_crypto_alg_serpent_base_h


#include "mk_lang_alignas.h"
#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


#define mk_lib_crypto_alg_serpent_base_nr 32
#define mk_lib_crypto_alg_serpent_base_key_len_d (256 / mk_lang_charbit)
#define mk_lib_crypto_alg_serpent_base_msg_len_d (128 / mk_lang_charbit)
#define mk_lib_crypto_alg_serpent_base_schedule_len_d ((1 + mk_lib_crypto_alg_serpent_base_nr) * mk_lib_crypto_alg_serpent_base_msg_len_d)
enum mk_lib_crypto_alg_serpent_base_key_len_e { mk_lib_crypto_alg_serpent_base_key_len_v = mk_lib_crypto_alg_serpent_base_key_len_d };
enum mk_lib_crypto_alg_serpent_base_msg_len_e { mk_lib_crypto_alg_serpent_base_msg_len_v = mk_lib_crypto_alg_serpent_base_msg_len_d };
enum mk_lib_crypto_alg_serpent_base_schedule_len_e { mk_lib_crypto_alg_serpent_base_schedule_len_v = mk_lib_crypto_alg_serpent_base_schedule_len_d };


union mk_lib_crypto_alg_serpent_base_key_data_u
{
	mk_lang_alignas(mk_lib_crypto_alg_serpent_base_key_len_v) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_alg_serpent_base_key_len_v];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_alg_serpent_base_key_data_u mk_lib_crypto_alg_serpent_base_key_data_t;
struct mk_lib_crypto_alg_serpent_base_key_s
{
	mk_lib_crypto_alg_serpent_base_key_data_t m_data;
};
typedef struct mk_lib_crypto_alg_serpent_base_key_s mk_lib_crypto_alg_serpent_base_key_t;
mk_lang_typedef(mk_lib_crypto_alg_serpent_base_key);

union mk_lib_crypto_alg_serpent_base_msg_data_u
{
	mk_lang_alignas(mk_lib_crypto_alg_serpent_base_msg_len_v) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_alg_serpent_base_msg_len_v];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_alg_serpent_base_msg_data_u mk_lib_crypto_alg_serpent_base_msg_data_t;
struct mk_lib_crypto_alg_serpent_base_msg_s
{
	mk_lib_crypto_alg_serpent_base_msg_data_t m_data;
};
typedef struct mk_lib_crypto_alg_serpent_base_msg_s mk_lib_crypto_alg_serpent_base_msg_t;
mk_lang_typedef(mk_lib_crypto_alg_serpent_base_msg);

union mk_lib_crypto_alg_serpent_base_schedule_data_u
{
	mk_lib_crypto_alg_serpent_base_msg_t m_msgs[1 + mk_lib_crypto_alg_serpent_base_nr];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_alg_serpent_base_schedule_data_u mk_lib_crypto_alg_serpent_base_schedule_data_t;
struct mk_lib_crypto_alg_serpent_base_schedule_s
{
	mk_lib_crypto_alg_serpent_base_schedule_data_t m_data;
};
typedef struct mk_lib_crypto_alg_serpent_base_schedule_s mk_lib_crypto_alg_serpent_base_schedule_t;
mk_lang_typedef(mk_lib_crypto_alg_serpent_base_schedule);


#if mk_lang_jumbo_have
#include "mk_lib_crypto_alg_serpent_base.c"
#endif
#endif
