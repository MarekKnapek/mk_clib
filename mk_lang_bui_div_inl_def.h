#include "mk_lang_bi.h"
#include "mk_lang_concat.h"
#include "mk_lang_endian.h"
#include "mk_lang_sizeof.h"


#ifndef mk_lang_bui_div_inl_def_bt2_ig
#define mk_lang_bui_div_inl_def_bt2_ig
#if mk_lang_sizeof_bi_ushort_t >= 2 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_div_inl_def_bui2_uchar_has 1
#define mk_lang_bui_div_inl_def_bui2_uchar_t mk_lang_bi_ushort_t
#else
#define mk_lang_bui_div_inl_def_bui2_uchar_has 0
#endif
#if mk_lang_sizeof_bi_uint_t >= 2 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_div_inl_def_bui2_ushort_has 1
#define mk_lang_bui_div_inl_def_bui2_ushort_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 2 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_div_inl_def_bui2_ushort_has 1
#define mk_lang_bui_div_inl_def_bui2_ushort_t mk_lang_bi_ulong_t
#else
#define mk_lang_bui_div_inl_def_bui2_ushort_has 0
#endif
#if mk_lang_sizeof_bi_ulong_t >= 2 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_div_inl_def_bui2_uint_has 1
#define mk_lang_bui_div_inl_def_bui2_uint_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 2 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_div_inl_def_bui2_uint_has 1
#define mk_lang_bui_div_inl_def_bui2_uint_t mk_lang_bi_ullong_t
#else
#define mk_lang_bui_div_inl_def_bui2_uint_has 0
#endif
#if mk_lang_sizeof_bi_ullong_t >= 2 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_div_inl_def_bui2_ulong_has 1
#define mk_lang_bui_div_inl_def_bui2_ulong_t mk_lang_bi_ullong_t
#else
#define mk_lang_bui_div_inl_def_bui2_ulong_has 0
#endif
#if mk_lang_sizeof_bi_ulllong_t >= 2 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_div_inl_def_bui2_ullong_has 1
#define mk_lang_bui_div_inl_def_bui2_ullong_t mk_lang_bi_ulllong_t
#else
#define mk_lang_bui_div_inl_def_bui2_ullong_has 0
#endif
#define mk_lang_bui_div_inl_def_bui2_ulllong_has 0
#if mk_lang_sizeof_bi_uint_t >= 2 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_div_inl_def_bui2_uintptr_has 1
#define mk_lang_bui_div_inl_def_bui2_uintptr_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 2 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_div_inl_def_bui2_uintptr_has 1
#define mk_lang_bui_div_inl_def_bui2_uintptr_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 2 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_div_inl_def_bui2_uintptr_has 1
#define mk_lang_bui_div_inl_def_bui2_uintptr_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 2 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_div_inl_def_bui2_uintptr_has 1
#define mk_lang_bui_div_inl_def_bui2_uintptr_t mk_lang_bi_ulllong_t
#else
#define mk_lang_bui_div_inl_def_bui2_uintptr_has 0
#endif
#define mk_lang_bui_div_inl_def_bui2_uintmax_has 0
#if mk_lang_sizeof_bi_uint_t >= 2 * mk_lang_sizeof_bi_size_t
#define mk_lang_bui_div_inl_def_bui2_size_has 1
#define mk_lang_bui_div_inl_def_bui2_size_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 2 * mk_lang_sizeof_bi_size_t
#define mk_lang_bui_div_inl_def_bui2_size_has 1
#define mk_lang_bui_div_inl_def_bui2_size_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 2 * mk_lang_sizeof_bi_size_t
#define mk_lang_bui_div_inl_def_bui2_size_has 1
#define mk_lang_bui_div_inl_def_bui2_size_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 2 * mk_lang_sizeof_bi_size_t
#define mk_lang_bui_div_inl_def_bui2_size_has 1
#define mk_lang_bui_div_inl_def_bui2_size_t mk_lang_bi_ulllong_t
#else
#define mk_lang_bui_div_inl_def_bui2_size_has 0
#endif
#endif

