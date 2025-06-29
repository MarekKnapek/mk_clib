#ifndef mk_include_guard_mk_lib_iip_logger_c
#define mk_include_guard_mk_lib_iip_logger_c
#include "mk_lib_iip_logger.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_logger_html.h"
#include "mk_sl_logger_stdout.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_logger_prrw_construct(mk_lib_iip_logger_pt const logger, mk_lang_types_pchar_pct const file_name) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);
	mk_lang_assert(file_name);
	mk_lang_assert(file_name[0] != '\0');

	err = mk_sl_logger_stdout_rw_construct(&logger->m_logger_stdout); mk_lang_check_rereturn(err);
	err = mk_sl_logger_html_rw_construct(&logger->m_logger_html, file_name); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_logger_prrw_destroy(mk_lib_iip_logger_pt const logger) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);

	err = mk_sl_logger_stdout_rw_destroy(&logger->m_logger_stdout); mk_lang_check_rereturn(err);
	err = mk_sl_logger_html_rw_destroy(&logger->m_logger_html); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_logger_prrw_begin_line(mk_lib_iip_logger_pt const logger) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);

	err = mk_sl_logger_stdout_rw_begin_line(&logger->m_logger_stdout); mk_lang_check_rereturn(err);
	err = mk_sl_logger_html_rw_begin_line(&logger->m_logger_html); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_logger_prrw_end_line(mk_lib_iip_logger_pt const logger) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);

	err = mk_sl_logger_stdout_rw_end_line(&logger->m_logger_stdout); mk_lang_check_rereturn(err);
	err = mk_sl_logger_html_rw_end_line(&logger->m_logger_html); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_logger_prrw_begin_color(mk_lib_iip_logger_pt const logger, mk_lib_iip_logger_color_text_t const color) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);
	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lib_iip_logger_color_text_e_dummy_end);

	err = mk_sl_logger_stdout_rw_begin_color(&logger->m_logger_stdout, color); mk_lang_check_rereturn(err);
	err = mk_sl_logger_html_rw_begin_color(&logger->m_logger_html, color); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_logger_prrw_end_color(mk_lib_iip_logger_pt const logger) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);

	err = mk_sl_logger_stdout_rw_end_color(&logger->m_logger_stdout); mk_lang_check_rereturn(err);
	err = mk_sl_logger_html_rw_end_color(&logger->m_logger_html); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_logger_prrw_print(mk_lib_iip_logger_pt const logger, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_sl_logger_stdout_rw_print(&logger->m_logger_stdout, str_buf, str_len); mk_lang_check_rereturn(err);
	err = mk_sl_logger_html_rw_print(&logger->m_logger_html, str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_logger_rw_construct(mk_lib_iip_logger_pt const logger, mk_lang_types_pchar_pct const file_name) mk_lang_noexcept
{
	return mk_lib_iip_logger_prrw_construct(logger, file_name);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_logger_rw_destroy(mk_lib_iip_logger_pt const logger) mk_lang_noexcept
{
	return mk_lib_iip_logger_prrw_destroy(logger);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_logger_rw_begin_line(mk_lib_iip_logger_pt const logger) mk_lang_noexcept
{
	return mk_lib_iip_logger_prrw_begin_line(logger);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_logger_rw_end_line(mk_lib_iip_logger_pt const logger) mk_lang_noexcept
{
	return mk_lib_iip_logger_prrw_end_line(logger);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_logger_rw_begin_color(mk_lib_iip_logger_pt const logger, mk_lib_iip_logger_color_text_t const color) mk_lang_noexcept
{
	return mk_lib_iip_logger_prrw_begin_color(logger, color);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_logger_rw_end_color(mk_lib_iip_logger_pt const logger) mk_lang_noexcept
{
	return mk_lib_iip_logger_prrw_end_color(logger);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_logger_rw_print(mk_lib_iip_logger_pt const logger, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lib_iip_logger_prrw_print(logger, str_buf, str_len);
}


#endif
