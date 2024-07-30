#include "mk_lib_mt_cv_windows_cs.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_unique_lock_windows_cs.h"
#include "mk_win_base.h"
#include "mk_win_kernel_cv.h"
#include "mk_win_kernel_errors.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_cs_construct(mk_lib_mt_cv_windows_cs_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	mk_win_kernel_cv_construct(&cv->m_cv);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_cs_destruct(mk_lib_mt_cv_windows_cs_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	mk_win_kernel_cv_destroy(&cv->m_cv);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_cs_wait_exclusive(mk_lib_mt_cv_windows_cs_pt const cv, mk_lib_mt_unique_lock_exclusive_windows_cs_pt const lock) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	mk_lang_assert(cv);
	mk_lang_assert(lock);
	mk_lang_assert(lock->m_mutex);

	ret = mk_win_kernel_cv_wait_cs(&cv->m_cv, &lock->m_mutex->m_mutex, mk_win_base_infinite); mk_lang_check_return(ret != mk_win_base_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_cs_wait_exclusive_for(mk_lib_mt_cv_windows_cs_pt const cv, mk_lib_mt_unique_lock_exclusive_windows_cs_pt const lock, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const signaled) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	mk_lang_assert(cv);
	mk_lang_assert(lock);
	mk_lang_assert(lock->m_mutex);
	mk_lang_assert(ms >= 1);
	mk_lang_assert(signaled);

	ret = mk_win_kernel_cv_wait_cs(&cv->m_cv, &lock->m_mutex->m_mutex, ((mk_win_base_dword_t)(ms))); mk_lang_check_return(ret != mk_win_base_false || mk_win_kernel_errors_get_last() == mk_win_kernel_errors_id_e_timeout);
	*signaled = ret != mk_win_base_false;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_cs_wait_shared(mk_lib_mt_cv_windows_cs_pt const cv, mk_lib_mt_unique_lock_shared_windows_cs_pt const lock) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	mk_lang_assert(cv);
	mk_lang_assert(lock);
	mk_lang_assert(lock->m_mutex);

	ret = mk_win_kernel_cv_wait_cs(&cv->m_cv, &lock->m_mutex->m_mutex, mk_win_base_infinite); mk_lang_check_return(ret != mk_win_base_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_cs_wait_shared_for(mk_lib_mt_cv_windows_cs_pt const cv, mk_lib_mt_unique_lock_shared_windows_cs_pt const lock, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const signaled) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	mk_lang_assert(cv);
	mk_lang_assert(lock);
	mk_lang_assert(lock->m_mutex);
	mk_lang_assert(ms);
	mk_lang_assert(signaled);

	ret = mk_win_kernel_cv_wait_cs(&cv->m_cv, &lock->m_mutex->m_mutex, ((mk_win_base_dword_t)(ms))); mk_lang_check_return(ret != mk_win_base_false || mk_win_kernel_errors_get_last() == mk_win_kernel_errors_id_e_timeout);
	*signaled = ret != mk_win_base_false;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_cs_notify_one(mk_lib_mt_cv_windows_cs_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	mk_win_kernel_cv_notify_one(&cv->m_cv);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_cs_notify_all(mk_lib_mt_cv_windows_cs_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	mk_win_kernel_cv_notify_all(&cv->m_cv);
	return 0;
}
