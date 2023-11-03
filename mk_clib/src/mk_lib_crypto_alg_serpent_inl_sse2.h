#include <emmintrin.h>

#pragma intrinsic(_mm_and_si128)
#pragma intrinsic(_mm_cmpeq_epi32)
#pragma intrinsic(_mm_load_si128)
#pragma intrinsic(_mm_or_si128)
#pragma intrinsic(_mm_slli_epi32)
#pragma intrinsic(_mm_srli_epi32)
#pragma intrinsic(_mm_store_si128)
#pragma intrinsic(_mm_unpackhi_epi32)
#pragma intrinsic(_mm_unpackhi_epi64)
#pragma intrinsic(_mm_unpacklo_epi32)
#pragma intrinsic(_mm_unpacklo_epi64)
#pragma intrinsic(_mm_xor_si128)

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_ui_and2(__m128i* const a, __m128i const* const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	*a = _mm_and_si128(*a, *b);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_ui_not1(__m128i* const a) mk_lang_noexcept
{
	__m128i b;

	mk_lang_assert(a);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	b = _mm_cmpeq_epi32(*a, *a);
	*a = _mm_xor_si128(*a, b);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_ui_or2(__m128i* const a, __m128i const* const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	*a = _mm_or_si128(*a, *b);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_ui_rotl2(__m128i* const a, mk_lang_types_sint_t const b) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	ta = _mm_slli_epi32(*a, b);
	tb = _mm_srli_epi32(*a, 32 - b);
	*a = _mm_or_si128(ta, tb);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_ui_rotr2(__m128i* const a, mk_lang_types_sint_t const b) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	ta = _mm_srli_epi32(*a, b);
	tb = _mm_slli_epi32(*a, 32 - b);
	*a = _mm_or_si128(ta, tb);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_ui_shl3(__m128i const* const a, mk_lang_types_sint_t const b, __m128i* const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(c);
	mk_lang_assert(a != c);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	*c = _mm_slli_epi32(*a, b);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_ui_xor2(__m128i* const a, __m128i const* const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	*a = _mm_xor_si128(*a, *b);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_ui_xor3(__m128i const* const a, __m128i const* const b, __m128i* const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	*c = _mm_xor_si128(*a, *b);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_transpose(__m128i* const ta, __m128i* const tb, __m128i* const tc, __m128i* const td) mk_lang_noexcept
{
	__m128i tta;
	__m128i ttb;
	__m128i ttc;
	__m128i ttd;

	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tc != td);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	tta = _mm_unpacklo_epi32(*ta, *tb);
	ttb = _mm_unpacklo_epi32(*tc, *td);
	ttc = _mm_unpackhi_epi32(*ta, *tb);
	ttd = _mm_unpackhi_epi32(*tc, *td);
	*ta = _mm_unpacklo_epi64(tta, ttb);
	*tb = _mm_unpackhi_epi64(tta, ttb);
	*tc = _mm_unpacklo_epi64(ttc, ttd);
	*td = _mm_unpackhi_epi64(ttc, ttd);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_load(mk_lib_crypto_alg_serpent_msg_pct const msgs, __m128i* const ta, __m128i* const tb, __m128i* const tc, __m128i* const td) mk_lang_noexcept
{
	mk_lang_assert(msgs);
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tc != td);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	*ta = _mm_load_si128(((__m128i const*)(&msgs->m_data.m_uint8s[0 * 16])));
	*tb = _mm_load_si128(((__m128i const*)(&msgs->m_data.m_uint8s[1 * 16])));
	*tc = _mm_load_si128(((__m128i const*)(&msgs->m_data.m_uint8s[2 * 16])));
	*td = _mm_load_si128(((__m128i const*)(&msgs->m_data.m_uint8s[3 * 16])));
	mk_lib_crypto_alg_serpent_sse2_transpose(ta, tb, tc, td);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_store(mk_lib_crypto_alg_serpent_msg_pt const msgs, __m128i* const ta, __m128i* const tb, __m128i* const tc, __m128i* const td) mk_lang_noexcept
{
	mk_lang_assert(msgs);
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tc != td);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	mk_lib_crypto_alg_serpent_sse2_transpose(ta, tb, tc, td);
	_mm_store_si128(((__m128i*)(&msgs->m_data.m_uint8s[0 * 16])), *ta);
	_mm_store_si128(((__m128i*)(&msgs->m_data.m_uint8s[1 * 16])), *tb);
	_mm_store_si128(((__m128i*)(&msgs->m_data.m_uint8s[2 * 16])), *tc);
	_mm_store_si128(((__m128i*)(&msgs->m_data.m_uint8s[3 * 16])), *td);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_xor2(mk_lib_crypto_alg_serpent_msg_pt const a, mk_lib_crypto_alg_serpent_msg_pct const b) mk_lang_noexcept
{
	__m128i bb;
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(a)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(b)) & 0xf) == 0);

	bb = _mm_load_si128(((__m128i const*)(b)));
	ta = _mm_load_si128(((__m128i const*)(((mk_lang_types_uchar_pct)(a)) + 0 * 16)));
	tb = _mm_load_si128(((__m128i const*)(((mk_lang_types_uchar_pct)(a)) + 1 * 16)));
	tc = _mm_load_si128(((__m128i const*)(((mk_lang_types_uchar_pct)(a)) + 2 * 16)));
	td = _mm_load_si128(((__m128i const*)(((mk_lang_types_uchar_pct)(a)) + 3 * 16)));
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &bb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &bb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &bb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &bb);
	_mm_store_si128(((__m128i*)(((mk_lang_types_uchar_pt)(a)) + 0 * 16)), ta);
	_mm_store_si128(((__m128i*)(((mk_lang_types_uchar_pt)(a)) + 1 * 16)), tb);
	_mm_store_si128(((__m128i*)(((mk_lang_types_uchar_pt)(a)) + 2 * 16)), tc);
	_mm_store_si128(((__m128i*)(((mk_lang_types_uchar_pt)(a)) + 3 * 16)), td);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_xor3(mk_lib_crypto_alg_serpent_msg_pct const a, mk_lib_crypto_alg_serpent_msg_pct const b, mk_lib_crypto_alg_serpent_msg_pt const c) mk_lang_noexcept
{
	__m128i bb;
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);
	mk_lang_assert(b != c);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(a)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(b)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(c)) & 0xf) == 0);

	bb = _mm_load_si128(((__m128i const*)(b)));
	ta = _mm_load_si128(((__m128i const*)(((mk_lang_types_uchar_pct)(a)) + 0 * 16)));
	tb = _mm_load_si128(((__m128i const*)(((mk_lang_types_uchar_pct)(a)) + 1 * 16)));
	tc = _mm_load_si128(((__m128i const*)(((mk_lang_types_uchar_pct)(a)) + 2 * 16)));
	td = _mm_load_si128(((__m128i const*)(((mk_lang_types_uchar_pct)(a)) + 3 * 16)));
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &bb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &bb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &bb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &bb);
	_mm_store_si128(((__m128i*)(((mk_lang_types_uchar_pt)(c)) + 0 * 16)), ta);
	_mm_store_si128(((__m128i*)(((mk_lang_types_uchar_pt)(c)) + 1 * 16)), tb);
	_mm_store_si128(((__m128i*)(((mk_lang_types_uchar_pt)(c)) + 2 * 16)), tc);
	_mm_store_si128(((__m128i*)(((mk_lang_types_uchar_pt)(c)) + 3 * 16)), td);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_copy(mk_lib_crypto_alg_serpent_msg_pct const a, mk_lib_crypto_alg_serpent_msg_pct const b) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(a)) & 0xf) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(b)) & 0xf) == 0);

	if(a == b) return;
	ta = _mm_load_si128(((__m128i const*)(((mk_lang_types_uchar_pct)(a)) + 0 * 16)));
	tb = _mm_load_si128(((__m128i const*)(((mk_lang_types_uchar_pct)(a)) + 1 * 16)));
	tc = _mm_load_si128(((__m128i const*)(((mk_lang_types_uchar_pct)(a)) + 2 * 16)));
	td = _mm_load_si128(((__m128i const*)(((mk_lang_types_uchar_pct)(a)) + 3 * 16)));
	_mm_store_si128(((__m128i*)(((mk_lang_types_uchar_pt)(b)) + 0 * 16)), ta);
	_mm_store_si128(((__m128i*)(((mk_lang_types_uchar_pt)(b)) + 1 * 16)), tb);
	_mm_store_si128(((__m128i*)(((mk_lang_types_uchar_pt)(b)) + 2 * 16)), tc);
	_mm_store_si128(((__m128i*)(((mk_lang_types_uchar_pt)(b)) + 3 * 16)), td);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_substitute_enc_0(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;
	__m128i te;

	mk_lang_assert(msgs);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	mk_lib_crypto_alg_serpent_sse2_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &ta); te = tb;
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&tb, &td); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &ta); mk_lib_crypto_alg_serpent_sse2_ui_or2(&ta, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &te); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &tc); mk_lib_crypto_alg_serpent_sse2_ui_or2(&tc, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &te); mk_lib_crypto_alg_serpent_sse2_ui_not1(&te);
	mk_lib_crypto_alg_serpent_sse2_ui_or2(&te, &tb);  mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &te); mk_lib_crypto_alg_serpent_sse2_ui_or2(&td, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &td); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &td);
	mk_lib_crypto_alg_serpent_sse2_store(msgs, &tb, &te, &tc, &ta);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_substitute_enc_1(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;
	__m128i te;

	mk_lang_assert(msgs);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	mk_lib_crypto_alg_serpent_sse2_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_not1(&ta);      mk_lib_crypto_alg_serpent_sse2_ui_not1(&tc);
	te = ta;                                         mk_lib_crypto_alg_serpent_sse2_ui_and2(&ta, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &ta); mk_lib_crypto_alg_serpent_sse2_ui_or2(&ta, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &tc); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &te); mk_lib_crypto_alg_serpent_sse2_ui_or2(&te, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &td); mk_lib_crypto_alg_serpent_sse2_ui_or2(&tc, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&tc, &te); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&tb, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &ta); mk_lib_crypto_alg_serpent_sse2_ui_and2(&ta, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &te);
	mk_lib_crypto_alg_serpent_sse2_store(msgs, &tc, &ta, &td, &tb);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_substitute_enc_2(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;
	__m128i te;

	mk_lang_assert(msgs);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	mk_lib_crypto_alg_serpent_sse2_load(msgs, &ta, &tb, &tc, &td);
	te = ta;                                         mk_lib_crypto_alg_serpent_sse2_ui_and2(&ta, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &td); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &ta); mk_lib_crypto_alg_serpent_sse2_ui_or2(&td, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &tb); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tc);
	tb = td;                                         mk_lib_crypto_alg_serpent_sse2_ui_or2(&td, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &ta); mk_lib_crypto_alg_serpent_sse2_ui_and2(&ta, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &ta); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &te); mk_lib_crypto_alg_serpent_sse2_ui_not1(&te);
	mk_lib_crypto_alg_serpent_sse2_store(msgs, &tc, &td, &tb, &te);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_substitute_enc_3(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;
	__m128i te;

	mk_lang_assert(msgs);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	mk_lib_crypto_alg_serpent_sse2_load(msgs, &ta, &tb, &tc, &td);
	te = ta;                                         mk_lib_crypto_alg_serpent_sse2_ui_or2(&ta, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &tb); mk_lib_crypto_alg_serpent_sse2_ui_and2(&tb, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tc); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&td, &ta); mk_lib_crypto_alg_serpent_sse2_ui_or2(&te, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &te); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&te, &ta); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tc); mk_lib_crypto_alg_serpent_sse2_ui_or2(&tb, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &tc); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &td);
	tc = tb;                                         mk_lib_crypto_alg_serpent_sse2_ui_or2(&tb, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &ta);
	mk_lib_crypto_alg_serpent_sse2_store(msgs, &tb, &tc, &td, &te);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_substitute_enc_4(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;
	__m128i te;

	mk_lang_assert(msgs);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	mk_lib_crypto_alg_serpent_sse2_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &td); mk_lib_crypto_alg_serpent_sse2_ui_not1(&td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &td); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &ta);
	te = tb;                                         mk_lib_crypto_alg_serpent_sse2_ui_and2(&tb, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &tc); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &te); mk_lib_crypto_alg_serpent_sse2_ui_and2(&tc, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &ta); mk_lib_crypto_alg_serpent_sse2_ui_and2(&ta, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &ta); mk_lib_crypto_alg_serpent_sse2_ui_or2(&te, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &ta); mk_lib_crypto_alg_serpent_sse2_ui_or2(&ta, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &tc); mk_lib_crypto_alg_serpent_sse2_ui_and2(&tc, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_not1(&ta);      mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_sse2_store(msgs, &tb, &te, &ta, &td);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_substitute_enc_5(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;
	__m128i te;

	mk_lang_assert(msgs);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	mk_lib_crypto_alg_serpent_sse2_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &tb); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_not1(&td);      te = tb;
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&tb, &ta); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &tc); mk_lib_crypto_alg_serpent_sse2_ui_or2(&tc, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &td); mk_lib_crypto_alg_serpent_sse2_ui_and2(&td, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &ta); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tc); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&ta, &td); mk_lib_crypto_alg_serpent_sse2_ui_not1(&tc);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &te); mk_lib_crypto_alg_serpent_sse2_ui_or2(&te, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &te);
	mk_lib_crypto_alg_serpent_sse2_store(msgs, &tb, &td, &ta, &tc);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_substitute_enc_6(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;
	__m128i te;

	mk_lang_assert(msgs);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	mk_lib_crypto_alg_serpent_sse2_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_not1(&tc);      te = td;
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&td, &ta); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &tc); mk_lib_crypto_alg_serpent_sse2_ui_or2(&tc, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &td); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_or2(&ta, &tb);  mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &ta); mk_lib_crypto_alg_serpent_sse2_ui_or2(&ta, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &tc); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &ta); mk_lib_crypto_alg_serpent_sse2_ui_not1(&td);
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&tc, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &td);
	mk_lib_crypto_alg_serpent_sse2_store(msgs, &ta, &tb, &te, &tc);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_substitute_enc_7(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;
	__m128i te;

	mk_lang_assert(msgs);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	mk_lib_crypto_alg_serpent_sse2_load(msgs, &ta, &tb, &tc, &td);
	te = tb;                                         mk_lib_crypto_alg_serpent_sse2_ui_or2(&tb, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &td); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &tb); mk_lib_crypto_alg_serpent_sse2_ui_or2(&td, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&td, &ta); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &tb); mk_lib_crypto_alg_serpent_sse2_ui_or2(&tb, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &ta); mk_lib_crypto_alg_serpent_sse2_ui_or2(&ta, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &tc); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &tb); mk_lib_crypto_alg_serpent_sse2_ui_and2(&tb, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &te); mk_lib_crypto_alg_serpent_sse2_ui_not1(&tc);
	mk_lib_crypto_alg_serpent_sse2_ui_or2(&tc, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_sse2_store(msgs, &te, &td, &tb, &ta);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_substitute_enc(int const sbox_idx, mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_lang_assert(sbox_idx >= 0 && sbox_idx < 8);
	mk_lang_assert(msgs);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	switch(sbox_idx)
	{
		case 0: mk_lib_crypto_alg_serpent_sse2_substitute_enc_0(msgs); break;
		case 1: mk_lib_crypto_alg_serpent_sse2_substitute_enc_1(msgs); break;
		case 2: mk_lib_crypto_alg_serpent_sse2_substitute_enc_2(msgs); break;
		case 3: mk_lib_crypto_alg_serpent_sse2_substitute_enc_3(msgs); break;
		case 4: mk_lib_crypto_alg_serpent_sse2_substitute_enc_4(msgs); break;
		case 5: mk_lib_crypto_alg_serpent_sse2_substitute_enc_5(msgs); break;
		case 6: mk_lib_crypto_alg_serpent_sse2_substitute_enc_6(msgs); break;
		case 7: mk_lib_crypto_alg_serpent_sse2_substitute_enc_7(msgs); break;
		default: mk_lang_assert(0); break;
	}
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_substitute_dec_0(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;
	__m128i te;

	mk_lang_assert(msgs);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	mk_lib_crypto_alg_serpent_sse2_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_not1(&tc);      te = tb;
	mk_lib_crypto_alg_serpent_sse2_ui_or2(&tb, &ta);  mk_lib_crypto_alg_serpent_sse2_ui_not1(&te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &tc); mk_lib_crypto_alg_serpent_sse2_ui_or2(&tc, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &td); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &ta); mk_lib_crypto_alg_serpent_sse2_ui_and2(&ta, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &ta); mk_lib_crypto_alg_serpent_sse2_ui_or2(&ta, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &tc); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &tb); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&tc, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_sse2_store(msgs, &ta, &te, &tb, &td);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_substitute_dec_1(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;
	__m128i te;

	mk_lang_assert(msgs);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	mk_lib_crypto_alg_serpent_sse2_load(msgs, &ta, &tb, &tc, &td);
	te = tb;                                         mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&td, &tb); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &ta); mk_lib_crypto_alg_serpent_sse2_ui_or2(&ta, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &td); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_or2(&ta, &tc);  mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &tb); mk_lib_crypto_alg_serpent_sse2_ui_or2(&tb, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &ta); mk_lib_crypto_alg_serpent_sse2_ui_not1(&te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tb); mk_lib_crypto_alg_serpent_sse2_ui_or2(&tb, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_or2(&tb, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &tb);
	mk_lib_crypto_alg_serpent_sse2_store(msgs, &te, &ta, &td, &tc);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_substitute_dec_2(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;
	__m128i te;

	mk_lang_assert(msgs);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	mk_lib_crypto_alg_serpent_sse2_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &td); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &ta);
	te = td;                                         mk_lib_crypto_alg_serpent_sse2_ui_and2(&td, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &tb); mk_lib_crypto_alg_serpent_sse2_ui_or2(&tb, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &te); mk_lib_crypto_alg_serpent_sse2_ui_and2(&te, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &td); mk_lib_crypto_alg_serpent_sse2_ui_and2(&te, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tc); mk_lib_crypto_alg_serpent_sse2_ui_and2(&tc, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_or2(&tc, &ta);  mk_lib_crypto_alg_serpent_sse2_ui_not1(&td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &td); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&ta, &tb); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &ta);
