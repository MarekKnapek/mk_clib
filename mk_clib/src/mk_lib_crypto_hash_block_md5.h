#ifndef mk_include_guard_mk_lib_crypto_hash_block_md5
#define mk_include_guard_mk_lib_crypto_hash_block_md5


/* rfc 1321 */


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_hash_block_md5_block_len 64
#define mk_lib_crypto_hash_block_md5_digest_len 16
#define mk_lib_crypto_hash_block_md5_name_def MD5
mk_lang_constexpr_static_inline char const mk_lib_crypto_hash_block_md5_name_str[] = mk_lang_stringify(mk_lib_crypto_hash_block_md5_name_def);
mk_lang_constexpr_static_inline int const mk_lib_crypto_hash_block_md5_name_str_len = ((int)(sizeof(mk_lib_crypto_hash_block_md5_name_str) - 1));


union mk_lib_crypto_hash_block_md5_aligned64_u
{
	mk_sl_cui_uint8_t m_uint8s[64];
	mk_sl_cui_uint32_t m_align;
};
typedef union mk_lib_crypto_hash_block_md5_aligned64_u mk_lib_crypto_hash_block_md5_aligned64_t;
typedef mk_lib_crypto_hash_block_md5_aligned64_t const mk_lib_crypto_hash_block_md5_aligned64_ct;
typedef mk_lib_crypto_hash_block_md5_aligned64_t* mk_lib_crypto_hash_block_md5_aligned64_pt;
typedef mk_lib_crypto_hash_block_md5_aligned64_t const* mk_lib_crypto_hash_block_md5_aligned64_pct;

union mk_lib_crypto_hash_block_md5_aligned16_u
{
	mk_sl_cui_uint8_t m_uint8s[16];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_md5_aligned16_u mk_lib_crypto_hash_block_md5_aligned16_t;
typedef mk_lib_crypto_hash_block_md5_aligned16_t const mk_lib_crypto_hash_block_md5_aligned16_ct;
typedef mk_lib_crypto_hash_block_md5_aligned16_t* mk_lib_crypto_hash_block_md5_aligned16_pt;
typedef mk_lib_crypto_hash_block_md5_aligned16_t const* mk_lib_crypto_hash_block_md5_aligned16_pct;


struct mk_lib_crypto_hash_block_md5_s
{
	mk_sl_cui_uint32_t m_state[4];
	mk_sl_cui_uint64_t m_len;
};
typedef struct mk_lib_crypto_hash_block_md5_s mk_lib_crypto_hash_block_md5_t;
typedef mk_lib_crypto_hash_block_md5_t const mk_lib_crypto_hash_block_md5_ct;
typedef mk_lib_crypto_hash_block_md5_t* mk_lib_crypto_hash_block_md5_pt;
typedef mk_lib_crypto_hash_block_md5_t const* mk_lib_crypto_hash_block_md5_pct;

typedef mk_lib_crypto_hash_block_md5_aligned64_t mk_lib_crypto_hash_block_md5_block_t;
typedef mk_lib_crypto_hash_block_md5_block_t const mk_lib_crypto_hash_block_md5_block_ct;
typedef mk_lib_crypto_hash_block_md5_block_t* mk_lib_crypto_hash_block_md5_block_pt;
typedef mk_lib_crypto_hash_block_md5_block_t const* mk_lib_crypto_hash_block_md5_block_pct;

typedef mk_lib_crypto_hash_block_md5_aligned16_t mk_lib_crypto_hash_block_md5_digest_t;
typedef mk_lib_crypto_hash_block_md5_digest_t const mk_lib_crypto_hash_block_md5_digest_ct;
typedef mk_lib_crypto_hash_block_md5_digest_t* mk_lib_crypto_hash_block_md5_digest_pt;
typedef mk_lib_crypto_hash_block_md5_digest_t const* mk_lib_crypto_hash_block_md5_digest_pct;

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_md5_init(mk_lib_crypto_hash_block_md5_pt const md5) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_md5_append_blocks(mk_lib_crypto_hash_block_md5_pt const md5, mk_lib_crypto_hash_block_md5_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_md5_finish(mk_lib_crypto_hash_block_md5_pt const md5, mk_lib_crypto_hash_block_md5_block_pt const block, int const idx, mk_lib_crypto_hash_block_md5_digest_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_block_md5.c"
#endif
#endif
