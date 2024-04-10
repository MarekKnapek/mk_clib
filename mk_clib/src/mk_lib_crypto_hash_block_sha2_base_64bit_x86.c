#include "mk_lib_crypto_hash_block_sha2_base_64bit_x86.h"

#include "mk_lang_alignas.h"
#include "mk_lang_alignof.h"
#include "mk_lang_arch.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_gnuc.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


#if mk_lang_gnuc_is_at_least(14, 0) && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664)


#include <emmintrin.h> /* SSE2 _mm_set_epi64x */
#include <immintrin.h> /* AVX _mm256_castsi128_si256 _mm256_castsi256_si128 _mm256_load_si256 _mm256_store_si256 */
#include <immintrin.h> /* AVX2 _mm256_add_epi64 _mm256_blend_epi32 _mm256_permute4x64_epi64 _mm256_shuffle_epi8 */
#include <immintrin.h> /* SHA512 _mm256_sha512msg1_epi64 _mm256_sha512msg2_epi64 _mm256_sha512rnds2_epi64 */


union mk_lib_crypto_hash_block_sha2_base_64bit_x86_table_data_u
{
	mk_sl_cui_uint64_t m_uint64s[80];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_sha2_base_64bit_x86_table_data_u mk_lib_crypto_hash_block_sha2_base_64bit_x86_table_data_t;

struct mk_lib_crypto_hash_block_sha2_base_64bit_x86_table_s
{
	mk_lang_alignas(64) mk_lib_crypto_hash_block_sha2_base_64bit_x86_table_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_sha2_base_64bit_x86_table_s mk_lib_crypto_hash_block_sha2_base_64bit_x86_table_t;


mk_lang_constexpr_static_inline mk_lib_crypto_hash_block_sha2_base_64bit_x86_table_t const s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table =
{{{
	mk_sl_cui_uint64_c(0x428a2f98ul, 0xd728ae22ul), mk_sl_cui_uint64_c(0x71374491ul, 0x23ef65cdul), mk_sl_cui_uint64_c(0xb5c0fbcful, 0xec4d3b2ful), mk_sl_cui_uint64_c(0xe9b5dba5ul, 0x8189dbbcul),
	mk_sl_cui_uint64_c(0x3956c25bul, 0xf348b538ul), mk_sl_cui_uint64_c(0x59f111f1ul, 0xb605d019ul), mk_sl_cui_uint64_c(0x923f82a4ul, 0xaf194f9bul), mk_sl_cui_uint64_c(0xab1c5ed5ul, 0xda6d8118ul),
	mk_sl_cui_uint64_c(0xd807aa98ul, 0xa3030242ul), mk_sl_cui_uint64_c(0x12835b01ul, 0x45706fbeul), mk_sl_cui_uint64_c(0x243185beul, 0x4ee4b28cul), mk_sl_cui_uint64_c(0x550c7dc3ul, 0xd5ffb4e2ul),
	mk_sl_cui_uint64_c(0x72be5d74ul, 0xf27b896ful), mk_sl_cui_uint64_c(0x80deb1feul, 0x3b1696b1ul), mk_sl_cui_uint64_c(0x9bdc06a7ul, 0x25c71235ul), mk_sl_cui_uint64_c(0xc19bf174ul, 0xcf692694ul),
	mk_sl_cui_uint64_c(0xe49b69c1ul, 0x9ef14ad2ul), mk_sl_cui_uint64_c(0xefbe4786ul, 0x384f25e3ul), mk_sl_cui_uint64_c(0x0fc19dc6ul, 0x8b8cd5b5ul), mk_sl_cui_uint64_c(0x240ca1ccul, 0x77ac9c65ul),
	mk_sl_cui_uint64_c(0x2de92c6ful, 0x592b0275ul), mk_sl_cui_uint64_c(0x4a7484aaul, 0x6ea6e483ul), mk_sl_cui_uint64_c(0x5cb0a9dcul, 0xbd41fbd4ul), mk_sl_cui_uint64_c(0x76f988daul, 0x831153b5ul),
	mk_sl_cui_uint64_c(0x983e5152ul, 0xee66dfabul), mk_sl_cui_uint64_c(0xa831c66dul, 0x2db43210ul), mk_sl_cui_uint64_c(0xb00327c8ul, 0x98fb213ful), mk_sl_cui_uint64_c(0xbf597fc7ul, 0xbeef0ee4ul),
	mk_sl_cui_uint64_c(0xc6e00bf3ul, 0x3da88fc2ul), mk_sl_cui_uint64_c(0xd5a79147ul, 0x930aa725ul), mk_sl_cui_uint64_c(0x06ca6351ul, 0xe003826ful), mk_sl_cui_uint64_c(0x14292967ul, 0x0a0e6e70ul),
	mk_sl_cui_uint64_c(0x27b70a85ul, 0x46d22ffcul), mk_sl_cui_uint64_c(0x2e1b2138ul, 0x5c26c926ul), mk_sl_cui_uint64_c(0x4d2c6dfcul, 0x5ac42aedul), mk_sl_cui_uint64_c(0x53380d13ul, 0x9d95b3dful),
	mk_sl_cui_uint64_c(0x650a7354ul, 0x8baf63deul), mk_sl_cui_uint64_c(0x766a0abbul, 0x3c77b2a8ul), mk_sl_cui_uint64_c(0x81c2c92eul, 0x47edaee6ul), mk_sl_cui_uint64_c(0x92722c85ul, 0x1482353bul),
	mk_sl_cui_uint64_c(0xa2bfe8a1ul, 0x4cf10364ul), mk_sl_cui_uint64_c(0xa81a664bul, 0xbc423001ul), mk_sl_cui_uint64_c(0xc24b8b70ul, 0xd0f89791ul), mk_sl_cui_uint64_c(0xc76c51a3ul, 0x0654be30ul),
	mk_sl_cui_uint64_c(0xd192e819ul, 0xd6ef5218ul), mk_sl_cui_uint64_c(0xd6990624ul, 0x5565a910ul), mk_sl_cui_uint64_c(0xf40e3585ul, 0x5771202aul), mk_sl_cui_uint64_c(0x106aa070ul, 0x32bbd1b8ul),
	mk_sl_cui_uint64_c(0x19a4c116ul, 0xb8d2d0c8ul), mk_sl_cui_uint64_c(0x1e376c08ul, 0x5141ab53ul), mk_sl_cui_uint64_c(0x2748774cul, 0xdf8eeb99ul), mk_sl_cui_uint64_c(0x34b0bcb5ul, 0xe19b48a8ul),
	mk_sl_cui_uint64_c(0x391c0cb3ul, 0xc5c95a63ul), mk_sl_cui_uint64_c(0x4ed8aa4aul, 0xe3418acbul), mk_sl_cui_uint64_c(0x5b9cca4ful, 0x7763e373ul), mk_sl_cui_uint64_c(0x682e6ff3ul, 0xd6b2b8a3ul),
	mk_sl_cui_uint64_c(0x748f82eeul, 0x5defb2fcul), mk_sl_cui_uint64_c(0x78a5636ful, 0x43172f60ul), mk_sl_cui_uint64_c(0x84c87814ul, 0xa1f0ab72ul), mk_sl_cui_uint64_c(0x8cc70208ul, 0x1a6439ecul),
	mk_sl_cui_uint64_c(0x90befffaul, 0x23631e28ul), mk_sl_cui_uint64_c(0xa4506cebul, 0xde82bde9ul), mk_sl_cui_uint64_c(0xbef9a3f7ul, 0xb2c67915ul), mk_sl_cui_uint64_c(0xc67178f2ul, 0xe372532bul),
	mk_sl_cui_uint64_c(0xca273eceul, 0xea26619cul), mk_sl_cui_uint64_c(0xd186b8c7ul, 0x21c0c207ul), mk_sl_cui_uint64_c(0xeada7dd6ul, 0xcde0eb1eul), mk_sl_cui_uint64_c(0xf57d4f7ful, 0xee6ed178ul),
	mk_sl_cui_uint64_c(0x06f067aaul, 0x72176fbaul), mk_sl_cui_uint64_c(0x0a637dc5ul, 0xa2c898a6ul), mk_sl_cui_uint64_c(0x113f9804ul, 0xbef90daeul), mk_sl_cui_uint64_c(0x1b710b35ul, 0x131c471bul),
	mk_sl_cui_uint64_c(0x28db77f5ul, 0x23047d84ul), mk_sl_cui_uint64_c(0x32caab7bul, 0x40c72493ul), mk_sl_cui_uint64_c(0x3c9ebe0aul, 0x15c9bebcul), mk_sl_cui_uint64_c(0x431d67c4ul, 0x9c100d4cul),
	mk_sl_cui_uint64_c(0x4cc5d4beul, 0xcb3e42b6ul), mk_sl_cui_uint64_c(0x597f299cul, 0xfc657e2aul), mk_sl_cui_uint64_c(0x5fcb6fabul, 0x3ad6faecul), mk_sl_cui_uint64_c(0x6c44198cul, 0x4a475817ul),
}}};


mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_x86_init(mk_lib_crypto_hash_block_sha2_base_64bit_x86_pt const sha2_base_64bit_x86, mk_sl_cui_uint64_pct const iv) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint128_t) == 16);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_t) == 128);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_sha2_base_64bit_x86_digest_t) == 64);

	mk_lang_assert(sha2_base_64bit_x86);

	sha2_base_64bit_x86->m_hs[0] = iv[0];
	sha2_base_64bit_x86->m_hs[1] = iv[1];
	sha2_base_64bit_x86->m_hs[2] = iv[2];
	sha2_base_64bit_x86->m_hs[3] = iv[3];
	sha2_base_64bit_x86->m_hs[4] = iv[4];
	sha2_base_64bit_x86->m_hs[5] = iv[5];
	sha2_base_64bit_x86->m_hs[6] = iv[6];
	sha2_base_64bit_x86->m_hs[7] = iv[7];
	mk_sl_cui_uint128_set_zero(&sha2_base_64bit_x86->m_len);
}

