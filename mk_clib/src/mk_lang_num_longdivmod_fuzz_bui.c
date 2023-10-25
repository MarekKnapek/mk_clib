#include "mk_lang_num_longdivmod_fuzz_bui.h"

#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"


#define mk_lang_bui_t_name mk_lang_num_longdivmod_fuzz_bui1
#define mk_lang_bui_t_base uchar
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_lang_num_longdivmod_fuzz_bui1_sizebits_d (mk_lang_sizeof_bi_uchar_t * mk_lang_charbit)

#define mk_lang_bui_t_name mk_lang_num_longdivmod_fuzz_bui2
#define mk_lang_bui_t_base ushort
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_lang_num_longdivmod_fuzz_bui2_sizebits_d (mk_lang_sizeof_bi_ushort_t * mk_lang_charbit)

#define mk_lang_bui_t_name mk_lang_num_longdivmod_fuzz_bui3
#define mk_lang_bui_t_base ulong
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_lang_num_longdivmod_fuzz_bui3_sizebits_d (mk_lang_sizeof_bi_ulong_t * mk_lang_charbit)

#define mk_lang_bui_t_name mk_lang_num_longdivmod_fuzz_builll
#define mk_lang_bui_t_base ulllong
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_lang_num_longdivmod_fuzz_builll_sizebits_d (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lang_num_longdivmod_fuzz_bui_convert_1s_to_2(mk_lang_num_longdivmod_fuzz_bui1_pct const a, mk_lang_num_longdivmod_fuzz_bui2_pt const b) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_num_longdivmod_fuzz_bui2_sizebits_d >= 2 * mk_lang_num_longdivmod_fuzz_bui1_sizebits_d);

	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_num_longdivmod_fuzz_bui2_t)(*a));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lang_num_longdivmod_fuzz_bui_convert_1d_to_2(mk_lang_num_longdivmod_fuzz_bui1_pct const a, mk_lang_num_longdivmod_fuzz_bui1_pct const b, mk_lang_num_longdivmod_fuzz_bui2_pt const c) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_num_longdivmod_fuzz_bui2_sizebits_d >= 2 * mk_lang_num_longdivmod_fuzz_bui1_sizebits_d);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_num_longdivmod_fuzz_bui2_t)(((mk_lang_num_longdivmod_fuzz_bui2_t)(((mk_lang_num_longdivmod_fuzz_bui2_t)(*a)) << mk_lang_num_longdivmod_fuzz_bui1_sizebits_d)) | ((mk_lang_num_longdivmod_fuzz_bui2_t)(*b))));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lang_num_longdivmod_fuzz_bui_convert_1d_to_3(mk_lang_num_longdivmod_fuzz_bui1_pct const a, mk_lang_num_longdivmod_fuzz_bui1_pct const b, mk_lang_num_longdivmod_fuzz_bui3_pt const c) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_num_longdivmod_fuzz_bui3_sizebits_d >= 3 * mk_lang_num_longdivmod_fuzz_bui1_sizebits_d);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_num_longdivmod_fuzz_bui3_t)(((mk_lang_num_longdivmod_fuzz_bui3_t)(((mk_lang_num_longdivmod_fuzz_bui3_t)(*a)) << ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(1)) * ((mk_lang_types_sint_t)(mk_lang_num_longdivmod_fuzz_bui1_sizebits_d)))))) | ((mk_lang_num_longdivmod_fuzz_bui3_t)(*b))));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lang_num_longdivmod_fuzz_bui_convert_1t_to_3(mk_lang_num_longdivmod_fuzz_bui1_pct const a, mk_lang_num_longdivmod_fuzz_bui1_pct const b, mk_lang_num_longdivmod_fuzz_bui1_pct const c, mk_lang_num_longdivmod_fuzz_bui3_pt const d) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_num_longdivmod_fuzz_bui3_sizebits_d >= 3 * mk_lang_num_longdivmod_fuzz_bui1_sizebits_d);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	*d = ((mk_lang_num_longdivmod_fuzz_bui3_t)(((mk_lang_num_longdivmod_fuzz_bui3_t)(((mk_lang_num_longdivmod_fuzz_bui3_t)(((mk_lang_num_longdivmod_fuzz_bui3_t)(*a)) << ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(2)) * ((mk_lang_types_sint_t)(mk_lang_num_longdivmod_fuzz_bui1_sizebits_d)))))) | ((mk_lang_num_longdivmod_fuzz_bui3_t)(((mk_lang_num_longdivmod_fuzz_bui3_t)(*b)) << ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(1)) * ((mk_lang_types_sint_t)(mk_lang_num_longdivmod_fuzz_bui1_sizebits_d)))))))) | ((mk_lang_num_longdivmod_fuzz_bui3_t)(*c))));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lang_num_longdivmod_fuzz_bui_convert_2_to_1lo(mk_lang_num_longdivmod_fuzz_bui2_pct const a, mk_lang_num_longdivmod_fuzz_bui1_pt const b) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_num_longdivmod_fuzz_bui2_sizebits_d >= 2 * mk_lang_num_longdivmod_fuzz_bui1_sizebits_d);

	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_num_longdivmod_fuzz_bui1_t)(*a));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lang_num_longdivmod_fuzz_bui_convert_2_to_1hi(mk_lang_num_longdivmod_fuzz_bui2_pct const a, mk_lang_num_longdivmod_fuzz_bui1_pt const b) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_num_longdivmod_fuzz_bui2_sizebits_d >= 2 * mk_lang_num_longdivmod_fuzz_bui1_sizebits_d);

	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_num_longdivmod_fuzz_bui1_t)(((mk_lang_num_longdivmod_fuzz_bui1_t)(((mk_lang_num_longdivmod_fuzz_bui2_t)(*a)) >> mk_lang_num_longdivmod_fuzz_bui1_sizebits_d))));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lang_num_longdivmod_fuzz_bui_convert_3_to_2(mk_lang_num_longdivmod_fuzz_bui3_pct const a, mk_lang_num_longdivmod_fuzz_bui2_pt const b) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_num_longdivmod_fuzz_bui3_sizebits_d >= 3 * mk_lang_num_longdivmod_fuzz_bui1_sizebits_d);

	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_num_longdivmod_fuzz_bui2_t)(*a));
}


