#ifndef mk_include_guard_mk_lib_iip_logger_more_h
#define mk_include_guard_mk_lib_iip_logger_more_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_lib_iip_logger);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_logger_rw_append_current_time(mk_lib_iip_logger_pt const logger) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_iip_logger_more.c"
#endif
#endif
