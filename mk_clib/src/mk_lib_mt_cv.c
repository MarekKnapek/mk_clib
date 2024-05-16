#include "mk_lib_mt_cv.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_mt_unique_lock.h"


#if defined _MSC_VER && defined _MSC_FULL_VER && defined _WIN32_WINNT && _WIN32_WINNT >= 0x0600
#include "mk_lib_mt_cv_windows_srwl.h"
#define mk_lib_mt_cv_impl_construct      mk_lib_mt_cv_windows_srwl_construct
#define mk_lib_mt_cv_impl_destruct       mk_lib_mt_cv_windows_srwl_destruct
#define mk_lib_mt_cv_impl_wait_exclusive mk_lib_mt_cv_windows_srwl_wait_exclusive
#define mk_lib_mt_cv_impl_wait_shared    mk_lib_mt_cv_windows_srwl_wait_shared
#define mk_lib_mt_cv_impl_notify_one     mk_lib_mt_cv_windows_srwl_notify_one
#define mk_lib_mt_cv_impl_notify_all     mk_lib_mt_cv_windows_srwl_notify_all
#elif defined _MSC_VER && defined _MSC_FULL_VER
#include "mk_lib_mt_cv_windows_cs.h"
#define mk_lib_mt_cv_impl_construct      mk_lib_mt_cv_windows_cs_construct
#define mk_lib_mt_cv_impl_destruct       mk_lib_mt_cv_windows_cs_destruct
#define mk_lib_mt_cv_impl_wait_exclusive mk_lib_mt_cv_windows_cs_wait_exclusive
#define mk_lib_mt_cv_impl_wait_shared    mk_lib_mt_cv_windows_cs_wait_shared
#define mk_lib_mt_cv_impl_notify_one     mk_lib_mt_cv_windows_cs_notify_one
#define mk_lib_mt_cv_impl_notify_all     mk_lib_mt_cv_windows_cs_notify_all
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
#include "mk_lib_mt_cv_portable_cpp.hpp"
#define mk_lib_mt_cv_impl_construct      mk_lib_mt_cv_portable_cpp_construct
#define mk_lib_mt_cv_impl_destruct       mk_lib_mt_cv_portable_cpp_destruct
#define mk_lib_mt_cv_impl_wait_exclusive mk_lib_mt_cv_portable_cpp_wait_exclusive
#define mk_lib_mt_cv_impl_wait_shared    mk_lib_mt_cv_portable_cpp_wait_shared
#define mk_lib_mt_cv_impl_notify_one     mk_lib_mt_cv_portable_cpp_notify_one
#define mk_lib_mt_cv_impl_notify_all     mk_lib_mt_cv_portable_cpp_notify_all
#elif mk_lang_version_at_least_c_11
#include "mk_lib_mt_cv_portable_c.h"
#define mk_lib_mt_cv_impl_construct      mk_lib_mt_cv_portable_c_construct
#define mk_lib_mt_cv_impl_destruct       mk_lib_mt_cv_portable_c_destruct
#define mk_lib_mt_cv_impl_wait_exclusive mk_lib_mt_cv_portable_c_wait_exclusive
#define mk_lib_mt_cv_impl_wait_shared    mk_lib_mt_cv_portable_c_wait_shared
#define mk_lib_mt_cv_impl_notify_one     mk_lib_mt_cv_portable_c_notify_one
#define mk_lib_mt_cv_impl_notify_all     mk_lib_mt_cv_portable_c_notify_all
#else
#error xxxxxxxxxx todo
#endif


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_construct(mk_lib_mt_cv_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	if(mk_lang_constexpr_is_constant_evaluated_test)
	{
		return mk_lang_check_line; /* todo */
	}
	else
	{
		return mk_lib_mt_cv_impl_construct(&cv->m_cv);
	}
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_destruct(mk_lib_mt_cv_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	if(mk_lang_constexpr_is_constant_evaluated_test)
	{
		return mk_lang_check_line; /* todo */
	}
	else
	{
		return mk_lib_mt_cv_impl_destruct(&cv->m_cv);
	}
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_wait_exclusive(mk_lib_mt_cv_pt const cv, mk_lib_mt_unique_lock_exclusive_pt const lock) mk_lang_noexcept
{
	mk_lang_assert(cv);
	mk_lang_assert(lock);

	if(mk_lang_constexpr_is_constant_evaluated_test)
	{
		return mk_lang_check_line; /* todo */
	}
	else
	{
		return mk_lib_mt_cv_impl_wait_exclusive(&cv->m_cv, &lock->m_unique_lock_exclusive);
	}
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_wait_shared(mk_lib_mt_cv_pt const cv, mk_lib_mt_unique_lock_shared_pt const lock) mk_lang_noexcept
{
	mk_lang_assert(cv);
	mk_lang_assert(lock);

	if(mk_lang_constexpr_is_constant_evaluated_test)
	{
		return mk_lang_check_line; /* todo */
	}
	else
	{
		return mk_lib_mt_cv_impl_wait_shared(&cv->m_cv, &lock->m_unique_lock_shared);
	}
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_notify_one(mk_lib_mt_cv_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	if(mk_lang_constexpr_is_constant_evaluated_test)
	{
		return mk_lang_check_line; /* todo */
	}
	else
	{
		return mk_lib_mt_cv_impl_notify_one(&cv->m_cv);
	}
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_cv_notify_all(mk_lib_mt_cv_pt const cv) mk_lang_noexcept
{
	mk_lang_assert(cv);

	if(mk_lang_constexpr_is_constant_evaluated_test)
	{
		return mk_lang_check_line; /* todo */
	}
	else
	{
		return mk_lib_mt_cv_impl_notify_all(&cv->m_cv);
	}
}
