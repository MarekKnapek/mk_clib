#ifndef mk_include_guard_mk_lib_crypto_hash_block_md2
#define mk_include_guard_mk_lib_crypto_hash_block_md2


/* rfc1115 */
/* rfc1319 */


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_hash_block_md2_block_len 16
#define mk_lib_crypto_hash_block_md2_digest_len 16
#define mk_lib_crypto_hash_block_md2_name_def MD2
mk_lang_constexpr_static_inline char const mk_lib_crypto_hash_block_md2_name_str[] = mk_lang_stringify(mk_lib_crypto_hash_block_md2_name_def);
mk_lang_constexpr_static_inline int const mk_lib_crypto_hash_block_md2_name_str_len = ((int)(sizeof(mk_lib_crypto_hash_block_md2_name_str) - 1));


union mk_lib_crypto_hash_block_md2_aligned16_u
{
	mk_sl_cui_uint8_t m_uint8s[16];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_md2_aligned16_u mk_lib_crypto_hash_block_md2_aligned16_t;
typedef mk_lib_crypto_hash_block_md2_aligned16_t const mk_lib_crypto_hash_block_md2_aligned16_ct;
typedef mk_lib_crypto_hash_block_md2_aligned16_t* mk_lib_crypto_hash_block_md2_aligned16_pt;
typedef mk_lib_crypto_hash_block_md2_aligned16_t const* mk_lib_crypto_hash_block_md2_aligned16_pct;


struct mk_lib_crypto_hash_block_md2_s
{
	mk_lib_crypto_hash_block_md2_aligned16_t m_state;
	mk_lib_crypto_hash_block_md2_aligned16_t m_checksum;
};
typedef struct mk_lib_crypto_hash_block_md2_s mk_lib_crypto_hash_block_md2_t;
typedef mk_lib_crypto_hash_block_md2_t const mk_lib_crypto_hash_block_md2_ct;
typedef mk_lib_crypto_hash_block_md2_t* mk_lib_crypto_hash_block_md2_pt;
typedef mk_lib_crypto_hash_block_md2_t const* mk_lib_crypto_hash_block_md2_pct;

typedef mk_lib_crypto_hash_block_md2_aligned16_t mk_lib_crypto_hash_block_md2_block_t;
typedef mk_lib_crypto_hash_block_md2_block_t const mk_lib_crypto_hash_block_md2_block_ct;
typedef mk_lib_crypto_hash_block_md2_block_t* mk_lib_crypto_hash_block_md2_block_pt;
typedef mk_lib_crypto_hash_block_md2_block_t const* mk_lib_crypto_hash_block_md2_block_pct;

typedef mk_lib_crypto_hash_block_md2_aligned16_t mk_lib_crypto_hash_block_md2_digest_t;
typedef mk_lib_crypto_hash_block_md2_digest_t const mk_lib_crypto_hash_block_md2_digest_ct;
typedef mk_lib_crypto_hash_block_md2_digest_t* mk_lib_crypto_hash_block_md2_digest_pt;
typedef mk_lib_crypto_hash_block_md2_digest_t const* mk_lib_crypto_hash_block_md2_digest_pct;

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_md2_init(mk_lib_crypto_hash_block_md2_pt const md2) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_md2_append_blocks(mk_lib_crypto_hash_block_md2_pt const md2, mk_lib_crypto_hash_block_md2_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_md2_finish(mk_lib_crypto_hash_block_md2_pt const md2, mk_lib_crypto_hash_block_md2_block_pt const block, int const idx, mk_lib_crypto_hash_block_md2_digest_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_block_md2.c"
#endif
#endif
