#include "mk_lib_fe.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_exception.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_kernel_errors.h"
#include "mk_win_kernel_files.h"
#include "mk_win_main_heap.h"
#include "mk_win_tstring.h"


typedef int* int_pt;
typedef int const* int_pct;


static mk_win_tstring_tchar_t const s_mk_lib_fe_up[] = mk_win_tstring_tchar_c("> ..");


static mk_lang_inline void mk_lib_fe_go_to_item_all(mk_lib_fe_lpt const fe) mk_lang_noexcept;
static mk_lang_inline void mk_lib_fe_go_to_item_up(mk_lib_fe_lpt const fe) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_bool_t mk_lib_fe_go_to_item_roots(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_to_item_folders(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_to_item_err_path_not_found(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_to_item_err_access_denied(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_to_item_err_not_ready(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_short_str_roots(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_short_str_folders(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_short_str_err_path_not_found(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_short_str_err_access_denied(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_short_str_err_not_ready(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline int mk_lib_fe_get_name_short_str_len_roots(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline int mk_lib_fe_get_name_short_str_len_folders(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline int mk_lib_fe_get_name_short_str_len_err_path_not_found(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline int mk_lib_fe_get_name_short_str_len_err_access_denied(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline int mk_lib_fe_get_name_short_str_len_err_not_ready(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_long_str_roots(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_long_str_folders(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_long_str_err_path_not_found(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_long_str_err_access_denied(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_long_str_err_not_ready(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_inline void mk_lib_fe_resize(mk_win_base_void_lpt* const ptr, mk_win_base_size_t* const curr_size, mk_win_base_size_t const requested_size) mk_lang_noexcept;
static mk_lang_inline int mk_lib_fe_ensure_has_length(mk_win_kernel_files_t_find_data_lpt const data) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_is_sorted(mk_win_kernel_files_t_find_data_lpct const a, mk_win_kernel_files_t_find_data_lpct const b) mk_lang_noexcept;
static mk_lang_inline void mk_lib_fe_sort_merge(mk_win_kernel_files_t_find_data_lpct const data, int_pct const input_a, int const cnt_a, int_pt const input_b, int const cnt_b, int_pt const output) mk_lang_noexcept;
static mk_lang_inline void mk_lib_fe_sort_recursive(mk_win_kernel_files_t_find_data_lpct const data, int_pt const input, int const cnt, int_pt const tmp, int_pt const output) mk_lang_noexcept;
static mk_lang_inline void mk_lib_fe_sort(mk_lib_fe_lpt const fe) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_size_t mk_lib_fe_get_size(void) mk_lang_noexcept
{
	mk_win_base_size_t size;

	size = sizeof(mk_lib_fe_t);
	return size;
}

mk_lang_jumbo void mk_lib_fe_construct(mk_lib_fe_lpt const fe) mk_lang_noexcept
{
	mk_lang_assert(fe);

	fe->m_state = mk_lib_fe_state_e_init;
	fe->m_str = mk_win_base_null;
	fe->m_str_capacity = 0;
	fe->m_str_len = 0;
	fe->m_addon_len = 0;
	fe->m_strs = mk_win_base_null;
	fe->m_strs_capacity = 0;
	fe->m_strs_count = 0;
	fe->m_sort = mk_win_base_null;
	fe->m_sort_capacity = 0;
}

mk_lang_jumbo void mk_lib_fe_destroy(mk_lib_fe_lpt const fe) mk_lang_noexcept
{
	mk_win_main_heap_deallocate(fe->m_str, fe->m_str_capacity);
	mk_win_main_heap_deallocate(fe->m_strs, fe->m_strs_capacity);
	mk_win_main_heap_deallocate(fe->m_sort, fe->m_sort_capacity);
}

mk_lang_nodiscard mk_lang_jumbo mk_lib_fe_state_t mk_lib_fe_get_state(mk_lib_fe_lpct const fe) mk_lang_nodiscard
{
	mk_lib_fe_state_t state;

	mk_lang_assert(fe);

	state = fe->m_state;
	return state;
}

mk_lang_jumbo void mk_lib_fe_go_to_root(mk_lib_fe_lpt const fe) mk_lang_noexcept
{
	mk_win_base_dword_t drives;
	int cnt;
	int n;
	int i;

	mk_lang_assert(fe);

	fe->m_state = mk_lib_fe_state_e_roots;
	drives = mk_win_kernel_files_get_logical_drives(); mk_lang_assert(drives != 0);
	fe->m_drives_mask = drives;
	cnt = 0;
	n = 'z' - 'a' + 1;
	for(i = 0; i != n; ++i)
	{
		if((drives & 0x01) != 0)
		{
			++cnt;
		}
		drives >>= 1;
	}
	mk_lang_assert(drives == 0);
	fe->m_drives_count = cnt;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lib_fe_go_to_item(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);

	switch(fe->m_state)
	{
		case mk_lib_fe_state_e_init: mk_lang_assert(0); break;
		case mk_lib_fe_state_e_roots: return mk_lib_fe_go_to_item_roots(fe, idx); break;
		case mk_lib_fe_state_e_folders: return mk_lib_fe_go_to_item_folders(fe, idx); break;
		case mk_lib_fe_state_e_err_path_not_found: return mk_lib_fe_go_to_item_err_path_not_found(fe, idx); break;
		case mk_lib_fe_state_e_err_access_denied: return mk_lib_fe_go_to_item_err_access_denied(fe, idx); break;
		case mk_lib_fe_state_e_err_not_ready: return mk_lib_fe_go_to_item_err_not_ready(fe, idx); break;
	}
	mk_lang_assert(0);
}

mk_lang_nodiscard mk_lang_jumbo int mk_lib_fe_get_count(mk_lib_fe_lpt const fe) mk_lang_noexcept
{
	mk_lang_assert(fe);

	switch(fe->m_state)
	{
		case mk_lib_fe_state_e_init: mk_lang_assert(0); break;
		case mk_lib_fe_state_e_roots: return fe->m_drives_count; break;
		case mk_lib_fe_state_e_folders: return fe->m_strs_count + 1; break;
		case mk_lib_fe_state_e_err_path_not_found: return 1; break;
		case mk_lib_fe_state_e_err_access_denied: return 1; break;
		case mk_lib_fe_state_e_err_not_ready: return 1; break;
	}
	mk_lang_assert(0);
}

mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tchar_lpct mk_lib_fe_get_name_short_str(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);

	switch(fe->m_state)
	{
		case mk_lib_fe_state_e_init: mk_lang_assert(0); break;
		case mk_lib_fe_state_e_roots: return mk_lib_fe_get_name_short_str_roots(fe, idx); break;
		case mk_lib_fe_state_e_folders: return mk_lib_fe_get_name_short_str_folders(fe, idx); break;
		case mk_lib_fe_state_e_err_path_not_found: return mk_lib_fe_get_name_short_str_err_path_not_found(fe, idx); break;
		case mk_lib_fe_state_e_err_access_denied: return mk_lib_fe_get_name_short_str_err_access_denied(fe, idx); break;
		case mk_lib_fe_state_e_err_not_ready: return mk_lib_fe_get_name_short_str_err_not_ready(fe, idx); break;
	}
	mk_lang_assert(0);
}

mk_lang_nodiscard mk_lang_jumbo int mk_lib_fe_get_name_short_str_len(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);

	switch(fe->m_state)
	{
		case mk_lib_fe_state_e_init: mk_lang_assert(0); break;
		case mk_lib_fe_state_e_roots: return mk_lib_fe_get_name_short_str_len_roots(fe, idx); break;
		case mk_lib_fe_state_e_folders: return mk_lib_fe_get_name_short_str_len_folders(fe, idx); break;
		case mk_lib_fe_state_e_err_path_not_found: return mk_lib_fe_get_name_short_str_len_err_path_not_found(fe, idx); break;
		case mk_lib_fe_state_e_err_access_denied: return mk_lib_fe_get_name_short_str_len_err_access_denied(fe, idx); break;
		case mk_lib_fe_state_e_err_not_ready: return mk_lib_fe_get_name_short_str_len_err_not_ready(fe, idx); break;
	}
	mk_lang_assert(0);
}

mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tchar_lpct mk_lib_fe_get_name_long_str(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);

	switch(fe->m_state)
	{
		case mk_lib_fe_state_e_init: mk_lang_assert(0); break;
		case mk_lib_fe_state_e_roots: return mk_lib_fe_get_name_long_str_roots(fe, idx); break;
		case mk_lib_fe_state_e_folders: return mk_lib_fe_get_name_long_str_folders(fe, idx); break;
		case mk_lib_fe_state_e_err_path_not_found: return mk_lib_fe_get_name_long_str_err_path_not_found(fe, idx); break;
		case mk_lib_fe_state_e_err_access_denied: return mk_lib_fe_get_name_long_str_err_access_denied(fe, idx); break;
		case mk_lib_fe_state_e_err_not_ready: return mk_lib_fe_get_name_long_str_err_not_ready(fe, idx); break;
	}
	mk_lang_assert(0);
}

mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tchar_lpct mk_lib_fe_get_type_str(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);

	switch(fe->m_state)
	{
		case mk_lib_fe_state_e_init: mk_lang_assert(0); break;
		case mk_lib_fe_state_e_roots: return mk_win_tstring_tchar_c("drive"); break;
		case mk_lib_fe_state_e_folders:
		{
			if(idx == 0)
			{
				return mk_win_tstring_tchar_c("");
			}
			else
			{
				return mk_win_tstring_tchar_c("file or directory"); break; /* todo */
			}
		}
		break;
		case mk_lib_fe_state_e_err_path_not_found: return mk_win_tstring_tchar_c("error"); break;
		case mk_lib_fe_state_e_err_access_denied: return mk_win_tstring_tchar_c("error"); break;
		case mk_lib_fe_state_e_err_not_ready: return mk_win_tstring_tchar_c("error"); break;
	}
	mk_lang_assert(0);
}

mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tchar_lpct mk_lib_fe_get_detail_str(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_win_base_size_t s;
	mk_win_tstring_tchar_lpt drive_str;
	mk_win_base_uint_t drive_type;

	mk_lang_assert(fe);

	switch(fe->m_state)
	{
		case mk_lib_fe_state_e_init:
		{
			mk_lang_assert(0);
		}
		break;
		case mk_lib_fe_state_e_roots:
		{
			s = sizeof(mk_win_tstring_tchar_t);
			mk_lib_fe_resize(&fe->m_str, &fe->m_str_capacity, (3 + 1) * s); mk_lang_assert(fe->m_str); mk_lang_assert(fe->m_str_capacity >= (3 + 1) * s);
			drive_str = ((mk_win_tstring_tchar_lpt)(mk_lib_fe_get_name_short_str(fe, idx))); mk_lang_assert(drive_str); mk_lang_assert(*drive_str);
			drive_str[2] = mk_win_tstring_tchar_c('\\');
			drive_str[3] = mk_win_tstring_tchar_c('\0');
			drive_type = mk_win_kernel_files_t_get_drive_type(drive_str);
			drive_str[2] = mk_win_tstring_tchar_c('\0');
			switch(drive_type)
			{
				case mk_win_kernel_files_drive_type_e_unknown: return mk_win_tstring_tchar_c("unknown"); break;
				case mk_win_kernel_files_drive_type_e_no_root_dir: return mk_win_tstring_tchar_c("invalid"); break;
				case mk_win_kernel_files_drive_type_e_removable: return mk_win_tstring_tchar_c("removable"); break;
				case mk_win_kernel_files_drive_type_e_fixed: return mk_win_tstring_tchar_c("fixed"); break;
				case mk_win_kernel_files_drive_type_e_remote: return mk_win_tstring_tchar_c("remote"); break;
				case mk_win_kernel_files_drive_type_e_cdrom: return mk_win_tstring_tchar_c("cd rom"); break;
				case mk_win_kernel_files_drive_type_e_ramdisk: return mk_win_tstring_tchar_c("ram disk"); break;
				default: return mk_win_tstring_tchar_c("???"); break; /* todo display number */
			}
		}
		break;
		case mk_lib_fe_state_e_folders:
		{
			if(idx == 0)
			{
				return mk_win_tstring_tchar_c("");
			}
			else
			{
				return mk_win_tstring_tchar_c("???"); /* todo */
			}
		}
		break;
		case mk_lib_fe_state_e_err_path_not_found: return mk_win_tstring_tchar_c("path not found"); break;
		case mk_lib_fe_state_e_err_access_denied: return mk_win_tstring_tchar_c("access denied"); break;
		case mk_lib_fe_state_e_err_not_ready: return mk_win_tstring_tchar_c("device is not ready"); break;
	}
	mk_lang_assert(0);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lib_fe_has_attributes(mk_lib_fe_lpct const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);

	switch(fe->m_state)
	{
		case mk_lib_fe_state_e_init: mk_lang_assert(0); break;
		case mk_lib_fe_state_e_roots: return mk_lang_false; break;
		case mk_lib_fe_state_e_folders: return (idx == 0) ? mk_lang_false : mk_lang_true; break;
		case mk_lib_fe_state_e_err_path_not_found: return mk_lang_false; break;
		case mk_lib_fe_state_e_err_access_denied: return mk_lang_false; break;
		case mk_lib_fe_state_e_err_not_ready: return mk_lang_false; break;
	}
	mk_lang_assert(0);
}

mk_lang_nodiscard mk_lang_jumbo mk_win_kernel_files_attribute_t mk_lib_fe_get_attributes(mk_lib_fe_lpct const fe, int const idx) mk_lang_noexcept
{
	int ridx;
	mk_win_kernel_files_t_find_data_lpct data;
	mk_win_kernel_files_attribute_t attributes;

	mk_lang_assert(fe);
	mk_lang_assert(mk_lib_fe_has_attributes(fe, idx));

	ridx = ((int_pt)(fe->m_sort))[idx - 1];
	data = ((mk_win_kernel_files_t_find_data_lpct)(fe->m_strs));
	attributes = data[ridx].m_attributes;
	return attributes;
}


static mk_lang_inline void mk_lib_fe_go_to_item_all(mk_lib_fe_lpt const fe) mk_lang_noexcept
{
	mk_win_base_size_t s;
	mk_win_kernel_files_t_find_data_lpt data;
	mk_win_base_handle_t handle;
	mk_win_kernel_errors_id_t err;
	mk_win_base_bool_t closed;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_str);
	mk_lang_assert(fe->m_str_len >= 4);

	s = sizeof(mk_win_kernel_files_t_find_data_t);
	fe->m_strs_count = 0;
	mk_lib_fe_resize(&fe->m_strs, &fe->m_strs_capacity, (fe->m_strs_count + 1) * s); mk_lang_assert(fe->m_strs); mk_lang_assert(fe->m_strs_capacity >= (fe->m_strs_count + 1) * s);
	data = ((mk_win_kernel_files_t_find_data_lpt)(fe->m_strs));
	handle = mk_win_kernel_files_t_find_first_file(fe->m_str, data);
	if(handle == s_mk_win_base_handle_invalid)
	{
		err = ((mk_win_kernel_errors_id_t)(mk_win_kernel_errors_get_last()));
		if(err == mk_win_kernel_errors_id_e_path_not_found) fe->m_state = mk_lib_fe_state_e_err_path_not_found;
		else if(err == mk_win_kernel_errors_id_e_access_denied) fe->m_state = mk_lib_fe_state_e_err_access_denied;
		else if(err == mk_win_kernel_errors_id_e_not_ready) fe->m_state = mk_lib_fe_state_e_err_not_ready;
		else
		{
			/* todo */
		}
	}
	else
	{
		for(;;)
		{
			if
			(
				(data->m_name[0] == mk_win_tstring_tchar_c('.') && data->m_name[1] == mk_win_tstring_tchar_c('\0')) ||
				(data->m_name[0] == mk_win_tstring_tchar_c('.') && data->m_name[1] == mk_win_tstring_tchar_c('.') && data->m_name[2] == mk_win_tstring_tchar_c('\0'))
			)
			{
				--fe->m_strs_count;
			}
			++fe->m_strs_count;
			data->m_reserved_1 = 0;
			mk_lib_fe_resize(&fe->m_strs, &fe->m_strs_capacity, (fe->m_strs_count + 1) * s); mk_lang_assert(fe->m_strs); mk_lang_assert(fe->m_strs_capacity >= (fe->m_strs_count + 1) * s);
			data = ((mk_win_kernel_files_t_find_data_lpt)(fe->m_strs)) + fe->m_strs_count;
			if(mk_win_kernel_files_t_find_next_file(handle, data) == 0)
			{
				err = ((mk_win_kernel_errors_id_t)(mk_win_kernel_errors_get_last()));
				if(err != mk_win_kernel_errors_id_e_no_more_files)
				{
					/* todo */
				}
				break;
			}
		}
		closed = mk_win_kernel_files_find_close(handle); mk_lang_assert(closed != 0);
		mk_lib_fe_sort(fe);
	}
}

static mk_lang_inline void mk_lib_fe_go_to_item_up(mk_lib_fe_lpt const fe) mk_lang_noexcept
{
	mk_win_tstring_tchar_lpct ptr;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state != mk_lib_fe_state_e_init);
	mk_lang_assert(fe->m_state != mk_lib_fe_state_e_roots);

	fe->m_str_len -= fe->m_addon_len;
	fe->m_addon_len = 0;
	if(fe->m_str_len == 2)
	{
		mk_lib_fe_go_to_root(fe);
	}
	else
	{
		fe->m_state = mk_lib_fe_state_e_folders;
		for(ptr = fe->m_str + fe->m_str_len - 2; *ptr != mk_win_tstring_tchar_c('\\'); --ptr){}
		fe->m_str_len -= ((int)(fe->m_str + fe->m_str_len - ptr));
		fe->m_str[fe->m_str_len + 1] = mk_win_tstring_tchar_c('*');
		fe->m_str[fe->m_str_len + 2] = mk_win_tstring_tchar_c('\0');
		fe->m_str_len += 2;
		fe->m_addon_len = 2;
		mk_lib_fe_go_to_item_all(fe);
	}
}

static mk_lang_nodiscard mk_lang_bool_t mk_lib_fe_go_to_item_roots(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_win_base_size_t s;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_roots);
	mk_lang_assert(idx >= 0 && idx < fe->m_drives_count);

	s = sizeof(mk_win_tstring_tchar_t);
	mk_lib_fe_resize(&fe->m_str, &fe->m_str_capacity, (4 + 1) * s); mk_lang_assert(fe->m_str); mk_lang_assert(fe->m_str_capacity >= (4 + 1) * s);
	((void)(mk_lib_fe_get_name_short_str(fe, idx)));
	fe->m_str[2] = mk_win_tstring_tchar_c('\\');
	fe->m_str[3] = mk_win_tstring_tchar_c('*');
	fe->m_str[4] = mk_win_tstring_tchar_c('\0');
	fe->m_str_len = 4;
	fe->m_addon_len = 2;
	fe->m_state = mk_lib_fe_state_e_folders;
	mk_lib_fe_go_to_item_all(fe);
	return mk_lang_true;
}

static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_to_item_folders(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	int ridx;
	mk_win_kernel_files_t_find_data_lpt data;
	int name_len;
	mk_win_base_size_t s;
	int i;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_folders);
	mk_lang_assert(idx >= 0 && idx < fe->m_strs_count + 1);

	if(idx == 0)
	{
		mk_lib_fe_go_to_item_up(fe);
		return mk_lang_true;
	}
	else
	{
		ridx = ((int_pt)(fe->m_sort))[idx - 1];
		data = ((mk_win_kernel_files_t_find_data_lpt)(fe->m_strs)) + ridx;
		if((data->m_attributes & mk_win_kernel_files_attribute_e_directory) != 0)
		{
			name_len = mk_lib_fe_ensure_has_length(data);
			s = sizeof(mk_win_tstring_tchar_t);
			fe->m_str_len -= fe->m_addon_len;
			mk_lib_fe_resize(&fe->m_str, &fe->m_str_capacity, (fe->m_str_len + 1 + name_len + 2 + 1) * s); mk_lang_assert(fe->m_str); mk_lang_assert(fe->m_str_capacity >= (fe->m_str_len + 1 + name_len + 2 + 1) * s);
			fe->m_str[fe->m_str_len] = mk_win_tstring_tchar_c('\\');
			for(i = 0; i != name_len; ++i){ fe->m_str[fe->m_str_len + 1 + i] = data->m_name[i]; }
			fe->m_str[fe->m_str_len + 1 + name_len + 0] = mk_win_tstring_tchar_c('\\');
			fe->m_str[fe->m_str_len + 1 + name_len + 1] = mk_win_tstring_tchar_c('*');
			fe->m_str[fe->m_str_len + 1 + name_len + 2] = mk_win_tstring_tchar_c('\0');
			fe->m_str_len += (1 + name_len + 2);
			fe->m_addon_len = 2;
			mk_lib_fe_go_to_item_all(fe);
			return mk_lang_true;
		}
		else
		{
			return mk_lang_false;
		}
	}
}

static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_to_item_err_path_not_found(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_err_path_not_found);
	mk_lang_assert(idx == 0);

	mk_lib_fe_go_to_item_up(fe);
	return mk_lang_true;
}

static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_to_item_err_access_denied(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_err_access_denied);
	mk_lang_assert(idx == 0);

	mk_lib_fe_go_to_item_up(fe);
	return mk_lang_true;
}

static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_to_item_err_not_ready(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_err_not_ready);
	mk_lang_assert(idx == 0);

	mk_lib_fe_go_to_item_up(fe);
	return mk_lang_true;
}

static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_short_str_roots(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_win_base_dword_t drives;
	int cnt;
	int n;
	int i;
	mk_win_base_size_t s;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_roots);
	mk_lang_assert(idx >= 0 && idx < 'z' - 'a' + 1);

	drives = fe->m_drives_mask;
	cnt = 0;
	n = 'z' - 'a' + 1;
	for(i = 0; i != n; ++i)
	{
		if((drives & 0x01) != 0)
		{
			if(cnt == idx)
			{
				s = sizeof(mk_win_tstring_tchar_t);
				mk_lib_fe_resize(&fe->m_str, &fe->m_str_capacity, (2 + 1) * s); mk_lang_assert(fe->m_str); mk_lang_assert(fe->m_str_capacity >= (2 + 1) * s);
				fe->m_str[0] = ((mk_win_tstring_tchar_t)(mk_win_tstring_tchar_c('a') + i));
				fe->m_str[1] = mk_win_tstring_tchar_c(':');
				fe->m_str[2] = mk_win_tstring_tchar_c('\0');
				fe->m_str_len = 2;
				fe->m_addon_len = 0;
				return fe->m_str;
			}
			++cnt;
		}
		drives >>= 1;
	}
	mk_lang_assert(0);
}

static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_short_str_folders(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	int ridx;
	mk_win_kernel_files_t_find_data_lpt data;
	mk_win_base_size_t s;
	int name_len;
	int i;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_folders);
	mk_lang_assert(idx >= 0 && idx < fe->m_strs_count + 1);

	if(idx == 0)
	{
		return s_mk_lib_fe_up;
	}
	else
	{
		ridx = ((int_pt)(fe->m_sort))[idx - 1];
		data = ((mk_win_kernel_files_t_find_data_lpt)(fe->m_strs)) + ridx;
		if((data->m_attributes & mk_win_kernel_files_attribute_e_directory) != 0)
		{
			name_len = mk_lib_fe_ensure_has_length(data);
			s = sizeof(mk_win_tstring_tchar_t);
			mk_lib_fe_resize(&fe->m_str, &fe->m_str_capacity, (fe->m_str_len + 1 + 2 + name_len + 1) * s); mk_lang_assert(fe->m_str); mk_lang_assert(fe->m_str_capacity >= (fe->m_str_len + 1 + 2 + name_len + 1) * s);
			fe->m_str[fe->m_str_len + 1] = mk_win_tstring_tchar_c('>'); /* todo create dir prefix constant */
			fe->m_str[fe->m_str_len + 2] = mk_win_tstring_tchar_c(' ');
			for(i = 0; i != name_len + 1; ++i){ fe->m_str[fe->m_str_len + 3 + i] = data->m_name[i]; }
			return fe->m_str + fe->m_str_len + 1;
		}
		else
		{
			return ((mk_win_kernel_files_t_find_data_lpct)(fe->m_strs))[ridx].m_name;
		}
	}
}

static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_short_str_err_path_not_found(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_err_path_not_found);
	mk_lang_assert(idx == 0);

	return s_mk_lib_fe_up;
}

static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_short_str_err_access_denied(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_err_access_denied);
	mk_lang_assert(idx == 0);

	return s_mk_lib_fe_up;
}

static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_short_str_err_not_ready(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_err_not_ready);
	mk_lang_assert(idx == 0);

	return s_mk_lib_fe_up;
}

static mk_lang_nodiscard mk_lang_inline int mk_lib_fe_get_name_short_str_len_roots(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_roots);
	mk_lang_assert(idx >= 0 && idx < 'z' - 'a' + 1);

	return 2;
}

static mk_lang_nodiscard mk_lang_inline int mk_lib_fe_get_name_short_str_len_folders(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	int ridx;
	mk_win_kernel_files_t_find_data_lpt data;
	int name_len;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_folders);
	mk_lang_assert(idx >= 0 && idx < fe->m_strs_count + 1);

	if(idx == 0)
	{
		return ((int)(sizeof(s_mk_lib_fe_up) / sizeof(s_mk_lib_fe_up[0]) - 1));
	}
	else
	{
		ridx = ((int_pt)(fe->m_sort))[idx - 1];
		data = ((mk_win_kernel_files_t_find_data_lpt)(fe->m_strs)) + ridx;
		name_len = mk_lib_fe_ensure_has_length(data); mk_lang_assert(name_len > 0);
		if((data->m_attributes & mk_win_kernel_files_attribute_e_directory) != 0)
		{
			return name_len + 2; /* todo create dir prefxi constant */
		}
		else
		{
			return name_len;
		}
	}
}

static mk_lang_nodiscard mk_lang_inline int mk_lib_fe_get_name_short_str_len_err_path_not_found(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_err_path_not_found);
	mk_lang_assert(idx == 0);

	return ((int)(sizeof(s_mk_lib_fe_up) / sizeof(s_mk_lib_fe_up[0]) - 1));
}

static mk_lang_nodiscard mk_lang_inline int mk_lib_fe_get_name_short_str_len_err_access_denied(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_err_access_denied);
	mk_lang_assert(idx == 0);

	return ((int)(sizeof(s_mk_lib_fe_up) / sizeof(s_mk_lib_fe_up[0]) - 1));
}

