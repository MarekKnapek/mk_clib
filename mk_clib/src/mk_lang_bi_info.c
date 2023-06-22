#include "mk_lang_bi_info.h"

#include "mk_lang_alignof.h"
#include "mk_lang_bi.h"
#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"

#include <stdio.h> /* printf */


mk_lang_jumbo void mk_lang_bi_info_print_sizes(void) mk_lang_noexcept
{
	printf("mk_lang_charbit == %d\n", ((int)(mk_lang_charbit)));
	printf("\n");
	printf("sizeof(mk_lang_bi_pchar_t) == %d\n", ((int)(sizeof(mk_lang_bi_pchar_t))));
	printf("sizeof(mk_lang_bi_uchar_t) == %d\n", ((int)(sizeof(mk_lang_bi_uchar_t))));
	printf("sizeof(mk_lang_bi_schar_t) == %d\n", ((int)(sizeof(mk_lang_bi_schar_t))));
	printf("sizeof(mk_lang_bi_ushort_t) == %d\n", ((int)(sizeof(mk_lang_bi_ushort_t))));
	printf("sizeof(mk_lang_bi_sshort_t) == %d\n", ((int)(sizeof(mk_lang_bi_sshort_t))));
	printf("sizeof(mk_lang_bi_uint_t) == %d\n", ((int)(sizeof(mk_lang_bi_uint_t))));
	printf("sizeof(mk_lang_bi_sint_t) == %d\n", ((int)(sizeof(mk_lang_bi_sint_t))));
	printf("sizeof(mk_lang_bi_ulong_t) == %d\n", ((int)(sizeof(mk_lang_bi_ulong_t))));
	printf("sizeof(mk_lang_bi_slong_t) == %d\n", ((int)(sizeof(mk_lang_bi_slong_t))));
	printf("sizeof(mk_lang_bi_ullong_t) == %d\n", ((int)(sizeof(mk_lang_bi_ullong_t))));
	printf("sizeof(mk_lang_bi_sllong_t) == %d\n", ((int)(sizeof(mk_lang_bi_sllong_t))));
	printf("sizeof(mk_lang_bi_ulllong_t) == %d\n", ((int)(sizeof(mk_lang_bi_ulllong_t))));
	printf("sizeof(mk_lang_bi_slllong_t) == %d\n", ((int)(sizeof(mk_lang_bi_slllong_t))));
	printf("sizeof(mk_lang_bi_uintptr_t) == %d\n", ((int)(sizeof(mk_lang_bi_uintptr_t))));
	printf("sizeof(mk_lang_bi_sintptr_t) == %d\n", ((int)(sizeof(mk_lang_bi_sintptr_t))));
	printf("sizeof(mk_lang_bi_uintmax_t) == %d\n", ((int)(sizeof(mk_lang_bi_uintmax_t))));
	printf("sizeof(mk_lang_bi_sintmax_t) == %d\n", ((int)(sizeof(mk_lang_bi_sintmax_t))));
	printf("sizeof(mk_lang_bi_size_t) == %d\n", ((int)(sizeof(mk_lang_bi_size_t))));
	printf("\n");
	printf("alignof(mk_lang_bi_pchar_t) == %d\n", ((int)(mk_lang_alignof(mk_lang_bi_pchar_t))));
	printf("alignof(mk_lang_bi_uchar_t) == %d\n", ((int)(mk_lang_alignof(mk_lang_bi_uchar_t))));
	printf("alignof(mk_lang_bi_schar_t) == %d\n", ((int)(mk_lang_alignof(mk_lang_bi_schar_t))));
	printf("alignof(mk_lang_bi_ushort_t) == %d\n", ((int)(mk_lang_alignof(mk_lang_bi_ushort_t))));
	printf("alignof(mk_lang_bi_sshort_t) == %d\n", ((int)(mk_lang_alignof(mk_lang_bi_sshort_t))));
	printf("alignof(mk_lang_bi_uint_t) == %d\n", ((int)(mk_lang_alignof(mk_lang_bi_uint_t))));
	printf("alignof(mk_lang_bi_sint_t) == %d\n", ((int)(mk_lang_alignof(mk_lang_bi_sint_t))));
	printf("alignof(mk_lang_bi_ulong_t) == %d\n", ((int)(mk_lang_alignof(mk_lang_bi_ulong_t))));
	printf("alignof(mk_lang_bi_slong_t) == %d\n", ((int)(mk_lang_alignof(mk_lang_bi_slong_t))));
	printf("alignof(mk_lang_bi_ullong_t) == %d\n", ((int)(mk_lang_alignof(mk_lang_bi_ullong_t))));
	printf("alignof(mk_lang_bi_sllong_t) == %d\n", ((int)(mk_lang_alignof(mk_lang_bi_sllong_t))));
	printf("alignof(mk_lang_bi_ulllong_t) == %d\n", ((int)(mk_lang_alignof(mk_lang_bi_ulllong_t))));
	printf("alignof(mk_lang_bi_slllong_t) == %d\n", ((int)(mk_lang_alignof(mk_lang_bi_slllong_t))));
	printf("alignof(mk_lang_bi_uintptr_t) == %d\n", ((int)(mk_lang_alignof(mk_lang_bi_uintptr_t))));
	printf("alignof(mk_lang_bi_sintptr_t) == %d\n", ((int)(mk_lang_alignof(mk_lang_bi_sintptr_t))));
	printf("alignof(mk_lang_bi_uintmax_t) == %d\n", ((int)(mk_lang_alignof(mk_lang_bi_uintmax_t))));
	printf("alignof(mk_lang_bi_sintmax_t) == %d\n", ((int)(mk_lang_alignof(mk_lang_bi_sintmax_t))));
	printf("alignof(mk_lang_bi_size_t) == %d\n", ((int)(mk_lang_alignof(mk_lang_bi_size_t))));
}
