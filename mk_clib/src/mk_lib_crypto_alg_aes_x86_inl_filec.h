/* NIST FIPS PUB 197 */


#include "mk_lang_alignas.h"
#include "mk_lang_alignof.h"
#include "mk_lang_arch.h"
#include "mk_lang_assert.h"
#include "mk_lang_attribute.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_compiler.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_msvc.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_pow2.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


#include "mk_lib_crypto_alg_aes_x86_inl_defd.h"


#if (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 || mk_lang_compiler_is_at_least_gcc(6, 1)) && (mk_lang_arch_is_x8632 || mk_lang_arch_is_x8664) && mk_lang_alignas_has && mk_lang_alignof_has


#include <emmintrin.h> /* SSE2 _mm_shuffle_epi32 _mm_slli_si128 _mm_xor_si128 */
#include <wmmintrin.h> /* AES _mm_aeskeygenassist_si128 */
#if mk_lang_compiler_is_at_least_clang(1, 0)
#include <intrin.h> /* clang-cl */
#endif


#if mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 && !mk_lang_compiler_is_at_least_clang(1, 0)
#pragma intrinsic(_mm_shuffle_epi32)
#pragma intrinsic(_mm_slli_si128)
#pragma intrinsic(_mm_xor_si128)

#pragma intrinsic(_mm_aeskeygenassist_si128)
#endif


#if mk_lib_crypto_alg_aes_x86_inl_defd_bits == 128


mk_lang_nodiscard static mk_lang_inline __m128i mk_lang_attribute_target("sse2") mk_lib_crypto_alg_aes_x86_inl_defd_assist_128(__m128i const a, __m128i const b) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;

	mk_lang_assert(mk_lang_cpuid_has_sse2());

	ta = a;
	tb = b;
	tb = _mm_shuffle_epi32(tb, 0xff);
	tc = _mm_slli_si128(ta, 0x04);
	ta = _mm_xor_si128(ta, tc);
	tc = _mm_slli_si128(tc, 0x04);
	ta = _mm_xor_si128(ta, tc);
	tc = _mm_slli_si128(tc, 0x04);
	ta = _mm_xor_si128(ta, tc);
	ta = _mm_xor_si128(ta, tb);
	return ta;
}


#elif mk_lib_crypto_alg_aes_x86_inl_defd_bits == 192


static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("sse2") mk_lib_crypto_alg_aes_x86_inl_defd_assist_192(__m128i* const ta, __m128i* const tb, __m128i* const tc) mk_lang_noexcept
{
	__m128i td;

	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	*tb = _mm_shuffle_epi32(*tb, 0x55);
	td = _mm_slli_si128(*ta, 0x04);
	*ta = _mm_xor_si128(*ta ,td);
	td = _mm_slli_si128(td, 0x04);
	*ta = _mm_xor_si128(*ta, td);
	td = _mm_slli_si128(td, 0x04);
	*ta = _mm_xor_si128(*ta, td);
	*ta = _mm_xor_si128(*ta, *tb);
	*tb = _mm_shuffle_epi32(*ta, 0xff);
	td = _mm_slli_si128(*tc, 0x04);
	*tc = _mm_xor_si128(*tc, td);
	*tc = _mm_xor_si128(*tc, *tb);
}


#elif mk_lib_crypto_alg_aes_x86_inl_defd_bits == 256


static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("sse2") mk_lib_crypto_alg_aes_x86_inl_defd_assist_256_a(__m128i* const ta, __m128i* const tb) mk_lang_noexcept
{
	__m128i tc;

	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	*tb = _mm_shuffle_epi32(*tb, 0xff);
	tc = _mm_slli_si128(*ta, 0x04);
	*ta = _mm_xor_si128(*ta, tc);
	tc = _mm_slli_si128(tc, 0x04);
	*ta = _mm_xor_si128(*ta, tc);
	tc = _mm_slli_si128(tc, 0x04);
	*ta = _mm_xor_si128(*ta, tc);
	*ta = _mm_xor_si128(*ta, *tb);
}

