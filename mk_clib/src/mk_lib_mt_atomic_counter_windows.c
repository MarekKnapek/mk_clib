#include "mk_lib_mt_atomic_counter_windows.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_synchronization.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_windows_construct(mk_lib_mt_atomic_counter_windows_pt const atomic_counter) mk_lang_noexcept
{
	mk_lang_assert(atomic_counter);

	atomic_counter->m_value = 0l;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_windows_destruct(mk_lib_mt_atomic_counter_windows_pt const atomic_counter) mk_lang_noexcept
{
	mk_lang_assert(atomic_counter);

	((mk_lang_types_void_t)(atomic_counter));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_windows_increment(mk_lib_mt_atomic_counter_windows_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lib_mt_atomic_counter_windows_int_t post;

	mk_lang_assert(atomic_counter);
	mk_lang_assert(cmp);

	post = mk_win_kernel_synchronization_interlocked_increment(&atomic_counter->m_value);
	*cmp = ((post < 0l) ? (-1) : ((post > 0l) ? (+1) : (0)));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_windows_decrement(mk_lib_mt_atomic_counter_windows_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lib_mt_atomic_counter_windows_int_t post;

	mk_lang_assert(atomic_counter);
	mk_lang_assert(cmp);

	post = mk_win_kernel_synchronization_interlocked_decrement(&atomic_counter->m_value);
	*cmp = ((post < 0l) ? (-1) : ((post > 0l) ? (+1) : (0)));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_windows_exchange(mk_lib_mt_atomic_counter_windows_pt const atomic_counter, mk_lib_mt_atomic_counter_windows_int_t const desired, mk_lib_mt_atomic_counter_windows_int_pt const previous) mk_lang_noexcept
{
	mk_lib_mt_atomic_counter_windows_int_t prev;

	mk_lang_assert(atomic_counter);
	mk_lang_assert(previous);

	prev = mk_win_kernel_synchronization_interlocked_exchange(&atomic_counter->m_value, desired);
	*previous = prev;
	return 0;
}
