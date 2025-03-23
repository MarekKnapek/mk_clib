#ifndef mk_include_guard_mk_lib_crypto_hash_stream_sha1_fuzz_c
#define mk_include_guard_mk_lib_crypto_hash_stream_sha1_fuzz_c
#include "mk_lib_crypto_hash_stream_sha1_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_sha1.h"
#include "mk_sl_cui_uint8.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_hash_stream_sha1_fuzz_compute_my(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_uint_t const data_len, mk_lib_crypto_hash_stream_sha1_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_crypto_hash_stream_sha1_t hasher;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(digest);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_lib_crypto_hash_stream_sha1_init(&hasher);
	mk_lib_crypto_hash_stream_sha1_append_u8s(&hasher, &data_buf[0], data_len);
	mk_lib_crypto_hash_stream_sha1_finish(&hasher, digest);
	return 0;
}

#if mk_lang_platform_is_windows_at_least_any
#include "mk_win_dll_bcrypt.h"
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_hash_stream_sha1_fuzz_compute_win(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_uint_t const data_len, mk_lib_crypto_hash_stream_sha1_digest_pt const digest) mk_lang_noexcept
{
	mk_win_base_ntstatus_t st;
	mk_win_dll_bcrypt_provider_t provider;
	mk_win_dll_bcrypt_hash_t hasher;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(digest);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	st = mk_win_dll_bcrypt_open_algorithm_provider(&provider, mk_win_dll_bcrypt_k_algorithm_sha1, mk_win_dll_bcrypt_k_provider_ms_primitive, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_create_hash(provider, &hasher, mk_win_base_null, 0, mk_win_base_null, 0, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_hash_data(hasher, data_buf, data_len, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_finish_hash(hasher, digest, mk_lib_crypto_hash_stream_sha1_digest_len_v, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_destroy_hash(hasher); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_close_algorithm_provider(provider, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	return 0;
}
#endif

#if mk_lang_platform == mk_lang_platform_linux
#include <openssl/evp.h>
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_hash_stream_sha1_fuzz_compute_open_ssl(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_uint_t const data_len, mk_lib_crypto_hash_stream_sha1_digest_pt const digest, mk_lang_types_bool_pt const gud) mk_lang_noexcept
{
	EVP_MD const* hash;
	EVP_MD_CTX* ctx;
	mk_lang_types_sint_t st;
	mk_lang_types_uint_t len;

	mk_lang_static_assert(mk_lib_crypto_hash_stream_sha1_digest_len_v <= EVP_MAX_MD_SIZE);

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(digest);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	OpenSSL_add_all_digests();
	hash = EVP_get_digestbyname("SHA1");
	if(hash)
	{
		ctx = EVP_MD_CTX_new(); mk_lang_check_return(ctx);
		EVP_MD_CTX_init(ctx);
		st = EVP_DigestInit(ctx, hash); mk_lang_check_return(st != 0);
		st = EVP_DigestUpdate(ctx, data_buf, data_len); mk_lang_check_return(st != 0);
		st = EVP_DigestFinal(ctx, ((mk_lang_types_uchar_pt)(digest)), &len); mk_lang_check_return(st != 0); mk_lang_check_return(len == mk_lib_crypto_hash_stream_sha1_digest_len_v);
		EVP_MD_CTX_free(ctx);
		*gud = mk_lang_true;
	}
	else
	{
		*gud = mk_lang_false;
	}
	return 0;
}
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_hash_stream_sha1_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_bool_t b;
	mk_lang_types_uint_t data_len;
	mk_sl_cui_uint8_t data_buf[1 * 1024];
	mk_lang_types_uint_t n;
	mk_lang_types_uint_t i;
	mk_lang_types_sint_t err;
	mk_lib_crypto_hash_stream_sha1_digest_t digest_my;
	#if mk_lang_platform_is_windows_at_least_any
	mk_lib_crypto_hash_stream_sha1_digest_t digest_win;
	#endif
	#if mk_lang_platform == mk_lang_platform_linux
	mk_lib_crypto_hash_stream_sha1_digest_t digest_open_ssl;
	mk_lang_types_bool_t gud;
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

	err = mk_lib_crypto_hash_stream_sha1_fuzz_compute_my(&data_buf[0], data_len, &digest_my); mk_lang_check_rereturn(err);
	#if mk_lang_platform_is_windows_at_least_any
	err = mk_lib_crypto_hash_stream_sha1_fuzz_compute_win(&data_buf[0], data_len, &digest_win); mk_lang_check_rereturn(err);
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&digest_my.m_data.m_uint8s[0], &digest_win.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha1_digest_len_v) == 0);
	#endif
	#if mk_lang_platform == mk_lang_platform_linux
	err = mk_lib_crypto_hash_stream_sha1_fuzz_compute_open_ssl(&data_buf[0], data_len, &digest_open_ssl, &gud); mk_lang_check_rereturn(err);
	mk_lang_test(!gud || mk_sl_cui_uint8_memcmp_fn(&digest_my.m_data.m_uint8s[0], &digest_open_ssl.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha1_digest_len_v) == 0);
	#endif
	return 0;
}


#endif
