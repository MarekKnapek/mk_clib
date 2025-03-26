include(`mk_lib_crypto_xof_stream_any.m')dnl
dnl
dnl
#ifndef mk_include_guard_mk_lib_crypto_xof_stream_any2_h
#define mk_include_guard_mk_lib_crypto_xof_stream_any2_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_xof_stream_any1.h"
#include "mk_sl_cui_uint8.h"

mm_per_xof(`#include "mk_lib_crypto_xof_stream_$1.h"')


#include "mk_lang_warning_msvc_push_c4820.h"
mm_per_xof(`struct mk_lib_crypto_xof_stream_any2_$1_s{ mk_lib_crypto_xof_stream_any1_id_t m_id; mk_lib_crypto_xof_stream_$1_t m_$1; }; typedef struct mk_lib_crypto_xof_stream_any2_$1_s mk_lib_crypto_xof_stream_any2_$1_t; mk_lang_typedef(mk_lib_crypto_xof_stream_any2_$1);')
#include "mk_lang_warning_msvc_pop.h"


union mk_lib_crypto_xof_stream_any2_data_u
{
	mk_lib_crypto_xof_stream_any1_id_t m_id;
mm_per_xof(`	mk_lib_crypto_xof_stream_any2_$1_t m_$1;')
};
typedef union mk_lib_crypto_xof_stream_any2_data_u mk_lib_crypto_xof_stream_any2_data_t;
struct mk_lib_crypto_xof_stream_any2_s
{
	mk_lib_crypto_xof_stream_any2_data_t m_data;
};
typedef struct mk_lib_crypto_xof_stream_any2_s mk_lib_crypto_xof_stream_any2_t;
mk_lang_typedef(mk_lib_crypto_xof_stream_any2);


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any2_init(mk_lib_crypto_xof_stream_any2_pt const hash_stream_any2, mk_lib_crypto_xof_stream_any1_id_t const id) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any2_append_u8s(mk_lib_crypto_xof_stream_any2_pt const hash_stream_any2, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any2_finish(mk_lib_crypto_xof_stream_any2_pt const hash_stream_any2) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any2_squeeze_u8s(mk_lib_crypto_xof_stream_any2_pt const hash_stream_any2, mk_sl_cui_uint8_pt const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_crypto_xof_stream_any2.c"
#endif
#endif
