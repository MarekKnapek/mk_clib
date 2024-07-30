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
	typedef std::mutex mtx_t;
	typedef mtx_t* mtx_pt;

	mtx_pt real;

	mk_lang_assert(mutex);

	real = reinterpret_cast<mtx_pt>(&mutex->m_mutex);
	::new(static_cast<mk_lang_types_void_pt>(real))(mtx_t)();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_cpp_destruct(mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept
{
	typedef std::mutex mtx_t;
	typedef mtx_t* mtx_pt;

	mtx_pt real;

	mk_lang_assert(mutex);

	real = reinterpret_cast<mtx_pt>(&mutex->m_mutex);
	real->~mutex();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_cpp_exclusive_lock(mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept
{
	typedef std::mutex mtx_t;
	typedef mtx_t* mtx_pt;

	mtx_pt real;

	mk_lang_assert(mutex);

	real = reinterpret_cast<mtx_pt>(&mutex->m_mutex);
	real->lock();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_cpp_exclusive_unlock(mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept
{
	typedef std::mutex mtx_t;
	typedef mtx_t* mtx_pt;

	mtx_pt real;

	mk_lang_assert(mutex);

	real = reinterpret_cast<mtx_pt>(&mutex->m_mutex);
	real->unlock();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_cpp_shared_lock(mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept
{
	typedef std::mutex mtx_t;
	typedef mtx_t* mtx_pt;

	mtx_pt real;

	mk_lang_assert(mutex);

	real = reinterpret_cast<mtx_pt>(&mutex->m_mutex);
	real->lock();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_cpp_shared_unlock(mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept
{
	typedef std::mutex mtx_t;
	typedef mtx_t* mtx_pt;

	mtx_pt real;

	mk_lang_assert(mutex);

	real = reinterpret_cast<mtx_pt>(&mutex->m_mutex);
	real->unlock();
	return 0;
}
