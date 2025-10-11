#ifndef mk_include_guard_mk_lib_crypto_alg_serpent_avx512_c
#define mk_include_guard_mk_lib_crypto_alg_serpent_avx512_c
#include "mk_lib_crypto_alg_serpent_avx512.h"

#include "mk_lang_assert.h"
#include "mk_lang_attribute.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_flatten.h"
#include "mk_lang_forceinline.h"
#include "mk_lang_inline.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_serpent_base.h"

#include <immintrin.h> /* AVX512 _mm512_and_si512 _mm512_load_si512 _mm512_or_si512 _mm512_set1_epi32 _mm512_set1_epi8 _mm512_slli_epi32 _mm512_srli_epi32 _mm512_store_si512 _mm512_unpackhi_epi32 _mm512_unpackhi_epi64 _mm512_unpacklo_epi32 _mm512_unpacklo_epi64 _mm512_xor_si512 */


#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2015
#pragma intrinsic(_mm512_and_si512)
#pragma intrinsic(_mm512_load_si512)
#pragma intrinsic(_mm512_or_si512)
#pragma intrinsic(_mm512_set1_epi32)
#pragma intrinsic(_mm512_set1_epi8)
#pragma intrinsic(_mm512_slli_epi32)
#pragma intrinsic(_mm512_srli_epi32)
#pragma intrinsic(_mm512_store_si512)
#pragma intrinsic(_mm512_unpackhi_epi32)
#pragma intrinsic(_mm512_unpackhi_epi64)
#pragma intrinsic(_mm512_unpacklo_epi32)
#pragma intrinsic(_mm512_unpacklo_epi64)
#pragma intrinsic(_mm512_xor_si512)
#endif


mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_assign(mk_lib_crypto_alg_serpent_avx512_uint_prt const a, mk_lib_crypto_alg_serpent_avx512_uint_prct const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	a->m_uint = b->m_uint;
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_and2(mk_lib_crypto_alg_serpent_avx512_uint_prt const a, mk_lib_crypto_alg_serpent_avx512_uint_prct const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	a->m_uint = _mm512_and_si512(a->m_uint, b->m_uint);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_not1(mk_lib_crypto_alg_serpent_avx512_uint_pt const a) mk_lang_noexcept { mk_lang_flatten
{
	mk_lib_crypto_alg_serpent_avx512_uint_t b;

	mk_lang_assert(a);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	b.m_uint = _mm512_set1_epi8('\xff');
	a->m_uint = _mm512_xor_si512(a->m_uint, b.m_uint);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_or2(mk_lib_crypto_alg_serpent_avx512_uint_prt const a, mk_lib_crypto_alg_serpent_avx512_uint_prct const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	a->m_uint = _mm512_or_si512(a->m_uint, b->m_uint);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_rotl2(mk_lib_crypto_alg_serpent_avx512_uint_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lib_crypto_alg_serpent_avx512_uint_t ta;
	mk_lib_crypto_alg_serpent_avx512_uint_t tb;

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	ta.m_uint = _mm512_slli_epi32(a->m_uint, ((mk_lang_types_uint_t)(b)));
	tb.m_uint = _mm512_srli_epi32(a->m_uint, ((mk_lang_types_uint_t)(32 - b)));
	a->m_uint = _mm512_or_si512(ta.m_uint, tb.m_uint);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_rotr2(mk_lib_crypto_alg_serpent_avx512_uint_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lib_crypto_alg_serpent_avx512_uint_t ta;
	mk_lib_crypto_alg_serpent_avx512_uint_t tb;

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	ta.m_uint = _mm512_srli_epi32(a->m_uint, ((mk_lang_types_uint_t)(b)));
	tb.m_uint = _mm512_slli_epi32(a->m_uint, ((mk_lang_types_uint_t)(32 - b)));
	a->m_uint = _mm512_or_si512(ta.m_uint, tb.m_uint);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_shl3(mk_lib_crypto_alg_serpent_avx512_uint_prct const a, mk_lang_types_sint_t const b, mk_lib_crypto_alg_serpent_avx512_uint_prt const c) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(c);
	mk_lang_assert(a != c);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	c->m_uint = _mm512_slli_epi32(a->m_uint, ((mk_lang_types_uint_t)(b)));
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_xor2(mk_lib_crypto_alg_serpent_avx512_uint_prt const a, mk_lib_crypto_alg_serpent_avx512_uint_prct const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	a->m_uint = _mm512_xor_si512(a->m_uint, b->m_uint);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_xor3(mk_lib_crypto_alg_serpent_avx512_uint_prct const a, mk_lib_crypto_alg_serpent_avx512_uint_prct const b, mk_lib_crypto_alg_serpent_avx512_uint_prt const c) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	c->m_uint = _mm512_xor_si512(a->m_uint, b->m_uint);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_broadcast(mk_lib_crypto_alg_serpent_avx512_uint_pt const a, mk_lib_crypto_alg_serpent_avx512_uints_pt const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	a->m_uint = _mm512_set1_epi32(*((mk_lang_types_sint_pct)(&b->m_data.m_uint32s[0])));
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_transpose_load(mk_lib_crypto_alg_serpent_avx512_uint_prt const ta, mk_lib_crypto_alg_serpent_avx512_uint_prt const tb, mk_lib_crypto_alg_serpent_avx512_uint_prt const tc, mk_lib_crypto_alg_serpent_avx512_uint_prt const td) mk_lang_noexcept { mk_lang_flatten
{
	mk_lib_crypto_alg_serpent_avx512_uint_t tta;
	mk_lib_crypto_alg_serpent_avx512_uint_t ttb;
	mk_lib_crypto_alg_serpent_avx512_uint_t ttc;
	mk_lib_crypto_alg_serpent_avx512_uint_t ttd;

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
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	tta.m_uint = _mm512_unpacklo_epi32(ta->m_uint, tb->m_uint);
	ttb.m_uint = _mm512_unpacklo_epi32(tc->m_uint, td->m_uint);
	ttc.m_uint = _mm512_unpackhi_epi32(ta->m_uint, tb->m_uint);
	ttd.m_uint = _mm512_unpackhi_epi32(tc->m_uint, td->m_uint);
	ta->m_uint = _mm512_unpacklo_epi64(tta.m_uint, ttb.m_uint);
	tb->m_uint = _mm512_unpackhi_epi64(tta.m_uint, ttb.m_uint);
	tc->m_uint = _mm512_unpacklo_epi64(ttc.m_uint, ttd.m_uint);
	td->m_uint = _mm512_unpackhi_epi64(ttc.m_uint, ttd.m_uint);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_transpose_store(mk_lib_crypto_alg_serpent_avx512_uint_prt const ta, mk_lib_crypto_alg_serpent_avx512_uint_prt const tb, mk_lib_crypto_alg_serpent_avx512_uint_prt const tc, mk_lib_crypto_alg_serpent_avx512_uint_prt const td) mk_lang_noexcept { mk_lang_flatten
{
	mk_lib_crypto_alg_serpent_avx512_uint_t tta;
	mk_lib_crypto_alg_serpent_avx512_uint_t ttb;
	mk_lib_crypto_alg_serpent_avx512_uint_t ttc;
	mk_lib_crypto_alg_serpent_avx512_uint_t ttd;

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
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	tta.m_uint = _mm512_unpacklo_epi32(ta->m_uint, tb->m_uint);
	ttb.m_uint = _mm512_unpacklo_epi32(tc->m_uint, td->m_uint);
	ttc.m_uint = _mm512_unpackhi_epi32(ta->m_uint, tb->m_uint);
	ttd.m_uint = _mm512_unpackhi_epi32(tc->m_uint, td->m_uint);
	ta->m_uint = _mm512_unpacklo_epi64(tta.m_uint, ttb.m_uint);
	tb->m_uint = _mm512_unpackhi_epi64(tta.m_uint, ttb.m_uint);
	tc->m_uint = _mm512_unpacklo_epi64(ttc.m_uint, ttd.m_uint);
	td->m_uint = _mm512_unpackhi_epi64(ttc.m_uint, ttd.m_uint);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_load(mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_ct, msgs, mk_lib_crypto_alg_serpent_avx512_blocks), mk_lib_crypto_alg_serpent_avx512_uint_prt const ta, mk_lib_crypto_alg_serpent_avx512_uint_prt const tb, mk_lib_crypto_alg_serpent_avx512_uint_prt const tc, mk_lib_crypto_alg_serpent_avx512_uint_prt const td) mk_lang_noexcept { mk_lang_flatten
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
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x3f) == 0);

	ta->m_uint = _mm512_load_si512(((__m512i const*)(&msgs[ 0].m_data.m_uint8s[0])));
	tb->m_uint = _mm512_load_si512(((__m512i const*)(&msgs[ 4].m_data.m_uint8s[0])));
	tc->m_uint = _mm512_load_si512(((__m512i const*)(&msgs[ 8].m_data.m_uint8s[0])));
	td->m_uint = _mm512_load_si512(((__m512i const*)(&msgs[12].m_data.m_uint8s[0])));
	mk_lib_crypto_alg_serpent_avx512_hlp_transpose_load(ta, tb, tc, td);
}}

mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_store(mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_t, msgs, mk_lib_crypto_alg_serpent_avx512_blocks), mk_lib_crypto_alg_serpent_avx512_uint_prt const ta, mk_lib_crypto_alg_serpent_avx512_uint_prt const tb, mk_lib_crypto_alg_serpent_avx512_uint_prt const tc, mk_lib_crypto_alg_serpent_avx512_uint_prt const td) mk_lang_noexcept { mk_lang_flatten
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
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x3f) == 0);

	mk_lib_crypto_alg_serpent_avx512_hlp_transpose_store(ta, tb, tc, td);
	_mm512_store_si512(((__m512i*)(&msgs[ 0].m_data.m_uint8s[0])), ta->m_uint);
	_mm512_store_si512(((__m512i*)(&msgs[ 4].m_data.m_uint8s[0])), tb->m_uint);
	_mm512_store_si512(((__m512i*)(&msgs[ 8].m_data.m_uint8s[0])), tc->m_uint);
	_mm512_store_si512(((__m512i*)(&msgs[12].m_data.m_uint8s[0])), td->m_uint);
}}


#define mk_lib_crypto_alg_serpent_t_name         mk_lib_crypto_alg_serpent_avx512
#define mk_lib_crypto_alg_serpent_t_type         mk_lib_crypto_alg_serpent_avx512_uint_t
#define mk_lib_crypto_alg_serpent_t_bits         mk_lib_crypto_alg_serpent_avx512_bits
#define mk_lib_crypto_alg_serpent_t_constexpr    0
#define mk_lib_crypto_alg_serpent_t_uints_t      mk_lib_crypto_alg_serpent_avx512_uints_t
#define mk_lib_crypto_alg_serpent_t_ui_assign    mk_lib_crypto_alg_serpent_avx512_hlp_ui_assign
#define mk_lib_crypto_alg_serpent_t_ui_and2      mk_lib_crypto_alg_serpent_avx512_hlp_ui_and2
#define mk_lib_crypto_alg_serpent_t_ui_not1      mk_lib_crypto_alg_serpent_avx512_hlp_ui_not1
#define mk_lib_crypto_alg_serpent_t_ui_or2       mk_lib_crypto_alg_serpent_avx512_hlp_ui_or2
#define mk_lib_crypto_alg_serpent_t_ui_rotl2     mk_lib_crypto_alg_serpent_avx512_hlp_ui_rotl2
#define mk_lib_crypto_alg_serpent_t_ui_rotr2     mk_lib_crypto_alg_serpent_avx512_hlp_ui_rotr2
#define mk_lib_crypto_alg_serpent_t_ui_shl3      mk_lib_crypto_alg_serpent_avx512_hlp_ui_shl3
#define mk_lib_crypto_alg_serpent_t_ui_xor2      mk_lib_crypto_alg_serpent_avx512_hlp_ui_xor2
#define mk_lib_crypto_alg_serpent_t_ui_xor3      mk_lib_crypto_alg_serpent_avx512_hlp_ui_xor3
#define mk_lib_crypto_alg_serpent_t_ui_broadcast mk_lib_crypto_alg_serpent_avx512_hlp_ui_broadcast
#define mk_lib_crypto_alg_serpent_t_load         mk_lib_crypto_alg_serpent_avx512_hlp_load
#define mk_lib_crypto_alg_serpent_t_store        mk_lib_crypto_alg_serpent_avx512_hlp_store
#define mk_lib_crypto_alg_serpent_t_target       mk_lang_attribute_target("avx512f")
#include "mk_lib_crypto_alg_serpent_inl_filec.h"
#include "mk_lib_crypto_alg_serpent_inl_fileu.h"


#endif
