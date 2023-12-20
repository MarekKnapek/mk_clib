#ifndef mk_include_guard_mk_win_kernel_time
#define mk_include_guard_mk_win_kernel_time


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


struct mk_win_kernel_time_system_time_s
{
	mk_win_base_word_t m_year;
	mk_win_base_word_t m_month;
	mk_win_base_word_t m_day_of_week;
	mk_win_base_word_t m_day;
	mk_win_base_word_t m_hour;
	mk_win_base_word_t m_minute;
	mk_win_base_word_t m_second;
	mk_win_base_word_t m_millisecond;
};
typedef struct mk_win_kernel_time_system_time_s mk_win_kernel_time_system_time_t;
typedef mk_win_kernel_time_system_time_t const mk_win_kernel_time_system_time_ct;
typedef mk_win_kernel_time_system_time_t* mk_win_kernel_time_system_time_pt;
typedef mk_win_kernel_time_system_time_t const* mk_win_kernel_time_system_time_pct;
typedef mk_win_kernel_time_system_time_t mk_win_base_far* mk_win_kernel_time_system_time_lpt;
typedef mk_win_kernel_time_system_time_t mk_win_base_far const* mk_win_kernel_time_system_time_lpct;
typedef mk_win_kernel_time_system_time_t mk_win_base_near* mk_win_kernel_time_system_time_npt;
typedef mk_win_kernel_time_system_time_t mk_win_base_near const* mk_win_kernel_time_system_time_npct;

struct mk_win_kernel_time_file_time_s
{
	mk_win_base_dword_t m_lo;
	mk_win_base_dword_t m_hi;
};
typedef struct mk_win_kernel_time_file_time_s mk_win_kernel_time_file_time_t;
typedef mk_win_kernel_time_file_time_t const mk_win_kernel_time_file_time_ct;
typedef mk_win_kernel_time_file_time_t* mk_win_kernel_time_file_time_pt;
typedef mk_win_kernel_time_file_time_t const* mk_win_kernel_time_file_time_pct;
typedef mk_win_kernel_time_file_time_t mk_win_base_far* mk_win_kernel_time_file_time_lpt;
typedef mk_win_kernel_time_file_time_t mk_win_base_far const* mk_win_kernel_time_file_time_lpct;
typedef mk_win_kernel_time_file_time_t mk_win_base_near* mk_win_kernel_time_file_time_npt;
typedef mk_win_kernel_time_file_time_t mk_win_base_near const* mk_win_kernel_time_file_time_npct;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_time_get_tick_count(void) mk_lang_noexcept;
mk_lang_jumbo void mk_win_kernel_time_get_system_time(mk_win_kernel_time_system_time_pt const system_time) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_time_system_to_file_time(mk_win_kernel_time_system_time_pct const system_time, mk_win_kernel_time_file_time_pt const file_time) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_time_file_to_system_time(mk_win_kernel_time_file_time_pct const file_time, mk_win_kernel_time_system_time_pt const system_time) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_time.c"
#endif
#endif
