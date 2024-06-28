#include "mk_lib_mt_unique_lock_posix.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_mutex_posix.h"


#if defined mk_lib_mt_posix_has && mk_lib_mt_posix_has == 1


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_exclusive_posix_construct(mk_lib_mt_unique_lock_exclusive_posix_pt const unique_lock, mk_lib_mt_mutex_posix_pt const mutex) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(unique_lock);
	mk_lang_assert(mutex);

	unique_lock->m_mutex = mutex;
	err = mk_lib_mt_mutex_posix_exclusive_lock(unique_lock->m_mutex); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_exclusive_posix_destruct(mk_lib_mt_unique_lock_exclusive_posix_pt const unique_lock) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(unique_lock);
	mk_lang_assert(unique_lock->m_mutex);

	err = mk_lib_mt_mutex_posix_exclusive_unlock(unique_lock->m_mutex); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_shared_posix_construct(mk_lib_mt_unique_lock_shared_posix_pt const unique_lock, mk_lib_mt_mutex_posix_pt const mutex) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(unique_lock);
	mk_lang_assert(mutex);

	unique_lock->m_mutex = mutex;
	err = mk_lib_mt_mutex_posix_shared_lock(unique_lock->m_mutex); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_shared_posix_destruct(mk_lib_mt_unique_lock_shared_posix_pt const unique_lock) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(unique_lock);
	mk_lang_assert(unique_lock->m_mutex);

	err = mk_lib_mt_mutex_posix_shared_unlock(unique_lock->m_mutex); mk_lang_check_rereturn(err);
	return 0;
}


#endif
