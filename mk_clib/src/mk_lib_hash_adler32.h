#ifndef mk_include_guard_mk_lib_hash_adler32_h
#define mk_include_guard_mk_lib_hash_adler32_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"


struct mk_lib_hash_adler32_s
{
	mk_sl_cui_uint32_t m_a;
	mk_sl_cui_uint32_t m_b;
};
typedef struct mk_lib_hash_adler32_s mk_lib_hash_adler32_t;
mk_lang_typedef(mk_lib_hash_adler32);


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_hash_adler32_init(mk_lib_hash_adler32_pt const adler32) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_hash_adler32_append(mk_lib_hash_adler32_pt const adler32, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_hash_adler32_finish(mk_lib_hash_adler32_pt const adler32, mk_sl_cui_uint32_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_hash_adler32.c"
#endif
#endif
