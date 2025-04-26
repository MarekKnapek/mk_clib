#ifndef mk_include_guard_mk_lib_crypto_hash_block_md2_h
#define mk_include_guard_mk_lib_crypto_hash_block_md2_h

/* RFC 1115 */
/* RFC 1319 */

#include "mk_lang_alignas.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


#define mk_lib_crypto_hash_block_md2_block_len_d 16
#define mk_lib_crypto_hash_block_md2_digest_len_d 16
#define mk_lib_crypto_hash_block_md2_name_def MD2
enum mk_lib_crypto_hash_block_md2_block_len_e{ mk_lib_crypto_hash_block_md2_block_len_v = mk_lib_crypto_hash_block_md2_block_len_d }; typedef enum mk_lib_crypto_hash_block_md2_block_len_e mk_lib_crypto_hash_block_md2_block_len_t;
enum mk_lib_crypto_hash_block_md2_digest_len_e{ mk_lib_crypto_hash_block_md2_digest_len_v = mk_lib_crypto_hash_block_md2_digest_len_d }; typedef enum mk_lib_crypto_hash_block_md2_digest_len_e mk_lib_crypto_hash_block_md2_digest_len_t;
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_crypto_hash_block_md2_name_str_buf[] = mk_lang_stringify(mk_lib_crypto_hash_block_md2_name_def);
mk_lang_constexpr_static_inline mk_lang_types_sint_t const mk_lib_crypto_hash_block_md2_name_str_len = mk_lang_countstr(mk_lib_crypto_hash_block_md2_name_str_buf);


union mk_lib_crypto_hash_block_md2_block_data_u
{
	mk_lang_alignas(mk_lib_crypto_hash_block_md2_block_len_v) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_hash_block_md2_block_len_v];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_md2_block_data_u mk_lib_crypto_hash_block_md2_block_data_t;
struct mk_lib_crypto_hash_block_md2_block_s
{
	mk_lib_crypto_hash_block_md2_block_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_md2_block_s mk_lib_crypto_hash_block_md2_block_t;
typedef mk_lib_crypto_hash_block_md2_block_t const mk_lib_crypto_hash_block_md2_block_ct;
typedef mk_lib_crypto_hash_block_md2_block_t* mk_lib_crypto_hash_block_md2_block_pt;
typedef mk_lib_crypto_hash_block_md2_block_t const* mk_lib_crypto_hash_block_md2_block_pct;

union mk_lib_crypto_hash_block_md2_digest_data_u
{
	mk_lang_alignas(mk_lib_crypto_hash_block_md2_digest_len_v) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_hash_block_md2_digest_len_v];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_md2_digest_data_u mk_lib_crypto_hash_block_md2_digest_data_t;
struct mk_lib_crypto_hash_block_md2_digest_s
{
	mk_lib_crypto_hash_block_md2_digest_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_md2_digest_s mk_lib_crypto_hash_block_md2_digest_t;
typedef mk_lib_crypto_hash_block_md2_digest_t const mk_lib_crypto_hash_block_md2_digest_ct;
typedef mk_lib_crypto_hash_block_md2_digest_t* mk_lib_crypto_hash_block_md2_digest_pt;
typedef mk_lib_crypto_hash_block_md2_digest_t const* mk_lib_crypto_hash_block_md2_digest_pct;


struct mk_lib_crypto_hash_block_md2_s
{
	mk_lib_crypto_hash_block_md2_block_t m_state;
	mk_lib_crypto_hash_block_md2_block_t m_checksum;
};
typedef struct mk_lib_crypto_hash_block_md2_s mk_lib_crypto_hash_block_md2_t;
typedef mk_lib_crypto_hash_block_md2_t const mk_lib_crypto_hash_block_md2_ct;
typedef mk_lib_crypto_hash_block_md2_t* mk_lib_crypto_hash_block_md2_pt;
typedef mk_lib_crypto_hash_block_md2_t const* mk_lib_crypto_hash_block_md2_pct;


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_md2_init(mk_lib_crypto_hash_block_md2_pt const md2) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_md2_append_blocks(mk_lib_crypto_hash_block_md2_pt const md2, mk_lib_crypto_hash_block_md2_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_md2_finish(mk_lib_crypto_hash_block_md2_pt const md2, mk_lib_crypto_hash_block_md2_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_md2_digest_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_have == 1
#include "mk_lib_crypto_hash_block_md2.c"
#endif
#endif
