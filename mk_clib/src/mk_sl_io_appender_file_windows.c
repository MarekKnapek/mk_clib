#ifndef mk_include_guard_mk_sl_io_appender_file_windows_c
#define mk_include_guard_mk_sl_io_appender_file_windows_c
#include "mk_sl_io_appender_file_windows.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any

#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"
#include "mk_win_dll_advapi.h"
#include "mk_win_dll_kernel_errors.h"
#include "mk_win_dll_kernel_files.h"
#include "mk_win_dll_kernel_handle.h"


#define mk_sl_io_appender_file_windows_is_valid(x) (!mk_win_base_handle_is_invalid(x))


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_appender_file_windows_open_n(mk_sl_io_appender_file_windows_pt const appender, mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	mk_win_base_pchar_lpct file_name;
	mk_win_base_dword_t desired_access;
	mk_win_base_dword_t share_mode;
	mk_win_dll_advapi_security_attributes_lpct security_attributes;
	mk_win_base_dword_t creation_disposition;
	mk_win_base_dword_t flags_and_attributes;
	mk_win_base_handle_t template_file;
	mk_sl_io_appender_file_windows_handle_t handle;

	mk_lang_assert(appender);
	mk_lang_assert(name && name[0] != '\0');

	file_name = name;
	desired_access = ((mk_win_base_dword_t)(mk_win_dll_advapi_right_generic_e_read)) | ((mk_win_base_dword_t)(mk_win_dll_advapi_right_specific_file_e_append_data));
	share_mode = ((mk_win_base_dword_t)(mk_win_dll_kernel_files_share_e_read | mk_win_dll_kernel_files_share_e_delete));
	security_attributes = mk_win_base_null;
	creation_disposition = mk_win_dll_kernel_files_create_e_open_always;
	flags_and_attributes = ((mk_win_base_dword_t)(mk_win_dll_kernel_files_attribute_e_normal));
	template_file = mk_win_base_handle_get_null();
	handle = mk_win_dll_kernel_files_a_create_file(file_name, desired_access, share_mode, security_attributes, creation_disposition, flags_and_attributes, template_file); mk_lang_check_return(mk_sl_io_appender_file_windows_is_valid(handle));
	appender->m_file_handle = handle;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_appender_file_windows_open_w(mk_sl_io_appender_file_windows_pt const appender, mk_lang_types_wchar_pct const name) mk_lang_noexcept
{
	mk_win_base_wchar_lpct file_name;
	mk_win_base_dword_t desired_access;
	mk_win_base_dword_t share_mode;
	mk_win_dll_advapi_security_attributes_lpct security_attributes;
	mk_win_base_dword_t creation_disposition;
	mk_win_base_dword_t flags_and_attributes;
	mk_win_base_handle_t template_file;
	mk_sl_io_appender_file_windows_handle_t handle;


	mk_lang_assert(appender);
	mk_lang_assert(name && name[0] != L'\0');

	file_name = name;
	desired_access = ((mk_win_base_dword_t)(mk_win_dll_advapi_right_generic_e_read)) | ((mk_win_base_dword_t)(mk_win_dll_advapi_right_specific_file_e_append_data));
	share_mode = ((mk_win_base_dword_t)(mk_win_dll_kernel_files_share_e_read | mk_win_dll_kernel_files_share_e_delete));
	security_attributes = mk_win_base_null;
	creation_disposition = mk_win_dll_kernel_files_create_e_open_always;
	flags_and_attributes = ((mk_win_base_dword_t)(mk_win_dll_kernel_files_attribute_e_normal));
	template_file = mk_win_base_handle_get_null();
	handle = mk_win_dll_kernel_files_w_create_file(file_name, desired_access, share_mode, security_attributes, creation_disposition, flags_and_attributes, template_file); mk_lang_check_return(mk_sl_io_appender_file_windows_is_valid(handle));
	appender->m_file_handle = handle;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_appender_file_windows_append(mk_sl_io_appender_file_windows_pt const appender, mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_lang_types_sint_pt const written) mk_lang_noexcept
{
	mk_win_base_ulong_t distance_sl_lo;
	mk_win_base_slong_t distance_sl_hi;
	mk_win_base_dword_t distance_dw_lo;
	mk_lang_types_uint_t tuis[2];
	mk_sl_cui_uint64_t cui_a;
	mk_sl_cui_uint64_t cui_b;
	mk_win_base_dword_t distance_dw_hi;
	mk_win_base_bool_t b;
	mk_win_base_dword_t wrtn;

	mk_lang_static_assert(sizeof(mk_win_base_dword_t) == sizeof(mk_lang_types_uint_t));
	mk_lang_static_assert(mk_lang_alignof(mk_win_base_dword_t) == mk_lang_alignof(mk_lang_types_uint_t));
	mk_lang_static_assert(sizeof(mk_win_base_ulong_t) == sizeof(mk_lang_types_uint_t));
	mk_lang_static_assert(mk_lang_alignof(mk_win_base_ulong_t) == mk_lang_alignof(mk_lang_types_uint_t));
	mk_lang_static_assert(sizeof(mk_win_base_slong_t) == sizeof(mk_lang_types_uint_t));
	mk_lang_static_assert(mk_lang_alignof(mk_win_base_slong_t) == mk_lang_alignof(mk_lang_types_uint_t));

	mk_lang_assert(appender);
	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(written);
	mk_lang_assert(mk_sl_io_appender_file_windows_is_valid(appender->m_file_handle));

	distance_sl_lo = 0;
	distance_sl_hi = 0;
	distance_dw_lo = mk_win_dll_kernel_files_set_file_pointer(appender->m_file_handle, ((mk_win_base_slong_t)(distance_sl_lo)), &distance_sl_hi, mk_win_dll_kernel_files_file_pos_e_end); mk_lang_check_return(distance_dw_lo != s_mk_win_dll_kernel_files_invalid_set_file_pointer);
	tuis[0] = ((mk_lang_types_uint_t)(distance_dw_lo));
	tuis[1] = ((mk_lang_types_uint_t)(distance_sl_hi));
	mk_sl_cui_uint64_from_buis_uint_le(&cui_a, &tuis[0]);
	mk_sl_cui_uint64_from_bi_sint(&cui_b, &len);
	mk_sl_cui_uint64_add2_wrap_cid_cod(&cui_a, &cui_b);
	mk_sl_cui_uint64_to_buis_uint_le(&cui_a, &tuis[0]);
	distance_dw_lo = ((mk_win_base_dword_t)(tuis[0]));
	distance_dw_hi = ((mk_win_base_dword_t)(tuis[1]));
	b = mk_win_dll_kernel_files_lock_file(appender->m_file_handle, distance_dw_lo, distance_dw_hi, ((mk_win_base_dword_t)(len)), 0); mk_lang_check_return(b != mk_win_base_false);
	b = mk_win_dll_kernel_files_write_file(appender->m_file_handle, buf, ((mk_win_base_dword_t)(len)), &wrtn, mk_win_base_null); mk_lang_check_return(b != mk_win_base_false);
	b = mk_win_dll_kernel_files_unlock_file(appender->m_file_handle, distance_dw_lo, distance_dw_hi, ((mk_win_base_dword_t)(len)), 0); mk_lang_check_return(b != mk_win_base_false);
	*written = ((mk_lang_types_sint_t)(wrtn));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_appender_file_windows_close(mk_sl_io_appender_file_windows_pt const appender) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	mk_lang_assert(appender);
	mk_lang_assert(mk_sl_io_appender_file_windows_is_valid(appender->m_file_handle));

	ret = mk_win_dll_kernel_handle_close(appender->m_file_handle); mk_lang_check_return(ret != 0);
	return 0;
}


#else
static void mk_sl_io_appender_file_windows_dummy(void){}
#endif
#endif
