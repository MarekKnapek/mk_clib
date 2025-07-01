#ifndef mk_include_guard_mk_lib_zlib_h
#define mk_include_guard_mk_lib_zlib_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_sl_cui_uint8);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_zlib_compress(mk_sl_cui_uint8_pct const src_buf, mk_lang_types_sint_t const src_len, mk_lang_types_sint_t const level, mk_sl_cui_uint8_pt const dst_buf, mk_lang_types_sint_t const dst_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_zlib_decompress(mk_sl_cui_uint8_pct const src_buf, mk_lang_types_sint_t const src_len, mk_sl_cui_uint8_pt const dst_buf, mk_lang_types_sint_t const dst_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_zlib.c"
#endif
#endif
