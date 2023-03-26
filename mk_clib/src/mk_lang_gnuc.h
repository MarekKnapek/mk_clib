#ifndef mk_include_guard_lang_gnuc
#define mk_include_guard_lang_gnuc


#if defined __GNUC__ && defined __GNUC_MINOR__
#define mk_lang_gnuc_is_at_least(major, minor) (((__GNUC__) > (major)) || (((__GNUC__) == (major)) && ((__GNUC_MINOR__) > (minor))))
#else
#define mk_lang_gnuc_is_at_least(major, minor) 0
#endif


#endif
