#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"


#include "mk_lang_bui_inl_tofrom_bi_defd.h"


mk_lang_jumbo void mk_lang_bui_inl_tofrom_bi_defd_fn_to(mk_lang_bui_inl_defd_type const* const x, mk_lang_bui_inl_tofrom_bi_defd_bi_t* const dst) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(dst);

	*dst = ((mk_lang_bui_inl_tofrom_bi_defd_bi_t)(*x));
}

mk_lang_jumbo void mk_lang_bui_inl_tofrom_bi_defd_fn_from(mk_lang_bui_inl_defd_type* const x, mk_lang_bui_inl_tofrom_bi_defd_bi_t const* const src) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(src);

	*x = ((mk_lang_bui_inl_defd_type)(*src));
}


#include "mk_lang_bui_inl_tofrom_bi_defu.h"
