#include "mk_lib_mt_mutex_windows_wosa.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_api_ms_win_core_synch_l1_2_0.h"
#include "mk_win_base.h"


#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2003
#include <intrin.h>
#pragma intrinsic(_InterlockedCompareExchange)
#pragma intrinsic(_InterlockedExchange)
#define mk_lib_mt_mutex_windows_wosa_interlocked_compare_exchange _InterlockedCompareExchange
#define mk_lib_mt_mutex_windows_wosa_interlocked_exchange _InterlockedExchange
#else
#include "mk_win_kernel_synchronization.h"
#define mk_lib_mt_mutex_windows_wosa_interlocked_compare_exchange mk_win_kernel_synchronization_interlocked_compare_exchange
#define mk_lib_mt_mutex_windows_wosa_interlocked_exchange mk_win_kernel_synchronization_interlocked_exchange
#endif


enum mk_lib_mt_mutex_windows_wosa_state_e
{
	mk_lib_mt_mutex_windows_wosa_state_e_unlocked,
	mk_lib_mt_mutex_windows_wosa_state_e_locked,
	mk_lib_mt_mutex_windows_wosa_state_e_contested,
	mk_lib_mt_mutex_windows_wosa_state_e_dummy_end
};
typedef enum mk_lib_mt_mutex_windows_wosa_state_e mk_lib_mt_mutex_windows_wosa_state_t;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_wosa_construct(mk_lib_mt_mutex_windows_wosa_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	mutex->m_mutex = mk_lib_mt_mutex_windows_wosa_state_e_unlocked;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_wosa_destruct(mk_lib_mt_mutex_windows_wosa_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	((mk_lang_types_void_t)(mutex));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_wosa_exclusive_lock(mk_lib_mt_mutex_windows_wosa_pt const mutex) mk_lang_noexcept
{
	mk_win_base_slong_t prev;
	mk_win_base_bool_t b;

	mk_lang_assert(mutex);

	prev = mk_lib_mt_mutex_windows_wosa_interlocked_compare_exchange(&mutex->m_mutex, mk_lib_mt_mutex_windows_wosa_state_e_locked, mk_lib_mt_mutex_windows_wosa_state_e_unlocked);
	if(prev != mk_lib_mt_mutex_windows_wosa_state_e_unlocked)
	{
		while((prev = mk_lib_mt_mutex_windows_wosa_interlocked_exchange(&mutex->m_mutex, mk_lib_mt_mutex_windows_wosa_state_e_contested)) != mk_lib_mt_mutex_windows_wosa_state_e_unlocked)
		{
			b = mk_win_api_ms_win_core_synch_l1_2_0_wait_on_address(&mutex->m_mutex, &prev, sizeof(prev), mk_win_base_infinite); mk_lang_check_return(b != 0);
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_wosa_exclusive_unlock(mk_lib_mt_mutex_windows_wosa_pt const mutex) mk_lang_noexcept
{
	mk_win_base_slong_t prev;

	mk_lang_assert(mutex);

	prev = mk_lib_mt_mutex_windows_wosa_interlocked_exchange(&mutex->m_mutex, mk_lib_mt_mutex_windows_wosa_state_e_unlocked);
	if(prev == mk_lib_mt_mutex_windows_wosa_state_e_contested)
	{
		mk_win_api_ms_win_core_synch_l1_2_0_wake_by_address_single(&mutex->m_mutex);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_wosa_shared_lock(mk_lib_mt_mutex_windows_wosa_pt const mutex) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(mutex);

	err = mk_lib_mt_mutex_windows_wosa_exclusive_lock(mutex);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_wosa_shared_unlock(mk_lib_mt_mutex_windows_wosa_pt const mutex) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(mutex);

	err = mk_lib_mt_mutex_windows_wosa_exclusive_unlock(mutex);
	return 0;
}
