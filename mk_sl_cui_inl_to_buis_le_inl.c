#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"


#include "mk_sl_cui_inl_to_buis_le_def.h"


mk_lang_jumbo void mk_sl_cui_inl_to_buis_le_fn(mk_sl_cui_t const* x, mk_sl_cui_inl_to_buis_le_t* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	#if mk_lang_sizeof_to_buis_le_t >= mk_lang_sizeof_bui_t
	*dst = ((mk_sl_cui_inl_to_buis_le_t)(*x));
	#else
	{
		#define n ((mk_lang_sizeof_bui_t + (mk_lang_sizeof_to_buis_le_t - 1)) / mk_lang_sizeof_to_buis_le_t)
		mk_sl_cui_t xx;
		int i;
		xx = *x;
		dst[0] = ((mk_sl_cui_inl_to_buis_le_t)(xx));
		for(i = 1; i != n; ++i)
		{
			xx >>= mk_lang_sizeof_to_buis_le_t * mk_lang_charbit;
			dst[i] = ((mk_sl_cui_inl_to_buis_le_t)(xx));
		}
		#undef n
	}
	#endif
}


#include "mk_sl_cui_inl_to_buis_le_undef.h"


#undef mk_sl_cui_inl_to_buis_le_n
#undef mk_sl_cui_inl_to_buis_le_btn
