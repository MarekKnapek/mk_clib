#ifndef mk_include_guard_mk_lib_mt_unique_lock
#define mk_include_guard_mk_lib_mt_unique_lock


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_mt_mutex.h"


#if mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60
#include "mk_lib_mt_unique_lock_windows_srwl.h"
typedef mk_lib_mt_unique_lock_exclusive_windows_srwl_t mk_lib_mt_unique_lock_exclusive_impl_t;
typedef mk_lib_mt_unique_lock_shared_windows_srwl_t    mk_lib_mt_unique_lock_shared_impl_t;
#elif mk_lang_platform == mk_lang_platform_windows
#include "mk_lib_mt_unique_lock_windows_cs.h"
typedef mk_lib_mt_unique_lock_exclusive_windows_cs_t mk_lib_mt_unique_lock_exclusive_impl_t;
typedef mk_lib_mt_unique_lock_shared_windows_cs_t    mk_lib_mt_unique_lock_shared_impl_t;
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
#include "mk_lib_mt_unique_lock_portable_cpp.hpp"
typedef mk_lib_mt_unique_lock_exclusive_portable_cpp_t mk_lib_mt_unique_lock_exclusive_impl_t;
typedef mk_lib_mt_unique_lock_shared_portable_cpp_t    mk_lib_mt_unique_lock_shared_impl_t;
#elif mk_lang_version_at_least_c_11
#include "mk_lib_mt_unique_lock_portable_c.h"
typedef mk_lib_mt_unique_lock_exclusive_portable_c_t mk_lib_mt_unique_lock_exclusive_impl_t;
typedef mk_lib_mt_unique_lock_shared_portable_c_t    mk_lib_mt_unique_lock_shared_impl_t;
#elif defined mk_lib_mt_posix_has && mk_lib_mt_posix_has == 1
#include "mk_lib_mt_unique_lock_posix.h"
typedef mk_lib_mt_unique_lock_exclusive_posix_t mk_lib_mt_unique_lock_exclusive_impl_t;
typedef mk_lib_mt_unique_lock_shared_posix_t    mk_lib_mt_unique_lock_shared_impl_t;
#else
#error xxxxxxxxxx todo
#endif


struct mk_lib_mt_unique_lock_exclusive_s
{
	mk_lib_mt_unique_lock_exclusive_impl_t m_unique_lock_exclusive;
};
typedef struct mk_lib_mt_unique_lock_exclusive_s mk_lib_mt_unique_lock_exclusive_t;
typedef mk_lib_mt_unique_lock_exclusive_t const mk_lib_mt_unique_lock_exclusive_ct;
typedef mk_lib_mt_unique_lock_exclusive_t* mk_lib_mt_unique_lock_exclusive_pt;
typedef mk_lib_mt_unique_lock_exclusive_t const* mk_lib_mt_unique_lock_exclusive_pct;

struct mk_lib_mt_unique_lock_shared_s
{
	mk_lib_mt_unique_lock_shared_impl_t m_unique_lock_shared;
};
typedef struct mk_lib_mt_unique_lock_shared_s mk_lib_mt_unique_lock_shared_t;
typedef mk_lib_mt_unique_lock_shared_t const mk_lib_mt_unique_lock_shared_ct;
typedef mk_lib_mt_unique_lock_shared_t* mk_lib_mt_unique_lock_shared_pt;
typedef mk_lib_mt_unique_lock_shared_t const* mk_lib_mt_unique_lock_shared_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_exclusive_construct(mk_lib_mt_unique_lock_exclusive_pt const unique_lock_exclusive, mk_lib_mt_mutex_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_exclusive_destruct(mk_lib_mt_unique_lock_exclusive_pt const unique_lock_exclusive) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_shared_construct(mk_lib_mt_unique_lock_shared_pt const unique_lock_shared, mk_lib_mt_mutex_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_shared_destruct(mk_lib_mt_unique_lock_shared_pt const unique_lock_shared) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_unique_lock.c"
#endif
#endif
