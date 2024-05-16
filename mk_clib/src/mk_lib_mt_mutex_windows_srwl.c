#include "mk_lib_mt_mutex_windows_srwl.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_kernel_srwl.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_srwl_construct(mk_lib_mt_mutex_windows_srwl_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	mk_win_kernel_srwl_construct(&mutex->m_mutex);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_srwl_destruct(mk_lib_mt_mutex_windows_srwl_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	mk_win_kernel_srwl_destroy(&mutex->m_mutex);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_srwl_exclusive_lock(mk_lib_mt_mutex_windows_srwl_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	mk_win_kernel_srwl_exclusive_lock(&mutex->m_mutex);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_srwl_exclusive_unlock(mk_lib_mt_mutex_windows_srwl_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	mk_win_kernel_srwl_exclusive_unlock(&mutex->m_mutex);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_srwl_shared_lock(mk_lib_mt_mutex_windows_srwl_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	mk_win_kernel_srwl_shared_lock(&mutex->m_mutex);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_windows_srwl_shared_unlock(mk_lib_mt_mutex_windows_srwl_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	mk_win_kernel_srwl_shared_unlock(&mutex->m_mutex);
	return 0;
}
