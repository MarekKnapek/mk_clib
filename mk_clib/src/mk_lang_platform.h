#ifndef mk_include_guard_mk_lang_platform
#define mk_include_guard_mk_lang_platform


#define mk_lang_platform_windows_61 4001
#define mk_lang_platform_windows_60 4002
#define mk_lang_platform_windows    4003
#define mk_lang_platform_linux      4004
#define mk_lang_platform_portable   4005


#if defined _WIN32_WINNT && _WIN32_WINNT >= 0x0601
#define mk_lang_platform mk_lang_platform_windows_61
#elif defined _WIN32_WINNT && _WIN32_WINNT >= 0x0600
#define mk_lang_platform mk_lang_platform_windows_60
#elif (defined _MSC_VER && defined _MSC_FULL_VER) || ((defined __WATCOMC__ || defined __WATCOM_CPLUSPLUS__) && defined __NT__) || defined _WIN32
#define mk_lang_platform mk_lang_platform_windows
#elif ((defined linux && linux == 1) || (defined __linux && __linux == 1) || (defined __linux__ && __linux__ == 1) || (defined __gnu_linux__ && __gnu_linux__ == 1)) && ((defined _POSIX_C_SOURCE && _POSIX_C_SOURCE >= 200809l) && (defined _XOPEN_SOURCE && _XOPEN_SOURCE >= 700) && (defined _GNU_SOURCE))
#define mk_lang_platform mk_lang_platform_linux
#else
#define mk_lang_platform mk_lang_platform_portable
#endif


#endif
