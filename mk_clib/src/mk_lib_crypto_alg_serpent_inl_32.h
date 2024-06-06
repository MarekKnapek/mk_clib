#include "mk_lang_assert.h"
#include "mk_lang_attribute.h"
#include "mk_lang_bool.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint32.h"


#define mk_lib_crypto_alg_serpent_inl_t_name         mk_lib_crypto_alg_serpent_32
#define mk_lib_crypto_alg_serpent_inl_t_type         mk_sl_cui_uint32_t
#define mk_lib_crypto_alg_serpent_inl_t_bits         32
#define mk_lib_crypto_alg_serpent_inl_t_constexpr    1
#define mk_lib_crypto_alg_serpent_inl_t_uints_t      mk_lib_crypto_alg_serpent_32_uints_t
#define mk_lib_crypto_alg_serpent_inl_t_ui_assign    mk_lib_crypto_alg_serpent_32_ui_assign
#define mk_lib_crypto_alg_serpent_inl_t_ui_and2      mk_lib_crypto_alg_serpent_32_ui_and2
#define mk_lib_crypto_alg_serpent_inl_t_ui_not1      mk_lib_crypto_alg_serpent_32_ui_not1
#define mk_lib_crypto_alg_serpent_inl_t_ui_or2       mk_lib_crypto_alg_serpent_32_ui_or2
#define mk_lib_crypto_alg_serpent_inl_t_ui_rotl2     mk_lib_crypto_alg_serpent_32_ui_rotl2
#define mk_lib_crypto_alg_serpent_inl_t_ui_rotr2     mk_lib_crypto_alg_serpent_32_ui_rotr2
#define mk_lib_crypto_alg_serpent_inl_t_ui_shl3      mk_lib_crypto_alg_serpent_32_ui_shl3
#define mk_lib_crypto_alg_serpent_inl_t_ui_xor2      mk_lib_crypto_alg_serpent_32_ui_xor2
#define mk_lib_crypto_alg_serpent_inl_t_ui_xor3      mk_lib_crypto_alg_serpent_32_ui_xor3
#define mk_lib_crypto_alg_serpent_inl_t_ui_broadcast mk_lib_crypto_alg_serpent_32_ui_broadcast
#define mk_lib_crypto_alg_serpent_inl_t_load         mk_lib_crypto_alg_serpent_32_load
#define mk_lib_crypto_alg_serpent_inl_t_store        mk_lib_crypto_alg_serpent_32_store
#define mk_lib_crypto_alg_serpent_inl_t_target


union mk_lib_crypto_alg_serpent_32_uints_data_u
{
	mk_sl_cui_uint32_t m_uint32s[mk_lib_crypto_alg_serpent_inl_t_bits / 32];
	mk_sl_cui_uint32_t m_alignment;
};
typedef union mk_lib_crypto_alg_serpent_32_uints_data_u mk_lib_crypto_alg_serpent_32_uints_data_t;

struct mk_lib_crypto_alg_serpent_32_uints_s
{
	mk_lib_crypto_alg_serpent_32_uints_data_t m_data;
};
typedef struct mk_lib_crypto_alg_serpent_32_uints_s mk_lib_crypto_alg_serpent_32_uints_t;
typedef mk_lib_crypto_alg_serpent_32_uints_t const mk_lib_crypto_alg_serpent_32_uints_ct;
typedef mk_lib_crypto_alg_serpent_32_uints_t* mk_lib_crypto_alg_serpent_32_uints_pt;
typedef mk_lib_crypto_alg_serpent_32_uints_t const* mk_lib_crypto_alg_serpent_32_uints_pct;


mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_ui_assign(mk_sl_cui_uint32_prt const a, mk_sl_cui_uint32_prct const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_sl_cui_uint32_assign(a, b);
}}

mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_ui_and2(mk_sl_cui_uint32_prt const a, mk_sl_cui_uint32_prct const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_sl_cui_uint32_and2(a, b);
}}

mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_ui_not1(mk_sl_cui_uint32_pt const a) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);

	mk_sl_cui_uint32_not1(a);
}}

mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_ui_or2(mk_sl_cui_uint32_prt const a, mk_sl_cui_uint32_prct const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_sl_cui_uint32_or2(a, b);
}}

mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_ui_rotl2(mk_sl_cui_uint32_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);

	mk_sl_cui_uint32_rotl2(a, b);
}}

mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_ui_rotr2(mk_sl_cui_uint32_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);

	mk_sl_cui_uint32_rotr2(a, b);
}}

mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_ui_shl3(mk_sl_cui_uint32_prct const a, mk_lang_types_sint_t const b, mk_sl_cui_uint32_prt const c) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(c);
	mk_lang_assert(a != c);

	mk_sl_cui_uint32_shl3(a, b, c);
}}

mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_ui_xor2(mk_sl_cui_uint32_prt const a, mk_sl_cui_uint32_prct const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_sl_cui_uint32_xor2(a, b);
}}

mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_ui_xor3(mk_sl_cui_uint32_prct const a, mk_sl_cui_uint32_prct const b, mk_sl_cui_uint32_prt const c) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);

	mk_sl_cui_uint32_xor3(a, b, c);
}}

mk_lang_attribute_msvc_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_ui_broadcast(mk_sl_cui_uint32_pt const a, mk_lib_crypto_alg_serpent_32_uints_pt const b) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*a = b->m_data.m_uint32s[0];
}}

#define mk_lib_crypto_alg_serpent_32_load(msgs, ta, tb, tc, td) \
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
	mk_sl_uint_strict_32_from_8_le(ta, &msgs[0].m_data.m_uint8s[0 * 4]); \
	mk_sl_uint_strict_32_from_8_le(tb, &msgs[0].m_data.m_uint8s[1 * 4]); \
	mk_sl_uint_strict_32_from_8_le(tc, &msgs[0].m_data.m_uint8s[2 * 4]); \
	mk_sl_uint_strict_32_from_8_le(td, &msgs[0].m_data.m_uint8s[3 * 4]); \
}while(mk_lang_false)

#define mk_lib_crypto_alg_serpent_32_store(msgs, ta, tb, tc, td) \
do mk_lang_attribute_msvc_flatten \
{ \
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
	mk_sl_uint_strict_32_to_8_le(ta, &msgs[0].m_data.m_uint8s[0 * 4]); \
	mk_sl_uint_strict_32_to_8_le(tb, &msgs[0].m_data.m_uint8s[1 * 4]); \
	mk_sl_uint_strict_32_to_8_le(tc, &msgs[0].m_data.m_uint8s[2 * 4]); \
	mk_sl_uint_strict_32_to_8_le(td, &msgs[0].m_data.m_uint8s[3 * 4]); \
}while(mk_lang_false)


#include "mk_lib_crypto_alg_serpent_inl.h"
