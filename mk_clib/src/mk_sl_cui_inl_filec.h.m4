include(`mk_sl_cui_inl.m')dnl
#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_encoding.h"
#include "mk_lang_endian.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_noalias.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_type_traits.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#include "mk_sl_cui_inl_defd.h"


#define mk_sl_cui_inl_filec_memmove_pc_name mk_lang_concat(mk_sl_cui_inl_defd_name, _memmove_pchar)
#define mk_sl_cui_inl_filec_memmove_pc_fn mk_lang_concat(mk_sl_cui_inl_filec_memmove_pc_name, _fn)
#define mk_lang_memmove_t_name mk_sl_cui_inl_filec_memmove_pc_name
#define mk_lang_memmove_t_type mk_lang_types_pchar_t
#include "mk_lang_memmove_inl_fileh.h"
#include "mk_lang_memmove_inl_filec.h"

#define mk_sl_cui_inl_filec_memmove_wc_name mk_lang_concat(mk_sl_cui_inl_defd_name, _memmove_wchar)
#define mk_sl_cui_inl_filec_memmove_wc_fn mk_lang_concat(mk_sl_cui_inl_filec_memmove_wc_name, _fn)
#define mk_lang_memmove_t_name mk_sl_cui_inl_filec_memmove_wc_name
#define mk_lang_memmove_t_type mk_lang_types_wchar_t
#include "mk_lang_memmove_inl_fileh.h"
#include "mk_lang_memmove_inl_filec.h"

#if(!mk_sl_cui_inl_defd_disable_big_div && (mk_sl_cui_inl_defd_sizebits_d > mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit) && (mk_lang_sizeof_bi_ulllong_t >= 2 * mk_lang_sizeof_bi_ullong_t))

#define mk_sl_cui_inl_defd_t1 mk_lang_concat(mk_sl_cui_inl_defd_name, _xxx_t1)
#define mk_sl_cui_inl_defd_t1_t mk_lang_concat(mk_sl_cui_inl_defd_t1, _t)
#define mk_sl_cui_inl_defd_t1_pt mk_lang_concat(mk_sl_cui_inl_defd_t1, _pt)
#define mk_sl_cui_inl_defd_t1_pct mk_lang_concat(mk_sl_cui_inl_defd_t1, _pct)
#define mk_lang_bui_t_name mk_sl_cui_inl_defd_t1
#define mk_lang_bui_t_base ullong
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_sl_cui_inl_defd_t1_sizebits_d (mk_lang_sizeof_bi_ullong_t * mk_lang_charbit)

#define mk_sl_cui_inl_defd_t2 mk_lang_concat(mk_sl_cui_inl_defd_name, _xxx_t2)
#define mk_sl_cui_inl_defd_t2_t mk_lang_concat(mk_sl_cui_inl_defd_t2, _t)
#define mk_sl_cui_inl_defd_t2_pt mk_lang_concat(mk_sl_cui_inl_defd_t2, _pt)
#define mk_sl_cui_inl_defd_t2_pct mk_lang_concat(mk_sl_cui_inl_defd_t2, _pct)
#define mk_lang_bui_t_name mk_sl_cui_inl_defd_t2
#define mk_lang_bui_t_base ulllong
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_sl_cui_inl_defd_t2_sizebits_d (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)

#define mk_sl_cui_inl_defd_t1s_to_t2 mk_lang_concat(mk_sl_cui_inl_defd_name, _zzz_t1s_to_t2)
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_cui_inl_defd_t1s_to_t2(mk_sl_cui_inl_defd_t1_pct const a, mk_sl_cui_inl_defd_t2_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_sl_cui_inl_defd_t2_t)(*a));
}}

#define mk_sl_cui_inl_defd_t1d_to_t2 mk_lang_concat(mk_sl_cui_inl_defd_name, _zzz_t1d_to_t2)
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_cui_inl_defd_t1d_to_t2(mk_sl_cui_inl_defd_t1_pct const a, mk_sl_cui_inl_defd_t1_pct const b, mk_sl_cui_inl_defd_t2_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_sl_cui_inl_defd_t2_t)(((mk_sl_cui_inl_defd_t2_t)(((mk_sl_cui_inl_defd_t2_t)(*a)) << ((mk_lang_types_sint_t)(mk_sl_cui_inl_defd_t1_sizebits_d)))) | ((mk_sl_cui_inl_defd_t2_t)(*b))));
}}

#define mk_sl_cui_inl_defd_t2_get_lo mk_lang_concat(mk_sl_cui_inl_defd_name, _zzz_t2_get_lo)
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_cui_inl_defd_t2_get_lo(mk_sl_cui_inl_defd_t2_pct const a, mk_sl_cui_inl_defd_t1_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_sl_cui_inl_defd_t1_t)(*a));
}}

#define mk_sl_cui_inl_defd_t2_get_hi mk_lang_concat(mk_sl_cui_inl_defd_name, _zzz_t2_get_hi)
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_cui_inl_defd_t2_get_hi(mk_sl_cui_inl_defd_t2_pct const a, mk_sl_cui_inl_defd_t1_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_sl_cui_inl_defd_t1_t)(((mk_sl_cui_inl_defd_t2_t)(((mk_sl_cui_inl_defd_t2_t)(*a)) >> ((mk_lang_types_sint_t)(mk_sl_cui_inl_defd_t1_sizebits_d))))));
}}

#define mk_lang_num_longdivmod_t_name mk_lang_concat(mk_lang_num_longdivmod_, mk_sl_cui_inl_defd_name)
#define mk_lang_num_longdivmod_t_tn1 mk_sl_cui_inl_defd_t1
#define mk_lang_num_longdivmod_t_tn2 mk_sl_cui_inl_defd_t2
#define mk_lang_num_longdivmod_t_tn3 x
#define mk_lang_num_longdivmod_t_lena mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ullong_t * mk_lang_charbit)
#define mk_lang_num_longdivmod_t_lenb mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ullong_t * mk_lang_charbit)
#define mk_lang_num_longdivmod_t_endian mk_lang_endian_little
#define mk_lang_num_longdivmod_t_alg 2
#define mk_lang_num_longdivmod_t_tn1s_to_tn2 mk_sl_cui_inl_defd_t1s_to_t2
#define mk_lang_num_longdivmod_t_tn1d_to_tn2 mk_sl_cui_inl_defd_t1d_to_t2
#define mk_lang_num_longdivmod_t_tn1d_to_tn3 x
#define mk_lang_num_longdivmod_t_tn1t_to_tn3 x
#define mk_lang_num_longdivmod_t_tn2_get_lo mk_sl_cui_inl_defd_t2_get_lo
#define mk_lang_num_longdivmod_t_tn2_get_hi mk_sl_cui_inl_defd_t2_get_hi
#define mk_lang_num_longdivmod_t_tn3_get_tn2 x
#define mk_lang_num_longdivmod_t_tn1_sizebits_d mk_sl_cui_inl_defd_t1_sizebits_d
#define mk_lang_num_longdivmod_t_tn2_sizebits_d mk_sl_cui_inl_defd_t2_sizebits_d
#define mk_lang_num_longdivmod_t_tn3_sizebits_d x
#include "mk_lang_num_longdivmod_inl_fileh.h"
#include "mk_lang_num_longdivmod_inl_filec.h"
#define mk_sl_cui_inl_defd_ldm_divmod4 mk_lang_concat(mk_lang_concat(mk_lang_num_longdivmod_, mk_sl_cui_inl_defd_name), _divmod4)

#define mk_lang_num_longdivmod_t_name mk_lang_concat(mk_lang_num_longdivmods_, mk_sl_cui_inl_defd_name)
#define mk_lang_num_longdivmod_t_tn1 mk_sl_cui_inl_defd_t1
#define mk_lang_num_longdivmod_t_tn2 mk_sl_cui_inl_defd_t2
#define mk_lang_num_longdivmod_t_tn3 x
#define mk_lang_num_longdivmod_t_lena mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ullong_t * mk_lang_charbit)
#define mk_lang_num_longdivmod_t_lenb mk_lang_div_roundup(mk_sl_cui_inl_defd_base_sizebits_d, mk_lang_sizeof_bi_ullong_t * mk_lang_charbit)
#define mk_lang_num_longdivmod_t_endian mk_lang_endian_little
#define mk_lang_num_longdivmod_t_alg 2
#define mk_lang_num_longdivmod_t_tn1s_to_tn2 mk_sl_cui_inl_defd_t1s_to_t2
#define mk_lang_num_longdivmod_t_tn1d_to_tn2 mk_sl_cui_inl_defd_t1d_to_t2
#define mk_lang_num_longdivmod_t_tn1d_to_tn3 x
#define mk_lang_num_longdivmod_t_tn1t_to_tn3 x
#define mk_lang_num_longdivmod_t_tn2_get_lo mk_sl_cui_inl_defd_t2_get_lo
#define mk_lang_num_longdivmod_t_tn2_get_hi mk_sl_cui_inl_defd_t2_get_hi
#define mk_lang_num_longdivmod_t_tn3_get_tn2 x
#define mk_lang_num_longdivmod_t_tn1_sizebits_d mk_sl_cui_inl_defd_t1_sizebits_d
#define mk_lang_num_longdivmod_t_tn2_sizebits_d mk_sl_cui_inl_defd_t2_sizebits_d
#define mk_lang_num_longdivmod_t_tn3_sizebits_d x
#include "mk_lang_num_longdivmod_inl_fileh.h"
#include "mk_lang_num_longdivmod_inl_filec.h"
#define mk_sl_cui_inl_defd_ldms_divmod4 mk_lang_concat(mk_lang_concat(mk_lang_num_longdivmods_, mk_sl_cui_inl_defd_name), _divmod4)

#elif(!mk_sl_cui_inl_defd_disable_big_div && (mk_sl_cui_inl_defd_sizebits_d > mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit) && (mk_lang_sizeof_bi_ullong_t >= 2 * mk_lang_sizeof_bi_ulong_t))

#define mk_sl_cui_inl_defd_t1 mk_lang_concat(mk_sl_cui_inl_defd_name, _xxx_t1)
#define mk_sl_cui_inl_defd_t1_t mk_lang_concat(mk_sl_cui_inl_defd_t1, _t)
#define mk_sl_cui_inl_defd_t1_pt mk_lang_concat(mk_sl_cui_inl_defd_t1, _pt)
#define mk_sl_cui_inl_defd_t1_pct mk_lang_concat(mk_sl_cui_inl_defd_t1, _pct)
#define mk_lang_bui_t_name mk_sl_cui_inl_defd_t1
#define mk_lang_bui_t_base ulong
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_sl_cui_inl_defd_t1_sizebits_d (mk_lang_sizeof_bi_ulong_t * mk_lang_charbit)

#define mk_sl_cui_inl_defd_t2 mk_lang_concat(mk_sl_cui_inl_defd_name, _xxx_t2)
#define mk_sl_cui_inl_defd_t2_t mk_lang_concat(mk_sl_cui_inl_defd_t2, _t)
#define mk_sl_cui_inl_defd_t2_pt mk_lang_concat(mk_sl_cui_inl_defd_t2, _pt)
#define mk_sl_cui_inl_defd_t2_pct mk_lang_concat(mk_sl_cui_inl_defd_t2, _pct)
#define mk_lang_bui_t_name mk_sl_cui_inl_defd_t2
#define mk_lang_bui_t_base ullong
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_sl_cui_inl_defd_t2_sizebits_d (mk_lang_sizeof_bi_ullong_t * mk_lang_charbit)

#define mk_sl_cui_inl_defd_t1s_to_t2 mk_lang_concat(mk_sl_cui_inl_defd_name, _zzz_t1s_to_t2)
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_cui_inl_defd_t1s_to_t2(mk_sl_cui_inl_defd_t1_pct const a, mk_sl_cui_inl_defd_t2_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_sl_cui_inl_defd_t2_t)(*a));
}}

#define mk_sl_cui_inl_defd_t1d_to_t2 mk_lang_concat(mk_sl_cui_inl_defd_name, _zzz_t1d_to_t2)
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_cui_inl_defd_t1d_to_t2(mk_sl_cui_inl_defd_t1_pct const a, mk_sl_cui_inl_defd_t1_pct const b, mk_sl_cui_inl_defd_t2_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_sl_cui_inl_defd_t2_t)(((mk_sl_cui_inl_defd_t2_t)(((mk_sl_cui_inl_defd_t2_t)(*a)) << ((mk_lang_types_sint_t)(mk_sl_cui_inl_defd_t1_sizebits_d)))) | ((mk_sl_cui_inl_defd_t2_t)(*b))));
}}

#define mk_sl_cui_inl_defd_t2_get_lo mk_lang_concat(mk_sl_cui_inl_defd_name, _zzz_t2_get_lo)
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_cui_inl_defd_t2_get_lo(mk_sl_cui_inl_defd_t2_pct const a, mk_sl_cui_inl_defd_t1_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_sl_cui_inl_defd_t1_t)(*a));
}}

#define mk_sl_cui_inl_defd_t2_get_hi mk_lang_concat(mk_sl_cui_inl_defd_name, _zzz_t2_get_hi)
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_cui_inl_defd_t2_get_hi(mk_sl_cui_inl_defd_t2_pct const a, mk_sl_cui_inl_defd_t1_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_sl_cui_inl_defd_t1_t)(((mk_sl_cui_inl_defd_t2_t)(((mk_sl_cui_inl_defd_t2_t)(*a)) >> ((mk_lang_types_sint_t)(mk_sl_cui_inl_defd_t1_sizebits_d))))));
}}

#define mk_lang_num_longdivmod_t_name mk_lang_concat(mk_lang_num_longdivmod_, mk_sl_cui_inl_defd_name)
#define mk_lang_num_longdivmod_t_tn1 mk_sl_cui_inl_defd_t1
#define mk_lang_num_longdivmod_t_tn2 mk_sl_cui_inl_defd_t2
#define mk_lang_num_longdivmod_t_tn3 x
#define mk_lang_num_longdivmod_t_lena mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ulong_t * mk_lang_charbit)
#define mk_lang_num_longdivmod_t_lenb mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ulong_t * mk_lang_charbit)
#define mk_lang_num_longdivmod_t_endian mk_lang_endian_little
#define mk_lang_num_longdivmod_t_alg 2
#define mk_lang_num_longdivmod_t_tn1s_to_tn2 mk_sl_cui_inl_defd_t1s_to_t2
#define mk_lang_num_longdivmod_t_tn1d_to_tn2 mk_sl_cui_inl_defd_t1d_to_t2
#define mk_lang_num_longdivmod_t_tn1d_to_tn3 x
#define mk_lang_num_longdivmod_t_tn1t_to_tn3 x
#define mk_lang_num_longdivmod_t_tn2_get_lo mk_sl_cui_inl_defd_t2_get_lo
#define mk_lang_num_longdivmod_t_tn2_get_hi mk_sl_cui_inl_defd_t2_get_hi
#define mk_lang_num_longdivmod_t_tn3_get_tn2 x
#define mk_lang_num_longdivmod_t_tn1_sizebits_d mk_sl_cui_inl_defd_t1_sizebits_d
#define mk_lang_num_longdivmod_t_tn2_sizebits_d mk_sl_cui_inl_defd_t2_sizebits_d
#define mk_lang_num_longdivmod_t_tn3_sizebits_d x
#include "mk_lang_num_longdivmod_inl_fileh.h"
#include "mk_lang_num_longdivmod_inl_filec.h"
#define mk_sl_cui_inl_defd_ldm_divmod4 mk_lang_concat(mk_lang_concat(mk_lang_num_longdivmod_, mk_sl_cui_inl_defd_name), _divmod4)

#define mk_lang_num_longdivmod_t_name mk_lang_concat(mk_lang_num_longdivmods_, mk_sl_cui_inl_defd_name)
#define mk_lang_num_longdivmod_t_tn1 mk_sl_cui_inl_defd_t1
#define mk_lang_num_longdivmod_t_tn2 mk_sl_cui_inl_defd_t2
#define mk_lang_num_longdivmod_t_tn3 x
#define mk_lang_num_longdivmod_t_lena mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ulong_t * mk_lang_charbit)
#define mk_lang_num_longdivmod_t_lenb mk_lang_div_roundup(mk_sl_cui_inl_defd_base_sizebits_d, mk_lang_sizeof_bi_ulong_t * mk_lang_charbit)
#define mk_lang_num_longdivmod_t_endian mk_lang_endian_little
#define mk_lang_num_longdivmod_t_alg 2
#define mk_lang_num_longdivmod_t_tn1s_to_tn2 mk_sl_cui_inl_defd_t1s_to_t2
#define mk_lang_num_longdivmod_t_tn1d_to_tn2 mk_sl_cui_inl_defd_t1d_to_t2
#define mk_lang_num_longdivmod_t_tn1d_to_tn3 x
#define mk_lang_num_longdivmod_t_tn1t_to_tn3 x
#define mk_lang_num_longdivmod_t_tn2_get_lo mk_sl_cui_inl_defd_t2_get_lo
#define mk_lang_num_longdivmod_t_tn2_get_hi mk_sl_cui_inl_defd_t2_get_hi
#define mk_lang_num_longdivmod_t_tn3_get_tn2 x
#define mk_lang_num_longdivmod_t_tn1_sizebits_d mk_sl_cui_inl_defd_t1_sizebits_d
#define mk_lang_num_longdivmod_t_tn2_sizebits_d mk_sl_cui_inl_defd_t2_sizebits_d
#define mk_lang_num_longdivmod_t_tn3_sizebits_d x
#include "mk_lang_num_longdivmod_inl_fileh.h"
#include "mk_lang_num_longdivmod_inl_filec.h"
#define mk_sl_cui_inl_defd_ldms_divmod4 mk_lang_concat(mk_lang_concat(mk_lang_num_longdivmods_, mk_sl_cui_inl_defd_name), _divmod4)

#elif((mk_sl_cui_inl_defd_sizebits_d > mk_lang_sizeof_bi_ulong_t * mk_lang_charbit) && (mk_lang_sizeof_bi_uint_t >= 2 * mk_lang_sizeof_bi_ushort_t))

#define mk_sl_cui_inl_defd_t1 mk_lang_concat(mk_sl_cui_inl_defd_name, _xxx_t1)
#define mk_sl_cui_inl_defd_t1_t mk_lang_concat(mk_sl_cui_inl_defd_t1, _t)
#define mk_sl_cui_inl_defd_t1_pt mk_lang_concat(mk_sl_cui_inl_defd_t1, _pt)
#define mk_sl_cui_inl_defd_t1_pct mk_lang_concat(mk_sl_cui_inl_defd_t1, _pct)
#define mk_lang_bui_t_name mk_sl_cui_inl_defd_t1
#define mk_lang_bui_t_base ushort
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_sl_cui_inl_defd_t1_sizebits_d (mk_lang_sizeof_bi_ushort_t * mk_lang_charbit)

#define mk_sl_cui_inl_defd_t2 mk_lang_concat(mk_sl_cui_inl_defd_name, _xxx_t2)
#define mk_sl_cui_inl_defd_t2_t mk_lang_concat(mk_sl_cui_inl_defd_t2, _t)
#define mk_sl_cui_inl_defd_t2_pt mk_lang_concat(mk_sl_cui_inl_defd_t2, _pt)
#define mk_sl_cui_inl_defd_t2_pct mk_lang_concat(mk_sl_cui_inl_defd_t2, _pct)
#define mk_lang_bui_t_name mk_sl_cui_inl_defd_t2
#define mk_lang_bui_t_base uint
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_sl_cui_inl_defd_t2_sizebits_d (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)

#define mk_sl_cui_inl_defd_t1s_to_t2 mk_lang_concat(mk_sl_cui_inl_defd_name, _zzz_t1s_to_t2)
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_cui_inl_defd_t1s_to_t2(mk_sl_cui_inl_defd_t1_pct const a, mk_sl_cui_inl_defd_t2_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_sl_cui_inl_defd_t2_t)(*a));
}}

#define mk_sl_cui_inl_defd_t1d_to_t2 mk_lang_concat(mk_sl_cui_inl_defd_name, _zzz_t1d_to_t2)
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_cui_inl_defd_t1d_to_t2(mk_sl_cui_inl_defd_t1_pct const a, mk_sl_cui_inl_defd_t1_pct const b, mk_sl_cui_inl_defd_t2_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_sl_cui_inl_defd_t2_t)(((mk_sl_cui_inl_defd_t2_t)(((mk_sl_cui_inl_defd_t2_t)(*a)) << ((mk_lang_types_sint_t)(mk_sl_cui_inl_defd_t1_sizebits_d)))) | ((mk_sl_cui_inl_defd_t2_t)(*b))));
}}

#define mk_sl_cui_inl_defd_t2_get_lo mk_lang_concat(mk_sl_cui_inl_defd_name, _zzz_t2_get_lo)
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_cui_inl_defd_t2_get_lo(mk_sl_cui_inl_defd_t2_pct const a, mk_sl_cui_inl_defd_t1_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_sl_cui_inl_defd_t1_t)(*a));
}}

#define mk_sl_cui_inl_defd_t2_get_hi mk_lang_concat(mk_sl_cui_inl_defd_name, _zzz_t2_get_hi)
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_cui_inl_defd_t2_get_hi(mk_sl_cui_inl_defd_t2_pct const a, mk_sl_cui_inl_defd_t1_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_sl_cui_inl_defd_t1_t)(((mk_sl_cui_inl_defd_t2_t)(((mk_sl_cui_inl_defd_t2_t)(*a)) >> ((mk_lang_types_sint_t)(mk_sl_cui_inl_defd_t1_sizebits_d))))));
}}

#define mk_lang_num_longdivmod_t_name mk_lang_concat(mk_lang_num_longdivmod_, mk_sl_cui_inl_defd_name)
#define mk_lang_num_longdivmod_t_tn1 mk_sl_cui_inl_defd_t1
#define mk_lang_num_longdivmod_t_tn2 mk_sl_cui_inl_defd_t2
#define mk_lang_num_longdivmod_t_tn3 x
#define mk_lang_num_longdivmod_t_lena mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ushort_t * mk_lang_charbit)
#define mk_lang_num_longdivmod_t_lenb mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ushort_t * mk_lang_charbit)
#define mk_lang_num_longdivmod_t_endian mk_lang_endian_little
#define mk_lang_num_longdivmod_t_alg 2
#define mk_lang_num_longdivmod_t_tn1s_to_tn2 mk_sl_cui_inl_defd_t1s_to_t2
#define mk_lang_num_longdivmod_t_tn1d_to_tn2 mk_sl_cui_inl_defd_t1d_to_t2
#define mk_lang_num_longdivmod_t_tn1d_to_tn3 x
#define mk_lang_num_longdivmod_t_tn1t_to_tn3 x
#define mk_lang_num_longdivmod_t_tn2_get_lo mk_sl_cui_inl_defd_t2_get_lo
#define mk_lang_num_longdivmod_t_tn2_get_hi mk_sl_cui_inl_defd_t2_get_hi
#define mk_lang_num_longdivmod_t_tn3_get_tn2 x
#define mk_lang_num_longdivmod_t_tn1_sizebits_d mk_sl_cui_inl_defd_t1_sizebits_d
#define mk_lang_num_longdivmod_t_tn2_sizebits_d mk_sl_cui_inl_defd_t2_sizebits_d
#define mk_lang_num_longdivmod_t_tn3_sizebits_d x
#include "mk_lang_num_longdivmod_inl_fileh.h"
#include "mk_lang_num_longdivmod_inl_filec.h"
#define mk_sl_cui_inl_defd_ldm_divmod4 mk_lang_concat(mk_lang_concat(mk_lang_num_longdivmod_, mk_sl_cui_inl_defd_name), _divmod4)

#define mk_lang_num_longdivmod_t_name mk_lang_concat(mk_lang_num_longdivmods_, mk_sl_cui_inl_defd_name)
#define mk_lang_num_longdivmod_t_tn1 mk_sl_cui_inl_defd_t1
#define mk_lang_num_longdivmod_t_tn2 mk_sl_cui_inl_defd_t2
#define mk_lang_num_longdivmod_t_tn3 x
#define mk_lang_num_longdivmod_t_lena mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ushort_t * mk_lang_charbit)
#define mk_lang_num_longdivmod_t_lenb mk_lang_div_roundup(mk_sl_cui_inl_defd_base_sizebits_d, mk_lang_sizeof_bi_ushort_t * mk_lang_charbit)
#define mk_lang_num_longdivmod_t_endian mk_lang_endian_little
#define mk_lang_num_longdivmod_t_alg 2
#define mk_lang_num_longdivmod_t_tn1s_to_tn2 mk_sl_cui_inl_defd_t1s_to_t2
#define mk_lang_num_longdivmod_t_tn1d_to_tn2 mk_sl_cui_inl_defd_t1d_to_t2
#define mk_lang_num_longdivmod_t_tn1d_to_tn3 x
#define mk_lang_num_longdivmod_t_tn1t_to_tn3 x
#define mk_lang_num_longdivmod_t_tn2_get_lo mk_sl_cui_inl_defd_t2_get_lo
#define mk_lang_num_longdivmod_t_tn2_get_hi mk_sl_cui_inl_defd_t2_get_hi
#define mk_lang_num_longdivmod_t_tn3_get_tn2 x
#define mk_lang_num_longdivmod_t_tn1_sizebits_d mk_sl_cui_inl_defd_t1_sizebits_d
#define mk_lang_num_longdivmod_t_tn2_sizebits_d mk_sl_cui_inl_defd_t2_sizebits_d
#define mk_lang_num_longdivmod_t_tn3_sizebits_d x
#include "mk_lang_num_longdivmod_inl_fileh.h"
#include "mk_lang_num_longdivmod_inl_filec.h"
#define mk_sl_cui_inl_defd_ldms_divmod4 mk_lang_concat(mk_lang_concat(mk_lang_num_longdivmods_, mk_sl_cui_inl_defd_name), _divmod4)

#endif


mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_from_base(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_base_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	a->m_data[mk_sl_cui_inl_defd_idx(0)] = *b;
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	a->m_data[mk_sl_cui_inl_defd_idx(0)] = *b;
	n = mk_sl_cui_inl_defd_count;
	for(i = 1; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_set_zero(&a->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_from_bi_bool(mk_sl_cui_inl_defd_pt const a, mk_lang_types_bool_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);

	mk_sl_cui_inl_defd_base_from_bi_bool(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);

	mk_sl_cui_inl_defd_base_from_bi_bool(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b);
	n = mk_sl_cui_inl_defd_count;
	for(i = 1; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_set_zero(&a->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_from_bi_pchar(mk_sl_cui_inl_defd_pt const a, mk_lang_types_pchar_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_types_uchar_t uc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	uc = ((mk_lang_types_uchar_t)(*b));
	mk_sl_cui_inl_defd_from_bi_uchar(a, &uc);
}}

mm_per_bui(`mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_from_bi_$1(mk_sl_cui_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);

	mk_sl_cui_inl_defd_base_from_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b);
