#ifndef mk_include_guard_mk_win_sl_copier
#define mk_include_guard_mk_win_sl_copier


#include "mk_lang_exception.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_types.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_files.h"
#include "mk_win_tstring.h"

/*#define mk_lang_bui_name mk_win_sl_copier
#define mk_lang_bui_type mk_lang_types_uint_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_uint_t
#include "mk_lang_bui_inl_fileh.h"
#undef mk_lang_bui_name
#undef mk_lang_bui_type
#undef mk_lang_bui_sizeof

#define mk_sl_speed_counter_t_name mk_win_sl_copier
#define mk_sl_speed_counter_t_item_prefix mk_lang_bui_mk_win_sl_copier
#define mk_sl_speed_counter_t_time_prefix mk_lang_bui_mk_win_sl_copier
#define mk_sl_speed_counter_t_time_denominator 1000
#define mk_sl_speed_counter_t_time_granule_size 500
#define mk_sl_speed_counter_t_time_granule_count 4
#include "mk_sl_speed_counter_inl_fileh.h"
#undef mk_sl_speed_counter_t_name
#undef mk_sl_speed_counter_t_item_prefix
#undef mk_sl_speed_counter_t_time_prefix
#undef mk_sl_speed_counter_t_time_denominator
#undef mk_sl_speed_counter_t_time_granule_size
#undef mk_sl_speed_counter_t_time_granule_count*/


struct mk_win_sl_copier_overlapped2_s
{
	mk_win_kernel_files_overlapped_t m_overlapped;
	mk_win_base_dword_t m_submitted;
};
typedef struct mk_win_sl_copier_overlapped2_s mk_win_sl_copier_overlapped2_t;
typedef mk_win_sl_copier_overlapped2_t const mk_win_sl_copier_overlapped2_ct;
typedef mk_win_sl_copier_overlapped2_t* mk_win_sl_copier_overlapped2_pt;
typedef mk_win_sl_copier_overlapped2_t const* mk_win_sl_copier_overlapped2_pct;
typedef mk_win_sl_copier_overlapped2_t mk_win_base_far* mk_win_sl_copier_overlapped2_lpt;
typedef mk_win_sl_copier_overlapped2_t mk_win_base_far const* mk_win_sl_copier_overlapped2_lpct;
typedef mk_win_sl_copier_overlapped2_t mk_win_base_near* mk_win_sl_copier_overlapped2_npt;
typedef mk_win_sl_copier_overlapped2_t mk_win_base_near const* mk_win_sl_copier_overlapped2_npct;

struct mk_win_sl_copier_s
{
	int m_state;
	mk_win_tstring_tchar_lpt m_src_path;
	mk_win_base_size_t m_src_path_len;
	mk_win_tstring_tchar_lpt m_dst_path;
	mk_win_base_size_t m_dst_path_len;
	mk_win_base_handle_t m_src_handle;
	mk_win_kernel_files_file_type_t m_src_file_type;
	mk_win_base_dword_t m_src_cluster;
	mk_win_base_dword_t m_src_size_lo;
	mk_win_base_dword_t m_src_size_hi;
	mk_win_base_handle_t m_dst_handle;
	mk_win_kernel_files_file_type_t m_dst_file_type;
	mk_win_base_dword_t m_dst_cluster;
	mk_win_base_void_lpt m_buffers;
	mk_lang_types_bool_t m_active_buffer;
	mk_lang_types_bool_t m_at_end;
	unsigned m_buffer_parts;
	mk_win_sl_copier_overlapped2_t m_overlapped_a;
	mk_win_sl_copier_overlapped2_t m_overlapped_b;
	mk_win_sl_copier_overlapped2_t m_overlapped_c;
};
typedef struct mk_win_sl_copier_s mk_win_sl_copier_t;
typedef mk_win_sl_copier_t const mk_win_sl_copier_ct;
typedef mk_win_sl_copier_t* mk_win_sl_copier_pt;
typedef mk_win_sl_copier_t const* mk_win_sl_copier_pct;
typedef mk_win_sl_copier_t mk_win_base_far* mk_win_sl_copier_lpt;
typedef mk_win_sl_copier_t mk_win_base_far const* mk_win_sl_copier_lpct;
typedef mk_win_sl_copier_t mk_win_base_near* mk_win_sl_copier_npt;
typedef mk_win_sl_copier_t mk_win_base_near const* mk_win_sl_copier_npct;


mk_lang_jumbo void mk_win_sl_copier_construct(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex, mk_win_tstring_tchar_pct const src_file_name, mk_win_tstring_tchar_pct const dst_file_name) mk_lang_noexcept;
mk_lang_jumbo void mk_win_sl_copier_destroy(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_win_sl_copier_make_step(mk_win_sl_copier_pt const copier, mk_lang_exception_pt const ex) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_sl_copier.c"
#endif
#endif