static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("sse2,aes") mk_lib_crypto_alg_aes_x86_inl_defd_assist_256_b(__m128i* const ta, __m128i* const tb) mk_lang_noexcept
{
	__m128i tc;
	__m128i td;

	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_aesni());

	tc = _mm_aeskeygenassist_si128(*ta, 0x00);
	td = _mm_shuffle_epi32(tc, 0xaa);
	tc = _mm_slli_si128(*tb, 0x04);
	*tb = _mm_xor_si128(*tb, tc);
	tc = _mm_slli_si128(tc, 0x04);
	*tb = _mm_xor_si128(*tb, tc);
	tc = _mm_slli_si128(tc, 0x04);
	*tb = _mm_xor_si128(*tb, tc);
	*tb = _mm_xor_si128(*tb, td);
}


#else
#error xxxxxxxxxx
#endif


#endif





#if (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 || mk_lang_compiler_is_at_least_gcc(6, 1)) && (mk_lang_arch_is_x8632 || mk_lang_arch_is_x8664) && mk_lang_alignas_has && mk_lang_alignof_has


#if mk_lib_crypto_alg_aes_x86_inl_defd_tech == mk_lib_crypto_alg_aes_x86_tech_aesni


#include <emmintrin.h> /* SSE2 _mm_load_si128 _mm_store_si128 _mm_xor_si128 */
#include <wmmintrin.h> /* AES _mm_aesdec_si128 _mm_aesdeclast_si128 _mm_aesenc_si128 _mm_aesenclast_si128 */
#if mk_lang_compiler_is_at_least_clang(1, 0)
#include <intrin.h> /* clang-cl */
#endif


#if mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 && !mk_lang_compiler_is_at_least_clang(1, 0)
#pragma intrinsic(_mm_load_si128)
#pragma intrinsic(_mm_store_si128)
#pragma intrinsic(_mm_xor_si128)

#pragma intrinsic(_mm_aesdec_si128)
#pragma intrinsic(_mm_aesdeclast_si128)
#pragma intrinsic(_mm_aesenc_si128)
#pragma intrinsic(_mm_aesenclast_si128)
#endif


mk_lang_jumbo mk_lang_types_void_t mk_lang_attribute_target("sse2,aes") mk_lib_crypto_alg_aes_x86_inl_defd_schedule_encrypt(mk_lib_crypto_alg_aes_x86_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_aes_x86_inl_defd_msg_pct const input, mk_lib_crypto_alg_aes_x86_inl_defd_msg_pt const output, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	__m128i v;
	__m128i ta;

	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_schedule_t) >= sizeof(__m128i));
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_msg_t) >= sizeof(__m128i));

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_lang_limits_usize_max / mk_lib_crypto_alg_aes_x86_inl_defd_msg_len_v);
	mk_lang_assert((((mk_lang_types_uintptr_t)(schedule)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(input)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(output)) & 0xf) == 0);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_aesni());
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	n = count;
	for(i = 0; i != n; ++i)
	{
		v = _mm_load_si128(((__m128i const*)(&input[i])));
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 0]))); v = _mm_xor_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 1]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 2]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 3]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 4]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 5]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 6]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 7]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 8]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 9]))); v = _mm_aesenc_si128(v, ta);
		#if mk_lib_crypto_alg_aes_x86_inl_defd_bits == 128
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10]))); v = _mm_aesenclast_si128(v, ta);
		#elif mk_lib_crypto_alg_aes_x86_inl_defd_bits == 192
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[11]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[12]))); v = _mm_aesenclast_si128(v, ta);
		#elif mk_lib_crypto_alg_aes_x86_inl_defd_bits == 256
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[11]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[12]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[13]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[14]))); v = _mm_aesenclast_si128(v, ta);
		#else
		#error xxxxxxxxxx
		#endif
		_mm_store_si128(((__m128i*)(&output[i])), v);
	}
}

