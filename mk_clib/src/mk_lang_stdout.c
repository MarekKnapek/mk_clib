#ifndef mk_include_guard_mk_lang_stdout_c
#define mk_include_guard_mk_lang_stdout_c
#include "mk_lang_stdout.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_dll_kernel_console.h"
#include "mk_win_dll_kernel_files.h"


enum mk_lang_stdout_type_e
{
	mk_lang_stdout_type_e_normal,
	mk_lang_stdout_type_e_redirected,
	mk_lang_stdout_type_e_missing,
	mk_lang_stdout_type_e_dummy_end
};
typedef enum mk_lang_stdout_type_e mk_lang_stdout_type_t;


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lang_stdout_s
{
	mk_win_base_handle_t m_handle;
	mk_lang_stdout_type_t m_type;
};
typedef struct mk_lang_stdout_s mk_lang_stdout_t;
mk_lang_typedef(mk_lang_stdout);
#include "mk_lang_warning_msvc_pop.h"


static mk_lang_stdout_t mk_lang_stdout_g;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_handle_t stdout;
	mk_win_base_dword_t type;

	stdout = mk_win_dll_kernel_console_get_std_handle(mk_win_dll_kernel_console_std_handle_id_e_output); mk_lang_check_return(!mk_win_base_handle_is_invalid(stdout));
	if(mk_win_base_handle_is_null(stdout))
	{
		mk_lang_stdout_g.m_type = mk_lang_stdout_type_e_missing;
	}
	else
	{
		mk_lang_stdout_g.m_handle = stdout;
		type = mk_win_dll_kernel_files_get_file_type(stdout);
		if(type == mk_win_dll_kernel_files_file_type_e_char)
		{
			mk_lang_stdout_g.m_type = mk_lang_stdout_type_e_normal;
		}
		else
		{
			mk_lang_stdout_g.m_type = mk_lang_stdout_type_e_redirected;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_print_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_print_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_dword_t written;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	switch(mk_lang_stdout_g.m_type)
	{
		case mk_lang_stdout_type_e_normal: b = mk_win_dll_kernel_console_w_write(mk_lang_stdout_g.m_handle, str_buf, ((mk_win_base_dword_t)(str_len)), &written, mk_win_base_null); mk_lang_check_return(b != 0); mk_lang_check_return(written == ((mk_win_base_dword_t)(str_len))); break;
		case mk_lang_stdout_type_e_redirected: b = mk_win_dll_kernel_files_write_file(mk_lang_stdout_g.m_handle, str_buf, ((mk_win_base_dword_t)(str_len)), &written, mk_win_base_null); mk_lang_check_return(b != 0); mk_lang_check_return(written == ((mk_win_base_dword_t)(str_len))); break;
		case mk_lang_stdout_type_e_missing: ((mk_lang_types_void_t)(str_buf)); ((mk_lang_types_void_t)(str_len)); break;
		case mk_lang_stdout_type_e_dummy_end: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}


#endif
