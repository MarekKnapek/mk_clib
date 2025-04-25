#ifndef mk_include_guard_mk_lang_bui_h
#define mk_include_guard_mk_lang_bui_h


#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"


#if mk_lang_sizeof_bi_wchar_t == mk_lang_sizeof_bi_ushort_t
#define mk_lang_bui_wchar_base ushort
#elif mk_lang_sizeof_bi_wchar_t == mk_lang_sizeof_bi_uint_t
#define mk_lang_bui_wchar_base uint
#elif mk_lang_sizeof_bi_wchar_t == mk_lang_sizeof_bi_ulong_t
#define mk_lang_bui_wchar_base ulong
#else
#error xxxxxxxxxx
#endif

#define mk_lang_bui_t_name mk_lang_bui_wchar
#define mk_lang_bui_t_base mk_lang_bui_wchar_base
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_fileu.h"
#define mk_lang_bui_uchar_size_bits_d ((mk_lang_sizeof_bi_uchar_t) * (mk_lang_charbit))
#define mk_lang_memall2_t_name mk_lang_bui_wchar
#define mk_lang_memall2_t_tn mk_lang_bui_wchar
#include "mk_lang_memall2_inl_fileh.h"
#include "mk_lang_memall2_inl_fileu.h"

#define mk_lang_bui_t_name mk_lang_bui_uchar
#define mk_lang_bui_t_base uchar
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_fileu.h"
#define mk_lang_bui_uchar_size_bits_d ((mk_lang_sizeof_bi_uchar_t) * (mk_lang_charbit))
#define mk_lang_memall2_t_name mk_lang_bui_uchar
#define mk_lang_memall2_t_tn mk_lang_bui_uchar
#include "mk_lang_memall2_inl_fileh.h"
#include "mk_lang_memall2_inl_fileu.h"

#define mk_lang_bui_t_name mk_lang_bui_ushort
#define mk_lang_bui_t_base ushort
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_fileu.h"
#define mk_lang_bui_ushort_size_bits_d ((mk_lang_sizeof_bi_ushort_t) * (mk_lang_charbit))
#define mk_lang_memall2_t_name mk_lang_bui_ushort
#define mk_lang_memall2_t_tn mk_lang_bui_ushort
#include "mk_lang_memall2_inl_fileh.h"
#include "mk_lang_memall2_inl_fileu.h"

#define mk_lang_bui_t_name mk_lang_bui_uint
#define mk_lang_bui_t_base uint
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_fileu.h"
#define mk_lang_bui_uint_size_bits_d ((mk_lang_sizeof_bi_uint_t) * (mk_lang_charbit))
#define mk_lang_memall2_t_name mk_lang_bui_uint
#define mk_lang_memall2_t_tn mk_lang_bui_uint
#include "mk_lang_memall2_inl_fileh.h"
#include "mk_lang_memall2_inl_fileu.h"

#define mk_lang_bui_t_name mk_lang_bui_ulong
#define mk_lang_bui_t_base ulong
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_fileu.h"
#define mk_lang_bui_ulong_size_bits_d ((mk_lang_sizeof_bi_ulong_t) * (mk_lang_charbit))
#define mk_lang_memall2_t_name mk_lang_bui_ulong
#define mk_lang_memall2_t_tn mk_lang_bui_ulong
#include "mk_lang_memall2_inl_fileh.h"
#include "mk_lang_memall2_inl_fileu.h"

#define mk_lang_bui_t_name mk_lang_bui_ullong
#define mk_lang_bui_t_base ullong
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_fileu.h"
#define mk_lang_bui_ullong_size_bits_d ((mk_lang_sizeof_bi_ullong_t) * (mk_lang_charbit))
#define mk_lang_memall2_t_name mk_lang_bui_ullong
#define mk_lang_memall2_t_tn mk_lang_bui_ullong
#include "mk_lang_memall2_inl_fileh.h"
#include "mk_lang_memall2_inl_fileu.h"

#define mk_lang_bui_t_name mk_lang_bui_ulllong
#define mk_lang_bui_t_base ulllong
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_fileu.h"
#define mk_lang_bui_ulllong_size_bits_d ((mk_lang_sizeof_bi_ulllong_t) * (mk_lang_charbit))
#define mk_lang_memall2_t_name mk_lang_bui_ulllong
#define mk_lang_memall2_t_tn mk_lang_bui_ulllong
#include "mk_lang_memall2_inl_fileh.h"
#include "mk_lang_memall2_inl_fileu.h"

#define mk_lang_bui_t_name mk_lang_bui_uintptr
#define mk_lang_bui_t_base uintptr
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_fileu.h"
#define mk_lang_bui_uintptr_size_bits_d ((mk_lang_sizeof_bi_uintptr_t) * (mk_lang_charbit))
#define mk_lang_memall2_t_name mk_lang_bui_uintptr
#define mk_lang_memall2_t_tn mk_lang_bui_uintptr
#include "mk_lang_memall2_inl_fileh.h"
#include "mk_lang_memall2_inl_fileu.h"

#define mk_lang_bui_t_name mk_lang_bui_uintmax
#define mk_lang_bui_t_base uintmax
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_fileu.h"
#define mk_lang_bui_uintmax_size_bits_d ((mk_lang_sizeof_bi_uintmax_t) * (mk_lang_charbit))
#define mk_lang_memall2_t_name mk_lang_bui_uintmax
#define mk_lang_memall2_t_tn mk_lang_bui_uintmax
#include "mk_lang_memall2_inl_fileh.h"
#include "mk_lang_memall2_inl_fileu.h"

#define mk_lang_bui_t_name mk_lang_bui_usize
#define mk_lang_bui_t_base usize
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_fileu.h"
#define mk_lang_bui_usize_size_bits_d ((mk_lang_sizeof_bi_usize_t) * (mk_lang_charbit))
#define mk_lang_memall2_t_name mk_lang_bui_usize
#define mk_lang_memall2_t_tn mk_lang_bui_usize
#include "mk_lang_memall2_inl_fileh.h"
#include "mk_lang_memall2_inl_fileu.h"


#if mk_lang_jumbo_have == 1
#include "mk_lang_bui.c"
#endif
#endif