mk_lib_crypto_alg_serpent_sse2_store(msgs, &tb, &te, &tc, &td);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_substitute_dec_3(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;
	__m128i te;

	mk_lang_assert(msgs);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	mk_lib_crypto_alg_serpent_sse2_load(msgs, &ta, &tb, &tc, &td);
	te = tc;                                         mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &tc); mk_lib_crypto_alg_serpent_sse2_ui_and2(&te, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &ta); mk_lib_crypto_alg_serpent_sse2_ui_and2(&ta, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &td); mk_lib_crypto_alg_serpent_sse2_ui_or2(&td, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &td); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &te); mk_lib_crypto_alg_serpent_sse2_ui_and2(&td, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &tb); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_or2(&tb, &tc);  mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &tb);
	mk_lib_crypto_alg_serpent_sse2_store(msgs, &tc, &tb, &td, &ta);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_substitute_dec_4(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;
	__m128i te;

	mk_lang_assert(msgs);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	mk_lib_crypto_alg_serpent_sse2_load(msgs, &ta, &tb, &tc, &td);
	te = tc;                                         mk_lib_crypto_alg_serpent_sse2_ui_and2(&tc, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &tb); mk_lib_crypto_alg_serpent_sse2_ui_or2(&tb, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&tb, &ta); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tb); mk_lib_crypto_alg_serpent_sse2_ui_and2(&tb, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_not1(&ta);      mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &td); mk_lib_crypto_alg_serpent_sse2_ui_and2(&td, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &tc); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&tc, &ta); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_or2(&tc, &td); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &tb);
	mk_lib_crypto_alg_serpent_sse2_store(msgs, &ta, &td, &tc, &te);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_substitute_dec_5(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;
	__m128i te;

	mk_lang_assert(msgs);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	mk_lib_crypto_alg_serpent_sse2_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_not1(&tb);      te = td;
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &tb); mk_lib_crypto_alg_serpent_sse2_ui_or2(&td, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &tc); mk_lib_crypto_alg_serpent_sse2_ui_or2(&tc, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&tc, &ta); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &te); mk_lib_crypto_alg_serpent_sse2_ui_or2(&te, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tb); mk_lib_crypto_alg_serpent_sse2_ui_and2(&tb, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &td); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&td, &te); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &te); mk_lib_crypto_alg_serpent_sse2_ui_not1(&te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &ta);
	mk_lib_crypto_alg_serpent_sse2_store(msgs, &tb, &te, &td, &tc);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_substitute_dec_6(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;
	__m128i te;

	mk_lang_assert(msgs);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	mk_lib_crypto_alg_serpent_sse2_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &tc); te = tc;
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&tc, &ta); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_not1(&tc);      mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &td); mk_lib_crypto_alg_serpent_sse2_ui_or2(&te, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &tc); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tb); mk_lib_crypto_alg_serpent_sse2_ui_and2(&tb, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &ta); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_or2(&ta, &tc);  mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &ta);
	mk_lib_crypto_alg_serpent_sse2_store(msgs, &tb, &tc, &te, &td);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_substitute_dec_7(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;
	__m128i te;

	mk_lang_assert(msgs);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	mk_lib_crypto_alg_serpent_sse2_load(msgs, &ta, &tb, &tc, &td);
	te = tc;                                         mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&ta, &td); mk_lib_crypto_alg_serpent_sse2_ui_or2(&te, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_not1(&tc);      mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_or2(&tb, &ta);  mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_and2(&tc, &te); mk_lib_crypto_alg_serpent_sse2_ui_and2(&td, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &tc); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &ta);
	mk_lib_crypto_alg_serpent_sse2_ui_or2(&ta, &tc);  mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tb);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &td); mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_or2(&te, &ta);  mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_sse2_store(msgs, &td, &ta, &tb, &te);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_substitute_dec(int const sbox_idx, mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_lang_assert(sbox_idx >= 0 && sbox_idx < 8);
	mk_lang_assert(msgs);
	mk_lang_assert(mk_lang_cpuid_has_sse2());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);

	switch(sbox_idx)
	{
		case 0: mk_lib_crypto_alg_serpent_sse2_substitute_dec_0(msgs); break;
		case 1: mk_lib_crypto_alg_serpent_sse2_substitute_dec_1(msgs); break;
		case 2: mk_lib_crypto_alg_serpent_sse2_substitute_dec_2(msgs); break;
		case 3: mk_lib_crypto_alg_serpent_sse2_substitute_dec_3(msgs); break;
		case 4: mk_lib_crypto_alg_serpent_sse2_substitute_dec_4(msgs); break;
		case 5: mk_lib_crypto_alg_serpent_sse2_substitute_dec_5(msgs); break;
		case 6: mk_lib_crypto_alg_serpent_sse2_substitute_dec_6(msgs); break;
		case 7: mk_lib_crypto_alg_serpent_sse2_substitute_dec_7(msgs); break;
		default: mk_lang_assert(0); break;
	}
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_lt_enc(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;
	__m128i te;

	mk_lang_assert(msgs);

	mk_lib_crypto_alg_serpent_sse2_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_rotl2(&ta, 13);
	mk_lib_crypto_alg_serpent_sse2_ui_rotl2(&tc, 3);
	mk_lib_crypto_alg_serpent_sse2_ui_xor3(&ta, &tc, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_shl3(&ta, 3, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_rotl2(&tb, 1);
	mk_lib_crypto_alg_serpent_sse2_ui_rotl2(&td, 7);
	mk_lib_crypto_alg_serpent_sse2_ui_xor3(&tb, &td, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_shl3(&tb, 7, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_rotl2(&ta, 5);
	mk_lib_crypto_alg_serpent_sse2_ui_rotl2(&tc, 22);
	mk_lib_crypto_alg_serpent_sse2_store(msgs, &ta, &tb, &tc, &td);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_round_middle_enc(mk_lib_crypto_alg_serpent_schedule_pct const schedule, int const rnd_idx, mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(rnd_idx >= 0 && rnd_idx < mk_lib_crypto_alg_serpent_nr - 1);
	mk_lang_assert(msgs);

	mk_lib_crypto_alg_serpent_sse2_xor2(msgs, &schedule->m_data.m_msgs[rnd_idx]);
	mk_lib_crypto_alg_serpent_sse2_substitute_enc(rnd_idx % mk_lib_crypto_alg_serpent_sbox_count, msgs);
	mk_lib_crypto_alg_serpent_sse2_lt_enc(msgs);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_round_last_enc(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(msgs);

	mk_lib_crypto_alg_serpent_sse2_xor2(msgs, &schedule->m_data.m_msgs[mk_lib_crypto_alg_serpent_nr - 1]);
	mk_lib_crypto_alg_serpent_sse2_substitute_enc((mk_lib_crypto_alg_serpent_nr - 1) % mk_lib_crypto_alg_serpent_sbox_count, msgs);
	mk_lib_crypto_alg_serpent_sse2_xor2(msgs, &schedule->m_data.m_msgs[mk_lib_crypto_alg_serpent_nr - 0]);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_lt_dec(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;
	__m128i td;
	__m128i te;

	mk_lang_assert(msgs);

	mk_lib_crypto_alg_serpent_sse2_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_rotr2(&tc, 22);
	mk_lib_crypto_alg_serpent_sse2_ui_rotr2(&ta, 5);
	mk_lib_crypto_alg_serpent_sse2_ui_shl3(&tb, 7, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &td);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tc, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor3(&tb, &td, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&ta, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_rotr2(&td, 7);
	mk_lib_crypto_alg_serpent_sse2_ui_rotr2(&tb, 1);
	mk_lib_crypto_alg_serpent_sse2_ui_shl3(&ta, 3, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&td, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor3(&ta, &tc, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_xor2(&tb, &te);
	mk_lib_crypto_alg_serpent_sse2_ui_rotr2(&tc, 3);
	mk_lib_crypto_alg_serpent_sse2_ui_rotr2(&ta, 13);
	mk_lib_crypto_alg_serpent_sse2_store(msgs, &ta, &tb, &tc, &td);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_round_first_dec(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_alg_serpent_sse2_xor3(input, &schedule->m_data.m_msgs[(mk_lib_crypto_alg_serpent_nr - 0)], output);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_round_middle_dec(mk_lib_crypto_alg_serpent_schedule_pct const schedule, int const rnd_idx, mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(rnd_idx >= 0 && rnd_idx < mk_lib_crypto_alg_serpent_nr - 1);
	mk_lang_assert(msgs);

	mk_lib_crypto_alg_serpent_sse2_substitute_dec(((mk_lib_crypto_alg_serpent_nr - 1) - rnd_idx) % mk_lib_crypto_alg_serpent_sbox_count, msgs);
	mk_lib_crypto_alg_serpent_sse2_xor2(msgs, &schedule->m_data.m_msgs[(mk_lib_crypto_alg_serpent_nr - 1) - rnd_idx]);
	mk_lib_crypto_alg_serpent_sse2_lt_dec(msgs);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_sse2_round_last_dec(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(msgs);

	mk_lib_crypto_alg_serpent_sse2_substitute_dec(0 % mk_lib_crypto_alg_serpent_sbox_count, msgs);
	mk_lib_crypto_alg_serpent_sse2_xor2(msgs, &schedule->m_data.m_msgs[0]);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_schedule_encrypt_sse2(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock;
	mk_lang_types_sint_t i;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks % 4 == 0);

	for(iblock = 0; iblock != nblocks; iblock += 4)
	{
		mk_lib_crypto_alg_serpent_sse2_copy(&input[iblock], &output[iblock]);
		for(i = 0; i != mk_lib_crypto_alg_serpent_nr - 1; ++i)
		{
			mk_lib_crypto_alg_serpent_sse2_round_middle_enc(schedule, i, &output[iblock]);
		}
		mk_lib_crypto_alg_serpent_sse2_round_last_enc(schedule, &output[iblock]);
	}
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_schedule_decrypt_sse2(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock;
	mk_lang_types_sint_t i;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks % 4 == 0);

	for(iblock = 0; iblock != nblocks; iblock += 4)
	{
		mk_lib_crypto_alg_serpent_sse2_round_first_dec(schedule, &input[iblock], &output[iblock]);
		for(i = 0; i != mk_lib_crypto_alg_serpent_nr - 1; ++i)
		{
			mk_lib_crypto_alg_serpent_sse2_round_middle_dec(schedule, i, &output[iblock]);
		}
		mk_lib_crypto_alg_serpent_sse2_round_last_dec(schedule, &output[iblock]);
	}
}
