#ifndef mk_include_guard_mk_sl_logger_stdout_h
#define mk_include_guard_mk_sl_logger_stdout_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


enum mk_sl_logger_stdout_color_text_e
{
	mk_sl_logger_stdout_color_text_e_dark_black,
	mk_sl_logger_stdout_color_text_e_dark_red,
	mk_sl_logger_stdout_color_text_e_dark_green,
	mk_sl_logger_stdout_color_text_e_dark_blue,
	mk_sl_logger_stdout_color_text_e_dark_yellow,
	mk_sl_logger_stdout_color_text_e_dark_magenta,
	mk_sl_logger_stdout_color_text_e_dark_cyan,
	mk_sl_logger_stdout_color_text_e_dark_white,
	mk_sl_logger_stdout_color_text_e_light_black,
	mk_sl_logger_stdout_color_text_e_light_red,
	mk_sl_logger_stdout_color_text_e_light_green,
	mk_sl_logger_stdout_color_text_e_light_blue,
	mk_sl_logger_stdout_color_text_e_light_yellow,
	mk_sl_logger_stdout_color_text_e_light_magenta,
	mk_sl_logger_stdout_color_text_e_light_cyan,
	mk_sl_logger_stdout_color_text_e_light_white,
	mk_sl_logger_stdout_color_text_e_dummy_end
};
typedef enum mk_sl_logger_stdout_color_text_e mk_sl_logger_stdout_color_text_t;


struct mk_sl_logger_stdout_s
{
	mk_sl_logger_stdout_color_text_t m_color;
};
typedef struct mk_sl_logger_stdout_s mk_sl_logger_stdout_t;
mk_lang_typedef(mk_sl_logger_stdout);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_stdout_rw_construct(mk_sl_logger_stdout_pt const logger) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_stdout_rw_destroy(mk_sl_logger_stdout_pt const logger) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_stdout_rw_begin_line(mk_sl_logger_stdout_pt const logger) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_stdout_rw_end_line(mk_sl_logger_stdout_pt const logger) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_stdout_rw_begin_color(mk_sl_logger_stdout_pt const logger, mk_sl_logger_stdout_color_text_t const color) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_stdout_rw_end_color(mk_sl_logger_stdout_pt const logger) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_logger_stdout_rw_print(mk_sl_logger_stdout_pt const logger, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
#define mk_sl_logger_stdout_rw_print_str_lit(logger, str_lit) mk_sl_logger_stdout_rw_print((logger), &(str_lit)[0], mk_lang_countstr((str_lit)))


#if mk_lang_jumbo_have
#include "mk_sl_logger_stdout.c"
#endif
#endif
