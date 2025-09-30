#ifndef mk_include_guard_mk_lang_sizeof_h
#define mk_include_guard_mk_lang_sizeof_h


#include "mk_lang_arch.h"
#include "mk_lang_bitness.h"
#include "mk_lang_intmaxt.h"
#include "mk_lang_lllong.h"
#include "mk_lang_llong.h"
#include "mk_lang_msvc.h"
#include "mk_lang_version.h"


#if defined __cplusplus
#define mk_lang_sizeof_bi_bool_t 1
#elif mk_lang_version_at_least_c_23 && (mk_lang_msvc_ver == 0 || mk_lang_msvc_ver >= 9999l) /* todo when msvc starts supporting this */
#define mk_lang_sizeof_bi_bool_t 1
#elif mk_lang_version_at_least_c_99
#define mk_lang_sizeof_bi_bool_t 1
#else
#define mk_lang_sizeof_bi_bool_t mk_lang_sizeof_bi_sint_t
#endif

#define mk_lang_sizeof_bi_pchar_t 1
#define mk_lang_sizeof_bi_uchar_t mk_lang_sizeof_bi_pchar_t
#define mk_lang_sizeof_bi_schar_t mk_lang_sizeof_bi_pchar_t

#if defined __SIZEOF_WCHAR_T__
#define mk_lang_sizeof_bi_wchar_t __SIZEOF_WCHAR_T__
#elif defined __TINYC__ && !defined _WIN32
#define mk_lang_sizeof_bi_wchar_t 4
#else
#define mk_lang_sizeof_bi_wchar_t 2
#endif

#define mk_lang_sizeof_bi_ushort_t 2
#define mk_lang_sizeof_bi_sshort_t mk_lang_sizeof_bi_ushort_t

#if mk_lang_arch == mk_lang_arch_x8616
#define mk_lang_sizeof_bi_uint_t 2
#else
#define mk_lang_sizeof_bi_uint_t 4
#endif
#define mk_lang_sizeof_bi_sint_t mk_lang_sizeof_bi_uint_t

#if defined __SIZEOF_LONG__
#define mk_lang_sizeof_bi_ulong_t __SIZEOF_LONG__
#elif defined __TINYC__ && defined LONG_SIZE
#define mk_lang_sizeof_bi_ulong_t LONG_SIZE
#else
#define mk_lang_sizeof_bi_ulong_t 4
#endif
#define mk_lang_sizeof_bi_slong_t mk_lang_sizeof_bi_ulong_t

#if mk_lang_llong_has == 1
#define mk_lang_sizeof_bi_ullong_t 8
#elif mk_lang_llong_has == 0
#define mk_lang_sizeof_bi_ullong_t mk_lang_sizeof_bi_ulong_t
#endif
#define mk_lang_sizeof_bi_sllong_t mk_lang_sizeof_bi_ullong_t

#if mk_lang_lllong_has == 1
#define mk_lang_sizeof_bi_ulllong_t 16
#elif mk_lang_lllong_has == 0
#define mk_lang_sizeof_bi_ulllong_t mk_lang_sizeof_bi_ullong_t
#endif
#define mk_lang_sizeof_bi_slllong_t mk_lang_sizeof_bi_ulllong_t

#if mk_lang_bitness_is_16
#define mk_lang_sizeof_bi_uintptr_t 2
#elif mk_lang_bitness_is_32
#define mk_lang_sizeof_bi_uintptr_t 4
#elif mk_lang_bitness_is_64
#define mk_lang_sizeof_bi_uintptr_t 8
#endif
#define mk_lang_sizeof_bi_sintptr_t mk_lang_sizeof_bi_uintptr_t

#if mk_lang_intmaxt_has == 1
#define mk_lang_sizeof_bi_uintmax_t mk_lang_sizeof_bi_ullong_t
#elif mk_lang_intmaxt_has == 0
#define mk_lang_sizeof_bi_uintmax_t mk_lang_sizeof_bi_ulllong_t
#endif
#define mk_lang_sizeof_bi_sintmax_t mk_lang_sizeof_bi_uintmax_t

#if mk_lang_bitness_is_16
#define mk_lang_sizeof_bi_usize_t 2
#elif mk_lang_bitness_is_32
#define mk_lang_sizeof_bi_usize_t 4
#elif mk_lang_bitness_is_64
#define mk_lang_sizeof_bi_usize_t 8
#endif
#define mk_lang_sizeof_bi_ssize_t mk_lang_sizeof_bi_usize_t


#endif
