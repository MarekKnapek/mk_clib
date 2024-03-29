#ifndef mk_include_guard_mk_lib_crypto_hash_block_blake2b_256
#define mk_include_guard_mk_lib_crypto_hash_block_blake2b_256


/* rfc 7693 */


#include "mk_lang_alignas.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_blake2b_base.h"
#include "mk_sl_uint128.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_hash_block_blake2b_256_block_len 128
#define mk_lib_crypto_hash_block_blake2b_256_digest_len 32
#define mk_lib_crypto_hash_block_blake2b_256_name_def BLAKE2b-256
mk_lang_constexpr_static_inline char const mk_lib_crypto_hash_block_blake2b_256_name_str[] = mk_lang_stringify(mk_lib_crypto_hash_block_blake2b_256_name_def);
mk_lang_constexpr_static_inline int const mk_lib_crypto_hash_block_blake2b_256_name_str_len = ((int)(sizeof(mk_lib_crypto_hash_block_blake2b_256_name_str) - 1));


union mk_lib_crypto_hash_block_blake2b_256_aligned32_u
{
	mk_lang_alignas(32) mk_sl_cui_uint8_t m_uint8s[32];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_blake2b_256_aligned32_u mk_lib_crypto_hash_block_blake2b_256_aligned32_t;
typedef mk_lib_crypto_hash_block_blake2b_256_aligned32_t const mk_lib_crypto_hash_block_blake2b_256_aligned32_ct;
typedef mk_lib_crypto_hash_block_blake2b_256_aligned32_t* mk_lib_crypto_hash_block_blake2b_256_aligned32_pt;
typedef mk_lib_crypto_hash_block_blake2b_256_aligned32_t const* mk_lib_crypto_hash_block_blake2b_256_aligned32_pct;


struct mk_lib_crypto_hash_block_blake2b_256_s
{
	mk_lib_crypto_hash_block_blake2b_base_t m_blake2b_256_base;
};
typedef struct mk_lib_crypto_hash_block_blake2b_256_s mk_lib_crypto_hash_block_blake2b_256_t;
typedef mk_lib_crypto_hash_block_blake2b_256_t const mk_lib_crypto_hash_block_blake2b_256_ct;
typedef mk_lib_crypto_hash_block_blake2b_256_t* mk_lib_crypto_hash_block_blake2b_256_pt;
typedef mk_lib_crypto_hash_block_blake2b_256_t const* mk_lib_crypto_hash_block_blake2b_256_pct;

typedef mk_lib_crypto_hash_block_blake2b_base_block_t mk_lib_crypto_hash_block_blake2b_256_block_t;
typedef mk_lib_crypto_hash_block_blake2b_256_block_t const mk_lib_crypto_hash_block_blake2b_256_block_ct;
typedef mk_lib_crypto_hash_block_blake2b_256_block_t* mk_lib_crypto_hash_block_blake2b_256_block_pt;
typedef mk_lib_crypto_hash_block_blake2b_256_block_t const* mk_lib_crypto_hash_block_blake2b_256_block_pct;

typedef mk_lib_crypto_hash_block_blake2b_256_aligned32_t mk_lib_crypto_hash_block_blake2b_256_digest_t;
typedef mk_lib_crypto_hash_block_blake2b_256_digest_t const mk_lib_crypto_hash_block_blake2b_256_digest_ct;
typedef mk_lib_crypto_hash_block_blake2b_256_digest_t* mk_lib_crypto_hash_block_blake2b_256_digest_pt;
typedef mk_lib_crypto_hash_block_blake2b_256_digest_t const* mk_lib_crypto_hash_block_blake2b_256_digest_pct;

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake2b_256_init(mk_lib_crypto_hash_block_blake2b_256_pt const blake2b_256) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake2b_256_append_blocks(mk_lib_crypto_hash_block_blake2b_256_pt const blake2b_256, mk_lib_crypto_hash_block_blake2b_256_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake2b_256_finish(mk_lib_crypto_hash_block_blake2b_256_pt const blake2b_256, mk_lib_crypto_hash_block_blake2b_256_block_pt const block, int const idx, mk_lib_crypto_hash_block_blake2b_256_digest_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_block_blake2b_256.c"
#endif
#endif
