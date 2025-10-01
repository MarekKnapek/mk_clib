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
#include "mk_sl_speedometer.h"


#define mk_lib_wasm_hasher_buffer_size (64 * 1024)
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

#include "mk_lang_warning_msvc_push_c4820.h"
union mk_lib_wasm_hasher_message_data_u
{
	mk_lang_types_pchar_t m_pchars[256];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_wasm_hasher_message_data_u mk_lib_wasm_hasher_message_data_t;
struct mk_lib_wasm_hasher_message_s
{
	mk_lib_wasm_hasher_message_data_t m_data;
	mk_lang_types_sint_t m_len;
};
typedef struct mk_lib_wasm_hasher_message_s mk_lib_wasm_hasher_message_t;
#include "mk_lang_warning_msvc_pop.h"

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
	mk_sl_speedometer_t m_speedometer;
	mk_lib_wasm_hasher_message_t m_message;
	mk_lib_wasm_hasher_buffer_t m_buffer;
};
typedef struct mk_lib_wasm_hasher_s mk_lib_wasm_hasher_t;
mk_lang_typedef(mk_lib_wasm_hasher);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_main(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const fnc, mk_lang_types_uintptr_t const arg) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_wasm_hasher.c"
#endif
#endif
