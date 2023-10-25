#ifndef mk_include_guard_mk_lang_bui_to3
#define mk_include_guard_mk_lang_bui_to3


#include "mk_lang_sizeof.h"


#if mk_lang_sizeof_bi_uchar_t >= 3 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_to3_uchar_t mk_lang_bi_uchar_t
#elif mk_lang_sizeof_bi_ushort_t >= 3 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_to3_uchar_t mk_lang_bi_ushort_t
#elif mk_lang_sizeof_bi_uint_t >= 3 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_to3_uchar_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 3 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_to3_uchar_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 3 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_to3_uchar_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 3 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_to3_uchar_t mk_lang_bi_ulllong_t
#elif mk_lang_sizeof_bi_uintptr_t >= 3 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_to3_uchar_t mk_lang_bi_uintptr_t
#elif mk_lang_sizeof_bi_uintmax_t >= 3 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_to3_uchar_t mk_lang_bi_uintmax_t
#elif mk_lang_sizeof_bi_usize_t >= 3 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_to3_uchar_t mk_lang_bi_usize_t
#endif
#if defined mk_lang_bui_to3_uchar_t
#define mk_lang_bui_to3_uchar_has 1
#else
#define mk_lang_bui_to3_uchar_has 0
#endif

#if mk_lang_sizeof_bi_uchar_t >= 3 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_to3_ushort_t mk_lang_bi_uchar_t
#elif mk_lang_sizeof_bi_ushort_t >= 3 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_to3_ushort_t mk_lang_bi_ushort_t
#elif mk_lang_sizeof_bi_uint_t >= 3 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_to3_ushort_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 3 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_to3_ushort_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 3 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_to3_ushort_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 3 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_to3_ushort_t mk_lang_bi_ulllong_t
#elif mk_lang_sizeof_bi_uintptr_t >= 3 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_to3_ushort_t mk_lang_bi_uintptr_t
#elif mk_lang_sizeof_bi_uintmax_t >= 3 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_to3_ushort_t mk_lang_bi_uintmax_t
#elif mk_lang_sizeof_bi_usize_t >= 3 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_to3_ushort_t mk_lang_bi_usize_t
#endif
#if defined mk_lang_bui_to3_ushort_t
#define mk_lang_bui_to3_ushort_has 1
#else
#define mk_lang_bui_to3_ushort_has 0
#endif

#if mk_lang_sizeof_bi_uchar_t >= 3 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_to3_uint_t mk_lang_bi_uchar_t
#elif mk_lang_sizeof_bi_ushort_t >= 3 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_to3_uint_t mk_lang_bi_ushort_t
#elif mk_lang_sizeof_bi_uint_t >= 3 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_to3_uint_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 3 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_to3_uint_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 3 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_to3_uint_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 3 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_to3_uint_t mk_lang_bi_ulllong_t
#elif mk_lang_sizeof_bi_uintptr_t >= 3 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_to3_uint_t mk_lang_bi_uintptr_t
#elif mk_lang_sizeof_bi_uintmax_t >= 3 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_to3_uint_t mk_lang_bi_uintmax_t
#elif mk_lang_sizeof_bi_usize_t >= 3 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_to3_uint_t mk_lang_bi_usize_t
#endif
#if defined mk_lang_bui_to3_uint_t
#define mk_lang_bui_to3_uint_has 1
#else
#define mk_lang_bui_to3_uint_has 0
#endif

#if mk_lang_sizeof_bi_uchar_t >= 3 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_to3_ulong_t mk_lang_bi_uchar_t
#elif mk_lang_sizeof_bi_ushort_t >= 3 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_to3_ulong_t mk_lang_bi_ushort_t
#elif mk_lang_sizeof_bi_uint_t >= 3 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_to3_ulong_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 3 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_to3_ulong_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 3 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_to3_ulong_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 3 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_to3_ulong_t mk_lang_bi_ulllong_t
#elif mk_lang_sizeof_bi_uintptr_t >= 3 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_to3_ulong_t mk_lang_bi_uintptr_t
#elif mk_lang_sizeof_bi_uintmax_t >= 3 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_to3_ulong_t mk_lang_bi_uintmax_t
#elif mk_lang_sizeof_bi_usize_t >= 3 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_to3_ulong_t mk_lang_bi_usize_t
#endif
#if defined mk_lang_bui_to3_ulong_t
#define mk_lang_bui_to3_ulong_has 1
#else
#define mk_lang_bui_to3_ulong_has 0
#endif

