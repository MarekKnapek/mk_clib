#ifndef mk_include_guard_mk_lib_crypto_hash_block_blake3
#define mk_include_guard_mk_lib_crypto_hash_block_blake3


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_hash_block_blake3_block_len 64
#define mk_lib_crypto_hash_block_blake3_digest_len 32
#define mk_lib_crypto_hash_block_blake3_name_def BLAKE3
mk_lang_constexpr_static_inline char const mk_lib_crypto_hash_block_blake3_name_str[] = mk_lang_stringify(mk_lib_crypto_hash_block_blake3_name_def);
mk_lang_constexpr_static_inline int const mk_lib_crypto_hash_block_blake3_name_str_len = ((int)(sizeof(mk_lib_crypto_hash_block_blake3_name_str) - 1));


union mk_lib_crypto_hash_block_blake3_aligned64_u
{
	mk_sl_cui_uint8_t m_uint8s[64];
	mk_sl_cui_uint32_t m_align;
};
typedef union mk_lib_crypto_hash_block_blake3_aligned64_u mk_lib_crypto_hash_block_blake3_aligned64_t;

union mk_lib_crypto_hash_block_blake3_aligned32_u
{
	mk_sl_cui_uint8_t m_uint8s[32];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_blake3_aligned32_u mk_lib_crypto_hash_block_blake3_aligned32_t;

union mk_lib_crypto_hash_block_blake3_state_u
{
	mk_sl_cui_uint32_t m_uint32s[8];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_blake3_state_u mk_lib_crypto_hash_block_blake3_state_t;
typedef mk_lib_crypto_hash_block_blake3_state_t const mk_lib_crypto_hash_block_blake3_state_ct;
typedef mk_lib_crypto_hash_block_blake3_state_t* mk_lib_crypto_hash_block_blake3_state_pt;
typedef mk_lib_crypto_hash_block_blake3_state_t const* mk_lib_crypto_hash_block_blake3_state_pct;
typedef mk_lib_crypto_hash_block_blake3_state_t* mk_lang_restrict mk_lib_crypto_hash_block_blake3_state_prt;
typedef mk_lib_crypto_hash_block_blake3_state_t const* mk_lang_restrict mk_lib_crypto_hash_block_blake3_state_prct;

#define mk_lib_crypto_hash_block_blake3_chunk_len 1024
#define mk_lib_crypto_hash_block_blake3_max_msg_len /* 2^64 */
#define mk_lib_crypto_hash_block_blake3_max_depth 54 /* log2(max_msg_len) - log2(chunk_len) */

union mk_lib_crypto_hash_block_blake3_aligned_states_u
{
	mk_lib_crypto_hash_block_blake3_state_t m_states[mk_lib_crypto_hash_block_blake3_max_depth + 1];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_blake3_aligned_states_u mk_lib_crypto_hash_block_blake3_aligned_states_t;
typedef mk_lib_crypto_hash_block_blake3_aligned_states_t const mk_lib_crypto_hash_block_blake3_aligned_states_ct;
typedef mk_lib_crypto_hash_block_blake3_aligned_states_t* mk_lib_crypto_hash_block_blake3_aligned_states_pt;
typedef mk_lib_crypto_hash_block_blake3_aligned_states_t const* mk_lib_crypto_hash_block_blake3_aligned_states_pct;

struct mk_lib_crypto_hash_block_blake3_s
{
	mk_lib_crypto_hash_block_blake3_state_t m_state;
	mk_sl_cui_uint64_t m_chunk_count;
	mk_lang_types_uchar_t m_block_count;
	mk_lang_types_uchar_t m_state_count;
	mk_lib_crypto_hash_block_blake3_aligned_states_t m_states;
};
typedef struct mk_lib_crypto_hash_block_blake3_s mk_lib_crypto_hash_block_blake3_t;
typedef mk_lib_crypto_hash_block_blake3_t const mk_lib_crypto_hash_block_blake3_ct;
typedef mk_lib_crypto_hash_block_blake3_t* mk_lib_crypto_hash_block_blake3_pt;
typedef mk_lib_crypto_hash_block_blake3_t const* mk_lib_crypto_hash_block_blake3_pct;

typedef mk_lib_crypto_hash_block_blake3_aligned64_t mk_lib_crypto_hash_block_blake3_block_t;
typedef mk_lib_crypto_hash_block_blake3_block_t const mk_lib_crypto_hash_block_blake3_block_ct;
typedef mk_lib_crypto_hash_block_blake3_block_t* mk_lib_crypto_hash_block_blake3_block_pt;
typedef mk_lib_crypto_hash_block_blake3_block_t const* mk_lib_crypto_hash_block_blake3_block_pct;
typedef mk_lib_crypto_hash_block_blake3_block_t* mk_lang_restrict mk_lib_crypto_hash_block_blake3_block_prt;
typedef mk_lib_crypto_hash_block_blake3_block_t const* mk_lang_restrict mk_lib_crypto_hash_block_blake3_block_prct;

typedef mk_lib_crypto_hash_block_blake3_aligned32_t mk_lib_crypto_hash_block_blake3_digest_t;
typedef mk_lib_crypto_hash_block_blake3_digest_t const mk_lib_crypto_hash_block_blake3_digest_ct;
typedef mk_lib_crypto_hash_block_blake3_digest_t* mk_lib_crypto_hash_block_blake3_digest_pt;
typedef mk_lib_crypto_hash_block_blake3_digest_t const* mk_lib_crypto_hash_block_blake3_digest_pct;
typedef mk_lib_crypto_hash_block_blake3_digest_t* mk_lang_restrict mk_lib_crypto_hash_block_blake3_digest_prt;
typedef mk_lib_crypto_hash_block_blake3_digest_t const* mk_lang_restrict mk_lib_crypto_hash_block_blake3_digest_prct;

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake3_init(mk_lib_crypto_hash_block_blake3_pt const blake3) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake3_append_blocks(mk_lib_crypto_hash_block_blake3_pt const blake3, mk_lib_crypto_hash_block_blake3_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_blake3_finish(mk_lib_crypto_hash_block_blake3_pt const blake3, mk_lib_crypto_hash_block_blake3_block_pt const block, int const idx, mk_lib_crypto_hash_block_blake3_digest_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_block_blake3.c"
#endif
#endif
