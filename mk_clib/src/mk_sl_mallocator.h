#ifndef mk_include_guard_mk_sl_mallocator_h
#define mk_include_guard_mk_sl_mallocator_h


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
typedef mk_sl_mallocator_arena_blocks_t mk_sl_mallocator_blocks_t;
mk_lang_typedef(mk_sl_mallocator_blocks);
typedef mk_sl_mallocator_arena_bytes_t mk_sl_mallocator_bytes_t;
mk_lang_typedef(mk_sl_mallocator_bytes);
#elif mk_lang_platform_is_windows_at_least_any
#include "mk_sl_mallocator_windows.h"
typedef mk_sl_mallocator_windows_blocks_t mk_sl_mallocator_blocks_t;
mk_lang_typedef(mk_sl_mallocator_blocks);
typedef mk_sl_mallocator_windows_bytes_t mk_sl_mallocator_bytes_t;
mk_lang_typedef(mk_sl_mallocator_bytes);
#elif mk_lang_version_has_macro_cplusplus
#include "mk_sl_mallocator_lang_cpp.hpp"
typedef mk_sl_mallocator_lang_cpp_blocks_t mk_sl_mallocator_blocks_t;
mk_lang_typedef(mk_sl_mallocator_blocks);
typedef mk_sl_mallocator_lang_cpp_bytes_t mk_sl_mallocator_bytes_t;
mk_lang_typedef(mk_sl_mallocator_bytes);
#else
#include "mk_sl_mallocator_lang_c.h"
typedef mk_sl_mallocator_lang_c_blocks_t mk_sl_mallocator_blocks_t;
mk_lang_typedef(mk_sl_mallocator_blocks);
typedef mk_sl_mallocator_lang_c_bytes_t mk_sl_mallocator_bytes_t;
mk_lang_typedef(mk_sl_mallocator_bytes);
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_deinit(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_allocate(mk_lang_types_usize_t const size_bytes, mk_lang_types_void_ppt const mem) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_deallocate(mk_lang_types_void_pct const mem, mk_lang_types_usize_t const size_bytes) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_reallocate(mk_lang_types_void_pct const old_mem, mk_lang_types_usize_t const old_size_bytes, mk_lang_types_usize_t const new_size_bytes, mk_lang_types_void_ppt const new_mem) mk_lang_noexcept;

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
