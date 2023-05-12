#include "mk_lib_fe.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_exception.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_sl_buffer_win_main_heap.h"
#include "mk_win_base.h"
#include "mk_win_kernel_errors.h"
#include "mk_win_kernel_files.h"
#include "mk_win_main_heap.h"
#include "mk_win_tstring.h"


struct mk_lib_fe_data_s
{
	mk_win_kernel_files_t_find_data_t m_data;
	int m_name_len;
	int m_name83_len;
};
typedef struct mk_lib_fe_data_s mk_lib_fe_data_t;
typedef mk_lib_fe_data_t const mk_lib_fe_data_ct;
typedef mk_lib_fe_data_t* mk_lib_fe_data_pt;
typedef mk_lib_fe_data_t const mk_lib_fe_data_ct;
typedef mk_lib_fe_data_t* mk_lib_fe_data_pt;
typedef mk_lib_fe_data_t const* mk_lib_fe_data_pct;
typedef mk_lib_fe_data_t mk_win_base_far* mk_lib_fe_data_lpt;
typedef mk_lib_fe_data_t mk_win_base_far const* mk_lib_fe_data_lpct;
typedef mk_lib_fe_data_t mk_win_base_near* mk_lib_fe_data_npt;
typedef mk_lib_fe_data_t mk_win_base_near const* mk_lib_fe_data_npct;


#define mk_sl_vector_t_name fedata
#define mk_sl_vector_t_elem_t mk_lib_fe_data_t
#define mk_sl_vector_t_buffer_tn mk_sl_buffer_win_main_heap
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"

#define mk_sl_vector_t_name fetchar
#define mk_sl_vector_t_elem_t mk_win_tstring_tchar_t
#define mk_sl_vector_t_buffer_tn mk_sl_buffer_win_main_heap
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"

#define mk_sl_vector_t_name feint
#define mk_sl_vector_t_elem_t int
#define mk_sl_vector_t_buffer_tn mk_sl_buffer_win_main_heap
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"


enum mk_lib_fe_state_e
{
	mk_lib_fe_state_e_init,
	mk_lib_fe_state_e_roots,
	mk_lib_fe_state_e_folders,
	mk_lib_fe_state_e_err_path_not_found,
	mk_lib_fe_state_e_err_access_denied,
	mk_lib_fe_state_e_err_not_ready
};
typedef enum mk_lib_fe_state_e mk_lib_fe_state_t;


#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(push)
#pragma warning(disable:4820) /* warning C4820: 'xxx': 'xxx' bytes padding added after data member 'xxx' */
#endif
struct mk_lib_fe_s
{
	mk_lib_fe_state_t m_state;
	mk_win_base_dword_t m_drives_mask;
	int m_drives_count;
	int m_addon_len;
	mk_sl_vector_fetchar_t m_str;
	mk_sl_vector_fedata_t m_data;
	mk_sl_vector_feint_t m_sort;
	mk_sl_vector_feint_t m_breadcrumb;
};
typedef struct mk_lib_fe_s mk_lib_fe_t;
typedef mk_lib_fe_t const mk_lib_fe_ct;
typedef mk_lib_fe_t* mk_lib_fe_pt;
typedef mk_lib_fe_t const* mk_lib_fe_pct;
typedef mk_lib_fe_t mk_win_base_far* mk_lib_fe_lpt;
typedef mk_lib_fe_t mk_win_base_far const* mk_lib_fe_lpct;
typedef mk_lib_fe_t mk_win_base_near* mk_lib_fe_npt;
typedef mk_lib_fe_t mk_win_base_near const* mk_lib_fe_npct;
#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(pop)
#endif


typedef int* int_pt;
typedef int const* int_pct; /* todo move away */


static mk_win_tstring_tchar_t const s_mk_lib_fe_up[] = mk_win_tstring_tchar_c("> ..");


