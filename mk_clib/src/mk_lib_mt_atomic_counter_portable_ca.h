#ifndef mk_include_guard_mk_lib_mt_atomic_counter_portable_ca
#define mk_include_guard_mk_lib_mt_atomic_counter_portable_ca


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#if mk_lang_version_at_least_c_11 && !defined __STDC_NO_ATOMICS__


typedef mk_lang_types_slong_t mk_lib_mt_atomic_counter_portable_ca_int_t;
typedef mk_lib_mt_atomic_counter_portable_ca_int_t const mk_lib_mt_atomic_counter_portable_ca_int_ct;
typedef mk_lib_mt_atomic_counter_portable_ca_int_t* mk_lib_mt_atomic_counter_portable_ca_int_pt;
typedef mk_lib_mt_atomic_counter_portable_ca_int_t const* mk_lib_mt_atomic_counter_portable_ca_int_pct;

struct mk_lib_mt_atomic_counter_portable_ca_s
{
	_Atomic mk_lib_mt_atomic_counter_portable_ca_int_t m_value;
};
typedef struct mk_lib_mt_atomic_counter_portable_ca_s mk_lib_mt_atomic_counter_portable_ca_t;
typedef mk_lib_mt_atomic_counter_portable_ca_t const mk_lib_mt_atomic_counter_portable_ca_ct;
typedef mk_lib_mt_atomic_counter_portable_ca_t* mk_lib_mt_atomic_counter_portable_ca_pt;
typedef mk_lib_mt_atomic_counter_portable_ca_t const* mk_lib_mt_atomic_counter_portable_ca_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_ca_construct(mk_lib_mt_atomic_counter_portable_ca_pt const atomic_counter) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_ca_destruct(mk_lib_mt_atomic_counter_portable_ca_pt const atomic_counter) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_ca_increment(mk_lib_mt_atomic_counter_portable_ca_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_ca_decrement(mk_lib_mt_atomic_counter_portable_ca_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_ca_exchange(mk_lib_mt_atomic_counter_portable_ca_pt const atomic_counter, mk_lib_mt_atomic_counter_portable_ca_int_t const desired, mk_lib_mt_atomic_counter_portable_ca_int_pt const previous) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_atomic_counter_portable_ca.c"
#endif
#endif