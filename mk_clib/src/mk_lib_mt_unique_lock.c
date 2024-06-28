#include "mk_lib_mt_unique_lock.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
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
#define mk_lib_mt_unique_lock_exclusive_impl_construct mk_lib_mt_unique_lock_exclusive_windows_srwl_construct
#define mk_lib_mt_unique_lock_exclusive_impl_destruct  mk_lib_mt_unique_lock_exclusive_windows_srwl_destruct
#define mk_lib_mt_unique_lock_shared_impl_construct    mk_lib_mt_unique_lock_shared_windows_srwl_construct
#define mk_lib_mt_unique_lock_shared_impl_destruct     mk_lib_mt_unique_lock_shared_windows_srwl_destruct
#elif mk_lang_platform == mk_lang_platform_windows
#include "mk_lib_mt_unique_lock_windows_cs.h"
#define mk_lib_mt_unique_lock_exclusive_impl_construct mk_lib_mt_unique_lock_exclusive_windows_cs_construct
#define mk_lib_mt_unique_lock_exclusive_impl_destruct  mk_lib_mt_unique_lock_exclusive_windows_cs_destruct
#define mk_lib_mt_unique_lock_shared_impl_construct    mk_lib_mt_unique_lock_shared_windows_cs_construct
#define mk_lib_mt_unique_lock_shared_impl_destruct     mk_lib_mt_unique_lock_shared_windows_cs_destruct
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
#include "mk_lib_mt_unique_lock_portable_cpp.hpp"
#define mk_lib_mt_unique_lock_exclusive_impl_construct mk_lib_mt_unique_lock_exclusive_portable_cpp_construct
#define mk_lib_mt_unique_lock_exclusive_impl_destruct  mk_lib_mt_unique_lock_exclusive_portable_cpp_destruct
#define mk_lib_mt_unique_lock_shared_impl_construct    mk_lib_mt_unique_lock_shared_portable_cpp_construct
#define mk_lib_mt_unique_lock_shared_impl_destruct     mk_lib_mt_unique_lock_shared_portable_cpp_destruct
#elif mk_lang_version_at_least_c_11
#include "mk_lib_mt_unique_lock_portable_c.h"
#define mk_lib_mt_unique_lock_exclusive_impl_construct mk_lib_mt_unique_lock_exclusive_portable_c_construct
#define mk_lib_mt_unique_lock_exclusive_impl_destruct  mk_lib_mt_unique_lock_exclusive_portable_c_destruct
#define mk_lib_mt_unique_lock_shared_impl_construct    mk_lib_mt_unique_lock_shared_portable_c_construct
#define mk_lib_mt_unique_lock_shared_impl_destruct     mk_lib_mt_unique_lock_shared_portable_c_destruct
#elif defined mk_lib_mt_posix_has && mk_lib_mt_posix_has == 1
#include "mk_lib_mt_unique_lock_posix.h"
#define mk_lib_mt_unique_lock_exclusive_impl_construct mk_lib_mt_unique_lock_exclusive_posix_construct
#define mk_lib_mt_unique_lock_exclusive_impl_destruct  mk_lib_mt_unique_lock_exclusive_posix_destruct
#define mk_lib_mt_unique_lock_shared_impl_construct    mk_lib_mt_unique_lock_shared_posix_construct
#define mk_lib_mt_unique_lock_shared_impl_destruct     mk_lib_mt_unique_lock_shared_posix_destruct
#else
#error xxxxxxxxxx todo
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_exclusive_construct(mk_lib_mt_unique_lock_exclusive_pt const unique_lock_exclusive, mk_lib_mt_mutex_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(unique_lock_exclusive);
	mk_lang_assert(mutex);

	return mk_lib_mt_unique_lock_exclusive_impl_construct(&unique_lock_exclusive->m_unique_lock_exclusive, &mutex->m_mutex);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_exclusive_destruct(mk_lib_mt_unique_lock_exclusive_pt const unique_lock_exclusive) mk_lang_noexcept
{
	mk_lang_assert(unique_lock_exclusive);

	return mk_lib_mt_unique_lock_exclusive_impl_destruct(&unique_lock_exclusive->m_unique_lock_exclusive);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_shared_construct(mk_lib_mt_unique_lock_shared_pt const unique_lock_shared, mk_lib_mt_mutex_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(unique_lock_shared);
	mk_lang_assert(mutex);

	return mk_lib_mt_unique_lock_shared_impl_construct(&unique_lock_shared->m_unique_lock_shared, &mutex->m_mutex);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_shared_destruct(mk_lib_mt_unique_lock_shared_pt const unique_lock_shared) mk_lang_noexcept
{
	mk_lang_assert(unique_lock_shared);

	return mk_lib_mt_unique_lock_shared_impl_destruct(&unique_lock_shared->m_unique_lock_shared);
}
