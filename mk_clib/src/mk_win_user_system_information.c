#include "mk_win_user_system_information.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_user_color.h"


mk_lang_extern_c mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetSysColor(int) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_user_system_information_get_color(mk_win_user_color_id_t const color_id) mk_lang_noexcept
{
	mk_win_base_dword_t color;

	color = GetSysColor(((int)(color_id)));
	return color;
}
