#ifndef mk_include_guard_mk_lang_typedef_h
#define mk_include_guard_mk_lang_typedef_h


#include "mk_lang_bitness.h"
#include "mk_lang_concat.h"
#include "mk_lang_platform.h"
#include "mk_lang_restrict.h"
#include "mk_lang_version.h"


#if mk_lang_bitness == mk_lang_bitness_16 && mk_lang_platform_is_windows_at_least_any
#define mk_lang_typedef_far __far
#define mk_lang_typedef_near __near
#else
#define mk_lang_typedef_far
#define mk_lang_typedef_near
#endif


#define mk_lang_typedef_add_const(a, b) typedef a##b const a##c##b
#define mk_lang_typedef_add_volatile(a, b) typedef a##b volatile a##v##b
#define mk_lang_typedef_add_cv(a, b) typedef a##b const volatile a##cv##b
#define mk_lang_typedef_add_pointer(a, b) typedef a##b* a##p##b
#define mk_lang_typedef_add_restrict(a, b) typedef a##b mk_lang_restrict a##r##b
#define mk_lang_typedef_add_far(a, b) typedef a##b mk_lang_typedef_far* a##lp##b
#define mk_lang_typedef_add_near(a, b) typedef a##b mk_lang_typedef_near* a##np##b

#define mk_lang_typedef_add_top_level_cv(a, b) \
	mk_lang_typedef_add_const(a, b); \
	mk_lang_typedef_add_volatile(a, b); \
	mk_lang_typedef_add_cv(a, b)

#define mk_lang_typedef_add_pointers(a, b) \
	mk_lang_typedef_add_pointer(a, b); \
	mk_lang_typedef_add_pointer(a, c##b); \
	mk_lang_typedef_add_pointer(a, v##b); \
	mk_lang_typedef_add_pointer(a, cv##b)

#define mk_lang_typedef_add_restricts(a, b) \
	mk_lang_typedef_add_restrict(a, b); \
	mk_lang_typedef_add_restrict(a, c##b); \
	mk_lang_typedef_add_restrict(a, v##b); \
	mk_lang_typedef_add_restrict(a, cv##b)

#define mk_lang_typedef_add_fars_2(a, b) \
	mk_lang_typedef_add_far(a, b); \
	mk_lang_typedef_add_far(a, c##b); \
	mk_lang_typedef_add_far(a, v##b); \
	mk_lang_typedef_add_far(a, cv##b)

#define mk_lang_typedef_add_nears_2(a, b) \
	mk_lang_typedef_add_near(a, b); \
	mk_lang_typedef_add_near(a, c##b); \
	mk_lang_typedef_add_near(a, v##b); \
	mk_lang_typedef_add_near(a, cv##b)

#define mk_lang_typedef_add_fars(a, b) \
	mk_lang_typedef_add_fars_2(a, b); \
	mk_lang_typedef_add_restricts(mk_lang_concat(a, lp), b)

#define mk_lang_typedef_add_nears(a, b) \
	mk_lang_typedef_add_nears_2(a, b); \
	mk_lang_typedef_add_restricts(mk_lang_concat(a, np), b)

#define mk_lang_typedef_2(a, b) \
	mk_lang_typedef_add_top_level_cv(mk_lang_concat(a, _), b); \
	mk_lang_typedef_add_pointers(mk_lang_concat(a, _), b); \
	mk_lang_typedef_add_restricts(mk_lang_concat(a, _p), b); \
	mk_lang_typedef_add_fars(mk_lang_concat(a, _), b); \
	mk_lang_typedef_add_nears(mk_lang_concat(a, _), b) \

#define mk_lang_typedef_3(a, b) \
	mk_lang_typedef_2(a, b); \
	mk_lang_typedef_2(a, p##b); \
	mk_lang_typedef_2(a, pc##b)

#define mk_lang_typedef(x) \
	mk_lang_typedef_3(x, t); \
	mk_lang_typedef_3(x, p##t); \
	mk_lang_typedef_3(x, pc##t)

#define mk_lang_forward(x) \
	struct x##_s; \
	typedef struct x##_s x##_t; \
	mk_lang_typedef(x)


#if mk_lang_version_at_least_cpp_17
#define mk_lang_typedef_func(ret, name, args) typedef ret(*name)args mk_lang_noexcept
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
#define mk_lang_typedef_func(ret, name, args) ret mk_lang_concat(mk_lang_typedef_func_dummy_, name)args mk_lang_noexcept; typedef decltype(&mk_lang_concat(mk_lang_typedef_func_dummy_, name)) name
#else
#define mk_lang_typedef_func(ret, name, args) typedef ret(*name)args mk_lang_noexcept
#endif


#endif
