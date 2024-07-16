#include "mk_clib_app_fe.h"

#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_attribute.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clamp.h"
#include "mk_lang_concat.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_exe_name.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_offsetof.h"
#include "mk_lang_platform.h"
#include "mk_lang_pow2.h"
#include "mk_lang_roundup.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_strlen.h"
#include "mk_lang_types.h"
#include "mk_lib_fmt.h"
#include "mk_lib_mt_cv.h"
#include "mk_lib_mt_mutex.h"
#include "mk_lib_mt_thread.h"
#include "mk_lib_mt_unique_lock.h"
#include "mk_lib_win_impersonate_linked.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"
#include "mk_win_advapi_token.h"
#include "mk_win_kernel_errors.h"
#include "mk_win_kernel_files.h"
#include "mk_win_kernel_handle.h"
#include "mk_win_kernel_process.h"
#include "mk_win_kernel_string.h"
#include "mk_win_kernel_thread.h"
#include "mk_win_user_base.h"
#include "mk_win_user_brush.h"
#include "mk_win_user_class.h"
#include "mk_win_user_cursor.h"
#include "mk_win_user_dc.h"
#include "mk_win_user_icon.h"
#include "mk_win_user_msg.h"
#include "mk_win_user_window.h"

#if defined mk_clib_app_fe_mallocatorg_want && (mk_clib_app_fe_mallocatorg_want) == 2
#define mk_clib_app_fe_mallocatorg_id 2
#elif defined mk_clib_app_fe_mallocatorg_want && (mk_clib_app_fe_mallocatorg_want) == 3
#define mk_clib_app_fe_mallocatorg_id 3
#elif defined mk_clib_app_fe_mallocatorg_want && (mk_clib_app_fe_mallocatorg_want) == 4
#define mk_clib_app_fe_mallocatorg_id 4
#elif defined mk_clib_app_fe_mallocatorg_want && (mk_clib_app_fe_mallocatorg_want) == 5
#define mk_clib_app_fe_mallocatorg_id 5
#elif defined mk_clib_app_fe_mallocatorg_want && (mk_clib_app_fe_mallocatorg_want) == 6
#define mk_clib_app_fe_mallocatorg_id 6
#elif !defined mk_clib_app_fe_mallocatorg_want
#if defined NDEBUG
#define mk_clib_app_fe_mallocatorg_id 2
#else
#define mk_clib_app_fe_mallocatorg_id 6
#endif
#else
#error xxxxxxxxxx
#endif

#if mk_clib_app_fe_mallocatorg_id == 2
#include "mk_sl_mallocatorg.h"
#define mk_clib_app_fe_mallocatorg_name mk_sl_mallocatorg
#elif mk_clib_app_fe_mallocatorg_id == 3
#include "mk_sl_mallocatorg_portablec.h"
#define mk_clib_app_fe_mallocatorg_name mk_sl_mallocatorg_portablec
#elif mk_clib_app_fe_mallocatorg_id == 4
#include "mk_sl_mallocatorg_portablecpp.hpp"
#define mk_clib_app_fe_mallocatorg_name mk_sl_mallocatorg_portablecpp
#elif mk_clib_app_fe_mallocatorg_id == 5
#include "mk_sl_mallocatorg_windows.h"
#define mk_clib_app_fe_mallocatorg_name mk_sl_mallocatorg_windows
#elif mk_clib_app_fe_mallocatorg_id == 6
#include "mk_sl_mallocg_tracer.h"
#define mk_clib_app_fe_mallocatorg_name mk_sl_mallocg_tracer
#else
#error xxxxxxxxxx
#endif
#define mk_clib_app_fe_mallocatorg_init mk_lang_concat(mk_clib_app_fe_mallocatorg_name, _init)
#define mk_clib_app_fe_mallocatorg_deinit mk_lang_concat(mk_clib_app_fe_mallocatorg_name, _deinit)

#define mk_lang_memset_t_name mk_clib_app_fe_memset_uc
#define mk_lang_memset_t_type mk_lang_types_uchar_t
#include "mk_lang_memset_inl_fileh.h"
#include "mk_lang_memset_inl_filec.h"

#define mk_lang_memcmp_t_name mk_clib_app_fe_memcmp_uc
#define mk_lang_memcmp_t_type mk_lang_types_uchar_t
#include "mk_lang_memcmp_inl_fileh.h"
#include "mk_lang_memcmp_inl_filec.h"

#define mk_lang_memcpy_t_name mk_clib_app_fe_memcpy_wc
#define mk_lang_memcpy_t_type mk_lang_types_wchar_t
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"

#define mk_sl_vector_t_name mk_clib_app_fe_server_name
#define mk_sl_vector_t_element mk_lang_types_wchar_t
#define mk_sl_vector_t_mallocatorg mk_clib_app_fe_mallocatorg_name
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"

#define mk_sl_vector_t_name mk_clib_app_fe_server_ints
#define mk_sl_vector_t_element mk_lang_types_sint_t
#define mk_sl_vector_t_mallocatorg mk_clib_app_fe_mallocatorg_name
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"

#define mk_lang_bui_t_name mk_clib_app_fe_server_uint
#define mk_lang_bui_t_base uint
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"

#define mk_lib_mt_atomic_t_name mk_clib_app_fe_server_atomic_sint
#define mk_lib_mt_atomic_t_type mk_lang_types_sint_t
#include "mk_lib_mt_atomic_inl_fileh.h"
#include "mk_lib_mt_atomic_inl_filec.h"

struct mk_clib_app_fe_server_file_s
{
	mk_lang_types_bool_t m_is_dir;
	mk_clib_app_fe_server_name_t m_name;
};
typedef struct mk_clib_app_fe_server_file_s mk_clib_app_fe_server_file_t;
typedef mk_clib_app_fe_server_file_t const mk_clib_app_fe_server_file_ct;
typedef mk_clib_app_fe_server_file_t* mk_clib_app_fe_server_file_pt;
typedef mk_clib_app_fe_server_file_t const* mk_clib_app_fe_server_file_pct;

#define mk_sl_vector_t_name mk_clib_app_fe_server_files
#define mk_sl_vector_t_element mk_clib_app_fe_server_file_t
#define mk_sl_vector_t_mallocatorg mk_clib_app_fe_mallocatorg_name
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"

enum mk_clib_app_fe_server_request_type_e
{
	mk_clib_app_fe_server_request_type_e_root,
	mk_clib_app_fe_server_request_type_e_idx,
	mk_clib_app_fe_server_request_type_e_dummy_end
};
typedef enum mk_clib_app_fe_server_request_type_e mk_clib_app_fe_server_request_type_t;

struct mk_clib_app_fe_server_request_root_s
{
	mk_lang_types_sint_t m_dummy;
};
typedef struct mk_clib_app_fe_server_request_root_s mk_clib_app_fe_server_request_root_t;
typedef mk_clib_app_fe_server_request_root_t const mk_clib_app_fe_server_request_root_ct;
typedef mk_clib_app_fe_server_request_root_t* mk_clib_app_fe_server_request_root_pt;
typedef mk_clib_app_fe_server_request_root_t const* mk_clib_app_fe_server_request_root_pct;

struct mk_clib_app_fe_server_request_idx_s
{
	mk_lang_types_sint_t m_idx;
};
typedef struct mk_clib_app_fe_server_request_idx_s mk_clib_app_fe_server_request_idx_t;
typedef mk_clib_app_fe_server_request_idx_t const mk_clib_app_fe_server_request_idx_ct;
typedef mk_clib_app_fe_server_request_idx_t* mk_clib_app_fe_server_request_idx_pt;
typedef mk_clib_app_fe_server_request_idx_t const* mk_clib_app_fe_server_request_idx_pct;

union mk_clib_app_fe_server_request_data_u
{
	mk_clib_app_fe_server_request_root_t m_root;
	mk_clib_app_fe_server_request_idx_t m_idx;
};
typedef union mk_clib_app_fe_server_request_data_u mk_clib_app_fe_server_request_data_t;

struct mk_clib_app_fe_server_request_s
{
	mk_clib_app_fe_server_atomic_sint_t m_ref_count;
	mk_clib_app_fe_server_request_type_t m_type;
	mk_lang_types_uint_t m_req_id;
	mk_clib_app_fe_server_request_data_t m_data;
};
typedef struct mk_clib_app_fe_server_request_s mk_clib_app_fe_server_request_t;
typedef mk_clib_app_fe_server_request_t const mk_clib_app_fe_server_request_ct;
typedef mk_clib_app_fe_server_request_t* mk_clib_app_fe_server_request_pt;
typedef mk_clib_app_fe_server_request_t const* mk_clib_app_fe_server_request_pct;

enum mk_clib_app_fe_server_response_type_e
{
	mk_clib_app_fe_server_response_type_e_notadir,
	mk_clib_app_fe_server_response_type_e_invalid,
	mk_clib_app_fe_server_response_type_e_root,
	mk_clib_app_fe_server_response_type_e_idx,
	mk_clib_app_fe_server_response_type_e_dummy_end
};
typedef enum mk_clib_app_fe_server_response_type_e mk_clib_app_fe_server_response_type_t;

struct mk_clib_app_fe_server_response_nothing_s
{
	mk_lang_types_sint_t m_dummy;
};
typedef struct mk_clib_app_fe_server_response_nothing_s mk_clib_app_fe_server_response_nothing_t;
typedef mk_clib_app_fe_server_response_nothing_t const mk_clib_app_fe_server_response_nothing_ct;
typedef mk_clib_app_fe_server_response_nothing_t* mk_clib_app_fe_server_response_nothing_pt;
typedef mk_clib_app_fe_server_response_nothing_t const* mk_clib_app_fe_server_response_nothing_pct;

struct mk_clib_app_fe_server_response_invalid_s
{
	mk_lang_types_sint_t m_dummy;
};
typedef struct mk_clib_app_fe_server_response_invalid_s mk_clib_app_fe_server_response_invalid_t;
typedef mk_clib_app_fe_server_response_invalid_t const mk_clib_app_fe_server_response_invalid_ct;
typedef mk_clib_app_fe_server_response_invalid_t* mk_clib_app_fe_server_response_invalid_pt;
typedef mk_clib_app_fe_server_response_invalid_t const* mk_clib_app_fe_server_response_invalid_pct;

struct mk_clib_app_fe_server_response_root_s
{
	mk_lang_types_uint_t m_drive_letters;
	mk_lang_types_uchar_t m_drive_types[((mk_lang_types_sint_t)('z' - 'a')) + 1];
};
typedef struct mk_clib_app_fe_server_response_root_s mk_clib_app_fe_server_response_root_t;
typedef mk_clib_app_fe_server_response_root_t const mk_clib_app_fe_server_response_root_ct;
typedef mk_clib_app_fe_server_response_root_t* mk_clib_app_fe_server_response_root_pt;
typedef mk_clib_app_fe_server_response_root_t const* mk_clib_app_fe_server_response_root_pct;

struct mk_clib_app_fe_server_response_idx_s
{
	mk_clib_app_fe_server_name_t m_path;
	mk_clib_app_fe_server_files_t m_files;
	mk_clib_app_fe_server_ints_t m_sort;
	mk_lang_types_bool_t m_went_up;
	mk_win_base_dword_t m_gle;
};
typedef struct mk_clib_app_fe_server_response_idx_s mk_clib_app_fe_server_response_idx_t;
typedef mk_clib_app_fe_server_response_idx_t const mk_clib_app_fe_server_response_idx_ct;
typedef mk_clib_app_fe_server_response_idx_t* mk_clib_app_fe_server_response_idx_pt;
typedef mk_clib_app_fe_server_response_idx_t const* mk_clib_app_fe_server_response_idx_pct;

union mk_clib_app_fe_server_response_data_u
{
	mk_clib_app_fe_server_response_nothing_t m_nothing;
	mk_clib_app_fe_server_response_invalid_t m_invalid;
	mk_clib_app_fe_server_response_root_t m_root;
	mk_clib_app_fe_server_response_idx_t m_idx;
};
typedef union mk_clib_app_fe_server_response_data_u mk_clib_app_fe_server_response_data_t;

struct mk_clib_app_fe_server_response_s
{
	mk_clib_app_fe_server_atomic_sint_t m_ref_count;
	mk_clib_app_fe_server_response_type_t m_type;
	mk_lang_types_uint_t m_req_id;
	mk_clib_app_fe_server_response_data_t m_data;
};
typedef struct mk_clib_app_fe_server_response_s mk_clib_app_fe_server_response_t;
typedef mk_clib_app_fe_server_response_t const mk_clib_app_fe_server_response_ct;
typedef mk_clib_app_fe_server_response_t* mk_clib_app_fe_server_response_pt;
typedef mk_clib_app_fe_server_response_t const* mk_clib_app_fe_server_response_pct;

#define mk_sl_array_t_name mk_clib_app_fe_server_requests_store
#define mk_sl_array_t_element mk_clib_app_fe_server_request_t
#define mk_sl_array_t_count 32
#include "mk_sl_array_inl_fileh.h"
#include "mk_sl_array_inl_filec.h"

#define mk_lib_mt_ring_t_name mk_clib_app_fe_server_requestsmt
#define mk_lib_mt_ring_t_element mk_clib_app_fe_server_request_pt
#define mk_lib_mt_ring_t_count 32
#include "mk_lib_mt_ring_inl_fileh.h"
#include "mk_lib_mt_ring_inl_filec.h"

#define mk_sl_array_t_name mk_clib_app_fe_server_responses_store
#define mk_sl_array_t_element mk_clib_app_fe_server_response_t
#define mk_sl_array_t_count 32
#include "mk_sl_array_inl_fileh.h"
#include "mk_sl_array_inl_filec.h"

#define mk_lib_mt_ring_t_name mk_clib_app_fe_server_responsesmt
#define mk_lib_mt_ring_t_element mk_clib_app_fe_server_response_pt
#define mk_lib_mt_ring_t_count 32
#include "mk_lib_mt_ring_inl_fileh.h"
#include "mk_lib_mt_ring_inl_filec.h"

