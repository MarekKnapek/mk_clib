#ifndef mk_include_guard_mk_sl_dynamic_ring_c
#define mk_include_guard_mk_sl_dynamic_ring_c
#include "mk_sl_dynamic_ring.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_debug_break.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_dynamic_ring_copy.h"
#include "mk_sl_mallocator.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_u8_support_construct_void(mk_sl_cui_uint8_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_lang_debug_break();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_u8_support_destruct(mk_sl_cui_uint8_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	((mk_lang_types_void_t)(x));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_u8_support_construct_copy(mk_sl_cui_uint8_pt const dst, mk_sl_cui_uint8_pct const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_debug_break();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_u8_support_construct_move(mk_sl_cui_uint8_pt const dst, mk_sl_cui_uint8_pct const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_sl_cui_uint8_assign(dst, src);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_u8_support_assign_copy(mk_sl_cui_uint8_pt const dst, mk_sl_cui_uint8_pt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_debug_break();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_u8_support_assign_move(mk_sl_cui_uint8_pt const dst, mk_sl_cui_uint8_pt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_debug_break();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_dynamic_ring_u8_support_eq(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lang_debug_break();
	return 0==1;
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


#endif
