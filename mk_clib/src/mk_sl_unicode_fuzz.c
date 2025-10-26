#ifndef mk_include_guard_mk_sl_unicode_fuzz_c
#define mk_include_guard_mk_sl_unicode_fuzz_c
#include "mk_sl_unicode_fuzz.h"

#include "mk_lang_test.h"
#include "mk_lang_null.h"
#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stdint.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_unicode.h"





#include "mk_lang_extern.h"
#include "mk_win_base.h"
#include "mk_win_dll_kernel_errors.h"
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall WideCharToMultiByte(mk_win_base_uint_t const code_page, mk_win_base_dword_t const flags, mk_win_base_wchar_lpct const wide_buf, mk_lang_types_sint_t const wide_len, mk_win_base_pchar_lpt const multi_buf, mk_lang_types_sint_t const multi_len, mk_win_base_pchar_lpct const default_char, mk_win_base_bool_lpt const default_used) mk_lang_noexcept;




mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_unicode_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_uint_t data_len;
	mk_lang_types_wchar_t data_buf[1 * 1024];
	mk_lang_types_uint_t n;
	mk_lang_types_uint_t i;
	mk_sl_cui_uint8_t u8s_buf[3 * mk_lang_countof(data_buf)];
	mk_win_base_pchar_t u8s_buf_2[mk_lang_countof(u8s_buf)];
	mk_lang_types_sint_t consumed_u16;
	mk_lang_types_sint_t consumed_u8;
	mk_lang_types_sint_t bytes_out;
	mk_win_base_dword_t gle;

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
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	data_len = mk_lang_min(data_len, mk_lang_countof(data_buf));
	data_len = mk_lang_min(data_len, ((mk_lang_types_uint_t)(s)));
	data_len /= 2;
	n = data_len;
	for(i = 0; i != n; ++i)
	{
		data_buf[i] = ((mk_lang_types_wchar_t)(((mk_lang_stdint_uint16_t)(((mk_lang_stdint_uint16_t)(((mk_lang_stdint_uint16_t)(d[i * 2 + 0])) << (0 * 8))) | ((mk_lang_stdint_uint16_t)(((mk_lang_stdint_uint16_t)(d[i * 2 + 1])) * (1 * 8)))))));
	}
	mk_sl_unicode_utf16_wchar_to_utf8_u8(&data_buf[0], data_len, &u8s_buf[0], mk_lang_countof(u8s_buf), &consumed_u16, &consumed_u8);
	#ifndef WC_ERR_INVALID_CHARS
	#define WC_ERR_INVALID_CHARS 0x00000080
	#endif
	#ifndef WC_NO_BEST_FIT_CHARS
	#define WC_NO_BEST_FIT_CHARS 0x00000400
	#endif
	if(data_len != 0)
	{
		bytes_out = WideCharToMultiByte(65001, WC_ERR_INVALID_CHARS | WC_NO_BEST_FIT_CHARS, &data_buf[0], data_len, &u8s_buf_2[0], mk_lang_countof(u8s_buf_2), mk_lang_null, mk_lang_null);
		mk_lang_test
		(
			(bytes_out == 0 && (gle = mk_win_dll_kernel_errors_get_last()) == mk_win_dll_kernel_errors_id_e_no_unicode_translation && consumed_u16 != ((mk_lang_types_sint_t)(data_len))) ||
			(consumed_u16 == ((mk_lang_types_sint_t)(data_len)) && consumed_u8 >= ((mk_lang_types_sint_t)(data_len)) && consumed_u8 == bytes_out && mk_sl_cui_uint8_memcmp_fn(&u8s_buf[0], ((mk_sl_cui_uint8_pct)(&u8s_buf_2[0])), bytes_out) == 0)
		);
	}
	return 0;
}


#endif
