#ifndef mk_include_guard_mk_lang_log2
#define mk_include_guard_mk_lang_log2


#include "mk_lang_llong.h"


#if mk_lang_llong_has

#define mk_lang_log2_impl_g(x) (0)
#define mk_lang_log2_impl_f(x) (((x) >= (mk_lang_ullong_c(1) <<  1)) ? ( 1 + mk_lang_log2_impl_g((x) / (mk_lang_ullong_c(1) <<  1))) : (mk_lang_log2_impl_g(x)))
#define mk_lang_log2_impl_e(x) (((x) >= (mk_lang_ullong_c(1) <<  2)) ? ( 2 + mk_lang_log2_impl_f((x) / (mk_lang_ullong_c(1) <<  2))) : (mk_lang_log2_impl_f(x)))
#define mk_lang_log2_impl_d(x) (((x) >= (mk_lang_ullong_c(1) <<  4)) ? ( 4 + mk_lang_log2_impl_e((x) / (mk_lang_ullong_c(1) <<  4))) : (mk_lang_log2_impl_e(x)))
#define mk_lang_log2_impl_c(x) (((x) >= (mk_lang_ullong_c(1) <<  8)) ? ( 8 + mk_lang_log2_impl_d((x) / (mk_lang_ullong_c(1) <<  8))) : (mk_lang_log2_impl_d(x)))
#define mk_lang_log2_impl_b(x) (((x) >= (mk_lang_ullong_c(1) << 16)) ? (16 + mk_lang_log2_impl_c((x) / (mk_lang_ullong_c(1) << 16))) : (mk_lang_log2_impl_c(x)))
#define mk_lang_log2_impl_a(x) (((x) >= (mk_lang_ullong_c(1) << 32)) ? (32 + mk_lang_log2_impl_b((x) / (mk_lang_ullong_c(1) << 32))) : (mk_lang_log2_impl_b(x)))

#define mk_lang_log2(x) mk_lang_log2_impl_a(mk_lang_ullong_c(1) * x)

#else

#define mk_lang_log2_impl_f(x) (0)
#define mk_lang_log2_impl_e(x) (((x) >= (1ul <<  1)) ? ( 1 + mk_lang_log2_impl_f((x) / (1ul <<  1))) : (mk_lang_log2_impl_f(x)))
#define mk_lang_log2_impl_d(x) (((x) >= (1ul <<  2)) ? ( 2 + mk_lang_log2_impl_e((x) / (1ul <<  2))) : (mk_lang_log2_impl_e(x)))
#define mk_lang_log2_impl_c(x) (((x) >= (1ul <<  4)) ? ( 4 + mk_lang_log2_impl_d((x) / (1ul <<  4))) : (mk_lang_log2_impl_d(x)))
#define mk_lang_log2_impl_b(x) (((x) >= (1ul <<  8)) ? ( 8 + mk_lang_log2_impl_c((x) / (1ul <<  8))) : (mk_lang_log2_impl_c(x)))
#define mk_lang_log2_impl_a(x) (((x) >= (1ul << 16)) ? (16 + mk_lang_log2_impl_b((x) / (1ul << 16))) : (mk_lang_log2_impl_b(x)))

#define mk_lang_log2(x) mk_lang_log2_impl_a(1ul * x)

#endif


#endif
