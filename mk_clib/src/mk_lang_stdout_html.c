#ifndef mk_include_guard_mk_lang_stdout_html_c
#define mk_include_guard_mk_lang_stdout_html_c
#include "mk_lang_stdout_html.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_string.h"
#include "mk_lang_tchar.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_io_appender_file.h"
#include "mk_sl_logger_html.h"


struct mk_lang_stdout_html_s
{
	mk_sl_logger_html_t m_logger_html;
};
typedef struct mk_lang_stdout_html_s mk_lang_stdout_html_t;
mk_lang_typedef(mk_lang_stdout_html);


static mk_lang_stdout_html_t mk_lang_stdout_html_g;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_html_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_sl_logger_html_rw_construct(&mk_lang_stdout_html_g.m_logger_html, "out.html"); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_html_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_sl_logger_html_rw_destroy(&mk_lang_stdout_html_g.m_logger_html); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_html_begin_line(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_sl_logger_html_rw_begin_line(&mk_lang_stdout_html_g.m_logger_html); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_html_end_line(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_sl_logger_html_rw_end_line(&mk_lang_stdout_html_g.m_logger_html); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_html_begin_color(mk_lang_stdout_html_color_text_t const color) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_sl_logger_html_rw_begin_color(&mk_lang_stdout_html_g.m_logger_html, ((mk_sl_logger_html_color_text_t)(color))); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_html_end_color(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_sl_logger_html_rw_end_color(&mk_lang_stdout_html_g.m_logger_html); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_html_print(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_sl_logger_html_rw_print(&mk_lang_stdout_html_g.m_logger_html, str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}


#endif
