#ifndef mk_include_guard_mk_lang_version
#define mk_include_guard_mk_lang_version


#define mk_lang_version_value_c_99 199901l
#define mk_lang_version_value_c_11 201112l
#define mk_lang_version_value_c_18 201710l
#define mk_lang_version_value_c_23 202299l /* todo c23 */

#define mk_lang_version_value_cpp_98 199711l
#define mk_lang_version_value_cpp_11 201103l
#define mk_lang_version_value_cpp_14 201402l
#define mk_lang_version_value_cpp_17 201703l
#define mk_lang_version_value_cpp_20 202002l
#define mk_lang_version_value_cpp_23 202299l /* todo c++ 23 */


#if defined __STDC__
#define mk_lang_version_at_least_c_89 1
#define mk_lang_version_at_least_c_90 1
#else
#define mk_lang_version_at_least_c_89 0
#define mk_lang_version_at_least_c_90 0
#endif

#if defined __STDC_VERSION__ && __STDC_VERSION__ >= mk_lang_version_value_c_99
#define mk_lang_version_at_least_c_99 1
#else
#define mk_lang_version_at_least_c_99 0
#endif

#if defined __STDC_VERSION__ && __STDC_VERSION__ >= mk_lang_version_value_c_11
#define mk_lang_version_at_least_c_11 1
#else
#define mk_lang_version_at_least_c_11 0
#endif

#if defined __STDC_VERSION__ && __STDC_VERSION__ >= mk_lang_version_value_c_18
#define mk_lang_version_at_least_c_18 1
#else
#define mk_lang_version_at_least_c_18 0
#endif

#if defined __STDC_VERSION__ && __STDC_VERSION__ >= mk_lang_version_value_c_23
#define mk_lang_version_at_least_c_23 1
#else
#define mk_lang_version_at_least_c_23 0
#endif


#if defined __cplusplus && __cplusplus >= mk_lang_version_value_cpp_98
#define mk_lang_version_at_least_cpp_98 1
#else
#define mk_lang_version_at_least_cpp_98 0
#endif

#if defined __cplusplus && __cplusplus >= mk_lang_version_value_cpp_11
#define mk_lang_version_at_least_cpp_11 1
#else
#define mk_lang_version_at_least_cpp_11 0
#endif

#if defined __cplusplus && __cplusplus >= mk_lang_version_value_cpp_14
#define mk_lang_version_at_least_cpp_14 1
#else
#define mk_lang_version_at_least_cpp_14 0
#endif

#if defined __cplusplus && __cplusplus >= mk_lang_version_value_cpp_17
#define mk_lang_version_at_least_cpp_17 1
#else
#define mk_lang_version_at_least_cpp_17 0
#endif

#if defined __cplusplus && __cplusplus >= mk_lang_version_value_cpp_20
#define mk_lang_version_at_least_cpp_20 1
#else
#define mk_lang_version_at_least_cpp_20 0
#endif

#if defined __cplusplus && __cplusplus >= mk_lang_version_value_cpp_23
#define mk_lang_version_at_least_cpp_23 1
#else
#define mk_lang_version_at_least_cpp_23 0
#endif


#if defined _MSVC_LANG && _MSVC_LANG >= mk_lang_version_value_cpp_11
#define mk_lang_version_at_least_msvc_cpp_11 1
#else
#define mk_lang_version_at_least_msvc_cpp_11 0
#endif

#if defined _MSVC_LANG && _MSVC_LANG >= mk_lang_version_value_cpp_14
#define mk_lang_version_at_least_msvc_cpp_14 1
#else
#define mk_lang_version_at_least_msvc_cpp_14 0
#endif

#if defined _MSVC_LANG && _MSVC_LANG >= mk_lang_version_value_cpp_17
#define mk_lang_version_at_least_msvc_cpp_17 1
#else
#define mk_lang_version_at_least_msvc_cpp_17 0
#endif

#if defined _MSVC_LANG && _MSVC_LANG >= mk_lang_version_value_cpp_20
#define mk_lang_version_at_least_msvc_cpp_20 1
#else
#define mk_lang_version_at_least_msvc_cpp_20 0
#endif


#endif
