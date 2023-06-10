#ifndef mk_include_guard_mk_lang_bi
#define mk_include_guard_mk_lang_bi


#include "mk_lang_intmaxt.h"
#include "mk_lang_intptrt.h"
#include "mk_lang_lllong.h"
#include "mk_lang_llong.h"
#include "mk_lang_sizet.h"


#define mk_lang_bi_pchar_t char
#define mk_lang_bi_uchar_t unsigned char
#define mk_lang_bi_schar_t signed char
#define mk_lang_bi_ushort_t unsigned short int
#define mk_lang_bi_sshort_t signed short int
#define mk_lang_bi_uint_t unsigned int
#define mk_lang_bi_sint_t signed int
#define mk_lang_bi_ulong_t unsigned long int
#define mk_lang_bi_slong_t signed long int
#define mk_lang_bi_ullong_t mk_lang_ullong_t
#define mk_lang_bi_sllong_t mk_lang_sllong_t
#define mk_lang_bi_ulllong_t mk_lang_ulllong_t
#define mk_lang_bi_slllong_t mk_lang_slllong_t
#define mk_lang_bi_uintptr_t mk_lang_uintptr_t
#define mk_lang_bi_sintptr_t mk_lang_sintptr_t
#define mk_lang_bi_uintmax_t mk_lang_uintmax_t
#define mk_lang_bi_sintmax_t mk_lang_sintmax_t
#define mk_lang_bi_size_t mk_lang_size_t

#define mk_lang_bi_is_unsigned_pchar_t 0
#define mk_lang_bi_is_unsigned_uchar_t 1
#define mk_lang_bi_is_unsigned_schar_t 0
#define mk_lang_bi_is_unsigned_ushort_t 1
#define mk_lang_bi_is_unsigned_sshort_t 0
#define mk_lang_bi_is_unsigned_uint_t 1
#define mk_lang_bi_is_unsigned_sint_t 0
#define mk_lang_bi_is_unsigned_ulong_t 1
#define mk_lang_bi_is_unsigned_slong_t 0
#define mk_lang_bi_is_unsigned_ullong_t 1
#define mk_lang_bi_is_unsigned_sllong_t 0
#define mk_lang_bi_is_unsigned_ulllong_t 1
#define mk_lang_bi_is_unsigned_slllong_t 0
#define mk_lang_bi_is_unsigned_uintptr_t 1
#define mk_lang_bi_is_unsigned_sintptr_t 0
#define mk_lang_bi_is_unsigned_uintmax_t 1
#define mk_lang_bi_is_unsigned_sintmax_t 0
#define mk_lang_bi_is_unsigned_size_t 1

#define mk_lang_bi_to_unsigned_pchar_t mk_lang_bi_uchar_t
#define mk_lang_bi_to_unsigned_uchar_t mk_lang_bi_uchar_t
#define mk_lang_bi_to_unsigned_schar_t mk_lang_bi_uchar_t
#define mk_lang_bi_to_unsigned_ushort_t mk_lang_bi_ushort_t
#define mk_lang_bi_to_unsigned_sshort_t mk_lang_bi_ushort_t
#define mk_lang_bi_to_unsigned_uint_t mk_lang_bi_uint_t
#define mk_lang_bi_to_unsigned_sint_t mk_lang_bi_uint_t
#define mk_lang_bi_to_unsigned_ulong_t mk_lang_bi_ulong_t
#define mk_lang_bi_to_unsigned_slong_t mk_lang_bi_ulong_t
#define mk_lang_bi_to_unsigned_ullong_t mk_lang_bi_ullong_t
#define mk_lang_bi_to_unsigned_sllong_t mk_lang_bi_ullong_t
#define mk_lang_bi_to_unsigned_ulllong_t mk_lang_bi_ulllong_t
#define mk_lang_bi_to_unsigned_slllong_t mk_lang_bi_ulllong_t
#define mk_lang_bi_to_unsigned_uintptr_t mk_lang_bi_uintptr_t
#define mk_lang_bi_to_unsigned_sintptr_t mk_lang_bi_uintptr_t
#define mk_lang_bi_to_unsigned_uintmax_t mk_lang_bi_uintmax_t
#define mk_lang_bi_to_unsigned_sintmax_t mk_lang_bi_uintmax_t
#define mk_lang_bi_to_unsigned_size_t mk_lang_bi_size_t

#define mk_lang_bi_to_unsigned_prefix_pchar_t uchar
#define mk_lang_bi_to_unsigned_prefix_uchar_t uchar
#define mk_lang_bi_to_unsigned_prefix_schar_t uchar
#define mk_lang_bi_to_unsigned_prefix_ushort_t ushort
#define mk_lang_bi_to_unsigned_prefix_sshort_t ushort
#define mk_lang_bi_to_unsigned_prefix_uint_t uint
#define mk_lang_bi_to_unsigned_prefix_sint_t uint
#define mk_lang_bi_to_unsigned_prefix_ulong_t ulong
#define mk_lang_bi_to_unsigned_prefix_slong_t ulong
#define mk_lang_bi_to_unsigned_prefix_ullong_t ullong
#define mk_lang_bi_to_unsigned_prefix_sllong_t ullong
#define mk_lang_bi_to_unsigned_prefix_ulllong_t ulllong
#define mk_lang_bi_to_unsigned_prefix_slllong_t ulllong
#define mk_lang_bi_to_unsigned_prefix_uintptr_t uintptr
#define mk_lang_bi_to_unsigned_prefix_sintptr_t uintptr
#define mk_lang_bi_to_unsigned_prefix_uintmax_t uintmax
#define mk_lang_bi_to_unsigned_prefix_sintmax_t uintmax
#define mk_lang_bi_to_unsigned_prefix_size_t size


#endif
