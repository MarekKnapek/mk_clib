#ifndef include_guard_mk_win_user_brush
#define include_guard_mk_win_user_brush


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_user_color.h"


struct mk_win_user_brush_handle_s; typedef struct mk_win_user_brush_handle_s mk_win_user_brush_handle_t; typedef mk_win_user_brush_handle_t const* mk_win_user_brush_t;


mk_lang_nodiscard mk_lang_jumbo mk_win_user_brush_t mk_win_user_brush_get_syscolor(mk_win_user_color_id_t const color_id) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_brush_t mk_win_user_brush_create_solid(mk_win_base_dword_t const color) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_brush.c"
#endif
#endif
