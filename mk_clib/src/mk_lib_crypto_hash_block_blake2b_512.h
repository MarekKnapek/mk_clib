#ifndef mk_include_guard_mk_lib_crypto_hash_block_blake2b_512
#define mk_include_guard_mk_lib_crypto_hash_block_blake2b_512


/* rfc 7693 */


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_blake2b_base.h"
#include "mk_sl_uint128.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_hash_block_blake2b_512_block_len 128
#define mk_lib_crypto_hash_block_blake2b_512_digest_len 64
#define mk_lib_crypto_hash_block_blake2b_512_name_def BLAKE2b-512
mk_lang_constexpr_static_inline char const mk_lib_crypto_hash_block_blake2b_512_name_str[] = mk_lang_stringify(mk_lib_crypto_hash_block_blake2b_512_name_def);
mk_lang_constexpr_static_inline int const mk_lib_crypto_hash_block_blake2b_512_name_str_len = ((int)(sizeof(mk_lib_crypto_hash_block_blake2b_512_name_str) - 1));


struct mk_lib_crypto_hash_block_blake2b_512_s
{
	mk_lib_crypto_hash_block_blake2b_base_t m_blake2b_512_base;
};
typedef struct mk_lib_crypto_hash_block_blake2b_512_s mk_lib_crypto_hash_block_blake2b_512_t;
typedef mk_lib_crypto_hash_block_blake2b_512_t const mk_lib_crypto_hash_block_blake2b_512_ct;
typedef mk_lib_crypto_hash_block_blake2b_512_t* mk_lib_crypto_hash_block_blake2b_512_pt;
typedef mk_lib_crypto_hash_block_blake2b_512_t const* mk_lib_crypto_hash_block_blake2b_512_pct;

typedef mk_lib_crypto_hash_block_blake2b_base_block_t mk_lib_crypto_hash_block_blake2b_512_block_t;
typedef mk_lib_crypto_hash_block_blake2b_512_block_t const mk_lib_crypto_hash_block_blake2b_512_block_ct;
typedef mk_lib_crypto_hash_block_blake2b_512_block_t* mk_lib_crypto_hash_block_blake2b_512_block_pt;
typedef mk_lib_crypto_hash_block_blake2b_512_block_t const* mk_lib_crypto_hash_block_blake2b_512_block_pct;

typedef mk_lib_crypto_hash_block_blake2b_base_digest_t mk_lib_crypto_hash_block_blake2b_512_digest_t;
typedef mk_lib_crypto_hash_block_blake2b_512_digest_t const mk_lib_crypto_hash_block_blake2b_512_digest_ct;
typedef mk_lib_crypto_hash_block_blake2b_512_digest_t* mk_lib_crypto_hash_block_blake2b_512_digest_pt;
typedef mk_lib_crypto_hash_block_blake2b_512_digest_t const* mk_lib_crypto_hash_block_blake2b_512_digest_pct;

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake2b_512_init(mk_lib_crypto_hash_block_blake2b_512_pt const blake2b_512) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake2b_512_append_blocks(mk_lib_crypto_hash_block_blake2b_512_pt const blake2b_512, mk_lib_crypto_hash_block_blake2b_512_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake2b_512_finish(mk_lib_crypto_hash_block_blake2b_512_pt const blake2b_512, mk_lib_crypto_hash_block_blake2b_512_block_pt const block, int const idx, mk_lib_crypto_hash_block_blake2b_512_digest_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_block_blake2b_512.c"
#endif
#endif
