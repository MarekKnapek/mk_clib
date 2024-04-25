#ifndef mk_include_guard_mk_win_kernel_console
#define mk_include_guard_mk_win_kernel_console


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


enum mk_win_kernel_console_ctrl_event_id_e
{
	mk_win_kernel_console_ctrl_event_id_e_c        = 0,
	mk_win_kernel_console_ctrl_event_id_e_break    = 1,
	mk_win_kernel_console_ctrl_event_id_e_close    = 2,
	mk_win_kernel_console_ctrl_event_id_e_logoff   = 5,
	mk_win_kernel_console_ctrl_event_id_e_shutdown = 6,
	mk_win_kernel_console_ctrl_event_id_e_dummy_end
};
typedef enum mk_win_kernel_console_ctrl_event_id_e mk_win_kernel_console_ctrl_event_id_t;

enum mk_win_kernel_console_std_handle_id_e
{
	mk_win_kernel_console_std_handle_id_e_input  = ((mk_win_base_dword_t)(((mk_win_base_sint_t)(-10)))),
	mk_win_kernel_console_std_handle_id_e_output = ((mk_win_base_dword_t)(((mk_win_base_sint_t)(-11)))),
	mk_win_kernel_console_std_handle_id_e_error  = ((mk_win_base_dword_t)(((mk_win_base_sint_t)(-12)))),
	mk_win_kernel_console_std_handle_id_e_dummy_end = 0
};
typedef enum mk_win_kernel_console_std_handle_id_e mk_win_kernel_console_std_handle_id_t;


typedef mk_win_base_bool_t(mk_win_base_far mk_win_base_stdcall*mk_win_kernel_console_handler_lpt)(mk_win_base_dword_t const type) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_console_set_ctrl_handler(mk_win_kernel_console_handler_lpt const handler, mk_win_base_bool_t const add) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_console_get_std_handle(mk_win_kernel_console_std_handle_id_t const handle_id) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_console_a_write(mk_win_base_handle_t const handle, mk_win_base_pchar_lpct const buff, mk_win_base_dword_t const len, mk_win_base_dword_lpt const nwritten, mk_win_base_void_lpt const reserved) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_console_w_write(mk_win_base_handle_t const handle, mk_win_base_wchar_lpct const buff, mk_win_base_dword_t const len, mk_win_base_dword_lpt const nwritten, mk_win_base_void_lpt const reserved) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_console.c"
#endif
#endif
