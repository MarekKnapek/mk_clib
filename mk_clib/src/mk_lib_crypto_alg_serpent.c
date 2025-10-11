#ifndef mk_include_guard_mk_lib_crypto_alg_serpent_c
#define mk_include_guard_mk_lib_crypto_alg_serpent_c
#include "mk_lib_crypto_alg_serpent.h"

#include "mk_lang_alignas.h"
#include "mk_lang_alignof.h"
#include "mk_lang_arch.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_compiler.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_llong.h"
#include "mk_lang_msvc.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"


#define mk_lib_crypto_alg_serpent_word_bits 32
#define mk_lib_crypto_alg_serpent_word_bytes (32 / mk_lang_charbit)
#define mk_lib_crypto_alg_serpent_msg_words (mk_lib_crypto_alg_serpent_msg_len_d / mk_lib_crypto_alg_serpent_word_bytes)
#define mk_lib_crypto_alg_serpent_key_words (mk_lib_crypto_alg_serpent_key_len_d / mk_lib_crypto_alg_serpent_word_bytes)
#define mk_lib_crypto_alg_serpent_sbox_count 8


#define mk_lib_crypto_alg_serpent_is_64_ct \
( \
	(mk_lang_llong_has) && \
	1 \
)
#define mk_lib_crypto_alg_serpent_is_64_rt \
( \
	(rem >= 2) && \
	(mk_lang_true) \
)
#define mk_lib_crypto_alg_serpent_is_sse2_ct \
( \
	( \
		(mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) || \
		(mk_lang_compiler_is_at_least_gcc(4, 8)) || \
		0 \
	) && \
	( \
		(mk_lang_arch_is_x8632) || \
		(mk_lang_arch_is_x8664) || \
		0 \
	) && \
	( \
		(mk_lang_alignas_has) && \
		(mk_lang_alignof_has) && \
		1 \
	) \
)
#define mk_lib_crypto_alg_serpent_is_sse2_rt \
( \
	(!mk_lang_constexpr_is_constant_evaluated_test) && \
	(rem >= 4) && \
	((((mk_lang_types_uintptr_t)(in)) & 0xf) == 0) && \
	((((mk_lang_types_uintptr_t)(out)) & 0xf) == 0) && \
	(mk_lang_cpuid_has_sse2()) && \
	(mk_lang_true) \
)
#define mk_lib_crypto_alg_serpent_is_avx2_ct \
( \
	( \
		(mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) || \
		(mk_lang_compiler_is_at_least_gcc(4, 8)) || \
		0 \
	) && \
	( \
		(mk_lang_arch_is_x8632) || \
		(mk_lang_arch_is_x8664) || \
		0 \
	) && \
	( \
		(mk_lang_alignas_has) && \
		(mk_lang_alignof_has) && \
		1 \
	) \
)
#define mk_lib_crypto_alg_serpent_is_avx2_rt \
( \
	(!mk_lang_constexpr_is_constant_evaluated_test) && \
	(rem >= 8) && \
	((((mk_lang_types_uintptr_t)(in)) & 0x1f) == 0) && \
	((((mk_lang_types_uintptr_t)(out)) & 0x1f) == 0) && \
	(mk_lang_cpuid_has_avx()) && \
	(mk_lang_cpuid_has_avx2()) && \
	(mk_lang_true) \
)
#define mk_lib_crypto_alg_serpent_is_avx512_ct \
( \
	( \
		(mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) || \
		(mk_lang_compiler_is_at_least_gcc(5, 1)) || \
		0 \
	) && \
	( \
		(mk_lang_arch_is_x8632) || \
		(mk_lang_arch_is_x8664) || \
		0 \
	) && \
	( \
		(mk_lang_alignas_has) && \
		(mk_lang_alignof_has) && \
		1 \
	) \
)
#define mk_lib_crypto_alg_serpent_is_avx512_rt \
( \
	(!mk_lang_constexpr_is_constant_evaluated_test) && \
	(rem >= 16) && \
	((((mk_lang_types_uintptr_t)(in)) & 0x3f) == 0) && \
	((((mk_lang_types_uintptr_t)(out)) & 0x3f) == 0) && \
	(mk_lang_cpuid_has_sse2()) && \
	(mk_lang_cpuid_has_avx512_f()) && \
	(mk_lang_true) \
)


