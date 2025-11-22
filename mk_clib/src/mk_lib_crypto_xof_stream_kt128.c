#ifndef mk_include_guard_mk_lib_crypto_xof_stream_kt128_c
#define mk_include_guard_mk_lib_crypto_xof_stream_kt128_c
#include "mk_lib_crypto_xof_stream_kt128.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_xof_kt128.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_kt128_init(mk_lib_crypto_xof_stream_kt128_pt const stream) mk_lang_noexcept
{
	mk_lang_assert(stream);

	mk_lib_crypto_xof_kt128_init(&stream->m_base);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_kt128_append_u8s(mk_lib_crypto_xof_stream_kt128_pt const stream, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_assert(stream);

	mk_lib_crypto_xof_kt128_append_message_u8s(&stream->m_base, u8s, count);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_kt128_finish(mk_lib_crypto_xof_stream_kt128_pt const stream) mk_lang_noexcept
{
	mk_lang_assert(stream);

	mk_lib_crypto_xof_kt128_finish(&stream->m_base);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_kt128_squeeze_u8s(mk_lib_crypto_xof_stream_kt128_pt const stream, mk_sl_cui_uint8_pt const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_assert(stream);

	mk_lib_crypto_xof_kt128_squeeze_u8s(&stream->m_base, u8s, count);
}


#endif
