#ifndef mk_include_guard_mk_lib_crypto_hash_block_sha2_base_32bit_x86_c
#define mk_include_guard_mk_lib_crypto_hash_block_sha2_base_32bit_x86_c
#include "mk_lib_crypto_hash_block_sha2_base_32bit_x86.h"


#include "mk_lang_compiler.h"
#include "mk_lang_msvc.h"
#if (mk_lang_msvc_ver >= mk_lang_msvc_ver_2015 || mk_lang_compiler_is_at_least_gcc(11, 1)) && (mk_lang_arch_is_x8632 || mk_lang_arch_is_x8664)


#include "mk_lang_alignas.h"
#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_attribute.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_static_param.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_bitops_bulk.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"

#include <emmintrin.h> /* SSE2 _mm_add_epi32 _mm_load_si128 _mm_set_epi64x _mm_shuffle_epi32 _mm_store_si128 */
#include <tmmintrin.h> /* SSSE3 _mm_alignr_epi8 _mm_shuffle_epi8 */
#include <smmintrin.h> /* SSE4.1 _mm_blend_epi16 */
#include <immintrin.h> /* SHA _mm_sha256msg1_epu32 _mm_sha256msg2_epu32 _mm_sha256rnds2_epu32 */
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2015 && mk_lang_compiler_is_at_least_clang(1, 0)
#include <intrin.h> /* clang-cl */
#endif


#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2015 && !mk_lang_compiler_is_at_least_clang(1, 0)
#pragma intrinsic(_mm_add_epi32)
#pragma intrinsic(_mm_alignr_epi8)
#pragma intrinsic(_mm_blend_epi16)
#pragma intrinsic(_mm_blend_epi32)
#pragma intrinsic(_mm_load_si128)
#pragma intrinsic(_mm_set_epi64x)
#pragma intrinsic(_mm_sha256msg1_epu32)
#pragma intrinsic(_mm_sha256msg2_epu32)
#pragma intrinsic(_mm_sha256rnds2_epu32)
#pragma intrinsic(_mm_shuffle_epi32)
#pragma intrinsic(_mm_shuffle_epi8)
#pragma intrinsic(_mm_store_si128)
#endif