#include "mk_lib_crypto_alg_serpent_32.h"
#include "mk_lib_crypto_alg_serpent_32.c"

#if mk_lib_crypto_alg_serpent_is_64_ct
#include "mk_lib_crypto_alg_serpent_64.h"
#endif

#if mk_lib_crypto_alg_serpent_is_sse2_ct
#include "mk_lib_crypto_alg_serpent_sse2.h"
#endif

#if mk_lib_crypto_alg_serpent_is_avx2_ct
#include "mk_lib_crypto_alg_serpent_avx2.h"
#endif

#if mk_lib_crypto_alg_serpent_is_avx512_ct
#include "mk_lib_crypto_alg_serpent_avx512.h"
#endif


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32c_encrypt_blocks(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_sint_t m mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_lib_crypto_alg_serpent_base_schedule_t sch mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_crypto_alg_serpent_base_msg_t msgs[1] mk_lang_constexpr_init;

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_serpent_msg_len_v);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	m = mk_lang_countof(schedule->m_data.m_msgs);
	for(j = 0; j != m; ++j)
	{
		mk_sl_cui_uint8_memcpy_fn(&sch.m_data.m_msgs[j].m_data.m_uint8s[0], &schedule->m_data.m_msgs[j].m_data.m_uint8s[0], mk_lib_crypto_alg_serpent_msg_len_v);
	}
	n = nblocks;
	for(i = 0; i != n; ++i)
	{
		m = mk_lang_countof(msgs);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_memcpy_fn(&msgs[j].m_data.m_uint8s[0], &input[i * m + j].m_data.m_uint8s[0], mk_lib_crypto_alg_serpent_msg_len_v);
		}
		mk_lib_crypto_alg_serpent_32_encrypt_blocks(&sch, &msgs[0], &msgs[0], n);
		m = mk_lang_countof(msgs);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_memcpy_fn(&output[i * m + j].m_data.m_uint8s[0], &msgs[j].m_data.m_uint8s[0], mk_lib_crypto_alg_serpent_msg_len_v);
		}
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32c_decrypt_blocks(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_sint_t m mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_lib_crypto_alg_serpent_base_schedule_t sch mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_crypto_alg_serpent_base_msg_t msgs[1] mk_lang_constexpr_init;

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_serpent_msg_len_v);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	m = mk_lang_countof(schedule->m_data.m_msgs);
	for(j = 0; j != m; ++j)
	{
		mk_sl_cui_uint8_memcpy_fn(&sch.m_data.m_msgs[j].m_data.m_uint8s[0], &schedule->m_data.m_msgs[j].m_data.m_uint8s[0], mk_lib_crypto_alg_serpent_msg_len_v);
	}
	n = nblocks;
	for(i = 0; i != n; ++i)
	{
		m = mk_lang_countof(msgs);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_memcpy_fn(&msgs[j].m_data.m_uint8s[0], &input[i * m + j].m_data.m_uint8s[0], mk_lib_crypto_alg_serpent_msg_len_v);
		}
		mk_lib_crypto_alg_serpent_32_decrypt_blocks(&sch, &msgs[0], &msgs[0], n);
		m = mk_lang_countof(msgs);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_memcpy_fn(&output[i * m + j].m_data.m_uint8s[0], &msgs[j].m_data.m_uint8s[0], mk_lib_crypto_alg_serpent_msg_len_v);
		}
	}
}

