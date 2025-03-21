#ifndef mk_include_guard_mk_lang_version_h
#define mk_include_guard_mk_lang_version_h


#define mk_lang_version_value_c_94 199409l
#define mk_lang_version_value_c_99 199901l
#define mk_lang_version_value_c_11 201112l
#define mk_lang_version_value_c_17 201710l
#define mk_lang_version_value_c_23 202311l

#define mk_lang_version_value_cpp_98 199711l
#define mk_lang_version_value_cpp_11 201103l
#define mk_lang_version_value_cpp_14 201402l
#define mk_lang_version_value_cpp_17 201703l
#define mk_lang_version_value_cpp_20 202002l
#define mk_lang_version_value_cpp_23 202302l


#if defined __STDC__
#define mk_lang_version_has_macro_stdc 1
#else
#define mk_lang_version_has_macro_stdc 0
#endif

#if defined __STDC_VERSION__
#define mk_lang_version_has_macro_stdc_version 1
#define mk_lang_version_macro_stdc_version (__STDC_VERSION__)
#else
#define mk_lang_version_has_macro_stdc_version 0
#define mk_lang_version_macro_stdc_version 0
#endif

#if defined __cplusplus
#define mk_lang_version_has_macro_cplusplus 1
#define mk_lang_version_macro_cplusplus (__cplusplus)
#else
#define mk_lang_version_has_macro_cplusplus 0
#define mk_lang_version_macro_cplusplus 0
#endif

#if defined _MSVC_LANG
#define mk_lang_version_has_macro_msvc_lang 1
#define mk_lang_version_macro_msvc_lang (_MSVC_LANG)
#else
#define mk_lang_version_has_macro_msvc_lang 0
#define mk_lang_version_macro_msvc_lang 0
#endif


#define mk_lang_version_at_least_c_89 (mk_lang_version_has_macro_stdc)
#define mk_lang_version_at_least_c_90 (mk_lang_version_has_macro_stdc)
#define mk_lang_version_at_least_c_94 (mk_lang_version_macro_stdc_version >= mk_lang_version_value_c_94)
#define mk_lang_version_at_least_c_99 (mk_lang_version_macro_stdc_version >= mk_lang_version_value_c_99)
#define mk_lang_version_at_least_c_11 (mk_lang_version_macro_stdc_version >= mk_lang_version_value_c_11)
#define mk_lang_version_at_least_c_17 (mk_lang_version_macro_stdc_version >= mk_lang_version_value_c_17)
#define mk_lang_version_at_least_c_23 (mk_lang_version_macro_stdc_version >= mk_lang_version_value_c_23)

#define mk_lang_version_at_least_cpp_98 (mk_lang_version_macro_cplusplus >= mk_lang_version_value_cpp_98)
#define mk_lang_version_at_least_cpp_11 (mk_lang_version_macro_cplusplus >= mk_lang_version_value_cpp_11)
#define mk_lang_version_at_least_cpp_14 (mk_lang_version_macro_cplusplus >= mk_lang_version_value_cpp_14)
#define mk_lang_version_at_least_cpp_17 (mk_lang_version_macro_cplusplus >= mk_lang_version_value_cpp_17)
#define mk_lang_version_at_least_cpp_20 (mk_lang_version_macro_cplusplus >= mk_lang_version_value_cpp_20)
#define mk_lang_version_at_least_cpp_23 (mk_lang_version_macro_cplusplus >= mk_lang_version_value_cpp_23)

#define mk_lang_version_at_least_msvc_cpp_11 (mk_lang_version_macro_msvc_lang >= mk_lang_version_value_cpp_11)
#define mk_lang_version_at_least_msvc_cpp_14 (mk_lang_version_macro_msvc_lang >= mk_lang_version_value_cpp_14)
#define mk_lang_version_at_least_msvc_cpp_17 (mk_lang_version_macro_msvc_lang >= mk_lang_version_value_cpp_17)
#define mk_lang_version_at_least_msvc_cpp_20 (mk_lang_version_macro_msvc_lang >= mk_lang_version_value_cpp_20)


#endif
