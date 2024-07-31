#ifndef mk_include_guard_mk_lib_mt_atomic_counter
#define mk_include_guard_mk_lib_mt_atomic_counter


#include "mk_lang_bitness.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
#include "mk_lib_mt_atomic_counter_portable_cpp.hpp"
typedef mk_lib_mt_atomic_counter_portable_cpp_int_t mk_lib_mt_atomic_counter_impl_int_t;
typedef mk_lib_mt_atomic_counter_portable_cpp_t mk_lib_mt_atomic_counter_impl_t;
#elif mk_lang_version_at_least_c_11 && !defined __STDC_NO_ATOMICS__
#include "mk_lib_mt_atomic_counter_portable_ca.h"
typedef mk_lib_mt_atomic_counter_portable_ca_int_t mk_lib_mt_atomic_counter_impl_int_t;
typedef mk_lib_mt_atomic_counter_portable_ca_t mk_lib_mt_atomic_counter_impl_t;
#elif mk_lang_version_at_least_c_11 && !defined __STDC_NO_THREADS__
#include "mk_lib_mt_atomic_counter_portable_cb.h"
typedef mk_lib_mt_atomic_counter_portable_cb_int_t mk_lib_mt_atomic_counter_impl_int_t;
typedef mk_lib_mt_atomic_counter_portable_cb_t mk_lib_mt_atomic_counter_impl_t;
#elif mk_lang_bitness == mk_lang_bitness_32 && (mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows_51 || mk_lang_platform == mk_lang_platform_windows)
#include "mk_lib_mt_atomic_counter_windows.h"
typedef mk_lib_mt_atomic_counter_windows_int_t mk_lib_mt_atomic_counter_impl_int_t;
typedef mk_lib_mt_atomic_counter_windows_t mk_lib_mt_atomic_counter_impl_t;
#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2003
#include "mk_lib_mt_atomic_counter_intrinsics.h"
typedef mk_lib_mt_atomic_counter_intrinsics_int_t mk_lib_mt_atomic_counter_impl_int_t;
typedef mk_lib_mt_atomic_counter_intrinsics_t mk_lib_mt_atomic_counter_impl_t;
#elif defined __TINYC__ && __TINYC__ >= 928 /* todo version */
#include "mk_lib_mt_atomic_counter_tcc.h"
typedef mk_lib_mt_atomic_counter_tcc_int_t mk_lib_mt_atomic_counter_impl_int_t;
typedef mk_lib_mt_atomic_counter_tcc_t mk_lib_mt_atomic_counter_impl_t;
#else
#error xxxxxxxxxx
#endif


typedef mk_lib_mt_atomic_counter_impl_int_t mk_lib_mt_atomic_counter_int_t;
typedef mk_lib_mt_atomic_counter_int_t const mk_lib_mt_atomic_counter_int_ct;
typedef mk_lib_mt_atomic_counter_int_t* mk_lib_mt_atomic_counter_int_pt;
typedef mk_lib_mt_atomic_counter_int_t const* mk_lib_mt_atomic_counter_int_pct;

struct mk_lib_mt_atomic_counter_s
{
	mk_lib_mt_atomic_counter_impl_t m_value;
};
typedef struct mk_lib_mt_atomic_counter_s mk_lib_mt_atomic_counter_t;
typedef mk_lib_mt_atomic_counter_t const mk_lib_mt_atomic_counter_ct;
typedef mk_lib_mt_atomic_counter_t* mk_lib_mt_atomic_counter_pt;
typedef mk_lib_mt_atomic_counter_t const* mk_lib_mt_atomic_counter_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_construct(mk_lib_mt_atomic_counter_pt const atomic_counter) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_destruct(mk_lib_mt_atomic_counter_pt const atomic_counter) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_increment(mk_lib_mt_atomic_counter_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_decrement(mk_lib_mt_atomic_counter_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_exchange(mk_lib_mt_atomic_counter_pt const atomic_counter, mk_lib_mt_atomic_counter_int_t const desired, mk_lib_mt_atomic_counter_int_pt const previous) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_atomic_counter.c"
#endif
#endif