union mk_lib_crypto_hash_block_sha2_base_32bit_x86_block2_data_u
{
	mk_sl_cui_uint32_t m_uint32s[16];
	mk_lib_crypto_hash_block_sha2_base_32bit_x86_block_t m_align;
};
typedef union mk_lib_crypto_hash_block_sha2_base_32bit_x86_block2_data_u mk_lib_crypto_hash_block_sha2_base_32bit_x86_block2_data_t;
struct mk_lib_crypto_hash_block_sha2_base_32bit_x86_block2_s
{
	mk_lang_alignas(sizeof(mk_lib_crypto_hash_block_sha2_base_32bit_x86_block2_data_t)) mk_lib_crypto_hash_block_sha2_base_32bit_x86_block2_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_sha2_base_32bit_x86_block2_s mk_lib_crypto_hash_block_sha2_base_32bit_x86_block2_t;
mk_lang_typedef(mk_lib_crypto_hash_block_sha2_base_32bit_x86_block);

union mk_lib_crypto_hash_block_sha2_base_32bit_x86_table_data_u
{
	mk_sl_cui_uint32_t m_uint32s[64];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_sha2_base_32bit_x86_table_data_u mk_lib_crypto_hash_block_sha2_base_32bit_x86_table_data_t;
struct mk_lib_crypto_hash_block_sha2_base_32bit_x86_table_s
{
	mk_lang_alignas(sizeof(mk_lib_crypto_hash_block_sha2_base_32bit_x86_table_data_t)) mk_lib_crypto_hash_block_sha2_base_32bit_x86_table_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_sha2_base_32bit_x86_table_s mk_lib_crypto_hash_block_sha2_base_32bit_x86_table_t;


mk_lang_constexpr_static_inline mk_lib_crypto_hash_block_sha2_base_32bit_x86_table_t const mk_lib_crypto_hash_block_sha2_base_32bit_x86_k_table =
{{{
	mk_sl_cui_uint32_c(0x428a2f98ul), mk_sl_cui_uint32_c(0x71374491ul), mk_sl_cui_uint32_c(0xb5c0fbcful), mk_sl_cui_uint32_c(0xe9b5dba5ul),
	mk_sl_cui_uint32_c(0x3956c25bul), mk_sl_cui_uint32_c(0x59f111f1ul), mk_sl_cui_uint32_c(0x923f82a4ul), mk_sl_cui_uint32_c(0xab1c5ed5ul),
	mk_sl_cui_uint32_c(0xd807aa98ul), mk_sl_cui_uint32_c(0x12835b01ul), mk_sl_cui_uint32_c(0x243185beul), mk_sl_cui_uint32_c(0x550c7dc3ul),
	mk_sl_cui_uint32_c(0x72be5d74ul), mk_sl_cui_uint32_c(0x80deb1feul), mk_sl_cui_uint32_c(0x9bdc06a7ul), mk_sl_cui_uint32_c(0xc19bf174ul),
	mk_sl_cui_uint32_c(0xe49b69c1ul), mk_sl_cui_uint32_c(0xefbe4786ul), mk_sl_cui_uint32_c(0x0fc19dc6ul), mk_sl_cui_uint32_c(0x240ca1ccul),
	mk_sl_cui_uint32_c(0x2de92c6ful), mk_sl_cui_uint32_c(0x4a7484aaul), mk_sl_cui_uint32_c(0x5cb0a9dcul), mk_sl_cui_uint32_c(0x76f988daul),
	mk_sl_cui_uint32_c(0x983e5152ul), mk_sl_cui_uint32_c(0xa831c66dul), mk_sl_cui_uint32_c(0xb00327c8ul), mk_sl_cui_uint32_c(0xbf597fc7ul),
	mk_sl_cui_uint32_c(0xc6e00bf3ul), mk_sl_cui_uint32_c(0xd5a79147ul), mk_sl_cui_uint32_c(0x06ca6351ul), mk_sl_cui_uint32_c(0x14292967ul),
	mk_sl_cui_uint32_c(0x27b70a85ul), mk_sl_cui_uint32_c(0x2e1b2138ul), mk_sl_cui_uint32_c(0x4d2c6dfcul), mk_sl_cui_uint32_c(0x53380d13ul),
	mk_sl_cui_uint32_c(0x650a7354ul), mk_sl_cui_uint32_c(0x766a0abbul), mk_sl_cui_uint32_c(0x81c2c92eul), mk_sl_cui_uint32_c(0x92722c85ul),
	mk_sl_cui_uint32_c(0xa2bfe8a1ul), mk_sl_cui_uint32_c(0xa81a664bul), mk_sl_cui_uint32_c(0xc24b8b70ul), mk_sl_cui_uint32_c(0xc76c51a3ul),
	mk_sl_cui_uint32_c(0xd192e819ul), mk_sl_cui_uint32_c(0xd6990624ul), mk_sl_cui_uint32_c(0xf40e3585ul), mk_sl_cui_uint32_c(0x106aa070ul),
	mk_sl_cui_uint32_c(0x19a4c116ul), mk_sl_cui_uint32_c(0x1e376c08ul), mk_sl_cui_uint32_c(0x2748774cul), mk_sl_cui_uint32_c(0x34b0bcb5ul),
	mk_sl_cui_uint32_c(0x391c0cb3ul), mk_sl_cui_uint32_c(0x4ed8aa4aul), mk_sl_cui_uint32_c(0x5b9cca4ful), mk_sl_cui_uint32_c(0x682e6ff3ul),
	mk_sl_cui_uint32_c(0x748f82eeul), mk_sl_cui_uint32_c(0x78a5636ful), mk_sl_cui_uint32_c(0x84c87814ul), mk_sl_cui_uint32_c(0x8cc70208ul),
	mk_sl_cui_uint32_c(0x90befffaul), mk_sl_cui_uint32_c(0xa4506cebul), mk_sl_cui_uint32_c(0xbef9a3f7ul), mk_sl_cui_uint32_c(0xc67178f2ul),
}}};


mk_lang_jumbo mk_lang_types_void_t mk_lang_attribute_target("sse2,ssse3,sse4.1,sha") mk_lib_crypto_hash_block_sha2_base_32bit_x86_init(mk_lib_crypto_hash_block_sha2_base_32bit_x86_pt const sha2_base_32bit_x86, mk_lang_static_param(mk_sl_cui_uint32_ct, iv, 8)) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_base_32bit_x86_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_base_32bit_x86_digest_t) == 32);

