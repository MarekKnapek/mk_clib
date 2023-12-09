#include "mk_lang_assert.h"
#include "mk_lang_exception.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"


#include "mk_sl_buffer_inl_defd.h"


mk_lang_jumbo void mk_sl_buffer_inl_defd_buffer_ro_destroy(mk_sl_buffer_inl_defd_buffer_pct const buffer) mk_lang_noexcept
{
	mk_lang_assert(buffer);
	mk_lang_assert(mk_sl_buffer_inl_defd_buffer_pr_check_invariants(buffer));

	mk_sl_buffer_inl_defd_mallocator_deallocate(buffer->m_data, buffer->m_size);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_void_pct mk_sl_buffer_inl_defd_buffer_ro_get_data(mk_sl_buffer_inl_defd_buffer_pct const buffer) mk_lang_noexcept
{
	mk_lang_assert(buffer);
	mk_lang_assert(mk_sl_buffer_inl_defd_buffer_pr_check_invariants(buffer));

	return buffer->m_data;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_buffer_inl_defd_buffer_ro_get_size(mk_sl_buffer_inl_defd_buffer_pct const buffer) mk_lang_noexcept
{
	mk_lang_assert(buffer);
	mk_lang_assert(mk_sl_buffer_inl_defd_buffer_pr_check_invariants(buffer));

	return buffer->m_size;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_buffer_inl_defd_buffer_ro_is_empty(mk_sl_buffer_inl_defd_buffer_pct const buffer) mk_lang_noexcept
{
	mk_lang_assert(buffer);
	mk_lang_assert(mk_sl_buffer_inl_defd_buffer_pr_check_invariants(buffer));

	return buffer->m_size == 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_void_pct mk_sl_buffer_inl_defd_buffer_ro_get_data_at(mk_sl_buffer_inl_defd_buffer_pct const buffer, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_lang_assert(buffer);
	mk_lang_assert(mk_sl_buffer_inl_defd_buffer_pr_check_invariants(buffer));
	mk_lang_assert(buffer->m_data);
	mk_lang_assert(idx < buffer->m_size);

	return ((mk_lang_types_void_pct)(((mk_lang_types_uchar_pct)(buffer->m_data)) + idx));
}


mk_lang_jumbo void mk_sl_buffer_inl_defd_buffer_rw_destroy(mk_sl_buffer_inl_defd_buffer_pt const buffer) mk_lang_noexcept
{
	mk_sl_buffer_inl_defd_buffer_ro_destroy(buffer);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_void_pt mk_sl_buffer_inl_defd_buffer_rw_get_data(mk_sl_buffer_inl_defd_buffer_pt const buffer) mk_lang_noexcept
{
	return ((mk_lang_types_void_pt)(mk_sl_buffer_inl_defd_buffer_ro_get_data(buffer)));
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_buffer_inl_defd_buffer_rw_get_size(mk_sl_buffer_inl_defd_buffer_pt const buffer) mk_lang_noexcept
{
	return mk_sl_buffer_inl_defd_buffer_ro_get_size(buffer);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_buffer_inl_defd_buffer_rw_is_empty(mk_sl_buffer_inl_defd_buffer_pct const buffer) mk_lang_noexcept
{
	return mk_sl_buffer_inl_defd_buffer_ro_is_empty(buffer);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_void_pt mk_sl_buffer_inl_defd_buffer_rw_get_data_at(mk_sl_buffer_inl_defd_buffer_pt const buffer, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	return ((mk_lang_types_void_pt)(mk_sl_buffer_inl_defd_buffer_ro_get_data_at(buffer, idx)));
}


mk_lang_jumbo void mk_sl_buffer_inl_defd_buffer_rw_construct(mk_sl_buffer_inl_defd_buffer_pt const buffer) mk_lang_noexcept
{
	mk_lang_assert(buffer);

	buffer->m_data = mk_lang_null;
	buffer->m_size = 0;
	mk_lang_assert(mk_sl_buffer_inl_defd_buffer_pr_check_invariants(buffer));
}

mk_lang_jumbo void mk_sl_buffer_inl_defd_buffer_rw_resize(mk_sl_buffer_inl_defd_buffer_pt const buffer, mk_lang_exception_pt const ex, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_assert(buffer);
	mk_lang_assert(mk_sl_buffer_inl_defd_buffer_pr_check_invariants(buffer));
	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));

	if(size > buffer->m_size)
	{
		if(buffer->m_data)
		{
			mk_sl_buffer_inl_defd_mallocator_reallocate(ex, buffer->m_data, buffer->m_size, size, &buffer->m_data); mk_lang_exception_if_is_return(ex);
		}
		else
		{
			mk_sl_buffer_inl_defd_mallocator_allocate(ex, size, &buffer->m_data); mk_lang_exception_if_is_return(ex);
		}
		buffer->m_size = size;
	}
	mk_lang_assert(mk_sl_buffer_inl_defd_buffer_pr_check_invariants(buffer));
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_buffer_inl_defd_buffer_pr_check_invariants(mk_sl_buffer_inl_defd_buffer_pct const buffer) mk_lang_nodiscard
{
	mk_lang_assert(buffer);

	return
		(buffer->m_data || buffer->m_size == 0) &&
		(buffer->m_size != 0 || !buffer->m_data);
}


#include "mk_sl_buffer_inl_defu.h"


#undef mk_sl_buffer_t_name
#undef mk_sl_buffer_t_mallocator
