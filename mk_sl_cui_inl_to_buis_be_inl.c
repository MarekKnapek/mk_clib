#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"


#include "mk_sl_cui_inl_to_buis_be_def.h"


mk_lang_jumbo void mk_sl_cui_inl_to_buis_be_fn(mk_sl_cui_t const* x, mk_sl_cui_inl_to_buis_be_t* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	#if mk_lang_sizeof_to_buis_be_t >= mk_lang_sizeof_bui_t
	*dst = ((mk_sl_cui_inl_to_buis_be_t)(*x));
	#else
	{
		#define n ((mk_lang_sizeof_bui_t + (mk_lang_sizeof_to_buis_be_t - 1)) / mk_lang_sizeof_to_buis_be_t)
		mk_sl_cui_t xx;
		int i;
		xx = *x;
		dst[n - 1] = ((mk_sl_cui_inl_to_buis_be_t)(xx));
		for(i = 1; i != n; ++i)
		{
			xx >>= mk_lang_sizeof_to_buis_be_t * mk_lang_charbit;
			dst[n - 1 - i] = ((mk_sl_cui_inl_to_buis_be_t)(xx));
		}
		#undef n
	}
	#endif
}


#include "mk_sl_cui_inl_to_buis_be_undef.h"


#undef mk_sl_cui_inl_to_buis_be_n
#undef mk_sl_cui_inl_to_buis_be_btn
