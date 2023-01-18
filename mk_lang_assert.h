#ifndef mk_include_guard_lang_assert
#define mk_include_guard_lang_assert


#if defined NDEBUG
#if defined __cpp_lib_unreachable && __cpp_lib_unreachable >= 202202l
#include <utility> /* std::unreachable */
#define mk_lang_assert(x) if(!(x)) std::unreachable(); ((void)(0))
#elif defined __STDC_VERSION__ && __STDC_VERSION__ >= 202299l /* todo c23 */
#include <stddef.h> /* unreachable */
#define mk_lang_assert(x) if(!(x)) unreachable(); ((void)(0))
#elif defined _MSC_VER && _MSC_VER >= 1200 /* vs 6 */
#define mk_lang_assert(x) __assume(x)
#elif defined __GNUC__ && defined __GNUC_MINOR__ && __GNUC__ * 100 + __GNUC_MINOR__ >= 405
#define mk_lang_assert(x) if(!(x)) __builtin_unreachable(); ((void)(0))
#elif defined __has_builtin && __has_builtin(__builtin_unreachable)
#define mk_lang_assert(x) if(!(x)) __builtin_unreachable(); ((void)(0))
#else
#define mk_lang_assert(x) ((void)(0))
#endif
#else
#if defined(__cplusplus)
#include <cassert> /* assert */
#define mk_lang_assert assert
#else
#include <assert.h> /* assert */
#define mk_lang_assert assert
#endif
#endif


#endif
