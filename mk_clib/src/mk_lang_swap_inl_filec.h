#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#include "mk_lang_swap_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_swap_inl_defd_fn(mk_lang_swap_inl_defd_type_pt const a, mk_lang_swap_inl_defd_type_pt const b) mk_lang_noexcept
{
	mk_lang_swap_inl_defd_type_t t mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	t = *a;
	*a = *b;
	*b = t;
}


#include "mk_lang_swap_inl_defu.h"


#undef mk_lang_swap_t_name
#undef mk_lang_swap_t_type
