#include "mk_lib_mt_unique_lock_portable_c.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_mutex_portable_c.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_exclusive_portable_c_construct(mk_lib_mt_unique_lock_exclusive_portable_c_pt const unique_lock, mk_lib_mt_mutex_portable_c_pt const mutex) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(unique_lock);
	mk_lang_assert(mutex);

	unique_lock->m_mutex = mutex;
	err = mk_lib_mt_mutex_portable_c_exclusive_lock(unique_lock->m_mutex); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_exclusive_portable_c_destruct(mk_lib_mt_unique_lock_exclusive_portable_c_pt const unique_lock) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(unique_lock);
	mk_lang_assert(unique_lock->m_mutex);

	err = mk_lib_mt_mutex_portable_c_exclusive_unlock(unique_lock->m_mutex); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_shared_portable_c_construct(mk_lib_mt_unique_lock_shared_portable_c_pt const unique_lock, mk_lib_mt_mutex_portable_c_pt const mutex) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(unique_lock);
	mk_lang_assert(mutex);

	unique_lock->m_mutex = mutex;
	err = mk_lib_mt_mutex_portable_c_shared_lock(unique_lock->m_mutex); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_shared_portable_c_destruct(mk_lib_mt_unique_lock_shared_portable_c_pt const unique_lock) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(unique_lock);
	mk_lang_assert(unique_lock->m_mutex);

	err = mk_lib_mt_mutex_portable_c_shared_unlock(unique_lock->m_mutex); mk_lang_check_rereturn(err);
	return 0;
}
