#ifndef mk_include_guard_mk_lang_concat_h
#define mk_include_guard_mk_lang_concat_h


#define mk_lang_concat_impl(a, b) a ## b
#define mk_lang_concat(a, b) mk_lang_concat_impl(a, b)


#endif
