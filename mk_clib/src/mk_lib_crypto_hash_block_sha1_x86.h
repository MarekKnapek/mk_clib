#ifndef mk_include_guard_mk_lib_crypto_hash_block_sha1_x86_h
#define mk_include_guard_mk_lib_crypto_hash_block_sha1_x86_h

/* NIST FIPS PUB 180-1 */
/* NIST FIPS PUB 180-2 */
/* NIST FIPS PUB 180-3 */
/* NIST FIPS PUB 180-4 */

#include "mk_lang_alignas.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_pow2.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"


#define mk_lib_crypto_hash_block_sha1_x86_block_len_d 64
#define mk_lib_crypto_hash_block_sha1_x86_digest_len_d 20
#define mk_lib_crypto_hash_block_sha1_x86_name_def SHA-1
enum mk_lib_crypto_hash_block_sha1_x86_block_len_e{ mk_lib_crypto_hash_block_sha1_x86_block_len_v = mk_lib_crypto_hash_block_sha1_x86_block_len_d }; typedef enum mk_lib_crypto_hash_block_sha1_x86_block_len_e mk_lib_crypto_hash_block_sha1_x86_block_len_t;
enum mk_lib_crypto_hash_block_sha1_x86_digest_len_e{ mk_lib_crypto_hash_block_sha1_x86_digest_len_v = mk_lib_crypto_hash_block_sha1_x86_digest_len_d }; typedef enum mk_lib_crypto_hash_block_sha1_x86_digest_len_e mk_lib_crypto_hash_block_sha1_x86_digest_len_t;
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_crypto_hash_block_sha1_x86_name_str_buf[] = mk_lang_stringify(mk_lib_crypto_hash_block_sha1_x86_name_def);
mk_lang_constexpr_static_inline mk_lang_types_sint_t const mk_lib_crypto_hash_block_sha1_x86_name_str_len = mk_lang_countstr(mk_lib_crypto_hash_block_sha1_x86_name_str_buf);


union mk_lib_crypto_hash_block_sha1_x86_block_data_u
{
	mk_lang_alignas(mk_lib_crypto_hash_block_sha1_x86_block_len_v) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_hash_block_sha1_x86_block_len_v];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_sha1_x86_block_data_u mk_lib_crypto_hash_block_sha1_x86_block_data_t;
struct mk_lib_crypto_hash_block_sha1_x86_block_s
{
	mk_lib_crypto_hash_block_sha1_x86_block_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_sha1_x86_block_s mk_lib_crypto_hash_block_sha1_x86_block_t;
typedef mk_lib_crypto_hash_block_sha1_x86_block_t const mk_lib_crypto_hash_block_sha1_x86_block_ct;
typedef mk_lib_crypto_hash_block_sha1_x86_block_t* mk_lib_crypto_hash_block_sha1_x86_block_pt;
typedef mk_lib_crypto_hash_block_sha1_x86_block_t const* mk_lib_crypto_hash_block_sha1_x86_block_pct;

union mk_lib_crypto_hash_block_sha1_x86_digest_data_u
{
	mk_lang_alignas(mk_lang_pow2_roundup(mk_lib_crypto_hash_block_sha1_x86_digest_len_v)) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_hash_block_sha1_x86_digest_len_v];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_sha1_x86_digest_data_u mk_lib_crypto_hash_block_sha1_x86_digest_data_t;
struct mk_lib_crypto_hash_block_sha1_x86_digest_s
{
	mk_lib_crypto_hash_block_sha1_x86_digest_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_sha1_x86_digest_s mk_lib_crypto_hash_block_sha1_x86_digest_t;
typedef mk_lib_crypto_hash_block_sha1_x86_digest_t const mk_lib_crypto_hash_block_sha1_x86_digest_ct;
typedef mk_lib_crypto_hash_block_sha1_x86_digest_t* mk_lib_crypto_hash_block_sha1_x86_digest_pt;
typedef mk_lib_crypto_hash_block_sha1_x86_digest_t const* mk_lib_crypto_hash_block_sha1_x86_digest_pct;


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_crypto_hash_block_sha1_x86_s
{
	mk_sl_cui_uint32_t m_state[5];
	mk_sl_cui_uint64_t m_len;
};
typedef struct mk_lib_crypto_hash_block_sha1_x86_s mk_lib_crypto_hash_block_sha1_x86_t;
typedef mk_lib_crypto_hash_block_sha1_x86_t const mk_lib_crypto_hash_block_sha1_x86_ct;
typedef mk_lib_crypto_hash_block_sha1_x86_t* mk_lib_crypto_hash_block_sha1_x86_pt;
typedef mk_lib_crypto_hash_block_sha1_x86_t const* mk_lib_crypto_hash_block_sha1_x86_pct;
#include "mk_lang_warning_msvc_pop.h"


mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha1_x86_init(mk_lib_crypto_hash_block_sha1_x86_pt const sha1_x86) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha1_x86_append_blocks(mk_lib_crypto_hash_block_sha1_x86_pt const sha1_x86, mk_lib_crypto_hash_block_sha1_x86_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha1_x86_finish(mk_lib_crypto_hash_block_sha1_x86_pt const sha1_x86, mk_lib_crypto_hash_block_sha1_x86_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_sha1_x86_digest_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_have == 1
#include "mk_lib_crypto_hash_block_sha1_x86.c"
#endif
#endif