static mk_lang_inline void mk_lib_fe_breadcrumb_go_dn(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_inline void mk_lib_fe_breadcrumb_go_up(mk_lib_fe_lpt const fe) mk_lang_noexcept;
static mk_lang_inline void mk_lib_fe_go_to_item_all(mk_lib_fe_lpt const fe) mk_lang_noexcept;
static mk_lang_inline void mk_lib_fe_go_to_item_up(mk_lib_fe_lpt const fe) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_to_item_roots(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_to_item_folders(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_to_item_err_path_not_found(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_to_item_err_access_denied(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_to_item_err_not_ready(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_up_roots(mk_lib_fe_lpt const fe) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_up_folders(mk_lib_fe_lpt const fe) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_up_err_path_not_found(mk_lib_fe_lpt const fe) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_up_err_access_denied(mk_lib_fe_lpt const fe) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_up_err_not_ready(mk_lib_fe_lpt const fe) mk_lang_noexcept;
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
static mk_lang_inline int mk_lib_fe_ensure_has_length(mk_lib_fe_data_lpt const data) mk_lang_noexcept;
static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_is_sorted(mk_lib_fe_data_lpct const a, mk_lib_fe_data_lpct const b) mk_lang_noexcept;
static mk_lang_inline void mk_lib_fe_sort_merge(mk_lib_fe_data_lpct const data, int_pct const input_a, int const cnt_a, int_pt const input_b, int const cnt_b, int_pt const output) mk_lang_noexcept;
static mk_lang_inline void mk_lib_fe_sort_recursive(mk_lib_fe_data_lpct const data, int_pt const input, int const cnt, int_pt const tmp, int_pt const output) mk_lang_noexcept;
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
	fe->m_addon_len = 0;
	mk_sl_vector_fetchar_rw_construct(&fe->m_str);
	mk_sl_vector_fedata_rw_construct(&fe->m_data);
	mk_sl_vector_feint_rw_construct(&fe->m_sort);
	mk_sl_vector_feint_rw_construct(&fe->m_breadcrumb);
}

mk_lang_jumbo void mk_lib_fe_destroy(mk_lib_fe_lpt const fe) mk_lang_noexcept
{
	mk_sl_vector_fetchar_rw_destroy(&fe->m_str);
	mk_sl_vector_fedata_rw_destroy(&fe->m_data);
	mk_sl_vector_feint_rw_destroy(&fe->m_sort);
	mk_sl_vector_feint_rw_destroy(&fe->m_breadcrumb);
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
	mk_win_base_dword_t drives_mask;
	mk_win_base_dword_t drives;
	int cnt;
	int n;
	int i;

	mk_lang_assert(fe);

	drives_mask = mk_win_kernel_files_get_logical_drives(); mk_lang_assert(drives_mask != 0);
	drives = drives_mask;
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
	fe->m_state = mk_lib_fe_state_e_roots;
	fe->m_drives_mask = drives_mask;
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

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lib_fe_go_up(mk_lib_fe_lpt const fe) mk_lang_noexcept
{
	mk_lang_assert(fe);

	switch(fe->m_state)
	{
		case mk_lib_fe_state_e_init: mk_lang_assert(0); break;
		case mk_lib_fe_state_e_roots: return mk_lib_fe_go_up_roots(fe); break;
		case mk_lib_fe_state_e_folders: return mk_lib_fe_go_up_folders(fe); break;
		case mk_lib_fe_state_e_err_path_not_found: return mk_lib_fe_go_up_err_path_not_found(fe); break;
		case mk_lib_fe_state_e_err_access_denied: return mk_lib_fe_go_up_err_access_denied(fe); break;
		case mk_lib_fe_state_e_err_not_ready: return mk_lib_fe_go_up_err_not_ready(fe); break;
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
		case mk_lib_fe_state_e_folders: return ((int)(mk_sl_vector_fedata_ro_get_count(&fe->m_data))) + 1; break;
		case mk_lib_fe_state_e_err_path_not_found: return 1; break;
		case mk_lib_fe_state_e_err_access_denied: return 1; break;
		case mk_lib_fe_state_e_err_not_ready: return 1; break;
	}
	mk_lang_assert(0);
}

mk_lang_nodiscard mk_lang_jumbo int mk_lib_fe_get_breadcrumb_depth(mk_lib_fe_lpt const fe) mk_lang_noexcept
{
	mk_lang_assert(fe);

	return ((int)(mk_sl_vector_feint_ro_get_count(&fe->m_breadcrumb)));
}

mk_lang_nodiscard mk_lang_jumbo int mk_lib_fe_get_breadcrumb_value(mk_lib_fe_lpt const fe) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(mk_sl_vector_feint_ro_get_capacity(&fe->m_breadcrumb) > mk_sl_vector_feint_ro_get_count(&fe->m_breadcrumb));

	return mk_sl_vector_feint_ro_get_data(&fe->m_breadcrumb)[mk_sl_vector_feint_ro_get_count(&fe->m_breadcrumb)];
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
	mk_lang_exception_t ex;
	mk_win_tstring_tchar_lpt drive_str;
	mk_win_kernel_files_drive_type_t drive_type;

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
			mk_lang_exception_make_none(&ex);
			mk_sl_vector_fetchar_rw_reserve(&fe->m_str, &ex, 3 + 1);
			mk_lang_assert(!mk_lang_exception_is(&ex)); /* todo throw */
			drive_str = ((mk_win_tstring_tchar_lpt)(mk_lib_fe_get_name_short_str(fe, idx))); mk_lang_assert(drive_str); mk_lang_assert(*drive_str);
			drive_str[2] = mk_win_tstring_tchar_c('\\');
			drive_str[3] = mk_win_tstring_tchar_c('\0');
			drive_type = ((mk_win_kernel_files_drive_type_t)(mk_win_kernel_files_t_get_drive_type(drive_str)));
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
	mk_lib_fe_data_lpct data;
	mk_win_kernel_files_attribute_t attributes;

	mk_lang_assert(fe);
	mk_lang_assert(mk_lib_fe_has_attributes(fe, idx));

	ridx = *mk_sl_vector_feint_ro_get_data_at(&fe->m_sort, idx - 1);
	data = mk_sl_vector_fedata_ro_get_data_at(&fe->m_data, ridx);
	attributes = data->m_data.m_attributes;
	return attributes;
}


static mk_lang_inline void mk_lib_fe_breadcrumb_go_dn(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_exception_t ex;

	mk_lang_assert(fe);
	mk_lang_assert(idx >= 0);

	mk_lang_exception_make_none(&ex);
	mk_sl_vector_feint_rw_push_back(&fe->m_breadcrumb, &ex, &idx);
	mk_lang_assert(!mk_lang_exception_is(&ex)); /* todo throw */
}

static mk_lang_inline void mk_lib_fe_breadcrumb_go_up(mk_lib_fe_lpt const fe) mk_lang_noexcept
{
	mk_lang_assert(fe);

	mk_sl_vector_feint_rw_pop_back_one(&fe->m_breadcrumb);
}

static mk_lang_inline void mk_lib_fe_go_to_item_all(mk_lib_fe_lpt const fe) mk_lang_noexcept
{
	mk_lang_exception_t ex;
	mk_lib_fe_data_lpt data;
	mk_win_base_handle_t handle;
	mk_win_kernel_errors_id_t err;
	mk_win_base_bool_t closed;

	mk_lang_assert(fe);
	mk_lang_assert(mk_sl_vector_fetchar_ro_get_count(&fe->m_str) >= 4);

	mk_lang_exception_make_none(&ex);
	mk_sl_vector_fedata_rw_clear(&fe->m_data);
	mk_sl_vector_fedata_rw_reserve(&fe->m_data, &ex, mk_sl_vector_fedata_ro_get_count(&fe->m_data) + 1);
	mk_lang_assert(!mk_lang_exception_is(&ex)); /* todo throw */
	data = mk_sl_vector_fedata_rw_get_data(&fe->m_data) + mk_sl_vector_fedata_ro_get_count(&fe->m_data);
	handle = mk_win_kernel_files_t_find_first_file(mk_sl_vector_fetchar_ro_get_data(&fe->m_str), &data->m_data);
	if(handle == s_mk_win_base_handle_invalid)
	{
		err = ((mk_win_kernel_errors_id_t)(mk_win_kernel_errors_get_last()));
		if(err == mk_win_kernel_errors_id_e_path_not_found) fe->m_state = mk_lib_fe_state_e_err_path_not_found;
		else if(err == mk_win_kernel_errors_id_e_access_denied) fe->m_state = mk_lib_fe_state_e_err_access_denied;
		else if(err == mk_win_kernel_errors_id_e_not_ready) fe->m_state = mk_lib_fe_state_e_err_not_ready;
		else
		{
			mk_lang_assert(0); /* todo */
		}
	}
	else
	{
		for(;;)
		{
			mk_sl_vector_fedata_rw_push_back_from_capacity_one(&fe->m_data);
			if
			(
				(data->m_data.m_name[0] == mk_win_tstring_tchar_c('.') && data->m_data.m_name[1] == mk_win_tstring_tchar_c('\0')) ||
				(data->m_data.m_name[0] == mk_win_tstring_tchar_c('.') && data->m_data.m_name[1] == mk_win_tstring_tchar_c('.') && data->m_data.m_name[2] == mk_win_tstring_tchar_c('\0'))
			)
			{
				mk_sl_vector_fedata_rw_pop_back_one(&fe->m_data);
			}
			data->m_name_len = 0;
			mk_sl_vector_fedata_rw_reserve(&fe->m_data, &ex, mk_sl_vector_fedata_ro_get_count(&fe->m_data) + 1);
			mk_lang_assert(!mk_lang_exception_is(&ex)); /* todo throw */
			data = mk_sl_vector_fedata_rw_get_data(&fe->m_data) + mk_sl_vector_fedata_ro_get_count(&fe->m_data);
			if(mk_win_kernel_files_t_find_next_file(handle, &data->m_data) == 0)
			{
				err = ((mk_win_kernel_errors_id_t)(mk_win_kernel_errors_get_last()));
				if(err != mk_win_kernel_errors_id_e_no_more_files)
				{
					mk_lang_assert(0); /* todo */
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

	mk_lib_fe_breadcrumb_go_up(fe);
	mk_sl_vector_fetchar_rw_pop_back_n(&fe->m_str, fe->m_addon_len);
	fe->m_addon_len = 0;
	if(mk_sl_vector_fetchar_ro_get_count(&fe->m_str) == 2)
	{
		mk_lib_fe_go_to_root(fe);
	}
	else
	{
		fe->m_state = mk_lib_fe_state_e_folders;
		for(ptr = mk_sl_vector_fetchar_ro_get_data_at(&fe->m_str, mk_sl_vector_fetchar_ro_get_count(&fe->m_str) - 2); *ptr != mk_win_tstring_tchar_c('\\'); --ptr){}
		mk_sl_vector_fetchar_rw_pop_back_n(&fe->m_str, ((int)(mk_sl_vector_fetchar_ro_get_data(&fe->m_str) + mk_sl_vector_fetchar_ro_get_count(&fe->m_str) - ptr)));
		mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[mk_sl_vector_fetchar_ro_get_count(&fe->m_str) + 1] = mk_win_tstring_tchar_c('*');
		mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[mk_sl_vector_fetchar_ro_get_count(&fe->m_str) + 2] = mk_win_tstring_tchar_c('\0');
		mk_sl_vector_fetchar_rw_push_back_from_capacity_n(&fe->m_str, 2);
		fe->m_addon_len = 2;
		mk_lib_fe_go_to_item_all(fe);
	}
}

static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_to_item_roots(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_exception_t ex;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_roots);
	mk_lang_assert(idx >= 0 && idx < fe->m_drives_count);

	mk_lang_exception_make_none(&ex);
	mk_sl_vector_fetchar_rw_reserve(&fe->m_str, &ex, 4 + 1);
	mk_lang_assert(!mk_lang_exception_is(&ex)); /* todo throw */
	((void)(mk_lib_fe_get_name_short_str(fe, idx)));
	mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[2] = mk_win_tstring_tchar_c('\\');
	mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[3] = mk_win_tstring_tchar_c('*');
	mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[4] = mk_win_tstring_tchar_c('\0');
	mk_sl_vector_fetchar_rw_clear(&fe->m_str);
	mk_sl_vector_fetchar_rw_push_back_from_capacity_n(&fe->m_str, 4);
	fe->m_addon_len = 2;
	fe->m_state = mk_lib_fe_state_e_folders;
	mk_lib_fe_breadcrumb_go_dn(fe, idx);
	mk_lib_fe_go_to_item_all(fe);
	return mk_lang_true;
}

static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_to_item_folders(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	int ridx;
	mk_lib_fe_data_lpt data;
	int name_len;
	mk_lang_exception_t ex;
	int i;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_folders);
	mk_lang_assert(idx >= 0 && idx < ((int)(mk_sl_vector_fedata_ro_get_count(&fe->m_data))) + 1);

	if(idx == 0)
	{
		mk_lib_fe_go_to_item_up(fe);
		return mk_lang_true;
	}
	else
	{
		ridx = *mk_sl_vector_feint_ro_get_data_at(&fe->m_sort, idx - 1);
		data = mk_sl_vector_fedata_rw_get_data_at(&fe->m_data, ridx);
		if((data->m_data.m_attributes & mk_win_kernel_files_attribute_e_directory) != 0)
		{
			name_len = mk_lib_fe_ensure_has_length(data);
			mk_sl_vector_fetchar_rw_pop_back_n(&fe->m_str, fe->m_addon_len);
			mk_lang_exception_make_none(&ex);
			mk_sl_vector_fetchar_rw_reserve(&fe->m_str, &ex, mk_sl_vector_fetchar_ro_get_count(&fe->m_str) + 1 + name_len + 2 + 1);
			mk_lang_assert(!mk_lang_exception_is(&ex)); /* todo throw */
			mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[mk_sl_vector_fetchar_ro_get_count(&fe->m_str)] = mk_win_tstring_tchar_c('\\');
			for(i = 0; i != name_len; ++i){ mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[mk_sl_vector_fetchar_ro_get_count(&fe->m_str) + 1 + i] = data->m_data.m_name[i]; }
			mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[mk_sl_vector_fetchar_ro_get_count(&fe->m_str) + 1 + name_len + 0] = mk_win_tstring_tchar_c('\\');
			mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[mk_sl_vector_fetchar_ro_get_count(&fe->m_str) + 1 + name_len + 1] = mk_win_tstring_tchar_c('*');
			mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[mk_sl_vector_fetchar_ro_get_count(&fe->m_str) + 1 + name_len + 2] = mk_win_tstring_tchar_c('\0');
			mk_sl_vector_fetchar_rw_push_back_from_capacity_n(&fe->m_str, 1 + name_len + 2);
			fe->m_addon_len = 2;
			mk_lib_fe_breadcrumb_go_dn(fe, idx);
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

static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_up_roots(mk_lib_fe_lpt const fe) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_roots);

	mk_sl_vector_feint_rw_clear(&fe->m_breadcrumb);

	return mk_lang_false;
}

static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_up_folders(mk_lib_fe_lpt const fe) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_folders);

	mk_lib_fe_go_to_item_up(fe);
	return mk_lang_true;
}

static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_up_err_path_not_found(mk_lib_fe_lpt const fe) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_err_path_not_found);

	mk_lib_fe_go_to_item_up(fe);
	return mk_lang_true;
}

static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_up_err_access_denied(mk_lib_fe_lpt const fe) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_err_access_denied);

	mk_lib_fe_go_to_item_up(fe);
	return mk_lang_true;
}

static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_go_up_err_not_ready(mk_lib_fe_lpt const fe) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_err_not_ready);

	mk_lib_fe_go_to_item_up(fe);
	return mk_lang_true;
}

