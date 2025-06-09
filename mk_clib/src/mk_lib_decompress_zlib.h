#ifndef mk_include_guard_mk_lib_decompress_zlib_h
#define mk_include_guard_mk_lib_decompress_zlib_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_decompress_deflate.h"
#include "mk_lib_hash_adler32.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"


enum mk_lib_decompress_zlib_header_len_e{ mk_lib_decompress_zlib_header_len_v = mk_sl_cui_uint8_size_bytes_v + mk_sl_cui_uint8_size_bytes_v }; typedef enum mk_lib_decompress_zlib_header_len_e mk_lib_decompress_zlib_header_len_t;


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_decompress_zlib_s
{
	mk_sl_cui_uint8_t m_stream_header_buf[mk_lib_decompress_zlib_header_len_v];
	mk_lang_types_sint_t m_stream_header_idx;
	mk_lang_types_bool_t m_stream_header_processed;
	mk_lib_decompress_deflate_t m_deflate;
	mk_lib_hash_adler32_t m_adler32;
	mk_sl_cui_uint8_t m_stream_footer_buf[mk_sl_cui_uint32_size_bytes_v];
	mk_lang_types_sint_t m_stream_footer_idx;
	mk_lang_types_bool_t m_done;
};
typedef struct mk_lib_decompress_zlib_s mk_lib_decompress_zlib_t;
mk_lang_typedef(mk_lib_decompress_zlib);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_decompress_zlib_init(mk_lib_decompress_zlib_pt const zlib) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_decompress_zlib_append(mk_lib_decompress_zlib_pt const zlib, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pt const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_in_consumed, mk_lang_types_sint_pt const data_out_consumed) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_decompress_zlib.c"
#endif
#endif
