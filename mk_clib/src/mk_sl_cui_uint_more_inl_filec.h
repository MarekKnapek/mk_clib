#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_sl_uint_more.h"

#include "mk_sl_cui_uint8.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint128.h"
#include "mk_sl_cui_uint256.h"
#include "mk_sl_cui_uint512.h"
#include "mk_sl_cui_uint1024.h"


#include "mk_sl_cui_uint_more_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint_more_inl_defd_xor2(mk_lang_static_param(mk_sl_cui_uint_more_inl_defd_type_t, a, mk_sl_cui_uint_more_inl_defd_count), mk_lang_static_param(mk_sl_cui_uint_more_inl_defd_type_ct, b, mk_sl_cui_uint_more_inl_defd_count)) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	#if mk_sl_cui_uint_more_inl_defd_type == 8
	/* todo test for align, and sse and such stuff */
	mk_sl_cui_uint8_xor2_many(a, b, mk_sl_cui_uint_more_inl_defd_count);
	#else
	#error xxxxxxxxxx
	#endif
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint_more_inl_defd_xor3(mk_lang_static_param(mk_sl_cui_uint_more_inl_defd_type_ct, a, mk_sl_cui_uint_more_inl_defd_count), mk_lang_static_param(mk_sl_cui_uint_more_inl_defd_type_ct, b, mk_sl_cui_uint_more_inl_defd_count), mk_lang_static_param(mk_sl_cui_uint_more_inl_defd_type_t, c, mk_sl_cui_uint_more_inl_defd_count)) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	#if mk_sl_cui_uint_more_inl_defd_type == 8
	mk_sl_cui_uint8_xor3_many_n(a, b, mk_sl_cui_uint_more_inl_defd_count, c);
	#else
	#error xxxxxxxxxx
	#endif
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint_more_inl_defd_memcpy(mk_lang_static_param(mk_sl_cui_uint_more_inl_defd_type_t, dst, mk_sl_cui_uint_more_inl_defd_count), mk_lang_static_param(mk_sl_cui_uint_more_inl_defd_type_ct, src, mk_sl_cui_uint_more_inl_defd_count)) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	#if mk_sl_cui_uint_more_inl_defd_type == 8
	mk_sl_cui_uint8_memcpy_fn(dst, src, mk_sl_cui_uint_more_inl_defd_count);
	#else
	#error xxxxxxxxxx
	#endif
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint_more_inl_defd_memmov(mk_lang_static_param(mk_sl_cui_uint_more_inl_defd_type_t, dst, mk_sl_cui_uint_more_inl_defd_count), mk_lang_static_param(mk_sl_cui_uint_more_inl_defd_type_ct, src, mk_sl_cui_uint_more_inl_defd_count)) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	#if mk_sl_cui_uint_more_inl_defd_type == 8
	mk_sl_cui_uint8_memmov_fn(dst, src, mk_sl_cui_uint_more_inl_defd_count);
	#else
	#error xxxxxxxxxx
	#endif
}


#include "mk_sl_cui_uint_more_inl_defu.h"
