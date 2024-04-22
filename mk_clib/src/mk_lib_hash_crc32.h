#ifndef mk_include_guard_mk_lib_hash_crc32
#define mk_include_guard_mk_lib_hash_crc32


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_hash_crc32_fn(mk_sl_cui_uint8_pct const data, mk_lang_types_usize_t const len, mk_sl_cui_uint32_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_hash_crc32.c"
#endif
#endif
