#include "mk_win_user_scroll_bars.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall ShowScrollBar(mk_win_user_window_t, int, mk_win_base_bool_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall EnableScrollBar(mk_win_user_window_t, mk_win_base_uint_t, mk_win_base_uint_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SetScrollRange(mk_win_user_window_t, int, int, int, mk_win_base_bool_t) mk_lang_noexcept;
mk_win_base_dll_import int mk_win_base_stdcall SetScrollPos(mk_win_user_window_t, int, int, mk_win_base_bool_t) mk_lang_noexcept;
mk_win_base_dll_import int mk_win_base_stdcall GetScrollPos(mk_win_user_window_t, int) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall ScrollWindow(mk_win_user_window_t, int, int, mk_win_base_rect_lpct, mk_win_base_rect_lpct) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_scroll_bars_show(mk_win_user_window_t const window, mk_win_user_scroll_bars_id_t const id, mk_win_base_bool_t const show) mk_lang_noexcept
{
	mk_win_base_bool_t shown;

	shown = ShowScrollBar(window, ((int)(id)), show);
	return shown;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_scroll_bars_enable(mk_win_user_window_t const window, mk_win_user_scroll_bars_id_t const id, mk_win_user_scroll_bars_enable_t const arrows) mk_lang_noexcept
{
	mk_win_base_bool_t enabled;

	enabled = EnableScrollBar(window, ((mk_win_base_uint_t)(id)), ((mk_win_base_uint_t)(arrows)));
	return enabled;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_scroll_bars_set_range(mk_win_user_window_t const window, mk_win_user_scroll_bars_id_t const id, int const min, int const max, mk_win_base_bool_t const redraw) mk_lang_noexcept
{
	mk_win_base_bool_t set;

	set = SetScrollRange(window, ((int)(id)), min, max, redraw);
	return set;
}

mk_lang_nodiscard mk_lang_jumbo int mk_win_user_scroll_bars_set_pos(mk_win_user_window_t const window, mk_win_user_scroll_bars_id_t const id, int const pos, mk_win_base_bool_t const redraw) mk_lang_noexcept
{
	int set;

	set = SetScrollPos(window, ((int)(id)), pos, redraw);
	return set;
}

mk_lang_nodiscard mk_lang_jumbo int mk_win_user_scroll_bars_get_pos(mk_win_user_window_t const window, mk_win_user_scroll_bars_id_t const id) mk_lang_noexcept
{
	int pos;

	pos = GetScrollPos(window, ((int)(id)));
	return pos;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_scroll_bars_scroll_window(mk_win_user_window_t const window, int const dx, int const dy, mk_win_base_rect_lpct const scroll, mk_win_base_rect_lpct const clip) mk_lang_noexcept
{
	mk_win_base_bool_t scrolled;

	scrolled = ScrollWindow(window, dx, dy, scroll, clip);
	return scrolled;
}
