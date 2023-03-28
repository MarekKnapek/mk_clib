#include "mk_sl_cui_inl_tofrom_buis_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_tofrom_buis_inl_defd_fn_to(mk_sl_cui_inl_defd_t const* const x, mk_sl_cui_inl_tofrom_buis_inl_defd_bui_t* const dst) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_lang_assert(dst);

	mk_sl_cui_inl_tofrom_buis_inl_defd_base_to_buis(&x->m_data[0], dst);
#elif mk_sl_cui_inl_defd_base_bits == mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t
	int i mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_tofrom_buis_inl_defd_base_to_bi(&x->m_data[mk_sl_cui_inl_defd_idx(i)], &dst[mk_sl_cui_inl_tofrom_buis_inl_defd_bui_idx(i)]);
	}
#elif ((mk_sl_cui_inl_defd_base_bits > mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t) && ((mk_sl_cui_inl_defd_base_bits % mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t) == 0))
	int i mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_tofrom_buis_inl_defd_base_to_buis(&x->m_data[mk_sl_cui_inl_defd_idx(i)], &dst[mk_sl_cui_inl_tofrom_buis_inl_defd_bui_idx(i * mk_sl_cui_inl_tofrom_buis_inl_defd_ratio_base_bui) - ((mk_sl_cui_inl_tofrom_buis_inl_defd_endian_value == mk_lang_endian_big) ? (mk_sl_cui_inl_tofrom_buis_inl_defd_ratio_base_bui - 1) : (0))]);
	}
#elif ((mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t > mk_sl_cui_inl_defd_base_bits) && ((mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t % mk_sl_cui_inl_defd_base_bits) == 0))
	int i mk_lang_constexpr_init;
	mk_sl_cui_inl_tofrom_buis_inl_defd_bui_t ta mk_lang_constexpr_init;
	int j mk_lang_constexpr_init;
	mk_sl_cui_inl_tofrom_buis_inl_defd_bui_t tb mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(dst);
	mk_lang_assert(mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t / mk_sl_cui_inl_defd_base_bits >= 2);

	for(i = 0; i != mk_sl_cui_inl_defd_bits / mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t; ++i)
	{
		mk_sl_cui_inl_tofrom_buis_inl_defd_base_to_bi(&x->m_data[mk_sl_cui_inl_defd_idx(i * (mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t / mk_sl_cui_inl_defd_base_bits) + ((mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t / mk_sl_cui_inl_defd_base_bits) - 1 - 0))], &ta);
		for(j = 1; j != mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t / mk_sl_cui_inl_defd_base_bits; ++j)
		{
			mk_sl_cui_inl_tofrom_buis_inl_defd_base_to_bi(&x->m_data[mk_sl_cui_inl_defd_idx(i * (mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t / mk_sl_cui_inl_defd_base_bits) + ((mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t / mk_sl_cui_inl_defd_base_bits) - 1 - j))], &tb);
			mk_sl_cui_inl_tofrom_buis_inl_defd_bui_shl2(&ta, mk_sl_cui_inl_defd_base_bits);
			mk_sl_cui_inl_tofrom_buis_inl_defd_bui_or2(&ta, &tb);
		}
		dst[mk_sl_cui_inl_tofrom_buis_inl_defd_bui_idx(i)] = ta;
	}
	#if(mk_sl_cui_inl_tofrom_buis_inl_defd_rest != 0)
	mk_sl_cui_inl_tofrom_buis_inl_defd_base_to_bi(&x->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - 0)], &ta);
	#if(mk_sl_cui_inl_tofrom_buis_inl_defd_rest >= 2)
	for(j = 1; j != mk_sl_cui_inl_tofrom_buis_inl_defd_rest; ++j)
	{
		mk_sl_cui_inl_tofrom_buis_inl_defd_base_to_bi(&x->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - j)], &tb);
		mk_sl_cui_inl_tofrom_buis_inl_defd_bui_shl2(&ta, mk_sl_cui_inl_defd_base_bits);
		mk_sl_cui_inl_tofrom_buis_inl_defd_bui_or2(&ta, &tb);
	}
	#endif
	dst[mk_sl_cui_inl_tofrom_buis_inl_defd_bui_idx(i)] = ta;
	#endif
