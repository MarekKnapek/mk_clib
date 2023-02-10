#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"


#include "mk_lang_bui_inl_from_buis_be_def.h"


mk_lang_jumbo void mk_lang_bui_inl_from_buis_be_fn(mk_lang_bui_t* x, mk_lang_bui_inl_from_buis_be_t const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	#if mk_lang_sizeof_bui_t <= mk_lang_sizeof_from_buis_be_t
	*x = ((mk_lang_bui_t)(*src));
	#else
	{
		#define n ((mk_lang_sizeof_bui_t + (mk_lang_sizeof_from_buis_be_t - 1)) / mk_lang_sizeof_from_buis_be_t)
		mk_lang_bui_t xx;
		int i;
		xx = ((mk_lang_bui_t)(src[0]));
		for(i = 1; i != n; ++i)
		{
			xx = ((mk_lang_bui_t)(xx << ((int)(mk_lang_sizeof_from_buis_be_t * mk_lang_charbit))));
			xx = ((mk_lang_bui_t)(xx | ((mk_lang_bui_t)(src[i]))));
		}
		*x = xx;
		#undef n
	}
	#endif
}


#include "mk_lang_bui_inl_from_buis_be_undef.h"


#undef mk_lang_bui_inl_from_buis_be_n
#undef mk_lang_bui_inl_from_buis_be_btn
