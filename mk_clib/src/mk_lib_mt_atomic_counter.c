#include "mk_lib_mt_atomic_counter.h"

#include "mk_lang_assert.h"
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
#define mk_lib_mt_atomic_counter_impl_construct mk_lib_mt_atomic_counter_portable_cpp_construct
#define mk_lib_mt_atomic_counter_impl_destruct mk_lib_mt_atomic_counter_portable_cpp_destruct
#define mk_lib_mt_atomic_counter_impl_increment mk_lib_mt_atomic_counter_portable_cpp_increment
#define mk_lib_mt_atomic_counter_impl_decrement mk_lib_mt_atomic_counter_portable_cpp_decrement
#define mk_lib_mt_atomic_counter_impl_exchange mk_lib_mt_atomic_counter_portable_cpp_exchange
#elif mk_lang_version_at_least_c_11 && !defined __STDC_NO_ATOMICS__
#include "mk_lib_mt_atomic_counter_portable_ca.h"
#define mk_lib_mt_atomic_counter_impl_construct mk_lib_mt_atomic_counter_portable_ca_construct
#define mk_lib_mt_atomic_counter_impl_destruct mk_lib_mt_atomic_counter_portable_ca_destruct
#define mk_lib_mt_atomic_counter_impl_increment mk_lib_mt_atomic_counter_portable_ca_increment
#define mk_lib_mt_atomic_counter_impl_decrement mk_lib_mt_atomic_counter_portable_ca_decrement
#define mk_lib_mt_atomic_counter_impl_exchange mk_lib_mt_atomic_counter_portable_ca_exchange
#elif mk_lang_version_at_least_c_11 && !defined __STDC_NO_THREADS__
#include "mk_lib_mt_atomic_counter_portable_cb.h"
#define mk_lib_mt_atomic_counter_impl_construct mk_lib_mt_atomic_counter_portable_cb_construct
#define mk_lib_mt_atomic_counter_impl_destruct mk_lib_mt_atomic_counter_portable_cb_destruct
#define mk_lib_mt_atomic_counter_impl_increment mk_lib_mt_atomic_counter_portable_cb_increment
#define mk_lib_mt_atomic_counter_impl_decrement mk_lib_mt_atomic_counter_portable_cb_decrement
#define mk_lib_mt_atomic_counter_impl_exchange mk_lib_mt_atomic_counter_portable_cb_exchange
#elif mk_lang_bitness == mk_lang_bitness_32 && (mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows_51 || mk_lang_platform == mk_lang_platform_windows)
#include "mk_lib_mt_atomic_counter_windows.h"
#define mk_lib_mt_atomic_counter_impl_construct mk_lib_mt_atomic_counter_windows_construct
#define mk_lib_mt_atomic_counter_impl_destruct mk_lib_mt_atomic_counter_windows_destruct
#define mk_lib_mt_atomic_counter_impl_increment mk_lib_mt_atomic_counter_windows_increment
#define mk_lib_mt_atomic_counter_impl_decrement mk_lib_mt_atomic_counter_windows_decrement
#define mk_lib_mt_atomic_counter_impl_exchange mk_lib_mt_atomic_counter_windows_exchange
#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2003
#include "mk_lib_mt_atomic_counter_intrinsics.h"
#define mk_lib_mt_atomic_counter_impl_construct mk_lib_mt_atomic_counter_intrinsics_construct
#define mk_lib_mt_atomic_counter_impl_destruct mk_lib_mt_atomic_counter_intrinsics_destruct
#define mk_lib_mt_atomic_counter_impl_increment mk_lib_mt_atomic_counter_intrinsics_increment
#define mk_lib_mt_atomic_counter_impl_decrement mk_lib_mt_atomic_counter_intrinsics_decrement
#define mk_lib_mt_atomic_counter_impl_exchange mk_lib_mt_atomic_counter_intrinsics_exchange
#elif defined __TINYC__ && __TINYC__ >= 928 /* todo version */
#include "mk_lib_mt_atomic_counter_tcc.h"
#define mk_lib_mt_atomic_counter_impl_construct mk_lib_mt_atomic_counter_tcc_construct
#define mk_lib_mt_atomic_counter_impl_destruct mk_lib_mt_atomic_counter_tcc_destruct
#define mk_lib_mt_atomic_counter_impl_increment mk_lib_mt_atomic_counter_tcc_increment
#define mk_lib_mt_atomic_counter_impl_decrement mk_lib_mt_atomic_counter_tcc_decrement
#define mk_lib_mt_atomic_counter_impl_exchange mk_lib_mt_atomic_counter_tcc_exchange
#else
#error xxxxxxxxxx
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_construct(mk_lib_mt_atomic_counter_pt const atomic_counter) mk_lang_noexcept
{
	return mk_lib_mt_atomic_counter_impl_construct(&atomic_counter->m_value);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_destruct(mk_lib_mt_atomic_counter_pt const atomic_counter) mk_lang_noexcept
{
	return mk_lib_mt_atomic_counter_impl_destruct(&atomic_counter->m_value);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_increment(mk_lib_mt_atomic_counter_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	return mk_lib_mt_atomic_counter_impl_increment(&atomic_counter->m_value, cmp);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_decrement(mk_lib_mt_atomic_counter_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	return mk_lib_mt_atomic_counter_impl_decrement(&atomic_counter->m_value, cmp);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_exchange(mk_lib_mt_atomic_counter_pt const atomic_counter, mk_lib_mt_atomic_counter_int_t const desired, mk_lib_mt_atomic_counter_int_pt const previous) mk_lang_noexcept
{
	return mk_lib_mt_atomic_counter_impl_exchange(&atomic_counter->m_value, desired, previous);
}
