#ifndef mk_include_guard_mk_lang_alignof
#define mk_include_guard_mk_lang_alignof

#include "mk_lang_arch.h"
#include "mk_lang_intmaxt.h"
#include "mk_lang_lllong.h"
#include "mk_lang_llong.h"
#include "mk_lang_min.h"
#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_14
#define mk_lang_alignof_has 1
#define mk_lang_alignof(x) alignof(x)
#elif mk_lang_version_at_least_c_11
#define mk_lang_alignof_has 1
#define mk_lang_alignof(x) _Alignof(x)
#else
#define mk_lang_alignof_has 0
#define mk_lang_alignof(x) mk_lang_min(16, sizeof(x))
#endif


#define mk_lang_alignof_bi_pchar_t 1
#define mk_lang_alignof_bi_uchar_t mk_lang_alignof_bi_pchar_t
#define mk_lang_alignof_bi_schar_t mk_lang_alignof_bi_pchar_t

#define mk_lang_alignof_bi_ushort_t 2
#define mk_lang_alignof_bi_sshort_t mk_lang_alignof_bi_ushort_t

#if mk_lang_arch == mk_lang_arch_x8616
#define mk_lang_alignof_bi_uint_t 2
#else
#define mk_lang_alignof_bi_uint_t 4
#endif
#define mk_lang_alignof_bi_sint_t mk_lang_alignof_bi_uint_t

#if defined __SIZEOF_LONG__
#define mk_lang_alignof_bi_ulong_t __SIZEOF_LONG__
#else
#define mk_lang_alignof_bi_ulong_t 4
#endif
#define mk_lang_alignof_bi_slong_t mk_lang_alignof_bi_ulong_t

#if mk_lang_llong_has == 1
#define mk_lang_alignof_bi_ullong_t 8
#elif mk_lang_llong_has == 0
#define mk_lang_alignof_bi_ullong_t mk_lang_alignof_bi_ulong_t
#endif
#define mk_lang_alignof_bi_sllong_t mk_lang_alignof_bi_ullong_t

#if mk_lang_lllong_has == 1
#define mk_lang_alignof_bi_ulllong_t 16
#elif mk_lang_lllong_has == 0
#define mk_lang_alignof_bi_ulllong_t mk_lang_alignof_bi_ullong_t
#endif
#define mk_lang_alignof_bi_slllong_t mk_lang_alignof_bi_ulllong_t

#if mk_lang_bitness == mk_lang_bitness_16
#define mk_lang_alignof_bi_uintptr_t 2
#elif mk_lang_bitness == mk_lang_bitness_32
#define mk_lang_alignof_bi_uintptr_t 4
#elif mk_lang_bitness == mk_lang_bitness_64
#define mk_lang_alignof_bi_uintptr_t 8
#endif
#define mk_lang_alignof_bi_sintptr_t mk_lang_alignof_bi_uintptr_t

#if mk_lang_intmaxt_has == 1
#define mk_lang_alignof_bi_uintmax_t mk_lang_alignof_bi_ullong_t
#elif mk_lang_intmaxt_has == 0
#define mk_lang_alignof_bi_uintmax_t mk_lang_alignof_bi_ulllong_t
#endif
#define mk_lang_alignof_bi_sintmax_t mk_lang_alignof_bi_uintmax_t

#if mk_lang_bitness == mk_lang_bitness_16
#define mk_lang_alignof_bi_size_t 2
#elif mk_lang_bitness == mk_lang_bitness_32
#define mk_lang_alignof_bi_size_t 4
#elif mk_lang_bitness == mk_lang_bitness_64
#define mk_lang_alignof_bi_size_t 8
#endif


#endif
