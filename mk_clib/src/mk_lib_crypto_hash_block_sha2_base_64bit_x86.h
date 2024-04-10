#ifndef mk_include_guard_mk_lib_crypto_hash_block_sha2_base_64bit_x86
#define mk_include_guard_mk_lib_crypto_hash_block_sha2_base_64bit_x86


#include "mk_lang_alignas.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_sl_uint128.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_len 128
#define mk_lib_crypto_hash_block_sha2_base_64bit_x86_digest_len 64


union mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_data_u
{
	mk_lang_alignas(128) mk_sl_cui_uint8_t m_uint8s[128];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_data_u mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_data_t;

union mk_lib_crypto_hash_block_sha2_base_64bit_x86_digest_data_u
{
	mk_lang_alignas(64) mk_sl_cui_uint8_t m_uint8s[64];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_sha2_base_64bit_x86_digest_data_u mk_lib_crypto_hash_block_sha2_base_64bit_x86_digest_data_t;


struct mk_lib_crypto_hash_block_sha2_base_64bit_x86_s
{
	mk_sl_cui_uint64_t m_hs[8];
	mk_sl_cui_uint128_t m_len;
};
typedef struct mk_lib_crypto_hash_block_sha2_base_64bit_x86_s mk_lib_crypto_hash_block_sha2_base_64bit_x86_t;
typedef mk_lib_crypto_hash_block_sha2_base_64bit_x86_t const mk_lib_crypto_hash_block_sha2_base_64bit_x86_ct;
typedef mk_lib_crypto_hash_block_sha2_base_64bit_x86_t* mk_lib_crypto_hash_block_sha2_base_64bit_x86_pt;
typedef mk_lib_crypto_hash_block_sha2_base_64bit_x86_t const* mk_lib_crypto_hash_block_sha2_base_64bit_x86_pct;

typedef mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_data_t mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_t;
typedef mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_t const mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_ct;
typedef mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_t* mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_pt;
typedef mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_t const* mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_pct;

typedef mk_lib_crypto_hash_block_sha2_base_64bit_x86_digest_data_t mk_lib_crypto_hash_block_sha2_base_64bit_x86_digest_t;
typedef mk_lib_crypto_hash_block_sha2_base_64bit_x86_digest_t const mk_lib_crypto_hash_block_sha2_base_64bit_x86_digest_ct;
typedef mk_lib_crypto_hash_block_sha2_base_64bit_x86_digest_t* mk_lib_crypto_hash_block_sha2_base_64bit_x86_digest_pt;
typedef mk_lib_crypto_hash_block_sha2_base_64bit_x86_digest_t const* mk_lib_crypto_hash_block_sha2_base_64bit_x86_digest_pct;

mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_x86_init(mk_lib_crypto_hash_block_sha2_base_64bit_x86_pt const sha2_base_64bit_x86, mk_sl_cui_uint64_pct const iv) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_x86_append_blocks(mk_lib_crypto_hash_block_sha2_base_64bit_x86_pt const sha2_base_64bit_x86, mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_x86_finish(mk_lib_crypto_hash_block_sha2_base_64bit_x86_pt const sha2_base_64bit_x86, mk_lib_crypto_hash_block_sha2_base_64bit_x86_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_sha2_base_64bit_x86_digest_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_block_sha2_base_64bit_x86.c"
#endif
#endif
