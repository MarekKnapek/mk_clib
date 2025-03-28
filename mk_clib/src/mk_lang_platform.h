#ifndef mk_include_guard_mk_lang_platform_h
#define mk_include_guard_mk_lang_platform_h


#define mk_lang_platform_windows  1001
#define mk_lang_platform_linux    1002
#define mk_lang_platform_posix    1003
#define mk_lang_platform_portable 1004


#if defined _WIN32_WINNT && _WIN32_WINNT >= 0x0602
#define mk_lang_platform_is_windows_ver 62
#elif defined _WIN32_WINNT && _WIN32_WINNT >= 0x0601
#define mk_lang_platform_is_windows_ver 61
#elif defined _WIN32_WINNT && _WIN32_WINNT >= 0x0600
#define mk_lang_platform_is_windows_ver 60
#elif defined _WIN32_WINNT && _WIN32_WINNT >= 0x0501
#define mk_lang_platform_is_windows_ver 51
#elif (defined _MSC_VER && defined _MSC_FULL_VER) || ((defined __WATCOMC__ || defined __WATCOM_CPLUSPLUS__) && defined __NT__) || defined _WIN32 || defined WIN32
#define mk_lang_platform_is_windows_ver 1
#else
#define mk_lang_platform_is_windows_ver 0
#endif

#if !defined mk_lang_platform
#if mk_lang_platform_is_windows_ver != 0
#define mk_lang_platform mk_lang_platform_windows
#endif
#endif


#if !defined mk_lang_platform
#if (defined linux && linux == 1) || (defined __linux && __linux == 1) || (defined __linux__ && __linux__ == 1) || (defined __gnu_linux__ && __gnu_linux__ == 1)
#define mk_lang_platform mk_lang_platform_linux
#endif
#endif


#if defined _POSIX_C_SOURCE
#if (_POSIX_C_SOURCE) >= 1 && (_POSIX_C_SOURCE) <= 999999
#define mk_lang_platform_is_posix_ver (_POSIX_C_SOURCE)
#else
#define mk_lang_platform_is_posix_ver 0
#endif
#else
#define mk_lang_platform_is_posix_ver 0
#endif

#if !defined mk_lang_platform
#if mk_lang_platform_is_posix_ver != 0
#define mk_lang_platform mk_lang_platform_posix
#endif
#endif


#if !defined mk_lang_platform
#define mk_lang_platform mk_lang_platform_portable
#endif


#define mk_lang_platform_is_windows_at_least_62 (mk_lang_platform_is_windows_ver >= 62)
#define mk_lang_platform_is_windows_at_least_61 (mk_lang_platform_is_windows_ver >= 61)
#define mk_lang_platform_is_windows_at_least_60 (mk_lang_platform_is_windows_ver >= 60)
#define mk_lang_platform_is_windows_at_least_51 (mk_lang_platform_is_windows_ver >= 51)
#define mk_lang_platform_is_windows_at_least_any (mk_lang_platform_is_windows_ver >= 1)

#define mk_lang_platform_is_posix_at_least_2008_09 (mk_lang_platform_is_posix_ver >= 200809l)
#define mk_lang_platform_is_posix_at_least_2001_12 (mk_lang_platform_is_posix_ver >= 200112l)
#define mk_lang_platform_is_posix_at_least_1995_06 (mk_lang_platform_is_posix_ver >= 199506l)
#define mk_lang_platform_is_posix_at_least_1993_09 (mk_lang_platform_is_posix_ver >= 199309l)
#define mk_lang_platform_is_posix_at_least_2 (mk_lang_platform_is_posix_ver >= 2)
#define mk_lang_platform_is_posix_at_least_1 (mk_lang_platform_is_posix_ver >= 1)


#endif