mk_lang_jumbo mk_lang_types_void_t mk_lang_attribute_target("sse2,aes") mk_lib_crypto_alg_aes_x86_inl_defd_schedule_decrypt(mk_lib_crypto_alg_aes_x86_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_aes_x86_inl_defd_msg_pct const input, mk_lib_crypto_alg_aes_x86_inl_defd_msg_pt const output, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	__m128i v;
	__m128i ta;

	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_schedule_t) >= sizeof(__m128i));
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_msg_t) >= sizeof(__m128i));

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_lang_limits_usize_max / mk_lib_crypto_alg_aes_x86_inl_defd_msg_len_v);
	mk_lang_assert((((mk_lang_types_uintptr_t)(schedule)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(input)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(output)) & 0xf) == 0);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_aesni());
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	n = count;
	for(i = 0; i != n; ++i)
	{
		v = _mm_load_si128(((__m128i const*)(&input[i])));
		#if mk_lib_crypto_alg_aes_x86_inl_defd_bits == 256
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[14]))); v = _mm_xor_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[13]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[12]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[11]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10]))); v = _mm_aesdec_si128(v, ta);
		#elif mk_lib_crypto_alg_aes_x86_inl_defd_bits == 192
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[12]))); v = _mm_xor_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[11]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10]))); v = _mm_aesdec_si128(v, ta);
		#elif mk_lib_crypto_alg_aes_x86_inl_defd_bits == 128
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10]))); v = _mm_xor_si128(v, ta);
		#else
		#error xxxxxxxxxx
		#endif
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 9]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 8]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 7]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 6]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 5]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 4]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 3]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 2]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 1]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 0]))); v = _mm_aesdeclast_si128(v, ta);
		_mm_store_si128(((__m128i*)(&output[i])), v);
	}
}


#endif


#endif





#if (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 || mk_lang_compiler_is_at_least_gcc(11, 1)) && (mk_lang_arch_is_x8632 || mk_lang_arch_is_x8664) && mk_lang_alignas_has && mk_lang_alignof_has


#if mk_lib_crypto_alg_aes_x86_inl_defd_tech == mk_lib_crypto_alg_aes_x86_tech_vaes256


#include <emmintrin.h> /* SSE2 _mm_load_si128 */
#include <immintrin.h> /* AVX _mm256_load_si256 _mm256_store_si256 */
#include <immintrin.h> /* AVX2 _mm256_broadcastsi128_si256 _mm256_xor_si256 */
#include <immintrin.h> /* VAES _mm256_aesdec_epi128 _mm256_aesdeclast_epi128 _mm256_aesenc_epi128 _mm256_aesenclast_epi128 */
#if mk_lang_compiler_is_at_least_clang(1, 0)
#include <intrin.h> /* clang-cl */
#endif


#if mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 && !mk_lang_compiler_is_at_least_clang(1, 0)
#pragma intrinsic(_mm_load_si128)

#pragma intrinsic(_mm256_load_si256)
#pragma intrinsic(_mm256_store_si256)

#pragma intrinsic(_mm256_broadcastsi128_si256)
#pragma intrinsic(_mm256_xor_si256)

#pragma intrinsic(_mm256_aesdec_epi128)
#pragma intrinsic(_mm256_aesdeclast_epi128)
#pragma intrinsic(_mm256_aesenc_epi128)
#pragma intrinsic(_mm256_aesenclast_epi128)
#endif