static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_short_str_roots(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_win_base_dword_t drives;
	int cnt;
	int n;
	int i;
	mk_lang_exception_t ex;

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
				mk_sl_vector_fetchar_rw_clear(&fe->m_str);
				mk_lang_exception_make_none(&ex);
				mk_sl_vector_fetchar_rw_reserve(&fe->m_str, &ex, 2 + 1);
				mk_lang_assert(!mk_lang_exception_is(&ex)); /* todo throw */
				mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[0] = ((mk_win_tstring_tchar_t)(mk_win_tstring_tchar_c('a') + i));
				mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[1] = mk_win_tstring_tchar_c(':');
				mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[2] = mk_win_tstring_tchar_c('\0');
				mk_sl_vector_fetchar_rw_push_back_from_capacity_n(&fe->m_str, 2);
				fe->m_addon_len = 0;
				return mk_sl_vector_fetchar_ro_get_data(&fe->m_str);
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
	mk_lib_fe_data_lpt data;
	mk_lang_exception_t ex;
	int name_len;
	int i;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_folders);
	mk_lang_assert(idx >= 0 && idx < ((int)(mk_sl_vector_fedata_ro_get_count(&fe->m_data))) + 1);

	if(idx == 0)
	{
		return s_mk_lib_fe_up;
	}
	else
	{
		ridx = *mk_sl_vector_feint_ro_get_data_at(&fe->m_sort, idx - 1);
		data = mk_sl_vector_fedata_rw_get_data_at(&fe->m_data, ridx);
		if((data->m_data.m_attributes & mk_win_kernel_files_attribute_e_directory) != 0)
		{
			name_len = mk_lib_fe_ensure_has_length(data);
			mk_lang_exception_make_none(&ex);
			mk_sl_vector_fetchar_rw_reserve(&fe->m_str, &ex, 2 + mk_sl_vector_fetchar_ro_get_count(&fe->m_str) + 1 + name_len + 1);
			mk_lang_assert(!mk_lang_exception_is(&ex)); /* todo throw */
			mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[mk_sl_vector_fetchar_ro_get_count(&fe->m_str) + 1] = mk_win_tstring_tchar_c('>'); /* todo create dir prefix constant */
			mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[mk_sl_vector_fetchar_ro_get_count(&fe->m_str) + 2] = mk_win_tstring_tchar_c(' ');
			for(i = 0; i != name_len + 1; ++i){ mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[mk_sl_vector_fetchar_ro_get_count(&fe->m_str) + 3 + i] = data->m_data.m_name[i]; }
			return mk_sl_vector_fetchar_ro_get_data(&fe->m_str) + mk_sl_vector_fetchar_ro_get_count(&fe->m_str) + 1;
		}
		else
		{
			return mk_sl_vector_fedata_ro_get_data_at(&fe->m_data, ridx)->m_data.m_name;
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
	mk_lib_fe_data_lpt data;
	int name_len;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_folders);
	mk_lang_assert(idx >= 0 && idx < ((int)(mk_sl_vector_fedata_ro_get_count(&fe->m_data))) + 1);

	if(idx == 0)
	{
		return ((int)(sizeof(s_mk_lib_fe_up) / sizeof(s_mk_lib_fe_up[0]) - 1));
	}
	else
	{
		ridx = *mk_sl_vector_feint_ro_get_data_at(&fe->m_sort, idx - 1);
		data = mk_sl_vector_fedata_rw_get_data_at(&fe->m_data, ridx);
		name_len = mk_lib_fe_ensure_has_length(data); mk_lang_assert(name_len > 0);
		if((data->m_data.m_attributes & mk_win_kernel_files_attribute_e_directory) != 0)
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
	mk_lib_fe_data_lpt data;
	int name_len;
	mk_lang_exception_t ex;
	int i;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_folders);
	mk_lang_assert(idx >= 0 && idx < ((int)(mk_sl_vector_fedata_ro_get_count(&fe->m_data))) + 1);

	if(idx == 0)
	{
		return s_mk_lib_fe_up;
	}
	else
	{
		ridx = *mk_sl_vector_feint_ro_get_data_at(&fe->m_sort, idx - 1);
		data = mk_sl_vector_fedata_rw_get_data_at(&fe->m_data, ridx);
		name_len = mk_lib_fe_ensure_has_length(data);
		mk_sl_vector_fetchar_rw_pop_back_n(&fe->m_str, fe->m_addon_len);
		mk_lang_exception_make_none(&ex);
		mk_sl_vector_fetchar_rw_reserve(&fe->m_str, &ex, mk_sl_vector_fetchar_ro_get_count(&fe->m_str) + 1 + name_len + 1);
		mk_lang_assert(!mk_lang_exception_is(&ex)); /* todo throw */
		mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[mk_sl_vector_fetchar_ro_get_count(&fe->m_str)] = mk_win_tstring_tchar_c('\\');
		for(i = 0; i != name_len + 1; ++i){ mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[mk_sl_vector_fetchar_ro_get_count(&fe->m_str) + 1 + i] = data->m_data.m_name[i]; }
		mk_sl_vector_fetchar_rw_push_back_from_capacity_n(&fe->m_str, 1 + name_len);
		fe->m_addon_len = (1 + name_len);
		return mk_sl_vector_fetchar_ro_get_data(&fe->m_str);
	}
}

