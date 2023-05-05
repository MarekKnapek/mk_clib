#include "mk_win_user_brush.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_kernel_dll.h"
#include "mk_win_user_color.h"


mk_win_base_dll_import mk_win_user_brush_t mk_win_base_stdcall GetSysColorBrush(int) mk_lang_noexcept;


typedef mk_win_user_brush_t(mk_win_base_far mk_win_base_stdcall*mk_win_user_brush_GetSysColorBrush)(int) mk_lang_noexcept;


static mk_win_base_proc_t g_mk_win_user_brush_GetSysColorBrush;


mk_lang_nodiscard mk_lang_jumbo mk_win_user_brush_t mk_win_user_brush_get_syscolor(mk_win_user_color_id_t const color_id) mk_lang_noexcept
{
	#if defined _MSC_VER && _MSC_VER == 1935
	#pragma warning(push)
	#pragma warning(disable:4191) /* warning C4191: 'type cast': unsafe conversion from 'xxx' to 'xxx' */
	#endif

	mk_win_user_brush_t brush;

	if(!g_mk_win_user_brush_GetSysColorBrush)
	{
		g_mk_win_user_brush_GetSysColorBrush = mk_win_kernel_dll_get_proc_address(mk_win_kernel_dll_t_get_handle(mk_win_tstring_tchar_c("user32")), "GetSysColorBrush");
		if(!g_mk_win_user_brush_GetSysColorBrush)
		{
			g_mk_win_user_brush_GetSysColorBrush = mk_win_base_proc_not_found;
		}
	}
	mk_lang_assert(g_mk_win_user_brush_GetSysColorBrush);
	if(g_mk_win_user_brush_GetSysColorBrush != mk_win_base_proc_not_found)
	{
		brush = ((mk_win_user_brush_GetSysColorBrush)(g_mk_win_user_brush_GetSysColorBrush))(((int)(color_id)));
	}
	else
	{
		/* todo get color and create solid brush? get stock object? wite / black brush? */
		brush = ((mk_win_user_brush_t)(((mk_win_base_uintptr_t)(color_id + 1))));
	}
	return brush;

	#if defined _MSC_VER && _MSC_VER == 1935
	#pragma warning(pop)
	#endif
}
