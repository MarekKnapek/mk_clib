#ifndef mk_include_guard_mk_lib_crypto_hash_block_sha1_x86_c
#define mk_include_guard_mk_lib_crypto_hash_block_sha1_x86_c
#include "mk_lib_crypto_hash_block_sha1_x86.h"

/* NIST FIPS PUB 180-1 */
/* NIST FIPS PUB 180-2 */
/* NIST FIPS PUB 180-3 */
/* NIST FIPS PUB 180-4 */

#include "mk_lang_compiler.h"
#include "mk_lang_msvc.h"
#if (mk_lang_msvc_ver >= mk_lang_msvc_ver_2015 || mk_lang_compiler_is_at_least_gcc(11, 1)) && (mk_lang_arch_is_x8632 || mk_lang_arch_is_x8664)


#include "mk_lang_alignas.h"
#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_attribute.h"
#include "mk_lang_charbit.h"
#include "mk_lang_compiler.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"

#include <emmintrin.h> /* SSE2 _mm_add_epi32 _mm_load_si128 _mm_set_epi32 _mm_set_epi64x _mm_setzero_si128 _mm_shuffle_epi32 _mm_store_si128 _mm_xor_si128 */
#include <tmmintrin.h> /* SSSE3 _mm_shuffle_epi8 */
#include <smmintrin.h> /* SSE4.1 _mm_extract_epi32 */
#include <immintrin.h> /* SHA _mm_sha1msg1_epu32 _mm_sha1msg2_epu32 _mm_sha1nexte_epu32 _mm_sha1rnds4_epu32 */
#if mk_lang_compiler_is_at_least_clang(1, 0)
#include <intrin.h> /* clang-cl */
#endif


#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2015 && !mk_lang_compiler_is_at_least_clang(1, 0)
#pragma intrinsic(_mm_add_epi32)
#pragma intrinsic(_mm_extract_epi32)
#pragma intrinsic(_mm_load_si128)
#pragma intrinsic(_mm_set_epi32)
#pragma intrinsic(_mm_set_epi64x)
#pragma intrinsic(_mm_setzero_si128)
#pragma intrinsic(_mm_sha1msg1_epu32)
#pragma intrinsic(_mm_sha1msg2_epu32)
#pragma intrinsic(_mm_sha1nexte_epu32)
#pragma intrinsic(_mm_sha1rnds4_epu32)
#pragma intrinsic(_mm_shuffle_epi32)
#pragma intrinsic(_mm_shuffle_epi8)
#pragma intrinsic(_mm_store_si128)
#pragma intrinsic(_mm_xor_si128)
#endif


