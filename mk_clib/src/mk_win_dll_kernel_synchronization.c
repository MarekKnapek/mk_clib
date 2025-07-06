#ifndef mk_include_guard_mk_win_dll_kernel_synchronization_c
#define mk_include_guard_mk_win_dll_kernel_synchronization_c
#include "mk_win_dll_kernel_synchronization.h"

#include "mk_lang_assert.h"
#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"

#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2003
#include <intrin.h>
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_InterlockedExchange)
#pragma intrinsic(_InterlockedCompareExchange)
#endif


#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2003
#define InterlockedIncrement _InterlockedIncrement
#define InterlockedDecrement _InterlockedDecrement
#define InterlockedExchange _InterlockedExchange
#define InterlockedCompareExchange _InterlockedCompareExchange
#else
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_slong_t mk_win_base_stdcall InterlockedIncrement(mk_win_base_slong_lpt const addend) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_slong_t mk_win_base_stdcall InterlockedDecrement(mk_win_base_slong_lpt const addend) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_slong_t mk_win_base_stdcall InterlockedExchange(mk_win_base_slong_lpt const target, mk_win_base_slong_t const value) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_slong_t mk_win_base_stdcall InterlockedCompareExchange(mk_win_base_slong_lpt const target, mk_win_base_slong_t const exchange, mk_win_base_slong_t const comparand) mk_lang_noexcept;
#endif


mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall WaitForSingleObject(mk_win_base_handle_t const object, mk_win_base_dword_t const timeout) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SetEvent(mk_win_base_handle_t const object) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_dll_kernel_synchronization_wait_one(mk_win_base_handle_t const object, mk_win_base_dword_t const timeout) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	mk_lang_assert(object.m_data);

	ret = WaitForSingleObject(object, timeout);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_synchronization_set_event(mk_win_base_handle_t const object) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = SetEvent(object);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_slong_t mk_win_dll_kernel_synchronization_interlocked_increment(mk_win_base_slong_lpt const addend) mk_lang_noexcept
{
	mk_win_base_slong_t ret;

	ret = InterlockedIncrement(addend);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_slong_t mk_win_dll_kernel_synchronization_interlocked_decrement(mk_win_base_slong_lpt const addend) mk_lang_noexcept
{
	mk_win_base_slong_t ret;

	ret = InterlockedDecrement(addend);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_slong_t mk_win_dll_kernel_synchronization_interlocked_exchange(mk_win_base_slong_lpt const target, mk_win_base_slong_t const value) mk_lang_noexcept
{
	mk_win_base_slong_t ret;

	ret = InterlockedExchange(target, value);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_slong_t mk_win_dll_kernel_synchronization_interlocked_compare_exchange(mk_win_base_slong_lpt const target, mk_win_base_slong_t const exchange, mk_win_base_slong_t const comparand) mk_lang_noexcept
{
	mk_win_base_slong_t ret;

	ret = InterlockedCompareExchange(target, exchange, comparand);
	return ret;
}


#endif
