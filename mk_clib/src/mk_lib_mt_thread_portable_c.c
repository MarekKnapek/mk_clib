#include "mk_lib_mt_thread_portable_c.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#include <threads.h> /* thrd_start_t thrd_t thrd_create thrd_success thrd_join */


mk_lang_nodiscard static mk_lang_types_sint_t mk_lib_mt_thread_portable_c_procedure(mk_lang_types_void_pt const arg) mk_lang_noexcept
{
	mk_lib_mt_thread_portable_c_args_pt args;
	mk_lib_mt_thread_portable_c_callback_t callback;
	mk_lang_types_void_pt context;
	mk_lang_types_sint_t ret;

	mk_lang_assert(arg);
	mk_lang_assert(((mk_lib_mt_thread_portable_c_args_pt)(arg))->m_callback);

	args = ((mk_lib_mt_thread_portable_c_args_pt)(arg));
	callback = args->m_callback;
	context = args->m_context;
	ret = callback(context);
	mk_lang_assert(ret == 0);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_c_hardware_concurrency(mk_lang_types_void_t) mk_lang_noexcept
{
	return 4; /* dunno */
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_c_create(mk_lib_mt_thread_portable_c_pt const thread, mk_lib_mt_thread_portable_c_callback_t const callback, mk_lang_types_void_pt const context) mk_lang_noexcept
{
	thrd_start_t start;
	mk_lang_types_sint_t ret;

	mk_lang_assert(thread);
	mk_lang_assert(callback);

	thread->m_args.m_callback = callback;
	thread->m_args.m_context = context;
	start = mk_lib_mt_thread_portable_c_procedure;
	ret = thrd_create(&thread->m_thread, start, &thread->m_args); mk_lang_check_return(ret == thrd_success);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_c_join(mk_lib_mt_thread_portable_c_pt const thread) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;
	mk_lang_types_sint_t res;

	mk_lang_assert(thread);

	ret = thrd_join(thread->m_thread, &res); mk_lang_check_return(ret == thrd_success); mk_lang_check_return(res == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_c_destroy(mk_lib_mt_thread_portable_c_pt const thread) mk_lang_noexcept
{
	mk_lang_assert(thread);

	((mk_lang_types_void_t)(thread));
	return 0;
}