union mk_lib_crypto_hash_block_sha1_x86_block2_data_u
{
	mk_sl_cui_uint32_t m_u32s[16];
	mk_lib_crypto_hash_block_sha1_x86_block_t m_align;
};
typedef union mk_lib_crypto_hash_block_sha1_x86_block2_data_u mk_lib_crypto_hash_block_sha1_x86_block2_data_t;
struct mk_lib_crypto_hash_block_sha1_x86_block2_s
{
	mk_lang_alignas(mk_lib_crypto_hash_block_sha1_x86_block_len_v) mk_lib_crypto_hash_block_sha1_x86_block2_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_sha1_x86_block2_s mk_lib_crypto_hash_block_sha1_x86_block2_t;
typedef mk_lib_crypto_hash_block_sha1_x86_block2_t const mk_lib_crypto_hash_block_sha1_x86_block2_ct;
typedef mk_lib_crypto_hash_block_sha1_x86_block2_t* mk_lib_crypto_hash_block_sha1_x86_block2_pt;
typedef mk_lib_crypto_hash_block_sha1_x86_block2_t const* mk_lib_crypto_hash_block_sha1_x86_block2_pct;


mk_lang_constexpr_static_inline mk_sl_cui_uint32_t const mk_lib_crypto_hash_block_sha1_x86_s_init[5] =
{
	mk_sl_cui_uint32_c(0x67452301ul),
	mk_sl_cui_uint32_c(0xefcdab89ul),
	mk_sl_cui_uint32_c(0x98badcfeul),
	mk_sl_cui_uint32_c(0x10325476ul),
	mk_sl_cui_uint32_c(0xc3d2e1f0ul),
};


mk_lang_jumbo mk_lang_types_void_t mk_lang_attribute_target("sse2,ssse3,sse4.1,sha") mk_lib_crypto_hash_block_sha1_x86_init(mk_lib_crypto_hash_block_sha1_x86_pt const sha1_x86) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha1_x86_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha1_x86_digest_t) >= 20);

	mk_lang_assert(sha1_x86);
	mk_lang_assert((((mk_lang_types_uintptr_t)(&sha1_x86->m_state[0])) & 0xf) == 0);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_ssse3());
	mk_lang_assert(mk_lang_cpuid_has_sse41());
	mk_lang_assert(mk_lang_cpuid_has_sha());

	sha1_x86->m_state[0] = mk_lib_crypto_hash_block_sha1_x86_s_init[0];
	sha1_x86->m_state[1] = mk_lib_crypto_hash_block_sha1_x86_s_init[1];
	sha1_x86->m_state[2] = mk_lib_crypto_hash_block_sha1_x86_s_init[2];
	sha1_x86->m_state[3] = mk_lib_crypto_hash_block_sha1_x86_s_init[3];
	sha1_x86->m_state[4] = mk_lib_crypto_hash_block_sha1_x86_s_init[4];
	mk_sl_cui_uint64_set_zero(&sha1_x86->m_len);
}