#ifndef mk_lang_bui_div_inl_def_bt3_ig
#define mk_lang_bui_div_inl_def_bt3_ig
#if mk_lang_sizeof_bi_ushort_t >= 3 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_div_inl_def_bui3_uchar_has 1
#define mk_lang_bui_div_inl_def_bui3_uchar_t mk_lang_bi_ushort_t
#elif mk_lang_sizeof_bi_uint_t >= 3 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_div_inl_def_bui3_uchar_has 1
#define mk_lang_bui_div_inl_def_bui3_uchar_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 3 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_div_inl_def_bui3_uchar_has 1
#define mk_lang_bui_div_inl_def_bui3_uchar_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 3 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_div_inl_def_bui3_uchar_has 1
#define mk_lang_bui_div_inl_def_bui3_uchar_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 3 * mk_lang_sizeof_bi_uchar_t
#define mk_lang_bui_div_inl_def_bui3_uchar_has 1
#define mk_lang_bui_div_inl_def_bui3_uchar_t mk_lang_bi_ulllong_t
#else
#define mk_lang_bui_div_inl_def_bui3_uchar_has 0
#endif
#if mk_lang_sizeof_bi_uint_t >= 3 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_div_inl_def_bui3_ushort_has 1
#define mk_lang_bui_div_inl_def_bui3_ushort_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 3 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_div_inl_def_bui3_ushort_has 1
#define mk_lang_bui_div_inl_def_bui3_ushort_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 3 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_div_inl_def_bui3_ushort_has 1
#define mk_lang_bui_div_inl_def_bui3_ushort_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 3 * mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_div_inl_def_bui3_ushort_has 1
#define mk_lang_bui_div_inl_def_bui3_ushort_t mk_lang_bi_ulllong_t
#else
#define mk_lang_bui_div_inl_def_bui3_ushort_has 0
#endif
#if mk_lang_sizeof_bi_ulong_t >= 3 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_div_inl_def_bui3_uint_has 1
#define mk_lang_bui_div_inl_def_bui3_uint_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 3 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_div_inl_def_bui3_uint_has 1
#define mk_lang_bui_div_inl_def_bui3_uint_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 3 * mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_div_inl_def_bui3_uint_has 1
#define mk_lang_bui_div_inl_def_bui3_uint_t mk_lang_bi_ulllong_t
#else
#define mk_lang_bui_div_inl_def_bui3_uint_has 0
#endif
#if mk_lang_sizeof_bi_ullong_t >= 3 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_div_inl_def_bui3_ulong_has 1
#define mk_lang_bui_div_inl_def_bui3_ulong_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 3 * mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_div_inl_def_bui3_ulong_has 1
#define mk_lang_bui_div_inl_def_bui3_ulong_t mk_lang_bi_ulllong_t
#else
#define mk_lang_bui_div_inl_def_bui3_ulong_has 0
#endif
#if mk_lang_sizeof_bi_ulllong_t >= 3 * mk_lang_sizeof_bi_ullong_t
#define mk_lang_bui_div_inl_def_bui3_ullong_has 1
#define mk_lang_bui_div_inl_def_bui3_ullong_t mk_lang_bi_ulllong_t
#else
#define mk_lang_bui_div_inl_def_bui3_ullong_has 0
#endif
#define mk_lang_bui_div_inl_def_bui3_ulllong_has 0
#if mk_lang_sizeof_bi_uint_t >= 3 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_div_inl_def_bui3_uintptr_has 1
#define mk_lang_bui_div_inl_def_bui3_uintptr_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 3 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_div_inl_def_bui3_uintptr_has 1
#define mk_lang_bui_div_inl_def_bui3_uintptr_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 3 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_div_inl_def_bui3_uintptr_has 1
#define mk_lang_bui_div_inl_def_bui3_uintptr_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 3 * mk_lang_sizeof_bi_uintptr_t
#define mk_lang_bui_div_inl_def_bui3_uintptr_has 1
#define mk_lang_bui_div_inl_def_bui3_uintptr_t mk_lang_bi_ulllong_t
#else
#define mk_lang_bui_div_inl_def_bui3_uintptr_has 0
#endif
#define mk_lang_bui_div_inl_def_bui3_uintmax_has 0
#if mk_lang_sizeof_bi_uint_t >= 3 * mk_lang_sizeof_bi_size_t
#define mk_lang_bui_div_inl_def_bui3_size_has 1
#define mk_lang_bui_div_inl_def_bui3_size_t mk_lang_bi_uint_t
#elif mk_lang_sizeof_bi_ulong_t >= 3 * mk_lang_sizeof_bi_size_t
#define mk_lang_bui_div_inl_def_bui3_size_has 1
#define mk_lang_bui_div_inl_def_bui3_size_t mk_lang_bi_ulong_t
#elif mk_lang_sizeof_bi_ullong_t >= 3 * mk_lang_sizeof_bi_size_t
#define mk_lang_bui_div_inl_def_bui3_size_has 1
#define mk_lang_bui_div_inl_def_bui3_size_t mk_lang_bi_ullong_t
#elif mk_lang_sizeof_bi_ulllong_t >= 3 * mk_lang_sizeof_bi_size_t
#define mk_lang_bui_div_inl_def_bui3_size_has 1
#define mk_lang_bui_div_inl_def_bui3_size_t mk_lang_bi_ulllong_t
#else
#define mk_lang_bui_div_inl_def_bui3_size_has 0
#endif
#endif