mk_lang_jumbo mk_lang_types_void_t mk_lang_gnuc_attribute_target("sse2,avx,avx2,sha512") mk_lib_crypto_hash_block_sha2_base_64bit_x86_append_blocks(mk_lib_crypto_hash_block_sha2_base_64bit_x86_pt const sha2_base_64bit_x86, mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	#define mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(a, b, c, d) ((((a) & 0x3) << (3 * 2)) | (((b) & 0x3) << (2 * 2)) | (((c) & 0x3) << (1 * 2)) | (((d) & 0x3) << (0 * 2)))
	#define mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi32_c(a, b, c, d, e, f, g, h) ((((a) & 0x1) << 7) | (((b) & 0x1) << 6) | (((c) & 0x1) << 5) | (((d) & 0x1) << 4) | (((e) & 0x1) << 3) | (((f) & 0x1) << 2) | (((g) & 0x1) << 1) | (((h) & 0x1) << 0))
	#define mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(a, b, c, d) ((((a) & 0x1) << 3) | (((b) & 0x1) << 2) | (((c) & 0x1) << 1) | (((d) & 0x1) << 0))
	#define _mm256_blend_epi64(a, b, c) _mm256_blend_epi32((a), (b), mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi32_c((((c) >> 3) & 0x1), (((c) >> 3) & 0x1), (((c) >> 2) & 0x1), (((c) >> 2) & 0x1), (((c) >> 1) & 0x1), (((c) >> 1) & 0x1), (((c) >> 0) & 0x1), (((c) >> 0) & 0x1)))
	#define any 0

	__m256i reverse;
	mk_sl_cui_uint128_t ta;
	__m256i state_a;
	__m256i state_b;
	__m256i tmp_a;
	__m256i tmp_b;
	__m256i tmp_c;
	__m256i tmp_d;
	mk_lang_types_usize_t iblock;
	mk_sl_cui_uint8_pct ptr;
	__m256i old_a;
	__m256i old_b;
	__m256i msg_a;
	__m256i msg_b;
	__m256i msg_c;
	__m256i msg_d;

	mk_lang_assert(sha2_base_64bit_x86);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_len);
	mk_lang_assert((((mk_lang_types_uintptr_t)(&sha2_base_64bit_x86->m_hs[0])) & 0x1f) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(pblocks)) & 0x1f) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[0])) & 0x1f) == 0);
	mk_lang_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_assert(mk_lang_alignof(mk_sl_cui_uint64_t) == 8);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_avx());
	mk_lang_assert(mk_lang_cpuid_has_avx2());
	mk_lang_assert(mk_lang_cpuid_has_sha512());

	reverse = _mm256_permute4x64_epi64(_mm256_castsi128_si256(_mm_set_epi64x(0x08090a0b0c0d0e0full, 0x0001020304050607ull)), mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x1, 0x0, 0x1, 0x0));
	mk_sl_cui_uint128_from_bi_usize(&ta, &nblocks);
	mk_lang_assert(!mk_sl_cui_uint128_would_overflow_add_cc(&sha2_base_64bit_x86->m_len, &ta));
	mk_sl_cui_uint128_add2_wrap_cid_cod(&sha2_base_64bit_x86->m_len, &ta);
	state_a = _mm256_load_si256(((__m256i const*)(&sha2_base_64bit_x86->m_hs[0])));
	state_b = _mm256_load_si256(((__m256i const*)(&sha2_base_64bit_x86->m_hs[4])));
	tmp_a = _mm256_permute4x64_epi64(state_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x2, 0x3));
	tmp_b = _mm256_permute4x64_epi64(state_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x2, 0x3, any, any));
	tmp_c = _mm256_permute4x64_epi64(state_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x0, 0x1));
	tmp_d = _mm256_permute4x64_epi64(state_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x0, 0x1, any, any));
	state_a = _mm256_blend_epi64(tmp_a, tmp_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x1, 0x0, 0x0));
	state_b = _mm256_blend_epi64(tmp_c, tmp_d, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x1, 0x0, 0x0));
	for(iblock = 0, ptr = &pblocks->m_uint8s[0]; iblock != nblocks; ++iblock, ptr += 128)
	{
		old_a = state_a;
		old_b = state_b;
		msg_a = _mm256_load_si256(((__m256i const*)(&ptr[0 * 4 * 8])));
		msg_b = _mm256_load_si256(((__m256i const*)(&ptr[1 * 4 * 8])));
		msg_c = _mm256_load_si256(((__m256i const*)(&ptr[2 * 4 * 8])));
		msg_d = _mm256_load_si256(((__m256i const*)(&ptr[3 * 4 * 8])));
		msg_a = _mm256_shuffle_epi8(msg_a, reverse);
		msg_b = _mm256_shuffle_epi8(msg_b, reverse);
		msg_c = _mm256_shuffle_epi8(msg_c, reverse);
		msg_d = _mm256_shuffle_epi8(msg_d, reverse);
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[0 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_a);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[1 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_b);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[2 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_c);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[3 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_d);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		msg_a = _mm256_sha512msg1_epi64(msg_a, _mm256_castsi256_si128(msg_b));
		tmp_a = _mm256_permute4x64_epi64(msg_c, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, 0x3, 0x2, 0x1));
		tmp_b = _mm256_permute4x64_epi64(msg_d, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x0, any, any, any));
		tmp_a = _mm256_blend_epi64(tmp_a, tmp_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x0, 0x0, 0x0));
		tmp_a = _mm256_add_epi64(tmp_a, msg_a);
		msg_a = _mm256_sha512msg2_epi64(tmp_a, msg_d);
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[4 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_a);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		msg_b = _mm256_sha512msg1_epi64(msg_b, _mm256_castsi256_si128(msg_c));
		tmp_a = _mm256_permute4x64_epi64(msg_d, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, 0x3, 0x2, 0x1));
		tmp_b = _mm256_permute4x64_epi64(msg_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x0, any, any, any));
		tmp_a = _mm256_blend_epi64(tmp_a, tmp_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x0, 0x0, 0x0));
		tmp_a = _mm256_add_epi64(tmp_a, msg_b);
		msg_b = _mm256_sha512msg2_epi64(tmp_a, msg_a);
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[5 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_b);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		msg_c = _mm256_sha512msg1_epi64(msg_c, _mm256_castsi256_si128(msg_d));
		tmp_a = _mm256_permute4x64_epi64(msg_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, 0x3, 0x2, 0x1));
		tmp_b = _mm256_permute4x64_epi64(msg_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x0, any, any, any));
		tmp_a = _mm256_blend_epi64(tmp_a, tmp_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x0, 0x0, 0x0));
		tmp_a = _mm256_add_epi64(tmp_a, msg_c);
		msg_c = _mm256_sha512msg2_epi64(tmp_a, msg_b);
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[6 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_c);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		msg_d = _mm256_sha512msg1_epi64(msg_d, _mm256_castsi256_si128(msg_a));
		tmp_a = _mm256_permute4x64_epi64(msg_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, 0x3, 0x2, 0x1));
		tmp_b = _mm256_permute4x64_epi64(msg_c, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x0, any, any, any));
		tmp_a = _mm256_blend_epi64(tmp_a, tmp_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x0, 0x0, 0x0));
		tmp_a = _mm256_add_epi64(tmp_a, msg_d);
		msg_d = _mm256_sha512msg2_epi64(tmp_a, msg_c);
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[7 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_d);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		msg_a = _mm256_sha512msg1_epi64(msg_a, _mm256_castsi256_si128(msg_b));
		tmp_a = _mm256_permute4x64_epi64(msg_c, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, 0x3, 0x2, 0x1));
		tmp_b = _mm256_permute4x64_epi64(msg_d, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x0, any, any, any));
		tmp_a = _mm256_blend_epi64(tmp_a, tmp_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x0, 0x0, 0x0));
		tmp_a = _mm256_add_epi64(tmp_a, msg_a);
		msg_a = _mm256_sha512msg2_epi64(tmp_a, msg_d);
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[8 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_a);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		msg_b = _mm256_sha512msg1_epi64(msg_b, _mm256_castsi256_si128(msg_c));
		tmp_a = _mm256_permute4x64_epi64(msg_d, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, 0x3, 0x2, 0x1));
		tmp_b = _mm256_permute4x64_epi64(msg_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x0, any, any, any));
		tmp_a = _mm256_blend_epi64(tmp_a, tmp_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x0, 0x0, 0x0));
		tmp_a = _mm256_add_epi64(tmp_a, msg_b);
		msg_b = _mm256_sha512msg2_epi64(tmp_a, msg_a);
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[9 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_b);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		msg_c = _mm256_sha512msg1_epi64(msg_c, _mm256_castsi256_si128(msg_d));
		tmp_a = _mm256_permute4x64_epi64(msg_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, 0x3, 0x2, 0x1));
		tmp_b = _mm256_permute4x64_epi64(msg_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x0, any, any, any));
		tmp_a = _mm256_blend_epi64(tmp_a, tmp_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x0, 0x0, 0x0));
		tmp_a = _mm256_add_epi64(tmp_a, msg_c);
		msg_c = _mm256_sha512msg2_epi64(tmp_a, msg_b);
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[10 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_c);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		msg_d = _mm256_sha512msg1_epi64(msg_d, _mm256_castsi256_si128(msg_a));
		tmp_a = _mm256_permute4x64_epi64(msg_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, 0x3, 0x2, 0x1));
		tmp_b = _mm256_permute4x64_epi64(msg_c, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x0, any, any, any));
		tmp_a = _mm256_blend_epi64(tmp_a, tmp_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x0, 0x0, 0x0));
		tmp_a = _mm256_add_epi64(tmp_a, msg_d);
		msg_d = _mm256_sha512msg2_epi64(tmp_a, msg_c);
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[11 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_d);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		msg_a = _mm256_sha512msg1_epi64(msg_a, _mm256_castsi256_si128(msg_b));
		tmp_a = _mm256_permute4x64_epi64(msg_c, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, 0x3, 0x2, 0x1));
		tmp_b = _mm256_permute4x64_epi64(msg_d, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x0, any, any, any));
		tmp_a = _mm256_blend_epi64(tmp_a, tmp_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x0, 0x0, 0x0));
		tmp_a = _mm256_add_epi64(tmp_a, msg_a);
		msg_a = _mm256_sha512msg2_epi64(tmp_a, msg_d);
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[12 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_a);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		msg_b = _mm256_sha512msg1_epi64(msg_b, _mm256_castsi256_si128(msg_c));
		tmp_a = _mm256_permute4x64_epi64(msg_d, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, 0x3, 0x2, 0x1));
		tmp_b = _mm256_permute4x64_epi64(msg_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x0, any, any, any));
		tmp_a = _mm256_blend_epi64(tmp_a, tmp_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x0, 0x0, 0x0));
		tmp_a = _mm256_add_epi64(tmp_a, msg_b);
		msg_b = _mm256_sha512msg2_epi64(tmp_a, msg_a);
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[13 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_b);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		msg_c = _mm256_sha512msg1_epi64(msg_c, _mm256_castsi256_si128(msg_d));
		tmp_a = _mm256_permute4x64_epi64(msg_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, 0x3, 0x2, 0x1));
		tmp_b = _mm256_permute4x64_epi64(msg_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x0, any, any, any));
		tmp_a = _mm256_blend_epi64(tmp_a, tmp_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x0, 0x0, 0x0));
		tmp_a = _mm256_add_epi64(tmp_a, msg_c);
		msg_c = _mm256_sha512msg2_epi64(tmp_a, msg_b);
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[14 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_c);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		msg_d = _mm256_sha512msg1_epi64(msg_d, _mm256_castsi256_si128(msg_a));
		tmp_a = _mm256_permute4x64_epi64(msg_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, 0x3, 0x2, 0x1));
		tmp_b = _mm256_permute4x64_epi64(msg_c, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x0, any, any, any));
		tmp_a = _mm256_blend_epi64(tmp_a, tmp_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x0, 0x0, 0x0));
		tmp_a = _mm256_add_epi64(tmp_a, msg_d);
		msg_d = _mm256_sha512msg2_epi64(tmp_a, msg_c);
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[15 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_d);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		msg_a = _mm256_sha512msg1_epi64(msg_a, _mm256_castsi256_si128(msg_b));
		tmp_a = _mm256_permute4x64_epi64(msg_c, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, 0x3, 0x2, 0x1));
		tmp_b = _mm256_permute4x64_epi64(msg_d, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x0, any, any, any));
		tmp_a = _mm256_blend_epi64(tmp_a, tmp_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x0, 0x0, 0x0));
		tmp_a = _mm256_add_epi64(tmp_a, msg_a);
		msg_a = _mm256_sha512msg2_epi64(tmp_a, msg_d);
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[16 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_a);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		msg_b = _mm256_sha512msg1_epi64(msg_b, _mm256_castsi256_si128(msg_c));
		tmp_a = _mm256_permute4x64_epi64(msg_d, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, 0x3, 0x2, 0x1));
		tmp_b = _mm256_permute4x64_epi64(msg_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x0, any, any, any));
		tmp_a = _mm256_blend_epi64(tmp_a, tmp_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x0, 0x0, 0x0));
		tmp_a = _mm256_add_epi64(tmp_a, msg_b);
		msg_b = _mm256_sha512msg2_epi64(tmp_a, msg_a);
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[17 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_b);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		msg_c = _mm256_sha512msg1_epi64(msg_c, _mm256_castsi256_si128(msg_d));
		tmp_a = _mm256_permute4x64_epi64(msg_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, 0x3, 0x2, 0x1));
		tmp_b = _mm256_permute4x64_epi64(msg_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x0, any, any, any));
		tmp_a = _mm256_blend_epi64(tmp_a, tmp_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x0, 0x0, 0x0));
		tmp_a = _mm256_add_epi64(tmp_a, msg_c);
		msg_c = _mm256_sha512msg2_epi64(tmp_a, msg_b);
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[18 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_c);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		msg_d = _mm256_sha512msg1_epi64(msg_d, _mm256_castsi256_si128(msg_a));
		tmp_a = _mm256_permute4x64_epi64(msg_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, 0x3, 0x2, 0x1));
		tmp_b = _mm256_permute4x64_epi64(msg_c, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x0, any, any, any));
		tmp_a = _mm256_blend_epi64(tmp_a, tmp_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x0, 0x0, 0x0));
		tmp_a = _mm256_add_epi64(tmp_a, msg_d);
		msg_d = _mm256_sha512msg2_epi64(tmp_a, msg_c);
		tmp_a = _mm256_load_si256(((__m256i const*)(&s_mk_lib_crypto_hash_block_sha2_base_64bit_x86_table.m_data.m_uint64s[19 * 4])));
		tmp_a = _mm256_add_epi64(tmp_a, msg_d);
		state_a = _mm256_sha512rnds2_epi64(state_a, state_b, _mm256_castsi256_si128(tmp_a));
		tmp_a = _mm256_permute4x64_epi64(tmp_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x3, 0x2));
		state_b = _mm256_sha512rnds2_epi64(state_b, state_a, _mm256_castsi256_si128(tmp_a));
		state_a = _mm256_add_epi64(state_a, old_a);
		state_b = _mm256_add_epi64(state_b, old_b);
	}
	tmp_a = _mm256_permute4x64_epi64(state_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x2, 0x3));
	tmp_b = _mm256_permute4x64_epi64(state_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x2, 0x3, any, any));
	tmp_c = _mm256_permute4x64_epi64(state_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(any, any, 0x0, 0x1));
	tmp_d = _mm256_permute4x64_epi64(state_a, mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c(0x0, 0x1, any, any));
	state_a = _mm256_blend_epi64(tmp_a, tmp_b, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x1, 0x0, 0x0));
	state_b = _mm256_blend_epi64(tmp_c, tmp_d, mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c(0x1, 0x1, 0x0, 0x0));
	_mm256_store_si256(((__m256i*)(&sha2_base_64bit_x86->m_hs[0])), state_a);
	_mm256_store_si256(((__m256i*)(&sha2_base_64bit_x86->m_hs[4])), state_b);

	#undef mk_lib_crypto_hash_block_sha2_base_64bit_x86_permute_epi64_c
	#undef mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi32_c
	#undef mk_lib_crypto_hash_block_sha2_base_64bit_x86_blend_epi64_c
	#undef _mm256_blend_epi64
	#undef any
}

mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_x86_finish(mk_lib_crypto_hash_block_sha2_base_64bit_x86_pt const sha2_base_64bit_x86, mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_sha2_base_64bit_x86_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_types_uint_t tui;
	mk_sl_cui_uint128_t ta;
	mk_sl_cui_uint128_t tb;
	mk_lang_types_sint_t rest;
	mk_lang_types_sint_t i;

	mk_lang_assert(sha2_base_64bit_x86);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_len);
	mk_lang_assert(digest);

	tui = mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_len;
	mk_sl_cui_uint128_from_bi_uint(&ta, &tui);
	mk_lang_assert(!mk_sl_cui_uint128_would_overflow_mul(&sha2_base_64bit_x86->m_len, &ta));
	mk_sl_cui_uint128_shl3(&sha2_base_64bit_x86->m_len, 7, &ta);
	mk_sl_cui_uint128_from_bi_sint(&tb, &idx);
	mk_lang_assert(!mk_sl_cui_uint128_would_overflow_add_cc(&ta, &tb));
	mk_sl_cui_uint128_add2_wrap_cid_cod(&ta, &tb);
	tui = 8;
	mk_sl_cui_uint128_from_bi_uint(&tb, &tui);
	mk_lang_assert(!mk_sl_cui_uint128_would_overflow_mul(&ta, &tb));
	mk_sl_cui_uint128_shl2(&ta, 3);
	tui = 0x80;
	mk_sl_cui_uint8_from_bi_uint(&block->m_uint8s[idx], &tui);
	rest = mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_len - idx - 1;
	if(rest >= 16)
	{
		for(i = 0; i != rest - 16; ++i)
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
		mk_lib_crypto_hash_block_sha2_base_64bit_x86_append_blocks(sha2_base_64bit_x86, block, 1);
		for(i = 0; i != mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_len - 16; ++i)
		{
			mk_sl_cui_uint8_set_zero(&block->m_uint8s[i]);
		}
	}
	mk_sl_uint_128_to_8_be(&ta, &block->m_uint8s[mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_len - 16]);
	mk_lib_crypto_hash_block_sha2_base_64bit_x86_append_blocks(sha2_base_64bit_x86, block, 1);
	for(i = 0; i != 8; ++i)
	{
		mk_sl_uint_64_to_8_be(&sha2_base_64bit_x86->m_hs[i], &digest->m_uint8s[i * 8]);
	}
}


#else


mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_x86_init(mk_lib_crypto_hash_block_sha2_base_64bit_x86_pt const sha2_base_64bit_x86, mk_sl_cui_uint64_pct const iv) mk_lang_noexcept
{
	((mk_lang_types_void_t)(sha2_base_64bit_x86));
	((mk_lang_types_void_t)(iv));

	mk_lang_assert(0);
}

mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_x86_append_blocks(mk_lib_crypto_hash_block_sha2_base_64bit_x86_pt const sha2_base_64bit_x86, mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	((mk_lang_types_void_t)(sha2_base_64bit_x86));
	((mk_lang_types_void_t)(pblocks));
	((mk_lang_types_void_t)(nblocks));

	mk_lang_assert(0);
}

mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_x86_finish(mk_lib_crypto_hash_block_sha2_base_64bit_x86_pt const sha2_base_64bit_x86, mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_sha2_base_64bit_x86_digest_pt const digest) mk_lang_noexcept
{
	((mk_lang_types_void_t)(sha2_base_64bit_x86));
	((mk_lang_types_void_t)(block));
	((mk_lang_types_void_t)(idx));
	((mk_lang_types_void_t)(digest));

	mk_lang_assert(0);
}


#endif
