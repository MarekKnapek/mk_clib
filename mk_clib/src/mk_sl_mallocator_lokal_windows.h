#ifndef mk_include_guard_mk_sl_mallocator_lokal_windows_h
#define mk_include_guard_mk_sl_mallocator_lokal_windows_h


#include "mk_lang_jumbo.h"
#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any


#if defined mk_sl_mallocator_lokal_windows_statistics_want
#if (mk_sl_mallocator_lokal_windows_statistics_want) == 0
#define mk_sl_mallocator_lokal_windows_statistics_have 0
#elif (mk_sl_mallocator_lokal_windows_statistics_want) == 1
#define mk_sl_mallocator_lokal_windows_statistics_have 1
#else
#error xxxxxxxxxx
#endif
#else
#if defined DEBUG || defined _DEBUG
#define mk_sl_mallocator_lokal_windows_statistics_have 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_sl_mallocator_lokal_windows_statistics_have 0
#else
#define mk_sl_mallocator_lokal_windows_statistics_have 1
#endif
#endif
#endif


#include "mk_lang_bui.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_dll_kernel_heap.h"


#define mk_sl_cui_t_name mk_sl_mallocator_lokal_windows_num_blocks
#define mk_sl_cui_t_base_type_name mk_lang_bui_usize
#define mk_sl_cui_t_count 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_sl_mallocator_lokal_windows_num_bytes
#define mk_sl_cui_t_base_type_name mk_lang_bui_usize
#define mk_sl_cui_t_count 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"


struct mk_sl_mallocator_lokal_windows_statistics_s
{
	mk_sl_mallocator_lokal_windows_num_blocks_t m_blocks_allocated;
	mk_sl_mallocator_lokal_windows_num_blocks_t m_blocks_deallocated;
	mk_sl_mallocator_lokal_windows_num_blocks_t m_blocks_peak;
	mk_sl_mallocator_lokal_windows_num_bytes_t m_bytes_allocated;
	mk_sl_mallocator_lokal_windows_num_bytes_t m_bytes_deallocated;
	mk_sl_mallocator_lokal_windows_num_bytes_t m_bytes_peak;
};
typedef struct mk_sl_mallocator_lokal_windows_statistics_s mk_sl_mallocator_lokal_windows_statistics_t;
mk_lang_typedef(mk_sl_mallocator_lokal_windows_statistics);


struct mk_sl_mallocator_lokal_windows_s
{
	#if mk_sl_mallocator_lokal_windows_statistics_have
	mk_sl_mallocator_lokal_windows_statistics_t m_statistics;
	#endif
	mk_win_dll_kernel_heap_t m_heap;
};
typedef struct mk_sl_mallocator_lokal_windows_s mk_sl_mallocator_lokal_windows_t;
mk_lang_typedef(mk_sl_mallocator_lokal_windows);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_lokal_windows_init(mk_sl_mallocator_lokal_windows_pt const win) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_lokal_windows_deinit(mk_sl_mallocator_lokal_windows_pt const win) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_lokal_windows_allocate(mk_sl_mallocator_lokal_windows_pt const win, mk_lang_types_usize_t const size_bytes, mk_lang_types_void_ppt const mem) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_lokal_windows_deallocate(mk_sl_mallocator_lokal_windows_pt const win, mk_lang_types_void_pt const mem, mk_lang_types_usize_t const size_bytes) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_lokal_windows_reallocate(mk_sl_mallocator_lokal_windows_pt const win, mk_lang_types_void_pt const old_mem, mk_lang_types_usize_t const old_size_bytes, mk_lang_types_usize_t const new_size_bytes, mk_lang_types_void_ppt const new_mem) mk_lang_noexcept;

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_get_blocks_allocated(mk_sl_mallocator_lokal_windows_pt const win, mk_sl_mallocator_lokal_windows_num_blocks_pt const blocks_allocated) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_get_blocks_dealocated(mk_sl_mallocator_lokal_windows_pt const win, mk_sl_mallocator_lokal_windows_num_blocks_pt const blocks_deallocated) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_get_blocks_peak(mk_sl_mallocator_lokal_windows_pt const win, mk_sl_mallocator_lokal_windows_num_blocks_pt const blocks_peak) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_get_blocks_live(mk_sl_mallocator_lokal_windows_pt const win, mk_sl_mallocator_lokal_windows_num_blocks_pt const blocks_live) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_get_bytes_allocated(mk_sl_mallocator_lokal_windows_pt const win, mk_sl_mallocator_lokal_windows_num_bytes_pt const bytes_allocated) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_get_bytes_dealocated(mk_sl_mallocator_lokal_windows_pt const win, mk_sl_mallocator_lokal_windows_num_bytes_pt const bytes_deallocated) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_get_bytes_peak(mk_sl_mallocator_lokal_windows_pt const win, mk_sl_mallocator_lokal_windows_num_bytes_pt const bytes_peak) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_get_bytes_live(mk_sl_mallocator_lokal_windows_pt const win, mk_sl_mallocator_lokal_windows_num_bytes_pt const bytes_live) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_lokal_windows_statistics_get_all(mk_sl_mallocator_lokal_windows_pt const win, mk_lang_static_param(mk_sl_mallocator_lokal_windows_num_blocks_t, blocks_all, 4), mk_lang_static_param(mk_sl_mallocator_lokal_windows_num_bytes_t, bytes_all, 4)) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_sl_mallocator_lokal_windows.c"
#endif
#endif
