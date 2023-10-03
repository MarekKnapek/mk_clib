#ifndef mk_include_guard_mk_lang_assert
#define mk_include_guard_mk_lang_assert


#include "mk_lang_crash.h"


#define mk_lang_assert_mode_test_crash 1
#define mk_lang_assert_mode_assume 2
#define mk_lang_assert_mode_assert 3


#if defined NDEBUG && defined mk_lang_assert_want && mk_lang_assert_want == 1
#define mk_lang_assert_mode mk_lang_assert_mode_test_crash
#elif defined NDEBUG && defined mk_lang_assert_want && mk_lang_assert_want == 0
#define mk_lang_assert_mode mk_lang_assert_mode_assume
#elif defined NDEBUG && !defined mk_lang_assert_want
#define mk_lang_assert_mode mk_lang_assert_mode_assume
#elif !defined NDEBUG && defined mk_lang_assert_want && mk_lang_assert_want == 1
#define mk_lang_assert_mode mk_lang_assert_mode_assert
#elif !defined NDEBUG && defined mk_lang_assert_want && mk_lang_assert_want == 0
#define mk_lang_assert_mode mk_lang_assert_mode_assume
#elif !defined NDEBUG && !defined mk_lang_assert_want
#define mk_lang_assert_mode mk_lang_assert_mode_assert
#endif


#if mk_lang_assert_mode == mk_lang_assert_mode_test_crash

#define mk_lang_assert(x) ((void)((x) ? ((void)(0)) : ((void)(mk_lang_crash()))))

#elif mk_lang_assert_mode == mk_lang_assert_mode_assume

#include "mk_lang_builtin.h"
#include "mk_lang_gnuc.h"
#include "mk_lang_version.h"
#if mk_lang_version_at_least_cpp_23
#define mk_lang_assert(x) [[assume(x)]]
#elif defined __cpp_lib_unreachable && __cpp_lib_unreachable >= 202202l
#include <utility> /* std::unreachable */
#define mk_lang_assert(x) ((void)((x) ? ((void)(0)) : ((void)(std::unreachable()))))
#elif mk_lang_version_at_least_c_23
#include <stddef.h> /* unreachable */
#define mk_lang_assert(x) ((void)((x) ? ((void)(0)) : ((void)(unreachable()))))
#elif defined _MSC_VER && _MSC_VER >= 1200 /* vs 6 */
#define mk_lang_assert(x) __assume(x)
#elif mk_lang_builtin_has_assume
#define mk_lang_assert(x) __builtin_assume(x)
#elif mk_lang_builtin_has_unreachable
#define mk_lang_assert(x) ((void)((x) ? ((void)(0)) : ((void)(__builtin_unreachable()))))
#elif mk_lang_gnuc_is_at_least(4, 5)
#define mk_lang_assert(x) ((void)((x) ? ((void)(0)) : ((void)(__builtin_unreachable()))))
#else
#define mk_lang_assert(x) ((void)(0))
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

#define mk_lang_test(x) ((void)((x) ? ((void)(0)) : ((void)(mk_lang_crash()))))


#undef mk_lang_assert_mode_test_crash
#undef mk_lang_assert_mode_assume
#undef mk_lang_assert_mode_assert


#endif
