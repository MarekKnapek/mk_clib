#include "mk_lang_assert.h"
#include "mk_lang_attribute.h"
#include "mk_lang_bool.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_llong.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint_strict.h"


#define mk_lib_crypto_alg_serpent_inl_t_name         mk_lib_crypto_alg_serpent_64
#define mk_lib_crypto_alg_serpent_inl_t_type         mk_sl_cui_uint64_t
#define mk_lib_crypto_alg_serpent_inl_t_bits         64
#define mk_lib_crypto_alg_serpent_inl_t_constexpr    1
#define mk_lib_crypto_alg_serpent_inl_t_uints_t      mk_lib_crypto_alg_serpent_64_uints_t
#define mk_lib_crypto_alg_serpent_inl_t_ui_assign    mk_lib_crypto_alg_serpent_64_ui_assign
#define mk_lib_crypto_alg_serpent_inl_t_ui_and2      mk_lib_crypto_alg_serpent_64_ui_and2
#define mk_lib_crypto_alg_serpent_inl_t_ui_not1      mk_lib_crypto_alg_serpent_64_ui_not1
#define mk_lib_crypto_alg_serpent_inl_t_ui_or2       mk_lib_crypto_alg_serpent_64_ui_or2
#define mk_lib_crypto_alg_serpent_inl_t_ui_rotl2     mk_lib_crypto_alg_serpent_64_ui_rotl2
#define mk_lib_crypto_alg_serpent_inl_t_ui_rotr2     mk_lib_crypto_alg_serpent_64_ui_rotr2
#define mk_lib_crypto_alg_serpent_inl_t_ui_shl3      mk_lib_crypto_alg_serpent_64_ui_shl3
#define mk_lib_crypto_alg_serpent_inl_t_ui_xor2      mk_lib_crypto_alg_serpent_64_ui_xor2
#define mk_lib_crypto_alg_serpent_inl_t_ui_xor3      mk_lib_crypto_alg_serpent_64_ui_xor3
#define mk_lib_crypto_alg_serpent_inl_t_ui_broadcast mk_lib_crypto_alg_serpent_64_ui_broadcast
#define mk_lib_crypto_alg_serpent_inl_t_load         mk_lib_crypto_alg_serpent_64_load
#define mk_lib_crypto_alg_serpent_inl_t_store        mk_lib_crypto_alg_serpent_64_store
#define mk_lib_crypto_alg_serpent_inl_t_target


union mk_lib_crypto_alg_serpent_64_uints_data_u
{
	mk_sl_cui_uint32_t m_uint32s[mk_lib_crypto_alg_serpent_inl_t_bits / 32];
	mk_sl_cui_uint64_t m_alignment;
};
typedef union mk_lib_crypto_alg_serpent_64_uints_data_u mk_lib_crypto_alg_serpent_64_uints_data_t;

struct mk_lib_crypto_alg_serpent_64_uints_s
{
	mk_lib_crypto_alg_serpent_64_uints_data_t m_data;
};
typedef struct mk_lib_crypto_alg_serpent_64_uints_s mk_lib_crypto_alg_serpent_64_uints_t;
typedef mk_lib_crypto_alg_serpent_64_uints_t const mk_lib_crypto_alg_serpent_64_uints_ct;
typedef mk_lib_crypto_alg_serpent_64_uints_t* mk_lib_crypto_alg_serpent_64_uints_pt;
typedef mk_lib_crypto_alg_serpent_64_uints_t const* mk_lib_crypto_alg_serpent_64_uints_pct;


mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_ui_assign(mk_sl_cui_uint64_prt const a, mk_sl_cui_uint64_prct const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_sl_cui_uint64_assign(a, b);
}}

mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_ui_and2(mk_sl_cui_uint64_prt const a, mk_sl_cui_uint64_prct const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_sl_cui_uint64_and2(a, b);
}}

mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_ui_not1(mk_sl_cui_uint64_pt const a) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);

	mk_sl_cui_uint64_not1(a);
}}

mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_ui_or2(mk_sl_cui_uint64_prt const a, mk_sl_cui_uint64_prct const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_sl_cui_uint64_or2(a, b);
}}

mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_ui_rotl2(mk_sl_cui_uint64_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lib_crypto_alg_serpent_64_uints_t uints mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);

	mk_sl_uint_strict_64_to_32_le(a, &uints.m_data.m_uint32s[0]);
	mk_sl_cui_uint32_rotl2(&uints.m_data.m_uint32s[0], b);
	mk_sl_cui_uint32_rotl2(&uints.m_data.m_uint32s[1], b);
	mk_sl_uint_strict_64_from_32_le(a, &uints.m_data.m_uint32s[0]);
}}

mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_ui_rotr2(mk_sl_cui_uint64_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lib_crypto_alg_serpent_64_uints_t uints mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);

	mk_sl_uint_strict_64_to_32_le(a, &uints.m_data.m_uint32s[0]);
	mk_sl_cui_uint32_rotr2(&uints.m_data.m_uint32s[0], b);
	mk_sl_cui_uint32_rotr2(&uints.m_data.m_uint32s[1], b);
	mk_sl_uint_strict_64_from_32_le(a, &uints.m_data.m_uint32s[0]);
}}

mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_ui_shl3(mk_sl_cui_uint64_prct const a, mk_lang_types_sint_t const b, mk_sl_cui_uint64_prt const c) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lib_crypto_alg_serpent_64_uints_t uints mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(c);
	mk_lang_assert(a != c);

	mk_sl_uint_strict_64_to_32_le(a, &uints.m_data.m_uint32s[0]);
	mk_sl_cui_uint32_shl2(&uints.m_data.m_uint32s[0], b);
	mk_sl_cui_uint32_shl2(&uints.m_data.m_uint32s[1], b);
	mk_sl_uint_strict_64_from_32_le(c, &uints.m_data.m_uint32s[0]);
}}

mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_ui_xor2(mk_sl_cui_uint64_prt const a, mk_sl_cui_uint64_prct const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_sl_cui_uint64_xor2(a, b);
}}

mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_ui_xor3(mk_sl_cui_uint64_prct const a, mk_sl_cui_uint64_prct const b, mk_sl_cui_uint64_prt const c) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);

	mk_sl_cui_uint64_xor3(a, b, c);
}}

mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_ui_broadcast(mk_sl_cui_uint64_pt const a, mk_lib_crypto_alg_serpent_64_uints_pt const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b);

	b->m_data.m_uint32s[1] = b->m_data.m_uint32s[0];
	mk_sl_uint_strict_64_from_32_le(a, &b->m_data.m_uint32s[0]);
}}

