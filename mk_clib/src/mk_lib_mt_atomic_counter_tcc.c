#include "mk_lib_mt_atomic_counter_tcc.h"

#include "mk_lang_assert.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


#if defined __TINYC__ && __TINYC__ >= 928 /* todo version */


mk_lang_nodiscard static mk_lang_inline mk_lib_mt_atomic_counter_tcc_int_t mk_lib_mt_atomic_counter_tcc_inc(mk_lib_mt_atomic_counter_tcc_int_t volatile* const addend) mk_lang_noexcept
{
	mk_lang_types_uchar_t c;
	mk_lang_types_uchar_t s;

	mk_lang_assert(addend);

	__asm__ __volatile__
	(
		"lock ; addl $1, %0; sete %1 ; sets %2"
		:"=m" (*addend), "=qm" (c), "=qm" (s)
		:"m" (*addend) : "memory"
	);
	return (c != 0 ? 0l : (s != 0 ? -1l : +1l));
}

mk_lang_nodiscard static mk_lang_inline mk_lib_mt_atomic_counter_tcc_int_t mk_lib_mt_atomic_counter_tcc_dec(mk_lib_mt_atomic_counter_tcc_int_t volatile* const addend) mk_lang_noexcept
{
	mk_lang_types_uchar_t c;
	mk_lang_types_uchar_t s;

	mk_lang_assert(addend);

	__asm__ __volatile__
	(
		"lock ; subl $1, %0; sete %1 ; sets %2"
		:"=m" (*addend), "=qm" (c), "=qm" (s)
		:"m" (*addend) : "memory"
	);
	return (c != 0 ? 0l : (s != 0 ? -1l : +1l));
}

mk_lang_nodiscard static mk_lang_inline mk_lib_mt_atomic_counter_tcc_int_t mk_lib_mt_atomic_counter_tcc_xchg(mk_lib_mt_atomic_counter_tcc_int_t volatile* const target, mk_lib_mt_atomic_counter_tcc_int_t const desired) mk_lang_noexcept
{
	mk_lang_types_uchar_t c;
	mk_lang_types_uchar_t s;

	mk_lang_assert(target);

	__asm__ __volatile
	(
		"lock ; xchgl %0, %1"
		: "=r"(desired)
		: "m"(*target),"0"(desired)
		: "memory"
	);
	return desired;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_tcc_construct(mk_lib_mt_atomic_counter_tcc_pt const atomic_counter) mk_lang_noexcept
{
	mk_lang_assert(atomic_counter);

	atomic_counter->m_value = 0l;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_tcc_destruct(mk_lib_mt_atomic_counter_tcc_pt const atomic_counter) mk_lang_noexcept
{
	mk_lang_assert(atomic_counter);

	((mk_lang_types_void_t)(atomic_counter));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_tcc_increment(mk_lib_mt_atomic_counter_tcc_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lib_mt_atomic_counter_tcc_int_t post;

	mk_lang_assert(atomic_counter);
	mk_lang_assert(cmp);

	post = mk_lib_mt_atomic_counter_tcc_inc(&atomic_counter->m_value);
	*cmp = ((post < 0l) ? (-1) : ((post > 0l) ? (+1) : (0)));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_tcc_decrement(mk_lib_mt_atomic_counter_tcc_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lib_mt_atomic_counter_tcc_int_t post;

	mk_lang_assert(atomic_counter);
	mk_lang_assert(cmp);

	post = mk_lib_mt_atomic_counter_tcc_dec(&atomic_counter->m_value);
	*cmp = ((post < 0l) ? (-1) : ((post > 0l) ? (+1) : (0)));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_tcc_exchange(mk_lib_mt_atomic_counter_tcc_pt const atomic_counter, mk_lib_mt_atomic_counter_tcc_int_t const desired, mk_lib_mt_atomic_counter_tcc_int_pt const previous) mk_lang_noexcept
{
	mk_lib_mt_atomic_counter_tcc_int_t prev;

	mk_lang_assert(atomic_counter);
	mk_lang_assert(previous);

	prev = mk_lib_mt_atomic_counter_tcc_xchg(&atomic_counter->m_value, desired);
	*previous = prev;
	return 0;
}


#endif
