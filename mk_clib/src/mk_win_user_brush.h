#ifndef mk_include_guard_mk_win_user_brush
#define mk_include_guard_mk_win_user_brush


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_user_base.h"


enum mk_win_user_brush_id_e
{
	mk_win_user_brush_id_e_application = 32512,
	mk_win_user_brush_id_e_hand        = 32513,
	mk_win_user_brush_id_e_question    = 32514,
	mk_win_user_brush_id_e_exclamation = 32515,
	mk_win_user_brush_id_e_asterisk    = 32516,
	mk_win_user_brush_id_e_winlogo     = 32517, /* winver >= 0x0400 */
	mk_win_user_brush_id_e_shield      = 32518, /* winver >= 0x0600 */
	mk_win_user_brush_id_e_dummy_end
};
typedef enum mk_win_user_brush_id_e mk_win_user_brush_id_t;


mk_lang_nodiscard mk_lang_jumbo mk_win_user_brush_t mk_win_user_brush_from_color_id(mk_win_user_base_color_id_t const color_id) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_brush_t mk_win_user_brush_from_color_idx(mk_win_base_sint_t const color_idx) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_brush.c"
#endif
#endif
