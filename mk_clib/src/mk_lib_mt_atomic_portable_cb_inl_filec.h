#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_memory_order.h"
#include "mk_lib_mt_mutex_portable_c.h"
#include "mk_lib_mt_unique_lock_portable_c.h"


#include "mk_lib_mt_atomic_portable_cb_inl_defd.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cb_inl_defd_construct(mk_lib_mt_atomic_portable_cb_inl_defd_pt const atomyc) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(atomyc);

	err = mk_lib_mt_mutex_portable_c_construct(&atomyc->m_mtx); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cb_inl_defd_destroy(mk_lib_mt_atomic_portable_cb_inl_defd_pt const atomyc) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(atomyc);

	err = mk_lib_mt_mutex_portable_c_destruct(&atomyc->m_mtx); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cb_inl_defd_store(mk_lib_mt_atomic_portable_cb_inl_defd_pt const atomyc, mk_lib_mt_atomic_portable_cb_inl_defd_type_pct const desired, mk_lib_mt_memory_order_t const mo) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_portable_c_t ul;

	mk_lang_assert(atomyc);
	mk_lang_assert(desired);

	((mk_lang_types_void_t)(mo));
	err = mk_lib_mt_unique_lock_exclusive_portable_c_construct(&ul, &atomyc->m_mtx); mk_lang_check_rereturn(err);
	atomyc->m_atomyc = *desired;
	err = mk_lib_mt_unique_lock_exclusive_portable_c_destruct(&ul); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cb_inl_defd_load(mk_lib_mt_atomic_portable_cb_inl_defd_pct const atomyc, mk_lib_mt_atomic_portable_cb_inl_defd_type_pt const dst, mk_lib_mt_memory_order_t const mo) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_portable_c_t ul;

	mk_lang_assert(atomyc);
	mk_lang_assert(dst);

	((mk_lang_types_void_t)(mo));
	err = mk_lib_mt_unique_lock_exclusive_portable_c_construct(&ul, &atomyc->m_mtx); mk_lang_check_rereturn(err);
	*dst = atomyc->m_atomyc;
	err = mk_lib_mt_unique_lock_exclusive_portable_c_destruct(&ul); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cb_inl_defd_fetch_add(mk_lib_mt_atomic_portable_cb_inl_defd_pt const atomyc, mk_lib_mt_atomic_portable_cb_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_cb_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_portable_c_t ul;

	mk_lang_assert(atomyc);
	mk_lang_assert(arg);
	mk_lang_assert(dst);

	((mk_lang_types_void_t)(mo));
	err = mk_lib_mt_unique_lock_exclusive_portable_c_construct(&ul, &atomyc->m_mtx); mk_lang_check_rereturn(err);
	atomyc->m_atomyc += *arg;
	err = mk_lib_mt_unique_lock_exclusive_portable_c_destruct(&ul); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cb_inl_defd_fetch_sub(mk_lib_mt_atomic_portable_cb_inl_defd_pt const atomyc, mk_lib_mt_atomic_portable_cb_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_cb_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_portable_c_t ul;

	mk_lang_assert(atomyc);
	mk_lang_assert(arg);
	mk_lang_assert(dst);

	((mk_lang_types_void_t)(mo));
	err = mk_lib_mt_unique_lock_exclusive_portable_c_construct(&ul, &atomyc->m_mtx); mk_lang_check_rereturn(err);
	atomyc->m_atomyc -= *arg;
	err = mk_lib_mt_unique_lock_exclusive_portable_c_destruct(&ul); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cb_inl_defd_fetch_and(mk_lib_mt_atomic_portable_cb_inl_defd_pt const atomyc, mk_lib_mt_atomic_portable_cb_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_cb_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_portable_c_t ul;

	mk_lang_assert(atomyc);
	mk_lang_assert(arg);
	mk_lang_assert(dst);

	((mk_lang_types_void_t)(mo));
	err = mk_lib_mt_unique_lock_exclusive_portable_c_construct(&ul, &atomyc->m_mtx); mk_lang_check_rereturn(err);
	atomyc->m_atomyc &= *arg;
	err = mk_lib_mt_unique_lock_exclusive_portable_c_destruct(&ul); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cb_inl_defd_fetch_xor(mk_lib_mt_atomic_portable_cb_inl_defd_pt const atomyc, mk_lib_mt_atomic_portable_cb_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_cb_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_portable_c_t ul;

	mk_lang_assert(atomyc);
	mk_lang_assert(arg);
	mk_lang_assert(dst);

	((mk_lang_types_void_t)(mo));
	err = mk_lib_mt_unique_lock_exclusive_portable_c_construct(&ul, &atomyc->m_mtx); mk_lang_check_rereturn(err);
	atomyc->m_atomyc ^= *arg;
	err = mk_lib_mt_unique_lock_exclusive_portable_c_destruct(&ul); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cb_inl_defd_fetch_or(mk_lib_mt_atomic_portable_cb_inl_defd_pt const atomyc, mk_lib_mt_atomic_portable_cb_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_cb_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_portable_c_t ul;

	mk_lang_assert(atomyc);
	mk_lang_assert(arg);
	mk_lang_assert(dst);

	((mk_lang_types_void_t)(mo));
	err = mk_lib_mt_unique_lock_exclusive_portable_c_construct(&ul, &atomyc->m_mtx); mk_lang_check_rereturn(err);
	atomyc->m_atomyc |= *arg;
	err = mk_lib_mt_unique_lock_exclusive_portable_c_destruct(&ul); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cb_inl_defd_inc(mk_lib_mt_atomic_portable_cb_inl_defd_pt const atomyc, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_cb_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_portable_c_t ul;

	mk_lang_assert(atomyc);
	mk_lang_assert(dst);

	((mk_lang_types_void_t)(mo));
	err = mk_lib_mt_unique_lock_exclusive_portable_c_construct(&ul, &atomyc->m_mtx); mk_lang_check_rereturn(err);
	*dst = atomyc->m_atomyc;
	++atomyc->m_atomyc;
	err = mk_lib_mt_unique_lock_exclusive_portable_c_destruct(&ul); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cb_inl_defd_dec(mk_lib_mt_atomic_portable_cb_inl_defd_pt const atomyc, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_cb_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_portable_c_t ul;

	mk_lang_assert(atomyc);
	mk_lang_assert(dst);

	((mk_lang_types_void_t)(mo));
	err = mk_lib_mt_unique_lock_exclusive_portable_c_construct(&ul, &atomyc->m_mtx); mk_lang_check_rereturn(err);
	*dst = atomyc->m_atomyc;
	--atomyc->m_atomyc;
	err = mk_lib_mt_unique_lock_exclusive_portable_c_destruct(&ul); mk_lang_check_rereturn(err);
	return 0;
}


#include "mk_lib_mt_atomic_portable_cb_inl_defu.h"


#undef mk_lib_mt_atomic_portable_cb_t_name
#undef mk_lib_mt_atomic_portable_cb_t_type
