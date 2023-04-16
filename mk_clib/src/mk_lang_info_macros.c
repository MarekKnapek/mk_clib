#include "mk_lang_info_macros.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"

#include <stdio.h> /* printf */


#define to_str_impl(x) #x
#define to_str(x) to_str_impl(x)


mk_lang_jumbo void mk_lang_info_macros_print_normal(void) mk_lang_noexcept
{
	#if defined __386__
	printf("Macro __386__ is \"" to_str(__386__) "\".\n");
	#else
	printf("Macro __386__ is not defined.\n");
	#endif

	#if defined __amd64__
	printf("Macro __amd64__ is \"" to_str(__amd64__) "\".\n");
	#else
	printf("Macro __amd64__ is not defined.\n");
	#endif

	#if defined __cplusplus
	printf("Macro __cplusplus is \"" to_str(__cplusplus) "\".\n");
	#else
	printf("Macro __cplusplus is not defined.\n");
	#endif

	#if defined __cpp_lib_unreachable
	printf("Macro __cpp_lib_unreachable is \"" to_str(__cpp_lib_unreachable) "\".\n");
	#else
	printf("Macro __cpp_lib_unreachable is not defined.\n");
	#endif

	#if defined __cpp_static_assert
	printf("Macro __cpp_static_assert is \"" to_str(__cpp_static_assert) "\".\n");
	#else
	printf("Macro __cpp_static_assert is not defined.\n");
	#endif

	#if defined __GNUC__
	printf("Macro __GNUC__ is \"" to_str(__GNUC__) "\".\n");
	#else
	printf("Macro __GNUC__ is not defined.\n");
	#endif

	#if defined __GNUC_MINOR__
	printf("Macro __GNUC_MINOR__ is \"" to_str(__GNUC_MINOR__) "\".\n");
	#else
	printf("Macro __GNUC_MINOR__ is not defined.\n");
	#endif

	#if defined __i386__
	printf("Macro __i386__ is \"" to_str(__i386__) "\".\n");
	#else
	printf("Macro __i386__ is not defined.\n");
	#endif

	#if defined __I86__
	printf("Macro __I86__ is \"" to_str(__I86__) "\".\n");
	#else
	printf("Macro __I86__ is not defined.\n");
	#endif

	#if defined __SIZEOF_INT128__
	printf("Macro __SIZEOF_INT128__ is \"" to_str(__SIZEOF_INT128__) "\".\n");
	#else
	printf("Macro __SIZEOF_INT128__ is not defined.\n");
	#endif

	#if defined __STDC_VERSION__
	printf("Macro __STDC_VERSION__ is \"" to_str(__STDC_VERSION__) "\".\n");
	#else
	printf("Macro __STDC_VERSION__ is not defined.\n");
	#endif

	#if defined __WATCOM_CPLUSPLUS__
	printf("Macro __WATCOM_CPLUSPLUS__ is \"" to_str(__WATCOM_CPLUSPLUS__) "\".\n");
	#else
	printf("Macro __WATCOM_CPLUSPLUS__ is not defined.\n");
	#endif

	#if defined __WATCOMC__
	printf("Macro __WATCOMC__ is \"" to_str(__WATCOMC__) "\".\n");
	#else
	printf("Macro __WATCOMC__ is not defined.\n");
	#endif

	#if defined _M_ALPHA
	printf("Macro _M_ALPHA is \"" to_str(_M_ALPHA) "\".\n");
	#else
	printf("Macro _M_ALPHA is not defined.\n");
	#endif

	#if defined _M_AMD64
	printf("Macro _M_AMD64 is \"" to_str(_M_AMD64) "\".\n");
	#else
	printf("Macro _M_AMD64 is not defined.\n");
	#endif

	#if defined _M_ARM
	printf("Macro _M_ARM is \"" to_str(_M_ARM) "\".\n");
	#else
	printf("Macro _M_ARM is not defined.\n");
	#endif

	#if defined _M_ARM64
	printf("Macro _M_ARM64 is \"" to_str(_M_ARM64) "\".\n");
	#else
	printf("Macro _M_ARM64 is not defined.\n");
	#endif

	#if defined _M_I386
	printf("Macro _M_I386 is \"" to_str(_M_I386) "\".\n");
	#else
	printf("Macro _M_I386 is not defined.\n");
	#endif

	#if defined _M_I86
	printf("Macro _M_I86 is \"" to_str(_M_I86) "\".\n");
	#else
	printf("Macro _M_I86 is not defined.\n");
	#endif

	#if defined _M_IA64
	printf("Macro _M_IA64 is \"" to_str(_M_IA64) "\".\n");
	#else
	printf("Macro _M_IA64 is not defined.\n");
	#endif

	#if defined _M_IX86
	printf("Macro _M_IX86 is \"" to_str(_M_IX86) "\".\n");
	#else
	printf("Macro _M_IX86 is not defined.\n");
	#endif

	#if defined _M_MPPC
	printf("Macro _M_MPPC is \"" to_str(_M_MPPC) "\".\n");
	#else
	printf("Macro _M_MPPC is not defined.\n");
	#endif

	#if defined _M_MRX000
	printf("Macro _M_MRX000 is \"" to_str(_M_MRX000) "\".\n");
	#else
	printf("Macro _M_MRX000 is not defined.\n");
	#endif

	#if defined _M_PPC
	printf("Macro _M_PPC is \"" to_str(_M_PPC) "\".\n");
	#else
	printf("Macro _M_PPC is not defined.\n");
	#endif

	#if defined _M_X64
	printf("Macro _M_X64 is \"" to_str(_M_X64) "\".\n");
	#else
	printf("Macro _M_X64 is not defined.\n");
	#endif

	#if defined _MSC_VER
	printf("Macro _MSC_VER is \"" to_str(_MSC_VER) "\".\n");
	#else
	printf("Macro _MSC_VER is not defined.\n");
	#endif

	#if defined _MSVC_LANG
	printf("Macro _MSVC_LANG is \"" to_str(_MSVC_LANG) "\".\n");
	#else
	printf("Macro _MSVC_LANG is not defined.\n");
	#endif

	#if defined INTPTR_MAX
	printf("Macro INTPTR_MAX is \"" to_str(INTPTR_MAX) "\".\n");
	#else
	printf("Macro INTPTR_MAX is not defined.\n");
	#endif

	#if defined INTPTR_MIN
	printf("Macro INTPTR_MIN is \"" to_str(INTPTR_MIN) "\".\n");
	#else
	printf("Macro INTPTR_MIN is not defined.\n");
	#endif

	#if defined M_I386
	printf("Macro M_I386 is \"" to_str(M_I386) "\".\n");
	#else
	printf("Macro M_I386 is not defined.\n");
	#endif

	#if defined M_I86
	printf("Macro M_I86 is \"" to_str(M_I86) "\".\n");
	#else
	printf("Macro M_I86 is not defined.\n");
	#endif

	#if defined mk_lang_assert_want
	printf("Macro mk_lang_assert_want is \"" to_str(mk_lang_assert_want) "\".\n");
	#else
	printf("Macro mk_lang_assert_want is not defined.\n");
	#endif

	#if defined mk_lang_jumbo_want
	printf("Macro mk_lang_jumbo_want is \"" to_str(mk_lang_jumbo_want) "\".\n");
	#else
	printf("Macro mk_lang_jumbo_want is not defined.\n");
	#endif

	#if defined NDEBUG
	printf("Macro NDEBUG is \"" to_str(NDEBUG) "\".\n");
	#else
	printf("Macro NDEBUG is not defined.\n");
	#endif

	#if defined UINTPTR_MAX
	printf("Macro UINTPTR_MAX is \"" to_str(UINTPTR_MAX) "\".\n");
	#else
	printf("Macro UINTPTR_MAX is not defined.\n");
	#endif
}

mk_lang_jumbo void mk_lang_info_macros_print_has_builtin(void) mk_lang_noexcept
{
	#if defined __has_builtin
	printf("__has_builtin(__builtin_unreachable) " to_str(__has_builtin(__builtin_unreachable)) "\n");
	printf("__has_builtin(__builtin_debugtrap) " to_str(__has_builtin(__builtin_debugtrap)) "\n");
	printf("__has_builtin(__builtin_trap) " to_str(__has_builtin(__builtin_trap)) "\n");
	#endif
}


mk_lang_jumbo void mk_lang_info_macros_print(void) mk_lang_noexcept
{
	mk_lang_info_macros_print_normal();
	mk_lang_info_macros_print_has_builtin();
}


#undef to_str_impl
#undef to_str
