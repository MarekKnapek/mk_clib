#include "mk_lib_mt_thread_windows_cs.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_cv_windows_cs.h"
#include "mk_lib_mt_mutex_windows_cs.h"
#include "mk_lib_mt_unique_lock_windows_cs.h"
#include "mk_win_base.h"
#include "mk_win_kernel_handle.h"
#include "mk_win_kernel_synchronization.h"
#include "mk_win_kernel_system_information.h"
#include "mk_win_kernel_thread.h"


struct mk_lib_mt_thread_windows_cs_args_s
{
	mk_lib_mt_mutex_windows_cs_t m_mutex;
	mk_lib_mt_cv_windows_cs_t m_cv;
	mk_lang_types_bool_t m_inited;
	mk_lib_mt_thread_windows_cs_callback_t m_callback;
	mk_lang_types_void_pt m_context;
};
typedef struct mk_lib_mt_thread_windows_cs_args_s mk_lib_mt_thread_windows_cs_args_t;
typedef mk_lib_mt_thread_windows_cs_args_t const mk_lib_mt_thread_windows_cs_args_ct;
typedef mk_lib_mt_thread_windows_cs_args_t* mk_lib_mt_thread_windows_cs_args_pt;
typedef mk_lib_mt_thread_windows_cs_args_t const* mk_lib_mt_thread_windows_cs_args_pct;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_mt_thread_windows_cs_procedure_impl_1(mk_lang_types_void_pt const arg) mk_lang_noexcept
{
	mk_lib_mt_thread_windows_cs_args_pt args;
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_windows_cs_t ul;
	mk_lib_mt_thread_windows_cs_callback_t callback;
	mk_lang_types_void_pt context;

	mk_lang_assert(arg);

	args = ((mk_lib_mt_thread_windows_cs_args_pt)(arg));
	err = mk_lib_mt_unique_lock_exclusive_windows_cs_construct(&ul, &args->m_mutex); mk_lang_check_rereturn(err);
	callback = args->m_callback;
	context = args->m_context;
	args->m_inited = mk_lang_true;
	err = mk_lib_mt_unique_lock_exclusive_windows_cs_destruct(&ul); mk_lang_check_rereturn(err);
	err = mk_lib_mt_cv_windows_cs_notify_one(&args->m_cv); mk_lang_check_rereturn(err);
	err = callback(context); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_win_base_dword_t mk_win_base_stdcall mk_lib_mt_thread_windows_cs_procedure(mk_win_base_void_lpt const arg) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_lib_mt_thread_windows_cs_procedure_impl_1(arg); mk_lang_check_recrash(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_mt_thread_windows_cs_create_impl_4(mk_lib_mt_thread_windows_cs_args_pt const args, mk_lib_mt_unique_lock_exclusive_windows_cs_pt const ul) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(args);
	mk_lang_assert(ul);

	while(!args->m_inited)
	{
		err = mk_lib_mt_cv_windows_cs_wait_exclusive(&args->m_cv, ul); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_mt_thread_windows_cs_create_impl_3(mk_lib_mt_thread_windows_cs_args_pt const args) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_windows_cs_t ul;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(args);

	err = mk_lib_mt_unique_lock_exclusive_windows_cs_construct(&ul, &args->m_mutex); mk_lang_check_rereturn(err);
	err_b = mk_lib_mt_thread_windows_cs_create_impl_4(args, &ul);
	err = mk_lib_mt_unique_lock_exclusive_windows_cs_destruct(&ul); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_mt_thread_windows_cs_create_impl_2(mk_lib_mt_thread_windows_cs_pt const thread, mk_lib_mt_thread_windows_cs_args_pt const args) mk_lang_noexcept
{
	mk_win_kernel_thread_callback_t start;
	mk_win_base_handle_t t;
	mk_win_base_dword_t tid;
	mk_lang_types_sint_t err;

	mk_lang_assert(thread);
	mk_lang_assert(args);

	start = &mk_lib_mt_thread_windows_cs_procedure;
	t = mk_win_kernel_thread_create(mk_win_base_null, 0, start, args, 0, &tid); mk_lang_check_return(t.m_data);
	thread->m_thread = t;
	err = mk_lib_mt_thread_windows_cs_create_impl_3(args); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_mt_thread_windows_cs_create_impl_1(mk_lib_mt_thread_windows_cs_pt const thread, mk_lib_mt_thread_windows_cs_args_pt const args) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(thread);
	mk_lang_assert(args);

	err = mk_lib_mt_cv_windows_cs_construct(&args->m_cv); mk_lang_check_rereturn(err);
	err_b = mk_lib_mt_thread_windows_cs_create_impl_2(thread, args);
	err = mk_lib_mt_cv_windows_cs_destruct(&args->m_cv); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_windows_cs_hardware_concurrency(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_kernel_system_information_t info;
	mk_lang_types_sint_t ret;

	mk_win_kernel_system_information_get(&info);
	ret = ((mk_lang_types_sint_t)(info.m_number_of_processors));
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_windows_cs_create(mk_lib_mt_thread_windows_cs_pt const thread, mk_lib_mt_thread_windows_cs_callback_t const callback, mk_lang_types_void_pt const context) mk_lang_noexcept
{
	mk_lib_mt_thread_windows_cs_args_t args;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(thread);
	mk_lang_assert(callback);

	args.m_inited = mk_lang_false;
	args.m_callback = callback;
	args.m_context = context;
	err = mk_lib_mt_mutex_windows_cs_construct(&args.m_mutex); mk_lang_check_rereturn(err);
	err_b = mk_lib_mt_thread_windows_cs_create_impl_1(thread, &args);
	err = mk_lib_mt_mutex_windows_cs_destruct(&args.m_mutex); mk_lang_check_rereturn(err);
	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_windows_cs_create_all(mk_lib_mt_thread_windows_cs_pt const threads, mk_lang_types_sint_pt const count, mk_lib_mt_thread_windows_cs_callback_t const callback, mk_lang_types_void_pt const context) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;

	mk_lang_assert(threads);
	mk_lang_assert(count);
	mk_lang_assert(*count >= 2);
	mk_lang_assert(callback);

	n = mk_lang_min(*count, mk_lib_mt_thread_windows_cs_hardware_concurrency());
	for(i = 0; i != n; ++i)
	{
		err = mk_lib_mt_thread_windows_cs_create(&threads[i], callback, context); mk_lang_check_rereturn(err); /* todo if it fails, clean up previous successful */
	}
	*count = n;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_windows_cs_join(mk_lib_mt_thread_windows_cs_pt const thread) mk_lang_noexcept
{
	mk_win_base_dword_t dw;

	mk_lang_assert(thread);

	dw = mk_win_kernel_synchronization_wait_one(thread->m_thread, mk_win_base_infinite); mk_lang_check_return(dw == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_windows_cs_destroy(mk_lib_mt_thread_windows_cs_pt const thread) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(thread);
	mk_lang_assert(thread->m_thread.m_data);

	b = mk_win_kernel_handle_close_handle(thread->m_thread); mk_lang_check_return(b != mk_win_base_false);
	return 0;
}
