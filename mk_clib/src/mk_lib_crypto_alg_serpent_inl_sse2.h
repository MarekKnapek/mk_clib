#include "mk_lang_assert.h"
#include "mk_lang_attribute.h"
#include "mk_lang_bool.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_gnuc.h"
#include "mk_lang_inline.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint32.h"

#include <emmintrin.h> /* SSE2 __m128i _mm_and_si128 _mm_cmpeq_epi32 _mm_load_si128 _mm_or_si128 _mm_set1_epi32 _mm_slli_epi32 _mm_srli_epi32 _mm_store_si128 _mm_unpackhi_epi32 _mm_unpackhi_epi64 _mm_unpacklo_epi32 _mm_unpacklo_epi64 _mm_xor_si128 */


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


#define mk_lib_crypto_alg_serpent_inl_t_name         mk_lib_crypto_alg_serpent_sse2
#define mk_lib_crypto_alg_serpent_inl_t_type         __m128i
#define mk_lib_crypto_alg_serpent_inl_t_bits         128
#define mk_lib_crypto_alg_serpent_inl_t_constexpr    0
#define mk_lib_crypto_alg_serpent_inl_t_uints_t      mk_lib_crypto_alg_serpent_sse2_uints_t
#define mk_lib_crypto_alg_serpent_inl_t_ui_assign    mk_lib_crypto_alg_serpent_sse2_ui_assign
#define mk_lib_crypto_alg_serpent_inl_t_ui_and2      mk_lib_crypto_alg_serpent_sse2_ui_and2
#define mk_lib_crypto_alg_serpent_inl_t_ui_not1      mk_lib_crypto_alg_serpent_sse2_ui_not1
#define mk_lib_crypto_alg_serpent_inl_t_ui_or2       mk_lib_crypto_alg_serpent_sse2_ui_or2
#define mk_lib_crypto_alg_serpent_inl_t_ui_rotl2     mk_lib_crypto_alg_serpent_sse2_ui_rotl2
#define mk_lib_crypto_alg_serpent_inl_t_ui_rotr2     mk_lib_crypto_alg_serpent_sse2_ui_rotr2
#define mk_lib_crypto_alg_serpent_inl_t_ui_shl3      mk_lib_crypto_alg_serpent_sse2_ui_shl3
#define mk_lib_crypto_alg_serpent_inl_t_ui_xor2      mk_lib_crypto_alg_serpent_sse2_ui_xor2
#define mk_lib_crypto_alg_serpent_inl_t_ui_xor3      mk_lib_crypto_alg_serpent_sse2_ui_xor3
#define mk_lib_crypto_alg_serpent_inl_t_ui_broadcast mk_lib_crypto_alg_serpent_sse2_ui_broadcast
#define mk_lib_crypto_alg_serpent_inl_t_load         mk_lib_crypto_alg_serpent_sse2_load
#define mk_lib_crypto_alg_serpent_inl_t_store        mk_lib_crypto_alg_serpent_sse2_store
#define mk_lib_crypto_alg_serpent_inl_t_target       mk_lang_gnuc_attribute_target("sse2")


union mk_lib_crypto_alg_serpent_sse2_uints_data_u
{
	mk_sl_cui_uint32_t m_uint32s[mk_lib_crypto_alg_serpent_inl_t_bits / 32];
	__m128i m_alignment;
};
typedef union mk_lib_crypto_alg_serpent_sse2_uints_data_u mk_lib_crypto_alg_serpent_sse2_uints_data_t;

struct mk_lib_crypto_alg_serpent_sse2_uints_s
{
	mk_lib_crypto_alg_serpent_sse2_uints_data_t m_data;
};
typedef struct mk_lib_crypto_alg_serpent_sse2_uints_s mk_lib_crypto_alg_serpent_sse2_uints_t;
typedef mk_lib_crypto_alg_serpent_sse2_uints_t const mk_lib_crypto_alg_serpent_sse2_uints_ct;
typedef mk_lib_crypto_alg_serpent_sse2_uints_t* mk_lib_crypto_alg_serpent_sse2_uints_pt;
typedef mk_lib_crypto_alg_serpent_sse2_uints_t const* mk_lib_crypto_alg_serpent_sse2_uints_pct;


mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("sse2") mk_lib_crypto_alg_serpent_sse2_ui_assign(__m128i* const a, __m128i const* const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	*a = *b;
}}

mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("sse2") mk_lib_crypto_alg_serpent_sse2_ui_and2(__m128i* const a, __m128i const* const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	*a = _mm_and_si128(*a, *b);
}}

mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("sse2") mk_lib_crypto_alg_serpent_sse2_ui_not1(__m128i* const a) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	__m128i b;

	mk_lang_assert(a);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	b = _mm_cmpeq_epi32(*a, *a);
	*a = _mm_xor_si128(*a, b);
}}

mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("sse2") mk_lib_crypto_alg_serpent_sse2_ui_or2(__m128i* const a, __m128i const* const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	*a = _mm_or_si128(*a, *b);
}}

mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("sse2") mk_lib_crypto_alg_serpent_sse2_ui_rotl2(__m128i* const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	__m128i ta;
	__m128i tb;

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	ta = _mm_slli_epi32(*a, b);
	tb = _mm_srli_epi32(*a, 32 - b);
	*a = _mm_or_si128(ta, tb);
}}

mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("sse2") mk_lib_crypto_alg_serpent_sse2_ui_rotr2(__m128i* const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	__m128i ta;
	__m128i tb;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	ta = _mm_srli_epi32(*a, b);
	tb = _mm_slli_epi32(*a, 32 - b);
	*a = _mm_or_si128(ta, tb);
}}

mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("sse2") mk_lib_crypto_alg_serpent_sse2_ui_shl3(__m128i const* const a, mk_lang_types_sint_t const b, __m128i* const c) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(c);
	mk_lang_assert(a != c);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	*c = _mm_slli_epi32(*a, b);
}}

mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("sse2") mk_lib_crypto_alg_serpent_sse2_ui_xor2(__m128i* const a, __m128i const* const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	*a = _mm_xor_si128(*a, *b);
}}

mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("sse2") mk_lib_crypto_alg_serpent_sse2_ui_xor3(__m128i const* const a, __m128i const* const b, __m128i* const c) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	*c = _mm_xor_si128(*a, *b);
}}

mk_lang_attribute_msvc_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_gnuc_attribute_target("sse2") mk_lib_crypto_alg_serpent_sse2_ui_broadcast(__m128i* const a, mk_lib_crypto_alg_serpent_sse2_uints_pt const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(mk_lang_cpuid_has_sse2());

	*a = _mm_set1_epi32(*((mk_lang_types_sint_pct)(&b->m_data.m_uint32s[0])));
}}

