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


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_exclusive_portable_cpp_construct(mk_lib_mt_unique_lock_exclusive_portable_cpp_pt const unique_lock, mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept
{
	typedef std::unique_lock<std::mutex> ul_t;
	typedef ul_t* ul_pt;
	typedef std::mutex mtx_t;
	typedef mtx_t* mtx_pt;

	ul_pt real_ul;
	mtx_pt real_mtx;

	mk_lang_assert(unique_lock);
	mk_lang_assert(mutex);

	real_ul = reinterpret_cast<ul_pt>(&unique_lock->m_unique_lock);
	real_mtx = reinterpret_cast<mtx_pt>(&mutex->m_mutex);
	::new(static_cast<mk_lang_types_void_pt>(real_ul))(ul_t)(*real_mtx);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_exclusive_portable_cpp_destruct(mk_lib_mt_unique_lock_exclusive_portable_cpp_pt const unique_lock) mk_lang_noexcept
{
	typedef std::unique_lock<std::mutex> ul_t;
	typedef ul_t* ul_pt;

	ul_pt real;

	mk_lang_assert(unique_lock);

	real = reinterpret_cast<ul_pt>(&unique_lock->m_unique_lock);
	real->~unique_lock();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_shared_portable_cpp_construct(mk_lib_mt_unique_lock_shared_portable_cpp_pt const unique_lock, mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept
{
	typedef std::unique_lock<std::mutex> ul_t;
	typedef ul_t* ul_pt;
	typedef std::mutex mtx_t;
	typedef mtx_t* mtx_pt;

	ul_pt real_ul;
	mtx_pt real_mtx;

	mk_lang_assert(unique_lock);
	mk_lang_assert(mutex);

	real_ul = reinterpret_cast<ul_pt>(&unique_lock->m_unique_lock);
	real_mtx = reinterpret_cast<mtx_pt>(&mutex->m_mutex);
	::new(static_cast<mk_lang_types_void_pt>(real_ul))(ul_t)(*real_mtx);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_shared_portable_cpp_destruct(mk_lib_mt_unique_lock_shared_portable_cpp_pt const unique_lock) mk_lang_noexcept
{
	typedef std::unique_lock<std::mutex> ul_t;
	typedef ul_t* ul_pt;

	ul_pt real;

	mk_lang_assert(unique_lock);

	real = reinterpret_cast<ul_pt>(&unique_lock->m_unique_lock);
	real->~unique_lock();
	return 0;
}
