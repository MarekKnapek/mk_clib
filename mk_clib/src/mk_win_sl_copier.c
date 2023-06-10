#include "mk_win_sl_copier.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_exception.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_max.h"
#include "mk_lang_memcpy.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_win_advapi_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_errors.h"
#include "mk_win_kernel_files.h"
#include "mk_win_kernel_handle.h"
#include "mk_win_kernel_memory_management.h"
#include "mk_win_kernel_synchronization.h"
#include "mk_win_main_heap.h"
#include "mk_win_sl_copier_exception.h"
#include "mk_win_sl_tdw.h"
#include "mk_win_tstring.h"

/*#define mk_lang_bui_name mk_win_sl_copier
#define mk_lang_bui_type mk_lang_types_uint_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_uint_t
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_speed_counter_t_name mk_win_sl_copier
#define mk_sl_speed_counter_t_item_prefix mk_lang_bui_mk_win_sl_copier
#define mk_sl_speed_counter_t_time_prefix mk_lang_bui_mk_win_sl_copier
#define mk_sl_speed_counter_t_time_denominator 1000
#define mk_sl_speed_counter_t_time_granule_size 500
#define mk_sl_speed_counter_t_time_granule_count 4
#include "mk_sl_speed_counter_inl_filec.h"*/


enum mk_win_sl_copier_state_e
{
	mk_win_sl_copier_state_e_src_open,
	mk_win_sl_copier_state_e_src_get_type,
	mk_win_sl_copier_state_e_src_get_cluster,
	mk_win_sl_copier_state_e_src_get_size,
	mk_win_sl_copier_state_e_dst_open,
	mk_win_sl_copier_state_e_dst_get_type,
	mk_win_sl_copier_state_e_dst_get_cluster,
	mk_win_sl_copier_state_e_dst_set_ptr,
	mk_win_sl_copier_state_e_dst_set_size,
	mk_win_sl_copier_state_e_cpr_allocate_buffers,
	mk_win_sl_copier_state_e_sra1,
	mk_win_sl_copier_state_e_srb1,
	mk_win_sl_copier_state_e_wrarb,
	mk_win_sl_copier_state_e_swa1,
	mk_win_sl_copier_state_e_wrbwa,
	mk_win_sl_copier_state_e_sra2,
	mk_win_sl_copier_state_e_wrbra,
	mk_win_sl_copier_state_e_swb1,
	mk_win_sl_copier_state_e_wrawb,
	mk_win_sl_copier_state_e_swb2,
	mk_win_sl_copier_state_e_wwawb,
	mk_win_sl_copier_state_e_sra3,
	mk_win_sl_copier_state_e_wwbra,
	mk_win_sl_copier_state_e_swa2,
	mk_win_sl_copier_state_e_wwbwa,
	mk_win_sl_copier_state_e_srb2,
	mk_win_sl_copier_state_e_wwarb,
	mk_win_sl_copier_state_e_dummy_end
};
typedef enum mk_win_sl_copier_state_e mk_win_sl_copier_state_t;


mk_lang_jumbo void mk_win_sl_copier_dir_name_from_file_name(mk_win_tstring_tchar_lpt const file_name, mk_win_base_size_pt const dir_name_len, mk_win_tstring_tchar_pt const backup_char) mk_lang_noexcept
{
	mk_win_tstring_tchar_lpt p;
	mk_win_tstring_tchar_lpt last;
	mk_win_base_size_t len;
	mk_win_tstring_tchar_t chr;

	mk_lang_assert(file_name);
	mk_lang_assert(*file_name);
	mk_lang_assert(dir_name_len);
	mk_lang_assert(backup_char);

	for(p = file_name, last = mk_win_base_null; *p; ++p)
	{
		if(*p == mk_win_tstring_tchar_c('\\') || *p == mk_win_tstring_tchar_c('/'))
		{
			last = p;
		}
	}
	if(last == mk_win_base_null)
	{
		*dir_name_len = 0;
	}
	else
	{
		len = ((mk_win_base_size_t)(last - file_name + 1));
		chr = file_name[len];
		file_name[len] = mk_win_tstring_tchar_c('\0');
		*dir_name_len = len;
		*backup_char = chr;
	}
}

mk_lang_jumbo void mk_win_sl_copier_file_name_from_dir_name(mk_win_tstring_tchar_lpt const dir_name, mk_win_base_size_t const dir_name_len, mk_win_tstring_tchar_t const backup_char) mk_lang_noexcept
{
	mk_lang_assert(dir_name);
	mk_lang_assert(*dir_name);

	if(dir_name_len != 0)
	{
		dir_name[dir_name_len] = backup_char;
	}
}

