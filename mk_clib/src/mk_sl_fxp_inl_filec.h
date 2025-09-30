#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
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
#include "mk_lang_roundup.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_str_style.h"
#include "mk_lang_string.h"
#include "mk_lang_tchar.h"
#include "mk_lang_type_traits.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_sl_cui_uint1024.h"
#include "mk_sl_cui_uint128.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint256.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint512.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"


#include "mk_sl_fxp_inl_defd.h"


#define mk_sl_cui_t_name mk_sl_fxp_inl_defd_2cui
#define mk_sl_cui_t_base_type_name mk_sl_fxp_inl_defd_base_type_name
#define mk_sl_cui_t_count 2
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_fxp_inl_defd_base_type_size_bits_d
#define mk_sl_cui_t_inline mk_sl_fxp_inl_defd_inline
#define mk_sl_cui_t_alignas (2 * mk_sl_fxp_inl_defd_base_type_size_bits_d) / mk_lang_charbit
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_ldm_tn1s_to_tn2(mk_sl_fxp_inl_defd_base_pct const a, mk_sl_fxp_inl_defd_2cui_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_2cui_from_base(b, a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_ldm_tn1d_to_tn2(mk_sl_fxp_inl_defd_base_pct const hi, mk_sl_fxp_inl_defd_base_pct const lo, mk_sl_fxp_inl_defd_2cui_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_2cui_t hh mk_lang_constexpr_init;
	mk_sl_fxp_inl_defd_2cui_t ll mk_lang_constexpr_init;

	mk_lang_assert(hi);
	mk_lang_assert(lo);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_2cui_from_base(&hh, hi);
	mk_sl_fxp_inl_defd_2cui_from_base(&ll, lo);
	mk_sl_fxp_inl_defd_2cui_shl2(&hh, mk_sl_fxp_inl_defd_base_type_size_bits_d);
	mk_sl_fxp_inl_defd_2cui_or3(&hh, &ll, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_ldm_tn2_get_lo(mk_sl_fxp_inl_defd_2cui_pct const a, mk_sl_fxp_inl_defd_base_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_2cui_to_base(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_ldm_tn2_get_hi(mk_sl_fxp_inl_defd_2cui_pct const a, mk_sl_fxp_inl_defd_base_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_2cui_t aa mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_2cui_shr3(a, mk_sl_fxp_inl_defd_base_type_size_bits_d, &aa);
	mk_sl_fxp_inl_defd_2cui_to_base(&aa, b);
}}

#define mk_lang_num_longdivmod_t_name mk_sl_fxp_inl_defd_ldm_name
#define mk_lang_num_longdivmod_t_tn1 mk_sl_fxp_inl_defd_base
#define mk_lang_num_longdivmod_t_tn2 mk_sl_fxp_inl_defd_2cui
#define mk_lang_num_longdivmod_t_lena 2
#define mk_lang_num_longdivmod_t_lenb 1
#define mk_lang_num_longdivmod_t_endian mk_lang_endian_little
#define mk_lang_num_longdivmod_t_alg 2
#define mk_lang_num_longdivmod_t_tn1s_to_tn2 mk_sl_fxp_inl_defd_ldm_tn1s_to_tn2
#define mk_lang_num_longdivmod_t_tn1d_to_tn2 mk_sl_fxp_inl_defd_ldm_tn1d_to_tn2
#define mk_lang_num_longdivmod_t_tn2_get_lo mk_sl_fxp_inl_defd_ldm_tn2_get_lo
#define mk_lang_num_longdivmod_t_tn2_get_hi mk_sl_fxp_inl_defd_ldm_tn2_get_hi
#define mk_lang_num_longdivmod_t_tn1_size_bits_d mk_sl_fxp_inl_defd_base_type_size_bits_d
#define mk_lang_num_longdivmod_t_tn2_size_bits_d 2 * mk_sl_fxp_inl_defd_base_type_size_bits_d
#include "mk_lang_num_longdivmod_inl_fileh.h"
#include "mk_lang_num_longdivmod_inl_filec.h"
#include "mk_lang_num_longdivmod_inl_fileu.h"


mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_base(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_base_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_assign(&a->m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_adjust_after_import(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(x);

	mk_sl_fxp_inl_defd_base_shl2(&x->m_base, mk_sl_fxp_inl_defd_bits_after_v);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_bool(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_bool_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_bool(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_pchar(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_pchar_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_pchar(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_wchar(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_wchar_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_wchar(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_uchar(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_uchar_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_uchar(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_ushort(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_ushort_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_ushort(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_uint(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_uint_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_uint(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_ulong(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_ulong_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_ulong(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_ullong(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_ullong_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_ullong(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_ulllong(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_ulllong_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_ulllong(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_uintptr(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_uintptr_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_uintptr(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_uintmax(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_uintmax_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_uintmax(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_usize(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_usize_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_usize(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_schar(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_schar_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_schar(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_sshort(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_sshort_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_sshort(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_sint(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_sint_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_sint(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_slong(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_slong_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_slong(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_sllong(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_sllong_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_sllong(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_slllong(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_slllong_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_slllong(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_sintptr(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_sintptr_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_sintptr(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_sintmax(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_sintmax_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_sintmax(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_bi_ssize(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_ssize_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_from_bi_ssize(&a->m_base, b);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_uint8(mk_sl_fxp_inl_defd_pt const a, mk_sl_cui_uint8_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	union mk_sl_fxp_inl_defd_pr_from_uint8_convertor_data_u
	{
		mk_lang_types_uchar_t m_bytes[mk_lang_max(((mk_lang_types_sint_t)(mk_sl_cui_uint8_size_bytes_v)), ((mk_lang_types_sint_t)(mk_sl_fxp_inl_defd_base_size_bytes_v)))] mk_lang_constexpr_init;
		mk_sl_cui_uint8_t m_cui;
		mk_sl_fxp_inl_defd_base_t m_base;
	};
	typedef union mk_sl_fxp_inl_defd_pr_from_uint8_convertor_data_u mk_sl_fxp_inl_defd_pr_from_uint8_convertor_data_t;
	struct mk_sl_fxp_inl_defd_pr_from_uint8_convertor_s
	{
		mk_sl_fxp_inl_defd_pr_from_uint8_convertor_data_t m_data;
	};
	typedef struct mk_sl_fxp_inl_defd_pr_from_uint8_convertor_s mk_sl_fxp_inl_defd_pr_from_uint8_convertor_t;

	mk_sl_fxp_inl_defd_pr_from_uint8_convertor_t convertor mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(mk_sl_cui_uint8_size_bits_v - mk_sl_cui_uint8_count_leading_zeros(b) <= mk_sl_fxp_inl_defd_bits_before_v);

	mk_lang_string_memclr_uc_fn(&convertor.m_data.m_bytes[0], mk_lang_countof(convertor.m_data.m_bytes));
	mk_sl_cui_uint8_to_buis_uchar_le(b, &convertor.m_data.m_bytes[0]);
	mk_sl_fxp_inl_defd_base_from_buis_uchar_le(&a->m_base, &convertor.m_data.m_bytes[0]);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_uint16(mk_sl_fxp_inl_defd_pt const a, mk_sl_cui_uint16_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	union mk_sl_fxp_inl_defd_pr_from_uint16_convertor_data_u
	{
		mk_lang_types_uchar_t m_bytes[mk_lang_max(((mk_lang_types_sint_t)(mk_sl_cui_uint16_size_bytes_v)), ((mk_lang_types_sint_t)(mk_sl_fxp_inl_defd_base_size_bytes_v)))] mk_lang_constexpr_init;
		mk_sl_cui_uint16_t m_cui;
		mk_sl_fxp_inl_defd_base_t m_base;
	};
	typedef union mk_sl_fxp_inl_defd_pr_from_uint16_convertor_data_u mk_sl_fxp_inl_defd_pr_from_uint16_convertor_data_t;
	struct mk_sl_fxp_inl_defd_pr_from_uint16_convertor_s
	{
		mk_sl_fxp_inl_defd_pr_from_uint16_convertor_data_t m_data;
	};
	typedef struct mk_sl_fxp_inl_defd_pr_from_uint16_convertor_s mk_sl_fxp_inl_defd_pr_from_uint16_convertor_t;

	mk_sl_fxp_inl_defd_pr_from_uint16_convertor_t convertor mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(mk_sl_cui_uint16_size_bits_v - mk_sl_cui_uint16_count_leading_zeros(b) <= mk_sl_fxp_inl_defd_bits_before_v);

	mk_lang_string_memclr_uc_fn(&convertor.m_data.m_bytes[0], mk_lang_countof(convertor.m_data.m_bytes));
	mk_sl_cui_uint16_to_buis_uchar_le(b, &convertor.m_data.m_bytes[0]);
	mk_sl_fxp_inl_defd_base_from_buis_uchar_le(&a->m_base, &convertor.m_data.m_bytes[0]);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_uint32(mk_sl_fxp_inl_defd_pt const a, mk_sl_cui_uint32_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	union mk_sl_fxp_inl_defd_pr_from_uint32_convertor_data_u
	{
		mk_lang_types_uchar_t m_bytes[mk_lang_max(((mk_lang_types_sint_t)(mk_sl_cui_uint32_size_bytes_v)), ((mk_lang_types_sint_t)(mk_sl_fxp_inl_defd_base_size_bytes_v)))] mk_lang_constexpr_init;
		mk_sl_cui_uint32_t m_cui;
		mk_sl_fxp_inl_defd_base_t m_base;
	};
	typedef union mk_sl_fxp_inl_defd_pr_from_uint32_convertor_data_u mk_sl_fxp_inl_defd_pr_from_uint32_convertor_data_t;
	struct mk_sl_fxp_inl_defd_pr_from_uint32_convertor_s
	{
		mk_sl_fxp_inl_defd_pr_from_uint32_convertor_data_t m_data;
	};
	typedef struct mk_sl_fxp_inl_defd_pr_from_uint32_convertor_s mk_sl_fxp_inl_defd_pr_from_uint32_convertor_t;

	mk_sl_fxp_inl_defd_pr_from_uint32_convertor_t convertor mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(mk_sl_cui_uint32_size_bits_v - mk_sl_cui_uint32_count_leading_zeros(b) <= mk_sl_fxp_inl_defd_bits_before_v);

	mk_lang_string_memclr_uc_fn(&convertor.m_data.m_bytes[0], mk_lang_countof(convertor.m_data.m_bytes));
	mk_sl_cui_uint32_to_buis_uchar_le(b, &convertor.m_data.m_bytes[0]);
	mk_sl_fxp_inl_defd_base_from_buis_uchar_le(&a->m_base, &convertor.m_data.m_bytes[0]);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_uint64(mk_sl_fxp_inl_defd_pt const a, mk_sl_cui_uint64_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	union mk_sl_fxp_inl_defd_pr_from_uint64_convertor_data_u
	{
		mk_lang_types_uchar_t m_bytes[mk_lang_max(((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v)), ((mk_lang_types_sint_t)(mk_sl_fxp_inl_defd_base_size_bytes_v)))] mk_lang_constexpr_init;
		mk_sl_cui_uint64_t m_cui;
		mk_sl_fxp_inl_defd_base_t m_base;
	};
	typedef union mk_sl_fxp_inl_defd_pr_from_uint64_convertor_data_u mk_sl_fxp_inl_defd_pr_from_uint64_convertor_data_t;
	struct mk_sl_fxp_inl_defd_pr_from_uint64_convertor_s
	{
		mk_sl_fxp_inl_defd_pr_from_uint64_convertor_data_t m_data;
	};
	typedef struct mk_sl_fxp_inl_defd_pr_from_uint64_convertor_s mk_sl_fxp_inl_defd_pr_from_uint64_convertor_t;

	mk_sl_fxp_inl_defd_pr_from_uint64_convertor_t convertor mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(mk_sl_cui_uint64_size_bits_v - mk_sl_cui_uint64_count_leading_zeros(b) <= mk_sl_fxp_inl_defd_bits_before_v);

	mk_lang_string_memclr_uc_fn(&convertor.m_data.m_bytes[0], mk_lang_countof(convertor.m_data.m_bytes));
	mk_sl_cui_uint64_to_buis_uchar_le(b, &convertor.m_data.m_bytes[0]);
	mk_sl_fxp_inl_defd_base_from_buis_uchar_le(&a->m_base, &convertor.m_data.m_bytes[0]);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_uint128(mk_sl_fxp_inl_defd_pt const a, mk_sl_cui_uint128_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	union mk_sl_fxp_inl_defd_pr_from_uint128_convertor_data_u
	{
		mk_lang_types_uchar_t m_bytes[mk_lang_max(((mk_lang_types_sint_t)(mk_sl_cui_uint128_size_bytes_v)), ((mk_lang_types_sint_t)(mk_sl_fxp_inl_defd_base_size_bytes_v)))] mk_lang_constexpr_init;
		mk_sl_cui_uint128_t m_cui;
		mk_sl_fxp_inl_defd_base_t m_base;
	};
	typedef union mk_sl_fxp_inl_defd_pr_from_uint128_convertor_data_u mk_sl_fxp_inl_defd_pr_from_uint128_convertor_data_t;
	struct mk_sl_fxp_inl_defd_pr_from_uint128_convertor_s
	{
		mk_sl_fxp_inl_defd_pr_from_uint128_convertor_data_t m_data;
	};
	typedef struct mk_sl_fxp_inl_defd_pr_from_uint128_convertor_s mk_sl_fxp_inl_defd_pr_from_uint128_convertor_t;

	mk_sl_fxp_inl_defd_pr_from_uint128_convertor_t convertor mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(mk_sl_cui_uint128_size_bits_v - mk_sl_cui_uint128_count_leading_zeros(b) <= mk_sl_fxp_inl_defd_bits_before_v);

	mk_lang_string_memclr_uc_fn(&convertor.m_data.m_bytes[0], mk_lang_countof(convertor.m_data.m_bytes));
	mk_sl_cui_uint128_to_buis_uchar_le(b, &convertor.m_data.m_bytes[0]);
	mk_sl_fxp_inl_defd_base_from_buis_uchar_le(&a->m_base, &convertor.m_data.m_bytes[0]);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_uint256(mk_sl_fxp_inl_defd_pt const a, mk_sl_cui_uint256_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	union mk_sl_fxp_inl_defd_pr_from_uint256_convertor_data_u
	{
		mk_lang_types_uchar_t m_bytes[mk_lang_max(((mk_lang_types_sint_t)(mk_sl_cui_uint256_size_bytes_v)), ((mk_lang_types_sint_t)(mk_sl_fxp_inl_defd_base_size_bytes_v)))] mk_lang_constexpr_init;
		mk_sl_cui_uint256_t m_cui;
		mk_sl_fxp_inl_defd_base_t m_base;
	};
	typedef union mk_sl_fxp_inl_defd_pr_from_uint256_convertor_data_u mk_sl_fxp_inl_defd_pr_from_uint256_convertor_data_t;
	struct mk_sl_fxp_inl_defd_pr_from_uint256_convertor_s
	{
		mk_sl_fxp_inl_defd_pr_from_uint256_convertor_data_t m_data;
	};
	typedef struct mk_sl_fxp_inl_defd_pr_from_uint256_convertor_s mk_sl_fxp_inl_defd_pr_from_uint256_convertor_t;

	mk_sl_fxp_inl_defd_pr_from_uint256_convertor_t convertor mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(mk_sl_cui_uint256_size_bits_v - mk_sl_cui_uint256_count_leading_zeros(b) <= mk_sl_fxp_inl_defd_bits_before_v);

	mk_lang_string_memclr_uc_fn(&convertor.m_data.m_bytes[0], mk_lang_countof(convertor.m_data.m_bytes));
	mk_sl_cui_uint256_to_buis_uchar_le(b, &convertor.m_data.m_bytes[0]);
	mk_sl_fxp_inl_defd_base_from_buis_uchar_le(&a->m_base, &convertor.m_data.m_bytes[0]);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_uint512(mk_sl_fxp_inl_defd_pt const a, mk_sl_cui_uint512_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	union mk_sl_fxp_inl_defd_pr_from_uint512_convertor_data_u
	{
		mk_lang_types_uchar_t m_bytes[mk_lang_max(((mk_lang_types_sint_t)(mk_sl_cui_uint512_size_bytes_v)), ((mk_lang_types_sint_t)(mk_sl_fxp_inl_defd_base_size_bytes_v)))] mk_lang_constexpr_init;
		mk_sl_cui_uint512_t m_cui;
		mk_sl_fxp_inl_defd_base_t m_base;
	};
	typedef union mk_sl_fxp_inl_defd_pr_from_uint512_convertor_data_u mk_sl_fxp_inl_defd_pr_from_uint512_convertor_data_t;
	struct mk_sl_fxp_inl_defd_pr_from_uint512_convertor_s
	{
		mk_sl_fxp_inl_defd_pr_from_uint512_convertor_data_t m_data;
	};
	typedef struct mk_sl_fxp_inl_defd_pr_from_uint512_convertor_s mk_sl_fxp_inl_defd_pr_from_uint512_convertor_t;

	mk_sl_fxp_inl_defd_pr_from_uint512_convertor_t convertor mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(mk_sl_cui_uint512_size_bits_v - mk_sl_cui_uint512_count_leading_zeros(b) <= mk_sl_fxp_inl_defd_bits_before_v);

	mk_lang_string_memclr_uc_fn(&convertor.m_data.m_bytes[0], mk_lang_countof(convertor.m_data.m_bytes));
	mk_sl_cui_uint512_to_buis_uchar_le(b, &convertor.m_data.m_bytes[0]);
	mk_sl_fxp_inl_defd_base_from_buis_uchar_le(&a->m_base, &convertor.m_data.m_bytes[0]);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_from_uint1024(mk_sl_fxp_inl_defd_pt const a, mk_sl_cui_uint1024_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	union mk_sl_fxp_inl_defd_pr_from_uint1024_convertor_data_u
	{
		mk_lang_types_uchar_t m_bytes[mk_lang_max(((mk_lang_types_sint_t)(mk_sl_cui_uint1024_size_bytes_v)), ((mk_lang_types_sint_t)(mk_sl_fxp_inl_defd_base_size_bytes_v)))] mk_lang_constexpr_init;
		mk_sl_cui_uint1024_t m_cui;
		mk_sl_fxp_inl_defd_base_t m_base;
	};
	typedef union mk_sl_fxp_inl_defd_pr_from_uint1024_convertor_data_u mk_sl_fxp_inl_defd_pr_from_uint1024_convertor_data_t;
	struct mk_sl_fxp_inl_defd_pr_from_uint1024_convertor_s
	{
		mk_sl_fxp_inl_defd_pr_from_uint1024_convertor_data_t m_data;
	};
	typedef struct mk_sl_fxp_inl_defd_pr_from_uint1024_convertor_s mk_sl_fxp_inl_defd_pr_from_uint1024_convertor_t;

	mk_sl_fxp_inl_defd_pr_from_uint1024_convertor_t convertor mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(mk_sl_cui_uint1024_size_bits_v - mk_sl_cui_uint1024_count_leading_zeros(b) <= mk_sl_fxp_inl_defd_bits_before_v);

	mk_lang_string_memclr_uc_fn(&convertor.m_data.m_bytes[0], mk_lang_countof(convertor.m_data.m_bytes));
	mk_sl_cui_uint1024_to_buis_uchar_le(b, &convertor.m_data.m_bytes[0]);
	mk_sl_fxp_inl_defd_base_from_buis_uchar_le(&a->m_base, &convertor.m_data.m_bytes[0]);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_base(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_base_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_assign(b, &a->m_base);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_adjust_before_export(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_shr3(&a->m_base, mk_sl_fxp_inl_defd_bits_after_v, &b->m_base);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_bool(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_bool_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_bool(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_pchar(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_pchar_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_pchar(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_wchar(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_wchar_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_wchar(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_uchar(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_uchar_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_uchar(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_ushort(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_ushort_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_ushort(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_uint(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_uint_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_uint(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_ulong(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_ulong_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_ulong(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_ullong(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_ullong_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_ullong(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_ulllong(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_ulllong_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_to_bi_ulllong(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_uintptr(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_uintptr_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_uintptr(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_uintmax(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_uintmax_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_uintmax(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_usize(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_usize_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_usize(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_schar(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_schar_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_schar(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_sshort(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_sshort_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_sshort(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_sint(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_sint_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_sint(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_slong(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_slong_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_slong(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_sllong(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_sllong_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_sllong(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_slllong(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_slllong_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_slllong(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_sintptr(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_sintptr_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_sintptr(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_sintmax(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_sintmax_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_sintmax(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_to_bi_ssize(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_ssize_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_adjust_before_export(a, &tmp);
	mk_sl_fxp_inl_defd_base_from_bi_ssize(&tmp.m_base, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_set_zero(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(x);

	mk_sl_fxp_inl_defd_base_set_zero(&x->m_base);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(x);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_set_one(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(x);

	mk_sl_fxp_inl_defd_base_set_one(&x->m_base);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(x);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_set_two(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(x);

	mk_sl_fxp_inl_defd_base_set_two(&x->m_base);
	mk_sl_fxp_inl_defd_pr_adjust_after_import(x);
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_bool_t mk_sl_fxp_inl_defd_pr_is_zero(mk_sl_fxp_inl_defd_pct const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_base_t tmp mk_lang_constexpr_init;
	mk_lang_types_bool_t is mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_sl_fxp_inl_defd_base_set_zero(&tmp);
	is = mk_sl_fxp_inl_defd_base_eq(&x->m_base, &tmp);
	return is;
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_bool_t mk_sl_fxp_inl_defd_pr_is_one(mk_sl_fxp_inl_defd_pct const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_base_t tmp mk_lang_constexpr_init;
	mk_lang_types_bool_t is mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_sl_fxp_inl_defd_base_set_one(&tmp);
	is = mk_sl_fxp_inl_defd_base_eq(&x->m_base, &tmp);
	return is;
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_bool_t mk_sl_fxp_inl_defd_pr_is_two(mk_sl_fxp_inl_defd_pct const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_base_t tmp mk_lang_constexpr_init;
	mk_lang_types_bool_t is mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_sl_fxp_inl_defd_base_set_two(&tmp);
	is = mk_sl_fxp_inl_defd_base_eq(&x->m_base, &tmp);
	return is;
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_fxp_inl_defd_pr_eq(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_types_bool_t eq mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	eq = mk_sl_fxp_inl_defd_base_eq(&a->m_base, &b->m_base);
	return eq;
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_fxp_inl_defd_pr_ne(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_types_bool_t ne mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ne = mk_sl_fxp_inl_defd_base_ne(&a->m_base, &b->m_base);
	return ne;
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_fxp_inl_defd_pr_lt(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_types_bool_t lt mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	lt = mk_sl_fxp_inl_defd_base_lt(&a->m_base, &b->m_base);
	return lt;
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_fxp_inl_defd_pr_le(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_types_bool_t le mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	le = mk_sl_fxp_inl_defd_base_le(&a->m_base, &b->m_base);
	return le;
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_fxp_inl_defd_pr_gt(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_types_bool_t gt mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	gt = mk_sl_fxp_inl_defd_base_gt(&a->m_base, &b->m_base);
	return gt;
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_fxp_inl_defd_pr_ge(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_types_bool_t ge mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ge = mk_sl_fxp_inl_defd_base_ge(&a->m_base, &b->m_base);
	return ge;
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_fxp_inl_defd_pr_cmp(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_types_sint_t cmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	cmp = mk_sl_fxp_inl_defd_base_cmp(&a->m_base, &b->m_base);
	return cmp;
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_ulp_inc1(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(x);

	mk_sl_fxp_inl_defd_base_inc1(&x->m_base);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_ulp_dec1(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(x);

	mk_sl_fxp_inl_defd_base_dec1(&x->m_base);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_ulp_inc2(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_inc2(&a->m_base, &b->m_base);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_ulp_dec2(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_dec2(&a->m_base, &b->m_base);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_add3_wrap_cid_cod(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_fxp_inl_defd_base_add3_wrap_cid_cod(&a->m_base, &b->m_base, &c->m_base);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_add3_wrap_cid_coe(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_fxp_inl_defd_base_add3_wrap_cid_coe(&a->m_base, &b->m_base, &c->m_base, co);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_add3_wrap_cie_cod(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(ci == mk_lang_true || ci == mk_lang_false);
	mk_lang_assert(c);

	mk_sl_fxp_inl_defd_base_add3_wrap_cie_cod(&a->m_base, &b->m_base, ci, &c->m_base);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_add3_wrap_cie_coe(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_sl_fxp_inl_defd_pt const c, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(ci == mk_lang_true || ci == mk_lang_false);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_fxp_inl_defd_base_add3_wrap_cie_coe(&a->m_base, &b->m_base, ci, &c->m_base, co);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_add2_wrap_cid_cod(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_add2_wrap_cid_cod(&a->m_base, &b->m_base);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_add2_wrap_cid_coe(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(co);

	mk_sl_fxp_inl_defd_base_add2_wrap_cid_coe(&a->m_base, &b->m_base, co);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_add2_wrap_cie_cod(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_t const ci) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(ci == mk_lang_true || ci == mk_lang_false);

	mk_sl_fxp_inl_defd_base_add2_wrap_cie_cod(&a->m_base, &b->m_base, ci);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_add2_wrap_cie_coe(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(ci == mk_lang_true || ci == mk_lang_false);
	mk_lang_assert(co);

	mk_sl_fxp_inl_defd_base_add2_wrap_cie_coe(&a->m_base, &b->m_base, ci, co);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_sub3_wrap_cid_cod(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_fxp_inl_defd_base_sub3_wrap_cid_cod(&a->m_base, &b->m_base, &c->m_base);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_sub3_wrap_cid_coe(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_fxp_inl_defd_base_sub3_wrap_cid_coe(&a->m_base, &b->m_base, &c->m_base, co);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_sub3_wrap_cie_cod(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(ci == mk_lang_true || ci == mk_lang_false);
	mk_lang_assert(c);

	mk_sl_fxp_inl_defd_base_sub3_wrap_cie_cod(&a->m_base, &b->m_base, ci, &c->m_base);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_sub3_wrap_cie_coe(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_sl_fxp_inl_defd_pt const c, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(ci == mk_lang_true || ci == mk_lang_false);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_fxp_inl_defd_base_sub3_wrap_cie_coe(&a->m_base, &b->m_base, ci, &c->m_base, co);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_sub2_wrap_cid_cod(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_base_sub2_wrap_cid_cod(&a->m_base, &b->m_base);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_sub2_wrap_cid_coe(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(co);

	mk_sl_fxp_inl_defd_base_sub2_wrap_cid_coe(&a->m_base, &b->m_base, co);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_sub2_wrap_cie_cod(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_t const ci) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(ci == mk_lang_true || ci == mk_lang_false);

	mk_sl_fxp_inl_defd_base_sub2_wrap_cie_cod(&a->m_base, &b->m_base, ci);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_sub2_wrap_cie_coe(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(ci == mk_lang_true || ci == mk_lang_false);
	mk_lang_assert(co);

	mk_sl_fxp_inl_defd_base_sub2_wrap_cie_coe(&a->m_base, &b->m_base, ci, co);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_mul3_wrap_lo(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_base_t cc mk_lang_constexpr_init;
	mk_sl_fxp_inl_defd_base_t dd mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_fxp_inl_defd_base_mul4_wrap_wi(&a->m_base, &b->m_base, &cc, &dd);
	mk_sl_fxp_inl_defd_base_shr2(&cc, mk_sl_fxp_inl_defd_bits_after_v);
	mk_sl_fxp_inl_defd_base_shl2(&dd, mk_sl_fxp_inl_defd_bits_before_v);
	mk_sl_fxp_inl_defd_base_or3(&dd, &cc, &c->m_base);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_mul2_wrap_lo(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_mul3_wrap_lo(a, b, a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_div3_wrap(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept mk_sl_fxp_inl_defd_flatten {
{
	mk_sl_fxp_inl_defd_base_t aa[2] mk_lang_constexpr_init;
	mk_sl_fxp_inl_defd_base_t cc[2] mk_lang_constexpr_init;
	mk_sl_fxp_inl_defd_base_t dd mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_fxp_inl_defd_base_shl3(&a->m_base, mk_sl_fxp_inl_defd_bits_after_v, &aa[0]);
	mk_sl_fxp_inl_defd_base_shr3(&a->m_base, mk_sl_fxp_inl_defd_bits_before_v, &aa[1]);
	mk_sl_fxp_inl_defd_ldm_divmod4(&aa[0], &b->m_base, &cc[0], &dd);
	mk_sl_fxp_inl_defd_base_assign(&c->m_base, &cc[0]);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_div2_wrap(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept mk_sl_fxp_inl_defd_flatten {
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_div3_wrap(a, b, a);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_inc1(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_sl_fxp_inl_defd_pr_set_one(&tmp);
	mk_sl_fxp_inl_defd_pr_add2_wrap_cid_cod(x, &tmp);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_dec1(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_sl_fxp_inl_defd_pr_set_one(&tmp);
	mk_sl_fxp_inl_defd_pr_sub2_wrap_cid_cod(x, &tmp);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_inc2(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_set_one(&tmp);
	mk_sl_fxp_inl_defd_pr_add3_wrap_cid_cod(a, &tmp, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_sl_fxp_inl_defd_pr_dec2(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_t tmp mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_fxp_inl_defd_pr_set_one(&tmp);
	mk_sl_fxp_inl_defd_pr_sub3_wrap_cid_cod(a, &tmp, b);
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_sint_t mk_sl_fxp_inl_defd_pr_to_string_n(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept mk_sl_fxp_inl_defd_flatten {
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_sl_fxp_inl_defd_base_t tmp mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_fxp_inl_defd_base_t ten mk_lang_constexpr_init;
	mk_sl_fxp_inl_defd_base_t over mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	ptr = str_buf;
	rem = str_len;
	mk_sl_fxp_inl_defd_base_assign(&tmp, &x->m_base);
	mk_sl_fxp_inl_defd_base_shr2(&tmp, mk_sl_fxp_inl_defd_bits_after_v);
	len = mk_sl_fxp_inl_defd_base_to_str_dec_n(&tmp, ptr, rem);
	if(!(len >= 1))
	{
		return 0;
	}
	mk_lang_assert(len <= rem);
	ptr += len; rem -= len;
	if(!(rem >= 1))
	{
		return 0;
	}
	ptr[0] = '.';
	ptr += 1; rem -= 1;
	mk_sl_fxp_inl_defd_base_assign(&tmp, &x->m_base);
	mk_sl_fxp_inl_defd_base_shl2(&tmp, mk_sl_fxp_inl_defd_bits_before_v);
	tsi = 10; mk_sl_fxp_inl_defd_base_from_bi_sint(&ten, &tsi);
	if(!(rem >= 1))
	{
		return 0;
	}
	for(;;)
	{
		mk_sl_fxp_inl_defd_base_mul4_wrap_wi(&tmp, &ten, &tmp, &over);
		mk_sl_fxp_inl_defd_base_to_bi_sint(&over, &tsi);
		mk_lang_assert(tsi >= 0); mk_lang_assert(tsi <= 9);
		ptr[0] = ((mk_lang_types_pchar_t)('0' + tsi)); /* todo table */
		ptr += 1; rem -= 1;
		if(mk_sl_fxp_inl_defd_base_is_zero(&tmp))
		{
			break;
		}
		if(!(rem >= 1))
		{
			break;
		}
	}
	len = str_len - rem;
	return len;
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_sint_t mk_sl_fxp_inl_defd_pr_to_string_w(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_wchar_pt const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept mk_sl_fxp_inl_defd_flatten {
{
	mk_lang_types_wchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_sl_fxp_inl_defd_base_t tmp mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_fxp_inl_defd_base_t ten mk_lang_constexpr_init;
	mk_sl_fxp_inl_defd_base_t over mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	ptr = str_buf;
	rem = str_len;
	mk_sl_fxp_inl_defd_base_assign(&tmp, &x->m_base);
	mk_sl_fxp_inl_defd_base_shr2(&tmp, mk_sl_fxp_inl_defd_bits_after_v);
	len = mk_sl_fxp_inl_defd_base_to_str_dec_w(&tmp, ptr, rem);
	if(!(len >= 1))
	{
		return 0;
	}
	mk_lang_assert(len <= rem);
	ptr += len; rem -= len;
	if(!(rem >= 1))
	{
		return 0;
	}
	ptr[0] = L'.';
	ptr += 1; rem -= 1;
	mk_sl_fxp_inl_defd_base_assign(&tmp, &x->m_base);
	mk_sl_fxp_inl_defd_base_shl2(&tmp, mk_sl_fxp_inl_defd_bits_before_v);
	tsi = 10; mk_sl_fxp_inl_defd_base_from_bi_sint(&ten, &tsi);
	if(!(rem >= 1))
	{
		return 0;
	}
	for(;;)
	{
		mk_sl_fxp_inl_defd_base_mul4_wrap_wi(&tmp, &ten, &tmp, &over);
		mk_sl_fxp_inl_defd_base_to_bi_sint(&over, &tsi);
		mk_lang_assert(tsi >= 0); mk_lang_assert(tsi <= 9);
		ptr[0] = ((mk_lang_types_wchar_t)(L'0' + tsi)); /* todo table */
		ptr += 1; rem -= 1;
		if(mk_sl_fxp_inl_defd_base_is_zero(&tmp))
		{
			break;
		}
		if(!(rem >= 1))
		{
			break;
		}
	}
	len = str_len - rem;
	return len;
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_sint_t mk_sl_fxp_inl_defd_pr_to_string_t(mk_sl_fxp_inl_defd_pct const x, mk_lang_tchar_pt const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept mk_sl_fxp_inl_defd_flatten {
{
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	len = mk_lang_tchar_dispatch(mk_sl_fxp_inl_defd_pr_to_string_)(x, str_buf, str_len);
	return len;
}}





mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_base(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_base_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_base(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_bool(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_bool_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_bool(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_pchar(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_pchar_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_pchar(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_wchar(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_wchar_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_wchar(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_uchar(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_uchar_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_uchar(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_ushort(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_ushort_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_ushort(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_uint(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_uint_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_uint(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_ulong(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_ulong_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_ulong(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_ullong(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_ullong_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_ullong(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_ulllong(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_ulllong_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_ulllong(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_uintptr(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_uintptr_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_uintptr(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_uintmax(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_uintmax_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_uintmax(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_usize(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_usize_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_usize(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_schar(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_schar_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_schar(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_sshort(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_sshort_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_sshort(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_sint(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_sint_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_sint(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_slong(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_slong_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_slong(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_sllong(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_sllong_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_sllong(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_slllong(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_slllong_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_slllong(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_sintptr(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_sintptr_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_sintptr(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_sintmax(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_sintmax_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_sintmax(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_bi_ssize(mk_sl_fxp_inl_defd_pt const a, mk_lang_types_ssize_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_bi_ssize(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_uint8(mk_sl_fxp_inl_defd_pt const a, mk_sl_cui_uint8_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_uint8(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_uint16(mk_sl_fxp_inl_defd_pt const a, mk_sl_cui_uint16_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_uint16(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_uint32(mk_sl_fxp_inl_defd_pt const a, mk_sl_cui_uint32_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_uint32(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_uint64(mk_sl_fxp_inl_defd_pt const a, mk_sl_cui_uint64_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_uint64(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_uint128(mk_sl_fxp_inl_defd_pt const a, mk_sl_cui_uint128_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_uint128(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_uint256(mk_sl_fxp_inl_defd_pt const a, mk_sl_cui_uint256_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_uint256(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_uint512(mk_sl_fxp_inl_defd_pt const a, mk_sl_cui_uint512_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_uint512(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_from_uint1024(mk_sl_fxp_inl_defd_pt const a, mk_sl_cui_uint1024_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_from_uint1024(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_base(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_base_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_base(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_bool(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_bool_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_bool(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_pchar(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_pchar_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_pchar(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_wchar(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_wchar_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_wchar(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_uchar(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_uchar_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_uchar(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_ushort(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_ushort_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_ushort(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_uint(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_uint_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_uint(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_ulong(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_ulong_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_ulong(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_ullong(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_ullong_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_ullong(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_ulllong(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_ulllong_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_ulllong(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_uintptr(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_uintptr_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_uintptr(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_uintmax(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_uintmax_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_uintmax(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_usize(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_usize_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_usize(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_schar(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_schar_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_schar(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_sshort(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_sshort_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_sshort(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_sint(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_sint_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_sint(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_slong(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_slong_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_slong(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_sllong(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_sllong_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_sllong(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_slllong(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_slllong_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_slllong(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_sintptr(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_sintptr_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_sintptr(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_sintmax(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_sintmax_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_sintmax(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_to_bi_ssize(mk_sl_fxp_inl_defd_pct const a, mk_lang_types_ssize_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_to_bi_ssize(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_set_zero(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_set_zero(x);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_set_one(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_set_one(x);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_set_two(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_set_two(x);
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_fxp_inl_defd_is_zero(mk_sl_fxp_inl_defd_pct const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	return mk_sl_fxp_inl_defd_pr_is_zero(x);
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_fxp_inl_defd_is_one(mk_sl_fxp_inl_defd_pct const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	return mk_sl_fxp_inl_defd_pr_is_one(x);
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_fxp_inl_defd_is_two(mk_sl_fxp_inl_defd_pct const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	return mk_sl_fxp_inl_defd_pr_is_two(x);
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_fxp_inl_defd_eq(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	return mk_sl_fxp_inl_defd_pr_eq(a, b);
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_fxp_inl_defd_ne(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	return mk_sl_fxp_inl_defd_pr_ne(a, b);
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_fxp_inl_defd_lt(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	return mk_sl_fxp_inl_defd_pr_lt(a, b);
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_fxp_inl_defd_le(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	return mk_sl_fxp_inl_defd_pr_le(a, b);
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_fxp_inl_defd_gt(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	return mk_sl_fxp_inl_defd_pr_gt(a, b);
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_sl_fxp_inl_defd_ge(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	return mk_sl_fxp_inl_defd_pr_ge(a, b);
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_fxp_inl_defd_cmp(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	return mk_sl_fxp_inl_defd_pr_cmp(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_inc1(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_inc1(x);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_dec1(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_dec1(x);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_inc2(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_inc2(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_dec2(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_dec2(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_ulp_inc1(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_ulp_inc1(x);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_ulp_dec1(mk_sl_fxp_inl_defd_pt const x) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_ulp_dec1(x);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_ulp_inc2(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_ulp_inc2(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_ulp_dec2(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pt const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_ulp_dec2(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_add3_wrap_cid_cod(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_add3_wrap_cid_cod(a, b, c);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_add3_wrap_cid_coe(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_add3_wrap_cid_coe(a, b, c, co);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_add3_wrap_cie_cod(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_add3_wrap_cie_cod(a, b, ci, c);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_add3_wrap_cie_coe(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_sl_fxp_inl_defd_pt const c, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_add3_wrap_cie_coe(a, b, ci, c, co);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_add2_wrap_cid_cod(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_add2_wrap_cid_cod(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_add2_wrap_cid_coe(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_add2_wrap_cid_coe(a, b, co);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_add2_wrap_cie_cod(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_t const ci) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_add2_wrap_cie_cod(a, b, ci);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_add2_wrap_cie_coe(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_add2_wrap_cie_coe(a, b, ci, co);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_sub3_wrap_cid_cod(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_sub3_wrap_cid_cod(a, b, c);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_sub3_wrap_cid_coe(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_sub3_wrap_cid_coe(a, b, c, co);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_sub3_wrap_cie_cod(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_sub3_wrap_cie_cod(a, b, ci, c);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_sub3_wrap_cie_coe(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_sl_fxp_inl_defd_pt const c, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_sub3_wrap_cie_coe(a, b, ci, c, co);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_sub2_wrap_cid_cod(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_sub2_wrap_cid_cod(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_sub2_wrap_cid_coe(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_sub2_wrap_cid_coe(a, b, co);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_sub2_wrap_cie_cod(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_t const ci) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_sub2_wrap_cie_cod(a, b, ci);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_sub2_wrap_cie_coe(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_sub2_wrap_cie_coe(a, b, ci, co);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_mul3_wrap_lo(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_mul3_wrap_lo(a, b, c);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_mul2_wrap_lo(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept { mk_sl_fxp_inl_defd_flatten
{
	mk_sl_fxp_inl_defd_pr_mul2_wrap_lo(a, b);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_div3_wrap(mk_sl_fxp_inl_defd_pct const a, mk_sl_fxp_inl_defd_pct const b, mk_sl_fxp_inl_defd_pt const c) mk_lang_noexcept mk_sl_fxp_inl_defd_flatten {
{
	mk_sl_fxp_inl_defd_pr_div3_wrap(a, b, c);
}}

mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_sl_fxp_inl_defd_div2_wrap(mk_sl_fxp_inl_defd_pt const a, mk_sl_fxp_inl_defd_pct const b) mk_lang_noexcept mk_sl_fxp_inl_defd_flatten {
{
	mk_sl_fxp_inl_defd_pr_div2_wrap(a, b);
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_fxp_inl_defd_to_string_n(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept mk_sl_fxp_inl_defd_flatten {
{
	return mk_sl_fxp_inl_defd_pr_to_string_n(x, str_buf, str_len);
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_fxp_inl_defd_to_string_w(mk_sl_fxp_inl_defd_pct const x, mk_lang_types_wchar_pt const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept mk_sl_fxp_inl_defd_flatten {
{
	return mk_sl_fxp_inl_defd_pr_to_string_w(x, str_buf, str_len);
}}

mk_lang_nodiscard mk_sl_fxp_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_sl_fxp_inl_defd_to_string_t(mk_sl_fxp_inl_defd_pct const x, mk_lang_tchar_pt const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept mk_sl_fxp_inl_defd_flatten {
{
	return mk_sl_fxp_inl_defd_pr_to_string_t(x, str_buf, str_len);
}}


#include "mk_sl_fxp_inl_defu.h"
