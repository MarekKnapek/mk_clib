#ifndef mk_include_guard_mk_lib_mt_cv_portable_cpp
#define mk_include_guard_mk_lib_mt_cv_portable_cpp


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_mt_unique_lock_portable_cpp.hpp"

#include <condition_variable> /* std::condition_variable */
#include <type_traits> /* std::aligned_storage */


struct mk_lib_mt_cv_portable_cpp_s
{
	#if mk_lang_version_at_least_cpp_23
	alignas(alignof(std::condition_variable)) mk_lang_types_uchar_t m_cv[sizeof(std::condition_variable)];
	#else
	typename std::aligned_storage<sizeof(std::condition_variable), alignof(std::condition_variable)>::type m_cv;
	#endif
};
typedef struct mk_lib_mt_cv_portable_cpp_s mk_lib_mt_cv_portable_cpp_t;
typedef mk_lib_mt_cv_portable_cpp_t const mk_lib_mt_cv_portable_cpp_ct;
typedef mk_lib_mt_cv_portable_cpp_t* mk_lib_mt_cv_portable_cpp_pt;
typedef mk_lib_mt_cv_portable_cpp_t const* mk_lib_mt_cv_portable_cpp_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_cpp_construct(mk_lib_mt_cv_portable_cpp_pt const cv) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_cpp_destruct(mk_lib_mt_cv_portable_cpp_pt const cv) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_cpp_wait_exclusive(mk_lib_mt_cv_portable_cpp_pt const cv, mk_lib_mt_unique_lock_exclusive_portable_cpp_pt const lock) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_cpp_wait_shared(mk_lib_mt_cv_portable_cpp_pt const cv, mk_lib_mt_unique_lock_shared_portable_cpp_pt const lock) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_cpp_notify_one(mk_lib_mt_cv_portable_cpp_pt const cv) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_portable_cpp_notify_all(mk_lib_mt_cv_portable_cpp_pt const cv) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_cv_portable_cpp.cpp"
#endif
#endif
