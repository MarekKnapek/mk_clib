#include "mk_lang_alignas.h"
#include "mk_lang_alignof.h"
#include "mk_lang_arch.h"
#include "mk_lang_assert.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


#include "mk_lib_crypto_mode_base_x86_inl_defd.h"


#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has))


#include <immintrin.h> /* _mm_load_ps _mm_store_ps _mm_xor_ps */


mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_base_x86_inl_defd_xor3(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pct const b, mk_sl_cui_uint8_pt const c) mk_lang_noexcept
{
	__m128 ta;
	__m128 tb;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(mk_lang_cpuid_has_sse());
	mk_lang_assert((((mk_lang_types_uintptr_t)(a)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(b)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(c)) & 0xf) == 0);

	ta = _mm_load_ps(((mk_lang_types_float_pct)(a)));
	tb = _mm_load_ps(((mk_lang_types_float_pct)(b)));
	ta = _mm_xor_ps(ta, tb);
	_mm_store_ps(((mk_lang_types_float_pt)(c)), ta);
}

mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_base_x86_inl_defd_xor2(mk_sl_cui_uint8_pt const a, mk_sl_cui_uint8_pct const b) mk_lang_noexcept
{
	__m128 ta;
	__m128 tb;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(mk_lang_cpuid_has_sse());
	mk_lang_assert((((mk_lang_types_uintptr_t)(a)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(b)) & 0xf) == 0);

	ta = _mm_load_ps(((mk_lang_types_float_pct)(a)));
	tb = _mm_load_ps(((mk_lang_types_float_pct)(b)));
	ta = _mm_xor_ps(ta, tb);
	_mm_store_ps(((mk_lang_types_float_pt)(a)), ta);
}

#else

mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_base_x86_inl_defd_xor3(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pct const b, mk_sl_cui_uint8_pt const c) mk_lang_noexcept
{
	((mk_lang_types_void_t)(a));
	((mk_lang_types_void_t)(b));
	((mk_lang_types_void_t)(c));
	mk_lang_assert(0);
}

mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_base_x86_inl_defd_xor2(mk_sl_cui_uint8_pt const a, mk_sl_cui_uint8_pct const b) mk_lang_noexcept
{
	((mk_lang_types_void_t)(a));
	((mk_lang_types_void_t)(b));
	mk_lang_assert(0);
}

#endif


#include "mk_lib_crypto_mode_base_x86_inl_defu.h"


#undef mk_lib_crypto_mode_base_x86_t_name
#undef mk_lib_crypto_mode_base_x86_t_len
