#ifndef mk_include_guard_mk_lang_os
#define mk_include_guard_mk_lang_os


#define mk_lang_os_windows 4001
#define mk_lang_os_linux   4002
#define mk_lang_os_c       4003


#if defined _MSC_VER && defined _MSC_FULL_VER
#define mk_lang_os mk_lang_os_windows
#elif ((defined linux && linux == 1) || (defined __linux && __linux == 1) || (defined __linux__ && __linux__ == 1) || (defined __gnu_linux__ && __gnu_linux__ == 1)) && ((defined _POSIX_C_SOURCE && _POSIX_C_SOURCE >= 200809l) && (defined _XOPEN_SOURCE && _XOPEN_SOURCE >= 700) && (defined _GNU_SOURCE))
#define mk_lang_os mk_lang_os_linux
#else
#define mk_lang_os mk_lang_os_c
#endif


#endif
