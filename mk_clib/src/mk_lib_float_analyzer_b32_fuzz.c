#ifndef mk_include_guard_mk_lib_float_analyzer_b32_fuzz_c
#define mk_include_guard_mk_lib_float_analyzer_b32_fuzz_c
#include "mk_lib_float_analyzer_b32_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_float_analyzer_b32.h"
#include "mk_sl_cui_uint32.h"

#if defined __cplusplus
#include <cstring> /* std::memcpy */
#include <cstdlib> /* std::atof */
#define mk_memcpy std::memcpy
#define mk_atof std::atof
#else
#include <string.h> /* memcpy */
#include <stdlib.h> /* atof */
#define mk_memcpy memcpy
#define mk_atof atof
#endif

#if mk_lang_version_at_least_cpp_17 || mk_lang_version_at_least_msvc_cpp_17
#include <charconv> /* std::from_chars_result std::from_chars */
#include <system_error> /* std::errc */
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_float_analyzer_b32_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_float_t flt_val;
	mk_sl_cui_uint32_t cui;
	mk_lib_float_analyzer_b32_t analyzer;
	mk_lang_types_float_t res_flt;

	mk_lang_static_assert(sizeof(flt_val) * mk_lang_charbit == 32);
	mk_lang_static_assert(mk_lang_countof(analyzer.m_float_bytes_le) * mk_lang_charbit == 32);

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= sizeof(flt_val)))
	{
		return 0;
	}
	mk_sl_cui_uint32_from_buis_uchar_le(&cui, d); /* ne */
	d += sizeof(flt_val);
	s -= sizeof(flt_val);

	mk_sl_cui_uint32_to_buis_uchar_le(&cui, &analyzer.m_float_bytes_le[0]);
	mk_memcpy(&flt_val, &analyzer.m_float_bytes_le[0], sizeof(flt_val));

	mk_lib_float_analyzer_b32_analyze(&analyzer);

	#if mk_lang_version_at_least_cpp_17 || mk_lang_version_at_least_msvc_cpp_17
	{
		std::from_chars_result res;

		res = std::from_chars(&analyzer.m_value_buf[0], &analyzer.m_value_buf[analyzer.m_value_len], res_flt, std::chars_format::fixed);
		mk_lang_test(res.ec == std::errc{});
		mk_lang_test(res.ptr == &analyzer.m_value_buf[analyzer.m_value_len]);
		mk_lang_test((res_flt == flt_val) || (res_flt != res_flt && flt_val != flt_val));
	}
	#endif

	analyzer.m_value_buf[analyzer.m_value_len] = '\0';
	res_flt = ((mk_lang_types_float_t)(mk_atof(&analyzer.m_value_buf[0])));
	mk_lang_test((res_flt == flt_val) || (res_flt != res_flt && flt_val != flt_val));
	return 0;
}


#endif
