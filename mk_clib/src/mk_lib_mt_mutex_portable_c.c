#include "mk_lib_mt_mutex_portable_c.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#include <threads.h> /* mtx_t mtx_init mtx_plain thrd_success mtx_destroy mtx_lock mtx_unlock */


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_c_construct(mk_lib_mt_mutex_portable_c_pt const mutex) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(mutex);

	ret = mtx_init(&mutex->m_mutex, mtx_plain); mk_lang_check_return(ret == thrd_success);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_c_destruct(mk_lib_mt_mutex_portable_c_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	mtx_destroy(&mutex->m_mutex);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_c_lock(mk_lib_mt_mutex_portable_c_pt const mutex) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(mutex);

	ret = mtx_lock(&mutex->m_mutex); mk_lang_check_return(ret == thrd_success);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_c_unlock(mk_lib_mt_mutex_portable_c_pt const mutex) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(mutex);

	ret = mtx_unlock(&mutex->m_mutex); mk_lang_check_return(ret == thrd_success);
	return 0;
}
