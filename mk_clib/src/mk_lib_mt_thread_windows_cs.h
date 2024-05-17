#ifndef mk_include_guard_mk_lib_mt_thread_windows_cs
#define mk_include_guard_mk_lib_mt_thread_windows_cs


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_win_base.h"


#if mk_lang_version_at_least_cpp_17
typedef mk_lang_types_sint_t(*mk_lib_mt_thread_windows_cs_callback_t)(mk_lang_types_void_pt) mk_lang_noexcept;
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
mk_lang_types_sint_t mk_lib_mt_thread_dummy(mk_lang_types_void_pt) mk_lang_noexcept;
typedef decltype(&mk_lib_mt_thread_dummy) mk_lib_mt_thread_windows_cs_callback_t;
#else
typedef mk_lang_types_sint_t(*mk_lib_mt_thread_windows_cs_callback_t)(mk_lang_types_void_pt) mk_lang_noexcept;
#endif

struct mk_lib_mt_thread_windows_cs_s
{
	mk_win_base_handle_t m_thread;
};
typedef struct mk_lib_mt_thread_windows_cs_s mk_lib_mt_thread_windows_cs_t;
typedef mk_lib_mt_thread_windows_cs_t const mk_lib_mt_thread_windows_cs_ct;
typedef mk_lib_mt_thread_windows_cs_t* mk_lib_mt_thread_windows_cs_pt;
typedef mk_lib_mt_thread_windows_cs_t const* mk_lib_mt_thread_windows_cs_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_windows_cs_hardware_concurrency(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_windows_cs_create(mk_lib_mt_thread_windows_cs_pt const thread, mk_lib_mt_thread_windows_cs_callback_t const callback, mk_lang_types_void_pt const context) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_windows_cs_create_all(mk_lib_mt_thread_windows_cs_pt const threads, mk_lang_types_sint_pt const count, mk_lib_mt_thread_windows_cs_callback_t const callback, mk_lang_types_void_pt const context) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_windows_cs_join(mk_lib_mt_thread_windows_cs_pt const thread) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_thread_windows_cs_destroy(mk_lib_mt_thread_windows_cs_pt const thread) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_thread_windows_cs.c"
#endif
#endif
