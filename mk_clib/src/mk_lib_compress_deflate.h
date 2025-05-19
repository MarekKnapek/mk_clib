#ifndef mk_include_guard_mk_lib_compress_deflate_h
#define mk_include_guard_mk_lib_compress_deflate_h


#include "mk_lang_alignas.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint8.h"


enum mk_lib_compress_deflate_block_non_compressed_header_len_e{ mk_lib_compress_deflate_block_non_compressed_header_len_v = mk_sl_cui_uint8_size_bytes_v + mk_sl_cui_uint16_size_bytes_v + mk_sl_cui_uint16_size_bytes_v }; typedef enum mk_lib_compress_deflate_block_non_compressed_header_len_e mk_lib_compress_deflate_block_non_compressed_header_len_t;
enum mk_lib_compress_deflate_uncompressed_data_len_max_e{ mk_lib_compress_deflate_uncompressed_data_len_max_v = 16 * 1024 }; typedef enum mk_lib_compress_deflate_uncompressed_data_len_max_e mk_lib_compress_deflate_uncompressed_data_len_max_t;


union mk_lib_compress_deflate_buf_data_u
{
	mk_lang_alignas(1024) mk_sl_cui_uint8_t m_u8s[mk_lib_compress_deflate_uncompressed_data_len_max_v];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_compress_deflate_buf_data_u mk_lib_compress_deflate_buf_data_t;
struct mk_lib_compress_deflate_buf_s
{
	mk_lib_compress_deflate_buf_data_t m_data;
};
typedef struct mk_lib_compress_deflate_buf_s mk_lib_compress_deflate_buf_t;
mk_lang_typedef(mk_lib_compress_deflate_buf);


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_compress_deflate_s
{
	mk_lib_compress_deflate_buf_t m_uncompressed_data_buf;
	mk_lang_types_sint_t m_uncompressed_data_idx;
	mk_lang_types_sint_t m_uncompressed_data_beg;
	mk_sl_cui_uint8_t m_block_header_buf[mk_lib_compress_deflate_block_non_compressed_header_len_v];
	mk_lang_types_sint_t m_block_header_beg;
	mk_lang_types_bool_t m_block_header_computed;
	mk_lang_types_bool_t m_finish_requested;
	mk_lang_types_bool_t m_finished;
};
typedef struct mk_lib_compress_deflate_s mk_lib_compress_deflate_t;
mk_lang_typedef(mk_lib_compress_deflate);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_compress_deflate_init(mk_lib_compress_deflate_pt const deflate) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_compress_deflate_append(mk_lib_compress_deflate_pt const deflate, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_compress_deflate_finish(mk_lib_compress_deflate_pt const deflate, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_compress_deflate.c"
#endif
#endif
