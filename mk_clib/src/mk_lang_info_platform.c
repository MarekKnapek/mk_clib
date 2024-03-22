#include "mk_lang_info_platform.h"

#include "mk_lang_arch.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"

#include <stdio.h> /* printf */


mk_lang_jumbo mk_lang_types_void_t mk_lang_info_platform_print(mk_lang_types_void_t) mk_lang_noexcept
{
	#if 0
	#elif mk_lang_arch == mk_lang_arch_x8616
	printf("platform: x8616\n");
	#elif mk_lang_arch == mk_lang_arch_x8632
	printf("platform: x8632\n");
	#elif mk_lang_arch == mk_lang_arch_x8664
	printf("platform: x8664\n");
	#elif mk_lang_arch == mk_lang_arch_ia64
	printf("platform: ia64\n");
	#elif mk_lang_arch == mk_lang_arch_alpha
	printf("platform: alpha\n");
	#elif mk_lang_arch == mk_lang_arch_ppc
	printf("platform: ppc\n");
	#elif mk_lang_arch == mk_lang_arch_mips
	printf("platform: mips\n");
	#elif mk_lang_arch == mk_lang_arch_arm32
	printf("platform: arm32\n");
	#elif mk_lang_arch == mk_lang_arch_arm64
	printf("platform: arm64\n");
	#elif mk_lang_arch == mk_lang_arch_arm64ec
	printf("platform: arm64ec\n");
	#elif mk_lang_arch == mk_lang_arch_emscripten
	printf("platform: emscripten\n");
	#else
	#error todo xxxxxxxxxx
	#endif
	printf("\n");

	printf("at_least_c_89       : %s\n", mk_lang_version_at_least_c_89 == 1 ? "yes" : "no");
	printf("at_least_c_90       : %s\n", mk_lang_version_at_least_c_90 == 1 ? "yes" : "no");
	printf("at_least_c_99       : %s\n", mk_lang_version_at_least_c_99 == 1 ? "yes" : "no");
	printf("at_least_c_11       : %s\n", mk_lang_version_at_least_c_11 == 1 ? "yes" : "no");
	printf("at_least_c_18       : %s\n", mk_lang_version_at_least_c_18 == 1 ? "yes" : "no");
	printf("at_least_c_23       : %s\n", mk_lang_version_at_least_c_23 == 1 ? "yes" : "no");
	printf("at_least_cpp_98     : %s\n", mk_lang_version_at_least_cpp_98 == 1 ? "yes" : "no");
	printf("at_least_cpp_11     : %s\n", mk_lang_version_at_least_cpp_11 == 1 ? "yes" : "no");
	printf("at_least_cpp_14     : %s\n", mk_lang_version_at_least_cpp_14 == 1 ? "yes" : "no");
	printf("at_least_cpp_17     : %s\n", mk_lang_version_at_least_cpp_17 == 1 ? "yes" : "no");
	printf("at_least_cpp_20     : %s\n", mk_lang_version_at_least_cpp_20 == 1 ? "yes" : "no");
	printf("at_least_cpp_23     : %s\n", mk_lang_version_at_least_cpp_23 == 1 ? "yes" : "no");
	printf("at_least_msvc_cpp_11: %s\n", mk_lang_version_at_least_msvc_cpp_11 == 1 ? "yes" : "no");
	printf("at_least_msvc_cpp_14: %s\n", mk_lang_version_at_least_msvc_cpp_14 == 1 ? "yes" : "no");
	printf("at_least_msvc_cpp_17: %s\n", mk_lang_version_at_least_msvc_cpp_17 == 1 ? "yes" : "no");
	printf("at_least_msvc_cpp_20: %s\n", mk_lang_version_at_least_msvc_cpp_20 == 1 ? "yes" : "no");
	printf("\n");

	#if defined _MSC_VER
	printf("_MSC_VER " mk_lang_stringify(_MSC_VER) "\n");
	#else
	printf("_MSC_VER not defined\n");
	#endif

	#if defined _MSC_FULL_VER
	printf("_MSC_FULL_VER " mk_lang_stringify(_MSC_FULL_VER) "\n");
	#else
	printf("_MSC_FULL_VER not defined\n");
	#endif

	#if defined __GNUC__
	printf("__GNUC__ " mk_lang_stringify(__GNUC__) "\n");
	#else
	printf("__GNUC__ not defined\n");
	#endif

	#if defined __GNUC_MINOR__
	printf("__GNUC_MINOR__ " mk_lang_stringify(__GNUC_MINOR__) "\n");
	#else
	printf("__GNUC_MINOR__ not defined\n");
	#endif

	#if defined __clang_major__
	printf("__clang_major__ " mk_lang_stringify(__clang_major__) "\n");
	#else
	printf("__clang_major__ not defined\n");
	#endif

	#if defined __clang_minor__
	printf("__clang_minor__ " mk_lang_stringify(__clang_minor__) "\n");
	#else
	printf("__clang_minor__ not defined\n");
	#endif

	#if defined __WATCOMC__
	printf("__WATCOMC__ " mk_lang_stringify(__WATCOMC__) "\n");
	#else
	printf("__WATCOMC__ not defined\n");
	#endif

	#if defined __WATCOM_CPLUSPLUS__
	printf("__WATCOM_CPLUSPLUS__ " mk_lang_stringify(__WATCOM_CPLUSPLUS__) "\n");
	#else
	printf("__WATCOM_CPLUSPLUS__ not defined\n");
	#endif

	printf("\n");

	#if mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664
	mk_lang_cpuid_init();
	printf("ssse3   : %s\n", mk_lang_cpuid_has_ssse3()    ? "yes" : "no");
	printf("sse41   : %s\n", mk_lang_cpuid_has_sse41()    ? "yes" : "no");
	printf("popcnt  : %s\n", mk_lang_cpuid_has_popcnt()   ? "yes" : "no");
	printf("aes_ni  : %s\n", mk_lang_cpuid_has_aes_ni()   ? "yes" : "no");
	printf("avx     : %s\n", mk_lang_cpuid_has_avx()      ? "yes" : "no");
	printf("sse     : %s\n", mk_lang_cpuid_has_sse()      ? "yes" : "no");
	printf("sse2    : %s\n", mk_lang_cpuid_has_sse2()     ? "yes" : "no");
	printf("avx2    : %s\n", mk_lang_cpuid_has_avx2()     ? "yes" : "no");
	printf("avx512_f: %s\n", mk_lang_cpuid_has_avx512_f() ? "yes" : "no");
	printf("sha     : %s\n", mk_lang_cpuid_has_sha()      ? "yes" : "no");
	printf("\n");
	#endif
}