#define mk_lang_num_longdivmod_t_name mk_lang_num_longdivmod_fuzz_bui_2
#define mk_lang_num_longdivmod_t_tn1 mk_lang_num_longdivmod_fuzz_bui1
#define mk_lang_num_longdivmod_t_tn2 mk_lang_num_longdivmod_fuzz_bui2
#define mk_lang_num_longdivmod_t_lena mk_lang_sizeof_bi_ulllong_t
#define mk_lang_num_longdivmod_t_lenb mk_lang_sizeof_bi_ulllong_t
#define mk_lang_num_longdivmod_t_endian mk_lang_endian_little
#define mk_lang_num_longdivmod_t_alg 2
#define mk_lang_num_longdivmod_t_tn1s_to_tn2 mk_lang_num_longdivmod_fuzz_bui_convert_1s_to_2
#define mk_lang_num_longdivmod_t_tn1d_to_tn2 mk_lang_num_longdivmod_fuzz_bui_convert_1d_to_2
#define mk_lang_num_longdivmod_t_tn1d_to_tn3 mk_lang_num_longdivmod_fuzz_bui_convert_1d_to_3
#define mk_lang_num_longdivmod_t_tn1t_to_tn3 mk_lang_num_longdivmod_fuzz_bui_convert_1t_to_3
#define mk_lang_num_longdivmod_t_tn2_get_lo mk_lang_num_longdivmod_fuzz_bui_convert_2_to_1lo
#define mk_lang_num_longdivmod_t_tn2_get_hi mk_lang_num_longdivmod_fuzz_bui_convert_2_to_1hi
#define mk_lang_num_longdivmod_t_tn3_get_tn2 mk_lang_num_longdivmod_fuzz_bui_convert_3_to_2
#include "mk_lang_num_longdivmod_inl_fileh.h"
#include "mk_lang_num_longdivmod_inl_filec.h"

#define mk_lang_num_longdivmod_t_name mk_lang_num_longdivmod_fuzz_bui_3
#define mk_lang_num_longdivmod_t_tn1 mk_lang_num_longdivmod_fuzz_bui1
#define mk_lang_num_longdivmod_t_tn2 mk_lang_num_longdivmod_fuzz_bui2
#define mk_lang_num_longdivmod_t_tn3 mk_lang_num_longdivmod_fuzz_bui3
#define mk_lang_num_longdivmod_t_lena mk_lang_sizeof_bi_ulllong_t
#define mk_lang_num_longdivmod_t_lenb mk_lang_sizeof_bi_ulllong_t
#define mk_lang_num_longdivmod_t_endian mk_lang_endian_little
#define mk_lang_num_longdivmod_t_alg 3
#define mk_lang_num_longdivmod_t_tn1s_to_tn2 mk_lang_num_longdivmod_fuzz_bui_convert_1s_to_2
#define mk_lang_num_longdivmod_t_tn1d_to_tn2 mk_lang_num_longdivmod_fuzz_bui_convert_1d_to_2
#define mk_lang_num_longdivmod_t_tn1d_to_tn3 mk_lang_num_longdivmod_fuzz_bui_convert_1d_to_3
#define mk_lang_num_longdivmod_t_tn1t_to_tn3 mk_lang_num_longdivmod_fuzz_bui_convert_1t_to_3
#define mk_lang_num_longdivmod_t_tn2_get_lo mk_lang_num_longdivmod_fuzz_bui_convert_2_to_1lo
#define mk_lang_num_longdivmod_t_tn2_get_hi mk_lang_num_longdivmod_fuzz_bui_convert_2_to_1hi
#define mk_lang_num_longdivmod_t_tn3_get_tn2 mk_lang_num_longdivmod_fuzz_bui_convert_3_to_2
#include "mk_lang_num_longdivmod_inl_fileh.h"
#include "mk_lang_num_longdivmod_inl_filec.h"


