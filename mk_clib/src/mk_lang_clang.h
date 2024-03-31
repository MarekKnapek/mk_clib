#ifndef mk_include_guard_mk_lang_clang
#define mk_include_guard_mk_lang_clang


#if defined __clang_major__ && defined __clang_minor__
#define mk_lang_clang_is_at_least(major, minor) (((__clang_major__) > (major)) || (((__clang_major__) == (major)) && ((__clang_minor__) >= (minor))))
#define mk_lang_clang_attribute_target(x) __attribute__((__target__(x)))
#else
#define mk_lang_clang_is_at_least(major, minor) 0
#define mk_lang_clang_attribute_target(x)
#endif


#endif
