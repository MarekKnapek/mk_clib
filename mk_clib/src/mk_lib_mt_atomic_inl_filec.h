#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_concat.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_mt_memory_order.h"


#include "mk_lib_mt_atomic_inl_defd.h"


#if mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
#define mk_lib_mt_atomic_portable_cpp_t_name mk_lib_mt_atomic_inl_defd_base
#define mk_lib_mt_atomic_portable_cpp_t_type mk_lib_mt_atomic_inl_defd_type
#include "mk_lib_mt_atomic_portable_cpp_inl_filec.hpp"
#elif mk_lang_version_at_least_c_11 && !defined __STDC_NO_ATOMICS__
#define mk_lib_mt_atomic_portable_ca_t_name mk_lib_mt_atomic_inl_defd_base
#define mk_lib_mt_atomic_portable_ca_t_type mk_lib_mt_atomic_inl_defd_type
#include "mk_lib_mt_atomic_portable_ca_inl_filec.h"
#elif mk_lang_version_at_least_c_11 && !defined __STDC_NO_THREADS__
#define mk_lib_mt_atomic_portable_cb_t_name mk_lib_mt_atomic_inl_defd_base
#define mk_lib_mt_atomic_portable_cb_t_type mk_lib_mt_atomic_inl_defd_type
#include "mk_lib_mt_atomic_portable_cb_inl_filec.h"
#else
#error xxxxxxxxxx
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_construct(mk_lib_mt_atomic_inl_defd_pt const atomyc) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(atomyc);

	ret = mk_lib_mt_atomic_inl_defd_base_construct(&atomyc->m_atomyc);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_destroy(mk_lib_mt_atomic_inl_defd_pt const atomyc) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(atomyc);

	ret = mk_lib_mt_atomic_inl_defd_base_destroy(&atomyc->m_atomyc);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_store(mk_lib_mt_atomic_inl_defd_pt const atomyc, mk_lib_mt_atomic_inl_defd_type_pct const desired, mk_lib_mt_memory_order_t const mo) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(atomyc);

	ret = mk_lib_mt_atomic_inl_defd_base_store(&atomyc->m_atomyc, desired, mo);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_load(mk_lib_mt_atomic_inl_defd_pct const atomyc, mk_lib_mt_atomic_inl_defd_type_pt const dst, mk_lib_mt_memory_order_t const mo) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(atomyc);

	ret = mk_lib_mt_atomic_inl_defd_base_load(&atomyc->m_atomyc, dst, mo);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_fetch_add(mk_lib_mt_atomic_inl_defd_pt const atomyc, mk_lib_mt_atomic_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(atomyc);

	ret = mk_lib_mt_atomic_inl_defd_base_fetch_add(&atomyc->m_atomyc, arg, mo, dst);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_fetch_sub(mk_lib_mt_atomic_inl_defd_pt const atomyc, mk_lib_mt_atomic_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(atomyc);

	ret = mk_lib_mt_atomic_inl_defd_base_fetch_sub(&atomyc->m_atomyc, arg, mo, dst);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_fetch_and(mk_lib_mt_atomic_inl_defd_pt const atomyc, mk_lib_mt_atomic_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(atomyc);

	ret = mk_lib_mt_atomic_inl_defd_base_fetch_and(&atomyc->m_atomyc, arg, mo, dst);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_fetch_xor(mk_lib_mt_atomic_inl_defd_pt const atomyc, mk_lib_mt_atomic_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(atomyc);

	ret = mk_lib_mt_atomic_inl_defd_base_fetch_xor(&atomyc->m_atomyc, arg, mo, dst);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_fetch_or(mk_lib_mt_atomic_inl_defd_pt const atomyc, mk_lib_mt_atomic_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(atomyc);

	ret = mk_lib_mt_atomic_inl_defd_base_fetch_or(&atomyc->m_atomyc, arg, mo, dst);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_inc(mk_lib_mt_atomic_inl_defd_pt const atomyc, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(atomyc);

	ret = mk_lib_mt_atomic_inl_defd_base_inc(&atomyc->m_atomyc, mo, dst);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_inl_defd_dec(mk_lib_mt_atomic_inl_defd_pt const atomyc, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_inl_defd_type_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(atomyc);

	ret = mk_lib_mt_atomic_inl_defd_base_dec(&atomyc->m_atomyc, mo, dst);
	return ret;
}


#include "mk_lib_mt_atomic_inl_defu.h"


#undef mk_lib_mt_atomic_t_name
#undef mk_lib_mt_atomic_t_type
