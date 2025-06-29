#ifndef mk_include_guard_mk_sl_logger_stdout_c
#define mk_include_guard_mk_sl_logger_stdout_c
#include "mk_sl_logger_stdout.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stdout.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_stdout_prrw_construct(mk_sl_logger_stdout_pt const logger) mk_lang_noexcept
{
	mk_lang_assert(logger);

	logger->m_color = mk_sl_logger_stdout_color_text_e_dummy_end;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_stdout_prrw_destroy(mk_sl_logger_stdout_pt const logger) mk_lang_noexcept
{
	mk_lang_assert(logger);

	((mk_lang_types_void_t)(logger));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_stdout_prrw_begin_line(mk_sl_logger_stdout_pt const logger) mk_lang_noexcept
{
	mk_lang_assert(logger);

	((mk_lang_types_void_t)(logger));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_stdout_prrw_end_line(mk_sl_logger_stdout_pt const logger) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);

	err = mk_lang_stdout_println_lit_n(""); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_stdout_prrw_begin_color(mk_sl_logger_stdout_pt const logger, mk_sl_logger_stdout_color_text_t const color) mk_lang_noexcept
{
	mk_lang_assert(logger);
	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_sl_logger_stdout_color_text_e_dummy_end);

	logger->m_color = color;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_stdout_prrw_end_color(mk_sl_logger_stdout_pt const logger) mk_lang_noexcept
{
	mk_lang_assert(logger);

	logger->m_color = mk_sl_logger_stdout_color_text_e_dummy_end;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_stdout_prrw_print(mk_sl_logger_stdout_pt const logger, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	if(logger->m_color == mk_sl_logger_stdout_color_text_e_dummy_end)
	{
		err = mk_lang_stdout_print_n(str_buf, str_len); mk_lang_check_rereturn(err);
	}
	else
	{
		err = mk_lang_stdout_print_color_n(logger->m_color, str_buf, str_len); mk_lang_check_rereturn(err);
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_stdout_rw_construct(mk_sl_logger_stdout_pt const logger) mk_lang_noexcept
{
	return mk_sl_logger_stdout_prrw_construct(logger);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_stdout_rw_destroy(mk_sl_logger_stdout_pt const logger) mk_lang_noexcept
{
	return mk_sl_logger_stdout_prrw_destroy(logger);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_stdout_rw_begin_line(mk_sl_logger_stdout_pt const logger) mk_lang_noexcept
{
	return mk_sl_logger_stdout_prrw_begin_line(logger);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_stdout_rw_end_line(mk_sl_logger_stdout_pt const logger) mk_lang_noexcept
{
	return mk_sl_logger_stdout_prrw_end_line(logger);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_stdout_rw_begin_color(mk_sl_logger_stdout_pt const logger, mk_sl_logger_stdout_color_text_t const color) mk_lang_noexcept
{
	return mk_sl_logger_stdout_prrw_begin_color(logger, color);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_stdout_rw_end_color(mk_sl_logger_stdout_pt const logger) mk_lang_noexcept
{
	return mk_sl_logger_stdout_prrw_end_color(logger);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_stdout_rw_print(mk_sl_logger_stdout_pt const logger, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_sl_logger_stdout_prrw_print(logger, str_buf, str_len);
}


#endif