mk_lang_jumbo mk_lang_types_void_t mk_lang_attribute_target("sse2,avx,avx2,vaes") mk_lib_crypto_alg_aes_x86_inl_defd_schedule_encrypt(mk_lib_crypto_alg_aes_x86_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_aes_x86_inl_defd_msg_pct const input, mk_lib_crypto_alg_aes_x86_inl_defd_msg_pt const output, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	__m256i v;
	__m128i ta;
	__m256i tb;

	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_schedule_t) >= sizeof(__m128i));
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_msg_t) >= sizeof(__m128i));

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_lang_limits_usize_max / mk_lib_crypto_alg_aes_x86_inl_defd_msg_len_v);
	mk_lang_assert(count % 2 == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(schedule)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(input)) & 0x1f) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(output)) & 0x1f) == 0);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_avx());
	mk_lang_assert(mk_lang_cpuid_has_avx2());
	mk_lang_assert(mk_lang_cpuid_has_vaes());
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	n = count;
	for(i = 0; i != n; i += 2)
	{
		#include "mk_lang_warning_clang_push_cast_align.h"
		v = _mm256_load_si256(((__m256i const*)(&input[i])));
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 0]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_xor_si256(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 1]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 2]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 3]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 4]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 5]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 6]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 7]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 8]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 9]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesenc_epi128(v, tb);
		#if mk_lib_crypto_alg_aes_x86_inl_defd_bits == 128
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesenclast_epi128(v, tb);
		#elif mk_lib_crypto_alg_aes_x86_inl_defd_bits == 192
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[11]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[12]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesenclast_epi128(v, tb);
		#elif mk_lib_crypto_alg_aes_x86_inl_defd_bits == 256
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[11]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[12]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[13]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[14]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesenclast_epi128(v, tb);
		#else
		#error xxxxxxxxxx
		#endif
		_mm256_store_si256(((__m256i*)(&output[i])), v);
		#include "mk_lang_warning_clang_pop.h"
	}
}

mk_lang_jumbo mk_lang_types_void_t mk_lang_attribute_target("sse2,avx,avx2,vaes") mk_lib_crypto_alg_aes_x86_inl_defd_schedule_decrypt(mk_lib_crypto_alg_aes_x86_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_aes_x86_inl_defd_msg_pct const input, mk_lib_crypto_alg_aes_x86_inl_defd_msg_pt const output, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	__m256i v;
	__m128i ta;
	__m256i tb;

	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_schedule_t) >= sizeof(__m128i));
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_msg_t) >= sizeof(__m128i));

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_lang_limits_usize_max / mk_lib_crypto_alg_aes_x86_inl_defd_msg_len_v);
	mk_lang_assert(count % 2 == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(schedule)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(input)) & 0x1f) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(output)) & 0x1f) == 0);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_avx());
	mk_lang_assert(mk_lang_cpuid_has_avx2());
	mk_lang_assert(mk_lang_cpuid_has_vaes());
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	n = count;
	for(i = 0; i != n; i += 2)
	{
		#include "mk_lang_warning_clang_push_cast_align.h"
		v = _mm256_load_si256(((__m256i const*)(&input[i])));
		#if mk_lib_crypto_alg_aes_x86_inl_defd_bits == 256
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[14]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_xor_si256(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[13]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[12]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[11]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesdec_epi128(v, tb);
		#elif mk_lib_crypto_alg_aes_x86_inl_defd_bits == 192
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[12]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_xor_si256(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[11]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesdec_epi128(v, tb);
		#elif mk_lib_crypto_alg_aes_x86_inl_defd_bits == 128
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_xor_si256(v, tb);
		#else
		#error xxxxxxxxxx
		#endif
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 9]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 8]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 7]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 6]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 5]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 4]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 3]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 2]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 1]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 0]))); tb = _mm256_broadcastsi128_si256(ta); v = _mm256_aesdeclast_epi128(v, tb);
		_mm256_store_si256(((__m256i*)(&output[i])), v);
		#include "mk_lang_warning_clang_pop.h"
	}
}


#endif


#endif





#if (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 || mk_lang_compiler_is_at_least_gcc(11, 1)) && (mk_lang_arch_is_x8632 || mk_lang_arch_is_x8664) && mk_lang_alignas_has && mk_lang_alignof_has


