#ifndef mk_include_guard_mk_win_dll_kernel_time_h
#define mk_include_guard_mk_win_dll_kernel_time_h


#include "mk_lang_jumbo.h"
#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any


#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


struct mk_win_dll_kernel_time_system_time_s
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
typedef struct mk_win_dll_kernel_time_system_time_s mk_win_dll_kernel_time_system_time_t;
mk_lang_typedef(mk_win_dll_kernel_time_system_time);

struct mk_win_dll_kernel_time_file_time_s
{
	mk_win_base_dword_t m_lo;
	mk_win_base_dword_t m_hi;
};
typedef struct mk_win_dll_kernel_time_file_time_s mk_win_dll_kernel_time_file_time_t;
mk_lang_typedef(mk_win_dll_kernel_time_file_time);


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_dll_kernel_time_get_tick_count(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_dll_kernel_time_get_system_time(mk_win_dll_kernel_time_system_time_lpt const system_time) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_time_system_to_file_time(mk_win_dll_kernel_time_system_time_lpct const system_time, mk_win_dll_kernel_time_file_time_lpt const file_time) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_time_file_to_system_time(mk_win_dll_kernel_time_file_time_lpct const file_time, mk_win_dll_kernel_time_system_time_lpt const system_time) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_dll_kernel_time_get_system_time_precise_as_file_time(mk_win_dll_kernel_time_file_time_lpt const file_time) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_win_dll_kernel_time.c"
#endif
#endif
