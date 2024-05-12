#include "mk_lib_mt_thread_portable_cpp.hpp"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
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
	mk_lang_types_sint_t ret;

	mk_lang_assert(thread);
	mk_lang_assert(callback);

	ret = 0;
	try
	{
		::new(static_cast<mk_lang_types_void_pt>(&thread->m_thread))(std::thread)(mk_lib_mt_thread_portable_cpp_procedure, callback, context);
	}
	catch(...)
	{
		ret = mk_lang_check_line;
	}
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_cpp_join(mk_lib_mt_thread_portable_cpp_pt const thread) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(thread);

	ret = 0;
	try
	{
		reinterpret_cast<std::thread*>(&thread->m_thread)->join();
	}
	catch(...)
	{
		ret = mk_lang_check_line;
	}
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_cpp_destroy(mk_lib_mt_thread_portable_cpp_pt const thread) mk_lang_noexcept
{
	mk_lang_assert(thread);

	reinterpret_cast<std::thread*>(&thread->m_thread)->~thread();
	return 0;
}
