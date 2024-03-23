#ifndef mk_include_guard_mk_lang_cpuid
#define mk_include_guard_mk_lang_cpuid


#include "mk_lang_arch.h"
#include "mk_lang_gnuc.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#if mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1 && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664)


#if mk_lang_arch == mk_lang_arch_x8664
#define mk_lang_cpuid_has_sse() 1
#elif defined _M_IX86_FP && _M_IX86_FP >= 1
#define mk_lang_cpuid_has_sse() 1
#else
#define mk_lang_cpuid_has_sse() mk_lang_cpuid_has_sse_impl()
#endif

#if mk_lang_arch == mk_lang_arch_x8664
#define mk_lang_cpuid_has_sse2() 1
#elif defined _M_IX86_FP && _M_IX86_FP >= 2
#define mk_lang_cpuid_has_sse2() 1
#else
#define mk_lang_cpuid_has_sse2() mk_lang_cpuid_has_sse2_impl()
#endif


mk_lang_jumbo mk_lang_types_void_t mk_lang_cpuid_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_lang_cpuid_reset(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_ssse3(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse41(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_popcnt(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_aes_ni(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse_impl(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse2_impl(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx2(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx512_f(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sha(mk_lang_types_void_t) mk_lang_noexcept;


#elif mk_lang_gnuc_is_at_least(4, 1) && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664)


mk_lang_jumbo mk_lang_types_void_t mk_lang_cpuid_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_lang_cpuid_reset(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_ssse3(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse41(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_popcnt(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_aes_ni(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse2(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx2(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_avx512_f(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sha(mk_lang_types_void_t) mk_lang_noexcept;


#else


#define mk_lang_cpuid_init()
#define mk_lang_cpuid_reset()
#define mk_lang_cpuid_has_ssse3() 0
#define mk_lang_cpuid_has_sse41() 0
#define mk_lang_cpuid_has_popcnt() 0
#define mk_lang_cpuid_has_aes_ni() 0
#define mk_lang_cpuid_has_avx() 0
#define mk_lang_cpuid_has_sse() 0
#define mk_lang_cpuid_has_sse2() 0
#define mk_lang_cpuid_has_avx2() 0
#define mk_lang_cpuid_has_avx512_f() 0
#define mk_lang_cpuid_has_sha() 0


#endif


#if mk_lang_jumbo_want == 1
#include "mk_lang_cpuid.c"
#endif
#endif