	mk_lang_assert(sha2_base_32bit_x86);
	mk_lang_assert(iv);
	mk_lang_assert((((mk_lang_types_uintptr_t)(&sha2_base_32bit_x86->m_state[0])) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(&iv[0])) & 0xf) == 0);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_ssse3());
	mk_lang_assert(mk_lang_cpuid_has_sse41());
	mk_lang_assert(mk_lang_cpuid_has_sha());

	mk_lib_crypto_bitops_bulk_uint32_8_memcpy(&sha2_base_32bit_x86->m_state[0], &iv[0]);
	mk_sl_cui_uint64_set_zero(&sha2_base_32bit_x86->m_len);
}

mk_lang_jumbo mk_lang_types_void_t mk_lang_attribute_target("sse2,ssse3,sse4.1,sha") mk_lib_crypto_hash_block_sha2_base_32bit_x86_append_blocks(mk_lib_crypto_hash_block_sha2_base_32bit_x86_pt const sha2_base_32bit_x86, mk_lib_crypto_hash_block_sha2_base_32bit_x86_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	#define mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(a, b, c, d) ((((a) & 0x3) << (3 * 2)) | (((b) & 0x3) << (2 * 2)) | (((c) & 0x3) << (1 * 2)) | (((d) & 0x3) << (0 * 2)))
	#define mk_lib_crypto_hash_block_sha2_base_32bit_x86_blend_epi32(a, b, c, d) ((((a) & 0x1) << (3 * 1)) | (((b) & 0x1) << (2 * 1)) | (((c) & 0x1) << (1 * 1)) | (((d) & 0x1) << (0 * 1)))
	#define mk_lib_crypto_hash_block_sha2_base_32bit_x86_alignr_epi8(a) (((a) & 0x3) * 4)
	#define mk_lib_crypto_hash_block_sha2_base_32bit_x86_blend_epi16(a, b, c, d, e, f, g, h) ((((a) & 0x1) << 7) | (((b) & 0x1) << 6) | (((c) & 0x1) << 5) | (((d) & 0x1) << 4) | (((e) & 0x1) << 3) | (((f) & 0x1) << 2) | (((g) & 0x1) << 1) | (((h) & 0x1) << 0))
	#define mk_mm_blend_epi32(a, b, c) _mm_blend_epi16((a), (b), mk_lib_crypto_hash_block_sha2_base_32bit_x86_blend_epi16((((c) >> 3) & 0x1), (((c) >> 3) & 0x1), (((c) >> 2) & 0x1), (((c) >> 2) & 0x1), (((c) >> 1) & 0x1), (((c) >> 1) & 0x1), (((c) >> 0) & 0x1), (((c) >> 0) & 0x1)))
	#define any 0x0

	mk_sl_cui_uint64_t ta;
	__m128i reverse;
	__m128i state_0;
	__m128i state_1;
	__m128i tmp;
	mk_lang_types_usize_t iblock;
	mk_sl_cui_uint8_pct ptr;
	__m128i old_0;
	__m128i old_1;
	__m128i msg_0;
	__m128i msg;
	__m128i msg_1;
	__m128i msg_2;
	__m128i msg_3;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(sha2_base_32bit_x86);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha2_base_32bit_x86_block_len_v);
	mk_lang_assert((((mk_lang_types_uintptr_t)(&sha2_base_32bit_x86->m_state[0])) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(pblocks)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(&mk_lib_crypto_hash_block_sha2_base_32bit_x86_k_table.m_data.m_uint32s[0])) & 0xf) == 0);
	mk_lang_assert(sizeof(mk_sl_cui_uint32_t) == sizeof(int));
	mk_lang_assert(sizeof(mk_sl_cui_uint32_t) == 4);
	mk_lang_assert(mk_lang_alignof(mk_sl_cui_uint32_t) == mk_lang_alignof(int));
	mk_lang_assert(mk_lang_alignof(mk_sl_cui_uint32_t) == 4);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_ssse3());
	mk_lang_assert(mk_lang_cpuid_has_sse41());
	mk_lang_assert(mk_lang_cpuid_has_sha());
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(nblocks != 0)
	{
		mk_sl_cui_uint64_from_bi_usize(&ta, &nblocks);
		mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&sha2_base_32bit_x86->m_len, &ta));
		mk_sl_cui_uint64_add2_wrap_cid_cod(&sha2_base_32bit_x86->m_len, &ta);
		reverse = _mm_set_epi64x(0x0c0d0e0f08090a0bull, 0x0405060700010203ull);
		#include "mk_lang_warning_clang_push_cast_align.h"
		state_0 = _mm_load_si128(((__m128i const*)(&sha2_base_32bit_x86->m_state[0])));
		state_1 = _mm_load_si128(((__m128i const*)(&sha2_base_32bit_x86->m_state[4])));
		#include "mk_lang_warning_clang_pop.h"
		tmp = _mm_shuffle_epi32(state_0, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(0x2, 0x3, 0x0, 0x1));
		state_1 = _mm_shuffle_epi32(state_1, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(0x0, 0x1, 0x2, 0x3));
		state_0 = _mm_alignr_epi8(tmp, state_1, mk_lib_crypto_hash_block_sha2_base_32bit_x86_alignr_epi8(2));
		state_1 = mk_mm_blend_epi32(state_1, tmp, mk_lib_crypto_hash_block_sha2_base_32bit_x86_blend_epi32(0x1, 0x1, 0x0, 0x0));
		for(iblock = 0, ptr = &pblocks->m_data.m_uint8s[0]; iblock != nblocks; ++iblock, ptr += mk_lib_crypto_hash_block_sha2_base_32bit_x86_block_len_v)
		{
			#include "mk_lang_warning_clang_push_cast_align.h"
			old_0 = state_0;
			old_1 = state_1;
			msg_0 = _mm_load_si128(((__m128i const*)(&ptr[0 * 16])));
			msg_0 = _mm_shuffle_epi8(msg_0, reverse);
			tmp = _mm_load_si128(((__m128i const*)(&mk_lib_crypto_hash_block_sha2_base_32bit_x86_k_table.m_data.m_uint32s[0 * 4])));
			msg = _mm_add_epi32(msg_0, tmp);
			state_1 = _mm_sha256rnds2_epu32(state_1, state_0, msg);
			msg = _mm_shuffle_epi32(msg, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(any, any, 0x3, 0x2));
			state_0 = _mm_sha256rnds2_epu32(state_0, state_1, msg);
			msg_1 = _mm_load_si128(((__m128i const*)(&ptr[1 * 16])));
			msg_1 = _mm_shuffle_epi8(msg_1, reverse);
			tmp = _mm_load_si128(((__m128i const*)(&mk_lib_crypto_hash_block_sha2_base_32bit_x86_k_table.m_data.m_uint32s[1 * 4])));
			msg = _mm_add_epi32(msg_1, tmp);
			state_1 = _mm_sha256rnds2_epu32(state_1, state_0, msg);
			msg = _mm_shuffle_epi32(msg, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(any, any, 0x3, 0x2));
			state_0 = _mm_sha256rnds2_epu32(state_0, state_1, msg);
			msg_2 = _mm_load_si128(((__m128i const*)(&ptr[2 * 16])));
			msg_2 = _mm_shuffle_epi8(msg_2, reverse);
			tmp = _mm_load_si128(((__m128i const*)(&mk_lib_crypto_hash_block_sha2_base_32bit_x86_k_table.m_data.m_uint32s[2 * 4])));
			msg = _mm_add_epi32(msg_2, tmp);
			state_1 = _mm_sha256rnds2_epu32(state_1, state_0, msg);
			msg = _mm_shuffle_epi32(msg, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(any, any, 0x3, 0x2));
			state_0 = _mm_sha256rnds2_epu32(state_0, state_1, msg);
			msg_3 = _mm_load_si128(((__m128i const*)(&ptr[3 * 16])));
			msg_3 = _mm_shuffle_epi8(msg_3, reverse);
			tmp = _mm_load_si128(((__m128i const*)(&mk_lib_crypto_hash_block_sha2_base_32bit_x86_k_table.m_data.m_uint32s[3 * 4])));
			msg = _mm_add_epi32(msg_3, tmp);
			state_1 = _mm_sha256rnds2_epu32(state_1, state_0, msg);
			msg = _mm_shuffle_epi32(msg, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(any, any, 0x3, 0x2));
			state_0 = _mm_sha256rnds2_epu32(state_0, state_1, msg);
			msg_0 = _mm_sha256msg1_epu32(msg_0, msg_1);
			tmp = _mm_alignr_epi8(msg_3, msg_2, mk_lib_crypto_hash_block_sha2_base_32bit_x86_alignr_epi8(1));
			msg_0 = _mm_add_epi32(msg_0, tmp);
			msg_0 = _mm_sha256msg2_epu32(msg_0, msg_3);
			tmp = _mm_load_si128(((__m128i const*)(&mk_lib_crypto_hash_block_sha2_base_32bit_x86_k_table.m_data.m_uint32s[4 * 4])));
			msg = _mm_add_epi32(msg_0, tmp);
			state_1 = _mm_sha256rnds2_epu32(state_1, state_0, msg);
			msg = _mm_shuffle_epi32(msg, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(any, any, 0x3, 0x2));
			state_0 = _mm_sha256rnds2_epu32(state_0, state_1, msg);
			msg_1 = _mm_sha256msg1_epu32(msg_1, msg_2);
			tmp = _mm_alignr_epi8(msg_0, msg_3, mk_lib_crypto_hash_block_sha2_base_32bit_x86_alignr_epi8(1));
			msg_1 = _mm_add_epi32(msg_1, tmp);
			msg_1 = _mm_sha256msg2_epu32(msg_1, msg_0);
			tmp = _mm_load_si128(((__m128i const*)(&mk_lib_crypto_hash_block_sha2_base_32bit_x86_k_table.m_data.m_uint32s[5 * 4])));
			msg = _mm_add_epi32(msg_1, tmp);
			state_1 = _mm_sha256rnds2_epu32(state_1, state_0, msg);
			msg = _mm_shuffle_epi32(msg, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(any, any, 0x3, 0x2));
			state_0 = _mm_sha256rnds2_epu32(state_0, state_1, msg);
			msg_2 = _mm_sha256msg1_epu32(msg_2, msg_3);
			tmp = _mm_alignr_epi8(msg_1, msg_0, mk_lib_crypto_hash_block_sha2_base_32bit_x86_alignr_epi8(1));
			msg_2 = _mm_add_epi32(msg_2, tmp);
			msg_2 = _mm_sha256msg2_epu32(msg_2, msg_1);
			tmp = _mm_load_si128(((__m128i const*)(&mk_lib_crypto_hash_block_sha2_base_32bit_x86_k_table.m_data.m_uint32s[6 * 4])));
			msg = _mm_add_epi32(msg_2, tmp);
			state_1 = _mm_sha256rnds2_epu32(state_1, state_0, msg);
			msg = _mm_shuffle_epi32(msg, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(any, any, 0x3, 0x2));
			state_0 = _mm_sha256rnds2_epu32(state_0, state_1, msg);
			msg_3 = _mm_sha256msg1_epu32(msg_3, msg_0);
			tmp = _mm_alignr_epi8(msg_2, msg_1, mk_lib_crypto_hash_block_sha2_base_32bit_x86_alignr_epi8(1));
			msg_3 = _mm_add_epi32(msg_3, tmp);
			msg_3 = _mm_sha256msg2_epu32(msg_3, msg_2);
			tmp = _mm_load_si128(((__m128i const*)(&mk_lib_crypto_hash_block_sha2_base_32bit_x86_k_table.m_data.m_uint32s[7 * 4])));
			msg = _mm_add_epi32(msg_3, tmp);
			state_1 = _mm_sha256rnds2_epu32(state_1, state_0, msg);
			msg = _mm_shuffle_epi32(msg, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(any, any, 0x3, 0x2));
			state_0 = _mm_sha256rnds2_epu32(state_0, state_1, msg);
			msg_0 = _mm_sha256msg1_epu32(msg_0, msg_1);
			tmp = _mm_alignr_epi8(msg_3, msg_2, mk_lib_crypto_hash_block_sha2_base_32bit_x86_alignr_epi8(1));
			msg_0 = _mm_add_epi32(msg_0, tmp);
			msg_0 = _mm_sha256msg2_epu32(msg_0, msg_3);
			tmp = _mm_load_si128(((__m128i const*)(&mk_lib_crypto_hash_block_sha2_base_32bit_x86_k_table.m_data.m_uint32s[8 * 4])));
			msg = _mm_add_epi32(msg_0, tmp);
			state_1 = _mm_sha256rnds2_epu32(state_1, state_0, msg);
			msg = _mm_shuffle_epi32(msg, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(any, any, 0x3, 0x2));
			state_0 = _mm_sha256rnds2_epu32(state_0, state_1, msg);
			msg_1 = _mm_sha256msg1_epu32(msg_1, msg_2);
			tmp = _mm_alignr_epi8(msg_0, msg_3, mk_lib_crypto_hash_block_sha2_base_32bit_x86_alignr_epi8(1));
			msg_1 = _mm_add_epi32(msg_1, tmp);
			msg_1 = _mm_sha256msg2_epu32(msg_1, msg_0);
			tmp = _mm_load_si128(((__m128i const*)(&mk_lib_crypto_hash_block_sha2_base_32bit_x86_k_table.m_data.m_uint32s[9 * 4])));
			msg = _mm_add_epi32(msg_1, tmp);
			state_1 = _mm_sha256rnds2_epu32(state_1, state_0, msg);
			msg = _mm_shuffle_epi32(msg, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(any, any, 0x3, 0x2));
			state_0 = _mm_sha256rnds2_epu32(state_0, state_1, msg);
			msg_2 = _mm_sha256msg1_epu32(msg_2, msg_3);
			tmp = _mm_alignr_epi8(msg_1, msg_0, mk_lib_crypto_hash_block_sha2_base_32bit_x86_alignr_epi8(1));
			msg_2 = _mm_add_epi32(msg_2, tmp);
			msg_2 = _mm_sha256msg2_epu32(msg_2, msg_1);
			tmp = _mm_load_si128(((__m128i const*)(&mk_lib_crypto_hash_block_sha2_base_32bit_x86_k_table.m_data.m_uint32s[10 * 4])));
			msg = _mm_add_epi32(msg_2, tmp);
			state_1 = _mm_sha256rnds2_epu32(state_1, state_0, msg);
			msg = _mm_shuffle_epi32(msg, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(any, any, 0x3, 0x2));
			state_0 = _mm_sha256rnds2_epu32(state_0, state_1, msg);
			msg_3 = _mm_sha256msg1_epu32(msg_3, msg_0);
			tmp = _mm_alignr_epi8(msg_2, msg_1, mk_lib_crypto_hash_block_sha2_base_32bit_x86_alignr_epi8(1));
			msg_3 = _mm_add_epi32(msg_3, tmp);
			msg_3 = _mm_sha256msg2_epu32(msg_3, msg_2);
			tmp = _mm_load_si128(((__m128i const*)(&mk_lib_crypto_hash_block_sha2_base_32bit_x86_k_table.m_data.m_uint32s[11 * 4])));
			msg = _mm_add_epi32(msg_3, tmp);
			state_1 = _mm_sha256rnds2_epu32(state_1, state_0, msg);
			msg = _mm_shuffle_epi32(msg, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(any, any, 0x3, 0x2));
			state_0 = _mm_sha256rnds2_epu32(state_0, state_1, msg);
			msg_0 = _mm_sha256msg1_epu32(msg_0, msg_1);
			tmp = _mm_alignr_epi8(msg_3, msg_2, mk_lib_crypto_hash_block_sha2_base_32bit_x86_alignr_epi8(1));
			msg_0 = _mm_add_epi32(msg_0, tmp);
			msg_0 = _mm_sha256msg2_epu32(msg_0, msg_3);
			tmp = _mm_load_si128(((__m128i const*)(&mk_lib_crypto_hash_block_sha2_base_32bit_x86_k_table.m_data.m_uint32s[12 * 4])));
			msg = _mm_add_epi32(msg_0, tmp);
			state_1 = _mm_sha256rnds2_epu32(state_1, state_0, msg);
			msg = _mm_shuffle_epi32(msg, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(any, any, 0x3, 0x2));
			state_0 = _mm_sha256rnds2_epu32(state_0, state_1, msg);
			msg_1 = _mm_sha256msg1_epu32(msg_1, msg_2);
			tmp = _mm_alignr_epi8(msg_0, msg_3, mk_lib_crypto_hash_block_sha2_base_32bit_x86_alignr_epi8(1));
			msg_1 = _mm_add_epi32(msg_1, tmp);
			msg_1 = _mm_sha256msg2_epu32(msg_1, msg_0);
			tmp = _mm_load_si128(((__m128i const*)(&mk_lib_crypto_hash_block_sha2_base_32bit_x86_k_table.m_data.m_uint32s[13 * 4])));
			msg = _mm_add_epi32(msg_1, tmp);
			state_1 = _mm_sha256rnds2_epu32(state_1, state_0, msg);
			msg = _mm_shuffle_epi32(msg, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(any, any, 0x3, 0x2));
			state_0 = _mm_sha256rnds2_epu32(state_0, state_1, msg);
			msg_2 = _mm_sha256msg1_epu32(msg_2, msg_3);
			tmp = _mm_alignr_epi8(msg_1, msg_0, mk_lib_crypto_hash_block_sha2_base_32bit_x86_alignr_epi8(1));
			msg_2 = _mm_add_epi32(msg_2, tmp);
			msg_2 = _mm_sha256msg2_epu32(msg_2, msg_1);
			tmp = _mm_load_si128(((__m128i const*)(&mk_lib_crypto_hash_block_sha2_base_32bit_x86_k_table.m_data.m_uint32s[14 * 4])));
			msg = _mm_add_epi32(msg_2, tmp);
			state_1 = _mm_sha256rnds2_epu32(state_1, state_0, msg);
			msg = _mm_shuffle_epi32(msg, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(any, any, 0x3, 0x2));
			state_0 = _mm_sha256rnds2_epu32(state_0, state_1, msg);
			msg_3 = _mm_sha256msg1_epu32(msg_3, msg_0);
			tmp = _mm_alignr_epi8(msg_2, msg_1, mk_lib_crypto_hash_block_sha2_base_32bit_x86_alignr_epi8(1));
			msg_3 = _mm_add_epi32(msg_3, tmp);
			msg_3 = _mm_sha256msg2_epu32(msg_3, msg_2);
			tmp = _mm_load_si128(((__m128i const*)(&mk_lib_crypto_hash_block_sha2_base_32bit_x86_k_table.m_data.m_uint32s[15 * 4])));
			msg = _mm_add_epi32(msg_3, tmp);
			state_1 = _mm_sha256rnds2_epu32(state_1, state_0, msg);
			msg = _mm_shuffle_epi32(msg, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(any, any, 0x3, 0x2));
			state_0 = _mm_sha256rnds2_epu32(state_0, state_1, msg);
			state_0 = _mm_add_epi32(state_0, old_0);
			state_1 = _mm_add_epi32(state_1, old_1);
			#include "mk_lang_warning_clang_pop.h"
		}
		tmp = _mm_shuffle_epi32(state_0, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(0x0, 0x1, 0x2, 0x3));
		state_1 = _mm_shuffle_epi32(state_1, mk_lib_crypto_hash_block_sha2_base_32bit_x86_shuffle_epi32(0x2, 0x3, 0x0, 0x1));
		state_0 = mk_mm_blend_epi32(tmp, state_1, mk_lib_crypto_hash_block_sha2_base_32bit_x86_blend_epi32(0x1, 0x1, 0x0, 0x0));
		state_1 = _mm_alignr_epi8(state_1, tmp, mk_lib_crypto_hash_block_sha2_base_32bit_x86_alignr_epi8(2));
		#include "mk_lang_warning_clang_push_cast_align.h"
		_mm_store_si128(((__m128i*)(&sha2_base_32bit_x86->m_state[0])), state_0);
		_mm_store_si128(((__m128i*)(&sha2_base_32bit_x86->m_state[4])), state_1);
		#include "mk_lang_warning_clang_pop.h"
	}

	#undef any
}

