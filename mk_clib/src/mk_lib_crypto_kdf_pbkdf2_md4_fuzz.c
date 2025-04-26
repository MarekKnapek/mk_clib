#ifndef mk_include_guard_mk_lib_crypto_kdf_pbkdf2_md4_fuzz_c
#define mk_include_guard_mk_lib_crypto_kdf_pbkdf2_md4_fuzz_c
#include "mk_lib_crypto_kdf_pbkdf2_md4_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_kdf_pbkdf2_md4.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"
#include "mk_win_base.h"
#include "mk_win_dll_bcrypt.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_kdf_pbkdf2_md4_fuzz_compute_my(mk_sl_cui_uint8_pct const password_buf, mk_lang_types_sint_t const password_len, mk_sl_cui_uint8_pct const salt_buf, mk_lang_types_sint_t const salt_len, mk_lang_types_ulong_t const cost, mk_lang_types_sint_t const key_len, mk_sl_cui_uint8_pt const key_buf) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(password_buf || password_len == 0);
	mk_lang_assert(password_len >= 0);
	mk_lang_assert(salt_buf || salt_len == 0);
	mk_lang_assert(salt_len >= 0);
	mk_lang_assert(cost >= 1);
	mk_lang_assert(key_len >= 1);
	mk_lang_assert(key_buf);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_lib_crypto_kdf_pbkdf2_md4_fn(password_buf, password_len, salt_buf, salt_len, cost, key_len, key_buf);
	return 0;
}

#if mk_lang_platform_is_windows_at_least_any
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_kdf_pbkdf2_md4_fuzz_compute_win(mk_sl_cui_uint8_pct const password_buf, mk_lang_types_sint_t const password_len, mk_sl_cui_uint8_pct const salt_buf, mk_lang_types_sint_t const salt_len, mk_lang_types_ulong_t const cost, mk_lang_types_sint_t const key_len, mk_sl_cui_uint8_pt const key_buf) mk_lang_noexcept
{
	mk_win_base_ntstatus_t st;
	mk_win_dll_bcrypt_provider_t provider;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(password_buf || password_len == 0);
	mk_lang_assert(password_len >= 0);
	mk_lang_assert(salt_buf || salt_len == 0);
	mk_lang_assert(salt_len >= 0);
	mk_lang_assert(cost >= 1);
	mk_lang_assert(key_len >= 1);
	mk_lang_assert(key_buf);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	st = mk_win_dll_bcrypt_open_algorithm_provider(&provider, mk_win_dll_bcrypt_k_algorithm_md4, mk_win_dll_bcrypt_k_provider_ms_primitive, mk_win_dll_bcrypt_k_flag_alg_handle_hmac); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_pbkdf2(provider, password_buf, ((mk_win_base_ulong_t)(password_len)), salt_buf, ((mk_win_base_ulong_t)(salt_len)), cost, key_buf, ((mk_win_base_ulong_t)(key_len)), mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_close_algorithm_provider(provider, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	return 0;
}
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_kdf_pbkdf2_md4_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_bool_t b;
	mk_lang_types_uint_t password_len;
	mk_lang_types_uint_t salt_len;
	mk_lang_types_uint_t key_len;
	mk_sl_cui_uint8_t password_buf[128];
	mk_sl_cui_uint8_t salt_buf[128];
	mk_lang_types_uint_t cost;
	mk_sl_cui_uint8_t key_buf_my[128];
	mk_lang_types_sint_t err;
	#if mk_lang_platform_is_windows_at_least_any
	mk_sl_cui_uint8_t key_buf_win[mk_lang_countof(key_buf_my)];
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
	mk_lang_bui_uint_from_buis_uchar_le(&password_len, &d[0]);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	password_len = password_len % mk_lang_countof(password_buf) + 1;
	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&salt_len, &d[0]);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	salt_len = salt_len % mk_lang_countof(salt_buf);
	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&cost, &d[0]);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	if(!(cost >= 1 && cost <= 4 * 1024))
	{
		return 0;
	}
	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&key_len, &d[0]);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	key_len = key_len % mk_lang_countof(key_buf_my) + 1;
	if(!(s >= password_len))
	{
		return 0;
	}
	mk_sl_cui_uint8_from_bi_uchar_many(&password_buf[0], &d[0], password_len);
	d += password_len;
	s -= password_len;
	if(!(s >= salt_len))
	{
		return 0;
	}
	mk_sl_cui_uint8_from_bi_uchar_many(&salt_buf[0], &d[0], salt_len);
	d += salt_len;
	s -= salt_len;
	err = mk_lib_crypto_kdf_pbkdf2_md4_fuzz_compute_my(&password_buf[0], ((mk_lang_types_sint_t)(password_len)), &salt_buf[0], ((mk_lang_types_sint_t)(salt_len)), cost, ((mk_lang_types_sint_t)(key_len)), &key_buf_my[0]); mk_lang_check_rereturn(err);
	#if mk_lang_platform_is_windows_at_least_any
	err = mk_lib_crypto_kdf_pbkdf2_md4_fuzz_compute_win(&password_buf[0], ((mk_lang_types_sint_t)(password_len)), &salt_buf[0], ((mk_lang_types_sint_t)(salt_len)), cost, ((mk_lang_types_sint_t)(key_len)), &key_buf_win[0]); mk_lang_check_rereturn(err);
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&key_buf_my[0], &key_buf_win[0], key_len) == 0);
	#endif
	return 0;
}


#endif
