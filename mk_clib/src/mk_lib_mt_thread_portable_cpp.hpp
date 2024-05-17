#ifndef mk_include_guard_mk_lib_mt_thread_portable_cpp
#define mk_include_guard_mk_lib_mt_thread_portable_cpp


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"

#include <thread> /* std::thread */
#include <type_traits> /* std::aligned_storage */


#if mk_lang_version_at_least_cpp_17
typedef mk_lang_types_sint_t(*mk_lib_mt_thread_portable_cpp_callback_t)(mk_lang_types_void_pt) mk_lang_noexcept;
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
mk_lang_types_sint_t mk_lib_mt_thread_dummy(mk_lang_types_void_pt) mk_lang_noexcept;
typedef decltype(&mk_lib_mt_thread_dummy) mk_lib_mt_thread_portable_cpp_callback_t;
#else
typedef mk_lang_types_sint_t(*mk_lib_mt_thread_portable_cpp_callback_t)(mk_lang_types_void_pt) mk_lang_noexcept;
#endif

struct mk_lib_mt_thread_portable_cpp_s
{
	typename std::aligned_storage<sizeof(std::thread), alignof(std::thread)>::type m_thread;
};
typedef struct mk_lib_mt_thread_portable_cpp_s mk_lib_mt_thread_portable_cpp_t;
typedef mk_lib_mt_thread_portable_cpp_t const mk_lib_mt_thread_portable_cpp_ct;
typedef mk_lib_mt_thread_portable_cpp_t* mk_lib_mt_thread_portable_cpp_pt;
typedef mk_lib_mt_thread_portable_cpp_t const* mk_lib_mt_thread_portable_cpp_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_cpp_hardware_concurrency(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_cpp_create(mk_lib_mt_thread_portable_cpp_pt const thread, mk_lib_mt_thread_portable_cpp_callback_t const callback, mk_lang_types_void_pt const context) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_cpp_create_all(mk_lib_mt_thread_portable_cpp_pt const threads, mk_lang_types_sint_pt const count, mk_lib_mt_thread_portable_cpp_callback_t const callback, mk_lang_types_void_pt const context) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_cpp_join(mk_lib_mt_thread_portable_cpp_pt const thread) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_portable_cpp_destroy(mk_lib_mt_thread_portable_cpp_pt const thread) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_thread_portable_cpp.cpp"
#endif
#endif
