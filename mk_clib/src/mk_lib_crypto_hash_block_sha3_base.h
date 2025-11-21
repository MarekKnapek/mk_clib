#ifndef mk_include_guard_mk_lib_crypto_hash_block_sha3_base_h
#define mk_include_guard_mk_lib_crypto_hash_block_sha3_base_h


#include "mk_lang_alignas.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_pow2.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint64.h"


#include "mk_lang_warning_msvc_push_c4820.h"
union mk_lib_crypto_hash_block_sha3_base_data_u
{
	mk_sl_cui_uint64_t m_uint64s[25];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_hash_block_sha3_base_data_u mk_lib_crypto_hash_block_sha3_base_data_t;
struct mk_lib_crypto_hash_block_sha3_base_s
{
	mk_lib_crypto_hash_block_sha3_base_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_sha3_base_s mk_lib_crypto_hash_block_sha3_base_t;
mk_lang_typedef(mk_lib_crypto_hash_block_sha3_base);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha3_base_init(mk_lib_crypto_hash_block_sha3_base_pt const sha3_base) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha3_base_f(mk_lib_crypto_hash_block_sha3_base_pt const sha3_base) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_sha3_base_f_turbo(mk_lib_crypto_hash_block_sha3_base_pt const sha3_base) mk_lang_noexcept;


#if mk_lang_jumbo_have == 1
#include "mk_lib_crypto_hash_block_sha3_base.c"
#endif
#endif