#define mk_lib_crypto_alg_serpent_sse2_transpose_load(ta, tb, tc, td) \
do mk_lang_attribute_msvc_flatten \
{ \
	__m128i tta;                              \
	__m128i ttb;                              \
	__m128i ttc;                              \
	__m128i ttd;                              \
	mk_lang_assert(ta);                       \
	mk_lang_assert(tb);                       \
	mk_lang_assert(tc);                       \
	mk_lang_assert(td);                       \
	mk_lang_assert(ta != tb);                 \
	mk_lang_assert(ta != tc);                 \
	mk_lang_assert(ta != td);                 \
	mk_lang_assert(tb != tc);                 \
	mk_lang_assert(tb != td);                 \
	mk_lang_assert(tc != td);                 \
	mk_lang_assert(mk_lang_cpuid_has_sse2()); \
	tta = _mm_unpacklo_epi32(*ta, *tb);       \
	ttb = _mm_unpacklo_epi32(*tc, *td);       \
	ttc = _mm_unpackhi_epi32(*ta, *tb);       \
	ttd = _mm_unpackhi_epi32(*tc, *td);       \
	*ta = _mm_unpacklo_epi64(tta, ttb);       \
	*tb = _mm_unpackhi_epi64(tta, ttb);       \
	*tc = _mm_unpacklo_epi64(ttc, ttd);       \
	*td = _mm_unpackhi_epi64(ttc, ttd);       \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_sse2_load(msgs, ta, tb, tc, td) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(msgs);                                                  \
	mk_lang_assert(ta);                                                    \
	mk_lang_assert(tb);                                                    \
	mk_lang_assert(tc);                                                    \
	mk_lang_assert(td);                                                    \
	mk_lang_assert(ta != tb);                                              \
	mk_lang_assert(ta != tc);                                              \
	mk_lang_assert(ta != td);                                              \
	mk_lang_assert(tb != tc);                                              \
	mk_lang_assert(tb != td);                                              \
	mk_lang_assert(tc != td);                                              \
	mk_lang_assert(mk_lang_cpuid_has_sse2());                              \
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);        \
	*ta = _mm_load_si128(((__m128i const*)(&msgs[0].m_data.m_uint8s[0]))); \
	*tb = _mm_load_si128(((__m128i const*)(&msgs[1].m_data.m_uint8s[0]))); \
	*tc = _mm_load_si128(((__m128i const*)(&msgs[2].m_data.m_uint8s[0]))); \
	*td = _mm_load_si128(((__m128i const*)(&msgs[3].m_data.m_uint8s[0]))); \
	mk_lib_crypto_alg_serpent_sse2_transpose_load(ta, tb, tc, td);         \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_sse2_transpose_store(ta, tb, tc, td) \
do mk_lang_attribute_msvc_flatten \
{ \
	__m128i tta;                              \
	__m128i ttb;                              \
	__m128i ttc;                              \
	__m128i ttd;                              \
	mk_lang_assert(ta);                       \
	mk_lang_assert(tb);                       \
	mk_lang_assert(tc);                       \
	mk_lang_assert(td);                       \
	mk_lang_assert(ta != tb);                 \
	mk_lang_assert(ta != tc);                 \
	mk_lang_assert(ta != td);                 \
	mk_lang_assert(tb != tc);                 \
	mk_lang_assert(tb != td);                 \
	mk_lang_assert(tc != td);                 \
	mk_lang_assert(mk_lang_cpuid_has_sse2()); \
	tta = _mm_unpacklo_epi32(*ta, *tb);       \
	ttb = _mm_unpacklo_epi32(*tc, *td);       \
	ttc = _mm_unpackhi_epi32(*ta, *tb);       \
	ttd = _mm_unpackhi_epi32(*tc, *td);       \
	*ta = _mm_unpacklo_epi64(tta, ttb);       \
	*tb = _mm_unpackhi_epi64(tta, ttb);       \
	*tc = _mm_unpacklo_epi64(ttc, ttd);       \
	*td = _mm_unpackhi_epi64(ttc, ttd);       \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_sse2_store(msgs, ta, tb, tc, td) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_assert(msgs);                                            \
	mk_lang_assert(ta);                                              \
	mk_lang_assert(tb);                                              \
	mk_lang_assert(tc);                                              \
	mk_lang_assert(td);                                              \
	mk_lang_assert(ta != tb);                                        \
	mk_lang_assert(ta != tc);                                        \
	mk_lang_assert(ta != td);                                        \
	mk_lang_assert(tb != tc);                                        \
	mk_lang_assert(tb != td);                                        \
	mk_lang_assert(tc != td);                                        \
	mk_lang_assert(mk_lang_cpuid_has_sse2());                        \
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0xf) == 0);  \
	mk_lib_crypto_alg_serpent_sse2_transpose_store(ta, tb, tc, td);  \
	_mm_store_si128(((__m128i*)(&msgs[0].m_data.m_uint8s[0])), *ta); \
	_mm_store_si128(((__m128i*)(&msgs[1].m_data.m_uint8s[0])), *tb); \
	_mm_store_si128(((__m128i*)(&msgs[2].m_data.m_uint8s[0])), *tc); \
	_mm_store_si128(((__m128i*)(&msgs[3].m_data.m_uint8s[0])), *td); \
}while(mk_lang_false)


#include "mk_lib_crypto_alg_serpent_inl.h"