static mk_lang_nodiscard mk_lang_inline int mk_lib_fe_get_name_short_str_len_err_not_ready(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_err_not_ready);
	mk_lang_assert(idx == 0);

	return ((int)(sizeof(s_mk_lib_fe_up) / sizeof(s_mk_lib_fe_up[0]) - 1));
}

static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_long_str_roots(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_roots);

	return mk_lib_fe_get_name_short_str_roots(fe, idx);
}

static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_long_str_folders(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	int ridx;
	mk_win_kernel_files_t_find_data_lpt data;
	int name_len;
	mk_win_base_size_t s;
	int i;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_folders);
	mk_lang_assert(idx >= 0 && idx < fe->m_strs_count + 1);

	if(idx == 0)
	{
		return s_mk_lib_fe_up;
	}
	else
	{
		ridx = ((int_pt)(fe->m_sort))[idx - 1];
		data = ((mk_win_kernel_files_t_find_data_lpt)(fe->m_strs)) + ridx;
		name_len = mk_lib_fe_ensure_has_length(data);
		fe->m_str_len -= fe->m_addon_len;
		s = sizeof(mk_win_tstring_tchar_t);
		mk_lib_fe_resize(&fe->m_str, &fe->m_str_capacity, (fe->m_str_len + 1 + name_len + 1) * s); mk_lang_assert(fe->m_str); mk_lang_assert(fe->m_str_capacity >= (fe->m_str_len + 1 + name_len + 1) * s);
		fe->m_str[fe->m_str_len] = mk_win_tstring_tchar_c('\\');
		for(i = 0; i != name_len + 1; ++i){ fe->m_str[fe->m_str_len + 1 + i] = data->m_name[i]; }
		fe->m_str_len += (1 + name_len);
		fe->m_addon_len = (1 + name_len);
		return fe->m_str;
	}
}

