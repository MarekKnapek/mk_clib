#ifndef mk_include_guard_mk_lib_iip_cp_bytes_h
#define mk_include_guard_mk_lib_iip_cp_bytes_h


#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_typedef.h"
#include "mk_sl_cui_uint8.h"


#define mk_lib_iip_cp_bytes_make(x) \
struct mk_lang_concat(mk_lang_concat(mk_lib_iip_cp_bytes_, x), _s) \
{ \
	mk_sl_cui_uint8_t m_bytes[x]; \
}; \
typedef struct mk_lang_concat(mk_lang_concat(mk_lib_iip_cp_bytes_, x), _s) mk_lang_concat(mk_lang_concat(mk_lib_iip_cp_bytes_, x), _t); \
mk_lang_typedef(mk_lang_concat(mk_lib_iip_cp_bytes_, x))


mk_lib_iip_cp_bytes_make(20);
mk_lib_iip_cp_bytes_make(128);
mk_lib_iip_cp_bytes_make(256);


#if mk_lang_jumbo_have
#include "mk_lib_iip_cp_bytes.c"
#endif
#endif
