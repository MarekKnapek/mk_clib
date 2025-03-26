#ifndef mk_include_guard_mk_lang_type_traits_h
#define mk_include_guard_mk_lang_type_traits_h


#include "mk_lang_sizeof.h"
#include "mk_lang_types.h"


typedef mk_lang_types_uchar_t   mk_lang_type_traits_to_unsigned_uchar_t  ;
typedef mk_lang_types_uchar_t   mk_lang_type_traits_to_unsigned_schar_t  ;
typedef mk_lang_types_ushort_t  mk_lang_type_traits_to_unsigned_ushort_t ;
typedef mk_lang_types_ushort_t  mk_lang_type_traits_to_unsigned_sshort_t ;
typedef mk_lang_types_uint_t    mk_lang_type_traits_to_unsigned_uint_t   ;
typedef mk_lang_types_uint_t    mk_lang_type_traits_to_unsigned_sint_t   ;
typedef mk_lang_types_ulong_t   mk_lang_type_traits_to_unsigned_ulong_t  ;
typedef mk_lang_types_ulong_t   mk_lang_type_traits_to_unsigned_slong_t  ;
typedef mk_lang_types_ullong_t  mk_lang_type_traits_to_unsigned_ullong_t ;
typedef mk_lang_types_ullong_t  mk_lang_type_traits_to_unsigned_sllong_t ;
typedef mk_lang_types_ulllong_t mk_lang_type_traits_to_unsigned_ulllong_t;
typedef mk_lang_types_ulllong_t mk_lang_type_traits_to_unsigned_slllong_t;
typedef mk_lang_types_uintptr_t mk_lang_type_traits_to_unsigned_uintptr_t;
typedef mk_lang_types_uintptr_t mk_lang_type_traits_to_unsigned_sintptr_t;
typedef mk_lang_types_uintmax_t mk_lang_type_traits_to_unsigned_uintmax_t;
typedef mk_lang_types_uintmax_t mk_lang_type_traits_to_unsigned_sintmax_t;
typedef mk_lang_types_usize_t   mk_lang_type_traits_to_unsigned_usize_t  ;
typedef mk_lang_types_usize_t   mk_lang_type_traits_to_unsigned_ssize_t  ;

#define mk_lang_type_traits_to_unsigned_prefix_uchar_t   uchar
#define mk_lang_type_traits_to_unsigned_prefix_schar_t   uchar
#define mk_lang_type_traits_to_unsigned_prefix_ushort_t  ushort
#define mk_lang_type_traits_to_unsigned_prefix_sshort_t  ushort
#define mk_lang_type_traits_to_unsigned_prefix_uint_t    uint
#define mk_lang_type_traits_to_unsigned_prefix_sint_t    uint
#define mk_lang_type_traits_to_unsigned_prefix_ulong_t   ulong
#define mk_lang_type_traits_to_unsigned_prefix_slong_t   ulong
#define mk_lang_type_traits_to_unsigned_prefix_ullong_t  ullong
#define mk_lang_type_traits_to_unsigned_prefix_sllong_t  ullong
#define mk_lang_type_traits_to_unsigned_prefix_ulllong_t ulllong
#define mk_lang_type_traits_to_unsigned_prefix_slllong_t ulllong
#define mk_lang_type_traits_to_unsigned_prefix_uintptr_t uintptr
#define mk_lang_type_traits_to_unsigned_prefix_sintptr_t uintptr
#define mk_lang_type_traits_to_unsigned_prefix_uintmax_t uintmax
#define mk_lang_type_traits_to_unsigned_prefix_sintmax_t uintmax
#define mk_lang_type_traits_to_unsigned_prefix_usize_t   usize
#define mk_lang_type_traits_to_unsigned_prefix_ssize_t   usize

#define mk_lang_type_traits_is_unsigned_uchar_t   1
#define mk_lang_type_traits_is_unsigned_schar_t   0
#define mk_lang_type_traits_is_unsigned_ushort_t  1
#define mk_lang_type_traits_is_unsigned_sshort_t  0
#define mk_lang_type_traits_is_unsigned_uint_t    1
#define mk_lang_type_traits_is_unsigned_sint_t    0
#define mk_lang_type_traits_is_unsigned_ulong_t   1
#define mk_lang_type_traits_is_unsigned_slong_t   0
#define mk_lang_type_traits_is_unsigned_ullong_t  1
#define mk_lang_type_traits_is_unsigned_sllong_t  0
#define mk_lang_type_traits_is_unsigned_ulllong_t 1
#define mk_lang_type_traits_is_unsigned_slllong_t 0
#define mk_lang_type_traits_is_unsigned_uintptr_t 1
#define mk_lang_type_traits_is_unsigned_sintptr_t 0
#define mk_lang_type_traits_is_unsigned_uintmax_t 1
#define mk_lang_type_traits_is_unsigned_sintmax_t 0
#define mk_lang_type_traits_is_unsigned_usize_t   1
#define mk_lang_type_traits_is_unsigned_ssize_t   0

#define mk_lang_type_traits_is_signed_uchar_t   0
#define mk_lang_type_traits_is_signed_schar_t   1
#define mk_lang_type_traits_is_signed_ushort_t  0
#define mk_lang_type_traits_is_signed_sshort_t  1
#define mk_lang_type_traits_is_signed_uint_t    0
#define mk_lang_type_traits_is_signed_sint_t    1
#define mk_lang_type_traits_is_signed_ulong_t   0
#define mk_lang_type_traits_is_signed_slong_t   1
#define mk_lang_type_traits_is_signed_ullong_t  0
#define mk_lang_type_traits_is_signed_sllong_t  1
#define mk_lang_type_traits_is_signed_ulllong_t 0
#define mk_lang_type_traits_is_signed_slllong_t 1
#define mk_lang_type_traits_is_signed_uintptr_t 0
#define mk_lang_type_traits_is_signed_sintptr_t 1
#define mk_lang_type_traits_is_signed_uintmax_t 0
#define mk_lang_type_traits_is_signed_sintmax_t 1
#define mk_lang_type_traits_is_signed_usize_t   0
#define mk_lang_type_traits_is_signed_ssize_t   1





typedef mk_lang_types_uchar_t mk_lang_type_traits_to_unsigned_pchar_t;

#if mk_lang_sizeof_bi_wchar_t == mk_lang_sizeof_bi_ushort_t
typedef mk_lang_types_ushort_t mk_lang_type_traits_to_unsigned_wchar_t;
#elif mk_lang_sizeof_bi_wchar_t == mk_lang_sizeof_bi_uint_t
typedef mk_lang_types_uint_t mk_lang_type_traits_to_unsigned_wchar_t;
#elif mk_lang_sizeof_bi_wchar_t == mk_lang_sizeof_bi_ulong_t
typedef mk_lang_types_ulong_t mk_lang_type_traits_to_unsigned_wchar_t;
#else
#error xxxxxxxxxx
#endif


#endif
