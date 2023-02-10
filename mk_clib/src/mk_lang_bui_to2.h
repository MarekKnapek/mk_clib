#ifndef mk_include_guard_lang_bui_to2
#define mk_include_guard_lang_bui_to2


#include "mk_lang_sizeof.h"


#if mk_lang_sizeof_bi_uchar_t >= 2 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_to2_uchar_t mk_lang_bi_uchar_t
#elif mk_lang_sizeof_bi_ushort_t >= 2 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_to2_uchar_t mk_lang_bi_ushort_t
#elif mk_lang_sizeof_bi_uint_t >= 2 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_to2_uchar_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 2 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_to2_uchar_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 2 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_to2_uchar_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 2 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_to2_uchar_t mk_lang_bi_ulllong_t
#elif mk_lang_sizeof_bi_uintptr_t >= 2 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_to2_uchar_t mk_lang_bi_uintptr_t
#elif mk_lang_sizeof_bi_uintmax_t >= 2 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_to2_uchar_t mk_lang_bi_uintmax_t
#elif mk_lang_sizeof_bi_size_t >= 2 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_to2_uchar_t mk_lang_bi_size_t
#endif
#if defined mk_lang_bui_to2_uchar_t
#define mk_lang_bui_to2_uchar_has 1
#else
#define mk_lang_bui_to2_uchar_has 0
#endif

#if mk_lang_sizeof_bi_uchar_t >= 2 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_to2_ushort_t mk_lang_bi_uchar_t
#elif mk_lang_sizeof_bi_ushort_t >= 2 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_to2_ushort_t mk_lang_bi_ushort_t
#elif mk_lang_sizeof_bi_uint_t >= 2 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_to2_ushort_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 2 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_to2_ushort_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 2 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_to2_ushort_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 2 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_to2_ushort_t mk_lang_bi_ulllong_t
#elif mk_lang_sizeof_bi_uintptr_t >= 2 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_to2_ushort_t mk_lang_bi_uintptr_t
#elif mk_lang_sizeof_bi_uintmax_t >= 2 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_to2_ushort_t mk_lang_bi_uintmax_t
#elif mk_lang_sizeof_bi_size_t >= 2 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_to2_ushort_t mk_lang_bi_size_t
#endif
#if defined mk_lang_bui_to2_ushort_t
#define mk_lang_bui_to2_ushort_has 1
#else
#define mk_lang_bui_to2_ushort_has 0
#endif

#if mk_lang_sizeof_bi_uchar_t >= 2 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_to2_uint_t mk_lang_bi_uchar_t
#elif mk_lang_sizeof_bi_ushort_t >= 2 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_to2_uint_t mk_lang_bi_ushort_t
#elif mk_lang_sizeof_bi_uint_t >= 2 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_to2_uint_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 2 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_to2_uint_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 2 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_to2_uint_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 2 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_to2_uint_t mk_lang_bi_ulllong_t
#elif mk_lang_sizeof_bi_uintptr_t >= 2 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_to2_uint_t mk_lang_bi_uintptr_t
#elif mk_lang_sizeof_bi_uintmax_t >= 2 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_to2_uint_t mk_lang_bi_uintmax_t
#elif mk_lang_sizeof_bi_size_t >= 2 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_to2_uint_t mk_lang_bi_size_t
#endif
#if defined mk_lang_bui_to2_uint_t
#define mk_lang_bui_to2_uint_has 1
#else
#define mk_lang_bui_to2_uint_has 0
#endif

