#include "mk_lib_mt_atomic_counter_portable_cb.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_mutex_portable_c.h"
#include "mk_lib_mt_unique_lock_portable_c.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_cb_construct(mk_lib_mt_atomic_counter_portable_cb_pt const atomic_counter) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(atomic_counter);

	err = mk_lib_mt_mutex_portable_c_construct(&atomic_counter->m_mtx); mk_lang_check_rereturn(err);
	atomic_counter->m_value = 0l;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_cb_destruct(mk_lib_mt_atomic_counter_portable_cb_pt const atomic_counter) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(atomic_counter);

	err = mk_lib_mt_mutex_portable_c_destruct(&atomic_counter->m_mtx); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_cb_increment(mk_lib_mt_atomic_counter_portable_cb_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_portable_c_t ul;
	mk_lib_mt_atomic_counter_portable_cb_int_t post;

	mk_lang_assert(atomic_counter);
	mk_lang_assert(cmp);

	err = mk_lib_mt_unique_lock_exclusive_portable_c_construct(&ul, &atomic_counter->m_mtx); mk_lang_check_rereturn(err);
	post = ++atomic_counter->m_value;
	err = mk_lib_mt_unique_lock_exclusive_portable_c_destruct(&ul); mk_lang_check_rereturn(err);
	*cmp = ((post < 0l) ? (-1) : ((post > 0l) ? (+1) : (0)));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_cb_decrement(mk_lib_mt_atomic_counter_portable_cb_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_portable_c_t ul;
	mk_lib_mt_atomic_counter_portable_cb_int_t post;

	mk_lang_assert(atomic_counter);
	mk_lang_assert(cmp);

	err = mk_lib_mt_unique_lock_exclusive_portable_c_construct(&ul, &atomic_counter->m_mtx); mk_lang_check_rereturn(err);
	post = --atomic_counter->m_value;
	err = mk_lib_mt_unique_lock_exclusive_portable_c_destruct(&ul); mk_lang_check_rereturn(err);
	*cmp = ((post < 0l) ? (-1) : ((post > 0l) ? (+1) : (0)));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_portable_cb_exchange(mk_lib_mt_atomic_counter_portable_cb_pt const atomic_counter, mk_lib_mt_atomic_counter_portable_cb_int_t const desired, mk_lib_mt_atomic_counter_portable_cb_int_pt const previous) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_portable_c_t ul;
	mk_lib_mt_atomic_counter_portable_cb_int_t prev;

	mk_lang_assert(atomic_counter);
	mk_lang_assert(previous);

	err = mk_lib_mt_unique_lock_exclusive_portable_c_construct(&ul, &atomic_counter->m_mtx); mk_lang_check_rereturn(err);
	prev = atomic_counter->m_value;
	atomic_counter->m_value = desired;
	err = mk_lib_mt_unique_lock_exclusive_portable_c_destruct(&ul); mk_lang_check_rereturn(err);
	*previous = prev;
	return 0;
}
