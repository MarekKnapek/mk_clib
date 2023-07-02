#ifndef mk_include_guard_mk_lang_constexpr
#define mk_include_guard_mk_lang_constexpr


#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_23
#define mk_lang_constexpr_has 1
#define mk_lang_constexpr constexpr
#define mk_lang_constexpr_init {}
#define mk_lang_constexpr_static static constexpr
#define mk_lang_constexpr_static_inline static constexpr inline
#elif mk_lang_version_at_least_cpp_17
#define mk_lang_constexpr_has 1
#define mk_lang_constexpr constexpr
#define mk_lang_constexpr_init {}
#define mk_lang_constexpr_static constexpr
#define mk_lang_constexpr_static_inline static constexpr inline
#elif mk_lang_version_at_least_cpp_14
#define mk_lang_constexpr_has 1
#define mk_lang_constexpr constexpr
#define mk_lang_constexpr_init {}
#define mk_lang_constexpr_static constexpr
#define mk_lang_constexpr_static_inline constexpr
#elif mk_lang_version_at_least_msvc_cpp_14
#define mk_lang_constexpr_has 1
#define mk_lang_constexpr constexpr
#define mk_lang_constexpr_init {}
#define mk_lang_constexpr_static constexpr
#define mk_lang_constexpr_static_inline constexpr
#else
#define mk_lang_constexpr_has 0
#define mk_lang_constexpr
#define mk_lang_constexpr_init
#define mk_lang_constexpr_static static
#define mk_lang_constexpr_static_inline static
#endif


#if mk_lang_version_at_least_cpp_20 || (defined __cpp_lib_is_constant_evaluated && __cpp_lib_is_constant_evaluated >= 201811l)
#include <type_traits> /* std::is_constant_evaluated */
#define mk_lang_constexpr_is_constant_evaluated 1
#define mk_lang_constexpr_is_constant_evaluated_test std::is_constant_evaluated()
#elif mk_lang_constexpr_has
#define mk_lang_constexpr_is_constant_evaluated 1
#define mk_lang_constexpr_is_constant_evaluated_test 1
#else
#define mk_lang_constexpr_is_constant_evaluated 0
#endif


#endif
