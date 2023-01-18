#ifndef mk_include_guard_lang_log2
#define mk_include_guard_lang_log2


#include "mk_lang_llong.h"


#if mk_lang_llong_has == 1
#define mk_lang_log2_1(x) (((x) >= (mk_lang_ullong_c(1) << 1)) ? 1 : 0)
#define mk_lang_log2_2(x) (((x) >= (mk_lang_ullong_c(1) << 2)) ? (2 + mk_lang_log2_1((x) >> 2)) : mk_lang_log2_1(x))
#define mk_lang_log2_4(x) (((x) >= (mk_lang_ullong_c(1) << 4)) ? (4 + mk_lang_log2_2((x) >> 4)) : mk_lang_log2_2(x))
#define mk_lang_log2_8(x) (((x) >= (mk_lang_ullong_c(1) << 8)) ? (8 + mk_lang_log2_4((x) >> 8)) : mk_lang_log2_4(x))
#define mk_lang_log2_16(x) (((x) >= (mk_lang_ullong_c(1) << 16)) ? (8 + mk_lang_log2_8((x) >> 16)) : mk_lang_log2_8(x))
#define mk_lang_log2(x) (((x) >= (mk_lang_ullong_c(1) << 32)) ? (32 + mk_lang_log2_16((x) >> 32)) : mk_lang_log2_16(x))
#elif mk_lang_llong_has == 0
#define mk_lang_log2_1(x) (((x) >= (1ul << 1)) ? 1 : 0)
#define mk_lang_log2_2(x) (((x) >= (1ul << 2)) ? (2 + mk_lang_log2_1((x) >> 2)) : mk_lang_log2_1(x))
#define mk_lang_log2_4(x) (((x) >= (1ul << 4)) ? (4 + mk_lang_log2_2((x) >> 4)) : mk_lang_log2_2(x))
#define mk_lang_log2_8(x) (((x) >= (1ul << 8)) ? (8 + mk_lang_log2_4((x) >> 8)) : mk_lang_log2_4(x))
#define mk_lang_log2(x) (((x) >= (1ul << 16)) ? (16 + mk_lang_log2_8((x) >> 16)) : mk_lang_log2_8(x))
#endif


#endif