static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_long_str_err_path_not_found(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_err_path_not_found);
	mk_lang_assert(idx == 0);

	fe->m_str_len -= fe->m_addon_len;
	fe->m_addon_len = 0;
	fe->m_str[fe->m_str_len] = mk_win_tstring_tchar_c('\0');
	return fe->m_str;
}

static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_long_str_err_access_denied(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_err_access_denied);
	mk_lang_assert(idx == 0);

	fe->m_str_len -= fe->m_addon_len;
	fe->m_addon_len = 0;
	fe->m_str[fe->m_str_len] = mk_win_tstring_tchar_c('\0');
	return fe->m_str;
}

static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_long_str_err_not_ready(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_err_not_ready);
	mk_lang_assert(idx == 0);

	fe->m_str_len -= fe->m_addon_len;
	fe->m_addon_len = 0;
	fe->m_str[fe->m_str_len] = mk_win_tstring_tchar_c('\0');
	return fe->m_str;
}

static mk_lang_inline void mk_lib_fe_resize(mk_win_base_void_lpt* const ptr, mk_win_base_size_t* const curr_size, mk_win_base_size_t const requested_size) mk_lang_noexcept
{
	mk_win_base_size_t new_size;
	mk_lang_exception_t ex;

	mk_lang_assert(ptr);
	mk_lang_assert(curr_size);
	mk_lang_assert(*ptr || *curr_size == 0);

	if(requested_size > *curr_size)
	{
		new_size = *curr_size;
		if(new_size == 0) new_size = sizeof(mk_win_base_void_lpct);
		do
		{
			new_size *= 2;
		}while(new_size < requested_size);
		mk_lang_exception_make_none(&ex);
		if(!*ptr)
		{
			mk_win_main_heap_allocate(&ex, new_size, ptr);
		}
		else
		{
			mk_win_main_heap_reallocate(&ex, *ptr, *curr_size, new_size, ptr);
		}
		mk_lang_assert(!mk_lang_exception_is(&ex)); /* todo throw */
		*curr_size = new_size;
	}
}

