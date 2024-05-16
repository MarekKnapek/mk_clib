#include "mk_lib_mt_cv_windows_srwl.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_unique_lock_windows_srwl.h"
#include "mk_win_base.h"
#include "mk_win_kernel_cv.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_srwl_construct(mk_lib_mt_cv_windows_srwl_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	mk_win_kernel_cv_construct(&cv->m_cv);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_srwl_destruct(mk_lib_mt_cv_windows_srwl_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	mk_win_kernel_cv_destroy(&cv->m_cv);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_srwl_wait_exclusive(mk_lib_mt_cv_windows_srwl_pt const cv, mk_lib_mt_unique_lock_exclusive_windows_srwl_pt const lock) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	mk_lang_assert(cv);
	mk_lang_assert(lock);
	mk_lang_assert(lock->m_mutex);

	ret = mk_win_kernel_cv_wait_srwl(&cv->m_cv, &lock->m_mutex->m_mutex, mk_win_base_infinite, mk_win_kernel_cv_flags_e_lockmode_exclusive); mk_lang_check_return(ret != mk_win_base_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_srwl_wait_shared(mk_lib_mt_cv_windows_srwl_pt const cv, mk_lib_mt_unique_lock_shared_windows_srwl_pt const lock) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	mk_lang_assert(cv);
	mk_lang_assert(lock);
	mk_lang_assert(lock->m_mutex);

	ret = mk_win_kernel_cv_wait_srwl(&cv->m_cv, &lock->m_mutex->m_mutex, mk_win_base_infinite, mk_win_kernel_cv_flags_e_lockmode_shared); mk_lang_check_return(ret != mk_win_base_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_srwl_notify_one(mk_lib_mt_cv_windows_srwl_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	mk_win_kernel_cv_notify_one(&cv->m_cv);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_windows_srwl_notify_all(mk_lib_mt_cv_windows_srwl_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	mk_win_kernel_cv_notify_all(&cv->m_cv);
	return 0;
}
