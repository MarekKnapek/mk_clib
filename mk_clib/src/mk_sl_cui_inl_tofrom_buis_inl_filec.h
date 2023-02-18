#include "mk_sl_cui_inl_tofrom_buis_inl_defd.h"


mk_lang_jumbo void mk_sl_cui_inl_tofrom_buis_inl_defd_fn_to(mk_sl_cui_inl_defd_t const* const x, mk_sl_cui_inl_tofrom_buis_inl_defd_bui_t* const dst) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_lang_assert(dst);

	mk_sl_cui_inl_tofrom_buis_inl_defd_base_to_buis(&x->m_data[0], dst);
#elif mk_sl_cui_inl_defd_base_bits == mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_tofrom_buis_inl_defd_base_to_bi(&x->m_data[mk_sl_cui_inl_defd_idx(i)], &dst[mk_sl_cui_inl_tofrom_buis_inl_defd_bui_idx(i)]);
	}
#elif ((mk_sl_cui_inl_defd_base_bits > mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t) && ((mk_sl_cui_inl_defd_base_bits % mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t) == 0))
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_tofrom_buis_inl_defd_base_to_buis(&x->m_data[mk_sl_cui_inl_defd_idx(i)], &dst[mk_sl_cui_inl_tofrom_buis_inl_defd_bui_idx(i * mk_sl_cui_inl_tofrom_buis_inl_defd_ratio_base_bui) - ((mk_sl_cui_inl_tofrom_buis_inl_defd_endian_value == mk_lang_endian_big) ? (mk_sl_cui_inl_tofrom_buis_inl_defd_ratio_base_bui - 1) : (0))]);
	}
#else
	int i;
	mk_sl_cui_inl_tofrom_buis_inl_defd_bui_t da;
	int j;
	mk_sl_cui_inl_tofrom_buis_inl_defd_bui_t db;

	mk_lang_static_assert(mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t > mk_sl_cui_inl_defd_base_bits);
	mk_lang_static_assert((mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t % mk_sl_cui_inl_defd_base_bits) == 0);
	mk_lang_static_assert((mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t / mk_sl_cui_inl_defd_base_bits) >= 2);
	mk_lang_assert(x);
	mk_lang_assert(dst);

	for(i = 0; i != mk_sl_cui_inl_tofrom_buis_inl_defd_cnt_bui; ++i)
	{
		mk_sl_cui_inl_tofrom_buis_inl_defd_base_to_bi(&x->m_data[mk_sl_cui_inl_defd_idx((i * mk_sl_cui_inl_tofrom_buis_inl_defd_ratio_bui_base) + ((mk_sl_cui_inl_tofrom_buis_inl_defd_ratio_bui_base - 1) - 0))], &da);
		for(j = 1; j != mk_sl_cui_inl_tofrom_buis_inl_defd_ratio_bui_base; ++j)
		{
			da = ((mk_sl_cui_inl_tofrom_buis_inl_defd_bui_t)(da << mk_sl_cui_inl_defd_base_bits));
			mk_sl_cui_inl_tofrom_buis_inl_defd_base_to_bi(&x->m_data[mk_sl_cui_inl_defd_idx((i * mk_sl_cui_inl_tofrom_buis_inl_defd_ratio_bui_base) + ((mk_sl_cui_inl_tofrom_buis_inl_defd_ratio_bui_base - 1) - j))], &db);
			mk_sl_cui_inl_tofrom_buis_inl_defd_bui_or2(&da, &db);
		}
		dst[mk_sl_cui_inl_tofrom_buis_inl_defd_bui_idx(i)] = da;
	}
#endif
}

mk_lang_jumbo void mk_sl_cui_inl_tofrom_buis_inl_defd_fn_from(mk_sl_cui_inl_defd_t* const x, mk_sl_cui_inl_tofrom_buis_inl_defd_bui_t const* const src) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_lang_assert(src);

	mk_sl_cui_inl_tofrom_buis_inl_defd_base_from_buis(&x->m_data[0], src);
#elif mk_sl_cui_inl_defd_base_bits == mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_tofrom_buis_inl_defd_base_from_bi(&x->m_data[mk_sl_cui_inl_defd_idx(i)], &src[mk_sl_cui_inl_tofrom_buis_inl_defd_bui_idx(i)]);
	}
#elif ((mk_sl_cui_inl_defd_base_bits > mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t) && ((mk_sl_cui_inl_defd_base_bits % mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t) == 0))
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_tofrom_buis_inl_defd_base_from_buis(&x->m_data[mk_sl_cui_inl_defd_idx(i)], &src[mk_sl_cui_inl_tofrom_buis_inl_defd_bui_idx(i * mk_sl_cui_inl_tofrom_buis_inl_defd_ratio_base_bui) - ((mk_sl_cui_inl_tofrom_buis_inl_defd_endian_value == mk_lang_endian_big) ? (mk_sl_cui_inl_tofrom_buis_inl_defd_ratio_base_bui - 1) : (0))]);
	}
#else
	int i;
	mk_sl_cui_inl_tofrom_buis_inl_defd_bui_t s;
	int j;

	mk_lang_static_assert(mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t > mk_sl_cui_inl_defd_base_bits);
	mk_lang_static_assert((mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t % mk_sl_cui_inl_defd_base_bits) == 0);
	mk_lang_static_assert((mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t / mk_sl_cui_inl_defd_base_bits) >= 2);
	mk_lang_assert(x);
	mk_lang_assert(src);

	for(i = 0; i != mk_sl_cui_inl_tofrom_buis_inl_defd_cnt_bui; ++i)
	{
		s = src[mk_sl_cui_inl_tofrom_buis_inl_defd_bui_idx(i)];
		mk_sl_cui_inl_tofrom_buis_inl_defd_base_from_bi(&x->m_data[mk_sl_cui_inl_defd_idx(i * mk_sl_cui_inl_tofrom_buis_inl_defd_ratio_bui_base + 0)], &s);
		for(j = 1; j != mk_sl_cui_inl_tofrom_buis_inl_defd_ratio_bui_base; ++j)
		{
			s = ((mk_sl_cui_inl_tofrom_buis_inl_defd_bui_t)(s >> mk_sl_cui_inl_defd_base_bits));
			mk_sl_cui_inl_tofrom_buis_inl_defd_base_from_bi(&x->m_data[mk_sl_cui_inl_defd_idx(i * mk_sl_cui_inl_tofrom_buis_inl_defd_ratio_bui_base + j)], &s);
		}
	}
#endif
}


#include "mk_sl_cui_inl_tofrom_buis_inl_defu.h"
