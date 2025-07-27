#ifndef mk_include_guard_mk_lib_hash_crc32_windows_h
#define mk_include_guard_mk_lib_hash_crc32_windows_h


#include "mk_lang_jumbo.h"
#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any


#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"
#include "mk_win_base.h"


#define mk_lib_hash_crc32_windows_digest_len_d 4
enum mk_lib_hash_crc32_windows_digest_len_e{ mk_lib_hash_crc32_windows_digest_len_v = mk_lib_hash_crc32_windows_digest_len_d }; typedef enum mk_lib_hash_crc32_windows_digest_len_e mk_lib_hash_crc32_windows_digest_len_t;


union mk_lib_hash_crc32_windows_digest_data_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_hash_crc32_windows_digest_len_v];
	mk_win_base_dword_t m_align;
};
typedef union mk_lib_hash_crc32_windows_digest_data_u mk_lib_hash_crc32_windows_digest_data_t;
struct mk_lib_hash_crc32_windows_digest_s
{
	mk_lib_hash_crc32_windows_digest_data_t m_data;
};
typedef struct mk_lib_hash_crc32_windows_digest_s mk_lib_hash_crc32_windows_digest_t;
mk_lang_typedef(mk_lib_hash_crc32_windows_digest);


struct mk_lib_hash_crc32_windows_s
{
	mk_win_base_dword_t m_state;
};
typedef struct mk_lib_hash_crc32_windows_s mk_lib_hash_crc32_windows_t;
mk_lang_typedef(mk_lib_hash_crc32_windows);


mk_lang_jumbo mk_lang_types_void_t mk_lib_hash_crc32_windows_init(mk_lib_hash_crc32_windows_pt const crc32) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_lib_hash_crc32_windows_append(mk_lib_hash_crc32_windows_pt const crc32, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_usize_t const data_len) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_lib_hash_crc32_windows_finish(mk_lib_hash_crc32_windows_pt const crc32, mk_lib_hash_crc32_windows_digest_pt const digest) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_lib_hash_crc32_windows.c"
#endif
#endif
