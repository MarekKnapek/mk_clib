#include "mk_lib_crypto_hash_block_sha1_x86_msvc.h"

/* nist fips pub 180-1 */
/* nist fips pub 180-2 */
/* nist fips pub 180-3 */
/* nist fips pub 180-4 */

#include "mk_lang_alignof.h"
#include "mk_lang_arch.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_msvc.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"

#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2015 && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664)

#include <emmintrin.h> /* _mm_add_epi32 _mm_load_si128 _mm_set_epi32 _mm_set_epi64x _mm_setzero_si128 _mm_shuffle_epi32 _mm_store_si128 _mm_xor_si128 */
#include <immintrin.h> /* _mm_sha1msg1_epu32 _mm_sha1msg2_epu32 _mm_sha1nexte_epu32 _mm_sha1rnds4_epu32 */
#include <smmintrin.h> /* _mm_extract_epi32 */
#include <tmmintrin.h> /* _mm_shuffle_epi8 */


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


mk_lang_constexpr_static_inline mk_sl_cui_uint32_t const s_mk_lib_crypto_hash_block_sha1_x86_msvc_init[5] =
{
	mk_sl_cui_uint32_c(0x67452301ul),
	mk_sl_cui_uint32_c(0xefcdab89ul),
	mk_sl_cui_uint32_c(0x98badcfeul),
	mk_sl_cui_uint32_c(0x10325476ul),
	mk_sl_cui_uint32_c(0xc3d2e1f0ul),
};


mk_lang_jumbo void mk_lib_crypto_hash_block_sha1_x86_msvc_init(mk_lib_crypto_hash_block_sha1_x86_msvc_pt const sha1) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha1_x86_msvc_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha1_x86_msvc_digest_t) >= 20);

	mk_lang_assert(sha1);

	sha1->m_state[0] = s_mk_lib_crypto_hash_block_sha1_x86_msvc_init[0];
	sha1->m_state[1] = s_mk_lib_crypto_hash_block_sha1_x86_msvc_init[1];
	sha1->m_state[2] = s_mk_lib_crypto_hash_block_sha1_x86_msvc_init[2];
	sha1->m_state[3] = s_mk_lib_crypto_hash_block_sha1_x86_msvc_init[3];
	sha1->m_state[4] = s_mk_lib_crypto_hash_block_sha1_x86_msvc_init[4];
	mk_sl_cui_uint64_set_zero(&sha1->m_len);
}

mk_lang_jumbo void mk_lib_crypto_hash_block_sha1_x86_msvc_append_blocks(mk_lib_crypto_hash_block_sha1_x86_msvc_pt const sha1, mk_lib_crypto_hash_block_sha1_x86_msvc_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	#define mk_lib_crypto_hash_block_sha1_x86_msvc_reverse_32 ((0x0 << (3 * 2)) | (0x1 << (2 * 2)) | (0x2 << (1 * 2)) | (0x3 << (0 * 2)))

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

	mk_lang_assert(sha1);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha1_x86_msvc_block_len);
	mk_lang_assert((((mk_lang_types_uintptr_t)(&sha1->m_state[0])) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(pblocks)) & 0xf) == 0);
	mk_lang_assert(sizeof(mk_sl_cui_uint32_t) == sizeof(int));
	mk_lang_assert(sizeof(mk_sl_cui_uint32_t) == 4);
	mk_lang_assert(mk_lang_alignof(mk_sl_cui_uint32_t) == 4);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_ssse3());
	mk_lang_assert(mk_lang_cpuid_has_sse41());
	mk_lang_assert(mk_lang_cpuid_has_sha());

	if(nblocks != 0)
	{
		reverse_8 = _mm_set_epi64x(0x0001020304050607ull, 0x08090a0b0c0d0e0full);
		mk_sl_cui_uint64_from_bi_usize(&ta, &nblocks);
		mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&sha1->m_len, &ta));
		mk_sl_cui_uint64_add2_wrap_cid_cod(&sha1->m_len, &ta);
		abcdx = _mm_load_si128(((__m128i const*)(&sha1->m_state[0])));
		abcdx = _mm_shuffle_epi32(abcdx, mk_lib_crypto_hash_block_sha1_x86_msvc_reverse_32);
		e = _mm_set_epi32(*((int const*)(&sha1->m_state[4])), 0, 0, 0);
		for(iblock = 0, ptr = &pblocks[0].m_uint8s[0]; iblock != nblocks; ++iblock, ptr += mk_lib_crypto_hash_block_sha1_x86_msvc_block_len)
		{
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
		}
		abcdx = _mm_shuffle_epi32(abcdx, mk_lib_crypto_hash_block_sha1_x86_msvc_reverse_32);
		_mm_store_si128(((__m128i*)(&sha1->m_state[0])), abcdx);
		*((int*)(&sha1->m_state[4])) = _mm_extract_epi32(e, 3);
	}
}

