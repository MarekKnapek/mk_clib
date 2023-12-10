#include "mk_lang_alignof_test.h"

#include "mk_lang_alignof.h"
#include "mk_lang_bi.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"


mk_lang_jumbo void mk_lang_alignof_test(void) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_alignof_bi_pchar_t == mk_lang_alignof(mk_lang_bi_pchar_t));
	mk_lang_static_assert(mk_lang_alignof_bi_wchar_t == mk_lang_alignof(mk_lang_bi_wchar_t));
	mk_lang_static_assert(mk_lang_alignof_bi_uchar_t == mk_lang_alignof(mk_lang_bi_uchar_t));
	mk_lang_static_assert(mk_lang_alignof_bi_schar_t == mk_lang_alignof(mk_lang_bi_schar_t));
	mk_lang_static_assert(mk_lang_alignof_bi_ushort_t == mk_lang_alignof(mk_lang_bi_ushort_t));
	mk_lang_static_assert(mk_lang_alignof_bi_sshort_t == mk_lang_alignof(mk_lang_bi_sshort_t));
	mk_lang_static_assert(mk_lang_alignof_bi_uint_t == mk_lang_alignof(mk_lang_bi_uint_t));
	mk_lang_static_assert(mk_lang_alignof_bi_sint_t == mk_lang_alignof(mk_lang_bi_sint_t));
	mk_lang_static_assert(mk_lang_alignof_bi_ulong_t == mk_lang_alignof(mk_lang_bi_ulong_t));
	mk_lang_static_assert(mk_lang_alignof_bi_slong_t == mk_lang_alignof(mk_lang_bi_slong_t));
	mk_lang_static_assert(mk_lang_alignof_bi_ullong_t == mk_lang_alignof(mk_lang_bi_ullong_t));
	mk_lang_static_assert(mk_lang_alignof_bi_sllong_t == mk_lang_alignof(mk_lang_bi_sllong_t));
	mk_lang_static_assert(mk_lang_alignof_bi_ulllong_t == mk_lang_alignof(mk_lang_bi_ulllong_t));
	mk_lang_static_assert(mk_lang_alignof_bi_slllong_t == mk_lang_alignof(mk_lang_bi_slllong_t));
	mk_lang_static_assert(mk_lang_alignof_bi_uintptr_t == mk_lang_alignof(mk_lang_bi_uintptr_t));
	mk_lang_static_assert(mk_lang_alignof_bi_sintptr_t == mk_lang_alignof(mk_lang_bi_sintptr_t));
	mk_lang_static_assert(mk_lang_alignof_bi_uintmax_t == mk_lang_alignof(mk_lang_bi_uintmax_t));
	mk_lang_static_assert(mk_lang_alignof_bi_sintmax_t == mk_lang_alignof(mk_lang_bi_sintmax_t));
	mk_lang_static_assert(mk_lang_alignof_bi_usize_t == mk_lang_alignof(mk_lang_bi_usize_t));
	mk_lang_static_assert(mk_lang_alignof_bi_ssize_t == mk_lang_alignof(mk_lang_bi_ssize_t));
}
