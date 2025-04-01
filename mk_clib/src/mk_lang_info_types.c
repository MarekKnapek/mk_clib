#ifndef mk_include_guard_mk_lang_info_types_c
#define mk_include_guard_mk_lang_info_types_c
#include "mk_lang_info_types.h"

#include "mk_lang_alignof.h"
#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#include <stdio.h> /* printf */


mk_lang_jumbo mk_lang_types_void_t mk_lang_info_types_print_sizes(mk_lang_types_void_t) mk_lang_noexcept
{
	printf("mk_lang_charbit == %d\n", ((mk_lang_types_sint_t)(mk_lang_charbit)));
	printf("\n");
	printf("sizeof(mk_lang_types_pchar_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_pchar_t))));
	printf("sizeof(mk_lang_types_wchar_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_wchar_t))));
	printf("sizeof(mk_lang_types_uchar_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_uchar_t))));
	printf("sizeof(mk_lang_types_schar_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_schar_t))));
	printf("sizeof(mk_lang_types_ushort_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_ushort_t))));
	printf("sizeof(mk_lang_types_sshort_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_sshort_t))));
	printf("sizeof(mk_lang_types_uint_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_uint_t))));
	printf("sizeof(mk_lang_types_sint_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_sint_t))));
	printf("sizeof(mk_lang_types_ulong_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_ulong_t))));
	printf("sizeof(mk_lang_types_slong_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_slong_t))));
	printf("sizeof(mk_lang_types_ullong_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_ullong_t))));
	printf("sizeof(mk_lang_types_sllong_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_sllong_t))));
	printf("sizeof(mk_lang_types_ulllong_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_ulllong_t))));
	printf("sizeof(mk_lang_types_slllong_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_slllong_t))));
	printf("sizeof(mk_lang_types_uintptr_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_uintptr_t))));
	printf("sizeof(mk_lang_types_sintptr_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_sintptr_t))));
	printf("sizeof(mk_lang_types_uintmax_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_uintmax_t))));
	printf("sizeof(mk_lang_types_sintmax_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_sintmax_t))));
	printf("sizeof(mk_lang_types_usize_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_usize_t))));
	printf("sizeof(mk_lang_types_ssize_t) == %d\n", ((mk_lang_types_sint_t)(sizeof(mk_lang_types_ssize_t))));
	printf("\n");
	printf("alignof(mk_lang_types_pchar_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_pchar_t))));
	printf("alignof(mk_lang_types_wchar_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_wchar_t))));
	printf("alignof(mk_lang_types_uchar_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_uchar_t))));
	printf("alignof(mk_lang_types_schar_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_schar_t))));
	printf("alignof(mk_lang_types_ushort_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_ushort_t))));
	printf("alignof(mk_lang_types_sshort_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_sshort_t))));
	printf("alignof(mk_lang_types_uint_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_uint_t))));
	printf("alignof(mk_lang_types_sint_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_sint_t))));
	printf("alignof(mk_lang_types_ulong_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_ulong_t))));
	printf("alignof(mk_lang_types_slong_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_slong_t))));
	printf("alignof(mk_lang_types_ullong_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_ullong_t))));
	printf("alignof(mk_lang_types_sllong_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_sllong_t))));
	printf("alignof(mk_lang_types_ulllong_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_ulllong_t))));
	printf("alignof(mk_lang_types_slllong_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_slllong_t))));
	printf("alignof(mk_lang_types_uintptr_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_uintptr_t))));
	printf("alignof(mk_lang_types_sintptr_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_sintptr_t))));
	printf("alignof(mk_lang_types_uintmax_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_uintmax_t))));
	printf("alignof(mk_lang_types_sintmax_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_sintmax_t))));
	printf("alignof(mk_lang_types_usize_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_usize_t))));
	printf("alignof(mk_lang_types_ssize_t) == %d\n", ((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_ssize_t))));
}


#endif
