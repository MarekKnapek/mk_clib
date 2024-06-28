#include "mk_lib_mt_mutex_posix.h"

#if defined mk_lib_mt_posix_has && mk_lib_mt_posix_has == 1

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"

#include <pthread.h> /* pthread_mutex_t pthread_mutex_init pthread_mutex_destroy pthread_mutex_lock pthread_mutex_unlock */


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_posix_construct(mk_lib_mt_mutex_posix_pt const mutex) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(mutex);

	ret = pthread_mutex_init(&mutex->m_mutex, mk_lang_null); mk_lang_check_return(ret == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_posix_destruct(mk_lib_mt_mutex_posix_pt const mutex) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(mutex);

	ret = pthread_mutex_destroy(&mutex->m_mutex); mk_lang_check_return(ret == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_posix_exclusive_lock(mk_lib_mt_mutex_posix_pt const mutex) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(mutex);

	ret = pthread_mutex_lock(&mutex->m_mutex); mk_lang_check_return(ret == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_posix_exclusive_unlock(mk_lib_mt_mutex_posix_pt const mutex) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(mutex);

	ret = pthread_mutex_unlock(&mutex->m_mutex); mk_lang_check_return(ret == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_posix_shared_lock(mk_lib_mt_mutex_posix_pt const mutex) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(mutex);

	ret = pthread_mutex_lock(&mutex->m_mutex); mk_lang_check_return(ret == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_posix_shared_unlock(mk_lib_mt_mutex_posix_pt const mutex) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(mutex);

	ret = pthread_mutex_unlock(&mutex->m_mutex); mk_lang_check_return(ret == 0);
	return 0;
}


#endif