static mk_lang_inline int mk_lib_fe_ensure_has_length(mk_win_kernel_files_t_find_data_lpt const data) mk_lang_noexcept
{
	mk_win_tstring_tchar_lpct name;
	int name_len;

	mk_lang_assert(data);

	if(((int)(data->m_reserved_1)) == 0)
	{
		name = data->m_name;
		mk_lang_assert(*name);
		name_len = 0;
		do{ ++name_len; }while(name[name_len]);
		data->m_reserved_1 = name_len;
	}
	return ((int)(data->m_reserved_1));
}

static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_is_sorted(mk_win_kernel_files_t_find_data_lpct const a, mk_win_kernel_files_t_find_data_lpct const b) mk_lang_noexcept
{
	mk_lang_bool_t is_dir_a;
	mk_lang_bool_t is_dir_b;
	mk_win_tstring_tchar_lpct name_a;
	mk_win_tstring_tchar_lpct name_b;
	mk_win_tstring_tchar_t ch_a;
	mk_win_tstring_tchar_t ch_b;

	mk_lang_assert(a);
	mk_lang_assert(b);

	is_dir_a = ((a->m_attributes & mk_win_kernel_files_attribute_e_directory) != 0);
	is_dir_b = ((b->m_attributes & mk_win_kernel_files_attribute_e_directory) != 0);
	if(is_dir_a && !is_dir_b)
	{
		return mk_lang_true;
	}
	else if(!is_dir_a && is_dir_b)
	{
		return mk_lang_false;
	}
	else
	{
		mk_lang_assert((is_dir_a && is_dir_b) || (!is_dir_a && !is_dir_b));
		name_a = a->m_name;
		name_b = b->m_name;
		while(*name_a && *name_b)
		{
			ch_a = *name_a;
			ch_b = *name_b;
			if(ch_a >= mk_win_tstring_tchar_c('A') && ch_a <= mk_win_tstring_tchar_c('Z'))
			{
				ch_a = mk_win_tstring_tchar_c('a') + (ch_a - mk_win_tstring_tchar_c('A'));
			}
			if(ch_b >= mk_win_tstring_tchar_c('A') && ch_b <= mk_win_tstring_tchar_c('Z'))
			{
				ch_b = mk_win_tstring_tchar_c('a') + (ch_b - mk_win_tstring_tchar_c('A'));
			}
			if(ch_a < ch_b)
			{
				return mk_lang_true;
			}
			else if(ch_b < ch_a)
			{
				return mk_lang_false;
			}
			else
			{
				mk_lang_assert(ch_a == ch_b);
			}
			++name_a;
			++name_b;
		}
		return !*name_a;
	}
}