#if mk_lib_crypto_alg_aes_x86_inl_defd_tech == mk_lib_crypto_alg_aes_x86_tech_vaes512


#include <emmintrin.h> /* SSE2 _mm_load_si128 */
#include <immintrin.h> /* AVX _mm256_load_si256 _mm256_store_si256 */
#include <immintrin.h> /* AVX2 _mm256_broadcastsi128_si256 _mm256_xor_si256 */
#include <immintrin.h> /* VAES _mm256_aesdec_epi128 _mm256_aesdeclast_epi128 _mm256_aesenc_epi128 _mm256_aesenclast_epi128 */
#if mk_lang_compiler_is_at_least_clang(1, 0)
#include <intrin.h> /* clang-cl */
#endif


#if mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 && !mk_lang_compiler_is_at_least_clang(1, 0)
#pragma intrinsic(_mm_load_si128)

#pragma intrinsic(_mm256_load_si256)
#pragma intrinsic(_mm256_store_si256)

#pragma intrinsic(_mm256_broadcastsi128_si256)
#pragma intrinsic(_mm256_xor_si256)

#pragma intrinsic(_mm256_aesdec_epi128)
#pragma intrinsic(_mm256_aesdeclast_epi128)
#pragma intrinsic(_mm256_aesenc_epi128)
#pragma intrinsic(_mm256_aesenclast_epi128)
#endif


mk_lang_jumbo mk_lang_types_void_t mk_lang_attribute_target("sse2,avx,avx512f,vaes") mk_lib_crypto_alg_aes_x86_inl_defd_schedule_encrypt(mk_lib_crypto_alg_aes_x86_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_aes_x86_inl_defd_msg_pct const input, mk_lib_crypto_alg_aes_x86_inl_defd_msg_pt const output, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	__m512i v;
	__m128i ta;
	__m512i tb;

	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_schedule_t) >= sizeof(__m128i));
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_msg_t) >= sizeof(__m128i));

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_lang_limits_usize_max / mk_lib_crypto_alg_aes_x86_inl_defd_msg_len_v);
	mk_lang_assert(count % 4 == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(schedule)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(input)) & 0x3f) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(output)) & 0x3f) == 0);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_avx());
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());
	mk_lang_assert(mk_lang_cpuid_has_vaes());
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	n = count;
	for(i = 0; i != n; i += 4)
	{
		#include "mk_lang_warning_clang_push_cast_align.h"
		v = _mm512_load_si512(((__m512i const*)(&input[i])));
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 0]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_xor_si512(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 1]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 2]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 3]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 4]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 5]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 6]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 7]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 8]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 9]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesenc_epi128(v, tb);
		#if mk_lib_crypto_alg_aes_x86_inl_defd_bits == 128
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesenclast_epi128(v, tb);
		#elif mk_lib_crypto_alg_aes_x86_inl_defd_bits == 192
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[11]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[12]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesenclast_epi128(v, tb);
		#elif mk_lib_crypto_alg_aes_x86_inl_defd_bits == 256
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[11]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[12]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[13]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesenc_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[14]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesenclast_epi128(v, tb);
		#else
		#error xxxxxxxxxx
		#endif
		_mm512_store_si512(((__m512i*)(&output[i])), v);
		#include "mk_lang_warning_clang_pop.h"
	}
}

