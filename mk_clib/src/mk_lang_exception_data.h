#ifndef mk_include_guard_mk_lang_exception_data
#define mk_include_guard_mk_lang_exception_data


#include "mk_lang_exception_out_of_memory.h"
#include "mk_lang_jumbo.h"
#include "mk_win_sl_exception_gle.h"


union mk_lang_exception_data_u
{
	mk_lang_exception_out_of_memory_t m_out_of_memory;
	mk_win_sl_exception_gle_t m_win_gle;
};
typedef union mk_lang_exception_data_u mk_lang_exception_data_t;
typedef mk_lang_exception_data_t const mk_lang_exception_data_ct;
typedef mk_lang_exception_data_t* mk_lang_exception_data_pt;
typedef mk_lang_exception_data_t const* mk_lang_exception_data_pct;


#if mk_lang_jumbo_want == 1
#include "mk_lang_exception_data.c"
#endif
#endif
