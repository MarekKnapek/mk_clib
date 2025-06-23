#ifndef mk_include_guard_mk_win_dll_kernel_console_h
#define mk_include_guard_mk_win_dll_kernel_console_h


#include "mk_lang_jumbo.h"
#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any


#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


enum mk_win_dll_kernel_console_ctrl_event_id_e
{
	mk_win_dll_kernel_console_ctrl_event_id_e_c        = 0,
	mk_win_dll_kernel_console_ctrl_event_id_e_break    = 1,
	mk_win_dll_kernel_console_ctrl_event_id_e_close    = 2,
	mk_win_dll_kernel_console_ctrl_event_id_e_logoff   = 5,
	mk_win_dll_kernel_console_ctrl_event_id_e_shutdown = 6,
	mk_win_dll_kernel_console_ctrl_event_id_e_dummy_end
};
typedef enum mk_win_dll_kernel_console_ctrl_event_id_e mk_win_dll_kernel_console_ctrl_event_id_t;

#include "mk_lang_warning_gcc_push_enumenator.h"
enum mk_win_dll_kernel_console_std_handle_id_e
{
	mk_win_dll_kernel_console_std_handle_id_e_input  = ((mk_win_base_dword_t)(((mk_win_base_sint_t)(-10)))),
	mk_win_dll_kernel_console_std_handle_id_e_output = ((mk_win_base_dword_t)(((mk_win_base_sint_t)(-11)))),
	mk_win_dll_kernel_console_std_handle_id_e_error  = ((mk_win_base_dword_t)(((mk_win_base_sint_t)(-12)))),
	mk_win_dll_kernel_console_std_handle_id_e_dummy_end = 0
};
typedef enum mk_win_dll_kernel_console_std_handle_id_e mk_win_dll_kernel_console_std_handle_id_t;
#include "mk_lang_warning_gcc_pop.h"

enum mk_win_dll_kernel_console_attribute_e
{
	mk_win_dll_kernel_console_attribute_e_foreground_blue            = 0x0001,
	mk_win_dll_kernel_console_attribute_e_foreground_green           = 0x0002,
	mk_win_dll_kernel_console_attribute_e_foreground_red             = 0x0004,
	mk_win_dll_kernel_console_attribute_e_foreground_intensity       = 0x0008,
	mk_win_dll_kernel_console_attribute_e_background_blue            = 0x0010,
	mk_win_dll_kernel_console_attribute_e_background_green           = 0x0020,
	mk_win_dll_kernel_console_attribute_e_background_red             = 0x0040,
	mk_win_dll_kernel_console_attribute_e_background_intensity       = 0x0080,
	mk_win_dll_kernel_console_attribute_e_common_lvb_leading_byte    = 0x0100,
	mk_win_dll_kernel_console_attribute_e_common_lvb_trailing_byte   = 0x0200,
	mk_win_dll_kernel_console_attribute_e_common_lvb_sbcsdbcs        = 0x0300,
	mk_win_dll_kernel_console_attribute_e_common_lvb_grid_horizontal = 0x0400,
	mk_win_dll_kernel_console_attribute_e_common_lvb_grid_lvertical  = 0x0800,
	mk_win_dll_kernel_console_attribute_e_common_lvb_grid_rvertical  = 0x1000,
	mk_win_dll_kernel_console_attribute_e_common_lvb_reverse_video   = 0x4000,
	mk_win_dll_kernel_console_attribute_e_common_lvb_underscore      = 0x8000,
	mk_win_dll_kernel_console_attribute_e_dummy_end = 0xffff
};
typedef enum mk_win_dll_kernel_console_attribute_e mk_win_dll_kernel_console_attribute_t;


typedef mk_win_base_bool_t(mk_win_base_far mk_win_base_stdcall*mk_win_dll_kernel_console_handler_t)(mk_win_base_dword_t const type) mk_lang_noexcept;


struct mk_win_dll_kernel_console_console_screen_buffer_info_s
{
	mk_win_base_coord_t m_size;
	mk_win_base_coord_t m_cursor_position;
	mk_win_base_word_t m_attributes;
	mk_win_base_smallrect_t m_window;
	mk_win_base_coord_t m_maximum_window_size;
};
typedef struct mk_win_dll_kernel_console_console_screen_buffer_info_s mk_win_dll_kernel_console_console_screen_buffer_info_t;
mk_lang_typedef(mk_win_dll_kernel_console_console_screen_buffer_info);


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_console_set_ctrl_handler(mk_win_dll_kernel_console_handler_t const handler, mk_win_base_bool_t const add) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_dll_kernel_console_get_std_handle(mk_win_dll_kernel_console_std_handle_id_t const handle_id) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_console_get_mode(mk_win_base_handle_t const handle, mk_win_base_dword_lpt const mode) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_console_a_write(mk_win_base_handle_t const handle, mk_win_base_pchar_lpct const buff, mk_win_base_dword_t const len, mk_win_base_dword_lpt const nwritten, mk_win_base_void_lpt const reserved) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_console_w_write(mk_win_base_handle_t const handle, mk_win_base_wchar_lpct const buff, mk_win_base_dword_t const len, mk_win_base_dword_lpt const nwritten, mk_win_base_void_lpt const reserved) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_console_get_console_screen_buffer_info(mk_win_base_handle_t const handle, mk_win_dll_kernel_console_console_screen_buffer_info_pt const console_screen_buffer_info) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_console_set_console_text_attribute(mk_win_base_handle_t const handle, mk_win_base_word_t const attributes) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_win_dll_kernel_console.c"
#endif
#endif
