#include "mk_win_kernel_files.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_tstring.h"


mk_win_base_dll_import mk_win_base_uint_t mk_win_base_stdcall GetDriveTypeA(mk_win_base_pchar_lpct) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall FindFirstFileA(mk_win_base_pchar_lpct, mk_win_kernel_files_a_find_data_lpt) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall FindNextFileA(mk_win_base_handle_t, mk_win_kernel_files_a_find_data_lpt) mk_lang_noexcept;

mk_win_base_dll_import mk_win_base_uint_t mk_win_base_stdcall GetDriveTypeW(mk_win_base_wchar_lpct) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall FindFirstFileW(mk_win_base_wchar_lpct, mk_win_kernel_files_w_find_data_lpt) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall FindNextFileW(mk_win_base_handle_t, mk_win_kernel_files_w_find_data_lpt) mk_lang_noexcept;

mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetLogicalDrives(void) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall FindClose(mk_win_base_handle_t) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_uint_t mk_win_kernel_files_a_get_drive_type(mk_win_base_pchar_lpct const path) mk_lang_noexcept
{
	mk_win_base_uint_t type;

	type = GetDriveTypeA(path);
	return type;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_files_a_find_first_file(mk_win_base_pchar_lpct const name, mk_win_kernel_files_a_find_data_lpt const data) mk_lang_noexcept
{
	mk_win_base_handle_t handle;

	handle = FindFirstFileA(name, data);
	return handle;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_a_find_next_file(mk_win_base_handle_t const handle, mk_win_kernel_files_a_find_data_lpt const data) mk_lang_noexcept
{
	mk_win_base_bool_t found;

	found = FindNextFileA(handle, data);
	return found;
}


mk_lang_nodiscard mk_lang_jumbo mk_win_base_uint_t mk_win_kernel_files_w_get_drive_type(mk_win_base_wchar_lpct const path) mk_lang_noexcept
{
	mk_win_base_uint_t type;

	type = GetDriveTypeW(path);
	return type;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_files_w_find_first_file(mk_win_base_wchar_lpct const name, mk_win_kernel_files_w_find_data_lpt const data) mk_lang_noexcept
{
	mk_win_base_handle_t handle;

	handle = FindFirstFileW(name, data);
	return handle;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_w_find_next_file(mk_win_base_handle_t const handle, mk_win_kernel_files_w_find_data_lpt const data) mk_lang_noexcept
{
	mk_win_base_bool_t found;

	found = FindNextFileW(handle, data);
	return found;
}


mk_lang_nodiscard mk_lang_jumbo mk_win_base_uint_t mk_win_kernel_files_t_get_drive_type(mk_win_tstring_tchar_lpct const path) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_kernel_files_a_get_drive_type(path);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_kernel_files_a_get_drive_type(mk_win_tstring_tstr_to_ansi_zt_nofail(path).m_str);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_kernel_files_w_get_drive_type(path);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_kernel_files_w_get_drive_type(mk_win_tstring_tstr_to_wide_zt_nofail(path).m_str);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_kernel_files_a_get_drive_type(path);
		#else
			return mk_win_kernel_files_a_get_drive_type(mk_win_tstring_tstr_to_ansi_zt_nofail(path).m_str);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_kernel_files_w_get_drive_type(path);
		#else
			return mk_win_kernel_files_w_get_drive_type(mk_win_tstring_tstr_to_wide_zt_nofail(path).m_str);
		#endif
	}
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_files_t_find_first_file(mk_win_tstring_tchar_lpct const name, mk_win_kernel_files_t_find_data_lpt const data) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_kernel_files_a_find_first_file(name, data);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_kernel_files_a_find_first_file(mk_win_tstring_tstr_to_ansi_zt_nofail(name).m_str, data);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_kernel_files_w_find_first_file(name, data);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_kernel_files_w_find_first_file(mk_win_tstring_tstr_to_wide_zt_nofail(name).m_str, data);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_kernel_files_a_find_first_file(name, data);
		#else
			return mk_win_kernel_files_a_find_first_file(mk_win_tstring_tstr_to_ansi_zt_nofail(name).m_str, data);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_kernel_files_w_find_first_file(name, data);
		#else
			mk_win_base_handle_t handle;
			mk_win_kernel_files_w_find_data_t dataw;
			handle = mk_win_kernel_files_w_find_first_file(mk_win_tstring_tstr_to_wide_zt_nofail(name).m_str, &dataw);
			if(handle != s_mk_win_base_handle_invalid)
			{
				data->m_attributes = dataw.m_attributes;
				data->m_created = dataw.m_created;
				data->m_accessed = dataw.m_accessed;
				data->m_written = dataw.m_written;
				data->m_size_hi = dataw.m_size_hi;
				data->m_size_lo = dataw.m_size_lo;
				data->m_reserved_1 = dataw.m_reserved_1;
				data->m_reserved_2 = dataw.m_reserved_2;
				mk_win_tstring_wide_to_tstr_buff_zt_nofail(dataw.m_name, data->m_name, ((int)(sizeof(data->m_name) / sizeof(data->m_name[0]))));
				mk_win_tstring_wide_to_tstr_buff_zt_nofail(dataw.m_name_83, data->m_name_83, ((int)(sizeof(data->m_name_83) / sizeof(data->m_name_83[0]))));
			}
			return handle;
		#endif
	}
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_t_find_next_file(mk_win_base_handle_t const handle, mk_win_kernel_files_t_find_data_lpt const data) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_kernel_files_a_find_next_file(name, data);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_kernel_files_a_find_next_file(name, data);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_kernel_files_w_find_next_file(handle, data);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_kernel_files_a_find_next_file(name, data);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_kernel_files_a_find_next_file(name, data);
		#else
			return mk_win_kernel_files_a_find_next_file(handle, data);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_kernel_files_w_find_next_file(handle, data);
		#else
			mk_win_base_bool_t found;
			mk_win_kernel_files_w_find_data_t dataw;
			found = mk_win_kernel_files_w_find_next_file(handle, &dataw);
			if(found != 0)
			{
				data->m_attributes = dataw.m_attributes;
				data->m_created = dataw.m_created;
				data->m_accessed = dataw.m_accessed;
				data->m_written = dataw.m_written;
				data->m_size_hi = dataw.m_size_hi;
				data->m_size_lo = dataw.m_size_lo;
				data->m_reserved_1 = dataw.m_reserved_1;
				data->m_reserved_2 = dataw.m_reserved_2;
				mk_win_tstring_wide_to_tstr_buff_zt_nofail(dataw.m_name, data->m_name, ((int)(sizeof(data->m_name) / sizeof(data->m_name[0]))));
				mk_win_tstring_wide_to_tstr_buff_zt_nofail(dataw.m_name_83, data->m_name_83, ((int)(sizeof(data->m_name_83) / sizeof(data->m_name_83[0]))));
			}
			return found;
		#endif
	}
#endif
}


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_files_get_logical_drives(void) mk_lang_noexcept
{
	mk_win_base_dword_t drives;

	drives = GetLogicalDrives();
	return drives;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_find_close(mk_win_base_handle_t const handle) mk_lang_noexcept
{
	mk_win_base_bool_t closed;

	closed = FindClose(handle);
	return closed;
}
