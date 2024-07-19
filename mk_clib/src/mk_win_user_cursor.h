#ifndef mk_include_guard_mk_win_user_cursor
#define mk_include_guard_mk_win_user_cursor


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_win_base_make_handle(mk_win_user_cursor)

enum mk_win_user_cursor_id_e
{
	mk_win_user_cursor_id_e_arrow       = 32512,
	mk_win_user_cursor_id_e_ibeam       = 32513,
	mk_win_user_cursor_id_e_wait        = 32514,
	mk_win_user_cursor_id_e_cross       = 32515,
	mk_win_user_cursor_id_e_uparrow     = 32516,
	mk_win_user_cursor_id_e_size        = 32640, /* obsolete: use sizeall */
	mk_win_user_cursor_id_e_icon        = 32641, /* obsolete: use arrow */
	mk_win_user_cursor_id_e_sizenwse    = 32642,
	mk_win_user_cursor_id_e_sizenesw    = 32643,
	mk_win_user_cursor_id_e_sizewe      = 32644,
	mk_win_user_cursor_id_e_sizens      = 32645,
	mk_win_user_cursor_id_e_sizeall     = 32646,
	mk_win_user_cursor_id_e_no          = 32648, /* not in win3.1 */
	mk_win_user_cursor_id_e_hand        = 32649, /* winver >= 0x0500 */
	mk_win_user_cursor_id_e_appstarting = 32650, /* not in win3.1 */
	mk_win_user_cursor_id_e_help        = 32651, /* winver >= 0x0400 */
	mk_win_user_cursor_id_e_pin         = 32671, /* winver >= 0x0606 */
	mk_win_user_cursor_id_e_person      = 32672, /* winver >= 0x0606 */
	mk_win_user_cursor_id_e_dummy_end
};
typedef enum mk_win_user_cursor_id_e mk_win_user_cursor_id_t;


mk_lang_nodiscard mk_lang_jumbo mk_win_user_cursor_t mk_win_user_cursor_a_load(mk_win_base_instance_t const instance, mk_win_base_pchar_lpct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_cursor_t mk_win_user_cursor_w_load(mk_win_base_instance_t const instance, mk_win_base_wchar_lpct const name) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_cursor.c"
#endif
#endif
