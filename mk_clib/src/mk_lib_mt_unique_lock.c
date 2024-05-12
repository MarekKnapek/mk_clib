#include "mk_lib_mt_unique_lock.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_mt_mutex.h"


#if mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
#include "mk_lib_mt_unique_lock_portable_cpp.hpp"
#define mk_lib_mt_unique_lock_impl_construct mk_lib_mt_unique_lock_portable_cpp_construct
#define mk_lib_mt_unique_lock_impl_destruct  mk_lib_mt_unique_lock_portable_cpp_destruct
#elif mk_lang_version_at_least_c_11
#include "mk_lib_mt_unique_lock_portable_c.h"
#define mk_lib_mt_unique_lock_impl_construct mk_lib_mt_unique_lock_portable_c_construct
#define mk_lib_mt_unique_lock_impl_destruct  mk_lib_mt_unique_lock_portable_c_destruct
#else
#error xxxxxxxxxx todo
#endif


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_construct(mk_lib_mt_unique_lock_pt const unique_lock, mk_lib_mt_mutex_pt const mutex) mk_lang_noexcept
{
	mk_lang_assert(unique_lock);
	mk_lang_assert(mutex);

	if(mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_check_return(mk_lang_false); /* todo */
	}
	else
	{
		return mk_lib_mt_unique_lock_impl_construct(&unique_lock->m_unique_lock, &mutex->m_mutex);
	}
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_destruct(mk_lib_mt_unique_lock_pt const unique_lock) mk_lang_noexcept
{
	mk_lang_assert(unique_lock);

	if(mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_check_return(mk_lang_false); /* todo */
	}
	else
	{
		return mk_lib_mt_unique_lock_impl_destruct(&unique_lock->m_unique_lock);
	}
}
