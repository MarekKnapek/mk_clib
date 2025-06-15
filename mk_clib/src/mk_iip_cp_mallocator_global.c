#ifndef mk_include_guard_mk_iip_cp_mallocator_global_c
#define mk_include_guard_mk_iip_cp_mallocator_global_c
#include "mk_iip_cp_mallocator_global.h"

#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_struct.h"
#include "mk_lang_types.h"
#include "mk_sl_mallocator_global.h"
#include "mk_sl_mallocator_global_tracer.h"


#if defined mk_iip_cp_mallocator_global_statistics_want && (mk_iip_cp_mallocator_global_statistics_want) == 1
#define mk_iip_cp_mallocator_global_statistics_have 1
#elif defined mk_iip_cp_mallocator_global_statistics_want && (mk_iip_cp_mallocator_global_statistics_want) == 0
#define mk_iip_cp_mallocator_global_statistics_have 0
#elif !defined mk_iip_cp_mallocator_global_statistics_want
#if defined NDEBUG
#define mk_iip_cp_mallocator_global_statistics_have 0
#else
#define mk_iip_cp_mallocator_global_statistics_have 1
#endif
#else
#error xxxxxxxxxx
#endif

#if defined mk_iip_cp_mallocator_global_report_want && (mk_iip_cp_mallocator_global_report_want) == 1
#define mk_iip_cp_mallocator_global_report_have 1
#elif defined mk_iip_cp_mallocator_global_report_want && (mk_iip_cp_mallocator_global_report_want) == 0
#define mk_iip_cp_mallocator_global_report_have 0
#elif !defined mk_iip_cp_mallocator_global_report_want
#if defined NDEBUG
#define mk_iip_cp_mallocator_global_report_have 0
#else
#define mk_iip_cp_mallocator_global_report_have 1
#endif
#else
#error xxxxxxxxxx
#endif

#if defined mk_iip_cp_mallocator_global_tracer_want && (mk_iip_cp_mallocator_global_tracer_want) == 1
#define mk_iip_cp_mallocator_global_tracer_have 1
#elif defined mk_iip_cp_mallocator_global_tracer_want && (mk_iip_cp_mallocator_global_tracer_want) == 0
#define mk_iip_cp_mallocator_global_tracer_have 0
#elif !defined mk_iip_cp_mallocator_global_tracer_want
#if defined NDEBUG
#define mk_iip_cp_mallocator_global_tracer_have 0
#else
#define mk_iip_cp_mallocator_global_tracer_have 1
#endif
#else
#error xxxxxxxxxx
#endif


#if mk_iip_cp_mallocator_global_tracer_have
#define mk_iip_cp_mallocator_global_impl_base mk_lang_concat(mk_lang_concat(mk_sl_mallocator_global_tracer_, mk_iip_cp_mallocator_global_statistics_have), mk_iip_cp_mallocator_global_report_have)
#else
#define mk_iip_cp_mallocator_global_impl_base mk_lang_concat(mk_lang_concat(mk_sl_mallocator_global_, mk_iip_cp_mallocator_global_statistics_have), mk_iip_cp_mallocator_global_report_have)
#endif

#define mk_iip_cp_mallocator_global_impl_init       mk_lang_concat(mk_iip_cp_mallocator_global_impl_base, _init)
#define mk_iip_cp_mallocator_global_impl_deinit     mk_lang_concat(mk_iip_cp_mallocator_global_impl_base, _deinit)
#define mk_iip_cp_mallocator_global_impl_allocate   mk_lang_concat(mk_iip_cp_mallocator_global_impl_base, _allocate)
#define mk_iip_cp_mallocator_global_impl_deallocate mk_lang_concat(mk_iip_cp_mallocator_global_impl_base, _deallocate)
#define mk_iip_cp_mallocator_global_impl_reallocate mk_lang_concat(mk_iip_cp_mallocator_global_impl_base, _reallocate)

