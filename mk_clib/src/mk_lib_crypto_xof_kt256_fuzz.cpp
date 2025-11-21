#ifndef mk_include_guard_mk_lib_crypto_xof_kt256_fuzz_cpp
#define mk_include_guard_mk_lib_crypto_xof_kt256_fuzz_cpp


#if defined mk_lang_jumbo_want
#undef mk_lang_jumbo_want
#endif
#define mk_lang_jumbo_want 2


#include "mk_lang_warning_msvc_push_c4514.h"


#include "mk_lib_crypto_xof_kt256_fuzz.hpp"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_extern.h"
#include "mk_lang_external_digestpp.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_static_param.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_xof_kt256.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


#define mk_lib_crypto_xof_kt256_fuzz_bytes_count (64 * 1024)


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_xof_kt256_fuzz_compute_my(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_uint_t const data_len, mk_lang_static_param(mk_sl_cui_uint8_t, digest, mk_lib_crypto_xof_kt256_fuzz_bytes_count)) mk_lang_noexcept
{
	mk_lib_crypto_xof_kt256_t xofer;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(digest);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_lib_crypto_xof_kt256_init(&xofer);
	mk_lib_crypto_xof_kt256_append_message_u8s(&xofer, &data_buf[0], data_len);
	mk_lib_crypto_xof_kt256_finish(&xofer);
	mk_lib_crypto_xof_kt256_squeeze_u8s(&xofer, digest, mk_lib_crypto_xof_kt256_fuzz_bytes_count);
	return 0;
}

#if mk_lang_external_digestpp_have
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_xof_kt256_fuzz_compute_dpp(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_uint_t const data_len, mk_lang_static_param(mk_sl_cui_uint8_t, digest, mk_lib_crypto_xof_kt256_fuzz_bytes_count)) mk_lang_noexcept
{

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(digest);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	digestpp::k12 hasher{};
	hasher.absorb(((mk_lang_types_uchar_pct)(data_buf)), data_len);
	hasher.squeeze(((mk_lang_types_uchar_pt)(digest)), mk_lib_crypto_xof_kt256_fuzz_bytes_count);
	return 0;
}
#endif


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_xof_kt256_fuzz_impl(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_uint_t data_len;
	mk_sl_cui_uint8_t data_buf[64 * 1024];
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_t digest_my[mk_lib_crypto_xof_kt256_fuzz_bytes_count];
	#if mk_lang_external_digestpp_have
	mk_sl_cui_uint8_t digest_dpp[mk_lib_crypto_xof_kt256_fuzz_bytes_count];
	#endif

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;

	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&data_len, &d[0]);
	data_len = mk_lang_min(data_len, mk_lang_countof(data_buf));
	data_len = mk_lang_min(data_len, ((mk_lang_types_uint_t)(s)));
	mk_sl_cui_uint8_from_bi_uchar_many(&data_buf[0], &d[0], data_len);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;

	err = mk_lib_crypto_xof_kt256_fuzz_compute_my(&data_buf[0], data_len, &digest_my[0]); mk_lang_check_rereturn(err);
	#if mk_lang_external_digestpp_have
	err = mk_lib_crypto_xof_kt256_fuzz_compute_dpp(&data_buf[0], data_len, &digest_dpp[0]); mk_lang_check_rereturn(err);
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&digest_my[0], &digest_dpp[0], mk_lib_crypto_xof_kt256_fuzz_bytes_count) == 0);
	#endif
	return 0;
}

mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t mk_lib_crypto_xof_kt256_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	return mk_lib_crypto_xof_kt256_fuzz_impl(data, size);
}


#include "mk_lang_warning_msvc_pop.h"


#endif
