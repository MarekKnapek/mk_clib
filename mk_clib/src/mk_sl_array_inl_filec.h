#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#include "mk_sl_array_inl_defd.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_array_inl_defd_st_capacity(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	ret = mk_sl_array_inl_defd_len_v;
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_array_inl_defd_st_size(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	ret = mk_sl_array_inl_defd_st_capacity();
	return ret;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_array_inl_defd_ro_capacity(mk_sl_array_inl_defd_pct const arr) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(arr);

	((mk_lang_types_void_t)(arr));
	ret = mk_sl_array_inl_defd_st_capacity();
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_array_inl_defd_ro_size(mk_sl_array_inl_defd_pct const arr) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(arr);

	((mk_lang_types_void_t)(arr));
	ret = mk_sl_array_inl_defd_st_size();
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_array_inl_defd_element_pct mk_sl_array_inl_defd_ro_at(mk_sl_array_inl_defd_pct const arr, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_sl_array_inl_defd_element_pct ret mk_lang_constexpr_init;

	mk_lang_assert(arr);
	mk_lang_assert(idx >= 0 && idx < mk_sl_array_inl_defd_ro_size(arr));

	ret = &arr->m_elements[idx];
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_array_inl_defd_element_pct mk_sl_array_inl_defd_ro_data(mk_sl_array_inl_defd_pct const arr) mk_lang_noexcept
{
	mk_sl_array_inl_defd_element_pct ret mk_lang_constexpr_init;

	mk_lang_assert(arr);

	ret = mk_sl_array_inl_defd_ro_at(arr, 0);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_array_inl_defd_element_pct mk_sl_array_inl_defd_ro_front(mk_sl_array_inl_defd_pct const arr) mk_lang_noexcept
{
	mk_sl_array_inl_defd_element_pct ret mk_lang_constexpr_init;

	mk_lang_assert(arr);

	ret = mk_sl_array_inl_defd_ro_data(arr);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_array_inl_defd_element_pct mk_sl_array_inl_defd_ro_back(mk_sl_array_inl_defd_pct const arr) mk_lang_noexcept
{
	mk_sl_array_inl_defd_element_pct ret mk_lang_constexpr_init;

	mk_lang_assert(arr);

	ret = mk_sl_array_inl_defd_ro_at(arr, mk_sl_array_inl_defd_ro_size(arr) - 1);
	return ret;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_array_inl_defd_rw_capacity(mk_sl_array_inl_defd_pt const arr) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(arr);

	ret = mk_sl_array_inl_defd_ro_capacity(arr);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_array_inl_defd_rw_size(mk_sl_array_inl_defd_pt const arr) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(arr);

	ret = mk_sl_array_inl_defd_ro_size(arr);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_array_inl_defd_element_pt mk_sl_array_inl_defd_rw_at(mk_sl_array_inl_defd_pt const arr, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_sl_array_inl_defd_element_pt ret mk_lang_constexpr_init;

	mk_lang_assert(arr);
	mk_lang_assert(idx >= 0 && idx < mk_sl_array_inl_defd_rw_size(arr));

	ret = ((mk_sl_array_inl_defd_element_pt)(mk_sl_array_inl_defd_ro_at(arr, idx)));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_array_inl_defd_element_pt mk_sl_array_inl_defd_rw_data(mk_sl_array_inl_defd_pt const arr) mk_lang_noexcept
{
	mk_sl_array_inl_defd_element_pt ret mk_lang_constexpr_init;

	mk_lang_assert(arr);

	ret = ((mk_sl_array_inl_defd_element_pt)(mk_sl_array_inl_defd_ro_data(arr)));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_array_inl_defd_element_pt mk_sl_array_inl_defd_rw_front(mk_sl_array_inl_defd_pt const arr) mk_lang_noexcept
{
	mk_sl_array_inl_defd_element_pt ret mk_lang_constexpr_init;

	mk_lang_assert(arr);

	ret = ((mk_sl_array_inl_defd_element_pt)(mk_sl_array_inl_defd_ro_front(arr)));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_array_inl_defd_element_pt mk_sl_array_inl_defd_rw_back(mk_sl_array_inl_defd_pt const arr) mk_lang_noexcept
{
	mk_sl_array_inl_defd_element_pt ret mk_lang_constexpr_init;

	mk_lang_assert(arr);

	ret = ((mk_sl_array_inl_defd_element_pt)(mk_sl_array_inl_defd_ro_back(arr)));
	return ret;
}


#include "mk_sl_array_inl_defu.h"


#undef mk_sl_array_t_name
#undef mk_sl_array_t_element
#undef mk_sl_array_t_count