static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_long_str_err_path_not_found(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_err_path_not_found);
	mk_lang_assert(idx == 0);

	mk_sl_vector_fetchar_rw_pop_back_n(&fe->m_str, fe->m_addon_len);
	fe->m_addon_len = 0;
	mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[mk_sl_vector_fetchar_ro_get_count(&fe->m_str)] = mk_win_tstring_tchar_c('\0');
	return mk_sl_vector_fetchar_ro_get_data(&fe->m_str);
}

static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_long_str_err_access_denied(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_err_access_denied);
	mk_lang_assert(idx == 0);

	mk_sl_vector_fetchar_rw_pop_back_n(&fe->m_str, fe->m_addon_len);
	fe->m_addon_len = 0;
	mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[mk_sl_vector_fetchar_ro_get_count(&fe->m_str)] = mk_win_tstring_tchar_c('\0');
	return mk_sl_vector_fetchar_ro_get_data(&fe->m_str);
}

static mk_lang_nodiscard mk_lang_inline mk_win_tstring_tchar_lpct mk_lib_fe_get_name_long_str_err_not_ready(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_state == mk_lib_fe_state_e_err_not_ready);
	mk_lang_assert(idx == 0);

	mk_sl_vector_fetchar_rw_pop_back_n(&fe->m_str, fe->m_addon_len);
	fe->m_addon_len = 0;
	mk_sl_vector_fetchar_rw_get_data(&fe->m_str)[mk_sl_vector_fetchar_ro_get_count(&fe->m_str)] = mk_win_tstring_tchar_c('\0');
	return mk_sl_vector_fetchar_ro_get_data(&fe->m_str);
}

