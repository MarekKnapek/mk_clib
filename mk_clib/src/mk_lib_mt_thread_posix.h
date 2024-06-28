#ifndef mk_include_guard_mk_lib_mt_thread_posix
#define mk_include_guard_mk_lib_mt_thread_posix


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#if defined mk_lib_mt_posix_has && mk_lib_mt_posix_has == 1


#include <pthread.h> /* pthread_t */


#if mk_lang_version_at_least_cpp_17
typedef mk_lang_types_sint_t(*mk_lib_mt_thread_posix_callback_t)(mk_lang_types_void_pt) mk_lang_noexcept;
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
mk_lang_types_sint_t mk_lib_mt_thread_dummy(mk_lang_types_void_pt) mk_lang_noexcept;
typedef decltype(&mk_lib_mt_thread_dummy) mk_lib_mt_thread_posix_callback_t;
#else
typedef mk_lang_types_sint_t(*mk_lib_mt_thread_posix_callback_t)(mk_lang_types_void_pt) mk_lang_noexcept;
#endif

struct mk_lib_mt_thread_posix_s
{
	pthread_t m_thread;
};
typedef struct mk_lib_mt_thread_posix_s mk_lib_mt_thread_posix_t;
typedef mk_lib_mt_thread_posix_t const mk_lib_mt_thread_posix_ct;
typedef mk_lib_mt_thread_posix_t* mk_lib_mt_thread_posix_pt;
typedef mk_lib_mt_thread_posix_t const* mk_lib_mt_thread_posix_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_posix_hardware_concurrency(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_posix_create(mk_lib_mt_thread_posix_pt const thread, mk_lib_mt_thread_posix_callback_t const callback, mk_lang_types_void_pt const context) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_posix_create_all(mk_lib_mt_thread_posix_pt const threads, mk_lang_types_sint_pt const count, mk_lib_mt_thread_posix_callback_t const callback, mk_lang_types_void_pt const context) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_posix_join(mk_lib_mt_thread_posix_pt const thread) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_posix_destroy(mk_lib_mt_thread_posix_pt const thread) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_thread_posix.c"
#endif
#endif
