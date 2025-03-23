#ifndef mk_include_guard_mk_lang_roundup_h
#define mk_include_guard_mk_lang_roundup_h


#define mk_lang_roundup_div(a, b) (((a) + ((b) - 1)) / (b))
#define mk_lang_roundup_mul(a, b) (mk_lang_roundup_div((a), (b)) * (b))


#endif
