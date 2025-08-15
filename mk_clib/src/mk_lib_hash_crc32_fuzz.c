#ifndef mk_include_guard_mk_lib_hash_crc32_fuzz_c
#define mk_include_guard_mk_lib_hash_crc32_fuzz_c
#include "mk_lib_hash_crc32_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_compiler.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lib_hash_crc32.h"
#include "mk_lib_hash_crc32_portable.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_hash_crc32_fuzz_compute_my(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_uint_t const data_len, mk_lib_hash_crc32_portable_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_hash_crc32_portable_t hasher;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(digest);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_lib_hash_crc32_portable_init(&hasher);
	mk_lib_hash_crc32_portable_append(&hasher, &data_buf[0], data_len);
	mk_lib_hash_crc32_portable_append(&hasher, &data_buf[0], data_len);
	mk_lib_hash_crc32_portable_finish(&hasher, digest);
	return 0;
}

#if mk_lang_platform_is_windows_at_least_any && !mk_lang_compiler_is_watcom
#include "mk_lib_hash_crc32_windows.h"
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_hash_crc32_fuzz_compute_win(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_uint_t const data_len, mk_lib_hash_crc32_windows_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_hash_crc32_windows_t hasher;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(digest);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_lib_hash_crc32_windows_init(&hasher);
	mk_lib_hash_crc32_windows_append(&hasher, &data_buf[0], data_len);
	mk_lib_hash_crc32_windows_append(&hasher, &data_buf[0], data_len);
	mk_lib_hash_crc32_windows_finish(&hasher, digest);
	return 0;
}
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_hash_crc32_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_uint_t data_len;
	mk_sl_cui_uint8_t data_buf[1 * 1024];
	mk_lang_types_uint_t n;
	mk_lang_types_uint_t i;
	mk_lang_types_sint_t err;
	mk_lib_hash_crc32_portable_digest_t digest_my;
	#if mk_lang_platform_is_windows_at_least_any && !mk_lang_compiler_is_watcom
	mk_lib_hash_crc32_windows_digest_t digest_win;
	#endif

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_hash_crc32_digest_len_v)) == ((mk_lang_types_sint_t)(mk_lib_hash_crc32_portable_digest_len_v)));
	#if mk_lang_platform_is_windows_at_least_any && !mk_lang_compiler_is_watcom
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_hash_crc32_digest_len_v)) == ((mk_lang_types_sint_t)(mk_lib_hash_crc32_windows_digest_len_v)));
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
	n = data_len;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_from_bi_uchar(&data_buf[i], &d[i]);
	}
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;

	err = mk_lib_hash_crc32_fuzz_compute_my(&data_buf[0], data_len, &digest_my); mk_lang_check_rereturn(err);
	#if mk_lang_platform_is_windows_at_least_any && !mk_lang_compiler_is_watcom
	err = mk_lib_hash_crc32_fuzz_compute_win(&data_buf[0], data_len, &digest_win); mk_lang_check_rereturn(err);
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&digest_my.m_data.m_uint8s[0], &digest_win.m_data.m_uint8s[0], mk_lib_hash_crc32_portable_digest_len_v) == 0);
	#endif
	return 0;
}


#endif
