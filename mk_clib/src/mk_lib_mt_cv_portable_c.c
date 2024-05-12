#include "mk_lib_mt_cv_portable_c.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_unique_lock_portable_c.h"

#include <threads.h> /* cnd_t cnd_init thrd_success cnd_destroy cnd_wait cnd_signal cnd_broadcast */


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

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_c_wait(mk_lib_mt_cv_portable_c_pt const cv, mk_lib_mt_unique_lock_portable_c_pt const lock) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(cv);
	mk_lang_assert(lock);
	mk_lang_assert(lock->m_mutex);

	ret = cnd_wait(&cv->m_cv, &lock->m_mutex->m_mutex); mk_lang_check_return(ret == thrd_success);
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
