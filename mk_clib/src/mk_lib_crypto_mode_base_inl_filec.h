#include "mk_lang_alignas.h"
#include "mk_lang_alignof.h"
#include "mk_lang_arch.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


#include "mk_lib_crypto_mode_base_inl_defd.h"


#define mk_lib_crypto_mode_base_c_t_name mk_lang_concat(mk_lib_crypto_mode_base_inl_defd_prefix, _disp_c)
#define mk_lib_crypto_mode_base_c_t_len mk_lib_crypto_mode_base_inl_defd_len
#include "mk_lib_crypto_mode_base_c_inl_fileh.h"
#include "mk_lib_crypto_mode_base_c_inl_filec.h"
#define mk_lib_crypto_mode_base_inl_defd_c_xor3 mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_base_inl_defd_prefix, _disp_c), _xor3)
#define mk_lib_crypto_mode_base_inl_defd_c_xor2 mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_base_inl_defd_prefix, _disp_c), _xor2)

#define mk_lib_crypto_mode_base_x86_t_name mk_lang_concat(mk_lib_crypto_mode_base_inl_defd_prefix, _disp_x86)
#define mk_lib_crypto_mode_base_x86_t_len mk_lib_crypto_mode_base_inl_defd_len
#include "mk_lib_crypto_mode_base_x86_inl_fileh.h"
#include "mk_lib_crypto_mode_base_x86_inl_filec.h"
#define mk_lib_crypto_mode_base_inl_defd_x86_xor3 mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_base_inl_defd_prefix, _disp_x86), _xor3)
#define mk_lib_crypto_mode_base_inl_defd_x86_xor2 mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_base_inl_defd_prefix, _disp_x86), _xor2)


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_base_inl_defd_xor3(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pct const b, mk_sl_cui_uint8_pt const c) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has) && (mk_lib_crypto_mode_base_inl_defd_len == 16))
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_sse() && ((((mk_lang_types_uintptr_t)(a)) & 0xf) == 0) && ((((mk_lang_types_uintptr_t)(b)) & 0xf) == 0) && ((((mk_lang_types_uintptr_t)(c)) & 0xf) == 0))
	{
		mk_lib_crypto_mode_base_inl_defd_x86_xor3(a, b, c);
	}
	else
	#endif
	{
		mk_lib_crypto_mode_base_inl_defd_c_xor3(a, b, c);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_base_inl_defd_xor2(mk_sl_cui_uint8_pt const a, mk_sl_cui_uint8_pct const b) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has) && (mk_lib_crypto_mode_base_inl_defd_len == 16))
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_sse() && ((((mk_lang_types_uintptr_t)(a)) & 0xf) == 0) && ((((mk_lang_types_uintptr_t)(b)) & 0xf) == 0))
	{
		mk_lib_crypto_mode_base_inl_defd_x86_xor2(a, b);
	}
	else
	#endif
	{
		mk_lib_crypto_mode_base_inl_defd_c_xor2(a, b);
	}
}


#include "mk_lib_crypto_mode_base_inl_defu.h"


#undef mk_lib_crypto_mode_base_t_name
#undef mk_lib_crypto_mode_base_t_len
