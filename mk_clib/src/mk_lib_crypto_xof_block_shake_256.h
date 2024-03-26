#ifndef mk_include_guard_mk_lib_crypto_xof_block_shake_256
#define mk_include_guard_mk_lib_crypto_xof_block_shake_256


/* nist fips pub 202 */


#include "mk_lang_alignas.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_sha3_base.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_xof_block_shake_256_block_len 136
#define mk_lib_crypto_xof_block_shake_256_name_def SHAKE256
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_crypto_xof_block_shake_256_name_str[] = mk_lang_stringify(mk_lib_crypto_xof_block_shake_256_name_def);
mk_lang_constexpr_static_inline mk_lang_types_sint_t const mk_lib_crypto_xof_block_shake_256_name_str_len = mk_lang_countstr(mk_lib_crypto_xof_block_shake_256_name_str);


union mk_lib_crypto_xof_block_shake_256_aligned136_u
{
	mk_lang_alignas(mk_sl_cui_uint64_t) mk_sl_cui_uint8_t m_uint8s[136];
	mk_sl_cui_uint64_t m_align;
};
typedef union mk_lib_crypto_xof_block_shake_256_aligned136_u mk_lib_crypto_xof_block_shake_256_aligned136_t;


struct mk_lib_crypto_xof_block_shake_256_s
{
	mk_lib_crypto_hash_block_sha3_base_state_t m_sha3;
	mk_lang_types_sint_t m_idx;
};
typedef struct mk_lib_crypto_xof_block_shake_256_s mk_lib_crypto_xof_block_shake_256_t;
typedef mk_lib_crypto_xof_block_shake_256_t const mk_lib_crypto_xof_block_shake_256_ct;
typedef mk_lib_crypto_xof_block_shake_256_t* mk_lib_crypto_xof_block_shake_256_pt;
typedef mk_lib_crypto_xof_block_shake_256_t const* mk_lib_crypto_xof_block_shake_256_pct;

typedef mk_lib_crypto_xof_block_shake_256_aligned136_t mk_lib_crypto_xof_block_shake_256_block_t;
typedef mk_lib_crypto_xof_block_shake_256_block_t const mk_lib_crypto_xof_block_shake_256_block_ct;
typedef mk_lib_crypto_xof_block_shake_256_block_t* mk_lib_crypto_xof_block_shake_256_block_pt;
typedef mk_lib_crypto_xof_block_shake_256_block_t const* mk_lib_crypto_xof_block_shake_256_block_pct;


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_shake_256_init(mk_lib_crypto_xof_block_shake_256_pt const shake_256) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_shake_256_append_blocks(mk_lib_crypto_xof_block_shake_256_pt const shake_256, mk_lib_crypto_xof_block_shake_256_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_shake_256_finish(mk_lib_crypto_xof_block_shake_256_pt const shake_256, mk_lib_crypto_xof_block_shake_256_block_pt const block, mk_lang_types_sint_t const idx) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_shake_256_squeeze(mk_lib_crypto_xof_block_shake_256_pt const shake_256, mk_lang_types_usize_t const len, mk_sl_cui_uint8_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_xof_block_shake_256.c"
#endif
#endif
