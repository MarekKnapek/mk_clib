#ifndef mk_include_guard_mk_lib_crypto_alg_serpent_64_c
#define mk_include_guard_mk_lib_crypto_alg_serpent_64_c
#include "mk_lib_crypto_alg_serpent_64.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_flatten.h"
#include "mk_lang_forceinline.h"
#include "mk_lang_inline.h"
#include "mk_lang_llong.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_serpent_base.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_uint_convert.h"


mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_hlp_ui_assign(mk_sl_cui_uint64_prt const a, mk_sl_cui_uint64_prct const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_sl_cui_uint64_assign(a, b);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_hlp_ui_and2(mk_sl_cui_uint64_prt const a, mk_sl_cui_uint64_prct const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_sl_cui_uint64_and2(a, b);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_hlp_ui_not1(mk_sl_cui_uint64_pt const a) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);

	mk_sl_cui_uint64_not1(a);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_hlp_ui_or2(mk_sl_cui_uint64_prt const a, mk_sl_cui_uint64_prct const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_sl_cui_uint64_or2(a, b);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_hlp_ui_rotl2(mk_sl_cui_uint64_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lib_crypto_alg_serpent_64_uints_t uints mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);

	mk_sl_uint_convert_64_32_le_to_sml(a, &uints.m_data.m_uint32s[0]);
	mk_sl_cui_uint32_rotl2(&uints.m_data.m_uint32s[0], b);
	mk_sl_cui_uint32_rotl2(&uints.m_data.m_uint32s[1], b);
	mk_sl_uint_convert_64_32_le_to_big(a, &uints.m_data.m_uint32s[0]);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_hlp_ui_rotr2(mk_sl_cui_uint64_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lib_crypto_alg_serpent_64_uints_t uints mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);

	mk_sl_uint_convert_64_32_le_to_sml(a, &uints.m_data.m_uint32s[0]);
	mk_sl_cui_uint32_rotr2(&uints.m_data.m_uint32s[0], b);
	mk_sl_cui_uint32_rotr2(&uints.m_data.m_uint32s[1], b);
	mk_sl_uint_convert_64_32_le_to_big(a, &uints.m_data.m_uint32s[0]);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_hlp_ui_shl3(mk_sl_cui_uint64_prct const a, mk_lang_types_sint_t const b, mk_sl_cui_uint64_prt const c) mk_lang_noexcept { mk_lang_flatten
{
	mk_lib_crypto_alg_serpent_64_uints_t uints mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(c);
	mk_lang_assert(a != c);

	mk_sl_uint_convert_64_32_le_to_sml(a, &uints.m_data.m_uint32s[0]);
	mk_sl_cui_uint32_shl2(&uints.m_data.m_uint32s[0], b);
	mk_sl_cui_uint32_shl2(&uints.m_data.m_uint32s[1], b);
	mk_sl_uint_convert_64_32_le_to_big(c, &uints.m_data.m_uint32s[0]);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_hlp_ui_xor2(mk_sl_cui_uint64_prt const a, mk_sl_cui_uint64_prct const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_sl_cui_uint64_xor2(a, b);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_hlp_ui_xor3(mk_sl_cui_uint64_prct const a, mk_sl_cui_uint64_prct const b, mk_sl_cui_uint64_prt const c) mk_lang_noexcept { mk_lang_flatten
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

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_hlp_ui_broadcast(mk_sl_cui_uint64_pt const a, mk_lib_crypto_alg_serpent_64_uints_pt const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b);

	b->m_data.m_uint32s[1] = b->m_data.m_uint32s[0];
	mk_sl_uint_convert_64_32_le_to_big(a, &b->m_data.m_uint32s[0]);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_hlp_transpose_load(mk_sl_cui_uint64_prt const ta, mk_sl_cui_uint64_prt const tb, mk_sl_cui_uint64_prt const tc, mk_sl_cui_uint64_prt const td) mk_lang_noexcept { mk_lang_flatten
{
	mk_sl_cui_uint64_t a mk_lang_constexpr_init;
	mk_sl_cui_uint64_t b mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ttb mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ttc mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ttd mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_llong_has);

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

	mk_sl_cui_uint64_shl3(ta, 32, &a);
	mk_sl_cui_uint64_shr2(&a, 32);
	mk_sl_cui_uint64_shl3(tc, 32, &b);
	mk_sl_cui_uint64_or3(&a, &b, &tta);
	mk_sl_cui_uint64_shr3(ta, 32, &a);
	mk_sl_cui_uint64_shr3(tc, 32, &b);
	mk_sl_cui_uint64_shl2(&b, 32);
	mk_sl_cui_uint64_or3(&a, &b, &ttb);
	mk_sl_cui_uint64_shl3(tb, 32, &a);
	mk_sl_cui_uint64_shr2(&a, 32);
	mk_sl_cui_uint64_shl3(td, 32, &b);
	mk_sl_cui_uint64_or3(&a, &b, &ttc);
	mk_sl_cui_uint64_shr3(tb, 32, &a);
	mk_sl_cui_uint64_shr3(td, 32, &b);
	mk_sl_cui_uint64_shl2(&b, 32);
	mk_sl_cui_uint64_or3(&a, &b, &ttd);
	*ta = tta;
	*tb = ttb;
	*tc = ttc;
	*td = ttd;
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_hlp_transpose_store(mk_sl_cui_uint64_prt const ta, mk_sl_cui_uint64_prt const tb, mk_sl_cui_uint64_prt const tc, mk_sl_cui_uint64_prt const td) mk_lang_noexcept { mk_lang_flatten
{
	mk_sl_cui_uint64_t a mk_lang_constexpr_init;
	mk_sl_cui_uint64_t b mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ttb mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ttc mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ttd mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_llong_has);

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

	mk_sl_cui_uint64_shl3(ta, 32, &a);
	mk_sl_cui_uint64_shr2(&a, 32);
	mk_sl_cui_uint64_shl3(tb, 32, &b);
	mk_sl_cui_uint64_or3(&a, &b, &tta);
	mk_sl_cui_uint64_shl3(tc, 32, &a);
	mk_sl_cui_uint64_shr2(&a, 32);
	mk_sl_cui_uint64_shl3(td, 32, &b);
	mk_sl_cui_uint64_or3(&a, &b, &ttb);
	mk_sl_cui_uint64_shr3(ta, 32, &a);
	mk_sl_cui_uint64_shr3(tb, 32, &b);
	mk_sl_cui_uint64_shl2(&b, 32);
	mk_sl_cui_uint64_or3(&a, &b, &ttc);
	mk_sl_cui_uint64_shr3(tc, 32, &a);
	mk_sl_cui_uint64_shr3(td, 32, &b);
	mk_sl_cui_uint64_shl2(&b, 32);
	mk_sl_cui_uint64_or3(&a, &b, &ttd);
	*ta = tta;
	*tb = ttb;
	*tc = ttc;
	*td = ttd;
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_hlp_load(mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_ct, msgs, mk_lib_crypto_alg_serpent_64_blocks), mk_sl_cui_uint64_prt const ta, mk_sl_cui_uint64_prt const tb, mk_sl_cui_uint64_prt const tc, mk_sl_cui_uint64_prt const td) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_static_assert(mk_lang_llong_has);

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

	mk_sl_uint_convert_64_8_le_to_big(ta, &msgs[0].m_data.m_uint8s[0 * mk_sl_cui_uint64_size_bytes_v]);
	mk_sl_uint_convert_64_8_le_to_big(tb, &msgs[0].m_data.m_uint8s[1 * mk_sl_cui_uint64_size_bytes_v]);
	mk_sl_uint_convert_64_8_le_to_big(tc, &msgs[1].m_data.m_uint8s[0 * mk_sl_cui_uint64_size_bytes_v]);
	mk_sl_uint_convert_64_8_le_to_big(td, &msgs[1].m_data.m_uint8s[1 * mk_sl_cui_uint64_size_bytes_v]);
	mk_lib_crypto_alg_serpent_64_hlp_transpose_load(ta, tb, tc, td);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_64_hlp_store(mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_t, msgs, mk_lib_crypto_alg_serpent_64_blocks), mk_sl_cui_uint64_prt const ta, mk_sl_cui_uint64_prt const tb, mk_sl_cui_uint64_prt const tc, mk_sl_cui_uint64_prt const td) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_static_assert(mk_lang_llong_has);

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

	mk_lib_crypto_alg_serpent_64_hlp_transpose_store(ta, tb, tc, td);
	mk_sl_uint_convert_64_8_le_to_sml(ta, &msgs[0].m_data.m_uint8s[0 * mk_sl_cui_uint64_size_bytes_v]);
	mk_sl_uint_convert_64_8_le_to_sml(tb, &msgs[0].m_data.m_uint8s[1 * mk_sl_cui_uint64_size_bytes_v]);
	mk_sl_uint_convert_64_8_le_to_sml(tc, &msgs[1].m_data.m_uint8s[0 * mk_sl_cui_uint64_size_bytes_v]);
	mk_sl_uint_convert_64_8_le_to_sml(td, &msgs[1].m_data.m_uint8s[1 * mk_sl_cui_uint64_size_bytes_v]);
}}


#define mk_lib_crypto_alg_serpent_t_name         mk_lib_crypto_alg_serpent_64
#define mk_lib_crypto_alg_serpent_t_type         mk_sl_cui_uint64_t
#define mk_lib_crypto_alg_serpent_t_bits         mk_lib_crypto_alg_serpent_64_bits
#define mk_lib_crypto_alg_serpent_t_constexpr    1
#define mk_lib_crypto_alg_serpent_t_uints_t      mk_lib_crypto_alg_serpent_64_uints_t
#define mk_lib_crypto_alg_serpent_t_ui_assign    mk_lib_crypto_alg_serpent_64_hlp_ui_assign
#define mk_lib_crypto_alg_serpent_t_ui_and2      mk_lib_crypto_alg_serpent_64_hlp_ui_and2
#define mk_lib_crypto_alg_serpent_t_ui_not1      mk_lib_crypto_alg_serpent_64_hlp_ui_not1
#define mk_lib_crypto_alg_serpent_t_ui_or2       mk_lib_crypto_alg_serpent_64_hlp_ui_or2
#define mk_lib_crypto_alg_serpent_t_ui_rotl2     mk_lib_crypto_alg_serpent_64_hlp_ui_rotl2
#define mk_lib_crypto_alg_serpent_t_ui_rotr2     mk_lib_crypto_alg_serpent_64_hlp_ui_rotr2
#define mk_lib_crypto_alg_serpent_t_ui_shl3      mk_lib_crypto_alg_serpent_64_hlp_ui_shl3
#define mk_lib_crypto_alg_serpent_t_ui_xor2      mk_lib_crypto_alg_serpent_64_hlp_ui_xor2
#define mk_lib_crypto_alg_serpent_t_ui_xor3      mk_lib_crypto_alg_serpent_64_hlp_ui_xor3
#define mk_lib_crypto_alg_serpent_t_ui_broadcast mk_lib_crypto_alg_serpent_64_hlp_ui_broadcast
#define mk_lib_crypto_alg_serpent_t_load         mk_lib_crypto_alg_serpent_64_hlp_load
#define mk_lib_crypto_alg_serpent_t_store        mk_lib_crypto_alg_serpent_64_hlp_store
#define mk_lib_crypto_alg_serpent_t_target
#include "mk_lib_crypto_alg_serpent_inl_filec.h"
#include "mk_lib_crypto_alg_serpent_inl_fileu.h"


#endif
