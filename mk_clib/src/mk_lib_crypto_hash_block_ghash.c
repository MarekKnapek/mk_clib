#include "mk_lib_crypto_hash_block_ghash.h"

/* NIST SP 800-38D */

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
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"

#define mk_lang_memset_t_name mk_lib_crypto_hash_block_ghash_memsetu8
#define mk_lang_memset_t_type mk_sl_cui_uint8_t
#include "mk_lang_memset_inl_fileh.h"
#include "mk_lang_memset_inl_filec.h"

#define mk_lang_memcpy_t_name mk_lib_crypto_hash_block_ghash_memcpyu8
#define mk_lang_memcpy_t_type mk_sl_cui_uint8_t
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"

#define mk_lib_crypto_mode_base_t_name mk_lib_crypto_hash_block_ghash_xor
#define mk_lib_crypto_mode_base_t_len 16
#include "mk_lib_crypto_mode_base_inl_fileh.h"
#include "mk_lib_crypto_mode_base_inl_filec.h"


#if mk_lang_msvc_full_ver >= mk_lang_msvc_ver_2005 && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664)

#include <wmmintrin.h> /* _mm_clmulepi64_si128 */
#include <emmintrin.h> /* SSE2 _mm_load_si128 _mm_or_si128 _mm_set_epi8 _mm_slli_epi32 _mm_slli_si128 _mm_srli_epi32 _mm_srli_si128 _mm_store_si128 _mm_xor_si128 */
#include <tmmintrin.h> /* SSSE3 _mm_shuffle_epi8 */

#pragma intrinsic(_mm_clmulepi64_si128)
#pragma intrinsic(_mm_load_si128)
#pragma intrinsic(_mm_or_si128)
#pragma intrinsic(_mm_set_epi8)
#pragma intrinsic(_mm_shuffle_epi8)
#pragma intrinsic(_mm_slli_epi32)
#pragma intrinsic(_mm_slli_si128)
#pragma intrinsic(_mm_srli_epi32)
#pragma intrinsic(_mm_srli_si128)
#pragma intrinsic(_mm_store_si128)
#pragma intrinsic(_mm_xor_si128)

static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_ghash_multiply2_x86(mk_lang_static_param(mk_sl_cui_uint8_t, a, 16), mk_lang_static_param(mk_sl_cui_uint8_ct, b, 16)) mk_lang_noexcept
{
	__m128i bswap;
	__m128i aa;
	__m128i bb;
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;
	__m128i te;
	__m128i tf;
	__m128i tg;
	__m128i th;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(mk_lang_cpuid_has_pclmulqdq());
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert(mk_lang_cpuid_has_ssse3());
	mk_lang_assert((((mk_lang_types_uintptr_t)(a)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(b)) & 0xf) == 0);

	bswap = _mm_set_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	aa = _mm_load_si128(((__m128i const*)(a)));
	bb = _mm_load_si128(((__m128i const*)(b)));
	aa = _mm_shuffle_epi8(aa, bswap);
	bb = _mm_shuffle_epi8(bb, bswap);
	ta = _mm_clmulepi64_si128(aa, bb, 0x00);
	tb = _mm_clmulepi64_si128(aa, bb, 0x10);
	tc = _mm_clmulepi64_si128(aa, bb, 0x01);
	td = _mm_clmulepi64_si128(aa, bb, 0x11);
	tb = _mm_xor_si128(tb, tc);
	tc = _mm_slli_si128(tb, 8);
	tb = _mm_srli_si128(tb, 8);
	ta = _mm_xor_si128(ta, tc);
	td = _mm_xor_si128(td, tb);
	te = _mm_srli_epi32(ta, 31);
	tf = _mm_srli_epi32(td, 31);
	ta = _mm_slli_epi32(ta, 1);
	td = _mm_slli_epi32(td, 1);
	tg = _mm_srli_si128(te, 12);
	tf = _mm_slli_si128(tf, 4);
	te = _mm_slli_si128(te, 4);
	ta = _mm_or_si128(ta, te);
	td = _mm_or_si128(td, tf);
	td = _mm_or_si128(td, tg);
	te = _mm_slli_epi32(ta, 31);
	tf = _mm_slli_epi32(ta, 30);
	tg = _mm_slli_epi32(ta, 25);
	te = _mm_xor_si128(te, tf);
	te = _mm_xor_si128(te, tg);
	tf = _mm_srli_si128(te, 4);
	te = _mm_slli_si128(te, 12);
	ta = _mm_xor_si128(ta, te);
	th = _mm_srli_epi32(ta, 1);
	tb = _mm_srli_epi32(ta, 2);
	tc = _mm_srli_epi32(ta, 7);
	th = _mm_xor_si128(th, tb);
	th = _mm_xor_si128(th, tc);
	th = _mm_xor_si128(th, tf);
	ta = _mm_xor_si128(ta, th);
	td = _mm_xor_si128(td, ta);
	td = _mm_shuffle_epi8(td, bswap);
	_mm_store_si128(((__m128i*)(a)), td);
}

