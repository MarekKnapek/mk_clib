#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#include "mk_sl_fixed_vector_inl_defd.h"


#define mk_sl_array_t_name mk_sl_fixed_vector_inl_defd_array_name
#define mk_sl_array_t_element mk_sl_fixed_vector_inl_defd_element
#define mk_sl_array_t_count mk_sl_fixed_vector_inl_defd_count
#include "mk_sl_array_inl_filec.h"

#define mk_sl_fixed_vector_inl_filec_memcpy_name mk_lang_concat(mk_sl_fixed_vector_inl_defd_name, _memcpy)
#define mk_lang_memcpy_t_name mk_sl_fixed_vector_inl_filec_memcpy_name
#define mk_lang_memcpy_t_type mk_sl_fixed_vector_inl_defd_element
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"
#define mk_sl_fixed_vector_inl_filec_memcpy_fn mk_lang_concat(mk_sl_fixed_vector_inl_filec_memcpy_name, _fn)


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_st_capacity(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_array_st_capacity();
	return ret;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_ro_capacity(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);

	((mk_lang_types_void_t)(fixed_vector));
	ret = mk_sl_fixed_vector_inl_defd_st_capacity();
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_ro_size(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);

	ret = fixed_vector->m_size;
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_ro_free(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);

	ret = mk_sl_fixed_vector_inl_defd_ro_capacity(fixed_vector) - mk_sl_fixed_vector_inl_defd_ro_size(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_ro_is_empty(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);

	ret = mk_sl_fixed_vector_inl_defd_ro_size(fixed_vector) == 0;
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_ro_is_full(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);

	ret = mk_sl_fixed_vector_inl_defd_ro_size(fixed_vector) == mk_sl_fixed_vector_inl_defd_ro_capacity(fixed_vector);;
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pct mk_sl_fixed_vector_inl_defd_ro_at(mk_sl_fixed_vector_inl_defd_pct const fixed_vector, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pct ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(!mk_sl_fixed_vector_inl_defd_ro_is_empty(fixed_vector));
	mk_lang_assert(idx >= 0 && idx < mk_sl_fixed_vector_inl_defd_ro_size(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_array_ro_at(&fixed_vector->m_array, idx);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pct mk_sl_fixed_vector_inl_defd_ro_data(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pct ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(!mk_sl_fixed_vector_inl_defd_ro_is_empty(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_ro_at(fixed_vector, 0);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pct mk_sl_fixed_vector_inl_defd_ro_front(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pct ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(!mk_sl_fixed_vector_inl_defd_ro_is_empty(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_ro_data(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pct mk_sl_fixed_vector_inl_defd_ro_back(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pct ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(!mk_sl_fixed_vector_inl_defd_ro_is_empty(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_ro_at(fixed_vector, mk_sl_fixed_vector_inl_defd_ro_size(fixed_vector) - 1);
	return ret;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_rw_capacity(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);

	ret = mk_sl_fixed_vector_inl_defd_ro_capacity(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_rw_size(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);

	ret = mk_sl_fixed_vector_inl_defd_ro_size(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_rw_free(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);

	ret = mk_sl_fixed_vector_inl_defd_ro_free(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_rw_is_empty(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);

	ret = mk_sl_fixed_vector_inl_defd_ro_is_empty(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_rw_is_full(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);

	ret = mk_sl_fixed_vector_inl_defd_ro_is_full(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_at(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pt ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(!mk_sl_fixed_vector_inl_defd_rw_is_empty(fixed_vector));
	mk_lang_assert(idx >= 0 && idx < mk_sl_fixed_vector_inl_defd_rw_size(fixed_vector));

	ret = ((mk_sl_fixed_vector_inl_defd_element_pt)(mk_sl_fixed_vector_inl_defd_ro_at(fixed_vector, idx)));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_data(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pt ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(!mk_sl_fixed_vector_inl_defd_rw_is_empty(fixed_vector));

	ret = ((mk_sl_fixed_vector_inl_defd_element_pt)(mk_sl_fixed_vector_inl_defd_ro_data(fixed_vector)));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_front(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pt ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(!mk_sl_fixed_vector_inl_defd_rw_is_empty(fixed_vector));

	ret = ((mk_sl_fixed_vector_inl_defd_element_pt)(mk_sl_fixed_vector_inl_defd_ro_front(fixed_vector)));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_back(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pt ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(!mk_sl_fixed_vector_inl_defd_rw_is_empty(fixed_vector));

	ret = ((mk_sl_fixed_vector_inl_defd_element_pt)(mk_sl_fixed_vector_inl_defd_ro_back(fixed_vector)));
	return ret;
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fixed_vector_inl_defd_rw_construct(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_assert(fixed_vector);

	fixed_vector->m_size = 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_void_t mk_sl_fixed_vector_inl_defd_rw_shrink(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_assert(fixed_vector);
	mk_lang_assert(count >= 0);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_rw_size(fixed_vector) >= count);

	fixed_vector->m_size -= count;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_void_t mk_sl_fixed_vector_inl_defd_rw_resize(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t size;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(count >= 0);

	size = mk_sl_fixed_vector_inl_defd_rw_size(fixed_vector);
	if(count > size)
	{
		mk_lang_assert(mk_sl_fixed_vector_inl_defd_rw_free(fixed_vector) >= count);
		fixed_vector->m_size += count;
	}
	else if(count < size)
	{
		mk_sl_fixed_vector_inl_defd_rw_shrink(fixed_vector, size - count);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_push_back_many(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_element_pct const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pt item mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(elements || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_rw_free(fixed_vector) >= count);

	item = mk_sl_fixed_vector_inl_defd_array_rw_at(&fixed_vector->m_array, fixed_vector->m_size);
	mk_sl_fixed_vector_inl_filec_memcpy_fn(&item[0], &elements[0], count);
	fixed_vector->m_size += count;
	return item;
}

mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_push_back_one(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_element_pct const element) mk_lang_noexcept
{
	return mk_sl_fixed_vector_inl_defd_rw_push_back_many(fixed_vector, element, 1);
}

mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_push_back_void(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pt item mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(count >= 0);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_rw_free(fixed_vector) >= count);

	item = mk_sl_fixed_vector_inl_defd_array_rw_at(&fixed_vector->m_array, fixed_vector->m_size);
	fixed_vector->m_size += count;
	return item;
}

mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_pop_back_one(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pt item mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(!mk_sl_fixed_vector_inl_defd_rw_is_empty(fixed_vector));

	item = mk_sl_fixed_vector_inl_defd_array_rw_at(&fixed_vector->m_array, --fixed_vector->m_size);
	return item;
}

mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_pop_back_many(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pt item mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(count >= 0);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_rw_size(fixed_vector) >= count);

	item = mk_sl_fixed_vector_inl_defd_array_rw_at(&fixed_vector->m_array, fixed_vector->m_size - count);
	fixed_vector->m_size -= count;
	return item;
}


#undef mk_sl_fixed_vector_inl_filec_memcpy_name
#undef mk_sl_fixed_vector_inl_filec_memcpy_fn


#include "mk_sl_fixed_vector_inl_defu.h"


#undef mk_sl_fixed_vector_t_name
#undef mk_sl_fixed_vector_t_element
#undef mk_sl_fixed_vector_t_count