#define mk_iip_cp_mallocator_global_impl_statistics_get_bytes_allocated    mk_lang_concat(mk_iip_cp_mallocator_global_impl_base, _statistics_get_bytes_allocated)
#define mk_iip_cp_mallocator_global_impl_statistics_get_bytes_deallocated  mk_lang_concat(mk_iip_cp_mallocator_global_impl_base, _statistics_get_bytes_deallocated)
#define mk_iip_cp_mallocator_global_impl_statistics_get_bytes_peak         mk_lang_concat(mk_iip_cp_mallocator_global_impl_base, _statistics_get_bytes_peak)
#define mk_iip_cp_mallocator_global_impl_statistics_get_bytes_live         mk_lang_concat(mk_iip_cp_mallocator_global_impl_base, _statistics_get_bytes_live)
#define mk_iip_cp_mallocator_global_impl_statistics_get_blocks_allocated   mk_lang_concat(mk_iip_cp_mallocator_global_impl_base, _statistics_get_blocks_allocated)
#define mk_iip_cp_mallocator_global_impl_statistics_get_blocks_deallocated mk_lang_concat(mk_iip_cp_mallocator_global_impl_base, _statistics_get_blocks_deallocated)
#define mk_iip_cp_mallocator_global_impl_statistics_get_blocks_peak        mk_lang_concat(mk_iip_cp_mallocator_global_impl_base, _statistics_get_blocks_peak)
#define mk_iip_cp_mallocator_global_impl_statistics_get_blocks_live        mk_lang_concat(mk_iip_cp_mallocator_global_impl_base, _statistics_get_blocks_live)
#define mk_iip_cp_mallocator_global_impl_statistics_get_all                mk_lang_concat(mk_iip_cp_mallocator_global_impl_base, _statistics_get_all)


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_mallocator_global_init(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_iip_cp_mallocator_global_impl_init();
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_mallocator_global_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_iip_cp_mallocator_global_impl_deinit();
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_mallocator_global_allocate(mk_lang_types_usize_t const size, mk_lang_types_void_ppt const mem) mk_lang_noexcept
{
	return mk_iip_cp_mallocator_global_impl_allocate(size, mem);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_mallocator_global_deallocate(mk_lang_types_void_pct const mem, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	return mk_iip_cp_mallocator_global_impl_deallocate(mem, size);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_mallocator_global_reallocate(mk_lang_types_void_pct const old_mem, mk_lang_types_usize_t const old_size, mk_lang_types_usize_t const new_size, mk_lang_types_void_ppt const new_mem) mk_lang_noexcept
{
	return mk_iip_cp_mallocator_global_impl_reallocate(old_mem, old_size, new_size, new_mem);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_mallocator_global_statistics_get_bytes_allocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	return mk_iip_cp_mallocator_global_impl_statistics_get_bytes_allocated(cnt);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_mallocator_global_statistics_get_bytes_deallocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	return mk_iip_cp_mallocator_global_impl_statistics_get_bytes_deallocated(cnt);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_mallocator_global_statistics_get_bytes_peak(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	return mk_iip_cp_mallocator_global_impl_statistics_get_bytes_peak(cnt);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_mallocator_global_statistics_get_bytes_live(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	return mk_iip_cp_mallocator_global_impl_statistics_get_bytes_live(cnt);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_mallocator_global_statistics_get_blocks_allocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	return mk_iip_cp_mallocator_global_impl_statistics_get_blocks_allocated(cnt);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_mallocator_global_statistics_get_blocks_deallocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	return mk_iip_cp_mallocator_global_impl_statistics_get_blocks_deallocated(cnt);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_mallocator_global_statistics_get_blocks_peak(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	return mk_iip_cp_mallocator_global_impl_statistics_get_blocks_peak(cnt);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_mallocator_global_statistics_get_blocks_live(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	return mk_iip_cp_mallocator_global_impl_statistics_get_blocks_live(cnt);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_mallocator_global_statistics_get_all(mk_lang_static_param(mk_sl_cui_uint128_t, cnts, 8)) mk_lang_noexcept
{
	return mk_iip_cp_mallocator_global_impl_statistics_get_all(cnts);
}


#endif
