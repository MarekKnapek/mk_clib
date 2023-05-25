#ifndef include_guard_mk_lang_limits
#define include_guard_mk_lang_limits


#include "mk_lang_bi.h"


#define mk_lang_limits_uchar_min ((mk_lang_bi_uchar_t)(0))
#define mk_lang_limits_uchar_max ((mk_lang_bi_uchar_t)(((mk_lang_bi_uchar_t)(0)) - ((mk_lang_bi_uchar_t)(1))))
#define mk_lang_limits_ushort_min ((mk_lang_bi_ushort_t)(0))
#define mk_lang_limits_ushort_max ((mk_lang_bi_ushort_t)(((mk_lang_bi_ushort_t)(0)) - ((mk_lang_bi_ushort_t)(1))))
#define mk_lang_limits_uint_min ((mk_lang_bi_uint_t)(0))
#define mk_lang_limits_uint_max ((mk_lang_bi_uint_t)(((mk_lang_bi_uint_t)(0)) - ((mk_lang_bi_uint_t)(1))))
#define mk_lang_limits_ulong_min ((mk_lang_bi_ulong_t)(0))
#define mk_lang_limits_ulong_max ((mk_lang_bi_ulong_t)(((mk_lang_bi_ulong_t)(0)) - ((mk_lang_bi_ulong_t)(1))))
#define mk_lang_limits_ullong_min ((mk_lang_bi_ullong_t)(0))
#define mk_lang_limits_ullong_max ((mk_lang_bi_ullong_t)(((mk_lang_bi_ullong_t)(0)) - ((mk_lang_bi_ullong_t)(1))))
#define mk_lang_limits_ulllong_min ((mk_lang_bi_ulllong_t)(0))
#define mk_lang_limits_ulllong_max ((mk_lang_bi_ulllong_t)(((mk_lang_bi_ulllong_t)(0)) - ((mk_lang_bi_ulllong_t)(1))))
#define mk_lang_limits_uintptr_min ((mk_lang_bi_uintptr_t)(0))
#define mk_lang_limits_uintptr_max ((mk_lang_bi_uintptr_t)(((mk_lang_bi_uintptr_t)(0)) - ((mk_lang_bi_uintptr_t)(1))))
#define mk_lang_limits_uintmax_min ((mk_lang_bi_uintmax_t)(0))
#define mk_lang_limits_uintmax_max ((mk_lang_bi_uintmax_t)(((mk_lang_bi_uintmax_t)(0)) - ((mk_lang_bi_uintmax_t)(1))))
#define mk_lang_limits_size_min ((mk_lang_bi_size_t)(0))
#define mk_lang_limits_size_max ((mk_lang_bi_size_t)(((mk_lang_bi_size_t)(0)) - ((mk_lang_bi_size_t)(1))))

#define mk_lang_limits_schar_min ((mk_lang_bi_schar_t)(((mk_lang_bi_schar_t)(((mk_lang_bi_schar_t)(0)) - ((mk_lang_bi_schar_t)(((mk_lang_bi_uchar_t)(mk_lang_limits_schar_max / 2)))))) - ((mk_lang_bi_schar_t)(1))))
#define mk_lang_limits_schar_max ((mk_lang_bi_schar_t)(((mk_lang_bi_uchar_t)(mk_lang_limits_uchar_max / 2))))
#define mk_lang_limits_sshort_min ((mk_lang_bi_sshort_t)(((mk_lang_bi_sshort_t)(((mk_lang_bi_sshort_t)(0)) - ((mk_lang_bi_sshort_t)(((mk_lang_bi_ushort_t)(mk_lang_limits_sshort_max / 2)))))) - ((mk_lang_bi_sshort_t)(1))))
#define mk_lang_limits_sshort_max ((mk_lang_bi_sshort_t)(((mk_lang_bi_ushort_t)(mk_lang_limits_ushort_max / 2))))
#define mk_lang_limits_sint_min ((mk_lang_bi_sint_t)(((mk_lang_bi_sint_t)(((mk_lang_bi_sint_t)(0)) - ((mk_lang_bi_sint_t)(((mk_lang_bi_uint_t)(mk_lang_limits_sint_max / 2)))))) - ((mk_lang_bi_sint_t)(1))))
#define mk_lang_limits_sint_max ((mk_lang_bi_sint_t)(((mk_lang_bi_uint_t)(mk_lang_limits_uint_max / 2))))
#define mk_lang_limits_slong_min ((mk_lang_bi_slong_t)(((mk_lang_bi_slong_t)(((mk_lang_bi_slong_t)(0)) - ((mk_lang_bi_slong_t)(((mk_lang_bi_ulong_t)(mk_lang_limits_slong_max / 2)))))) - ((mk_lang_bi_slong_t)(1))))
#define mk_lang_limits_slong_max ((mk_lang_bi_slong_t)(((mk_lang_bi_ulong_t)(mk_lang_limits_ulong_max / 2))))
#define mk_lang_limits_sllong_min ((mk_lang_bi_sllong_t)(((mk_lang_bi_sllong_t)(((mk_lang_bi_sllong_t)(0)) - ((mk_lang_bi_sllong_t)(((mk_lang_bi_ullong_t)(mk_lang_limits_sllong_max / 2)))))) - ((mk_lang_bi_sllong_t)(1))))
#define mk_lang_limits_sllong_max ((mk_lang_bi_sllong_t)(((mk_lang_bi_ullong_t)(mk_lang_limits_ullong_max / 2))))
#define mk_lang_limits_slllong_min ((mk_lang_bi_slllong_t)(((mk_lang_bi_slllong_t)(((mk_lang_bi_slllong_t)(0)) - ((mk_lang_bi_slllong_t)(((mk_lang_bi_ulllong_t)(mk_lang_limits_slllong_max / 2)))))) - ((mk_lang_bi_slllong_t)(1))))
#define mk_lang_limits_slllong_max ((mk_lang_bi_slllong_t)(((mk_lang_bi_ulllong_t)(mk_lang_limits_ulllong_max / 2))))
#define mk_lang_limits_sintptr_min ((mk_lang_bi_sintptr_t)(((mk_lang_bi_sintptr_t)(((mk_lang_bi_sintptr_t)(0)) - ((mk_lang_bi_sintptr_t)(((mk_lang_bi_uintptr_t)(mk_lang_limits_sintptr_max / 2)))))) - ((mk_lang_bi_sintptr_t)(1))))
#define mk_lang_limits_sintptr_max ((mk_lang_bi_sintptr_t)(((mk_lang_bi_uintptr_t)(mk_lang_limits_uintptr_max / 2))))
#define mk_lang_limits_sintmax_min ((mk_lang_bi_sintmax_t)(((mk_lang_bi_sintmax_t)(((mk_lang_bi_sintmax_t)(0)) - ((mk_lang_bi_sintmax_t)(((mk_lang_bi_uintmax_t)(mk_lang_limits_sintmax_max / 2)))))) - ((mk_lang_bi_sintmax_t)(1))))
#define mk_lang_limits_sintmax_max ((mk_lang_bi_sintmax_t)(((mk_lang_bi_uintmax_t)(mk_lang_limits_uintmax_max / 2))))


#endif
