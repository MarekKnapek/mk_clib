#ifndef mk_include_guard_mk_lang_types
#define mk_include_guard_mk_lang_types


#include "mk_lang_bool.h"
#include "mk_lang_intmaxt.h"
#include "mk_lang_intptrt.h"
#include "mk_lang_lllong.h"
#include "mk_lang_llong.h"
#include "mk_lang_restrict.h"
#include "mk_lang_sizet.h"


typedef void mk_lang_types_void_t;
typedef mk_lang_bool_t mk_lang_types_bool_t;
typedef char mk_lang_types_pchar_t;
typedef unsigned char mk_lang_types_uchar_t;
typedef signed char mk_lang_types_schar_t;
typedef unsigned short int mk_lang_types_ushort_t;
typedef signed short int mk_lang_types_sshort_t;
typedef unsigned int mk_lang_types_uint_t;
typedef signed int mk_lang_types_sint_t;
typedef unsigned long int mk_lang_types_ulong_t;
typedef signed long int mk_lang_types_slong_t;
typedef mk_lang_ullong_t mk_lang_types_ullong_t;
typedef mk_lang_sllong_t mk_lang_types_sllong_t;
typedef mk_lang_ulllong_t mk_lang_types_ulllong_t;
typedef mk_lang_slllong_t mk_lang_types_slllong_t;
typedef mk_lang_uintptr_t mk_lang_types_uintptr_t;
typedef mk_lang_sintptr_t mk_lang_types_sintptr_t;
typedef mk_lang_uintmax_t mk_lang_types_uintmax_t;
typedef mk_lang_sintmax_t mk_lang_types_sintmax_t;
typedef mk_lang_usize_t mk_lang_types_usize_t;
typedef mk_lang_ssize_t mk_lang_types_ssize_t;

typedef mk_lang_types_void_t const mk_lang_types_void_ct;
typedef mk_lang_types_bool_t const mk_lang_types_bool_ct;
typedef mk_lang_types_pchar_t const mk_lang_types_pchar_ct;
typedef mk_lang_types_uchar_t const mk_lang_types_uchar_ct;
typedef mk_lang_types_schar_t const mk_lang_types_schar_ct;
typedef mk_lang_types_ushort_t const mk_lang_types_ushort_ct;
typedef mk_lang_types_sshort_t const mk_lang_types_sshort_ct;
typedef mk_lang_types_uint_t const mk_lang_types_uint_ct;
typedef mk_lang_types_sint_t const mk_lang_types_sint_ct;
typedef mk_lang_types_ulong_t const mk_lang_types_ulong_ct;
typedef mk_lang_types_slong_t const mk_lang_types_slong_ct;
typedef mk_lang_types_ullong_t const mk_lang_types_ullong_ct;
typedef mk_lang_types_sllong_t const mk_lang_types_sllong_ct;
typedef mk_lang_types_ulllong_t const mk_lang_types_ulllong_ct;
typedef mk_lang_types_slllong_t const mk_lang_types_slllong_ct;
typedef mk_lang_types_uintptr_t const mk_lang_types_uintptr_ct;
typedef mk_lang_types_sintptr_t const mk_lang_types_sintptr_ct;
typedef mk_lang_types_uintmax_t const mk_lang_types_uintmax_ct;
typedef mk_lang_types_sintmax_t const mk_lang_types_sintmax_ct;
typedef mk_lang_types_usize_t const mk_lang_types_usize_ct;
typedef mk_lang_types_ssize_t const mk_lang_types_ssize_ct;

typedef mk_lang_types_void_t* mk_lang_types_void_pt;
typedef mk_lang_types_bool_t* mk_lang_types_bool_pt;
typedef mk_lang_types_pchar_t* mk_lang_types_pchar_pt;
typedef mk_lang_types_uchar_t* mk_lang_types_uchar_pt;
typedef mk_lang_types_schar_t* mk_lang_types_schar_pt;
typedef mk_lang_types_ushort_t* mk_lang_types_ushort_pt;
typedef mk_lang_types_sshort_t* mk_lang_types_sshort_pt;
typedef mk_lang_types_uint_t* mk_lang_types_uint_pt;
typedef mk_lang_types_sint_t* mk_lang_types_sint_pt;
typedef mk_lang_types_ulong_t* mk_lang_types_ulong_pt;
typedef mk_lang_types_slong_t* mk_lang_types_slong_pt;
typedef mk_lang_types_ullong_t* mk_lang_types_ullong_pt;
typedef mk_lang_types_sllong_t* mk_lang_types_sllong_pt;
typedef mk_lang_types_ulllong_t* mk_lang_types_ulllong_pt;
typedef mk_lang_types_slllong_t* mk_lang_types_slllong_pt;
typedef mk_lang_types_uintptr_t* mk_lang_types_uintptr_pt;
typedef mk_lang_types_sintptr_t* mk_lang_types_sintptr_pt;
typedef mk_lang_types_uintmax_t* mk_lang_types_uintmax_pt;
typedef mk_lang_types_sintmax_t* mk_lang_types_sintmax_pt;
typedef mk_lang_types_usize_t* mk_lang_types_usize_pt;
typedef mk_lang_types_ssize_t* mk_lang_types_ssize_pt;

