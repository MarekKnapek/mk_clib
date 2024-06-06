#include "mk_lang_assert.h"
#include "mk_lang_attribute.h"
#include "mk_lang_bool.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_gnuc.h"
#include "mk_lang_inline.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint32.h"

#include <immintrin.h> /* AVX512 __m512i _mm512_and_si512 _mm512_load_si512 _mm512_or_si512 _mm512_set1_epi32 _mm512_set1_epi8 _mm512_slli_epi32 _mm512_srli_epi32 _mm512_store_si512 _mm512_unpackhi_epi32 _mm512_unpackhi_epi64 _mm512_unpacklo_epi32 _mm512_unpacklo_epi64 _mm512_xor_si512 */


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


#define mk_lib_crypto_alg_serpent_inl_t_name         mk_lib_crypto_alg_serpent_avx512
#define mk_lib_crypto_alg_serpent_inl_t_type         __m512i
#define mk_lib_crypto_alg_serpent_inl_t_bits         512
#define mk_lib_crypto_alg_serpent_inl_t_constexpr    0
#define mk_lib_crypto_alg_serpent_inl_t_uints_t      mk_lib_crypto_alg_serpent_avx512_uints_t
#define mk_lib_crypto_alg_serpent_inl_t_ui_assign    mk_lib_crypto_alg_serpent_avx512_ui_assign
#define mk_lib_crypto_alg_serpent_inl_t_ui_and2      mk_lib_crypto_alg_serpent_avx512_ui_and2
#define mk_lib_crypto_alg_serpent_inl_t_ui_not1      mk_lib_crypto_alg_serpent_avx512_ui_not1
#define mk_lib_crypto_alg_serpent_inl_t_ui_or2       mk_lib_crypto_alg_serpent_avx512_ui_or2
#define mk_lib_crypto_alg_serpent_inl_t_ui_rotl2     mk_lib_crypto_alg_serpent_avx512_ui_rotl2
#define mk_lib_crypto_alg_serpent_inl_t_ui_rotr2     mk_lib_crypto_alg_serpent_avx512_ui_rotr2
#define mk_lib_crypto_alg_serpent_inl_t_ui_shl3      mk_lib_crypto_alg_serpent_avx512_ui_shl3
#define mk_lib_crypto_alg_serpent_inl_t_ui_xor2      mk_lib_crypto_alg_serpent_avx512_ui_xor2
#define mk_lib_crypto_alg_serpent_inl_t_ui_xor3      mk_lib_crypto_alg_serpent_avx512_ui_xor3
#define mk_lib_crypto_alg_serpent_inl_t_ui_broadcast mk_lib_crypto_alg_serpent_avx512_ui_broadcast
#define mk_lib_crypto_alg_serpent_inl_t_load         mk_lib_crypto_alg_serpent_avx512_load
#define mk_lib_crypto_alg_serpent_inl_t_store        mk_lib_crypto_alg_serpent_avx512_store
#define mk_lib_crypto_alg_serpent_inl_t_target       mk_lang_gnuc_attribute_target("avx512f")


union mk_lib_crypto_alg_serpent_avx512_uints_data_u
{
	mk_sl_cui_uint32_t m_uint32s[mk_lib_crypto_alg_serpent_inl_t_bits / 32];
	__m512i m_alignment;
};
typedef union mk_lib_crypto_alg_serpent_avx512_uints_data_u mk_lib_crypto_alg_serpent_avx512_uints_data_t;

struct mk_lib_crypto_alg_serpent_avx512_uints_s
{
	mk_lib_crypto_alg_serpent_avx512_uints_data_t m_data;
};
typedef struct mk_lib_crypto_alg_serpent_avx512_uints_s mk_lib_crypto_alg_serpent_avx512_uints_t;
typedef mk_lib_crypto_alg_serpent_avx512_uints_t const mk_lib_crypto_alg_serpent_avx512_uints_ct;
typedef mk_lib_crypto_alg_serpent_avx512_uints_t* mk_lib_crypto_alg_serpent_avx512_uints_pt;
typedef mk_lib_crypto_alg_serpent_avx512_uints_t const* mk_lib_crypto_alg_serpent_avx512_uints_pct;


mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_ui_assign(__m512i* const a, __m512i const* const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	*a = *b;
}}

mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_ui_and2(__m512i* const a, __m512i const* const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	*a = _mm512_and_si512(*a, *b);
}}

mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_ui_not1(__m512i* const a) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	__m512i b;

	mk_lang_assert(a);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	b = _mm512_set1_epi8('\xff');
	*a = _mm512_xor_si512(*a, b);
}}

mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_ui_or2(__m512i* const a, __m512i const* const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	*a = _mm512_or_si512(*a, *b);
}}

mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_ui_rotl2(__m512i* const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	__m512i ta;
	__m512i tb;

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	ta = _mm512_slli_epi32(*a, b);
	tb = _mm512_srli_epi32(*a, 32 - b);
	*a = _mm512_or_si512(ta, tb);
}}

mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_ui_rotr2(__m512i* const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	__m512i ta;
	__m512i tb;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	ta = _mm512_srli_epi32(*a, b);
	tb = _mm512_slli_epi32(*a, 32 - b);
	*a = _mm512_or_si512(ta, tb);
}}

mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_ui_shl3(__m512i const* const a, mk_lang_types_sint_t const b, __m512i* const c) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(c);
	mk_lang_assert(a != c);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	*c = _mm512_slli_epi32(*a, b);
}}

mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_ui_xor2(__m512i* const a, __m512i const* const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	*a = _mm512_xor_si512(*a, *b);
}}

mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_ui_xor3(__m512i const* const a, __m512i const* const b, __m512i* const c) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	*c = _mm512_xor_si512(*a, *b);
}}

mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_ui_broadcast(__m512i* const a, mk_lib_crypto_alg_serpent_avx512_uints_pt const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());

	*a = _mm512_set1_epi32(*((mk_lang_types_sint_pct)(&b->m_data.m_uint32s[0])));
}}

#define mk_lib_crypto_alg_serpent_avx512_transpose_load(ta, tb, tc, td) \
do mk_lang_attribute_msvc_flatten \
{ \
	__m512i tta;                                  \
	__m512i ttb;                                  \
	__m512i ttc;                                  \
	__m512i ttd;                                  \
	mk_lang_assert(ta);                           \
	mk_lang_assert(tb);                           \
	mk_lang_assert(tc);                           \
	mk_lang_assert(td);                           \
	mk_lang_assert(ta != tb);                     \
	mk_lang_assert(ta != tc);                     \
	mk_lang_assert(ta != td);                     \
	mk_lang_assert(tb != tc);                     \
	mk_lang_assert(tb != td);                     \
	mk_lang_assert(tc != td);                     \
	mk_lang_assert(mk_lang_cpuid_has_avx512_f()); \
	tta = _mm512_unpacklo_epi32(*ta, *tb);        \
	ttb = _mm512_unpacklo_epi32(*tc, *td);        \
	ttc = _mm512_unpackhi_epi32(*ta, *tb);        \
	ttd = _mm512_unpackhi_epi32(*tc, *td);        \
	*ta = _mm512_unpacklo_epi64(tta, ttb);        \
	*tb = _mm512_unpackhi_epi64(tta, ttb);        \
	*tc = _mm512_unpacklo_epi64(ttc, ttd);        \
	*td = _mm512_unpackhi_epi64(ttc, ttd);        \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_avx512_load(msgs, ta, tb, tc, td) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(msgs);                                                      \
	mk_lang_assert(ta);                                                        \
	mk_lang_assert(tb);                                                        \
	mk_lang_assert(tc);                                                        \
	mk_lang_assert(td);                                                        \
	mk_lang_assert(ta != tb);                                                  \
	mk_lang_assert(ta != tc);                                                  \
	mk_lang_assert(ta != td);                                                  \
	mk_lang_assert(tb != tc);                                                  \
	mk_lang_assert(tb != td);                                                  \
	mk_lang_assert(tc != td);                                                  \
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());                              \
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x3f) == 0);           \
	*ta = _mm512_load_si512(((__m512i const*)(&msgs[ 0].m_data.m_uint8s[0]))); \
	*tb = _mm512_load_si512(((__m512i const*)(&msgs[ 4].m_data.m_uint8s[0]))); \
	*tc = _mm512_load_si512(((__m512i const*)(&msgs[ 8].m_data.m_uint8s[0]))); \
	*td = _mm512_load_si512(((__m512i const*)(&msgs[12].m_data.m_uint8s[0]))); \
	mk_lib_crypto_alg_serpent_avx512_transpose_load(ta, tb, tc, td);           \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_avx512_transpose_store(ta, tb, tc, td) \
do mk_lang_attribute_msvc_flatten \
{ \
	__m512i tta;                                  \
	__m512i ttb;                                  \
	__m512i ttc;                                  \
	__m512i ttd;                                  \
	mk_lang_assert(ta);                           \
	mk_lang_assert(tb);                           \
	mk_lang_assert(tc);                           \
	mk_lang_assert(td);                           \
	mk_lang_assert(ta != tb);                     \
	mk_lang_assert(ta != tc);                     \
	mk_lang_assert(ta != td);                     \
	mk_lang_assert(tb != tc);                     \
	mk_lang_assert(tb != td);                     \
	mk_lang_assert(tc != td);                     \
	mk_lang_assert(mk_lang_cpuid_has_avx512_f()); \
	tta = _mm512_unpacklo_epi32(*ta, *tb);        \
	ttb = _mm512_unpacklo_epi32(*tc, *td);        \
	ttc = _mm512_unpackhi_epi32(*ta, *tb);        \
	ttd = _mm512_unpackhi_epi32(*tc, *td);        \
	*ta = _mm512_unpacklo_epi64(tta, ttb);        \
	*tb = _mm512_unpackhi_epi64(tta, ttb);        \
	*tc = _mm512_unpacklo_epi64(ttc, ttd);        \
	*td = _mm512_unpackhi_epi64(ttc, ttd);        \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_avx512_store(msgs, ta, tb, tc, td) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(msgs);                                                \
	mk_lang_assert(ta);                                                  \
	mk_lang_assert(tb);                                                  \
	mk_lang_assert(tc);                                                  \
	mk_lang_assert(td);                                                  \
	mk_lang_assert(ta != tb);                                            \
	mk_lang_assert(ta != tc);                                            \
	mk_lang_assert(ta != td);                                            \
	mk_lang_assert(tb != tc);                                            \
	mk_lang_assert(tb != td);                                            \
	mk_lang_assert(tc != td);                                            \
	mk_lang_assert(mk_lang_cpuid_has_avx512_f());                        \
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x3f) == 0);     \
	mk_lib_crypto_alg_serpent_avx512_transpose_store(ta, tb, tc, td);    \
	_mm512_store_si512(((__m512i*)(&msgs[ 0].m_data.m_uint8s[0])), *ta); \
	_mm512_store_si512(((__m512i*)(&msgs[ 4].m_data.m_uint8s[0])), *tb); \
	_mm512_store_si512(((__m512i*)(&msgs[ 8].m_data.m_uint8s[0])), *tc); \
	_mm512_store_si512(((__m512i*)(&msgs[12].m_data.m_uint8s[0])), *td); \
}while(mk_lang_false)


#include "mk_lib_crypto_alg_serpent_inl.h"