mk_lang_jumbo void mk_win_sl_copier_construct(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_win_tstring_tchar_pct const src_file_name, mk_win_tstring_tchar_pct const dst_file_name) mk_lang_noexcept
{
	mk_win_base_size_t len;
	mk_win_base_void_lpt mem;

	mk_lang_static_assert(sizeof(mk_win_base_dword_t) == sizeof(unsigned));

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(src_file_name);
	mk_lang_assert(*src_file_name);
	mk_lang_assert(dst_file_name);
	mk_lang_assert(*dst_file_name);

	copier->m_state = 0;
	copier->m_src_path = mk_win_base_null;
	copier->m_src_path_len = 0;
	copier->m_dst_path = mk_win_base_null;
	copier->m_dst_path_len = 0;
	copier->m_src_handle = mk_win_base_null;
	copier->m_src_file_type = mk_win_kernel_files_file_type_e_unknown;
	copier->m_src_cluster = 0;
	copier->m_src_size_lo = 0;
	copier->m_src_size_hi = 0;
	copier->m_dst_handle = mk_win_base_null;
	copier->m_dst_file_type = mk_win_kernel_files_file_type_e_unknown;
	copier->m_dst_cluster = 0;
	copier->m_buffers = mk_win_base_null;
	copier->m_active_buffer = mk_lang_false;
	copier->m_at_end = mk_lang_false;
	copier->m_buffer_parts = 0;
	copier->m_overlapped_a.m_submitted = 0;
	copier->m_overlapped_a.m_overlapped.m_event = mk_win_base_null;
	copier->m_overlapped_a.m_overlapped.m_offset_lo = 0;
	copier->m_overlapped_a.m_overlapped.m_offset_hi = 0;
	copier->m_overlapped_b.m_submitted = 0;
	copier->m_overlapped_b.m_overlapped.m_event = mk_win_base_null;
	copier->m_overlapped_b.m_overlapped.m_offset_lo = 0;
	copier->m_overlapped_b.m_overlapped.m_offset_hi = 0;
	copier->m_overlapped_c.m_submitted = 0;
	copier->m_overlapped_c.m_overlapped.m_event = mk_win_base_null;
	copier->m_overlapped_c.m_overlapped.m_offset_lo = 0;
	copier->m_overlapped_c.m_overlapped.m_offset_hi = 0;

	len = 0; do{ ++len; }while(src_file_name[len] != mk_win_tstring_tchar_c('\0')); ++len; mk_lang_assert(len <= 64 * 1024);
	mk_win_main_heap_allocate(ex, len * sizeof(mk_win_tstring_tchar_t), &mem); mk_lang_exception_if_is_return(ex); mk_lang_assert(mem);
	mk_lang_memcpy(mem, src_file_name, len * sizeof(mk_win_tstring_tchar_t));
	copier->m_src_path = ((mk_win_tstring_tchar_lpt)(mem));
	copier->m_src_path_len = len;

	len = 0; do{ ++len; }while(dst_file_name[len] != mk_win_tstring_tchar_c('\0')); ++len; mk_lang_assert(len <= 64 * 1024);
	mk_win_main_heap_allocate(ex, len * sizeof(mk_win_tstring_tchar_t), &mem); mk_lang_exception_if_is_return(ex); mk_lang_assert(mem);
	mk_lang_memcpy(mem, dst_file_name, len * sizeof(mk_win_tstring_tchar_t));
	copier->m_dst_path = ((mk_win_tstring_tchar_lpt)(mem));
	copier->m_dst_path_len = len;
}
/*{
	copier->m_buffers_a = mk_win_kernel_memory_management_virtual_alloc(mk_win_base_null, copier->m_src_cluster, mk_win_kernel_memory_management_type_e_commit | mk_win_kernel_memory_management_type_e_reserve, mk_win_kernel_memory_management_protect_e_readwrite);
	if(mk_lang_check_if_failed(copier->m_buffers_a)) mk_lang_unlikely { mk_lang_exception_out_of_memory_make(ex, copier->m_src_cluster); return; }
	copier->m_buffers_b = mk_win_kernel_memory_management_virtual_alloc(mk_win_base_null, copier->m_dst_cluster, mk_win_kernel_memory_management_type_e_commit | mk_win_kernel_memory_management_type_e_reserve, mk_win_kernel_memory_management_protect_e_readwrite);
	if(mk_lang_check_if_failed(copier->m_buffers_b)) mk_lang_unlikely { mk_lang_exception_out_of_memory_make(ex, copier->m_dst_cluster); return; }
	copier->m_overlapped_a.m_overlapped.m_offset_lo = 0;
	copier->m_overlapped_a.m_overlapped.m_offset_hi = 0;
	copier->m_overlapped_a.m_overlapped.m_event = mk_win_kernel_synchronization_t_create_event(mk_win_base_null, mk_win_base_true, mk_win_base_true, mk_win_base_null);
	if(mk_lang_check_if_failed(copier->m_overlapped_a.m_overlapped.m_event)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
	copier->m_overlapped_b.m_overlapped.m_event = mk_win_kernel_synchronization_t_create_event(mk_win_base_null, mk_win_base_true, mk_win_base_true, mk_win_base_null);
	if(mk_lang_check_if_failed(copier->m_overlapped_b.m_overlapped.m_event)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
}*/

mk_lang_jumbo void mk_win_sl_copier_destroy(mk_win_sl_copier_pt const, mk_lang_exception_pt const) mk_lang_noexcept
{
	/*mk_win_base_bool_t closed;
	mk_win_base_bool_t freed;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	if(copier->m_source_handle != mk_win_base_null && copier->m_source_handle != s_mk_win_base_handle_invalid)
	{
		closed = mk_win_kernel_handle_close_handle(copier->m_source_handle);
		if(mk_lang_check_if_failed(closed != 0)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
		if(copier->m_destination_handle != mk_win_base_null && copier->m_destination_handle != s_mk_win_base_handle_invalid)
		{
			closed = mk_win_kernel_handle_close_handle(copier->m_destination_handle);
			if(mk_lang_check_if_failed(closed != 0)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
			if(copier->m_buffers_a)
			{
				freed = mk_win_kernel_memory_management_virtual_free(copier->m_buffers_a, 0, mk_win_kernel_memory_management_type_e_release);
				if(mk_lang_check_if_failed(freed != 0)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
				if(copier->m_buffers_b)
				{
					freed = mk_win_kernel_memory_management_virtual_free(copier->m_buffers_b, 0, mk_win_kernel_memory_management_type_e_release);
					if(mk_lang_check_if_failed(freed != 0)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
					if(copier->m_overlapped_a.m_overlapped.m_event)
					{
						closed = mk_win_kernel_handle_close_handle(copier->m_overlapped_a.m_overlapped.m_event);
						if(mk_lang_check_if_failed(closed != 0)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
						if(copier->m_overlapped_b.m_overlapped.m_event)
						{
							closed = mk_win_kernel_handle_close_handle(copier->m_overlapped_b.m_overlapped.m_event);
							if(mk_lang_check_if_failed(closed != 0)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
						}
					}
				}
			}
		}
	}*/
}

