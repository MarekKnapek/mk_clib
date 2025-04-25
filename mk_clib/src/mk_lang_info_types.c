#ifndef mk_include_guard_mk_lang_info_types_c
#define mk_include_guard_mk_lang_info_types_c
#include "mk_lang_info_types.h"

#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stdout.h"
#include "mk_lang_types.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lang_info_types_print_num(mk_lang_types_sint_t const num) mk_lang_noexcept
{
	mk_lang_types_uint_t x;
	mk_lang_types_sint_t len;
	mk_lang_types_pchar_t buf[mk_lang_bui_uint_strlen_dec_v];
	mk_lang_types_sint_t err;

	mk_lang_assert(num >= 1);

	x = ((mk_lang_types_uint_t)(num));
	len = mk_lang_bui_uint_to_str_dec_n(&x, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(buf));
	err = mk_lang_stdout_println_n(&buf[0], len); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_info_types_print_sizes(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_lang_stdout_print_lit_n("mk_lang_charbit == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_charbit))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_println_lit_n(""); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_pchar_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_pchar_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_wchar_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_wchar_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_uchar_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_uchar_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_schar_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_schar_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_ushort_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_ushort_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_sshort_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_sshort_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_uint_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_uint_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_sint_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_sint_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_ulong_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_ulong_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_slong_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_slong_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_ullong_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_ullong_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_sllong_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_sllong_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_ulllong_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_ulllong_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_slllong_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_slllong_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_uintptr_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_uintptr_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_sintptr_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_sintptr_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_uintmax_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_uintmax_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_sintmax_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_sintmax_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_usize_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_usize_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("sizeof(mk_lang_types_ssize_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(sizeof(mk_lang_types_ssize_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_println_lit_n(""); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_pchar_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_pchar_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_wchar_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_wchar_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_uchar_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_uchar_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_schar_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_schar_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_ushort_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_ushort_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_sshort_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_sshort_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_uint_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_uint_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_sint_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_sint_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_ulong_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_ulong_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_slong_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_slong_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_ullong_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_ullong_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_sllong_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_sllong_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_ulllong_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_ulllong_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_slllong_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_slllong_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_uintptr_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_uintptr_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_sintptr_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_sintptr_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_uintmax_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_uintmax_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_sintmax_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_sintmax_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_usize_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_usize_t)))); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n("alignof(mk_lang_types_ssize_t) == "); mk_lang_check_rereturn(err); err = mk_lang_info_types_print_num(((mk_lang_types_sint_t)(mk_lang_alignof(mk_lang_types_ssize_t)))); mk_lang_check_rereturn(err);
	return 0;
}


#endif
