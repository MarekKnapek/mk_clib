#ifndef mk_include_guard_mk_lib_iip_cp_bytes_h
#define mk_include_guard_mk_lib_iip_cp_bytes_h


#include "mk_lang_jumbo.h"
#include "mk_lang_typedef.h"
#include "mk_sl_cui_uint8.h"


struct mk_lib_iip_cp_bytes_20_s
{
	mk_sl_cui_uint8_t m_bytes[20];
};
typedef struct mk_lib_iip_cp_bytes_20_s mk_lib_iip_cp_bytes_20_t;
mk_lang_typedef(mk_lib_iip_cp_bytes_20);

struct mk_lib_iip_cp_bytes_128_s
{
	mk_sl_cui_uint8_t m_bytes[128];
};
typedef struct mk_lib_iip_cp_bytes_128_s mk_lib_iip_cp_bytes_128_t;
mk_lang_typedef(mk_lib_iip_cp_bytes_128);

struct mk_lib_iip_cp_bytes_256_s
{
	mk_sl_cui_uint8_t m_bytes[256];
};
typedef struct mk_lib_iip_cp_bytes_256_s mk_lib_iip_cp_bytes_256_t;
mk_lang_typedef(mk_lib_iip_cp_bytes_256);


#if mk_lang_jumbo_have
#include "mk_lib_iip_cp_bytes.c"
#endif
#endif
