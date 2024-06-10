#ifndef mk_include_guard_mk_lib_crypto_hash_block_whirlpool
#define mk_include_guard_mk_lib_crypto_hash_block_whirlpool


/* http://www.larc.usp.br/~pbarreto/WhirlpoolPage.html */
/* http://www.larc.usp.br/~pbarreto/whirlpool.zip */


#include "mk_lang_alignas.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"

#define mk_sl_cui_t_name mk_lib_crypto_hash_block_whirlpool_uint256
#define mk_sl_cui_t_base mk_sl_cui_uint64
#define mk_sl_cui_t_count 4
#include "mk_sl_cui_inl_fileh.h"
#undef mk_sl_cui_t_name
#undef mk_sl_cui_t_base
#undef mk_sl_cui_t_count


#define mk_lib_crypto_hash_block_whirlpool_block_len 64
#define mk_lib_crypto_hash_block_whirlpool_digest_len 64
#define mk_lib_crypto_hash_block_whirlpool_name_def Whirlpool
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_crypto_hash_block_whirlpool_name_str[] = mk_lang_stringify(mk_lib_crypto_hash_block_whirlpool_name_def);
mk_lang_constexpr_static_inline mk_lang_types_sint_t const mk_lib_crypto_hash_block_whirlpool_name_str_len = ((mk_lang_types_sint_t)(sizeof(mk_lib_crypto_hash_block_whirlpool_name_str) - 1));


union mk_lib_crypto_hash_block_whirlpool_aligned64_u
{
	mk_lang_alignas(64) mk_sl_cui_uint8_t m_uint8s[64];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_whirlpool_aligned64_u mk_lib_crypto_hash_block_whirlpool_aligned64_t;
typedef mk_lib_crypto_hash_block_whirlpool_aligned64_t const mk_lib_crypto_hash_block_whirlpool_aligned64_ct;
typedef mk_lib_crypto_hash_block_whirlpool_aligned64_t* mk_lib_crypto_hash_block_whirlpool_aligned64_pt;
typedef mk_lib_crypto_hash_block_whirlpool_aligned64_t const* mk_lib_crypto_hash_block_whirlpool_aligned64_pct;


union mk_lib_crypto_hash_block_whirlpool_state_data_u
{
	mk_lang_alignas(64) mk_sl_cui_uint64_t m_uint64s[8];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_whirlpool_state_data_u mk_lib_crypto_hash_block_whirlpool_state_data_t;

struct mk_lib_crypto_hash_block_whirlpool_state_s
{
	mk_lib_crypto_hash_block_whirlpool_state_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_whirlpool_state_s mk_lib_crypto_hash_block_whirlpool_state_t;
typedef mk_lib_crypto_hash_block_whirlpool_state_t const mk_lib_crypto_hash_block_whirlpool_state_ct;
typedef mk_lib_crypto_hash_block_whirlpool_state_t* mk_lib_crypto_hash_block_whirlpool_state_pt;
typedef mk_lib_crypto_hash_block_whirlpool_state_t const* mk_lib_crypto_hash_block_whirlpool_state_pct;


struct mk_lib_crypto_hash_block_whirlpool_s
{
	mk_lib_crypto_hash_block_whirlpool_state_t m_state;
	mk_lib_crypto_hash_block_whirlpool_uint256_t m_len;
};
typedef struct mk_lib_crypto_hash_block_whirlpool_s mk_lib_crypto_hash_block_whirlpool_t;
typedef mk_lib_crypto_hash_block_whirlpool_t const mk_lib_crypto_hash_block_whirlpool_ct;
typedef mk_lib_crypto_hash_block_whirlpool_t* mk_lib_crypto_hash_block_whirlpool_pt;
typedef mk_lib_crypto_hash_block_whirlpool_t const* mk_lib_crypto_hash_block_whirlpool_pct;

typedef mk_lib_crypto_hash_block_whirlpool_aligned64_t mk_lib_crypto_hash_block_whirlpool_block_t;
typedef mk_lib_crypto_hash_block_whirlpool_block_t const mk_lib_crypto_hash_block_whirlpool_block_ct;
typedef mk_lib_crypto_hash_block_whirlpool_block_t* mk_lib_crypto_hash_block_whirlpool_block_pt;
typedef mk_lib_crypto_hash_block_whirlpool_block_t const* mk_lib_crypto_hash_block_whirlpool_block_pct;

typedef mk_lib_crypto_hash_block_whirlpool_aligned64_t mk_lib_crypto_hash_block_whirlpool_digest_t;
typedef mk_lib_crypto_hash_block_whirlpool_digest_t const mk_lib_crypto_hash_block_whirlpool_digest_ct;
typedef mk_lib_crypto_hash_block_whirlpool_digest_t* mk_lib_crypto_hash_block_whirlpool_digest_pt;
typedef mk_lib_crypto_hash_block_whirlpool_digest_t const* mk_lib_crypto_hash_block_whirlpool_digest_pct;

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_whirlpool_init(mk_lib_crypto_hash_block_whirlpool_pt const whirlpool) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_whirlpool_append_blocks(mk_lib_crypto_hash_block_whirlpool_pt const whirlpool, mk_lib_crypto_hash_block_whirlpool_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_whirlpool_finish(mk_lib_crypto_hash_block_whirlpool_pt const whirlpool, mk_lib_crypto_hash_block_whirlpool_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_whirlpool_digest_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_block_whirlpool.c"
#endif
#endif
