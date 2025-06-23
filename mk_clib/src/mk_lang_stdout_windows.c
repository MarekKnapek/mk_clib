#ifndef mk_include_guard_mk_lang_stdout_windows_c
#define mk_include_guard_mk_lang_stdout_windows_c
#include "mk_lang_stdout_windows.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_tchar.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_dll_kernel_console.h"
#include "mk_win_dll_kernel_files.h"


enum mk_lang_stdout_windows_type_e
{
	mk_lang_stdout_windows_type_e_not_initialized,
	mk_lang_stdout_windows_type_e_normal,
	mk_lang_stdout_windows_type_e_redirected,
	mk_lang_stdout_windows_type_e_missing,
	mk_lang_stdout_windows_type_e_dummy_end
};
typedef enum mk_lang_stdout_windows_type_e mk_lang_stdout_windows_type_t;


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lang_stdout_windows_s
{
	mk_win_base_handle_t m_handle;
	mk_lang_stdout_windows_type_t m_type;
};
typedef struct mk_lang_stdout_windows_s mk_lang_stdout_windows_t;
mk_lang_typedef(mk_lang_stdout_windows);
#include "mk_lang_warning_msvc_pop.h"


static mk_lang_stdout_windows_t mk_lang_stdout_windows_g;


mk_lang_nodiscard static mk_lang_inline mk_win_dll_kernel_console_attribute_t mk_lang_stdout_windows_pr_color_to_attribute(mk_lang_stdout_windows_color_text_t const color) mk_lang_noexcept
{
	mk_win_dll_kernel_console_attribute_t attribute;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_windows_color_text_e_dummy_end);

	switch(color)
	{
		case mk_lang_stdout_windows_color_text_e_dark_black   : attribute = ((mk_win_dll_kernel_console_attribute_t)(0)); break;
		case mk_lang_stdout_windows_color_text_e_dark_red     : attribute = ((mk_win_dll_kernel_console_attribute_t)(mk_win_dll_kernel_console_attribute_e_foreground_red)); break;
		case mk_lang_stdout_windows_color_text_e_dark_green   : attribute = ((mk_win_dll_kernel_console_attribute_t)(mk_win_dll_kernel_console_attribute_e_foreground_green)); break;
		case mk_lang_stdout_windows_color_text_e_dark_blue    : attribute = ((mk_win_dll_kernel_console_attribute_t)(mk_win_dll_kernel_console_attribute_e_foreground_blue)); break;
		case mk_lang_stdout_windows_color_text_e_dark_yellow  : attribute = ((mk_win_dll_kernel_console_attribute_t)(mk_win_dll_kernel_console_attribute_e_foreground_red | mk_win_dll_kernel_console_attribute_e_foreground_green)); break;
		case mk_lang_stdout_windows_color_text_e_dark_magenta : attribute = ((mk_win_dll_kernel_console_attribute_t)(mk_win_dll_kernel_console_attribute_e_foreground_red | mk_win_dll_kernel_console_attribute_e_foreground_blue)); break;
		case mk_lang_stdout_windows_color_text_e_dark_cyan    : attribute = ((mk_win_dll_kernel_console_attribute_t)(mk_win_dll_kernel_console_attribute_e_foreground_green | mk_win_dll_kernel_console_attribute_e_foreground_blue)); break;
		case mk_lang_stdout_windows_color_text_e_dark_white   : attribute = ((mk_win_dll_kernel_console_attribute_t)(mk_win_dll_kernel_console_attribute_e_foreground_red | mk_win_dll_kernel_console_attribute_e_foreground_green | mk_win_dll_kernel_console_attribute_e_foreground_blue)); break;
		case mk_lang_stdout_windows_color_text_e_light_black  : attribute = ((mk_win_dll_kernel_console_attribute_t)(mk_win_dll_kernel_console_attribute_e_foreground_intensity)); break;
		case mk_lang_stdout_windows_color_text_e_light_red    : attribute = ((mk_win_dll_kernel_console_attribute_t)(mk_win_dll_kernel_console_attribute_e_foreground_intensity | mk_win_dll_kernel_console_attribute_e_foreground_red)); break;
		case mk_lang_stdout_windows_color_text_e_light_green  : attribute = ((mk_win_dll_kernel_console_attribute_t)(mk_win_dll_kernel_console_attribute_e_foreground_intensity | mk_win_dll_kernel_console_attribute_e_foreground_green)); break;
		case mk_lang_stdout_windows_color_text_e_light_blue   : attribute = ((mk_win_dll_kernel_console_attribute_t)(mk_win_dll_kernel_console_attribute_e_foreground_intensity | mk_win_dll_kernel_console_attribute_e_foreground_blue)); break;
		case mk_lang_stdout_windows_color_text_e_light_yellow : attribute = ((mk_win_dll_kernel_console_attribute_t)(mk_win_dll_kernel_console_attribute_e_foreground_intensity | mk_win_dll_kernel_console_attribute_e_foreground_red | mk_win_dll_kernel_console_attribute_e_foreground_green)); break;
		case mk_lang_stdout_windows_color_text_e_light_magenta: attribute = ((mk_win_dll_kernel_console_attribute_t)(mk_win_dll_kernel_console_attribute_e_foreground_intensity | mk_win_dll_kernel_console_attribute_e_foreground_red | mk_win_dll_kernel_console_attribute_e_foreground_blue)); break;
		case mk_lang_stdout_windows_color_text_e_light_cyan   : attribute = ((mk_win_dll_kernel_console_attribute_t)(mk_win_dll_kernel_console_attribute_e_foreground_intensity | mk_win_dll_kernel_console_attribute_e_foreground_green | mk_win_dll_kernel_console_attribute_e_foreground_blue)); break;
		case mk_lang_stdout_windows_color_text_e_light_white  : attribute = ((mk_win_dll_kernel_console_attribute_t)(mk_win_dll_kernel_console_attribute_e_foreground_intensity | mk_win_dll_kernel_console_attribute_e_foreground_red | mk_win_dll_kernel_console_attribute_e_foreground_green | mk_win_dll_kernel_console_attribute_e_foreground_blue)); break;
		case mk_lang_stdout_windows_color_text_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&attribute);
	return attribute;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lang_stdout_windows_pr_color_change(mk_lang_stdout_windows_color_text_t const color, mk_win_base_word_pt const restore) mk_lang_noexcept
{
	mk_win_dll_kernel_console_attribute_t attribute;
	mk_win_base_bool_t b;
	mk_win_dll_kernel_console_console_screen_buffer_info_t info;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_windows_color_text_e_dummy_end);
	mk_lang_assert(restore);
	mk_lang_assert(mk_lang_stdout_windows_g.m_type >= 0);
	mk_lang_assert(mk_lang_stdout_windows_g.m_type < mk_lang_stdout_windows_type_e_dummy_end);
	mk_lang_assert(mk_lang_stdout_windows_g.m_type != mk_lang_stdout_windows_type_e_not_initialized);

	if(mk_lang_stdout_windows_g.m_type == mk_lang_stdout_windows_type_e_normal)
	{
		attribute = mk_lang_stdout_windows_pr_color_to_attribute(color);
		b = mk_win_dll_kernel_console_get_console_screen_buffer_info(mk_lang_stdout_windows_g.m_handle, &info); mk_lang_check_return(b != 0);
		b = mk_win_dll_kernel_console_set_console_text_attribute(mk_lang_stdout_windows_g.m_handle, ((mk_win_base_word_t)(attribute))); mk_lang_check_return(b != 0);
		*restore = info.m_attributes;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lang_stdout_windows_pr_color_restore(mk_win_base_word_pct const restore) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(restore);
	mk_lang_assert(mk_lang_stdout_windows_g.m_type >= 0);
	mk_lang_assert(mk_lang_stdout_windows_g.m_type < mk_lang_stdout_windows_type_e_dummy_end);
	mk_lang_assert(mk_lang_stdout_windows_g.m_type != mk_lang_stdout_windows_type_e_not_initialized);

	if(mk_lang_stdout_windows_g.m_type == mk_lang_stdout_windows_type_e_normal)
	{
		b = mk_win_dll_kernel_console_set_console_text_attribute(mk_lang_stdout_windows_g.m_handle, *restore); mk_lang_check_return(b != 0);
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_windows_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_handle_t out;
	mk_win_base_dword_t type;

	out = mk_win_dll_kernel_console_get_std_handle(mk_win_dll_kernel_console_std_handle_id_e_output); mk_lang_check_return(!mk_win_base_handle_is_invalid(out));
	if(mk_win_base_handle_is_null(out))
	{
		mk_lang_stdout_windows_g.m_type = mk_lang_stdout_windows_type_e_missing;
	}
	else
	{
		mk_lang_stdout_windows_g.m_handle = out;
		type = mk_win_dll_kernel_files_get_file_type(out);
		if(type == mk_win_dll_kernel_files_file_type_e_char)
		{
			mk_lang_stdout_windows_g.m_type = mk_lang_stdout_windows_type_e_normal;
		}
		else
		{
			mk_lang_stdout_windows_g.m_type = mk_lang_stdout_windows_type_e_redirected;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_windows_print_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_dword_t written;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	switch(mk_lang_stdout_windows_g.m_type)
	{
		case mk_lang_stdout_windows_type_e_not_initialized: mk_lang_assert_false(); break;
		case mk_lang_stdout_windows_type_e_normal: b = mk_win_dll_kernel_console_a_write(mk_lang_stdout_windows_g.m_handle, str_buf, ((mk_win_base_dword_t)(str_len)), &written, mk_win_base_null); mk_lang_check_return(b != 0); mk_lang_check_return(written == ((mk_win_base_dword_t)(str_len))); break;
		case mk_lang_stdout_windows_type_e_redirected: b = mk_win_dll_kernel_files_write_file(mk_lang_stdout_windows_g.m_handle, str_buf, ((mk_win_base_dword_t)(str_len)), &written, mk_win_base_null); mk_lang_check_return(b != 0); mk_lang_check_return(written == ((mk_win_base_dword_t)(str_len))); break;
		case mk_lang_stdout_windows_type_e_missing: ((mk_lang_types_void_t)(str_buf)); ((mk_lang_types_void_t)(str_len)); break;
		case mk_lang_stdout_windows_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_windows_print_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_dword_t written;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(((mk_win_base_dword_t)(str_len)) / mk_lang_sizeof_bi_wchar_t <= ((mk_win_base_dword_t)(((mk_win_base_dword_t)(0)) - ((mk_win_base_dword_t)(1)))));

	switch(mk_lang_stdout_windows_g.m_type)
	{
		case mk_lang_stdout_windows_type_e_not_initialized: mk_lang_assert_false(); break;
		case mk_lang_stdout_windows_type_e_normal: b = mk_win_dll_kernel_console_w_write(mk_lang_stdout_windows_g.m_handle, str_buf, ((mk_win_base_dword_t)(str_len)), &written, mk_win_base_null); mk_lang_check_return(b != 0); mk_lang_check_return(written == ((mk_win_base_dword_t)(str_len))); break;
		case mk_lang_stdout_windows_type_e_redirected: b = mk_win_dll_kernel_files_write_file(mk_lang_stdout_windows_g.m_handle, str_buf, ((mk_win_base_dword_t)(str_len)) * mk_lang_sizeof_bi_wchar_t, &written, mk_win_base_null); mk_lang_check_return(b != 0); mk_lang_check_return(written == ((mk_win_base_dword_t)(str_len)) * mk_lang_sizeof_bi_wchar_t); break;
		case mk_lang_stdout_windows_type_e_missing: ((mk_lang_types_void_t)(str_buf)); ((mk_lang_types_void_t)(str_len)); break;
		case mk_lang_stdout_windows_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_windows_print_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_clang_push_tautological_value_range_compare.h"
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(((mk_win_base_dword_t)(str_len)) / sizeof(mk_lang_tchar_t) <= ((mk_win_base_dword_t)(((mk_win_base_dword_t)(0)) - ((mk_win_base_dword_t)(1)))));
	#include "mk_lang_warning_clang_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	err = mk_lang_tchar_dispatch(mk_lang_stdout_windows_print_)(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_windows_println_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_windows_print_n(str_buf, str_len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_windows_print_lit_n("\x0d\x0a"); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_windows_println_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_windows_print_w(str_buf, str_len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_windows_print_lit_w(L"\x0d\x0a"); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_windows_println_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_tchar_dispatch(mk_lang_stdout_windows_println_)(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_windows_print_color_n(mk_lang_stdout_windows_color_text_t const color, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_win_base_word_t restore;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_windows_color_text_e_dummy_end);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_windows_pr_color_change(color, &restore); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_windows_print_n(str_buf, str_len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_windows_pr_color_restore(&restore); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_windows_print_color_w(mk_lang_stdout_windows_color_text_t const color, mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_win_base_word_t restore;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_windows_color_text_e_dummy_end);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_windows_pr_color_change(color, &restore); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_windows_print_w(str_buf, str_len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_windows_pr_color_restore(&restore); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_windows_print_color_t(mk_lang_stdout_windows_color_text_t const color, mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_win_base_word_t restore;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_windows_color_text_e_dummy_end);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_windows_pr_color_change(color, &restore); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_windows_print_t(str_buf, str_len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_windows_pr_color_restore(&restore); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_windows_println_color_n(mk_lang_stdout_windows_color_text_t const color, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_win_base_word_t restore;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_windows_color_text_e_dummy_end);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_windows_pr_color_change(color, &restore); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_windows_println_n(str_buf, str_len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_windows_pr_color_restore(&restore); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_windows_println_color_w(mk_lang_stdout_windows_color_text_t const color, mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_win_base_word_t restore;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_windows_color_text_e_dummy_end);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_windows_pr_color_change(color, &restore); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_windows_println_w(str_buf, str_len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_windows_pr_color_restore(&restore); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_windows_println_color_t(mk_lang_stdout_windows_color_text_t const color, mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_win_base_word_t restore;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_windows_color_text_e_dummy_end);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_windows_pr_color_change(color, &restore); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_windows_println_t(str_buf, str_len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_windows_pr_color_restore(&restore); mk_lang_check_rereturn(err);
	return 0;
}


#endif
#endif