mk_lang_jumbo mk_lang_types_void_t mk_lang_attribute_target("sse2,avx,avx2,avx512f,vaes") mk_lib_crypto_alg_aes_x86_inl_defd_schedule_decrypt(mk_lib_crypto_alg_aes_x86_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_aes_x86_inl_defd_msg_pct const input, mk_lib_crypto_alg_aes_x86_inl_defd_msg_pt const output, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	__m512i v;
	__m128i ta;
	__m512i tb;

	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_schedule_t) >= sizeof(__m128i));
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_msg_t) >= sizeof(__m128i));

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_lang_limits_usize_max / mk_lib_crypto_alg_aes_x86_inl_defd_msg_len_v);
	mk_lang_assert(count % 4 == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(schedule)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(input)) & 0x3f) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(output)) & 0x3f) == 0);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_avx());
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());
	mk_lang_assert(mk_lang_cpuid_has_vaes());
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	n = count;
	for(i = 0; i != n; i += 4)
	{
		#include "mk_lang_warning_clang_push_cast_align.h"
		v = _mm512_load_si512(((__m512i const*)(&input[i])));
		#if mk_lib_crypto_alg_aes_x86_inl_defd_bits == 256
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[14]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_xor_si512(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[13]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[12]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[11]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesdec_epi128(v, tb);
		#elif mk_lib_crypto_alg_aes_x86_inl_defd_bits == 192
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[12]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_xor_si512(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[11]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesdec_epi128(v, tb);
		#elif mk_lib_crypto_alg_aes_x86_inl_defd_bits == 128
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_xor_si512(v, tb);
		#else
		#error xxxxxxxxxx
		#endif
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 9]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 8]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 7]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 6]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 5]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 4]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 3]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 2]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 1]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesdec_epi128(v, tb);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 0]))); tb = _mm512_broadcast_i32x4(ta); v = _mm512_aesdeclast_epi128(v, tb);
		_mm512_store_si512(((__m512i*)(&output[i])), v);
		#include "mk_lang_warning_clang_pop.h"
	}
}


#endif





#if (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 || mk_lang_compiler_is_at_least_gcc(6, 1)) && (mk_lang_arch_is_x8632 || mk_lang_arch_is_x8664) && mk_lang_alignas_has && mk_lang_alignof_has


#include <emmintrin.h> /* SSE2 _mm_castpd_si128 _mm_castsi128_pd _mm_load_si128 _mm_shuffle_pd _mm_store_si128 */
#include <wmmintrin.h> /* AES _mm_aesimc_si128 _mm_aeskeygenassist_si128 */


#if mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 && !mk_lang_compiler_is_at_least_clang(1, 0)
#pragma intrinsic(_mm_castpd_si128)
#pragma intrinsic(_mm_castsi128_pd)
#pragma intrinsic(_mm_load_si128)
#pragma intrinsic(_mm_shuffle_pd)
#pragma intrinsic(_mm_store_si128)

#pragma intrinsic(_mm_aesimc_si128)
#pragma intrinsic(_mm_aeskeygenassist_si128)
#endif


mk_lang_jumbo mk_lang_types_void_t mk_lang_attribute_target("sse2,aes") mk_lib_crypto_alg_aes_x86_inl_defd_expand_enc(mk_lib_crypto_alg_aes_x86_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_x86_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
#if mk_lib_crypto_alg_aes_x86_inl_defd_bits == 128

	__m128i ta;
	__m128i tb;

	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_key_t) >= sizeof(__m128i));
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_schedule_t) >= sizeof(__m128i));

	mk_lang_assert(key);
	mk_lang_assert(schedule);
	mk_lang_assert((((mk_lang_types_uintptr_t)(key)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(schedule)) & 0xf) == 0);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_aesni());

	#include "mk_lang_warning_clang_push_cast_align.h"
	ta = _mm_load_si128(((__m128i const*)(&key->m_data.m_uint8s[0])));
	#include "mk_lang_warning_clang_pop.h"
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[0])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x01); ta = mk_lib_crypto_alg_aes_x86_inl_defd_assist_128(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 1])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x02); ta = mk_lib_crypto_alg_aes_x86_inl_defd_assist_128(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 2])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x04); ta = mk_lib_crypto_alg_aes_x86_inl_defd_assist_128(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 3])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x08); ta = mk_lib_crypto_alg_aes_x86_inl_defd_assist_128(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 4])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x10); ta = mk_lib_crypto_alg_aes_x86_inl_defd_assist_128(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 5])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x20); ta = mk_lib_crypto_alg_aes_x86_inl_defd_assist_128(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 6])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x40); ta = mk_lib_crypto_alg_aes_x86_inl_defd_assist_128(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 7])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x80); ta = mk_lib_crypto_alg_aes_x86_inl_defd_assist_128(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 8])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x1b); ta = mk_lib_crypto_alg_aes_x86_inl_defd_assist_128(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 9])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x36); ta = mk_lib_crypto_alg_aes_x86_inl_defd_assist_128(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[10])), ta);