static mk_lang_inline mk_lang_types_void_t mk_lang_num_longdivmod_fuzz_bui_test2(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_num_longdivmod_fuzz_builll_t aa;
	mk_lang_num_longdivmod_fuzz_builll_t bb;
	mk_lang_num_longdivmod_fuzz_builll_t cc;
	mk_lang_num_longdivmod_fuzz_builll_t dd;
	mk_lang_num_longdivmod_fuzz_bui1_t a[mk_lang_sizeof_bi_ulllong_t];
	mk_lang_num_longdivmod_fuzz_bui1_t b[mk_lang_sizeof_bi_ulllong_t];
	mk_lang_num_longdivmod_fuzz_bui1_t c[mk_lang_sizeof_bi_ulllong_t];
	mk_lang_num_longdivmod_fuzz_bui1_t d[mk_lang_sizeof_bi_ulllong_t];

	if(size >= 2 * mk_lang_sizeof_bi_ulllong_t)
	{
		mk_lang_num_longdivmod_fuzz_builll_from_buis_uchar_le(&aa, &data[0 + 0 * mk_lang_sizeof_bi_ulllong_t]);
		mk_lang_num_longdivmod_fuzz_builll_from_buis_uchar_le(&bb, &data[0 + 1 * mk_lang_sizeof_bi_ulllong_t]);
		if(bb != 0)
		{
			cc = aa / bb;
			dd = aa % bb;
			mk_lang_num_longdivmod_fuzz_builll_to_buis_uchar_le(&aa, &a[0]);
			mk_lang_num_longdivmod_fuzz_builll_to_buis_uchar_le(&bb, &b[0]);
			mk_lang_num_longdivmod_fuzz_bui_2_divmod4(&a[0], &b[0], &c[0], &d[0]);
			mk_lang_num_longdivmod_fuzz_builll_from_buis_uchar_le(&aa, &c[0]);
			mk_lang_num_longdivmod_fuzz_builll_from_buis_uchar_le(&bb, &d[0]);
			mk_lang_test(aa == cc);
			mk_lang_test(bb == dd);
		}
	}
}

static mk_lang_inline mk_lang_types_void_t mk_lang_num_longdivmod_fuzz_bui_test3(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_num_longdivmod_fuzz_builll_t aa;
	mk_lang_num_longdivmod_fuzz_builll_t bb;
	mk_lang_num_longdivmod_fuzz_builll_t cc;
	mk_lang_num_longdivmod_fuzz_builll_t dd;
	mk_lang_num_longdivmod_fuzz_bui1_t a[mk_lang_sizeof_bi_ulllong_t];
	mk_lang_num_longdivmod_fuzz_bui1_t b[mk_lang_sizeof_bi_ulllong_t];
	mk_lang_num_longdivmod_fuzz_bui1_t c[mk_lang_sizeof_bi_ulllong_t];
	mk_lang_num_longdivmod_fuzz_bui1_t d[mk_lang_sizeof_bi_ulllong_t];

	if(size >= 2 * mk_lang_sizeof_bi_ulllong_t)
	{
		mk_lang_num_longdivmod_fuzz_builll_from_buis_uchar_le(&aa, &data[0 + 0 * mk_lang_sizeof_bi_ulllong_t]);
		mk_lang_num_longdivmod_fuzz_builll_from_buis_uchar_le(&bb, &data[0 + 1 * mk_lang_sizeof_bi_ulllong_t]);
		if(bb != 0)
		{
			cc = aa / bb;
			dd = aa % bb;
			mk_lang_num_longdivmod_fuzz_builll_to_buis_uchar_le(&aa, &a[0]);
			mk_lang_num_longdivmod_fuzz_builll_to_buis_uchar_le(&bb, &b[0]);
			mk_lang_num_longdivmod_fuzz_bui_3_divmod4(&a[0], &b[0], &c[0], &d[0]);
			mk_lang_num_longdivmod_fuzz_builll_from_buis_uchar_le(&aa, &c[0]);
			mk_lang_num_longdivmod_fuzz_builll_from_buis_uchar_le(&bb, &d[0]);
			mk_lang_test(aa == cc);
			mk_lang_test(bb == dd);
		}
	}
}


mk_lang_jumbo void mk_lang_num_longdivmod_fuzz_bui(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_num_longdivmod_fuzz_bui_test2(data, size);
	mk_lang_num_longdivmod_fuzz_bui_test3(data, size);
}
