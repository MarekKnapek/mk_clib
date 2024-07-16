#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_memory_order.h"

#include <stdatomic.h>


#include "mk_lib_mt_atomic_portable_ca_inl_defd.h"


mk_lang_nodiscard static mk_lang_inline memory_order mk_lib_mt_atomic_portable_ca_inl_defd_memory_order_convert(mk_lib_mt_memory_order_t const mo) mk_lang_noexcept
{
	memory_order ret;

	switch(mo)
	{
		case mk_lib_mt_memory_order_e_relaxed: ret = memory_order_relaxed; break;
		case mk_lib_mt_memory_order_e_acquire: ret = memory_order_acquire; break;
		case mk_lib_mt_memory_order_e_release: ret = memory_order_release; break;
		case mk_lib_mt_memory_order_e_acq_rel: ret = memory_order_acq_rel; break;
		case mk_lib_mt_memory_order_e_seq_cst: ret = memory_order_seq_cst; break;
		case mk_lib_mt_memory_order_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_ca_inl_defd_construct(mk_lib_mt_atomic_portable_ca_inl_defd_pt const atomyc) mk_lang_noexcept
{
	mk_lang_assert(atomyc);

	((mk_lang_types_void_t)(atomyc));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_ca_inl_defd_destroy(mk_lib_mt_atomic_portable_ca_inl_defd_pt const atomyc) mk_lang_noexcept
{
	mk_lang_assert(atomyc);

	((mk_lang_types_void_t)(atomyc));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_ca_inl_defd_store(mk_lib_mt_atomic_portable_ca_inl_defd_pt const atomyc, mk_lib_mt_atomic_portable_ca_inl_defd_type_pct const desired, mk_lib_mt_memory_order_t const mo) mk_lang_noexcept
{
	mk_lang_assert(atomyc);
	mk_lang_assert(desired);

	atomic_store_explicit(&atomyc->m_atomyc, *desired, mk_lib_mt_atomic_portable_ca_inl_defd_memory_order_convert(mo));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_ca_inl_defd_load(mk_lib_mt_atomic_portable_ca_inl_defd_pct const atomyc, mk_lib_mt_atomic_portable_ca_inl_defd_type_pt const dst, mk_lib_mt_memory_order_t const mo) mk_lang_noexcept
{
	mk_lang_assert(atomyc);
	mk_lang_assert(dst);

	*dst = atomic_load_explicit(&atomyc->m_atomyc, mk_lib_mt_atomic_portable_ca_inl_defd_memory_order_convert(mo));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_ca_inl_defd_fetch_add(mk_lib_mt_atomic_portable_ca_inl_defd_pt const atomyc, mk_lib_mt_atomic_portable_ca_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_ca_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(atomyc);
	mk_lang_assert(arg);
	mk_lang_assert(dst);

	*dst = atomic_fetch_add_explicit(&atomyc->m_atomyc, *arg, mk_lib_mt_atomic_portable_ca_inl_defd_memory_order_convert(mo));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_ca_inl_defd_fetch_sub(mk_lib_mt_atomic_portable_ca_inl_defd_pt const atomyc, mk_lib_mt_atomic_portable_ca_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_ca_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(atomyc);
	mk_lang_assert(arg);
	mk_lang_assert(dst);

	*dst = atomic_fetch_sub_explicit(&atomyc->m_atomyc, *arg, mk_lib_mt_atomic_portable_ca_inl_defd_memory_order_convert(mo));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_ca_inl_defd_fetch_and(mk_lib_mt_atomic_portable_ca_inl_defd_pt const atomyc, mk_lib_mt_atomic_portable_ca_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_ca_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(atomyc);
	mk_lang_assert(arg);
	mk_lang_assert(dst);

	*dst = atomic_fetch_and_explicit(&atomyc->m_atomyc, *arg, mk_lib_mt_atomic_portable_ca_inl_defd_memory_order_convert(mo));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_ca_inl_defd_fetch_xor(mk_lib_mt_atomic_portable_ca_inl_defd_pt const atomyc, mk_lib_mt_atomic_portable_ca_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_ca_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(atomyc);
	mk_lang_assert(arg);
	mk_lang_assert(dst);

	*dst = atomic_fetch_xor_explicit(&atomyc->m_atomyc, *arg, mk_lib_mt_atomic_portable_ca_inl_defd_memory_order_convert(mo));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_ca_inl_defd_fetch_or(mk_lib_mt_atomic_portable_ca_inl_defd_pt const atomyc, mk_lib_mt_atomic_portable_ca_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_ca_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(atomyc);
	mk_lang_assert(arg);
	mk_lang_assert(dst);

	*dst = atomic_fetch_or_explicit(&atomyc->m_atomyc, *arg, mk_lib_mt_atomic_portable_ca_inl_defd_memory_order_convert(mo));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_ca_inl_defd_inc(mk_lib_mt_atomic_portable_ca_inl_defd_pt const atomyc, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_ca_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(atomyc);
	mk_lang_assert(dst);

	*dst = atomic_fetch_add_explicit(&atomyc->m_atomyc, 1, mk_lib_mt_atomic_portable_ca_inl_defd_memory_order_convert(mo));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_ca_inl_defd_dec(mk_lib_mt_atomic_portable_ca_inl_defd_pt const atomyc, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_ca_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(atomyc);
	mk_lang_assert(dst);

	*dst = atomic_fetch_sub_explicit(&atomyc->m_atomyc, 1, mk_lib_mt_atomic_portable_ca_inl_defd_memory_order_convert(mo));
	return 0;
}


#include "mk_lib_mt_atomic_portable_ca_inl_defu.h"


#undef mk_lib_mt_atomic_portable_ca_t_name
#undef mk_lib_mt_atomic_portable_ca_t_type
