#include "mk_lib_mt_atomic_counter_portable_cpp.hpp"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#include <atomic>


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_cpp_construct(mk_lib_mt_atomic_counter_portable_cpp_pt const atomic_counter) mk_lang_noexcept
{
	mk_lang_assert(atomic_counter);

	atomic_counter->m_value.store(0l, std::memory_order_relaxed);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_cpp_destruct(mk_lib_mt_atomic_counter_portable_cpp_pt const atomic_counter) mk_lang_noexcept
{
	mk_lang_assert(atomic_counter);

	((mk_lang_types_void_t)(atomic_counter));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_cpp_increment(mk_lib_mt_atomic_counter_portable_cpp_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lang_types_slong_t post;

	mk_lang_assert(atomic_counter);
	mk_lang_assert(cmp);

	post = atomic_counter->m_value.operator++();
	*cmp = ((post < 0l) ? (-1) : ((post > 0l) ? (+1) : (0)));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_cpp_decrement(mk_lib_mt_atomic_counter_portable_cpp_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lang_types_slong_t post;

	mk_lang_assert(atomic_counter);
	mk_lang_assert(cmp);

	post = atomic_counter->m_value.operator--();
	*cmp = ((post < 0l) ? (-1) : ((post > 0l) ? (+1) : (0)));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_cpp_exchange(mk_lib_mt_atomic_counter_portable_cpp_pt const atomic_counter, mk_lib_mt_atomic_counter_portable_cpp_int_t const desired, mk_lib_mt_atomic_counter_portable_cpp_int_pt const previous) mk_lang_noexcept
{
	mk_lang_types_slong_t prev;

	mk_lang_assert(atomic_counter);
	mk_lang_assert(previous);

	prev = atomic_counter->m_value.exchange(desired, std::memory_order_acq_rel);
	*previous = prev;
	return 0;
}
