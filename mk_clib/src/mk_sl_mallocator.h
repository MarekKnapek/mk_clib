#ifndef mk_include_guard_mk_sl_mallocator_h
#define mk_include_guard_mk_sl_mallocator_h


#define mk_lang_concat_implx(a, b) a ## b
#define mk_lang_concatx(a, b) mk_lang_concat_implx(a, b)


#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_static_param.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#if defined mk_sl_mallocator_constexpr_want
#if (mk_sl_mallocator_constexpr_want) == 0
#define mk_sl_mallocator_constexpr_have 0
#elif (mk_sl_mallocator_constexpr_want) == 1
#define mk_sl_mallocator_constexpr_have 1
#else
#error xxxxxxxxxx
#endif
#else
#define mk_sl_mallocator_constexpr_have 0
#endif


#if mk_sl_mallocator_constexpr_have
#include "mk_sl_mallocator_arena.h"
#define mk_sl_mallocator_base_name mk_sl_mallocator_arena
#elif mk_lang_platform_is_windows_at_least_any
#include "mk_sl_mallocator_windows.h"
#define mk_sl_mallocator_base_name mk_sl_mallocator_windows
#elif mk_lang_version_has_macro_cplusplus
#include "mk_sl_mallocator_lang_cpp.hpp"
#define mk_sl_mallocator_base_name mk_sl_mallocator_lang_cpp
#elif mk_lang_version_at_least_c_23
#include "mk_sl_mallocator_lang_c23.h"
#define mk_sl_mallocator_base_name mk_sl_mallocator_lang_c23
#else
#include "mk_sl_mallocator_lang_c89.h"
#define mk_sl_mallocator_base_name mk_sl_mallocator_lang_c89
#endif

#define mk_sl_mallocator_base_blocks_name mk_lang_concatx(mk_sl_mallocator_base_name, _blocks)
#define mk_sl_mallocator_base_blocks_size_bits_d mk_lang_concatx(mk_sl_mallocator_base_blocks_name, _size_bits_d)

#define mk_sl_mallocator_base_bytes_name mk_lang_concatx(mk_sl_mallocator_base_name, _bytes)
#define mk_sl_mallocator_base_bytes_size_bits_d mk_lang_concatx(mk_sl_mallocator_base_bytes_name, _size_bits_d)


#define mk_sl_cui_t_name mk_sl_mallocator_blocks
#define mk_sl_cui_t_base_type_name mk_sl_mallocator_base_blocks_name
#define mk_sl_cui_t_count 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_sl_mallocator_blocks_size_bits_d mk_sl_mallocator_base_blocks_size_bits_d 

#define mk_sl_cui_t_name mk_sl_mallocator_bytes
#define mk_sl_cui_t_base_type_name mk_sl_mallocator_base_bytes_name
#define mk_sl_cui_t_count 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_sl_mallocator_bytes_size_bits_d mk_sl_mallocator_base_bytes_size_bits_d


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_deinit(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_allocate(mk_lang_types_usize_t const size_bytes, mk_lang_types_void_ppt const mem) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_deallocate(mk_lang_types_void_pt const mem, mk_lang_types_usize_t const size_bytes) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_reallocate(mk_lang_types_void_pt const old_mem, mk_lang_types_usize_t const old_size_bytes, mk_lang_types_usize_t const new_size_bytes, mk_lang_types_void_ppt const new_mem) mk_lang_noexcept;

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_statistics_get_blocks_allocated(mk_sl_mallocator_blocks_pt const blocks_allocated) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_statistics_get_blocks_dealocated(mk_sl_mallocator_blocks_pt const blocks_deallocated) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_statistics_get_blocks_peak(mk_sl_mallocator_blocks_pt const blocks_peak) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_statistics_get_blocks_live(mk_sl_mallocator_blocks_pt const blocks_live) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_statistics_get_bytes_allocated(mk_sl_mallocator_bytes_pt const bytes_allocated) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_statistics_get_bytes_dealocated(mk_sl_mallocator_bytes_pt const bytes_deallocated) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_statistics_get_bytes_peak(mk_sl_mallocator_bytes_pt const bytes_peak) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_statistics_get_bytes_live(mk_sl_mallocator_bytes_pt const bytes_live) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_statistics_get_all(mk_lang_static_param(mk_sl_mallocator_blocks_t, blocks_all, 4), mk_lang_static_param(mk_sl_mallocator_bytes_t, bytes_all, 4)) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_sl_mallocator.c"
#endif
#endif
