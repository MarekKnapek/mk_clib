#ifndef mk_include_guard_mk_lib_crypto_hash_block_tiger_base
#define mk_include_guard_mk_lib_crypto_hash_block_tiger_base


#include "mk_lang_alignas.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_hash_block_tiger_base_block_len 64
#define mk_lib_crypto_hash_block_tiger_base_digest_len 24


union mk_lib_crypto_hash_block_tiger_base_aligned64_u
{
	mk_lang_alignas(64) mk_sl_cui_uint8_t m_uint8s[64];
	mk_sl_cui_uint64_t m_align;
};
typedef union mk_lib_crypto_hash_block_tiger_base_aligned64_u mk_lib_crypto_hash_block_tiger_base_aligned64_t;
typedef mk_lib_crypto_hash_block_tiger_base_aligned64_t const mk_lib_crypto_hash_block_tiger_base_aligned64_ct;
typedef mk_lib_crypto_hash_block_tiger_base_aligned64_t* mk_lib_crypto_hash_block_tiger_base_aligned64_pt;
typedef mk_lib_crypto_hash_block_tiger_base_aligned64_t const* mk_lib_crypto_hash_block_tiger_base_aligned64_pct;

union mk_lib_crypto_hash_block_tiger_base_aligned24_u
{
	mk_lang_alignas(32) mk_sl_cui_uint8_t m_uint8s[24];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_tiger_base_aligned24_u mk_lib_crypto_hash_block_tiger_base_aligned24_t;
typedef mk_lib_crypto_hash_block_tiger_base_aligned24_t const mk_lib_crypto_hash_block_tiger_base_aligned24_ct;
typedef mk_lib_crypto_hash_block_tiger_base_aligned24_t* mk_lib_crypto_hash_block_tiger_base_aligned24_pt;
typedef mk_lib_crypto_hash_block_tiger_base_aligned24_t const* mk_lib_crypto_hash_block_tiger_base_aligned24_pct;


struct mk_lib_crypto_hash_block_tiger_base_s
{
	mk_sl_cui_uint64_t m_a;
	mk_sl_cui_uint64_t m_b;
	mk_sl_cui_uint64_t m_c;
	mk_sl_cui_uint64_t m_len;
};
typedef struct mk_lib_crypto_hash_block_tiger_base_s mk_lib_crypto_hash_block_tiger_base_t;
typedef mk_lib_crypto_hash_block_tiger_base_t const mk_lib_crypto_hash_block_tiger_base_ct;
typedef mk_lib_crypto_hash_block_tiger_base_t* mk_lib_crypto_hash_block_tiger_base_pt;
typedef mk_lib_crypto_hash_block_tiger_base_t const* mk_lib_crypto_hash_block_tiger_base_pct;

typedef mk_lib_crypto_hash_block_tiger_base_aligned64_t mk_lib_crypto_hash_block_tiger_base_block_t;
typedef mk_lib_crypto_hash_block_tiger_base_block_t const mk_lib_crypto_hash_block_tiger_base_block_ct;
typedef mk_lib_crypto_hash_block_tiger_base_block_t* mk_lib_crypto_hash_block_tiger_base_block_pt;
typedef mk_lib_crypto_hash_block_tiger_base_block_t const* mk_lib_crypto_hash_block_tiger_base_block_pct;

typedef mk_lib_crypto_hash_block_tiger_base_aligned24_t mk_lib_crypto_hash_block_tiger_base_digest_t;
typedef mk_lib_crypto_hash_block_tiger_base_digest_t const mk_lib_crypto_hash_block_tiger_base_digest_ct;
typedef mk_lib_crypto_hash_block_tiger_base_digest_t* mk_lib_crypto_hash_block_tiger_base_digest_pt;
typedef mk_lib_crypto_hash_block_tiger_base_digest_t const* mk_lib_crypto_hash_block_tiger_base_digest_pct;

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_tiger_base_init(mk_lib_crypto_hash_block_tiger_base_pt const tiger_base) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_tiger_base_append_blocks(mk_lib_crypto_hash_block_tiger_base_pt const tiger_base, mk_lib_crypto_hash_block_tiger_base_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_tiger_base_finish(mk_lib_crypto_hash_block_tiger_base_pt const tiger_base, mk_lang_types_bool_t const variant, mk_lib_crypto_hash_block_tiger_base_block_pt const block, int const idx, mk_lib_crypto_hash_block_tiger_base_digest_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_block_tiger_base.c"
#endif
#endif