#elif mk_sl_cui_inl_defd_base_sizebits_d >= mk_lang_sizeof_bi_$1_t * mk_lang_charbit
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);

	mk_sl_cui_inl_defd_base_from_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b);
	n = mk_sl_cui_inl_defd_count;
	for(i = 1; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_set_zero(&a->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#else
	#define nn mk_lang_min(mk_sl_cui_inl_defd_count, mk_lang_div_roundup(mk_lang_sizeof_bi_$1_t * mk_lang_charbit, mk_sl_cui_inl_defd_base_sizebits_d))

	mk_lang_types_$1_t bb mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(nn >= 2);
	mk_lang_static_assert(nn <= mk_sl_cui_inl_defd_count);

	mk_lang_assert(a);
	mk_lang_assert(b);

	bb = *b;
	mk_sl_cui_inl_defd_base_from_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &bb);
	n = nn;
	for(i = 1; i != n; ++i)
	{
		bb = ((mk_lang_types_$1_t)(bb >> mk_sl_cui_inl_defd_base_sizebits_d));
		mk_sl_cui_inl_defd_base_from_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &bb);
	}
	#if mk_sl_cui_inl_defd_count > nn
	n = mk_sl_cui_inl_defd_count;
	for(; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_set_zero(&a->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
	#endif

	#undef nn
#endif
}}
')
mm_per_bsi(`mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_from_bi_$1(mk_sl_cui_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_type_traits_to_unsigned_$1_t ui mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ui = ((mk_lang_type_traits_to_unsigned_$1_t)(*b));
	mk_lang_concat(mk_sl_cui_inl_defd_name, mk_lang_concat(_from_bi_, mk_lang_concat(mk_lang_concat(mk_lang_type_traits_to_unsigned_prefix_, $1), _t)))(a, &ui);
}}
')
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_to_base(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_base_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = a->m_data[mk_sl_cui_inl_defd_idx(0)];
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_to_bi_bool(mk_sl_cui_inl_defd_pct const a, mk_lang_types_bool_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = !mk_sl_cui_inl_defd_is_zero(a);
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_to_bi_pchar(mk_sl_cui_inl_defd_pct const a, mk_lang_types_pchar_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_types_uchar_t uc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_inl_defd_to_bi_uchar(a, &uc);
	*b = ((mk_lang_types_pchar_t)(uc));
}}

mm_per_bui(`mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_to_bi_$1(mk_sl_cui_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1 || mk_sl_cui_inl_defd_base_sizebits_d >= mk_lang_sizeof_bi_$1_t * mk_lang_charbit
	mk_lang_assert(a);

	mk_sl_cui_inl_defd_base_to_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b);
#else
	#define nn mk_lang_min(mk_sl_cui_inl_defd_count, mk_lang_div_roundup(mk_lang_sizeof_bi_$1_t * mk_lang_charbit, mk_sl_cui_inl_defd_base_sizebits_d))

	mk_lang_types_$1_t bb mk_lang_constexpr_init;
	mk_lang_types_$1_t bbb mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(nn >= 2);
	mk_lang_static_assert(nn <= mk_sl_cui_inl_defd_count);

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_inl_defd_base_to_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx((nn - 1) - 0)], &bb);
	n = nn;
	for(i = 1; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_to_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx((nn - 1) - i)], &bbb);
		bb = ((mk_lang_types_$1_t)(bb << mk_sl_cui_inl_defd_base_sizebits_d));
		bb = ((mk_lang_types_$1_t)(bb | bbb));
	}
	*b = bb;

	#undef nn
#endif
}}
')
mm_per_bsi(`mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_to_bi_$1(mk_sl_cui_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_type_traits_to_unsigned_$1_t ui mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lang_concat(mk_sl_cui_inl_defd_name, mk_lang_concat(_to_bi_, mk_lang_concat(mk_lang_concat(mk_lang_type_traits_to_unsigned_prefix_, $1), _t)))(a, &ui);
	*b = ((mk_lang_types_$1_t)(ui));
}}
')
mm_per_bui(`#if mk_sl_cui_inl_defd_count == 1
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_from_buis_$1_le_impl_one(mk_sl_cui_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_assert(a);

	mk_sl_cui_inl_defd_base_from_buis_$1_le(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b);
}}
#endif

#if mk_sl_cui_inl_defd_base_sizebits_d == mk_lang_sizeof_bi_$1_t * mk_lang_charbit
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_from_buis_$1_le_impl_same(mk_sl_cui_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_from_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b[i]);
	}
}}
#endif

#if mk_sl_cui_inl_defd_base_sizebits_d > mk_lang_sizeof_bi_$1_t * mk_lang_charbit && mk_sl_cui_inl_defd_base_sizebits_d % (mk_lang_sizeof_bi_$1_t * mk_lang_charbit) == 0
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_from_buis_$1_le_impl_bigger_int(mk_sl_cui_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	#define xx_ratio (mk_sl_cui_inl_defd_base_sizebits_d / (mk_lang_sizeof_bi_$1_t * mk_lang_charbit))

	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_from_buis_$1_le(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b[i * xx_ratio]);
	}

	#undef xx_ratio
}}
#endif

