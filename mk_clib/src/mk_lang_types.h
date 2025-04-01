#ifndef mk_include_guard_mk_lang_types_h
#define mk_include_guard_mk_lang_types_h


#include "mk_lang_bool.h"
#include "mk_lang_intmaxt.h"
#include "mk_lang_intptrt.h"
#include "mk_lang_lllong.h"
#include "mk_lang_llong.h"
#include "mk_lang_sizet.h"
#include "mk_lang_typedef.h"
#include "mk_lang_wchar.h"


typedef void mk_lang_types_void_t;
typedef mk_lang_bool_t mk_lang_types_bool_t;
typedef char mk_lang_types_pchar_t;
typedef mk_lang_wchar_t mk_lang_types_wchar_t;
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
typedef float mk_lang_types_float_t;
typedef double mk_lang_types_double_t;
typedef long double mk_lang_types_ldouble_t;


mk_lang_typedef(mk_lang_types_void);
mk_lang_typedef(mk_lang_types_bool);
mk_lang_typedef(mk_lang_types_pchar);
mk_lang_typedef(mk_lang_types_wchar);
mk_lang_typedef(mk_lang_types_uchar);
mk_lang_typedef(mk_lang_types_schar);
mk_lang_typedef(mk_lang_types_ushort);
mk_lang_typedef(mk_lang_types_sshort);
mk_lang_typedef(mk_lang_types_uint);
mk_lang_typedef(mk_lang_types_sint);
mk_lang_typedef(mk_lang_types_ulong);
mk_lang_typedef(mk_lang_types_slong);
mk_lang_typedef(mk_lang_types_ullong);
mk_lang_typedef(mk_lang_types_sllong);
mk_lang_typedef(mk_lang_types_ulllong);
mk_lang_typedef(mk_lang_types_slllong);
mk_lang_typedef(mk_lang_types_uintptr);
mk_lang_typedef(mk_lang_types_sintptr);
mk_lang_typedef(mk_lang_types_uintmax);
mk_lang_typedef(mk_lang_types_sintmax);
mk_lang_typedef(mk_lang_types_usize);
mk_lang_typedef(mk_lang_types_ssize);
mk_lang_typedef(mk_lang_types_float);
mk_lang_typedef(mk_lang_types_double);
mk_lang_typedef(mk_lang_types_ldouble);


#endif
