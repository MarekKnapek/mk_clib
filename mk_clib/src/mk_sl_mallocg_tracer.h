#ifndef mk_include_guard_mk_sl_mallocg_tracer
#define mk_include_guard_mk_sl_mallocg_tracer


#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint128.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_deinit(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_allocate_impl(mk_lang_types_pchar_pct const file_buf, mk_lang_types_sint_t const file_len, mk_lang_types_sint_t const line, mk_lang_types_pchar_pct const func_buf, mk_lang_types_sint_t const func_len, mk_lang_types_usize_t const size, mk_lang_types_void_ppt const mem) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_deallocate(mk_lang_types_void_pct const mem, mk_lang_types_usize_t const size) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_reallocate_impl(mk_lang_types_pchar_pct const file_buf, mk_lang_types_sint_t const file_len, mk_lang_types_sint_t const line, mk_lang_types_pchar_pct const func_buf, mk_lang_types_sint_t const func_len, mk_lang_types_void_pt const old_mem, mk_lang_types_usize_t const old_size, mk_lang_types_usize_t const new_size, mk_lang_types_void_ppt const new_mem) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_statistics_get_bytes_allocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_statistics_get_bytes_deallocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_statistics_get_bytes_live(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_statistics_get_bytes_peak(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_statistics_get_blocks_allocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_statistics_get_blocks_deallocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_statistics_get_blocks_live(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_statistics_get_blocks_peak(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept;


#define mk_sl_mallocg_tracer_allocate(size, mem) mk_sl_mallocg_tracer_allocate_impl(&__FILE__[0], mk_lang_countstr(__FILE__), ((mk_lang_types_sint_t)(__LINE__)), &__func__[0], mk_lang_countstr(__func__), (size), (mem))
#define mk_sl_mallocg_tracer_reallocate(old_mem, old_size, new_size, new_mem) mk_sl_mallocg_tracer_reallocate_impl(&__FILE__[0], mk_lang_countstr(__FILE__), ((mk_lang_types_sint_t)(__LINE__)), &__func__[0], mk_lang_countstr(__func__), (old_mem), (old_size), (new_size), (new_mem))


#if mk_lang_jumbo_want == 1
#include "mk_sl_mallocg_tracer.c"
#endif
#endif
