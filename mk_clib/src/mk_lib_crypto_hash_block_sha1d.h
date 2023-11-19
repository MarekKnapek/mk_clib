#ifndef mk_include_guard_mk_lib_crypto_hash_block_sha1d
#define mk_include_guard_mk_lib_crypto_hash_block_sha1d


/* nist fips pub 180-1 */
/* nist fips pub 180-2 */
/* nist fips pub 180-3 */
/* nist fips pub 180-4 */


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_sha1.h"
#include "mk_lib_crypto_hash_block_sha1x86.h"


#define mk_lib_crypto_hash_block_sha1d_block_len 64
#define mk_lib_crypto_hash_block_sha1d_digest_len 20
#define mk_lib_crypto_hash_block_sha1d_name_def SHA-1
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_crypto_hash_block_sha1d_name_str[] = mk_lang_stringify(mk_lib_crypto_hash_block_sha1d_name_def);
mk_lang_constexpr_static_inline mk_lang_types_sint_t const mk_lib_crypto_hash_block_sha1d_name_str_len = ((mk_lang_types_sint_t)(sizeof(mk_lib_crypto_hash_block_sha1d_name_str) - 1));


union mk_lib_crypto_hash_block_sha1d_data_u
{
	mk_lib_crypto_hash_block_sha1_t m_sha1;
	mk_lib_crypto_hash_block_sha1x86_t m_sha1x86;
};
typedef union mk_lib_crypto_hash_block_sha1d_data_u mk_lib_crypto_hash_block_sha1d_data_t;


struct mk_lib_crypto_hash_block_sha1d_s
{
	mk_lib_crypto_hash_block_sha1d_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_sha1d_s mk_lib_crypto_hash_block_sha1d_t;
typedef mk_lib_crypto_hash_block_sha1d_t const mk_lib_crypto_hash_block_sha1d_ct;
typedef mk_lib_crypto_hash_block_sha1d_t* mk_lib_crypto_hash_block_sha1d_pt;
typedef mk_lib_crypto_hash_block_sha1d_t const* mk_lib_crypto_hash_block_sha1d_pct;

typedef mk_lib_crypto_hash_block_sha1_block_t mk_lib_crypto_hash_block_sha1d_block_t;
typedef mk_lib_crypto_hash_block_sha1d_block_t const mk_lib_crypto_hash_block_sha1d_block_ct;
typedef mk_lib_crypto_hash_block_sha1d_block_t* mk_lib_crypto_hash_block_sha1d_block_pt;
typedef mk_lib_crypto_hash_block_sha1d_block_t const* mk_lib_crypto_hash_block_sha1d_block_pct;

typedef mk_lib_crypto_hash_block_sha1_digest_t mk_lib_crypto_hash_block_sha1d_digest_t;
typedef mk_lib_crypto_hash_block_sha1d_digest_t const mk_lib_crypto_hash_block_sha1d_digest_ct;
typedef mk_lib_crypto_hash_block_sha1d_digest_t* mk_lib_crypto_hash_block_sha1d_digest_pt;
typedef mk_lib_crypto_hash_block_sha1d_digest_t const* mk_lib_crypto_hash_block_sha1d_digest_pct;

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha1d_init(mk_lib_crypto_hash_block_sha1d_pt const sha1) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha1d_append_blocks(mk_lib_crypto_hash_block_sha1d_pt const sha1, mk_lib_crypto_hash_block_sha1d_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha1d_finish(mk_lib_crypto_hash_block_sha1d_pt const sha1, mk_lib_crypto_hash_block_sha1d_block_pt const block, int const idx, mk_lib_crypto_hash_block_sha1d_digest_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_block_sha1d.c"
#endif
#endif
