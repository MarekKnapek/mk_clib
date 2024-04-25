#include "mk_win_kernel_files.h"

#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_advapi_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_time.h"
#include "mk_win_tstring.h"


mk_lang_extern_c mk_win_base_dll_import mk_win_base_uint_t mk_win_base_stdcall GetDriveTypeA(mk_win_base_pchar_lpct) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall FindFirstFileA(mk_win_base_pchar_lpct, mk_win_kernel_files_a_find_data_lpt) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall FindNextFileA(mk_win_base_handle_t, mk_win_kernel_files_a_find_data_lpt) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateFileA(mk_win_base_pchar_lpct, mk_win_base_dword_t, mk_win_base_dword_t, mk_win_advapi_base_security_attributes_lpct, mk_win_base_dword_t, mk_win_base_dword_t, mk_win_base_handle_t) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetDiskFreeSpaceA(mk_win_base_pchar_lpct, mk_win_base_dword_lpt, mk_win_base_dword_lpt, mk_win_base_dword_lpt, mk_win_base_dword_lpt) mk_lang_noexcept;

mk_lang_extern_c mk_win_base_dll_import mk_win_base_uint_t mk_win_base_stdcall GetDriveTypeW(mk_win_base_wchar_lpct) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall FindFirstFileW(mk_win_base_wchar_lpct, mk_win_kernel_files_w_find_data_lpt) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall FindNextFileW(mk_win_base_handle_t, mk_win_kernel_files_w_find_data_lpt) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateFileW(mk_win_base_wchar_lpct, mk_win_base_dword_t, mk_win_base_dword_t, mk_win_advapi_base_security_attributes_lpct, mk_win_base_dword_t, mk_win_base_dword_t, mk_win_base_handle_t) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetDiskFreeSpaceW(mk_win_base_wchar_lpct, mk_win_base_dword_lpt, mk_win_base_dword_lpt, mk_win_base_dword_lpt, mk_win_base_dword_lpt) mk_lang_noexcept;

