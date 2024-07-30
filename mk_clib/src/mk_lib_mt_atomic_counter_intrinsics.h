#ifndef mk_include_guard_mk_lib_mt_atomic_counter_intrinsics
#define mk_include_guard_mk_lib_mt_atomic_counter_intrinsics


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


typedef mk_win_base_slong_t mk_lib_mt_atomic_counter_intrinsics_int_t;
typedef mk_lib_mt_atomic_counter_intrinsics_int_t const mk_lib_mt_atomic_counter_intrinsics_int_ct;
typedef mk_lib_mt_atomic_counter_intrinsics_int_t* mk_lib_mt_atomic_counter_intrinsics_int_pt;
typedef mk_lib_mt_atomic_counter_intrinsics_int_t const* mk_lib_mt_atomic_counter_intrinsics_int_pct;

struct mk_lib_mt_atomic_counter_intrinsics_s
{
	mk_lib_mt_atomic_counter_intrinsics_int_t m_value;
};
typedef struct mk_lib_mt_atomic_counter_intrinsics_s mk_lib_mt_atomic_counter_intrinsics_t;
typedef mk_lib_mt_atomic_counter_intrinsics_t const mk_lib_mt_atomic_counter_intrinsics_ct;
typedef mk_lib_mt_atomic_counter_intrinsics_t* mk_lib_mt_atomic_counter_intrinsics_pt;
typedef mk_lib_mt_atomic_counter_intrinsics_t const* mk_lib_mt_atomic_counter_intrinsics_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_intrinsics_construct(mk_lib_mt_atomic_counter_intrinsics_pt const atomic_counter) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_intrinsics_destruct(mk_lib_mt_atomic_counter_intrinsics_pt const atomic_counter) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_intrinsics_increment(mk_lib_mt_atomic_counter_intrinsics_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_intrinsics_decrement(mk_lib_mt_atomic_counter_intrinsics_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_intrinsics_exchange(mk_lib_mt_atomic_counter_intrinsics_pt const atomic_counter, mk_lib_mt_atomic_counter_intrinsics_int_t const desired, mk_lib_mt_atomic_counter_intrinsics_int_pt const previous) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_atomic_counter_intrinsics.c"
#endif
#endif
