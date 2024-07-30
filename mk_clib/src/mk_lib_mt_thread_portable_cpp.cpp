#include "mk_lib_mt_thread_portable_cpp.hpp"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#include <thread> /* std::thread::hardware_concurrency std::thread::thread std::thread::join std::thread::~thread */
#include <new> /* new */


static mk_lang_types_void_t mk_lib_mt_thread_portable_cpp_procedure(mk_lib_mt_thread_portable_cpp_callback_t const callback, mk_lang_types_void_pt const context) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(callback);

	ret = callback(context);
	mk_lang_assert(ret == 0);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_cpp_hardware_concurrency(mk_lang_types_void_t) mk_lang_noexcept
{
	return static_cast<mk_lang_types_sint_t>(std::thread::hardware_concurrency());
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_cpp_create(mk_lib_mt_thread_portable_cpp_pt const thread, mk_lib_mt_thread_portable_cpp_callback_t const callback, mk_lang_types_void_pt const context) mk_lang_noexcept
{
	typedef std::thread thread_t;
	typedef thread_t* thread_pt;

	mk_lang_types_sint_t ret;
	thread_pt real;

	mk_lang_assert(thread);
	mk_lang_assert(callback);

	ret = 0;
	try
	{
		real = reinterpret_cast<thread_pt>(&thread->m_thread);
		::new(static_cast<mk_lang_types_void_pt>(real))(thread_t)(mk_lib_mt_thread_portable_cpp_procedure, callback, context);
	}
	catch(...)
	{
		ret = mk_lang_check_line;
	}
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_cpp_create_all(mk_lib_mt_thread_portable_cpp_pt const threads, mk_lang_types_sint_pt const count, mk_lib_mt_thread_portable_cpp_callback_t const callback, mk_lang_types_void_pt const context) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;

	mk_lang_assert(threads);
	mk_lang_assert(count);
	mk_lang_assert(*count >= 2);
	mk_lang_assert(callback);

	n = mk_lang_min(*count, mk_lib_mt_thread_portable_cpp_hardware_concurrency());
	for(i = 0; i != n; ++i)
	{
		err = mk_lib_mt_thread_portable_cpp_create(&threads[i], callback, context); mk_lang_check_rereturn(err); /* todo if it fails, clean up previous successful */
	}
	*count = n;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_cpp_join(mk_lib_mt_thread_portable_cpp_pt const thread) mk_lang_noexcept
{
	typedef std::thread thread_t;
	typedef thread_t* thread_pt;

	mk_lang_types_sint_t ret;
	thread_pt real;

	mk_lang_assert(thread);

	ret = 0;
	try
	{
		real = reinterpret_cast<thread_pt>(&thread->m_thread);
		real->join();
	}
	catch(...)
	{
		ret = mk_lang_check_line;
	}
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_cpp_destroy(mk_lib_mt_thread_portable_cpp_pt const thread) mk_lang_noexcept
{
	typedef std::thread thread_t;
	typedef thread_t* thread_pt;

	thread_pt real;

	mk_lang_assert(thread);

	real = reinterpret_cast<thread_pt>(&thread->m_thread);
	real->~thread();
	return 0;
}