mk_lang_extern_c mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetLogicalDrives(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall FindClose(mk_win_base_handle_t) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall ReadFile(mk_win_base_handle_t, mk_win_base_void_lpt, mk_win_base_dword_t, mk_win_base_dword_lpt, mk_win_base_void_lpt /*todo overlapped*/) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall WriteFile(mk_win_base_handle_t, mk_win_base_void_lpct, mk_win_base_dword_t, mk_win_base_dword_lpt, mk_win_base_void_lpt /*todo overlapped*/) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetFileSize(mk_win_base_handle_t, mk_win_base_dword_lpt) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall SetFilePointer(mk_win_base_handle_t, mk_win_base_slong_t, mk_win_base_slong_lpt, mk_win_base_dword_t) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SetEndOfFile(mk_win_base_handle_t) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetFileType(mk_win_base_handle_t) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_uint_t mk_win_kernel_files_a_get_drive_type(mk_win_base_pchar_lpct const path) mk_lang_noexcept
{
	mk_win_base_uint_t ret;

	ret = GetDriveTypeA(path);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_files_a_find_first_file(mk_win_base_pchar_lpct const name, mk_win_kernel_files_a_find_data_lpt const data) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = FindFirstFileA(name, data);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_a_find_next_file(mk_win_base_handle_t const handle, mk_win_kernel_files_a_find_data_lpt const data) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = FindNextFileA(handle, data);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_files_a_create_file(mk_win_base_pchar_lpct const file_name, mk_win_base_dword_t const desired_access, mk_win_base_dword_t const share_mode, mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_dword_t const creation_disposition, mk_win_base_dword_t const flags_and_attributes, mk_win_base_handle_t const template_file) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = CreateFileA(file_name, desired_access, share_mode, security_attributes, creation_disposition, flags_and_attributes, template_file);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_a_get_disk_free_space(mk_win_base_pchar_lpct const root_path_name, mk_win_base_dword_lpt const sectors_per_cluster, mk_win_base_dword_lpt const bytes_per_sector, mk_win_base_dword_lpt const free_clusters_count, mk_win_base_dword_lpt const total_clusters_count) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = GetDiskFreeSpaceA(root_path_name, sectors_per_cluster, bytes_per_sector, free_clusters_count, total_clusters_count);
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_win_base_uint_t mk_win_kernel_files_w_get_drive_type(mk_win_base_wchar_lpct const path) mk_lang_noexcept
{
	mk_win_base_uint_t ret;

	ret = GetDriveTypeW(path);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_files_w_find_first_file(mk_win_base_wchar_lpct const name, mk_win_kernel_files_w_find_data_lpt const data) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = FindFirstFileW(name, data);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_w_find_next_file(mk_win_base_handle_t const handle, mk_win_kernel_files_w_find_data_lpt const data) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = FindNextFileW(handle, data);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_files_w_create_file(mk_win_base_wchar_lpct const file_name, mk_win_base_dword_t const desired_access, mk_win_base_dword_t const share_mode, mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_dword_t const creation_disposition, mk_win_base_dword_t const flags_and_attributes, mk_win_base_handle_t const template_file) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = CreateFileW(file_name, desired_access, share_mode, security_attributes, creation_disposition, flags_and_attributes, template_file);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_w_get_disk_free_space(mk_win_base_wchar_lpct const root_path_name, mk_win_base_dword_lpt const sectors_per_cluster, mk_win_base_dword_lpt const bytes_per_sector, mk_win_base_dword_lpt const free_clusters_count, mk_win_base_dword_lpt const total_clusters_count) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = GetDiskFreeSpaceW(root_path_name, sectors_per_cluster, bytes_per_sector, free_clusters_count, total_clusters_count);
	return ret;
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
			if(handle.m_data != mk_win_base_handle_invalid)
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

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_files_t_create_file(mk_win_tstring_tchar_lpct const file_name, mk_win_base_dword_t const desired_access, mk_win_base_dword_t const share_mode, mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_dword_t const creation_disposition, mk_win_base_dword_t const flags_and_attributes, mk_win_base_handle_t const template_file) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_kernel_files_a_create_file(file_name, desired_access, share_mode, security_attributes, creation_disposition, flags_and_attributes, template_file);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_kernel_files_a_create_file(mk_win_tstring_tstr_to_ansi_zt_nofail(file_name).m_str, desired_access, share_mode, security_attributes, creation_disposition, flags_and_attributes, template_file);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_kernel_files_w_create_file(file_name, desired_access, share_mode, security_attributes, creation_disposition, flags_and_attributes, template_file);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_kernel_files_w_create_file(mk_win_tstring_tstr_to_wide_zt_nofail(file_name).m_str, desired_access, share_mode, security_attributes, creation_disposition, flags_and_attributes, template_file);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_kernel_files_a_create_file(file_name, desired_access, share_mode, security_attributes, creation_disposition, flags_and_attributes, template_file);
		#else
			return mk_win_kernel_files_a_create_file(mk_win_tstring_tstr_to_ansi_zt_nofail(file_name).m_str, desired_access, share_mode, security_attributes, creation_disposition, flags_and_attributes, template_file);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_kernel_files_w_create_file(file_name, desired_access, share_mode, security_attributes, creation_disposition, flags_and_attributes, template_file);
		#else
			return mk_win_kernel_files_w_create_file(mk_win_tstring_tstr_to_wide_zt_nofail(file_name).m_str, desired_access, share_mode, security_attributes, creation_disposition, flags_and_attributes, template_file);
		#endif
	}
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_t_get_disk_free_space(mk_win_tstring_tchar_lpct const root_path_name, mk_win_base_dword_lpt const sectors_per_cluster, mk_win_base_dword_lpt const bytes_per_sector, mk_win_base_dword_lpt const free_clusters_count, mk_win_base_dword_lpt const total_clusters_count) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_kernel_files_a_get_disk_free_space(root_path_name, sectors_per_cluster, bytes_per_sector, free_clusters_count, total_clusters_count);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_kernel_files_a_get_disk_free_space(mk_win_tstring_tstr_to_ansi_zt_nofail(root_path_name).m_str, sectors_per_cluster, bytes_per_sector, free_clusters_count, total_clusters_count);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_kernel_files_w_get_disk_free_space(root_path_name, sectors_per_cluster, bytes_per_sector, free_clusters_count, total_clusters_count);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_kernel_files_w_get_disk_free_space(mk_win_tstring_tstr_to_wide_zt_nofail(root_path_name).m_str, sectors_per_cluster, bytes_per_sector, free_clusters_count, total_clusters_count);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_kernel_files_a_get_disk_free_space(root_path_name, sectors_per_cluster, bytes_per_sector, free_clusters_count, total_clusters_count);
		#else
			return mk_win_kernel_files_a_get_disk_free_space(mk_win_tstring_tstr_to_ansi_zt_nofail(root_path_name).m_str, sectors_per_cluster, bytes_per_sector, free_clusters_count, total_clusters_count);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_kernel_files_w_get_disk_free_space(root_path_name, sectors_per_cluster, bytes_per_sector, free_clusters_count, total_clusters_count);
		#else
			return mk_win_kernel_files_w_get_disk_free_space(mk_win_tstring_tstr_to_wide_zt_nofail(root_path_name).m_str, sectors_per_cluster, bytes_per_sector, free_clusters_count, total_clusters_count);
		#endif
	}
#endif
}


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_files_get_logical_drives(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	ret = GetLogicalDrives();
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_find_close(mk_win_base_handle_t const handle) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = FindClose(handle);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_read_file(mk_win_base_handle_t const handle, mk_win_base_void_lpt const buffer, mk_win_base_dword_t const bytes_requested, mk_win_base_dword_lpt const bytes_read, mk_win_kernel_files_overlapped_lpt const overlapped) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = ReadFile(handle, buffer, bytes_requested, bytes_read, overlapped);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_write_file(mk_win_base_handle_t const handle, mk_win_base_void_lpct const buffer, mk_win_base_dword_t const bytes_to_write, mk_win_base_dword_lpt const bytes_written, mk_win_kernel_files_overlapped_lpt const overlapped) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = WriteFile(handle, buffer, bytes_to_write, bytes_written, overlapped);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_files_get_file_size(mk_win_base_handle_t const handle, mk_win_base_dword_lpt const file_size_hi) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	ret = GetFileSize(handle, file_size_hi);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_files_set_file_pointer(mk_win_base_handle_t const handle, mk_win_base_slong_t const distance_lo, mk_win_base_slong_lpt const distance_hi, mk_win_base_dword_t const move_method) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	ret = SetFilePointer(handle, distance_lo, distance_hi, move_method);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_files_set_end_of_file(mk_win_base_handle_t const handle) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = SetEndOfFile(handle);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_files_get_file_type(mk_win_base_handle_t const handle) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	ret = GetFileType(handle);
	return ret;
}
