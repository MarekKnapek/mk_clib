#ifndef mk_include_guard_mk_lib_crypto_hash_block_sha3
#define mk_include_guard_mk_lib_crypto_hash_block_sha3


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_sl_uint64.h"


union mk_lib_crypto_hash_block_sha3_aligned200_u
{
	mk_sl_cui_uint64_t m_uint64s[25];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_hash_block_sha3_aligned200_u mk_lib_crypto_hash_block_sha3_aligned200_t;

typedef mk_lib_crypto_hash_block_sha3_aligned200_t mk_lib_crypto_hash_block_sha3_state_t;
typedef mk_lib_crypto_hash_block_sha3_state_t const mk_lib_crypto_hash_block_sha3_state_ct;
typedef mk_lib_crypto_hash_block_sha3_state_t* mk_lib_crypto_hash_block_sha3_state_pt;
typedef mk_lib_crypto_hash_block_sha3_state_t* mk_lang_restrict mk_lib_crypto_hash_block_sha3_state_prt;
typedef mk_lib_crypto_hash_block_sha3_state_t const* mk_lib_crypto_hash_block_sha3_state_pct;
typedef mk_lib_crypto_hash_block_sha3_state_t const* mk_lang_restrict mk_lib_crypto_hash_block_sha3_state_prct;


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha3_init(mk_lib_crypto_hash_block_sha3_state_prt const state) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_sha3_f(mk_lib_crypto_hash_block_sha3_state_prt const state) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_block_sha3.c"
#endif
#endif
