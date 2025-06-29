#ifndef mk_include_guard_mk_sl_logger_html_c
#define mk_include_guard_mk_sl_logger_html_c
#include "mk_sl_logger_html.h"

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
#include "mk_win_dll_advapi.h"
#include "mk_win_dll_kernel_errors.h"
#include "mk_win_dll_kernel_files.h"
#include "mk_win_dll_kernel_handle.h"


#define mk_sl_logger_html_k_crlf "\x0d\x0a"
#define mk_sl_logger_html_k_tab "\t"
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_document_header[] =
	"<!DOCTYPE html>" mk_sl_logger_html_k_crlf
	"<html lang=\"en\">" mk_sl_logger_html_k_crlf
	mk_sl_logger_html_k_tab "<head>" mk_sl_logger_html_k_crlf
	mk_sl_logger_html_k_tab mk_sl_logger_html_k_tab "<meta charset=\"UTF-8\">" mk_sl_logger_html_k_crlf
	mk_sl_logger_html_k_tab mk_sl_logger_html_k_tab "<title>log</title>" mk_sl_logger_html_k_crlf
	mk_sl_logger_html_k_tab mk_sl_logger_html_k_tab "<style>" mk_sl_logger_html_k_crlf
	"div.session" mk_sl_logger_html_k_crlf
	"{" mk_sl_logger_html_k_crlf
	"	background-color: #0c0c0c;" mk_sl_logger_html_k_crlf
	"	color: #cccccc;" mk_sl_logger_html_k_crlf
	"	display: inline-block;" mk_sl_logger_html_k_crlf
	"	font-family: monospace;" mk_sl_logger_html_k_crlf
	"}" mk_sl_logger_html_k_crlf
	"span.line" mk_sl_logger_html_k_crlf
	"{" mk_sl_logger_html_k_crlf
	"	white-space: pre;" mk_sl_logger_html_k_crlf
	"}" mk_sl_logger_html_k_crlf
	"span.color_dark_black    { color: #0c0c0c; }" mk_sl_logger_html_k_crlf
	"span.color_dark_red      { color: #c50f1f; }" mk_sl_logger_html_k_crlf
	"span.color_dark_green    { color: #13a10e; }" mk_sl_logger_html_k_crlf
	"span.color_dark_blue     { color: #0037da; }" mk_sl_logger_html_k_crlf
	"span.color_dark_yellow   { color: #c19c00; }" mk_sl_logger_html_k_crlf
	"span.color_dark_magenta  { color: #881798; }" mk_sl_logger_html_k_crlf
	"span.color_dark_cyan     { color: #3a96dd; }" mk_sl_logger_html_k_crlf
	"span.color_dark_white    { color: #cccccc; }" mk_sl_logger_html_k_crlf
	"span.color_light_black   { color: #767676; }" mk_sl_logger_html_k_crlf
	"span.color_light_red     { color: #e74856; }" mk_sl_logger_html_k_crlf
	"span.color_light_green   { color: #16c60c; }" mk_sl_logger_html_k_crlf
	"span.color_light_blue    { color: #3b78ff; }" mk_sl_logger_html_k_crlf
	"span.color_light_yellow  { color: #f9f1a5; }" mk_sl_logger_html_k_crlf
	"span.color_light_magenta { color: #b4009e; }" mk_sl_logger_html_k_crlf
	"span.color_light_cyan    { color: #61d6d6; }" mk_sl_logger_html_k_crlf
	"span.color_light_white   { color: #f2f2f2; }" mk_sl_logger_html_k_crlf
	mk_sl_logger_html_k_tab mk_sl_logger_html_k_tab "</style>" mk_sl_logger_html_k_crlf
	mk_sl_logger_html_k_tab "</head>" mk_sl_logger_html_k_crlf
	mk_sl_logger_html_k_tab "<body>" mk_sl_logger_html_k_crlf
	"";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_document_footer[] =
	mk_sl_logger_html_k_tab "</body>" mk_sl_logger_html_k_crlf
	"</html>" mk_sl_logger_html_k_crlf
	"";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_session_header[] =
	mk_sl_logger_html_k_tab mk_sl_logger_html_k_tab "<div class=\"session\">" mk_sl_logger_html_k_crlf;
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_session_footer[] =
	mk_sl_logger_html_k_tab mk_sl_logger_html_k_tab "</div>" mk_sl_logger_html_k_crlf;
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_line_header[] =
	mk_sl_logger_html_k_tab mk_sl_logger_html_k_tab mk_sl_logger_html_k_tab "<span class=\"line\">";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_line_footer[] =
	"</span><br>" mk_sl_logger_html_k_crlf
	"";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_color_header_a[] = "<span class=\"";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_color_header_b[] = "\">";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_color_footer[] = "</span>";

mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_color_dark_black   [] = "color_dark_black";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_color_dark_red     [] = "color_dark_red";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_color_dark_green   [] = "color_dark_green";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_color_dark_blue    [] = "color_dark_blue";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_color_dark_yellow  [] = "color_dark_yellow";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_color_dark_magenta [] = "color_dark_magenta";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_color_dark_cyan    [] = "color_dark_cyan";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_color_dark_white   [] = "color_dark_white";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_color_light_black  [] = "color_light_black";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_color_light_red    [] = "color_light_red";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_color_light_green  [] = "color_light_green";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_color_light_blue   [] = "color_light_blue";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_color_light_yellow [] = "color_light_yellow";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_color_light_magenta[] = "color_light_magenta";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_color_light_cyan   [] = "color_light_cyan";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_logger_html_k_color_light_white  [] = "color_light_white";

mk_lang_constexpr_static_inline mk_lang_types_pchar_pct const mk_sl_logger_html_k_colors_buf[] =
{
	&mk_sl_logger_html_k_color_dark_black   [0],
	&mk_sl_logger_html_k_color_dark_red     [0],
	&mk_sl_logger_html_k_color_dark_green   [0],
	&mk_sl_logger_html_k_color_dark_blue    [0],
	&mk_sl_logger_html_k_color_dark_yellow  [0],
	&mk_sl_logger_html_k_color_dark_magenta [0],
	&mk_sl_logger_html_k_color_dark_cyan    [0],
	&mk_sl_logger_html_k_color_dark_white   [0],
	&mk_sl_logger_html_k_color_light_black  [0],
	&mk_sl_logger_html_k_color_light_red    [0],
	&mk_sl_logger_html_k_color_light_green  [0],
	&mk_sl_logger_html_k_color_light_blue   [0],
	&mk_sl_logger_html_k_color_light_yellow [0],
	&mk_sl_logger_html_k_color_light_magenta[0],
	&mk_sl_logger_html_k_color_light_cyan   [0],
	&mk_sl_logger_html_k_color_light_white  [0],
};
mk_lang_constexpr_static_inline mk_lang_types_uchar_t const mk_sl_logger_html_k_colors_len[] =
{
	((mk_lang_types_uchar_t)(mk_lang_countstr(mk_sl_logger_html_k_color_dark_black   ))),
	((mk_lang_types_uchar_t)(mk_lang_countstr(mk_sl_logger_html_k_color_dark_red     ))),
	((mk_lang_types_uchar_t)(mk_lang_countstr(mk_sl_logger_html_k_color_dark_green   ))),
	((mk_lang_types_uchar_t)(mk_lang_countstr(mk_sl_logger_html_k_color_dark_blue    ))),
	((mk_lang_types_uchar_t)(mk_lang_countstr(mk_sl_logger_html_k_color_dark_yellow  ))),
	((mk_lang_types_uchar_t)(mk_lang_countstr(mk_sl_logger_html_k_color_dark_magenta ))),
	((mk_lang_types_uchar_t)(mk_lang_countstr(mk_sl_logger_html_k_color_dark_cyan    ))),
	((mk_lang_types_uchar_t)(mk_lang_countstr(mk_sl_logger_html_k_color_dark_white   ))),
	((mk_lang_types_uchar_t)(mk_lang_countstr(mk_sl_logger_html_k_color_light_black  ))),
	((mk_lang_types_uchar_t)(mk_lang_countstr(mk_sl_logger_html_k_color_light_red    ))),
	((mk_lang_types_uchar_t)(mk_lang_countstr(mk_sl_logger_html_k_color_light_green  ))),
	((mk_lang_types_uchar_t)(mk_lang_countstr(mk_sl_logger_html_k_color_light_blue   ))),
	((mk_lang_types_uchar_t)(mk_lang_countstr(mk_sl_logger_html_k_color_light_yellow ))),
	((mk_lang_types_uchar_t)(mk_lang_countstr(mk_sl_logger_html_k_color_light_magenta))),
	((mk_lang_types_uchar_t)(mk_lang_countstr(mk_sl_logger_html_k_color_light_cyan   ))),
	((mk_lang_types_uchar_t)(mk_lang_countstr(mk_sl_logger_html_k_color_light_white  ))),
};


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_write_str(mk_sl_logger_html_pt const logger, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_win_base_handle_t handle;
	mk_win_base_void_lpct buffer;
	mk_win_base_dword_t bytes_to_write;
	mk_win_base_dword_t bytes_written;
	mk_win_dll_kernel_files_overlapped_lpt overlapped;
	mk_win_base_bool_t b;

	mk_lang_assert(logger);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(!mk_win_base_handle_is_invalid(logger->m_file_handle));

	handle = logger->m_file_handle;
	buffer = str_buf;
	bytes_to_write = str_len;
	bytes_written = 0;
	overlapped = mk_win_base_null;
	b = mk_win_dll_kernel_files_write_file(handle, buffer, bytes_to_write, &bytes_written, overlapped); mk_lang_check_return(b != mk_win_base_false); mk_lang_check_return(bytes_written == bytes_to_write);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_write_document_header(mk_sl_logger_html_pt const logger) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);
	mk_lang_assert(!mk_win_base_handle_is_invalid(logger->m_file_handle));

	err = mk_sl_logger_html_prrw_write_str(logger, &mk_sl_logger_html_k_document_header[0], mk_lang_countstr(mk_sl_logger_html_k_document_header)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_write_document_footer(mk_sl_logger_html_pt const logger) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);
	mk_lang_assert(!mk_win_base_handle_is_invalid(logger->m_file_handle));

	err = mk_sl_logger_html_prrw_write_str(logger, &mk_sl_logger_html_k_document_footer[0], mk_lang_countstr(mk_sl_logger_html_k_document_footer)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_write_session_header(mk_sl_logger_html_pt const logger) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);
	mk_lang_assert(!mk_win_base_handle_is_invalid(logger->m_file_handle));

	err = mk_sl_logger_html_prrw_write_str(logger, &mk_sl_logger_html_k_session_header[0], mk_lang_countstr(mk_sl_logger_html_k_session_header)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_write_session_footer(mk_sl_logger_html_pt const logger) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);
	mk_lang_assert(!mk_win_base_handle_is_invalid(logger->m_file_handle));

	err = mk_sl_logger_html_prrw_write_str(logger, &mk_sl_logger_html_k_session_footer[0], mk_lang_countstr(mk_sl_logger_html_k_session_footer)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_write_line_header(mk_sl_logger_html_pt const logger) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);
	mk_lang_assert(!mk_win_base_handle_is_invalid(logger->m_file_handle));

	err = mk_sl_logger_html_prrw_write_str(logger, &mk_sl_logger_html_k_line_header[0], mk_lang_countstr(mk_sl_logger_html_k_line_header)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_write_line_footer(mk_sl_logger_html_pt const logger) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);
	mk_lang_assert(!mk_win_base_handle_is_invalid(logger->m_file_handle));

	err = mk_sl_logger_html_prrw_write_str(logger, &mk_sl_logger_html_k_line_footer[0], mk_lang_countstr(mk_sl_logger_html_k_line_footer)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_write_color_header_a(mk_sl_logger_html_pt const logger) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);
	mk_lang_assert(!mk_win_base_handle_is_invalid(logger->m_file_handle));

	err = mk_sl_logger_html_prrw_write_str(logger, &mk_sl_logger_html_k_color_header_a[0], mk_lang_countstr(mk_sl_logger_html_k_color_header_a)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_write_color_header_b(mk_sl_logger_html_pt const logger) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);
	mk_lang_assert(!mk_win_base_handle_is_invalid(logger->m_file_handle));

	err = mk_sl_logger_html_prrw_write_str(logger, &mk_sl_logger_html_k_color_header_b[0], mk_lang_countstr(mk_sl_logger_html_k_color_header_b)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_write_color_footer(mk_sl_logger_html_pt const logger) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);
	mk_lang_assert(!mk_win_base_handle_is_invalid(logger->m_file_handle));

	err = mk_sl_logger_html_prrw_write_str(logger, &mk_sl_logger_html_k_color_footer[0], mk_lang_countstr(mk_sl_logger_html_k_color_footer)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_move_in_front_of_document_footer(mk_sl_logger_html_pt const logger) mk_lang_noexcept
{
	mk_win_base_handle_t handle;
	mk_win_base_slong_t distance_lo;
	mk_win_base_slong_lpt distance_hi;
	mk_win_base_dword_t move_method;
	mk_win_base_dword_t new_lo;
	mk_win_base_dword_t gle;

	mk_lang_assert(logger);
	mk_lang_assert(!mk_win_base_handle_is_invalid(logger->m_file_handle));

	handle = logger->m_file_handle;
	distance_lo = -mk_lang_countstr(mk_sl_logger_html_k_document_footer);
	distance_hi = mk_win_base_null;
	move_method = mk_win_dll_kernel_files_file_pos_e_end;
	new_lo = mk_win_dll_kernel_files_set_file_pointer(handle, distance_lo, distance_hi, move_method); mk_lang_check_return(new_lo != s_mk_win_dll_kernel_files_invalid_set_file_pointer || (gle = mk_win_dll_kernel_errors_get_last()) == mk_win_dll_kernel_errors_id_e_success);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_move_in_front_of_session_footer(mk_sl_logger_html_pt const logger) mk_lang_noexcept
{
	mk_win_base_handle_t handle;
	mk_win_base_slong_t distance_lo;
	mk_win_base_slong_lpt distance_hi;
	mk_win_base_dword_t move_method;
	mk_win_base_dword_t new_lo;
	mk_win_base_dword_t gle;

	mk_lang_assert(logger);
	mk_lang_assert(!mk_win_base_handle_is_invalid(logger->m_file_handle));

	handle = logger->m_file_handle;
	distance_lo = -(mk_lang_countstr(mk_sl_logger_html_k_document_footer) + mk_lang_countstr(mk_sl_logger_html_k_session_footer));
	distance_hi = mk_win_base_null;
	move_method = mk_win_dll_kernel_files_file_pos_e_end;
	new_lo = mk_win_dll_kernel_files_set_file_pointer(handle, distance_lo, distance_hi, move_method); mk_lang_check_return(new_lo != s_mk_win_dll_kernel_files_invalid_set_file_pointer || (gle = mk_win_dll_kernel_errors_get_last()) == mk_win_dll_kernel_errors_id_e_success);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_open_file(mk_sl_logger_html_pt const logger, mk_lang_types_pchar_pct const name, mk_lang_types_bool_pt const already_existed) mk_lang_noexcept
{
	mk_win_base_pchar_lpct file_name;
	mk_win_base_dword_t desired_access;
	mk_win_base_dword_t share_mode;
	mk_win_dll_advapi_security_attributes_lpct security_attributes;
	mk_win_base_dword_t creation_disposition;
	mk_win_base_dword_t flags_and_attributes;
	mk_win_base_handle_t template_file;
	mk_win_base_handle_t file_handle;
	mk_win_base_dword_t gle;

	mk_lang_assert(logger);
	mk_lang_assert(name);
	mk_lang_assert(name[0] != '\0');
	mk_lang_assert(already_existed);

	file_name = name;
	desired_access = ((mk_win_base_dword_t)(mk_win_dll_advapi_right_generic_e_read)) | ((mk_win_base_dword_t)(mk_win_dll_advapi_right_generic_e_write));
	share_mode = mk_win_dll_kernel_files_share_e_read | mk_win_dll_kernel_files_share_e_delete;
	security_attributes = mk_win_base_null;
	creation_disposition = mk_win_dll_kernel_files_create_e_open_always;
	flags_and_attributes = mk_win_dll_kernel_files_flag_e_none | mk_win_dll_kernel_files_attribute_e_normal;
	template_file = mk_win_base_handle_get_null();
	file_handle = mk_win_dll_kernel_files_a_create_file(file_name, desired_access, share_mode, security_attributes, creation_disposition, flags_and_attributes, template_file); mk_lang_check_return(!mk_win_base_handle_is_invalid(file_handle));
	logger->m_file_handle = file_handle;
	gle = mk_win_dll_kernel_errors_get_last();
	*already_existed = gle == mk_win_dll_kernel_errors_id_e_already_exists;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_construct(mk_sl_logger_html_pt const logger, mk_lang_types_pchar_pct const file_name) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t already_existed;

	mk_lang_assert(logger);
	mk_lang_assert(file_name);
	mk_lang_assert(file_name[0] != '\0');

	err = mk_sl_logger_html_prrw_open_file(logger, file_name, &already_existed); mk_lang_check_rereturn(err);
	if(!already_existed)
	{
		err = mk_sl_logger_html_prrw_write_document_header(logger); mk_lang_check_rereturn(err);
		err = mk_sl_logger_html_prrw_write_document_footer(logger); mk_lang_check_rereturn(err);
	}
	err = mk_sl_logger_html_prrw_move_in_front_of_document_footer(logger); mk_lang_check_rereturn(err);
	err = mk_sl_logger_html_prrw_write_session_header(logger); mk_lang_check_rereturn(err);
	err = mk_sl_logger_html_prrw_write_session_footer(logger); mk_lang_check_rereturn(err);
	err = mk_sl_logger_html_prrw_write_document_footer(logger); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_destroy(mk_sl_logger_html_pt const logger) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(logger);
	mk_lang_assert(!mk_win_base_handle_is_invalid(logger->m_file_handle));

	b = mk_win_dll_kernel_handle_close(logger->m_file_handle); mk_lang_check_return(b != mk_win_base_false);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_begin_line(mk_sl_logger_html_pt const logger) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);
	mk_lang_assert(!mk_win_base_handle_is_invalid(logger->m_file_handle));

	err = mk_sl_logger_html_prrw_move_in_front_of_session_footer(logger); mk_lang_check_rereturn(err);
	err = mk_sl_logger_html_prrw_write_line_header(logger); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_end_line(mk_sl_logger_html_pt const logger) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);
	mk_lang_assert(!mk_win_base_handle_is_invalid(logger->m_file_handle));

	err = mk_sl_logger_html_prrw_write_line_footer(logger); mk_lang_check_rereturn(err);
	err = mk_sl_logger_html_prrw_write_session_footer(logger); mk_lang_check_rereturn(err);
	err = mk_sl_logger_html_prrw_write_document_footer(logger); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_begin_color(mk_sl_logger_html_pt const logger, mk_sl_logger_html_color_text_t const color) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct col_str_buf;
	mk_lang_types_sint_t col_str_len;

	mk_lang_assert(logger);
	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_sl_logger_html_color_text_e_dummy_end);
	mk_lang_assert(!mk_win_base_handle_is_invalid(logger->m_file_handle));

	err = mk_sl_logger_html_prrw_write_color_header_a(logger); mk_lang_check_rereturn(err);
	col_str_buf = mk_sl_logger_html_k_colors_buf[color];
	col_str_len = mk_sl_logger_html_k_colors_len[color];
	err = mk_sl_logger_html_prrw_write_str(logger, col_str_buf, col_str_len); mk_lang_check_rereturn(err);
	err = mk_sl_logger_html_prrw_write_color_header_b(logger); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_end_color(mk_sl_logger_html_pt const logger) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);
	mk_lang_assert(!mk_win_base_handle_is_invalid(logger->m_file_handle));

	err = mk_sl_logger_html_prrw_write_color_footer(logger); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_logger_html_prrw_print(mk_sl_logger_html_pt const logger, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(!mk_win_base_handle_is_invalid(logger->m_file_handle));

	err = mk_sl_logger_html_prrw_write_str(logger, str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_html_rw_construct(mk_sl_logger_html_pt const logger, mk_lang_types_pchar_pct const file_name) mk_lang_noexcept
{
	return mk_sl_logger_html_prrw_construct(logger, file_name);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_html_rw_destroy(mk_sl_logger_html_pt const logger) mk_lang_noexcept
{
	return mk_sl_logger_html_prrw_destroy(logger);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_html_rw_begin_line(mk_sl_logger_html_pt const logger) mk_lang_noexcept
{
	return mk_sl_logger_html_prrw_begin_line(logger);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_html_rw_end_line(mk_sl_logger_html_pt const logger) mk_lang_noexcept
{
	return mk_sl_logger_html_prrw_end_line(logger);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_html_rw_begin_color(mk_sl_logger_html_pt const logger, mk_sl_logger_html_color_text_t const color) mk_lang_noexcept
{
	return mk_sl_logger_html_prrw_begin_color(logger, color);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_html_rw_end_color(mk_sl_logger_html_pt const logger) mk_lang_noexcept
{
	return mk_sl_logger_html_prrw_end_color(logger);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_html_rw_print(mk_sl_logger_html_pt const logger, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_sl_logger_html_prrw_print(logger, str_buf, str_len);
}


#endif
