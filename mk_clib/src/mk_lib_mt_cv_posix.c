#include "mk_lib_mt_cv_posix.h"

#if defined mk_lib_mt_posix_has && mk_lib_mt_posix_has == 1

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_unique_lock_posix.h"

#include <pthread.h> /* pthread_cond_t pthread_cond_init pthread_cond_destroy pthread_cond_wait pthread_cond_timedwait pthread_cond_signal pthread_cond_broadcast ETIMEDOUT */


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_posix_construct(mk_lib_mt_cv_posix_pt const cv) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(cv);

	ret = pthread_cond_init(&cv->m_cv, mk_lang_null); mk_lang_check_return(ret == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_posix_destruct(mk_lib_mt_cv_posix_pt const cv) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(cv);

	ret = pthread_cond_destroy(&cv->m_cv); mk_lang_check_return(ret == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_posix_wait_exclusive(mk_lib_mt_cv_posix_pt const cv, mk_lib_mt_unique_lock_exclusive_posix_pt const lock) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(cv);
	mk_lang_assert(lock);
	mk_lang_assert(lock->m_mutex);

	ret = pthread_cond_wait(&cv->m_cv, &lock->m_mutex->m_mutex); mk_lang_check_return(ret == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_posix_wait_exclusive_for(mk_lib_mt_cv_posix_pt const cv, mk_lib_mt_unique_lock_exclusive_posix_pt const lock, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const signaled) mk_lang_noexcept
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
	ret = pthread_cond_timedwait(&cv->m_cv, &lock->m_mutex->m_mutex, &timeout); mk_lang_check_return(ret == 0 || ret == ETIMEDOUT);
	*signaled = ret == 0;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_posix_wait_shared(mk_lib_mt_cv_posix_pt const cv, mk_lib_mt_unique_lock_shared_posix_pt const lock) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(cv);
	mk_lang_assert(lock);
	mk_lang_assert(lock->m_mutex);

	ret = pthread_cond_wait(&cv->m_cv, &lock->m_mutex->m_mutex); mk_lang_check_return(ret == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_posix_wait_shared_for(mk_lib_mt_cv_posix_pt const cv, mk_lib_mt_unique_lock_shared_posix_pt const lock, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const signaled) mk_lang_noexcept
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
	ret = pthread_cond_timedwait(&cv->m_cv, &lock->m_mutex->m_mutex, &timeout); mk_lang_check_return(ret == 0 || ret == ETIMEDOUT);
	*signaled = ret == 0;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_posix_notify_one(mk_lib_mt_cv_posix_pt const cv) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(cv);

	ret = pthread_cond_signal(&cv->m_cv); mk_lang_check_return(ret == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_posix_notify_all(mk_lib_mt_cv_posix_pt const cv) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(cv);

	ret = pthread_cond_broadcast(&cv->m_cv); mk_lang_check_return(ret == 0);
	return 0;
}


#endif
