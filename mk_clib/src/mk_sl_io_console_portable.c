#include "mk_sl_io_console_portable.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint8.h"

#include <stdio.h> /* printf */


mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_io_console_portable_contains_null_n(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_sl_cui_uint8_t tu8;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(buf);
	mk_lang_assert(len >= 0);

	mk_sl_cui_uint8_set_zero(&tu8);
	n = len;
	for(i = 0; i != n; ++i)
	{
		if(mk_sl_cui_uint8_eq(&buf[i], &tu8))
		{
			return mk_lang_true;
		}
	}
	return mk_lang_false;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_io_console_portable_contains_null_w(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_sl_cui_uint16_pct bf;
	mk_sl_cui_uint16_t tu16;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(buf);
	mk_lang_assert(((mk_lang_types_uintptr_t)(buf)) % 2 == 0);
	mk_lang_assert(len >= 0);

	bf = ((mk_sl_cui_uint16_pct)(buf));
	mk_sl_cui_uint16_set_zero(&tu16);
	n = len;
	for(i = 0; i != n; ++i)
	{
		if(mk_sl_cui_uint16_eq(&bf[i], &tu16))
		{
			return mk_lang_true;
		}
	}
	return mk_lang_false;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_console_portable_write_n(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(buf);
	mk_lang_assert(len >= 0);
	mk_lang_assert(!mk_sl_io_console_portable_contains_null_n(buf, len));

	ret = printf("%s", ((mk_lang_types_pchar_pct)(buf))); mk_lang_check_return(ret >= 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_console_portable_write_w(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(buf);
	mk_lang_assert(len >= 0);
	mk_lang_assert(!mk_sl_io_console_portable_contains_null_w(buf, len));

	ret = printf("%ls", ((mk_lang_types_wchar_pct)(buf))); mk_lang_check_return(ret >= 0);
	return 0;
}
