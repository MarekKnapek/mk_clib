#define mk_lang_jumbo_want 1


#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_limits.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_advapi_security.h"
#include "mk_win_advapi_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_communication.h"
#include "mk_win_kernel_files.h"
#include "mk_win_kernel_handle.h"
#include "mk_win_kernel_synchronization.h"
#include "mk_win_kernel_process.h"
#include "mk_win_mt.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t wstrlenus(mk_win_base_wchar_lpct const str) mk_lang_noexcept
{
	mk_win_base_wchar_lpct ptr;
	mk_lang_types_usize_t len;

	mk_lang_assert(str);

	ptr = str;
	while(ptr[0] != L'\0')
	{
		++ptr;
	}
	len = ((mk_lang_types_usize_t)(ptr - str));
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t wstrlensi(mk_win_base_wchar_lpct const str) mk_lang_noexcept
{
	mk_lang_types_usize_t lenus;
	mk_lang_types_sint_t lensi;

	mk_lang_assert(str);

	lenus = wstrlenus(str); mk_lang_check_crash(lenus <= mk_lang_limits_sint_max);
	lensi = ((mk_lang_types_sint_t)(lenus));
	return lensi;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t enable_backup(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_luid_t backup;
	mk_win_base_handle_t token;
	mk_win_advapi_security_token_privileges_t privs;

	b = mk_win_advapi_security_lookup_privilege_value_w(mk_win_base_null, mk_win_advapi_base_privilege_name_w_se_backup, &backup); mk_lang_check_return(b != 0);
	b = mk_win_advapi_security_open_process_token(mk_win_kernel_process_get_current(), mk_win_advapi_base_right_specific_token_e_query | mk_win_advapi_base_right_specific_token_e_adjust_privileges, &token); mk_lang_check_return(b != 0);
	privs.m_count = 1;
	privs.m_privileges[0].m_luid = backup;
	privs.m_privileges[0].m_attributes = mk_win_advapi_security_privilege_attribute_e_enabled;
	b = mk_win_advapi_security_adjust_token_privileges(token, mk_win_base_false, &privs, 0, mk_win_base_null, mk_win_base_null); mk_lang_check_return(b != 0);
	b = mk_win_kernel_handle_close_handle(token); mk_lang_check_return(b != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t open_volume(mk_win_base_wchar_pct const file_path, mk_win_base_handle_pt const volume) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_wchar_t volume_mount_point[1024];
	mk_win_base_wchar_t volume_name[1024];
	mk_lang_types_sint_t len;
	mk_win_base_handle_t vol;

	mk_lang_assert(file_path);
	mk_lang_assert(file_path[0] != L'\0');
	mk_lang_assert(volume);

	b = GetVolumePathNameW(file_path, &volume_mount_point[0], mk_lang_countof(volume_mount_point)); mk_lang_check_return(b != 0);
	b = GetVolumeNameForVolumeMountPointW(volume_mount_point, &volume_name[0], mk_lang_countof(volume_name)); mk_lang_check_return(b != 0);
	len = wstrlensi(volume_name); mk_lang_check_return(len >= 2);
	if(volume_name[len - 1] == L'\\')
	{
		volume_name[len - 1] = L'\0';
		--len;
	}
	vol = mk_win_kernel_files_w_create_file(volume_name, mk_win_advapi_base_right_generic_e_read, mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_write | mk_win_kernel_files_share_e_delete, mk_win_base_null, mk_win_kernel_files_create_e_open_existing, mk_win_kernel_files_flag_e_none, mk_win_base_handle_null_g); mk_lang_check_return(vol.m_data != mk_win_base_handle_invalid);
	*volume = vol;
	return 0;
}


mk_lang_types_sint_t wmain(mk_lang_types_sint_t const argc, mk_win_base_wchar_pct const* const argv)
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_win_base_wchar_pct path;
	mk_win_base_handle_t volume;
	mk_win_kernel_communication_mark_handle_info_data_t mark;
	mk_win_base_handle_t file;
	mk_win_base_bool_t b;
	mk_win_base_dword_t nwritten;
	mk_win_base_dword_t waited;

	if(argc >= 2)
	{
		err = enable_backup(); mk_lang_check_rereturn(err);
		n = argc - 1;
		for(i = 0; i != n; ++i)
		{
			path = argv[1 + i];
			err = open_volume(path, &volume); mk_lang_check_rereturn(err);
			mark.m_usn_source_info_or_copy_number = mk_win_kernel_communication_usn_source_id_e_data_management;
			mark.m_volume = volume;
			mark.m_handle_info = mk_win_kernel_communication_mark_handle_id_e_protect_clusters;
			file = mk_win_kernel_files_w_create_file(path, mk_win_advapi_base_right_specific_file_e_read_attributes, mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_write | mk_win_kernel_files_share_e_delete, mk_win_base_null, mk_win_kernel_files_create_e_open_existing, mk_win_kernel_files_flag_e_backup_semantics, mk_win_base_handle_null_g); mk_lang_check_return(file.m_data != mk_win_base_handle_invalid);
			b = mk_win_kernel_communication_device_io_control(file, mk_win_kernel_communication_ioctl_id_e_fsctl_mark_handle, &mark, ((mk_lang_types_sint_t)(sizeof(mark))), mk_win_base_null, 0, &nwritten, mk_win_base_null); mk_lang_check_return(b != 0 && nwritten == 0);
		}
		waited = mk_win_kernel_synchronization_wait_for_single_object(mk_win_kernel_process_get_current(), mk_win_kernel_synchronization_infinite); mk_lang_check_return(0);
	}
}
