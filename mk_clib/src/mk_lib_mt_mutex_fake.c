#include "mk_lib_mt_mutex_fake.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_fake_construct(mk_lib_mt_mutex_fake_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	mutex->m_mutex = 0;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_fake_destruct(mk_lib_mt_mutex_fake_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	((mk_lang_types_void_t)(mutex));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_fake_exclusive_lock(mk_lib_mt_mutex_fake_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);
	mk_lang_assert(mutex->m_mutex == 0);

	mutex->m_mutex = 1;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_fake_exclusive_unlock(mk_lib_mt_mutex_fake_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);
	mk_lang_assert(mutex->m_mutex == 1);

	mutex->m_mutex = 0;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_fake_shared_lock(mk_lib_mt_mutex_fake_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);
	mk_lang_assert(mutex->m_mutex == 0);

	mutex->m_mutex = 2;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_fake_shared_unlock(mk_lib_mt_mutex_fake_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);
	mk_lang_assert(mutex->m_mutex == 2);

	mutex->m_mutex = 0;
	return 0;
}
