#ifndef mk_include_guard_mk_lib_crypto_hash_block_sha3_224
#define mk_include_guard_mk_lib_crypto_hash_block_sha3_224


/* nist fips pub 202 */


#include "mk_lang_alignas.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_pow2.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_sha3_base.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_hash_block_sha3_224_block_len 144
#define mk_lib_crypto_hash_block_sha3_224_digest_len 28
#define mk_lib_crypto_hash_block_sha3_224_name_def SHA3-224
mk_lang_constexpr_static_inline char const mk_lib_crypto_hash_block_sha3_224_name_str[] = mk_lang_stringify(mk_lib_crypto_hash_block_sha3_224_name_def);
mk_lang_constexpr_static_inline int const mk_lib_crypto_hash_block_sha3_224_name_str_len = ((int)(sizeof(mk_lib_crypto_hash_block_sha3_224_name_str) - 1));


union mk_lib_crypto_hash_block_sha3_224_aligned144_u
{
	mk_lang_alignas(16) mk_sl_cui_uint8_t m_uint8s[144];
	mk_sl_cui_uint64_t m_align;
};
typedef union mk_lib_crypto_hash_block_sha3_224_aligned144_u mk_lib_crypto_hash_block_sha3_224_aligned144_t;
typedef mk_lib_crypto_hash_block_sha3_224_aligned144_t const mk_lib_crypto_hash_block_sha3_224_aligned144_ct;
typedef mk_lib_crypto_hash_block_sha3_224_aligned144_t* mk_lib_crypto_hash_block_sha3_224_aligned144_pt;
typedef mk_lib_crypto_hash_block_sha3_224_aligned144_t const* mk_lib_crypto_hash_block_sha3_224_aligned144_pct;

union mk_lib_crypto_hash_block_sha3_224_aligned28_u
{
	mk_lang_alignas(mk_lang_pow2_roundup(28)) mk_sl_cui_uint8_t m_uint8s[28];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_sha3_224_aligned28_u mk_lib_crypto_hash_block_sha3_224_aligned28_t;
typedef mk_lib_crypto_hash_block_sha3_224_aligned28_t const mk_lib_crypto_hash_block_sha3_224_aligned28_ct;
typedef mk_lib_crypto_hash_block_sha3_224_aligned28_t* mk_lib_crypto_hash_block_sha3_224_aligned28_pt;
typedef mk_lib_crypto_hash_block_sha3_224_aligned28_t const* mk_lib_crypto_hash_block_sha3_224_aligned28_pct;


struct mk_lib_crypto_hash_block_sha3_224_s
{
	mk_lib_crypto_hash_block_sha3_base_state_t m_sha3;
};
typedef struct mk_lib_crypto_hash_block_sha3_224_s mk_lib_crypto_hash_block_sha3_224_t;
typedef mk_lib_crypto_hash_block_sha3_224_t const mk_lib_crypto_hash_block_sha3_224_ct;
typedef mk_lib_crypto_hash_block_sha3_224_t* mk_lib_crypto_hash_block_sha3_224_pt;
typedef mk_lib_crypto_hash_block_sha3_224_t const* mk_lib_crypto_hash_block_sha3_224_pct;

typedef mk_lib_crypto_hash_block_sha3_224_aligned144_t mk_lib_crypto_hash_block_sha3_224_block_t;
typedef mk_lib_crypto_hash_block_sha3_224_block_t const mk_lib_crypto_hash_block_sha3_224_block_ct;
typedef mk_lib_crypto_hash_block_sha3_224_block_t* mk_lib_crypto_hash_block_sha3_224_block_pt;
typedef mk_lib_crypto_hash_block_sha3_224_block_t const* mk_lib_crypto_hash_block_sha3_224_block_pct;

typedef mk_lib_crypto_hash_block_sha3_224_aligned28_t mk_lib_crypto_hash_block_sha3_224_digest_t;
typedef mk_lib_crypto_hash_block_sha3_224_digest_t const mk_lib_crypto_hash_block_sha3_224_digest_ct;
typedef mk_lib_crypto_hash_block_sha3_224_digest_t* mk_lib_crypto_hash_block_sha3_224_digest_pt;
typedef mk_lib_crypto_hash_block_sha3_224_digest_t const* mk_lib_crypto_hash_block_sha3_224_digest_pct;

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha3_224_init(mk_lib_crypto_hash_block_sha3_224_pt const sha3_224) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha3_224_append_blocks(mk_lib_crypto_hash_block_sha3_224_pt const sha3_224, mk_lib_crypto_hash_block_sha3_224_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha3_224_finish(mk_lib_crypto_hash_block_sha3_224_pt const sha3_224, mk_lib_crypto_hash_block_sha3_224_block_pt const block, int const idx, mk_lib_crypto_hash_block_sha3_224_digest_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_block_sha3_224.c"
#endif
#endif
