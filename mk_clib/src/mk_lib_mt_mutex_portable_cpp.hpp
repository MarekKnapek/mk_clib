#ifndef mk_include_guard_mk_lib_mt_mutex_portable_cpp
#define mk_include_guard_mk_lib_mt_mutex_portable_cpp


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"

#include <mutex> /* std::mutex */
#include <type_traits> /* std::aligned_storage */


struct mk_lib_mt_mutex_portable_cpp_s
{
	#if mk_lang_version_at_least_cpp_23
	alignas(alignof(std::mutex)) mk_lang_types_uchar_t m_mutex[sizeof(std::mutex)];
	#else
	typename std::aligned_storage<sizeof(std::mutex), alignof(std::mutex)>::type m_mutex;
	#endif
};
typedef struct mk_lib_mt_mutex_portable_cpp_s mk_lib_mt_mutex_portable_cpp_t;
typedef mk_lib_mt_mutex_portable_cpp_t const mk_lib_mt_mutex_portable_cpp_ct;
typedef mk_lib_mt_mutex_portable_cpp_t* mk_lib_mt_mutex_portable_cpp_pt;
typedef mk_lib_mt_mutex_portable_cpp_t const* mk_lib_mt_mutex_portable_cpp_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_cpp_construct(mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_cpp_destruct(mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_cpp_exclusive_lock(mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_cpp_exclusive_unlock(mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_cpp_shared_lock(mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_cpp_shared_unlock(mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_mutex_portable_cpp.cpp"
#endif
#endif
