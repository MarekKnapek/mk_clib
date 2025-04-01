#ifndef mk_include_guard_mk_lib_wasm_hasher_h
#define mk_include_guard_mk_lib_wasm_hasher_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_roundup.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_any2.h"
#include "mk_lib_crypto_xof_stream_any2.h"
#include "mk_sl_cui_uint8.h"


#define mk_lib_wasm_hasher_buffer_size (1 * 1024 * 1024)
#define mk_lib_wasm_hasher_buffer_algn (64 * 1024)
union mk_lib_wasm_hasher_buffer_data_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lang_roundup_add(mk_lib_wasm_hasher_buffer_size, mk_lib_wasm_hasher_buffer_algn)];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_wasm_hasher_buffer_data_u mk_lib_wasm_hasher_buffer_data_t;
struct mk_lib_wasm_hasher_buffer_s
{
	mk_lib_wasm_hasher_buffer_data_t m_data;
};
typedef struct mk_lib_wasm_hasher_buffer_s mk_lib_wasm_hasher_buffer_t;

union mk_lib_wasm_hasher_worker_data_u
{
	mk_lib_crypto_hash_stream_any2_t m_hasher;
	mk_lib_crypto_xof_stream_any2_t m_xofer;
};
typedef union mk_lib_wasm_hasher_worker_data_u mk_lib_wasm_hasher_worker_data_t;
struct mk_lib_wasm_hasher_worker_s
{
	mk_lib_wasm_hasher_worker_data_t m_data;
};
typedef struct mk_lib_wasm_hasher_worker_s mk_lib_wasm_hasher_worker_t;


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_wasm_hasher_s
{
	mk_lang_types_bool_t m_is_xofer;
	mk_lib_wasm_hasher_worker_t m_worker;
	mk_lib_wasm_hasher_buffer_t m_buffer;
};
typedef struct mk_lib_wasm_hasher_s mk_lib_wasm_hasher_t;
mk_lang_typedef(mk_lib_wasm_hasher);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_buffer_buf(mk_lib_wasm_hasher_pt const hasher) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_buffer_len(mk_lib_wasm_hasher_pt const hasher) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_alg_count(mk_lib_wasm_hasher_pt const hasher) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_default_alg(mk_lib_wasm_hasher_pt const hasher) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_alg_str_buf(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const idx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_alg_str_len(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const idx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_digest_len(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const idx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_init(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const idx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_append(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const count) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_finish(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const xof_len) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_wasm_hasher.c"
#endif
#endif
