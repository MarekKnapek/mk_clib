#ifndef mk_include_guard_mk_sl_mallocatorg_portablec
#define mk_include_guard_mk_sl_mallocatorg_portablec


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint128.h"


#if defined mk_sl_mallocatorg_portablec_statistics_want && (mk_sl_mallocatorg_portablec_statistics_want) == 1
#define mk_sl_mallocatorg_portablec_statistics_have 1
#elif defined mk_sl_mallocatorg_portablec_statistics_want && (mk_sl_mallocatorg_portablec_statistics_want) == 0
#define mk_sl_mallocatorg_portablec_statistics_have 0
#elif !defined mk_sl_mallocatorg_portablec_statistics_have
#if defined NDEBUG
#define mk_sl_mallocatorg_portablec_statistics_have 0
#else
#define mk_sl_mallocatorg_portablec_statistics_have 1
#endif
#else
#error xxxxxxxxxx
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablec_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablec_deinit(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablec_allocate(mk_lang_types_usize_t const size, mk_lang_types_void_ppt const mem) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablec_deallocate(mk_lang_types_void_pct const mem, mk_lang_types_usize_t const size) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablec_reallocate(mk_lang_types_void_pct const old_mem, mk_lang_types_usize_t const old_size, mk_lang_types_usize_t const new_size, mk_lang_types_void_ppt const new_mem) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablec_statistics_get_bytes_allocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablec_statistics_get_bytes_deallocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablec_statistics_get_bytes_live(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablec_statistics_get_bytes_peak(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablec_statistics_get_blocks_allocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablec_statistics_get_blocks_deallocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablec_statistics_get_blocks_live(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablec_statistics_get_blocks_peak(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_mallocatorg_portablec.c"
#endif
#endif