#if mk_lang_sizeof_bi_$1_t * mk_lang_charbit > mk_sl_cui_inl_defd_base_sizebits_d && (mk_lang_sizeof_bi_$1_t * mk_lang_charbit) % mk_sl_cui_inl_defd_base_sizebits_d == 0
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_from_buis_$1_le_impl_smoler_int(mk_sl_cui_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	#define xx_inner ((mk_lang_sizeof_bi_$1_t * mk_lang_charbit) / mk_sl_cui_inl_defd_base_sizebits_d)
	#define xx_outer (mk_sl_cui_inl_defd_count / xx_inner)
	#define xx_rest (mk_sl_cui_inl_defd_count - (xx_outer * xx_inner))

	mk_lang_types_sint_t m mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_$1_t bb mk_lang_constexpr_init;
	#if xx_outer != 0
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	#endif
	#if xx_rest != 0
	#if xx_rest >= 2
	mk_lang_types_sint_t r mk_lang_constexpr_init;
	mk_lang_types_sint_t k mk_lang_constexpr_init;
	#endif
	#endif

	mk_lang_static_assert(xx_inner >= 2);
	mk_lang_static_assert(xx_outer >= 0);
	mk_lang_static_assert(xx_outer * xx_inner <= mk_sl_cui_inl_defd_count);
	mk_lang_static_assert(xx_outer * xx_inner + xx_rest == mk_sl_cui_inl_defd_count);
	mk_lang_static_assert(xx_rest >= 0);
	mk_lang_static_assert(xx_rest < xx_inner);

	mk_lang_assert(a);
	mk_lang_assert(b);

	m = mk_lang_min(mk_sl_cui_inl_defd_count, xx_inner);
	i = 0;
	#if xx_outer != 0
	n = xx_outer;
	for(i = 0; i != n; ++i)
	{
		bb = b[i];
		mk_sl_cui_inl_defd_base_from_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i * m + 0)], &bb);
		for(j = 1; j != m; ++j)
		{
			bb = ((mk_lang_types_$1_t)(bb >> mk_sl_cui_inl_defd_base_sizebits_d));
			mk_sl_cui_inl_defd_base_from_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i * m + j)], &bb);
		}
	}
	#endif
	#if xx_rest != 0
	bb = b[i];
	mk_sl_cui_inl_defd_base_from_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i * m + 0)], &bb);
	#if xx_rest >= 2
	r = xx_rest;
	for(k = 1; k != r; ++k)
	{
		bb = ((mk_lang_types_$1_t)(bb >> mk_sl_cui_inl_defd_base_sizebits_d));
		mk_sl_cui_inl_defd_base_from_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i * m + k)], &bb);
	}
	#endif
	#endif

	#undef xx_inner
	#undef xx_outer
	#undef xx_rest
}}
#endif

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_from_buis_$1_le(mk_sl_cui_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_sl_cui_inl_defd_from_buis_$1_le_impl_one(a, b);
#elif mk_sl_cui_inl_defd_base_sizebits_d == mk_lang_sizeof_bi_$1_t * mk_lang_charbit
	mk_sl_cui_inl_defd_from_buis_$1_le_impl_same(a, b);
#elif mk_sl_cui_inl_defd_base_sizebits_d > mk_lang_sizeof_bi_$1_t * mk_lang_charbit && mk_sl_cui_inl_defd_base_sizebits_d % (mk_lang_sizeof_bi_$1_t * mk_lang_charbit) == 0
	mk_sl_cui_inl_defd_from_buis_$1_le_impl_bigger_int(a, b);
#elif mk_lang_sizeof_bi_$1_t * mk_lang_charbit > mk_sl_cui_inl_defd_base_sizebits_d && (mk_lang_sizeof_bi_$1_t * mk_lang_charbit) % mk_sl_cui_inl_defd_base_sizebits_d == 0
	mk_sl_cui_inl_defd_from_buis_$1_le_impl_smoler_int(a, b);
#else
	#error xxxxxxxxxx todo
	mk_lang_assert(0);
#endif
}}
')
mm_per_bui(`#if mk_sl_cui_inl_defd_count == 1
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_to_buis_$1_le_impl_one(mk_sl_cui_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_assert(a);

	mk_sl_cui_inl_defd_base_to_buis_$1_le(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b);
}}
#endif

#if mk_sl_cui_inl_defd_base_sizebits_d == mk_lang_sizeof_bi_$1_t * mk_lang_charbit
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_to_buis_$1_le_impl_same(mk_sl_cui_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_to_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b[i]);
	}
}}
#endif

#if mk_sl_cui_inl_defd_base_sizebits_d > mk_lang_sizeof_bi_$1_t * mk_lang_charbit && mk_sl_cui_inl_defd_base_sizebits_d % (mk_lang_sizeof_bi_$1_t * mk_lang_charbit) == 0
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_to_buis_$1_le_impl_bigger_int(mk_sl_cui_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	#define xx_ratio (mk_sl_cui_inl_defd_base_sizebits_d / (mk_lang_sizeof_bi_$1_t * mk_lang_charbit))

	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_to_buis_$1_le(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b[i * xx_ratio]);
	}

	#undef xx_ratio
}}
#endif

#if mk_lang_sizeof_bi_$1_t * mk_lang_charbit > mk_sl_cui_inl_defd_base_sizebits_d && (mk_lang_sizeof_bi_$1_t * mk_lang_charbit) % mk_sl_cui_inl_defd_base_sizebits_d == 0
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_to_buis_$1_le_impl_smoler_int(mk_sl_cui_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	#define xx_inner ((mk_lang_sizeof_bi_$1_t * mk_lang_charbit) / mk_sl_cui_inl_defd_base_sizebits_d)
	#define xx_outer (mk_sl_cui_inl_defd_count / xx_inner)
	#define xx_rest (mk_sl_cui_inl_defd_count - (xx_outer * xx_inner))

	mk_lang_types_sint_t m mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	#if xx_outer != 0
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	#endif
	#if xx_outer != 0 || xx_rest != 0
	mk_lang_types_$1_t bb mk_lang_constexpr_init;
	#endif
	#if xx_outer != 0 || xx_rest >= 2
	mk_lang_types_$1_t bbb mk_lang_constexpr_init;
	#endif
	#if xx_rest != 0
	mk_lang_types_sint_t r mk_lang_constexpr_init;
	#if xx_rest >= 2
	mk_lang_types_sint_t k mk_lang_constexpr_init;
	#endif
	#endif

	mk_lang_static_assert(xx_inner >= 2);
	mk_lang_static_assert(xx_outer >= 0);
	mk_lang_static_assert(xx_outer * xx_inner <= mk_sl_cui_inl_defd_count);
	mk_lang_static_assert(xx_outer * xx_inner + xx_rest == mk_sl_cui_inl_defd_count);
	mk_lang_static_assert(xx_rest >= 0);
	mk_lang_static_assert(xx_rest < xx_inner);

	mk_lang_assert(a);
	mk_lang_assert(b);

	m = mk_lang_min(mk_sl_cui_inl_defd_count, xx_inner);
	i = 0;
	#if xx_outer != 0
	n = xx_outer;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_to_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i * m + (m - 1) - 0)], &bb);
		for(j = 1; j != m; ++j)
		{
			mk_sl_cui_inl_defd_base_to_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i * m + (m - 1) - j)], &bbb);
			bb = ((mk_lang_types_$1_t)(bb << mk_sl_cui_inl_defd_base_sizebits_d));
			bb = ((mk_lang_types_$1_t)(bb | bbb));
		}
		b[i] = bb;
	}
	#endif
	#if xx_rest != 0
	r = xx_rest;
	mk_sl_cui_inl_defd_base_to_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i * m + (r - 1) - 0)], &bb);
	#if xx_rest >= 2
	for(k = 1; k != r; ++k)
	{
		mk_sl_cui_inl_defd_base_to_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i * m + (r - 1) - k)], &bbb);
		bb = ((mk_lang_types_$1_t)(bb << mk_sl_cui_inl_defd_base_sizebits_d));
		bb = ((mk_lang_types_$1_t)(bb | bbb));
	}
	#endif
	b[i] = bb;
	#endif

	#undef xx_inner
	#undef xx_outer
	#undef xx_rest
}}
#endif

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_to_buis_$1_le(mk_sl_cui_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_sl_cui_inl_defd_to_buis_$1_le_impl_one(a, b);
#elif mk_sl_cui_inl_defd_base_sizebits_d == mk_lang_sizeof_bi_$1_t * mk_lang_charbit
	mk_sl_cui_inl_defd_to_buis_$1_le_impl_same(a, b);
#elif mk_sl_cui_inl_defd_base_sizebits_d > mk_lang_sizeof_bi_$1_t * mk_lang_charbit && mk_sl_cui_inl_defd_base_sizebits_d % (mk_lang_sizeof_bi_$1_t * mk_lang_charbit) == 0
	mk_sl_cui_inl_defd_to_buis_$1_le_impl_bigger_int(a, b);
#elif mk_lang_sizeof_bi_$1_t * mk_lang_charbit > mk_sl_cui_inl_defd_base_sizebits_d && (mk_lang_sizeof_bi_$1_t * mk_lang_charbit) % mk_sl_cui_inl_defd_base_sizebits_d == 0
	mk_sl_cui_inl_defd_to_buis_$1_le_impl_smoler_int(a, b);
#else
	#error xxxxxxxxxx todo
	mk_lang_assert(0);
#endif
}}
')
mm_per_bui(`#if mk_sl_cui_inl_defd_count == 1
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_from_buis_$1_be_impl_one(mk_sl_cui_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_assert(a);

	mk_sl_cui_inl_defd_base_from_buis_$1_be(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b);
}}
#endif

#if mk_sl_cui_inl_defd_base_sizebits_d == mk_lang_sizeof_bi_$1_t * mk_lang_charbit
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_from_buis_$1_be_impl_same(mk_sl_cui_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_from_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b[(mk_sl_cui_inl_defd_count - 1) - i]);
	}
}}
#endif

#if mk_sl_cui_inl_defd_base_sizebits_d > mk_lang_sizeof_bi_$1_t * mk_lang_charbit && mk_sl_cui_inl_defd_base_sizebits_d % (mk_lang_sizeof_bi_$1_t * mk_lang_charbit) == 0
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_from_buis_$1_be_impl_bigger_int(mk_sl_cui_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	#define xx_cnt ((mk_sl_cui_inl_defd_count * mk_sl_cui_inl_defd_base_sizebits_d) / (mk_lang_sizeof_bi_$1_t * mk_lang_charbit))
	#define xx_ratio (mk_sl_cui_inl_defd_base_sizebits_d / (mk_lang_sizeof_bi_$1_t * mk_lang_charbit))

	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_from_buis_$1_be(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b[(xx_cnt - xx_ratio) - (i * xx_ratio)]);
	}

	#undef xx_cnt
	#undef xx_ratio
}}
#endif

