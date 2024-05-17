#include "mk_win_kernel_thread.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_advapi_types.h"
#include "mk_win_base.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateThread(mk_win_advapi_base_security_attributes_lpct const sa, mk_win_base_usize_t const stack_len, mk_win_kernel_thread_callback_t const callback, mk_win_base_void_lpt const parameter, mk_win_base_dword_t const flags, mk_win_base_dword_lpt const tid) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_thread_create(mk_win_advapi_base_security_attributes_lpct const sa, mk_win_base_usize_t const stack_len, mk_win_kernel_thread_callback_t const callback, mk_win_base_void_lpt const parameter, mk_win_base_dword_t const flags, mk_win_base_dword_lpt const tid) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	mk_lang_assert(callback);

	ret = CreateThread(sa, stack_len, callback, parameter, flags, tid);
	return ret;
}