#if defined mk_lang_bui_div_lena
#define mk_lang_bui_div_inl_def_lena mk_lang_bui_div_lena
#elif defined mk_lang_bui_div_inl_lena
#define mk_lang_bui_div_inl_def_lena mk_lang_bui_div_inl_lena
#else
#define mk_lang_bui_div_inl_def_lena 4
#endif

#if defined mk_lang_bui_div_lenb
#define mk_lang_bui_div_inl_def_lenb mk_lang_bui_div_lenb
#elif defined mk_lang_bui_div_inl_lenb
#define mk_lang_bui_div_inl_def_lenb mk_lang_bui_div_inl_lenb
#else
#define mk_lang_bui_div_inl_def_lenb 4
#endif

#if defined mk_lang_bui_div_endian
#define mk_lang_bui_div_inl_def_endian mk_lang_bui_div_endian
#elif defined mk_lang_bui_div_inl_endian
#define mk_lang_bui_div_inl_def_endian mk_lang_bui_div_inl_endian
#else
#define mk_lang_bui_div_inl_def_endian mk_lang_endian_little
#endif
#if mk_lang_bui_div_inl_def_endian == mk_lang_endian_little
#define mk_lang_bui_div_inl_def_endian_name le
#define mk_lang_bui_div_inl_def_endian_idxa(x) (x)
#define mk_lang_bui_div_inl_def_endian_idxb(x) (x)
#elif mk_lang_bui_div_inl_def_endian == mk_lang_endian_big
#define mk_lang_bui_div_inl_def_endian_name be
#define mk_lang_bui_div_inl_def_endian_idxa(x) ((mk_lang_bui_div_inl_def_lena - 1) - (x))
#define mk_lang_bui_div_inl_def_endian_idxb(x) ((mk_lang_bui_div_inl_def_lenb - 1) - (x))
#endif

#if defined mk_lang_bui_div_alg
#define mk_lang_bui_div_inl_def_alg mk_lang_bui_div_alg
#elif defined mk_lang_bui_div_inl_alg
#define mk_lang_bui_div_inl_def_alg mk_lang_bui_div_inl_alg
#else
#define mk_lang_bui_div_inl_def_alg 2
#endif

