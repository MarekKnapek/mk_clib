#include "mk_lib_mt_mutex_windows_cs.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_kernel_cs.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_cs_construct(mk_lib_mt_mutex_windows_cs_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	mk_win_kernel_cs_construct(&mutex->m_mutex);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_cs_destruct(mk_lib_mt_mutex_windows_cs_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	mk_win_kernel_cs_destroy(&mutex->m_mutex);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_cs_exclusive_lock(mk_lib_mt_mutex_windows_cs_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	mk_win_kernel_cs_lock(&mutex->m_mutex);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_cs_exclusive_unlock(mk_lib_mt_mutex_windows_cs_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	mk_win_kernel_cs_unlock(&mutex->m_mutex);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_cs_shared_lock(mk_lib_mt_mutex_windows_cs_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	mk_win_kernel_cs_lock(&mutex->m_mutex);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_cs_shared_unlock(mk_lib_mt_mutex_windows_cs_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	mk_win_kernel_cs_unlock(&mutex->m_mutex);
	return 0;
}
