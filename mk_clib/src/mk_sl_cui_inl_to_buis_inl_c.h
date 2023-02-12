#include "mk_lang_jumbo.h"


#include "mk_sl_cui_inl_to_buis_inl_defd.h"


mk_lang_jumbo void mk_sl_cui_inl_to_buis_inl_defd_fn(mk_sl_cui_inl_def_t const* const x, mk_sl_cui_inl_to_buis_inl_defd_bui_t* const dst)
{
#if mk_sl_cui_inl_def_base_bits == mk_sl_cui_inl_to_buis_inl_defd_bits_bui_t
#if mk_sl_cui_inl_def_count == 1
	mk_lang_assert(x);
	mk_lang_assert(dst);
	*dst = ((mk_sl_cui_inl_to_buis_inl_defd_bui_t)(x->m_data[0]));
#else
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		dst[mk_sl_cui_inl_to_buis_inl_defd_idx(i)] = ((mk_sl_cui_inl_to_buis_inl_defd_bui_t)(x->m_data[mk_sl_cui_inl_def_idx(i)]));
	}
#endif
#elif mk_sl_cui_inl_def_base_bits > mk_sl_cui_inl_to_buis_inl_defd_bits_bui_t && mk_sl_cui_inl_def_base_bits % mk_sl_cui_inl_to_buis_inl_defd_bits_bui_t == 0
#if mk_sl_cui_inl_def_count == 1
	mk_lang_assert(x);
	mk_lang_assert(dst);
	mk_sl_cui_inl_to_buis_inl_defd_base_to_buis(&x->m_data[0], dst);
#else
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_to_buis_inl_defd_base_to_buis(&x->m_data[mk_sl_cui_inl_def_idx(i)], &dst[mk_sl_cui_inl_to_buis_inl_defd_idx2(i)]);
	}
#endif
#elif mk_sl_cui_inl_def_base_bits < mk_sl_cui_inl_to_buis_inl_defd_bits_bui_t
#if mk_sl_cui_inl_def_count == 1
	mk_lang_assert(x);
	mk_lang_assert(dst);
	*dst = ((mk_sl_cui_inl_to_buis_inl_defd_bui_t)(x->m_data[0]));
#else
	((void)(x));
	((void)(dst));
	/*todo*/
#endif
#endif
}/* todo test all this */


#include "mk_sl_cui_inl_to_buis_inl_defu.h"
