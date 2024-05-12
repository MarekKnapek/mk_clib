#ifndef mk_include_guard_mk_lib_mt_unique_lock
#define mk_include_guard_mk_lib_mt_unique_lock


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_mt_mutex.h"


#if mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
#include "mk_lib_mt_unique_lock_portable_cpp.hpp"
typedef mk_lib_mt_unique_lock_portable_cpp_t mk_lib_mt_unique_lock_impl_t;
#elif mk_lang_version_at_least_c_11
#include "mk_lib_mt_unique_lock_portable_c.h"
typedef mk_lib_mt_unique_lock_portable_c_t mk_lib_mt_unique_lock_impl_t;
#else
#error xxxxxxxxxx todo
#endif


struct mk_lib_mt_unique_lock_s
{
	mk_lib_mt_unique_lock_impl_t m_unique_lock;
};
typedef struct mk_lib_mt_unique_lock_s mk_lib_mt_unique_lock_t;
typedef mk_lib_mt_unique_lock_t const mk_lib_mt_unique_lock_ct;
typedef mk_lib_mt_unique_lock_t* mk_lib_mt_unique_lock_pt;
typedef mk_lib_mt_unique_lock_t const* mk_lib_mt_unique_lock_pct;


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_construct(mk_lib_mt_unique_lock_pt const unique_lock, mk_lib_mt_mutex_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_destruct(mk_lib_mt_unique_lock_pt const unique_lock) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_unique_lock.c"
#endif
#endif
