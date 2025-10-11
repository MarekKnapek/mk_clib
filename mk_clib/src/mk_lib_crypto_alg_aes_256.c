#ifndef mk_include_guard_mk_lib_crypto_alg_aes_256_c
#define mk_include_guard_mk_lib_crypto_alg_aes_256_c
#include "mk_lib_crypto_alg_aes_256.h"

/* NIST FIPS PUB 197 */

#include "mk_lang_alignas.h"
#include "mk_lang_alignof.h"
#include "mk_lang_arch.h"
#include "mk_lang_assert.h"
#include "mk_lang_compiler.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_msvc.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_aes_portable_256.h"
#include "mk_lib_crypto_alg_aes_x86_aesni_256.h"
#include "mk_lib_crypto_alg_aes_x86_vaes256_256.h"
#include "mk_lib_crypto_alg_aes_x86_vaes512_256.h"
#include "mk_lib_crypto_bitops_bulk.h"


#define mk_lib_crypto_alg_aes_256_x86_vaes512_test_ct ( \
	( \
		(mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) || \
		(mk_lang_compiler_is_at_least_gcc(11, 1)) || \
		0 \
	) && \
	( \
		(mk_lang_arch_is_x8632) || \
		(mk_lang_arch_is_x8664) || \
		0 \
	) && \
	(mk_lang_alignas_has) && \
	(mk_lang_alignof_has) && \
1)
#define mk_lib_crypto_alg_aes_256_x86_vaes512_test_st ( \
	(!mk_lang_constexpr_is_constant_evaluated_test) && \
	(mk_lang_cpuid_has_sse2()) && \
	(mk_lang_cpuid_has_avx()) && \
	(mk_lang_cpuid_has_avx512_f()) && \
	(mk_lang_cpuid_has_vaes()) && \
1)
#define mk_lib_crypto_alg_aes_256_x86_vaes512_test_rt ( \
	(!mk_lang_constexpr_is_constant_evaluated_test) && \
	(rem >= 4) && \
	((((mk_lang_types_uintptr_t)(schedule)) & 0xf) == 0) && \
	((((mk_lang_types_uintptr_t)(in)) & 0x3f) == 0) && \
	((((mk_lang_types_uintptr_t)(out)) & 0x3f) == 0) && \
	(mk_lang_cpuid_has_sse2()) && \
	(mk_lang_cpuid_has_avx()) && \
	(mk_lang_cpuid_has_avx512_f()) && \
	(mk_lang_cpuid_has_vaes()) && \
1)

#define mk_lib_crypto_alg_aes_256_x86_vaes256_test_ct ( \
	( \
		(mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) || \
		(mk_lang_compiler_is_at_least_gcc(11, 1)) || \
		0 \
	) && \
	( \
		(mk_lang_arch_is_x8632) || \
		(mk_lang_arch_is_x8664) || \
		0 \
	) && \
	(mk_lang_alignas_has) && \
	(mk_lang_alignof_has) && \
1)
#define mk_lib_crypto_alg_aes_256_x86_vaes256_test_st ( \
	(!mk_lang_constexpr_is_constant_evaluated_test) && \
	(mk_lang_cpuid_has_sse2()) && \
	(mk_lang_cpuid_has_avx()) && \
	(mk_lang_cpuid_has_avx2()) && \
	(mk_lang_cpuid_has_vaes()) && \
1)
#define mk_lib_crypto_alg_aes_256_x86_vaes256_test_rt ( \
	(!mk_lang_constexpr_is_constant_evaluated_test) && \
	(rem >= 2) && \
	((((mk_lang_types_uintptr_t)(schedule)) & 0xf) == 0) && \
	((((mk_lang_types_uintptr_t)(in)) & 0x1f) == 0) && \
	((((mk_lang_types_uintptr_t)(out)) & 0x1f) == 0) && \
	(mk_lang_cpuid_has_sse2()) && \
	(mk_lang_cpuid_has_avx()) && \
	(mk_lang_cpuid_has_avx2()) && \
	(mk_lang_cpuid_has_vaes()) && \
