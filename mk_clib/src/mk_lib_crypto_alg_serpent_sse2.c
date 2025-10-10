#ifndef mk_include_guard_mk_lib_crypto_alg_serpent_sse2_c
#define mk_include_guard_mk_lib_crypto_alg_serpent_sse2_c
#include "mk_lib_crypto_alg_serpent_sse2.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_flatten.h"
#include "mk_lang_forceinline.h"
#include "mk_lang_inline.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_serpent_base.h"

#include <emmintrin.h> /* SSE2 _mm_and_si128 _mm_cmpeq_epi32 _mm_load_si128 _mm_or_si128 _mm_set1_epi32 _mm_slli_epi32 _mm_srli_epi32 _mm_store_si128 _mm_unpackhi_epi32 _mm_unpackhi_epi64 _mm_unpacklo_epi32 _mm_unpacklo_epi64 _mm_xor_si128 */


#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2015
#pragma intrinsic(_mm_and_si128)
#pragma intrinsic(_mm_cmpeq_epi32)
#pragma intrinsic(_mm_load_si128)
#pragma intrinsic(_mm_or_si128)
#pragma intrinsic(_mm_set1_epi32)
#pragma intrinsic(_mm_slli_epi32)
#pragma intrinsic(_mm_srli_epi32)
#pragma intrinsic(_mm_store_si128)
#pragma intrinsic(_mm_unpackhi_epi32)
#pragma intrinsic(_mm_unpackhi_epi64)
#pragma intrinsic(_mm_unpacklo_epi32)
#pragma intrinsic(_mm_unpacklo_epi64)
#pragma intrinsic(_mm_xor_si128)
#endif


mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_sse2_hlp_ui_assign(mk_lib_crypto_alg_serpent_sse2_uint_prt const a, mk_lib_crypto_alg_serpent_sse2_uint_prct const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	a->m_uint = b->m_uint;
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_sse2_hlp_ui_and2(mk_lib_crypto_alg_serpent_sse2_uint_prt const a, mk_lib_crypto_alg_serpent_sse2_uint_prct const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	a->m_uint = _mm_and_si128(a->m_uint, b->m_uint);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_sse2_hlp_ui_not1(mk_lib_crypto_alg_serpent_sse2_uint_pt const a) mk_lang_noexcept { mk_lang_flatten
{
	mk_lib_crypto_alg_serpent_sse2_uint_t b;

	mk_lang_assert(a);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	b.m_uint = _mm_cmpeq_epi32(a->m_uint, a->m_uint);
	a->m_uint = _mm_xor_si128(a->m_uint, b.m_uint);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_sse2_hlp_ui_or2(mk_lib_crypto_alg_serpent_sse2_uint_prt const a, mk_lib_crypto_alg_serpent_sse2_uint_prct const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	a->m_uint = _mm_or_si128(a->m_uint, b->m_uint);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_sse2_hlp_ui_rotl2(mk_lib_crypto_alg_serpent_sse2_uint_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lib_crypto_alg_serpent_sse2_uint_t ta;
	mk_lib_crypto_alg_serpent_sse2_uint_t tb;

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	ta.m_uint = _mm_slli_epi32(a->m_uint, b);
	tb.m_uint = _mm_srli_epi32(a->m_uint, 32 - b);
	a->m_uint = _mm_or_si128(ta.m_uint, tb.m_uint);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_sse2_hlp_ui_rotr2(mk_lib_crypto_alg_serpent_sse2_uint_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lib_crypto_alg_serpent_sse2_uint_t ta;
	mk_lib_crypto_alg_serpent_sse2_uint_t tb;

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	ta.m_uint = _mm_srli_epi32(a->m_uint, b);
	tb.m_uint = _mm_slli_epi32(a->m_uint, 32 - b);
	a->m_uint = _mm_or_si128(ta.m_uint, tb.m_uint);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_sse2_hlp_ui_shl3(mk_lib_crypto_alg_serpent_sse2_uint_prct const a, mk_lang_types_sint_t const b, mk_lib_crypto_alg_serpent_sse2_uint_prt const c) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(c);
	mk_lang_assert(a != c);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	c->m_uint = _mm_slli_epi32(a->m_uint, b);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_sse2_hlp_ui_xor2(mk_lib_crypto_alg_serpent_sse2_uint_prt const a, mk_lib_crypto_alg_serpent_sse2_uint_prct const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	a->m_uint = _mm_xor_si128(a->m_uint, b->m_uint);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_sse2_hlp_ui_xor3(mk_lib_crypto_alg_serpent_sse2_uint_prct const a, mk_lib_crypto_alg_serpent_sse2_uint_prct const b, mk_lib_crypto_alg_serpent_sse2_uint_prt const c) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	c->m_uint = _mm_xor_si128(a->m_uint, b->m_uint);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_sse2_hlp_ui_broadcast(mk_lib_crypto_alg_serpent_sse2_uint_pt const a, mk_lib_crypto_alg_serpent_sse2_uints_pt const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	a->m_uint = _mm_set1_epi32(*((mk_lang_types_sint_pct)(&b->m_data.m_uint32s[0])));
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_sse2_hlp_transpose_load(mk_lib_crypto_alg_serpent_sse2_uint_prt const ta, mk_lib_crypto_alg_serpent_sse2_uint_prt const tb, mk_lib_crypto_alg_serpent_sse2_uint_prt const tc, mk_lib_crypto_alg_serpent_sse2_uint_prt const td) mk_lang_noexcept { mk_lang_flatten
{
	mk_lib_crypto_alg_serpent_sse2_uint_t tta;
	mk_lib_crypto_alg_serpent_sse2_uint_t ttb;
	mk_lib_crypto_alg_serpent_sse2_uint_t ttc;
	mk_lib_crypto_alg_serpent_sse2_uint_t ttd;

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

	tta.m_uint = _mm_unpacklo_epi32(ta->m_uint, tb->m_uint);
	ttb.m_uint = _mm_unpacklo_epi32(tc->m_uint, td->m_uint);
	ttc.m_uint = _mm_unpackhi_epi32(ta->m_uint, tb->m_uint);
	ttd.m_uint = _mm_unpackhi_epi32(tc->m_uint, td->m_uint);
	ta->m_uint = _mm_unpacklo_epi64(tta.m_uint, ttb.m_uint);
	tb->m_uint = _mm_unpackhi_epi64(tta.m_uint, ttb.m_uint);
	tc->m_uint = _mm_unpacklo_epi64(ttc.m_uint, ttd.m_uint);
	td->m_uint = _mm_unpackhi_epi64(ttc.m_uint, ttd.m_uint);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_sse2_hlp_transpose_store(mk_lib_crypto_alg_serpent_sse2_uint_prt const ta, mk_lib_crypto_alg_serpent_sse2_uint_prt const tb, mk_lib_crypto_alg_serpent_sse2_uint_prt const tc, mk_lib_crypto_alg_serpent_sse2_uint_prt const td) mk_lang_noexcept { mk_lang_flatten
{
	mk_lib_crypto_alg_serpent_sse2_uint_t tta;
	mk_lib_crypto_alg_serpent_sse2_uint_t ttb;
	mk_lib_crypto_alg_serpent_sse2_uint_t ttc;
	mk_lib_crypto_alg_serpent_sse2_uint_t ttd;

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

	tta.m_uint = _mm_unpacklo_epi32(ta->m_uint, tb->m_uint);
	ttb.m_uint = _mm_unpacklo_epi32(tc->m_uint, td->m_uint);
	ttc.m_uint = _mm_unpackhi_epi32(ta->m_uint, tb->m_uint);
	ttd.m_uint = _mm_unpackhi_epi32(tc->m_uint, td->m_uint);
	ta->m_uint = _mm_unpacklo_epi64(tta.m_uint, ttb.m_uint);
	tb->m_uint = _mm_unpackhi_epi64(tta.m_uint, ttb.m_uint);
	tc->m_uint = _mm_unpacklo_epi64(ttc.m_uint, ttd.m_uint);
	td->m_uint = _mm_unpackhi_epi64(ttc.m_uint, ttd.m_uint);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_sse2_hlp_load(mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_ct, msgs, mk_lib_crypto_alg_serpent_sse2_blocks), mk_lib_crypto_alg_serpent_sse2_uint_prt const ta, mk_lib_crypto_alg_serpent_sse2_uint_prt const tb, mk_lib_crypto_alg_serpent_sse2_uint_prt const tc, mk_lib_crypto_alg_serpent_sse2_uint_prt const td) mk_lang_noexcept { mk_lang_flatten
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

	ta->m_uint = _mm_load_si128(((__m128i const*)(&msgs[0].m_data.m_uint8s[0])));
	tb->m_uint = _mm_load_si128(((__m128i const*)(&msgs[1].m_data.m_uint8s[0])));
	tc->m_uint = _mm_load_si128(((__m128i const*)(&msgs[2].m_data.m_uint8s[0])));
	td->m_uint = _mm_load_si128(((__m128i const*)(&msgs[3].m_data.m_uint8s[0])));
	mk_lib_crypto_alg_serpent_sse2_hlp_transpose_load(ta, tb, tc, td);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_sse2_hlp_store(mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_t, msgs, mk_lib_crypto_alg_serpent_sse2_blocks), mk_lib_crypto_alg_serpent_sse2_uint_prt const ta, mk_lib_crypto_alg_serpent_sse2_uint_prt const tb, mk_lib_crypto_alg_serpent_sse2_uint_prt const tc, mk_lib_crypto_alg_serpent_sse2_uint_prt const td) mk_lang_noexcept { mk_lang_flatten
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

	mk_lib_crypto_alg_serpent_sse2_hlp_transpose_store(ta, tb, tc, td);
	_mm_store_si128(((__m128i*)(&msgs[0].m_data.m_uint8s[0])), ta->m_uint);
	_mm_store_si128(((__m128i*)(&msgs[1].m_data.m_uint8s[0])), tb->m_uint);
	_mm_store_si128(((__m128i*)(&msgs[2].m_data.m_uint8s[0])), tc->m_uint);
	_mm_store_si128(((__m128i*)(&msgs[3].m_data.m_uint8s[0])), td->m_uint);
}}


#define mk_lib_crypto_alg_serpent_t_name         mk_lib_crypto_alg_serpent_sse2
#define mk_lib_crypto_alg_serpent_t_type         mk_lib_crypto_alg_serpent_sse2_uint_t
#define mk_lib_crypto_alg_serpent_t_bits         mk_lib_crypto_alg_serpent_sse2_bits
#define mk_lib_crypto_alg_serpent_t_constexpr    0
#define mk_lib_crypto_alg_serpent_t_uints_t      mk_lib_crypto_alg_serpent_sse2_uints_t
#define mk_lib_crypto_alg_serpent_t_ui_assign    mk_lib_crypto_alg_serpent_sse2_hlp_ui_assign
#define mk_lib_crypto_alg_serpent_t_ui_and2      mk_lib_crypto_alg_serpent_sse2_hlp_ui_and2
#define mk_lib_crypto_alg_serpent_t_ui_not1      mk_lib_crypto_alg_serpent_sse2_hlp_ui_not1
#define mk_lib_crypto_alg_serpent_t_ui_or2       mk_lib_crypto_alg_serpent_sse2_hlp_ui_or2
#define mk_lib_crypto_alg_serpent_t_ui_rotl2     mk_lib_crypto_alg_serpent_sse2_hlp_ui_rotl2
#define mk_lib_crypto_alg_serpent_t_ui_rotr2     mk_lib_crypto_alg_serpent_sse2_hlp_ui_rotr2
#define mk_lib_crypto_alg_serpent_t_ui_shl3      mk_lib_crypto_alg_serpent_sse2_hlp_ui_shl3
#define mk_lib_crypto_alg_serpent_t_ui_xor2      mk_lib_crypto_alg_serpent_sse2_hlp_ui_xor2
#define mk_lib_crypto_alg_serpent_t_ui_xor3      mk_lib_crypto_alg_serpent_sse2_hlp_ui_xor3
#define mk_lib_crypto_alg_serpent_t_ui_broadcast mk_lib_crypto_alg_serpent_sse2_hlp_ui_broadcast
#define mk_lib_crypto_alg_serpent_t_load         mk_lib_crypto_alg_serpent_sse2_hlp_load
#define mk_lib_crypto_alg_serpent_t_store        mk_lib_crypto_alg_serpent_sse2_hlp_store
#define mk_lib_crypto_alg_serpent_t_target
#include "mk_lib_crypto_alg_serpent_inl_filec.h"
#include "mk_lib_crypto_alg_serpent_inl_fileu.h"


#endif
