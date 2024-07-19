#include "mk_lib_mt_cv_portable_c.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_unique_lock_portable_c.h"

#include <threads.h> /* cnd_t cnd_init thrd_success thrd_timedout cnd_destroy cnd_wait cnd_timedwait cnd_signal cnd_broadcast */


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_c_construct(mk_lib_mt_cv_portable_c_pt const cv) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(cv);

	ret = cnd_init(&cv->m_cv); mk_lang_check_return(ret == thrd_success);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_c_destruct(mk_lib_mt_cv_portable_c_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	cnd_destroy(&cv->m_cv);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_c_wait_exclusive(mk_lib_mt_cv_portable_c_pt const cv, mk_lib_mt_unique_lock_exclusive_portable_c_pt const lock) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(cv);
	mk_lang_assert(lock);
	mk_lang_assert(lock->m_mutex);

	ret = cnd_wait(&cv->m_cv, &lock->m_mutex->m_mutex); mk_lang_check_return(ret == thrd_success);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_c_wait_exclusive_for(mk_lib_mt_cv_portable_c_pt const cv, mk_lib_mt_unique_lock_exclusive_portable_c_pt const lock, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const signaled) mk_lang_noexcept
{
	struct timespec timeout;
	mk_lang_types_sint_t ret;

	mk_lang_assert(cv);
	mk_lang_assert(lock);
	mk_lang_assert(lock->m_mutex);
	mk_lang_assert(ms >= 1);
	mk_lang_assert(signaled);

	timeout.tv_sec = ms / 1000;
	timeout.tv_nsec = (ms % 1000) * 1000l * 1000l;
	ret = cnd_timedwait(&cv->m_cv, &lock->m_mutex->m_mutex, &timeout); mk_lang_check_return(ret == thrd_success || ret == thrd_timedout);
	*signaled = ret == thrd_success;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_c_wait_shared(mk_lib_mt_cv_portable_c_pt const cv, mk_lib_mt_unique_lock_shared_portable_c_pt const lock) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(cv);
	mk_lang_assert(lock);
	mk_lang_assert(lock->m_mutex);

	ret = cnd_wait(&cv->m_cv, &lock->m_mutex->m_mutex); mk_lang_check_return(ret == thrd_success);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_c_wait_shared_for(mk_lib_mt_cv_portable_c_pt const cv, mk_lib_mt_unique_lock_shared_portable_c_pt const lock, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const signaled) mk_lang_noexcept
{
	struct timespec timeout;
	mk_lang_types_sint_t ret;

	mk_lang_assert(cv);
	mk_lang_assert(lock);
	mk_lang_assert(lock->m_mutex);
	mk_lang_assert(ms >= 1);
	mk_lang_assert(signaled);

	timeout.tv_sec = ms / 1000;
	timeout.tv_nsec = (ms % 1000) * 1000l * 1000l;
	ret = cnd_timedwait(&cv->m_cv, &lock->m_mutex->m_mutex, &timeout); mk_lang_check_return(ret == thrd_success || ret == thrd_timedout);
	*signaled = ret == thrd_success;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_c_notify_one(mk_lib_mt_cv_portable_c_pt const cv) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(cv);

	ret = cnd_signal(&cv->m_cv); mk_lang_check_return(ret == thrd_success);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_c_notify_all(mk_lib_mt_cv_portable_c_pt const cv) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(cv);

	ret = cnd_broadcast(&cv->m_cv); mk_lang_check_return(ret == thrd_success);
	return 0;
}