#else
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_tofrom_buis_inl_defd_fn_from(mk_sl_cui_inl_defd_t* const x, mk_sl_cui_inl_tofrom_buis_inl_defd_bui_t const* const src) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_lang_assert(src);

	mk_sl_cui_inl_tofrom_buis_inl_defd_base_from_buis(&x->m_data[0], src);
#elif mk_sl_cui_inl_defd_base_bits == mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t
	int i mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(src);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_tofrom_buis_inl_defd_base_from_bi(&x->m_data[mk_sl_cui_inl_defd_idx(i)], &src[mk_sl_cui_inl_tofrom_buis_inl_defd_bui_idx(i)]);
	}
#elif ((mk_sl_cui_inl_defd_base_bits > mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t) && ((mk_sl_cui_inl_defd_base_bits % mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t) == 0))
	int i mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(src);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_tofrom_buis_inl_defd_base_from_buis(&x->m_data[mk_sl_cui_inl_defd_idx(i)], &src[mk_sl_cui_inl_tofrom_buis_inl_defd_bui_idx(i * mk_sl_cui_inl_tofrom_buis_inl_defd_ratio_base_bui) - ((mk_sl_cui_inl_tofrom_buis_inl_defd_endian_value == mk_lang_endian_big) ? (mk_sl_cui_inl_tofrom_buis_inl_defd_ratio_base_bui - 1) : (0))]);
	}
#elif ((mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t > mk_sl_cui_inl_defd_base_bits) && ((mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t % mk_sl_cui_inl_defd_base_bits) == 0))
	int i mk_lang_constexpr_init;
	mk_sl_cui_inl_tofrom_buis_inl_defd_bui_t ta mk_lang_constexpr_init;
	int j mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(src);
	mk_lang_assert(mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t / mk_sl_cui_inl_defd_base_bits >= 2);

	for(i = 0; i != mk_sl_cui_inl_defd_bits / mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t; ++i)
	{
		ta = src[mk_sl_cui_inl_tofrom_buis_inl_defd_bui_idx(i)];
		mk_sl_cui_inl_tofrom_buis_inl_defd_base_from_bi(&x->m_data[mk_sl_cui_inl_defd_idx(i * (mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t / mk_sl_cui_inl_defd_base_bits) + 0)], &ta);
		for(j = 1; j != mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t / mk_sl_cui_inl_defd_base_bits; ++j)
		{
			mk_sl_cui_inl_tofrom_buis_inl_defd_bui_shr2(&ta, mk_sl_cui_inl_defd_base_bits);
			mk_sl_cui_inl_tofrom_buis_inl_defd_base_from_bi(&x->m_data[mk_sl_cui_inl_defd_idx(i * (mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t / mk_sl_cui_inl_defd_base_bits) + j)], &ta);
		}
	}
	#if(mk_sl_cui_inl_tofrom_buis_inl_defd_rest != 0)
	ta = src[mk_sl_cui_inl_tofrom_buis_inl_defd_bui_idx(i)];
	mk_sl_cui_inl_tofrom_buis_inl_defd_base_from_bi(&x->m_data[mk_sl_cui_inl_defd_idx(i * (mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t / mk_sl_cui_inl_defd_base_bits) + 0)], &ta);
	#if(mk_sl_cui_inl_tofrom_buis_inl_defd_rest >= 2)
	for(j = 1; j != mk_sl_cui_inl_tofrom_buis_inl_defd_rest; ++j)
	{
		mk_sl_cui_inl_tofrom_buis_inl_defd_bui_shr2(&ta, mk_sl_cui_inl_defd_base_bits);
		mk_sl_cui_inl_tofrom_buis_inl_defd_base_from_bi(&x->m_data[mk_sl_cui_inl_defd_idx(i * (mk_sl_cui_inl_tofrom_buis_inl_defd_bui_bits_t / mk_sl_cui_inl_defd_base_bits) + j)], &ta);
	}
	#endif
	#endif
#else
#endif
}


#include "mk_sl_cui_inl_tofrom_buis_inl_defu.h"
