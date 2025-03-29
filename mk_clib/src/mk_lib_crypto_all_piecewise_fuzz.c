#ifndef mk_include_guard_mk_lib_crypto_all_piecewise_fuzz_c
#define mk_include_guard_mk_lib_crypto_all_piecewise_fuzz_c
#include "mk_lib_crypto_all_piecewise_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_any1.h"
#include "mk_lib_crypto_hash_stream_any2.h"
#include "mk_lib_crypto_xof_stream_any1.h"
#include "mk_lib_crypto_xof_stream_any2.h"
#include "mk_sl_cui_uint8.h"


#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_all_piecewise_fuzz_hashers(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_uint_t kind;
	mk_lib_crypto_hash_stream_any2_t hasher_piecewise;
	mk_lib_crypto_hash_stream_any2_t hasher_once;
	mk_sl_cui_uint8_pt ptr;
	mk_sl_cui_uint8_t buf[1 * 1024];
	mk_lang_types_sint_t rem;
	mk_lang_types_uint_t amount;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_sl_cui_uint8_t digest_piecewise[256];
	mk_sl_cui_uint8_t digest_once[mk_lang_countof(digest_piecewise)];

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(s >= mk_lang_bui_uint_size_bytes_v)
	{
		mk_lang_bui_uint_from_buis_uchar_le(&kind, &d[0]);
		d += mk_lang_bui_uint_size_bytes_v;
		s -= mk_lang_bui_uint_size_bytes_v;
	}
	else
	{
		return 0;
	}
	kind = kind % mk_lib_crypto_hash_stream_any1_id_e_dummy_end;
	mk_lib_crypto_hash_stream_any2_init(&hasher_piecewise, ((mk_lib_crypto_hash_stream_any1_id_t)(kind)));
	mk_lib_crypto_hash_stream_any2_init(&hasher_once, ((mk_lib_crypto_hash_stream_any1_id_t)(kind)));
	ptr = &buf[0];
	rem = mk_lang_countof(buf);
	for(;;)
	{
		if(s >= mk_lang_bui_uint_size_bytes_v)
		{
			mk_lang_bui_uint_from_buis_uchar_le(&amount, &d[0]);
			d += mk_lang_bui_uint_size_bytes_v;
			s -= mk_lang_bui_uint_size_bytes_v;
		}
		else
		{
			break;
		}
		amount = ((mk_lang_types_uint_t)(mk_lang_min(((mk_lang_types_usize_t)(amount)), ((mk_lang_types_usize_t)(rem)))));
		amount = ((mk_lang_types_uint_t)(mk_lang_min(((mk_lang_types_usize_t)(amount)), ((mk_lang_types_usize_t)(s)))));
		n = ((mk_lang_types_sint_t)(amount));
		for(i = 0; i != n; ++i)
		{
			mk_sl_cui_uint8_from_bi_uchar(&ptr[i], &d[i]);
		}
		d += amount;
		s -= amount;
		mk_lib_crypto_hash_stream_any2_append_u8s(&hasher_piecewise, ptr, amount);
		ptr += amount;
		rem -= amount;
		if(rem == 0)
		{
			break;
		}
		if(s == 0)
		{
			break;
		}
	}
	mk_lib_crypto_hash_stream_any2_finish(&hasher_piecewise, &digest_piecewise[0]);
	mk_lib_crypto_hash_stream_any2_append_u8s(&hasher_once, &buf[0], ((mk_lang_types_usize_t)(mk_lang_countof(buf) - rem)));
	mk_lib_crypto_hash_stream_any2_finish(&hasher_once, &digest_once[0]);
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&digest_piecewise[0], &digest_once[0], ((mk_lang_types_usize_t)(mk_lib_crypto_hash_stream_any2_digest_len(&hasher_piecewise)))) == 0);
	return 0;
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_all_piecewise_fuzz_xofers(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_uint_t kind;
	mk_lib_crypto_xof_stream_any2_t xofer_piecewise;
	mk_lib_crypto_xof_stream_any2_t xofer_once;
	mk_sl_cui_uint8_pt ptr;
	mk_sl_cui_uint8_t buf[1 * 1024];
	mk_lang_types_sint_t rem;
	mk_lang_types_uint_t amount;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_sl_cui_uint8_t digest_piecewise[1 * 1024];
	mk_sl_cui_uint8_t digest_once[mk_lang_countof(digest_piecewise)];

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(s >= mk_lang_bui_uint_size_bytes_v)
	{
		mk_lang_bui_uint_from_buis_uchar_le(&kind, &d[0]);
		d += mk_lang_bui_uint_size_bytes_v;
		s -= mk_lang_bui_uint_size_bytes_v;
	}
	else
	{
		return 0;
	}
	kind = kind % mk_lib_crypto_xof_stream_any1_id_e_dummy_end;
	mk_lib_crypto_xof_stream_any2_init(&xofer_piecewise, ((mk_lib_crypto_xof_stream_any1_id_t)(kind)));
	mk_lib_crypto_xof_stream_any2_init(&xofer_once, ((mk_lib_crypto_xof_stream_any1_id_t)(kind)));
	ptr = &buf[0];
	rem = mk_lang_countof(buf);
	for(;;)
	{
		if(s >= mk_lang_bui_uint_size_bytes_v)
		{
			mk_lang_bui_uint_from_buis_uchar_le(&amount, &d[0]);
			d += mk_lang_bui_uint_size_bytes_v;
			s -= mk_lang_bui_uint_size_bytes_v;
		}
		else
		{
			break;
		}
		amount = ((mk_lang_types_uint_t)(mk_lang_min(((mk_lang_types_usize_t)(amount)), ((mk_lang_types_usize_t)(rem)))));
		amount = ((mk_lang_types_uint_t)(mk_lang_min(((mk_lang_types_usize_t)(amount)), ((mk_lang_types_usize_t)(s)))));
		n = ((mk_lang_types_sint_t)(amount));
		for(i = 0; i != n; ++i)
		{
			mk_sl_cui_uint8_from_bi_uchar(&ptr[i], &d[i]);
		}
		d += amount;
		s -= amount;
		mk_lib_crypto_xof_stream_any2_append_u8s(&xofer_piecewise, ptr, amount);
		ptr += amount;
		rem -= amount;
		if(rem == 0)
		{
			break;
		}
	}
	mk_lib_crypto_xof_stream_any2_finish(&xofer_piecewise);
	mk_lib_crypto_xof_stream_any2_append_u8s(&xofer_once, &buf[0], ((mk_lang_types_usize_t)(mk_lang_countof(buf) - rem)));
	mk_lib_crypto_xof_stream_any2_finish(&xofer_once);
	ptr = &digest_piecewise[0];
	rem = mk_lang_countof(digest_piecewise);
	for(;;)
	{
		if(s >= mk_lang_bui_uint_size_bytes_v)
		{
			mk_lang_bui_uint_from_buis_uchar_le(&amount, &d[0]);
			d += mk_lang_bui_uint_size_bytes_v;
			s -= mk_lang_bui_uint_size_bytes_v;
		}
		else
		{
			break;
		}
		amount = ((mk_lang_types_uint_t)(mk_lang_min(((mk_lang_types_usize_t)(amount)), ((mk_lang_types_usize_t)(rem)))));
		mk_lib_crypto_xof_stream_any2_squeeze_u8s(&xofer_piecewise, ptr, amount);
		ptr += amount;
		rem -= amount;
		if(rem == 0)
		{
			break;
		}
	}
	mk_lib_crypto_xof_stream_any2_squeeze_u8s(&xofer_once, &digest_once[0], ((mk_lang_types_usize_t)(mk_lang_countof(digest_once) - rem)));
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&digest_piecewise[0], &digest_once[0], ((mk_lang_types_usize_t)(mk_lang_countof(digest_once) - rem))) == 0);
	return 0;
}
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_all_piecewise_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size, mk_lang_types_bool_t const allow_all) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_uint_t line mk_lang_constexpr_init;
	mk_lang_types_bool_t all mk_lang_constexpr_init;
	mk_lang_types_uint_t base mk_lang_constexpr_init;
	mk_lang_types_uint_t curr mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

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
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_all_piecewise_fuzz_hashers(d, s); mk_lang_check_rereturn(err); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ err = mk_lib_crypto_all_piecewise_fuzz_xofers(d, s); mk_lang_check_rereturn(err); }
	return 0;
}


#endif
