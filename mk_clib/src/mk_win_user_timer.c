#include "mk_win_user_timer.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_user_window.h"


mk_win_base_dll_import mk_win_base_uintptr_t mk_win_base_stdcall SetTimer(mk_win_user_window_t, mk_win_base_uintptr_t, mk_win_base_uint_t, mk_win_user_timer_proc_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall KillTimer(mk_win_user_window_t, mk_win_base_uintptr_t) mk_lang_noexcept;


mk_lang_jumbo mk_win_base_uintptr_t mk_win_user_timer_set(mk_win_user_window_t const window, mk_win_base_uintptr_t const id, mk_win_base_uint_t const timeout, mk_win_user_timer_proc_t const proc) mk_lang_noexcept
{
	mk_win_base_uintptr_t id_out;

	id_out = SetTimer(window, id, timeout, proc);
	return id_out;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_user_timer_kill(mk_win_user_window_t const window, mk_win_base_uintptr_t const id) mk_lang_noexcept
{
	mk_win_base_bool_t killed;

	killed = KillTimer(window, id);
	return killed;
}