1)

#define mk_lib_crypto_alg_aes_256_x86_aesni_test_ct ( \
	( \
		(mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) || \
		(mk_lang_compiler_is_at_least_gcc(6, 1)) || \
		0 \
	) && \
	( \
		(mk_lang_arch_is_x8632) || \
		(mk_lang_arch_is_x8664) || \
		0 \
	) && \
	(mk_lang_alignas_has) && \
	(mk_lang_alignof_has) && \
1)
#define mk_lib_crypto_alg_aes_256_x86_aesni_test_st ( \
	(!mk_lang_constexpr_is_constant_evaluated_test) && \
	(mk_lang_cpuid_has_sse2()) && \
	(mk_lang_cpuid_has_aesni()) && \
1)
#define mk_lib_crypto_alg_aes_256_x86_aesni_test_rt ( \
	(!mk_lang_constexpr_is_constant_evaluated_test) && \
	(rem >= 1) && \
	((((mk_lang_types_uintptr_t)(schedule)) & 0xf) == 0) && \
	((((mk_lang_types_uintptr_t)(in)) & 0xf) == 0) && \
	((((mk_lang_types_uintptr_t)(out)) & 0xf) == 0) && \
	(mk_lang_cpuid_has_sse2()) && \
	(mk_lang_cpuid_has_aesni()) && \
1)
#define mk_lib_crypto_alg_aes_256_x86_aesni_test_rt2 ( \
	(!mk_lang_constexpr_is_constant_evaluated_test) && \
	((((mk_lang_types_uintptr_t)(key)) & 0xf) == 0) && \
	((((mk_lang_types_uintptr_t)(schedule)) & 0xf) == 0) && \
	(mk_lang_cpuid_has_sse2()) && \
	(mk_lang_cpuid_has_aesni()) && \
