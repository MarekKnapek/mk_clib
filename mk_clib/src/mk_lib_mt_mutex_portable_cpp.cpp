#include "mk_lib_mt_mutex_portable_cpp.hpp"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#include <mutex> /* std::mutex std::mutex::mutex std::mutex::~mutex std::mutex::mutex::lock std::mutex::unlock */
#include <new> /* new */


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_cpp_construct(mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	::new(static_cast<mk_lang_types_void_pt>(&mutex->m_mutex))(std::mutex)();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_cpp_destruct(mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	reinterpret_cast<std::mutex*>(&mutex->m_mutex)->~mutex();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_cpp_lock(mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	reinterpret_cast<std::mutex*>(&mutex->m_mutex)->lock();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_cpp_unlock(mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	reinterpret_cast<std::mutex*>(&mutex->m_mutex)->unlock();
	return 0;
}
