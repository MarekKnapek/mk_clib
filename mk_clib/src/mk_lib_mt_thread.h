#ifndef mk_include_guard_mk_lib_mt_thread
#define mk_include_guard_mk_lib_mt_thread


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#if defined _MSC_VER && defined _MSC_FULL_VER && defined _WIN32_WINNT && _WIN32_WINNT >= 0x0601
#define mk_lib_mt_thread_has 1
#include "mk_lib_mt_thread_windows_pg.h"
typedef mk_lib_mt_thread_windows_pg_t mk_lib_mt_thread_impl_t;
#elif defined _MSC_VER && defined _MSC_FULL_VER && defined _WIN32_WINNT && _WIN32_WINNT >= 0x0600
#define mk_lib_mt_thread_has 1
#include "mk_lib_mt_thread_windows_srwl.h"
typedef mk_lib_mt_thread_windows_srwl_t mk_lib_mt_thread_impl_t;
#elif defined _MSC_VER && defined _MSC_FULL_VER
#define mk_lib_mt_thread_has 1
#include "mk_lib_mt_thread_windows_cs.h"
typedef mk_lib_mt_thread_windows_cs_t mk_lib_mt_thread_impl_t;
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
#define mk_lib_mt_thread_has 1
#include "mk_lib_mt_thread_portable_cpp.hpp"
typedef mk_lib_mt_thread_portable_cpp_t mk_lib_mt_thread_impl_t;
#elif mk_lang_version_at_least_c_11 && !defined __STDC_NO_THREADS__
#define mk_lib_mt_thread_has 1
#include "mk_lib_mt_thread_portable_c.h"
typedef mk_lib_mt_thread_portable_c_t mk_lib_mt_thread_impl_t;
#else
#define mk_lib_mt_thread_has 0
#endif


#if mk_lib_mt_thread_has


#if mk_lang_version_at_least_cpp_17
typedef mk_lang_types_sint_t(*mk_lib_mt_thread_callback_t)(mk_lang_types_void_pt) mk_lang_noexcept;
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
mk_lang_types_sint_t mk_lib_mt_thread_dummy(mk_lang_types_void_pt) mk_lang_noexcept;
typedef decltype(&mk_lib_mt_thread_dummy) mk_lib_mt_thread_callback_t;
#else
typedef mk_lang_types_sint_t(*mk_lib_mt_thread_callback_t)(mk_lang_types_void_pt) mk_lang_noexcept;
#endif

struct mk_lib_mt_thread_s
{
	mk_lib_mt_thread_impl_t m_thread;
};
typedef struct mk_lib_mt_thread_s mk_lib_mt_thread_t;
typedef mk_lib_mt_thread_t const mk_lib_mt_thread_ct;
typedef mk_lib_mt_thread_t* mk_lib_mt_thread_pt;
typedef mk_lib_mt_thread_t const* mk_lib_mt_thread_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_hardware_concurrency(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_create(mk_lib_mt_thread_pt const thread, mk_lib_mt_thread_callback_t const callback, mk_lang_types_void_pt const context) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_create_all(mk_lib_mt_thread_pt const threads, mk_lang_types_sint_pt const count, mk_lib_mt_thread_callback_t const callback, mk_lang_types_void_pt const context) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_join(mk_lib_mt_thread_pt const thread) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_destroy(mk_lib_mt_thread_pt const thread) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_thread.c"
#endif
#endif
