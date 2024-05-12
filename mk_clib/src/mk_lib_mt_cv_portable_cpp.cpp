#include "mk_lib_mt_cv_portable_cpp.hpp"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_unique_lock_portable_cpp.hpp"

#include <condition_variable> /* std::condition_variable */
#include <new> /* new */


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_cpp_construct(mk_lib_mt_cv_portable_cpp_pt const cv) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(cv);

	ret = 0;
	try
	{
		::new(static_cast<mk_lang_types_void_pt>(&cv->m_cv))(std::condition_variable)();
	}
	catch(...)
	{
		ret = mk_lang_check_line;
	}
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_cpp_destruct(mk_lib_mt_cv_portable_cpp_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	reinterpret_cast<std::condition_variable*>(&cv->m_cv)->~condition_variable();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_cpp_wait(mk_lib_mt_cv_portable_cpp_pt const cv, mk_lib_mt_unique_lock_portable_cpp_pt const lock) mk_lang_noexcept
{
	mk_lang_assert(cv);
	mk_lang_assert(lock);

	reinterpret_cast<std::condition_variable*>(&cv->m_cv)->wait(*reinterpret_cast<std::unique_lock<std::mutex>*>(&lock->m_unique_lock));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_cpp_notify_one(mk_lib_mt_cv_portable_cpp_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	reinterpret_cast<std::condition_variable*>(&cv->m_cv)->notify_one();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_cpp_notify_all(mk_lib_mt_cv_portable_cpp_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	reinterpret_cast<std::condition_variable*>(&cv->m_cv)->notify_all();
	return 0;
}
