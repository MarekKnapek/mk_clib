#ifndef mk_include_guard_mk_lib_app_cryptor_h
#define mk_include_guard_mk_lib_app_cryptor_h


#include "mk_lang_bitness.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_pow2.h"
#include "mk_lang_roundup.h"
#include "mk_lang_tchar.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_app_cryptor_alg_names.h"
#include "mk_lib_app_cryptor_mode_names.h"
#include "mk_lib_app_cryptor_mode_stream_any2.h"
#include "mk_lib_crypto_hash_names.h"
#include "mk_lib_crypto_mac_hmac_stream_any2.h"
#include "mk_lib_crypto_padding_names.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_speedometer.h"


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

enum mk_lib_app_cryptor_param_id_e
{
	mk_lib_app_cryptor_param_id_e_direction,
	mk_lib_app_cryptor_param_id_e_mode     ,
	mk_lib_app_cryptor_param_id_e_alg      ,
	mk_lib_app_cryptor_param_id_e_padding  ,
	mk_lib_app_cryptor_param_id_e_kdf      ,
	mk_lib_app_cryptor_param_id_e_hash     ,
	mk_lib_app_cryptor_param_id_e_cost     ,
	mk_lib_app_cryptor_param_id_e_password ,
	mk_lib_app_cryptor_param_id_e_salt     ,
	mk_lib_app_cryptor_param_id_e_input    ,
	mk_lib_app_cryptor_param_id_e_output   ,
	mk_lib_app_cryptor_param_id_e_dummy_end
};
typedef enum mk_lib_app_cryptor_param_id_e mk_lib_app_cryptor_param_id_t;
mk_lang_typedef(mk_lib_app_cryptor_param_id);

enum mk_lib_app_cryptor_direction_e
{
	mk_lib_app_cryptor_direction_e_encrypt,
	mk_lib_app_cryptor_direction_e_decrypt,
	mk_lib_app_cryptor_direction_e_dummy_end
};
typedef enum mk_lib_app_cryptor_direction_e mk_lib_app_cryptor_direction_t;

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_app_cryptor_config_s
{
	mk_lib_app_cryptor_direction_t m_direction;
	mk_lib_app_cryptor_mode_names_id_t m_mode;
	mk_lib_app_cryptor_alg_names_id_t m_alg;
	mk_lib_crypto_padding_names_id_t m_padding;
	mk_lang_types_bool_t m_kdf;
	mk_lib_crypto_hash_names_id_t m_hash;
	mk_lang_types_ulong_t m_cost;
	mk_sl_cui_uint8_pct m_password_ptr;
	mk_lang_types_sint_t m_password_len;
	mk_sl_cui_uint8_pct m_salt_ptr;
	mk_lang_types_sint_t m_salt_len;
};
typedef struct mk_lib_app_cryptor_config_s mk_lib_app_cryptor_config_t;
mk_lang_typedef(mk_lib_app_cryptor_config);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_app_cryptor_command_line_s
{
	mk_lib_app_cryptor_config_t m_config;
	mk_lang_tchar_pct m_input_ptr;
	mk_lang_types_sint_t m_input_len;
	mk_lang_tchar_pct m_output_ptr;
	mk_lang_types_sint_t m_output_len;
};
typedef struct mk_lib_app_cryptor_command_line_s mk_lib_app_cryptor_command_line_t;
mk_lang_typedef(mk_lib_app_cryptor_command_line);
#include "mk_lang_warning_msvc_pop.h"


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_app_cryptor_s
{
	mk_lib_app_cryptor_config_t m_config;
	mk_sl_cui_uint8_t m_password_buf[4 * 1024];
	mk_sl_cui_uint8_t m_salt_buf[4 * 1024];
	mk_lib_app_cryptor_mode_stream_any2_iv_t m_mode_iv;
	mk_lib_app_cryptor_mode_stream_any2_t m_mode_stream;
	mk_lib_crypto_mac_hmac_stream_any2_t m_hmac_stream;
	mk_lang_types_bool_t m_iv_handled;
	mk_lang_types_bool_t m_padding_handled;
	mk_sl_cui_uint8_t m_last_chunk_buf[mk_lang_pow2_roundup(((mk_lang_types_sint_t)(mk_lib_app_cryptor_mode_stream_any2_msg_len_v)) + ((mk_lang_types_sint_t)(mk_lib_crypto_mac_hmac_stream_any2_digest_len_v)))];
	mk_lang_types_sint_t m_last_chunk_idx;
	mk_sl_speedometer_t m_speedometer;
	mk_lib_app_cryptor_buff_t m_buffer;
};
typedef struct mk_lib_app_cryptor_s mk_lib_app_cryptor_t;
mk_lang_typedef(mk_lib_app_cryptor);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_construct_args(mk_lib_app_cryptor_pt const cryptor, mk_lib_app_cryptor_direction_t const direction, mk_lib_app_cryptor_mode_names_id_t const mode, mk_lib_app_cryptor_alg_names_id_t const alg, mk_lib_crypto_padding_names_id_t const padding, mk_lang_types_bool_t const kdf, mk_lib_crypto_hash_names_id_t const hash, mk_lang_types_ulong_t const cost, mk_sl_cui_uint8_pct const password_ptr, mk_lang_types_sint_t const password_len, mk_sl_cui_uint8_pct const salt_ptr, mk_lang_types_sint_t const salt_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_construct_config(mk_lib_app_cryptor_pt const cryptor, mk_lib_app_cryptor_config_pct const config) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_construct_cmd_line(mk_lib_app_cryptor_pt const cryptor, mk_lib_app_cryptor_command_line_pt const command_line, mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens, mk_lib_app_cryptor_param_id_pt const failed) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_construct_parse(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_destroy(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_init_objects(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_cui_uint8_pt mk_lib_app_cryptor_rw_get_buffer_1_ptr(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_get_buffer_1_len(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_cui_uint8_pt mk_lib_app_cryptor_rw_get_buffer_2_ptr(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_get_buffer_2_len(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_append_chunk(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pct const input_ptr, mk_lang_types_sint_t const input_len, mk_sl_cui_uint8_pt const output_ptr, mk_lang_types_sint_t const output_len, mk_lang_types_sint_pt const input_consumed, mk_lang_types_sint_pt const output_consumed) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_finish(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pt const output_ptr, mk_lang_types_sint_t const output_len, mk_lang_types_sint_pt const consumed, mk_lang_types_bool_pt const succeeded) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_app_cryptor.c"
#endif
#endif