mk_lang_jumbo mk_lang_types_void_t mk_lang_attribute_target("sse2,ssse3,sse4.1,sha") mk_lib_crypto_hash_block_sha1_x86_append_blocks(mk_lib_crypto_hash_block_sha1_x86_pt const sha1_x86, mk_lib_crypto_hash_block_sha1_x86_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	#define mk_lib_crypto_hash_block_sha1_x86_reverse_32 ((0x0 << (3 * 2)) | (0x1 << (2 * 2)) | (0x2 << (1 * 2)) | (0x3 << (0 * 2)))

	__m128i reverse_8;
	mk_sl_cui_uint64_t ta;
	__m128i abcdx;
	__m128i e;
	mk_lang_types_usize_t iblock;
	mk_sl_cui_uint8_pct ptr;
	__m128i old_abcd;
	__m128i old_e;
	__m128i msg_0;
	__m128i abcdy;
	__m128i msg_1;
	__m128i msg_2;
	__m128i msg_3;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(sha1_x86);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha1_x86_block_len_v);
	mk_lang_assert((((mk_lang_types_uintptr_t)(&sha1_x86->m_state[0])) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(pblocks)) & 0xf) == 0);
	mk_lang_assert(sizeof(mk_sl_cui_uint32_t) == sizeof(mk_lang_types_sint_t));
	mk_lang_assert(sizeof(mk_sl_cui_uint32_t) == 4);
	mk_lang_assert(mk_lang_alignof(mk_sl_cui_uint32_t) == 4);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_ssse3());
	mk_lang_assert(mk_lang_cpuid_has_sse41());
	mk_lang_assert(mk_lang_cpuid_has_sha());
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(nblocks != 0)
	{
		reverse_8 = _mm_set_epi64x(0x0001020304050607ull, 0x08090a0b0c0d0e0full);
		mk_sl_cui_uint64_from_bi_usize(&ta, &nblocks);
		mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&sha1_x86->m_len, &ta));
		mk_sl_cui_uint64_add2_wrap_cid_cod(&sha1_x86->m_len, &ta);
		#include "mk_lang_warning_clang_push_cast_align.h"
		abcdx = _mm_load_si128(((__m128i const*)(&sha1_x86->m_state[0])));
		#include "mk_lang_warning_clang_pop.h"
		abcdx = _mm_shuffle_epi32(abcdx, mk_lib_crypto_hash_block_sha1_x86_reverse_32);
		e = _mm_set_epi32(*((mk_lang_types_sint_pct)(&sha1_x86->m_state[4])), 0, 0, 0);
		for(iblock = 0, ptr = &pblocks[0].m_data.m_uint8s[0]; iblock != nblocks; ++iblock, ptr += mk_lib_crypto_hash_block_sha1_x86_block_len_v)
		{
			#include "mk_lang_warning_clang_push_cast_align.h"
			#include "mk_lang_warning_clang_push_vector_conversion.h"
			old_abcd = abcdx;
			old_e = e;
			msg_0 = _mm_load_si128(((__m128i const*)(&ptr[0 * 16])));
			msg_0 = _mm_shuffle_epi8(msg_0, reverse_8);
			e = _mm_add_epi32(e, msg_0);
			abcdy = _mm_sha1rnds4_epu32(abcdx, e, 0);
			msg_1 = _mm_load_si128(((__m128i const*)(&ptr[1 * 16])));
			msg_1 = _mm_shuffle_epi8(msg_1, reverse_8);
			e = _mm_sha1nexte_epu32(abcdx, msg_1);
			abcdx = _mm_sha1rnds4_epu32(abcdy, e, 0);
			msg_2 = _mm_load_si128(((__m128i const*)(&ptr[2 * 16])));
			msg_2 = _mm_shuffle_epi8(msg_2, reverse_8);
			e = _mm_sha1nexte_epu32(abcdy, msg_2);
			abcdy = _mm_sha1rnds4_epu32(abcdx, e, 0);
			msg_3 = _mm_load_si128(((__m128i const*)(&ptr[3 * 16])));
			msg_3 = _mm_shuffle_epi8(msg_3, reverse_8);
			e = _mm_sha1nexte_epu32(abcdx, msg_3);
			abcdx = _mm_sha1rnds4_epu32(abcdy, e, 0);
			msg_0 = _mm_sha1msg1_epu32(msg_0, msg_1);
			msg_0 = _mm_xor_si128(msg_0, msg_2);
			msg_0 = _mm_sha1msg2_epu32(msg_0, msg_3);
			e = _mm_sha1nexte_epu32(abcdy, msg_0);
			abcdy = _mm_sha1rnds4_epu32(abcdx, e, 0);
			msg_1 = _mm_sha1msg1_epu32(msg_1, msg_2);
			msg_1 = _mm_xor_si128(msg_1, msg_3);
			msg_1 = _mm_sha1msg2_epu32(msg_1, msg_0);
			e = _mm_sha1nexte_epu32(abcdx, msg_1);
			abcdx = _mm_sha1rnds4_epu32(abcdy, e, 1);
			msg_2 = _mm_sha1msg1_epu32(msg_2, msg_3);
			msg_2 = _mm_xor_si128(msg_2, msg_0);
			msg_2 = _mm_sha1msg2_epu32(msg_2, msg_1);
			e = _mm_sha1nexte_epu32(abcdy, msg_2);
			abcdy = _mm_sha1rnds4_epu32(abcdx, e, 1);
			msg_3 = _mm_sha1msg1_epu32(msg_3, msg_0);
			msg_3 = _mm_xor_si128(msg_3, msg_1);
			msg_3 = _mm_sha1msg2_epu32(msg_3, msg_2);
			e = _mm_sha1nexte_epu32(abcdx, msg_3);
			abcdx = _mm_sha1rnds4_epu32(abcdy, e, 1);
			msg_0 = _mm_sha1msg1_epu32(msg_0, msg_1);
			msg_0 = _mm_xor_si128(msg_0, msg_2);
			msg_0 = _mm_sha1msg2_epu32(msg_0, msg_3);
			e = _mm_sha1nexte_epu32(abcdy, msg_0);
			abcdy = _mm_sha1rnds4_epu32(abcdx, e, 1);
			msg_1 = _mm_sha1msg1_epu32(msg_1, msg_2);
			msg_1 = _mm_xor_si128(msg_1, msg_3);
			msg_1 = _mm_sha1msg2_epu32(msg_1, msg_0);
			e = _mm_sha1nexte_epu32(abcdx, msg_1);
			abcdx = _mm_sha1rnds4_epu32(abcdy, e, 1);
			msg_2 = _mm_sha1msg1_epu32(msg_2, msg_3);
			msg_2 = _mm_xor_si128(msg_2, msg_0);
			msg_2 = _mm_sha1msg2_epu32(msg_2, msg_1);
			e = _mm_sha1nexte_epu32(abcdy, msg_2);
			abcdy = _mm_sha1rnds4_epu32(abcdx, e, 2);
			msg_3 = _mm_sha1msg1_epu32(msg_3, msg_0);
			msg_3 = _mm_xor_si128(msg_3, msg_1);
			msg_3 = _mm_sha1msg2_epu32(msg_3, msg_2);
			e = _mm_sha1nexte_epu32(abcdx, msg_3);
			abcdx = _mm_sha1rnds4_epu32(abcdy, e, 2);
			msg_0 = _mm_sha1msg1_epu32(msg_0, msg_1);
			msg_0 = _mm_xor_si128(msg_0, msg_2);
			msg_0 = _mm_sha1msg2_epu32(msg_0, msg_3);
			e = _mm_sha1nexte_epu32(abcdy, msg_0);
			abcdy = _mm_sha1rnds4_epu32(abcdx, e, 2);
			msg_1 = _mm_sha1msg1_epu32(msg_1, msg_2);
			msg_1 = _mm_xor_si128(msg_1, msg_3);
			msg_1 = _mm_sha1msg2_epu32(msg_1, msg_0);
			e = _mm_sha1nexte_epu32(abcdx, msg_1);
			abcdx = _mm_sha1rnds4_epu32(abcdy, e, 2);
			msg_2 = _mm_sha1msg1_epu32(msg_2, msg_3);
			msg_2 = _mm_xor_si128(msg_2, msg_0);
			msg_2 = _mm_sha1msg2_epu32(msg_2, msg_1);
			e = _mm_sha1nexte_epu32(abcdy, msg_2);
			abcdy = _mm_sha1rnds4_epu32(abcdx, e, 2);
			msg_3 = _mm_sha1msg1_epu32(msg_3, msg_0);
			msg_3 = _mm_xor_si128(msg_3, msg_1);
			msg_3 = _mm_sha1msg2_epu32(msg_3, msg_2);
			e = _mm_sha1nexte_epu32(abcdx, msg_3);
			abcdx = _mm_sha1rnds4_epu32(abcdy, e, 3);
			msg_0 = _mm_sha1msg1_epu32(msg_0, msg_1);
			msg_0 = _mm_xor_si128(msg_0, msg_2);
			msg_0 = _mm_sha1msg2_epu32(msg_0, msg_3);
			e = _mm_sha1nexte_epu32(abcdy, msg_0);
			abcdy = _mm_sha1rnds4_epu32(abcdx, e, 3);
			msg_1 = _mm_sha1msg1_epu32(msg_1, msg_2);
			msg_1 = _mm_xor_si128(msg_1, msg_3);
			msg_1 = _mm_sha1msg2_epu32(msg_1, msg_0);
			e = _mm_sha1nexte_epu32(abcdx, msg_1);
			abcdx = _mm_sha1rnds4_epu32(abcdy, e, 3);
			msg_2 = _mm_sha1msg1_epu32(msg_2, msg_3);
			msg_2 = _mm_xor_si128(msg_2, msg_0);
			msg_2 = _mm_sha1msg2_epu32(msg_2, msg_1);
			e = _mm_sha1nexte_epu32(abcdy, msg_2);
			abcdy = _mm_sha1rnds4_epu32(abcdx, e, 3);
			msg_3 = _mm_sha1msg1_epu32(msg_3, msg_0);
			msg_3 = _mm_xor_si128(msg_3, msg_1);
			msg_3 = _mm_sha1msg2_epu32(msg_3, msg_2);
			e = _mm_sha1nexte_epu32(abcdx, msg_3);
			abcdx = _mm_sha1rnds4_epu32(abcdy, e, 3);
			msg_0 = _mm_setzero_si128();
			e = _mm_sha1nexte_epu32(abcdy, msg_0);
			abcdx = _mm_add_epi32(abcdx, old_abcd);
			e = _mm_add_epi32(e, old_e);
			#include "mk_lang_warning_clang_pop.h"
			#include "mk_lang_warning_clang_pop.h"
		}
		#include "mk_lang_warning_clang_push_cast_align.h"
		abcdx = _mm_shuffle_epi32(abcdx, mk_lib_crypto_hash_block_sha1_x86_reverse_32);
		_mm_store_si128(((__m128i*)(&sha1_x86->m_state[0])), abcdx);
		*((mk_lang_types_sint_pt)(&sha1_x86->m_state[4])) = _mm_extract_epi32(e, 3);
		#include "mk_lang_warning_clang_pop.h"
	}
}