mk_lang_jumbo void mk_lib_crypto_hash_block_sha1_x86_msvc_finish(mk_lib_crypto_hash_block_sha1_x86_msvc_pt const sha1, mk_lib_crypto_hash_block_sha1_x86_msvc_block_pt const block, int const idx, mk_lib_crypto_hash_block_sha1_x86_msvc_digest_pt const digest) mk_lang_noexcept
{
	unsigned ui mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tb mk_lang_constexpr_init;
	int rest mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(sha1);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_sha1_x86_msvc_block_len);
	mk_lang_assert(digest);

	ui = mk_lib_crypto_hash_block_sha1_x86_msvc_block_len;
	mk_sl_cui_uint64_from_bi_uint(&ta, &ui);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_mul(&sha1->m_len, &ta));
	mk_sl_cui_uint64_shl3(&sha1->m_len, 6, &ta);
	mk_sl_cui_uint64_from_bi_sint(&tb, &idx);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&ta, &tb));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&ta, &tb);
	ui = 8;
	mk_sl_cui_uint64_from_bi_uint(&tb, &ui);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_mul(&ta, &tb));
	mk_sl_cui_uint64_shl2(&ta, 3);
	ui = 0x80;
	mk_sl_cui_uint8_from_bi_uint(&block->m_uint8s[idx], &ui);
	rest = mk_lib_crypto_hash_block_sha1_x86_msvc_block_len - idx - 1;
	if(rest >= 8)
	{
		for(i = 0; i != rest - 8; ++i)
		{
			mk_sl_cui_uint8_set_zero(&block->m_uint8s[idx + 1 + i]);
		}
	}
	else
	{
		for(i = 0; i != rest; ++i)
		{
			mk_sl_cui_uint8_set_zero(&block->m_uint8s[idx + 1 + i]);
		}
		mk_lib_crypto_hash_block_sha1_x86_msvc_append_blocks(sha1, block, 1);
		for(i = 0; i != mk_lib_crypto_hash_block_sha1_x86_msvc_block_len - 8; ++i)
		{
			mk_sl_cui_uint8_set_zero(&block->m_uint8s[i]);
		}
	}
	mk_sl_uint_64_to_8_be(&ta, &block->m_uint8s[mk_lib_crypto_hash_block_sha1_x86_msvc_block_len - 8]);
	mk_lib_crypto_hash_block_sha1_x86_msvc_append_blocks(sha1, block, 1);
	for(i = 0; i != 5; ++i)
	{
		mk_sl_uint_32_to_8_be(&sha1->m_state[i], &digest->m_uint8s[i * 4]);
	}
}

#else

mk_lang_jumbo void mk_lib_crypto_hash_block_sha1_x86_msvc_init(mk_lib_crypto_hash_block_sha1_x86_msvc_pt const sha1) mk_lang_noexcept
{
	((void)(sha1));
	mk_lang_assert(0);
}

mk_lang_jumbo void mk_lib_crypto_hash_block_sha1_x86_msvc_append_blocks(mk_lib_crypto_hash_block_sha1_x86_msvc_pt const sha1, mk_lib_crypto_hash_block_sha1_x86_msvc_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	((void)(sha1));
	((void)(pblocks));
	((void)(nblocks));
	mk_lang_assert(0);
}

mk_lang_jumbo void mk_lib_crypto_hash_block_sha1_x86_msvc_finish(mk_lib_crypto_hash_block_sha1_x86_msvc_pt const sha1, mk_lib_crypto_hash_block_sha1_x86_msvc_block_pt const block, int const idx, mk_lib_crypto_hash_block_sha1_x86_msvc_digest_pt const digest) mk_lang_noexcept
{
	((void)(sha1));
	((void)(block));
	((void)(idx));
	((void)(digest));
	mk_lang_assert(0);
}

#endif
