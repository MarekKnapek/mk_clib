#ifndef mk_include_guard_mk_lib_crypto_hash_block_sha2_base_64bit
#define mk_include_guard_mk_lib_crypto_hash_block_sha2_base_64bit


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_sha2_base_64bit_c.h"
#include "mk_lib_crypto_hash_block_sha2_base_64bit_x86.h"
#include "mk_sl_uint64.h"


#define mk_lib_crypto_hash_block_sha2_base_64bit_block_len 128
#define mk_lib_crypto_hash_block_sha2_base_64bit_digest_len 64


union mk_lib_crypto_hash_block_sha2_base_64bit_data_u
{
	mk_lib_crypto_hash_block_sha2_base_64bit_c_t m_sha2_base_64bit_c;
	mk_lib_crypto_hash_block_sha2_base_64bit_x86_t m_sha2_base_64bit_x86;
};
typedef union mk_lib_crypto_hash_block_sha2_base_64bit_data_u mk_lib_crypto_hash_block_sha2_base_64bit_data_t;

struct mk_lib_crypto_hash_block_sha2_base_64bit_s
{
	mk_lib_crypto_hash_block_sha2_base_64bit_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_sha2_base_64bit_s mk_lib_crypto_hash_block_sha2_base_64bit_t;
typedef mk_lib_crypto_hash_block_sha2_base_64bit_t const mk_lib_crypto_hash_block_sha2_base_64bit_ct;
typedef mk_lib_crypto_hash_block_sha2_base_64bit_t* mk_lib_crypto_hash_block_sha2_base_64bit_pt;
typedef mk_lib_crypto_hash_block_sha2_base_64bit_t const* mk_lib_crypto_hash_block_sha2_base_64bit_pct;

typedef mk_lib_crypto_hash_block_sha2_base_64bit_c_block_t mk_lib_crypto_hash_block_sha2_base_64bit_block_t;
typedef mk_lib_crypto_hash_block_sha2_base_64bit_block_t const mk_lib_crypto_hash_block_sha2_base_64bit_block_ct;
typedef mk_lib_crypto_hash_block_sha2_base_64bit_block_t* mk_lib_crypto_hash_block_sha2_base_64bit_block_pt;
typedef mk_lib_crypto_hash_block_sha2_base_64bit_block_t const* mk_lib_crypto_hash_block_sha2_base_64bit_block_pct;

typedef mk_lib_crypto_hash_block_sha2_base_64bit_c_digest_t mk_lib_crypto_hash_block_sha2_base_64bit_digest_t;
typedef mk_lib_crypto_hash_block_sha2_base_64bit_digest_t const mk_lib_crypto_hash_block_sha2_base_64bit_digest_ct;
typedef mk_lib_crypto_hash_block_sha2_base_64bit_digest_t* mk_lib_crypto_hash_block_sha2_base_64bit_digest_pt;
typedef mk_lib_crypto_hash_block_sha2_base_64bit_digest_t const* mk_lib_crypto_hash_block_sha2_base_64bit_digest_pct;


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_init(mk_lib_crypto_hash_block_sha2_base_64bit_pt const sha2_base_64bit, mk_sl_cui_uint64_pct const iv) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_append_blocks(mk_lib_crypto_hash_block_sha2_base_64bit_pt const sha2_base_64bit, mk_lib_crypto_hash_block_sha2_base_64bit_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha2_base_64bit_finish(mk_lib_crypto_hash_block_sha2_base_64bit_pt const sha2_base_64bit, mk_lib_crypto_hash_block_sha2_base_64bit_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_sha2_base_64bit_digest_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_block_sha2_base_64bit.c"
#endif
#endif
