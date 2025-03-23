#include "mk_lang_assert.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"


#include "mk_lib_crypto_bitops_bulk_inl_defd.h"


#define mk_lib_crypto_bitops_bulk_inl_filec_memcpy_name mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_defd_name, _zzz_memcpy)
#define mk_lib_crypto_bitops_bulk_inl_filec_memcpy_fn mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_filec_memcpy_name, _fn)
#define mk_lang_memcpy2_t_name mk_lib_crypto_bitops_bulk_inl_filec_memcpy_name
#define mk_lang_memcpy2_t_tn mk_lib_crypto_bitops_bulk_inl_defd_tn
#include "mk_lang_memcpy2_inl_fileh.h"
#include "mk_lang_memcpy2_inl_filec.h"
#include "mk_lang_memcpy2_inl_fileu.h"

#define mk_lib_crypto_bitops_bulk_inl_filec_memclr_name mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_defd_name, _zzz_memclr)
#define mk_lib_crypto_bitops_bulk_inl_filec_memclr_fn mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_filec_memclr_name, _fn)
#define mk_lang_memclr2_t_name mk_lib_crypto_bitops_bulk_inl_filec_memclr_name
#define mk_lang_memclr2_t_tn mk_lib_crypto_bitops_bulk_inl_defd_tn
#include "mk_lang_memclr2_inl_fileh.h"
#include "mk_lang_memclr2_inl_filec.h"
#include "mk_lang_memclr2_inl_fileu.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_bitops_bulk_inl_defd_memcpy(mk_lang_static_param(mk_lib_crypto_bitops_bulk_inl_defd_t, dst, mk_lib_crypto_bitops_bulk_inl_defd_count), mk_lang_static_param(mk_lib_crypto_bitops_bulk_inl_defd_ct, src, mk_lib_crypto_bitops_bulk_inl_defd_count)) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lib_crypto_bitops_bulk_inl_filec_memcpy_fn(dst, src, mk_lib_crypto_bitops_bulk_inl_defd_count);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_bitops_bulk_inl_defd_memclr(mk_lang_static_param(mk_lib_crypto_bitops_bulk_inl_defd_t, x, mk_lib_crypto_bitops_bulk_inl_defd_count)) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_lib_crypto_bitops_bulk_inl_filec_memclr_fn(x, mk_lib_crypto_bitops_bulk_inl_defd_count);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_bitops_bulk_inl_defd_xor2(mk_lang_static_param(mk_lib_crypto_bitops_bulk_inl_defd_t, a, mk_lib_crypto_bitops_bulk_inl_defd_count), mk_lang_static_param(mk_lib_crypto_bitops_bulk_inl_defd_ct, b, mk_lib_crypto_bitops_bulk_inl_defd_count)) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_lib_crypto_bitops_bulk_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_bitops_bulk_inl_defd_base_xor2(&a[i], &b[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_bitops_bulk_inl_defd_xor3(mk_lang_static_param(mk_lib_crypto_bitops_bulk_inl_defd_ct, a, mk_lib_crypto_bitops_bulk_inl_defd_count), mk_lang_static_param(mk_lib_crypto_bitops_bulk_inl_defd_ct, b, mk_lib_crypto_bitops_bulk_inl_defd_count), mk_lang_static_param(mk_lib_crypto_bitops_bulk_inl_defd_t, c, mk_lib_crypto_bitops_bulk_inl_defd_count)) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	n = mk_lib_crypto_bitops_bulk_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_bitops_bulk_inl_defd_base_xor3(&a[i], &b[i], &c[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_bitops_bulk_inl_defd_add2_wrap_cid_cod(mk_lang_static_param(mk_lib_crypto_bitops_bulk_inl_defd_t, a, mk_lib_crypto_bitops_bulk_inl_defd_count), mk_lang_static_param(mk_lib_crypto_bitops_bulk_inl_defd_ct, b, mk_lib_crypto_bitops_bulk_inl_defd_count)) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_lib_crypto_bitops_bulk_inl_defd_count;
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_bitops_bulk_inl_defd_base_add2_wrap_cid_cod(&a[i], &b[i]);
	}
}

#undef mk_lib_crypto_bitops_bulk_inl_filec_memcpy_name
#undef mk_lib_crypto_bitops_bulk_inl_filec_memcpy_fn

#undef mk_lib_crypto_bitops_bulk_inl_filec_memclr_name
#undef mk_lib_crypto_bitops_bulk_inl_filec_memclr_fn


#include "mk_lib_crypto_bitops_bulk_inl_defu.h"
