#include "mk_win_kernel_system_information.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_lang_extern_c mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetVersion(mk_win_base_void_t) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetCurrentDirectoryW(mk_win_base_dword_t, mk_win_base_wchar_lpt) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_system_information_get_version(mk_win_base_void_t) mk_lang_noexcept
{
	mk_win_base_dword_t version;

	version = GetVersion();
	return version;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_system_information_get_current_directory_w(mk_win_base_dword_t const len, mk_win_base_wchar_lpt const str) mk_lang_noexcept
{
	mk_win_base_dword_t r;

	r = GetCurrentDirectoryW(len, str);
	return r;
}
