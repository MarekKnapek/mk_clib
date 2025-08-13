#ifndef mk_include_guard_mk_lang_configuration_h
#define mk_include_guard_mk_lang_configuration_h


#if defined DEBUG || defined _DEBUG
#define mk_lang_configuration_have_debug 1
#else
#define mk_lang_configuration_have_debug 0
#endif

#if defined NDEBUG || defined _NDEBUG
#define mk_lang_configuration_have_ndebug 1
#else
#define mk_lang_configuration_have_ndebug 0
#endif

#if mk_lang_configuration_have_debug && mk_lang_configuration_have_ndebug
#error xxxxxxxxxx
#endif

#define mk_lang_configuration_is_debug   (mk_lang_configuration_have_debug )
#define mk_lang_configuration_is_release (mk_lang_configuration_have_ndebug)


#endif
