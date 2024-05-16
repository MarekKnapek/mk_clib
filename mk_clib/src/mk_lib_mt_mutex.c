#include "mk_lib_mt_mutex.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
#include "mk_lib_mt_mutex_portable_cpp.hpp"
#define mk_lib_mt_mutex_impl_construct        mk_lib_mt_mutex_portable_cpp_construct
#define mk_lib_mt_mutex_impl_destruct         mk_lib_mt_mutex_portable_cpp_destruct
#define mk_lib_mt_mutex_impl_exclusive_lock   mk_lib_mt_mutex_portable_cpp_exclusive_lock
#define mk_lib_mt_mutex_impl_exclusive_unlock mk_lib_mt_mutex_portable_cpp_exclusive_unlock
#define mk_lib_mt_mutex_impl_shared_lock      mk_lib_mt_mutex_portable_cpp_shared_lock
#define mk_lib_mt_mutex_impl_shared_unlock    mk_lib_mt_mutex_portable_cpp_shared_unlock
#elif mk_lang_version_at_least_c_11
#include "mk_lib_mt_mutex_portable_c.h"
#define mk_lib_mt_mutex_impl_construct        mk_lib_mt_mutex_portable_c_construct
#define mk_lib_mt_mutex_impl_destruct         mk_lib_mt_mutex_portable_c_destruct
#define mk_lib_mt_mutex_impl_exclusive_lock   mk_lib_mt_mutex_portable_c_exclusive_lock
#define mk_lib_mt_mutex_impl_exclusive_unlock mk_lib_mt_mutex_portable_c_exclusive_unlock
#define mk_lib_mt_mutex_impl_shared_lock      mk_lib_mt_mutex_portable_c_shared_lock
#define mk_lib_mt_mutex_impl_shared_unlock    mk_lib_mt_mutex_portable_c_shared_unlock
#else
#error xxxxxxxxxx todo
#endif


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_construct(mk_lib_mt_mutex_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	if(mk_lang_constexpr_is_constant_evaluated_test)
	{
		return mk_lang_check_line; /* todo */
	}
	else
	{
		return mk_lib_mt_mutex_impl_construct(&mutex->m_mutex);
	}
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_destruct(mk_lib_mt_mutex_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	if(mk_lang_constexpr_is_constant_evaluated_test)
	{
		return mk_lang_check_line; /* todo */
	}
	else
	{
		return mk_lib_mt_mutex_impl_destruct(&mutex->m_mutex);
	}
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_exclusive_lock(mk_lib_mt_mutex_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	if(mk_lang_constexpr_is_constant_evaluated_test)
	{
		return mk_lang_check_line; /* todo */
	}
	else
	{
		return mk_lib_mt_mutex_impl_exclusive_lock(&mutex->m_mutex);
	}
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_exclusive_unlock(mk_lib_mt_mutex_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	if(mk_lang_constexpr_is_constant_evaluated_test)
	{
		return mk_lang_check_line; /* todo */
	}
	else
	{
		return mk_lib_mt_mutex_impl_exclusive_unlock(&mutex->m_mutex);
	}
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_shared_lock(mk_lib_mt_mutex_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	if(mk_lang_constexpr_is_constant_evaluated_test)
	{
		return mk_lang_check_line; /* todo */
	}
	else
	{
		return mk_lib_mt_mutex_impl_shared_lock(&mutex->m_mutex);
	}
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_shared_unlock(mk_lib_mt_mutex_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(mutex);

	if(mk_lang_constexpr_is_constant_evaluated_test)
	{
		return mk_lang_check_line; /* todo */
	}
	else
	{
		return mk_lib_mt_mutex_impl_shared_unlock(&mutex->m_mutex);
	}
}