#if mk_lang_sizeof_bi_uchar_t >= 2 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_to2_ulong_t mk_lang_bi_uchar_t
#elif mk_lang_sizeof_bi_ushort_t >= 2 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_to2_ulong_t mk_lang_bi_ushort_t
#elif mk_lang_sizeof_bi_uint_t >= 2 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_to2_ulong_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 2 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_to2_ulong_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 2 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_to2_ulong_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 2 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_to2_ulong_t mk_lang_bi_ulllong_t
#elif mk_lang_sizeof_bi_uintptr_t >= 2 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_to2_ulong_t mk_lang_bi_uintptr_t
#elif mk_lang_sizeof_bi_uintmax_t >= 2 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_to2_ulong_t mk_lang_bi_uintmax_t
#elif mk_lang_sizeof_bi_size_t >= 2 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_to2_ulong_t mk_lang_bi_size_t
#endif
#if defined mk_lang_bui_to2_ulong_t
#define mk_lang_bui_to2_ulong_has 1
#else
#define mk_lang_bui_to2_ulong_has 0
#endif

#if mk_lang_sizeof_bi_uchar_t >= 2 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_to2_ullong_t mk_lang_bi_uchar_t
#elif mk_lang_sizeof_bi_ushort_t >= 2 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_to2_ullong_t mk_lang_bi_ushort_t
#elif mk_lang_sizeof_bi_uint_t >= 2 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_to2_ullong_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 2 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_to2_ullong_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 2 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_to2_ullong_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 2 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_to2_ullong_t mk_lang_bi_ulllong_t
#elif mk_lang_sizeof_bi_uintptr_t >= 2 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_to2_ullong_t mk_lang_bi_uintptr_t
#elif mk_lang_sizeof_bi_uintmax_t >= 2 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_to2_ullong_t mk_lang_bi_uintmax_t
#elif mk_lang_sizeof_bi_size_t >= 2 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_to2_ullong_t mk_lang_bi_size_t
#endif
#if defined mk_lang_bui_to2_ullong_t
#define mk_lang_bui_to2_ullong_has 1
#else
#define mk_lang_bui_to2_ullong_has 0
#endif

#if mk_lang_sizeof_bi_uchar_t >= 2 * mk_lang_sizeof_bi_ulllong_t
#define mk_lang_bui_to2_ulllong_t mk_lang_bi_uchar_t
#elif mk_lang_sizeof_bi_ushort_t >= 2 * mk_lang_sizeof_bi_ulllong_t
#define mk_lang_bui_to2_ulllong_t mk_lang_bi_ushort_t
#elif mk_lang_sizeof_bi_uint_t >= 2 * mk_lang_sizeof_bi_ulllong_t
#define mk_lang_bui_to2_ulllong_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 2 * mk_lang_sizeof_bi_ulllong_t
#define mk_lang_bui_to2_ulllong_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 2 * mk_lang_sizeof_bi_ulllong_t
#define mk_lang_bui_to2_ulllong_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 2 * mk_lang_sizeof_bi_ulllong_t
#define mk_lang_bui_to2_ulllong_t mk_lang_bi_ulllong_t
#elif mk_lang_sizeof_bi_uintptr_t >= 2 * mk_lang_sizeof_bi_ulllong_t
#define mk_lang_bui_to2_ulllong_t mk_lang_bi_uintptr_t
#elif mk_lang_sizeof_bi_uintmax_t >= 2 * mk_lang_sizeof_bi_ulllong_t
#define mk_lang_bui_to2_ulllong_t mk_lang_bi_uintmax_t
#elif mk_lang_sizeof_bi_size_t >= 2 * mk_lang_sizeof_bi_ulllong_t
#define mk_lang_bui_to2_ulllong_t mk_lang_bi_size_t
#endif
#if defined mk_lang_bui_to2_ulllong_t
#define mk_lang_bui_to2_ulllong_has 1
#else
#define mk_lang_bui_to2_ulllong_has 0
#endif

#if mk_lang_sizeof_bi_uchar_t >= 2 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_to2_uintptr_t mk_lang_bi_uchar_t
#elif mk_lang_sizeof_bi_ushort_t >= 2 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_to2_uintptr_t mk_lang_bi_ushort_t
#elif mk_lang_sizeof_bi_uint_t >= 2 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_to2_uintptr_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 2 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_to2_uintptr_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 2 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_to2_uintptr_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 2 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_to2_uintptr_t mk_lang_bi_ulllong_t
#elif mk_lang_sizeof_bi_uintptr_t >= 2 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_to2_uintptr_t mk_lang_bi_uintptr_t
#elif mk_lang_sizeof_bi_uintmax_t >= 2 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_to2_uintptr_t mk_lang_bi_uintmax_t
#elif mk_lang_sizeof_bi_size_t >= 2 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_to2_uintptr_t mk_lang_bi_size_t
#endif
#if defined mk_lang_bui_to2_uintptr_t
#define mk_lang_bui_to2_uintptr_has 1
#else
#define mk_lang_bui_to2_uintptr_has 0
#endif

