#include "mk_lib_mt_unique_lock_portable_cpp.hpp"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_mutex_portable_cpp.hpp"

#include <mutex> /* std::unique_lock std::unique_lock::unique_lock std::unique_lock::~unique_lock */
#include <new> /* new */


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_portable_cpp_construct(mk_lib_mt_unique_lock_portable_cpp_pt const unique_lock, mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(unique_lock);
	mk_lang_assert(mutex);

	::new(static_cast<mk_lang_types_void_pt>(&unique_lock->m_unique_lock))(std::unique_lock<std::mutex>)(*reinterpret_cast<std::mutex*>(&mutex->m_mutex));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_portable_cpp_destruct(mk_lib_mt_unique_lock_portable_cpp_pt const unique_lock) mk_lang_noexcept
{
	mk_lang_assert(unique_lock);

	reinterpret_cast<std::unique_lock<std::mutex>*>(&unique_lock->m_unique_lock)->~unique_lock();
	return 0;
}