static mk_lang_inline void mk_lib_fe_sort_merge(mk_win_kernel_files_t_find_data_lpct const data, int_pct const input_a, int const cnt_a, int_pt const input_b, int const cnt_b, int_pt const output) mk_lang_noexcept
{
	int idx_a;
	int idx_b;
	int idx_o;

	mk_lang_assert(data);
	mk_lang_assert(input_a);
	mk_lang_assert(cnt_a >= 1);
	mk_lang_assert(input_b);
	mk_lang_assert(cnt_b >= 1);
	mk_lang_assert(output);
	mk_lang_assert(!(input_a >= input_b && input_a < input_b + cnt_b));
	mk_lang_assert(!(input_b >= input_a && input_b < input_a + cnt_a));
	mk_lang_assert(!(input_a >= output && input_a < output + cnt_a + cnt_b));
	mk_lang_assert(!(output >= input_a && output < input_a + cnt_a));
	mk_lang_assert(!(input_b >= output && input_b < output + cnt_a + cnt_b));
	mk_lang_assert(!(output >= input_b && output < input_b + cnt_b));

	idx_a = 0;
	idx_b = 0;
	idx_o = 0;
	while(idx_a != cnt_a && idx_b != cnt_b)
	{
		if(mk_lib_fe_is_sorted(&data[input_a[idx_a]], &data[input_b[idx_b]]))
		{
			output[idx_o++] = input_a[idx_a++];
		}
		else
		{
			output[idx_o++] = input_b[idx_b++];
		}
	}
	while(idx_a != cnt_a)
	{
		output[idx_o++] = input_a[idx_a++];
	}
	while(idx_b != cnt_b)
	{
		output[idx_o++] = input_b[idx_b++];
	}
}

