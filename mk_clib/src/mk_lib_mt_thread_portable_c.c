#include "mk_lib_mt_thread_portable_c.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_cv_portable_c.h"
#include "mk_lib_mt_mutex_portable_c.h"
#include "mk_lib_mt_unique_lock_portable_c.h"

#include <threads.h> /* thrd_start_t thrd_t thrd_create thrd_success thrd_join */


struct mk_lib_mt_thread_portable_c_args_s
{
	mk_lib_mt_mutex_portable_c_t m_mutex;
	mk_lib_mt_cv_portable_c_t m_cv;
	mk_lang_types_bool_t m_inited;
	mk_lib_mt_thread_portable_c_callback_t m_callback;
	mk_lang_types_void_pt m_context;
};
typedef struct mk_lib_mt_thread_portable_c_args_s mk_lib_mt_thread_portable_c_args_t;
typedef mk_lib_mt_thread_portable_c_args_t const mk_lib_mt_thread_portable_c_args_ct;
typedef mk_lib_mt_thread_portable_c_args_t* mk_lib_mt_thread_portable_c_args_pt;
typedef mk_lib_mt_thread_portable_c_args_t const* mk_lib_mt_thread_portable_c_args_pct;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_mt_thread_portable_c_procedure_impl_1(mk_lang_types_void_pt const arg) mk_lang_noexcept
{
	mk_lib_mt_thread_portable_c_args_pt args;
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_portable_c_t ul;
	mk_lib_mt_thread_portable_c_callback_t callback;
	mk_lang_types_void_pt context;

	mk_lang_assert(arg);

	args = ((mk_lib_mt_thread_portable_c_args_pt)(arg));
	err = mk_lib_mt_unique_lock_portable_c_construct(&ul, &args->m_mutex); mk_lang_check_rereturn(err);
	callback = args->m_callback;
	context = args->m_context;
	args->m_inited = mk_lang_true;
	err = mk_lib_mt_unique_lock_portable_c_destruct(&ul); mk_lang_check_rereturn(err);
	err = mk_lib_mt_cv_portable_c_notify_one(&args->m_cv); mk_lang_check_rereturn(err);
	err = callback(context); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_types_sint_t mk_lib_mt_thread_portable_c_procedure(mk_lang_types_void_pt const arg) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_lib_mt_thread_portable_c_procedure_impl_1(arg); mk_lang_check_recrash(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_mt_thread_portable_c_create_impl_4(mk_lib_mt_thread_portable_c_args_pt const args, mk_lib_mt_unique_lock_portable_c_pt const ul) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(args);
	mk_lang_assert(ul);

	while(!args->m_inited)
	{
		err = mk_lib_mt_cv_portable_c_wait(&args->m_cv, ul); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_mt_thread_portable_c_create_impl_3(mk_lib_mt_thread_portable_c_args_pt const args) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_portable_c_t ul;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(args);

	err = mk_lib_mt_unique_lock_portable_c_construct(&ul, &args->m_mutex); mk_lang_check_rereturn(err);
	err_b = mk_lib_mt_thread_portable_c_create_impl_4(args, &ul);
	err = mk_lib_mt_unique_lock_portable_c_destruct(&ul); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_mt_thread_portable_c_create_impl_2(mk_lib_mt_thread_portable_c_pt const thread, mk_lib_mt_thread_portable_c_args_pt const args) mk_lang_noexcept
{
	thrd_start_t start;
	mk_lang_types_sint_t ret;
	mk_lang_types_sint_t err;

	mk_lang_assert(thread);
	mk_lang_assert(args);

	start = &mk_lib_mt_thread_portable_c_procedure;
	ret = thrd_create(&thread->m_thread, start, args); mk_lang_check_return(ret == thrd_success);
	err = mk_lib_mt_thread_portable_c_create_impl_3(args); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_mt_thread_portable_c_create_impl_1(mk_lib_mt_thread_portable_c_pt const thread, mk_lib_mt_thread_portable_c_args_pt const args) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(thread);
	mk_lang_assert(args);

	err = mk_lib_mt_cv_portable_c_construct(&args->m_cv); mk_lang_check_rereturn(err);
	err_b = mk_lib_mt_thread_portable_c_create_impl_2(thread, args);
	err = mk_lib_mt_cv_portable_c_destruct(&args->m_cv); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_c_hardware_concurrency(mk_lang_types_void_t) mk_lang_noexcept
{
	return 4; /* dunno */
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_c_create(mk_lib_mt_thread_portable_c_pt const thread, mk_lib_mt_thread_portable_c_callback_t const callback, mk_lang_types_void_pt const context) mk_lang_noexcept
{
	mk_lib_mt_thread_portable_c_args_t args;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(thread);
	mk_lang_assert(callback);

	args.m_inited = mk_lang_false;
	args.m_callback = callback;
	args.m_context = context;
	err = mk_lib_mt_mutex_portable_c_construct(&args.m_mutex); mk_lang_check_rereturn(err);
	err_b = mk_lib_mt_thread_portable_c_create_impl_1(thread, &args);
	err = mk_lib_mt_mutex_portable_c_destruct(&args.m_mutex); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
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
