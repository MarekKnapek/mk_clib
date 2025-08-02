#ifndef mk_include_guard_mk_lib_hash_crc32_windows_c
#define mk_include_guard_mk_lib_hash_crc32_windows_c
#include "mk_lib_hash_crc32_windows.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any

#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"
#include "mk_win_base.h"
#include "mk_win_dll_ntdll.h"


mk_lang_jumbo mk_lang_types_void_t mk_lib_hash_crc32_windows_init(mk_lib_hash_crc32_windows_pt const crc32) mk_lang_noexcept
{
	mk_lang_assert(crc32);

	crc32->m_state = 0;
}

mk_lang_jumbo mk_lang_types_void_t mk_lib_hash_crc32_windows_append(mk_lib_hash_crc32_windows_pt const crc32, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_usize_t const data_len) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(crc32);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(data_len <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
	#include "mk_lang_warning_msvc_pop.h"

	crc32->m_state = mk_win_dll_ntdll_rtl_compute_crc32(crc32->m_state, data_buf, ((mk_lang_types_sint_t)(data_len)));
}

mk_lang_jumbo mk_lang_types_void_t mk_lib_hash_crc32_windows_finish(mk_lib_hash_crc32_windows_pt const crc32, mk_lib_hash_crc32_windows_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_bui_uint_t tui;
	mk_lang_types_uchar_t tucs[mk_lang_countof(digest->m_data.m_uint8s)];

	mk_lang_static_assert(sizeof(tui) == sizeof(crc32->m_state));
	mk_lang_static_assert(sizeof(tui) == sizeof(tucs));

	mk_lang_assert(crc32);
	mk_lang_assert(digest);

	tui = ((mk_lang_bui_uint_t)(crc32->m_state));
	mk_lang_bui_uint_to_buis_uchar_le(&tui, &tucs[0]);
	mk_sl_cui_uint8_from_bi_uchar_many(&digest->m_data.m_uint8s[0], &tucs[0], mk_lang_countof(tucs));
}


#else
static void mk_lib_hash_crc32_windows_dummy(void){}
#endif
#endif
