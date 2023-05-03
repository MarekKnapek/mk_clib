#include "mk_win_kernel_system_information.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetVersion(void) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_system_information_get_version(void) mk_lang_noexcept
{
	mk_win_base_dword_t version;

	version = GetVersion();
	return version;
}
