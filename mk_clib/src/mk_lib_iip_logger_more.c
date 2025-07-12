#ifndef mk_include_guard_mk_lib_iip_logger_more_c
#define mk_include_guard_mk_lib_iip_logger_more_c
#include "mk_lib_iip_logger_more.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_logger.h"
#include "mk_sl_time.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_logger_prrw_append_current_time(mk_lib_iip_logger_pt const logger) mk_lang_noexcept
{
	mk_sl_time_timestamp_t time_val;
	mk_lang_types_sint_t time_len;
	mk_lang_types_pchar_t time_str[mk_sl_time_k_str_len];
	mk_lang_types_sint_t err;

	mk_lang_assert(logger);

	mk_sl_time_timestamp_get_now(&time_val);
	time_len = mk_sl_time_to_text(&time_val, &time_str[0], mk_lang_countof(time_str)); mk_lang_assert(time_len == mk_lang_countof(time_str));
	{
		err = mk_lib_iip_logger_rw_begin_color(logger, mk_lib_iip_logger_color_text_e_dark_magenta); mk_lang_check_rereturn(err);
		err = mk_lib_iip_logger_rw_print(logger, &time_str[0], time_len); mk_lang_check_rereturn(err);
		err = mk_lib_iip_logger_rw_end_color(logger); mk_lang_check_rereturn(err);
		err = mk_lib_iip_logger_rw_print_str_lit(logger, " "); mk_lang_check_rereturn(err);
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_logger_rw_append_current_time(mk_lib_iip_logger_pt const logger) mk_lang_noexcept
{
	return mk_lib_iip_logger_prrw_append_current_time(logger);
}


#endif
