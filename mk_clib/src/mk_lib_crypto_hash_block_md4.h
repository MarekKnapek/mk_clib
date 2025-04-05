#ifndef mk_include_guard_mk_lib_crypto_hash_block_md4_h
#define mk_include_guard_mk_lib_crypto_hash_block_md4_h

/* RFC 1186 */
/* RFC 1320 */

#include "mk_lang_alignas.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"


#define mk_lib_crypto_hash_block_md4_block_len_d 64
#define mk_lib_crypto_hash_block_md4_digest_len_d 16
#define mk_lib_crypto_hash_block_md4_name_def MD4
enum mk_lib_crypto_hash_block_md4_block_len_e{ mk_lib_crypto_hash_block_md4_block_len_v = mk_lib_crypto_hash_block_md4_block_len_d }; typedef enum mk_lib_crypto_hash_block_md4_block_len_e mk_lib_crypto_hash_block_md4_block_len_t;
enum mk_lib_crypto_hash_block_md4_digest_len_e{ mk_lib_crypto_hash_block_md4_digest_len_v = mk_lib_crypto_hash_block_md4_digest_len_d }; typedef enum mk_lib_crypto_hash_block_md4_digest_len_e mk_lib_crypto_hash_block_md4_digest_len_t;
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_crypto_hash_block_md4_name_str_buf[] = mk_lang_stringify(mk_lib_crypto_hash_block_md4_name_def);
mk_lang_constexpr_static_inline mk_lang_types_sint_t const mk_lib_crypto_hash_block_md4_name_str_len = mk_lang_countstr(mk_lib_crypto_hash_block_md4_name_str_buf);


union mk_lib_crypto_hash_block_md4_block_data_u
{
	mk_lang_alignas(mk_lib_crypto_hash_block_md4_block_len_v) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_hash_block_md4_block_len_v];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_md4_block_data_u mk_lib_crypto_hash_block_md4_block_data_t;
struct mk_lib_crypto_hash_block_md4_block_s
{
	mk_lib_crypto_hash_block_md4_block_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_md4_block_s mk_lib_crypto_hash_block_md4_block_t;
typedef mk_lib_crypto_hash_block_md4_block_t const mk_lib_crypto_hash_block_md4_block_ct;
typedef mk_lib_crypto_hash_block_md4_block_t* mk_lib_crypto_hash_block_md4_block_pt;
typedef mk_lib_crypto_hash_block_md4_block_t const* mk_lib_crypto_hash_block_md4_block_pct;

union mk_lib_crypto_hash_block_md4_digest_data_u
{
	mk_lang_alignas(mk_lib_crypto_hash_block_md4_digest_len_v) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_hash_block_md4_digest_len_v];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_md4_digest_data_u mk_lib_crypto_hash_block_md4_digest_data_t;
struct mk_lib_crypto_hash_block_md4_digest_s
{
	mk_lib_crypto_hash_block_md4_digest_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_md4_digest_s mk_lib_crypto_hash_block_md4_digest_t;
typedef mk_lib_crypto_hash_block_md4_digest_t const mk_lib_crypto_hash_block_md4_digest_ct;
typedef mk_lib_crypto_hash_block_md4_digest_t* mk_lib_crypto_hash_block_md4_digest_pt;
typedef mk_lib_crypto_hash_block_md4_digest_t const* mk_lib_crypto_hash_block_md4_digest_pct;


struct mk_lib_crypto_hash_block_md4_s
{
	mk_sl_cui_uint32_t m_state[4];
	mk_sl_cui_uint64_t m_len;
};
typedef struct mk_lib_crypto_hash_block_md4_s mk_lib_crypto_hash_block_md4_t;
typedef mk_lib_crypto_hash_block_md4_t const mk_lib_crypto_hash_block_md4_ct;
typedef mk_lib_crypto_hash_block_md4_t* mk_lib_crypto_hash_block_md4_pt;
typedef mk_lib_crypto_hash_block_md4_t const* mk_lib_crypto_hash_block_md4_pct;


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_md4_init(mk_lib_crypto_hash_block_md4_pt const md4) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_md4_append_blocks(mk_lib_crypto_hash_block_md4_pt const md4, mk_lib_crypto_hash_block_md4_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_md4_finish(mk_lib_crypto_hash_block_md4_pt const md4, mk_lib_crypto_hash_block_md4_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_md4_digest_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_have == 1
#include "mk_lib_crypto_hash_block_md4.c"
#endif
#endif