#if mk_lang_sizeof_bi_$1_t * mk_lang_charbit > mk_sl_cui_inl_defd_base_sizebits_d && (mk_lang_sizeof_bi_$1_t * mk_lang_charbit) % mk_sl_cui_inl_defd_base_sizebits_d == 0
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_from_buis_$1_be_impl_smoler_int(mk_sl_cui_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	#define xx_inner ((mk_lang_sizeof_bi_$1_t * mk_lang_charbit) / mk_sl_cui_inl_defd_base_sizebits_d)
	#define xx_outer (mk_sl_cui_inl_defd_count / xx_inner)
	#define xx_rest (mk_sl_cui_inl_defd_count - (xx_outer * xx_inner))
	#define xx_cnt mk_lang_div_roundup(mk_sl_cui_inl_defd_count * mk_sl_cui_inl_defd_base_sizebits_d, mk_lang_sizeof_bi_$1_t * mk_lang_charbit)

	mk_lang_types_sint_t m mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_$1_t bb mk_lang_constexpr_init;
	#if xx_outer != 0
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	#endif
	#if xx_rest >= 2
	mk_lang_types_sint_t r mk_lang_constexpr_init;
	mk_lang_types_sint_t k mk_lang_constexpr_init;
	#endif

	mk_lang_static_assert(xx_inner >= 2);
	mk_lang_static_assert(xx_outer >= 0);
	mk_lang_static_assert(xx_outer * xx_inner <= mk_sl_cui_inl_defd_count);
	mk_lang_static_assert(xx_outer * xx_inner + xx_rest == mk_sl_cui_inl_defd_count);
	mk_lang_static_assert(xx_rest >= 0);
	mk_lang_static_assert(xx_rest < xx_inner);

	mk_lang_assert(a);
	mk_lang_assert(b);

	m = mk_lang_min(mk_sl_cui_inl_defd_count, xx_inner);
	i = 0;
	#if xx_outer != 0
	n = xx_outer;
	for(i = 0; i != n; ++i)
	{
		bb = b[(xx_cnt - 1) - i];
		mk_sl_cui_inl_defd_base_from_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i * m + 0)], &bb);
		for(j = 1; j != m; ++j)
		{
			bb = ((mk_lang_types_$1_t)(bb >> mk_sl_cui_inl_defd_base_sizebits_d));
			mk_sl_cui_inl_defd_base_from_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i * m + j)], &bb);
		}
	}
	#endif
	#if xx_rest != 0
	bb = b[(xx_cnt - 1) - i];
	mk_sl_cui_inl_defd_base_from_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i * m + 0)], &bb);
	#if xx_rest >= 2
	r = xx_rest;
	for(k = 1; k != r; ++k)
	{
		bb = ((mk_lang_types_$1_t)(bb >> mk_sl_cui_inl_defd_base_sizebits_d));
		mk_sl_cui_inl_defd_base_from_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i * m + k)], &bb);
	}
	#endif
	#endif

	#undef xx_inner
	#undef xx_outer
	#undef xx_rest
	#undef xx_cnt
}}
#endif

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_from_buis_$1_be(mk_sl_cui_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_sl_cui_inl_defd_from_buis_$1_be_impl_one(a, b);
#elif mk_sl_cui_inl_defd_base_sizebits_d == mk_lang_sizeof_bi_$1_t * mk_lang_charbit
	mk_sl_cui_inl_defd_from_buis_$1_be_impl_same(a, b);
#elif mk_sl_cui_inl_defd_base_sizebits_d > mk_lang_sizeof_bi_$1_t * mk_lang_charbit && mk_sl_cui_inl_defd_base_sizebits_d % (mk_lang_sizeof_bi_$1_t * mk_lang_charbit) == 0
	mk_sl_cui_inl_defd_from_buis_$1_be_impl_bigger_int(a, b);
#elif mk_lang_sizeof_bi_$1_t * mk_lang_charbit > mk_sl_cui_inl_defd_base_sizebits_d && (mk_lang_sizeof_bi_$1_t * mk_lang_charbit) % mk_sl_cui_inl_defd_base_sizebits_d == 0
	mk_sl_cui_inl_defd_from_buis_$1_be_impl_smoler_int(a, b);
#else
	#error xxxxxxxxxx todo
	mk_lang_assert(0);
#endif
}}
')
mm_per_bui(`#if mk_sl_cui_inl_defd_count == 1
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_to_buis_$1_be_impl_one(mk_sl_cui_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_assert(a);

	mk_sl_cui_inl_defd_base_to_buis_$1_be(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b);
}}
#endif

#if mk_sl_cui_inl_defd_base_sizebits_d == mk_lang_sizeof_bi_$1_t * mk_lang_charbit
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_to_buis_$1_be_impl_same(mk_sl_cui_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_to_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b[(mk_sl_cui_inl_defd_count - 1) - i]);
	}
}}
#endif

#if mk_sl_cui_inl_defd_base_sizebits_d > mk_lang_sizeof_bi_$1_t * mk_lang_charbit && mk_sl_cui_inl_defd_base_sizebits_d % (mk_lang_sizeof_bi_$1_t * mk_lang_charbit) == 0
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_to_buis_$1_be_impl_bigger_int(mk_sl_cui_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	#define xx_cnt ((mk_sl_cui_inl_defd_count * mk_sl_cui_inl_defd_base_sizebits_d) / (mk_lang_sizeof_bi_$1_t * mk_lang_charbit))
	#define xx_ratio (mk_sl_cui_inl_defd_base_sizebits_d / (mk_lang_sizeof_bi_$1_t * mk_lang_charbit))

	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_to_buis_$1_be(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b[(xx_cnt - xx_ratio) - (i * xx_ratio)]);
	}

	#undef xx_cnt
	#undef xx_ratio
}}
#endif

#if mk_lang_sizeof_bi_$1_t * mk_lang_charbit > mk_sl_cui_inl_defd_base_sizebits_d && (mk_lang_sizeof_bi_$1_t * mk_lang_charbit) % mk_sl_cui_inl_defd_base_sizebits_d == 0
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_to_buis_$1_be_impl_smoler_int(mk_sl_cui_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	#define xx_inner ((mk_lang_sizeof_bi_$1_t * mk_lang_charbit) / mk_sl_cui_inl_defd_base_sizebits_d)
	#define xx_outer (mk_sl_cui_inl_defd_count / xx_inner)
	#define xx_rest (mk_sl_cui_inl_defd_count - (xx_outer * xx_inner))
	#define xx_cnt mk_lang_div_roundup(mk_sl_cui_inl_defd_count * mk_sl_cui_inl_defd_base_sizebits_d, mk_lang_sizeof_bi_$1_t * mk_lang_charbit)

	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t m mk_lang_constexpr_init;
	#if xx_outer != 0
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	#endif
	#if xx_outer != 0 || xx_rest != 0
	mk_lang_types_$1_t bb mk_lang_constexpr_init;
	#endif
	#if xx_outer != 0 || xx_rest >= 2
	mk_lang_types_$1_t bbb mk_lang_constexpr_init;
	#endif
	#if xx_rest != 0
	mk_lang_types_sint_t r mk_lang_constexpr_init;
	#if xx_rest >= 2
	mk_lang_types_sint_t k mk_lang_constexpr_init;
	#endif
	#endif

	mk_lang_static_assert(xx_inner >= 2);
	mk_lang_static_assert(xx_outer >= 0);
	mk_lang_static_assert(xx_outer * xx_inner <= mk_sl_cui_inl_defd_count);
	mk_lang_static_assert(xx_outer * xx_inner + xx_rest == mk_sl_cui_inl_defd_count);
	mk_lang_static_assert(xx_rest >= 0);
	mk_lang_static_assert(xx_rest < xx_inner);

	mk_lang_assert(a);
	mk_lang_assert(b);

	i = 0;
	m = mk_lang_min(mk_sl_cui_inl_defd_count, xx_inner);
	#if xx_outer != 0
	n = xx_outer;
	for(; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_to_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i * m + (m - 1) - 0)], &bb);
		for(j = 1; j != m; ++j)
		{
			mk_sl_cui_inl_defd_base_to_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i * m + (m - 1) - j)], &bbb);
			bb = ((mk_lang_types_$1_t)(bb << mk_sl_cui_inl_defd_base_sizebits_d));
			bb = ((mk_lang_types_$1_t)(bb | bbb));
		}
		b[(xx_cnt - 1) - i] = bb;
	}
	#endif
	#if xx_rest != 0
	r = xx_rest;
	mk_sl_cui_inl_defd_base_to_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i * m + (r - 1) - 0)], &bb);
	#if xx_rest >= 2
	for(k = 1; k != r; ++k)
	{
		mk_sl_cui_inl_defd_base_to_bi_$1(&a->m_data[mk_sl_cui_inl_defd_idx(i * m + (r - 1) - k)], &bbb);
		bb = ((mk_lang_types_$1_t)(bb << mk_sl_cui_inl_defd_base_sizebits_d));
		bb = ((mk_lang_types_$1_t)(bb | bbb));
	}
	#endif
	b[(xx_cnt - 1) - i] = bb;
	#endif

	#undef xx_inner
	#undef xx_outer
	#undef xx_rest
	#undef xx_cnt
}}
#endif

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_to_buis_$1_be(mk_sl_cui_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_sl_cui_inl_defd_to_buis_$1_be_impl_one(a, b);
#elif mk_sl_cui_inl_defd_base_sizebits_d == mk_lang_sizeof_bi_$1_t * mk_lang_charbit
	mk_sl_cui_inl_defd_to_buis_$1_be_impl_same(a, b);
#elif mk_sl_cui_inl_defd_base_sizebits_d > mk_lang_sizeof_bi_$1_t * mk_lang_charbit && mk_sl_cui_inl_defd_base_sizebits_d % (mk_lang_sizeof_bi_$1_t * mk_lang_charbit) == 0
	mk_sl_cui_inl_defd_to_buis_$1_be_impl_bigger_int(a, b);
#elif mk_lang_sizeof_bi_$1_t * mk_lang_charbit > mk_sl_cui_inl_defd_base_sizebits_d && (mk_lang_sizeof_bi_$1_t * mk_lang_charbit) % mk_sl_cui_inl_defd_base_sizebits_d == 0
	mk_sl_cui_inl_defd_to_buis_$1_be_impl_smoler_int(a, b);
#else
	#error xxxxxxxxxx todo
	mk_lang_assert(0);
#endif
}}
')
mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_assign(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_inl_defd_base_assign(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_assign(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_set_zero(mk_sl_cui_inl_defd_pt const x) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);

	mk_sl_cui_inl_defd_base_set_zero(&x->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(x);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_set_zero(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_set_max(mk_sl_cui_inl_defd_pt const x) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);

	mk_sl_cui_inl_defd_base_set_max(&x->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(x);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_set_max(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_set_one(mk_sl_cui_inl_defd_pt const x) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);

	mk_sl_cui_inl_defd_base_set_one(&x->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_sl_cui_inl_defd_base_set_one(&x->m_data[mk_sl_cui_inl_defd_idx(0)]);
	n = mk_sl_cui_inl_defd_count;
	for(i = 1; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_set_zero(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_set_bit(mk_sl_cui_inl_defd_pt const x, mk_lang_types_sint_t const bit_idx) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);

	mk_sl_cui_inl_defd_base_set_bit(&x->m_data[mk_sl_cui_inl_defd_idx(0)], bit_idx);
#else
	mk_lang_assert(x);
	mk_lang_assert(bit_idx >= 0 && bit_idx < mk_sl_cui_inl_defd_sizebits_d);

	mk_sl_cui_inl_defd_set_zero(x);
	mk_sl_cui_inl_defd_base_set_bit(&x->m_data[mk_sl_cui_inl_defd_idx(bit_idx / mk_sl_cui_inl_defd_base_sizebits_d)], bit_idx % mk_sl_cui_inl_defd_base_sizebits_d);
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_set_mask(mk_sl_cui_inl_defd_pt const x, mk_lang_types_sint_t const bits_count) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);

	mk_sl_cui_inl_defd_base_set_mask(&x->m_data[mk_sl_cui_inl_defd_idx(0)], bits_count);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(bits_count >= 1 && bits_count <= mk_sl_cui_inl_defd_sizebits_d);

	n = bits_count / mk_sl_cui_inl_defd_base_sizebits_d;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_set_max(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
	if(bits_count % mk_sl_cui_inl_defd_base_sizebits_d != 0)
	{
		mk_sl_cui_inl_defd_base_set_mask(&x->m_data[mk_sl_cui_inl_defd_idx(i)], bits_count % mk_sl_cui_inl_defd_base_sizebits_d);
		++i;
	}
	n = mk_sl_cui_inl_defd_count;
	for(; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_set_zero(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_cui_inl_defd_count_leading_zeros(mk_sl_cui_inl_defd_pct const x) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);

	return mk_sl_cui_inl_defd_base_count_leading_zeros(&x->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t cnt mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(x);

	cnt = 0;
	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		if(mk_sl_cui_inl_defd_base_is_zero(&x->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]))
		{
			cnt += mk_sl_cui_inl_defd_base_sizebits_d;
		}
		else
		{
			cnt += mk_sl_cui_inl_defd_base_count_leading_zeros(&x->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]);
			break;
		}
	}
	return cnt;
#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_cui_inl_defd_count_leading_ones(mk_sl_cui_inl_defd_pct const x) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);

	return mk_sl_cui_inl_defd_base_count_leading_ones(&x->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t cnt mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(x);

	cnt = 0;
	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		if(mk_sl_cui_inl_defd_base_is_max(&x->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]))
		{
			cnt += mk_sl_cui_inl_defd_base_sizebits_d;
		}
		else
		{
			cnt += mk_sl_cui_inl_defd_base_count_leading_ones(&x->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]);
			break;
		}
	}
	return cnt;
#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_cui_inl_defd_count_trailing_zeros(mk_sl_cui_inl_defd_pct const x) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);

	return mk_sl_cui_inl_defd_base_count_trailing_zeros(&x->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t cnt mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(x);

	cnt = 0;
	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		if(mk_sl_cui_inl_defd_base_is_zero(&x->m_data[mk_sl_cui_inl_defd_idx(i)]))
		{
			cnt += mk_sl_cui_inl_defd_base_sizebits_d;
		}
		else
		{
			cnt += mk_sl_cui_inl_defd_base_count_trailing_zeros(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
			break;
		}
	}
	return cnt;
#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_cui_inl_defd_count_trailing_ones(mk_sl_cui_inl_defd_pct const x) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);

	return mk_sl_cui_inl_defd_base_count_trailing_ones(&x->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t cnt mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(x);

	cnt = 0;
	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		if(mk_sl_cui_inl_defd_base_is_max(&x->m_data[mk_sl_cui_inl_defd_idx(i)]))
		{
			cnt += mk_sl_cui_inl_defd_base_sizebits_d;
		}
		else
		{
			cnt += mk_sl_cui_inl_defd_base_count_trailing_ones(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
			break;
		}
	}
	return cnt;
#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_cui_inl_defd_count_zeros(mk_sl_cui_inl_defd_pct const x) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);

	return mk_sl_cui_inl_defd_base_count_zeros(&x->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t cnt mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(x);

	cnt = 0;
	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		cnt += mk_sl_cui_inl_defd_base_count_zeros(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
	return cnt;
#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_cui_inl_defd_count_ones(mk_sl_cui_inl_defd_pct const x) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);

	return mk_sl_cui_inl_defd_base_count_ones(&x->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t cnt mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(x);

	cnt = 0;
	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		cnt += mk_sl_cui_inl_defd_base_count_ones(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
	return cnt;
#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_cui_inl_defd_has_lsb(mk_sl_cui_inl_defd_pct const x) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_assert(x);

	return mk_sl_cui_inl_defd_base_has_lsb(&x->m_data[mk_sl_cui_inl_defd_idx(0)]);
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_cui_inl_defd_is_zero(mk_sl_cui_inl_defd_pct const x) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);

	return mk_sl_cui_inl_defd_base_is_zero(&x->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(x);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		if(!mk_sl_cui_inl_defd_base_is_zero(&x->m_data[mk_sl_cui_inl_defd_idx(i)]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_cui_inl_defd_is_one(mk_sl_cui_inl_defd_pct const x) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);

	return mk_sl_cui_inl_defd_base_is_one(&x->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(x);

	if(!mk_sl_cui_inl_defd_base_is_one(&x->m_data[mk_sl_cui_inl_defd_idx(0)]))
	{
		return mk_lang_false;
	}
	n = mk_sl_cui_inl_defd_count;
	for(i = 1; i != n; ++i)
	{
		if(!mk_sl_cui_inl_defd_base_is_zero(&x->m_data[mk_sl_cui_inl_defd_idx(i)]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_cui_inl_defd_is_max(mk_sl_cui_inl_defd_pct const x) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);

	return mk_sl_cui_inl_defd_base_is_max(&x->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(x);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		if(!mk_sl_cui_inl_defd_base_is_max(&x->m_data[mk_sl_cui_inl_defd_idx(i)]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_cui_inl_defd_eq(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	return mk_sl_cui_inl_defd_base_eq(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	if(a == b)
	{
		return mk_lang_true;
	}
	else
	{
		mk_lang_types_sint_t n mk_lang_constexpr_init;
		mk_lang_types_sint_t i mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);

		n = mk_sl_cui_inl_defd_count;
		for(i = 0; i != n; ++i)
		{
			if(!mk_sl_cui_inl_defd_base_eq(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]))
			{
				return mk_lang_false;
			}
		}
		return mk_lang_true;
	}
#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_cui_inl_defd_ne(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	return mk_sl_cui_inl_defd_base_ne(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	if(a == b)
	{
		return mk_lang_false;
	}
	else
	{
		mk_lang_types_sint_t n mk_lang_constexpr_init;
		mk_lang_types_sint_t i mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);

		n = mk_sl_cui_inl_defd_count;
		for(i = 0; i != n; ++i)
		{
			if(mk_sl_cui_inl_defd_base_ne(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]))
			{
				return mk_lang_true;
			}
		}
		return mk_lang_false;
	}
#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_cui_inl_defd_lt(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	return mk_sl_cui_inl_defd_base_lt(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	if(a == b)
	{
		return mk_lang_false;
	}
	else
	{
		mk_lang_types_sint_t n mk_lang_constexpr_init;
		mk_lang_types_sint_t i mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);

		n = mk_sl_cui_inl_defd_count;
		for(i = 0; i != n; ++i)
		{
			if(mk_sl_cui_inl_defd_base_lt(&a->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)], &b->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]))
			{
				return mk_lang_true;
			}
			else if(mk_sl_cui_inl_defd_base_lt(&b->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)], &a->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]))
			{
				return mk_lang_false;
			}
		}
		return mk_lang_false;
	}
#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_cui_inl_defd_le(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	return mk_sl_cui_inl_defd_base_le(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	if(a == b)
	{
		return mk_lang_true;
	}
	else
	{
		mk_lang_types_sint_t n mk_lang_constexpr_init;
		mk_lang_types_sint_t i mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);

		n = mk_sl_cui_inl_defd_count;
		for(i = 0; i != n; ++i)
		{
			if(mk_sl_cui_inl_defd_base_lt(&a->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)], &b->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]))
			{
				return mk_lang_true;
			}
			else if(mk_sl_cui_inl_defd_base_lt(&b->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)], &a->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]))
			{
				return mk_lang_false;
			}
		}
		return mk_lang_true;
	}
#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_cui_inl_defd_gt(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	return mk_sl_cui_inl_defd_base_gt(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	if(a == b)
	{
		return mk_lang_false;
	}
	else
	{
		mk_lang_types_sint_t n mk_lang_constexpr_init;
		mk_lang_types_sint_t i mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);

		n = mk_sl_cui_inl_defd_count;
		for(i = 0; i != n; ++i)
		{
			if(mk_sl_cui_inl_defd_base_gt(&a->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)], &b->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]))
			{
				return mk_lang_true;
			}
			else if(mk_sl_cui_inl_defd_base_gt(&b->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)], &a->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]))
			{
				return mk_lang_false;
			}
		}
		return mk_lang_false;
	}
#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_cui_inl_defd_ge(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	return mk_sl_cui_inl_defd_base_ge(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	if(a == b)
	{
		return mk_lang_true;
	}
	else
	{
		mk_lang_types_sint_t n mk_lang_constexpr_init;
		mk_lang_types_sint_t i mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);

		n = mk_sl_cui_inl_defd_count;
		for(i = 0; i != n; ++i)
		{
			if(mk_sl_cui_inl_defd_base_gt(&a->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)], &b->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]))
			{
				return mk_lang_true;
			}
			else if(mk_sl_cui_inl_defd_base_gt(&b->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)], &a->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]))
			{
				return mk_lang_false;
			}
		}
		return mk_lang_true;
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_inc2(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_inl_defd_base_inc2(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	if(a == b)
	{
		mk_sl_cui_inl_defd_inc1(b);
	}
	else
	{
		mk_lang_types_bool_t c mk_lang_constexpr_init;
		mk_lang_types_sint_t n mk_lang_constexpr_init;
		mk_lang_types_sint_t i mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);

		c = mk_lang_true;
		n = mk_sl_cui_inl_defd_count - 1;
		for(i = 0; i != n && c; ++i)
		{
			mk_sl_cui_inl_defd_base_inc2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
			c = mk_sl_cui_inl_defd_base_is_zero(&b->m_data[mk_sl_cui_inl_defd_idx(i)]);
		}
		if(c)
		{
			mk_sl_cui_inl_defd_base_inc2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
			++i;
		}
		n = mk_sl_cui_inl_defd_count;
		for(; i != n; ++i)
		{
			b->m_data[mk_sl_cui_inl_defd_idx(i)] = a->m_data[mk_sl_cui_inl_defd_idx(i)];
		}
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_dec2(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_inl_defd_base_dec2(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	if(a == b)
	{
		mk_sl_cui_inl_defd_dec1(b);
	}
	else
	{
		mk_lang_types_bool_t c mk_lang_constexpr_init;
		mk_lang_types_sint_t n mk_lang_constexpr_init;
		mk_lang_types_sint_t i mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);

		c = mk_lang_true;
		n = mk_sl_cui_inl_defd_count - 1;
		for(i = 0; i != n && c; ++i)
		{
			c = mk_sl_cui_inl_defd_base_is_zero(&a->m_data[mk_sl_cui_inl_defd_idx(i)]);
			mk_sl_cui_inl_defd_base_dec2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
		}
		if(c)
		{
			mk_sl_cui_inl_defd_base_dec2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
			++i;
		}
		n = mk_sl_cui_inl_defd_count;
		for(; i != n; ++i)
		{
			b->m_data[mk_sl_cui_inl_defd_idx(i)] = a->m_data[mk_sl_cui_inl_defd_idx(i)];
		}
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_inc1(mk_sl_cui_inl_defd_pt const x) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);

	mk_sl_cui_inl_defd_base_inc1(&x->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_bool_t c mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(x);

	c = mk_lang_true;
	n = mk_sl_cui_inl_defd_count - 1;
	for(i = 0; i != n && c; ++i)
	{
		mk_sl_cui_inl_defd_base_inc1(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
		c = mk_sl_cui_inl_defd_base_is_zero(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
	if(c)
	{
		mk_sl_cui_inl_defd_base_inc1(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_dec1(mk_sl_cui_inl_defd_pt const x) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);

	mk_sl_cui_inl_defd_base_dec1(&x->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_bool_t c mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(x);

	c = mk_lang_true;
	n = mk_sl_cui_inl_defd_count - 1;
	for(i = 0; i != n && c; ++i)
	{
		mk_sl_cui_inl_defd_base_dec1(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
		c = mk_sl_cui_inl_defd_base_is_max(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
	if(c)
	{
		mk_sl_cui_inl_defd_base_dec1(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_not2(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_inl_defd_base_not2(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_not2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_or3(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_or3(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_or3(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_and3(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_and3(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_and3(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_xor3(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_xor3(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_xor3(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_not1(mk_sl_cui_inl_defd_pt const x) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);

	mk_sl_cui_inl_defd_base_not1(&x->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(x);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_not1(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_or2(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_inl_defd_base_or2(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_or2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_and2(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_inl_defd_base_and2(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_and2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_xor2(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_inl_defd_base_xor2(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_xor2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_shl3(mk_sl_cui_inl_defd_pct const a, mk_lang_types_sint_t const b, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < mk_sl_cui_inl_defd_sizebits_d);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_shl3(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b, &c->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t big mk_lang_constexpr_init;
	mk_lang_types_sint_t smol mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t t mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < mk_sl_cui_inl_defd_sizebits_d);
	mk_lang_assert(c);

	big = ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(b)) / ((mk_lang_types_sint_t)(mk_sl_cui_inl_defd_base_sizebits_d))));
	smol = ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(b)) % ((mk_lang_types_sint_t)(mk_sl_cui_inl_defd_base_sizebits_d))));
	if(smol == 0)
	{
		n = mk_sl_cui_inl_defd_count - big;
		for(i = 0; i != n; ++i)
		{
			c->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)] = a->m_data[mk_sl_cui_inl_defd_idx(((mk_sl_cui_inl_defd_count - 1) - big) - i)];
		}
		n = mk_sl_cui_inl_defd_count;
		for(; i != n; ++i)
		{
			mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]);
		}
	}
	else
	{
		n = mk_sl_cui_inl_defd_count - big - 1;
		for(i = 0; i != n; ++i)
		{
			mk_sl_cui_inl_defd_base_shl3(&a->m_data[mk_sl_cui_inl_defd_idx((((mk_sl_cui_inl_defd_count - 1) - 0) - big) - i)], smol, &c->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]);
			mk_sl_cui_inl_defd_base_shr3(&a->m_data[mk_sl_cui_inl_defd_idx((((mk_sl_cui_inl_defd_count - 1) - 1) - big) - i)], mk_sl_cui_inl_defd_base_sizebits_d - smol, &t);
			mk_sl_cui_inl_defd_base_or2(&c->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)], &t);
		}
		mk_sl_cui_inl_defd_base_shl3(&a->m_data[mk_sl_cui_inl_defd_idx((((mk_sl_cui_inl_defd_count - 1) - 0) - big) - i)], smol, &c->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]);
		n = mk_sl_cui_inl_defd_count;
		for(++i; i != n; ++i)
		{
			mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]);
		}
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_shr3(mk_sl_cui_inl_defd_pct const a, mk_lang_types_sint_t const b, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < mk_sl_cui_inl_defd_sizebits_d);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_shr3(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b, &c->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t big mk_lang_constexpr_init;
	mk_lang_types_sint_t smol mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t t mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < mk_sl_cui_inl_defd_sizebits_d);
	mk_lang_assert(c);

	big = ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(b)) / ((mk_lang_types_sint_t)(mk_sl_cui_inl_defd_base_sizebits_d))));
	smol = ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(b)) % ((mk_lang_types_sint_t)(mk_sl_cui_inl_defd_base_sizebits_d))));
	if(smol == 0)
	{
		n = mk_sl_cui_inl_defd_count - big;
		for(i = 0; i != n; ++i)
		{
			c->m_data[mk_sl_cui_inl_defd_idx(i)] = a->m_data[mk_sl_cui_inl_defd_idx(big + i)];
		}
		n = mk_sl_cui_inl_defd_count;
		for(; i != n; ++i)
		{
			mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(i)]);
		}
	}
	else
	{
		n = mk_sl_cui_inl_defd_count - big - 1;
		for(i = 0; i != n; ++i)
		{
			mk_sl_cui_inl_defd_base_shr3(&a->m_data[mk_sl_cui_inl_defd_idx(big + 0 + i)], smol, &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
			mk_sl_cui_inl_defd_base_shl3(&a->m_data[mk_sl_cui_inl_defd_idx(big + 1 + i)], mk_sl_cui_inl_defd_base_sizebits_d - smol, &t);
			mk_sl_cui_inl_defd_base_or2(&c->m_data[mk_sl_cui_inl_defd_idx(i)], &t);
		}
		mk_sl_cui_inl_defd_base_shr3(&a->m_data[mk_sl_cui_inl_defd_idx(big + i)], smol, &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
		n = mk_sl_cui_inl_defd_count;
		for(++i; i != n; ++i)
		{
			mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(i)]);
		}
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_rotl3(mk_sl_cui_inl_defd_pct const a, mk_lang_types_sint_t const b, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b < mk_sl_cui_inl_defd_sizebits_d);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_rotl3(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b, &c->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_sl_cui_inl_defd_t ta mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b < mk_sl_cui_inl_defd_sizebits_d);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_shl3(a, b, &ta);
	mk_sl_cui_inl_defd_shr3(a, mk_sl_cui_inl_defd_sizebits_d - b, &tb);
	mk_sl_cui_inl_defd_or3(&ta, &tb, c);
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_rotr3(mk_sl_cui_inl_defd_pct const a, mk_lang_types_sint_t const b, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b < mk_sl_cui_inl_defd_sizebits_d);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_rotr3(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b, &c->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_sl_cui_inl_defd_t ta mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b < mk_sl_cui_inl_defd_sizebits_d);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_shr3(a, b, &ta);
	mk_sl_cui_inl_defd_shl3(a, mk_sl_cui_inl_defd_sizebits_d - b, &tb);
	mk_sl_cui_inl_defd_or3(&ta, &tb, c);
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_shl2(mk_sl_cui_inl_defd_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_shl3(a, b, a);
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_shr2(mk_sl_cui_inl_defd_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_shr3(a, b, a);
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_rotl2(mk_sl_cui_inl_defd_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_rotl3(a, b, a);
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_rotr2(mk_sl_cui_inl_defd_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_rotr3(a, b, a);
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_cui_inl_defd_would_overflow_add_cc(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	return mk_sl_cui_inl_defd_base_would_overflow_add_cc(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t ta mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_inl_defd_base_set_max(&ta);
	n = mk_sl_cui_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_base_sub3_wrap_cid_cod(&ta, &a->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)], &tb);
		if(mk_sl_cui_inl_defd_base_lt(&tb, &b->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]))
		{
			return mk_lang_true;
		}
		else if(mk_sl_cui_inl_defd_base_gt(&tb, &b->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_false;
#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_cui_inl_defd_would_overflow_add_cs(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	return mk_sl_cui_inl_defd_base_would_overflow_add_cs(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t ta mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_inl_defd_base_set_max(&ta);
	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_sub3_wrap_cid_cod(&ta, &a->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)], &tb);
		if(mk_sl_cui_inl_defd_base_lt(&tb, &b->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]))
		{
			return mk_lang_true;
		}
		else if(mk_sl_cui_inl_defd_base_gt(&tb, &b->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_cui_inl_defd_would_overflow_add(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_lang_types_bool_t const cf) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	return cf ? mk_sl_cui_inl_defd_would_overflow_add_cs(a, b) : mk_sl_cui_inl_defd_would_overflow_add_cc(a, b);
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_cui_inl_defd_would_overflow_sub_cc(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	return mk_sl_cui_inl_defd_lt(a, b);
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_cui_inl_defd_would_overflow_sub_cs(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	return mk_sl_cui_inl_defd_le(a, b);
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_cui_inl_defd_would_overflow_sub(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_lang_types_bool_t const cf) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	return cf ? mk_sl_cui_inl_defd_would_overflow_sub_cs(a, b) : mk_sl_cui_inl_defd_would_overflow_sub_cc(a, b);
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_cui_inl_defd_would_overflow_mul(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_t c mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t d mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_inl_defd_mul4_wrap_wi(a, b, &c, &d);
	return !mk_sl_cui_inl_defd_is_zero(&d);
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_add2_wrap_cid_cod_smol(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_base_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b);
#else
	mk_lang_types_bool_t cf mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b, &cf);
	if(cf)
	{
		mk_sl_cui_inl_defd_base_inc1(&a->m_data[mk_sl_cui_inl_defd_idx(1)]);
		n = mk_sl_cui_inl_defd_count;
		for(i = 2; i != n && mk_sl_cui_inl_defd_base_is_zero(&a->m_data[mk_sl_cui_inl_defd_idx(i - 1)]); ++i)
		{
			mk_sl_cui_inl_defd_base_inc1(&a->m_data[mk_sl_cui_inl_defd_idx(i)]);
		}
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_add3_wrap_cid_cod(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_add3_wrap_cid_cod(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_bool_t cf mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_add3_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], &cf);
	n = mk_sl_cui_inl_defd_count;
	for(i = 1; i != n - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], &cf);
	}
	mk_sl_cui_inl_defd_base_add3_wrap_cie_cod(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_add3_wrap_cid_coe(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_sl_cui_inl_defd_pt const c, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_cui_inl_defd_base_add3_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], co);
#else
	mk_lang_types_bool_t cf mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_cui_inl_defd_base_add3_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], &cf);
	n = mk_sl_cui_inl_defd_count;
	for(i = 1; i != n - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], &cf);
	}
	mk_sl_cui_inl_defd_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], co);
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_add3_wrap_cie_cod(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_add3_wrap_cie_cod(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], ci, &c->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_bool_t cf mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], ci, &c->m_data[mk_sl_cui_inl_defd_idx(0)], &cf);
	n = mk_sl_cui_inl_defd_count;
	for(i = 1; i != n - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], &cf);
	}
	mk_sl_cui_inl_defd_base_add3_wrap_cie_cod(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_add3_wrap_cie_coe(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_sl_cui_inl_defd_pt const c, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_cui_inl_defd_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], ci, &c->m_data[mk_sl_cui_inl_defd_idx(0)], co);
#else
	mk_lang_types_bool_t cf mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_cui_inl_defd_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], ci, &c->m_data[mk_sl_cui_inl_defd_idx(0)], &cf);
	n = mk_sl_cui_inl_defd_count;
	for(i = 1; i != n - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], &cf);
	}
	mk_sl_cui_inl_defd_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], co);
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_add2_wrap_cid_cod(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_add3_wrap_cid_cod(a, b, a);
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_add2_wrap_cid_coe(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_pct const b, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_add3_wrap_cid_coe(a, b, a, co);
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_add2_wrap_cie_cod(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_pct const b, mk_lang_types_bool_t const ci) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_add3_wrap_cie_cod(a, b, ci, a);
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_add2_wrap_cie_coe(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_add3_wrap_cie_coe(a, b, ci, a, co);
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_sub3_wrap_cid_cod(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_sub3_wrap_cid_cod(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_bool_t cf mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_sub3_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], &cf);
	n = mk_sl_cui_inl_defd_count;
	for(i = 1; i != n - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], &cf);
	}
	mk_sl_cui_inl_defd_base_sub3_wrap_cie_cod(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_sub3_wrap_cid_coe(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_sl_cui_inl_defd_pt const c, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_cui_inl_defd_base_sub3_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], co);
#else
	mk_lang_types_bool_t cf mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_cui_inl_defd_base_sub3_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], &cf);
	n = mk_sl_cui_inl_defd_count;
	for(i = 1; i != n - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], &cf);
	}
	mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], co);
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_sub3_wrap_cie_cod(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_sub3_wrap_cie_cod(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], ci, &c->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_bool_t cf mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], ci, &c->m_data[mk_sl_cui_inl_defd_idx(0)], &cf);
	n = mk_sl_cui_inl_defd_count;
	for(i = 1; i != n - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], &cf);
	}
	mk_sl_cui_inl_defd_base_sub3_wrap_cie_cod(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_sub3_wrap_cie_coe(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_sl_cui_inl_defd_pt const c, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], ci, &c->m_data[mk_sl_cui_inl_defd_idx(0)], co);
#else
	mk_lang_types_bool_t cf mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], ci, &c->m_data[mk_sl_cui_inl_defd_idx(0)], &cf);
	n = mk_sl_cui_inl_defd_count;
	for(i = 1; i != n - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], &cf);
	}
	mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], co);
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_sub2_wrap_cid_cod(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_sub3_wrap_cid_cod(a, b, a);
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_sub2_wrap_cid_coe(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_pct const b, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_sub3_wrap_cid_coe(a, b, a, co);
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_sub2_wrap_cie_cod(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_pct const b, mk_lang_types_bool_t const ci) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_sub3_wrap_cie_cod(a, b, ci, a);
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_sub2_wrap_cie_coe(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_sub3_wrap_cie_coe(a, b, ci, a, co);
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_mul3_wrap_lo_smol(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_base_pct const b, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b, &c->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t tba mk_lang_constexpr_init;
	mk_lang_types_bool_t cf mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b, &c->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	n = mk_sl_cui_inl_defd_count;
	for(i = 1; i != n - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(i)], b, &tba, &c->m_data[mk_sl_cui_inl_defd_idx(i + 1)]);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(i)], &tba, &cf);
		if(cf){ mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(i + 1)]); }
	}
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(i)], b, &tba);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(i)], &tba);
#endif
}}

#if mk_sl_cui_inl_defd_count != 1

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_mul3_wrap_lo_restrict(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 2
	mk_sl_cui_inl_defd_base_t ta mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c != a && c != b);

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta);
#elif mk_sl_cui_inl_defd_count == 3
	mk_sl_cui_inl_defd_base_t ta mk_lang_constexpr_init;
	mk_lang_types_bool_t cf mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c != a && c != b);

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &tb, cf);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &ta);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &ta);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &ta);
#elif mk_sl_cui_inl_defd_count == 4
	mk_sl_cui_inl_defd_base_t ta mk_lang_constexpr_init;
	mk_lang_types_bool_t cf mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c != a && c != b);

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(3)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(3)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_defd_idx(3)], &tb, cf);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_defd_idx(3)], &tb, cf);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_defd_idx(3)], &tb, cf);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(3)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(3)], &ta);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(3)], &ta);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(3)], &ta);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(3)], &ta);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(3)], &ta);
#else
	mk_sl_cui_inl_defd_base_t ta mk_lang_constexpr_init;
	mk_lang_types_bool_t cf mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t tb mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_cui_inl_defd_count > 4);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c != a && c != b);

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(3)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(3)]);
	n = mk_sl_cui_inl_defd_count;
	for(j = 2; j != n - 2; ++j)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(j)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &tb);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j)], &ta, &cf);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j + 1)], &tb, cf, &cf);
		if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(j + 2)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(j + 2)]);
		for(i = 1; i != j + 1; ++i)
		{
			mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(j - i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &ta, &tb);
			mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j)], &ta, &cf);
			mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j + 1)], &tb, cf, &cf);
			if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(j + 2)]);
		}
	}
	for(i = 0; i != j + 1; ++i)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(j - i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &ta, &tb);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j)], &ta, &cf);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_defd_idx(j + 1)], &tb, cf);
	}
	++j;
	for(i = 0; i != j + 1; ++i)
	{
		mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(j - i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &ta);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(j)], &ta);
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_mul3_wrap_lo_alias(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_t cc mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_cui_inl_defd_count >= 2);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c == a || c == b);

	mk_sl_cui_inl_defd_mul3_wrap_lo_restrict(a, b, &cc);
	*c = cc;
}}

#endif

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_mul3_wrap_lo(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	if(c != a && c != b)
	{
		mk_sl_cui_inl_defd_mul3_wrap_lo_restrict(a, b, c);
	}
	else
	{
		mk_sl_cui_inl_defd_mul3_wrap_lo_alias(a, b, c);
	}
#endif
}}

#if mk_sl_cui_inl_defd_count != 1

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_mul3_wrap_hi_restrict(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 2
	mk_sl_cui_inl_defd_base_t ta mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t tb mk_lang_constexpr_init;
	mk_lang_types_bool_t cf mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t tc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c != a && c != b);

	mk_sl_cui_inl_defd_base_mul3_wrap_hi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &tb, &c->m_data[mk_sl_cui_inl_defd_idx(0)]);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&ta, &tb, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(0)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &tb, &tc);
	cf = mk_sl_cui_inl_defd_base_would_overflow_add_cc(&ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &tc, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(1)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &tb, cf);
#elif mk_sl_cui_inl_defd_count == 3
	#error xxxxxxxxxx todo
#elif mk_sl_cui_inl_defd_count == 4
	mk_sl_cui_inl_defd_base_t ta mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t tb mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t tc mk_lang_constexpr_init;
	mk_lang_types_bool_t cf mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t td mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c != a && c != b);

	mk_sl_cui_inl_defd_base_mul3_wrap_hi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &tb, &tc);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&ta, &tb, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&tc);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &tb, &td);
	cf = mk_sl_cui_inl_defd_base_would_overflow_add_cc(&ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&tc, &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&ta); else mk_sl_cui_inl_defd_base_set_zero(&ta);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &tb, &td);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&tc, &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&ta, &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(0)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(0)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &tb, &td);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&tc, &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&ta, &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(0)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &tb, &td);
	cf = mk_sl_cui_inl_defd_base_would_overflow_add_cc(&tc, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&ta, &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(0)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(3)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &tb, &tc);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&ta, &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &tc, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(1)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &tb, &tc);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&ta, &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &tc, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &tb, &tc);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&ta, &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &tc, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(3)], &tb, &tc);
	cf = mk_sl_cui_inl_defd_base_would_overflow_add_cc(&ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &tc, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(3)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(2)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(3)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(3)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(3)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(3)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(3)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(3)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(3)], &b->m_data[mk_sl_cui_inl_defd_idx(3)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_defd_idx(3)], &tb, cf);
#else
	mk_sl_cui_inl_defd_base_t ta mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t tb mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t tc mk_lang_constexpr_init;
	mk_lang_types_bool_t cf mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t td mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_pt t0 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_pt t1 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_pt t2 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t te mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_pt t3 mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_cui_inl_defd_count >= 4);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c != a && c != b);

	mk_sl_cui_inl_defd_base_mul3_wrap_hi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &tb, &tc);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&ta, &tb, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&tc);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &tb, &td);
	cf = mk_sl_cui_inl_defd_base_would_overflow_add_cc(&ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&tc, &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&ta); else mk_sl_cui_inl_defd_base_set_zero(&ta);
	t0 = &tc;
	t1 = &ta;
	t2 = &te;
	n = mk_sl_cui_inl_defd_count;
	for(j = 2; j != n - 2; ++j)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(j)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &tb, &td);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(t0, &tb, &cf);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(t1, &td, cf, &cf);
		if(cf) mk_sl_cui_inl_defd_base_set_one(t2); else mk_sl_cui_inl_defd_base_set_zero(t2);
		for(i = 1; i != j; ++i)
		{
			mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(j - i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &tb, &td);
			mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(t0, &tb, &cf);
			mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(t1, &td, cf, &cf);
			if(cf) mk_sl_cui_inl_defd_base_inc1(t2);
		}
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(j)], &tb, &td);
		cf = mk_sl_cui_inl_defd_base_would_overflow_add_cc(t0, &tb);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(t1, &td, cf, &cf);
		if(cf) mk_sl_cui_inl_defd_base_inc1(t2);
		t3 = t0;
		t0 = t1;
		t1 = t2;
		t2 = t3;
	}
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(n - 2)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &tb, &td);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(t0, &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(t1, &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(0)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(0)]);
	for(i = 1; i != n - 2; ++i)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(n - 2 - i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &tb, &td);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(t0, &tb, &cf);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(t1, &td, cf, &cf);
		if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(0)]);
	}
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(n - 2)], &tb, &td);
	cf = mk_sl_cui_inl_defd_base_would_overflow_add_cc(t0, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(t1, &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(0)]);
	t0 = t1;
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(n - 1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &tb, &td);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(t0, &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(1)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	for(i = 1; i != n - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(n - 1 - i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &tb, &td);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(t0, &tb, &cf);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &td, cf, &cf);
		if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	}
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(n - 1)], &tb, &td);
	cf = mk_sl_cui_inl_defd_base_would_overflow_add_cc(t0, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	for(j = 0; j != n - 3; ++j)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(n - 1)], &b->m_data[mk_sl_cui_inl_defd_idx(j + 1)], &tb, &td);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j)], &tb, &cf);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j + 1)], &td, cf, &cf);
		if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(j + 2)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(j + 2)]);
		for(i = 1; i != n - 2 - j; ++i)
		{
			mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(n - 1 - i)], &b->m_data[mk_sl_cui_inl_defd_idx(j + 1 + i)], &tb, &td);
			mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j)], &tb, &cf);
			mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j + 1)], &td, cf, &cf);
			if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(j + 2)]);
		}
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(j + 1)], &b->m_data[mk_sl_cui_inl_defd_idx(n - 1)], &tb, &td);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j)], &tb, &cf);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j + 1)], &td, cf, &cf);
		if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(j + 2)]);
	}
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(n - 1)], &b->m_data[mk_sl_cui_inl_defd_idx(n - 2)], &tb, &td);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(n - 3)], &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(n - 2)], &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(n - 1)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(n - 1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(n - 2)], &b->m_data[mk_sl_cui_inl_defd_idx(n - 1)], &tb, &td);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(n - 3)], &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(n - 2)], &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(n - 1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(n - 1)], &b->m_data[mk_sl_cui_inl_defd_idx(n - 1)], &tb, &td);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(n - 2)], &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_defd_idx(n - 1)], &td, cf);
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_mul3_wrap_hi_alias(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_t cc mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_cui_inl_defd_count >= 2);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c == a || c == b);

	mk_sl_cui_inl_defd_mul3_wrap_hi_restrict(a, b, &cc);
	*c = cc;
}}

#endif

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_mul3_wrap_hi(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_mul3_wrap_hi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	if(c != a && c != b)
	{
		mk_sl_cui_inl_defd_mul3_wrap_hi_restrict(a, b, c);
	}
	else
	{
		mk_sl_cui_inl_defd_mul3_wrap_hi_alias(a, b, c);
	}
#endif
}}

#if mk_sl_cui_inl_defd_count != 1

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_mul4_wrap_wi_restrict(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_sl_cui_inl_defd_pt const c, mk_sl_cui_inl_defd_pt const d) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 2
	#define out_idx(x) (out[(x) / mk_sl_cui_inl_defd_count]->m_data[mk_sl_cui_inl_defd_idx((x) % mk_sl_cui_inl_defd_count)])

	mk_sl_cui_inl_defd_pt out[2] mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t ta mk_lang_constexpr_init;
	mk_lang_types_bool_t cf mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(c != a && c != b && d != a && d != b);

	out[0] = c;
	out[1] = d;
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &out_idx(0), &out_idx(1));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &out_idx(2));
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(1), &ta, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(2));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(1), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(2), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(3)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(3));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(2), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(3), &tb, cf, &cf);
	mk_lang_assert(!cf);

	#undef out_idx
#elif mk_sl_cui_inl_defd_count == 3
	#define out_idx(x) (out[(x) / mk_sl_cui_inl_defd_count]->m_data[mk_sl_cui_inl_defd_idx((x) % mk_sl_cui_inl_defd_count)])

	mk_sl_cui_inl_defd_pt out[2] mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t ta mk_lang_constexpr_init;
	mk_lang_types_bool_t cf mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(c != a && c != b && d != a && d != b);

	out[0] = c;
	out[1] = d;
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &out_idx(0), &out_idx(1));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &out_idx(2));
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(1), &ta, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(2));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(1), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(2), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(3)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(3));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(2), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&out_idx(3), &tb, cf);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(2), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(3), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(4)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(4));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(2), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(3), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(4));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(3), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(4), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(5)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(5));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(3), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(4), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(5));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(4), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(5), &tb, cf, &cf);
	mk_lang_assert(!cf);

	#undef out_idx
#elif mk_sl_cui_inl_defd_count == 4
	#define out_idx(x) (out[(x) / mk_sl_cui_inl_defd_count]->m_data[mk_sl_cui_inl_defd_idx((x) % mk_sl_cui_inl_defd_count)])

	mk_sl_cui_inl_defd_pt out[2] mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t ta mk_lang_constexpr_init;
	mk_lang_types_bool_t cf mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(c != a && c != b && d != a && d != b);

	out[0] = c;
	out[1] = d;
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &out_idx(0), &out_idx(1));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &out_idx(2));
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(1), &ta, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(2));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(1), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(2), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(3)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(3));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(2), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&out_idx(3), &tb, cf);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(2), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(3), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(4)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(4));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(2), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(3), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(4));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(3)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(3), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(4), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(5)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(5));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(3), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(4), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(5));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(3), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(4), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(5));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(3)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(3), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(4), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(5));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(3)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(4), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(5), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(6)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(6));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(4), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(5), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(6));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(3)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(4), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(5), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(6));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(3)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(5), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(6), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(7)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(7));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(3)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(5), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(6), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(7));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(3)], &b->m_data[mk_sl_cui_inl_defd_idx(3)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(6), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(7), &tb, cf, &cf);
	mk_lang_assert(!cf);

	#undef out_idx
#else
	#define out_idx(x) (out[(x) / mk_sl_cui_inl_defd_count]->m_data[mk_sl_cui_inl_defd_idx((x) % mk_sl_cui_inl_defd_count)])

	mk_sl_cui_inl_defd_pt out[2] mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t ta mk_lang_constexpr_init;
	mk_lang_types_bool_t cf mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t tb mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_cui_inl_defd_count >= 4);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(c != a && c != b && d != a && d != b);

	out[0] = c;
	out[1] = d;
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &out_idx(0), &out_idx(1));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &out_idx(2));
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(1), &ta, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(2));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(1), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(2), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(3)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(3));
	n = mk_sl_cui_inl_defd_count;
	for(j = 2; j != n; ++j)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(j)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &tb);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(j), &ta, &cf);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(j + 1), &tb, cf, &cf);
		if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(j + 2)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(j + 2));
		for(i = 1; i != j + 1; ++i)
		{
			mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(j - i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &ta, &tb);
			mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(j), &ta, &cf);
			mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(j + 1), &tb, cf, &cf);
			if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(j + 2));
		}
	}
	for(j = 0; j != n - 2; ++j)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(n - 1)], &b->m_data[mk_sl_cui_inl_defd_idx(j + 1)], &ta, &tb);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(n + j), &ta, &cf);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(n + 1 + j), &tb, cf, &cf);
		if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(n + 2 + j)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(n + 2 + j));
		for(i = 1; i != n - 1 - j; ++i)
		{
			mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(n - 1 - i)], &b->m_data[mk_sl_cui_inl_defd_idx(j + 1 + i)], &ta, &tb);
			mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(n + j), &ta, &cf);
			mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(n + 1 + j), &tb, cf, &cf);
			if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(n + 2 + j));
		}
	}
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(n - 1)], &b->m_data[mk_sl_cui_inl_defd_idx(n - 1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(n + n - 2), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(n + n - 1), &tb, cf, &cf);
	mk_lang_assert(!cf);

	#undef out_idx
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_mul4_wrap_wi_alias(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_sl_cui_inl_defd_pt const c, mk_sl_cui_inl_defd_pt const d) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_t cc mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t dd mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_cui_inl_defd_count >= 2);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(c == a || c == b || d == a || d == b);

	mk_sl_cui_inl_defd_mul4_wrap_wi_restrict(a, b, &cc, &dd);
	*c = cc;
	*d = dd;
}}

#endif

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_mul4_wrap_wi(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_sl_cui_inl_defd_pt const c, mk_sl_cui_inl_defd_pt const d) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], &d->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);

	if(c != a && c != b && d != a && d != b)
	{
		mk_sl_cui_inl_defd_mul4_wrap_wi_restrict(a, b, c, d);
	}
	else
	{
		mk_sl_cui_inl_defd_mul4_wrap_wi_alias(a, b, c, d);
	}
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_mul4_wrap_wi_smol(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_base_pct const b, mk_sl_cui_inl_defd_pt const c, mk_sl_cui_inl_defd_base_pt const d) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b, &c->m_data[mk_sl_cui_inl_defd_idx(0)], d);
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t tba mk_lang_constexpr_init;
	mk_lang_types_bool_t cf mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b, &c->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	n = mk_sl_cui_inl_defd_count;
	for(i = 1; i != n - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(i)], b, &tba, &c->m_data[mk_sl_cui_inl_defd_idx(i + 1)]);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(i)], &tba, &cf);
		if(cf){ mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(i + 1)]); }
	}
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(i)], b, &tba, d);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(i)], &tba, &cf);
	if(cf){ mk_sl_cui_inl_defd_base_inc1(d); }
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_mul2_wrap_lo(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_mul3_wrap_lo(a, b, a);
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_mul2_wrap_hi(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_mul3_wrap_hi(a, b, a);
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_mul2_wrap_wi(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_mul4_wrap_wi(a, b, a, b);
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_div3_wrap(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_div3_wrap(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_sl_cui_inl_defd_t d mk_lang_constexpr_init;

	mk_sl_cui_inl_defd_divmod4_wrap(a, b, c, &d);
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_mod3_wrap(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_sl_cui_inl_defd_pt const c) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_mod3_wrap(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	mk_sl_cui_inl_defd_t d mk_lang_constexpr_init;

	mk_sl_cui_inl_defd_divmod4_wrap(a, b, &d, c);
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_divmod4_wrap(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_pct const b, mk_sl_cui_inl_defd_pt const c, mk_sl_cui_inl_defd_pt const d) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_base_divmod4_wrap(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], &d->m_data[mk_sl_cui_inl_defd_idx(0)]);
#else
	#if mk_sl_cui_inl_defd_sizebits_d <= mk_lang_sizeof_bi_ushort_t * mk_lang_charbit

	mk_lang_types_ushort_t aa mk_lang_constexpr_init;
	mk_lang_types_ushort_t bb mk_lang_constexpr_init;
	mk_lang_types_ushort_t cc mk_lang_constexpr_init;
	mk_lang_types_ushort_t dd mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_to_bi_ushort(a, &aa);
	mk_sl_cui_inl_defd_to_bi_ushort(b, &bb);
	cc = aa / bb;
	dd = aa % bb;
	mk_sl_cui_inl_defd_from_bi_ushort(c, &cc);
	mk_sl_cui_inl_defd_from_bi_ushort(d, &dd);

	#elif mk_sl_cui_inl_defd_sizebits_d <= mk_lang_sizeof_bi_uint_t * mk_lang_charbit

	mk_lang_types_uint_t aa mk_lang_constexpr_init;
	mk_lang_types_uint_t bb mk_lang_constexpr_init;
	mk_lang_types_uint_t cc mk_lang_constexpr_init;
	mk_lang_types_uint_t dd mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_to_bi_uint(a, &aa);
	mk_sl_cui_inl_defd_to_bi_uint(b, &bb);
	cc = aa / bb;
	dd = aa % bb;
	mk_sl_cui_inl_defd_from_bi_uint(c, &cc);
	mk_sl_cui_inl_defd_from_bi_uint(d, &dd);

	#elif mk_sl_cui_inl_defd_sizebits_d <= mk_lang_sizeof_bi_ulong_t * mk_lang_charbit

	mk_lang_types_ulong_t aa mk_lang_constexpr_init;
	mk_lang_types_ulong_t bb mk_lang_constexpr_init;
	mk_lang_types_ulong_t cc mk_lang_constexpr_init;
	mk_lang_types_ulong_t dd mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_to_bi_ulong(a, &aa);
	mk_sl_cui_inl_defd_to_bi_ulong(b, &bb);
	cc = aa / bb;
	dd = aa % bb;
	mk_sl_cui_inl_defd_from_bi_ulong(c, &cc);
	mk_sl_cui_inl_defd_from_bi_ulong(d, &dd);

	#elif !mk_sl_cui_inl_defd_disable_big_div && mk_sl_cui_inl_defd_sizebits_d <= mk_lang_sizeof_bi_ullong_t * mk_lang_charbit

	mk_lang_types_ullong_t aa mk_lang_constexpr_init;
	mk_lang_types_ullong_t bb mk_lang_constexpr_init;
	mk_lang_types_ullong_t cc mk_lang_constexpr_init;
	mk_lang_types_ullong_t dd mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_to_bi_ullong(a, &aa);
	mk_sl_cui_inl_defd_to_bi_ullong(b, &bb);
	cc = aa / bb;
	dd = aa % bb;
	mk_sl_cui_inl_defd_from_bi_ullong(c, &cc);
	mk_sl_cui_inl_defd_from_bi_ullong(d, &dd);

	#elif !mk_sl_cui_inl_defd_disable_big_div && mk_sl_cui_inl_defd_sizebits_d <= mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit

	mk_lang_types_ulllong_t aa mk_lang_constexpr_init;
	mk_lang_types_ulllong_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t cc mk_lang_constexpr_init;
	mk_lang_types_ulllong_t dd mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_to_bi_ulllong(a, &aa);
	mk_sl_cui_inl_defd_to_bi_ulllong(b, &bb);
	cc = aa / bb;
	dd = aa % bb;
	mk_sl_cui_inl_defd_from_bi_ulllong(c, &cc);
	mk_sl_cui_inl_defd_from_bi_ulllong(d, &dd);

	#else
		#if !mk_sl_cui_inl_defd_disable_big_div && mk_lang_sizeof_bi_ulllong_t >= 2 * mk_lang_sizeof_bi_ullong_t

	mk_lang_types_ullong_t aa[mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ullong_t * mk_lang_charbit)] mk_lang_constexpr_init;
	mk_lang_types_ullong_t bb[mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ullong_t * mk_lang_charbit)] mk_lang_constexpr_init;
	mk_lang_types_ullong_t cc[mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ullong_t * mk_lang_charbit)] mk_lang_constexpr_init;
	mk_lang_types_ullong_t dd[mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ullong_t * mk_lang_charbit)] mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_to_buis_ullong_le(a, &aa[0]);
	mk_sl_cui_inl_defd_to_buis_ullong_le(b, &bb[0]);
	mk_sl_cui_inl_defd_ldm_divmod4(&aa[0], &bb[0], &cc[0], &dd[0]);
	mk_sl_cui_inl_defd_from_buis_ullong_le(c, &cc[0]);
	mk_sl_cui_inl_defd_from_buis_ullong_le(d, &dd[0]);

		#elif !mk_sl_cui_inl_defd_disable_big_div && mk_lang_sizeof_bi_ullong_t >= 2 * mk_lang_sizeof_bi_ulong_t

	mk_lang_types_ulong_t aa[mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ulong_t * mk_lang_charbit)] mk_lang_constexpr_init;
	mk_lang_types_ulong_t bb[mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ulong_t * mk_lang_charbit)] mk_lang_constexpr_init;
	mk_lang_types_ulong_t cc[mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ulong_t * mk_lang_charbit)] mk_lang_constexpr_init;
	mk_lang_types_ulong_t dd[mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ulong_t * mk_lang_charbit)] mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_to_buis_ulong_le(a, &aa[0]);
	mk_sl_cui_inl_defd_to_buis_ulong_le(b, &bb[0]);
	mk_sl_cui_inl_defd_ldm_divmod4(&aa[0], &bb[0], &cc[0], &dd[0]);
	mk_sl_cui_inl_defd_from_buis_ulong_le(c, &cc[0]);
	mk_sl_cui_inl_defd_from_buis_ulong_le(d, &dd[0]);

		#elif mk_lang_sizeof_bi_uint_t >= 2 * mk_lang_sizeof_bi_ushort_t

	mk_lang_types_ushort_t aa[mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ushort_t * mk_lang_charbit)] mk_lang_constexpr_init;
	mk_lang_types_ushort_t bb[mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ushort_t * mk_lang_charbit)] mk_lang_constexpr_init;
	mk_lang_types_ushort_t cc[mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ushort_t * mk_lang_charbit)] mk_lang_constexpr_init;
	mk_lang_types_ushort_t dd[mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ushort_t * mk_lang_charbit)] mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_to_buis_ushort_le(a, &aa[0]);
	mk_sl_cui_inl_defd_to_buis_ushort_le(b, &bb[0]);
	mk_sl_cui_inl_defd_ldm_divmod4(&aa[0], &bb[0], &cc[0], &dd[0]);
	mk_sl_cui_inl_defd_from_buis_ushort_le(c, &cc[0]);
	mk_sl_cui_inl_defd_from_buis_ushort_le(d, &dd[0]);

		#else
	#error xxxxxxxxxx todo
		#endif
	#endif
#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_divmod4_wrap_smol(mk_sl_cui_inl_defd_pct const a, mk_sl_cui_inl_defd_base_pct const b, mk_sl_cui_inl_defd_pt const c, mk_sl_cui_inl_defd_base_pt const d) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
#if mk_sl_cui_inl_defd_count == 1

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_base_divmod4_wrap(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b, &c->m_data[mk_sl_cui_inl_defd_idx(0)], d);

#elif mk_sl_cui_inl_defd_sizebits_d <= mk_lang_sizeof_bi_ushort_t * mk_lang_charbit

	mk_lang_types_ushort_t aa mk_lang_constexpr_init;
	mk_lang_types_ushort_t bb mk_lang_constexpr_init;
	mk_lang_types_ushort_t cc mk_lang_constexpr_init;
	mk_lang_types_ushort_t dd mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_to_bi_ushort(a, &aa);
	mk_sl_cui_inl_defd_base_to_bi_ushort(b, &bb);
	cc = aa / bb;
	dd = aa % bb;
	mk_sl_cui_inl_defd_from_bi_ushort(c, &cc);
	mk_sl_cui_inl_defd_base_from_bi_ushort(d, &dd);

#elif mk_sl_cui_inl_defd_sizebits_d <= mk_lang_sizeof_bi_uint_t * mk_lang_charbit

	mk_lang_types_uint_t aa mk_lang_constexpr_init;
	mk_lang_types_uint_t bb mk_lang_constexpr_init;
	mk_lang_types_uint_t cc mk_lang_constexpr_init;
	mk_lang_types_uint_t dd mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_to_bi_uint(a, &aa);
	mk_sl_cui_inl_defd_base_to_bi_uint(b, &bb);
	cc = aa / bb;
	dd = aa % bb;
	mk_sl_cui_inl_defd_from_bi_uint(c, &cc);
	mk_sl_cui_inl_defd_base_from_bi_uint(d, &dd);

#elif mk_sl_cui_inl_defd_sizebits_d <= mk_lang_sizeof_bi_ulong_t * mk_lang_charbit

	mk_lang_types_ulong_t aa mk_lang_constexpr_init;
	mk_lang_types_ulong_t bb mk_lang_constexpr_init;
	mk_lang_types_ulong_t cc mk_lang_constexpr_init;
	mk_lang_types_ulong_t dd mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_to_bi_ulong(a, &aa);
	mk_sl_cui_inl_defd_base_to_bi_ulong(b, &bb);
	cc = aa / bb;
	dd = aa % bb;
	mk_sl_cui_inl_defd_from_bi_ulong(c, &cc);
	mk_sl_cui_inl_defd_base_from_bi_ulong(d, &dd);

#elif !mk_sl_cui_inl_defd_disable_big_div && mk_sl_cui_inl_defd_sizebits_d <= mk_lang_sizeof_bi_ullong_t * mk_lang_charbit

	mk_lang_types_ullong_t aa mk_lang_constexpr_init;
	mk_lang_types_ullong_t bb mk_lang_constexpr_init;
	mk_lang_types_ullong_t cc mk_lang_constexpr_init;
	mk_lang_types_ullong_t dd mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_to_bi_ullong(a, &aa);
	mk_sl_cui_inl_defd_base_to_bi_ullong(b, &bb);
	cc = aa / bb;
	dd = aa % bb;
	mk_sl_cui_inl_defd_from_bi_ullong(c, &cc);
	mk_sl_cui_inl_defd_base_from_bi_ullong(d, &dd);

#elif !mk_sl_cui_inl_defd_disable_big_div && mk_sl_cui_inl_defd_sizebits_d <= mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit

	mk_lang_types_ulllong_t aa mk_lang_constexpr_init;
	mk_lang_types_ulllong_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t cc mk_lang_constexpr_init;
	mk_lang_types_ulllong_t dd mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_to_bi_ulllong(a, &aa);
	mk_sl_cui_inl_defd_base_to_bi_ulllong(b, &bb);
	cc = aa / bb;
	dd = aa % bb;
	mk_sl_cui_inl_defd_from_bi_ulllong(c, &cc);
	mk_sl_cui_inl_defd_base_from_bi_ulllong(d, &dd);

#elif !mk_sl_cui_inl_defd_disable_big_div && mk_lang_sizeof_bi_ulllong_t >= 2 * mk_lang_sizeof_bi_ullong_t

	mk_lang_types_ullong_t aa[mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ullong_t * mk_lang_charbit)] mk_lang_constexpr_init;
	mk_lang_types_ullong_t bb[mk_lang_div_roundup(mk_sl_cui_inl_defd_base_sizebits_d, mk_lang_sizeof_bi_ullong_t * mk_lang_charbit)] mk_lang_constexpr_init;
	mk_lang_types_ullong_t cc[mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ullong_t * mk_lang_charbit)] mk_lang_constexpr_init;
	mk_lang_types_ullong_t dd[mk_lang_div_roundup(mk_sl_cui_inl_defd_base_sizebits_d, mk_lang_sizeof_bi_ullong_t * mk_lang_charbit)] mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_to_buis_ullong_le(a, &aa[0]);
	mk_sl_cui_inl_defd_base_to_buis_ullong_le(b, &bb[0]);
	mk_sl_cui_inl_defd_ldms_divmod4(&aa[0], &bb[0], &cc[0], &dd[0]);
	mk_sl_cui_inl_defd_from_buis_ullong_le(c, &cc[0]);
	mk_sl_cui_inl_defd_base_from_buis_ullong_le(d, &dd[0]);

#elif !mk_sl_cui_inl_defd_disable_big_div && mk_lang_sizeof_bi_ullong_t >= 2 * mk_lang_sizeof_bi_ulong_t

	mk_lang_types_ulong_t aa[mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ulong_t * mk_lang_charbit)] mk_lang_constexpr_init;
	mk_lang_types_ulong_t bb[mk_lang_div_roundup(mk_sl_cui_inl_defd_base_sizebits_d, mk_lang_sizeof_bi_ulong_t * mk_lang_charbit)] mk_lang_constexpr_init;
	mk_lang_types_ulong_t cc[mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ulong_t * mk_lang_charbit)] mk_lang_constexpr_init;
	mk_lang_types_ulong_t dd[mk_lang_div_roundup(mk_sl_cui_inl_defd_base_sizebits_d, mk_lang_sizeof_bi_ulong_t * mk_lang_charbit)] mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_to_buis_ulong_le(a, &aa[0]);
	mk_sl_cui_inl_defd_base_to_buis_ulong_le(b, &bb[0]);
	mk_sl_cui_inl_defd_ldms_divmod4(&aa[0], &bb[0], &cc[0], &dd[0]);
	mk_sl_cui_inl_defd_from_buis_ulong_le(c, &cc[0]);
	mk_sl_cui_inl_defd_base_from_buis_ulong_le(d, &dd[0]);

#elif mk_lang_sizeof_bi_uint_t >= 2 * mk_lang_sizeof_bi_ushort_t

	mk_lang_types_ushort_t aa[mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ushort_t * mk_lang_charbit)] mk_lang_constexpr_init;
	mk_lang_types_ushort_t bb[mk_lang_div_roundup(mk_sl_cui_inl_defd_base_sizebits_d, mk_lang_sizeof_bi_ushort_t * mk_lang_charbit)] mk_lang_constexpr_init;
	mk_lang_types_ushort_t cc[mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, mk_lang_sizeof_bi_ushort_t * mk_lang_charbit)] mk_lang_constexpr_init;
	mk_lang_types_ushort_t dd[mk_lang_div_roundup(mk_sl_cui_inl_defd_base_sizebits_d, mk_lang_sizeof_bi_ushort_t * mk_lang_charbit)] mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_inl_defd_to_buis_ushort_le(a, &aa[0]);
	mk_sl_cui_inl_defd_base_to_buis_ushort_le(b, &bb[0]);
	mk_sl_cui_inl_defd_ldms_divmod4(&aa[0], &bb[0], &cc[0], &dd[0]);
	mk_sl_cui_inl_defd_from_buis_ushort_le(c, &cc[0]);
	mk_sl_cui_inl_defd_base_from_buis_ushort_le(d, &dd[0]);

#else

#error xxxxxxxxxx todo

#endif
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_div2_wrap(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_div3_wrap(a, b, a);
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_mod2_wrap(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_pct const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_mod3_wrap(a, b, a);
}}

mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_inl_defd_divmod2_wrap(mk_sl_cui_inl_defd_pt const a, mk_sl_cui_inl_defd_pt const b) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_divmod4_wrap(a, b, a, b);
}}

#if !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_cui_inl_defd_symbols_dec_a[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
#endif

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_cui_inl_defd_to_str_dec_n(mk_sl_cui_inl_defd_pct const x, mk_lang_types_pchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t base mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_pt pa1 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t a1 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_pt pa2 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t a2 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_pt pa3 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t b mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	i = str_len;
	n = 10;
	mk_sl_cui_inl_defd_base_from_bi_sint(&base, &n);
	pa1 = &a1;
	pa2 = &a2;
	*pa2 = *x;
	for(;;)
	{
		pa3 = pa1;
		pa1 = pa2;
		pa2 = pa3;
		mk_sl_cui_inl_defd_divmod4_wrap_smol(pa1, &base, pa2, &b);
		mk_sl_cui_inl_defd_base_to_bi_sint(&b, &n);
		mk_lang_assert(n >= 0 && n < 10);
		--i;
		#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
		str[i] = ((mk_lang_types_pchar_t)('0' + n));
		#else
		str[i] = mk_sl_cui_inl_defd_symbols_dec_a[n];
		#endif
		if(mk_sl_cui_inl_defd_is_zero(pa2))
		{
			break;
		}
		if(i == 0)
		{
			return 0;
		}
	}
	if(i != 0)
	{
		mk_lang_assert(str_len - i >= 1);
		mk_sl_cui_inl_filec_memmove_pc_fn(str, str + i, ((mk_lang_types_uint_t)(str_len - i)));
	}
	mk_lang_assert(str_len - i >= 0);
	mk_lang_assert(str_len - i <= mk_sl_cui_inl_defd_strlendec_v);
	return str_len - i;
}}

#if !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_sl_cui_inl_defd_symbols_dec_b[] = {L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9'};
#endif

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_cui_inl_defd_to_str_dec_w(mk_sl_cui_inl_defd_pct const x, mk_lang_types_wchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t base mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_pt pa1 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t a1 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_pt pa2 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t a2 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_pt pa3 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t b mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	i = str_len;
	n = 10;
	mk_sl_cui_inl_defd_base_from_bi_sint(&base, &n);
	pa1 = &a1;
	pa2 = &a2;
	*pa2 = *x;
	for(;;)
	{
		pa3 = pa1;
		pa1 = pa2;
		pa2 = pa3;
		mk_sl_cui_inl_defd_divmod4_wrap_smol(pa1, &base, pa2, &b);
		mk_sl_cui_inl_defd_base_to_bi_sint(&b, &n);
		mk_lang_assert(n >= 0 && n < 10);
		--i;
		#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
		str[i] = ((mk_lang_types_wchar_t)(L'0' + n));
		#else
		str[i] = mk_sl_cui_inl_defd_symbols_dec_b[n];
		#endif
		if(mk_sl_cui_inl_defd_is_zero(pa2))
		{
			break;
		}
		if(i == 0)
		{
			return 0;
		}
	}
	if(i != 0)
	{
		mk_lang_assert(str_len - i >= 1);
		mk_sl_cui_inl_filec_memmove_wc_fn(str, str + i, ((mk_lang_types_uint_t)(str_len - i)));
	}
	mk_lang_assert(str_len - i >= 0);
	mk_lang_assert(str_len - i <= mk_sl_cui_inl_defd_strlendec_v);
	return str_len - i;
}}

#if !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_cui_inl_defd_symbols_dec_c[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
#endif

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_sl_cui_inl_defd_base_t mk_sl_cui_inl_defd_from_str_dec_border_base_impl(mk_lang_types_void_t) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t base mk_lang_constexpr_init;

	tsi = 10;
	mk_sl_cui_inl_defd_base_from_bi_sint(&base, &tsi);
	return base;
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_sl_cui_inl_defd_t mk_sl_cui_inl_defd_from_str_dec_border_value_impl(mk_lang_types_void_t) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t base mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t mx mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t border_value mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t border_digit mk_lang_constexpr_init;

	tsi = 10;
	mk_sl_cui_inl_defd_base_from_bi_sint(&base, &tsi);
	mk_sl_cui_inl_defd_set_max(&mx);
	mk_sl_cui_inl_defd_divmod4_wrap_smol(&mx, &base, &border_value, &border_digit);
	mk_sl_cui_inl_defd_base_to_bi_sint(&border_digit, &tsi);
	return border_value;
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_sint_t mk_sl_cui_inl_defd_from_str_dec_border_digit_impl(mk_lang_types_void_t) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t base mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t mx mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t border_value mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t border_digit mk_lang_constexpr_init;

	tsi = 10;
	mk_sl_cui_inl_defd_base_from_bi_sint(&base, &tsi);
	mk_sl_cui_inl_defd_set_max(&mx);
	mk_sl_cui_inl_defd_divmod4_wrap_smol(&mx, &base, &border_value, &border_digit);
	mk_sl_cui_inl_defd_base_to_bi_sint(&border_digit, &tsi);
	return tsi;
}}

#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
mk_lang_constexpr_static_inline mk_sl_cui_inl_defd_base_t const mk_sl_cui_inl_defd_from_str_dec_border_base_val = mk_sl_cui_inl_defd_from_str_dec_border_base_impl();
mk_lang_constexpr_static_inline mk_sl_cui_inl_defd_t const mk_sl_cui_inl_defd_from_str_dec_border_value_val = mk_sl_cui_inl_defd_from_str_dec_border_value_impl();
mk_lang_constexpr_static_inline mk_lang_types_sint_t const mk_sl_cui_inl_defd_from_str_dec_border_digit_val = mk_sl_cui_inl_defd_from_str_dec_border_digit_impl();
#endif

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_sl_cui_inl_defd_base_t mk_sl_cui_inl_defd_from_str_dec_border_base(mk_lang_types_void_t) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
	return mk_sl_cui_inl_defd_from_str_dec_border_base_val;
	#else
	return mk_sl_cui_inl_defd_from_str_dec_border_base_impl();
	#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_sl_cui_inl_defd_t mk_sl_cui_inl_defd_from_str_dec_border_value(mk_lang_types_void_t) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
	return mk_sl_cui_inl_defd_from_str_dec_border_value_val;
	#else
	return mk_sl_cui_inl_defd_from_str_dec_border_value_impl();
	#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_sint_t mk_sl_cui_inl_defd_from_str_dec_border_digit(mk_lang_types_void_t) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
	return mk_sl_cui_inl_defd_from_str_dec_border_digit_val;
	#else
	return mk_sl_cui_inl_defd_from_str_dec_border_digit_impl();
	#endif
}}

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_cui_inl_defd_from_str_dec_n(mk_sl_cui_inl_defd_pt const x, mk_lang_types_pchar_pct const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_base_t s_base mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t s_border_value mk_lang_constexpr_init;
	mk_lang_types_sint_t s_border_digit mk_lang_constexpr_init;

	mk_lang_types_pchar_pct it mk_lang_constexpr_init;
	mk_lang_types_pchar_pct ite mk_lang_constexpr_init;
	mk_lang_types_pchar_t e mk_lang_constexpr_init;
	#if(!(mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	#endif
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t overflow mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_pt px1 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t xx mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_pt px2 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t digit mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_pt px3 mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str);
	mk_lang_assert(str_len >= 0);

	if(str_len == 0)
	{
		return 0;
	}
	{
		s_base = mk_sl_cui_inl_defd_from_str_dec_border_base();
		s_border_value = mk_sl_cui_inl_defd_from_str_dec_border_value();
		s_border_digit = mk_sl_cui_inl_defd_from_str_dec_border_digit();
	}
	it = str;
	ite = str + str_len;
	e = *it;
	#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
	if(e >= '0' && e <= '9')
	{
		i = e - '0';
	}
	else
	{
		return 0;
	}
	#else
	n = mk_lang_countof(mk_sl_cui_inl_defd_symbols_dec_c);
	for(i = 0; i != n; ++i)
	{
		if(e == mk_sl_cui_inl_defd_symbols_dec_c[i])
		{
			break;
		}
	}
	if(i == n)
	{
		return 0;
	}
	#endif
	overflow = 1;
	px1 = &xx;
	px2 = x;
	mk_sl_cui_inl_defd_from_bi_sint(px1, &i);
	for(++it; it != ite; ++it)
	{
		e = *it;
		#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
		if(e >= '0' && e <= '9')
		{
			i = e - '0';
		}
		else
		{
			break;
		}
		#else
		n = mk_lang_countof(mk_sl_cui_inl_defd_symbols_dec_c);
		for(i = 0; i != n; ++i)
		{
			if(e == mk_sl_cui_inl_defd_symbols_dec_c[i])
			{
				break;
			}
		}
		if(i == n)
		{
			break;
		}
		#endif
		if(!(mk_sl_cui_inl_defd_lt(px1, &s_border_value) || (mk_sl_cui_inl_defd_eq(px1, &s_border_value) && i <= s_border_digit)))
		{
			overflow = -1;
			break;
		}
		mk_sl_cui_inl_defd_mul3_wrap_lo_smol(px1, &s_base, px2);
		mk_sl_cui_inl_defd_base_from_bi_sint(&digit, &i);
		mk_sl_cui_inl_defd_add2_wrap_cid_cod_smol(px2, &digit);
		px3 = px1;
		px1 = px2;
		px2 = px3;
	}
	if(px1 == &xx)
	{
		*x = xx;
	}
	return ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(it - str)) * overflow));
}}

#if !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_sl_cui_inl_defd_symbols_dec_d[] = {L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9'};
#endif

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_cui_inl_defd_from_str_dec_w(mk_sl_cui_inl_defd_pt const x, mk_lang_types_wchar_pct const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_base_t s_base mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t s_border_value mk_lang_constexpr_init;
	mk_lang_types_sint_t s_border_digit mk_lang_constexpr_init;

	mk_lang_types_wchar_pct it mk_lang_constexpr_init;
	mk_lang_types_wchar_pct ite mk_lang_constexpr_init;
	mk_lang_types_wchar_t e mk_lang_constexpr_init;
	#if(!(mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	#endif
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t overflow mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_pt px1 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t xx mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_pt px2 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_t digit mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_pt px3 mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str);
	mk_lang_assert(str_len >= 0);

	if(str_len == 0)
	{
		return 0;
	}
	{
		mk_lang_types_sint_t nn mk_lang_constexpr_init;
		mk_sl_cui_inl_defd_base_t base mk_lang_constexpr_init;
		mk_sl_cui_inl_defd_t mx mk_lang_constexpr_init;
		mk_sl_cui_inl_defd_t border_value mk_lang_constexpr_init;
		mk_sl_cui_inl_defd_base_t border_digit mk_lang_constexpr_init;

		nn = 10;
		mk_sl_cui_inl_defd_base_from_bi_sint(&base, &nn);
		mk_sl_cui_inl_defd_set_max(&mx);
		mk_sl_cui_inl_defd_divmod4_wrap_smol(&mx, &base, &border_value, &border_digit);
		mk_sl_cui_inl_defd_base_to_bi_sint(&border_digit, &nn);
		s_base = base;
		s_border_value = border_value;
		s_border_digit = nn;
	}

	it = str;
	ite = str + str_len;
	e = *it;
	#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
	if(e >= L'0' && e <= L'9')
	{
		i = e - L'0';
	}
	else
	{
		return 0;
	}
	#else
	n = mk_lang_countof(mk_sl_cui_inl_defd_symbols_dec_d);
	for(i = 0; i != n; ++i)
	{
		if(e == mk_sl_cui_inl_defd_symbols_dec_d[i])
		{
			break;
		}
	}
	if(i == n)
	{
		return 0;
	}
	#endif
	overflow = 1;
	px1 = &xx;
	px2 = x;
	mk_sl_cui_inl_defd_from_bi_sint(px1, &i);
	for(++it; it != ite; ++it)
	{
		e = *it;
		#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
		if(e >= L'0' && e <= L'9')
		{
			i = e - L'0';
		}
		else
		{
			break;
		}
		#else
		n = mk_lang_countof(mk_sl_cui_inl_defd_symbols_dec_d);
		for(i = 0; i != n; ++i)
		{
			if(e == mk_sl_cui_inl_defd_symbols_dec_d[i])
			{
				break;
			}
		}
		if(i == n)
		{
			break;
		}
		#endif
		if(!(mk_sl_cui_inl_defd_lt(px1, &s_border_value) || (mk_sl_cui_inl_defd_eq(px1, &s_border_value) && i <= s_border_digit)))
		{
			overflow = -1;
			break;
		}
		mk_sl_cui_inl_defd_mul3_wrap_lo_smol(px1, &s_base, px2);
		mk_sl_cui_inl_defd_base_from_bi_sint(&digit, &i);
		mk_sl_cui_inl_defd_add2_wrap_cid_cod_smol(px2, &digit);
		px3 = px1;
		px1 = px2;
		px2 = px3;
	}
	if(px1 == &xx)
	{
		*x = xx;
	}
	return ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(it - str)) * overflow));
}}

#if !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_cui_inl_defd_symbols_hex_a[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
#endif

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_cui_inl_defd_to_str_hex_n(mk_sl_cui_inl_defd_pct const x, mk_lang_types_pchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_lang_types_bool_t zero mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc_lo mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc_hi mk_lang_constexpr_init;
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit % 2 == 0);

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	xx = *x;
	ptr = &str[str_len - 1];
	rem = str_len;
	for(;;)
	{
		mk_sl_cui_inl_defd_to_bi_uchar(&xx, &tuc);
		mk_sl_cui_inl_defd_shr2(&xx, mk_lang_charbit / 2);
		mk_sl_cui_inl_defd_shr2(&xx, mk_lang_charbit / 2);
		zero = mk_sl_cui_inl_defd_is_zero(&xx);
		tuc_lo = ((mk_lang_types_uchar_t)((tuc >> 0) & 0xf));
		if(rem == 0){ return 0; } --rem; /* todo return negative? */
		#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
		ptr[0] = (tuc_lo >= 0 && tuc_lo <= 9) ? ((mk_lang_types_pchar_t)('0' + tuc_lo)) : ((mk_lang_types_pchar_t)('a' + (tuc_lo - 10))); --ptr;
		#else
		ptr[0] = mk_sl_cui_inl_defd_symbols_hex_a[tuc_lo]; --ptr;
		#endif
		tuc_hi = ((mk_lang_types_uchar_t)((tuc >> 4) & 0xf));
		if(tuc_hi == 0 && zero){ break; }
		if(rem == 0){ return 0; } --rem; /* todo return negative? */
		#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
		ptr[0] = (tuc_hi >= 0 && tuc_hi <= 9) ? ((mk_lang_types_pchar_t)('0' + tuc_hi)) : ((mk_lang_types_pchar_t)('a' + (tuc_hi - 10))); --ptr;
		#else
		ptr[0] = mk_sl_cui_inl_defd_symbols_hex_a[tuc_hi]; --ptr;
		#endif
		if(zero){ break; }
	}
	ret = str_len - rem;
	if(ret != str_len)
	{
		mk_sl_cui_inl_filec_memmove_pc_fn(&str[0], &str[str_len - ret], ((mk_lang_types_usize_t)(ret)));
	}
	return ret;
}}

#if !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_sl_cui_inl_defd_symbols_hex_b[] = {L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9', L'a', L'b', L'c', L'd', L'e', L'f'};
#endif

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_cui_inl_defd_to_str_hex_w(mk_sl_cui_inl_defd_pct const x, mk_lang_types_wchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_types_wchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_lang_types_bool_t zero mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc_lo mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc_hi mk_lang_constexpr_init;
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit % 2 == 0);

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	xx = *x;
	ptr = &str[str_len - 1];
	rem = str_len;
	for(;;)
	{
		mk_sl_cui_inl_defd_to_bi_uchar(&xx, &tuc);
		mk_sl_cui_inl_defd_shr2(&xx, mk_lang_charbit / 2);
		mk_sl_cui_inl_defd_shr2(&xx, mk_lang_charbit / 2);
		zero = mk_sl_cui_inl_defd_is_zero(&xx);
		tuc_lo = ((mk_lang_types_uchar_t)((tuc >> 0) & 0xf));
		if(rem == 0){ return 0; } --rem; /* todo return negative? */
		#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
		ptr[0] = (tuc_lo >= 0 && tuc_lo <= 9) ? ((mk_lang_types_wchar_t)(L'0' + tuc_lo)) : ((mk_lang_types_wchar_t)(L'a' + (tuc_lo - 10))); --ptr;
		#else
		ptr[0] = mk_sl_cui_inl_defd_symbols_hex_b[tuc_lo]; --ptr;
		#endif
		tuc_hi = ((mk_lang_types_uchar_t)((tuc >> 4) & 0xf));
		if(tuc_hi == 0 && zero){ break; }
		if(rem == 0){ return 0; } --rem; /* todo return negative? */
		#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
		ptr[0] = (tuc_hi >= 0 && tuc_hi <= 9) ? ((mk_lang_types_wchar_t)(L'0' + tuc_hi)) : ((mk_lang_types_wchar_t)(L'a' + (tuc_hi - 10))); --ptr;
		#else
		ptr[0] = mk_sl_cui_inl_defd_symbols_hex_b[tuc_hi]; --ptr;
		#endif
		if(zero){ break; }
	}
	ret = str_len - rem;
	if(ret != str_len)
	{
		mk_sl_cui_inl_filec_memmove_wc_fn(&str[0], &str[str_len - ret], ((mk_lang_types_usize_t)(ret)));
	}
	return ret;
}}

#if !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_cui_inl_defd_symbols_hex_c[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
#endif

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_cui_inl_defd_to_str_hexf_n(mk_sl_cui_inl_defd_pct const x, mk_lang_types_pchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc_lo mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc_hi mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_cui_inl_defd_strlenhex_v % 2 == 0);
	mk_lang_static_assert(mk_lang_charbit % 2 == 0);

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	if(!(str_len >= mk_sl_cui_inl_defd_strlenhex_v)){ return 0; } /* todo return negative? */
	xx = *x;
	ptr = &str[mk_sl_cui_inl_defd_strlenhex_v - 1];
	n = mk_sl_cui_inl_defd_strlenhex_v / 2;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_to_bi_uchar(&xx, &tuc);
		mk_sl_cui_inl_defd_shr2(&xx, mk_lang_charbit / 2);
		mk_sl_cui_inl_defd_shr2(&xx, mk_lang_charbit / 2);
		tuc_lo = ((mk_lang_types_uchar_t)((tuc >> 0) & 0xf));
		tuc_hi = ((mk_lang_types_uchar_t)((tuc >> 4) & 0xf));
		#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
		ptr[0] = (tuc_lo >= 0 && tuc_lo <= 9) ? ((mk_lang_types_pchar_t)('0' + tuc_lo)) : ((mk_lang_types_pchar_t)('a' + (tuc_lo - 10))); --ptr;
		ptr[0] = (tuc_hi >= 0 && tuc_hi <= 9) ? ((mk_lang_types_pchar_t)('0' + tuc_hi)) : ((mk_lang_types_pchar_t)('a' + (tuc_hi - 10))); if(i != n - 1){ --ptr; }
		#else
		ptr[0] = mk_sl_cui_inl_defd_symbols_hex_c[tuc_lo]; --ptr;
		ptr[0] = mk_sl_cui_inl_defd_symbols_hex_c[tuc_hi]; --ptr;
		#endif
	}
	return mk_sl_cui_inl_defd_strlenhex_v;
}}

#if !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_sl_cui_inl_defd_symbols_hex_d[] = {L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9', L'a', L'b', L'c', L'd', L'e', L'f'};
#endif

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_cui_inl_defd_to_str_hexf_w(mk_sl_cui_inl_defd_pct const x, mk_lang_types_wchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_types_wchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc_lo mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc_hi mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_cui_inl_defd_strlenhex_v % 2 == 0);
	mk_lang_static_assert(mk_lang_charbit % 2 == 0);

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	if(!(str_len >= mk_sl_cui_inl_defd_strlenhex_v)){ return 0; } /* todo return negative? */
	xx = *x;
	ptr = &str[mk_sl_cui_inl_defd_strlenhex_v - 1];
	n = mk_sl_cui_inl_defd_strlenhex_v / 2;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_inl_defd_to_bi_uchar(&xx, &tuc);
		mk_sl_cui_inl_defd_shr2(&xx, mk_lang_charbit / 2);
		mk_sl_cui_inl_defd_shr2(&xx, mk_lang_charbit / 2);
		tuc_lo = ((mk_lang_types_uchar_t)((tuc >> 0) & 0xf));
		tuc_hi = ((mk_lang_types_uchar_t)((tuc >> 4) & 0xf));
		#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
		ptr[0] = (tuc_lo >= 0 && tuc_lo <= 9) ? ((mk_lang_types_wchar_t)(L'0' + tuc_lo)) : ((mk_lang_types_wchar_t)(L'a' + (tuc_lo - 10))); --ptr;
		ptr[0] = (tuc_hi >= 0 && tuc_hi <= 9) ? ((mk_lang_types_wchar_t)(L'0' + tuc_hi)) : ((mk_lang_types_wchar_t)(L'a' + (tuc_hi - 10))); if(i != n - 1){ --ptr; }
		#else
		ptr[0] = mk_sl_cui_inl_defd_symbols_hex_d[tuc_lo]; --ptr;
		ptr[0] = mk_sl_cui_inl_defd_symbols_hex_d[tuc_hi]; --ptr;
		#endif
	}
	return mk_sl_cui_inl_defd_strlenhex_v;
}}

#if !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_cui_inl_defd_symbols_bin_a[] = {'0', '1'};
#endif

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_cui_inl_defd_to_str_bin_n(mk_sl_cui_inl_defd_pct const x, mk_lang_types_pchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_bool_t lsb mk_lang_constexpr_init;
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	xx = *x;
	ptr = &str[str_len - 1];
	rem = str_len;
	for(;;)
	{
		if(rem == 0){ return 0; } --rem; /* todo return negative? */
		lsb = mk_sl_cui_inl_defd_has_lsb(&xx);
		#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
		ptr[0] = ((mk_lang_types_pchar_t)('0' + (lsb ? 1 : 0))); --ptr;
		#else
		ptr[0] = mk_sl_cui_inl_defd_symbols_bin_a[lsb ? 1 : 0]; --ptr;
		#endif
		mk_sl_cui_inl_defd_shr2(&xx, 1);
		if(mk_sl_cui_inl_defd_is_zero(&xx))
		{
			break;
		}
	}
	ret = str_len - rem;
	if(ret != str_len)
	{
		mk_sl_cui_inl_filec_memmove_pc_fn(&str[0], &str[str_len - ret], ((mk_lang_types_usize_t)(ret)));
	}
	return ret;
}}

#if !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_cui_inl_defd_symbols_bin_b[] = {'0', '1'};
#endif

mk_lang_nodiscard mk_sl_cui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_cui_inl_defd_to_str_binf_n(mk_sl_cui_inl_defd_pct const x, mk_lang_types_pchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_sl_cui_inl_defd_flatten
{
	mk_sl_cui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_bool_t lsb mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	if(!(str_len >= mk_sl_cui_inl_defd_strlenbin_v)){ return 0; } /* todo return negative? */
	xx = *x;
	ptr = &str[mk_sl_cui_inl_defd_strlenbin_v - 1];
	n = mk_sl_cui_inl_defd_strlenbin_v;
	for(i = 0; i != n; ++i)
	{
		lsb = mk_sl_cui_inl_defd_has_lsb(&xx);
		#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
		ptr[0] = ((mk_lang_types_pchar_t)('0' + (lsb ? 1 : 0))); --ptr;
		#else
		ptr[0] = mk_sl_cui_inl_defd_symbols_bin_b[lsb ? 1 : 0]; --ptr;
		#endif
		mk_sl_cui_inl_defd_shr2(&xx, 1);
	}
	return mk_sl_cui_inl_defd_strlenbin_v;
}}

#undef mk_sl_cui_inl_defd_t1_sizebits_d
#undef mk_sl_cui_inl_defd_t2_sizebits_d

#undef mk_sl_cui_inl_filec_memmove_pc_name
#undef mk_sl_cui_inl_filec_memmove_pc_fn

#undef mk_sl_cui_inl_filec_memmove_wc_name
#undef mk_sl_cui_inl_filec_memmove_wc_fn

#undef mk_sl_cui_inl_defd_ldm_divmod4
#undef mk_sl_cui_inl_defd_ldms_divmod4


#include "mk_sl_cui_inl_defu.h"


#undef mk_sl_cui_t_name
#undef mk_sl_cui_t_base
#undef mk_sl_cui_t_count
#undef mk_sl_cui_t_endian
#undef mk_sl_cui_t_disable_big_div
#undef mk_sl_cui_t_base_sizebits_d
#undef mk_sl_cui_t_inline
