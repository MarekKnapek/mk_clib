#include "mk_lang_sizeof_test.h"

#include "mk_lang_bi.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_static_assert.h"


mk_lang_jumbo void mk_lang_sizeof_test(void) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_sizeof_bi_pchar_t == sizeof(mk_lang_bi_pchar_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_uchar_t == sizeof(mk_lang_bi_uchar_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_schar_t == sizeof(mk_lang_bi_schar_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_ushort_t == sizeof(mk_lang_bi_ushort_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_sshort_t == sizeof(mk_lang_bi_sshort_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_uint_t == sizeof(mk_lang_bi_uint_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_sint_t == sizeof(mk_lang_bi_sint_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_ulong_t == sizeof(mk_lang_bi_ulong_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_slong_t == sizeof(mk_lang_bi_slong_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_ullong_t == sizeof(mk_lang_bi_ullong_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_sllong_t == sizeof(mk_lang_bi_sllong_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_ulllong_t == sizeof(mk_lang_bi_ulllong_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_slllong_t == sizeof(mk_lang_bi_slllong_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_uintptr_t == sizeof(mk_lang_bi_uintptr_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_sintptr_t == sizeof(mk_lang_bi_sintptr_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_uintmax_t == sizeof(mk_lang_bi_uintmax_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_sintmax_t == sizeof(mk_lang_bi_sintmax_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_size_t == sizeof(mk_lang_bi_size_t));
}
