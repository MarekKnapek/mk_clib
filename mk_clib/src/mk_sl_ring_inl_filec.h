#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_pow2.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"


#include "mk_sl_ring_inl_defd.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_ring_inl_defd_ro_is_empty(mk_sl_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_assert(ring);

	return ring->m_read == ring->m_write;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_ring_inl_defd_ro_is_full(mk_sl_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_assert(ring);

	return ring->m_write == ring->m_read + mk_sl_ring_inl_defd_capacity;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_ring_inl_defd_ro_get_size(mk_sl_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_assert(ring);

	return ring->m_write - ring->m_read;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_ring_inl_defd_ro_get_capacity(mk_sl_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_assert(ring);

	return mk_sl_ring_inl_defd_capacity;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_ring_inl_defd_ro_get_free(mk_sl_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_assert(ring);

	return mk_sl_ring_inl_defd_ro_get_capacity(ring) - mk_sl_ring_inl_defd_ro_get_size(ring);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_ring_inl_defd_elem_pct mk_sl_ring_inl_defd_ro_get_elem(mk_sl_ring_inl_defd_pct const ring, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_lang_assert(ring);
	mk_lang_assert(idx < mk_sl_ring_inl_defd_ro_get_size(ring));

	return &ring->m_arr[(ring->m_read + idx) % mk_sl_ring_inl_defd_capacity];
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_ring_inl_defd_elem_pct mk_sl_ring_inl_defd_ro_get_head(mk_sl_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_ring_inl_defd_ro_get_elem(ring, 0);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_ring_inl_defd_elem_pct mk_sl_ring_inl_defd_ro_get_tail(mk_sl_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_ring_inl_defd_ro_get_elem(ring, mk_sl_ring_inl_defd_ro_get_size(ring) - 1);
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_ring_inl_defd_rw_is_empty(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_ring_inl_defd_ro_is_empty(ring);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_ring_inl_defd_rw_is_full(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_ring_inl_defd_ro_is_full(ring);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_ring_inl_defd_rw_get_size(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_ring_inl_defd_ro_get_size(ring);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_ring_inl_defd_rw_get_capacity(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_ring_inl_defd_ro_get_capacity(ring);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_ring_inl_defd_rw_get_free(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_ring_inl_defd_ro_get_free(ring);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_ring_inl_defd_elem_pt mk_sl_ring_inl_defd_rw_get_elem(mk_sl_ring_inl_defd_pt const ring, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	return ((mk_sl_ring_inl_defd_elem_pt)(mk_sl_ring_inl_defd_ro_get_elem(ring, idx)));
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_ring_inl_defd_elem_pt mk_sl_ring_inl_defd_rw_get_head(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return ((mk_sl_ring_inl_defd_elem_pt)(mk_sl_ring_inl_defd_ro_get_head(ring)));
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_ring_inl_defd_elem_pt mk_sl_ring_inl_defd_rw_get_tail(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return ((mk_sl_ring_inl_defd_elem_pt)(mk_sl_ring_inl_defd_ro_get_tail(ring)));
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_ring_inl_defd_rw_construct(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_pow2_is(mk_sl_ring_inl_defd_capacity));

	mk_lang_assert(ring);

	ring->m_read = 0;
	ring->m_write = 0;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_ring_inl_defd_rw_push_void(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_assert(ring);
	mk_lang_assert(!mk_sl_ring_inl_defd_rw_is_full(ring));

	++ring->m_write;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_ring_inl_defd_rw_push_elem(mk_sl_ring_inl_defd_pt const ring, mk_sl_ring_inl_defd_elem_pct const elem) mk_lang_noexcept
{
	mk_lang_assert(ring);
	mk_lang_assert(elem);
	mk_lang_assert(!mk_sl_ring_inl_defd_rw_is_full(ring));

	ring->m_arr[ring->m_write % mk_sl_ring_inl_defd_capacity] = *elem;
	++ring->m_write;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_ring_inl_defd_rw_pop(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_assert(ring);
	mk_lang_assert(!mk_sl_ring_inl_defd_rw_is_empty(ring));

	++ring->m_read;
}


#include "mk_sl_ring_inl_defu.h"


#undef mk_sl_ring_inl_defd_name
#undef mk_sl_ring_inl_defd_elem_t
#undef mk_sl_ring_inl_defd_capacity
