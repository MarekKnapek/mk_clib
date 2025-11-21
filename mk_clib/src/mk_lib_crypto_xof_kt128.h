#ifndef mk_include_guard_mk_lib_crypto_xof_kt128_h
#define mk_include_guard_mk_lib_crypto_xof_kt128_h

/* https://keccak.team/files/TurboSHAKE.pdf */
/* https://www.rfc-editor.org/rfc/rfc9861.txt */
/* https://datatracker.ietf.org/doc/html/rfc9861 */

#include "mk_lang_alignas.h"
#include "mk_lang_configuration.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stringify.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_sha3_base.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"


#define mk_lib_crypto_xof_kt128_block_len_d 168
#define mk_lib_crypto_xof_kt128_name_def KangarooTwelve128
enum mk_lib_crypto_xof_kt128_block_len_e{ mk_lib_crypto_xof_kt128_block_len_v = mk_lib_crypto_xof_kt128_block_len_d }; typedef enum mk_lib_crypto_xof_kt128_block_len_e mk_lib_crypto_xof_kt128_block_len_t;
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_crypto_xof_kt128_name_str_buf[] = mk_lang_stringify(mk_lib_crypto_xof_kt128_name_def);
mk_lang_constexpr_static_inline mk_lang_types_sint_t const mk_lib_crypto_xof_kt128_name_str_len = mk_lang_countstr(mk_lib_crypto_xof_kt128_name_str_buf);


union mk_lib_crypto_xof_kt128_block_data_u
{
	mk_lang_alignas(8) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_xof_kt128_block_len_v];
	mk_sl_cui_uint64_t m_align;
};
typedef union mk_lib_crypto_xof_kt128_block_data_u mk_lib_crypto_xof_kt128_block_data_t;
struct mk_lib_crypto_xof_kt128_block_s
{
	mk_lib_crypto_xof_kt128_block_data_t m_data;
};
typedef struct mk_lib_crypto_xof_kt128_block_s mk_lib_crypto_xof_kt128_block_t;
mk_lang_typedef(mk_lib_crypto_xof_kt128_block);


enum mk_lib_crypto_xof_kt128_s_phase_e
{
	mk_lib_crypto_xof_kt128_s_phase_e_s_zero,
	mk_lib_crypto_xof_kt128_s_phase_e_s_n,
	mk_lib_crypto_xof_kt128_s_phase_e_dummy_end
};
typedef enum mk_lib_crypto_xof_kt128_s_phase_e mk_lib_crypto_xof_kt128_s_phase_t;


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_crypto_xof_kt128_s
{
	mk_lib_crypto_hash_block_sha3_base_t m_inner_state;
	mk_lib_crypto_hash_block_sha3_base_t m_outer_state;
	mk_lib_crypto_xof_kt128_block_t m_inner_block;
	mk_lib_crypto_xof_kt128_block_t m_outer_block;
	mk_sl_cui_uint64_t m_len_blocks;
	mk_sl_cui_uint64_t m_len_c;
	mk_lang_types_sint_t m_inner_rem;
	mk_lang_types_sint_t m_outer_rem;
	mk_lang_types_sint_t m_8k_rem;
	mk_lib_crypto_xof_kt128_s_phase_t m_phase;
	#if mk_lang_configuration_is_debug
	mk_lang_types_bool_t m_customization;
	mk_lang_types_bool_t m_finished;
	#endif
};
typedef struct mk_lib_crypto_xof_kt128_s mk_lib_crypto_xof_kt128_t;
mk_lang_typedef(mk_lib_crypto_xof_kt128);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_kt128_init(mk_lib_crypto_xof_kt128_pt const kt128) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_kt128_append_message_u8s(mk_lib_crypto_xof_kt128_pt const kt128, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_kt128_append_customization_u8s(mk_lib_crypto_xof_kt128_pt const kt128, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_kt128_finish(mk_lib_crypto_xof_kt128_pt const kt128) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_kt128_squeeze_u8s(mk_lib_crypto_xof_kt128_pt const kt128, mk_sl_cui_uint8_pt const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_crypto_xof_kt128.c"
#endif
#endif
