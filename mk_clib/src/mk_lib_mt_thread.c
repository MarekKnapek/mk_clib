#include "mk_lib_mt_thread.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
#include "mk_lib_mt_thread_portable_cpp.hpp"
#define mk_lib_mt_thread_impl_hardware_concurrency mk_lib_mt_thread_portable_cpp_hardware_concurrency
#define mk_lib_mt_thread_impl_create               mk_lib_mt_thread_portable_cpp_create
#define mk_lib_mt_thread_impl_join                 mk_lib_mt_thread_portable_cpp_join
#define mk_lib_mt_thread_impl_destroy              mk_lib_mt_thread_portable_cpp_destroy
#elif mk_lang_version_at_least_c_11
#include "mk_lib_mt_thread_portable_c.h"
#define mk_lib_mt_thread_impl_hardware_concurrency mk_lib_mt_thread_portable_c_hardware_concurrency
#define mk_lib_mt_thread_impl_create               mk_lib_mt_thread_portable_c_create
#define mk_lib_mt_thread_impl_join                 mk_lib_mt_thread_portable_c_join
#define mk_lib_mt_thread_impl_destroy              mk_lib_mt_thread_portable_c_destroy
#else
#error xxxxxxxxxx todo
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_hardware_concurrency(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_mt_thread_impl_hardware_concurrency();
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_create(mk_lib_mt_thread_pt const thread, mk_lib_mt_thread_callback_t const callback, mk_lang_types_void_pt const context) mk_lang_noexcept
{
	mk_lang_assert(thread);

	return mk_lib_mt_thread_impl_create(&thread->m_thread, callback, context);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_join(mk_lib_mt_thread_pt const thread) mk_lang_noexcept
{
	mk_lang_assert(thread);

	return mk_lib_mt_thread_impl_join(&thread->m_thread);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_destroy(mk_lib_mt_thread_pt const thread) mk_lang_noexcept
{
	mk_lang_assert(thread);

	return mk_lib_mt_thread_impl_destroy(&thread->m_thread);
}
