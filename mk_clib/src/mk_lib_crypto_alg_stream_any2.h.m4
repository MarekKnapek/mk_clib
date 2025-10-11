include(`mk_lib_crypto_alg_stream.m')dnl
#ifndef mk_include_guard_mk_lib_crypto_alg_stream_any2_h
#define mk_include_guard_mk_lib_crypto_alg_stream_any2_h

#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_stream.h"
#include "mk_lib_crypto_alg_stream_any1.h"
#include "mk_sl_cui_uint8.h"


#define mk_lib_crypto_alg_stream_any2_key_len_d ( \
define(`mk_lib_crypto_alg_stream_any2_mm_tab', `	')mk_lib_crypto_alg_stream_any2_mm_tab()mk_lang_max(`'dnl
define(`mk_lib_crypto_alg_stream_any2_h_mm_key_lens_a', `dnl
mk_lang_max(')`'dnl
mk_lib_crypto_alg_stream_mm_recurse(`mk_lib_crypto_alg_stream_any2_h_mm_key_lens_a', mk_lib_crypto_alg_stream_mm_half())dnl
1, \
define(`mk_lib_crypto_alg_stream_any2_h_mm_key_lens_b', `dnl
	mk_lib_crypto_alg_$1_key_len_d), \
')`'dnl
mk_lib_crypto_alg_stream_mm_recurse(`mk_lib_crypto_alg_stream_any2_h_mm_key_lens_b', mk_lib_crypto_alg_stream_mm_half())dnl
	1))
enum mk_lib_crypto_alg_stream_any2_key_len_e{mk_lib_crypto_alg_stream_any2_key_len_v = mk_lib_crypto_alg_stream_any2_key_len_d}; typedef enum mk_lib_crypto_alg_stream_any2_key_len_e mk_lib_crypto_alg_stream_any2_key_len_t; mk_lang_typedef(mk_lib_crypto_alg_stream_any2_key_len);
define(`mk_lib_crypto_alg_stream_any2_h_mm_keys', `dnl
struct mk_lib_crypto_alg_stream_any2_key_$1_s{ mk_lib_crypto_alg_stream_$1_key_t m_$1; }; typedef struct mk_lib_crypto_alg_stream_any2_key_$1_s mk_lib_crypto_alg_stream_any2_key_$1_t; mk_lang_typedef(mk_lib_crypto_alg_stream_any2_key_$1);
')`'dnl
mk_lib_crypto_alg_stream_mm_recurse(`mk_lib_crypto_alg_stream_any2_h_mm_keys', mk_lib_crypto_alg_stream_mm_half())dnl
union mk_lib_crypto_alg_stream_any2_key_data_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_alg_stream_any2_key_len_v];
define(`mk_lib_crypto_alg_stream_any2_h_mm_key_members', `dnl
	mk_lib_crypto_alg_stream_any2_key_$1_t m_$1;
')`'dnl
mk_lib_crypto_alg_stream_mm_recurse(`mk_lib_crypto_alg_stream_any2_h_mm_key_members', mk_lib_crypto_alg_stream_mm_half())dnl
};
typedef union mk_lib_crypto_alg_stream_any2_key_data_u mk_lib_crypto_alg_stream_any2_key_data_t;
struct mk_lib_crypto_alg_stream_any2_key_s
{
	mk_lib_crypto_alg_stream_any2_key_data_t m_data;
};
typedef struct mk_lib_crypto_alg_stream_any2_key_s mk_lib_crypto_alg_stream_any2_key_t;
mk_lang_typedef(mk_lib_crypto_alg_stream_any2_key);


#define mk_lib_crypto_alg_stream_any2_msg_len_d ( \
define(`mk_lib_crypto_alg_stream_any2_mm_tab', `	')mk_lib_crypto_alg_stream_any2_mm_tab()mk_lang_max(`'dnl
define(`mk_lib_crypto_alg_stream_any2_h_mm_msg_lens_a', `dnl
mk_lang_max(')`'dnl
mk_lib_crypto_alg_stream_mm_recurse(`mk_lib_crypto_alg_stream_any2_h_mm_msg_lens_a', mk_lib_crypto_alg_stream_mm_half())dnl
1, \
define(`mk_lib_crypto_alg_stream_any2_h_mm_msg_lens_b', `dnl
	mk_lib_crypto_alg_$1_msg_len_d), \
')`'dnl
mk_lib_crypto_alg_stream_mm_recurse(`mk_lib_crypto_alg_stream_any2_h_mm_msg_lens_b', mk_lib_crypto_alg_stream_mm_half())dnl
	1))
enum mk_lib_crypto_alg_stream_any2_msg_len_e{mk_lib_crypto_alg_stream_any2_msg_len_v = mk_lib_crypto_alg_stream_any2_msg_len_d}; typedef enum mk_lib_crypto_alg_stream_any2_msg_len_e mk_lib_crypto_alg_stream_any2_msg_len_t; mk_lang_typedef(mk_lib_crypto_alg_stream_any2_msg_len);
define(`mk_lib_crypto_alg_stream_any2_h_mm_msgs', `dnl
struct mk_lib_crypto_alg_stream_any2_msg_$1_s{ mk_lib_crypto_alg_stream_$1_msg_t m_$1; }; typedef struct mk_lib_crypto_alg_stream_any2_msg_$1_s mk_lib_crypto_alg_stream_any2_msg_$1_t; mk_lang_typedef(mk_lib_crypto_alg_stream_any2_msg_$1);
')`'dnl
mk_lib_crypto_alg_stream_mm_recurse(`mk_lib_crypto_alg_stream_any2_h_mm_msgs', mk_lib_crypto_alg_stream_mm_half())dnl
union mk_lib_crypto_alg_stream_any2_msg_data_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_alg_stream_any2_msg_len_v];
define(`mk_lib_crypto_alg_stream_any2_h_mm_msg_members', `dnl
	mk_lib_crypto_alg_stream_any2_msg_$1_t m_$1;
')`'dnl
mk_lib_crypto_alg_stream_mm_recurse(`mk_lib_crypto_alg_stream_any2_h_mm_msg_members', mk_lib_crypto_alg_stream_mm_half())dnl
};
typedef union mk_lib_crypto_alg_stream_any2_msg_data_u mk_lib_crypto_alg_stream_any2_msg_data_t;
struct mk_lib_crypto_alg_stream_any2_msg_s
{
	mk_lib_crypto_alg_stream_any2_msg_data_t m_data;
};
typedef struct mk_lib_crypto_alg_stream_any2_msg_s mk_lib_crypto_alg_stream_any2_msg_t;
mk_lang_typedef(mk_lib_crypto_alg_stream_any2_msg);


#include "mk_lang_warning_msvc_push_c4820.h"
define(`mk_lib_crypto_alg_stream_any2_h_mm_structs', `dnl
struct mk_lib_crypto_alg_stream_any2_$1_s{ mk_lib_crypto_alg_stream_any1_bigid_t m_id; mk_lib_crypto_alg_stream_$1_t m_$1; }; typedef struct mk_lib_crypto_alg_stream_any2_$1_s mk_lib_crypto_alg_stream_any2_$1_t; mk_lang_typedef(mk_lib_crypto_alg_stream_any2_$1);
')`'dnl
mk_lib_crypto_alg_stream_mm_recurse(`mk_lib_crypto_alg_stream_any2_h_mm_structs', mk_lib_crypto_alg_stream_mm_half())dnl
#include "mk_lang_warning_msvc_pop.h"
union mk_lib_crypto_alg_stream_any2_data_u
{
	mk_lib_crypto_alg_stream_any1_bigid_t m_id;
define(`mk_lib_crypto_alg_stream_any2_h_mm_unions', `dnl
	mk_lib_crypto_alg_stream_any2_$1_t m_$1;
')`'dnl
mk_lib_crypto_alg_stream_mm_recurse(`mk_lib_crypto_alg_stream_any2_h_mm_unions', mk_lib_crypto_alg_stream_mm_half())dnl
};
typedef union mk_lib_crypto_alg_stream_any2_data_u mk_lib_crypto_alg_stream_any2_data_t;
struct mk_lib_crypto_alg_stream_any2_s
{
	mk_lib_crypto_alg_stream_any2_data_t m_data;
};
typedef struct mk_lib_crypto_alg_stream_any2_s mk_lib_crypto_alg_stream_any2_t;
mk_lang_typedef(mk_lib_crypto_alg_stream_any2);


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_stream_any2_rw_construct(mk_lib_crypto_alg_stream_any2_pt const any2, mk_lib_crypto_alg_stream_any1_id_t const id) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_alg_stream_any2_ro_get_msg_len(mk_lib_crypto_alg_stream_any2_pct const any2) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_alg_stream_any2_ro_get_key_len(mk_lib_crypto_alg_stream_any2_pct const any2) mk_lang_noexcept;

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_stream_any2_rw_construct_encrypt(mk_lib_crypto_alg_stream_any2_pt const any2, mk_lib_crypto_alg_stream_any2_key_pct const key) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_stream_any2_rw_construct_decrypt(mk_lib_crypto_alg_stream_any2_pt const any2, mk_lib_crypto_alg_stream_any2_key_pct const key) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_stream_any2_rw_encrypt(mk_lib_crypto_alg_stream_any2_pt const any2, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_stream_any2_rw_decrypt(mk_lib_crypto_alg_stream_any2_pt const any2, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_crypto_alg_stream_any2.c"
#endif
#endif

