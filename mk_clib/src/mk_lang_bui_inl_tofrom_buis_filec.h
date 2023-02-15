#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"


#include "mk_lang_bui_inl_tofrom_buis_defd.h"


mk_lang_jumbo void mk_lang_bui_inl_tofrom_buis_defd_fn_to(mk_lang_bui_inl_defd_type const* const x, mk_lang_bui_inl_tofrom_buis_defd_bui_t* const dst)
{
	#if mk_lang_bui_inl_defd_sizeof <= mk_lang_bui_inl_tofrom_buis_defd_sizeof_bui_t

	mk_lang_assert(x);
	mk_lang_assert(dst);

	*dst = ((mk_lang_bui_inl_tofrom_buis_defd_bui_t)(*x));

	#else

	mk_lang_bui_inl_defd_type xx;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(dst);

	xx = *x;
	dst[mk_lang_bui_inl_tofrom_buis_defd_idx(0)] = ((mk_lang_bui_inl_tofrom_buis_defd_bui_t)(xx));
	for(i = 1; i != mk_lang_bui_inl_tofrom_buis_defd_count; ++i)
	{
		xx = ((mk_lang_bui_inl_defd_type)(xx >> ((int)(((int)(mk_lang_bui_inl_tofrom_buis_defd_sizeof_bui_t)) * ((int)(mk_lang_charbit))))));
		dst[mk_lang_bui_inl_tofrom_buis_defd_idx(i)] = ((mk_lang_bui_inl_tofrom_buis_defd_bui_t)(xx));
	}

	#endif
}

mk_lang_jumbo void mk_lang_bui_inl_tofrom_buis_defd_fn_from(mk_lang_bui_inl_defd_type* const x, mk_lang_bui_inl_tofrom_buis_defd_bui_t const* const src)
{
	#if mk_lang_bui_inl_defd_sizeof <= mk_lang_bui_inl_tofrom_buis_defd_sizeof_bui_t

	mk_lang_assert(x);
	mk_lang_assert(src);

	*x = ((mk_lang_bui_inl_defd_type)(*src));

	#else

	mk_lang_bui_inl_defd_type xx;
	int i;

	mk_lang_assert(x);
	mk_lang_assert(src);

	xx = ((mk_lang_bui_inl_defd_type)(src[mk_lang_bui_inl_tofrom_buis_defd_idx((mk_lang_bui_inl_tofrom_buis_defd_count - 1) - 0)]));
	for(i = 1; i != mk_lang_bui_inl_tofrom_buis_defd_count; ++i)
	{
		xx = ((mk_lang_bui_inl_defd_type)(xx << ((int)(((int)(mk_lang_bui_inl_tofrom_buis_defd_sizeof_bui_t)) * ((int)(mk_lang_charbit))))));
		xx = ((mk_lang_bui_inl_defd_type)(xx | ((mk_lang_bui_inl_defd_type)(src[mk_lang_bui_inl_tofrom_buis_defd_idx((mk_lang_bui_inl_tofrom_buis_defd_count - 1) - i)]))));
	}
	*x = xx;

	#endif
}


#include "mk_lang_bui_inl_tofrom_buis_defu.h"