#if mk_lang_bui_div_inl_def_alg == 2
#if defined mk_lang_bui_div_bt && defined mk_lang_bui_div_bt2
#define mk_lang_bui_div_inl_def_bt mk_lang_bui_div_bt
#define mk_lang_bui_div_inl_def_bt2 mk_lang_bui_div_bt2
#elif defined mk_lang_bui_div_inl_type
#define mk_lang_bui_div_inl_def_bt mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_bui_div_inl_type), _t)
#define mk_lang_bui_div_inl_def_bt2 mk_lang_concat(mk_lang_concat(mk_lang_bui_div_inl_def_bui2_, mk_lang_bui_div_inl_type), _t)
#define mk_lang_bui_div_inl_def_bt2_has mk_lang_concat(mk_lang_concat(mk_lang_bui_div_inl_def_bui2_, mk_lang_bui_div_inl_type), _has)
#else
#define mk_lang_bui_div_inl_def_bt mk_lang_bi_ushort_t
#define mk_lang_bui_div_inl_def_bt2 mk_lang_bi_ulong_t
#define mk_lang_bui_div_inl_def_bt2_has 1
#endif
#elif mk_lang_bui_div_inl_def_alg == 3
#if defined mk_lang_bui_div_bt && defined mk_lang_bui_div_bt2 && defined mk_lang_bui_div_bt3
#define mk_lang_bui_div_inl_def_bt mk_lang_bui_div_bt
#define mk_lang_bui_div_inl_def_bt2 mk_lang_bui_div_bt2
#define mk_lang_bui_div_inl_def_bt3 mk_lang_bui_div_bt3
#elif defined mk_lang_bui_div_inl_type
#define mk_lang_bui_div_inl_def_bt mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_bui_div_inl_type), _t)
#define mk_lang_bui_div_inl_def_bt2 mk_lang_concat(mk_lang_concat(mk_lang_bui_div_inl_def_bui2_, mk_lang_bui_div_inl_type), _t)
#define mk_lang_bui_div_inl_def_bt2_has mk_lang_concat(mk_lang_concat(mk_lang_bui_div_inl_def_bui2_, mk_lang_bui_div_inl_type), _has)
#define mk_lang_bui_div_inl_def_bt3 mk_lang_concat(mk_lang_concat(mk_lang_bui_div_inl_def_bui3_, mk_lang_bui_div_inl_type), _t)
#define mk_lang_bui_div_inl_def_bt3_has mk_lang_concat(mk_lang_concat(mk_lang_bui_div_inl_def_bui3_, mk_lang_bui_div_inl_type), _has)
#else
#define mk_lang_bui_div_inl_def_bt mk_lang_bi_uchar_t
#define mk_lang_bui_div_inl_def_bt2 mk_lang_bi_ushort_t
#define mk_lang_bui_div_inl_def_bt2_has 1
#define mk_lang_bui_div_inl_def_bt3 mk_lang_bi_ulong_t
#define mk_lang_bui_div_inl_def_bt3_has 1
#endif
#endif

