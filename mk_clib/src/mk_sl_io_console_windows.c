#include "mk_sl_io_console_windows.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"
#include "mk_win_base.h"
#include "mk_win_kernel_console.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_console_windows_write_n(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_win_base_handle_t output;
	mk_win_base_bool_t ret;
	mk_win_base_dword_t written;

	mk_lang_assert(buf);
	mk_lang_assert(len >= 0);

	output = mk_win_kernel_console_get_std_handle(mk_win_kernel_console_std_handle_id_e_output); mk_lang_check_return(output.m_data != mk_win_base_handle_invalid);
	if(output.m_data != mk_win_base_null)
	{
		ret = mk_win_kernel_console_a_write(output, ((mk_win_base_pchar_lpct)(buf)), ((mk_win_base_dword_t)(len)), &written, mk_win_base_null); mk_lang_check_return(ret != mk_win_base_false && written == ((mk_win_base_dword_t)(len)));
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_console_windows_write_w(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_win_base_handle_t output;
	mk_win_base_bool_t ret;
	mk_win_base_dword_t written;

	mk_lang_assert(buf);
	mk_lang_assert(len >= 0);

	output = mk_win_kernel_console_get_std_handle(mk_win_kernel_console_std_handle_id_e_output); mk_lang_check_return(output.m_data != mk_win_base_handle_invalid);
	if(output.m_data != mk_win_base_null)
	{
		ret = mk_win_kernel_console_w_write(output, ((mk_win_base_wchar_lpct)(buf)), ((mk_win_base_dword_t)(len)), &written, mk_win_base_null); mk_lang_check_return(ret != mk_win_base_false && written == ((mk_win_base_dword_t)(len)));
	}
	return 0;
}