1)


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_256_schedule_encrypt(mk_lib_crypto_alg_aes_256_schedule_pct const schedule, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	#if mk_lib_crypto_alg_aes_256_x86_vaes512_test_ct
	mk_lang_types_bool_t st_x86_vaes512 mk_lang_constexpr_init;
	#endif
	#if mk_lib_crypto_alg_aes_256_x86_vaes256_test_ct
	mk_lang_types_bool_t st_x86_vaes256 mk_lang_constexpr_init;
	#endif
	#if mk_lib_crypto_alg_aes_256_x86_aesni_test_ct
	mk_lang_types_bool_t st_x86_aesni mk_lang_constexpr_init;
	#endif
	mk_lib_crypto_alg_aes_256_msg_pct in mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_256_msg_pt out mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks >= 0 && nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_aes_256_msg_len_v);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	#if mk_lib_crypto_alg_aes_256_x86_vaes512_test_ct
	st_x86_vaes512 = mk_lib_crypto_alg_aes_256_x86_vaes512_test_st;
	#endif
	#if mk_lib_crypto_alg_aes_256_x86_vaes256_test_ct
	st_x86_vaes256 = mk_lib_crypto_alg_aes_256_x86_vaes256_test_st;
	#endif
	#if mk_lib_crypto_alg_aes_256_x86_aesni_test_ct
	st_x86_aesni = mk_lib_crypto_alg_aes_256_x86_aesni_test_st;
	#endif
	in = input;
	out = output;
	rem = nblocks;
	while(rem != 0)
	{
		#if mk_lib_crypto_alg_aes_256_x86_vaes512_test_ct
		if(st_x86_vaes512 && mk_lib_crypto_alg_aes_256_x86_vaes512_test_rt)
		{
			mk_lib_crypto_alg_aes_x86_vaes512_256_schedule_pct sch mk_lang_constexpr_init;
			mk_lib_crypto_alg_aes_x86_vaes512_256_msg_pct i mk_lang_constexpr_init;
			mk_lib_crypto_alg_aes_x86_vaes512_256_msg_pt o mk_lang_constexpr_init;
			mk_lang_types_usize_t n mk_lang_constexpr_init;

			mk_lang_static_assert(mk_lang_countof(sch->m_data.m_uint8s) == mk_lang_countof(schedule->m_data.m_uint8s));
			mk_lang_static_assert(sizeof(*sch) == sizeof(*schedule));
			mk_lang_static_assert(mk_lang_countof(i->m_data.m_uint8s) == mk_lang_countof(in->m_data.m_uint8s));
			mk_lang_static_assert(sizeof(*i) == sizeof(*in));

			sch = ((mk_lib_crypto_alg_aes_x86_vaes512_256_schedule_pct)(schedule));
			i = ((mk_lib_crypto_alg_aes_x86_vaes512_256_msg_pct)(in));
			o = ((mk_lib_crypto_alg_aes_x86_vaes512_256_msg_pt)(out));
			n = (rem / 4) * 4;
			mk_lib_crypto_alg_aes_x86_vaes512_256_schedule_encrypt(sch, i, o, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		#if mk_lib_crypto_alg_aes_256_x86_vaes256_test_ct
		if(st_x86_vaes256 && mk_lib_crypto_alg_aes_256_x86_vaes256_test_rt)
		{
			mk_lib_crypto_alg_aes_x86_vaes256_256_schedule_pct sch mk_lang_constexpr_init;
			mk_lib_crypto_alg_aes_x86_vaes256_256_msg_pct i mk_lang_constexpr_init;
			mk_lib_crypto_alg_aes_x86_vaes256_256_msg_pt o mk_lang_constexpr_init;
			mk_lang_types_usize_t n mk_lang_constexpr_init;

			mk_lang_static_assert(mk_lang_countof(sch->m_data.m_uint8s) == mk_lang_countof(schedule->m_data.m_uint8s));
			mk_lang_static_assert(sizeof(*sch) == sizeof(*schedule));
			mk_lang_static_assert(mk_lang_countof(i->m_data.m_uint8s) == mk_lang_countof(in->m_data.m_uint8s));
			mk_lang_static_assert(sizeof(*i) == sizeof(*in));

			sch = ((mk_lib_crypto_alg_aes_x86_vaes256_256_schedule_pct)(schedule));
			i = ((mk_lib_crypto_alg_aes_x86_vaes256_256_msg_pct)(in));
			o = ((mk_lib_crypto_alg_aes_x86_vaes256_256_msg_pt)(out));
			#if mk_lib_crypto_alg_aes_256_x86_vaes512_test_ct
			if(st_x86_vaes512 && (((mk_lang_types_uintptr_t)(in)) & 0x3f) == (((mk_lang_types_uintptr_t)(out)) & 0x3f))
			{
				n = 2;
			}
			else
			#endif
			{
				n = (rem / 2) * 2;
			}
			mk_lib_crypto_alg_aes_x86_vaes256_256_schedule_encrypt(sch, i, o, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		#if mk_lib_crypto_alg_aes_256_x86_aesni_test_ct
		if(st_x86_aesni && mk_lib_crypto_alg_aes_256_x86_aesni_test_rt)
		{
			mk_lib_crypto_alg_aes_x86_aesni_256_schedule_pct sch mk_lang_constexpr_init;
			mk_lib_crypto_alg_aes_x86_aesni_256_msg_pct i mk_lang_constexpr_init;
			mk_lib_crypto_alg_aes_x86_aesni_256_msg_pt o mk_lang_constexpr_init;
			mk_lang_types_usize_t n mk_lang_constexpr_init;

			mk_lang_static_assert(mk_lang_countof(sch->m_data.m_uint8s) == mk_lang_countof(schedule->m_data.m_uint8s));
			mk_lang_static_assert(sizeof(*sch) == sizeof(*schedule));
			mk_lang_static_assert(mk_lang_countof(i->m_data.m_uint8s) == mk_lang_countof(in->m_data.m_uint8s));
			mk_lang_static_assert(sizeof(*i) == sizeof(*in));

			sch = ((mk_lib_crypto_alg_aes_x86_aesni_256_schedule_pct)(schedule));
			i = ((mk_lib_crypto_alg_aes_x86_aesni_256_msg_pct)(in));
			o = ((mk_lib_crypto_alg_aes_x86_aesni_256_msg_pt)(out));
			#if mk_lib_crypto_alg_aes_256_x86_vaes256_test_ct
			if(st_x86_vaes256 && (((mk_lang_types_uintptr_t)(in)) & 0x1f) == (((mk_lang_types_uintptr_t)(out)) & 0x1f))
			{
				n = 1;
			}
			else
			#endif
			{
				n = (rem / 1) * 1;
			}
			mk_lib_crypto_alg_aes_x86_aesni_256_schedule_encrypt(sch, i, o, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		#include "mk_lang_warning_msvc_push_c4127.h"
		if(!mk_lang_constexpr_is_constant_evaluated_test)
		#include "mk_lang_warning_msvc_pop.h"
		{
			mk_lib_crypto_alg_aes_portable_256_schedule_pct sch mk_lang_constexpr_init;
			mk_lib_crypto_alg_aes_portable_256_msg_pct i mk_lang_constexpr_init;
			mk_lib_crypto_alg_aes_portable_256_msg_pt o mk_lang_constexpr_init;
			mk_lang_types_usize_t n mk_lang_constexpr_init;

			mk_lang_static_assert(mk_lang_countof(sch->m_data.m_uint8s) == mk_lang_countof(schedule->m_data.m_uint8s));
			mk_lang_static_assert(sizeof(*sch) == sizeof(*schedule));
			mk_lang_static_assert(mk_lang_countof(i->m_data.m_uint8s) == mk_lang_countof(in->m_data.m_uint8s));
			mk_lang_static_assert(sizeof(*i) == sizeof(*in));

			sch = ((mk_lib_crypto_alg_aes_portable_256_schedule_pct)(schedule));
			i = ((mk_lib_crypto_alg_aes_portable_256_msg_pct)(in));
			o = ((mk_lib_crypto_alg_aes_portable_256_msg_pt)(out));
			n = (rem / 1) * 1;
			mk_lib_crypto_alg_aes_portable_256_schedule_encrypt(sch, i, o, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		{
			#include "mk_lang_warning_clang_push_unreachable_code.h"
			mk_lib_crypto_alg_aes_portable_256_schedule_t sch mk_lang_constexpr_init;
			mk_lib_crypto_alg_aes_portable_256_msg_t m mk_lang_constexpr_init;
			mk_lang_types_usize_t n mk_lang_constexpr_init;
			mk_lang_types_usize_t i mk_lang_constexpr_init;

			mk_lang_static_assert(mk_lang_countof(sch.m_data.m_uint8s) == mk_lang_countof(schedule->m_data.m_uint8s));
			mk_lang_static_assert(mk_lang_countof(m.m_data.m_uint8s) == mk_lang_countof(in->m_data.m_uint8s));

			mk_lib_crypto_bitops_bulk_uint8_240_memcpy(&sch.m_data.m_uint8s[0], &schedule->m_data.m_uint8s[0]);
			n = (rem / 1) * 1;
			for(i = 0; i != n; ++i)
			{
				mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&m.m_data.m_uint8s[0], &in[i].m_data.m_uint8s[0]);
				mk_lib_crypto_alg_aes_portable_256_schedule_encrypt(&sch, &m, &m, 1);
				mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&out[i].m_data.m_uint8s[0], &m.m_data.m_uint8s[0]);
			}
			in += n;
			out += n;
			rem -= n;
			#include "mk_lang_warning_clang_pop.h"
		}
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_256_schedule_decrypt(mk_lib_crypto_alg_aes_256_schedule_pct const schedule, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	#if mk_lib_crypto_alg_aes_256_x86_vaes512_test_ct
	mk_lang_types_bool_t st_x86_vaes512 mk_lang_constexpr_init;
	#endif
	#if mk_lib_crypto_alg_aes_256_x86_vaes256_test_ct
	mk_lang_types_bool_t st_x86_vaes256 mk_lang_constexpr_init;
	#endif
	#if mk_lib_crypto_alg_aes_256_x86_aesni_test_ct
	mk_lang_types_bool_t st_x86_aesni mk_lang_constexpr_init;
	#endif
	mk_lib_crypto_alg_aes_256_msg_pct in mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_256_msg_pt out mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks >= 0 && nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_aes_256_msg_len_v);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	#if mk_lib_crypto_alg_aes_256_x86_vaes512_test_ct
	st_x86_vaes512 = mk_lib_crypto_alg_aes_256_x86_vaes512_test_st;
	#endif
	#if mk_lib_crypto_alg_aes_256_x86_vaes256_test_ct
	st_x86_vaes256 = mk_lib_crypto_alg_aes_256_x86_vaes256_test_st;
	#endif
	#if mk_lib_crypto_alg_aes_256_x86_aesni_test_ct
	st_x86_aesni = mk_lib_crypto_alg_aes_256_x86_aesni_test_st;
	#endif
	in = input;
	out = output;
	rem = nblocks;
	while(rem != 0)
	{
		#if mk_lib_crypto_alg_aes_256_x86_vaes512_test_ct
		if(st_x86_vaes512 && mk_lib_crypto_alg_aes_256_x86_vaes512_test_rt)
		{
			mk_lib_crypto_alg_aes_x86_vaes512_256_schedule_pct sch mk_lang_constexpr_init;
			mk_lib_crypto_alg_aes_x86_vaes512_256_msg_pct i mk_lang_constexpr_init;
			mk_lib_crypto_alg_aes_x86_vaes512_256_msg_pt o mk_lang_constexpr_init;
			mk_lang_types_usize_t n mk_lang_constexpr_init;

			mk_lang_static_assert(mk_lang_countof(sch->m_data.m_uint8s) == mk_lang_countof(schedule->m_data.m_uint8s));
			mk_lang_static_assert(sizeof(*sch) == sizeof(*schedule));
			mk_lang_static_assert(mk_lang_countof(i->m_data.m_uint8s) == mk_lang_countof(in->m_data.m_uint8s));
			mk_lang_static_assert(sizeof(*i) == sizeof(*in));

			sch = ((mk_lib_crypto_alg_aes_x86_vaes512_256_schedule_pct)(schedule));
			i = ((mk_lib_crypto_alg_aes_x86_vaes512_256_msg_pct)(in));
			o = ((mk_lib_crypto_alg_aes_x86_vaes512_256_msg_pt)(out));
			n = (rem / 4) * 4;
			mk_lib_crypto_alg_aes_x86_vaes512_256_schedule_decrypt(sch, i, o, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		#if mk_lib_crypto_alg_aes_256_x86_vaes256_test_ct
		if(st_x86_vaes256 && mk_lib_crypto_alg_aes_256_x86_vaes256_test_rt)
		{
			mk_lib_crypto_alg_aes_x86_vaes256_256_schedule_pct sch mk_lang_constexpr_init;
			mk_lib_crypto_alg_aes_x86_vaes256_256_msg_pct i mk_lang_constexpr_init;
			mk_lib_crypto_alg_aes_x86_vaes256_256_msg_pt o mk_lang_constexpr_init;
			mk_lang_types_usize_t n mk_lang_constexpr_init;

			mk_lang_static_assert(mk_lang_countof(sch->m_data.m_uint8s) == mk_lang_countof(schedule->m_data.m_uint8s));
			mk_lang_static_assert(sizeof(*sch) == sizeof(*schedule));
			mk_lang_static_assert(mk_lang_countof(i->m_data.m_uint8s) == mk_lang_countof(in->m_data.m_uint8s));
			mk_lang_static_assert(sizeof(*i) == sizeof(*in));

			sch = ((mk_lib_crypto_alg_aes_x86_vaes256_256_schedule_pct)(schedule));
			i = ((mk_lib_crypto_alg_aes_x86_vaes256_256_msg_pct)(in));
			o = ((mk_lib_crypto_alg_aes_x86_vaes256_256_msg_pt)(out));
			#if mk_lib_crypto_alg_aes_256_x86_vaes512_test_ct
			if(st_x86_vaes512 && (((mk_lang_types_uintptr_t)(in)) & 0x3f) == (((mk_lang_types_uintptr_t)(out)) & 0x3f))
			{
				n = 2;
			}
			else
			#endif
			{
				n = (rem / 2) * 2;
			}
			mk_lib_crypto_alg_aes_x86_vaes256_256_schedule_decrypt(sch, i, o, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		#if mk_lib_crypto_alg_aes_256_x86_aesni_test_ct
		if(st_x86_aesni && mk_lib_crypto_alg_aes_256_x86_aesni_test_rt)
		{
			mk_lib_crypto_alg_aes_x86_aesni_256_schedule_pct sch mk_lang_constexpr_init;
			mk_lib_crypto_alg_aes_x86_aesni_256_msg_pct i mk_lang_constexpr_init;
			mk_lib_crypto_alg_aes_x86_aesni_256_msg_pt o mk_lang_constexpr_init;
			mk_lang_types_usize_t n mk_lang_constexpr_init;

			mk_lang_static_assert(mk_lang_countof(sch->m_data.m_uint8s) == mk_lang_countof(schedule->m_data.m_uint8s));
			mk_lang_static_assert(sizeof(*sch) == sizeof(*schedule));
			mk_lang_static_assert(mk_lang_countof(i->m_data.m_uint8s) == mk_lang_countof(in->m_data.m_uint8s));
			mk_lang_static_assert(sizeof(*i) == sizeof(*in));

			sch = ((mk_lib_crypto_alg_aes_x86_aesni_256_schedule_pct)(schedule));
			i = ((mk_lib_crypto_alg_aes_x86_aesni_256_msg_pct)(in));
			o = ((mk_lib_crypto_alg_aes_x86_aesni_256_msg_pt)(out));
			#if mk_lib_crypto_alg_aes_256_x86_vaes256_test_ct
			if(st_x86_vaes256 && (((mk_lang_types_uintptr_t)(in)) & 0x1f) == (((mk_lang_types_uintptr_t)(out)) & 0x1f))
			{
				n = 1;
			}
			else
			#endif
			{
				n = (rem / 1) * 1;
			}
			mk_lib_crypto_alg_aes_x86_aesni_256_schedule_decrypt(sch, i, o, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		#include "mk_lang_warning_msvc_push_c4127.h"
		if(!mk_lang_constexpr_is_constant_evaluated_test)
		#include "mk_lang_warning_msvc_pop.h"
		{
			mk_lib_crypto_alg_aes_portable_256_schedule_pct sch mk_lang_constexpr_init;
			mk_lib_crypto_alg_aes_portable_256_msg_pct i mk_lang_constexpr_init;
			mk_lib_crypto_alg_aes_portable_256_msg_pt o mk_lang_constexpr_init;
			mk_lang_types_usize_t n mk_lang_constexpr_init;

			mk_lang_static_assert(mk_lang_countof(sch->m_data.m_uint8s) == mk_lang_countof(schedule->m_data.m_uint8s));
			mk_lang_static_assert(sizeof(*sch) == sizeof(*schedule));
			mk_lang_static_assert(mk_lang_countof(i->m_data.m_uint8s) == mk_lang_countof(in->m_data.m_uint8s));
			mk_lang_static_assert(sizeof(*i) == sizeof(*in));

			sch = ((mk_lib_crypto_alg_aes_portable_256_schedule_pct)(schedule));
			i = ((mk_lib_crypto_alg_aes_portable_256_msg_pct)(in));
			o = ((mk_lib_crypto_alg_aes_portable_256_msg_pt)(out));
			n = (rem / 1) * 1;
			mk_lib_crypto_alg_aes_portable_256_schedule_decrypt(sch, i, o, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		{
			#include "mk_lang_warning_clang_push_unreachable_code.h"
			mk_lib_crypto_alg_aes_portable_256_schedule_t sch mk_lang_constexpr_init;
			mk_lib_crypto_alg_aes_portable_256_msg_t m mk_lang_constexpr_init;
			mk_lang_types_usize_t n mk_lang_constexpr_init;
			mk_lang_types_usize_t i mk_lang_constexpr_init;

			mk_lang_static_assert(mk_lang_countof(sch.m_data.m_uint8s) == mk_lang_countof(schedule->m_data.m_uint8s));
			mk_lang_static_assert(mk_lang_countof(m.m_data.m_uint8s) == mk_lang_countof(in->m_data.m_uint8s));

			mk_lib_crypto_bitops_bulk_uint8_240_memcpy(&sch.m_data.m_uint8s[0], &schedule->m_data.m_uint8s[0]);
			n = (rem / 1) * 1;
			for(i = 0; i != n; ++i)
			{
				mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&m.m_data.m_uint8s[0], &in[i].m_data.m_uint8s[0]);
				mk_lib_crypto_alg_aes_portable_256_schedule_decrypt(&sch, &m, &m, 1);
				mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&out[i].m_data.m_uint8s[0], &m.m_data.m_uint8s[0]);
			}
			in += n;
			out += n;
			rem -= n;
			#include "mk_lang_warning_clang_pop.h"
		}
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_256_expand_enc(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lang_assert(key);
	mk_lang_assert(schedule);

	#if mk_lib_crypto_alg_aes_256_x86_aesni_test_ct
	if(mk_lib_crypto_alg_aes_256_x86_aesni_test_rt2)
	{
		mk_lib_crypto_alg_aes_x86_aesni_256_key_pct k mk_lang_constexpr_init;
		mk_lib_crypto_alg_aes_x86_aesni_256_schedule_pt sch mk_lang_constexpr_init;

		mk_lang_static_assert(mk_lang_countof(k->m_data.m_uint8s) == mk_lang_countof(key->m_data.m_uint8s));
		mk_lang_static_assert(sizeof(*k) == sizeof(*key));
		mk_lang_static_assert(mk_lang_countof(sch->m_data.m_uint8s) == mk_lang_countof(schedule->m_data.m_uint8s));
		mk_lang_static_assert(sizeof(*sch) == sizeof(*schedule));

		#include "mk_lang_warning_clang_push_cast_align.h"
		k = ((mk_lib_crypto_alg_aes_x86_aesni_256_key_pct)(key));
		sch = ((mk_lib_crypto_alg_aes_x86_aesni_256_schedule_pt)(schedule));
		#include "mk_lang_warning_clang_pop.h"
		mk_lib_crypto_alg_aes_x86_aesni_256_expand_enc(k, sch);
	}
	else
	#endif
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lib_crypto_alg_aes_portable_256_key_pct k mk_lang_constexpr_init;
		mk_lib_crypto_alg_aes_portable_256_schedule_pt sch mk_lang_constexpr_init;

		mk_lang_static_assert(mk_lang_countof(k->m_data.m_uint8s) == mk_lang_countof(key->m_data.m_uint8s));
		mk_lang_static_assert(sizeof(*k) == sizeof(*key));
		mk_lang_static_assert(mk_lang_countof(sch->m_data.m_uint8s) == mk_lang_countof(schedule->m_data.m_uint8s));
		mk_lang_static_assert(sizeof(*sch) == sizeof(*schedule));

		k = ((mk_lib_crypto_alg_aes_portable_256_key_pct)(key));
		sch = ((mk_lib_crypto_alg_aes_portable_256_schedule_pt)(schedule));
		mk_lib_crypto_alg_aes_portable_256_expand_enc(k, sch);
	}
	else
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
		mk_lib_crypto_alg_aes_portable_256_key_t portable_key mk_lang_constexpr_init;
		mk_lib_crypto_alg_aes_portable_256_schedule_t portable_schedule mk_lang_constexpr_init;
		mk_lang_static_assert(mk_lang_countof(key->m_data.m_uint8s) == mk_lang_countof(portable_key.m_data.m_uint8s));
		mk_lang_static_assert(mk_lang_countof(schedule->m_data.m_uint8s) == mk_lang_countof(portable_schedule.m_data.m_uint8s));
		mk_lib_crypto_bitops_bulk_uint8_32_memcpy(&portable_key.m_data.m_uint8s[0], &key->m_data.m_uint8s[0]);
		mk_lib_crypto_alg_aes_portable_256_expand_enc(&portable_key, &portable_schedule);
		mk_lib_crypto_bitops_bulk_uint8_240_memcpy(&schedule->m_data.m_uint8s[0], &portable_schedule.m_data.m_uint8s[0]);
		#include "mk_lang_warning_clang_pop.h"
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_256_expand_dec(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lang_assert(key);
	mk_lang_assert(schedule);

	#if mk_lib_crypto_alg_aes_256_x86_aesni_test_ct
	if(mk_lib_crypto_alg_aes_256_x86_aesni_test_rt2)
	{
		mk_lib_crypto_alg_aes_x86_aesni_256_key_pct k mk_lang_constexpr_init;
		mk_lib_crypto_alg_aes_x86_aesni_256_schedule_pt sch mk_lang_constexpr_init;

		mk_lang_static_assert(mk_lang_countof(k->m_data.m_uint8s) == mk_lang_countof(key->m_data.m_uint8s));
		mk_lang_static_assert(sizeof(*k) == sizeof(*key));
		mk_lang_static_assert(mk_lang_countof(sch->m_data.m_uint8s) == mk_lang_countof(schedule->m_data.m_uint8s));
		mk_lang_static_assert(sizeof(*sch) == sizeof(*schedule));

		#include "mk_lang_warning_clang_push_cast_align.h"
		k = ((mk_lib_crypto_alg_aes_x86_aesni_256_key_pct)(key));
		sch = ((mk_lib_crypto_alg_aes_x86_aesni_256_schedule_pt)(schedule));
		#include "mk_lang_warning_clang_pop.h"
		mk_lib_crypto_alg_aes_x86_aesni_256_expand_dec(k, sch);
	}
	else
	#endif
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lib_crypto_alg_aes_portable_256_key_pct k mk_lang_constexpr_init;
		mk_lib_crypto_alg_aes_portable_256_schedule_pt sch mk_lang_constexpr_init;

		mk_lang_static_assert(mk_lang_countof(k->m_data.m_uint8s) == mk_lang_countof(key->m_data.m_uint8s));
		mk_lang_static_assert(sizeof(*k) == sizeof(*key));
		mk_lang_static_assert(mk_lang_countof(sch->m_data.m_uint8s) == mk_lang_countof(schedule->m_data.m_uint8s));
		mk_lang_static_assert(sizeof(*sch) == sizeof(*schedule));

		k = ((mk_lib_crypto_alg_aes_portable_256_key_pct)(key));
		sch = ((mk_lib_crypto_alg_aes_portable_256_schedule_pt)(schedule));
		mk_lib_crypto_alg_aes_portable_256_expand_dec(k, sch);
	}
	else
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
		mk_lib_crypto_alg_aes_portable_256_key_t portable_key mk_lang_constexpr_init;
		mk_lib_crypto_alg_aes_portable_256_schedule_t portable_schedule mk_lang_constexpr_init;
		mk_lang_static_assert(mk_lang_countof(key->m_data.m_uint8s) == mk_lang_countof(portable_key.m_data.m_uint8s));
		mk_lang_static_assert(mk_lang_countof(schedule->m_data.m_uint8s) == mk_lang_countof(portable_schedule.m_data.m_uint8s));
		mk_lib_crypto_bitops_bulk_uint8_32_memcpy(&portable_key.m_data.m_uint8s[0], &key->m_data.m_uint8s[0]);
		mk_lib_crypto_alg_aes_portable_256_expand_dec(&portable_key, &portable_schedule);
		mk_lib_crypto_bitops_bulk_uint8_240_memcpy(&schedule->m_data.m_uint8s[0], &portable_schedule.m_data.m_uint8s[0]);
		#include "mk_lang_warning_clang_pop.h"
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


#endif
