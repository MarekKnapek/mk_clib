#include "mk_lib_crypto_alg_serpent.h"

#include "mk_lang_alignas.h"
#include "mk_lang_arch.h"
#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"

#define mk_lib_crypto_mode_base_t_name mk_lib_crypto_alg_serpent
#define mk_lib_crypto_mode_base_t_len mk_lib_crypto_alg_serpent_msg_len_m
#include "mk_lib_crypto_mode_base_inl_fileh.h"
#include "mk_lib_crypto_mode_base_inl_filec.h"

#define mk_lang_memmove_t_name mk_lib_crypto_alg_serpent_memmove_u8
#define mk_lang_memmove_t_base mk_sl_cui_uint8
#include "mk_lang_memmove_inl_fileh.h"
#include "mk_lang_memmove_inl_filec.h"

#define mk_lang_memcpy_t_name mk_lib_crypto_alg_serpent_memcpy_u8
#define mk_lang_memcpy_t_base mk_sl_cui_uint8
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"


#define mk_lib_crypto_alg_serpent_word_bits 32
#define mk_lib_crypto_alg_serpent_word_bytes (32 / mk_lang_charbit)
#define mk_lib_crypto_alg_serpent_msg_words (mk_lib_crypto_alg_serpent_msg_len_m / mk_lib_crypto_alg_serpent_word_bytes)
#define mk_lib_crypto_alg_serpent_key_words (mk_lib_crypto_alg_serpent_key_len_m / mk_lib_crypto_alg_serpent_word_bytes)
#define mk_lib_crypto_alg_serpent_sbox_count 8


#if(mk_lang_llong_has)

#include "mk_lib_crypto_alg_serpent_inl_64.h"

#endif

#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (defined _MSC_FULL_VER && _MSC_FULL_VER >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has))

#include "mk_lib_crypto_alg_serpent_inl_sse2.h"

#endif

#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (defined _MSC_FULL_VER && _MSC_FULL_VER >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has))

#include "mk_lib_crypto_alg_serpent_inl_avx2.h"

#endif

#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (defined _MSC_FULL_VER && _MSC_FULL_VER >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has))

#include "mk_lib_crypto_alg_serpent_inl_avx512.h"

#endif