/*mk_lang_jumbo void mk_win_sl_copier_submit_read(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, int const idx) mk_lang_noexcept
{
	mk_win_base_dword_t size;
	mk_win_base_void_lpt buff;
	mk_win_sl_copier_overlapped2_pt overlapped;
	mk_win_base_bool_t reset;
	mk_win_base_bool_t read;
	mk_win_kernel_errors_id_t err;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(idx >= 0 && idx <= 1);

	size = idx == 0 ? copier->m_src_cluster : copier->m_dst_cluster;
	buff = idx == 0 ? copier->m_buffers_a : copier->m_buffers_b;
	overlapped = idx == 0 ? &copier->m_overlapped_a : &copier->m_overlapped_b;
	overlapped->m_submitted = size;
	reset = mk_win_kernel_synchronization_reset_event(overlapped->m_overlapped.m_event);
	if(mk_lang_check_if_failed(reset != 0)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
	read = mk_win_kernel_files_read_file(copier->m_source_handle, buff, overlapped->m_submitted, mk_win_base_null, &overlapped->m_overlapped);
	err = ((mk_win_kernel_errors_id_t)(mk_win_kernel_errors_get_last()));
	if(mk_lang_check_if_failed((read != 0) || ((err == mk_win_kernel_errors_id_e_io_pending) || (err == mk_win_kernel_errors_id_e_handle_eof)))) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_id(ex, err); return; }
	if(read == 0 && err == mk_win_kernel_errors_id_e_handle_eof)
	{
		overlapped->m_submitted = 0;
	}
}*/

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_src_open(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_win_advapi_base_security_attributes_t sa;
	mk_win_base_handle_t handle;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	sa.m_size = ((mk_win_base_dword_t)(sizeof(sa)));
	sa.m_security_descriptor = mk_win_base_null;
	sa.m_inheritable = mk_win_base_false;
	handle = mk_win_kernel_files_t_create_file
	(
		copier->m_src_path,
		((mk_win_base_dword_t)(mk_win_advapi_base_right_generic_e_read)),
		mk_win_kernel_files_share_e_read | mk_win_kernel_files_share_e_delete,
		&sa,
		mk_win_kernel_files_create_e_open_existing,
		mk_win_kernel_files_attribute_e_normal | mk_win_kernel_files_flag_e_sequential_scan | mk_win_kernel_files_flag_e_overlapped,
		mk_win_base_null
	);
	if(mk_lang_check_if_failed((handle != mk_win_base_null) && (handle != s_mk_win_base_handle_invalid))) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
	copier->m_src_handle = handle;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_src_get_type(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	copier->m_src_file_type = ((mk_win_kernel_files_file_type_t)(mk_win_kernel_files_get_file_type(copier->m_src_handle)));
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_src_get_cluster(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_win_base_size_t dir_name_len;
	mk_win_tstring_tchar_t backup_char;
	mk_win_base_bool_t got;
	mk_win_base_dword_t sectors_per_cluster;
	mk_win_base_dword_t bytes_per_sector;
	mk_win_base_dword_t free_clusters_count;
	mk_win_base_dword_t total_clusters_count;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	if(copier->m_src_file_type == mk_win_kernel_files_file_type_e_disk)
	{
		/* https://learn.microsoft.com/en-us/windows/win32/memory/obtaining-a-file-name-from-a-file-handle */
		mk_win_sl_copier_dir_name_from_file_name(copier->m_src_path, &dir_name_len, &backup_char);
		got = mk_win_kernel_files_t_get_disk_free_space(copier->m_src_path, &sectors_per_cluster, &bytes_per_sector, &free_clusters_count, &total_clusters_count);
		mk_win_sl_copier_file_name_from_dir_name(copier->m_src_path, dir_name_len, backup_char);
		if(mk_lang_check_if_failed(got != 0)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
		copier->m_src_cluster = sectors_per_cluster * bytes_per_sector;
	}
	else
	{
		copier->m_src_cluster = 512;
	}
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_src_get_size(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_win_base_dword_t file_size_lo;
	mk_win_base_dword_t file_size_hi;
	mk_win_kernel_errors_id_t err;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	if(copier->m_src_file_type == mk_win_kernel_files_file_type_e_disk)
	{
		file_size_lo = mk_win_kernel_files_get_file_size(copier->m_src_handle, &file_size_hi);
		err = ((mk_win_kernel_errors_id_t)(mk_win_kernel_errors_get_last()));
		if(mk_lang_check_if_failed((file_size_lo != s_mk_win_kernel_files_invalid_file_size) || (err == mk_win_kernel_errors_id_e_success))) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_id(ex, err); return; }
		copier->m_src_size_lo = file_size_lo;
		copier->m_src_size_hi = file_size_hi;
	}
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_dst_open(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_win_advapi_base_security_attributes_t sa;
	mk_win_base_handle_t handle;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	sa.m_size = ((mk_win_base_dword_t)(sizeof(sa)));
	sa.m_security_descriptor = mk_win_base_null;
	sa.m_inheritable = mk_win_base_false;
	handle = mk_win_kernel_files_t_create_file
	(
		copier->m_dst_path,
		((mk_win_base_dword_t)(mk_win_advapi_base_right_generic_e_write | mk_win_advapi_base_right_generic_e_read)),
		mk_win_kernel_files_share_e_delete,
		&sa,
		mk_win_kernel_files_create_e_create_always,
		mk_win_kernel_files_attribute_e_normal | mk_win_kernel_files_flag_e_sequential_scan | mk_win_kernel_files_flag_e_overlapped,
		mk_win_base_null
	);
	if(mk_lang_check_if_failed((handle != mk_win_base_null) && (handle != s_mk_win_base_handle_invalid))) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
	copier->m_dst_handle = handle;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_dst_dst_get_type(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	copier->m_dst_file_type = ((mk_win_kernel_files_file_type_t)(mk_win_kernel_files_get_file_type(copier->m_dst_handle)));
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_dst_get_cluster(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_win_base_size_t dir_name_len;
	mk_win_tstring_tchar_t backup_char;
	mk_win_base_bool_t got;
	mk_win_base_dword_t sectors_per_cluster;
	mk_win_base_dword_t bytes_per_sector;
	mk_win_base_dword_t free_clusters_count;
	mk_win_base_dword_t total_clusters_count;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	if(copier->m_dst_file_type == mk_win_kernel_files_file_type_e_disk)
	{
		mk_win_sl_copier_dir_name_from_file_name(copier->m_dst_path, &dir_name_len, &backup_char);
		got = mk_win_kernel_files_t_get_disk_free_space(copier->m_dst_path, &sectors_per_cluster, &bytes_per_sector, &free_clusters_count, &total_clusters_count);
		mk_win_sl_copier_file_name_from_dir_name(copier->m_dst_path, dir_name_len, backup_char);
		if(mk_lang_check_if_failed(got != 0)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
		copier->m_dst_cluster = sectors_per_cluster * bytes_per_sector;
	}
	else
	{
		copier->m_dst_cluster = 512;
	}
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_dst_set_ptr(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_win_base_dword_t file_size_hi;
	mk_win_base_dword_t file_size_lo;
	mk_win_kernel_errors_id_t err;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	if
	(
		(copier->m_src_file_type == mk_win_kernel_files_file_type_e_disk) &&
		(copier->m_dst_file_type == mk_win_kernel_files_file_type_e_disk) &&
		((copier->m_src_size_lo != 0) || (copier->m_src_size_hi != 0))
	)
	{
		file_size_hi = copier->m_src_size_hi;
		file_size_lo = mk_win_kernel_files_set_file_pointer(copier->m_dst_handle, ((mk_win_base_slong_t)(copier->m_src_size_lo)), ((mk_win_base_slong_lpt)(&file_size_hi)), ((mk_win_base_dword_t)(mk_win_kernel_files_move_method_e_begin)));
		err = ((mk_win_kernel_errors_id_t)(mk_win_kernel_errors_get_last()));
		if(mk_lang_check_if_failed((file_size_lo == copier->m_src_size_lo) && (file_size_hi == copier->m_src_size_hi) && ((file_size_lo != s_mk_win_kernel_files_invalid_set_file_pointer) || (err == mk_win_kernel_errors_id_e_success)))) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_id(ex, err); return; }
	}
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_dst_set_size(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_win_base_bool_t set;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	if
	(
		(copier->m_src_file_type == mk_win_kernel_files_file_type_e_disk) &&
		(copier->m_dst_file_type == mk_win_kernel_files_file_type_e_disk) &&
		((copier->m_src_size_lo != 0) || (copier->m_src_size_hi != 0))
	)
	{
		set = mk_win_kernel_files_set_end_of_file(copier->m_dst_handle);
		if(mk_lang_check_if_failed(set != 0)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
	}
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_cpr_allocate_buffers(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_win_base_size_t size;
	mk_win_base_void_lpt mem;

	mk_lang_assert(copier);
	mk_lang_assert(copier->m_src_cluster != 0);
	mk_lang_assert(copier->m_dst_cluster != 0);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	size = mk_lang_max(copier->m_src_cluster, copier->m_dst_cluster) * 2;
	mem = mk_win_kernel_memory_management_virtual_alloc(mk_win_base_null, size, mk_win_kernel_memory_management_type_e_commit | mk_win_kernel_memory_management_type_e_reserve, mk_win_kernel_memory_management_protect_e_readwrite);
	if(mk_lang_check_if_failed(mem)) mk_lang_unlikely { mk_lang_exception_out_of_memory_make(ex, size); return; }
	copier->m_buffers = mem;
}

/*mk_lang_jumbo void mk_win_sl_copier_make_step_ll_cpr_prepare_first(mk_win_sl_copier_pt const copier) mk_lang_noexcept
{
	mk_sl_cui_wtdw_t cui1;
	mk_sl_cui_wtdw_t cui2;

	mk_lang_assert(copier);

	mk_sl_cui_wtdw_set_zero(&cui1);
	mk_sl_cui_wtdw_from_bi_uint(&cui2, &copier->m_src_cluster);
	mk_sl_cui_wtdw_sub2_wrap_cid_cod(&cui1, &cui2);
	mk_sl_cui_wtdw_to_bi_uint(&cui1, &copier->m_overlapped_b.m_overlapped.m_offset_lo);
	mk_sl_cui_wtdw_shr2(&cui1, 32);
	mk_sl_cui_wtdw_to_bi_uint(&cui1, &copier->m_overlapped_b.m_overlapped.m_offset_hi);
	copier->m_overlapped_c.m_overlapped.m_offset_lo = copier->m_overlapped_b.m_overlapped.m_offset_lo;
	copier->m_overlapped_c.m_overlapped.m_offset_hi = copier->m_overlapped_b.m_overlapped.m_offset_hi;
	copier->m_overlapped_d.m_overlapped.m_offset_lo = copier->m_overlapped_b.m_overlapped.m_offset_lo;
	copier->m_overlapped_d.m_overlapped.m_offset_hi = copier->m_overlapped_b.m_overlapped.m_offset_hi;
}*/

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_overlapped_add_dword(mk_win_sl_copier_overlapped2_pct const overlapped_a, mk_win_base_dword_t const dw, mk_win_sl_copier_overlapped2_pt const overlapped_b) mk_lang_noexcept
{
	mk_sl_cui_wtdw_t cui1;
	mk_sl_cui_wtdw_t cui2;

	mk_lang_assert(overlapped_a);
	mk_lang_assert(dw != 0);
	mk_lang_assert(overlapped_b);

	mk_sl_cui_wtdw_from_bi_uint(&cui1, &overlapped_a->m_overlapped.m_offset_hi);
	mk_sl_cui_wtdw_shl2(&cui1, 32);
	mk_sl_cui_wtdw_from_bi_uint(&cui2, &overlapped_a->m_overlapped.m_offset_lo);
	mk_sl_cui_wtdw_or2(&cui1, &cui2);
	mk_sl_cui_wtdw_from_bi_uint(&cui2, &dw);
	mk_lang_assert(!mk_sl_cui_wtdw_would_overflow_add_cc(&cui1, &cui2));
	mk_sl_cui_wtdw_add2_wrap_cid_cod(&cui1, &cui2);
	mk_sl_cui_wtdw_to_bi_uint(&cui1, &overlapped_b->m_overlapped.m_offset_lo);
	mk_sl_cui_wtdw_shr2(&cui1, 32);
	mk_sl_cui_wtdw_to_bi_uint(&cui1, &overlapped_b->m_overlapped.m_offset_hi);
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_src_wait_read_o(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_win_sl_copier_overlapped2_pt const overlapped) mk_lang_noexcept
{
	mk_win_base_dword_t waited;
	mk_win_base_bool_t got;
	mk_win_base_dword_t bytes_transfered;
	mk_win_kernel_errors_id_t err;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(overlapped);

	if(overlapped->m_overlapped.m_event)
	{
		mk_lang_assert(overlapped->m_submitted != 0);
		waited = mk_win_kernel_synchronization_wait_for_single_object(overlapped->m_overlapped.m_event, mk_win_kernel_synchronization_infinite);
		if(mk_lang_check_if_failed(waited == 0)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
		got = mk_win_kernel_synchronization_get_overlapped_result(copier->m_src_handle, &overlapped->m_overlapped, &bytes_transfered, mk_win_base_true);
		err = ((mk_win_kernel_errors_id_t)(mk_win_kernel_errors_get_last()));
		if(mk_lang_check_if_failed(got != 0 || err == mk_win_kernel_errors_id_e_handle_eof)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_id(ex, err); return; }
		if(got != 0)
		{
			if(mk_lang_check_if_failed(bytes_transfered == overlapped->m_submitted)) mk_lang_unlikely { mk_win_sl_copier_exception_make(ex, mk_win_sl_copier_exception_id_e_read_failed); return; }
			overlapped->m_submitted = 0;
		}
		else
		{
			copier->m_at_end = mk_lang_true;
		}
	}
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_src_wait_read_ab(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_t const ab) mk_lang_noexcept
{
	mk_lang_types_bool_t smol;
	mk_lang_types_bool_t even;
	mk_win_sl_copier_overlapped2_pt overlapped_a;
	mk_win_sl_copier_overlapped2_pt overlapped_b;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	smol = copier->m_src_cluster < copier->m_dst_cluster;
	even = (copier->m_dst_cluster / copier->m_src_cluster) % 2 == 0;
	overlapped_a = ((smol) ? ((even) ? ((ab) ? (&copier->m_overlapped_a) : (&copier->m_overlapped_b)) : (&copier->m_overlapped_c)) : ((ab) ? (&copier->m_overlapped_a) : (&copier->m_overlapped_b)));
	overlapped_b = ((smol) ? ((even) ? (&copier->m_overlapped_c) : ((ab) ? (&copier->m_overlapped_a) : (&copier->m_overlapped_b))) : ((ab) ? (&copier->m_overlapped_b) : (&copier->m_overlapped_a)));
	mk_win_sl_copier_make_step_ll_src_wait_read_o(copier, ex, overlapped_a); mk_lang_exception_if_is_return(ex);
	if(smol){ mk_win_sl_copier_make_step_ll_src_wait_read_o(copier, ex, overlapped_b); mk_lang_exception_if_is_return(ex); }
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_src_wait_read_a(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	mk_win_sl_copier_make_step_ll_src_wait_read_ab(copier, ex, mk_lang_true);
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_src_wait_read_b(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	mk_win_sl_copier_make_step_ll_src_wait_read_ab(copier, ex, mk_lang_false);
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_src_submit_read_o(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_t const ab, mk_win_sl_copier_overlapped2_pt const overlapped_a, mk_win_sl_copier_overlapped2_pt const overlapped_b) mk_lang_noexcept
{
	mk_win_base_bool_t reset;
	mk_win_base_void_lpt buff;
	mk_win_base_bool_t read;
	mk_win_kernel_errors_id_t err;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(overlapped_a);
	mk_lang_assert(overlapped_b);

	if(!overlapped_a->m_overlapped.m_event)
	{
		overlapped_a->m_overlapped.m_event = mk_win_kernel_synchronization_t_create_event(mk_win_base_null, mk_win_base_true, mk_win_base_true, mk_win_base_null);
		if(mk_lang_check_if_failed(overlapped_a->m_overlapped.m_event)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
	}
	mk_lang_assert(overlapped_a->m_overlapped.m_event);
	reset = mk_win_kernel_synchronization_reset_event(overlapped_a->m_overlapped.m_event);
	if(mk_lang_check_if_failed(reset != 0)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
	overlapped_a->m_submitted = copier->m_src_cluster;
	mk_win_sl_copier_make_step_ll_overlapped_add_dword(overlapped_b, copier->m_src_cluster, overlapped_a);
	buff = ((mk_win_base_void_lpt)(((mk_win_base_uchar_lpt)(copier->m_buffers)) + ((ab ? 1 : 0) * mk_lang_max(copier->m_src_cluster, copier->m_dst_cluster)) + (copier->m_buffer_parts * copier->m_src_cluster)));
	read = mk_win_kernel_files_read_file(copier->m_src_handle, buff, copier->m_src_cluster, mk_win_base_null, &overlapped_a->m_overlapped);
	err = ((mk_win_kernel_errors_id_t)(mk_win_kernel_errors_get_last()));
	if(mk_lang_check_if_failed((read != 0) || ((err == mk_win_kernel_errors_id_e_io_pending) || (err == mk_win_kernel_errors_id_e_handle_eof)))) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_id(ex, err); return; }
	++copier->m_buffer_parts;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_src_submit_read_ab(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_t const ab) mk_lang_noexcept
{
	mk_lang_types_bool_t even;
	mk_lang_types_bool_t smol;
	mk_win_sl_copier_overlapped2_pt overlapped_aa;
	mk_win_sl_copier_overlapped2_pt overlapped_bb;
	mk_win_sl_copier_overlapped2_pt overlapped_cc;
	mk_win_sl_copier_overlapped2_pt overlapped_a;
	mk_win_sl_copier_overlapped2_pt overlapped_b;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	even = copier->m_buffer_parts % 2 == 0;
	smol = copier->m_src_cluster < copier->m_dst_cluster;
	overlapped_aa = ab ? &copier->m_overlapped_a : &copier->m_overlapped_b;
	overlapped_bb = ab ? &copier->m_overlapped_b : &copier->m_overlapped_a;
	overlapped_cc = ab ? &copier->m_overlapped_c : &copier->m_overlapped_d;
	overlapped_a = smol ? (even ? overlapped_aa : overlapped_cc) : overlapped_aa;
	overlapped_b = smol ? (even ? overlapped_cc : overlapped_aa) : overlapped_bb;
	if(overlapped_a->m_submitted != 0)
	{
		mk_win_sl_copier_make_step_ll_src_wait_read_o(copier, ex, overlapped_a); mk_lang_exception_if_is_return(ex);
	}
	else
	{
		mk_win_sl_copier_make_step_ll_src_submit_read_o(copier, ex, ab, overlapped_a, overlapped_b); mk_lang_exception_if_is_return(ex);
	}
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_src_submit_read_a(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	mk_win_sl_copier_make_step_ll_src_submit_read_ab(copier, ex, mk_lang_true);
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_src_submit_read_b(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	mk_win_sl_copier_make_step_ll_src_submit_read_ab(copier, ex, mk_lang_false);
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_dst_wait_write_o(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_win_sl_copier_overlapped2_pt const overlapped) mk_lang_noexcept
{
	mk_win_base_dword_t waited;
	mk_win_base_bool_t got;
	mk_win_base_dword_t bytes_transfered;
	mk_win_kernel_errors_id_t err;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(overlapped);

	mk_lang_assert(overlapped->m_overlapped.m_event);
	mk_lang_assert(overlapped->m_submitted != 0);
	waited = mk_win_kernel_synchronization_wait_for_single_object(overlapped->m_overlapped.m_event, mk_win_kernel_synchronization_infinite);
	if(mk_lang_check_if_failed(waited == 0)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
	got = mk_win_kernel_synchronization_get_overlapped_result(copier->m_src_handle, &overlapped->m_overlapped, &bytes_transfered, mk_win_base_true);
	err = ((mk_win_kernel_errors_id_t)(mk_win_kernel_errors_get_last()));
	if(mk_lang_check_if_failed(got != 0)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_id(ex, err); return; }
	if(mk_lang_check_if_failed(bytes_transfered == overlapped->m_submitted)) mk_lang_unlikely { mk_win_sl_copier_exception_make(ex, mk_win_sl_copier_exception_id_e_read_failed); return; }
	overlapped->m_submitted = 0;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_dst_wait_write_ab(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_t const ab) mk_lang_noexcept
{
	mk_lang_types_bool_t smol;
	mk_lang_types_bool_t even;
	mk_win_sl_copier_overlapped2_pt overlapped_a;
	mk_win_sl_copier_overlapped2_pt overlapped_b;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	smol = copier->m_src_cluster < copier->m_dst_cluster;
	even = (copier->m_dst_cluster / copier->m_src_cluster) % 2 == 0;
	overlapped_a = ab ? (even ? &copier->m_overlapped_a : &copier->m_overlapped_c) : (even ? &copier->m_overlapped_b : &copier->m_overlapped_d);
	overlapped_b = ab ? (even ? &copier->m_overlapped_c : &copier->m_overlapped_a) : (even ? &copier->m_overlapped_d : &copier->m_overlapped_b);
	mk_win_sl_copier_make_step_ll_dst_wait_write_o(copier, ex, overlapped_a);
	mk_win_sl_copier_make_step_ll_dst_wait_write_o(copier, ex, overlapped_b);
	/*{
		mk_sl_cui_wtdw_t cui1;
		mk_sl_cui_wtdw_t cui2;
		mk_lang_types_bool_t would_overflow;
		mk_sl_cui_wtdw_from_bi_uint(&cui1, &overlapped_b->m_overlapped.m_offset_hi);
		mk_sl_cui_wtdw_shl2(&cui1, 32);
		mk_sl_cui_wtdw_from_bi_uint(&cui2, &overlapped_b->m_overlapped.m_offset_lo);
		mk_sl_cui_wtdw_or2(&cui1, &cui2);
		mk_sl_cui_wtdw_from_bi_uint(&cui2, &copier->m_src_cluster);
		would_overflow = mk_sl_cui_wtdw_would_overflow_add_cc(&cui1, &cui2);
		mk_sl_cui_wtdw_add2_wrap_cid_cod(&cui1, &cui2);
		mk_lang_assert(!would_overflow || mk_sl_cui_wtdw_is_zero(&cui1));
		mk_sl_cui_wtdw_to_bi_uint(&cui1, &overlapped_b->m_overlapped.m_offset_lo);
		mk_sl_cui_wtdw_shr2(&cui1, 32);
		mk_sl_cui_wtdw_to_bi_uint(&cui1, &overlapped_b->m_overlapped.m_offset_hi);
	}*/
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_dst_wait_write_a(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	mk_win_sl_copier_make_step_ll_dst_wait_write_ab(copier, ex, mk_lang_true);
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_dst_wait_write_b(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	mk_win_sl_copier_make_step_ll_dst_wait_write_ab(copier, ex, mk_lang_false);
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_dst_submit_write_o(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_t const ab, mk_win_sl_copier_overlapped2_pt const overlapped_a) mk_lang_noexcept
{
	mk_win_base_bool_t reset;
	mk_win_base_void_lpt buff;
	mk_win_base_bool_t write;
	mk_win_kernel_errors_id_t err;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(overlapped_a);

	mk_lang_assert(overlapped_a->m_overlapped.m_event);
	reset = mk_win_kernel_synchronization_reset_event(overlapped_a->m_overlapped.m_event);
	if(mk_lang_check_if_failed(reset != 0)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
	overlapped_a->m_submitted = copier->m_dst_cluster;
	buff = ((mk_win_base_void_lpt)(((mk_win_base_uchar_lpt)(copier->m_buffers)) + ((ab ? 1 : 0) * mk_lang_max(copier->m_src_cluster, copier->m_dst_cluster)) + (copier->m_buffer_parts * copier->m_dst_cluster)));
	/*{
		mk_sl_cui_wtdw_t cui1;
		mk_sl_cui_wtdw_t cui2;
		mk_sl_cui_wtdw_from_bi_uint(&cui1, &overlapped_a->m_overlapped.m_offset_hi);
		mk_sl_cui_wtdw_shl2(&cui1, 32);
		mk_sl_cui_wtdw_from_bi_uint(&cui2, &overlapped_a->m_overlapped.m_offset_lo);
		mk_sl_cui_wtdw_or2(&cui1, &cui2);
		mk_sl_cui_wtdw_from_bi_uint(&cui2, &copier->m_dst_cluster);
		mk_lang_assert(!mk_sl_cui_wtdw_would_overflow_sub_cc(&cui1, &cui2));
		mk_sl_cui_wtdw_sub2_wrap_cid_cod(&cui1, &cui2);
		mk_sl_cui_wtdw_to_bi_uint(&cui1, &overlapped_a->m_overlapped.m_offset_lo);
		mk_sl_cui_wtdw_shr2(&cui1, 32);
		mk_sl_cui_wtdw_to_bi_uint(&cui1, &overlapped_a->m_overlapped.m_offset_hi);
	}*/
	write = mk_win_kernel_files_write_file(copier->m_dst_handle, buff, copier->m_dst_cluster, mk_win_base_null, &overlapped_a->m_overlapped);
	err = ((mk_win_kernel_errors_id_t)(mk_win_kernel_errors_get_last()));
	if(mk_lang_check_if_failed((write != 0) || (err == mk_win_kernel_errors_id_e_io_pending))) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_id(ex, err); return; }
	++copier->m_buffer_parts;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_dst_submit_write_ab(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_t const ab) mk_lang_noexcept
{
	mk_lang_types_bool_t even;
	mk_lang_types_bool_t smol;
	mk_win_sl_copier_overlapped2_pt overlapped_aa;
	mk_win_sl_copier_overlapped2_pt overlapped_bb;
	mk_win_sl_copier_overlapped2_pt overlapped_cc;
	mk_win_sl_copier_overlapped2_pt overlapped_a;
	mk_win_sl_copier_overlapped2_pt overlapped_b;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	even = copier->m_buffer_parts % 2 == 0;
	smol = copier->m_dst_cluster < copier->m_src_cluster;
	overlapped_aa = ab ? &copier->m_overlapped_a : &copier->m_overlapped_b;
	overlapped_bb = ab ? &copier->m_overlapped_b : &copier->m_overlapped_a;
	overlapped_cc = ab ? &copier->m_overlapped_c : &copier->m_overlapped_d;
	overlapped_a = smol ? (even ? overlapped_aa : overlapped_cc) : overlapped_aa;
	overlapped_b = smol ? (even ? overlapped_cc : overlapped_aa) : overlapped_bb;
	if(overlapped_a->m_submitted != 0)
	{
		mk_win_sl_copier_make_step_ll_dst_wait_write_o(copier, ex, overlapped_a); mk_lang_exception_if_is_return(ex);
	}
	else
	{
		mk_win_sl_copier_make_step_ll_dst_submit_write_o(copier, ex, ab, overlapped_a); mk_lang_exception_if_is_return(ex);
	}
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_dst_submit_write_a(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	mk_win_sl_copier_make_step_ll_dst_submit_write_ab(copier, ex, mk_lang_true);
}

mk_lang_jumbo void mk_win_sl_copier_make_step_ll_dst_submit_write_b(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	mk_win_sl_copier_make_step_ll_dst_submit_write_ab(copier, ex, mk_lang_false);
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_src_open(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_win_sl_copier_make_step_ll_src_open(copier, ex); mk_lang_exception_if_is_return(ex);
	++copier->m_state;
	*keep_running = mk_lang_true;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_src_get_type(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_win_sl_copier_make_step_ll_src_get_type(copier, ex); mk_lang_exception_if_is_return(ex);
	++copier->m_state;
	*keep_running = mk_lang_true;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_src_get_cluster(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_win_sl_copier_make_step_ll_src_get_cluster(copier, ex); mk_lang_exception_if_is_return(ex);

	++copier->m_state;
	*keep_running = mk_lang_true;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_src_get_size(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_win_sl_copier_make_step_ll_src_get_size(copier, ex); mk_lang_exception_if_is_return(ex);
	++copier->m_state;
	*keep_running = mk_lang_true;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_dst_open(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_win_sl_copier_make_step_ll_dst_open(copier, ex); mk_lang_exception_if_is_return(ex);
	++copier->m_state;
	*keep_running = mk_lang_true;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_dst_get_type(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_win_sl_copier_make_step_ll_dst_dst_get_type(copier, ex); mk_lang_exception_if_is_return(ex);
	++copier->m_state;
	*keep_running = mk_lang_true;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_dst_get_cluster(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_win_sl_copier_make_step_ll_dst_get_cluster(copier, ex); mk_lang_exception_if_is_return(ex);
	if(mk_lang_check_if_failed(((copier->m_src_cluster % copier->m_dst_cluster) == 0) || ((copier->m_dst_cluster % copier->m_src_cluster) == 0))) mk_lang_unlikely { mk_win_sl_copier_exception_make(ex, mk_win_sl_copier_exception_id_e_cluster_size_not_even_multiple); return; }
	++copier->m_state;
	*keep_running = mk_lang_true;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_dst_set_ptr(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_win_sl_copier_make_step_ll_dst_set_ptr(copier, ex); mk_lang_exception_if_is_return(ex);
	++copier->m_state;
	*keep_running = mk_lang_true;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_dst_set_size(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_win_sl_copier_make_step_ll_dst_set_size(copier, ex); mk_lang_exception_if_is_return(ex);
	++copier->m_state;
	*keep_running = mk_lang_true;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_cpr_allocate_buffers(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_win_sl_copier_make_step_ll_cpr_allocate_buffers(copier, ex); mk_lang_exception_if_is_return(ex);
	/*mk_win_sl_copier_make_step_ll_cpr_prepare_first(copier);*/
	++copier->m_state;
	*keep_running = mk_lang_true;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_hlp_sran(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_win_sl_copier_make_step_ll_src_submit_read_a(copier, ex); mk_lang_exception_if_is_return(ex);
	if(copier->m_buffer_parts == ((copier->m_src_cluster < copier->m_dst_cluster) ? (copier->m_dst_cluster / copier->m_src_cluster) : (1)))
	{
		copier->m_buffer_parts = 0;
		++copier->m_state;
	}
	*keep_running = mk_lang_true;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_hlp_swan(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_win_sl_copier_make_step_ll_dst_submit_write_a(copier, ex); mk_lang_exception_if_is_return(ex);
	if(copier->m_buffer_parts == ((copier->m_dst_cluster < copier->m_src_cluster) ? (copier->m_src_cluster / copier->m_dst_cluster) : (1)))
	{
		copier->m_buffer_parts = 0;
		++copier->m_state;
	}
	*keep_running = mk_lang_true;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_hlp_swbn(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_win_sl_copier_make_step_ll_dst_submit_write_b(copier, ex); mk_lang_exception_if_is_return(ex);
	if(copier->m_buffer_parts == ((copier->m_dst_cluster < copier->m_src_cluster) ? (copier->m_src_cluster / copier->m_dst_cluster) : (1)))
	{
		copier->m_buffer_parts = 0;
		++copier->m_state;
	}
	*keep_running = mk_lang_true;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_sra1(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_win_sl_copier_make_step_hl_hlp_sran(copier, ex, keep_running);
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_srb1(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_win_sl_copier_make_step_ll_src_submit_read_b(copier, ex); mk_lang_exception_if_is_return(ex);
	if(copier->m_buffer_parts == mk_lang_max(1, copier->m_dst_cluster / copier->m_src_cluster))
	{
		copier->m_buffer_parts = 0;
		++copier->m_state;
	}
	*keep_running = mk_lang_true;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_wrarb(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_win_sl_copier_make_step_ll_src_wait_read_a(copier, ex); mk_lang_exception_if_is_return(ex);
	++copier->m_state;
	*keep_running = mk_lang_true;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_swa1(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_win_sl_copier_make_step_hl_hlp_swan(copier, ex, keep_running);
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_wrbwa(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_win_sl_copier_overlapped2_pt overlappeds[2];
	mk_win_base_handle_t handles[2];
	mk_win_base_dword_t waited;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	overlappeds[0] = ((copier->m_src_cluster < copier->m_dst_cluster) ? ((((copier->m_dst_cluster / copier->m_src_cluster) % 2) == 0) ? (&copier->m_overlapped_d) : (&copier->m_overlapped_b)) : (&copier->m_overlapped_b));
	overlappeds[1] = ((copier->m_dst_cluster < copier->m_src_cluster) ? ((((copier->m_src_cluster / copier->m_dst_cluster) % 2) == 0) ? (&copier->m_overlapped_c) : (&copier->m_overlapped_a)) : (&copier->m_overlapped_a));
	mk_lang_assert(overlappeds[0]->m_submitted != 0);
	mk_lang_assert(overlappeds[1]->m_submitted != 0);
	handles[0] = overlappeds[0]->m_overlapped.m_event;
	handles[1] = overlappeds[1]->m_overlapped.m_event;
	mk_lang_assert(handles[0]);
	mk_lang_assert(handles[1]);
	waited = mk_win_kernel_synchronization_wait_for_multiple_objects(2, handles, mk_win_base_false, mk_win_kernel_synchronization_infinite);
	if(mk_lang_check_if_failed(waited == 0 || waited == 1)) mk_lang_unlikely { mk_win_sl_exception_gle_make_from_current(ex); return; }
	mk_lang_assert(waited == 0 || waited == 1);
	overlappeds[waited]->m_submitted = 0;
	copier->m_state = ((waited == 0) ? (mk_win_sl_copier_state_e_swb2) : (mk_win_sl_copier_state_e_sra2));
	*keep_running = mk_lang_true;
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_sra2(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_win_sl_copier_make_step_hl_hlp_sran(copier, ex, keep_running);
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_wrbra(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_lang_assert(0 && "todo");
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_swb1(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_lang_assert(0 && "todo");
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_wrawb(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_lang_assert(0 && "todo");
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_swb2(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_win_sl_copier_make_step_hl_hlp_swbn(copier, ex, keep_running);
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_wwawb(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_lang_assert(0 && "todo");
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_sra3(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_win_sl_copier_make_step_hl_hlp_sran(copier, ex, keep_running);
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_wwbra(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_lang_assert(0 && "todo");
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_swa2(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_lang_assert(0 && "todo");
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_wwbwa(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_lang_assert(0 && "todo");
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_srb2(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_lang_assert(0 && "todo");
}

mk_lang_jumbo void mk_win_sl_copier_make_step_hl_wwarb(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	mk_lang_assert(0 && "todo");
}

mk_lang_jumbo void mk_win_sl_copier_make_step_2(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_lang_types_bool_pt const keep_running) mk_lang_noexcept
{
	mk_win_sl_copier_state_t state_id;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(keep_running);
	mk_lang_assert(!*keep_running);

	state_id = ((mk_win_sl_copier_state_t)(copier->m_state));
	switch(state_id)
	{
		case mk_win_sl_copier_state_e_src_open:             mk_win_sl_copier_make_step_hl_src_open            (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_src_get_type:         mk_win_sl_copier_make_step_hl_src_get_type        (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_src_get_cluster:      mk_win_sl_copier_make_step_hl_src_get_cluster     (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_src_get_size:         mk_win_sl_copier_make_step_hl_src_get_size        (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_dst_open:             mk_win_sl_copier_make_step_hl_dst_open            (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_dst_get_type:         mk_win_sl_copier_make_step_hl_dst_get_type        (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_dst_get_cluster:      mk_win_sl_copier_make_step_hl_dst_get_cluster     (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_dst_set_ptr:          mk_win_sl_copier_make_step_hl_dst_set_ptr         (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_dst_set_size:         mk_win_sl_copier_make_step_hl_dst_set_size        (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_cpr_allocate_buffers: mk_win_sl_copier_make_step_hl_cpr_allocate_buffers(copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_sra1:                 mk_win_sl_copier_make_step_hl_sra1                (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_srb1:                 mk_win_sl_copier_make_step_hl_srb1                (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_wrarb:                mk_win_sl_copier_make_step_hl_wrarb               (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_swa1:                 mk_win_sl_copier_make_step_hl_swa1                (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_wrbwa:                mk_win_sl_copier_make_step_hl_wrbwa               (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_sra2:                 mk_win_sl_copier_make_step_hl_sra2                (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_wrbra:                mk_win_sl_copier_make_step_hl_wrbra               (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_swb1:                 mk_win_sl_copier_make_step_hl_swb1                (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_wrawb:                mk_win_sl_copier_make_step_hl_wrawb               (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_swb2:                 mk_win_sl_copier_make_step_hl_swb2                (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_wwawb:                mk_win_sl_copier_make_step_hl_wwawb               (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_sra3:                 mk_win_sl_copier_make_step_hl_sra3                (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_wwbra:                mk_win_sl_copier_make_step_hl_wwbra               (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_swa2:                 mk_win_sl_copier_make_step_hl_swa2                (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_wwbwa:                mk_win_sl_copier_make_step_hl_wwbwa               (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_srb2:                 mk_win_sl_copier_make_step_hl_srb2                (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_wwarb:                mk_win_sl_copier_make_step_hl_wwarb               (copier, ex, keep_running); mk_lang_exception_if_is_return(ex); break;
		case mk_win_sl_copier_state_e_dummy_end: mk_lang_assert(0); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_win_sl_copier_make_step(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept
{
	mk_lang_types_bool_t keep_running;

	mk_lang_assert(copier);
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	keep_running = mk_lang_false;
	do
	{
		mk_win_sl_copier_make_step_2(copier, ex, &keep_running); mk_lang_exception_if_is_break(ex);
		return keep_running;
	}while(0);
	return mk_lang_false;
}
