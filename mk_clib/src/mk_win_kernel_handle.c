#include "mk_win_kernel_handle.h"

#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall CloseHandle(mk_win_base_handle_t) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_handle_close_handle(mk_win_base_handle_t const handle) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = CloseHandle(handle);
	return ret;
}