static mk_lang_inline int mk_lib_fe_ensure_has_length(mk_lib_fe_data_lpt const data) mk_lang_noexcept
{
	mk_win_tstring_tchar_lpct name;
	int name_len;

	mk_lang_assert(data);

	if(data->m_name_len == 0)
	{
		name = data->m_data.m_name;
		mk_lang_assert(*name);
		name_len = 0;
		do{ ++name_len; }while(name[name_len]);
		mk_lang_assert(name_len != 0);
		data->m_name_len = name_len;
	}
	return data->m_name_len;
}

static mk_lang_nodiscard mk_lang_inline mk_lang_bool_t mk_lib_fe_is_sorted(mk_lib_fe_data_lpct const a, mk_lib_fe_data_lpct const b) mk_lang_noexcept
{
	mk_lang_bool_t is_dir_a;
	mk_lang_bool_t is_dir_b;
	mk_win_tstring_tchar_lpct name_a;
	mk_win_tstring_tchar_lpct name_b;
	mk_win_tstring_tchar_t ch_a;
	mk_win_tstring_tchar_t ch_b;

	mk_lang_assert(a);
	mk_lang_assert(b);

	is_dir_a = ((a->m_data.m_attributes & mk_win_kernel_files_attribute_e_directory) != 0);
	is_dir_b = ((b->m_data.m_attributes & mk_win_kernel_files_attribute_e_directory) != 0);
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
		name_a = a->m_data.m_name;
		name_b = b->m_data.m_name;
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
			if(((unsigned)(ch_a)) < ((unsigned)(ch_b)))
			{
				return mk_lang_true;
			}
			else if(((unsigned)(ch_b)) < ((unsigned)(ch_a)))
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

static mk_lang_inline void mk_lib_fe_sort_merge(mk_lib_fe_data_lpct const data, int_pct const input_a, int const cnt_a, int_pt const input_b, int const cnt_b, int_pt const output) mk_lang_noexcept
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

static mk_lang_inline void mk_lib_fe_sort_recursive(mk_lib_fe_data_lpct const data, int_pt const input, int const cnt, int_pt const tmp, int_pt const output) mk_lang_noexcept
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
	mk_lang_exception_t ex;
	int n;
	int_pt pi;
	int i;
	mk_lib_fe_data_lpct data;

	mk_lang_assert(fe);

	mk_lang_exception_make_none(&ex);
	n = ((int)(mk_sl_vector_fedata_ro_get_count(&fe->m_data)));
	mk_sl_vector_feint_rw_reserve(&fe->m_sort, &ex, 3 * n);
	mk_lang_assert(!mk_lang_exception_is(&ex)); /* todo throw */
	mk_sl_vector_feint_rw_clear(&fe->m_sort);
	mk_sl_vector_feint_rw_push_back_from_capacity_n(&fe->m_sort, n);
	pi = mk_sl_vector_feint_rw_get_data(&fe->m_sort);
	for(i = 0; i != n; ++i){ pi[i] = i; }
	if(n >= 2)
	{
		data = mk_sl_vector_fedata_ro_get_data(&fe->m_data);
		mk_lib_fe_sort_recursive(data, pi, n, pi + n, pi + 2 * n);
		for(i = 0; i != n; ++i){ pi[i] = pi[n * 2 + i]; }
	}
}
