#ifndef include_guard_mk_win_user_scroll_bars
#define include_guard_mk_win_user_scroll_bars


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


enum mk_win_user_scroll_bars_id_e
{
	mk_win_user_scroll_bars_id_e_horz = 0,
	mk_win_user_scroll_bars_id_e_vert = 1,
	mk_win_user_scroll_bars_id_e_ctl  = 2,
	mk_win_user_scroll_bars_id_e_both = 3,
	mk_win_user_scroll_bars_id_e_dummy_end = 0
};
typedef enum mk_win_user_scroll_bars_id_e mk_win_user_scroll_bars_id_t;

enum mk_win_user_scroll_bars_enable_e
{
	mk_win_user_scroll_bars_enable_e_enable_both   = 0,
	mk_win_user_scroll_bars_enable_e_disable_left  = 1,
	mk_win_user_scroll_bars_enable_e_disable_up    = 1,
	mk_win_user_scroll_bars_enable_e_disable_right = 2,
	mk_win_user_scroll_bars_enable_e_disable_down  = 2,
	mk_win_user_scroll_bars_enable_e_disable_both  = 3,
	mk_win_user_scroll_bars_enable_e_disable_ltup  = mk_win_user_scroll_bars_enable_e_disable_left,
	mk_win_user_scroll_bars_enable_e_disable_rtdn  = mk_win_user_scroll_bars_enable_e_disable_right,
	mk_win_user_scroll_bars_enable_e_dummy_end = 0
};
typedef enum mk_win_user_scroll_bars_enable_e mk_win_user_scroll_bars_enable_t;

enum mk_win_user_scroll_bars_event_e
{
	mk_win_user_scroll_bars_event_e_lineleft      = 0,
	mk_win_user_scroll_bars_event_e_lineup        = 0,
	mk_win_user_scroll_bars_event_e_lineright     = 1,
	mk_win_user_scroll_bars_event_e_linedown      = 1,
	mk_win_user_scroll_bars_event_e_pageleft      = 2,
	mk_win_user_scroll_bars_event_e_pageup        = 2,
	mk_win_user_scroll_bars_event_e_pageright     = 3,
	mk_win_user_scroll_bars_event_e_pagedown      = 3,
	mk_win_user_scroll_bars_event_e_thumbposition = 4,
	mk_win_user_scroll_bars_event_e_thumbtrack    = 5,
	mk_win_user_scroll_bars_event_e_left          = 6,
	mk_win_user_scroll_bars_event_e_top           = 6,
	mk_win_user_scroll_bars_event_e_right         = 7,
	mk_win_user_scroll_bars_event_e_bottom        = 7,
	mk_win_user_scroll_bars_event_e_endscroll     = 8,
	mk_win_user_scroll_bars_event_e_dummy_end = 0
};
typedef enum mk_win_user_scroll_bars_event_e mk_win_user_scroll_bars_event_t;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_scroll_bars_show(mk_win_user_window_t const window, mk_win_user_scroll_bars_id_t const id, mk_win_base_bool_t const show) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_scroll_bars_enable(mk_win_user_window_t const window, mk_win_user_scroll_bars_id_t const id, mk_win_user_scroll_bars_enable_t const arrows) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_scroll_bars_set_range(mk_win_user_window_t const window, mk_win_user_scroll_bars_id_t const id, int const min, int const max, mk_win_base_bool_t const redraw) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo int mk_win_user_scroll_bars_set_pos(mk_win_user_window_t const window, mk_win_user_scroll_bars_id_t const id, int const pos, mk_win_base_bool_t const redraw) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo int mk_win_user_scroll_bars_get_pos(mk_win_user_window_t const window, mk_win_user_scroll_bars_id_t const id) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_scroll_bars_scroll_window(mk_win_user_window_t const window, int const dx, int const dy, mk_win_base_rect_lpct const scroll, mk_win_base_rect_lpct const clip) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_scroll_bars.c"
#endif
#endif
