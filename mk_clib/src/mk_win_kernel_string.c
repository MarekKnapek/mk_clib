#include "mk_win_kernel_string.h"

#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"

#include <stdarg.h> /* va_list */


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall WideCharToMultiByte(mk_win_base_uint_t const cp, mk_win_base_dword_t const flags, mk_win_base_wchar_lpct const wide_buf, mk_win_base_sint_t const wide_len, mk_win_base_pchar_lpt const ansi_buf, mk_win_base_sint_t const ansi_len, mk_win_base_pchar_lpct const def_char, mk_win_base_bool_lpt const def_used) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall MultiByteToWideChar(mk_win_base_uint_t const cp, mk_win_base_dword_t const flags, mk_win_base_pchar_lpct const ansi_buf, mk_win_base_sint_t const ansi_len, mk_win_base_wchar_lpt const wide_buf, mk_win_base_sint_t const wide_len) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall FormatMessageW(mk_win_base_dword_t const flags, mk_win_base_void_lpct const src, mk_win_base_dword_t const msg_id, mk_win_base_dword_t const lang_id, mk_win_base_wchar_lpt const buf, mk_win_base_dword_t const len, va_list* const args) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_kernel_string_wide_to_ansi(mk_win_base_uint_t const cp, mk_win_base_dword_t const flags, mk_win_base_wchar_lpct const wide_buf, mk_win_base_sint_t const wide_len, mk_win_base_pchar_lpt const ansi_buf, mk_win_base_sint_t const ansi_len, mk_win_base_pchar_lpct const def_char, mk_win_base_bool_lpt const def_used) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = WideCharToMultiByte(cp, flags, wide_buf, wide_len, ansi_buf, ansi_len, def_char, def_used);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_kernel_string_ansi_to_wide(mk_win_base_uint_t const cp, mk_win_base_dword_t const flags, mk_win_base_pchar_lpct const ansi_buf, mk_win_base_sint_t const ansi_len, mk_win_base_wchar_lpt const wide_buf, mk_win_base_sint_t const wide_len) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = MultiByteToWideChar(cp, flags, ansi_buf, ansi_len, wide_buf, wide_len);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_string_w_format(mk_win_base_dword_t const flags, mk_win_base_void_lpct const src, mk_win_base_dword_t const msg_id, mk_win_base_dword_t const lang_id, mk_win_base_wchar_lpt const buf, mk_win_base_dword_t const len, va_list* const args) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	ret = FormatMessageW(flags, src, msg_id, lang_id, buf, len, args);
	return ret;
}