#define mk_lib_crypto_alg_serpent_64_transpose_load(ta, tb, tc, td) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_sl_cui_uint64_t a mk_lang_constexpr_init;   \
	mk_sl_cui_uint64_t b mk_lang_constexpr_init;   \
	mk_sl_cui_uint64_t tta mk_lang_constexpr_init; \
	mk_sl_cui_uint64_t ttb mk_lang_constexpr_init; \
	mk_sl_cui_uint64_t ttc mk_lang_constexpr_init; \
	mk_sl_cui_uint64_t ttd mk_lang_constexpr_init; \
	mk_lang_static_assert(mk_lang_llong_has);      \
	mk_lang_assert(ta);                            \
	mk_lang_assert(tb);                            \
	mk_lang_assert(tc);                            \
	mk_lang_assert(td);                            \
	mk_lang_assert(ta != tb);                      \
	mk_lang_assert(ta != tc);                      \
	mk_lang_assert(ta != td);                      \
	mk_lang_assert(tb != tc);                      \
	mk_lang_assert(tb != td);                      \
	mk_lang_assert(tc != td);                      \
	mk_sl_cui_uint64_shl3(ta, 32, &a);             \
	mk_sl_cui_uint64_shr2(&a, 32);                 \
	mk_sl_cui_uint64_shl3(tc, 32, &b);             \
	mk_sl_cui_uint64_or3(&a, &b, &tta);            \
	mk_sl_cui_uint64_shr3(ta, 32, &a);             \
	mk_sl_cui_uint64_shr3(tc, 32, &b);             \
	mk_sl_cui_uint64_shl2(&b, 32);                 \
	mk_sl_cui_uint64_or3(&a, &b, &ttb);            \
	mk_sl_cui_uint64_shl3(tb, 32, &a);             \
	mk_sl_cui_uint64_shr2(&a, 32);                 \
	mk_sl_cui_uint64_shl3(td, 32, &b);             \
	mk_sl_cui_uint64_or3(&a, &b, &ttc);            \
	mk_sl_cui_uint64_shr3(tb, 32, &a);             \
	mk_sl_cui_uint64_shr3(td, 32, &b);             \
	mk_sl_cui_uint64_shl2(&b, 32);                 \
	mk_sl_cui_uint64_or3(&a, &b, &ttd);            \
	*ta = tta;                                     \
	*tb = ttb;                                     \
	*tc = ttc;                                     \
	*td = ttd;                                     \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_64_load(msgs, ta, tb, tc, td) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_static_assert(mk_lang_llong_has);                            \
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
	mk_sl_uint_strict_64_from_8_le(ta, &msgs[0].m_data.m_uint8s[0 * 8]); \
	mk_sl_uint_strict_64_from_8_le(tb, &msgs[0].m_data.m_uint8s[1 * 8]); \
	mk_sl_uint_strict_64_from_8_le(tc, &msgs[1].m_data.m_uint8s[0 * 8]); \
	mk_sl_uint_strict_64_from_8_le(td, &msgs[1].m_data.m_uint8s[1 * 8]); \
	mk_lib_crypto_alg_serpent_64_transpose_load(ta, tb, tc, td);         \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_64_transpose_store(ta, tb, tc, td) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_sl_cui_uint64_t a mk_lang_constexpr_init;   \
	mk_sl_cui_uint64_t b mk_lang_constexpr_init;   \
	mk_sl_cui_uint64_t tta mk_lang_constexpr_init; \
	mk_sl_cui_uint64_t ttb mk_lang_constexpr_init; \
	mk_sl_cui_uint64_t ttc mk_lang_constexpr_init; \
	mk_sl_cui_uint64_t ttd mk_lang_constexpr_init; \
	mk_lang_static_assert(mk_lang_llong_has);      \
	mk_lang_assert(ta);                            \
	mk_lang_assert(tb);                            \
	mk_lang_assert(tc);                            \
	mk_lang_assert(td);                            \
	mk_lang_assert(ta != tb);                      \
	mk_lang_assert(ta != tc);                      \
	mk_lang_assert(ta != td);                      \
	mk_lang_assert(tb != tc);                      \
	mk_lang_assert(tb != td);                      \
	mk_lang_assert(tc != td);                      \
	mk_sl_cui_uint64_shl3(ta, 32, &a);             \
	mk_sl_cui_uint64_shr2(&a, 32);                 \
	mk_sl_cui_uint64_shl3(tb, 32, &b);             \
	mk_sl_cui_uint64_or3(&a, &b, &tta);            \
	mk_sl_cui_uint64_shl3(tc, 32, &a);             \
	mk_sl_cui_uint64_shr2(&a, 32);                 \
	mk_sl_cui_uint64_shl3(td, 32, &b);             \
	mk_sl_cui_uint64_or3(&a, &b, &ttb);            \
	mk_sl_cui_uint64_shr3(ta, 32, &a);             \
	mk_sl_cui_uint64_shr3(tb, 32, &b);             \
	mk_sl_cui_uint64_shl2(&b, 32);                 \
	mk_sl_cui_uint64_or3(&a, &b, &ttc);            \
	mk_sl_cui_uint64_shr3(tc, 32, &a);             \
	mk_sl_cui_uint64_shr3(td, 32, &b);             \
	mk_sl_cui_uint64_shl2(&b, 32);                 \
	mk_sl_cui_uint64_or3(&a, &b, &ttd);            \
	*ta = tta;                                     \
	*tb = ttb;                                     \
	*tc = ttc;                                     \
	*td = ttd;                                     \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_64_store(msgs, ta, tb, tc, td) \
do mk_lang_attribute_msvc_flatten \
{ \
	mk_lang_static_assert(mk_lang_llong_has);                          \
	mk_lang_assert(msgs);                                              \
	mk_lang_assert(ta);                                                \
	mk_lang_assert(tb);                                                \
	mk_lang_assert(tc);                                                \
	mk_lang_assert(td);                                                \
	mk_lang_assert(ta != tb);                                          \
	mk_lang_assert(ta != tc);                                          \
	mk_lang_assert(ta != td);                                          \
	mk_lang_assert(tb != tc);                                          \
	mk_lang_assert(tb != td);                                          \
	mk_lang_assert(tc != td);                                          \
	mk_lib_crypto_alg_serpent_64_transpose_store(ta, tb, tc, td);      \
	mk_sl_uint_strict_64_to_8_le(ta, &msgs[0].m_data.m_uint8s[0 * 8]); \
	mk_sl_uint_strict_64_to_8_le(tb, &msgs[0].m_data.m_uint8s[1 * 8]); \
	mk_sl_uint_strict_64_to_8_le(tc, &msgs[1].m_data.m_uint8s[0 * 8]); \
	mk_sl_uint_strict_64_to_8_le(td, &msgs[1].m_data.m_uint8s[1 * 8]); \
}while(mk_lang_false)


#include "mk_lib_crypto_alg_serpent_inl.h"
