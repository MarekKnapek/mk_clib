#include "mk_win_user_msg.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_user_base.h"
#include "mk_win_user_menu.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetMessageW(mk_win_user_msg_lpt const msg, mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t fmin, mk_win_base_uint_t const fmax) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall PeekMessageW(mk_win_user_msg_lpt const msg, mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t fmin, mk_win_base_uint_t const fmax, mk_win_base_uint_t const remove) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall TranslateMessage(mk_win_user_msg_lpct const msg) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_base_lresult_t mk_win_base_stdcall DispatchMessageW(mk_win_user_msg_lpct const msg) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall PostQuitMessage(mk_win_base_sint_t const exit_code) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_msg_w_get(mk_win_user_msg_lpt const msg, mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t fmin, mk_win_base_uint_t const fmax) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = GetMessageW(msg, wnd, fmin, fmax);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_msg_w_peek(mk_win_user_msg_lpt const msg, mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t fmin, mk_win_base_uint_t const fmax, mk_win_base_uint_t const remove) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = PeekMessageW(msg, wnd, fmin, fmax, remove);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_msg_translate(mk_win_user_msg_lpct const msg) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = TranslateMessage(msg);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_lresult_t mk_win_user_msg_w_dispatch(mk_win_user_msg_lpct const msg) mk_lang_noexcept
{
	mk_win_user_base_lresult_t ret;

	ret = DispatchMessageW(msg);
	return ret;
}

mk_lang_jumbo mk_lang_types_void_t mk_win_user_msg_post_quit(mk_win_base_sint_t const exit_code) mk_lang_noexcept
{
	PostQuitMessage(exit_code);
}
