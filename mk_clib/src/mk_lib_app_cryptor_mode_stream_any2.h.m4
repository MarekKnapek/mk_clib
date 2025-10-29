include(`mk_mm_nl.m')dnl
include(`mk_lib_app_cryptor_mode_stream.m')dnl
include(`mk_mm_max.m')dnl
#ifndef mk_include_guard_mk_lib_app_cryptor_mode_stream_any2_h
#define mk_include_guard_mk_lib_app_cryptor_mode_stream_any2_h

#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_app_cryptor_mode_stream.h"
#include "mk_lib_app_cryptor_mode_stream_any1.h"
#include "mk_sl_cui_uint8.h"


`#'define mk_lib_app_cryptor_mode_stream_any2_iv_len_d mk_mm_max2(mk_lib_app_cryptor_mode_stream_mm_for_all(`mk_lib_app_cryptor_mode_stream_$1_$3_iv_len_d, '))
`#'define mk_lib_app_cryptor_mode_stream_any2_key_len_d mk_mm_max2(mk_lib_app_cryptor_mode_stream_mm_for_all(`mk_lib_app_cryptor_mode_stream_$1_$3_key_len_d, '))
`#'define mk_lib_app_cryptor_mode_stream_any2_msg_len_d mk_mm_max2(mk_lib_app_cryptor_mode_stream_mm_for_all(`mk_lib_app_cryptor_mode_stream_$1_$3_msg_len_d, '))
enum mk_lib_app_cryptor_mode_stream_any2_iv_len_e{mk_lib_app_cryptor_mode_stream_any2_iv_len_v = mk_lib_app_cryptor_mode_stream_any2_iv_len_d}; typedef enum mk_lib_app_cryptor_mode_stream_any2_iv_len_e mk_lib_app_cryptor_mode_stream_any2_iv_len_t; mk_lang_typedef(mk_lib_app_cryptor_mode_stream_any2_iv_len);
enum mk_lib_app_cryptor_mode_stream_any2_key_len_e{mk_lib_app_cryptor_mode_stream_any2_key_len_v = mk_lib_app_cryptor_mode_stream_any2_key_len_d}; typedef enum mk_lib_app_cryptor_mode_stream_any2_key_len_e mk_lib_app_cryptor_mode_stream_any2_key_len_t; mk_lang_typedef(mk_lib_app_cryptor_mode_stream_any2_key_len);
enum mk_lib_app_cryptor_mode_stream_any2_msg_len_e{mk_lib_app_cryptor_mode_stream_any2_msg_len_v = mk_lib_app_cryptor_mode_stream_any2_msg_len_d}; typedef enum mk_lib_app_cryptor_mode_stream_any2_msg_len_e mk_lib_app_cryptor_mode_stream_any2_msg_len_t; mk_lang_typedef(mk_lib_app_cryptor_mode_stream_any2_msg_len);

mk_lib_app_cryptor_mode_stream_mm_for_all(`dnl
struct mk_lib_app_cryptor_mode_stream_any2_iv_$1_$3_s{ mk_lib_app_cryptor_mode_stream_$1_$3_iv_t m_$1_$3; }; typedef struct mk_lib_app_cryptor_mode_stream_any2_iv_$1_$3_s mk_lib_app_cryptor_mode_stream_any2_iv_$1_$3_t; mk_lang_typedef(mk_lib_app_cryptor_mode_stream_any2_iv_$1_$3);
')dnl
union mk_lib_app_cryptor_mode_stream_any2_iv_data_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_app_cryptor_mode_stream_any2_iv_len_v];
mk_lib_app_cryptor_mode_stream_mm_for_all(`dnl
	mk_lib_app_cryptor_mode_stream_any2_iv_$1_$3_t m_$1_$3;
')dnl
};
typedef union mk_lib_app_cryptor_mode_stream_any2_iv_data_u mk_lib_app_cryptor_mode_stream_any2_iv_data_t;
struct mk_lib_app_cryptor_mode_stream_any2_iv_s
{
	mk_lib_app_cryptor_mode_stream_any2_iv_data_t m_data;
};
typedef struct mk_lib_app_cryptor_mode_stream_any2_iv_s mk_lib_app_cryptor_mode_stream_any2_iv_t;
mk_lang_typedef(mk_lib_app_cryptor_mode_stream_any2_iv);

mk_lib_app_cryptor_mode_stream_mm_for_all(`dnl
struct mk_lib_app_cryptor_mode_stream_any2_key_$1_$3_s{ mk_lib_app_cryptor_mode_stream_$1_$3_key_t m_$1_$3; }; typedef struct mk_lib_app_cryptor_mode_stream_any2_key_$1_$3_s mk_lib_app_cryptor_mode_stream_any2_key_$1_$3_t; mk_lang_typedef(mk_lib_app_cryptor_mode_stream_any2_key_$1_$3);
')dnl
union mk_lib_app_cryptor_mode_stream_any2_key_data_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_app_cryptor_mode_stream_any2_key_len_v];
mk_lib_app_cryptor_mode_stream_mm_for_all(`dnl
	mk_lib_app_cryptor_mode_stream_any2_key_$1_$3_t m_$1_$3;
')dnl
};
typedef union mk_lib_app_cryptor_mode_stream_any2_key_data_u mk_lib_app_cryptor_mode_stream_any2_key_data_t;
struct mk_lib_app_cryptor_mode_stream_any2_key_s
{
	mk_lib_app_cryptor_mode_stream_any2_key_data_t m_data;
};
typedef struct mk_lib_app_cryptor_mode_stream_any2_key_s mk_lib_app_cryptor_mode_stream_any2_key_t;
mk_lang_typedef(mk_lib_app_cryptor_mode_stream_any2_key);

mk_lib_app_cryptor_mode_stream_mm_for_all(`dnl
struct mk_lib_app_cryptor_mode_stream_any2_msg_$1_$3_s{ mk_lib_app_cryptor_mode_stream_$1_$3_msg_t m_$1_$3; }; typedef struct mk_lib_app_cryptor_mode_stream_any2_msg_$1_$3_s mk_lib_app_cryptor_mode_stream_any2_msg_$1_$3_t; mk_lang_typedef(mk_lib_app_cryptor_mode_stream_any2_msg_$1_$3);
')dnl
union mk_lib_app_cryptor_mode_stream_any2_msg_data_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_app_cryptor_mode_stream_any2_msg_len_v];
mk_lib_app_cryptor_mode_stream_mm_for_all(`dnl
	mk_lib_app_cryptor_mode_stream_any2_msg_$1_$3_t m_$1_$3;
')dnl
};
typedef union mk_lib_app_cryptor_mode_stream_any2_msg_data_u mk_lib_app_cryptor_mode_stream_any2_msg_data_t;
struct mk_lib_app_cryptor_mode_stream_any2_msg_s
{
	mk_lib_app_cryptor_mode_stream_any2_msg_data_t m_data;
};
typedef struct mk_lib_app_cryptor_mode_stream_any2_msg_s mk_lib_app_cryptor_mode_stream_any2_msg_t;
mk_lang_typedef(mk_lib_app_cryptor_mode_stream_any2_msg);


#include "mk_lang_warning_msvc_push_c4820.h"
mk_lib_app_cryptor_mode_stream_mm_for_all(`dnl
struct mk_lib_app_cryptor_mode_stream_any2_$1_$3_s{ mk_lib_app_cryptor_mode_stream_any1_bigid_t m_id; mk_lib_app_cryptor_mode_stream_$1_$3_t m_$1_$3; }; typedef struct mk_lib_app_cryptor_mode_stream_any2_$1_$3_s mk_lib_app_cryptor_mode_stream_any2_$1_$3_t; mk_lang_typedef(mk_lib_app_cryptor_mode_stream_any2_$1_$3);
')dnl
#include "mk_lang_warning_msvc_pop.h"
union mk_lib_app_cryptor_mode_stream_any2_data_u
{
	mk_lib_app_cryptor_mode_stream_any1_bigid_t m_id;
mk_lib_app_cryptor_mode_stream_mm_for_all(`dnl
	mk_lib_app_cryptor_mode_stream_any2_$1_$3_t m_$1_$3;
')dnl
};
typedef union mk_lib_app_cryptor_mode_stream_any2_data_u mk_lib_app_cryptor_mode_stream_any2_data_t;
struct mk_lib_app_cryptor_mode_stream_any2_s
{
	mk_lib_app_cryptor_mode_stream_any2_data_t m_data;
};
typedef struct mk_lib_app_cryptor_mode_stream_any2_s mk_lib_app_cryptor_mode_stream_any2_t;
mk_lang_typedef(mk_lib_app_cryptor_mode_stream_any2);


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_app_cryptor_mode_stream_any2_rw_construct(mk_lib_app_cryptor_mode_stream_any2_pt const any2, mk_lib_app_cryptor_mode_stream_any1_id_t const id) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_mode_stream_any2_ro_get_iv_len(mk_lib_app_cryptor_mode_stream_any2_pct const any2) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_mode_stream_any2_ro_get_key_len(mk_lib_app_cryptor_mode_stream_any2_pct const any2) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_mode_stream_any2_ro_get_msg_len(mk_lib_app_cryptor_mode_stream_any2_pct const any2) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_mode_stream_any2_ro_get_idx(mk_lib_app_cryptor_mode_stream_any2_pct const any2) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_cui_uint8_pt mk_lib_app_cryptor_mode_stream_any2_rw_get_ptr(mk_lib_app_cryptor_mode_stream_any2_pt const any2) mk_lang_noexcept;

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_app_cryptor_mode_stream_any2_rw_set_iv(mk_lib_app_cryptor_mode_stream_any2_pt const any2, mk_lib_app_cryptor_mode_stream_any2_iv_pct const iv) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_app_cryptor_mode_stream_any2_rw_set_key_enc(mk_lib_app_cryptor_mode_stream_any2_pt const any2, mk_lib_app_cryptor_mode_stream_any2_key_pct const key) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_app_cryptor_mode_stream_any2_rw_set_key_dec(mk_lib_app_cryptor_mode_stream_any2_pt const any2, mk_lib_app_cryptor_mode_stream_any2_key_pct const key) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_app_cryptor_mode_stream_any2_rw_encrypt(mk_lib_app_cryptor_mode_stream_any2_pt const any2, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_app_cryptor_mode_stream_any2_rw_decrypt(mk_lib_app_cryptor_mode_stream_any2_pt const any2, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_app_cryptor_mode_stream_any2.c"
#endif
#endif

