#ifndef mk_include_guard_mk_win_dll_kernel_files_c
#define mk_include_guard_mk_win_dll_kernel_files_c
#include "mk_win_dll_kernel_files.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any

#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_dll_kernel_time.h"


mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetCurrentDirectoryA(mk_win_base_dword_t const len, mk_win_base_pchar_pt const buf) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall CreateDirectoryA(mk_win_base_pchar_lpct const path, mk_win_dll_advapi_security_attributes_lpct const security_attributes) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_uint_t mk_win_base_stdcall GetDriveTypeA(mk_win_base_pchar_lpct const path) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall FindFirstFileA(mk_win_base_pchar_lpct const name, mk_win_dll_kernel_files_a_find_data_lpt const data) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall FindNextFileA(mk_win_base_handle_t const handle, mk_win_dll_kernel_files_a_find_data_lpt const data) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateFileA(mk_win_base_pchar_lpct const file_name, mk_win_base_dword_t const desired_access, mk_win_base_dword_t const share_mode, mk_win_dll_advapi_security_attributes_lpct const security_attributes, mk_win_base_dword_t const creation_disposition, mk_win_base_dword_t const flags_and_attributes, mk_win_base_handle_t const template_file) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetFinalPathNameByHandleA(mk_win_base_handle_t const handle, mk_win_base_pchar_lpt const buf, mk_win_base_dword_t const len, mk_win_base_dword_t const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetDiskFreeSpaceA(mk_win_base_pchar_lpct const root_path_name, mk_win_base_dword_lpt const sectors_per_cluster, mk_win_base_dword_lpt const bytes_per_sector, mk_win_base_dword_lpt const free_clusters_count, mk_win_base_dword_lpt const total_clusters_count) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetVolumePathNameA(mk_win_base_pchar_lpct const file_path, mk_win_base_pchar_lpt const volume_path, mk_win_base_dword_t const len) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetVolumeNameForVolumeMountPointA(mk_win_base_pchar_lpct const volume_mount_point, mk_win_base_pchar_lpt const volume_name, mk_win_base_dword_t const len) mk_lang_noexcept;

mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetCurrentDirectoryW(mk_win_base_dword_t const len, mk_win_base_wchar_pt const buf) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall CreateDirectoryW(mk_win_base_wchar_lpct const path, mk_win_dll_advapi_security_attributes_lpct const security_attributes) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_uint_t mk_win_base_stdcall GetDriveTypeW(mk_win_base_wchar_lpct const path) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall FindFirstFileW(mk_win_base_wchar_lpct const name, mk_win_dll_kernel_files_w_find_data_lpt const data) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall FindNextFileW(mk_win_base_handle_t const handle, mk_win_dll_kernel_files_w_find_data_lpt const data) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall FindFirstStreamW(mk_win_base_wchar_lpct const name, mk_win_base_dword_t const level, mk_win_base_void_lpt const data, mk_win_base_dword_t const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall FindNextStreamW(mk_win_base_handle_t const handle, mk_win_base_void_lpt const data) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateFileW(mk_win_base_wchar_lpct const file_name, mk_win_base_dword_t const desired_access, mk_win_base_dword_t const share_mode, mk_win_dll_advapi_security_attributes_lpct const security_attributes, mk_win_base_dword_t const creation_disposition, mk_win_base_dword_t const flags_and_attributes, mk_win_base_handle_t const template_file) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetFinalPathNameByHandleW(mk_win_base_handle_t const handle, mk_win_base_wchar_lpt const buf, mk_win_base_dword_t const len, mk_win_base_dword_t const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetDiskFreeSpaceW(mk_win_base_wchar_lpct const root_path_name, mk_win_base_dword_lpt const sectors_per_cluster, mk_win_base_dword_lpt const bytes_per_sector, mk_win_base_dword_lpt const free_clusters_count, mk_win_base_dword_lpt const total_clusters_count) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetVolumePathNameW(mk_win_base_wchar_lpct const file_path, mk_win_base_wchar_lpt const volume_path, mk_win_base_dword_t const len) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetVolumeNameForVolumeMountPointW(mk_win_base_wchar_lpct const volume_mount_point, mk_win_base_wchar_lpt const volume_name, mk_win_base_dword_t const len) mk_lang_noexcept;

mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetLogicalDrives(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall FindClose(mk_win_base_handle_t const handle) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall ReadFile(mk_win_base_handle_t const handle, mk_win_base_void_lpt const buffer, mk_win_base_dword_t const bytes_requested, mk_win_base_dword_lpt const bytes_read, mk_win_dll_kernel_files_overlapped_lpt const overlapped) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall WriteFile(mk_win_base_handle_t const handle, mk_win_base_void_lpct const buffer, mk_win_base_dword_t const bytes_to_write, mk_win_base_dword_lpt const bytes_written, mk_win_dll_kernel_files_overlapped_lpt const overlapped) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetFileSize(mk_win_base_handle_t const handle, mk_win_base_dword_lpt const file_size_hi) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall SetFilePointer(mk_win_base_handle_t const handle, mk_win_base_slong_t const distance_lo, mk_win_base_slong_lpt const distance_hi, mk_win_base_dword_t const move_method) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SetEndOfFile(mk_win_base_handle_t const handle) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetFileType(mk_win_base_handle_t const handle) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetFileInformationByHandle(mk_win_base_handle_t const handle, mk_win_dll_kernel_files_info_by_handle_lpt const info) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall LockFile(mk_win_base_handle_t const file, mk_win_base_dword_t const file_offset_lo, mk_win_base_dword_t const file_offset_hi, mk_win_base_dword_t const number_of_bytes_to_lock_lo, mk_win_base_dword_t const number_of_bytes_to_lock_hi) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall UnlockFile(mk_win_base_handle_t const file, mk_win_base_dword_t const file_offset_lo, mk_win_base_dword_t const file_offset_hi, mk_win_base_dword_t const number_of_bytes_to_unlock_lo, mk_win_base_dword_t const number_of_bytes_to_unlock_hi) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_dll_kernel_files_a_get_current_directory(mk_win_base_dword_t const len, mk_win_base_pchar_pt const buf) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	ret = GetCurrentDirectoryA(len, buf);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_files_a_create_directory(mk_win_base_pchar_lpct const path, mk_win_dll_advapi_security_attributes_lpct const security_attributes) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = CreateDirectoryA(path, security_attributes);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_uint_t mk_win_dll_kernel_files_a_get_drive_type(mk_win_base_pchar_lpct const path) mk_lang_noexcept
{
	mk_win_base_uint_t ret;

	ret = GetDriveTypeA(path);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_dll_kernel_files_a_find_first_file(mk_win_base_pchar_lpct const name, mk_win_dll_kernel_files_a_find_data_lpt const data) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = FindFirstFileA(name, data);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_files_a_find_next_file(mk_win_base_handle_t const handle, mk_win_dll_kernel_files_a_find_data_lpt const data) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = FindNextFileA(handle, data);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_dll_kernel_files_a_create_file(mk_win_base_pchar_lpct const file_name, mk_win_base_dword_t const desired_access, mk_win_base_dword_t const share_mode, mk_win_dll_advapi_security_attributes_lpct const security_attributes, mk_win_base_dword_t const creation_disposition, mk_win_base_dword_t const flags_and_attributes, mk_win_base_handle_t const template_file) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = CreateFileA(file_name, desired_access, share_mode, security_attributes, creation_disposition, flags_and_attributes, template_file);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_dll_kernel_files_a_get_final_path_name_by_handle(mk_win_base_handle_t const handle, mk_win_base_pchar_lpt const buf, mk_win_base_dword_t const len, mk_win_base_dword_t const flags) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	ret = GetFinalPathNameByHandleA(handle, buf, len, flags);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_files_a_get_disk_free_space(mk_win_base_pchar_lpct const root_path_name, mk_win_base_dword_lpt const sectors_per_cluster, mk_win_base_dword_lpt const bytes_per_sector, mk_win_base_dword_lpt const free_clusters_count, mk_win_base_dword_lpt const total_clusters_count) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = GetDiskFreeSpaceA(root_path_name, sectors_per_cluster, bytes_per_sector, free_clusters_count, total_clusters_count);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_files_a_get_volume_path_name(mk_win_base_pchar_lpct const file_path, mk_win_base_pchar_lpt const volume_path, mk_win_base_dword_t const len) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = GetVolumePathNameA(file_path, volume_path, len);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_files_a_get_volume_name_for_volume_mount_point(mk_win_base_pchar_lpct const volume_mount_point, mk_win_base_pchar_lpt const volume_name, mk_win_base_dword_t const len) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = GetVolumeNameForVolumeMountPointA(volume_mount_point, volume_name, len);
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_dll_kernel_files_w_get_current_directory(mk_win_base_dword_t const len, mk_win_base_wchar_pt const buf) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	ret = GetCurrentDirectoryW(len, buf);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_files_w_create_directory(mk_win_base_wchar_lpct const path, mk_win_dll_advapi_security_attributes_lpct const security_attributes) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = CreateDirectoryW(path, security_attributes);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_uint_t mk_win_dll_kernel_files_w_get_drive_type(mk_win_base_wchar_lpct const path) mk_lang_noexcept
{
	mk_win_base_uint_t ret;

	ret = GetDriveTypeW(path);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_dll_kernel_files_w_find_first_file(mk_win_base_wchar_lpct const name, mk_win_dll_kernel_files_w_find_data_lpt const data) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = FindFirstFileW(name, data);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_files_w_find_next_file(mk_win_base_handle_t const handle, mk_win_dll_kernel_files_w_find_data_lpt const data) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = FindNextFileW(handle, data);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_dll_kernel_files_w_find_first_stream(mk_win_base_wchar_lpct const name, mk_win_base_dword_t const level, mk_win_base_void_lpt const data, mk_win_base_dword_t const flags) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = FindFirstStreamW(name, level, data, flags);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_files_w_find_next_stream(mk_win_base_handle_t const handle, mk_win_base_void_lpt const data) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = FindNextStreamW(handle, data);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_dll_kernel_files_w_create_file(mk_win_base_wchar_lpct const file_name, mk_win_base_dword_t const desired_access, mk_win_base_dword_t const share_mode, mk_win_dll_advapi_security_attributes_lpct const security_attributes, mk_win_base_dword_t const creation_disposition, mk_win_base_dword_t const flags_and_attributes, mk_win_base_handle_t const template_file) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = CreateFileW(file_name, desired_access, share_mode, security_attributes, creation_disposition, flags_and_attributes, template_file);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_dll_kernel_files_w_get_final_path_name_by_handle(mk_win_base_handle_t const handle, mk_win_base_wchar_lpt const buf, mk_win_base_dword_t const len, mk_win_base_dword_t const flags) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	ret = GetFinalPathNameByHandleW(handle, buf, len, flags);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_files_w_get_disk_free_space(mk_win_base_wchar_lpct const root_path_name, mk_win_base_dword_lpt const sectors_per_cluster, mk_win_base_dword_lpt const bytes_per_sector, mk_win_base_dword_lpt const free_clusters_count, mk_win_base_dword_lpt const total_clusters_count) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = GetDiskFreeSpaceW(root_path_name, sectors_per_cluster, bytes_per_sector, free_clusters_count, total_clusters_count);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_files_w_get_volume_path_name(mk_win_base_wchar_lpct const file_path, mk_win_base_wchar_lpt const volume_path, mk_win_base_dword_t const len) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = GetVolumePathNameW(file_path, volume_path, len);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_files_w_get_volume_name_for_volume_mount_point(mk_win_base_wchar_lpct const volume_mount_point, mk_win_base_wchar_lpt const volume_name, mk_win_base_dword_t const len) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = GetVolumeNameForVolumeMountPointW(volume_mount_point, volume_name, len);
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_dll_kernel_files_get_logical_drives(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	ret = GetLogicalDrives();
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_files_find_close(mk_win_base_handle_t const handle) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = FindClose(handle);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_files_read_file(mk_win_base_handle_t const handle, mk_win_base_void_lpt const buffer, mk_win_base_dword_t const bytes_requested, mk_win_base_dword_lpt const bytes_read, mk_win_dll_kernel_files_overlapped_lpt const overlapped) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = ReadFile(handle, buffer, bytes_requested, bytes_read, overlapped);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_files_write_file(mk_win_base_handle_t const handle, mk_win_base_void_lpct const buffer, mk_win_base_dword_t const bytes_to_write, mk_win_base_dword_lpt const bytes_written, mk_win_dll_kernel_files_overlapped_lpt const overlapped) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = WriteFile(handle, buffer, bytes_to_write, bytes_written, overlapped);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_dll_kernel_files_get_file_size(mk_win_base_handle_t const handle, mk_win_base_dword_lpt const file_size_hi) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	ret = GetFileSize(handle, file_size_hi);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_dll_kernel_files_set_file_pointer(mk_win_base_handle_t const handle, mk_win_base_slong_t const distance_lo, mk_win_base_slong_lpt const distance_hi, mk_win_base_dword_t const move_method) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	ret = SetFilePointer(handle, distance_lo, distance_hi, move_method);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_files_set_end_of_file(mk_win_base_handle_t const handle) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = SetEndOfFile(handle);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_dll_kernel_files_get_file_type(mk_win_base_handle_t const handle) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	ret = GetFileType(handle);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_files_get_file_information_by_handle(mk_win_base_handle_t const handle, mk_win_dll_kernel_files_info_by_handle_lpt const info) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = GetFileInformationByHandle(handle, info);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_files_lock_file(mk_win_base_handle_t const file, mk_win_base_dword_t const file_offset_lo, mk_win_base_dword_t const file_offset_hi, mk_win_base_dword_t const number_of_bytes_to_lock_lo, mk_win_base_dword_t const number_of_bytes_to_lock_hi) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = LockFile(file, file_offset_lo, file_offset_hi, number_of_bytes_to_lock_lo, number_of_bytes_to_lock_hi);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_files_unlock_file(mk_win_base_handle_t const file, mk_win_base_dword_t const file_offset_lo, mk_win_base_dword_t const file_offset_hi, mk_win_base_dword_t const number_of_bytes_to_unlock_lo, mk_win_base_dword_t const number_of_bytes_to_unlock_hi) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = UnlockFile(file, file_offset_lo, file_offset_hi, number_of_bytes_to_unlock_lo, number_of_bytes_to_unlock_hi);
	return ret;
}


#else
static void mk_win_dll_kernel_files_dummy(void){}
#endif
#endif
