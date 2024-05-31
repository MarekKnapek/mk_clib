#include "mk_win_kernel_synchronization.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall WaitForSingleObject(mk_win_base_handle_t const object, mk_win_base_dword_t const timeout) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_synchronization_wait_one(mk_win_base_handle_t const object, mk_win_base_dword_t const timeout) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	mk_lang_assert(object.m_data);

	ret = WaitForSingleObject(object, timeout);
	return ret;
}