#if mk_lang_sizeof_bi_uchar_t >= 3 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_to3_ullong_t mk_lang_bi_uchar_t
#elif mk_lang_sizeof_bi_ushort_t >= 3 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_to3_ullong_t mk_lang_bi_ushort_t
#elif mk_lang_sizeof_bi_uint_t >= 3 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_to3_ullong_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 3 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_to3_ullong_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 3 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_to3_ullong_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 3 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_to3_ullong_t mk_lang_bi_ulllong_t
#elif mk_lang_sizeof_bi_uintptr_t >= 3 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_to3_ullong_t mk_lang_bi_uintptr_t
#elif mk_lang_sizeof_bi_uintmax_t >= 3 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_to3_ullong_t mk_lang_bi_uintmax_t
#elif mk_lang_sizeof_bi_usize_t >= 3 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_to3_ullong_t mk_lang_bi_usize_t
#endif
#if defined mk_lang_bui_to3_ullong_t
#define mk_lang_bui_to3_ullong_has 1
#else
#define mk_lang_bui_to3_ullong_has 0
#endif

#if mk_lang_sizeof_bi_uchar_t >= 3 * mk_lang_sizeof_bi_ulllong_t
#define mk_lang_bui_to3_ulllong_t mk_lang_bi_uchar_t
#elif mk_lang_sizeof_bi_ushort_t >= 3 * mk_lang_sizeof_bi_ulllong_t
#define mk_lang_bui_to3_ulllong_t mk_lang_bi_ushort_t
#elif mk_lang_sizeof_bi_uint_t >= 3 * mk_lang_sizeof_bi_ulllong_t
#define mk_lang_bui_to3_ulllong_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 3 * mk_lang_sizeof_bi_ulllong_t
#define mk_lang_bui_to3_ulllong_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 3 * mk_lang_sizeof_bi_ulllong_t
#define mk_lang_bui_to3_ulllong_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 3 * mk_lang_sizeof_bi_ulllong_t
#define mk_lang_bui_to3_ulllong_t mk_lang_bi_ulllong_t
#elif mk_lang_sizeof_bi_uintptr_t >= 3 * mk_lang_sizeof_bi_ulllong_t
#define mk_lang_bui_to3_ulllong_t mk_lang_bi_uintptr_t
#elif mk_lang_sizeof_bi_uintmax_t >= 3 * mk_lang_sizeof_bi_ulllong_t
#define mk_lang_bui_to3_ulllong_t mk_lang_bi_uintmax_t
#elif mk_lang_sizeof_bi_usize_t >= 3 * mk_lang_sizeof_bi_ulllong_t
#define mk_lang_bui_to3_ulllong_t mk_lang_bi_usize_t
#endif
#if defined mk_lang_bui_to3_ulllong_t
#define mk_lang_bui_to3_ulllong_has 1
#else
#define mk_lang_bui_to3_ulllong_has 0
#endif

#if mk_lang_sizeof_bi_uchar_t >= 3 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_to3_uintptr_t mk_lang_bi_uchar_t
#elif mk_lang_sizeof_bi_ushort_t >= 3 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_to3_uintptr_t mk_lang_bi_ushort_t
#elif mk_lang_sizeof_bi_uint_t >= 3 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_to3_uintptr_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 3 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_to3_uintptr_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 3 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_to3_uintptr_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 3 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_to3_uintptr_t mk_lang_bi_ulllong_t
#elif mk_lang_sizeof_bi_uintptr_t >= 3 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_to3_uintptr_t mk_lang_bi_uintptr_t
#elif mk_lang_sizeof_bi_uintmax_t >= 3 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_to3_uintptr_t mk_lang_bi_uintmax_t
#elif mk_lang_sizeof_bi_usize_t >= 3 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_to3_uintptr_t mk_lang_bi_usize_t
#endif
#if defined mk_lang_bui_to3_uintptr_t
#define mk_lang_bui_to3_uintptr_has 1
#else
#define mk_lang_bui_to3_uintptr_has 0
#endif