#if mk_lib_crypto_alg_serpent_is_64_ct
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64c_encrypt_blocks(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_sint_t m mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_lib_crypto_alg_serpent_base_schedule_t sch mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_crypto_alg_serpent_base_msg_t msgs[2] mk_lang_constexpr_init;

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_serpent_msg_len_v);
	mk_lang_assert(nblocks % mk_lang_countof(msgs) == 0);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	m = mk_lang_countof(schedule->m_data.m_msgs);
	for(j = 0; j != m; ++j)
	{
		mk_sl_cui_uint8_memcpy_fn(&sch.m_data.m_msgs[j].m_data.m_uint8s[0], &schedule->m_data.m_msgs[j].m_data.m_uint8s[0], mk_lib_crypto_alg_serpent_msg_len_v);
	}
	m = mk_lang_countof(msgs);
	n = nblocks / m;
	for(i = 0; i != n; ++i)
	{
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_memcpy_fn(&msgs[j].m_data.m_uint8s[0], &input[i * m + j].m_data.m_uint8s[0], mk_lib_crypto_alg_serpent_msg_len_v);
		}
		mk_lib_crypto_alg_serpent_64_encrypt_blocks(&sch, &msgs[0], &msgs[0], m);
		m = mk_lang_countof(msgs);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_memcpy_fn(&output[i * m + j].m_data.m_uint8s[0], &msgs[j].m_data.m_uint8s[0], mk_lib_crypto_alg_serpent_msg_len_v);
		}
	}
}
#endif