mk_lang_jumbo mk_lang_types_void_t mk_lang_attribute_target("sse2,ssse3,sse4.1,sha") mk_lib_crypto_hash_block_sha1_x86_finish(mk_lib_crypto_hash_block_sha1_x86_pt const sha1_x86, mk_lib_crypto_hash_block_sha1_x86_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_sha1_x86_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_types_uint_t ui mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tb mk_lang_constexpr_init;
	mk_lang_types_sint_t rest mk_lang_constexpr_init;

	mk_lang_assert(sha1_x86);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_sha1_x86_block_len_v);
	mk_lang_assert(digest);
	mk_lang_assert((((mk_lang_types_uintptr_t)(&sha1_x86->m_state[0])) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(block)) & 0xf) == 0);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_ssse3());
	mk_lang_assert(mk_lang_cpuid_has_sse41());
	mk_lang_assert(mk_lang_cpuid_has_sha());

	ui = mk_lib_crypto_hash_block_sha1_x86_block_len_v; mk_sl_cui_uint64_from_bi_uint(&ta, &ui);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_mul(&sha1_x86->m_len, &ta));
	mk_sl_cui_uint64_shl3(&sha1_x86->m_len, 6, &ta);
	mk_sl_cui_uint64_from_bi_sint(&tb, &idx);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&ta, &tb));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&ta, &tb);
	ui = 8; mk_sl_cui_uint64_from_bi_uint(&tb, &ui);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_mul(&ta, &tb));
	mk_sl_cui_uint64_shl2(&ta, 3);

	ui = 0x80; mk_sl_cui_uint8_from_bi_uint(&block->m_data.m_uint8s[idx], &ui);
	rest = mk_lib_crypto_hash_block_sha1_x86_block_len_v - idx - 1;
	mk_lang_assert(rest >= 0 && rest <= mk_lib_crypto_hash_block_sha1_x86_block_len_v - 1);
	if(rest >= mk_sl_cui_uint64_size_bytes_v)
	{
		mk_sl_cui_uint8_memclr_fn(&block->m_data.m_uint8s[idx + 1], ((mk_lang_types_usize_t)(rest - mk_sl_cui_uint64_size_bytes_v)));
	}
	else
	{
		mk_sl_cui_uint8_memclr_fn(&block->m_data.m_uint8s[idx + 1], ((mk_lang_types_usize_t)(rest)));
		mk_lib_crypto_hash_block_sha1_x86_append_blocks(sha1_x86, block, 1);
		mk_sl_cui_uint8_memclr_fn(&block->m_data.m_uint8s[0], ((mk_lang_types_sint_t)(mk_lib_crypto_hash_block_sha1_x86_block_len_v)) - ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v)));
	}

	mk_sl_uint_convert_64_8_be_to_sml(&ta, &block->m_data.m_uint8s[((mk_lang_types_sint_t)(mk_lib_crypto_hash_block_sha1_x86_block_len_v)) - ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v))]);
	mk_lib_crypto_hash_block_sha1_x86_append_blocks(sha1_x86, block, 1);
	mk_sl_uint_convert_32_8_be_to_sml_multi(&sha1_x86->m_state[0], &digest->m_data.m_uint8s[0], mk_lang_countof(sha1_x86->m_state));
}


#endif
#endif