#if mk_lang_sizeof_bi_uchar_t >= 3 * mk_lang_sizeof_bi_uintmax_t
#define mk_lang_bui_to3_uintmax_t mk_lang_bi_uchar_t
#elif mk_lang_sizeof_bi_ushort_t >= 3 * mk_lang_sizeof_bi_uintmax_t
#define mk_lang_bui_to3_uintmax_t mk_lang_bi_ushort_t
#elif mk_lang_sizeof_bi_uint_t >= 3 * mk_lang_sizeof_bi_uintmax_t
#define mk_lang_bui_to3_uintmax_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 3 * mk_lang_sizeof_bi_uintmax_t
#define mk_lang_bui_to3_uintmax_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 3 * mk_lang_sizeof_bi_uintmax_t
#define mk_lang_bui_to3_uintmax_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 3 * mk_lang_sizeof_bi_uintmax_t
#define mk_lang_bui_to3_uintmax_t mk_lang_bi_ulllong_t
#elif mk_lang_sizeof_bi_uintptr_t >= 3 * mk_lang_sizeof_bi_uintmax_t
#define mk_lang_bui_to3_uintmax_t mk_lang_bi_uintptr_t
#elif mk_lang_sizeof_bi_uintmax_t >= 3 * mk_lang_sizeof_bi_uintmax_t
#define mk_lang_bui_to3_uintmax_t mk_lang_bi_uintmax_t
#elif mk_lang_sizeof_bi_usize_t >= 3 * mk_lang_sizeof_bi_uintmax_t
#define mk_lang_bui_to3_uintmax_t mk_lang_bi_usize_t
#endif
#if defined mk_lang_bui_to3_uintmax_t
#define mk_lang_bui_to3_uintmax_has 1
#else
#define mk_lang_bui_to3_uintmax_has 0
#endif

#if mk_lang_sizeof_bi_uchar_t >= 3 * mk_lang_sizeof_bi_usize_t
#define mk_lang_bui_to3_size_t mk_lang_bi_uchar_t
#elif mk_lang_sizeof_bi_ushort_t >= 3 * mk_lang_sizeof_bi_usize_t
#define mk_lang_bui_to3_size_t mk_lang_bi_ushort_t
#elif mk_lang_sizeof_bi_uint_t >= 3 * mk_lang_sizeof_bi_usize_t
#define mk_lang_bui_to3_size_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 3 * mk_lang_sizeof_bi_usize_t
#define mk_lang_bui_to3_size_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 3 * mk_lang_sizeof_bi_usize_t
#define mk_lang_bui_to3_size_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 3 * mk_lang_sizeof_bi_usize_t
#define mk_lang_bui_to3_size_t mk_lang_bi_ulllong_t
#elif mk_lang_sizeof_bi_uintptr_t >= 3 * mk_lang_sizeof_bi_usize_t
#define mk_lang_bui_to3_size_t mk_lang_bi_uintptr_t
#elif mk_lang_sizeof_bi_uintmax_t >= 3 * mk_lang_sizeof_bi_usize_t
#define mk_lang_bui_to3_size_t mk_lang_bi_uintmax_t
#elif mk_lang_sizeof_bi_usize_t >= 3 * mk_lang_sizeof_bi_usize_t
#define mk_lang_bui_to3_size_t mk_lang_bi_usize_t
#endif
#if defined mk_lang_bui_to3_size_t
#define mk_lang_bui_to3_size_has 1
#else
#define mk_lang_bui_to3_size_has 0
#endif


#endif
