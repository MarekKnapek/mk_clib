#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_pow2.h"
#include "mk_lang_types.h"


#include "mk_sl_vector_inl_defd.h"


#define mk_sl_vector_inl_filec_memcpy_name mk_lang_concat(mk_sl_vector_inl_defd_name, _zzz_memcpy)
#define mk_lang_memcpy_t_name mk_sl_vector_inl_filec_memcpy_name
#define mk_lang_memcpy_t_type mk_sl_vector_inl_defd_element
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"
#define mk_sl_vector_inl_filec_memcpy_fn mk_lang_concat(mk_sl_vector_inl_filec_memcpy_name, _fn)


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_ro_capacity(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	mk_lang_assert(vector);

	ret = vector->m_capacity;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_ro_size(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	mk_lang_assert(vector);

	ret = vector->m_size;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_ro_free(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	mk_lang_assert(vector);

	ret = mk_sl_vector_inl_defd_ro_capacity(vector) - mk_sl_vector_inl_defd_ro_size(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_vector_inl_defd_ro_is_empty(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(vector);

	ret = mk_sl_vector_inl_defd_ro_size(vector) == 0;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_vector_inl_defd_ro_is_full(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(vector);

	ret = mk_sl_vector_inl_defd_ro_size(vector) == mk_sl_vector_inl_defd_ro_capacity(vector);;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pct mk_sl_vector_inl_defd_ro_at(mk_sl_vector_inl_defd_pct const vector, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pct ret;

	mk_lang_assert(vector);
	mk_lang_assert(!mk_sl_vector_inl_defd_ro_is_empty(vector));
	mk_lang_assert(idx >= 0 && idx < mk_sl_vector_inl_defd_ro_size(vector));

	ret = &vector->m_buffer[idx];
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pct mk_sl_vector_inl_defd_ro_data(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pct ret;

	mk_lang_assert(vector);
	mk_lang_assert(!mk_sl_vector_inl_defd_ro_is_empty(vector));

	ret = mk_sl_vector_inl_defd_ro_at(vector, 0);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pct mk_sl_vector_inl_defd_ro_front(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pct ret;

	mk_lang_assert(vector);
	mk_lang_assert(!mk_sl_vector_inl_defd_ro_is_empty(vector));

	ret = mk_sl_vector_inl_defd_ro_at(vector, 0);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pct mk_sl_vector_inl_defd_ro_back(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pct ret;

	mk_lang_assert(vector);
	mk_lang_assert(!mk_sl_vector_inl_defd_ro_is_empty(vector));

	ret = mk_sl_vector_inl_defd_ro_at(vector, mk_sl_vector_inl_defd_ro_size(vector) - 1);
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_rw_capacity(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	mk_lang_assert(vector);

	ret = mk_sl_vector_inl_defd_ro_capacity(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_rw_size(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	mk_lang_assert(vector);

	ret = mk_sl_vector_inl_defd_ro_size(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_rw_free(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	mk_lang_assert(vector);

	ret = mk_sl_vector_inl_defd_ro_free(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_vector_inl_defd_rw_is_empty(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(vector);

	ret = mk_sl_vector_inl_defd_ro_is_empty(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_vector_inl_defd_rw_is_full(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(vector);

	ret = mk_sl_vector_inl_defd_ro_is_full(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pt mk_sl_vector_inl_defd_rw_at(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pt ret;

	mk_lang_assert(vector);
	mk_lang_assert(!mk_sl_vector_inl_defd_rw_is_empty(vector));
	mk_lang_assert(idx >= 0 && idx < mk_sl_vector_inl_defd_rw_size(vector));

	ret = ((mk_sl_vector_inl_defd_element_pt)(mk_sl_vector_inl_defd_ro_at(vector, idx)));
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pt mk_sl_vector_inl_defd_rw_data(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pt ret;

	mk_lang_assert(vector);
	mk_lang_assert(!mk_sl_vector_inl_defd_rw_is_empty(vector));

	ret = ((mk_sl_vector_inl_defd_element_pt)(mk_sl_vector_inl_defd_ro_data(vector)));
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pt mk_sl_vector_inl_defd_rw_front(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pt ret;

	mk_lang_assert(vector);
	mk_lang_assert(!mk_sl_vector_inl_defd_rw_is_empty(vector));

	ret = ((mk_sl_vector_inl_defd_element_pt)(mk_sl_vector_inl_defd_ro_front(vector)));
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pt mk_sl_vector_inl_defd_rw_back(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pt ret;

	mk_lang_assert(vector);
	mk_lang_assert(!mk_sl_vector_inl_defd_rw_is_empty(vector));

	ret = ((mk_sl_vector_inl_defd_element_pt)(mk_sl_vector_inl_defd_ro_back(vector)));
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_construct(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_assert(vector);

	vector->m_buffer = mk_lang_null;
	vector->m_capacity = 0;
	vector->m_size = 0;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_destroy(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vector);

	if(vector->m_buffer && vector->m_capacity >= 1)
	{
		err = mk_sl_vecotr_inl_defd_mallocatorg_deallocate(vector->m_buffer, vector->m_capacity * sizeof(mk_sl_vector_inl_defd_element_t)); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_reserve_at_least(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t capacity;
	mk_lang_types_usize_t new_capacity;
	mk_lang_types_sint_t err;
	mk_sl_vector_inl_defd_element_pt new_buffer;

	mk_lang_assert(vector);
	mk_lang_assert(count >= 0);

	capacity = mk_sl_vector_inl_defd_rw_capacity(vector);
	if(capacity < count)
	{
		if(vector->m_buffer)
		{
			new_capacity = capacity * 2;
			new_capacity = mk_lang_max(new_capacity, count);
			new_capacity = mk_lang_pow2_roundup(new_capacity);
			err = mk_sl_vecotr_inl_defd_mallocatorg_reallocate(vector->m_buffer, capacity * sizeof(mk_sl_vector_inl_defd_element_t), new_capacity * sizeof(mk_sl_vector_inl_defd_element_t), ((mk_lang_types_void_ppt)(&new_buffer))); mk_lang_check_rereturn(err);
		}
		else
		{
			new_capacity = 4;
			new_capacity = mk_lang_max(new_capacity, count);
			new_capacity = mk_lang_pow2_roundup(new_capacity);
			err = mk_sl_vecotr_inl_defd_mallocatorg_allocate(new_capacity * sizeof(mk_sl_vector_inl_defd_element_t), ((mk_lang_types_void_ppt)(&new_buffer))); mk_lang_check_rereturn(err);
		}
		vector->m_buffer = new_buffer;
		vector->m_capacity = new_capacity;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_shrink(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_assert(vector);
	mk_lang_assert(count >= 0);
	mk_lang_assert(mk_sl_vector_inl_defd_rw_size(vector) >= count);

	vector->m_size -= count;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_resize(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t size;
	mk_lang_types_sint_t err;

	mk_lang_assert(vector);
	mk_lang_assert(count >= 0);

	size = mk_sl_vector_inl_defd_rw_size(vector);
	if(count > size)
	{
		err = mk_sl_vector_inl_defd_rw_reserve_at_least(vector, count); mk_lang_check_rereturn(err);
	}
	else if(count < size)
	{
		err = mk_sl_vector_inl_defd_rw_shrink(vector, size - count); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_clear(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vector);

	err = mk_sl_vector_inl_defd_rw_resize(vector, 0); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_push_back_many(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pct const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_vector_inl_defd_element_pt item;

	mk_lang_assert(vector);
	mk_lang_assert(elements || count == 0);
	mk_lang_assert(count >= 0);

	err = mk_sl_vector_inl_defd_rw_reserve_at_least(vector, mk_sl_vector_inl_defd_rw_size(vector) + count); mk_lang_check_rereturn(err);
	vector->m_size += count;
	item = mk_sl_vector_inl_defd_rw_at(vector, mk_sl_vector_inl_defd_rw_size(vector) - count);
	mk_sl_vector_inl_filec_memcpy_fn(&item[0], &elements[0], count);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_push_back_one(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pct const element) mk_lang_noexcept
{
	return mk_sl_vector_inl_defd_rw_push_back_many(vector, element, 1);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_push_back_void(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vector);
	mk_lang_assert(count >= 0);

	err = mk_sl_vector_inl_defd_rw_reserve_at_least(vector, mk_sl_vector_inl_defd_rw_size(vector) + count); mk_lang_check_rereturn(err);
	vector->m_size += count;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_pop_back_one(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_assert(vector);
	mk_lang_assert(!mk_sl_vector_inl_defd_rw_is_empty(vector));

	--vector->m_size;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_pop_back_many(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_assert(vector);
	mk_lang_assert(count >= 0);
	mk_lang_assert(mk_sl_vector_inl_defd_rw_size(vector) >= count);

	vector->m_size -= count;
	return 0;
}


#undef mk_sl_vector_inl_filec_memcpy_name
#undef mk_sl_vector_inl_filec_memcpy_fn


#include "mk_sl_vector_inl_defu.h"


#undef mk_sl_vector_t_name
#undef mk_sl_vector_t_element
#undef mk_sl_vector_t_mallocatorg
