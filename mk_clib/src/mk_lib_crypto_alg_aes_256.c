#include "mk_lib_crypto_alg_aes_256.h"


/* NIST FIPS PUB 197 */


#include "mk_lang_alignas.h"
#include "mk_lang_alignof.h"
#include "mk_lang_arch.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_gnuc.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_msvc.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_aes_portable_256.h"
#include "mk_lib_crypto_alg_aes_x86_aesni_256.h"
#include "mk_lib_crypto_alg_aes_x86_vaes256_256.h"
#include "mk_lib_crypto_alg_aes_x86_vaes512_256.h"
#include "mk_sl_uint8.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_256_schedule_encrypt(mk_lib_crypto_alg_aes_256_schedule_pct const schedule, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_256_msg_pct in mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_256_msg_pt out mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks >= 0 && nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_aes_256_msg_len_m);

	in = input;
	out = output;
	rem = nblocks;
	while(rem != 0)
	{
		#if (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 || mk_lang_gnuc_is_at_least(11, 1)) && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && mk_lang_alignas_has && mk_lang_alignof_has
		if(!mk_lang_constexpr_is_constant_evaluated_test && rem >= 4 && (((mk_lang_types_uintptr_t)(input)) & 0x3f) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0x3f) == 0 && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_avx() && mk_lang_cpuid_has_avx512_f() && mk_lang_cpuid_has_vaes())
		{
			n = (rem / 4) * 4;
			mk_lib_crypto_alg_aes_x86_vaes512_256_schedule_encrypt(schedule, in, out, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		#if (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 || mk_lang_gnuc_is_at_least(11, 1)) && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && mk_lang_alignas_has && mk_lang_alignof_has
		if(!mk_lang_constexpr_is_constant_evaluated_test && rem >= 2 && (((mk_lang_types_uintptr_t)(input)) & 0x1f) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0x1f) == 0 && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_avx() && mk_lang_cpuid_has_avx2() && mk_lang_cpuid_has_avx512_vl() && mk_lang_cpuid_has_vaes())
		{
			n = (rem / 2) * 2;
			mk_lib_crypto_alg_aes_x86_vaes256_256_schedule_encrypt(schedule, in, out, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		#if (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 || mk_lang_gnuc_is_at_least(6, 1)) && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && mk_lang_alignas_has && mk_lang_alignof_has
		if(!mk_lang_constexpr_is_constant_evaluated_test && (((mk_lang_types_uintptr_t)(input)) & 0xf) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0xf) == 0 && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aesni())
		{
			n = (rem / 1) * 1;
			mk_lib_crypto_alg_aes_x86_aesni_256_schedule_encrypt(schedule, in, out, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		{
			n = (rem / 1) * 1;
			mk_lib_crypto_alg_aes_portable_256_schedule_encrypt(schedule, in, out, n);
			in += n;
			out += n;
			rem -= n;
		}
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_256_schedule_decrypt(mk_lib_crypto_alg_aes_256_schedule_pct const schedule, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_256_msg_pct in mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_256_msg_pt out mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks >= 0 && nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_aes_256_msg_len_m);

	in = input;
	out = output;
	rem = nblocks;
	while(rem != 0)
	{
		#if (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 || mk_lang_gnuc_is_at_least(11, 1)) && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && mk_lang_alignas_has && mk_lang_alignof_has
		if(!mk_lang_constexpr_is_constant_evaluated_test && rem >= 4 && (((mk_lang_types_uintptr_t)(input)) & 0x3f) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0x3f) == 0 && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_avx() && mk_lang_cpuid_has_avx512_f() && mk_lang_cpuid_has_vaes())
		{
			n = (rem / 4) * 4;
			mk_lib_crypto_alg_aes_x86_vaes512_256_schedule_decrypt(schedule, in, out, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		#if (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 || mk_lang_gnuc_is_at_least(11, 1)) && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && mk_lang_alignas_has && mk_lang_alignof_has
		if(!mk_lang_constexpr_is_constant_evaluated_test && rem >= 2 && (((mk_lang_types_uintptr_t)(input)) & 0x1f) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0x1f) == 0 && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_avx() && mk_lang_cpuid_has_avx2() && mk_lang_cpuid_has_avx512_vl() && mk_lang_cpuid_has_vaes())
		{
			n = (rem / 2) * 2;
			mk_lib_crypto_alg_aes_x86_vaes256_256_schedule_decrypt(schedule, in, out, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		#if (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 || mk_lang_gnuc_is_at_least(6, 1)) && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && mk_lang_alignas_has && mk_lang_alignof_has
		if(!mk_lang_constexpr_is_constant_evaluated_test && (((mk_lang_types_uintptr_t)(input)) & 0xf) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0xf) == 0 && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aesni())
		{
			n = (rem / 1) * 1;
			mk_lib_crypto_alg_aes_x86_aesni_256_schedule_decrypt(schedule, in, out, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		{
			n = (rem / 1) * 1;
			mk_lib_crypto_alg_aes_portable_256_schedule_decrypt(schedule, in, out, n);
			in += n;
			out += n;
			rem -= n;
		}
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_256_expand_enc(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lang_assert(key);
	mk_lang_assert(schedule);

	#if (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 || mk_lang_gnuc_is_at_least(6, 1)) && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && mk_lang_alignas_has && mk_lang_alignof_has
	if(!mk_lang_constexpr_is_constant_evaluated_test && (((mk_lang_types_uintptr_t)(key)) & 0xf) == 0 && (((mk_lang_types_uintptr_t)(schedule)) & 0xf) == 0 && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aesni())
	{
		mk_lib_crypto_alg_aes_x86_aesni_256_expand_enc(key, schedule);
	}
	else
	#endif
	{
		mk_lib_crypto_alg_aes_portable_256_expand_enc(key, schedule);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_256_expand_dec(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lang_assert(key);
	mk_lang_assert(schedule);

	#if (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 || mk_lang_gnuc_is_at_least(6, 1)) && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && mk_lang_alignas_has && mk_lang_alignof_has
	if(!mk_lang_constexpr_is_constant_evaluated_test && (((mk_lang_types_uintptr_t)(key)) & 0xf) == 0 && (((mk_lang_types_uintptr_t)(schedule)) & 0xf) == 0 && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aesni())
	{
		mk_lib_crypto_alg_aes_x86_aesni_256_expand_dec(key, schedule);
	}
	else
	#endif
	{
		mk_lib_crypto_alg_aes_portable_256_expand_dec(key, schedule);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_256_encrypt(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_256_schedule_t schedule mk_lang_constexpr_init;

	mk_lib_crypto_alg_aes_256_expand_enc(key, &schedule);
	mk_lib_crypto_alg_aes_256_schedule_encrypt(&schedule, input, output, 1);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_256_decrypt(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_256_schedule_t schedule mk_lang_constexpr_init;

	mk_lib_crypto_alg_aes_256_expand_dec(key, &schedule);
	mk_lib_crypto_alg_aes_256_schedule_decrypt(&schedule, input, output, 1);
}
