#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"


#include "mk_sl_cui_convert_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_convert_inl_defd_fn_a_to_b(mk_sl_cui_convert_inl_defd_a_t const* const a, mk_sl_cui_convert_inl_defd_b_t* const b) mk_lang_noexcept
{
#if mk_sl_cui_convert_inl_defd_a_base_is_bui == 1 && mk_sl_cui_convert_inl_defd_b_base_is_bui == 1 && mk_sl_cui_convert_inl_defd_a_count == 1 && mk_sl_cui_convert_inl_defd_b_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	b->m_data[0] = ((mk_sl_cui_convert_inl_defd_b_base_t)(a->m_data[0]));
#elif mk_sl_cui_convert_inl_defd_a_base_is_bui == 1 && mk_sl_cui_convert_inl_defd_b_base_is_bui == 1 && mk_sl_cui_convert_inl_defd_a_base_bits == mk_sl_cui_convert_inl_defd_b_base_bits
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_lang_min(mk_sl_cui_convert_inl_defd_a_count, mk_sl_cui_convert_inl_defd_b_count); ++i)
	{
		b->m_data[mk_sl_cui_convert_inl_defd_a_idx(i)] = ((mk_sl_cui_convert_inl_defd_b_base_t)(a->m_data[mk_sl_cui_convert_inl_defd_a_idx(i)]));
	}
	#if mk_sl_cui_convert_inl_defd_b_count > mk_sl_cui_convert_inl_defd_a_count
	for(; i != mk_sl_cui_convert_inl_defd_b_count; ++i)
	{
		b->m_data[mk_sl_cui_convert_inl_defd_a_idx(i)] = ((mk_sl_cui_convert_inl_defd_b_base_t)(0));
	}
	#endif
#endif
}


#include "mk_sl_cui_convert_inl_defu.h"


#undef mk_sl_cui_convert_a_name
#undef mk_sl_cui_convert_a_base_type
#undef mk_sl_cui_convert_a_base_name
#undef mk_sl_cui_convert_a_base_bits
#undef mk_sl_cui_convert_a_count
#undef mk_sl_cui_convert_a_endian
#undef mk_sl_cui_convert_a_base_is_bui
#undef mk_sl_cui_convert_a_base_bui_tn
#undef mk_sl_cui_convert_b_name
#undef mk_sl_cui_convert_b_base_type
#undef mk_sl_cui_convert_b_base_name
#undef mk_sl_cui_convert_b_base_bits
#undef mk_sl_cui_convert_b_count
#undef mk_sl_cui_convert_b_endian
#undef mk_sl_cui_convert_b_base_is_bui
#undef mk_sl_cui_convert_b_base_bui_tn
