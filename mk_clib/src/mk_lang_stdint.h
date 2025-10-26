#ifndef mk_include_guard_mk_lang_stdint_h
#define mk_include_guard_mk_lang_stdint_h


#include "mk_lang_charbit.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_types.h"


#if mk_lang_charbit == 8 && mk_lang_sizeof_bi_uchar_t == 1
typedef mk_lang_types_uchar_t mk_lang_stdint_uint8_t;
typedef mk_lang_types_schar_t mk_lang_stdint_sint8_t;
#else
#error xxxxxxxxxx
#endif

#if mk_lang_charbit == 8 && mk_lang_sizeof_bi_ushort_t == 2
typedef mk_lang_types_ushort_t mk_lang_stdint_uint16_t;
typedef mk_lang_types_sshort_t mk_lang_stdint_sint16_t;
#else
#error xxxxxxxxxx
#endif

#if mk_lang_charbit == 8 && mk_lang_sizeof_bi_uint_t == 4
typedef mk_lang_types_uint_t mk_lang_stdint_uint32_t;
typedef mk_lang_types_sint_t mk_lang_stdint_sint32_t;
#elif mk_lang_charbit == 8 && mk_lang_sizeof_bi_ulong_t == 4
typedef mk_lang_types_ulong_t mk_lang_stdint_uint32_t;
typedef mk_lang_types_slong_t mk_lang_stdint_sint32_t;
#else
#error xxxxxxxxxx
#endif


#if mk_lang_jumbo_have
#include "mk_lang_stdint.c"
#endif
#endif
