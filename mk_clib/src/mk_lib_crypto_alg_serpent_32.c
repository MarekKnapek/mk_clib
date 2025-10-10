#ifndef mk_include_guard_mk_lib_crypto_alg_serpent_32_c
#define mk_include_guard_mk_lib_crypto_alg_serpent_32_c
#include "mk_lib_crypto_alg_serpent_32.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_flatten.h"
#include "mk_lang_forceinline.h"
#include "mk_lang_inline.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_serpent_base.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_uint_convert.h"


mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_hlp_ui_assign(mk_sl_cui_uint32_prt const a, mk_sl_cui_uint32_prct const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_sl_cui_uint32_assign(a, b);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_hlp_ui_and2(mk_sl_cui_uint32_prt const a, mk_sl_cui_uint32_prct const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_sl_cui_uint32_and2(a, b);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_hlp_ui_not1(mk_sl_cui_uint32_pt const a) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);

	mk_sl_cui_uint32_not1(a);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_hlp_ui_or2(mk_sl_cui_uint32_prt const a, mk_sl_cui_uint32_prct const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_sl_cui_uint32_or2(a, b);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_hlp_ui_rotl2(mk_sl_cui_uint32_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);

	mk_sl_cui_uint32_rotl2(a, b);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_hlp_ui_rotr2(mk_sl_cui_uint32_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);

	mk_sl_cui_uint32_rotr2(a, b);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_hlp_ui_shl3(mk_sl_cui_uint32_prct const a, mk_lang_types_sint_t const b, mk_sl_cui_uint32_prt const c) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(c);
	mk_lang_assert(a != c);

	mk_sl_cui_uint32_shl3(a, b, c);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_hlp_ui_xor2(mk_sl_cui_uint32_prt const a, mk_sl_cui_uint32_prct const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_sl_cui_uint32_xor2(a, b);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_hlp_ui_xor3(mk_sl_cui_uint32_prct const a, mk_sl_cui_uint32_prct const b, mk_sl_cui_uint32_prt const c) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);

	mk_sl_cui_uint32_xor3(a, b, c);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_hlp_ui_broadcast(mk_sl_cui_uint32_pt const a, mk_lib_crypto_alg_serpent_32_uints_pct const b) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*a = b->m_data.m_uint32s[0];
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_hlp_load(mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_ct, msgs, mk_lib_crypto_alg_serpent_32_blocks), mk_sl_cui_uint32_prt const a, mk_sl_cui_uint32_prt const b, mk_sl_cui_uint32_prt const c, mk_sl_cui_uint32_prt const d) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(msgs);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(a != d);
	mk_lang_assert(b != c);
	mk_lang_assert(b != d);
	mk_lang_assert(c != d);

	mk_sl_uint_convert_32_8_le_to_big(a, &msgs[0].m_data.m_uint8s[0 * mk_sl_cui_uint32_size_bytes_v]);
	mk_sl_uint_convert_32_8_le_to_big(b, &msgs[0].m_data.m_uint8s[1 * mk_sl_cui_uint32_size_bytes_v]);
	mk_sl_uint_convert_32_8_le_to_big(c, &msgs[0].m_data.m_uint8s[2 * mk_sl_cui_uint32_size_bytes_v]);
	mk_sl_uint_convert_32_8_le_to_big(d, &msgs[0].m_data.m_uint8s[3 * mk_sl_cui_uint32_size_bytes_v]);
}}

mk_lang_forceinline mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_32_hlp_store(mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_t, msgs, mk_lib_crypto_alg_serpent_32_blocks), mk_sl_cui_uint32_prct const a, mk_sl_cui_uint32_prct const b, mk_sl_cui_uint32_prct const c, mk_sl_cui_uint32_prct const d) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(msgs);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(a != d);
	mk_lang_assert(b != c);
	mk_lang_assert(b != d);
	mk_lang_assert(c != d);

	mk_sl_uint_convert_32_8_le_to_sml(a, &msgs[0].m_data.m_uint8s[0 * mk_sl_cui_uint32_size_bytes_v]);
	mk_sl_uint_convert_32_8_le_to_sml(b, &msgs[0].m_data.m_uint8s[1 * mk_sl_cui_uint32_size_bytes_v]);
	mk_sl_uint_convert_32_8_le_to_sml(c, &msgs[0].m_data.m_uint8s[2 * mk_sl_cui_uint32_size_bytes_v]);
	mk_sl_uint_convert_32_8_le_to_sml(d, &msgs[0].m_data.m_uint8s[3 * mk_sl_cui_uint32_size_bytes_v]);
}}


#define mk_lib_crypto_alg_serpent_t_name         mk_lib_crypto_alg_serpent_32
#define mk_lib_crypto_alg_serpent_t_type         mk_sl_cui_uint32_t
#define mk_lib_crypto_alg_serpent_t_bits         mk_lib_crypto_alg_serpent_32_bits
#define mk_lib_crypto_alg_serpent_t_constexpr    1
#define mk_lib_crypto_alg_serpent_t_uints_t      mk_lib_crypto_alg_serpent_32_uints_t
#define mk_lib_crypto_alg_serpent_t_ui_assign    mk_lib_crypto_alg_serpent_32_hlp_ui_assign
#define mk_lib_crypto_alg_serpent_t_ui_and2      mk_lib_crypto_alg_serpent_32_hlp_ui_and2
#define mk_lib_crypto_alg_serpent_t_ui_not1      mk_lib_crypto_alg_serpent_32_hlp_ui_not1
#define mk_lib_crypto_alg_serpent_t_ui_or2       mk_lib_crypto_alg_serpent_32_hlp_ui_or2
#define mk_lib_crypto_alg_serpent_t_ui_rotl2     mk_lib_crypto_alg_serpent_32_hlp_ui_rotl2
#define mk_lib_crypto_alg_serpent_t_ui_rotr2     mk_lib_crypto_alg_serpent_32_hlp_ui_rotr2
#define mk_lib_crypto_alg_serpent_t_ui_shl3      mk_lib_crypto_alg_serpent_32_hlp_ui_shl3
#define mk_lib_crypto_alg_serpent_t_ui_xor2      mk_lib_crypto_alg_serpent_32_hlp_ui_xor2
#define mk_lib_crypto_alg_serpent_t_ui_xor3      mk_lib_crypto_alg_serpent_32_hlp_ui_xor3
#define mk_lib_crypto_alg_serpent_t_ui_broadcast mk_lib_crypto_alg_serpent_32_hlp_ui_broadcast
#define mk_lib_crypto_alg_serpent_t_load         mk_lib_crypto_alg_serpent_32_hlp_load
#define mk_lib_crypto_alg_serpent_t_store        mk_lib_crypto_alg_serpent_32_hlp_store
#define mk_lib_crypto_alg_serpent_t_target
#include "mk_lib_crypto_alg_serpent_inl_filec.h"
#include "mk_lib_crypto_alg_serpent_inl_fileu.h"


#endif
