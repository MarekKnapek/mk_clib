#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_mt_memory_order.h"

#include <atomic> /* std::atomic std::memory_order */
#include <new> /* new */
#include <type_traits> /* std::aligned_storage */


#include "mk_lib_mt_atomic_portable_cpp_inl_defd.hpp"


mk_lang_nodiscard static mk_lang_inline std::memory_order mk_lib_mt_atomic_portable_cpp_inl_defd_memory_order_convert(mk_lib_mt_memory_order_t const memory_order) mk_lang_noexcept
{
	std::memory_order ret;

	switch(memory_order)
	{
		case mk_lib_mt_memory_order_e_relaxed: ret = std::memory_order_relaxed; break;
		case mk_lib_mt_memory_order_e_acquire: ret = std::memory_order_acquire; break;
		case mk_lib_mt_memory_order_e_release: ret = std::memory_order_release; break;
		case mk_lib_mt_memory_order_e_acq_rel: ret = std::memory_order_acq_rel; break;
		case mk_lib_mt_memory_order_e_seq_cst: ret = std::memory_order_seq_cst; break;
		case mk_lib_mt_memory_order_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cpp_inl_defd_construct(mk_lib_mt_atomic_portable_cpp_inl_defd_pt const atomyc) mk_lang_noexcept
{
	typedef std::atomic<mk_lib_mt_atomic_portable_cpp_inl_defd_type_t> atomyc_t;
	typedef atomyc_t* atomyc_pt;

	atomyc_pt real;

	mk_lang_assert(atomyc);

	real = reinterpret_cast<atomyc_pt>(&atomyc->m_atomyc);
	::new(static_cast<mk_lang_types_void_pt>(real))(atomyc_t)();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cpp_inl_defd_destroy(mk_lib_mt_atomic_portable_cpp_inl_defd_pt const atomyc) mk_lang_noexcept
{
	typedef std::atomic<mk_lib_mt_atomic_portable_cpp_inl_defd_type_t> atomyc_t;
	typedef atomyc_t* atomyc_pt;

	atomyc_pt real;

	mk_lang_assert(atomyc);

	real = reinterpret_cast<atomyc_pt>(&atomyc->m_atomyc);
	real->~atomyc_t();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cpp_inl_defd_store(mk_lib_mt_atomic_portable_cpp_inl_defd_pt const atomyc, mk_lib_mt_atomic_portable_cpp_inl_defd_type_pct const desired, mk_lib_mt_memory_order_t const mo) mk_lang_noexcept
{
	typedef std::atomic<mk_lib_mt_atomic_portable_cpp_inl_defd_type_t> atomyc_t;
	typedef atomyc_t* atomyc_pt;

	atomyc_pt real;

	mk_lang_assert(atomyc);
	mk_lang_assert(desired);

	real = reinterpret_cast<atomyc_pt>(&atomyc->m_atomyc);
	real->store(*desired, mk_lib_mt_atomic_portable_cpp_inl_defd_memory_order_convert(mo));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cpp_inl_defd_load(mk_lib_mt_atomic_portable_cpp_inl_defd_pct const atomyc, mk_lib_mt_atomic_portable_cpp_inl_defd_type_pt const dst, mk_lib_mt_memory_order_t const mo) mk_lang_noexcept
{
	typedef std::atomic<mk_lib_mt_atomic_portable_cpp_inl_defd_type_t> atomyc_t;
	typedef atomyc_t const* atomyc_pct;

	atomyc_pct real;

	mk_lang_assert(atomyc);
	mk_lang_assert(dst);

	real = reinterpret_cast<atomyc_pct>(&atomyc->m_atomyc);
	*dst = real->load(mk_lib_mt_atomic_portable_cpp_inl_defd_memory_order_convert(mo));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cpp_inl_defd_fetch_add(mk_lib_mt_atomic_portable_cpp_inl_defd_pt const atomyc, mk_lib_mt_atomic_portable_cpp_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_cpp_inl_defd_type_pt const dst) mk_lang_noexcept
{
	typedef std::atomic<mk_lib_mt_atomic_portable_cpp_inl_defd_type_t> atomyc_t;
	typedef atomyc_t* atomyc_pt;

	atomyc_pt real;

	mk_lang_assert(atomyc);
	mk_lang_assert(arg);
	mk_lang_assert(dst);

	real = reinterpret_cast<atomyc_pt>(&atomyc->m_atomyc);
	*dst = real->fetch_add(*arg, mk_lib_mt_atomic_portable_cpp_inl_defd_memory_order_convert(mo));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cpp_inl_defd_fetch_sub(mk_lib_mt_atomic_portable_cpp_inl_defd_pt const atomyc, mk_lib_mt_atomic_portable_cpp_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_cpp_inl_defd_type_pt const dst) mk_lang_noexcept
{
	typedef std::atomic<mk_lib_mt_atomic_portable_cpp_inl_defd_type_t> atomyc_t;
	typedef atomyc_t* atomyc_pt;

	atomyc_pt real;

	mk_lang_assert(atomyc);
	mk_lang_assert(arg);
	mk_lang_assert(dst);

	real = reinterpret_cast<atomyc_pt>(&atomyc->m_atomyc);
	*dst = real->fetch_sub(*arg, mk_lib_mt_atomic_portable_cpp_inl_defd_memory_order_convert(mo));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cpp_inl_defd_fetch_and(mk_lib_mt_atomic_portable_cpp_inl_defd_pt const atomyc, mk_lib_mt_atomic_portable_cpp_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_cpp_inl_defd_type_pt const dst) mk_lang_noexcept
{
	typedef std::atomic<mk_lib_mt_atomic_portable_cpp_inl_defd_type_t> atomyc_t;
	typedef atomyc_t* atomyc_pt;

	atomyc_pt real;

	mk_lang_assert(atomyc);
	mk_lang_assert(arg);
	mk_lang_assert(dst);

	real = reinterpret_cast<atomyc_pt>(&atomyc->m_atomyc);
	*dst = real->fetch_and(*arg, mk_lib_mt_atomic_portable_cpp_inl_defd_memory_order_convert(mo));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cpp_inl_defd_fetch_xor(mk_lib_mt_atomic_portable_cpp_inl_defd_pt const atomyc, mk_lib_mt_atomic_portable_cpp_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_cpp_inl_defd_type_pt const dst) mk_lang_noexcept
{
	typedef std::atomic<mk_lib_mt_atomic_portable_cpp_inl_defd_type_t> atomyc_t;
	typedef atomyc_t* atomyc_pt;

	atomyc_pt real;

	mk_lang_assert(atomyc);
	mk_lang_assert(arg);
	mk_lang_assert(dst);

	real = reinterpret_cast<atomyc_pt>(&atomyc->m_atomyc);
	*dst = real->fetch_xor(*arg, mk_lib_mt_atomic_portable_cpp_inl_defd_memory_order_convert(mo));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cpp_inl_defd_fetch_or(mk_lib_mt_atomic_portable_cpp_inl_defd_pt const atomyc, mk_lib_mt_atomic_portable_cpp_inl_defd_type_pct const arg, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_cpp_inl_defd_type_pt const dst) mk_lang_noexcept
{
	typedef std::atomic<mk_lib_mt_atomic_portable_cpp_inl_defd_type_t> atomyc_t;
	typedef atomyc_t* atomyc_pt;

	atomyc_pt real;

	mk_lang_assert(atomyc);
	mk_lang_assert(arg);
	mk_lang_assert(dst);

	real = reinterpret_cast<atomyc_pt>(&atomyc->m_atomyc);
	*dst = real->fetch_or(*arg, mk_lib_mt_atomic_portable_cpp_inl_defd_memory_order_convert(mo));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cpp_inl_defd_inc(mk_lib_mt_atomic_portable_cpp_inl_defd_pt const atomyc, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_cpp_inl_defd_type_pt const dst) mk_lang_noexcept
{
	typedef std::atomic<mk_lib_mt_atomic_portable_cpp_inl_defd_type_t> atomyc_t;
	typedef atomyc_t* atomyc_pt;

	atomyc_pt real;

	mk_lang_assert(atomyc);
	mk_lang_assert(dst);

	((mk_lang_types_void_t)(mo));
	real = reinterpret_cast<atomyc_pt>(&atomyc->m_atomyc);
	*dst = real->operator++(0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_portable_cpp_inl_defd_dec(mk_lib_mt_atomic_portable_cpp_inl_defd_pt const atomyc, mk_lib_mt_memory_order_t const mo, mk_lib_mt_atomic_portable_cpp_inl_defd_type_pt const dst) mk_lang_noexcept
{
	typedef std::atomic<mk_lib_mt_atomic_portable_cpp_inl_defd_type_t> atomyc_t;
	typedef atomyc_t* atomyc_pt;

	atomyc_pt real;

	mk_lang_assert(atomyc);
	mk_lang_assert(dst);

	((mk_lang_types_void_t)(mo));
	real = reinterpret_cast<atomyc_pt>(&atomyc->m_atomyc);
	*dst = real->operator--(0);
	return 0;
}


#include "mk_lib_mt_atomic_portable_cpp_inl_defu.hpp"


#undef mk_lib_mt_atomic_portable_cpp_t_name
#undef mk_lib_mt_atomic_portable_cpp_t_type