#elif mk_lib_crypto_alg_aes_x86_inl_defd_bits == 192

	union word_u
	{
		mk_lang_types_uchar_t m_uchars[16];
		__m128i m_i128;
	};
	typedef union word_u word_t;

	mk_lang_types_sint_t i;
	word_t w;
	__m128i ta;
	__m128i tb;
	__m128i tc;

	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_key_t) >= sizeof(__m128i));
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_schedule_t) >= sizeof(__m128i));

	mk_lang_assert(key);
	mk_lang_assert(schedule);
	mk_lang_assert((((mk_lang_types_uintptr_t)(key)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(schedule)) & 0xf) == 0);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_aesni());

	for(i = 0; i != 8; ++i)
	{
		mk_sl_cui_uint8_to_bi_uchar(&key->m_data.m_uint8s[16 + i], &w.m_uchars[i]);
	}
	for(i = 8; i != 16; ++i)
	{
		w.m_uchars[i] = 0;
	}
	#include "mk_lang_warning_clang_push_cast_align.h"
	ta = _mm_load_si128(((__m128i const*)(&key->m_data.m_uint8s[0])));
	tb = _mm_load_si128(((__m128i const*)(&w.m_uchars[0])));
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[0])), ta);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[1])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x01);
	mk_lib_crypto_alg_aes_x86_inl_defd_assist_192(&ta, &tc, &tb);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[1])), _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(_mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[1])))), _mm_castsi128_pd(ta), 0)));
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[2])), _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(ta), _mm_castsi128_pd(tb), 1)));
	tc = _mm_aeskeygenassist_si128(tb, 0x02);
	mk_lib_crypto_alg_aes_x86_inl_defd_assist_192(&ta, &tc, &tb);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[3])), ta);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[4])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x04);
	mk_lib_crypto_alg_aes_x86_inl_defd_assist_192(&ta, &tc, &tb);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[4])), _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(_mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[4])))), _mm_castsi128_pd(ta), 0)));
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[5])), _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(ta), _mm_castsi128_pd(tb), 1)));
	tc = _mm_aeskeygenassist_si128(tb, 0x08);
	mk_lib_crypto_alg_aes_x86_inl_defd_assist_192(&ta, &tc, &tb);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[6])), ta);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[7])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x10);
	mk_lib_crypto_alg_aes_x86_inl_defd_assist_192(&ta, &tc, &tb);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[7])), _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(_mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[7])))), _mm_castsi128_pd(ta), 0)));
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[8])), _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(ta), _mm_castsi128_pd(tb), 1)));
	tc = _mm_aeskeygenassist_si128(tb, 0x20);
	mk_lib_crypto_alg_aes_x86_inl_defd_assist_192(&ta, &tc, &tb);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[9])), ta);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[10])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x40);
	mk_lib_crypto_alg_aes_x86_inl_defd_assist_192(&ta, &tc, &tb);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[10])), _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(_mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10])))), _mm_castsi128_pd(ta), 0)));
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[11])), _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(ta), _mm_castsi128_pd(tb), 1)));
	tc = _mm_aeskeygenassist_si128(tb, 0x80);
	mk_lib_crypto_alg_aes_x86_inl_defd_assist_192(&ta, &tc, &tb);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[12])), ta);
	#include "mk_lang_warning_clang_pop.h"

