#include "mk_win_user_brush.h"

#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_user_base.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_user_brush_t mk_win_base_stdcall GetSysColorBrush(mk_win_base_sint_t const color_idx) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_user_brush_t mk_win_user_brush_from_color_id(mk_win_user_base_color_id_t const color_id) mk_lang_noexcept
{
	mk_win_user_brush_t ret;

	ret.m_data = ((mk_win_base_void_pct)(((mk_win_base_uintptr_t)(((mk_win_base_uint_t)(((mk_win_base_sint_t)(color_id)) + 1))))));
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_user_brush_t mk_win_user_brush_from_color_idx(mk_win_base_sint_t const color_idx) mk_lang_noexcept
{
	mk_win_user_brush_t ret;

	ret = GetSysColorBrush(color_idx);
	return ret;
}
