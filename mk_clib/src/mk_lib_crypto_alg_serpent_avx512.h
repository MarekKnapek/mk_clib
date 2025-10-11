#ifndef mk_include_guard_mk_lib_crypto_alg_serpent_avx512_h
#define mk_include_guard_mk_lib_crypto_alg_serpent_avx512_h


#include "mk_lang_attribute.h"
#include "mk_lang_forceinline.h"
#include "mk_lang_inline.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_serpent_base.h"
#include "mk_sl_cui_uint32.h"

#include <immintrin.h> /* AVX512 __m512i */


#define mk_lib_crypto_alg_serpent_avx512_bits (512)
#define mk_lib_crypto_alg_serpent_avx512_words ((mk_lib_crypto_alg_serpent_avx512_bits) / 32)
#define mk_lib_crypto_alg_serpent_avx512_blocks ((mk_lib_crypto_alg_serpent_avx512_bits) / 32)


struct mk_lib_crypto_alg_serpent_avx512_uint_s
{
	__m512i m_uint;
};
typedef struct mk_lib_crypto_alg_serpent_avx512_uint_s mk_lib_crypto_alg_serpent_avx512_uint_t;
mk_lang_typedef(mk_lib_crypto_alg_serpent_avx512_uint);

union mk_lib_crypto_alg_serpent_avx512_uints_data_u
{
	mk_sl_cui_uint32_t m_uint32s[mk_lib_crypto_alg_serpent_avx512_words];
	mk_lib_crypto_alg_serpent_avx512_uint_t m_alignment;
};
typedef union mk_lib_crypto_alg_serpent_avx512_uints_data_u mk_lib_crypto_alg_serpent_avx512_uints_data_t;
struct mk_lib_crypto_alg_serpent_avx512_uints_s
{
	mk_lib_crypto_alg_serpent_avx512_uints_data_t m_data;
};
typedef struct mk_lib_crypto_alg_serpent_avx512_uints_s mk_lib_crypto_alg_serpent_avx512_uints_t;
mk_lang_typedef(mk_lib_crypto_alg_serpent_avx512_uints);


mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_assign(mk_lib_crypto_alg_serpent_avx512_uint_prt const a, mk_lib_crypto_alg_serpent_avx512_uint_prct const b) mk_lang_noexcept;
mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_and2(mk_lib_crypto_alg_serpent_avx512_uint_prt const a, mk_lib_crypto_alg_serpent_avx512_uint_prct const b) mk_lang_noexcept;
mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_not1(mk_lib_crypto_alg_serpent_avx512_uint_pt const a) mk_lang_noexcept;
mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_or2(mk_lib_crypto_alg_serpent_avx512_uint_prt const a, mk_lib_crypto_alg_serpent_avx512_uint_prct const b) mk_lang_noexcept;
mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_rotl2(mk_lib_crypto_alg_serpent_avx512_uint_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept;
mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_rotr2(mk_lib_crypto_alg_serpent_avx512_uint_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept;
mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_shl3(mk_lib_crypto_alg_serpent_avx512_uint_prct const a, mk_lang_types_sint_t const b, mk_lib_crypto_alg_serpent_avx512_uint_prt const c) mk_lang_noexcept;
mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_xor2(mk_lib_crypto_alg_serpent_avx512_uint_prt const a, mk_lib_crypto_alg_serpent_avx512_uint_prct const b) mk_lang_noexcept;
mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_xor3(mk_lib_crypto_alg_serpent_avx512_uint_prct const a, mk_lib_crypto_alg_serpent_avx512_uint_prct const b, mk_lib_crypto_alg_serpent_avx512_uint_prt const c) mk_lang_noexcept;
mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_ui_broadcast(mk_lib_crypto_alg_serpent_avx512_uint_pt const a, mk_lib_crypto_alg_serpent_avx512_uints_pt const b) mk_lang_noexcept;
mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_transpose_load(mk_lib_crypto_alg_serpent_avx512_uint_prt const ta, mk_lib_crypto_alg_serpent_avx512_uint_prt const tb, mk_lib_crypto_alg_serpent_avx512_uint_prt const tc, mk_lib_crypto_alg_serpent_avx512_uint_prt const td) mk_lang_noexcept;
mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_transpose_store(mk_lib_crypto_alg_serpent_avx512_uint_prt const ta, mk_lib_crypto_alg_serpent_avx512_uint_prt const tb, mk_lib_crypto_alg_serpent_avx512_uint_prt const tc, mk_lib_crypto_alg_serpent_avx512_uint_prt const td) mk_lang_noexcept;
mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_load(mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_ct, msgs, mk_lib_crypto_alg_serpent_avx512_blocks), mk_lib_crypto_alg_serpent_avx512_uint_prt const ta, mk_lib_crypto_alg_serpent_avx512_uint_prt const tb, mk_lib_crypto_alg_serpent_avx512_uint_prt const tc, mk_lib_crypto_alg_serpent_avx512_uint_prt const td) mk_lang_noexcept;
mk_lang_forceinline static mk_lang_inline mk_lang_types_void_t mk_lang_attribute_target("avx512f") mk_lib_crypto_alg_serpent_avx512_hlp_store(mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_t, msgs, mk_lib_crypto_alg_serpent_avx512_blocks), mk_lib_crypto_alg_serpent_avx512_uint_prt const ta, mk_lib_crypto_alg_serpent_avx512_uint_prt const tb, mk_lib_crypto_alg_serpent_avx512_uint_prt const tc, mk_lib_crypto_alg_serpent_avx512_uint_prt const td) mk_lang_noexcept;


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
#include "mk_lib_crypto_alg_serpent_inl_fileh.h"
#include "mk_lib_crypto_alg_serpent_inl_fileu.h"


#if mk_lang_jumbo_have
#include "mk_lib_crypto_alg_serpent_avx512.c"
#endif
#endif
