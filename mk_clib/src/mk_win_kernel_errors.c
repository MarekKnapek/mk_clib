#include "mk_win_kernel_errors.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetLastError(void) mk_lang_noexcept;
mk_win_base_dll_import void mk_win_base_stdcall SetLastError(mk_win_base_dword_t) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_errors_get_last(void) mk_lang_noexcept
{
	mk_win_base_dword_t err;

	err = GetLastError();
	return err;
}

mk_lang_jumbo void mk_win_kernel_errors_set_last(mk_win_kernel_errors_id_t const err) mk_lang_noexcept
{
	SetLastError(((mk_win_base_dword_t)(err)));
}
