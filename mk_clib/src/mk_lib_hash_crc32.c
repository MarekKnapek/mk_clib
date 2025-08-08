#ifndef mk_include_guard_mk_lib_hash_crc32_c
#define mk_include_guard_mk_lib_hash_crc32_c
#include "mk_lib_hash_crc32.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_hash_crc32_portable.h"
#include "mk_lib_hash_crc32_windows.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_hash_crc32_init(mk_lib_hash_crc32_pt const crc32) mk_lang_noexcept
{
	#if mk_lang_platform_is_windows_at_least_any
	mk_lang_static_assert(sizeof(mk_win_base_dword_t) == mk_sl_cui_uint32_size_bytes_v);
	mk_lang_static_assert(sizeof(mk_win_base_dword_t) == sizeof(mk_lang_types_uint_t));
	#endif

	mk_lang_assert(crc32);

	#if mk_lang_platform_is_windows_at_least_any
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lib_hash_crc32_windows_t windows;
		mk_lang_types_uint_t tui;

		mk_lib_hash_crc32_windows_init(&windows);
		tui = ((mk_lang_types_uint_t)(windows.m_state));
		mk_sl_cui_uint32_from_bi_uint(&crc32->m_state, &tui);
	}
	else
	#endif
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
		mk_lib_hash_crc32_portable_t portable;

		mk_lib_hash_crc32_portable_init(&portable);
		crc32->m_state = portable.m_state;
		#include "mk_lang_warning_clang_pop.h"
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_hash_crc32_append(mk_lib_hash_crc32_pt const crc32, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_usize_t const data_len) mk_lang_noexcept
{
	#if mk_lang_platform_is_windows_at_least_any
	mk_lang_static_assert(sizeof(mk_win_base_dword_t) == mk_sl_cui_uint32_size_bytes_v);
	mk_lang_static_assert(sizeof(mk_win_base_dword_t) == sizeof(mk_lang_types_uint_t));
	#endif

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(crc32);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	#if mk_lang_platform_is_windows_at_least_any
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lib_hash_crc32_windows_t windows;
		mk_lang_types_uint_t tui;

		mk_sl_cui_uint32_to_bi_uint(&crc32->m_state, &tui);
		windows.m_state = ((mk_win_base_dword_t)(tui));
		mk_lib_hash_crc32_windows_append(&windows, data_buf, data_len);
		tui = ((mk_lang_types_uint_t)(windows.m_state));
		mk_sl_cui_uint32_from_bi_uint(&crc32->m_state, &tui);
	}
	else
	#endif
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
		mk_lib_hash_crc32_portable_t portable;

		portable.m_state = crc32->m_state;
		mk_lib_hash_crc32_portable_append(&portable, data_buf, data_len);
		crc32->m_state = portable.m_state;
		#include "mk_lang_warning_clang_pop.h"
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_hash_crc32_finish(mk_lib_hash_crc32_pt const crc32, mk_lib_hash_crc32_digest_pt const digest) mk_lang_noexcept
{
	#if mk_lang_platform_is_windows_at_least_any
	mk_lang_static_assert(sizeof(mk_win_base_dword_t) == mk_sl_cui_uint32_size_bytes_v);
	mk_lang_static_assert(sizeof(mk_win_base_dword_t) == sizeof(mk_lang_types_uint_t));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_hash_crc32_digest_len_v)) == ((mk_lang_types_sint_t)(mk_lib_hash_crc32_windows_digest_len_v)));
	#endif
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_hash_crc32_digest_len_v)) == ((mk_lang_types_sint_t)(mk_lib_hash_crc32_portable_digest_len_v)));

	mk_lang_assert(crc32);
	mk_lang_assert(digest);

	#if mk_lang_platform_is_windows_at_least_any
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lib_hash_crc32_windows_t windows;
		mk_lang_types_uint_t tui;
		mk_lib_hash_crc32_windows_digest_t dgst;

		mk_sl_cui_uint32_to_bi_uint(&crc32->m_state, &tui);
		windows.m_state = ((mk_win_base_dword_t)(tui));
		mk_lib_hash_crc32_windows_finish(&windows, &dgst);
		mk_sl_cui_uint8_memcpy_fn(&digest->m_data.m_uint8s[0], &dgst.m_data.m_uint8s[0], mk_lib_hash_crc32_digest_len_v);
	}
	else
	#endif
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
		mk_lib_hash_crc32_portable_t portable;
		mk_lib_hash_crc32_portable_digest_t dgst;

		portable.m_state = crc32->m_state;
		mk_lib_hash_crc32_portable_finish(&portable, &dgst);
		mk_sl_cui_uint8_memcpy_fn(&digest->m_data.m_uint8s[0], &dgst.m_data.m_uint8s[0], mk_lib_hash_crc32_digest_len_v);
		#include "mk_lang_warning_clang_pop.h"
	}
}


#endif
