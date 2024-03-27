#ifndef mk_include_guard_mk_lib_crypto_xof_block_blake3
#define mk_include_guard_mk_lib_crypto_xof_block_blake3


#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_blake3_base.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_xof_block_blake3_block_len 64
#define mk_lib_crypto_xof_block_blake3_name_def BLAKE3XOF
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_crypto_xof_block_blake3_name_str[] = mk_lang_stringify(mk_lib_crypto_xof_block_blake3_name_def);
mk_lang_constexpr_static_inline mk_lang_types_sint_t const mk_lib_crypto_xof_block_blake3_name_str_len = mk_lang_countstr(mk_lib_crypto_xof_block_blake3_name_str);


struct mk_lib_crypto_xof_block_blake3_s
{
	mk_lib_crypto_hash_block_blake3_base_t m_blake3;
	mk_lib_crypto_hash_block_blake3_base_block_t m_block;
	mk_lib_crypto_hash_block_blake3_base_output_block_t m_output_block;
	mk_sl_cui_uint64_t m_seek;
	mk_lang_types_sint_t m_idx;
};
typedef struct mk_lib_crypto_xof_block_blake3_s mk_lib_crypto_xof_block_blake3_t;
typedef mk_lib_crypto_xof_block_blake3_t const mk_lib_crypto_xof_block_blake3_ct;
typedef mk_lib_crypto_xof_block_blake3_t* mk_lib_crypto_xof_block_blake3_pt;
typedef mk_lib_crypto_xof_block_blake3_t const* mk_lib_crypto_xof_block_blake3_pct;

typedef mk_lib_crypto_hash_block_blake3_base_block_t mk_lib_crypto_xof_block_blake3_block_t;
typedef mk_lib_crypto_xof_block_blake3_block_t const mk_lib_crypto_xof_block_blake3_block_ct;
typedef mk_lib_crypto_xof_block_blake3_block_t* mk_lib_crypto_xof_block_blake3_block_pt;
typedef mk_lib_crypto_xof_block_blake3_block_t const* mk_lib_crypto_xof_block_blake3_block_pct;


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_blake3_init(mk_lib_crypto_xof_block_blake3_pt const blake3) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_blake3_append_blocks(mk_lib_crypto_xof_block_blake3_pt const blake3, mk_lib_crypto_xof_block_blake3_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_blake3_finish(mk_lib_crypto_xof_block_blake3_pt const blake3, mk_lib_crypto_xof_block_blake3_block_pt const block, mk_lang_types_sint_t const idx) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_block_blake3_squeeze(mk_lib_crypto_xof_block_blake3_pt const blake3, mk_lang_types_usize_t const len, mk_sl_cui_uint8_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_xof_block_blake3.c"
#endif
#endif
