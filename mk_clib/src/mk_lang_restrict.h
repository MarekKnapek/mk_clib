#ifndef mk_include_guard_lang_restrict
#define mk_include_guard_lang_restrict


#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901l
#define mk_lang_restrict restrict
#else
#define mk_lang_restrict
#endif


#endif
