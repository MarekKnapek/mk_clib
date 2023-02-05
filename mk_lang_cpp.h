#ifndef mk_include_guard_lang_cpp
#define mk_include_guard_lang_cpp


#if defined __cplusplus
#define mk_lang_extern_c extern "C"
#else
#define mk_lang_extern_c extern
#endif


#endif
