#ifndef mk_include_guard_mk_lang_countof
#define mk_include_guard_mk_lang_countof


#include "mk_lang_constexpr.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11


template<typename t>
struct mk_lang_countof_impl_s
{
};

template<typename t, mk_lang_types_sint_t n>
struct mk_lang_countof_impl_s<t[n]>
{
	mk_lang_constexpr static mk_lang_types_sint_t const value = n;
};

template<typename t>
struct mk_lang_countstr_impl_s
{
};

template<typename t>
struct mk_lang_countstr_impl_s<t[1]>
{
};

template<typename t, mk_lang_types_sint_t n>
struct mk_lang_countstr_impl_s<t[n]>
{
	mk_lang_constexpr static mk_lang_types_sint_t const value = n - 1;
};

#define mk_lang_countof(x) (mk_lang_countof_impl_s<decltype(x)>::value)
#define mk_lang_countstr(x) (mk_lang_countstr_impl_s<decltype(x)>::value)


#else


#define mk_lang_countof(x) ((mk_lang_types_sint_t)(sizeof(x) / sizeof((x)[0])))
#define mk_lang_countstr(x) (mk_lang_countof(x) - 1)


#endif


#endif
