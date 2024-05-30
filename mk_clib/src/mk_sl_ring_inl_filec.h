#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#include "mk_sl_ring_inl_defd.h"


#define mk_sl_array_t_name mk_sl_ring_inl_defd_array_name
#define mk_sl_array_t_element mk_sl_ring_inl_defd_element
#define mk_sl_array_t_count mk_sl_ring_inl_defd_count
#include "mk_sl_array_inl_filec.h"

#define mk_sl_ring_inl_filec_memcpy_name mk_lang_concat(mk_sl_ring_inl_defd_name, _memcpy)
#define mk_lang_memcpy_t_name mk_sl_ring_inl_filec_memcpy_name
#define mk_lang_memcpy_t_type mk_sl_ring_inl_defd_element
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"
#define mk_sl_ring_inl_filec_memcpy_fn mk_lang_concat(mk_sl_ring_inl_filec_memcpy_name, _fn)


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_ring_inl_defd_st_capacity(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	ret = mk_sl_ring_inl_defd_array_st_capacity();
	return ret;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_ring_inl_defd_ro_capacity(mk_sl_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(ring);

	((mk_lang_types_void_t)(ring));
	ret = mk_sl_ring_inl_defd_st_capacity();
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_ring_inl_defd_ro_size(mk_sl_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(ring);

	ret = ring->m_write - ring->m_read;
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_ring_inl_defd_ro_free(mk_sl_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(ring);

	ret = mk_sl_ring_inl_defd_ro_capacity(ring) - mk_sl_ring_inl_defd_ro_size(ring);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_ring_inl_defd_ro_is_empty(mk_sl_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(ring);

	ret = mk_sl_ring_inl_defd_ro_size(ring) == 0;
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_ring_inl_defd_ro_is_full(mk_sl_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(ring);

	ret = mk_sl_ring_inl_defd_ro_free(ring) == 0;
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_ring_inl_defd_element_pct mk_sl_ring_inl_defd_ro_at(mk_sl_ring_inl_defd_pct const ring, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_lang_types_usize_t pos mk_lang_constexpr_init;
	mk_sl_ring_inl_defd_element_pct ret mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(!mk_sl_ring_inl_defd_ro_is_empty(ring));
	mk_lang_assert(idx >= 0 && idx < mk_sl_ring_inl_defd_ro_size(ring));

	pos = (ring->m_read + idx) & (mk_sl_ring_inl_defd_ro_capacity(ring) - 1);
	ret = mk_sl_ring_inl_defd_array_ro_at(&ring->m_array, pos);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_ring_inl_defd_element_pct mk_sl_ring_inl_defd_ro_data(mk_sl_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_sl_ring_inl_defd_element_pct ret mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(!mk_sl_ring_inl_defd_ro_is_empty(ring));

	ret = mk_sl_ring_inl_defd_ro_at(ring, 0);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_ring_inl_defd_element_pct mk_sl_ring_inl_defd_ro_front(mk_sl_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_sl_ring_inl_defd_element_pct ret mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(!mk_sl_ring_inl_defd_ro_is_empty(ring));

	ret = mk_sl_ring_inl_defd_ro_data(ring);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_ring_inl_defd_element_pct mk_sl_ring_inl_defd_ro_back(mk_sl_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_sl_ring_inl_defd_element_pct ret mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(!mk_sl_ring_inl_defd_ro_is_empty(ring));

	ret = mk_sl_ring_inl_defd_ro_at(ring, mk_sl_ring_inl_defd_ro_size(ring) - 1);
	return ret;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_ring_inl_defd_rw_capacity(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(ring);

	ret = mk_sl_ring_inl_defd_ro_capacity(ring);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_ring_inl_defd_rw_size(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(ring);

	ret = mk_sl_ring_inl_defd_ro_size(ring);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_ring_inl_defd_rw_free(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(ring);

	ret = mk_sl_ring_inl_defd_ro_free(ring);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_ring_inl_defd_rw_is_empty(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(ring);

	ret = mk_sl_ring_inl_defd_ro_is_empty(ring);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_ring_inl_defd_rw_is_full(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(ring);

	ret = mk_sl_ring_inl_defd_ro_is_full(ring);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_ring_inl_defd_element_pt mk_sl_ring_inl_defd_rw_at(mk_sl_ring_inl_defd_pt const ring, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_sl_ring_inl_defd_element_pt ret mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(!mk_sl_ring_inl_defd_rw_is_empty(ring));
	mk_lang_assert(idx >= 0 && idx < mk_sl_ring_inl_defd_rw_size(ring));

	ret = ((mk_sl_ring_inl_defd_element_pt)(mk_sl_ring_inl_defd_ro_at(ring, idx)));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_ring_inl_defd_element_pt mk_sl_ring_inl_defd_rw_data(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_sl_ring_inl_defd_element_pt ret mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(!mk_sl_ring_inl_defd_rw_is_empty(ring));

	ret = ((mk_sl_ring_inl_defd_element_pt)(mk_sl_ring_inl_defd_ro_data(ring)));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_ring_inl_defd_element_pt mk_sl_ring_inl_defd_rw_front(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_sl_ring_inl_defd_element_pt ret mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(!mk_sl_ring_inl_defd_rw_is_empty(ring));

	ret = ((mk_sl_ring_inl_defd_element_pt)(mk_sl_ring_inl_defd_ro_front(ring)));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_ring_inl_defd_element_pt mk_sl_ring_inl_defd_rw_back(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_sl_ring_inl_defd_element_pt ret mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(!mk_sl_ring_inl_defd_rw_is_empty(ring));

	ret = ((mk_sl_ring_inl_defd_element_pt)(mk_sl_ring_inl_defd_ro_back(ring)));
	return ret;
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_ring_inl_defd_rw_construct(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_assert(ring);

	ring->m_read = 0;
	ring->m_write = 0;
}

mk_lang_constexpr mk_lang_jumbo mk_sl_ring_inl_defd_element_pt mk_sl_ring_inl_defd_rw_push_back_one(mk_sl_ring_inl_defd_pt const ring, mk_sl_ring_inl_defd_element_pct const element) mk_lang_noexcept
{
	mk_lang_types_usize_t pos mk_lang_constexpr_init;
	mk_sl_ring_inl_defd_element_pt item mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(element);
	mk_lang_assert(!mk_sl_ring_inl_defd_rw_is_full(ring));

	pos = (ring->m_write++) & (mk_sl_ring_inl_defd_rw_capacity(ring) - 1);
	item = mk_sl_ring_inl_defd_array_rw_at(&ring->m_array, pos);
	*item = *element;
	return item;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_ring_inl_defd_rw_push_back_many(mk_sl_ring_inl_defd_pt const ring, mk_sl_ring_inl_defd_element_pct const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_sl_ring_inl_defd_element_pct elems mk_lang_constexpr_init;
	mk_lang_types_usize_t rest mk_lang_constexpr_init;
	mk_lang_types_usize_t pos mk_lang_constexpr_init;
	mk_lang_types_usize_t avl mk_lang_constexpr_init;
	mk_lang_types_usize_t cnt mk_lang_constexpr_init;
	mk_sl_ring_inl_defd_element_pt item mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(elements || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(mk_sl_ring_inl_defd_rw_free(ring) >= count);

	elems = elements;
	rest = count;
	pos = ring->m_write & (mk_sl_ring_inl_defd_rw_capacity(ring) - 1);
	avl = mk_sl_ring_inl_defd_rw_capacity(ring) - pos;
	cnt = mk_lang_min(rest, avl);
	item = mk_sl_ring_inl_defd_array_rw_at(&ring->m_array, pos);
	mk_sl_ring_inl_filec_memcpy_fn(item, elems, cnt);
	elems += cnt;
	rest -= cnt;
	item = mk_sl_ring_inl_defd_array_rw_front(&ring->m_array);
	mk_sl_ring_inl_filec_memcpy_fn(item, elems, rest);
	ring->m_write += count;
}

mk_lang_constexpr mk_lang_jumbo mk_sl_ring_inl_defd_element_pt mk_sl_ring_inl_defd_rw_pop_back(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t pos mk_lang_constexpr_init;
	mk_sl_ring_inl_defd_element_pt item mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(!mk_sl_ring_inl_defd_rw_is_empty(ring));

	pos = (ring->m_write--) & (mk_sl_ring_inl_defd_rw_capacity(ring) - 1);
	item = mk_sl_ring_inl_defd_array_rw_at(&ring->m_array, pos);
	return item;
}

mk_lang_constexpr mk_lang_jumbo mk_sl_ring_inl_defd_element_pt mk_sl_ring_inl_defd_rw_push_front(mk_sl_ring_inl_defd_pt const ring, mk_sl_ring_inl_defd_element_pct const element) mk_lang_noexcept
{
	mk_lang_types_usize_t pos mk_lang_constexpr_init;
	mk_sl_ring_inl_defd_element_pt item mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(element);
	mk_lang_assert(!mk_sl_ring_inl_defd_rw_is_full(ring));

	pos = (ring->m_read--) & (mk_sl_ring_inl_defd_rw_capacity(ring) - 1);
	item = mk_sl_ring_inl_defd_array_rw_at(&ring->m_array, pos);
	*item = *element;
	return item;
}

mk_lang_constexpr mk_lang_jumbo mk_sl_ring_inl_defd_element_pt mk_sl_ring_inl_defd_rw_pop_front_one(mk_sl_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t pos mk_lang_constexpr_init;
	mk_sl_ring_inl_defd_element_pt item mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(!mk_sl_ring_inl_defd_rw_is_empty(ring));

	pos = (ring->m_read++) & (mk_sl_ring_inl_defd_rw_capacity(ring) - 1);
	item = mk_sl_ring_inl_defd_array_rw_at(&ring->m_array, pos);
	return item;
}


#undef mk_sl_ring_inl_filec_memcpy_name
#undef mk_sl_ring_inl_filec_memcpy_fn


#include "mk_sl_ring_inl_defu.h"


#undef mk_sl_ring_t_name
#undef mk_sl_ring_t_element
#undef mk_sl_ring_t_count
