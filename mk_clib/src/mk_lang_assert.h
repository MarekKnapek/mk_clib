#ifndef mk_include_guard_lang_assert
#define mk_include_guard_lang_assert


#if defined NDEBUG
#if defined __cplusplus && __cplusplus >= 202299l /* todo c++ 23 */
#define mk_lang_assert(x) [[assume(x)]]
#elif defined __cpp_lib_unreachable && __cpp_lib_unreachable >= 202202l
#include <utility> /* std::unreachable */
#define mk_lang_assert(x) ((void)((x) ? ((void)(0)) : ((void)(std::unreachable()))))
#elif defined __STDC_VERSION__ && __STDC_VERSION__ >= 202299l /* todo c23 */
#include <stddef.h> /* unreachable */
#define mk_lang_assert(x) ((void)((x) ? ((void)(0)) : ((void)(unreachable()))))
#elif defined _MSC_VER && _MSC_VER >= 1200 /* vs 6 */
#define mk_lang_assert(x) __assume(x)
#elif defined __GNUC__ && defined __GNUC_MINOR__ && __GNUC__ * 100 + __GNUC_MINOR__ >= 405
#define mk_lang_assert(x) ((void)((x) ? ((void)(0)) : ((void)(__builtin_unreachable()))))
#elif defined __has_builtin
#if __has_builtin(__builtin_unreachable)
#define mk_lang_assert(x) ((void)((x) ? ((void)(0)) : ((void)(__builtin_unreachable()))))
#else
#define mk_lang_assert(x) ((void)(0))
#endif
#else
#define mk_lang_assert(x) ((void)(0))
#endif
#else
#if defined __cplusplus
#include <cassert> /* assert */
#define mk_lang_assert assert
#else
#include <assert.h> /* assert */
#define mk_lang_assert assert
#endif
#endif


#endif
