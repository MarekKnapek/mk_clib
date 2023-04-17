#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_sizet.h"
#include "mk_lang_static_assert.h"


#include "mk_lang_range_inl_defd.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_range_is_valid_ptr_ptr(mk_lang_range_t const* const begin, mk_lang_range_t const* const end) mk_lang_noexcept
{
#if !defined NDEBUG && !mk_lang_constexpr_has
	unsigned acc;
	mk_lang_range_t	const volatile* it;
	unsigned char const volatile* ptr;
	mk_lang_size_t i;

	acc = 0;
	for(it = beign; it != end; ++it)
	{
		ptr = ((unsigned char const volatile*)(it));
		for(i = 0; i != sizeof(*it); ++i)
		{
			acc += ptr[i];
		}
	}
	((void)(acc));
	return mk_lang_true;
#else
	((void)(begin));
	((void)(end));
	return mk_lang_true;
#endif
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_range_is_valid_ptr_size(mk_lang_range_t const* const begin, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_lang_assert(begin || size == 0);

	return mk_lang_range_is_valid_ptr_size(begin, begin + size);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_range_is_valid_ptr_int(mk_lang_range_t const* const begin, int const size) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_sizeof_bi_size_t >= mk_lang_sizeof_bi_sint_t);

	mk_lang_assert(begin || size == 0);
	mk_lang_assert(size >= 0);

	return mk_lang_range_is_valid_ptr_size(begin, ((mk_lang_size_t)(size)));
}


#include "mk_lang_range_inl_defu.h"
