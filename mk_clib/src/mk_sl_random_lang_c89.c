#ifndef mk_include_guard_mk_sl_random_lang_c89_c
#define mk_include_guard_mk_sl_random_lang_c89_c
#include "mk_sl_random_lang_c89.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"

#include <stdlib.h> /* srand rand */
#include <time.h> /* time_t time */


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_lang_c89_init(mk_lang_types_void_t) mk_lang_noexcept
{
	time_t t;
	mk_lang_types_uint_t r;

	t = time(mk_lang_null); mk_lang_check_return(t != ((time_t)(-1)));
	r = ((mk_lang_types_uint_t)(t));
	srand(r);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_lang_c89_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_lang_c89_generate(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
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
		tsi = rand();
		tuc = ((mk_lang_types_uchar_t)(tsi));
		mk_sl_cui_uint8_from_bi_uchar(&data_buf[i], &tuc);
	}
	return 0;
}


#endif
