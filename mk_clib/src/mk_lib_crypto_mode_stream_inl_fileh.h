#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


#include "mk_lib_crypto_mode_stream_inl_defd.h"


enum mk_lib_crypto_mode_stream_inl_defd_iv_len_e{mk_lib_crypto_mode_stream_inl_defd_iv_len_v = mk_lib_crypto_mode_stream_inl_defd_base_iv_len_v}; typedef enum mk_lib_crypto_mode_stream_inl_defd_iv_len_e mk_lib_crypto_mode_stream_inl_defd_iv_len_t;
enum mk_lib_crypto_mode_stream_inl_defd_key_len_e{mk_lib_crypto_mode_stream_inl_defd_key_len_v = mk_lib_crypto_mode_stream_inl_defd_base_key_len_v}; typedef enum mk_lib_crypto_mode_stream_inl_defd_key_len_e mk_lib_crypto_mode_stream_inl_defd_key_len_t;
enum mk_lib_crypto_mode_stream_inl_defd_msg_len_e{mk_lib_crypto_mode_stream_inl_defd_msg_len_v = mk_lib_crypto_mode_stream_inl_defd_base_msg_len_v}; typedef enum mk_lib_crypto_mode_stream_inl_defd_msg_len_e mk_lib_crypto_mode_stream_inl_defd_msg_len_t;


union mk_lib_crypto_mode_stream_inl_defd_iv_data_u
{
	#if mk_lib_crypto_mode_stream_inl_defd_iv_len_d != 0
	mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_mode_stream_inl_defd_base_iv_len_v];
	mk_lib_crypto_mode_stream_inl_defd_base_iv_t m_base;
	#else
	#if defined __cplusplus
	#else
	mk_lang_types_sint_t m_dummy;
	#endif
	#endif
};
typedef union mk_lib_crypto_mode_stream_inl_defd_iv_data_u mk_lib_crypto_mode_stream_inl_defd_iv_data_t;
struct mk_lib_crypto_mode_stream_inl_defd_iv_s
{
	mk_lib_crypto_mode_stream_inl_defd_iv_data_t m_data;
};
typedef struct mk_lib_crypto_mode_stream_inl_defd_iv_s mk_lib_crypto_mode_stream_inl_defd_iv_t;
mk_lang_typedef(mk_lib_crypto_mode_stream_inl_defd_iv);

union mk_lib_crypto_mode_stream_inl_defd_key_data_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_mode_stream_inl_defd_base_key_len_v];
	mk_lib_crypto_mode_stream_inl_defd_base_key_t m_base;
};
typedef union mk_lib_crypto_mode_stream_inl_defd_key_data_u mk_lib_crypto_mode_stream_inl_defd_key_data_t;
struct mk_lib_crypto_mode_stream_inl_defd_key_s
{
	mk_lib_crypto_mode_stream_inl_defd_key_data_t m_data;
};
typedef struct mk_lib_crypto_mode_stream_inl_defd_key_s mk_lib_crypto_mode_stream_inl_defd_key_t;
mk_lang_typedef(mk_lib_crypto_mode_stream_inl_defd_key);

union mk_lib_crypto_mode_stream_inl_defd_msg_data_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_mode_stream_inl_defd_base_msg_len_v];
	mk_lib_crypto_mode_stream_inl_defd_base_msg_t m_base;
};
typedef union mk_lib_crypto_mode_stream_inl_defd_msg_data_u mk_lib_crypto_mode_stream_inl_defd_msg_data_t;
struct mk_lib_crypto_mode_stream_inl_defd_msg_s
{
	mk_lib_crypto_mode_stream_inl_defd_msg_data_t m_data;
};
typedef struct mk_lib_crypto_mode_stream_inl_defd_msg_s mk_lib_crypto_mode_stream_inl_defd_msg_t;
mk_lang_typedef(mk_lib_crypto_mode_stream_inl_defd_msg);


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_crypto_mode_stream_inl_defd_s
{
	mk_lib_crypto_mode_stream_inl_defd_base_alg_t m_base_alg;
	mk_lib_crypto_mode_stream_inl_defd_msg_t m_msg;
	mk_lang_types_sint_t m_idx;
};
typedef struct mk_lib_crypto_mode_stream_inl_defd_s mk_lib_crypto_mode_stream_inl_defd_t;
mk_lang_typedef(mk_lib_crypto_mode_stream_inl_defd);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_inl_defd_rw_set_iv(mk_lib_crypto_mode_stream_inl_defd_pt const stream, mk_lib_crypto_mode_stream_inl_defd_iv_pct const iv) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_inl_defd_rw_set_key_enc(mk_lib_crypto_mode_stream_inl_defd_pt const stream, mk_lib_crypto_mode_stream_inl_defd_key_pct const key) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_inl_defd_rw_set_key_dec(mk_lib_crypto_mode_stream_inl_defd_pt const stream, mk_lib_crypto_mode_stream_inl_defd_key_pct const key) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_inl_defd_rw_encrypt(mk_lib_crypto_mode_stream_inl_defd_pt const stream, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_inl_defd_rw_decrypt(mk_lib_crypto_mode_stream_inl_defd_pt const stream, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept;


#include "mk_lib_crypto_mode_stream_inl_defu.h"
