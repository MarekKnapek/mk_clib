#ifndef mk_include_guard_mk_lang_os
#define mk_include_guard_mk_lang_os


#define mk_lang_os_windows 4001
#define mk_lang_os_c       4002


#if defined _MSC_VER && defined _MSC_FULL_VER
#define mk_lang_os mk_lang_os_windows
#else
#define mk_lang_os mk_lang_os_c
#endif


#endif
