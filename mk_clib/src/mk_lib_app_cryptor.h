#ifndef mk_include_guard_mk_lib_app_cryptor_h
#define mk_include_guard_mk_lib_app_cryptor_h


#include "mk_lang_bitness.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_roundup.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_app_cryptor_alg_names.h"
#include "mk_lib_app_cryptor_mode_names.h"
#include "mk_lib_crypto_hash_names.h"
#include "mk_lib_crypto_padding_names.h"
#include "mk_sl_cui_uint8.h"


#if mk_lang_bitness_is_16
#define mk_lib_app_cryptor_buff_size 4 * 1024
#define mk_lib_app_cryptor_buff_algn 4 * 1024
#elif mk_lang_bitness_is_32
#define mk_lib_app_cryptor_buff_size 64 * 1024
#define mk_lib_app_cryptor_buff_algn 64 * 1024
#elif mk_lang_bitness_is_64
#define mk_lib_app_cryptor_buff_size 256 * 1024
#define mk_lib_app_cryptor_buff_algn 64 * 1024
#endif
union mk_lib_app_cryptor_buff_data_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lang_roundup_add(2 * mk_lib_app_cryptor_buff_size, mk_lib_app_cryptor_buff_algn)];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_app_cryptor_buff_data_u mk_lib_app_cryptor_buff_data_t;
struct mk_lib_app_cryptor_buff_s
{
	mk_lib_app_cryptor_buff_data_t m_data;
};
typedef struct mk_lib_app_cryptor_buff_s mk_lib_app_cryptor_buff_t;

enum mk_lib_app_cryptor_direction_e
{
	mk_lib_app_cryptor_direction_e_encrypt,
	mk_lib_app_cryptor_direction_e_decrypt,
	mk_lib_app_cryptor_direction_e_dummy_end
};
typedef enum mk_lib_app_cryptor_direction_e mk_lib_app_cryptor_direction_t;


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_app_cryptor_s
{
	mk_lib_app_cryptor_direction_t m_direction;
	mk_lib_app_cryptor_mode_names_id_t m_mode;
	mk_lib_app_cryptor_alg_names_id_t m_alg;
	mk_lib_crypto_padding_names_id_t m_padding;
	mk_lang_types_bool_t m_kdf;
	mk_lib_crypto_hash_names_id_t m_hash;
	mk_lang_types_ulong_t m_cost;
	mk_lang_types_pchar_t m_password_buf[4 * 1024];
	mk_lang_types_sint_t m_password_len;
	mk_lang_types_pchar_t m_salt_buf[4 * 1024];
	mk_lang_types_sint_t m_salt_len;
	mk_lib_app_cryptor_buff_t m_buffer;
};
typedef struct mk_lib_app_cryptor_s mk_lib_app_cryptor_t;
mk_lang_typedef(mk_lib_app_cryptor);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_construct_args(mk_lib_app_cryptor_pt const cryptor, mk_lib_app_cryptor_direction_t const direction, mk_lib_app_cryptor_mode_names_id_t const mode, mk_lib_app_cryptor_alg_names_id_t const alg, mk_lib_crypto_padding_names_id_t const padding, mk_lang_types_bool_t const kdf, mk_lib_crypto_hash_names_id_t const hash, mk_lang_types_ulong_t const cost, mk_lang_types_pchar_pct const password_buf, mk_lang_types_sint_t const password_len, mk_lang_types_pchar_pct const salt_buf, mk_lang_types_sint_t const salt_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_construct_parse(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_cui_uint8_pt mk_lib_app_cryptor_rw_get_buffer_1_ptr(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_get_buffer_1_len(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_cui_uint8_pt mk_lib_app_cryptor_rw_get_buffer_2_ptr(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_get_buffer_2_len(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_app_cryptor.c"
#endif
#endif