mk_lang_jumbo mk_lang_types_void_t mk_lang_attribute_target("sse2,ssse3,sse4.1,sha") mk_lib_crypto_hash_block_sha2_base_32bit_x86_finish(mk_lib_crypto_hash_block_sha2_base_32bit_x86_pt const sha2_base_32bit_x86, mk_lib_crypto_hash_block_sha2_base_32bit_x86_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_sha2_base_32bit_x86_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_types_uint_t ui;
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_lang_types_sint_t rest;
	mk_lang_types_sint_t ptr;

	mk_lang_static_assert(mk_lang_countof(sha2_base_32bit_x86->m_state) == 8);

	mk_lang_assert(sha2_base_32bit_x86);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_sha2_base_32bit_x86_block_len_v);
	mk_lang_assert(digest);
	mk_lang_assert((((mk_lang_types_uintptr_t)(&sha2_base_32bit_x86->m_state[0])) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(&block->m_data.m_uint8s[0])) & 0xf) == 0);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_ssse3());
	mk_lang_assert(mk_lang_cpuid_has_sse41());
	mk_lang_assert(mk_lang_cpuid_has_sha());

	ui = mk_lib_crypto_hash_block_sha2_base_32bit_x86_block_len_v; mk_sl_cui_uint64_from_bi_uint(&ta, &ui);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_mul(&sha2_base_32bit_x86->m_len, &ta));
	mk_sl_cui_uint64_shl3(&sha2_base_32bit_x86->m_len, 6, &ta);
	mk_sl_cui_uint64_from_bi_sint(&tb, &idx);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&ta, &tb));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&ta, &tb);
	ui = 8; mk_sl_cui_uint64_from_bi_uint(&tb, &ui);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_mul(&ta, &tb));
	mk_sl_cui_uint64_shl2(&ta, 3);

	ui = 0x80; mk_sl_cui_uint8_from_bi_uint(&block->m_data.m_uint8s[idx], &ui);
	rest = mk_lib_crypto_hash_block_sha2_base_32bit_x86_block_len_v - idx - 1;
	mk_lang_assert(rest >= 0 && rest <= mk_lib_crypto_hash_block_sha2_base_32bit_x86_block_len_v - 1);
	ptr = idx + 1;
	if(rest < mk_sl_cui_uint64_size_bytes_v)
	{
		mk_sl_cui_uint8_memclr_fn(&block->m_data.m_uint8s[ptr], ((mk_lang_types_usize_t)(rest)));
		mk_lib_crypto_hash_block_sha2_base_32bit_x86_append_blocks(sha2_base_32bit_x86, block, 1);
		ptr = 0; rest = mk_lib_crypto_hash_block_sha2_base_32bit_x86_block_len_v;
	}
	mk_sl_cui_uint8_memclr_fn(&block->m_data.m_uint8s[ptr], ((mk_lang_types_usize_t)(rest - mk_sl_cui_uint64_size_bytes_v)));

	mk_sl_uint_convert_64_8_be_to_sml(&ta, &block->m_data.m_uint8s[((mk_lang_types_sint_t)(mk_lib_crypto_hash_block_sha2_base_32bit_x86_block_len_v)) - ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v))]);
	mk_lib_crypto_hash_block_sha2_base_32bit_x86_append_blocks(sha2_base_32bit_x86, block, 1);
	mk_sl_uint_convert_32_8_be_to_sml_multi(&sha2_base_32bit_x86->m_state[0], &digest->m_data.m_uint8s[0], mk_lang_countof(sha2_base_32bit_x86->m_state));
}


#endif
#endif
