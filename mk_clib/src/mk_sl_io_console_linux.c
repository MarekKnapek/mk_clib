#include "mk_sl_io_console_linux.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_io_writer_file_linux.h"
#include "mk_sl_uint8.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_io_console_linux_contains_null_n(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
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


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_console_linux_write_n(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_sl_io_writer_file_linux_t stdout;
	mk_lang_types_sint_t ret;
	mk_lang_types_usize_t w;

	mk_lang_assert(buf);
	mk_lang_assert(len >= 0);
	mk_lang_assert(!mk_sl_io_console_linux_contains_null_n(buf, len));

	stdout.m_file_handle = 1;
	ret = mk_sl_io_writer_file_linux_write(&stdout, buf, ((mk_lang_types_usize_t)(len)), &w); mk_lang_check_rereturn(ret); mk_lang_check_return(w == ((mk_lang_types_usize_t)(len)));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_console_linux_write_w(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_assert(buf);
	mk_lang_assert(len >= 0);

	mk_lang_assert(mk_lang_false);
	mk_lang_check_return(mk_lang_false);
	return 0;
}
