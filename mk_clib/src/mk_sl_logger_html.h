#ifndef mk_include_guard_mk_sl_logger_html_h
#define mk_include_guard_mk_sl_logger_html_h


#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


enum mk_sl_logger_html_color_text_e
{
	mk_sl_logger_html_color_text_e_dark_black,
	mk_sl_logger_html_color_text_e_dark_red,
	mk_sl_logger_html_color_text_e_dark_green,
	mk_sl_logger_html_color_text_e_dark_blue,
	mk_sl_logger_html_color_text_e_dark_yellow,
	mk_sl_logger_html_color_text_e_dark_magenta,
	mk_sl_logger_html_color_text_e_dark_cyan,
	mk_sl_logger_html_color_text_e_dark_white,
	mk_sl_logger_html_color_text_e_light_black,
	mk_sl_logger_html_color_text_e_light_red,
	mk_sl_logger_html_color_text_e_light_green,
	mk_sl_logger_html_color_text_e_light_blue,
	mk_sl_logger_html_color_text_e_light_yellow,
	mk_sl_logger_html_color_text_e_light_magenta,
	mk_sl_logger_html_color_text_e_light_cyan,
	mk_sl_logger_html_color_text_e_light_white,
	mk_sl_logger_html_color_text_e_dummy_end
};
typedef enum mk_sl_logger_html_color_text_e mk_sl_logger_html_color_text_t;


struct mk_sl_logger_html_s
{
	mk_win_base_handle_t m_file_handle;
};
typedef struct mk_sl_logger_html_s mk_sl_logger_html_t;
mk_lang_typedef(mk_sl_logger_html);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_html_rw_construct(mk_sl_logger_html_pt const logger, mk_lang_types_pchar_pct const file_name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_html_rw_destroy(mk_sl_logger_html_pt const logger) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_html_rw_begin_line(mk_sl_logger_html_pt const logger) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_html_rw_end_line(mk_sl_logger_html_pt const logger) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_html_rw_begin_color(mk_sl_logger_html_pt const logger, mk_sl_logger_html_color_text_t const color) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_html_rw_end_color(mk_sl_logger_html_pt const logger) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_html_rw_print(mk_sl_logger_html_pt const logger, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
#define mk_sl_logger_html_rw_print_str_lit(logger, str_lit) mk_sl_logger_html_rw_print((logger), &(str_lit)[0], mk_lang_countstr((str_lit)))


#if mk_lang_jumbo_have
#include "mk_sl_logger_html.c"
#endif
#endif