#if defined mk_lang_bui_div_name
#define mk_lang_bui_div_inl_def_name mk_lang_concat(mk_lang_bui_div_, mk_lang_bui_div_name)
#elif defined mk_lang_bui_div_inl_type && !defined mk_lang_bui_div_inl_type_default && defined mk_lang_bui_div_inl_lena && !defined mk_lang_bui_div_inl_lena_default && defined mk_lang_bui_div_inl_lenb && !defined mk_lang_bui_div_inl_lenb_default && defined mk_lang_bui_div_inl_endian && !defined mk_lang_bui_div_inl_endian_default && defined mk_lang_bui_div_inl_alg && !defined mk_lang_bui_div_inl_alg_default
#define mk_lang_bui_div_inl_def_name mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_div_, mk_lang_bui_div_inl_type), _), mk_lang_bui_div_inl_lena), _), mk_lang_bui_div_inl_lenb), _), mk_lang_bui_div_inl_def_endian_name), _), mk_lang_bui_div_inl_alg)
#elif defined mk_lang_bui_div_inl_type && defined mk_lang_bui_div_inl_type_default && defined mk_lang_bui_div_inl_lena && !defined mk_lang_bui_div_inl_lena_default && defined mk_lang_bui_div_inl_lenb && !defined mk_lang_bui_div_inl_lenb_default && defined mk_lang_bui_div_inl_endian && !defined mk_lang_bui_div_inl_endian_default && defined mk_lang_bui_div_inl_alg && !defined mk_lang_bui_div_inl_alg_default
#define mk_lang_bui_div_inl_def_name mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_div_zzzzzzzzzz_type_, mk_lang_bui_div_inl_type), _), mk_lang_bui_div_inl_lena), _), mk_lang_bui_div_inl_lenb), _), mk_lang_bui_div_inl_def_endian_name), _), mk_lang_bui_div_inl_alg)
#elif !defined mk_lang_bui_div_inl_type && !defined mk_lang_bui_div_inl_type_default && defined mk_lang_bui_div_inl_lena && defined mk_lang_bui_div_inl_lena_default && defined mk_lang_bui_div_inl_lenb && !defined mk_lang_bui_div_inl_lenb_default && defined mk_lang_bui_div_inl_endian && !defined mk_lang_bui_div_inl_endian_default && defined mk_lang_bui_div_inl_alg && !defined mk_lang_bui_div_inl_alg_default
#define mk_lang_bui_div_inl_def_name mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_div_zzzzzzzzzz_lena_, zzzzzzzzzz), _), mk_lang_bui_div_inl_lena), _), mk_lang_bui_div_inl_lenb), _), mk_lang_bui_div_inl_def_endian_name), _), mk_lang_bui_div_inl_alg)
#elif !defined mk_lang_bui_div_inl_type && !defined mk_lang_bui_div_inl_type_default && !defined mk_lang_bui_div_inl_lena && !defined mk_lang_bui_div_inl_lena_default && defined mk_lang_bui_div_inl_lenb && defined mk_lang_bui_div_inl_lenb_default && defined mk_lang_bui_div_inl_endian && !defined mk_lang_bui_div_inl_endian_default && defined mk_lang_bui_div_inl_alg && !defined mk_lang_bui_div_inl_alg_default
#define mk_lang_bui_div_inl_def_name mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_div_zzzzzzzzzz_lenb_, zzzzzzzzzz), _), zzzzzzzzzz), _), _), mk_lang_bui_div_inl_def_endian_name), _), mk_lang_bui_div_inl_alg)
#elif !defined mk_lang_bui_div_inl_type && !defined mk_lang_bui_div_inl_type_default && !defined mk_lang_bui_div_inl_lena && !defined mk_lang_bui_div_inl_lena_default && !defined mk_lang_bui_div_inl_lenb && !defined mk_lang_bui_div_inl_lenb_default && defined mk_lang_bui_div_inl_endian && defined mk_lang_bui_div_inl_endian_default && defined mk_lang_bui_div_inl_alg && !defined mk_lang_bui_div_inl_alg_default
#define mk_lang_bui_div_inl_def_name mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_div_zzzzzzzzzz_endian_, zzzzzzzzzz), _), zzzzzzzzzz), _), zzzzzzzzzz), _), mk_lang_bui_div_inl_def_endian_name), _), mk_lang_bui_div_inl_alg)
#elif !defined mk_lang_bui_div_inl_type && !defined mk_lang_bui_div_inl_type_default && !defined mk_lang_bui_div_inl_lena && !defined mk_lang_bui_div_inl_lena_default && !defined mk_lang_bui_div_inl_lenb && !defined mk_lang_bui_div_inl_lenb_default && !defined mk_lang_bui_div_inl_endian && !defined mk_lang_bui_div_inl_endian_default && defined mk_lang_bui_div_inl_alg && defined mk_lang_bui_div_inl_alg_default
#define mk_lang_bui_div_inl_def_name mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_div_zzzzzzzzzz_alg_, zzzzzzzzzz), _), zzzzzzzzzz), _), zzzzzzzzzz), _), zzzzzzzzzz), _), mk_lang_bui_div_inl_alg)
#elif !defined mk_lang_bui_div_inl_type && !defined mk_lang_bui_div_inl_type_default && !defined mk_lang_bui_div_inl_lena && !defined mk_lang_bui_div_inl_lena_default && !defined mk_lang_bui_div_inl_lenb && !defined mk_lang_bui_div_inl_lenb_default && !defined mk_lang_bui_div_inl_endian && !defined mk_lang_bui_div_inl_endian_default && !defined mk_lang_bui_div_inl_alg && !defined mk_lang_bui_div_inl_alg_default
#define mk_lang_bui_div_inl_def_name mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_div_zzzzzzzzzz_inl_, zzzzzzzzzz), _), zzzzzzzzzz), _), zzzzzzzzzz), _), zzzzzzzzzz), _), zzzzzzzzzz)
#endif
