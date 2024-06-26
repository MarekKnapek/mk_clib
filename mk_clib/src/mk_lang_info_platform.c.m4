#include "mk_lang_info_platform.h"

#include "mk_lang_arch.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"

#include <stdio.h> /* printf */


mk_lang_jumbo mk_lang_types_void_t mk_lang_info_platform_print(mk_lang_types_void_t) mk_lang_noexcept
{
	#if 0
	#elif mk_lang_arch == mk_lang_arch_x8616
	printf("Architecture: x8616\n");
	#elif mk_lang_arch == mk_lang_arch_x8632
	printf("Architecture: x8632\n");
	#elif mk_lang_arch == mk_lang_arch_x8664
	printf("Architecture: x8664\n");
	#elif mk_lang_arch == mk_lang_arch_ia64
	printf("Architecture: ia64\n");
	#elif mk_lang_arch == mk_lang_arch_alpha
	printf("Architecture: alpha\n");
	#elif mk_lang_arch == mk_lang_arch_ppc
	printf("Architecture: ppc\n");
	#elif mk_lang_arch == mk_lang_arch_mips
	printf("Architecture: mips\n");
	#elif mk_lang_arch == mk_lang_arch_arm32
	printf("Architecture: arm32\n");
	#elif mk_lang_arch == mk_lang_arch_arm64
	printf("Architecture: arm64\n");
	#elif mk_lang_arch == mk_lang_arch_arm64ec
	printf("Architecture: arm64ec\n");
	#elif mk_lang_arch == mk_lang_arch_emscripten
	printf("Architecture: emscripten\n");
	#else
	#error xxxxxxxxxx todo
	#endif
	#if 0
	#elif mk_lang_platform == mk_lang_platform_windows_61
	printf("Platform: Windows 6.1\n");
	#elif mk_lang_platform == mk_lang_platform_windows_60
	printf("Platform: Windows 6.0\n");
	#elif mk_lang_platform == mk_lang_platform_windows
	printf("Platform: Windows\n");
	#elif mk_lang_platform == mk_lang_platform_linux
	printf("Platform: Linux\n");
	#elif mk_lang_platform == mk_lang_platform_portable
	printf("Platform: Portable\n");
	#else
	#error xxxxxxxxxx todo
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
define(`test_macro', `
	#if defined $1
	printf("$1 substr(`                                        ', 1, eval(20 - len($1)))" mk_lang_stringify($1) "\n");
	#else
	printf("$1 substr(`                                        ', 1, eval(20 - len($1)))not defined\n");
	#endif')dnl
test_macro(`_MSC_VER')
test_macro(`_MSC_FULL_VER')
test_macro(`__GNUC__')
test_macro(`__GNUC_MINOR__')
test_macro(`__clang_major__')
test_macro(`__clang_minor__')
test_macro(`__WATCOMC__')
test_macro(`__WATCOM_CPLUSPLUS__')
test_macro(`__TINYC__')
undefine(`test_macro')dnl

	printf("\n");

	#if mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664
	mk_lang_cpuid_init();
	printf("pclmulqdq: %s\n", mk_lang_cpuid_has_pclmulqdq() ? "yes" : "no");
	printf("ssse3    : %s\n", mk_lang_cpuid_has_ssse3()     ? "yes" : "no");
	printf("sse41    : %s\n", mk_lang_cpuid_has_sse41()     ? "yes" : "no");
	printf("popcnt   : %s\n", mk_lang_cpuid_has_popcnt()    ? "yes" : "no");
	printf("aesni    : %s\n", mk_lang_cpuid_has_aesni()     ? "yes" : "no");
	printf("avx      : %s\n", mk_lang_cpuid_has_avx()       ? "yes" : "no");
	printf("sse      : %s\n", mk_lang_cpuid_has_sse()       ? "yes" : "no");
	printf("sse2     : %s\n", mk_lang_cpuid_has_sse2()      ? "yes" : "no");
	printf("avx2     : %s\n", mk_lang_cpuid_has_avx2()      ? "yes" : "no");
	printf("vaes     : %s\n", mk_lang_cpuid_has_vaes()      ? "yes" : "no");
	printf("avx512_f : %s\n", mk_lang_cpuid_has_avx512_f()  ? "yes" : "no");
	printf("sha      : %s\n", mk_lang_cpuid_has_sha()       ? "yes" : "no");
	printf("avx512_vl: %s\n", mk_lang_cpuid_has_avx512_vl() ? "yes" : "no");
	printf("sha512   : %s\n", mk_lang_cpuid_has_sha512()    ? "yes" : "no");
	printf("\n");
	#endif
}
