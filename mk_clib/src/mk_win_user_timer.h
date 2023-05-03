#ifndef mk_include_guard_win_user_timer
#define mk_include_guard_win_user_timer


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_user_window.h"


typedef void(mk_win_base_stdcall*mk_win_user_timer_proc_t)(mk_win_user_window_t const window, mk_win_base_uint_t const msg, mk_win_base_uintptr_t const id, mk_win_base_dword_t const time) mk_lang_noexcept;


mk_lang_jumbo mk_win_base_uintptr_t mk_win_user_timer_set(mk_win_user_window_t const window, mk_win_base_uintptr_t const id, mk_win_base_uint_t const timeout, mk_win_user_timer_proc_t const proc) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_user_timer_kill(mk_win_user_window_t const window, mk_win_base_uintptr_t const id) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_timer.c"
#endif
#endif
