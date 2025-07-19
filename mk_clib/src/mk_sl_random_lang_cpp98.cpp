#ifndef mk_include_guard_mk_sl_random_lang_cpp98_cpp
#define mk_include_guard_mk_sl_random_lang_cpp98_cpp
#include "mk_sl_random_lang_cpp98.hpp"

#include "mk_lang_version.h"
#if mk_lang_version_has_macro_cplusplus

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"

#include <cstdlib> /* std::srand std::rand */
#include <ctime> /* std::time_t std::time */


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_lang_cpp98_init(mk_lang_types_void_t) mk_lang_noexcept
{
	std::time_t t;
	mk_lang_types_uint_t r;

	t = std::time(mk_lang_null); mk_lang_check_return(t != ((std::time_t)(-1)));
	r = ((mk_lang_types_uint_t)(t));
	std::srand(r);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_lang_cpp98_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_lang_cpp98_generate(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t tsi;
	mk_lang_types_uchar_t tuc;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);

	n = data_len;
	for(i = 0; i != n; ++i)
	{
		tsi = std::rand();
		tuc = ((mk_lang_types_uchar_t)(tsi));
		mk_sl_cui_uint8_from_bi_uchar(&data_buf[i], &tuc);
	}
	return 0;
}


#else
static void mk_sl_random_lang_cpp98_dummy(void){}
#endif
#endif
