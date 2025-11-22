#ifndef mk_include_guard_mk_lib_crypto_xof_stream_kt128_h
#define mk_include_guard_mk_lib_crypto_xof_stream_kt128_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_xof_kt128.h"


mk_lang_forward(mk_sl_cui_uint8);


#define mk_lib_crypto_xof_block_kt128_name_def mk_lib_crypto_xof_kt128_name_def


typedef mk_lib_crypto_xof_kt128_block_data_t mk_lib_crypto_xof_stream_kt128_digest_t;
mk_lang_typedef(mk_lib_crypto_xof_stream_kt128_digest);

struct mk_lib_crypto_xof_stream_kt128_s
{
	mk_lib_crypto_xof_kt128_t m_base;
};
typedef struct mk_lib_crypto_xof_stream_kt128_s mk_lib_crypto_xof_stream_kt128_t;
mk_lang_typedef(mk_lib_crypto_xof_stream_kt128);


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_kt128_init(mk_lib_crypto_xof_stream_kt128_pt const stream) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_kt128_append_u8s(mk_lib_crypto_xof_stream_kt128_pt const stream, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_kt128_finish(mk_lib_crypto_xof_stream_kt128_pt const stream) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_kt128_squeeze_u8s(mk_lib_crypto_xof_stream_kt128_pt const stream, mk_sl_cui_uint8_pt const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_crypto_xof_stream_kt128.c"
#endif
#endif
