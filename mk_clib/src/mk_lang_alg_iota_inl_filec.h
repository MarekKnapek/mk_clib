#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#include "mk_lang_alg_iota_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_alg_iota_inl_defd_fn(mk_lang_alg_iota_inl_defd_element_pt const data_buf, mk_lang_alg_iota_inl_defd_counter_t const data_len) mk_lang_noexcept
{
	mk_lang_alg_iota_inl_defd_counter_t n mk_lang_constexpr_init;
	mk_lang_alg_iota_inl_defd_counter_t i mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	n = data_len;
	for(i = 0; i != n; ++i)
	{
		data_buf[i] = ((mk_lang_alg_iota_inl_defd_element_t)(i));
	}
}


#include "mk_lang_alg_iota_inl_defu.h"
