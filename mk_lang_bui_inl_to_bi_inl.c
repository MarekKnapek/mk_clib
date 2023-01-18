#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_jumbo.h"


#include "mk_lang_bui_inl_to_bi_def.h"


mk_lang_jumbo void mk_lang_bui_inl_to_bi_fn(mk_lang_bui_t const* x, mk_lang_bui_inl_to_bi_t* dst)
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	*dst = ((mk_lang_bui_inl_to_bi_t)(*x));
}


#include "mk_lang_bui_inl_to_bi_undef.h"


#undef mk_lang_bui_inl_to_bi_n
#undef mk_lang_bui_inl_to_bi_btn
