#ifndef mk_include_guard_mk_lang_pow2
#define mk_include_guard_mk_lang_pow2


#define mk_lang_pow2_roundup_f(x) ((x) - 1)
#define mk_lang_pow2_roundup_e(x) (mk_lang_pow2_roundup_f(x) | (mk_lang_pow2_roundup_f(x) >>  1))
#define mk_lang_pow2_roundup_d(x) (mk_lang_pow2_roundup_e(x) | (mk_lang_pow2_roundup_e(x) >>  2))
#define mk_lang_pow2_roundup_c(x) (mk_lang_pow2_roundup_d(x) | (mk_lang_pow2_roundup_d(x) >>  4))
#define mk_lang_pow2_roundup_b(x) (mk_lang_pow2_roundup_c(x) | (mk_lang_pow2_roundup_c(x) >>  8))
#define mk_lang_pow2_roundup_a(x) (mk_lang_pow2_roundup_b(x) | (mk_lang_pow2_roundup_b(x) >> 16))


#define mk_lang_pow2_is(x) (((x) != 0) && (((x) & ((x) - 1)) == 0))
#define mk_lang_pow2_roundup(x) (mk_lang_pow2_roundup_a(x) + 1)


#endif
