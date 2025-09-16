#ifndef mk_include_guard_mk_lang_info_platform_c
#define mk_include_guard_mk_lang_info_platform_c
#include "mk_lang_info_platform.h"

#include "mk_lang_alignas.h"
#include "mk_lang_alignof.h"
#include "mk_lang_arch.h"
#include "mk_lang_asan.h"
#include "mk_lang_check.h"
#include "mk_lang_configuration.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_crash.h"
#include "mk_lang_fuzzer.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_lllong.h"
#include "mk_lang_llong.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_stdout.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_info_platform_print(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#if 0
	#elif mk_lang_arch == mk_lang_arch_x8616
	err = mk_lang_stdout_println_lit_n("Architecture: x8616"); mk_lang_check_rereturn(err);
	#elif mk_lang_arch == mk_lang_arch_x8632
	err = mk_lang_stdout_println_lit_n("Architecture: x8632"); mk_lang_check_rereturn(err);
	#elif mk_lang_arch == mk_lang_arch_x8664
	err = mk_lang_stdout_println_lit_n("Architecture: x8664"); mk_lang_check_rereturn(err);
	#elif mk_lang_arch == mk_lang_arch_ia64
	err = mk_lang_stdout_println_lit_n("Architecture: ia64"); mk_lang_check_rereturn(err);
	#elif mk_lang_arch == mk_lang_arch_alpha
	err = mk_lang_stdout_println_lit_n("Architecture: alpha"); mk_lang_check_rereturn(err);
	#elif mk_lang_arch == mk_lang_arch_ppc
	err = mk_lang_stdout_println_lit_n("Architecture: ppc"); mk_lang_check_rereturn(err);
	#elif mk_lang_arch == mk_lang_arch_mips
	err = mk_lang_stdout_println_lit_n("Architecture: mips"); mk_lang_check_rereturn(err);
	#elif mk_lang_arch == mk_lang_arch_arm32
	err = mk_lang_stdout_println_lit_n("Architecture: arm32"); mk_lang_check_rereturn(err);
	#elif mk_lang_arch == mk_lang_arch_arm64
	err = mk_lang_stdout_println_lit_n("Architecture: arm64"); mk_lang_check_rereturn(err);
	#elif mk_lang_arch == mk_lang_arch_arm64ec
	err = mk_lang_stdout_println_lit_n("Architecture: arm64ec"); mk_lang_check_rereturn(err);
	#elif mk_lang_arch == mk_lang_arch_emscripten
	err = mk_lang_stdout_println_lit_n("Architecture: emscripten"); mk_lang_check_rereturn(err);
	#else
	#error xxxxxxxxxx
	#endif

	#if 0
	#elif mk_lang_platform == mk_lang_platform_windows
	err = mk_lang_stdout_println_lit_n("Platform: Windows"); mk_lang_check_rereturn(err);
	#elif mk_lang_platform == mk_lang_platform_linux
	err = mk_lang_stdout_println_lit_n("Platform: Linux"); mk_lang_check_rereturn(err);
	#elif mk_lang_platform == mk_lang_platform_posix
	err = mk_lang_stdout_println_lit_n("Platform: POSIX"); mk_lang_check_rereturn(err);
	#elif mk_lang_platform == mk_lang_platform_portable
	err = mk_lang_stdout_println_lit_n("Platform: Portable"); mk_lang_check_rereturn(err);
	#else
	#error xxxxxxxxxx
	#endif

	#if 0
	#elif mk_lang_platform_is_windows_at_least_62
	err = mk_lang_stdout_println_lit_n("Platform version: Windows 6.2 (Windows 8 / Windows Server 2012)"); mk_lang_check_rereturn(err);
	#elif mk_lang_platform_is_windows_at_least_61
	err = mk_lang_stdout_println_lit_n("Platform version: Windows 6.1 (Windows 7 / Windows Server 2008 R2)"); mk_lang_check_rereturn(err);
	#elif mk_lang_platform_is_windows_at_least_60
	err = mk_lang_stdout_println_lit_n("Platform version: Windows 6.0 (Windows Vista / Windows Server 2008)"); mk_lang_check_rereturn(err);
	#elif mk_lang_platform_is_windows_at_least_51
	err = mk_lang_stdout_println_lit_n("Platform version: Windows 5.1 (Windows XP)"); mk_lang_check_rereturn(err);
	#elif mk_lang_platform_is_windows_at_least_any
	err = mk_lang_stdout_println_lit_n("Platform version: Windows"); mk_lang_check_rereturn(err);
	#endif

	#if 0
	#elif mk_lang_platform_is_posix_at_least_2024_05
	err = mk_lang_stdout_println_lit_n("Platform version: POSIX 2024"); mk_lang_check_rereturn(err);
	#elif mk_lang_platform_is_posix_at_least_2008_09
	err = mk_lang_stdout_println_lit_n("Platform version: POSIX 2008"); mk_lang_check_rereturn(err);
	#elif mk_lang_platform_is_posix_at_least_2001_12
	err = mk_lang_stdout_println_lit_n("Platform version: POSIX 2001"); mk_lang_check_rereturn(err);
	#elif mk_lang_platform_is_posix_at_least_1995_06
	err = mk_lang_stdout_println_lit_n("Platform version: POSIX 1995"); mk_lang_check_rereturn(err);
	#elif mk_lang_platform_is_posix_at_least_1993_09
	err = mk_lang_stdout_println_lit_n("Platform version: POSIX 1993"); mk_lang_check_rereturn(err);
	#elif mk_lang_platform_is_posix_at_least_2
	err = mk_lang_stdout_println_lit_n("Platform version: POSIX 1992"); mk_lang_check_rereturn(err);
	#elif mk_lang_platform_is_posix_at_least_1
	err = mk_lang_stdout_println_lit_n("Platform version: POSIX 1990"); mk_lang_check_rereturn(err);
	#endif

	err = mk_lang_stdout_print_lit_n("Configuration: "); mk_lang_check_rereturn(err); err = mk_lang_configuration_is_debug ? mk_lang_stdout_println_lit_n("Debug") : (mk_lang_configuration_is_release ? mk_lang_stdout_println_lit_n("Release") : (mk_lang_crash(), 0)); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("ASAN: "); mk_lang_check_rereturn(err); err = mk_lang_asan_has ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("Fuzzer: "); mk_lang_check_rereturn(err); err = mk_lang_fuzzer_has ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);

	err = mk_lang_stdout_println_lit_n(""); mk_lang_check_rereturn(err);

	err = mk_lang_stdout_print_lit_n("mk_lang_alignas_has: "); mk_lang_check_rereturn(err); err = mk_lang_alignas_has ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("mk_lang_alignof_has: "); mk_lang_check_rereturn(err); err = mk_lang_alignof_has ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("mk_lang_llong_has  : "); mk_lang_check_rereturn(err); err = mk_lang_llong_has   ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("mk_lang_lllong_has : "); mk_lang_check_rereturn(err); err = mk_lang_lllong_has  ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);

	err = mk_lang_stdout_println_lit_n(""); mk_lang_check_rereturn(err);

	err = mk_lang_stdout_print_lit_n("at_least_c_89       : "); mk_lang_check_rereturn(err); err = mk_lang_version_at_least_c_89 == 1 ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("at_least_c_90       : "); mk_lang_check_rereturn(err); err = mk_lang_version_at_least_c_90 == 1 ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("at_least_c_99       : "); mk_lang_check_rereturn(err); err = mk_lang_version_at_least_c_99 == 1 ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("at_least_c_11       : "); mk_lang_check_rereturn(err); err = mk_lang_version_at_least_c_11 == 1 ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("at_least_c_17       : "); mk_lang_check_rereturn(err); err = mk_lang_version_at_least_c_17 == 1 ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("at_least_c_23       : "); mk_lang_check_rereturn(err); err = mk_lang_version_at_least_c_23 == 1 ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("at_least_cpp_98     : "); mk_lang_check_rereturn(err); err = mk_lang_version_at_least_cpp_98 == 1 ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("at_least_cpp_11     : "); mk_lang_check_rereturn(err); err = mk_lang_version_at_least_cpp_11 == 1 ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("at_least_cpp_14     : "); mk_lang_check_rereturn(err); err = mk_lang_version_at_least_cpp_14 == 1 ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("at_least_cpp_17     : "); mk_lang_check_rereturn(err); err = mk_lang_version_at_least_cpp_17 == 1 ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("at_least_cpp_20     : "); mk_lang_check_rereturn(err); err = mk_lang_version_at_least_cpp_20 == 1 ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("at_least_cpp_23     : "); mk_lang_check_rereturn(err); err = mk_lang_version_at_least_cpp_23 == 1 ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("at_least_msvc_cpp_11: "); mk_lang_check_rereturn(err); err = mk_lang_version_at_least_msvc_cpp_11 == 1 ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("at_least_msvc_cpp_14: "); mk_lang_check_rereturn(err); err = mk_lang_version_at_least_msvc_cpp_14 == 1 ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("at_least_msvc_cpp_17: "); mk_lang_check_rereturn(err); err = mk_lang_version_at_least_msvc_cpp_17 == 1 ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("at_least_msvc_cpp_20: "); mk_lang_check_rereturn(err); err = mk_lang_version_at_least_msvc_cpp_20 == 1 ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);

	err = mk_lang_stdout_println_lit_n(""); mk_lang_check_rereturn(err);

	#if defined _MSC_VER
	err = mk_lang_stdout_println_lit_n("_MSC_VER             " mk_lang_stringify(_MSC_VER) ""); mk_lang_check_rereturn(err);
	#else
	err = mk_lang_stdout_println_lit_n("_MSC_VER             not defined"); mk_lang_check_rereturn(err);
	#endif

	#if defined _MSC_FULL_VER
	err = mk_lang_stdout_println_lit_n("_MSC_FULL_VER        " mk_lang_stringify(_MSC_FULL_VER) ""); mk_lang_check_rereturn(err);
	#else
	err = mk_lang_stdout_println_lit_n("_MSC_FULL_VER        not defined"); mk_lang_check_rereturn(err);
	#endif

	#if defined __GNUC__
	err = mk_lang_stdout_println_lit_n("__GNUC__             " mk_lang_stringify(__GNUC__) ""); mk_lang_check_rereturn(err);
	#else
	err = mk_lang_stdout_println_lit_n("__GNUC__             not defined"); mk_lang_check_rereturn(err);
	#endif

	#if defined __GNUC_MINOR__
	err = mk_lang_stdout_println_lit_n("__GNUC_MINOR__       " mk_lang_stringify(__GNUC_MINOR__) ""); mk_lang_check_rereturn(err);
	#else
	err = mk_lang_stdout_println_lit_n("__GNUC_MINOR__       not defined"); mk_lang_check_rereturn(err);
	#endif

	#if defined __clang_major__
	err = mk_lang_stdout_println_lit_n("__clang_major__      " mk_lang_stringify(__clang_major__) ""); mk_lang_check_rereturn(err);
	#else
	err = mk_lang_stdout_println_lit_n("__clang_major__      not defined"); mk_lang_check_rereturn(err);
	#endif

	#if defined __clang_minor__
	err = mk_lang_stdout_println_lit_n("__clang_minor__      " mk_lang_stringify(__clang_minor__) ""); mk_lang_check_rereturn(err);
	#else
	err = mk_lang_stdout_println_lit_n("__clang_minor__      not defined"); mk_lang_check_rereturn(err);
	#endif

	#if defined __WATCOMC__
	err = mk_lang_stdout_println_lit_n("__WATCOMC__          " mk_lang_stringify(__WATCOMC__) ""); mk_lang_check_rereturn(err);
	#else
	err = mk_lang_stdout_println_lit_n("__WATCOMC__          not defined"); mk_lang_check_rereturn(err);
	#endif

	#if defined __WATCOM_CPLUSPLUS__
	err = mk_lang_stdout_println_lit_n("__WATCOM_CPLUSPLUS__ " mk_lang_stringify(__WATCOM_CPLUSPLUS__) ""); mk_lang_check_rereturn(err);
	#else
	err = mk_lang_stdout_println_lit_n("__WATCOM_CPLUSPLUS__ not defined"); mk_lang_check_rereturn(err);
	#endif

	#if defined __TINYC__
	err = mk_lang_stdout_println_lit_n("__TINYC__            " mk_lang_stringify(__TINYC__) ""); mk_lang_check_rereturn(err);
	#else
	err = mk_lang_stdout_println_lit_n("__TINYC__            not defined"); mk_lang_check_rereturn(err);
	#endif

	err = mk_lang_stdout_println_lit_n(""); mk_lang_check_rereturn(err);

	#if mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664
	mk_lang_cpuid_init();
	err = mk_lang_stdout_print_lit_n("pclmulqdq: "); mk_lang_check_rereturn(err); err = mk_lang_cpuid_has_pclmulqdq() ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("ssse3    : "); mk_lang_check_rereturn(err); err = mk_lang_cpuid_has_ssse3()     ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sse41    : "); mk_lang_check_rereturn(err); err = mk_lang_cpuid_has_sse41()     ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("popcnt   : "); mk_lang_check_rereturn(err); err = mk_lang_cpuid_has_popcnt()    ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("aesni    : "); mk_lang_check_rereturn(err); err = mk_lang_cpuid_has_aesni()     ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("avx      : "); mk_lang_check_rereturn(err); err = mk_lang_cpuid_has_avx()       ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sse      : "); mk_lang_check_rereturn(err); err = mk_lang_cpuid_has_sse()       ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sse2     : "); mk_lang_check_rereturn(err); err = mk_lang_cpuid_has_sse2()      ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("avx2     : "); mk_lang_check_rereturn(err); err = mk_lang_cpuid_has_avx2()      ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("avx512_f : "); mk_lang_check_rereturn(err); err = mk_lang_cpuid_has_avx512_f()  ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sha      : "); mk_lang_check_rereturn(err); err = mk_lang_cpuid_has_sha()       ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("avx512_vl: "); mk_lang_check_rereturn(err); err = mk_lang_cpuid_has_avx512_vl() ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("vaes     : "); mk_lang_check_rereturn(err); err = mk_lang_cpuid_has_vaes()      ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sha512   : "); mk_lang_check_rereturn(err); err = mk_lang_cpuid_has_sha512()    ? mk_lang_stdout_println_lit_n("yes") : mk_lang_stdout_println_lit_n("no"); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_println_lit_n(""); mk_lang_check_rereturn(err);
	#endif

	return 0;
}


#endif
