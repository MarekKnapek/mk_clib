#ifndef mk_include_guard_mk_lib_crypto_xof_stream_any1_h
#define mk_include_guard_mk_lib_crypto_xof_stream_any1_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


mk_lang_forward(mk_lib_crypto_xof_stream_shake_128);
mk_lang_forward(mk_lib_crypto_xof_stream_shake_256);


enum mk_lib_crypto_xof_stream_any1_id_e
{
	mk_lib_crypto_xof_stream_any1_id_e_shake_128,
	mk_lib_crypto_xof_stream_any1_id_e_shake_256,
	mk_lib_crypto_xof_stream_any1_id_e_dummy_end
};
typedef enum mk_lib_crypto_xof_stream_any1_id_e mk_lib_crypto_xof_stream_any1_id_t;


union mk_lib_crypto_xof_stream_any1_bare_data_u
{
	mk_lib_crypto_xof_stream_shake_128_pt m_shake_128;
	mk_lib_crypto_xof_stream_shake_256_pt m_shake_256;
};
typedef union mk_lib_crypto_xof_stream_any1_bare_data_u mk_lib_crypto_xof_stream_any1_bare_data_t;
struct mk_lib_crypto_xof_stream_any1_bare_s
{
	mk_lib_crypto_xof_stream_any1_bare_data_t m_data;
};
typedef struct mk_lib_crypto_xof_stream_any1_bare_s mk_lib_crypto_xof_stream_any1_bare_t;
mk_lang_typedef(mk_lib_crypto_xof_stream_any1_bare);


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_crypto_xof_stream_any1_ptrid_s
{
	mk_lib_crypto_xof_stream_any1_id_t m_id;
	mk_lib_crypto_xof_stream_any1_bare_t m_ptr;
};
typedef struct mk_lib_crypto_xof_stream_any1_ptrid_s mk_lib_crypto_xof_stream_any1_ptrid_t;
mk_lang_typedef(mk_lib_crypto_xof_stream_any1_ptrid);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any1_bare_init(mk_lib_crypto_xof_stream_any1_bare_pt const xof_stream_any1_bare, mk_lib_crypto_xof_stream_any1_id_t const id) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any1_bare_append_u8s(mk_lib_crypto_xof_stream_any1_bare_pt const xof_stream_any1_bare, mk_lib_crypto_xof_stream_any1_id_t const id, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any1_bare_finish(mk_lib_crypto_xof_stream_any1_bare_pt const xof_stream_any1_bare, mk_lib_crypto_xof_stream_any1_id_t const id) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any1_bare_squeeze_u8s(mk_lib_crypto_xof_stream_any1_bare_pt const xof_stream_any1_bare, mk_lib_crypto_xof_stream_any1_id_t const id, mk_sl_cui_uint8_pt const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept;

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any1_ptrid_init(mk_lib_crypto_xof_stream_any1_ptrid_pt const hash_stream_any1_ptrid, mk_lib_crypto_xof_stream_any1_id_t const id) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any1_ptrid_append_u8s(mk_lib_crypto_xof_stream_any1_ptrid_pt const hash_stream_any1_ptrid, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any1_ptrid_finish(mk_lib_crypto_xof_stream_any1_ptrid_pt const hash_stream_any1_ptrid) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any1_ptrid_squeeze_u8s(mk_lib_crypto_xof_stream_any1_ptrid_pt const hash_stream_any1_ptrid, mk_sl_cui_uint8_pt const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_crypto_xof_stream_any1.c"
#endif
#endif
