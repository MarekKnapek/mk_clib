#ifndef mk_include_guard_mk_lib_mt_mutex
#define mk_include_guard_mk_lib_mt_mutex


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#if mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60
#include "mk_lib_mt_mutex_windows_srwl.h"
typedef mk_lib_mt_mutex_windows_srwl_t mk_lib_mt_mutex_impl_t;
#elif mk_lang_platform == mk_lang_platform_windows
#include "mk_lib_mt_mutex_windows_cs.h"
typedef mk_lib_mt_mutex_windows_cs_t mk_lib_mt_mutex_impl_t;
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
#include "mk_lib_mt_mutex_portable_cpp.hpp"
typedef mk_lib_mt_mutex_portable_cpp_t mk_lib_mt_mutex_impl_t;
#elif mk_lang_version_at_least_c_11
#include "mk_lib_mt_mutex_portable_c.h"
typedef mk_lib_mt_mutex_portable_c_t mk_lib_mt_mutex_impl_t;
#elif defined mk_lib_mt_posix_has && mk_lib_mt_posix_has == 1
#include "mk_lib_mt_mutex_posix.h"
typedef mk_lib_mt_mutex_posix_t mk_lib_mt_mutex_impl_t;
#else
#error xxxxxxxxxx todo
#endif


struct mk_lib_mt_mutex_s
{
	mk_lib_mt_mutex_impl_t m_mutex;
};
typedef struct mk_lib_mt_mutex_s mk_lib_mt_mutex_t;
typedef mk_lib_mt_mutex_t const mk_lib_mt_mutex_ct;
typedef mk_lib_mt_mutex_t* mk_lib_mt_mutex_pt;
typedef mk_lib_mt_mutex_t const* mk_lib_mt_mutex_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_construct(mk_lib_mt_mutex_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_destruct(mk_lib_mt_mutex_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_exclusive_lock(mk_lib_mt_mutex_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_exclusive_unlock(mk_lib_mt_mutex_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_shared_lock(mk_lib_mt_mutex_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_shareds_unlock(mk_lib_mt_mutex_pt const mutex) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_mutex.c"
#endif
#endif
