#ifndef mk_include_guard_mk_lib_crypto_xof_stream_turbo_shake_256_fuzz_c
#define mk_include_guard_mk_lib_crypto_xof_stream_turbo_shake_256_fuzz_c
#include "mk_lib_crypto_xof_stream_turbo_shake_256_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_external_ltc.h"
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
#include "mk_lib_crypto_xof_stream_turbo_shake_256.h"
#include "mk_sl_cui_uint8.h"


#define mk_lib_crypto_xof_stream_turbo_shake_256_fuzz_bytes_count 1024


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_xof_stream_turbo_shake_256_fuzz_compute_my(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_uint_t const data_len, mk_lang_static_param(mk_sl_cui_uint8_t, digest, mk_lib_crypto_xof_stream_turbo_shake_256_fuzz_bytes_count)) mk_lang_noexcept
{
	mk_lib_crypto_xof_stream_turbo_shake_256_t xofer;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(digest);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_lib_crypto_xof_stream_turbo_shake_256_init(&xofer);
	mk_lib_crypto_xof_stream_turbo_shake_256_append_u8s(&xofer, &data_buf[0], data_len);
	mk_lib_crypto_xof_stream_turbo_shake_256_finish(&xofer);
	mk_lib_crypto_xof_stream_turbo_shake_256_squeeze_u8s(&xofer, digest, mk_lib_crypto_xof_stream_turbo_shake_256_fuzz_bytes_count);
	return 0;
}

#if mk_lang_external_ltc_have
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_xof_stream_turbo_shake_256_fuzz_compute_ltc(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_uint_t const data_len, mk_lang_static_param(mk_sl_cui_uint8_t, digest, mk_lib_crypto_xof_stream_turbo_shake_256_fuzz_bytes_count)) mk_lang_noexcept
{
	mk_lang_types_sint_t st;
	hash_state xofer_ltc;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(digest);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	st = sha3_shake_init(&xofer_ltc, 256); mk_lang_check_return(st == CRYPT_OK);
	st = sha3_shake_turbo_process(&xofer_ltc, ((mk_lang_types_uchar_pct)(data_buf)), data_len); mk_lang_check_return(st == CRYPT_OK);
	st = sha3_shake_turbo_done(&xofer_ltc, ((mk_lang_types_uchar_pt)(digest)), mk_lib_crypto_xof_stream_turbo_shake_256_fuzz_bytes_count); mk_lang_check_return(st == CRYPT_OK);
	return 0;
}
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_xof_stream_turbo_shake_256_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_bool_t b;
	mk_lang_types_uint_t data_len;
	mk_sl_cui_uint8_t data_buf[1 * 1024];
	mk_lang_types_uint_t n;
	mk_lang_types_uint_t i;
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_t digest_my[mk_lib_crypto_xof_stream_turbo_shake_256_fuzz_bytes_count];
	#if mk_lang_external_ltc_have
	mk_sl_cui_uint8_t digest_ltc[mk_lib_crypto_xof_stream_turbo_shake_256_fuzz_bytes_count];
	#endif

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;

	if(!(s >= 1))
	{
		return 0;
	}
	b = d[0] % 2 == 0;
	d += 1;
	s -= 1;
	if(b)
	{
		mk_lang_cpuid_init();
	}
	else
	{
		mk_lang_cpuid_reset();
	}

	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&data_len, &d[0]);
	data_len = mk_lang_min(data_len, mk_lang_countof(data_buf));
	data_len = mk_lang_min(data_len, ((mk_lang_types_uint_t)(s)));
	n = data_len;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_from_bi_uchar(&data_buf[i], &d[i]);
	}
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;

	err = mk_lib_crypto_xof_stream_turbo_shake_256_fuzz_compute_my(&data_buf[0], data_len, &digest_my[0]); mk_lang_check_rereturn(err);
	#if mk_lang_external_ltc_have
	err = mk_lib_crypto_xof_stream_turbo_shake_256_fuzz_compute_ltc(&data_buf[0], data_len, &digest_ltc[0]); mk_lang_check_rereturn(err);
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&digest_my[0], &digest_ltc[0], mk_lib_crypto_xof_stream_turbo_shake_256_fuzz_bytes_count) == 0);
	#endif
	return 0;
}


#endif