#include "mk_lib_crypto_alg_serpent_inl_portable.h"

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_expand_w(mk_lib_crypto_alg_serpent_key_pct const k, int const idx, mk_sl_cui_uint32_pt const w) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_sl_cui_uint32_t const s_phi = mk_sl_cui_uint32_c(0x9e3779b9ul);

	mk_sl_cui_uint32_t ti mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;

	mk_lang_assert(k);
	mk_lang_assert(idx >= 0 && idx < (mk_lib_crypto_alg_serpent_nr + 1) * mk_lib_crypto_alg_serpent_msg_words);
	mk_lang_assert(w);

	mk_sl_cui_uint32_from_bi_sint(&ti, &idx);
	mk_sl_uint_32_from_8_le(&ta, &k->m_data.m_uint8s[(mk_lib_crypto_alg_serpent_key_words - 8) * mk_lib_crypto_alg_serpent_word_bytes]);
	mk_sl_uint_32_from_8_le(&tb, &k->m_data.m_uint8s[(mk_lib_crypto_alg_serpent_key_words - 5) * mk_lib_crypto_alg_serpent_word_bytes]);
	mk_sl_uint_32_from_8_le(&tc, &k->m_data.m_uint8s[(mk_lib_crypto_alg_serpent_key_words - 3) * mk_lib_crypto_alg_serpent_word_bytes]);
	mk_sl_uint_32_from_8_le(&td, &k->m_data.m_uint8s[(mk_lib_crypto_alg_serpent_key_words - 1) * mk_lib_crypto_alg_serpent_word_bytes]);
	mk_sl_cui_uint32_xor2(&ta, &td);
	mk_sl_cui_uint32_xor2(&tb, &s_phi);
	mk_sl_cui_uint32_xor2(&tc, &ti);
	mk_sl_cui_uint32_xor2(&ta, &tb);
	mk_sl_cui_uint32_xor2(&ta, &tc);
	mk_sl_cui_uint32_rotl3(&ta, 11, w);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_expand(mk_lib_crypto_alg_serpent_key_pct const key, mk_lib_crypto_alg_serpent_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_alg_serpent_key_t k mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	int j mk_lang_constexpr_init;
	mk_sl_cui_uint32_t w mk_lang_constexpr_init;
	int sbox_idx mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(schedule);

	k = *key;
	for(i = 0; i != mk_lib_crypto_alg_serpent_nr + 1; ++i)
	{
		for(j = 0; j != mk_lib_crypto_alg_serpent_msg_words; ++j)
		{
			mk_lib_crypto_alg_serpent_expand_w(&k, i * mk_lib_crypto_alg_serpent_msg_words + j, &w);
			mk_lib_crypto_alg_serpent_memmove_u8_fn(&k.m_data.m_uint8s[0], &k.m_data.m_uint8s[mk_lib_crypto_alg_serpent_word_bytes], mk_lib_crypto_alg_serpent_key_len_m - mk_lib_crypto_alg_serpent_word_bytes);
			mk_sl_uint_32_to_8_le(&w, &k.m_data.m_uint8s[mk_lib_crypto_alg_serpent_key_len_m - mk_lib_crypto_alg_serpent_word_bytes]);
		}
		mk_lib_crypto_alg_serpent_memcpy_u8_fn(&schedule->m_data.m_msgs[i].m_data.m_uint8s[0], &k.m_data.m_uint8s[mk_lib_crypto_alg_serpent_key_len_m - mk_lib_crypto_alg_serpent_msg_len_m], mk_lib_crypto_alg_serpent_msg_len_m);
		sbox_idx = (((mk_lib_crypto_alg_serpent_nr * mk_lib_crypto_alg_serpent_sbox_count) + 3) - i) % mk_lib_crypto_alg_serpent_sbox_count;
		mk_lib_crypto_alg_serpent_portable_substitute_enc(sbox_idx, &schedule->m_data.m_msgs[i]);
	}
}


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_serpent_schedule_encrypt(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (defined _MSC_FULL_VER && _MSC_FULL_VER >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has))
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(nblocks >= 16 && (((mk_lang_types_uintptr_t)(input)) & 0x3f) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0x3f) == 0 && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_avx512_f())
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && nblocks >= 16 && (((mk_lang_types_uintptr_t)(input)) & 0x3f) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0x3f) == 0 && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_avx512_f())
	#endif
	{
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		n = (nblocks / 16) * 16;
		mk_lib_crypto_alg_serpent_schedule_encrypt_avx512(schedule, input, output, n);
		mk_lib_crypto_alg_serpent_schedule_encrypt_portable(schedule, input + n, output + n, nblocks - n);
	}
	else
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(nblocks >= 8 && (((mk_lang_types_uintptr_t)(input)) & 0x1f) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0x1f) == 0 && mk_lang_cpuid_has_avx() && mk_lang_cpuid_has_avx2())
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && nblocks >= 8 && (((mk_lang_types_uintptr_t)(input)) & 0x1f) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0x1f) == 0 && mk_lang_cpuid_has_avx() && mk_lang_cpuid_has_avx2())
	#endif
	{
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		n = (nblocks / 8) * 8;
		mk_lib_crypto_alg_serpent_schedule_encrypt_avx2(schedule, input, output, n);
		mk_lib_crypto_alg_serpent_schedule_encrypt_portable(schedule, input + n, output + n, nblocks - n);
	}
	else
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(nblocks >= 4 && (((mk_lang_types_uintptr_t)(input)) & 0xf) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0xf) == 0 && mk_lang_cpuid_has_sse2())
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && nblocks >= 4 && (((mk_lang_types_uintptr_t)(input)) & 0xf) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0xf) == 0 && mk_lang_cpuid_has_sse2())
	#endif
	{
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		n = (nblocks / 4) * 4;
		mk_lib_crypto_alg_serpent_schedule_encrypt_sse2(schedule, input, output, n);
		mk_lib_crypto_alg_serpent_schedule_encrypt_portable(schedule, input + n, output + n, nblocks - n);
	}
	else
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(nblocks >= 2 && (((mk_lang_types_uintptr_t)(input)) & 0x7) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0x7) == 0)
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && nblocks >= 2 && (((mk_lang_types_uintptr_t)(input)) & 0x7) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0x7) == 0)
	#endif
	{
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		n = (nblocks / 2) * 2;
		mk_lib_crypto_alg_serpent_schedule_encrypt_64(schedule, input, output, n);
		mk_lib_crypto_alg_serpent_schedule_encrypt_portable(schedule, input + n, output + n, nblocks - n);
	}
	else
	#endif
	{
		mk_lib_crypto_alg_serpent_schedule_encrypt_portable(schedule, input, output, nblocks);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_serpent_schedule_decrypt(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (defined _MSC_FULL_VER && _MSC_FULL_VER >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has))
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(nblocks >= 16 && (((mk_lang_types_uintptr_t)(input)) & 0x3f) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0x3f) == 0 && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_avx512_f())
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && nblocks >= 16 && (((mk_lang_types_uintptr_t)(input)) & 0x3f) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0x3f) == 0 && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_avx512_f())
	#endif
	{
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		n = (nblocks / 16) * 16;
		mk_lib_crypto_alg_serpent_schedule_decrypt_avx512(schedule, input, output, n);
		mk_lib_crypto_alg_serpent_schedule_decrypt_portable(schedule, input + n, output + n, nblocks - n);
	}
	else
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(nblocks >= 8 && (((mk_lang_types_uintptr_t)(input)) & 0x1f) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0x1f) == 0 && mk_lang_cpuid_has_avx() && mk_lang_cpuid_has_avx2())
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && nblocks >= 8 && (((mk_lang_types_uintptr_t)(input)) & 0x1f) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0x1f) == 0 && mk_lang_cpuid_has_avx() && mk_lang_cpuid_has_avx2())
	#endif
	{
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		n = (nblocks / 8) * 8;
		mk_lib_crypto_alg_serpent_schedule_decrypt_avx2(schedule, input, output, n);
		mk_lib_crypto_alg_serpent_schedule_decrypt_portable(schedule, input + n, output + n, nblocks - n);
	}
	else
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(nblocks >= 4 && (((mk_lang_types_uintptr_t)(input)) & 0xf) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0xf) == 0 && mk_lang_cpuid_has_sse2())
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && nblocks >= 4 && (((mk_lang_types_uintptr_t)(input)) & 0xf) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0xf) == 0 && mk_lang_cpuid_has_sse2())
	#endif
	{
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		n = (nblocks / 4) * 4;
		mk_lib_crypto_alg_serpent_schedule_decrypt_sse2(schedule, input, output, n);
		mk_lib_crypto_alg_serpent_schedule_decrypt_portable(schedule, input + n, output + n, nblocks - n);
	}
	else
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(nblocks >= 2 && (((mk_lang_types_uintptr_t)(input)) & 0x7) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0x7) == 0)
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && nblocks >= 2 && (((mk_lang_types_uintptr_t)(input)) & 0x7) == 0 && (((mk_lang_types_uintptr_t)(output)) & 0x7) == 0)
	#endif
	{
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		n = (nblocks / 2) * 2;
		mk_lib_crypto_alg_serpent_schedule_decrypt_64(schedule, input, output, n);
		mk_lib_crypto_alg_serpent_schedule_decrypt_portable(schedule, input + n, output + n, nblocks - n);
	}
	else
	#endif
	{
		mk_lib_crypto_alg_serpent_schedule_decrypt_portable(schedule, input, output, nblocks);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_serpent_expand_enc(mk_lib_crypto_alg_serpent_key_pct const key, mk_lib_crypto_alg_serpent_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_alg_serpent_expand(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_serpent_expand_dec(mk_lib_crypto_alg_serpent_key_pct const key, mk_lib_crypto_alg_serpent_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_alg_serpent_expand(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_serpent_encrypt(mk_lib_crypto_alg_serpent_key_pct const key, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_serpent_schedule_t schedule mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_alg_serpent_expand_enc(key, &schedule);
	mk_lib_crypto_alg_serpent_schedule_encrypt(&schedule, input, output, 1);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_serpent_decrypt(mk_lib_crypto_alg_serpent_key_pct const key, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_serpent_schedule_t schedule mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_alg_serpent_expand_dec(key, &schedule);
	mk_lib_crypto_alg_serpent_schedule_decrypt(&schedule, input, output, 1);
}
