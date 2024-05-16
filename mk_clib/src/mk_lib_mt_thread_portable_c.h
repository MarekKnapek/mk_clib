#ifndef mk_include_guard_mk_lib_mt_thread_portable_c
#define mk_include_guard_mk_lib_mt_thread_portable_c


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"

#include <threads.h> /* thrd_t */


#if mk_lang_version_at_least_cpp_17
typedef mk_lang_types_sint_t(*mk_lib_mt_thread_portable_c_callback_t)(mk_lang_types_void_pt) mk_lang_noexcept;
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
mk_lang_types_sint_t mk_lib_mt_thread_dummy(mk_lang_types_void_pt) mk_lang_noexcept;
typedef decltype(&mk_lib_mt_thread_dummy) mk_lib_mt_thread_portable_c_callback_t;
#else
typedef mk_lang_types_sint_t(*mk_lib_mt_thread_portable_c_callback_t)(mk_lang_types_void_pt) mk_lang_noexcept;
#endif

struct mk_lib_mt_thread_portable_c_s
{
	thrd_t m_thread;
};
typedef struct mk_lib_mt_thread_portable_c_s mk_lib_mt_thread_portable_c_t;
typedef mk_lib_mt_thread_portable_c_t const mk_lib_mt_thread_portable_c_ct;
typedef mk_lib_mt_thread_portable_c_t* mk_lib_mt_thread_portable_c_pt;
typedef mk_lib_mt_thread_portable_c_t const* mk_lib_mt_thread_portable_c_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_c_hardware_concurrency(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_c_create(mk_lib_mt_thread_portable_c_pt const thread, mk_lib_mt_thread_portable_c_callback_t const callback, mk_lang_types_void_pt const context) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_c_join(mk_lib_mt_thread_portable_c_pt const thread) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_c_destroy(mk_lib_mt_thread_portable_c_pt const thread) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_thread_portable_c.c"
#endif
#endif
