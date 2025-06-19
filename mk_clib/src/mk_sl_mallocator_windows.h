#ifndef mk_include_guard_mk_sl_mallocator_windows_h
#define mk_include_guard_mk_sl_mallocator_windows_h


#include "mk_lang_jumbo.h"
#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any


#include "mk_lang_bui.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


#define mk_sl_cui_t_name mk_sl_mallocator_windows_blocks
#define mk_sl_cui_t_base mk_lang_bui_usize
#define mk_sl_cui_t_count 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_sl_mallocator_windows_blocks_size_bits_d mk_lang_bui_usize_size_bits_d

#define mk_sl_cui_t_name mk_sl_mallocator_windows_bytes
#define mk_sl_cui_t_base mk_lang_bui_usize
#define mk_sl_cui_t_count 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_sl_mallocator_windows_bytes_size_bits_d mk_lang_bui_usize_size_bits_d


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_windows_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_windows_deinit(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_windows_allocate(mk_lang_types_usize_t const size_bytes, mk_lang_types_void_ppt const mem) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_windows_deallocate(mk_lang_types_void_pct const mem, mk_lang_types_usize_t const size_bytes) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_windows_reallocate(mk_lang_types_void_pct const old_mem, mk_lang_types_usize_t const old_size_bytes, mk_lang_types_usize_t const new_size_bytes, mk_lang_types_void_ppt const new_mem) mk_lang_noexcept;

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_windows_statistics_get_blocks_allocated(mk_sl_mallocator_windows_blocks_pt const blocks_allocated) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_windows_statistics_get_blocks_dealocated(mk_sl_mallocator_windows_blocks_pt const blocks_deallocated) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_windows_statistics_get_blocks_peak(mk_sl_mallocator_windows_blocks_pt const blocks_peak) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_windows_statistics_get_blocks_live(mk_sl_mallocator_windows_blocks_pt const blocks_live) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_windows_statistics_get_bytes_allocated(mk_sl_mallocator_windows_bytes_pt const bytes_allocated) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_windows_statistics_get_bytes_dealocated(mk_sl_mallocator_windows_bytes_pt const bytes_deallocated) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_windows_statistics_get_bytes_peak(mk_sl_mallocator_windows_bytes_pt const bytes_peak) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_windows_statistics_get_bytes_live(mk_sl_mallocator_windows_bytes_pt const bytes_live) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_windows_statistics_get_all(mk_lang_static_param(mk_sl_mallocator_windows_blocks_t, blocks_all, 4), mk_lang_static_param(mk_sl_mallocator_windows_bytes_t, bytes_all, 4)) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_sl_mallocator_windows.c"
#endif
#endif