#endif

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_ghash_multiply2_portable(mk_lang_static_param(mk_sl_cui_uint8_t, a, 16), mk_lang_static_param(mk_sl_cui_uint8_ct, b, 16)) mk_lang_noexcept
{
	#define mk_lib_crypto_hash_block_ghash_r (0xe1)

	mk_sl_cui_uint8_pt z mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_ghash_block_t zz mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt v mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_ghash_block_t vv mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_bool_t f mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	z = &zz.m_data.m_uint8s[0];
	v = &vv.m_data.m_uint8s[0];
	mk_sl_cui_uint8_set_zero(&tu8);
	mk_lib_crypto_hash_block_ghash_memsetu8_fn(z, &tu8, 16);
	mk_lib_crypto_hash_block_ghash_memcpyu8_fn(v, b, 16);
	for(i = 0; i != 128; ++i)
	{
		mk_sl_cui_uint8_shr3(&a[i / 8], (8 - 1) - (i % 8), &tu8);
		if(mk_sl_cui_uint8_has_lsb(&tu8))
		{
			mk_lib_crypto_hash_block_ghash_xor_xor2(z, v);
		}
		f = mk_sl_cui_uint8_has_lsb(&v[16 - 1]);
		for(j = 0; j != 16 - 1; ++j)
		{
			mk_sl_cui_uint8_shr2(&v[(16 - 1) - (j + 0)], 1);
			mk_sl_cui_uint8_shl3(&v[(16 - 1) - (j + 1)], 7, &tu8);
			mk_sl_cui_uint8_xor2(&v[(16 - 1) - (j + 0)], &tu8);
		}
		mk_sl_cui_uint8_shr2(&v[(16 - 1) - (j + 0)], 1);
		if(f)
		{
			j = mk_lib_crypto_hash_block_ghash_r;
			mk_sl_cui_uint8_from_bi_sint(&tu8, &j);
			mk_sl_cui_uint8_xor2(&v[0], &tu8);
		}
	}
	mk_lib_crypto_hash_block_ghash_memcpyu8_fn(a, z, 16);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_ghash_multiply2(mk_lang_static_param(mk_sl_cui_uint8_t, a, 16), mk_lang_static_param(mk_sl_cui_uint8_ct, b, 16)) mk_lang_noexcept
{
	#if mk_lang_msvc_full_ver >= mk_lang_msvc_ver_2005 && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664)
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_pclmulqdq() && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_ssse3() && ((((mk_lang_types_uintptr_t)(a)) & 0xf) == 0) && ((((mk_lang_types_uintptr_t)(b)) & 0xf) == 0))
	{
		mk_lib_crypto_hash_block_ghash_multiply2_x86(a, b);
	}
	else
	#endif
	{
		mk_lib_crypto_hash_block_ghash_multiply2_portable(a, b);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_ghash_append_block(mk_lib_crypto_hash_block_ghash_pt const ghash, mk_lib_crypto_hash_block_ghash_block_pct const block) mk_lang_noexcept
{
	mk_lang_assert(ghash);
	mk_lang_assert(block);

	mk_lib_crypto_hash_block_ghash_xor_xor2(&ghash->m_state.m_data.m_uint8s[0], &block->m_data.m_uint8s[0]);
	mk_lib_crypto_hash_block_ghash_multiply2(&ghash->m_state.m_data.m_uint8s[0], &ghash->m_key.m_data.m_uint8s[0]);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_ghash_init(mk_lib_crypto_hash_block_ghash_pt const ghash, mk_lib_crypto_hash_block_ghash_block_pct const key) mk_lang_noexcept
{
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;

	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_ghash_block_t) == 16);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_ghash_digest_t) == 16);

	mk_lang_assert(ghash);
	mk_lang_assert(key);

	ghash->m_key = *key;
	mk_sl_cui_uint8_set_zero(&tu8);
	mk_lib_crypto_hash_block_ghash_memsetu8_fn(&ghash->m_state.m_data.m_uint8s[0], &tu8, 16);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_ghash_append_blocks(mk_lib_crypto_hash_block_ghash_pt const ghash, mk_lib_crypto_hash_block_ghash_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(ghash);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_ghash_block_len);

	n = nblocks;
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_hash_block_ghash_append_block(ghash, &pblocks[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_ghash_finish(mk_lib_crypto_hash_block_ghash_pt const ghash, mk_lib_crypto_hash_block_ghash_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_assert(ghash);
	mk_lang_assert(digest);

	mk_lib_crypto_hash_block_ghash_memcpyu8_fn(&digest->m_data.m_uint8s[0], &ghash->m_state.m_data.m_uint8s[0], 16);
}
