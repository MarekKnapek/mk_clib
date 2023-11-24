#ifndef mk_include_guard_mk_lang_cpuid
#define mk_include_guard_mk_lang_cpuid


#include "mk_lang_arch.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#if(mk_lang_arch == mk_lang_arch_x8664)
#define mk_lang_cpuid_has_sse() 1
#elif(defined _M_IX86_FP && _M_IX86_FP >= 1)
#define mk_lang_cpuid_has_sse() 1
#else
#define mk_lang_cpuid_has_sse() mk_lang_cpuid_has_sse_impl()
#endif

#if(mk_lang_arch == mk_lang_arch_x8664)
#define mk_lang_cpuid_has_sse2() 1
#elif(defined _M_IX86_FP && _M_IX86_FP >= 2)
#define mk_lang_cpuid_has_sse2() 1
#else
#define mk_lang_cpuid_has_sse2() mk_lang_cpuid_has_sse2_impl()
#endif


mk_lang_jumbo void mk_lang_cpuid_init(void) mk_lang_noexcept;
mk_lang_jumbo void mk_lang_cpuid_reset(void) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_ssse3(void) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse41(void) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_popcnt(void) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_aes_ni(void) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx(void) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse_impl(void) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse2_impl(void) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx2(void) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx512_f(void) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sha(void) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lang_cpuid.c"
#endif
#endif
