#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_exception.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"


#include "mk_sl_vector_inl_defd.h"


mk_lang_jumbo void mk_sl_vector_inl_defd_vector_ro_destroy(mk_sl_vector_inl_defd_vector_pct const vector) mk_lang_noexcept
{
	mk_lang_assert(vector);

	mk_sl_vector_inl_defd_buffer_ro_destroy(&vector->m_buffer);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_vector_inl_defd_vector_ro_is_empty(mk_sl_vector_inl_defd_vector_pct const vector) mk_lang_noexcept
{
	mk_lang_assert(vector);

	return vector->m_count == 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_size_t mk_sl_vector_inl_defd_vector_ro_get_count(mk_sl_vector_inl_defd_vector_pct const vector) mk_lang_noexcept
{
	mk_lang_assert(vector);

	return vector->m_count;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_size_t mk_sl_vector_inl_defd_vector_ro_get_capacity(mk_sl_vector_inl_defd_vector_pct const vector) mk_lang_noexcept
{
	mk_lang_assert(vector);

	return mk_sl_vector_inl_defd_buffer_ro_get_size(&vector->m_buffer) / sizeof(mk_sl_vector_inl_defd_elem_t);
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_elem_pct mk_sl_vector_inl_defd_vector_ro_get_data(mk_sl_vector_inl_defd_vector_pct const vector) mk_lang_noexcept
{
	mk_lang_assert(vector);

	return ((mk_sl_vector_inl_defd_elem_pct)(mk_sl_vector_inl_defd_buffer_ro_get_data(&vector->m_buffer)));
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_elem_pct mk_sl_vector_inl_defd_vector_ro_get_data_at(mk_sl_vector_inl_defd_vector_pct const vector, mk_lang_size_t const idx) mk_lang_noexcept
{
	mk_lang_assert(vector);
	mk_lang_assert(idx < vector->m_count);

	return ((mk_sl_vector_inl_defd_elem_pct)(mk_sl_vector_inl_defd_buffer_ro_get_data_at(&vector->m_buffer, idx * sizeof(mk_sl_vector_inl_defd_elem_t))));
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_elem_pct mk_sl_vector_inl_defd_vector_ro_get_data_back(mk_sl_vector_inl_defd_vector_pct const vector) mk_lang_noexcept
{
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_vector_ro_get_count(vector) != 0);

	return mk_sl_vector_inl_defd_vector_ro_get_data_at(vector, mk_sl_vector_inl_defd_vector_ro_get_count(vector) - 1);
}


mk_lang_jumbo void mk_sl_vector_inl_defd_vector_rw_construct(mk_sl_vector_inl_defd_vector_pt const vector) mk_lang_noexcept
{
	mk_lang_assert(vector);

	mk_sl_vector_inl_defd_buffer_rw_construct(&vector->m_buffer);
	vector->m_count = 0;
}

mk_lang_jumbo void mk_sl_vector_inl_defd_vector_rw_destroy(mk_sl_vector_inl_defd_vector_pt const vector) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_vector_ro_destroy(vector);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_vector_inl_defd_vector_rw_is_empty(mk_sl_vector_inl_defd_vector_pt const vector) mk_lang_noexcept
{
	return mk_sl_vector_inl_defd_vector_ro_is_empty(vector);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_size_t mk_sl_vector_inl_defd_vector_rw_get_count(mk_sl_vector_inl_defd_vector_pt const vector) mk_lang_noexcept
{
	return mk_sl_vector_inl_defd_vector_ro_get_count(vector);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_size_t mk_sl_vector_inl_defd_vector_rw_get_capacity(mk_sl_vector_inl_defd_vector_pt const vector) mk_lang_noexcept
{
	return mk_sl_vector_inl_defd_vector_ro_get_capacity(vector);
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_elem_pt mk_sl_vector_inl_defd_vector_rw_get_data(mk_sl_vector_inl_defd_vector_pt const vector) mk_lang_noexcept
{
	return ((mk_sl_vector_inl_defd_elem_pt)(mk_sl_vector_inl_defd_vector_ro_get_data(vector)));
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_elem_pt mk_sl_vector_inl_defd_vector_rw_get_data_at(mk_sl_vector_inl_defd_vector_pt const vector, mk_lang_size_t const idx) mk_lang_noexcept
{
	return ((mk_sl_vector_inl_defd_elem_pt)(mk_sl_vector_inl_defd_vector_ro_get_data_at(vector, idx)));
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_elem_pt mk_sl_vector_inl_defd_vector_rw_get_data_back(mk_sl_vector_inl_defd_vector_pt const vector) mk_lang_noexcept
{
	return ((mk_sl_vector_inl_defd_elem_pt)(mk_sl_vector_inl_defd_vector_ro_get_data_back(vector)));
}

mk_lang_jumbo void mk_sl_vector_inl_defd_vector_rw_reserve(mk_sl_vector_inl_defd_vector_pt const vector, mk_lang_exception_pt const ex, mk_lang_size_t const count) mk_lang_noexcept
{
	mk_lang_size_t size_requested;
	mk_lang_size_t size_curr;
	mk_lang_size_t size_new;

	mk_lang_assert(vector);
	mk_lang_assert(ex);

	if(count == 0)
	{
		return;
	}
	size_requested = count * sizeof(mk_sl_vector_inl_defd_elem_t);
	size_curr = mk_sl_vector_inl_defd_buffer_rw_get_size(&vector->m_buffer);
	if(size_curr >= size_requested)
	{
		return;
	}
	size_new = mk_lang_max(4 * sizeof(mk_sl_vector_inl_defd_elem_t), size_curr);
	do
	{
		size_new *= 2;
	}while(size_new < size_requested);
	mk_sl_vector_inl_defd_buffer_rw_resize(&vector->m_buffer, ex, size_new);
}

mk_lang_jumbo void mk_sl_vector_inl_defd_vector_rw_push_back(mk_sl_vector_inl_defd_vector_pt const vector, mk_lang_exception_pt const ex, mk_sl_vector_inl_defd_elem_pct const elem) mk_lang_noexcept
{
	mk_lang_assert(vector);
	mk_lang_assert(ex);
	mk_lang_assert(elem);

	mk_sl_vector_inl_defd_vector_rw_reserve(vector, ex, mk_sl_vector_inl_defd_vector_rw_get_count(vector) + 1);
	mk_sl_vector_inl_defd_vector_rw_get_data(vector)[mk_sl_vector_inl_defd_vector_rw_get_count(vector)] = *elem;
	mk_sl_vector_inl_defd_vector_rw_push_back_from_capacity_one(vector);
}

mk_lang_jumbo void mk_sl_vector_inl_defd_vector_rw_clear(mk_sl_vector_inl_defd_vector_pt const vector) mk_lang_noexcept
{
	mk_lang_assert(vector);

	vector->m_count = 0;
}

mk_lang_jumbo void mk_sl_vector_inl_defd_vector_rw_push_back_from_capacity_one(mk_sl_vector_inl_defd_vector_pt const vector) mk_lang_noexcept
{
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_vector_rw_get_capacity(vector) >= mk_sl_vector_inl_defd_vector_rw_get_count(vector) + 1);

	++vector->m_count;
}

mk_lang_jumbo void mk_sl_vector_inl_defd_vector_rw_push_back_from_capacity_n(mk_sl_vector_inl_defd_vector_pt const vector, mk_lang_size_t const count) mk_lang_noexcept
{
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_vector_rw_get_capacity(vector) >= mk_sl_vector_inl_defd_vector_rw_get_count(vector) + count);

	vector->m_count += count;
}

mk_lang_jumbo void mk_sl_vector_inl_defd_vector_rw_pop_back_one(mk_sl_vector_inl_defd_vector_pt const vector) mk_lang_noexcept
{
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_vector_rw_get_count(vector) != 0);

	--vector->m_count;
}

mk_lang_jumbo void mk_sl_vector_inl_defd_vector_rw_pop_back_n(mk_sl_vector_inl_defd_vector_pt const vector, mk_lang_size_t const count) mk_lang_noexcept
{
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_vector_rw_get_count(vector) >= count);

	vector->m_count -= count;
}


#include "mk_sl_vector_inl_defu.h"


#undef mk_sl_vector_t_name
#undef mk_sl_vector_t_elem_t
#undef mk_sl_vector_t_buffer_tn
