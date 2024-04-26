#include "mk_win_kernel_errors.h"

#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetLastError(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall SetLastError(mk_win_base_dword_t) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_uint_t mk_win_base_stdcall SetErrorMode(mk_win_base_uint_t) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_errors_get_last(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_dword_t err;

	err = GetLastError();
	return err;
}

mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_errors_set_last(mk_win_base_dword_t const err) mk_lang_noexcept
{
	SetLastError(err);
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_uint_t mk_win_kernel_errors_set_errmode(mk_win_base_uint_t const errmode) mk_lang_noexcept
{
	mk_win_base_uint_t prev;

	prev = SetErrorMode(errmode);
	return prev;
}
