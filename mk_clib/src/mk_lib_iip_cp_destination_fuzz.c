#ifndef mk_include_guard_mk_lib_iip_cp_destination_fuzz_c
#define mk_include_guard_mk_lib_iip_cp_destination_fuzz_c
#include "mk_lib_iip_cp_destination_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_destination.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_destination_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_uint_t tui;
	mk_lang_types_sint_t destination_cap;
	mk_sl_cui_uint8_t destination_buf[2 * 1024];
	mk_lang_types_sint_t destination_len;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_destination_remote_t remote_destination;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t consumed;
	mk_sl_cui_uint8_t destination_b_buf[2 * 1024];
	mk_lang_types_sint_t consumed_b;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	mk_lang_assert(size <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;

	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&tui, &d[0]); /* todo ne */
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;

	destination_cap = mk_lang_countof(destination_buf);
	tui = mk_lang_min(tui, ((mk_lang_types_uint_t)(s)));
	tui = mk_lang_min(tui, ((mk_lang_types_uint_t)(destination_cap)));
	destination_len = ((mk_lang_types_sint_t)(tui));

	mk_sl_cui_uint8_from_bi_uchar_many(&destination_buf[0], d, destination_len);
	d += destination_len;
	s -= destination_len;

	gud = mk_lang_true;
	err = mk_lib_iip_cp_destination_remote_rw_from_bytes(&remote_destination, &destination_buf[0], destination_len, &gud, &consumed); mk_lang_check_rereturn(err);
	if(gud)
	{
		mk_lang_assert(consumed >= 1);
		mk_lang_assert(consumed <= destination_len);
		err = mk_lib_iip_cp_destination_remote_ro_to_bytes(&remote_destination, &destination_b_buf[0], consumed, &gud, &consumed_b); mk_lang_check_rereturn(err);
		mk_lang_test(gud);
		mk_lang_test(consumed_b == consumed);
		mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&destination_b_buf[0], &destination_buf[0], consumed) == 0);
	}
	return 0;
}


#endif