#if mk_lang_sizeof_bi_uchar_t >= 2 * mk_lang_sizeof_bi_uintmax_t
#define mk_lang_bui_to2_uintmax_t mk_lang_bi_uchar_t
#elif mk_lang_sizeof_bi_ushort_t >= 2 * mk_lang_sizeof_bi_uintmax_t
#define mk_lang_bui_to2_uintmax_t mk_lang_bi_ushort_t
#elif mk_lang_sizeof_bi_uint_t >= 2 * mk_lang_sizeof_bi_uintmax_t
#define mk_lang_bui_to2_uintmax_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 2 * mk_lang_sizeof_bi_uintmax_t
#define mk_lang_bui_to2_uintmax_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 2 * mk_lang_sizeof_bi_uintmax_t
#define mk_lang_bui_to2_uintmax_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 2 * mk_lang_sizeof_bi_uintmax_t
#define mk_lang_bui_to2_uintmax_t mk_lang_bi_ulllong_t
#elif mk_lang_sizeof_bi_uintptr_t >= 2 * mk_lang_sizeof_bi_uintmax_t
#define mk_lang_bui_to2_uintmax_t mk_lang_bi_uintptr_t
#elif mk_lang_sizeof_bi_uintmax_t >= 2 * mk_lang_sizeof_bi_uintmax_t
#define mk_lang_bui_to2_uintmax_t mk_lang_bi_uintmax_t
#elif mk_lang_sizeof_bi_size_t >= 2 * mk_lang_sizeof_bi_uintmax_t
#define mk_lang_bui_to2_uintmax_t mk_lang_bi_size_t
#endif
#if defined mk_lang_bui_to2_uintmax_t
#define mk_lang_bui_to2_uintmax_has 1
#else
#define mk_lang_bui_to2_uintmax_has 0
#endif

#if mk_lang_sizeof_bi_uchar_t >= 2 * mk_lang_sizeof_bi_size_t
#define mk_lang_bui_to2_size_t mk_lang_bi_uchar_t
#elif mk_lang_sizeof_bi_ushort_t >= 2 * mk_lang_sizeof_bi_size_t
#define mk_lang_bui_to2_size_t mk_lang_bi_ushort_t
#elif mk_lang_sizeof_bi_uint_t >= 2 * mk_lang_sizeof_bi_size_t
#define mk_lang_bui_to2_size_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 2 * mk_lang_sizeof_bi_size_t
#define mk_lang_bui_to2_size_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 2 * mk_lang_sizeof_bi_size_t
#define mk_lang_bui_to2_size_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 2 * mk_lang_sizeof_bi_size_t
#define mk_lang_bui_to2_size_t mk_lang_bi_ulllong_t
#elif mk_lang_sizeof_bi_uintptr_t >= 2 * mk_lang_sizeof_bi_size_t
#define mk_lang_bui_to2_size_t mk_lang_bi_uintptr_t
#elif mk_lang_sizeof_bi_uintmax_t >= 2 * mk_lang_sizeof_bi_size_t
#define mk_lang_bui_to2_size_t mk_lang_bi_uintmax_t
#elif mk_lang_sizeof_bi_size_t >= 2 * mk_lang_sizeof_bi_size_t
#define mk_lang_bui_to2_size_t mk_lang_bi_size_t
#endif
#if defined mk_lang_bui_to2_size_t
#define mk_lang_bui_to2_size_has 1
#else
#define mk_lang_bui_to2_size_has 0
#endif


#endif