#if mk_lang_version_at_least_cpp_17
typedef mk_lang_types_sint_t(*mk_clib_app_fe_server_callback_on_response_t)(mk_lang_types_void_pt const ctx, mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept;
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
mk_lang_nodiscard static mk_lang_types_sint_t mk_clib_app_fe_server_callback_on_response_dummy(mk_lang_types_void_pt const ctx, mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept;
typedef decltype(&mk_clib_app_fe_server_callback_on_response_dummy) mk_clib_app_fe_server_callback_on_response_t;
#else
typedef mk_lang_types_sint_t(*mk_clib_app_fe_server_callback_on_response_t)(mk_lang_types_void_pt const ctx, mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept;
#endif

struct mk_clib_app_fe_server_s;
typedef struct mk_clib_app_fe_server_s mk_clib_app_fe_server_t;
typedef mk_clib_app_fe_server_t const mk_clib_app_fe_server_ct;
typedef mk_clib_app_fe_server_t* mk_clib_app_fe_server_pt;
typedef mk_clib_app_fe_server_t const* mk_clib_app_fe_server_pct;

struct mk_clib_app_fe_window_s;
typedef struct mk_clib_app_fe_window_s mk_clib_app_fe_window_t;
typedef mk_clib_app_fe_window_t const mk_clib_app_fe_window_ct;
typedef mk_clib_app_fe_window_t* mk_clib_app_fe_window_pt;
typedef mk_clib_app_fe_window_t const* mk_clib_app_fe_window_pct;

struct mk_clib_app_fe_s;
typedef struct mk_clib_app_fe_s mk_clib_app_fe_t;
typedef mk_clib_app_fe_t const mk_clib_app_fe_ct;
typedef mk_clib_app_fe_t* mk_clib_app_fe_pt;
typedef mk_clib_app_fe_t const* mk_clib_app_fe_pct;

struct mk_clib_app_fe_server_s
{
	mk_lib_mt_mutex_t m_mtx;
	mk_clib_app_fe_server_callback_on_response_t m_on_response_fun;
	mk_lang_types_void_pt m_on_response_ctx;
	mk_clib_app_fe_server_response_pt m_response_current;
	mk_clib_app_fe_server_requestsmt_t m_requests_waiting;
	mk_clib_app_fe_server_requestsmt_t m_requests_ready;
	mk_clib_app_fe_server_responsesmt_t m_responses_ready;
	mk_clib_app_fe_server_requests_store_t m_requests_store;
	mk_clib_app_fe_server_responses_store_t m_responses_store;
};
typedef struct mk_clib_app_fe_server_s mk_clib_app_fe_server_t;
typedef mk_clib_app_fe_server_t const mk_clib_app_fe_server_ct;
typedef mk_clib_app_fe_server_t* mk_clib_app_fe_server_pt;
typedef mk_clib_app_fe_server_t const* mk_clib_app_fe_server_pct;

struct mk_clib_app_fe_window_s
{
	mk_win_user_base_wnd_t m_wnd;
	mk_clib_app_fe_server_pt m_server;
	mk_win_base_rect_t m_rect;
	mk_win_user_dc_t m_mem_dc;
	mk_win_user_bitmap_t m_bitmap;
	mk_win_user_bitmap_t m_old_bitmap;
	mk_lang_types_bool_t m_init;
	mk_lang_types_uint_t m_req_id;
	mk_clib_app_fe_server_response_pt m_response_current;
	mk_lang_types_sint_t m_line_height;
	mk_lang_types_sint_t m_idx;
	mk_lang_types_sint_t m_scrollbar_status;
	mk_lang_types_sint_t m_scroll;
	mk_clib_app_fe_server_ints_t m_history_idx;
	mk_clib_app_fe_server_ints_t m_history_scroll;
	mk_clib_app_fe_server_responsesmt_t m_responses_waiting;
};
typedef struct mk_clib_app_fe_window_s mk_clib_app_fe_window_t;
typedef mk_clib_app_fe_window_t const mk_clib_app_fe_window_ct;
typedef mk_clib_app_fe_window_t* mk_clib_app_fe_window_pt;
typedef mk_clib_app_fe_window_t const* mk_clib_app_fe_window_pct;

struct mk_clib_app_fe_s
{
	mk_lang_types_bool_t m_wide;
	mk_win_base_instance_t m_instance;
	mk_win_base_wchar_lpct m_cmd_line;
	mk_lang_types_sint_t m_show;
	mk_lang_types_sint_t m_exit_code;
	mk_clib_app_fe_server_t m_server;
	mk_lib_mt_thread_t m_threads[4];
	mk_win_user_base_atom_t m_class;
	mk_clib_app_fe_window_t m_window;
};
typedef struct mk_clib_app_fe_s mk_clib_app_fe_t;
typedef mk_clib_app_fe_t const mk_clib_app_fe_ct;
typedef mk_clib_app_fe_t* mk_clib_app_fe_pt;
typedef mk_clib_app_fe_t const* mk_clib_app_fe_pct;

#define mk_clib_app_fe_class_name_a  "mkfe"
#define mk_clib_app_fe_class_name_w L"mkfe"
#define mk_clib_app_fe_timeout 100
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_clib_app_fe_window_hourglass[] = L"... working ...";
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_clib_app_fe_window_drive_type_unknown  [] = L"unknown"  ;
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_clib_app_fe_window_drive_type_removable[] = L"removable";
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_clib_app_fe_window_drive_type_fixed    [] = L"fixed"    ;
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_clib_app_fe_window_drive_type_remote   [] = L"remote"   ;
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_clib_app_fe_window_drive_type_cdrom    [] = L"cdrom"    ;
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_clib_app_fe_window_drive_type_ramdisk  [] = L"RAM disk" ;
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_clib_app_fe_up_str[] = L"[ .. ]" ;
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_clib_app_fe_fmt_err[] = L"Error %d 0x%x";


mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t find_reverse(mk_lang_types_wchar_pct const buf, mk_lang_types_usize_t const len, mk_lang_types_wchar_t const obj) mk_lang_noexcept
{
	/* todo constexpr and generic */
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_lang_types_usize_t ret;

	ret = len;
	n = len;
	for(i = 0; i != n; ++i)
	{
		idx = (n - 1) - i;
		if(buf[idx] == obj)
		{
			ret = idx;
			break;
		}
	}
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_clib_app_fe_server_file_lt(mk_clib_app_fe_server_file_pct const a, mk_clib_app_fe_server_file_pct const b)
{
	mk_lang_types_bool_t ret;
	mk_lang_types_wchar_pct texta;
	mk_lang_types_wchar_pct textb;
	mk_lang_types_usize_t lena;
	mk_lang_types_usize_t lenb;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_sint_t cmpa;
	mk_lang_types_sint_t cmpb;

	mk_lang_assert(a);
	mk_lang_assert(b);

	if(a->m_is_dir && !b->m_is_dir)
	{
		ret = mk_lang_true;
	}
	else if(b->m_is_dir && !a->m_is_dir)
	{
		ret = mk_lang_false;
	}
	else
	{
		cmpb = 0;
		texta = mk_clib_app_fe_server_name_ro_data(&a->m_name); mk_lang_assert(texta && texta[0] != L'\0');
		textb = mk_clib_app_fe_server_name_ro_data(&b->m_name); mk_lang_assert(textb && textb[0] != L'\0');
		lena = mk_clib_app_fe_server_name_ro_size(&a->m_name); mk_lang_assert(lena >= 1);
		lenb = mk_clib_app_fe_server_name_ro_size(&b->m_name); mk_lang_assert(lenb >= 1);
		n = mk_lang_min(lena, lenb);
		for(i = 0; i != n; ++i)
		{
			if
			(
				((texta[i] >= L'a' && texta[i] <= L'z') || (texta[i] >= L'A' && texta[i] <= L'Z')) &&
				((textb[i] >= L'a' && textb[i] <= L'z') || (textb[i] >= L'A' && textb[i] <= L'Z'))
			)
			{
				cmpa =
					((mk_lang_types_sint_t)(((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(texta[i])) | ((mk_lang_types_ushort_t)(1u << 5)))))) -
					((mk_lang_types_sint_t)(((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(textb[i])) | ((mk_lang_types_ushort_t)(1u << 5))))));
				if(cmpb == 0)
				{
					cmpb =
						((mk_lang_types_sint_t)(((mk_lang_types_ushort_t)(texta[i])))) -
						((mk_lang_types_sint_t)(((mk_lang_types_ushort_t)(textb[i]))));
				}
			}
			else
			{
				cmpa =
					((mk_lang_types_sint_t)(((mk_lang_types_ushort_t)(texta[i])))) -
					((mk_lang_types_sint_t)(((mk_lang_types_ushort_t)(textb[i]))));
			}
			if(cmpa != 0)
			{
				ret = cmpa < 0;
				break;
			}
		}
		if(i == n)
		{
			if(cmpb != 0)
			{
				ret = cmpb < 0;
			}
			else
			{
				ret = lena <= lenb;
			}
		}
	}
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_response_destroy_root(mk_clib_app_fe_server_response_root_pt const response) mk_lang_noexcept
{
	mk_lang_assert(response);

	((mk_lang_types_void_t)(response));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_response_destroy_idx(mk_clib_app_fe_server_response_idx_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;

	mk_lang_assert(response);

	err = mk_clib_app_fe_server_name_rw_destroy(&response->m_path); mk_lang_check_rereturn(err);
	n = mk_clib_app_fe_server_files_ro_size(&response->m_files);
	for(i = 0; i != n; ++i)
	{
		err = mk_clib_app_fe_server_name_rw_destroy(&mk_clib_app_fe_server_files_rw_at(&response->m_files, i)->m_name); mk_lang_check_rereturn(err);
	}
	err = mk_clib_app_fe_server_files_rw_destroy(&response->m_files); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_ints_rw_destroy(&response->m_sort); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_response_destroy(mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(response);

	err = mk_clib_app_fe_server_atomic_sint_destroy(&response->m_ref_count); mk_lang_check_rereturn(err);
	switch(response->m_type)
	{
		case mk_clib_app_fe_server_response_type_e_notadir  : break;
		case mk_clib_app_fe_server_response_type_e_invalid  : break;
		case mk_clib_app_fe_server_response_type_e_root     : err = mk_clib_app_fe_server_response_destroy_root(&response->m_data.m_root); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_idx      : err = mk_clib_app_fe_server_response_destroy_idx (&response->m_data.m_idx ); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default                                             : mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_response_get_count_notadir(mk_clib_app_fe_server_response_nothing_pct const response, mk_lang_types_sint_pt const count) mk_lang_noexcept
{
	mk_lang_assert(response);
	mk_lang_assert(response);
	mk_lang_assert(count);

	*count = 0;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_response_get_count_invalid(mk_clib_app_fe_server_response_invalid_pct const response, mk_lang_types_sint_pt const count) mk_lang_noexcept
{
	mk_lang_assert(response);
	mk_lang_assert(response);
	mk_lang_assert(count);

	*count = 0;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_response_get_count_root(mk_clib_app_fe_server_response_root_pct const response, mk_lang_types_sint_pt const count) mk_lang_noexcept
{
	mk_lang_types_sint_t cnt;

	mk_lang_assert(response);
	mk_lang_assert(response);
	mk_lang_assert(count);

	cnt = mk_clib_app_fe_server_uint_count_ones(&response->m_drive_letters); mk_lang_assert(cnt >= 1);
	*count = cnt;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_response_get_count_idx(mk_clib_app_fe_server_response_idx_pct const response, mk_lang_types_sint_pt const count) mk_lang_noexcept
{
	mk_lang_types_usize_t cntus;
	mk_lang_types_sint_t cntsi;

	mk_lang_assert(response);
	mk_lang_assert(count);

	cntus = mk_clib_app_fe_server_files_ro_size(&response->m_files); mk_lang_assert(cntus <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max))); cntsi = ((mk_lang_types_sint_t)(cntus));
	*count = cntsi;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_response_get_count(mk_clib_app_fe_server_response_pct const response, mk_lang_types_sint_pt const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(response);
	mk_lang_assert(count);

	switch(response->m_type)
	{
		case mk_clib_app_fe_server_response_type_e_notadir  : err = mk_clib_app_fe_server_response_get_count_notadir(&response->m_data.m_nothing, count); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_invalid  : err = mk_clib_app_fe_server_response_get_count_invalid(&response->m_data.m_invalid, count); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_root     : err = mk_clib_app_fe_server_response_get_count_root   (&response->m_data.m_root   , count); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_idx      : err = mk_clib_app_fe_server_response_get_count_idx    (&response->m_data.m_idx    , count); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default                                             : mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_response_has_up_notadir(mk_clib_app_fe_server_response_nothing_pct const response, mk_lang_types_bool_pt const has_up) mk_lang_noexcept
{
	mk_lang_assert(response);
	mk_lang_assert(has_up);

	((mk_lang_types_void_t)(response));
	mk_lang_assert(mk_lang_false); /* todo? */
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_response_has_up_invalid(mk_clib_app_fe_server_response_invalid_pct const response, mk_lang_types_bool_pt const has_up) mk_lang_noexcept
{
	mk_lang_assert(response);
	mk_lang_assert(has_up);

	((mk_lang_types_void_t)(response));
	mk_lang_assert(mk_lang_false); /* todo? */
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_response_has_up_root(mk_clib_app_fe_server_response_root_pct const response, mk_lang_types_bool_pt const has_up) mk_lang_noexcept
{
	mk_lang_assert(response);
	mk_lang_assert(has_up);

	((mk_lang_types_void_t)(response));
	*has_up = mk_lang_false;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_response_has_up_idx(mk_clib_app_fe_server_response_idx_pct const response, mk_lang_types_bool_pt const has_up) mk_lang_noexcept
{
	mk_lang_assert(response);
	mk_lang_assert(has_up);

	((mk_lang_types_void_t)(response));
	*has_up = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_response_has_up(mk_clib_app_fe_server_response_pct const response, mk_lang_types_bool_pt const has_up) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(response);
	mk_lang_assert(has_up);

	switch(response->m_type)
	{
		case mk_clib_app_fe_server_response_type_e_notadir  : err = mk_clib_app_fe_server_response_has_up_notadir(&response->m_data.m_nothing, has_up); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_invalid  : err = mk_clib_app_fe_server_response_has_up_invalid(&response->m_data.m_invalid, has_up); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_root     : err = mk_clib_app_fe_server_response_has_up_root   (&response->m_data.m_root   , has_up); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_idx      : err = mk_clib_app_fe_server_response_has_up_idx    (&response->m_data.m_idx    , has_up); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default                                             : mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_response_ref_count_dec(mk_clib_app_fe_server_pt const server, mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t val;

	mk_lang_assert(server);
	mk_lang_assert(response);

	err = mk_clib_app_fe_server_atomic_sint_dec(&response->m_ref_count, mk_lib_mt_memory_order_e_acq_rel, &val); mk_lang_check_rereturn(err); mk_lang_assert(val >= 1);
	if(val == 1)
	{
		err = mk_clib_app_fe_server_response_destroy(response); mk_lang_check_rereturn(err);
		err = mk_clib_app_fe_server_responsesmt_rw_push_back_one(&server->m_responses_ready, &response); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_response_curr_ref_count_dec(mk_clib_app_fe_server_pt const server) mk_lang_noexcept
{
	mk_clib_app_fe_server_response_pt response;
	mk_lang_types_sint_t err;

	mk_lang_assert(server);

	response = server->m_response_current;
	if(response)
	{
		err = mk_clib_app_fe_server_response_ref_count_dec(server, response); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_response_assign(mk_clib_app_fe_server_pt const server, mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(server);
	mk_lang_assert(response);

	if(response->m_type != mk_clib_app_fe_server_response_type_e_notadir)
	{
		err = mk_clib_app_fe_server_response_curr_ref_count_dec(server); mk_lang_check_rereturn(err);
		server->m_response_current = response;
	}
	else
	{
		if(server->m_response_current)
		{
			server->m_response_current->m_req_id = response->m_req_id;
		}
		err = mk_clib_app_fe_server_response_ref_count_dec(server, response); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_response_notify(mk_clib_app_fe_server_pt const server, mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_t ul;
	mk_clib_app_fe_server_callback_on_response_t on_response_fun;
	mk_lang_types_void_pt on_response_ctx;

	mk_lang_assert(server);
	mk_lang_assert(response);

	err = mk_clib_app_fe_server_response_assign(server, response); mk_lang_check_rereturn(err);
	err = mk_lib_mt_unique_lock_exclusive_construct(&ul, &server->m_mtx); mk_lang_check_rereturn(err);
	on_response_fun = server->m_on_response_fun;
	on_response_ctx = server->m_on_response_ctx;
	if(on_response_fun)
	{
		err = on_response_fun(on_response_ctx, server->m_response_current); mk_lang_check_rereturn(err);
	}
	err = mk_lib_mt_unique_lock_exclusive_destruct(&ul); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_request_process_root_impl_init(mk_clib_app_fe_server_request_pt const request, mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t val;
	mk_lang_types_sint_t err;

	mk_lang_assert(request);
	mk_lang_assert(request->m_type == mk_clib_app_fe_server_request_type_e_root);
	mk_lang_assert(response);

	val = 1;
	err = mk_clib_app_fe_server_atomic_sint_construct(&response->m_ref_count); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_atomic_sint_store(&response->m_ref_count, &val, mk_lib_mt_memory_order_e_relaxed); mk_lang_check_rereturn(err);
	response->m_type = mk_clib_app_fe_server_response_type_e_root;
	response->m_req_id = request->m_req_id;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_request_process_impl_init(mk_clib_app_fe_server_pt const server, mk_clib_app_fe_server_request_pt const request, mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_clib_app_fe_server_response_pt response_prev;
	mk_lang_types_sint_t j;
	mk_lang_types_uint_t drives;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t val;
	mk_lang_types_sint_t idx;
	mk_lang_types_sint_t err;
	mk_win_base_wchar_pt buf;
	mk_lang_types_usize_t countus;
	mk_lang_types_sint_t countsi;
	mk_lang_types_usize_t prev_path_len;
	mk_lang_types_usize_t next_path_len;
	mk_lang_types_wchar_pct prev_path_buf;
	mk_lang_types_wchar_pct next_path_buf;
	mk_clib_app_fe_server_file_pct file;
	mk_lang_types_wchar_t wc;
	mk_lang_types_bool_t has_up;
	mk_lang_types_usize_t pos;

	mk_lang_assert(server);
	mk_lang_assert(request);
	mk_lang_assert(response);

	response_prev = server->m_response_current;
	if(!response_prev && request->m_type == mk_clib_app_fe_server_request_type_e_root)
	{
		val = 1;
		err = mk_clib_app_fe_server_atomic_sint_construct(&response->m_ref_count); mk_lang_check_rereturn(err);
		err = mk_clib_app_fe_server_atomic_sint_store(&response->m_ref_count, &val, mk_lib_mt_memory_order_e_relaxed); mk_lang_check_rereturn(err);
		response->m_type = mk_clib_app_fe_server_response_type_e_root;
		response->m_req_id = request->m_req_id;
	}
	else if(response_prev->m_type == mk_clib_app_fe_server_response_type_e_root && request->m_type == mk_clib_app_fe_server_request_type_e_idx)
	{
		j = 0;
		drives = response_prev->m_data.m_root.m_drive_letters;
		n = ((mk_lang_types_sint_t)('z' - 'a')) + 1;
		for(i = 0; i != n; ++i)
		{
			if((drives & 0x1) != 0)
			{
				if(j == request->m_data.m_idx.m_idx)
				{
					break;
				}
				++j;
			}
			drives >>= 1;
		}
		if(i != n)
		{
			val = 1;
			err = mk_clib_app_fe_server_atomic_sint_construct(&response->m_ref_count); mk_lang_check_rereturn(err);
			err = mk_clib_app_fe_server_atomic_sint_store(&response->m_ref_count, &val, mk_lib_mt_memory_order_e_relaxed); mk_lang_check_rereturn(err);
			response->m_type = mk_clib_app_fe_server_response_type_e_idx;
			response->m_req_id = request->m_req_id;
			err = mk_clib_app_fe_server_name_rw_construct(&response->m_data.m_idx.m_path); mk_lang_check_rereturn(err);
			err = mk_clib_app_fe_server_files_rw_construct(&response->m_data.m_idx.m_files); mk_lang_check_rereturn(err);
			err = mk_clib_app_fe_server_ints_rw_construct(&response->m_data.m_idx.m_sort); mk_lang_check_rereturn(err);
			response->m_data.m_idx.m_went_up = mk_lang_false;
			err = mk_clib_app_fe_server_name_rw_push_back_void(&response->m_data.m_idx.m_path, 2); mk_lang_check_rereturn(err);
			buf = mk_clib_app_fe_server_name_rw_data(&response->m_data.m_idx.m_path); mk_lang_assert(buf);
			buf[0] = ((mk_win_base_wchar_t)(L'A' + i));
			buf[1] = L':';
		}
		else
		{
			val = 1;
			err = mk_clib_app_fe_server_atomic_sint_construct(&response->m_ref_count); mk_lang_check_rereturn(err);
			err = mk_clib_app_fe_server_atomic_sint_store(&response->m_ref_count, &val, mk_lib_mt_memory_order_e_relaxed); mk_lang_check_rereturn(err);
			response->m_type = mk_clib_app_fe_server_response_type_e_invalid;
			response->m_req_id = request->m_req_id;
			response->m_data.m_invalid.m_dummy = 0;
		}
	}
	else if(response_prev->m_type == mk_clib_app_fe_server_response_type_e_idx)
	{
		countus = mk_clib_app_fe_server_files_ro_size(&response_prev->m_data.m_idx.m_files); mk_lang_assert(countus >= 0 && countus <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max))); countsi = ((mk_lang_types_sint_t)(countus));
		err = mk_clib_app_fe_server_response_has_up_idx(&response_prev->m_data.m_idx, &has_up); mk_lang_check_rereturn(err);
		idx = request->m_data.m_idx.m_idx;
		if(has_up && idx == 0)
		{
			prev_path_buf = mk_clib_app_fe_server_name_ro_data(&response_prev->m_data.m_idx.m_path); mk_lang_assert(prev_path_buf && prev_path_buf[0] != L'\0');
			prev_path_len = mk_clib_app_fe_server_name_ro_size(&response_prev->m_data.m_idx.m_path);
			pos = find_reverse(prev_path_buf, prev_path_len, L'\\'); mk_lang_assert(pos != 0);
			if(pos != prev_path_len)
			{
				val = 1;
				err = mk_clib_app_fe_server_atomic_sint_construct(&response->m_ref_count); mk_lang_check_rereturn(err);
				err = mk_clib_app_fe_server_atomic_sint_store(&response->m_ref_count, &val, mk_lib_mt_memory_order_e_relaxed); mk_lang_check_rereturn(err);
				response->m_type = mk_clib_app_fe_server_response_type_e_idx;
				response->m_req_id = request->m_req_id;
				err = mk_clib_app_fe_server_name_rw_construct(&response->m_data.m_idx.m_path); mk_lang_check_rereturn(err);
				err = mk_clib_app_fe_server_files_rw_construct(&response->m_data.m_idx.m_files); mk_lang_check_rereturn(err);
				err = mk_clib_app_fe_server_ints_rw_construct(&response->m_data.m_idx.m_sort); mk_lang_check_rereturn(err);
				response->m_data.m_idx.m_went_up = mk_lang_true;
				err = mk_clib_app_fe_server_name_rw_push_back_many(&response->m_data.m_idx.m_path, prev_path_buf, pos); mk_lang_check_rereturn(err);
			}
			else
			{
				val = 1;
				err = mk_clib_app_fe_server_atomic_sint_construct(&response->m_ref_count); mk_lang_check_rereturn(err);
				err = mk_clib_app_fe_server_atomic_sint_store(&response->m_ref_count, &val, mk_lib_mt_memory_order_e_relaxed); mk_lang_check_rereturn(err);
				response->m_type = mk_clib_app_fe_server_response_type_e_root;
				response->m_req_id = request->m_req_id;
			}
		}
		else
		{
			if(idx >= 0 + (has_up ? 1 : 0) && idx < countsi + (has_up ? 1 : 0))
			{
				idx = idx - (has_up ? 1 : 0);
				idx = *mk_clib_app_fe_server_ints_ro_at(&response_prev->m_data.m_idx.m_sort, idx);
				file = mk_clib_app_fe_server_files_ro_at(&response_prev->m_data.m_idx.m_files, idx); mk_lang_assert(file);
				if(file->m_is_dir)
				{
					val = 1;
					err = mk_clib_app_fe_server_atomic_sint_construct(&response->m_ref_count); mk_lang_check_rereturn(err);
					err = mk_clib_app_fe_server_atomic_sint_store(&response->m_ref_count, &val, mk_lib_mt_memory_order_e_relaxed); mk_lang_check_rereturn(err);
					response->m_type = mk_clib_app_fe_server_response_type_e_idx;
					response->m_req_id = request->m_req_id;
					err = mk_clib_app_fe_server_name_rw_construct(&response->m_data.m_idx.m_path); mk_lang_check_rereturn(err);
					err = mk_clib_app_fe_server_files_rw_construct(&response->m_data.m_idx.m_files); mk_lang_check_rereturn(err);
					err = mk_clib_app_fe_server_ints_rw_construct(&response->m_data.m_idx.m_sort); mk_lang_check_rereturn(err);
					response->m_data.m_idx.m_went_up = mk_lang_false;
					prev_path_len = mk_clib_app_fe_server_name_ro_size(&response_prev->m_data.m_idx.m_path);
					prev_path_buf = mk_clib_app_fe_server_name_ro_data(&response_prev->m_data.m_idx.m_path); mk_lang_assert(prev_path_buf && prev_path_buf[0] != L'\0');
					next_path_len = mk_clib_app_fe_server_name_ro_size(&file->m_name);
					next_path_buf = mk_clib_app_fe_server_name_ro_data(&file->m_name); mk_lang_assert(next_path_buf && next_path_buf[0] != L'\0');
					err = mk_clib_app_fe_server_name_rw_reserve_at_least(&response->m_data.m_idx.m_path, prev_path_len + 1 + next_path_len); mk_lang_check_rereturn(err);
					err = mk_clib_app_fe_server_name_rw_push_back_many(&response->m_data.m_idx.m_path, prev_path_buf, prev_path_len); mk_lang_check_rereturn(err);
					wc = L'\\'; err = mk_clib_app_fe_server_name_rw_push_back_one(&response->m_data.m_idx.m_path, &wc); mk_lang_check_rereturn(err);
					err = mk_clib_app_fe_server_name_rw_push_back_many(&response->m_data.m_idx.m_path, next_path_buf, next_path_len); mk_lang_check_rereturn(err);
				}
				else
				{
					val = 1;
					err = mk_clib_app_fe_server_atomic_sint_construct(&response->m_ref_count); mk_lang_check_rereturn(err);
					err = mk_clib_app_fe_server_atomic_sint_store(&response->m_ref_count, &val, mk_lib_mt_memory_order_e_relaxed); mk_lang_check_rereturn(err);
					response->m_type = mk_clib_app_fe_server_response_type_e_notadir;
					response->m_req_id = request->m_req_id;
					response->m_data.m_invalid.m_dummy = 0;
				}
			}
			else
			{
				val = 1;
				err = mk_clib_app_fe_server_atomic_sint_construct(&response->m_ref_count); mk_lang_check_rereturn(err);
				err = mk_clib_app_fe_server_atomic_sint_store(&response->m_ref_count, &val, mk_lib_mt_memory_order_e_relaxed); mk_lang_check_rereturn(err);
				response->m_type = mk_clib_app_fe_server_response_type_e_invalid;
				response->m_req_id = request->m_req_id;
				response->m_data.m_invalid.m_dummy = 0;
			}
		}
	}
	else
	{
		mk_lang_assert(mk_lang_false);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_request_process_impl_gather_notadir(mk_clib_app_fe_server_pt const server, mk_clib_app_fe_server_request_pt const request, mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_lang_assert(server);
	mk_lang_assert(request);
	mk_lang_assert(response);
	mk_lang_assert(response->m_type == mk_clib_app_fe_server_response_type_e_notadir);

	((mk_lang_types_void_t)(server));
	((mk_lang_types_void_t)(request));
	((mk_lang_types_void_t)(response));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_request_process_impl_gather_invalid(mk_clib_app_fe_server_pt const server, mk_clib_app_fe_server_request_pt const request, mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_lang_assert(server);
	mk_lang_assert(request);
	mk_lang_assert(response);
	mk_lang_assert(response->m_type == mk_clib_app_fe_server_response_type_e_invalid);

	((mk_lang_types_void_t)(server));
	((mk_lang_types_void_t)(request));
	((mk_lang_types_void_t)(response));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_request_process_impl_gather_root(mk_clib_app_fe_server_pt const server, mk_clib_app_fe_server_request_pt const request, mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_clib_app_fe_server_response_root_pt response_root;
	mk_win_base_dword_t drives;
	mk_win_base_wchar_t buf[4];
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_win_base_uint_t dt;

	mk_lang_static_assert(sizeof(mk_lang_types_uint_t) == sizeof(mk_win_base_dword_t));

	mk_lang_assert(server);
	mk_lang_assert(request);
	mk_lang_assert(response);
	mk_lang_assert(response->m_type == mk_clib_app_fe_server_response_type_e_root);

	((mk_lang_types_void_t)(server));
	response_root = &response->m_data.m_root;
	drives = mk_win_kernel_files_get_logical_drives();
	response_root->m_drive_letters = ((mk_lang_types_uint_t)(drives));
	buf[1] = L':';
	buf[2] = L'\\';
	buf[3] = L'\0';
	n = ((mk_lang_types_sint_t)(L'Z' - L'A')) + 1;
	for(i = 0; i != n; ++i)
	{
		if((drives & 0x1) != 0)
		{
			buf[0] = ((mk_lang_types_wchar_t)(L'A' + i));
			dt = mk_win_kernel_files_w_get_drive_type(&buf[0]);
			if(dt <= 0 || dt >= mk_win_kernel_files_drive_type_e_dummy_end)
			{
				dt = mk_win_kernel_files_drive_type_e_unknown;
			}
			response_root->m_drive_types[i] = ((mk_lang_types_uchar_t)(dt));
		}
		drives >>= 1;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_request_process_impl_gather_idx(mk_clib_app_fe_server_pt const server, mk_clib_app_fe_server_request_pt const request, mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_win_base_wchar_t search[3];
	mk_lang_types_sint_t err;
	mk_win_base_wchar_pct buf;
	mk_win_base_handle_t fh;
	mk_win_kernel_files_w_find_data_t fd;
	mk_clib_app_fe_server_file_pt file;
	mk_lang_types_usize_t lenus;
	mk_win_base_bool_t b;
	mk_win_base_dword_t gle;

	mk_lang_assert(server);
	mk_lang_assert(request);
	mk_lang_assert(response);
	mk_lang_assert(response->m_type == mk_clib_app_fe_server_response_type_e_idx);

	((mk_lang_types_void_t)(server));
	search[0] = L'\\';
	search[1] = L'*';
	search[2] = L'\0';
	err = mk_clib_app_fe_server_name_rw_push_back_many(&response->m_data.m_idx.m_path, &search[0], mk_lang_countof(search)); mk_lang_check_rereturn(err);
	buf = mk_clib_app_fe_server_name_ro_data(&response->m_data.m_idx.m_path); mk_lang_assert(buf && buf[0] != L'\0');
	fh = mk_win_kernel_files_w_find_first_file(buf, &fd); gle = mk_win_kernel_errors_get_last();
	err = mk_clib_app_fe_server_name_rw_shrink(&response->m_data.m_idx.m_path, 3); mk_lang_check_rereturn(err);
	if(!mk_win_base_handle_is_invalid(fh))
	{
		response->m_data.m_idx.m_gle = 0;
		for(;;)
		{
			if
			(!(
				(fd.m_name[0] == L'.' && fd.m_name[1] == L'\0') ||
				(fd.m_name[0] == L'.' && fd.m_name[1] == L'.' && fd.m_name[2] == L'\0')
			))
			{
				err = mk_clib_app_fe_server_files_rw_push_back_void(&response->m_data.m_idx.m_files, 1); mk_lang_check_rereturn(err);
				file = mk_clib_app_fe_server_files_rw_back(&response->m_data.m_idx.m_files); mk_lang_assert(file);
				file->m_is_dir = (fd.m_attributes & mk_win_kernel_files_attribute_e_directory) != 0;
				err = mk_clib_app_fe_server_name_rw_construct(&file->m_name); mk_lang_check_rereturn(err);
				lenus = mk_lang_strlen_w_fn(fd.m_name); mk_lang_assert(lenus <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
				err = mk_clib_app_fe_server_name_rw_push_back_many(&file->m_name, &fd.m_name[0], lenus); mk_lang_check_rereturn(err);
			}
			b = mk_win_kernel_files_w_find_next_file(fh, &fd);
			if(b == 0)
			{
				break;
			}
		}
		b = mk_win_kernel_files_find_close(fh); mk_lang_check_return(b != 0);
	}
	else
	{
		response->m_data.m_idx.m_gle = gle;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_request_process_impl_gather(mk_clib_app_fe_server_pt const server, mk_clib_app_fe_server_request_pt const request, mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(request);
	mk_lang_assert(response);

	switch(response->m_type)
	{
		case mk_clib_app_fe_server_response_type_e_notadir  : err = mk_clib_app_fe_server_request_process_impl_gather_notadir(server, request, response); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_invalid  : err = mk_clib_app_fe_server_request_process_impl_gather_invalid(server, request, response); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_root     : err = mk_clib_app_fe_server_request_process_impl_gather_root   (server, request, response); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_idx      : err = mk_clib_app_fe_server_request_process_impl_gather_idx    (server, request, response); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_request_process_impl_merge_notadir(mk_clib_app_fe_server_response_pt const a, mk_clib_app_fe_server_response_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a->m_type == b->m_type);
	mk_lang_assert(a->m_type == mk_clib_app_fe_server_response_type_e_notadir);

	((mk_lang_types_void_t)(a));
	((mk_lang_types_void_t)(b));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_request_process_impl_merge_invalid(mk_clib_app_fe_server_response_pt const a, mk_clib_app_fe_server_response_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a->m_type == b->m_type);
	mk_lang_assert(a->m_type == mk_clib_app_fe_server_response_type_e_invalid);

	((mk_lang_types_void_t)(a));
	((mk_lang_types_void_t)(b));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_request_process_impl_merge_root(mk_clib_app_fe_server_response_pt const a, mk_clib_app_fe_server_response_pct const b) mk_lang_noexcept
{
	mk_lang_types_uint_t da;
	mk_lang_types_uint_t db;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a->m_type == b->m_type);
	mk_lang_assert(a->m_type == mk_clib_app_fe_server_response_type_e_root);

	da = a->m_data.m_root.m_drive_letters;
	db = b->m_data.m_root.m_drive_letters;
	n = ((mk_lang_types_sint_t)(L'z' - L'a')) + 1;
	for(i = 0; i != n; ++i)
	{
		if((da & 0x1) == 0 && (db & 0x1) != 0)
		{
			a->m_data.m_root.m_drive_types[i] = b->m_data.m_root.m_drive_types[i];
		}
		da >>= 1;
		db >>= 1;
	}
	a->m_data.m_root.m_drive_letters |= b->m_data.m_root.m_drive_letters;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_request_process_impl_merge_idx(mk_clib_app_fe_server_response_pt const a, mk_clib_app_fe_server_response_pct const b) mk_lang_noexcept
{
	mk_clib_app_fe_server_response_idx_pt aa;
	mk_clib_app_fe_server_response_idx_pct bb;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t m;
	mk_lang_types_usize_t j;
	mk_clib_app_fe_server_file_pct fb;
	mk_clib_app_fe_server_file_pct fa;
	mk_lang_types_usize_t lenb;
	mk_lang_types_usize_t lena;
	mk_lang_types_wchar_pct bufb;
	mk_lang_types_wchar_pct bufa;
	mk_lang_types_sint_t r;
	mk_clib_app_fe_server_file_t f;
	mk_lang_types_sint_t err;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a->m_type == b->m_type);
	mk_lang_assert(a->m_type == mk_clib_app_fe_server_response_type_e_idx);

	/* todo this is o^2 */
	if(a->m_type == mk_clib_app_fe_server_response_type_e_idx && b->m_type == mk_clib_app_fe_server_response_type_e_idx)
	{
		aa = &a->m_data.m_idx;
		bb = &b->m_data.m_idx;
		n = mk_clib_app_fe_server_files_ro_size(&bb->m_files);
		for(i = 0; i != n; ++i)
		{
			fb = mk_clib_app_fe_server_files_ro_at(&bb->m_files, i); mk_lang_assert(fb);
			lenb = mk_clib_app_fe_server_name_ro_size(&fb->m_name);
			bufb = mk_clib_app_fe_server_name_ro_data(&fb->m_name);
			m = mk_clib_app_fe_server_files_ro_size(&aa->m_files);
			for(j = 0; j != m; ++j)
			{
				fa = mk_clib_app_fe_server_files_ro_at(&aa->m_files, j); mk_lang_assert(fa);
				lena = mk_clib_app_fe_server_name_ro_size(&fa->m_name);
				bufa = mk_clib_app_fe_server_name_ro_data(&fa->m_name);
				if(lena == lenb)
				{
					r = mk_clib_app_fe_memcmp_uc_fn(((mk_lang_types_uchar_pct)(bufa)), ((mk_lang_types_uchar_pct)(bufb)), lena * sizeof(mk_lang_types_wchar_t));
					if(r == 0)
					{
						break;
					}
				}
			}
			if(j == m)
			{
				f.m_is_dir = fb->m_is_dir;
				err = mk_clib_app_fe_server_name_rw_construct(&f.m_name); mk_lang_check_rereturn(err);
				err = mk_clib_app_fe_server_name_rw_push_back_many(&f.m_name, bufb, lenb); mk_lang_check_rereturn(err);
				err = mk_clib_app_fe_server_files_rw_push_back_one(&aa->m_files, &f); mk_lang_check_rereturn(err);
			}
		}
		if(aa->m_gle == 0 || bb->m_gle == 0)
		{
			aa->m_gle = 0;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_request_process_impl_merge(mk_clib_app_fe_server_response_pt const a, mk_clib_app_fe_server_response_pct const b) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a->m_type == b->m_type);

	switch(a->m_type)
	{
		case mk_clib_app_fe_server_response_type_e_notadir  : err = mk_clib_app_fe_server_request_process_impl_merge_notadir(a, b); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_invalid  : err = mk_clib_app_fe_server_request_process_impl_merge_invalid(a, b); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_root     : err = mk_clib_app_fe_server_request_process_impl_merge_root   (a, b); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_idx      : err = mk_clib_app_fe_server_request_process_impl_merge_idx    (a, b); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_request_process_impl_sort_notadir(mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_lang_assert(response);
	mk_lang_assert(response->m_type == mk_clib_app_fe_server_response_type_e_notadir);

	((mk_lang_types_void_t)(response));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_request_process_impl_sort_invalid(mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_lang_assert(response);
	mk_lang_assert(response->m_type == mk_clib_app_fe_server_response_type_e_invalid);

	((mk_lang_types_void_t)(response));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_request_process_impl_sort_root(mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_lang_assert(response);
	mk_lang_assert(response->m_type == mk_clib_app_fe_server_response_type_e_root);

	((mk_lang_types_void_t)(response));
	return 0;
}

#define mk_lang_bui_t_name mk_clib_app_fe_server_cntr
#define mk_lang_bui_t_base uint
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_sort_merge_t_name mk_clib_app_fe_server_sort
#define mk_sl_sort_merge_t_data mk_clib_app_fe_server_file
#define mk_sl_sort_merge_t_counter mk_clib_app_fe_server_cntr
#define mk_sl_sort_merge_t_is_sorted mk_clib_app_fe_server_file_lt
#define mk_sl_sort_merge_t_first_round 1
#define mk_sl_sort_merge_t_proxy mk_lang_types_sint
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_request_process_impl_sort_idx(mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_clib_app_fe_server_files_pt files_obj;
	mk_lang_types_usize_t count;
	mk_clib_app_fe_server_file_pt files_buf;
	mk_clib_app_fe_server_ints_pt sort_obj;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_pt sort_buf;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;

	mk_lang_assert(response);
	mk_lang_assert(response->m_type == mk_clib_app_fe_server_response_type_e_idx);

	files_obj = &response->m_data.m_idx.m_files;
	sort_obj = &response->m_data.m_idx.m_sort;
	err = mk_clib_app_fe_server_ints_rw_clear(sort_obj); mk_lang_check_rereturn(err);
	count = mk_clib_app_fe_server_files_ro_size(files_obj); mk_lang_assert(count >= 0 && count <= mk_lang_limits_usize_max / 2 && count <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)) / 2);
	if(count != 0)
	{
		files_buf = mk_clib_app_fe_server_files_rw_data(files_obj); mk_lang_assert(files_buf);
		err = mk_clib_app_fe_server_ints_rw_push_back_void(sort_obj, count * 2); mk_lang_check_rereturn(err);
		sort_buf = mk_clib_app_fe_server_ints_rw_data(sort_obj); mk_lang_assert(sort_buf);
		n = count;
		for(i = 0; i != n; ++i)
		{
			sort_buf[i] = ((mk_lang_types_sint_t)(i));
		}
		mk_clib_app_fe_server_sort_proxy(&files_buf[0], &sort_buf[0], ((mk_clib_app_fe_server_cntr_t)(count)), &sort_buf[count]);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_request_process_impl_sort(mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(response);

	switch(response->m_type)
	{
		case mk_clib_app_fe_server_response_type_e_notadir  : err = mk_clib_app_fe_server_request_process_impl_sort_notadir(response); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_invalid  : err = mk_clib_app_fe_server_request_process_impl_sort_invalid(response); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_root     : err = mk_clib_app_fe_server_request_process_impl_sort_root   (response); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_idx      : err = mk_clib_app_fe_server_request_process_impl_sort_idx    (response); mk_lang_check_rereturn(err); break;
		case mk_clib_app_fe_server_response_type_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_request_process(mk_clib_app_fe_server_pt const server, mk_clib_app_fe_server_request_pt const request, mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_win_impersonate_linked_t impersonate_linked;
	mk_lang_types_sint_t err_b;
	mk_clib_app_fe_server_response_t r;
	mk_lang_types_sint_t err_c;
	mk_lang_types_sint_t err_d;

	mk_lang_assert(server);
	mk_lang_assert(request);
	mk_lang_assert(response);

	err = mk_clib_app_fe_server_request_process_impl_init(server, request, response); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_request_process_impl_gather(server, request, response); mk_lang_check_rereturn(err);
	err = mk_lib_win_impersonate_linked_begin(&impersonate_linked); mk_lang_check_rereturn(err);
	if(impersonate_linked.m_did)
	{
		err = mk_clib_app_fe_server_request_process_impl_init(server, request, &r); mk_lang_check_rereturn(err);
		err_b = mk_clib_app_fe_server_request_process_impl_gather(server, request, &r);
		err_c = mk_clib_app_fe_server_request_process_impl_merge(response, &r);
		err_d = mk_clib_app_fe_server_response_destroy(&r); mk_lang_check_rereturn(err);
	}
	else
	{
		err_b = 0;
		err_c = 0;
		err_d = 0;
	}
	err = mk_lib_win_impersonate_linked_end(&impersonate_linked); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	mk_lang_check_rereturn(err_c);
	mk_lang_check_rereturn(err_d);
	err = mk_clib_app_fe_server_request_process_impl_sort(response); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_request_ref_count_dec(mk_clib_app_fe_server_pt const server, mk_clib_app_fe_server_request_pt const request) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t val;

	mk_lang_assert(server);
	mk_lang_assert(request);

	err = mk_clib_app_fe_server_atomic_sint_dec(&request->m_ref_count, mk_lib_mt_memory_order_e_acq_rel, &val); mk_lang_check_rereturn(err); mk_lang_assert(val >= 1);
	if(val == 1)
	{
		err = mk_clib_app_fe_server_atomic_sint_destroy(&request->m_ref_count); mk_lang_check_rereturn(err);
		err = mk_clib_app_fe_server_requestsmt_rw_push_back_one(&server->m_requests_ready, &request); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_main(mk_clib_app_fe_server_pt const server) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_clib_app_fe_server_request_pt request;
	mk_clib_app_fe_server_response_pt response;

	mk_lang_assert(server);

	for(;;)
	{
		err = mk_clib_app_fe_server_requestsmt_rw_pop_front_copy(&server->m_requests_waiting, &request); mk_lang_check_rereturn(err);
		if(!request)
		{
			break;
		}
		err = mk_clib_app_fe_server_responsesmt_rw_pop_front_copy(&server->m_responses_ready, &response); mk_lang_check_rereturn(err); mk_lang_assert(response);
		err = mk_clib_app_fe_server_request_process(server, request, response); mk_lang_check_rereturn(err);
		err = mk_clib_app_fe_server_request_ref_count_dec(server, request); mk_lang_check_rereturn(err);
		err = mk_clib_app_fe_server_response_notify(server, response); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_types_sint_t mk_clib_app_fe_server_thread(mk_lang_types_void_pt const ctx) mk_lang_noexcept
{
	mk_clib_app_fe_server_pt server;
	mk_lang_types_sint_t err;

	mk_lang_assert(ctx);

	server = ((mk_clib_app_fe_server_pt)(ctx)); mk_lang_assert(server);
	err = mk_clib_app_fe_server_main(server); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_destroy(mk_clib_app_fe_server_pt const server) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t full;
	mk_lang_types_bool_t empty;

	mk_lang_assert(server);

	err = mk_clib_app_fe_server_response_curr_ref_count_dec(server); mk_lang_check_rereturn(err);
	mk_lang_assert((err = mk_clib_app_fe_server_responsesmt_ro_is_full(&server->m_responses_ready, &full), err == 0 && full));
	mk_lang_assert((err = mk_clib_app_fe_server_requestsmt_ro_is_full(&server->m_requests_ready, &full), err == 0 && full));
	mk_lang_assert((err = mk_clib_app_fe_server_requestsmt_ro_is_empty(&server->m_requests_waiting, &empty), err == 0 && empty));
	err = mk_clib_app_fe_server_responsesmt_rw_destroy(&server->m_responses_ready); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_requestsmt_rw_destroy(&server->m_requests_ready); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_requestsmt_rw_destroy(&server->m_requests_waiting); mk_lang_check_rereturn(err);
	err = mk_lib_mt_mutex_destruct(&server->m_mtx); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_server_construct(mk_clib_app_fe_server_pt const server) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_clib_app_fe_server_request_pt request;
	mk_clib_app_fe_server_response_pt response;

	mk_lang_assert(server);

	err = mk_lib_mt_mutex_construct(&server->m_mtx); mk_lang_check_rereturn(err);
	server->m_on_response_fun = mk_lang_null;
	server->m_on_response_ctx = mk_lang_null;
	server->m_response_current = mk_lang_null;
	err = mk_clib_app_fe_server_requestsmt_rw_construct(&server->m_requests_waiting); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_requestsmt_rw_construct(&server->m_requests_ready); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_responsesmt_rw_construct(&server->m_responses_ready); mk_lang_check_rereturn(err);
	mk_lang_static_assert(((mk_lang_types_uint_t)(mk_clib_app_fe_server_requestsmt_len_v)) == ((mk_lang_types_uint_t)(mk_clib_app_fe_server_requests_store_len_v)));
	n = mk_clib_app_fe_server_requests_store_len_v;
	for(i = 0; i != n; ++i)
	{
		request = mk_clib_app_fe_server_requests_store_rw_at(&server->m_requests_store, i); mk_lang_assert(request);
		err = mk_clib_app_fe_server_requestsmt_rw_push_back_one(&server->m_requests_ready, &request); mk_lang_check_rereturn(err);
	}
	mk_lang_static_assert(((mk_lang_types_uint_t)(mk_clib_app_fe_server_responsesmt_len_v)) == ((mk_lang_types_uint_t)(mk_clib_app_fe_server_responses_store_len_v)));
	n = mk_clib_app_fe_server_responses_store_len_v;
	for(i = 0; i != n; ++i)
	{
		response = mk_clib_app_fe_server_responses_store_rw_at(&server->m_responses_store, i); mk_lang_assert(response);
		err = mk_clib_app_fe_server_responsesmt_rw_push_back_one(&server->m_responses_ready, &response); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_response_ref_count_dec(mk_clib_app_fe_window_pt const window, mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t val;

	mk_lang_assert(window);

	if(response)
	{
		err = mk_clib_app_fe_server_atomic_sint_dec(&response->m_ref_count, mk_lib_mt_memory_order_e_acq_rel, &val); mk_lang_check_rereturn(err); mk_lang_assert(val >= 1);
		if(val == 1)
		{
			err = mk_clib_app_fe_server_response_destroy(response); mk_lang_check_rereturn(err);
			err = mk_clib_app_fe_server_responsesmt_rw_push_back_one(&window->m_server->m_responses_ready, &response); mk_lang_check_rereturn(err);
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_scroll_to_selected(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_win_base_sint_t client_height;
	mk_win_base_sint_t client_whole_rows;
	mk_lang_types_sint_t scroll_curr;
	mk_lang_types_sint_t scroll_lo;
	mk_lang_types_sint_t scroll_hi;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t idx;
	mk_lang_types_sint_t count;
	mk_lang_types_sint_t diff;
	mk_lang_types_bool_t has_up;
	mk_lang_types_sint_t scroll_max;
	mk_lang_types_sint_t scroll_min;

	mk_lang_assert(window);

	if(window->m_response_current)
	{
		client_height = ((mk_win_base_sint_t)(window->m_rect.m_bottom - window->m_rect.m_top));
		client_whole_rows = client_height / window->m_line_height;
		idx = window->m_idx;
		err = mk_clib_app_fe_server_response_get_count(window->m_response_current, &count); mk_lang_check_rereturn(err);
		err = mk_clib_app_fe_server_response_has_up(window->m_response_current, &has_up); mk_lang_check_rereturn(err);
		count += (has_up ? 1 : 0);
		scroll_curr = window->m_scroll;
		scroll_lo = idx - client_whole_rows + 1;
		scroll_hi = idx;
		if(scroll_curr < scroll_lo)
		{
			diff = scroll_lo - scroll_curr;
			if(diff > client_whole_rows)
			{
				scroll_curr = idx - client_whole_rows / 2;
			}
			else
			{
				scroll_curr = scroll_lo;
			}
		}
		else if(scroll_curr > scroll_hi)
		{
			diff = scroll_curr - scroll_hi;
			if(diff > client_whole_rows)
			{
				scroll_curr = idx - client_whole_rows / 2;
			}
			else
			{
				scroll_curr = scroll_hi;
			}
		}
		scroll_min = 0;
		scroll_max = mk_lang_max(0, count - client_whole_rows);
		scroll_curr = mk_lang_clamp(scroll_curr, scroll_min, scroll_max);
		window->m_scroll = scroll_curr;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_create(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const msg, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam) mk_lang_noexcept
{
	mk_win_user_msg_createw_lpct create;
	mk_clib_app_fe_window_pt window;
	mk_win_base_uintptr_t data;

	((mk_lang_types_void_t)(wparam));
	if(msg == mk_win_user_msg_id_e_create)
	{
		create = ((mk_win_user_msg_createw_lpct)(lparam)); mk_lang_assert(create);
		window = ((mk_clib_app_fe_window_pt)(create->m_param));
		window->m_wnd = wnd;
		data = mk_win_user_window_w_data_set(wnd, ((mk_win_base_sint_t)(mk_win_user_window_data_id_e_userdata)), ((mk_win_base_uintptr_t)(window))); mk_lang_assert(data == 0);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_destroy(mk_clib_app_fe_window_pt const window, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
{
	mk_win_base_uintptr_t data;
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_t ul;

	mk_lang_assert(window);
	mk_lang_assert(override_defproc);
	mk_lang_assert(override_result);

	((mk_lang_types_void_t)(wparam));
	((mk_lang_types_void_t)(lparam));
	data = mk_win_user_window_w_data_set(window->m_wnd, ((mk_win_base_sint_t)(mk_win_user_window_data_id_e_userdata)), ((mk_win_base_uintptr_t)(0))); mk_lang_assert(data == ((mk_win_base_uintptr_t)(window)));
	err = mk_lib_mt_unique_lock_exclusive_construct(&ul, &window->m_server->m_mtx); mk_lang_check_rereturn(err);
	window->m_server->m_on_response_fun = mk_lang_null;
	window->m_server->m_on_response_ctx = mk_lang_null;
	err = mk_lib_mt_unique_lock_exclusive_destruct(&ul); mk_lang_check_rereturn(err);
	mk_win_user_msg_post_quit(0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_draw_response_root_drive_type_to_str(mk_lang_types_uchar_t const drive_type, mk_lang_types_wchar_ppct const buf, mk_lang_types_sint_pt const len) mk_lang_noexcept
{
	mk_lang_types_wchar_pct str_buf;
	mk_lang_types_sint_t str_len;

	mk_lang_assert(buf);
	mk_lang_assert(len);

	switch(drive_type)
	{
		case mk_win_kernel_files_drive_type_e_unknown    : str_buf = &mk_clib_app_fe_window_drive_type_unknown  [0]; str_len = mk_lang_countstr(mk_clib_app_fe_window_drive_type_unknown  ); break;
		case mk_win_kernel_files_drive_type_e_no_root_dir: str_buf = &mk_clib_app_fe_window_drive_type_unknown  [0]; str_len = mk_lang_countstr(mk_clib_app_fe_window_drive_type_unknown  ); break;
		case mk_win_kernel_files_drive_type_e_removable  : str_buf = &mk_clib_app_fe_window_drive_type_removable[0]; str_len = mk_lang_countstr(mk_clib_app_fe_window_drive_type_removable); break;
		case mk_win_kernel_files_drive_type_e_fixed      : str_buf = &mk_clib_app_fe_window_drive_type_fixed    [0]; str_len = mk_lang_countstr(mk_clib_app_fe_window_drive_type_fixed    ); break;
		case mk_win_kernel_files_drive_type_e_remote     : str_buf = &mk_clib_app_fe_window_drive_type_remote   [0]; str_len = mk_lang_countstr(mk_clib_app_fe_window_drive_type_remote   ); break;
		case mk_win_kernel_files_drive_type_e_cdrom      : str_buf = &mk_clib_app_fe_window_drive_type_cdrom    [0]; str_len = mk_lang_countstr(mk_clib_app_fe_window_drive_type_cdrom    ); break;
		case mk_win_kernel_files_drive_type_e_ramdisk    : str_buf = &mk_clib_app_fe_window_drive_type_ramdisk  [0]; str_len = mk_lang_countstr(mk_clib_app_fe_window_drive_type_ramdisk  ); break;
		case mk_win_kernel_files_drive_type_e_dummy_end  : str_buf = &mk_clib_app_fe_window_drive_type_unknown  [0]; str_len = mk_lang_countstr(mk_clib_app_fe_window_drive_type_unknown  ); break;
		default                                          : str_buf = &mk_clib_app_fe_window_drive_type_unknown  [0]; str_len = mk_lang_countstr(mk_clib_app_fe_window_drive_type_unknown  ); break;
	}
	*buf = str_buf;
	*len = str_len;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_draw_response_root_line_height(mk_clib_app_fe_window_pt const window, mk_lang_types_sint_t const i, mk_lang_types_sint_pt const line_height) mk_lang_noexcept
{
	mk_clib_app_fe_server_response_root_pct response;
	mk_win_user_dc_t dc;
	mk_win_base_rect_t recta;
	mk_win_base_uint_t flags;
	mk_win_base_wchar_t buf[2];
	mk_win_base_rect_t rectb;
	mk_win_base_sint_t heighta;
	mk_lang_types_sint_t err;
	mk_lang_types_wchar_pct type_str_buf;
	mk_lang_types_sint_t type_str_len;
	mk_win_base_sint_t heightb;

	mk_lang_assert(window);
	mk_lang_assert(i >= 0 && i < ((mk_lang_types_sint_t)('z' - 'a')) + 1);
	mk_lang_assert(line_height);

	response = &window->m_response_current->m_data.m_root;
	dc = window->m_mem_dc;
	recta = window->m_rect;
	flags = ((mk_win_base_uint_t)(mk_win_user_dc_flag_e_left | mk_win_user_dc_flag_e_singleline | mk_win_user_dc_flag_e_noclip | mk_win_user_dc_flag_e_calcrect | mk_win_user_dc_flag_e_noprefix | mk_win_user_dc_flag_e_internal));
	buf[0] = ((mk_lang_types_wchar_t)(L'A' + i));
	buf[1] = L':';
	rectb = recta;
	heighta = mk_win_user_dc_draw_text_w(dc, &buf[0], 2, &recta, flags); mk_lang_check_return(heighta != 0); mk_lang_assert(heighta == ((mk_lang_types_sint_t)(recta.m_bottom - recta.m_top)));
	recta = rectb;
	err = mk_clib_app_fe_window_on_paint_impl_draw_response_root_drive_type_to_str(response->m_drive_types[i], &type_str_buf, &type_str_len); mk_lang_check_rereturn(err); mk_lang_assert(type_str_buf && type_str_buf[0] != L'\0' && type_str_len >= 1);
	heightb = mk_win_user_dc_draw_text_w(dc, &type_str_buf[0], type_str_len, &recta, flags); mk_lang_check_return(heightb != 0); mk_lang_assert(heightb == ((mk_lang_types_sint_t)(recta.m_bottom - recta.m_top)));
	*line_height = mk_lang_max(heighta, heightb);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_draw_response_root_widest_drive(mk_clib_app_fe_window_pt const window, mk_lang_types_sint_pt const widest) mk_lang_noexcept
{
	mk_clib_app_fe_server_response_root_pct response;
	mk_win_user_base_wnd_t wnd;
	mk_win_user_dc_t dc;
	mk_win_base_rect_t recta;
	mk_win_base_sint_t height;
	mk_win_base_sint_t max_height;
	mk_win_base_sint_t width;
	mk_win_base_rect_t rectb;
	mk_win_base_uint_t flags;
	mk_win_base_wchar_t buf[2];
	mk_lang_types_uint_t drives;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(window);
	mk_lang_assert(widest);

	response = &window->m_response_current->m_data.m_root;
	wnd = window->m_wnd;
	dc = window->m_mem_dc;
	recta = window->m_rect;
	height = 0;
	max_height = 0;
	width = 0;
	rectb = recta;
	flags = ((mk_win_base_uint_t)(mk_win_user_dc_flag_e_left | mk_win_user_dc_flag_e_singleline | mk_win_user_dc_flag_e_noclip | mk_win_user_dc_flag_e_calcrect | mk_win_user_dc_flag_e_noprefix | mk_win_user_dc_flag_e_internal));
	buf[1] = L':';
	drives = response->m_drive_letters;
	n = ((mk_lang_types_sint_t)(L'z' - L'a')) + 1;
	for(i = 0; i != n; ++i)
	{
		if((drives & 0x1) != 0)
		{
			recta = rectb;
			buf[0] = ((mk_lang_types_wchar_t)(L'A' + i));
			height = mk_win_user_dc_draw_text_w(dc, &buf[0], 2, &recta, flags); mk_lang_check_return(height != 0);
			width = mk_lang_max(width, ((mk_win_base_sint_t)(recta.m_right - recta.m_left)));
			max_height = mk_lang_max(max_height, ((mk_win_base_sint_t)(recta.m_bottom - recta.m_top)));
		}
		drives >>= 1;
	}
	if(max_height > window->m_line_height)
	{
		window->m_line_height = max_height;
	}
	*widest = width;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_draw_response_root(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_win_base_wchar_t buf[2];
	mk_win_base_uint_t flags;
	mk_win_base_rect_t recta;
	mk_win_user_dc_t dc;
	mk_clib_app_fe_server_response_root_pct response;
	mk_lang_types_uint_t drives;
	mk_lang_types_sint_t j;
	mk_lang_types_sint_t line_height;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t widest_drive;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_win_base_wchar_pct type_str;
	mk_lang_types_sint_t type_len;
	mk_win_user_base_colorref_t old_fg;
	mk_win_user_base_colorref_t old_bg;
	mk_win_base_rect_t rectb;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t height;
	mk_win_base_bool_t b;
	mk_win_base_sint_t client_height;
	mk_win_base_sint_t client_whole_rows;
	mk_win_base_sint_t vacant;

	mk_lang_assert(window->m_response_current);
	mk_lang_assert(!mk_win_user_base_wnd_is_null(window->m_wnd));
	mk_lang_assert(!mk_win_user_dc_is_null(window->m_mem_dc));

	buf[1] = L':';
	flags = ((mk_win_base_uint_t)(mk_win_user_dc_flag_e_left | mk_win_user_dc_flag_e_singleline | mk_win_user_dc_flag_e_noclip | mk_win_user_dc_flag_e_noprefix | mk_win_user_dc_flag_e_internal));
	recta = window->m_rect;
	dc = window->m_mem_dc;
	response = &window->m_response_current->m_data.m_root;
	drives = response->m_drive_letters;
	client_height = ((mk_win_base_sint_t)(recta.m_bottom - recta.m_top));
	client_whole_rows = client_height / window->m_line_height;
	vacant = client_whole_rows - (mk_clib_app_fe_server_uint_count_ones(&drives) - window->m_scroll);
	if(window->m_scroll >= 1 && vacant >= 1)
	{
		window->m_scroll -= vacant;
		window->m_scroll = mk_lang_max(0, window->m_scroll);
	}
	drives >>= window->m_scroll;
	j = 0;
	line_height = 0;
	err = mk_clib_app_fe_window_on_paint_impl_draw_response_root_widest_drive(window, &widest_drive); mk_lang_check_rereturn(err);
	n = ((mk_lang_types_sint_t)('z' - 'a')) + 1;
	for(i = window->m_scroll; i != n; ++i)
	{
		if((drives & 0x1) != 0)
		{
			recta.m_top += line_height;
			if(recta.m_top >= recta.m_bottom)
			{
				break;
			}
			err = mk_clib_app_fe_window_on_paint_impl_draw_response_root_line_height(window, i, &line_height); mk_lang_check_rereturn(err);
			if(line_height > window->m_line_height)
			{
				window->m_line_height = line_height;
				b = mk_win_user_window_w_msg_post(window->m_wnd, mk_win_user_msg_id_e_user + 1, 0, 0); mk_lang_check_return(b != 0);
				break;
			}
			err = mk_clib_app_fe_window_on_paint_impl_draw_response_root_drive_type_to_str(response->m_drive_types[i], &type_str, &type_len); mk_lang_check_rereturn(err);
			buf[0] = ((mk_lang_types_wchar_t)(L'A' + i));
			if(j == window->m_idx - window->m_scroll)
			{
				old_fg = mk_win_user_dc_set_text_color(dc, mk_win_user_base_get_sys_color(((mk_win_base_sint_t)(mk_win_user_base_color_id_e_highlighttext)))); mk_lang_check_return(old_fg != ((mk_win_user_base_colorref_t)(0xfffffffful)));
				old_bg = mk_win_user_dc_set_bk_color(dc, mk_win_user_base_get_sys_color(((mk_win_base_sint_t)(mk_win_user_base_color_id_e_highlight)))); mk_lang_check_return(old_bg != ((mk_win_user_base_colorref_t)(0xfffffffful)));
				rectb = recta; rectb.m_bottom = recta.m_top + line_height;
				tsi = mk_win_user_dc_fill_rect(dc, &rectb, mk_win_user_brush_from_color_id(mk_win_user_base_color_id_e_highlight)); mk_lang_check_return(tsi != 0);
			}
			rectb = recta;
			height = mk_win_user_dc_draw_text_w(dc, &buf[0], 2, &rectb, flags); mk_lang_check_return(height != 0); mk_lang_assert(height <= line_height);
			rectb = recta; rectb.m_left = recta.m_left + 2 * widest_drive;
			height = mk_win_user_dc_draw_text_w(dc, type_str, type_len, &rectb, flags); mk_lang_check_return(height != 0); mk_lang_assert(height <= line_height);
			if(j == window->m_idx - window->m_scroll)
			{
				old_fg = mk_win_user_dc_set_text_color(dc, old_fg); mk_lang_check_return(old_fg != ((mk_win_user_base_colorref_t)(0xfffffffful)));
				old_bg = mk_win_user_dc_set_bk_color(dc, old_fg); mk_lang_check_return(old_bg != ((mk_win_user_base_colorref_t)(0xfffffffful)));
			}
			++j;
		}
		drives >>= 1;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_draw_response_idx_line_height(mk_clib_app_fe_window_pt const window, mk_clib_app_fe_server_name_pct const name, mk_lang_types_sint_pt const line_height) mk_lang_noexcept
{
	mk_win_user_dc_t dc;
	mk_win_base_rect_t rect;
	mk_win_base_uint_t flags;
	mk_win_base_wchar_pct buf;
	mk_win_base_usize_t lenus;
	mk_win_base_sint_t lensi;
	mk_win_base_sint_t height;

	mk_lang_assert(window);
	mk_lang_assert(name);
	mk_lang_assert(line_height);

	dc = window->m_mem_dc;
	rect = window->m_rect;
	flags = ((mk_win_base_uint_t)(mk_win_user_dc_flag_e_left | mk_win_user_dc_flag_e_singleline | mk_win_user_dc_flag_e_noclip | mk_win_user_dc_flag_e_calcrect | mk_win_user_dc_flag_e_noprefix | mk_win_user_dc_flag_e_internal));
	buf = mk_clib_app_fe_server_name_ro_data(name); mk_lang_assert(buf && buf[0] != L'\0');
	lenus = mk_clib_app_fe_server_name_ro_size(name); mk_lang_assert(lenus >= 1 && lenus <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max))); lensi = ((mk_lang_types_sint_t)(lenus));
	height = mk_win_user_dc_draw_text_w(dc, &buf[0], lensi, &rect, flags); mk_lang_check_return(height != 0); mk_lang_assert(height == ((mk_lang_types_sint_t)(rect.m_bottom - rect.m_top)));
	*line_height = height;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_draw_response_idx_impl_dirify(mk_clib_app_fe_server_file_pct const file, mk_clib_app_fe_server_name_pt const name) mk_lang_noexcept
{
	mk_lang_types_usize_t len;
	mk_lang_types_usize_t extra;
	mk_win_base_sint_t err;
	mk_lang_types_wchar_t buf[2];

	mk_lang_assert(file);
	mk_lang_assert(name);

	len = mk_clib_app_fe_server_name_ro_size(&file->m_name);
	if(file->m_is_dir)
	{
		extra = 2 + 2;
	}
	else
	{
		extra = 0;
	}
	err = mk_clib_app_fe_server_name_rw_clear(name); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_name_rw_reserve_at_least(name, len + extra); mk_lang_check_rereturn(err);
	if(file->m_is_dir)
	{
		buf[0] = L'[';
		buf[1] = L' ';
		err = mk_clib_app_fe_server_name_rw_push_back_many(name, &buf[0], mk_lang_countof(buf)); mk_lang_check_rereturn(err);
	}
	err = mk_clib_app_fe_server_name_rw_push_back_many(name, mk_clib_app_fe_server_name_ro_data(&file->m_name), len); mk_lang_check_rereturn(err);
	if(file->m_is_dir)
	{
		buf[0] = L' ';
		buf[1] = L']';
		err = mk_clib_app_fe_server_name_rw_push_back_many(name, &buf[0], mk_lang_countof(buf)); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_draw_response_idx_impl_up(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_lang_assert(window);
	mk_lang_assert(window->m_response_current);
	mk_lang_assert(!mk_win_user_base_wnd_is_null(window->m_wnd));
	mk_lang_assert(!mk_win_user_dc_is_null(window->m_mem_dc));

	return 0;
}

struct mk_clib_app_fe_window_paint_s
{
	mk_clib_app_fe_window_pt m_window;
	mk_win_base_uint_t m_flags;
	mk_win_base_rect_t m_rect;
	mk_win_user_dc_t m_dc;
	mk_clib_app_fe_server_response_pct m_response;
	mk_win_base_sint_t m_client_height;
	mk_win_base_sint_t m_client_whole_rows;
	mk_win_user_base_colorref_t m_old_fg;
	mk_win_user_base_colorref_t m_old_bg;
};
typedef struct mk_clib_app_fe_window_paint_s mk_clib_app_fe_window_paint_t;
typedef mk_clib_app_fe_window_paint_t const mk_clib_app_fe_window_paint_ct;
typedef mk_clib_app_fe_window_paint_t* mk_clib_app_fe_window_paint_pt;
typedef mk_clib_app_fe_window_paint_t const* mk_clib_app_fe_window_paint_pct;

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_init(mk_clib_app_fe_window_paint_pt const pt, mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_lang_assert(pt);
	mk_lang_assert(window);

	pt->m_window = window;
	pt->m_flags = ((mk_win_base_uint_t)(mk_win_user_dc_flag_e_left | mk_win_user_dc_flag_e_singleline | mk_win_user_dc_flag_e_noclip | mk_win_user_dc_flag_e_noprefix | mk_win_user_dc_flag_e_internal));
	pt->m_rect = window->m_rect;
	pt->m_dc = window->m_mem_dc;
	pt->m_response = window->m_response_current;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_get_height_width(mk_clib_app_fe_window_paint_pt const pt, mk_lang_types_wchar_pct const buf, mk_lang_types_sint_t const len, mk_lang_types_sint_pt const out_width, mk_lang_types_sint_pt const out_height) mk_lang_noexcept
{
	mk_clib_app_fe_window_pt window;
	mk_win_user_dc_t dc;
	mk_win_base_rect_t rect;
	mk_win_base_uint_t flags;
	mk_win_base_sint_t height;
	mk_win_base_sint_t width;

	mk_lang_assert(pt);
	mk_lang_assert(buf);
	mk_lang_assert(buf[0] != L'\0');
	mk_lang_assert(len >= 1);
	mk_lang_assert(out_width);
	mk_lang_assert(out_height);

	window = pt->m_window;
	dc = window->m_mem_dc;
	rect = window->m_rect;
	flags = pt->m_flags;
	flags |= mk_win_user_dc_flag_e_calcrect;
	height = mk_win_user_dc_draw_text_w(dc, &buf[0], len, &rect, flags); mk_lang_check_return(height != 0); mk_lang_assert(height == ((mk_lang_types_sint_t)(rect.m_bottom - rect.m_top)));
	width = ((mk_lang_types_sint_t)(rect.m_right - rect.m_left));
	*out_width = width;
	*out_height = height;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_fixup_idx_and_scroll(mk_clib_app_fe_window_paint_pt const pt) mk_lang_noexcept
{
	mk_clib_app_fe_window_pt window;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t count;
	mk_lang_types_bool_t has_up;
	mk_lang_types_sint_t idx;
	mk_lang_types_sint_t scroll;
	mk_lang_types_sint_t vacant;
	mk_win_base_sint_t client_height;
	mk_win_base_sint_t client_whole_rows;

	mk_lang_assert(pt);

	window = pt->m_window;
	client_height = ((mk_win_base_sint_t)(window->m_rect.m_bottom - window->m_rect.m_top));
	client_whole_rows = client_height / window->m_line_height;
	err = mk_clib_app_fe_server_response_get_count(window->m_response_current, &count); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_response_has_up(window->m_response_current, &has_up); mk_lang_check_rereturn(err);
	count += (has_up ? 1 : 0);
	idx = mk_lang_min(window->m_idx, count - 1);
	if(idx != window->m_idx)
	{
		window->m_idx = idx;
		err = mk_clib_app_fe_window_scroll_to_selected(window); mk_lang_check_rereturn(err);
	}
	scroll = window->m_scroll;
	vacant = client_whole_rows - (count - scroll);
	if(vacant >= 1 && scroll >= 0)
	{
		scroll -= vacant;
		window->m_scroll = scroll;
		err = mk_clib_app_fe_window_scroll_to_selected(window); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_rows_notadir(mk_clib_app_fe_window_paint_pt const pt) mk_lang_noexcept
{
	mk_clib_app_fe_window_pt window;
	mk_clib_app_fe_server_response_pt resp;
	mk_clib_app_fe_server_response_nothing_pt response;

	mk_lang_assert(pt);

	window = pt->m_window;
	resp = window->m_response_current;
	response = &resp->m_data.m_nothing;
	mk_lang_assert(mk_lang_false); /* todo? */
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_rows_invalid(mk_clib_app_fe_window_paint_pt const pt) mk_lang_noexcept
{
	mk_clib_app_fe_window_pt window;
	mk_clib_app_fe_server_response_pt resp;
	mk_clib_app_fe_server_response_invalid_pt response;

	mk_lang_assert(pt);

	window = pt->m_window;
	resp = window->m_response_current;
	response = &resp->m_data.m_invalid;
	mk_lang_assert(mk_lang_false); /* todo? */
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_rows_root_sizes(mk_clib_app_fe_window_paint_pt const pt, mk_lang_types_sint_pt const out_width) mk_lang_noexcept
{
	mk_clib_app_fe_window_pt window;
	mk_clib_app_fe_server_response_pt resp;
	mk_clib_app_fe_server_response_root_pt response;
	mk_lang_types_wchar_t drive_text[2];
	mk_lang_types_uint_t drives;
	mk_lang_types_sint_t width_max;
	mk_lang_types_sint_t height_max;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;
	mk_lang_types_wchar_pct drive_type_buf;
	mk_lang_types_sint_t drive_type_len;
	mk_lang_types_sint_t width;
	mk_lang_types_sint_t height;

	mk_lang_assert(pt);

	window = pt->m_window;
	resp = window->m_response_current;
	response = &resp->m_data.m_root;
	drive_text[1] = L':';
	drives = response->m_drive_letters;
	width_max = 0;
	height_max = 0;
	n = ((mk_lang_types_sint_t)('z' - 'a')) + 1;
	for(i = 0; i != n; ++i)
	{
		if((drives & 0x1u) != 0)
		{
			drive_text[0] = ((mk_lang_types_wchar_t)(L'A' + i));
			err = mk_clib_app_fe_window_on_paint_impl_draw_response_root_drive_type_to_str(response->m_drive_types[i], &drive_type_buf, &drive_type_len); mk_lang_check_rereturn(err);
			err = mk_clib_app_fe_window_on_paint_impl_get_height_width(pt, &drive_text[0], mk_lang_countof(drive_text), &width, &height); mk_lang_check_rereturn(err); width_max = mk_lang_max(width_max, width); height_max = mk_lang_max(height_max, height);
			err = mk_clib_app_fe_window_on_paint_impl_get_height_width(pt, &drive_type_buf[0], drive_type_len, &width, &height); mk_lang_check_rereturn(err); height_max = mk_lang_max(height_max, height);
		}
		drives >>= 1;
	}
	if(height_max > window->m_line_height)
	{
		window->m_line_height = height_max;
	}
	*out_width = width_max;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_row_selected_on(mk_clib_app_fe_window_paint_pt const pt, mk_lang_types_sint_t const j) mk_lang_noexcept
{
	mk_clib_app_fe_window_pt window;
	mk_win_user_dc_t dc;
	mk_win_user_base_colorref_t old_fg;
	mk_win_user_base_colorref_t old_bg;
	mk_win_base_rect_t rect;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(pt);

	window = pt->m_window;
	dc = window->m_mem_dc;
	if(j == window->m_idx)
	{
		old_fg = mk_win_user_dc_set_text_color(dc, mk_win_user_base_get_sys_color(((mk_win_base_sint_t)(mk_win_user_base_color_id_e_highlighttext)))); mk_lang_check_return(old_fg != ((mk_win_user_base_colorref_t)(0xfffffffful)));
		old_bg = mk_win_user_dc_set_bk_color(dc, mk_win_user_base_get_sys_color(((mk_win_base_sint_t)(mk_win_user_base_color_id_e_highlight)))); mk_lang_check_return(old_bg != ((mk_win_user_base_colorref_t)(0xfffffffful)));
		rect = pt->m_rect;
		rect.m_bottom = pt->m_rect.m_top + window->m_line_height;
		tsi = mk_win_user_dc_fill_rect(dc, &rect, mk_win_user_brush_from_color_id(mk_win_user_base_color_id_e_highlight)); mk_lang_check_return(tsi != 0);
		pt->m_old_fg = old_fg;
		pt->m_old_bg = old_bg;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_row_selected_of(mk_clib_app_fe_window_paint_pt const pt, mk_lang_types_sint_t const j) mk_lang_noexcept
{
	mk_clib_app_fe_window_pt window;
	mk_win_user_dc_t dc;
	mk_win_user_base_colorref_t old_fg;
	mk_win_user_base_colorref_t old_bg;

	mk_lang_assert(pt);

	window = pt->m_window;
	dc = window->m_mem_dc;
	if(j == window->m_idx)
	{
		old_fg = mk_win_user_dc_set_text_color(dc, pt->m_old_fg); mk_lang_check_return(old_fg != ((mk_win_user_base_colorref_t)(0xfffffffful)));
		old_bg = mk_win_user_dc_set_bk_color(dc, pt->m_old_bg); mk_lang_check_return(old_bg != ((mk_win_user_base_colorref_t)(0xfffffffful)));
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_rows_root(mk_clib_app_fe_window_paint_pt const pt) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t width;
	mk_clib_app_fe_window_pt window;
	mk_clib_app_fe_server_response_pt resp;
	mk_clib_app_fe_server_response_root_pt response;
	mk_lang_types_wchar_t drive_text[2];
	mk_lang_types_uint_t drives;
	mk_lang_types_sint_t width_max;
	mk_lang_types_sint_t height_max;
	mk_lang_types_sint_t j;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_wchar_pct drive_type_buf;
	mk_lang_types_sint_t drive_type_len;
	mk_lang_types_sint_t height;
	mk_win_user_dc_t dc;
	mk_win_base_uint_t flags;
	mk_win_base_rect_pt rect;
	mk_win_base_rect_t recta;
	mk_lang_types_sint_t line_height;

	mk_lang_assert(pt);

	err = mk_clib_app_fe_window_on_paint_impl_rows_root_sizes(pt, &width); mk_lang_check_rereturn(err);
	window = pt->m_window;
	flags = pt->m_flags;
	rect = &pt->m_rect;
	dc = window->m_mem_dc;
	resp = window->m_response_current;
	line_height = window->m_line_height;
	response = &resp->m_data.m_root;
	drive_text[1] = L':';
	drives = response->m_drive_letters;
	width_max = 0;
	height_max = 0;
	j = 0;
	n = ((mk_lang_types_sint_t)('z' - 'a')) + 1;
	for(i = 0; i != n; ++i)
	{
		if((drives & 0x1u) != 0)
		{
			drive_text[0] = ((mk_lang_types_wchar_t)(L'A' + i));
			err = mk_clib_app_fe_window_on_paint_impl_draw_response_root_drive_type_to_str(response->m_drive_types[i], &drive_type_buf, &drive_type_len); mk_lang_check_rereturn(err);
			err = mk_clib_app_fe_window_on_paint_impl_row_selected_on(pt, j); mk_lang_check_rereturn(err);
			recta = *rect;
			height = mk_win_user_dc_draw_text_w(dc, &drive_text[0], mk_lang_countof(drive_text), &recta, flags); mk_lang_check_return(height != 0); mk_lang_assert(height <= line_height);
			recta = *rect; recta.m_left += 2 * width;
			height = mk_win_user_dc_draw_text_w(dc, &drive_type_buf[0], drive_type_len, &recta, flags); mk_lang_check_return(height != 0); mk_lang_assert(height <= line_height);
			err = mk_clib_app_fe_window_on_paint_impl_row_selected_of(pt, j); mk_lang_check_rereturn(err);
			rect->m_top += line_height;
			if(rect->m_top >= rect->m_bottom)
			{
				break;
			}
			++j;
		}
		drives >>= 1;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_rows_idx_erry(mk_clib_app_fe_window_paint_pt const pt) mk_lang_noexcept
{
	mk_clib_app_fe_window_pt window;
	mk_win_base_uint_t flags;
	mk_win_base_rect_pt rect;
	mk_win_user_dc_t dc;
	mk_clib_app_fe_server_response_pct resp;
	mk_clib_app_fe_server_response_idx_pct response;
	mk_lang_types_sint_t line_height;
	mk_win_base_rect_t recta;
	mk_lang_types_sint_t height_max;
	mk_lang_types_sint_t lensi;
	mk_lang_types_sint_t err;
	mk_clib_app_fe_server_name_t err_msg;
	mk_lang_types_wchar_pt err_buf;
	mk_win_user_base_colorref_t old_fg;
	mk_win_user_base_colorref_t old_bg;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t len;
	mk_win_base_rect_t rectb;
	mk_lang_types_sint_t height;
	mk_win_base_dword_t lendw;
	mk_win_base_dword_t gle;
	mk_win_base_bool_t b;

	mk_lang_assert(pt);

	window = pt->m_window;
	flags = pt->m_flags;
	rect = &pt->m_rect;
	dc = pt->m_dc;
	resp = pt->m_response;
	response = &resp->m_data.m_idx;
	line_height = window->m_line_height;
	recta = *rect;
	height_max = 0;
	recta.m_top += 2 * line_height;
	lensi = 2 * 1024;
	err = mk_clib_app_fe_server_name_rw_construct(&err_msg); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_name_rw_push_back_void(&err_msg, lensi); mk_lang_check_rereturn(err);
	err_buf = mk_clib_app_fe_server_name_rw_data(&err_msg); mk_lang_assert(err_buf);
	flags &=~ ((mk_win_base_dword_t)(mk_win_user_dc_flag_e_left));
	flags |= ((mk_win_base_dword_t)(mk_win_user_dc_flag_e_center));
	old_fg = mk_win_user_dc_set_text_color(dc, mk_win_user_base_get_sys_color(((mk_win_base_sint_t)(mk_win_user_base_color_id_e_graytext)))); mk_lang_check_return(old_fg != ((mk_win_user_base_colorref_t)(0xfffffffful)));
	old_bg = mk_win_user_dc_set_bk_color(dc, mk_win_user_base_get_sys_color(((mk_win_base_sint_t)(mk_win_user_base_color_id_e_window)))); mk_lang_check_return(old_bg != ((mk_win_user_base_colorref_t)(0xfffffffful)));
	{
		tsi = mk_lib_fmt_w_snnprintf(err_buf, lensi, &mk_clib_app_fe_fmt_err[0], mk_lang_countstr(mk_clib_app_fe_fmt_err), &response->m_gle, &response->m_gle); mk_lang_assert(tsi >= 1 && tsi < lensi); len = tsi;
		rectb = recta; rectb.m_bottom = recta.m_top + line_height;
		tsi = mk_win_user_dc_fill_rect(dc, &rectb, mk_win_user_brush_from_color_id(mk_win_user_base_color_id_e_window)); mk_lang_check_return(tsi != 0);
		rectb = recta;
		height = mk_win_user_dc_draw_text_w(dc, &err_buf[0], len, &rectb, flags); mk_lang_check_return(height != 0); height_max = mk_lang_max(height_max, height);
		recta.m_top += line_height;
	}
	{
		lendw = mk_win_kernel_string_w_format(((mk_win_base_dword_t)(mk_win_kernel_string_format_flags_e_ignore_inserts | mk_win_kernel_string_format_flags_e_from_system)), mk_win_base_null, response->m_gle, 0, err_buf, lensi, mk_lang_null);
		if(lendw != 0)
		{
			while(lendw >= 2 && err_buf[lendw - 2] == L'\x0d' && err_buf[lendw - 1] == L'\x0a'){ lendw -= 2; }
			rectb = recta; rectb.m_bottom = recta.m_top + line_height;
			tsi = mk_win_user_dc_fill_rect(dc, &rectb, mk_win_user_brush_from_color_id(mk_win_user_base_color_id_e_window)); mk_lang_check_return(tsi != 0);
			rectb = recta;
			height = mk_win_user_dc_draw_text_w(dc, &err_buf[0], ((mk_lang_types_sint_t)(lendw)), &rectb, flags); mk_lang_check_return(height != 0);
		}
		else
		{
			gle = mk_win_kernel_errors_get_last();
			mk_lang_check_return(gle == mk_win_kernel_errors_id_e_mr_mid_not_found);
		}
	}
	old_fg = mk_win_user_dc_set_text_color(dc, old_fg); mk_lang_check_return(old_fg != ((mk_win_user_base_colorref_t)(0xfffffffful)));
	old_bg = mk_win_user_dc_set_bk_color(dc, old_bg); mk_lang_check_return(old_bg != ((mk_win_user_base_colorref_t)(0xfffffffful)));
	err = mk_clib_app_fe_server_name_rw_destroy(&err_msg); mk_lang_check_rereturn(err);
	if(height > line_height)
	{
		window->m_line_height = height;
		b = mk_win_user_window_invalidate_region(window->m_wnd, mk_win_user_region_get_null(), mk_win_base_true); mk_lang_check_return(b != 0);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_up(mk_clib_app_fe_window_paint_pt const pt) mk_lang_noexcept
{
	mk_clib_app_fe_window_pt window;
	mk_win_base_uint_t flags;
	mk_win_base_rect_pt rect;
	mk_win_user_dc_t dc;
	mk_clib_app_fe_server_response_pct response;
	mk_lang_types_sint_pt line_height;
	mk_lang_types_sint_t scroll;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t has_up;
	mk_lang_types_wchar_pct text_buf;
	mk_lang_types_sint_t text_len;
	mk_win_base_rect_t recta;
	mk_lang_types_sint_t height;

	mk_lang_assert(pt);

	window = pt->m_window;
	flags = pt->m_flags;
	rect = &pt->m_rect;
	dc = pt->m_dc;
	response = pt->m_response;
	line_height = &window->m_line_height;
	scroll = window->m_scroll;
	err = mk_clib_app_fe_server_response_has_up(response, &has_up); mk_lang_check_rereturn(err);
	if(has_up && scroll == 0)
	{
		text_buf = &mk_clib_app_fe_up_str[0]; mk_lang_assert(text_buf && text_buf[0] != L'\0');
		text_len = mk_lang_countstr(mk_clib_app_fe_up_str); mk_lang_assert(text_len >= 1);
		recta = *rect;
		err = mk_clib_app_fe_window_on_paint_impl_row_selected_on(pt, 0); mk_lang_check_rereturn(err);
		height = mk_win_user_dc_draw_text_w(dc, &text_buf[0], text_len, &recta, flags); mk_lang_check_return(height != 0); *line_height = mk_lang_max(height, *line_height);
		err = mk_clib_app_fe_window_on_paint_impl_row_selected_of(pt, 0); mk_lang_check_rereturn(err);
		rect->m_top += *line_height;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_rows_idx_errn(mk_clib_app_fe_window_paint_pt const pt) mk_lang_noexcept
{
	mk_clib_app_fe_window_pt window;
	mk_win_base_uint_t flags;
	mk_win_base_rect_pt rect;
	mk_win_user_dc_t dc;
	mk_clib_app_fe_server_response_pt resp;
	mk_clib_app_fe_server_response_idx_pt response;
	mk_clib_app_fe_server_files_pct files;
	mk_clib_app_fe_server_ints_pct sort;
	mk_lang_types_sint_t line_height;
	mk_lang_types_sint_t scroll;
	mk_lang_types_sint_t j;
	mk_lang_types_sint_t err;
	mk_clib_app_fe_server_name_t dirified;
	mk_lang_types_bool_t has_up;
	mk_lang_types_wchar_pct text_buf;
	mk_lang_types_sint_t text_len;
	mk_win_base_rect_t recta;
	mk_lang_types_sint_t height;
	mk_win_base_bool_t b;
	mk_lang_types_usize_t tus;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t idx;
	mk_clib_app_fe_server_file_pct file;
	mk_clib_app_fe_server_name_pct name;

	mk_lang_assert(pt);

	window = pt->m_window;
	flags = pt->m_flags;
	rect = &pt->m_rect;
	dc = window->m_mem_dc;
	resp = window->m_response_current;
	response = &resp->m_data.m_idx;
	files = &response->m_files;
	sort = &response->m_sort;
	line_height = window->m_line_height;
	scroll = window->m_scroll;
	j = 0;
	err = mk_clib_app_fe_server_name_rw_construct(&dirified); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_response_has_up_idx(response, &has_up); mk_lang_check_rereturn(err);
	tus = mk_clib_app_fe_server_files_ro_size(files); mk_lang_assert(tus <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
	n = ((mk_lang_types_sint_t)(tus));
	for(i = (has_up ? (mk_lang_max(0, scroll - 1)) : (scroll)); i != n; ++i)
	{
		j = i + (has_up ? 1 : 0);
		idx = *mk_clib_app_fe_server_ints_ro_at(sort, i);
		file = mk_clib_app_fe_server_files_ro_at(files, idx); mk_lang_assert(file);
		name = &file->m_name;
		err = mk_clib_app_fe_window_on_paint_impl_draw_response_idx_impl_dirify(file, &dirified); mk_lang_check_rereturn(err);
		text_buf = mk_clib_app_fe_server_name_ro_data(&dirified); mk_lang_assert(text_buf && text_buf[0] != L'\0');
		text_len = mk_clib_app_fe_server_name_ro_size(&dirified); mk_lang_assert(text_len >= 1);
		recta = *rect;
		err = mk_clib_app_fe_window_on_paint_impl_row_selected_on(pt, j); mk_lang_check_rereturn(err);
		height = mk_win_user_dc_draw_text_w(dc, &text_buf[0], text_len, &recta, flags); mk_lang_check_return(height != 0);
		err = mk_clib_app_fe_window_on_paint_impl_row_selected_of(pt, j); mk_lang_check_rereturn(err);
		rect->m_top += line_height;
		++j;
		if(height > line_height)
		{
			window->m_line_height = height;
			b = mk_win_user_window_invalidate_region(window->m_wnd, mk_win_user_region_get_null(), mk_win_base_true); mk_lang_check_return(b != 0);
			break;
		}
		if(rect->m_top >= rect->m_bottom)
		{
			break;
		}
	}
	err = mk_clib_app_fe_server_name_rw_destroy(&dirified); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_rows_idx(mk_clib_app_fe_window_paint_pt const pt) mk_lang_noexcept
{
	mk_clib_app_fe_window_pt window;
	mk_clib_app_fe_server_response_pt response;
	mk_lang_types_sint_t err;

	mk_lang_assert(pt);

	window = pt->m_window;
	response = window->m_response_current;
	if(response->m_data.m_idx.m_gle == 0)
	{
		err = mk_clib_app_fe_window_on_paint_impl_rows_idx_errn(pt); mk_lang_check_rereturn(err);
	}
	else
	{
		err = mk_clib_app_fe_window_on_paint_impl_rows_idx_erry(pt); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_rows_hourglass(mk_clib_app_fe_window_paint_pt const pt) mk_lang_noexcept
{
	mk_clib_app_fe_window_pt window;
	mk_win_base_uint_t flags;
	mk_win_base_rect_pt rect;
	mk_win_user_dc_t dc;
	mk_clib_app_fe_server_response_pct response;
	mk_lang_types_sint_pt line_height;
	mk_lang_types_sint_t scroll;
	mk_lang_types_wchar_pct text_buf;
	mk_lang_types_sint_t text_len;
	mk_win_user_base_colorref_t old_fg;
	mk_win_user_base_colorref_t old_bg;
	mk_win_base_rect_t recta;
	mk_win_base_sint_t tsi;
	mk_win_base_sint_t height;

	mk_lang_assert(pt);

	window = pt->m_window;
	flags = pt->m_flags;
	rect = &pt->m_rect;
	dc = pt->m_dc;
	response = pt->m_response;
	line_height = &window->m_line_height;
	scroll = window->m_scroll;
	text_buf = &mk_clib_app_fe_window_hourglass[0]; mk_lang_assert(text_buf && text_buf[0] != L'\0');
	text_len = mk_lang_countstr(mk_clib_app_fe_window_hourglass); mk_lang_assert(text_len >= 1);
	flags &=~ ((mk_win_base_dword_t)(mk_win_user_dc_flag_e_left));
	flags |= ((mk_win_base_dword_t)(mk_win_user_dc_flag_e_center));
	old_fg = mk_win_user_dc_set_text_color(dc, mk_win_user_base_get_sys_color(((mk_win_base_sint_t)(mk_win_user_base_color_id_e_graytext)))); mk_lang_check_return(old_fg != ((mk_win_user_base_colorref_t)(0xfffffffful)));
	old_bg = mk_win_user_dc_set_bk_color(dc, mk_win_user_base_get_sys_color(((mk_win_base_sint_t)(mk_win_user_base_color_id_e_window)))); mk_lang_check_return(old_bg != ((mk_win_user_base_colorref_t)(0xfffffffful)));
	recta = *rect; recta.m_bottom = rect->m_top + *line_height;
	tsi = mk_win_user_dc_fill_rect(dc, &recta, mk_win_user_brush_from_color_id(mk_win_user_base_color_id_e_window)); mk_lang_check_return(tsi != 0);
	recta = *rect;
	height = mk_win_user_dc_draw_text_w(dc, &text_buf[0], text_len, &recta, flags); mk_lang_check_return(height != 0); *line_height = mk_lang_max(height, *line_height);
	rect->m_top += *line_height;
	old_fg = mk_win_user_dc_set_text_color(dc, old_fg); mk_lang_check_return(old_fg != ((mk_win_user_base_colorref_t)(0xfffffffful)));
	old_bg = mk_win_user_dc_set_bk_color(dc, old_bg); mk_lang_check_return(old_bg != ((mk_win_user_base_colorref_t)(0xfffffffful)));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_rows(mk_clib_app_fe_window_paint_pt const pt) mk_lang_noexcept
{
	mk_clib_app_fe_window_pt window;
	mk_clib_app_fe_server_response_pt response;
	mk_lang_types_sint_t err;

	mk_lang_assert(pt);

	window = pt->m_window;
	response = window->m_response_current;
	if(response && response->m_req_id == window->m_req_id)
	{
		switch(response->m_type)
		{
			case mk_clib_app_fe_server_response_type_e_notadir  : err = mk_clib_app_fe_window_on_paint_impl_rows_notadir(pt); mk_lang_check_rereturn(err); break;
			case mk_clib_app_fe_server_response_type_e_invalid  : err = mk_clib_app_fe_window_on_paint_impl_rows_invalid(pt); mk_lang_check_rereturn(err); break;
			case mk_clib_app_fe_server_response_type_e_root     : err = mk_clib_app_fe_window_on_paint_impl_rows_root   (pt); mk_lang_check_rereturn(err); break;
			case mk_clib_app_fe_server_response_type_e_idx      : err = mk_clib_app_fe_window_on_paint_impl_rows_idx    (pt); mk_lang_check_rereturn(err); break;
			case mk_clib_app_fe_server_response_type_e_dummy_end: mk_lang_assert(mk_lang_false); break;
			default                                             : mk_lang_assert(mk_lang_false); break;
		}
	}
	else
	{
		err = mk_clib_app_fe_window_on_paint_impl_rows_hourglass(pt); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_draw_response(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_clib_app_fe_window_paint_t pt;
	mk_lang_types_sint_t err;

	mk_lang_assert(window);
	mk_lang_assert(window->m_response_current);
	mk_lang_assert(!mk_win_user_base_wnd_is_null(window->m_wnd));
	mk_lang_assert(!mk_win_user_dc_is_null(window->m_mem_dc));

	err = mk_clib_app_fe_window_on_paint_impl_init(&pt, window); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_window_on_paint_impl_fixup_idx_and_scroll(&pt); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_window_on_paint_impl_up(&pt); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_window_on_paint_impl_rows(&pt); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_go_up_history(mk_clib_app_fe_window_pt const window, mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t idx;
	mk_lang_types_sint_t scroll;

	mk_lang_assert(window);
	mk_lang_assert(response);

	if(response->m_type == mk_clib_app_fe_server_response_type_e_idx && response->m_data.m_idx.m_went_up)
	{
		idx = *mk_clib_app_fe_server_ints_ro_back(&window->m_history_idx);
		err = mk_clib_app_fe_server_ints_rw_pop_back_one(&window->m_history_idx); mk_lang_check_rereturn(err);
		idx = *mk_clib_app_fe_server_ints_ro_back(&window->m_history_idx);
		err = mk_clib_app_fe_server_ints_rw_pop_back_one(&window->m_history_idx); mk_lang_check_rereturn(err);
		window->m_idx = idx;
		scroll = *mk_clib_app_fe_server_ints_ro_back(&window->m_history_scroll);
		err = mk_clib_app_fe_server_ints_rw_pop_back_one(&window->m_history_scroll); mk_lang_check_rereturn(err);
		scroll = *mk_clib_app_fe_server_ints_ro_back(&window->m_history_scroll);
		err = mk_clib_app_fe_server_ints_rw_pop_back_one(&window->m_history_scroll); mk_lang_check_rereturn(err);
		window->m_scroll = scroll;
		err = mk_clib_app_fe_window_scroll_to_selected(window); mk_lang_check_rereturn(err);
	}
	else if(response->m_type == mk_clib_app_fe_server_response_type_e_root)
	{
		if(!mk_clib_app_fe_server_ints_ro_is_empty(&window->m_history_idx))
		{
			idx = *mk_clib_app_fe_server_ints_ro_back(&window->m_history_idx);
			err = mk_clib_app_fe_server_ints_rw_pop_back_one(&window->m_history_idx); mk_lang_check_rereturn(err);
			idx = *mk_clib_app_fe_server_ints_ro_back(&window->m_history_idx);
			err = mk_clib_app_fe_server_ints_rw_pop_back_one(&window->m_history_idx); mk_lang_check_rereturn(err);
			mk_lang_assert(mk_clib_app_fe_server_ints_ro_is_empty(&window->m_history_idx));
			window->m_idx = idx;
			scroll = *mk_clib_app_fe_server_ints_ro_back(&window->m_history_scroll);
			err = mk_clib_app_fe_server_ints_rw_pop_back_one(&window->m_history_scroll); mk_lang_check_rereturn(err);
			scroll = *mk_clib_app_fe_server_ints_ro_back(&window->m_history_scroll);
			err = mk_clib_app_fe_server_ints_rw_pop_back_one(&window->m_history_scroll); mk_lang_check_rereturn(err);
			mk_lang_assert(mk_clib_app_fe_server_ints_ro_is_empty(&window->m_history_scroll));
			window->m_scroll = scroll;
			err = mk_clib_app_fe_window_scroll_to_selected(window); mk_lang_check_rereturn(err);
		}
		else
		{
			window->m_idx = 0;
			window->m_scroll = 0;
			err = mk_clib_app_fe_window_scroll_to_selected(window); mk_lang_check_rereturn(err);
		}
	}
	else if(response->m_type == mk_clib_app_fe_server_response_type_e_notadir)
	{
		err = mk_clib_app_fe_window_scroll_to_selected(window); mk_lang_check_rereturn(err);
	}
	else
	{
		window->m_idx = 0;
		window->m_scroll = 0;
		err = mk_clib_app_fe_window_scroll_to_selected(window); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_assign_response(mk_clib_app_fe_window_pt const window, mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t idx;
	mk_lang_types_sint_t scroll;

	mk_lang_assert(window);
	mk_lang_assert(response);

	if(response->m_type != mk_clib_app_fe_server_response_type_e_notadir)
	{
		err = mk_clib_app_fe_window_response_ref_count_dec(window, window->m_response_current); mk_lang_check_rereturn(err);
		window->m_response_current = response;
	}
	else
	{
		if(window->m_response_current)
		{
			window->m_response_current->m_req_id = response->m_req_id;
		}
		idx = *mk_clib_app_fe_server_ints_ro_back(&window->m_history_idx);
		err = mk_clib_app_fe_server_ints_rw_pop_back_one(&window->m_history_idx); mk_lang_check_rereturn(err);
		window->m_idx = idx;
		scroll = *mk_clib_app_fe_server_ints_ro_back(&window->m_history_scroll);
		err = mk_clib_app_fe_server_ints_rw_pop_back_one(&window->m_history_scroll); mk_lang_check_rereturn(err);
		window->m_scroll = scroll;
		err = mk_clib_app_fe_window_response_ref_count_dec(window, response); mk_lang_check_rereturn(err);
	}
	err = mk_clib_app_fe_window_go_up_history(window, response); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_make_request_root_and_wait_for_while(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_lang_types_sint_t val;
	mk_clib_app_fe_server_request_pt request;
	mk_lang_types_sint_t err;
	mk_clib_app_fe_server_response_pt response;
	mk_lang_types_bool_t success;

	mk_lang_assert(window);

	val = 1;
	++window->m_req_id;
	err = mk_clib_app_fe_server_requestsmt_rw_pop_front_copy(&window->m_server->m_requests_ready, &request); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_atomic_sint_construct(&request->m_ref_count); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_atomic_sint_store(&request->m_ref_count, &val, mk_lib_mt_memory_order_e_relaxed); mk_lang_check_rereturn(err);
	request->m_type = mk_clib_app_fe_server_request_type_e_root;
	request->m_req_id = window->m_req_id;
	request->m_data.m_root.m_dummy = 0;
	err = mk_clib_app_fe_server_requestsmt_rw_push_back_one(&window->m_server->m_requests_waiting, &request); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_responsesmt_rw_try_pop_front_for_copy(&window->m_responses_waiting, mk_clib_app_fe_timeout, &response, &success); mk_lang_check_rereturn(err);
	if(success)
	{
		mk_lang_assert(response);
		err = mk_clib_app_fe_window_assign_response(window, response); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_make_request_up_and_wait_for_while(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t has_up;
	mk_lang_types_sint_t val;
	mk_clib_app_fe_server_request_pt request;
	mk_clib_app_fe_server_response_pt response;
	mk_lang_types_bool_t success;
	mk_win_base_bool_t b;

	mk_lang_assert(window);

	if(window->m_response_current && window->m_response_current->m_req_id == window->m_req_id)
	{
		err = mk_clib_app_fe_server_response_has_up(window->m_response_current, &has_up); mk_lang_check_rereturn(err);
		if(has_up)
		{
			val = 1;
			++window->m_req_id;
			err = mk_clib_app_fe_server_requestsmt_rw_pop_front_copy(&window->m_server->m_requests_ready, &request); mk_lang_check_rereturn(err);
			err = mk_clib_app_fe_server_atomic_sint_construct(&request->m_ref_count); mk_lang_check_rereturn(err);
			err = mk_clib_app_fe_server_atomic_sint_store(&request->m_ref_count, &val, mk_lib_mt_memory_order_e_relaxed); mk_lang_check_rereturn(err);
			request->m_type = mk_clib_app_fe_server_request_type_e_idx;
			request->m_req_id = window->m_req_id;
			request->m_data.m_idx.m_idx = 0;
			err = mk_clib_app_fe_server_ints_rw_push_back_one(&window->m_history_idx, &window->m_idx); mk_lang_check_rereturn(err);
			err = mk_clib_app_fe_server_ints_rw_push_back_one(&window->m_history_scroll, &window->m_scroll); mk_lang_check_rereturn(err);
			err = mk_clib_app_fe_server_requestsmt_rw_push_back_one(&window->m_server->m_requests_waiting, &request); mk_lang_check_rereturn(err);
			err = mk_clib_app_fe_server_responsesmt_rw_try_pop_front_for_copy(&window->m_responses_waiting, mk_clib_app_fe_timeout, &response, &success); mk_lang_check_rereturn(err);
			if(success)
			{
				mk_lang_assert(response);
				err = mk_clib_app_fe_window_assign_response(window, response); mk_lang_check_rereturn(err);
			}
			b = mk_win_user_window_invalidate_region(window->m_wnd, mk_win_user_region_get_null(), mk_win_base_true); mk_lang_check_return(b != 0);
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_make_request_idx_and_wait_for_while(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_lang_types_sint_t val;
	mk_clib_app_fe_server_request_pt request;
	mk_lang_types_sint_t err;
	mk_clib_app_fe_server_response_pt response;
	mk_lang_types_bool_t success;
	mk_win_base_bool_t b;

	mk_lang_assert(window);

	if(window->m_response_current && window->m_response_current->m_req_id == window->m_req_id)
	{
		val = 1;
		++window->m_req_id;
		err = mk_clib_app_fe_server_requestsmt_rw_pop_front_copy(&window->m_server->m_requests_ready, &request); mk_lang_check_rereturn(err);
		err = mk_clib_app_fe_server_atomic_sint_construct(&request->m_ref_count); mk_lang_check_rereturn(err);
		err = mk_clib_app_fe_server_atomic_sint_store(&request->m_ref_count, &val, mk_lib_mt_memory_order_e_relaxed); mk_lang_check_rereturn(err);
		request->m_type = mk_clib_app_fe_server_request_type_e_idx;
		request->m_req_id = window->m_req_id;
		request->m_data.m_idx.m_idx = window->m_idx;
		err = mk_clib_app_fe_server_ints_rw_push_back_one(&window->m_history_idx, &window->m_idx); mk_lang_check_rereturn(err);
		err = mk_clib_app_fe_server_ints_rw_push_back_one(&window->m_history_scroll, &window->m_scroll); mk_lang_check_rereturn(err);
		err = mk_clib_app_fe_server_requestsmt_rw_push_back_one(&window->m_server->m_requests_waiting, &request); mk_lang_check_rereturn(err);
		err = mk_clib_app_fe_server_responsesmt_rw_try_pop_front_for_copy(&window->m_responses_waiting, mk_clib_app_fe_timeout, &response, &success); mk_lang_check_rereturn(err);
		if(success)
		{
			mk_lang_assert(response);
			err = mk_clib_app_fe_window_assign_response(window, response); mk_lang_check_rereturn(err);
		}
		b = mk_win_user_window_invalidate_region(window->m_wnd, mk_win_user_region_get_null(), mk_win_base_true); mk_lang_check_return(b != 0);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_pump_response(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_clib_app_fe_server_response_pt response;
	mk_lang_types_bool_t success;

	mk_lang_assert(window);

	for(;;)
	{
		err = mk_clib_app_fe_server_responsesmt_rw_try_pop_front_copy(&window->m_responses_waiting, &response, &success); mk_lang_check_rereturn(err);
		if(success)
		{
			mk_lang_assert(response);
			err = mk_clib_app_fe_window_assign_response(window, response); mk_lang_check_rereturn(err);
		}
		else
		{
			break;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_2(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_clib_app_fe_pt fe;
	mk_lang_types_sint_t err;

	mk_lang_assert(window);
	mk_lang_assert(!mk_win_user_dc_is_null(window->m_mem_dc));

	if(window->m_init)
	{
		window->m_init = mk_lang_false;
		err = mk_clib_app_fe_window_make_request_root_and_wait_for_while(window); mk_lang_check_rereturn(err);
	}
	err = mk_clib_app_fe_window_pump_response(window); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_window_on_paint_impl_draw_response(window); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_memdc_free(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_win_user_bitmap_t old_bitmap;
	mk_win_base_bool_t b;

	mk_lang_assert(window);

	if(!mk_win_user_bitmap_is_null(window->m_bitmap))
	{
		mk_lang_assert(!mk_win_user_dc_is_null(window->m_mem_dc));
		old_bitmap = mk_win_user_dc_select_bitmap(window->m_mem_dc, window->m_old_bitmap); mk_lang_assert(mk_win_user_bitmap_is_null(window->m_old_bitmap) || old_bitmap.m_data == window->m_bitmap.m_data);
		b = mk_win_user_dc_delete(window->m_mem_dc); mk_lang_check_return(b != 0);
		b = mk_win_user_gdi_obj_delete(mk_win_user_base_gdi_obj_from(window->m_bitmap.m_data)); mk_lang_check_return(b != 0);
		window->m_bitmap = mk_win_user_bitmap_get_null();
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_memdc_refresh(mk_clib_app_fe_window_pt const window, mk_win_user_dc_t const dc) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_rect_t rect;
	mk_lang_types_sint_t err;
	mk_win_user_dc_t mem_dc;
	mk_win_user_bitmap_t bitmap;
	mk_win_user_bitmap_t old_bitmap;
	mk_win_user_brush_t brush;
	mk_win_base_sint_t tsi;

	mk_lang_assert(window);
	mk_lang_assert(!mk_win_user_dc_is_null(dc));

	b = mk_win_user_window_get_rect_client(window->m_wnd, &rect); mk_lang_check_return(b != 0);
	if(window->m_rect.m_left != rect.m_left || window->m_rect.m_top != rect.m_top || window->m_rect.m_right != rect.m_right || window->m_rect.m_bottom != rect.m_bottom)
	{
		err = mk_clib_app_fe_window_memdc_free(window); mk_lang_check_rereturn(err);
		mem_dc = mk_win_user_dc_create_compatible(dc); mk_lang_check_return(!mk_win_user_dc_is_null(mem_dc));
		bitmap = mk_win_user_bitmap_create_compatible(dc, ((mk_win_base_sint_t)(rect.m_right - rect.m_left)), ((mk_win_base_sint_t)(rect.m_bottom - rect.m_top))); mk_lang_check_return(!mk_win_user_bitmap_is_null(bitmap));
		old_bitmap = mk_win_user_dc_select_bitmap(mem_dc, bitmap);
		window->m_rect = rect;
		window->m_mem_dc = mem_dc;
		window->m_bitmap = bitmap;
		window->m_old_bitmap = old_bitmap;
	}
	else
	{
		mem_dc = window->m_mem_dc;
	}
	brush = mk_win_user_brush_from_color_id(mk_win_user_base_color_id_e_window); mk_lang_check_return(!mk_win_user_brush_is_null(brush));
	tsi = mk_win_user_dc_fill_rect(mem_dc, &rect, brush); mk_lang_check_return(tsi != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_memdc_bitblast(mk_clib_app_fe_window_pt const window, mk_win_user_dc_t const dc) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(window);
	mk_lang_assert(!mk_win_user_dc_is_null(dc));

	b = bitblast(dc, 0, 0, ((mk_win_base_sint_t)(window->m_rect.m_right - window->m_rect.m_left)), ((mk_win_base_sint_t)(window->m_rect.m_bottom - window->m_rect.m_top)), window->m_mem_dc, 0, 0, ((mk_win_base_dword_t)(bitblast_rop_e_srccopy))); mk_lang_check_return(b != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_impl_1(mk_clib_app_fe_window_pt const window, mk_win_user_base_ps_pt const ps) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(window);
	mk_lang_assert(ps);
	mk_lang_assert(!mk_win_user_dc_is_null(ps->m_dc));

	err = mk_clib_app_fe_window_memdc_refresh(window, ps->m_dc); mk_lang_check_rereturn(err);
	err_b = mk_clib_app_fe_window_on_paint_impl_2(window);
	err = mk_clib_app_fe_window_memdc_bitblast(window, ps->m_dc); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_dc_acquire(mk_clib_app_fe_window_pt const window, mk_win_user_base_ps_lpt const ps) mk_lang_noexcept
{
	mk_win_user_dc_t dc;

	mk_lang_assert(window);
	mk_lang_assert(ps);

	dc = mk_win_user_window_paint_begin(window->m_wnd, ps); mk_lang_check_return(!mk_win_user_dc_is_null(dc) && dc.m_data == ps->m_dc.m_data);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint_dc_release(mk_clib_app_fe_window_pt const window, mk_win_user_base_ps_lpt const ps) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(window);
	mk_lang_assert(ps);

	b = mk_win_user_window_paint_end(window->m_wnd, ps); mk_lang_check_return(b != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_scrollbar_refresh(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t count;
	mk_lang_types_bool_t has_up;
	mk_lang_types_sint_t client_height;
	mk_lang_types_sint_t client_whole_rows;
	mk_lang_types_sint_t scrollbar_status;
	mk_lang_types_sint_t tsi;
	mk_win_base_bool_t b;
	mk_win_user_window_scrollinfo_t scrollinfo;

	mk_lang_assert(window);

	if(window->m_response_current)
	{
		err = mk_clib_app_fe_server_response_get_count(window->m_response_current, &count); mk_lang_check_rereturn(err);
		err = mk_clib_app_fe_server_response_has_up(window->m_response_current, &has_up); mk_lang_check_rereturn(err);
		count += (has_up ? 1 : 0);
		client_height = ((mk_win_base_sint_t)(window->m_rect.m_bottom - window->m_rect.m_top));
		client_whole_rows = client_height / window->m_line_height;
		if(client_whole_rows >= count && window->m_scroll == 0)
		{
			scrollbar_status = 0;
		}
		else if(window->m_scroll == 0)
		{
			scrollbar_status = 1;
		}
		else if(client_whole_rows >= count - window->m_scroll)
		{
			scrollbar_status = 2;
		}
		else
		{
			scrollbar_status = 3;
		}
		if(window->m_scrollbar_status != scrollbar_status)
		{
			window->m_scrollbar_status = scrollbar_status;
			b = mk_win_user_window_scrollbar_enable(window->m_wnd, ((mk_win_base_uint_t)(mk_win_user_window_scrollbar_e_vert)), ((mk_win_base_uint_t)(mk_win_user_window_scrollbar_arrow_e_enable_both))); ((mk_lang_types_void_t)(b));
			if(scrollbar_status == 0)
			{
				b = mk_win_user_window_scrollbar_enable(window->m_wnd, ((mk_win_base_uint_t)(mk_win_user_window_scrollbar_e_vert)), ((mk_win_base_uint_t)(mk_win_user_window_scrollbar_arrow_e_disable_both))); ((mk_lang_types_void_t)(b));
			}
			else
			{
				if(scrollbar_status == 1)
				{
					b = mk_win_user_window_scrollbar_enable(window->m_wnd, ((mk_win_base_uint_t)(mk_win_user_window_scrollbar_e_vert)), ((mk_win_base_uint_t)(mk_win_user_window_scrollbar_arrow_e_disable_up))); ((mk_lang_types_void_t)(b));
				}
				else if(scrollbar_status == 2)
				{
					b = mk_win_user_window_scrollbar_enable(window->m_wnd, ((mk_win_base_uint_t)(mk_win_user_window_scrollbar_e_vert)), ((mk_win_base_uint_t)(mk_win_user_window_scrollbar_arrow_e_disable_down))); ((mk_lang_types_void_t)(b));
				}
			}
		}
		if(scrollbar_status != 0)
		{
			scrollinfo.m_len = ((mk_win_base_uint_t)(sizeof(scrollinfo)));
			scrollinfo.m_mask = ((mk_win_base_uint_t)(mk_win_user_window_scrollbar_info_e_range | mk_win_user_window_scrollbar_info_e_page | mk_win_user_window_scrollbar_info_e_pos));
			scrollinfo.m_min = 0;
			scrollinfo.m_max = count - 1;
			scrollinfo.m_page = client_whole_rows;
			scrollinfo.m_pos = mk_lang_max(0, mk_lang_min(scrollinfo.m_max, window->m_scroll));
			scrollinfo.m_track_pos = 0;
			tsi = mk_win_user_window_scrollbar_info_set(window->m_wnd, ((mk_win_base_sint_t)(mk_win_user_window_scrollbar_e_vert)), &scrollinfo, mk_win_base_true); ((mk_lang_types_void_t)(tsi));
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_paint(mk_clib_app_fe_window_pt const window, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_win_user_base_ps_t ps;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(window);
	mk_lang_assert(override_defproc);
	mk_lang_assert(override_result);

	((mk_lang_types_void_t)(wparam));
	((mk_lang_types_void_t)(lparam));
	err = mk_clib_app_fe_window_on_paint_dc_acquire(window, &ps); mk_lang_check_rereturn(err);
	err_b = mk_clib_app_fe_window_on_paint_impl_1(window, &ps);
	err = mk_clib_app_fe_window_on_paint_dc_release(window, &ps); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	err = mk_clib_app_fe_window_scrollbar_refresh(window); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_erasebkgnd(mk_clib_app_fe_window_pt const window, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
{
	mk_lang_assert(window);
	mk_lang_assert(override_defproc);
	mk_lang_assert(override_result);

	((mk_lang_types_void_t)(wparam));
	((mk_lang_types_void_t)(lparam));
	*override_defproc = mk_lang_true;
	*override_result = 1;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_keydown_vk_prior(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_win_base_sint_t client_height;
	mk_win_base_sint_t client_whole_rows;
	mk_lang_types_sint_t idx_old;
	mk_lang_types_sint_t idx_new;
	mk_lang_types_sint_t err;
	mk_win_base_bool_t b;

	mk_lang_assert(window);
	mk_lang_assert(!mk_win_user_base_wnd_is_null(window->m_wnd));
	mk_lang_assert(window->m_response_current);

	client_height = ((mk_win_base_sint_t)(window->m_rect.m_bottom - window->m_rect.m_top));
	client_whole_rows = client_height / window->m_line_height;
	idx_old = window->m_idx;
	idx_new = mk_lang_max(0, idx_old - client_whole_rows);
	if(idx_new != idx_old)
	{
		window->m_idx = idx_new;
		err = mk_clib_app_fe_window_scroll_to_selected(window); mk_lang_check_rereturn(err);
		/* todo smarter invalidation */
		b = mk_win_user_window_invalidate_region(window->m_wnd, mk_win_user_region_get_null(), mk_win_base_true); mk_lang_check_return(b != 0);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_keydown_vk_next(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_win_base_sint_t client_height;
	mk_win_base_sint_t client_whole_rows;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t count;
	mk_lang_types_bool_t has_up;
	mk_lang_types_sint_t idx_old;
	mk_lang_types_sint_t idx_new;
	mk_win_base_bool_t b;

	mk_lang_assert(window);
	mk_lang_assert(!mk_win_user_base_wnd_is_null(window->m_wnd));
	mk_lang_assert(window->m_response_current);

	client_height = ((mk_win_base_sint_t)(window->m_rect.m_bottom - window->m_rect.m_top));
	client_whole_rows = client_height / window->m_line_height;
	err = mk_clib_app_fe_server_response_get_count(window->m_response_current, &count); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_response_has_up(window->m_response_current, &has_up); mk_lang_check_rereturn(err);
	count += (has_up ? 1 : 0);
	idx_old = window->m_idx;
	idx_new = mk_lang_min(count - 1, idx_old + client_whole_rows);
	if(idx_new != idx_old)
	{
		window->m_idx = idx_new;
		err = mk_clib_app_fe_window_scroll_to_selected(window); mk_lang_check_rereturn(err);
		/* todo smarter invalidation */
		b = mk_win_user_window_invalidate_region(window->m_wnd, mk_win_user_region_get_null(), mk_win_base_true); mk_lang_check_return(b != 0);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_keydown_vk_end(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t count;
	mk_lang_types_bool_t has_up;
	mk_lang_types_sint_t idx_old;
	mk_lang_types_sint_t idx_new;
	mk_win_base_bool_t b;

	mk_lang_assert(window);
	mk_lang_assert(!mk_win_user_base_wnd_is_null(window->m_wnd));
	mk_lang_assert(window->m_response_current);

	err = mk_clib_app_fe_server_response_get_count(window->m_response_current, &count); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_response_has_up(window->m_response_current, &has_up); mk_lang_check_rereturn(err);
	count += (has_up ? 1 : 0);
	idx_old = window->m_idx;
	idx_new = count - 1;
	if(idx_new != idx_old)
	{
		window->m_idx = idx_new;
		err = mk_clib_app_fe_window_scroll_to_selected(window); mk_lang_check_rereturn(err);
		/* todo smarter invalidation */
		b = mk_win_user_window_invalidate_region(window->m_wnd, mk_win_user_region_get_null(), mk_win_base_true); mk_lang_check_return(b != 0);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_keydown_vk_home(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_lang_types_sint_t idx_old;
	mk_lang_types_sint_t idx_new;
	mk_lang_types_sint_t err;
	mk_win_base_bool_t b;

	mk_lang_assert(window);
	mk_lang_assert(!mk_win_user_base_wnd_is_null(window->m_wnd));
	mk_lang_assert(window->m_response_current);

	idx_old = window->m_idx;
	idx_new = 0;
	if(idx_new != idx_old)
	{
		window->m_idx = idx_new;
		err = mk_clib_app_fe_window_scroll_to_selected(window); mk_lang_check_rereturn(err);
		/* todo smarter invalidation */
		b = mk_win_user_window_invalidate_region(window->m_wnd, mk_win_user_region_get_null(), mk_win_base_true); mk_lang_check_return(b != 0);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_keydown_vk_up(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_lang_types_sint_t idx_old;
	mk_lang_types_sint_t idx_new;
	mk_lang_types_sint_t err;
	mk_win_base_bool_t b;

	mk_lang_assert(window);
	mk_lang_assert(!mk_win_user_base_wnd_is_null(window->m_wnd));
	mk_lang_assert(window->m_response_current);

	idx_old = window->m_idx;
	idx_new = mk_lang_max(0, idx_old - 1);
	if(idx_new != idx_old)
	{
		window->m_idx = idx_new;
		err = mk_clib_app_fe_window_scroll_to_selected(window); mk_lang_check_rereturn(err);
		/* todo smarter invalidation */
		b = mk_win_user_window_invalidate_region(window->m_wnd, mk_win_user_region_get_null(), mk_win_base_true); mk_lang_check_return(b != 0);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_keydown_vk_down(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t count;
	mk_lang_types_bool_t has_up;
	mk_lang_types_sint_t idx_old;
	mk_lang_types_sint_t idx_new;
	mk_win_base_bool_t b;

	mk_lang_assert(window);
	mk_lang_assert(!mk_win_user_base_wnd_is_null(window->m_wnd));
	mk_lang_assert(window->m_response_current);

	err = mk_clib_app_fe_server_response_get_count(window->m_response_current, &count); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_response_has_up(window->m_response_current, &has_up); mk_lang_check_rereturn(err);
	count += (has_up ? 1 : 0);
	idx_old = window->m_idx;
	idx_new = mk_lang_min(count - 1, idx_old + 1);
	if(idx_new != idx_old)
	{
		window->m_idx = idx_new;
		err = mk_clib_app_fe_window_scroll_to_selected(window); mk_lang_check_rereturn(err);
		/* todo smarter invalidation */
		b = mk_win_user_window_invalidate_region(window->m_wnd, mk_win_user_region_get_null(), mk_win_base_true); mk_lang_check_return(b != 0);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_keydown(mk_clib_app_fe_window_pt const window, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
{
	mk_win_user_msg_vk_t vk;
	mk_lang_types_sint_t err;

	mk_lang_assert(window);
	mk_lang_assert(override_defproc);
	mk_lang_assert(override_result);

	vk = ((mk_win_user_msg_vk_t)(wparam));
	switch(vk)
	{
		case mk_win_user_msg_vk_e_prior: err = mk_clib_app_fe_window_on_keydown_vk_prior(window); mk_lang_check_rereturn(err); break;
		case mk_win_user_msg_vk_e_next : err = mk_clib_app_fe_window_on_keydown_vk_next (window); mk_lang_check_rereturn(err); break;
		case mk_win_user_msg_vk_e_end  : err = mk_clib_app_fe_window_on_keydown_vk_end  (window); mk_lang_check_rereturn(err); break;
		case mk_win_user_msg_vk_e_home : err = mk_clib_app_fe_window_on_keydown_vk_home (window); mk_lang_check_rereturn(err); break;
		case mk_win_user_msg_vk_e_up   : err = mk_clib_app_fe_window_on_keydown_vk_up   (window); mk_lang_check_rereturn(err); break;
		case mk_win_user_msg_vk_e_down : err = mk_clib_app_fe_window_on_keydown_vk_down (window); mk_lang_check_rereturn(err); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_char_vk_back(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(window);

	err = mk_clib_app_fe_window_make_request_up_and_wait_for_while(window); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_char_vk_return(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(window);

	err = mk_clib_app_fe_window_make_request_idx_and_wait_for_while(window); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_char(mk_clib_app_fe_window_pt const window, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
{
	mk_win_user_msg_vk_t vk;
	mk_lang_types_sint_t err;

	mk_lang_assert(window);
	mk_lang_assert(override_defproc);
	mk_lang_assert(override_result);

	((mk_lang_types_void_t)(lparam));
	vk = ((mk_win_user_msg_vk_t)(wparam));
	switch(vk)
	{
		case mk_win_user_msg_vk_e_back  : err = mk_clib_app_fe_window_on_char_vk_back  (window); mk_lang_check_rereturn(err); break;
		case mk_win_user_msg_vk_e_return: err = mk_clib_app_fe_window_on_char_vk_return(window); mk_lang_check_rereturn(err); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_vscroll(mk_clib_app_fe_window_pt const window, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
{
	mk_win_user_msg_sb_t scroll_code;
	mk_win_base_bool_t b;

	mk_lang_assert(window);
	mk_lang_assert(override_defproc);
	mk_lang_assert(override_result);

	scroll_code = ((mk_win_user_msg_sb_t)(((mk_win_base_ushort_t)(((mk_win_base_usize_t)(wparam)) & ((mk_win_base_usize_t)(0xfffful))))));
	switch(scroll_code)
	{
		case mk_win_user_msg_sb_e_lineup  : --window->m_scroll; break;
		case mk_win_user_msg_sb_e_linedown: ++window->m_scroll; break;
	}
	b = mk_win_user_window_invalidate_region(window->m_wnd, mk_win_user_region_get_null(), mk_win_base_true); mk_lang_check_return(b != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_user_1(mk_clib_app_fe_window_pt const window, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(window);
	mk_lang_assert(override_defproc);
	mk_lang_assert(override_result);

	((mk_lang_types_void_t)(wparam));
	((mk_lang_types_void_t)(lparam));
	((mk_lang_types_void_t)(override_defproc));
	((mk_lang_types_void_t)(override_result));
	b = mk_win_user_window_invalidate_region(window->m_wnd, mk_win_user_region_get_null(), mk_win_base_true); mk_lang_check_return(b != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_msg(mk_clib_app_fe_window_pt const window, mk_win_base_uint_t const msg, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(window);
	mk_lang_assert(override_defproc);
	mk_lang_assert(override_result);

	switch(msg)
	{
		case mk_win_user_msg_id_e_destroy   : err = mk_clib_app_fe_window_on_destroy   (window, wparam, lparam, override_defproc, override_result); mk_lang_check_rereturn(err); break;
		case mk_win_user_msg_id_e_paint     : err = mk_clib_app_fe_window_on_paint     (window, wparam, lparam, override_defproc, override_result); mk_lang_check_rereturn(err); break;
		case mk_win_user_msg_id_e_erasebkgnd: err = mk_clib_app_fe_window_on_erasebkgnd(window, wparam, lparam, override_defproc, override_result); mk_lang_check_rereturn(err); break;
		case mk_win_user_msg_id_e_keydown   : err = mk_clib_app_fe_window_on_keydown   (window, wparam, lparam, override_defproc, override_result); mk_lang_check_rereturn(err); break;
		case mk_win_user_msg_id_e_char      : err = mk_clib_app_fe_window_on_char      (window, wparam, lparam, override_defproc, override_result); mk_lang_check_rereturn(err); break;
		case mk_win_user_msg_id_e_vscroll   : err = mk_clib_app_fe_window_on_vscroll   (window, wparam, lparam, override_defproc, override_result); mk_lang_check_rereturn(err); break;
		case mk_win_user_msg_id_e_user + 1  : err = mk_clib_app_fe_window_on_user_1    (window, wparam, lparam, override_defproc, override_result); mk_lang_check_rereturn(err); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_win_user_base_lresult_t mk_win_base_stdcall mk_clib_app_fe_window_raw_on_msg(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const msg, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t override_defproc;
	mk_win_base_uintptr_t data;
	mk_clib_app_fe_window_pt window;
	mk_win_user_base_lresult_t lr;

	err = mk_clib_app_fe_window_on_create(wnd, msg, wparam, lparam); mk_lang_check_recrash(err);
	override_defproc = mk_lang_false;
	data = mk_win_user_window_w_data_get(wnd, ((mk_win_base_sint_t)(mk_win_user_window_data_id_e_userdata))); window = ((mk_clib_app_fe_window_pt)(data));
	if(data != 0)
	{
		err = mk_clib_app_fe_window_on_msg(window, msg, wparam, lparam, &override_defproc, &lr); mk_lang_check_recrash(err);
	}
	if(!override_defproc)
	{
		lr = mk_win_user_window_w_def_proc(wnd, msg, wparam, lparam);
	}
	return lr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_on_response_impl_1(mk_clib_app_fe_window_pt const window, mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t val;
	mk_win_base_bool_t b;

	mk_lang_assert(window);
	mk_lang_assert(response);

	err = mk_clib_app_fe_server_atomic_sint_inc(&response->m_ref_count, mk_lib_mt_memory_order_e_acq_rel, &val); mk_lang_check_rereturn(err); mk_lang_assert(val >= 1);
	err = mk_clib_app_fe_server_responsesmt_rw_push_back_one(&window->m_responses_waiting, &response); mk_lang_check_rereturn(err);
	b = mk_win_user_window_w_msg_post(window->m_wnd, mk_win_user_msg_id_e_user + 1, 0, 0); mk_lang_check_return(b != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_types_sint_t mk_clib_app_fe_window_on_response(mk_lang_types_void_pt const ctx, mk_clib_app_fe_server_response_pt const response) mk_lang_noexcept
{
	mk_clib_app_fe_window_pt window;
	mk_lang_types_sint_t err;

	mk_lang_assert(ctx);
	mk_lang_assert(response);

	window = ((mk_clib_app_fe_window_pt)(ctx));
	err = mk_clib_app_fe_window_on_response_impl_1(window, response); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_display(mk_clib_app_fe_window_pt const window, mk_clib_app_fe_pt const fe) mk_lang_noexcept
{
	mk_win_base_rect_t rect;
	mk_win_base_bool_t b;
	mk_win_user_base_wnd_t wnd;

	mk_lang_assert(window);
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_class != 0);

	rect.m_left = 0;
	rect.m_top = 0;
	rect.m_right = 320;
	rect.m_bottom = 200;
	b = mk_win_user_window_rect_adjust_ex(&rect, ((mk_win_base_dword_t)(mk_win_user_window_style_id_e_overlappedwindow)), mk_win_base_false, ((mk_win_base_dword_t)(mk_win_user_window_styleex_id_e_overlappedwindow))); mk_lang_check_return(b != 0);
	wnd = mk_win_user_window_w_createex(((mk_win_base_dword_t)(mk_win_user_window_styleex_id_e_overlappedwindow)), ((mk_win_base_wchar_lpct)(((mk_win_base_uintptr_t)(fe->m_class)))), L"mkfe", ((mk_win_base_dword_t)(mk_win_user_window_style_id_e_overlappedwindow)), mk_win_user_window_use_default, mk_win_user_window_use_default, ((mk_win_base_sint_t)(rect.m_right - rect.m_left)), ((mk_win_base_sint_t)(rect.m_bottom - rect.m_top)), mk_win_user_base_wnd_get_null(), mk_win_user_menu_get_null(), fe->m_instance, window); mk_lang_check_return(!mk_win_user_base_wnd_is_null(wnd)); mk_lang_assert(window->m_wnd.m_data == wnd.m_data);
	b = mk_win_user_window_scrollbar_show(wnd, ((mk_win_base_sint_t)(mk_win_user_window_scrollbar_e_both)), mk_win_base_true); mk_lang_check_return(b != 0);
	b = mk_win_user_window_scrollbar_enable(wnd, ((mk_win_base_uint_t)(mk_win_user_window_scrollbar_e_horz)), ((mk_win_base_uint_t)(mk_win_user_window_scrollbar_arrow_e_disable_both))); ((mk_lang_types_void_t)(b));
	b = mk_win_user_window_show(wnd, ((mk_win_base_sint_t)(mk_win_user_window_show_e_showdefault))); ((mk_lang_types_void_t)(b));
	b = mk_win_user_window_update(wnd); mk_lang_check_return(b != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_destroy(mk_clib_app_fe_window_pt const window) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_clib_app_fe_server_response_pt response;
	mk_lang_types_bool_t success;

	mk_lang_assert(window);

	for(;;)
	{
		err = mk_clib_app_fe_server_responsesmt_rw_try_pop_front_copy(&window->m_responses_waiting, &response, &success); mk_lang_check_rereturn(err);
		if(success)
		{
			mk_lang_assert(response);
			err = mk_clib_app_fe_window_response_ref_count_dec(window, response); mk_lang_check_rereturn(err);
		}
		else
		{
			break;
		}
	}
	err = mk_clib_app_fe_window_memdc_free(window); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_window_response_ref_count_dec(window, window->m_response_current); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_ints_rw_destroy(&window->m_history_idx); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_ints_rw_destroy(&window->m_history_scroll); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_responsesmt_rw_destroy(&window->m_responses_waiting); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_window_construct(mk_clib_app_fe_window_pt const window, mk_clib_app_fe_server_pt const server) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(window);
	mk_lang_assert(server);

	window->m_server = server;
	window->m_rect.m_left = 0;
	window->m_rect.m_top = 0;
	window->m_rect.m_right = 0;
	window->m_rect.m_bottom = 0;
	window->m_bitmap = mk_win_user_bitmap_get_null();
	window->m_init = mk_lang_true;
	window->m_req_id = 0;
	window->m_response_current = mk_lang_null;
	window->m_line_height = 1;
	window->m_idx = 0;
	window->m_scrollbar_status = 3;
	window->m_scroll = 0;
	err = mk_clib_app_fe_server_ints_rw_construct(&window->m_history_idx); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_ints_rw_construct(&window->m_history_scroll); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_server_responsesmt_rw_construct(&window->m_responses_waiting); mk_lang_check_rereturn(err);
	window->m_server->m_on_response_fun = mk_clib_app_fe_window_on_response;
	window->m_server->m_on_response_ctx = window;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_pump(mk_clib_app_fe_pt const fe) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_user_msg_t msg;
	mk_win_user_base_lresult_t lr;

	mk_lang_assert(fe);

	for(;;)
	{
		b = mk_win_user_msg_w_get(&msg, mk_win_user_base_wnd_get_null(), 0, 0); mk_lang_assert((b != 0 && msg.m_msg != mk_win_user_msg_id_e_quit) || (b == 0 && msg.m_msg == mk_win_user_msg_id_e_quit));
		if(b == 0)
		{
			break;
		}
		b = mk_win_user_msg_translate(&msg); ((mk_lang_types_void_t)(b));
		lr = mk_win_user_msg_w_dispatch(&msg); ((mk_lang_types_void_t)(lr));
	}
	fe->m_exit_code = ((mk_lang_types_sint_t)(msg.m_wparam));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_run_impl_6(mk_clib_app_fe_pt const fe) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);

	err = mk_clib_app_fe_window_display(&fe->m_window, fe); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_pump(fe); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_run_impl_5(mk_clib_app_fe_pt const fe) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(fe);

	err = mk_clib_app_fe_window_construct(&fe->m_window, &fe->m_server); mk_lang_check_rereturn(err);
	err_b = mk_clib_app_fe_run_impl_6(fe);
	err = mk_clib_app_fe_window_destroy(&fe->m_window); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_register(mk_clib_app_fe_pt const fe) mk_lang_noexcept
{
	mk_win_user_class_exw_t cls;
	mk_win_user_base_atom_t atom;

	mk_lang_assert(fe);

	cls.m_len = ((mk_win_base_uint_t)(sizeof(cls)));
	cls.m_style = ((mk_win_base_uint_t)(mk_win_user_class_style_id_e_vredraw | mk_win_user_class_style_id_e_hredraw));
	cls.m_callback = &mk_clib_app_fe_window_raw_on_msg;
	cls.m_extra_cls = ((mk_win_base_sint_t)(0));
	cls.m_extra_wnd = ((mk_win_base_sint_t)(sizeof(mk_clib_app_fe_window_pt)));
	cls.m_instance = fe->m_instance;
	cls.m_icon_big = mk_win_user_icon_w_load(mk_win_base_instance_get_null(), ((mk_win_base_wchar_lpct)(((mk_win_base_uintptr_t)(((mk_win_base_ushort_t)(mk_win_user_icon_id_e_application)))))));
	cls.m_cursor = mk_win_user_cursor_w_load(mk_win_base_instance_get_null(), ((mk_win_base_wchar_lpct)(((mk_win_base_uintptr_t)(((mk_win_base_ushort_t)(mk_win_user_cursor_id_e_arrow)))))));
	cls.m_background = mk_win_user_brush_from_color_id(mk_win_user_base_color_id_e_window);
	cls.m_menu = mk_win_base_null;
	cls.m_name = mk_clib_app_fe_class_name_w;
	cls.m_icon_smol = cls.m_icon_big;
	atom = mk_win_user_class_register_exw(&cls); mk_lang_check_return(atom != 0);
	fe->m_class = atom;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_unregister(mk_clib_app_fe_pt const fe) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_class != 0);

	b = mk_win_user_class_w_unregister(((mk_win_base_wchar_lpct)(((mk_win_base_uintptr_t)(fe->m_class)))), fe->m_instance); mk_lang_check_return(b != 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_run_impl_4(mk_clib_app_fe_pt const fe) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(fe);

	err = mk_clib_app_fe_register(fe); mk_lang_check_rereturn(err);
	err_b = mk_clib_app_fe_run_impl_5(fe);
	err = mk_clib_app_fe_unregister(fe); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_thread_request_stop_and_wait_and_destroy(mk_clib_app_fe_pt const fe) mk_lang_noexcept
{
	mk_clib_app_fe_server_request_pt request;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);

	request = mk_lang_null;
	n = mk_lang_countof(fe->m_threads);
	for(i = 0; i != n; ++i)
	{
		err = mk_clib_app_fe_server_requestsmt_rw_push_back_one(&fe->m_server.m_requests_waiting, &request); mk_lang_check_rereturn(err);
	}
	for(i = 0; i != n; ++i)
	{
		err = mk_lib_mt_thread_join(&fe->m_threads[i]); mk_lang_check_rereturn(err);
		err = mk_lib_mt_thread_destroy(&fe->m_threads[i]); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_run_impl_3(mk_clib_app_fe_pt const fe) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(fe);

	n = mk_lang_countof(fe->m_threads);
	for(i = 0; i != n; ++i)
	{
		err = mk_lib_mt_thread_create(&fe->m_threads[i], &mk_clib_app_fe_server_thread, &fe->m_server); mk_lang_check_rereturn(err);
	}
	err_b = mk_clib_app_fe_run_impl_4(fe);
	err = mk_clib_app_fe_thread_request_stop_and_wait_and_destroy(fe); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_run_impl_2(mk_clib_app_fe_pt const fe) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(fe);

	err = mk_clib_app_fe_server_construct(&fe->m_server); mk_lang_check_rereturn(err);
	err_b = mk_clib_app_fe_run_impl_3(fe);
	err = mk_clib_app_fe_server_destroy(&fe->m_server); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_run_impl_1(mk_clib_app_fe_pt const fe) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(fe);

	err = mk_clib_app_fe_mallocatorg_init(); mk_lang_check_rereturn(err);
	err_b = mk_clib_app_fe_run_impl_2(fe);
	err = mk_clib_app_fe_mallocatorg_deinit(); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fe_run(mk_clib_app_fe_pt const fe, mk_lang_types_bool_t const wide, mk_win_base_instance_t const instance, mk_win_base_instance_t const prev, mk_win_base_wchar_lpct const cmd_line, mk_lang_types_sint_t const show) mk_lang_noexcept
{
	mk_lang_types_uchar_t tuc;
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);
	mk_lang_assert(wide == mk_lang_false || mk_lang_true);
	mk_lang_assert(!mk_win_base_instance_is_null(instance));
	mk_lang_assert(mk_win_base_instance_is_null(prev));
	mk_lang_assert(cmd_line);

	((mk_lang_types_void_t)(prev));
	mk_lang_cpuid_init();
	#if defined NDEBUG
	((mk_lang_types_void_t)(tuc));
	#else
	tuc = 0xff;
	mk_clib_app_fe_memset_uc_fn(((mk_lang_types_uchar_pt)(fe)), &tuc, sizeof(*fe));
	#endif
	fe->m_wide = wide;
	fe->m_instance = instance;
	fe->m_cmd_line = cmd_line;
	fe->m_show = show;
	fe->m_exit_code = 0;
	err = mk_clib_app_fe_run_impl_1(fe); mk_lang_check_rereturn(err);
	return 0;
}


mk_clib_app_fe_t g_mk_clib_app_fe;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_fe_arg(mk_lang_types_bool_t const wide, mk_win_base_instance_t const instance, mk_win_base_instance_t const prev, mk_win_base_wchar_lpct const cmd_line, mk_lang_types_sint_t const show) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_clib_app_fe_run(&g_mk_clib_app_fe, wide, instance, prev, cmd_line, show); mk_lang_check_rereturn(err);
	return g_mk_clib_app_fe.m_exit_code;
}


#if defined mk_lang_nodefaultlib_want && mk_lang_nodefaultlib_want == 1


#include "mk_win_base.h"
#include "mk_win_kernel_process.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_module_t mk_win_base_stdcall GetModuleHandleA(mk_win_base_pchar_lpct const name) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_fe_peb(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(peb);

	err = mk_clib_app_fe_arg(mk_lang_true, mk_win_base_instance_from(GetModuleHandleA(mk_win_base_null).m_data), mk_win_base_instance_get_null(), mk_win_kernel_process_get_command_line(), ((mk_lang_types_sint_t)(mk_win_user_window_show_e_showdefault)));
	return err;
}


#endif
