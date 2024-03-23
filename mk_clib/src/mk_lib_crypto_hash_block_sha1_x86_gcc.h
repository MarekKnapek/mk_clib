#ifndef mk_include_guard_mk_lib_crypto_hash_block_sha1_x86_gcc
#define mk_include_guard_mk_lib_crypto_hash_block_sha1_x86_gcc


/* nist fips pub 180-1 */
/* nist fips pub 180-2 */
/* nist fips pub 180-3 */
/* nist fips pub 180-4 */


#include "mk_lang_alignas.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_pow2.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_hash_block_sha1_x86_gcc_block_len 64
#define mk_lib_crypto_hash_block_sha1_x86_gcc_digest_len 20
#define mk_lib_crypto_hash_block_sha1_x86_gcc_name_def SHA-1
mk_lang_constexpr_static_inline char const mk_lib_crypto_hash_block_sha1_x86_gcc_name_str[] = mk_lang_stringify(mk_lib_crypto_hash_block_sha1_x86_gcc_name_def);
mk_lang_constexpr_static_inline int const mk_lib_crypto_hash_block_sha1_x86_gcc_name_str_len = ((int)(sizeof(mk_lib_crypto_hash_block_sha1_x86_gcc_name_str) - 1));


union mk_lib_crypto_hash_block_sha1_x86_gcc_aligned64_u
{
	mk_lang_alignas(64) mk_sl_cui_uint8_t m_uint8s[64];
	mk_sl_cui_uint32_t m_align;
};
typedef union mk_lib_crypto_hash_block_sha1_x86_gcc_aligned64_u mk_lib_crypto_hash_block_sha1_x86_gcc_aligned64_t;
typedef mk_lib_crypto_hash_block_sha1_x86_gcc_aligned64_t const mk_lib_crypto_hash_block_sha1_x86_gcc_aligned64_ct;
typedef mk_lib_crypto_hash_block_sha1_x86_gcc_aligned64_t* mk_lib_crypto_hash_block_sha1_x86_gcc_aligned64_pt;
typedef mk_lib_crypto_hash_block_sha1_x86_gcc_aligned64_t const* mk_lib_crypto_hash_block_sha1_x86_gcc_aligned64_pct;

union mk_lib_crypto_hash_block_sha1_x86_gcc_aligned20_u
{
	mk_lang_alignas(mk_lang_pow2_roundup(20)) mk_sl_cui_uint8_t m_uint8s[20];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_sha1_x86_gcc_aligned20_u mk_lib_crypto_hash_block_sha1_x86_gcc_aligned20_t;
typedef mk_lib_crypto_hash_block_sha1_x86_gcc_aligned20_t const mk_lib_crypto_hash_block_sha1_x86_gcc_aligned20_ct;
typedef mk_lib_crypto_hash_block_sha1_x86_gcc_aligned20_t* mk_lib_crypto_hash_block_sha1_x86_gcc_aligned20_pt;
typedef mk_lib_crypto_hash_block_sha1_x86_gcc_aligned20_t const* mk_lib_crypto_hash_block_sha1_x86_gcc_aligned20_pct;


struct mk_lib_crypto_hash_block_sha1_x86_gcc_s
{
	mk_lang_alignas(16) mk_sl_cui_uint32_t m_state[5];
	mk_sl_cui_uint64_t m_len;
};
typedef struct mk_lib_crypto_hash_block_sha1_x86_gcc_s mk_lib_crypto_hash_block_sha1_x86_gcc_t;
typedef mk_lib_crypto_hash_block_sha1_x86_gcc_t const mk_lib_crypto_hash_block_sha1_x86_gcc_ct;
typedef mk_lib_crypto_hash_block_sha1_x86_gcc_t* mk_lib_crypto_hash_block_sha1_x86_gcc_pt;
typedef mk_lib_crypto_hash_block_sha1_x86_gcc_t const* mk_lib_crypto_hash_block_sha1_x86_gcc_pct;

typedef mk_lib_crypto_hash_block_sha1_x86_gcc_aligned64_t mk_lib_crypto_hash_block_sha1_x86_gcc_block_t;
typedef mk_lib_crypto_hash_block_sha1_x86_gcc_block_t const mk_lib_crypto_hash_block_sha1_x86_gcc_block_ct;
typedef mk_lib_crypto_hash_block_sha1_x86_gcc_block_t* mk_lib_crypto_hash_block_sha1_x86_gcc_block_pt;
typedef mk_lib_crypto_hash_block_sha1_x86_gcc_block_t const* mk_lib_crypto_hash_block_sha1_x86_gcc_block_pct;

typedef mk_lib_crypto_hash_block_sha1_x86_gcc_aligned20_t mk_lib_crypto_hash_block_sha1_x86_gcc_digest_t;
typedef mk_lib_crypto_hash_block_sha1_x86_gcc_digest_t const mk_lib_crypto_hash_block_sha1_x86_gcc_digest_ct;
typedef mk_lib_crypto_hash_block_sha1_x86_gcc_digest_t* mk_lib_crypto_hash_block_sha1_x86_gcc_digest_pt;
typedef mk_lib_crypto_hash_block_sha1_x86_gcc_digest_t const* mk_lib_crypto_hash_block_sha1_x86_gcc_digest_pct;

mk_lang_jumbo void mk_lib_crypto_hash_block_sha1_x86_gcc_init(mk_lib_crypto_hash_block_sha1_x86_gcc_pt const sha1) mk_lang_noexcept;
mk_lang_jumbo void mk_lib_crypto_hash_block_sha1_x86_gcc_append_blocks(mk_lib_crypto_hash_block_sha1_x86_gcc_pt const sha1, mk_lib_crypto_hash_block_sha1_x86_gcc_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_jumbo void mk_lib_crypto_hash_block_sha1_x86_gcc_finish(mk_lib_crypto_hash_block_sha1_x86_gcc_pt const sha1, mk_lib_crypto_hash_block_sha1_x86_gcc_block_pt const block, int const idx, mk_lib_crypto_hash_block_sha1_x86_gcc_digest_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_block_sha1_x86_gcc.c"
#endif
#endif
