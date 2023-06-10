#ifndef mk_include_guard_mk_lang_concat
#define mk_include_guard_mk_lang_concat


#define mk_lang_concat_impl(a, b) a ## b
#define mk_lang_concat(a, b) mk_lang_concat_impl(a, b)


#endif
