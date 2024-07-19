#include "mk_win_user_base.h"

#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetSysColor(mk_win_base_sint_t const color_idx) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_user_base_get_sys_color(mk_win_base_sint_t const color_idx) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	ret = GetSysColor(color_idx);
	return ret;
}
