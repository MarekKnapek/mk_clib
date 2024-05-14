#ifndef mk_include_guard_mk_lib_mt_mutex_portable_cpp
#define mk_include_guard_mk_lib_mt_mutex_portable_cpp


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#include <mutex> /* std::mutex */
#include <type_traits> /* std::aligned_storage */


struct mk_lib_mt_mutex_portable_cpp_s
{
	typename std::aligned_storage<sizeof(std::mutex), alignof(std::mutex)>::type m_mutex;
};
typedef struct mk_lib_mt_mutex_portable_cpp_s mk_lib_mt_mutex_portable_cpp_t;
typedef mk_lib_mt_mutex_portable_cpp_t const mk_lib_mt_mutex_portable_cpp_ct;
typedef mk_lib_mt_mutex_portable_cpp_t* mk_lib_mt_mutex_portable_cpp_pt;
typedef mk_lib_mt_mutex_portable_cpp_t const* mk_lib_mt_mutex_portable_cpp_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_cpp_construct(mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_cpp_destruct(mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_cpp_lock(mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_cpp_unlock(mk_lib_mt_mutex_portable_cpp_pt const mutex) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_mutex_portable_cpp.cpp"
#endif
#endif