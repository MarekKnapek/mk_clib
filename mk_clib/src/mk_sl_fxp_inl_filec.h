#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_memmove_obj.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_overlap.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"


#include "mk_sl_fxp_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_base(mk_sl_fxp_inl_defd_pt const x, mk_sl_fxp_inl_defd_base_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	x->m_data = *a;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_bool(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_bool_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	*a ? mk_sl_fxp_inl_defd_set_one(x) : mk_sl_fxp_inl_defd_set_zero(x);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_pchar(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_pchar_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	mk_sl_fxp_inl_defd_base_from_bi_pchar(&x->m_data, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_uchar(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_uchar_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	mk_sl_fxp_inl_defd_base_from_bi_uchar(&x->m_data, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_schar(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_schar_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	mk_sl_fxp_inl_defd_base_from_bi_schar(&x->m_data, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_ushort(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_ushort_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	mk_sl_fxp_inl_defd_base_from_bi_ushort(&x->m_data, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_sshort(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_sshort_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	mk_sl_fxp_inl_defd_base_from_bi_sshort(&x->m_data, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_uint(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_uint_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	mk_sl_fxp_inl_defd_base_from_bi_uint(&x->m_data, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_sint(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_sint_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	mk_sl_fxp_inl_defd_base_from_bi_sint(&x->m_data, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_ulong(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_ulong_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	mk_sl_fxp_inl_defd_base_from_bi_ulong(&x->m_data, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_slong(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_slong_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	mk_sl_fxp_inl_defd_base_from_bi_slong(&x->m_data, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_ullong(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_ullong_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	mk_sl_fxp_inl_defd_base_from_bi_ullong(&x->m_data, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_sllong(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_sllong_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	mk_sl_fxp_inl_defd_base_from_bi_sllong(&x->m_data, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_ulllong(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_ulllong_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	mk_sl_fxp_inl_defd_base_from_bi_ulllong(&x->m_data, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_slllong(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_slllong_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	mk_sl_fxp_inl_defd_base_from_bi_slllong(&x->m_data, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_uintptr(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_uintptr_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	mk_sl_fxp_inl_defd_base_from_bi_uintptr(&x->m_data, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_sintptr(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_sintptr_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	mk_sl_fxp_inl_defd_base_from_bi_sintptr(&x->m_data, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_uintmax(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_uintmax_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	mk_sl_fxp_inl_defd_base_from_bi_uintmax(&x->m_data, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_sintmax(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_sintmax_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	mk_sl_fxp_inl_defd_base_from_bi_sintmax(&x->m_data, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_usize(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_usize_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	mk_sl_fxp_inl_defd_base_from_bi_usize(&x->m_data, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_ssize(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_ssize_pct const a) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(a);

	mk_sl_fxp_inl_defd_base_from_bi_ssize(&x->m_data, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_buis_uchar_le(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_uchar_pct const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_buis_ushort_le(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_ushort_pct const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_buis_uint_le(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_uint_pct const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_buis_ulong_le(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_ulong_pct const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_buis_ullong_le(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_ullong_pct const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_buis_ulllong_le(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_ulllong_pct const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_buis_uintptr_le(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_uintptr_pct const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_buis_uintmax_le(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_uintmax_pct const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_buis_usize_le(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_usize_pct const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_buis_uchar_be(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_uchar_pct const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_buis_ushort_be(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_ushort_pct const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_buis_uint_be(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_uint_pct const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_buis_ulong_be(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_ulong_pct const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_buis_ullong_be(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_ullong_pct const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_buis_ulllong_be(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_ulllong_pct const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_buis_uintptr_be(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_uintptr_pct const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_buis_uintmax_be(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_uintmax_pct const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_buis_usize_be(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_usize_pct const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_base(mk_sl_fxp_inl_defd_pct const x, mk_sl_fxp_inl_defd_base_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_bool(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_bool_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_pchar(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_pchar_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_uchar(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_uchar_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_schar(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_schar_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_ushort(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_ushort_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_sshort(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_sshort_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_uint(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_uint_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_sint(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_sint_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_ulong(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_ulong_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_slong(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_slong_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_ullong(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_ullong_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_sllong(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_sllong_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_ulllong(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_ulllong_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_slllong(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_slllong_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_uintptr(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_uintptr_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_sintptr(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_sintptr_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_uintmax(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_uintmax_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_sintmax(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_sintmax_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_usize(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_usize_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_ssize(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_ssize_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_buis_uchar_le(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_uchar_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_buis_ushort_le(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_ushort_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_buis_uint_le(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_uint_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_buis_ulong_le(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_ulong_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_buis_ullong_le(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_ullong_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_buis_ulllong_le(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_ulllong_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_buis_uintptr_le(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_uintptr_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_buis_uintmax_le(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_uintmax_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_buis_usize_le(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_usize_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_buis_uchar_be(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_uchar_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_buis_ushort_be(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_ushort_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_buis_uint_be(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_uint_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_buis_ulong_be(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_ulong_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_buis_ullong_be(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_ullong_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_buis_ulllong_be(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_ulllong_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_buis_uintptr_be(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_uintptr_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_buis_uintmax_be(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_uintmax_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_buis_usize_be(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_usize_pt const a) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_set_zero(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_set_max(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_set_one(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_set_bit(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_sint_t const bit_idx) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_set_mask(mk_sl_fxp_inl_defd_pt const x, mk_lang_types_sint_t const bits_count) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fxp_inl_defd_count_leading_zeros(mk_sl_fxp_inl_defd_pct const x) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fxp_inl_defd_count_leading_ones(mk_sl_fxp_inl_defd_pct const x) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fxp_inl_defd_count_trailing_zeros(mk_sl_fxp_inl_defd_pct const x) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fxp_inl_defd_count_trailing_ones(mk_sl_fxp_inl_defd_pct const x) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fxp_inl_defd_count_zeros(mk_sl_fxp_inl_defd_pct const x) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fxp_inl_defd_count_ones(mk_sl_fxp_inl_defd_pct const x) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_fxp_inl_defd_has_lsb(mk_sl_fxp_inl_defd_pct const x) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_fxp_inl_defd_is_zero(mk_sl_fxp_inl_defd_pct const x) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_fxp_inl_defd_is_max(mk_sl_fxp_inl_defd_pct const x) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_fxp_inl_defd_eq(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_fxp_inl_defd_ne(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_fxp_inl_defd_lt(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_fxp_inl_defd_le(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_fxp_inl_defd_gt(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_fxp_inl_defd_ge(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_inc2(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_dec2(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_inc1(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_dec1(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_not2(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_or3(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_and3(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_xor3(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_not1(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_or2(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_and2(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_xor2(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_shl3(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_sint_t const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_shr3(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_sint_t const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_rotl3(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_sint_t const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_rotr3(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_sint_t const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_shl2(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_shr2(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_rotl2(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_rotr2(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_fxp_inl_defd_would_overflow_add_cc(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_fxp_inl_defd_would_overflow_add_cs(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_fxp_inl_defd_would_overflow_add(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_bool_t const cf) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_fxp_inl_defd_would_overflow_sub_cc(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_fxp_inl_defd_would_overflow_sub_cs(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_fxp_inl_defd_would_overflow_sub(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_bool_t const cf) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_fxp_inl_defd_would_overflow_mul(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_add3_wrap_cid_cod(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_add3_wrap_cid_coe(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c, mk_lang_bool_t* const co) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_add3_wrap_cie_cod(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_bool_t const ci, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_add3_wrap_cie_coe(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_bool_t const ci, mk_sl_fxp_inl_defd_pt const c, mk_lang_bool_t* const co) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_add2_wrap_cid_cod(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_add2_wrap_cid_coe(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_bool_t* const co) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_add2_wrap_cie_cod(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_bool_t const ci) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_add2_wrap_cie_coe(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_bool_t const ci, mk_lang_bool_t* const co) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_sub3_wrap_cid_cod(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_sub3_wrap_cid_coe(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c, mk_lang_bool_t* const co) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_sub3_wrap_cie_cod(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_bool_t const ci, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_sub3_wrap_cie_coe(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_bool_t const ci, mk_sl_fxp_inl_defd_pt const c, mk_lang_bool_t* const co) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_sub2_wrap_cid_cod(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_sub2_wrap_cid_coe(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_bool_t* const co) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_sub2_wrap_cie_cod(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_bool_t const ci) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_sub2_wrap_cie_coe(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_bool_t const ci, mk_lang_bool_t* const co) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_mul3_wrap_lo(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_mul3_wrap_hi(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_mul4_wrap_wi(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c, mk_sl_fxp_inl_defd_pt const d) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_mul2_wrap_lo(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_mul2_wrap_hi(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_mul2_wrap_wi(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_div3_wrap(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_mod3_wrap(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_divmod4_wrap(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c, mk_sl_fxp_inl_defd_pt const d) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_div2_wrap(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_mod2_wrap(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_divmod2_wrap(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_divmod_smol(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_base_t const* const b, mk_sl_fxp_inl_defd_pt const c, mk_sl_fxp_inl_defd_base_t* const d) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_mul3_wrap_lo_smol(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_base_t const* const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_add2_wrap_cid_cod_smol(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_base_t const* const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_mul4_wrap_wi_smol(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_base_t const* const b, mk_sl_fxp_inl_defd_pt const c, mk_sl_fxp_inl_defd_base_t* const d) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fxp_inl_defd_to_str_dec_n(mk_sl_fxp_inl_defd_pct const x, char* const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fxp_inl_defd_from_str_dec_n(mk_sl_fxp_inl_defd_pt const x, char const* const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept;


#include "mk_sl_fxp_inl_defu.h"


#undef mk_sl_fxp_name
#undef mk_sl_fxp_base_name
#undef mk_sl_fxp_bits_all
#undef mk_sl_fxp_bits_pre
#undef mk_sl_fxp_bits_post
