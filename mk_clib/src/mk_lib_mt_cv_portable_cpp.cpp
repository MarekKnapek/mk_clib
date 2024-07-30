#include "mk_lib_mt_cv_portable_cpp.hpp"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_unique_lock_portable_cpp.hpp"

#include <chrono> /* std::chrono::milliseconds */
#include <condition_variable> /* std::condition_variable */
#include <new> /* new */


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_cpp_construct(mk_lib_mt_cv_portable_cpp_pt const cv) mk_lang_noexcept
{
	typedef std::condition_variable cv_t;
	typedef cv_t* cv_pt;

	mk_lang_types_sint_t ret;
	cv_pt real;

	mk_lang_assert(cv);

	ret = 0;
	try
	{
		real = reinterpret_cast<cv_pt>(&cv->m_cv);
		::new(static_cast<mk_lang_types_void_pt>(real))(cv_t)();
	}
	catch(...)
	{
		ret = mk_lang_check_line;
	}
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_cpp_destruct(mk_lib_mt_cv_portable_cpp_pt const cv) mk_lang_noexcept
{
	typedef std::condition_variable cv_t;
	typedef cv_t* cv_pt;

	cv_pt real;

	mk_lang_assert(cv);

	real = reinterpret_cast<cv_pt>(&cv->m_cv);
	real->~condition_variable();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_cpp_wait_exclusive(mk_lib_mt_cv_portable_cpp_pt const cv, mk_lib_mt_unique_lock_exclusive_portable_cpp_pt const lock) mk_lang_noexcept
{
	typedef std::condition_variable cv_t;
	typedef cv_t* cv_pt;
	typedef std::unique_lock<std::mutex> ul_t;
	typedef ul_t* ul_pt;

	cv_pt real_cv;
	ul_pt real_ul;

	mk_lang_assert(cv);
	mk_lang_assert(lock);

	real_cv = reinterpret_cast<cv_pt>(&cv->m_cv);
	real_ul = reinterpret_cast<ul_pt>(&lock->m_unique_lock);
	real_cv->wait(*real_ul);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_cpp_wait_exclusive_for(mk_lib_mt_cv_portable_cpp_pt const cv, mk_lib_mt_unique_lock_exclusive_portable_cpp_pt const lock, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const signaled) mk_lang_noexcept
{
	typedef std::condition_variable cv_t;
	typedef cv_t* cv_pt;
	typedef std::unique_lock<std::mutex> ul_t;
	typedef ul_t* ul_pt;

	cv_pt real_cv;
	ul_pt real_ul;
	std::cv_status res;

	mk_lang_assert(cv);
	mk_lang_assert(lock);
	mk_lang_assert(ms >= 1);
	mk_lang_assert(signaled);

	real_cv = reinterpret_cast<cv_pt>(&cv->m_cv);
	real_ul = reinterpret_cast<ul_pt>(&lock->m_unique_lock);
	res = real_cv->wait_for(*real_ul, std::chrono::milliseconds{ms}); mk_lang_assert(res == std::cv_status::no_timeout || res == std::cv_status::timeout);
	*signaled = res == std::cv_status::no_timeout;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_cpp_wait_shared(mk_lib_mt_cv_portable_cpp_pt const cv, mk_lib_mt_unique_lock_shared_portable_cpp_pt const lock) mk_lang_noexcept
{
	typedef std::condition_variable cv_t;
	typedef cv_t* cv_pt;
	typedef std::unique_lock<std::mutex> ul_t;
	typedef ul_t* ul_pt;

	cv_pt real_cv;
	ul_pt real_ul;

	mk_lang_assert(cv);
	mk_lang_assert(lock);

	real_cv = reinterpret_cast<cv_pt>(&cv->m_cv);
	real_ul = reinterpret_cast<ul_pt>(&lock->m_unique_lock);
	real_cv->wait(*real_ul);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_cpp_wait_shared_for(mk_lib_mt_cv_portable_cpp_pt const cv, mk_lib_mt_unique_lock_shared_portable_cpp_pt const lock, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const signaled) mk_lang_noexcept
{
	typedef std::condition_variable cv_t;
	typedef cv_t* cv_pt;
	typedef std::unique_lock<std::mutex> ul_t;
	typedef ul_t* ul_pt;

	cv_pt real_cv;
	ul_pt real_ul;
	std::cv_status res;

	mk_lang_assert(cv);
	mk_lang_assert(lock);
	mk_lang_assert(ms >= 1);
	mk_lang_assert(signaled);

	real_cv = reinterpret_cast<cv_pt>(&cv->m_cv);
	real_ul = reinterpret_cast<ul_pt>(&lock->m_unique_lock);
	res = real_cv->wait_for(*real_ul, std::chrono::milliseconds{ms}); mk_lang_assert(res == std::cv_status::no_timeout || res == std::cv_status::timeout);
	*signaled = res == std::cv_status::no_timeout;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_cpp_notify_one(mk_lib_mt_cv_portable_cpp_pt const cv) mk_lang_noexcept
{
	typedef std::condition_variable cv_t;
	typedef cv_t* cv_pt;

	cv_pt real;

	mk_lang_assert(cv);

	real = reinterpret_cast<cv_pt>(&cv->m_cv);
	real->notify_one();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_cpp_notify_all(mk_lib_mt_cv_portable_cpp_pt const cv) mk_lang_noexcept
{
	typedef std::condition_variable cv_t;
	typedef cv_t* cv_pt;

	cv_pt real;

	mk_lang_assert(cv);

	real = reinterpret_cast<cv_pt>(&cv->m_cv);
	real->notify_all();
	return 0;
}
