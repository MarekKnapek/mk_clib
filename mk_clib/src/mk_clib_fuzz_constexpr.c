#include "mk_clib_fuzz_constexpr.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_xof_stream_shake_128.h"
#include "mk_sl_uint8.h"

#include "mk_lang_bui_fuzz.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_clib_fuzz_constexpr_append_file(mk_lib_crypto_xof_stream_shake_128_pt const shaker, mk_lang_types_pchar_pct const file) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;

	mk_lang_assert(shaker);
	mk_lang_assert(file && file[0] != '\0');

	for(i = 0; file[i] != '\0'; ++i)
	{
		mk_sl_cui_uint8_from_bi_pchar(&tu8, &file[i]);
		mk_lib_crypto_xof_stream_shake_128_append_u8(shaker, &tu8, 1);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_clib_fuzz_constexpr_append_line(mk_lib_crypto_xof_stream_shake_128_pt const shaker, mk_lang_types_ulllong_t const line) mk_lang_noexcept
{
	mk_sl_cui_uint8_t tu8s[sizeof(line)] mk_lang_constexpr_init;

	mk_lang_assert(shaker);

	mk_sl_cui_uint8_from_buis_ulllong_le(&tu8s[0], &line);
	mk_lib_crypto_xof_stream_shake_128_append_u8(shaker, &tu8s[0], mk_lang_countof(tu8s));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_clib_fuzz_constexpr_append_date(mk_lib_crypto_xof_stream_shake_128_pt const shaker, mk_lang_types_pchar_pct const date) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;

	mk_lang_assert(shaker);
	mk_lang_assert(date && date[0] != '\0');

	for(i = 0; date[i] != '\0'; ++i)
	{
		mk_sl_cui_uint8_from_bi_pchar(&tu8, &date[i]);
		mk_lib_crypto_xof_stream_shake_128_append_u8(shaker, &tu8, 1);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_clib_fuzz_constexpr_append_time(mk_lib_crypto_xof_stream_shake_128_pt const shaker, mk_lang_types_pchar_pct const time) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;

	mk_lang_assert(shaker);
	mk_lang_assert(time && time[0] != '\0');

	for(i = 0; time[i] != '\0'; ++i)
	{
		mk_sl_cui_uint8_from_bi_pchar(&tu8, &time[i]);
		mk_lib_crypto_xof_stream_shake_128_append_u8(shaker, &tu8, 1);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_clib_fuzz_constexpr_init_shaker(mk_lib_crypto_xof_stream_shake_128_pt const shaker) mk_lang_noexcept
{
	mk_lang_assert(shaker);

	mk_lib_crypto_xof_stream_shake_128_init(shaker);
	mk_clib_fuzz_constexpr_append_file(shaker, __FILE__);
	mk_clib_fuzz_constexpr_append_line(shaker, __LINE__);
	mk_clib_fuzz_constexpr_append_date(shaker, __DATE__);
	mk_clib_fuzz_constexpr_append_time(shaker, __TIME__);
	mk_lib_crypto_xof_stream_shake_128_finish(shaker);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_clib_fuzz_constexpr_get_nth_block(mk_lib_crypto_xof_stream_shake_128_pt const shaker, mk_lang_types_sint_t const nth, mk_lang_static_param(mk_lang_types_uchar_t, data_uc, 256)) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint8_t data_u8[256] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;

	mk_lang_assert(shaker);
	mk_lang_assert(nth >= 0 && nth <= 999);
	mk_lang_assert(data_uc);

	mk_clib_fuzz_constexpr_init_shaker(shaker);
	for(i = 0; i != nth; ++i)
	{
		mk_lib_crypto_xof_stream_shake_128_squeeze(shaker, mk_lang_countof(data_u8), &data_u8[0]);
	}
	n = mk_lang_countof(data_u8);
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_to_bi_uchar(&data_u8[i], &data_uc[i]);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_clib_fuzz_constexpr_impl(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_fuzz(data, size);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_clib_fuzz_constexpr_test_nth_block(mk_lang_types_sint_t const nth) mk_lang_noexcept
{
	mk_lib_crypto_xof_stream_shake_128_t shaker mk_lang_constexpr_init;
	mk_lang_types_uchar_t data_uc[256] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(nth >= 0 && nth <= 999);

	mk_clib_fuzz_constexpr_get_nth_block(&shaker, nth, &data_uc[0]);
	n = mk_lang_countof(data_uc);
	for(i = 0; i != n; ++i)
	{
		mk_clib_fuzz_constexpr_impl(&data_uc[0], i);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_clib_fuzz_constexpr_test_n_blocks(mk_lang_types_sint_t const n) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(n >= 0 && n <= 999);

	for(i = 0; i != n; ++i)
	{
		mk_clib_fuzz_constexpr_test_nth_block(i);
	}
	return 0;
}


mk_lang_jumbo mk_lang_types_void_t mk_clib_fuzz_constexpr(mk_lang_types_void_t) mk_lang_noexcept
{
	#if mk_lang_constexpr_has
	mk_lang_static_assert(mk_clib_fuzz_constexpr_test_n_blocks(16) == 0);
	#endif
}