static mk_lang_inline void mk_lib_fe_sort_recursive(mk_win_kernel_files_t_find_data_lpct const data, int_pt const input, int const cnt, int_pt const tmp, int_pt const output) mk_lang_noexcept
{
	int_pt begin_a;
	int cnt_a;
	int_pt tmp_a;
	int_pt output_a;
	int_pt begin_b;
	int cnt_b;
	int_pt tmp_b;
	int_pt output_b;

	mk_lang_assert(data);
	mk_lang_assert(input);
	mk_lang_assert(cnt >= 1);
	mk_lang_assert(tmp);
	mk_lang_assert(output);
	mk_lang_assert(!(input >= tmp && input < tmp + cnt));
	mk_lang_assert(!(tmp >= input && tmp < input + cnt));
	mk_lang_assert(!(input >= output && input < output + cnt));
	mk_lang_assert(!(output >= input && output < input + cnt));
	mk_lang_assert(!(tmp >= output && tmp < output + cnt));
	mk_lang_assert(!(output >= tmp && output < tmp + cnt));

	if(cnt == 1)
	{
		output[0] = input[0];
	}
	else
	{
		begin_a = input;
		cnt_a = cnt / 2;
		tmp_a = tmp;
		output_a = output;
		begin_b = input + cnt_a;
		cnt_b = cnt - cnt_a;
		tmp_b = tmp + cnt_a;
		output_b = output + cnt_a;
		mk_lib_fe_sort_recursive(data, begin_a, cnt_a, output_a, tmp_a);
		mk_lib_fe_sort_recursive(data, begin_b, cnt_b, output_b, tmp_b);
		mk_lib_fe_sort_merge(data, tmp_a, cnt_a, tmp_b, cnt_b, output);
	}
}

static mk_lang_inline void mk_lib_fe_sort(mk_lib_fe_lpt const fe) mk_lang_noexcept
{
	int n;
	mk_win_base_size_t s;
	int_pt pi;
	int i;
	mk_win_kernel_files_t_find_data_lpct data;

	mk_lang_assert(fe);

	n = fe->m_strs_count;
	s = sizeof(int);
	mk_lib_fe_resize(&fe->m_sort, &fe->m_sort_capacity, 3 * n * s); mk_lang_assert(fe->m_sort); mk_lang_assert(fe->m_sort_capacity >= 3 * n * s);
	pi = ((int_pt)(fe->m_sort));
	for(i = 0; i != n; ++i){ pi[i] = i; }
	if(n >= 2)
	{
		data = ((mk_win_kernel_files_t_find_data_lpct)(fe->m_strs));
		mk_lib_fe_sort_recursive(data, pi, n, pi + n, pi + 2 * n);
		for(i = 0; i != n; ++i){ pi[i] = pi[n * 2 + i]; }
	}
}
