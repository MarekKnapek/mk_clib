#include "mk_sl_cui_inl_tofrom_bi_inl_defd.h"


mk_lang_jumbo void mk_sl_cui_inl_tofrom_bi_inl_defd_fn_to(mk_sl_cui_inl_defd_t const* const x, mk_sl_cui_inl_tofrom_bi_inl_defd_bi_t* const dst) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_lang_assert(dst);

	mk_sl_cui_inl_tofrom_bi_inl_defd_base_to_bi(&x->m_data[0], dst);
#elif mk_sl_cui_inl_defd_base_bits >= mk_sl_cui_inl_tofrom_bi_inl_defd_bits_bi_t
	mk_lang_assert(x);
	mk_lang_assert(dst);

	mk_sl_cui_inl_tofrom_bi_inl_defd_base_to_bi(&x->m_data[mk_sl_cui_inl_defd_idx(0)], dst);
#else
	mk_sl_cui_inl_tofrom_bi_inl_defd_bui_t ta;
	mk_sl_cui_inl_tofrom_bi_inl_defd_bui_t tb;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	mk_sl_cui_inl_tofrom_bi_inl_defd_base_to_bui(&x->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_tofrom_bi_inl_defd_parts - 1) - 0)], &ta);
	for(i = 1; i != mk_sl_cui_inl_tofrom_bi_inl_defd_parts; ++i)
	{
		mk_sl_cui_inl_tofrom_bi_inl_defd_bui_shl2(&ta, mk_sl_cui_inl_defd_base_bits);
		mk_sl_cui_inl_tofrom_bi_inl_defd_base_to_bui(&x->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_tofrom_bi_inl_defd_parts - 1) - i)], &tb);
		mk_sl_cui_inl_tofrom_bi_inl_defd_bui_or2(&ta, &tb);
	}
	*dst = ((mk_sl_cui_inl_tofrom_bi_inl_defd_bi_t)(ta));
#endif
}

mk_lang_jumbo void mk_sl_cui_inl_tofrom_bi_inl_defd_fn_from(mk_sl_cui_inl_defd_t* const x, mk_sl_cui_inl_tofrom_bi_inl_defd_bi_t const* const src) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_lang_assert(src);

	mk_sl_cui_inl_tofrom_bi_inl_defd_base_from_bi(&x->m_data[0], src);
#elif mk_sl_cui_inl_defd_base_bits >= mk_sl_cui_inl_tofrom_bi_inl_defd_bits_bi_t
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	mk_sl_cui_inl_tofrom_bi_inl_defd_base_from_bi(&x->m_data[mk_sl_cui_inl_defd_idx(0)], src);
	for(i = 1; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_set_zero(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#else
	mk_sl_cui_inl_tofrom_bi_inl_defd_bui_t s;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	s = ((mk_sl_cui_inl_tofrom_bi_inl_defd_bi_t)(*src));
	mk_sl_cui_inl_tofrom_bi_inl_defd_base_from_bui(&x->m_data[mk_sl_cui_inl_defd_idx(0)], &s);
	for(i = 1; i != mk_sl_cui_inl_tofrom_bi_inl_defd_parts; ++i)
	{
		mk_sl_cui_inl_tofrom_bi_inl_defd_bui_shr2(&s, mk_sl_cui_inl_defd_base_bits);
		mk_sl_cui_inl_tofrom_bi_inl_defd_base_from_bui(&x->m_data[mk_sl_cui_inl_defd_idx(i)], &s);
	}
	#if mk_sl_cui_inl_tofrom_bi_inl_defd_parts < mk_sl_cui_inl_defd_count
	for(; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_set_zero(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
	#endif
#endif
}


#include "mk_sl_cui_inl_tofrom_bi_inl_defu.h"
