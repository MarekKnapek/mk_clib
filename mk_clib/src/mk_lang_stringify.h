#ifndef mk_include_guard_mk_lang_stringify
#define mk_include_guard_mk_lang_stringify


#define mk_lang_stringify_(x) #x
#define mk_lang_stringify(x) mk_lang_stringify_(x)

#define mk_lang_stringifyw_(x) L ## #x
#define mk_lang_stringifyw(x) mk_lang_stringifyw_(x)


#endif
