#ifndef mk_include_guard_mk_sl_dynamic_ring_c
#define mk_include_guard_mk_sl_dynamic_ring_c
#include "mk_sl_dynamic_ring.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_dynamic_ring_copy.h"
#include "mk_sl_mallocator.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_u8_support_construct_void(mk_sl_cui_uint8_pt const elements_ptr, mk_lang_types_usize_t const elements_cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(elements_ptr || elements_cnt == 0);
	mk_lang_assert(elements_cnt >= 0);
	mk_lang_assert(elements_cnt <= mk_lang_limits_usize_max / sizeof(*elements_ptr));
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(elements_ptr));
	((mk_lang_types_void_t)(elements_cnt));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_u8_support_destruct(mk_sl_cui_uint8_pt const elements_ptr, mk_lang_types_usize_t const elements_cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(elements_ptr || elements_cnt == 0);
	mk_lang_assert(elements_cnt >= 0);
	mk_lang_assert(elements_cnt <= mk_lang_limits_usize_max / sizeof(*elements_ptr));
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(elements_ptr));
	((mk_lang_types_void_t)(elements_cnt));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_u8_support_construct_copy(mk_sl_cui_uint8_pt const dst, mk_sl_cui_uint8_pct const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_cui_uint8_memcpy_fn(dst, src, cnt);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_u8_support_construct_move(mk_sl_cui_uint8_pt const dst, mk_sl_cui_uint8_pt const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_cui_uint8_memcpy_fn(dst, src, cnt);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_u8_support_assign_copy(mk_sl_cui_uint8_pt const dst, mk_sl_cui_uint8_pct const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_cui_uint8_memcpy_fn(dst, src, cnt);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_u8_support_assign_move(mk_sl_cui_uint8_pt const dst, mk_sl_cui_uint8_pt const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_cui_uint8_memcpy_fn(dst, src, cnt);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_dynamic_ring_u8_support_eq(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pct const b, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	mk_lang_types_sint_t eq mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(a || cnt == 0);
	mk_lang_assert(b || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*a));
	#include "mk_lang_warning_msvc_pop.h"

	eq = mk_sl_cui_uint8_memcmp_fn(a, b, cnt);
	return eq == 0;
}

#define mk_sl_dynamic_ring_t_name mk_sl_dynamic_ring_u8
#define mk_sl_dynamic_ring_t_element_type mk_sl_cui_uint8_t
#define mk_sl_dynamic_ring_t_mallocatorg mk_sl_mallocator
#define mk_sl_dynamic_ring_t_copy_style mk_sl_dynamic_ring_copy_use_custom
#define mk_sl_dynamic_ring_t_element_construct_void mk_sl_dynamic_ring_u8_support_construct_void
#define mk_sl_dynamic_ring_t_element_destruct mk_sl_dynamic_ring_u8_support_destruct
#define mk_sl_dynamic_ring_t_element_construct_copy mk_sl_dynamic_ring_u8_support_construct_copy
#define mk_sl_dynamic_ring_t_element_construct_move mk_sl_dynamic_ring_u8_support_construct_move
#define mk_sl_dynamic_ring_t_element_assign_copy mk_sl_dynamic_ring_u8_support_assign_copy
#define mk_sl_dynamic_ring_t_element_assign_move mk_sl_dynamic_ring_u8_support_assign_move
#define mk_sl_dynamic_ring_t_element_eq mk_sl_dynamic_ring_u8_support_eq
#include "mk_sl_dynamic_ring_inl_filec.h"
#include "mk_sl_dynamic_ring_inl_fileu.h"





mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_uc_support_construct_void(mk_lang_types_uchar_pt const elements_ptr, mk_lang_types_usize_t const elements_cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(elements_ptr || elements_cnt == 0);
	mk_lang_assert(elements_cnt >= 0);
	mk_lang_assert(elements_cnt <= mk_lang_limits_usize_max / sizeof(*elements_ptr));
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(elements_ptr));
	((mk_lang_types_void_t)(elements_cnt));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_uc_support_destruct(mk_lang_types_uchar_pt const elements_ptr, mk_lang_types_usize_t const elements_cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(elements_ptr || elements_cnt == 0);
	mk_lang_assert(elements_cnt >= 0);
	mk_lang_assert(elements_cnt <= mk_lang_limits_usize_max / sizeof(*elements_ptr));
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(elements_ptr));
	((mk_lang_types_void_t)(elements_cnt));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_uc_support_construct_copy(mk_lang_types_uchar_pt const dst, mk_lang_types_uchar_pct const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	mk_lang_string_memcpy_uc_fn(dst, src, cnt);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_uc_support_construct_move(mk_lang_types_uchar_pt const dst, mk_lang_types_uchar_pt const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	mk_lang_string_memcpy_uc_fn(dst, src, cnt);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_uc_support_assign_copy(mk_lang_types_uchar_pt const dst, mk_lang_types_uchar_pct const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	mk_lang_string_memcpy_uc_fn(dst, src, cnt);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_uc_support_assign_move(mk_lang_types_uchar_pt const dst, mk_lang_types_uchar_pt const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	mk_lang_string_memcpy_uc_fn(dst, src, cnt);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_dynamic_ring_uc_support_eq(mk_lang_types_uchar_pct const a, mk_lang_types_uchar_pct const b, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	mk_lang_types_sint_t eq mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(a || cnt == 0);
	mk_lang_assert(b || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*a));
	#include "mk_lang_warning_msvc_pop.h"

	eq = mk_lang_string_memcmp_uc_fn(a, b, cnt);
	return eq == 0;
}

#define mk_sl_dynamic_ring_t_name mk_sl_dynamic_ring_uc
#define mk_sl_dynamic_ring_t_element_type mk_lang_types_uchar_t
#define mk_sl_dynamic_ring_t_mallocatorg mk_sl_mallocator
#define mk_sl_dynamic_ring_t_copy_style mk_sl_dynamic_ring_copy_use_custom
#define mk_sl_dynamic_ring_t_element_construct_void mk_sl_dynamic_ring_uc_support_construct_void
#define mk_sl_dynamic_ring_t_element_destruct mk_sl_dynamic_ring_uc_support_destruct
#define mk_sl_dynamic_ring_t_element_construct_copy mk_sl_dynamic_ring_uc_support_construct_copy
#define mk_sl_dynamic_ring_t_element_construct_move mk_sl_dynamic_ring_uc_support_construct_move
#define mk_sl_dynamic_ring_t_element_assign_copy mk_sl_dynamic_ring_uc_support_assign_copy
#define mk_sl_dynamic_ring_t_element_assign_move mk_sl_dynamic_ring_uc_support_assign_move
#define mk_sl_dynamic_ring_t_element_eq mk_sl_dynamic_ring_uc_support_eq
#include "mk_sl_dynamic_ring_inl_filec.h"
#include "mk_sl_dynamic_ring_inl_fileu.h"





mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_pc_support_construct_void(mk_lang_types_pchar_pt const elements_ptr, mk_lang_types_usize_t const elements_cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(elements_ptr || elements_cnt == 0);
	mk_lang_assert(elements_cnt >= 0);
	mk_lang_assert(elements_cnt <= mk_lang_limits_usize_max / sizeof(*elements_ptr));
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(elements_ptr));
	((mk_lang_types_void_t)(elements_cnt));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_pc_support_destruct(mk_lang_types_pchar_pt const elements_ptr, mk_lang_types_usize_t const elements_cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(elements_ptr || elements_cnt == 0);
	mk_lang_assert(elements_cnt >= 0);
	mk_lang_assert(elements_cnt <= mk_lang_limits_usize_max / sizeof(*elements_ptr));
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(elements_ptr));
	((mk_lang_types_void_t)(elements_cnt));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_pc_support_construct_copy(mk_lang_types_pchar_pt const dst, mk_lang_types_pchar_pct const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	mk_lang_string_memcpy_pc_fn(dst, src, cnt);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_pc_support_construct_move(mk_lang_types_pchar_pt const dst, mk_lang_types_pchar_pt const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	mk_lang_string_memcpy_pc_fn(dst, src, cnt);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_pc_support_assign_copy(mk_lang_types_pchar_pt const dst, mk_lang_types_pchar_pct const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	mk_lang_string_memcpy_pc_fn(dst, src, cnt);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_pc_support_assign_move(mk_lang_types_pchar_pt const dst, mk_lang_types_pchar_pt const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	mk_lang_string_memcpy_pc_fn(dst, src, cnt);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_dynamic_ring_pc_support_eq(mk_lang_types_pchar_pct const a, mk_lang_types_pchar_pct const b, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	mk_lang_types_sint_t eq mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(a || cnt == 0);
	mk_lang_assert(b || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*a));
	#include "mk_lang_warning_msvc_pop.h"

	eq = mk_lang_string_memcmp_pc_fn(a, b, cnt);
	return eq == 0;
}

#define mk_sl_dynamic_ring_t_name mk_sl_dynamic_ring_pc
#define mk_sl_dynamic_ring_t_element_type mk_lang_types_pchar_t
#define mk_sl_dynamic_ring_t_mallocatorg mk_sl_mallocator
#define mk_sl_dynamic_ring_t_copy_style mk_sl_dynamic_ring_copy_use_custom
#define mk_sl_dynamic_ring_t_element_construct_void mk_sl_dynamic_ring_pc_support_construct_void
#define mk_sl_dynamic_ring_t_element_destruct mk_sl_dynamic_ring_pc_support_destruct
#define mk_sl_dynamic_ring_t_element_construct_copy mk_sl_dynamic_ring_pc_support_construct_copy
#define mk_sl_dynamic_ring_t_element_construct_move mk_sl_dynamic_ring_pc_support_construct_move
#define mk_sl_dynamic_ring_t_element_assign_copy mk_sl_dynamic_ring_pc_support_assign_copy
#define mk_sl_dynamic_ring_t_element_assign_move mk_sl_dynamic_ring_pc_support_assign_move
#define mk_sl_dynamic_ring_t_element_eq mk_sl_dynamic_ring_pc_support_eq
#include "mk_sl_dynamic_ring_inl_filec.h"
#include "mk_sl_dynamic_ring_inl_fileu.h"


#endif
