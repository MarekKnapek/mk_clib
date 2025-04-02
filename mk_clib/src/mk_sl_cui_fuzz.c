#ifndef mk_include_guard_mk_sl_cui_fuzz_c
#define mk_include_guard_mk_sl_cui_fuzz_c
#include "mk_sl_cui_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_fuzz_bui.h"
#include "mk_sl_cui_fuzz_cui.h"
#include "mk_sl_cui_fuzz_fromchars.h"
#include "mk_sl_cui_fuzz_printf.h"
#include "mk_sl_cui_fuzz_tochars.h"


mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size, mk_lang_types_bool_t const allow_all) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_uint_t line mk_lang_constexpr_init;
	mk_lang_types_bool_t all mk_lang_constexpr_init;
	mk_lang_types_uint_t base mk_lang_constexpr_init;
	mk_lang_types_uint_t curr mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	mk_lang_assert(allow_all == mk_lang_true || allow_all == mk_lang_false);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	line = 0;
	if(s >= mk_lang_bui_uint_size_bytes_v)
	{
		mk_lang_bui_uint_from_buis_uchar_le(&line, &d[0]);
		d += mk_lang_bui_uint_size_bytes_v;
		s -= mk_lang_bui_uint_size_bytes_v;
	}
	all = mk_lang_bui_uint_is_max(&line) && allow_all;
	base = __LINE__;
	curr = base + 2 + line;
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_bui(d, s, allow_all); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_cui(d, s, allow_all); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_fromchars(d, s, allow_all); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_printf(d, s, allow_all); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_tochars(d, s, allow_all); }
}


#endif
