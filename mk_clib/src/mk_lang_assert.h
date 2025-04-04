#ifndef mk_include_guard_mk_lang_assert_h
#define mk_include_guard_mk_lang_assert_h


#if defined mk_lang_assert_want && (mk_lang_assert_want) == 1
#define mk_lang_assert_want_2 1
#elif defined mk_lang_assert_want && (mk_lang_assert_want) == 0
#define mk_lang_assert_want_2 0
#elif !defined mk_lang_assert_want
#if defined DEBUG || defined _DEBUG
#define mk_lang_assert_want_2 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lang_assert_want_2 0
#else
#define mk_lang_assert_want_2 1
#endif
#endif
#else
#error xxxxxxxxxx
#endif

#if defined mk_lang_assert_want_crash && (mk_lang_assert_want_crash) == 1
#define mk_lang_assert_want_crash_2 1
#elif defined mk_lang_assert_want_crash && (mk_lang_assert_want_crash) == 0
#define mk_lang_assert_want_crash_2 0
#elif !defined mk_lang_assert_want_crash
#define mk_lang_assert_want_crash_2 0
#else
#error xxxxxxxxxx
#endif


#define mk_lang_assert_mode_crash  1001
#define mk_lang_assert_mode_assume 1002
#define mk_lang_assert_mode_assert 1003

#if mk_lang_assert_want_2 && mk_lang_assert_want_crash_2
#define mk_lang_assert_mode mk_lang_assert_mode_crash
#elif mk_lang_assert_want_2 && !mk_lang_assert_want_crash_2
#define mk_lang_assert_mode mk_lang_assert_mode_assert
#elif !mk_lang_assert_want_2
#define mk_lang_assert_mode mk_lang_assert_mode_assume
#else
#error xxxxxxxxxx
#endif





#if mk_lang_assert_mode == mk_lang_assert_mode_crash


#include "mk_lang_crash.h"
#include "mk_lang_types.h"

#define mk_lang_assert(x) ((mk_lang_types_void_t)((x) ? ((mk_lang_types_void_t)(0)) : ((mk_lang_types_void_t)(mk_lang_crash()))))


#elif mk_lang_assert_mode == mk_lang_assert_mode_assume


#include "mk_lang_builtin.h"
#include "mk_lang_compiler.h"
#include "mk_lang_msvc.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"

#if mk_lang_version_at_least_cpp_23

#define mk_lang_assert(x) [[assume(x)]]

#elif defined __cpp_lib_unreachable && __cpp_lib_unreachable >= 202202l

#include <utility> /* std::unreachable */
#define mk_lang_assert(x) ((mk_lang_types_void_t)((x) ? ((mk_lang_types_void_t)(0)) : ((mk_lang_types_void_t)(std::unreachable()))))

#elif mk_lang_version_at_least_c_23

#include <stddef.h> /* unreachable */
#define mk_lang_assert(x) ((mk_lang_types_void_t)((x) ? ((mk_lang_types_void_t)(0)) : ((mk_lang_types_void_t)(unreachable()))))

#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_6

#define mk_lang_assert(x) __assume(x)

#elif mk_lang_builtin_has_assume

#define mk_lang_assert(x) __builtin_assume(x)

#elif mk_lang_builtin_has_unreachable

#define mk_lang_assert(x) ((mk_lang_types_void_t)((x) ? ((mk_lang_types_void_t)(0)) : ((mk_lang_types_void_t)(__builtin_unreachable()))))

#elif mk_lang_compiler_is_at_least_gcc(4, 5)

#define mk_lang_assert(x) ((mk_lang_types_void_t)((x) ? ((mk_lang_types_void_t)(0)) : ((mk_lang_types_void_t)(__builtin_unreachable()))))

#else

#define mk_lang_assert(x) ((mk_lang_types_void_t)(0))

#endif


#elif mk_lang_assert_mode == mk_lang_assert_mode_assert


#if defined __cplusplus

#include <cassert> /* assert */
#define mk_lang_assert assert

#else

#include <assert.h> /* assert */
#define mk_lang_assert assert

#endif


#endif





#endif
