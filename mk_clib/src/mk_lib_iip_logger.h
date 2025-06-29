#ifndef mk_include_guard_mk_lib_iip_logger_h
#define mk_include_guard_mk_lib_iip_logger_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_logger_html.h"
#include "mk_sl_logger_stdout.h"


enum mk_lib_iip_logger_color_text_e
{
	mk_lib_iip_logger_color_text_e_dark_black,
	mk_lib_iip_logger_color_text_e_dark_red,
	mk_lib_iip_logger_color_text_e_dark_green,
	mk_lib_iip_logger_color_text_e_dark_blue,
	mk_lib_iip_logger_color_text_e_dark_yellow,
	mk_lib_iip_logger_color_text_e_dark_magenta,
	mk_lib_iip_logger_color_text_e_dark_cyan,
	mk_lib_iip_logger_color_text_e_dark_white,
	mk_lib_iip_logger_color_text_e_light_black,
	mk_lib_iip_logger_color_text_e_light_red,
	mk_lib_iip_logger_color_text_e_light_green,
	mk_lib_iip_logger_color_text_e_light_blue,
	mk_lib_iip_logger_color_text_e_light_yellow,
	mk_lib_iip_logger_color_text_e_light_magenta,
	mk_lib_iip_logger_color_text_e_light_cyan,
	mk_lib_iip_logger_color_text_e_light_white,
	mk_lib_iip_logger_color_text_e_dummy_end
};
typedef enum mk_lib_iip_logger_color_text_e mk_lib_iip_logger_color_text_t;


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_logger_s
{
	mk_sl_logger_stdout_t m_logger_stdout;
	mk_sl_logger_html_t m_logger_html;
};
typedef struct mk_lib_iip_logger_s mk_lib_iip_logger_t;
mk_lang_typedef(mk_lib_iip_logger);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_logger_rw_construct(mk_lib_iip_logger_pt const logger, mk_lang_types_pchar_pct const file_name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_logger_rw_destroy(mk_lib_iip_logger_pt const logger) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_logger_rw_begin_line(mk_lib_iip_logger_pt const logger) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_logger_rw_end_line(mk_lib_iip_logger_pt const logger) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_logger_rw_begin_color(mk_lib_iip_logger_pt const logger, mk_lib_iip_logger_color_text_t const color) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_logger_rw_end_color(mk_lib_iip_logger_pt const logger) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_logger_rw_print(mk_lib_iip_logger_pt const logger, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
#define mk_lib_iip_logger_rw_print_str_lit(logger, str_lit) mk_lib_iip_logger_rw_print((logger), &(str_lit)[0], mk_lang_countstr((str_lit)))


#if mk_lang_jumbo_have
#include "mk_lib_iip_logger.c"
#endif
#endif
