#include "mk_lib_mt_atomic_counter_portable_ca.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#if mk_lang_version_at_least_c_11 && !defined __STDC_NO_ATOMICS__


#include <stdatomic.h>


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_ca_construct(mk_lib_mt_atomic_counter_portable_ca_pt const atomic_counter) mk_lang_noexcept
{
	mk_lang_assert(atomic_counter);

	atomic_store_explicit(&atomic_counter->m_value, 0l, memory_order_relaxed);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_ca_destruct(mk_lib_mt_atomic_counter_portable_ca_pt const atomic_counter) mk_lang_noexcept
{
	mk_lang_assert(atomic_counter);

	((mk_lang_types_void_t)(atomic_counter));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_ca_increment(mk_lib_mt_atomic_counter_portable_ca_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lib_mt_atomic_counter_portable_ca_int_t prev;
	mk_lib_mt_atomic_counter_portable_ca_int_t post;

	mk_lang_assert(atomic_counter);
	mk_lang_assert(cmp);

	prev = atomic_fetch_add_explicit(&atomic_counter->m_value, 1, memory_order_acq_rel);
	post = prev + 1;
	*cmp = ((post < 0l) ? (-1) : ((post > 0l) ? (+1) : (0)));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_ca_decrement(mk_lib_mt_atomic_counter_portable_ca_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lib_mt_atomic_counter_portable_ca_int_t prev;
	mk_lib_mt_atomic_counter_portable_ca_int_t post;

	mk_lang_assert(atomic_counter);
	mk_lang_assert(cmp);

	prev = atomic_fetch_sub_explicit(&atomic_counter->m_value, 1, memory_order_acq_rel);
	post = prev - 1;
	*cmp = ((post < 0l) ? (-1) : ((post > 0l) ? (+1) : (0)));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_ca_exchange(mk_lib_mt_atomic_counter_portable_ca_pt const atomic_counter, mk_lib_mt_atomic_counter_portable_ca_int_t const desired, mk_lib_mt_atomic_counter_portable_ca_int_pt const previous) mk_lang_noexcept
{
	mk_lib_mt_atomic_counter_portable_ca_int_t prev;

	mk_lang_assert(atomic_counter);
	mk_lang_assert(previous);

	prev = atomic_exchange_explicit(&atomic_counter->m_value, desired, memory_order_acq_rel);
	*previous = prev;
	return 0;
}


#endif
