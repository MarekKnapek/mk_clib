#include "mk_win_user_todo.h"

#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SystemParametersInfoW(mk_win_base_uint_t const action, mk_win_base_uint_t const param, mk_win_base_void_pt const buf, mk_win_base_uint_t const ini) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_font_t mk_win_base_stdcall CreateFontIndirectW(mk_win_user_todo_logfont_pct const logfont) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_todo_w_system_parameters_info(mk_win_base_uint_t const action, mk_win_base_uint_t const param, mk_win_base_void_pt const buf, mk_win_base_uint_t const ini) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = SystemParametersInfoW(action, param, buf, ini);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_font_t mk_win_user_todo_w_create_font_indirect(mk_win_user_todo_logfont_pct const logfont) mk_lang_noexcept
{
	mk_win_user_font_t ret;

	ret = CreateFontIndirectW(logfont);
	return ret;
}
