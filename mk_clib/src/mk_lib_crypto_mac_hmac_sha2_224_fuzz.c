#ifndef mk_include_guard_mk_lib_crypto_mac_hmac_sha2_224_fuzz_c
#define mk_include_guard_mk_lib_crypto_mac_hmac_sha2_224_fuzz_c
#include "mk_lib_crypto_mac_hmac_sha2_224_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_external_ltc.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_mac_hmac_sha2_224.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_mac_hmac_sha2_224_fuzz_compute_my(mk_sl_cui_uint8_pct const key_buf, mk_lang_types_uint_t const key_len, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_uint_t const data_len, mk_lib_crypto_mac_hmac_sha2_224_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_crypto_mac_hmac_sha2_224_t hmac;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(key_buf || key_len == 0);
	mk_lang_assert(key_len >= 0);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(digest);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_lib_crypto_mac_hmac_sha2_224_init(&hmac, key_buf, key_len);
	mk_lib_crypto_mac_hmac_sha2_224_append(&hmac, data_buf, data_len);
	mk_lib_crypto_mac_hmac_sha2_224_finish(&hmac, digest);
	return 0;
}

#if mk_lang_external_ltc_have
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_mac_hmac_sha2_224_fuzz_compute_ltc(mk_sl_cui_uint8_pct const key_buf, mk_lang_types_uint_t const key_len, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_uint_t const data_len, mk_lib_crypto_mac_hmac_sha2_224_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_types_sint_t idx;
	mk_lang_types_ulong_t olen;
	mk_lang_types_sint_t st;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(key_buf || key_len == 0);
	mk_lang_assert(key_len >= 0);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(digest);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	idx = register_hash(&sha224_desc); mk_lang_check_return(idx != -1);
	olen = mk_lib_crypto_mac_hmac_sha2_224_digest_len_v;
	st = hmac_memory(idx, ((mk_lang_types_uchar_pct)(key_buf)), key_len, ((mk_lang_types_uchar_pct)(data_buf)), data_len, ((mk_lang_types_uchar_pt)(digest)), &olen); mk_lang_check_return(st == CRYPT_OK); mk_lang_check_return(olen == mk_lib_crypto_mac_hmac_sha2_224_digest_len_v);
	return 0;
}
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mac_hmac_sha2_224_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_uint_t key_len;
	mk_lang_types_uint_t data_len;
	mk_sl_cui_uint8_t key_buf[1 * 1024];
	mk_sl_cui_uint8_t data_buf[1 * 1024];
	mk_lang_types_sint_t err;
	mk_lib_crypto_mac_hmac_sha2_224_digest_t digest_my;
	#if mk_lang_external_ltc_have
	mk_lib_crypto_mac_hmac_sha2_224_digest_t digest_ltc;
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
	mk_lang_bui_uint_from_buis_uchar_le(&key_len, &d[0]);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	key_len = mk_lang_min(key_len, mk_lang_countof(key_buf));
	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&data_len, &d[0]);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	data_len = mk_lang_min(data_len, mk_lang_countof(data_buf));
	if(!(s >= key_len && key_len != 0))
	{
		return 0;
	}
	mk_sl_cui_uint8_from_bi_uchar_many(&key_buf[0], &d[0], key_len);
	d += key_len;
	s -= key_len;
	if(!(s >= data_len))
	{
		return 0;
	}
	mk_sl_cui_uint8_from_bi_uchar_many(&data_buf[0], &d[0], data_len);
	d += data_len;
	s -= data_len;
	err = mk_lib_crypto_mac_hmac_sha2_224_fuzz_compute_my(&key_buf[0], key_len, &data_buf[0], data_len, &digest_my); mk_lang_check_rereturn(err);
	#if mk_lang_external_ltc_have
	err = mk_lib_crypto_mac_hmac_sha2_224_fuzz_compute_ltc(&key_buf[0], key_len, &data_buf[0], data_len, &digest_ltc); mk_lang_check_rereturn(err);
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&digest_my.m_data.m_uint8s[0], &digest_ltc.m_data.m_uint8s[0], mk_lib_crypto_mac_hmac_sha2_224_digest_len_v) == 0);
	#endif
	return 0;
}


#endif
