#ifndef mk_include_guard_mk_lib_crypto_hash_block_blake2b_384
#define mk_include_guard_mk_lib_crypto_hash_block_blake2b_384


/* rfc 7693 */


#include "mk_lang_alignas.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_pow2.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_blake2b_base.h"
#include "mk_sl_uint128.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_hash_block_blake2b_384_block_len 128
#define mk_lib_crypto_hash_block_blake2b_384_digest_len 48
#define mk_lib_crypto_hash_block_blake2b_384_name_def BLAKE2b-384
mk_lang_constexpr_static_inline char const mk_lib_crypto_hash_block_blake2b_384_name_str[] = mk_lang_stringify(mk_lib_crypto_hash_block_blake2b_384_name_def);
mk_lang_constexpr_static_inline int const mk_lib_crypto_hash_block_blake2b_384_name_str_len = ((int)(sizeof(mk_lib_crypto_hash_block_blake2b_384_name_str) - 1));


union mk_lib_crypto_hash_block_blake2b_384_aligned48_u
{
	mk_lang_alignas(mk_lang_pow2_roundup(48)) mk_sl_cui_uint8_t m_uint8s[48];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_blake2b_384_aligned48_u mk_lib_crypto_hash_block_blake2b_384_aligned48_t;
typedef mk_lib_crypto_hash_block_blake2b_384_aligned48_t const mk_lib_crypto_hash_block_blake2b_384_aligned48_ct;
typedef mk_lib_crypto_hash_block_blake2b_384_aligned48_t* mk_lib_crypto_hash_block_blake2b_384_aligned48_pt;
typedef mk_lib_crypto_hash_block_blake2b_384_aligned48_t const* mk_lib_crypto_hash_block_blake2b_384_aligned48_pct;


struct mk_lib_crypto_hash_block_blake2b_384_s
{
	mk_lib_crypto_hash_block_blake2b_base_t m_blake2b_384_base;
};
typedef struct mk_lib_crypto_hash_block_blake2b_384_s mk_lib_crypto_hash_block_blake2b_384_t;
typedef mk_lib_crypto_hash_block_blake2b_384_t const mk_lib_crypto_hash_block_blake2b_384_ct;
typedef mk_lib_crypto_hash_block_blake2b_384_t* mk_lib_crypto_hash_block_blake2b_384_pt;
typedef mk_lib_crypto_hash_block_blake2b_384_t const* mk_lib_crypto_hash_block_blake2b_384_pct;

typedef mk_lib_crypto_hash_block_blake2b_base_block_t mk_lib_crypto_hash_block_blake2b_384_block_t;
typedef mk_lib_crypto_hash_block_blake2b_384_block_t const mk_lib_crypto_hash_block_blake2b_384_block_ct;
typedef mk_lib_crypto_hash_block_blake2b_384_block_t* mk_lib_crypto_hash_block_blake2b_384_block_pt;
typedef mk_lib_crypto_hash_block_blake2b_384_block_t const* mk_lib_crypto_hash_block_blake2b_384_block_pct;

typedef mk_lib_crypto_hash_block_blake2b_384_aligned48_t mk_lib_crypto_hash_block_blake2b_384_digest_t;
typedef mk_lib_crypto_hash_block_blake2b_384_digest_t const mk_lib_crypto_hash_block_blake2b_384_digest_ct;
typedef mk_lib_crypto_hash_block_blake2b_384_digest_t* mk_lib_crypto_hash_block_blake2b_384_digest_pt;
typedef mk_lib_crypto_hash_block_blake2b_384_digest_t const* mk_lib_crypto_hash_block_blake2b_384_digest_pct;

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake2b_384_init(mk_lib_crypto_hash_block_blake2b_384_pt const blake2b_384) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake2b_384_append_blocks(mk_lib_crypto_hash_block_blake2b_384_pt const blake2b_384, mk_lib_crypto_hash_block_blake2b_384_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake2b_384_finish(mk_lib_crypto_hash_block_blake2b_384_pt const blake2b_384, mk_lib_crypto_hash_block_blake2b_384_block_pt const block, int const idx, mk_lib_crypto_hash_block_blake2b_384_digest_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_block_blake2b_384.c"
#endif
#endif
