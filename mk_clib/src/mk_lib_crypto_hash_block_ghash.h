#ifndef mk_include_guard_mk_lib_crypto_hash_block_ghash
#define mk_include_guard_mk_lib_crypto_hash_block_ghash


/* NIST SP 800-38D */


#include "mk_lang_alignas.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_hash_block_ghash_block_len 16
#define mk_lib_crypto_hash_block_ghash_digest_len 16
#define mk_lib_crypto_hash_block_ghash_name_def GHASH
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_crypto_hash_block_ghash_name_str[] = mk_lang_stringify(mk_lib_crypto_hash_block_ghash_name_def);
mk_lang_constexpr_static_inline mk_lang_types_sint_t const mk_lib_crypto_hash_block_ghash_name_str_len = ((mk_lang_types_sint_t)(sizeof(mk_lib_crypto_hash_block_ghash_name_str) - 1));


union mk_lib_crypto_hash_block_ghash_block_data_u
{
	mk_lang_alignas(16) mk_sl_cui_uint8_t m_uint8s[16];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_ghash_block_data_u mk_lib_crypto_hash_block_ghash_block_data_t;

struct mk_lib_crypto_hash_block_ghash_block_s
{
	mk_lib_crypto_hash_block_ghash_block_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_ghash_block_s mk_lib_crypto_hash_block_ghash_block_t;
typedef mk_lib_crypto_hash_block_ghash_block_t const mk_lib_crypto_hash_block_ghash_block_ct;
typedef mk_lib_crypto_hash_block_ghash_block_t* mk_lib_crypto_hash_block_ghash_block_pt;
typedef mk_lib_crypto_hash_block_ghash_block_t const* mk_lib_crypto_hash_block_ghash_block_pct;

union mk_lib_crypto_hash_block_ghash_digest_data_u
{
	mk_lang_alignas(16) mk_sl_cui_uint8_t m_uint8s[16];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_ghash_digest_data_u mk_lib_crypto_hash_block_ghash_digest_data_t;

struct mk_lib_crypto_hash_block_ghash_digest_s
{
	mk_lib_crypto_hash_block_ghash_digest_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_ghash_digest_s mk_lib_crypto_hash_block_ghash_digest_t;
typedef mk_lib_crypto_hash_block_ghash_digest_t const mk_lib_crypto_hash_block_ghash_digest_ct;
typedef mk_lib_crypto_hash_block_ghash_digest_t* mk_lib_crypto_hash_block_ghash_digest_pt;
typedef mk_lib_crypto_hash_block_ghash_digest_t const* mk_lib_crypto_hash_block_ghash_digest_pct;

struct mk_lib_crypto_hash_block_ghash_s
{
	mk_lib_crypto_hash_block_ghash_block_t m_key;
	mk_lib_crypto_hash_block_ghash_block_t m_state;
};
typedef struct mk_lib_crypto_hash_block_ghash_s mk_lib_crypto_hash_block_ghash_t;
typedef mk_lib_crypto_hash_block_ghash_t const mk_lib_crypto_hash_block_ghash_ct;
typedef mk_lib_crypto_hash_block_ghash_t* mk_lib_crypto_hash_block_ghash_pt;
typedef mk_lib_crypto_hash_block_ghash_t const* mk_lib_crypto_hash_block_ghash_pct;


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_ghash_init(mk_lib_crypto_hash_block_ghash_pt const ghash, mk_lib_crypto_hash_block_ghash_block_pct const key) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_ghash_append_blocks(mk_lib_crypto_hash_block_ghash_pt const ghash, mk_lib_crypto_hash_block_ghash_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_ghash_finish(mk_lib_crypto_hash_block_ghash_pt const ghash, mk_lib_crypto_hash_block_ghash_digest_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_block_ghash.c"
#endif
#endif
