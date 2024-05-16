#ifndef mk_include_guard_mk_lib_mt_cv
#define mk_include_guard_mk_lib_mt_cv


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_mt_unique_lock.h"


#if defined _MSC_VER && defined _MSC_FULL_VER
#include "mk_lib_mt_cv_windows_cs.h"
typedef mk_lib_mt_cv_windows_cs_t mk_lib_mt_cv_impl_t;
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
#include "mk_lib_mt_cv_portable_cpp.hpp"
typedef mk_lib_mt_cv_portable_cpp_t mk_lib_mt_cv_impl_t;
#elif mk_lang_version_at_least_c_11
#include "mk_lib_mt_cv_portable_c.h"
typedef mk_lib_mt_cv_portable_c_t mk_lib_mt_cv_impl_t;
#else
#error xxxxxxxxxx todo
#endif


struct mk_lib_mt_cv_s
{
	mk_lib_mt_cv_impl_t m_cv;
};
typedef struct mk_lib_mt_cv_s mk_lib_mt_cv_t;
typedef mk_lib_mt_cv_t const mk_lib_mt_cv_ct;
typedef mk_lib_mt_cv_t* mk_lib_mt_cv_pt;
typedef mk_lib_mt_cv_t const* mk_lib_mt_cv_pct;


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_construct(mk_lib_mt_cv_pt const cv) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_destruct(mk_lib_mt_cv_pt const cv) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_wait_exclusive(mk_lib_mt_cv_pt const cv, mk_lib_mt_unique_lock_exclusive_pt const lock) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_wait_shared(mk_lib_mt_cv_pt const cv, mk_lib_mt_unique_lock_shared_pt const lock) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_notify_one(mk_lib_mt_cv_pt const cv) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_notify_all(mk_lib_mt_cv_pt const cv) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_cv.c"
#endif
#endif
