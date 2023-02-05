#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"


#include "mk_sl_cui_inl_from_buis_le_def.h"


mk_lang_jumbo void mk_sl_cui_inl_from_buis_le_fn(mk_sl_cui_t* x, mk_sl_cui_inl_from_buis_le_t const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	#if mk_lang_sizeof_bui_t <= mk_lang_sizeof_from_buis_le_t
	*x = ((mk_sl_cui_t)(*src));
	#else
	{
		#define n ((mk_lang_sizeof_bui_t + (mk_lang_sizeof_from_buis_le_t - 1)) / mk_lang_sizeof_from_buis_le_t)
		mk_sl_cui_t xx;
		int i;
		xx = ((mk_sl_cui_t)(src[n - 1 - 0]));
		for(i = 1; i != n; ++i)
		{
			xx = ((mk_sl_cui_t)(xx << ((int)(mk_lang_sizeof_from_buis_le_t * mk_lang_charbit))));
			xx = ((mk_sl_cui_t)(xx | ((mk_sl_cui_t)(src[n - 1 - i]))));
		}
		*x = xx;
		#undef n
	}
	#endif
}


#include "mk_sl_cui_inl_from_buis_le_undef.h"


#undef mk_sl_cui_inl_from_buis_le_n
#undef mk_sl_cui_inl_from_buis_le_btn
