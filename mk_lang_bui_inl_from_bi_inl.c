#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_jumbo.h"


#include "mk_lang_bui_inl_from_bi_def.h"


mk_lang_jumbo void mk_lang_bui_inl_from_bi_fn(mk_lang_bui_t* x, mk_lang_bui_inl_from_bi_t const* src)
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	*x = ((mk_lang_bui_t)(*src));
}


#include "mk_lang_bui_inl_from_bi_undef.h"


#undef mk_lang_bui_inl_from_bi_n
#undef mk_lang_bui_inl_from_bi_btn
