#ifndef mk_include_guard_mk_lang_platform
#define mk_include_guard_mk_lang_platform


#define mk_lang_platform_windows_62 1001
#define mk_lang_platform_windows_61 1002
#define mk_lang_platform_windows_60 1003
#define mk_lang_platform_windows_51 1004
#define mk_lang_platform_windows    1005
#define mk_lang_platform_linux      1006
#define mk_lang_platform_portable   1007


#if defined _WIN32_WINNT && _WIN32_WINNT >= 0x0602
#define mk_lang_platform mk_lang_platform_windows_62
#define mk_lang_platform_is_windows_ver 62
#elif defined _WIN32_WINNT && _WIN32_WINNT >= 0x0601
#define mk_lang_platform mk_lang_platform_windows_61
#define mk_lang_platform_is_windows_ver 61
#elif defined _WIN32_WINNT && _WIN32_WINNT >= 0x0600
#define mk_lang_platform mk_lang_platform_windows_60
#define mk_lang_platform_is_windows_ver 60
#elif defined _WIN32_WINNT && _WIN32_WINNT >= 0x0501
#define mk_lang_platform mk_lang_platform_windows_51
#define mk_lang_platform_is_windows_ver 51
#elif (defined _MSC_VER && defined _MSC_FULL_VER) || ((defined __WATCOMC__ || defined __WATCOM_CPLUSPLUS__) && defined __NT__) || defined _WIN32
#define mk_lang_platform mk_lang_platform_windows
#define mk_lang_platform_is_windows_ver 10
#elif ((defined linux && linux == 1) || (defined __linux && __linux == 1) || (defined __linux__ && __linux__ == 1) || (defined __gnu_linux__ && __gnu_linux__ == 1)) && ((defined _POSIX_C_SOURCE && _POSIX_C_SOURCE >= 200809l) && (defined _XOPEN_SOURCE && _XOPEN_SOURCE >= 700) && (defined _GNU_SOURCE))
#define mk_lang_platform mk_lang_platform_linux
#define mk_lang_platform_is_windows_ver 0
#else
#define mk_lang_platform mk_lang_platform_portable
#define mk_lang_platform_is_windows_ver 0
#endif

#define mk_lang_platform_is_windows_at_least_62 (mk_lang_platform_is_windows_ver >= 62)
#define mk_lang_platform_is_windows_at_least_61 (mk_lang_platform_is_windows_ver >= 61)
#define mk_lang_platform_is_windows_at_least_60 (mk_lang_platform_is_windows_ver >= 60)
#define mk_lang_platform_is_windows_at_least_51 (mk_lang_platform_is_windows_ver >= 51)
#define mk_lang_platform_is_windows_at_least_any (mk_lang_platform_is_windows_ver >= 10)


#endif
