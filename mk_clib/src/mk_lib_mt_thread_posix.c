#include "mk_lib_mt_thread_posix.h"

#if defined mk_lib_mt_posix_has && mk_lib_mt_posix_has == 1

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_cv_posix.h"
#include "mk_lib_mt_mutex_posix.h"
#include "mk_lib_mt_unique_lock_posix.h"

#include <pthread.h> /* pthread_t pthread_create pthread_join */
#include <unistd.h> /* sysconf _SC_NPROCESSORS_ONLN */


struct mk_lib_mt_thread_posix_args_s
{
	mk_lib_mt_mutex_posix_t m_mutex;
	mk_lib_mt_cv_posix_t m_cv;
	mk_lang_types_bool_t m_inited;
	mk_lib_mt_thread_posix_callback_t m_callback;
	mk_lang_types_void_pt m_context;
};
typedef struct mk_lib_mt_thread_posix_args_s mk_lib_mt_thread_posix_args_t;
typedef mk_lib_mt_thread_posix_args_t const mk_lib_mt_thread_posix_args_ct;
typedef mk_lib_mt_thread_posix_args_t* mk_lib_mt_thread_posix_args_pt;
typedef mk_lib_mt_thread_posix_args_t const* mk_lib_mt_thread_posix_args_pct;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_mt_thread_posix_procedure_impl_1(mk_lang_types_void_pt const arg) mk_lang_noexcept
{
	mk_lib_mt_thread_posix_args_pt args;
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_posix_t ul;
	mk_lib_mt_thread_posix_callback_t callback;
	mk_lang_types_void_pt context;

	mk_lang_assert(arg);

	args = ((mk_lib_mt_thread_posix_args_pt)(arg));
	err = mk_lib_mt_unique_lock_exclusive_posix_construct(&ul, &args->m_mutex); mk_lang_check_rereturn(err);
	callback = args->m_callback;
	context = args->m_context;
	args->m_inited = mk_lang_true;
	err = mk_lib_mt_unique_lock_exclusive_posix_destruct(&ul); mk_lang_check_rereturn(err);
	err = mk_lib_mt_cv_posix_notify_one(&args->m_cv); mk_lang_check_rereturn(err);
	err = callback(context); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_types_void_pt mk_lib_mt_thread_posix_procedure(mk_lang_types_void_pt const arg) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_lib_mt_thread_posix_procedure_impl_1(arg); mk_lang_check_recrash(err);
	return mk_lang_null;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_mt_thread_posix_create_impl_4(mk_lib_mt_thread_posix_args_pt const args, mk_lib_mt_unique_lock_exclusive_posix_pt const ul) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(args);
	mk_lang_assert(ul);

	while(!args->m_inited)
	{
		err = mk_lib_mt_cv_posix_wait_exclusive(&args->m_cv, ul); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_mt_thread_posix_create_impl_3(mk_lib_mt_thread_posix_args_pt const args) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_posix_t ul;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(args);

	err = mk_lib_mt_unique_lock_exclusive_posix_construct(&ul, &args->m_mutex); mk_lang_check_rereturn(err);
	err_b = mk_lib_mt_thread_posix_create_impl_4(args, &ul);
	err = mk_lib_mt_unique_lock_exclusive_posix_destruct(&ul); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_mt_thread_posix_create_impl_2(mk_lib_mt_thread_posix_pt const thread, mk_lib_mt_thread_posix_args_pt const args) mk_lang_noexcept
{
	typedef mk_lang_types_void_pt(*start_t)(mk_lang_types_void_pt);

	start_t start;
	mk_lang_types_sint_t ret;
	mk_lang_types_sint_t err;

	mk_lang_assert(thread);
	mk_lang_assert(args);

	start = &mk_lib_mt_thread_posix_procedure;
	ret = pthread_create(&thread->m_thread, mk_lang_null, start, args); mk_lang_check_return(ret == 0);
	err = mk_lib_mt_thread_posix_create_impl_3(args); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_mt_thread_posix_create_impl_1(mk_lib_mt_thread_posix_pt const thread, mk_lib_mt_thread_posix_args_pt const args) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(thread);
	mk_lang_assert(args);

	err = mk_lib_mt_cv_posix_construct(&args->m_cv); mk_lang_check_rereturn(err);
	err_b = mk_lib_mt_thread_posix_create_impl_2(thread, args);
	err = mk_lib_mt_cv_posix_destruct(&args->m_cv); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_posix_hardware_concurrency(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = ((mk_lang_types_sint_t)(sysconf(_SC_NPROCESSORS_ONLN)));
	return mk_lang_max(1, ret);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_posix_create(mk_lib_mt_thread_posix_pt const thread, mk_lib_mt_thread_posix_callback_t const callback, mk_lang_types_void_pt const context) mk_lang_noexcept
{
	mk_lib_mt_thread_posix_args_t args;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(thread);
	mk_lang_assert(callback);

	args.m_inited = mk_lang_false;
	args.m_callback = callback;
	args.m_context = context;
	err = mk_lib_mt_mutex_posix_construct(&args.m_mutex); mk_lang_check_rereturn(err);
	err_b = mk_lib_mt_thread_posix_create_impl_1(thread, &args);
	err = mk_lib_mt_mutex_posix_destruct(&args.m_mutex); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_posix_create_all(mk_lib_mt_thread_posix_pt const threads, mk_lang_types_sint_pt const count, mk_lib_mt_thread_posix_callback_t const callback, mk_lang_types_void_pt const context) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;

	mk_lang_assert(threads);
	mk_lang_assert(count);
	mk_lang_assert(*count >= 2);
	mk_lang_assert(callback);

	n = mk_lang_min(*count, mk_lib_mt_thread_posix_hardware_concurrency());
	for(i = 0; i != n; ++i)
	{
		err = mk_lib_mt_thread_posix_create(&threads[i], callback, context); mk_lang_check_rereturn(err); /* todo if it fails, clean up previous successful */
	}
	*count = n;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_posix_join(mk_lib_mt_thread_posix_pt const thread) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(thread);

	ret = pthread_join(thread->m_thread, mk_lang_null); mk_lang_check_return(ret == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_posix_destroy(mk_lib_mt_thread_posix_pt const thread) mk_lang_noexcept
{
	mk_lang_assert(thread);

	((mk_lang_types_void_t)(thread));
	return 0;
}

#endif
