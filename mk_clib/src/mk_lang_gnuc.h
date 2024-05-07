#ifndef mk_include_guard_mk_lang_gnuc
#define mk_include_guard_mk_lang_gnuc


#if defined __GNUC__ && defined __GNUC_MINOR__ && !defined __clang_major__ && !defined __clang_minor__
#define mk_lang_gnuc_is_at_least(major, minor) (((__GNUC__) > (major)) || (((__GNUC__) == (major)) && ((__GNUC_MINOR__) >= (minor))))
#define mk_lang_gnuc_attribute_target(x) __attribute__((__target__(x)))
#else
#define mk_lang_gnuc_is_at_least(major, minor) 0
#define mk_lang_gnuc_attribute_target(x)
#endif


#endif
