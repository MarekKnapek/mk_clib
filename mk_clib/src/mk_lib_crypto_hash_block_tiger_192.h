#ifndef mk_include_guard_mk_lib_crypto_hash_block_tiger_192
#define mk_include_guard_mk_lib_crypto_hash_block_tiger_192


/* http://www.cs.technion.ac.il/~biham/Reports/Tiger/ */


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_tiger_base.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_hash_block_tiger_192_block_len 64
#define mk_lib_crypto_hash_block_tiger_192_digest_len 24
#define mk_lib_crypto_hash_block_tiger_192_name_def Tiger/192
mk_lang_constexpr_static_inline char const mk_lib_crypto_hash_block_tiger_192_name_str[] = mk_lang_stringify(mk_lib_crypto_hash_block_tiger_192_name_def);
mk_lang_constexpr_static_inline int const mk_lib_crypto_hash_block_tiger_192_name_str_len = ((int)(sizeof(mk_lib_crypto_hash_block_tiger_192_name_str) - 1));


union mk_lib_crypto_hash_block_tiger_192_aligned24_u
{
	mk_sl_cui_uint8_t m_uint8s[24];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_tiger_192_aligned24_u mk_lib_crypto_hash_block_tiger_192_aligned24_t;
typedef mk_lib_crypto_hash_block_tiger_192_aligned24_t const mk_lib_crypto_hash_block_tiger_192_aligned24_ct;
typedef mk_lib_crypto_hash_block_tiger_192_aligned24_t* mk_lib_crypto_hash_block_tiger_192_aligned24_pt;
typedef mk_lib_crypto_hash_block_tiger_192_aligned24_t const* mk_lib_crypto_hash_block_tiger_192_aligned24_pct;


struct mk_lib_crypto_hash_block_tiger_192_s
{
	mk_lib_crypto_hash_block_tiger_base_t m_tiger;
};
typedef struct mk_lib_crypto_hash_block_tiger_192_s mk_lib_crypto_hash_block_tiger_192_t;
typedef mk_lib_crypto_hash_block_tiger_192_t const mk_lib_crypto_hash_block_tiger_192_ct;
typedef mk_lib_crypto_hash_block_tiger_192_t* mk_lib_crypto_hash_block_tiger_192_pt;
typedef mk_lib_crypto_hash_block_tiger_192_t const* mk_lib_crypto_hash_block_tiger_192_pct;

typedef mk_lib_crypto_hash_block_tiger_base_aligned64_t mk_lib_crypto_hash_block_tiger_192_block_t;
typedef mk_lib_crypto_hash_block_tiger_192_block_t const mk_lib_crypto_hash_block_tiger_192_block_ct;
typedef mk_lib_crypto_hash_block_tiger_192_block_t* mk_lib_crypto_hash_block_tiger_192_block_pt;
typedef mk_lib_crypto_hash_block_tiger_192_block_t const* mk_lib_crypto_hash_block_tiger_192_block_pct;

typedef mk_lib_crypto_hash_block_tiger_192_aligned24_t mk_lib_crypto_hash_block_tiger_192_digest_t;
typedef mk_lib_crypto_hash_block_tiger_192_digest_t const mk_lib_crypto_hash_block_tiger_192_digest_ct;
typedef mk_lib_crypto_hash_block_tiger_192_digest_t* mk_lib_crypto_hash_block_tiger_192_digest_pt;
typedef mk_lib_crypto_hash_block_tiger_192_digest_t const* mk_lib_crypto_hash_block_tiger_192_digest_pct;

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_tiger_192_init(mk_lib_crypto_hash_block_tiger_192_pt const tiger) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_tiger_192_append_blocks(mk_lib_crypto_hash_block_tiger_192_pt const tiger, mk_lib_crypto_hash_block_tiger_192_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_tiger_192_finish(mk_lib_crypto_hash_block_tiger_192_pt const tiger, mk_lib_crypto_hash_block_tiger_192_block_pt const block, int const idx, mk_lib_crypto_hash_block_tiger_192_digest_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_block_tiger_192.c"
#endif
#endif
