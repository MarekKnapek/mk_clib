#include "mk_win_kernel_system_information.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_lang_extern_c mk_win_base_dll_import mk_win_base_void_t mk_win_base_stdcall GetSystemInfo(mk_win_kernel_system_information_pt const info) mk_lang_noexcept;


mk_lang_jumbo mk_win_base_void_t mk_win_kernel_system_information_get(mk_win_kernel_system_information_pt const info) mk_lang_noexcept
{
	mk_lang_assert(info);

	GetSystemInfo(info);
}