#if mk_lib_crypto_alg_serpent_is_64_ct
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64c_decrypt_blocks(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_sint_t m mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_lib_crypto_alg_serpent_base_schedule_t sch mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_crypto_alg_serpent_base_msg_t msgs[2] mk_lang_constexpr_init;

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_serpent_msg_len_v);
	mk_lang_assert(nblocks % mk_lang_countof(msgs) == 0);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	m = mk_lang_countof(schedule->m_data.m_msgs);
	for(j = 0; j != m; ++j)
	{
		mk_sl_cui_uint8_memcpy_fn(&sch.m_data.m_msgs[j].m_data.m_uint8s[0], &schedule->m_data.m_msgs[j].m_data.m_uint8s[0], mk_lib_crypto_alg_serpent_msg_len_v);
	}
	m = mk_lang_countof(msgs);
	n = nblocks / m;
	for(i = 0; i != n; ++i)
	{
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_memcpy_fn(&msgs[j].m_data.m_uint8s[0], &input[i * m + j].m_data.m_uint8s[0], mk_lib_crypto_alg_serpent_msg_len_v);
		}
		mk_lib_crypto_alg_serpent_64_decrypt_blocks(&sch, &msgs[0], &msgs[0], m);
		m = mk_lang_countof(msgs);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_memcpy_fn(&output[i * m + j].m_data.m_uint8s[0], &msgs[j].m_data.m_uint8s[0], mk_lib_crypto_alg_serpent_msg_len_v);
		}
	}
}
#endif

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_schedule_encrypt_impl(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lib_crypto_alg_serpent_msg_pct in mk_lang_constexpr_init;
	mk_lib_crypto_alg_serpent_msg_pt out mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_serpent_msg_len_v);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	in = input;
	out = output;
	rem = nblocks;
	while(rem != 0)
	{
		#if mk_lib_crypto_alg_serpent_is_avx512_ct
		if(mk_lib_crypto_alg_serpent_is_avx512_rt)
		{
			n = (rem / 16) * 16;
			mk_lib_crypto_alg_serpent_avx512_encrypt_blocks(&schedule->m_data.m_base, &in->m_data.m_base, &out->m_data.m_base, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		#if mk_lib_crypto_alg_serpent_is_avx2_ct
		if(mk_lib_crypto_alg_serpent_is_avx2_rt)
		{
			#if mk_lib_crypto_alg_serpent_is_avx512_ct
			n = 8;
			#else
			n = (rem / 8) * 8;
			#endif
			mk_lib_crypto_alg_serpent_avx2_encrypt_blocks(&schedule->m_data.m_base, &in->m_data.m_base, &out->m_data.m_base, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		#if mk_lib_crypto_alg_serpent_is_sse2_ct
		if(mk_lib_crypto_alg_serpent_is_sse2_rt)
		{
			#if mk_lib_crypto_alg_serpent_is_avx2_ct
			n = 4;
			#else
			n = (rem / 4) * 4;
			#endif
			mk_lib_crypto_alg_serpent_sse2_encrypt_blocks(&schedule->m_data.m_base, &in->m_data.m_base, &out->m_data.m_base, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		#if mk_lib_crypto_alg_serpent_is_64_ct
		if(mk_lib_crypto_alg_serpent_is_64_rt)
		{
			#if mk_lib_crypto_alg_serpent_is_sse2_ct
			n = 2;
			#else
			n = (rem / 2) * 2;
			#endif
			#include "mk_lang_warning_msvc_push_c4127.h"
			if(!mk_lang_constexpr_is_constant_evaluated_test)
			#include "mk_lang_warning_msvc_pop.h"
			{
				mk_lib_crypto_alg_serpent_64_encrypt_blocks(&schedule->m_data.m_base, &in->m_data.m_base, &out->m_data.m_base, n);
			}
			else
			{
				mk_lib_crypto_alg_serpent_64c_encrypt_blocks(schedule, in, out, n);
			}
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		{
			#if mk_lib_crypto_alg_serpent_is_64_ct
			n = 1;
			#else
			n = (rem / 1) * 1;
			#endif
			#include "mk_lang_warning_msvc_push_c4127.h"
			if(!mk_lang_constexpr_is_constant_evaluated_test)
			#include "mk_lang_warning_msvc_pop.h"
			{
				mk_lib_crypto_alg_serpent_32_encrypt_blocks(&schedule->m_data.m_base, &in->m_data.m_base, &out->m_data.m_base, n);
			}
			else
			{
				mk_lib_crypto_alg_serpent_32c_encrypt_blocks(schedule, in, out, n);
			}
			in += n;
			out += n;
			rem -= n;
		}
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_schedule_decrypt_impl(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lib_crypto_alg_serpent_msg_pct in mk_lang_constexpr_init;
	mk_lib_crypto_alg_serpent_msg_pt out mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_serpent_msg_len_v);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	in = input;
	out = output;
	rem = nblocks;
	while(rem != 0)
	{
		#if mk_lib_crypto_alg_serpent_is_avx512_ct
		if(mk_lib_crypto_alg_serpent_is_avx512_rt)
		{
			n = (rem / 16) * 16;
			mk_lib_crypto_alg_serpent_avx512_decrypt_blocks(&schedule->m_data.m_base, &in->m_data.m_base, &out->m_data.m_base, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		#if mk_lib_crypto_alg_serpent_is_avx2_ct
		if(mk_lib_crypto_alg_serpent_is_avx2_rt)
		{
			#if mk_lib_crypto_alg_serpent_is_avx512_ct
			n = 8;
			#else
			n = (rem / 8) * 8;
			#endif
			mk_lib_crypto_alg_serpent_avx2_decrypt_blocks(&schedule->m_data.m_base, &in->m_data.m_base, &out->m_data.m_base, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		#if mk_lib_crypto_alg_serpent_is_sse2_ct
		if(mk_lib_crypto_alg_serpent_is_sse2_rt)
		{
			#if mk_lib_crypto_alg_serpent_is_avx2_ct
			n = 4;
			#else
			n = (rem / 4) * 4;
			#endif
			mk_lib_crypto_alg_serpent_sse2_decrypt_blocks(&schedule->m_data.m_base, &in->m_data.m_base, &out->m_data.m_base, n);
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		#if mk_lib_crypto_alg_serpent_is_64_ct
		if(mk_lib_crypto_alg_serpent_is_64_rt)
		{
			#if mk_lib_crypto_alg_serpent_is_sse2_ct
			n = 2;
			#else
			n = (rem / 2) * 2;
			#endif
			#include "mk_lang_warning_msvc_push_c4127.h"
			if(!mk_lang_constexpr_is_constant_evaluated_test)
			#include "mk_lang_warning_msvc_pop.h"
			{
				mk_lib_crypto_alg_serpent_64_decrypt_blocks(&schedule->m_data.m_base, &in->m_data.m_base, &out->m_data.m_base, n);
			}
			else
			{
				mk_lib_crypto_alg_serpent_64c_decrypt_blocks(schedule, in, out, n);
			}
			in += n;
			out += n;
			rem -= n;
		}
		else
		#endif
		{
			#if mk_lib_crypto_alg_serpent_is_64_ct
			n = 1;
			#else
			n = (rem / 1) * 1;
			#endif
			#include "mk_lang_warning_msvc_push_c4127.h"
			if(!mk_lang_constexpr_is_constant_evaluated_test)
			#include "mk_lang_warning_msvc_pop.h"
			{
				mk_lib_crypto_alg_serpent_32_decrypt_blocks(&schedule->m_data.m_base, &in->m_data.m_base, &out->m_data.m_base, n);
			}
			else
			{
				mk_lib_crypto_alg_serpent_32c_decrypt_blocks(schedule, in, out, n);
			}
			in += n;
			out += n;
			rem -= n;
		}
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_substitute_enc(mk_lang_types_sint_t const sbox, mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t a mk_lang_constexpr_init;
	mk_sl_cui_uint32_t b mk_lang_constexpr_init;
	mk_sl_cui_uint32_t c mk_lang_constexpr_init;
	mk_sl_cui_uint32_t d mk_lang_constexpr_init;
	mk_sl_cui_uint32_t e mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt pa mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt pb mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt pc mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt pd mk_lang_constexpr_init;
	mk_sl_cui_uint32_pt pe mk_lang_constexpr_init;

	mk_lang_assert(sbox >= 0);
	mk_lang_assert(sbox < 8);
	mk_lang_assert(msg);

	pa = &a;
	pb = &b;
	pc = &c;
	pd = &d;
	pe = &e;
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lib_crypto_alg_serpent_32_lload(&msg->m_data.m_base, pa, pb, pc, pd);
	}
	else
	{
		mk_lib_crypto_alg_serpent_base_msg_t msg_base mk_lang_constexpr_init;
		mk_sl_cui_uint8_memcpy_fn(&msg_base.m_data.m_uint8s[0], &msg->m_data.m_uint8s[0], mk_lib_crypto_alg_serpent_msg_len_v);
		mk_lib_crypto_alg_serpent_32_lload(&msg_base, pa, pb, pc, pd);
	}
	switch(sbox)
	{
		case 0: mk_lib_crypto_alg_serpent_32_enc_0(&pa, &pb, &pc, &pd, &pe); break;
		case 1: mk_lib_crypto_alg_serpent_32_enc_1(&pa, &pb, &pc, &pd, &pe); break;
		case 2: mk_lib_crypto_alg_serpent_32_enc_2(&pa, &pb, &pc, &pd, &pe); break;
		case 3: mk_lib_crypto_alg_serpent_32_enc_3(&pa, &pb, &pc, &pd, &pe); break;
		case 4: mk_lib_crypto_alg_serpent_32_enc_4(&pa, &pb, &pc, &pd, &pe); break;
		case 5: mk_lib_crypto_alg_serpent_32_enc_5(&pa, &pb, &pc, &pd, &pe); break;
		case 6: mk_lib_crypto_alg_serpent_32_enc_6(&pa, &pb, &pc, &pd, &pe); break;
		case 7: mk_lib_crypto_alg_serpent_32_enc_7(&pa, &pb, &pc, &pd, &pe); break;
	}
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lib_crypto_alg_serpent_32_sstore(&msg->m_data.m_base, pa, pb, pc, pd);
	}
	else
	{
		mk_lib_crypto_alg_serpent_base_msg_t msg_base mk_lang_constexpr_init;
		mk_lib_crypto_alg_serpent_32_sstore(&msg_base, pa, pb, pc, pd);
		mk_sl_cui_uint8_memcpy_fn(&msg->m_data.m_uint8s[0], &msg_base.m_data.m_uint8s[0], mk_lib_crypto_alg_serpent_msg_len_v);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_expand_w(mk_lib_crypto_alg_serpent_key_pct const k, mk_lang_types_sint_t const idx, mk_sl_cui_uint32_pt const w) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_sl_cui_uint32_t const phi = mk_sl_cui_uint32_c(0x9e3779b9ul);

	mk_sl_cui_uint32_t ti mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;

	mk_lang_assert(k);
	mk_lang_assert(idx >= 0);
	mk_lang_assert(idx < (mk_lib_crypto_alg_serpent_nr + 1) * mk_lib_crypto_alg_serpent_msg_words);
	mk_lang_assert(w);

	mk_sl_cui_uint32_from_bi_sint(&ti, &idx);
	mk_sl_uint_convert_32_8_le_to_big(&ta, &k->m_data.m_uint8s[(mk_lib_crypto_alg_serpent_key_words - 8) * mk_lib_crypto_alg_serpent_word_bytes]);
	mk_sl_uint_convert_32_8_le_to_big(&tb, &k->m_data.m_uint8s[(mk_lib_crypto_alg_serpent_key_words - 5) * mk_lib_crypto_alg_serpent_word_bytes]);
	mk_sl_uint_convert_32_8_le_to_big(&tc, &k->m_data.m_uint8s[(mk_lib_crypto_alg_serpent_key_words - 3) * mk_lib_crypto_alg_serpent_word_bytes]);
	mk_sl_uint_convert_32_8_le_to_big(&td, &k->m_data.m_uint8s[(mk_lib_crypto_alg_serpent_key_words - 1) * mk_lib_crypto_alg_serpent_word_bytes]);
	mk_sl_cui_uint32_xor2(&ta, &td);
	mk_sl_cui_uint32_xor2(&tb, &phi);
	mk_sl_cui_uint32_xor2(&tc, &ti);
	mk_sl_cui_uint32_xor2(&ta, &tb);
	mk_sl_cui_uint32_xor2(&ta, &tc);
	mk_sl_cui_uint32_rotl3(&ta, 11, w);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_expand(mk_lib_crypto_alg_serpent_key_pct const key, mk_lib_crypto_alg_serpent_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_alg_serpent_key_t k mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t m mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_sl_cui_uint32_t w mk_lang_constexpr_init;
	mk_lang_types_sint_t sbox_idx mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(schedule);

	k = *key;
	n = mk_lib_crypto_alg_serpent_nr + 1;
	for(i = 0; i != n; ++i)
	{
		m = mk_lib_crypto_alg_serpent_msg_words;
		for(j = 0; j != m; ++j)
		{
			mk_lib_crypto_alg_serpent_expand_w(&k, i * mk_lib_crypto_alg_serpent_msg_words + j, &w);
			mk_sl_cui_uint8_memmov_fn(&k.m_data.m_uint8s[0], &k.m_data.m_uint8s[mk_lib_crypto_alg_serpent_word_bytes], mk_lib_crypto_alg_serpent_key_len_d - mk_lib_crypto_alg_serpent_word_bytes);
			mk_sl_uint_convert_32_8_le_to_sml(&w, &k.m_data.m_uint8s[mk_lib_crypto_alg_serpent_key_len_d - mk_lib_crypto_alg_serpent_word_bytes]);
		}
		mk_sl_cui_uint8_memcpy_fn(&schedule->m_data.m_msgs[i].m_data.m_uint8s[0], &k.m_data.m_uint8s[mk_lib_crypto_alg_serpent_key_len_d - mk_lib_crypto_alg_serpent_msg_len_d], mk_lib_crypto_alg_serpent_msg_len_d);
		sbox_idx = (((mk_lib_crypto_alg_serpent_nr * mk_lib_crypto_alg_serpent_sbox_count) + 3) - i) % mk_lib_crypto_alg_serpent_sbox_count;
		mk_lib_crypto_alg_serpent_substitute_enc(sbox_idx, &schedule->m_data.m_msgs[i]);
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_serpent_schedule_encrypt(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_serpent_msg_len_v);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	mk_lib_crypto_alg_serpent_schedule_encrypt_impl(schedule, input, output, nblocks);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_serpent_schedule_decrypt(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_serpent_msg_len_v);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	mk_lib_crypto_alg_serpent_schedule_decrypt_impl(schedule, input, output, nblocks);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_serpent_expand_enc(mk_lib_crypto_alg_serpent_key_pct const key, mk_lib_crypto_alg_serpent_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_alg_serpent_expand(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_serpent_expand_dec(mk_lib_crypto_alg_serpent_key_pct const key, mk_lib_crypto_alg_serpent_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_alg_serpent_expand(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_serpent_encrypt(mk_lib_crypto_alg_serpent_key_pct const key, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_serpent_schedule_t schedule mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_alg_serpent_expand_enc(key, &schedule);
	mk_lib_crypto_alg_serpent_schedule_encrypt(&schedule, input, output, 1);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_serpent_decrypt(mk_lib_crypto_alg_serpent_key_pct const key, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_serpent_schedule_t schedule mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_alg_serpent_expand_dec(key, &schedule);
	mk_lib_crypto_alg_serpent_schedule_decrypt(&schedule, input, output, 1);
}


#endif