#elif mk_lib_crypto_alg_aes_x86_inl_defd_bits == 256

	__m128i ta;
	__m128i tb;
	__m128i tc;

	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_key_t) >= sizeof(__m128i));
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_schedule_t) >= sizeof(__m128i));

	mk_lang_assert(key);
	mk_lang_assert(schedule);
	mk_lang_assert((((mk_lang_types_uintptr_t)(key)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(schedule)) & 0xf) == 0);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_aesni());

	#include "mk_lang_warning_clang_push_cast_align.h"
	ta = _mm_load_si128(((__m128i const*)(&key->m_data.m_uint8s[ 0])));
	tb = _mm_load_si128(((__m128i const*)(&key->m_data.m_uint8s[16])));
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[0])), ta);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[1])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x01); mk_lib_crypto_alg_aes_x86_inl_defd_assist_256_a(&ta, &tc); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 2])), ta); mk_lib_crypto_alg_aes_x86_inl_defd_assist_256_b(&ta, &tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 3])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x02); mk_lib_crypto_alg_aes_x86_inl_defd_assist_256_a(&ta, &tc); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 4])), ta); mk_lib_crypto_alg_aes_x86_inl_defd_assist_256_b(&ta, &tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 5])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x04); mk_lib_crypto_alg_aes_x86_inl_defd_assist_256_a(&ta, &tc); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 6])), ta); mk_lib_crypto_alg_aes_x86_inl_defd_assist_256_b(&ta, &tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 7])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x08); mk_lib_crypto_alg_aes_x86_inl_defd_assist_256_a(&ta, &tc); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 8])), ta); mk_lib_crypto_alg_aes_x86_inl_defd_assist_256_b(&ta, &tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 9])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x10); mk_lib_crypto_alg_aes_x86_inl_defd_assist_256_a(&ta, &tc); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[10])), ta); mk_lib_crypto_alg_aes_x86_inl_defd_assist_256_b(&ta, &tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[11])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x20); mk_lib_crypto_alg_aes_x86_inl_defd_assist_256_a(&ta, &tc); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[12])), ta); mk_lib_crypto_alg_aes_x86_inl_defd_assist_256_b(&ta, &tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[13])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x40); mk_lib_crypto_alg_aes_x86_inl_defd_assist_256_a(&ta, &tc); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[14])), ta);
	#include "mk_lang_warning_clang_pop.h"

#else
#error xxxxxxxxxx
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_lang_attribute_target("sse2,aes") mk_lib_crypto_alg_aes_x86_inl_defd_expand_dec(mk_lib_crypto_alg_aes_x86_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_x86_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	__m128i ta;

	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_schedule_t) >= sizeof(__m128i));
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_x86_inl_defd_msg_t) >= sizeof(__m128i));

	mk_lang_assert(key);
	mk_lang_assert(schedule);
	mk_lang_assert((((mk_lang_types_uintptr_t)(key)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(schedule)) & 0xf) == 0);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_aesni());

	mk_lib_crypto_alg_aes_x86_inl_defd_expand_enc(key, schedule);
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 1]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 1])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 2]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 2])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 3]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 3])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 4]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 4])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 5]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 5])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 6]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 6])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 7]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 7])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 8]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 8])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[ 9]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 9])), _mm_aesimc_si128(ta));
	#if mk_lib_crypto_alg_aes_x86_inl_defd_bits > 128
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[10]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[10])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[11]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[11])), _mm_aesimc_si128(ta));
	#endif
	#if mk_lib_crypto_alg_aes_x86_inl_defd_bits > 192
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[12]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[12])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[13]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[13])), _mm_aesimc_si128(ta));
	#endif
}


#endif


#include "mk_lib_crypto_alg_aes_x86_inl_defu.h"


#endif