typedef mk_lang_types_void_t const* mk_lang_types_void_pct;
typedef mk_lang_types_bool_t const* mk_lang_types_bool_pct;
typedef mk_lang_types_pchar_t const* mk_lang_types_pchar_pct;
typedef mk_lang_types_uchar_t const* mk_lang_types_uchar_pct;
typedef mk_lang_types_schar_t const* mk_lang_types_schar_pct;
typedef mk_lang_types_ushort_t const* mk_lang_types_ushort_pct;
typedef mk_lang_types_sshort_t const* mk_lang_types_sshort_pct;
typedef mk_lang_types_uint_t const* mk_lang_types_uint_pct;
typedef mk_lang_types_sint_t const* mk_lang_types_sint_pct;
typedef mk_lang_types_ulong_t const* mk_lang_types_ulong_pct;
typedef mk_lang_types_slong_t const* mk_lang_types_slong_pct;
typedef mk_lang_types_ullong_t const* mk_lang_types_ullong_pct;
typedef mk_lang_types_sllong_t const* mk_lang_types_sllong_pct;
typedef mk_lang_types_ulllong_t const* mk_lang_types_ulllong_pct;
typedef mk_lang_types_slllong_t const* mk_lang_types_slllong_pct;
typedef mk_lang_types_uintptr_t const* mk_lang_types_uintptr_pct;
typedef mk_lang_types_sintptr_t const* mk_lang_types_sintptr_pct;
typedef mk_lang_types_uintmax_t const* mk_lang_types_uintmax_pct;
typedef mk_lang_types_sintmax_t const* mk_lang_types_sintmax_pct;
typedef mk_lang_types_usize_t const* mk_lang_types_usize_pct;
typedef mk_lang_types_ssize_t const* mk_lang_types_ssize_pct;

typedef mk_lang_types_void_t* mk_lang_restrict mk_lang_types_void_prt;
typedef mk_lang_types_bool_t* mk_lang_restrict mk_lang_types_bool_prt;
typedef mk_lang_types_pchar_t* mk_lang_restrict mk_lang_types_pchar_prt;
typedef mk_lang_types_uchar_t* mk_lang_restrict mk_lang_types_uchar_prt;
typedef mk_lang_types_schar_t* mk_lang_restrict mk_lang_types_schar_prt;
typedef mk_lang_types_ushort_t* mk_lang_restrict mk_lang_types_ushort_prt;
typedef mk_lang_types_sshort_t* mk_lang_restrict mk_lang_types_sshort_prt;
typedef mk_lang_types_uint_t* mk_lang_restrict mk_lang_types_uint_prt;
typedef mk_lang_types_sint_t* mk_lang_restrict mk_lang_types_sint_prt;
typedef mk_lang_types_ulong_t* mk_lang_restrict mk_lang_types_ulong_prt;
typedef mk_lang_types_slong_t* mk_lang_restrict mk_lang_types_slong_prt;
typedef mk_lang_types_ullong_t* mk_lang_restrict mk_lang_types_ullong_prt;
typedef mk_lang_types_sllong_t* mk_lang_restrict mk_lang_types_sllong_prt;
typedef mk_lang_types_ulllong_t* mk_lang_restrict mk_lang_types_ulllong_prt;
typedef mk_lang_types_slllong_t* mk_lang_restrict mk_lang_types_slllong_prt;
typedef mk_lang_types_uintptr_t* mk_lang_restrict mk_lang_types_uintptr_prt;
typedef mk_lang_types_sintptr_t* mk_lang_restrict mk_lang_types_sintptr_prt;
typedef mk_lang_types_uintmax_t* mk_lang_restrict mk_lang_types_uintmax_prt;
typedef mk_lang_types_sintmax_t* mk_lang_restrict mk_lang_types_sintmax_prt;
typedef mk_lang_types_usize_t* mk_lang_restrict mk_lang_types_usize_prt;
typedef mk_lang_types_ssize_t* mk_lang_restrict mk_lang_types_ssize_prt;

typedef mk_lang_types_void_t const* mk_lang_restrict mk_lang_types_void_prct;
typedef mk_lang_types_bool_t const* mk_lang_restrict mk_lang_types_bool_prct;
typedef mk_lang_types_pchar_t const* mk_lang_restrict mk_lang_types_pchar_prct;
typedef mk_lang_types_uchar_t const* mk_lang_restrict mk_lang_types_uchar_prct;
typedef mk_lang_types_schar_t const* mk_lang_restrict mk_lang_types_schar_prct;
typedef mk_lang_types_ushort_t const* mk_lang_restrict mk_lang_types_ushort_prct;
typedef mk_lang_types_sshort_t const* mk_lang_restrict mk_lang_types_sshort_prct;
typedef mk_lang_types_uint_t const* mk_lang_restrict mk_lang_types_uint_prct;
typedef mk_lang_types_sint_t const* mk_lang_restrict mk_lang_types_sint_prct;
typedef mk_lang_types_ulong_t const* mk_lang_restrict mk_lang_types_ulong_prct;
typedef mk_lang_types_slong_t const* mk_lang_restrict mk_lang_types_slong_prct;
typedef mk_lang_types_ullong_t const* mk_lang_restrict mk_lang_types_ullong_prct;
typedef mk_lang_types_sllong_t const* mk_lang_restrict mk_lang_types_sllong_prct;
typedef mk_lang_types_ulllong_t const* mk_lang_restrict mk_lang_types_ulllong_prct;
typedef mk_lang_types_slllong_t const* mk_lang_restrict mk_lang_types_slllong_prct;
typedef mk_lang_types_uintptr_t const* mk_lang_restrict mk_lang_types_uintptr_prct;
typedef mk_lang_types_sintptr_t const* mk_lang_restrict mk_lang_types_sintptr_prct;
typedef mk_lang_types_uintmax_t const* mk_lang_restrict mk_lang_types_uintmax_prct;
typedef mk_lang_types_sintmax_t const* mk_lang_restrict mk_lang_types_sintmax_prct;
typedef mk_lang_types_usize_t const* mk_lang_restrict mk_lang_types_usize_prct;
typedef mk_lang_types_ssize_t const* mk_lang_restrict mk_lang_types_ssize_prct;


#endif
