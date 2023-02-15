#include "mk_lang_bi_test.h"

#include "mk_lang_bi.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"


mk_lang_jumbo void mk_lang_bi_test(void) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_lang_bi_uintptr_t) == sizeof(void*));
	mk_lang_static_assert(sizeof(mk_lang_bi_sintptr_t) == sizeof(void*));

	mk_lang_static_assert(sizeof(mk_lang_bi_to_unsigned_pchar_t) == sizeof(mk_lang_bi_pchar_t));
	mk_lang_static_assert(sizeof(mk_lang_bi_to_unsigned_uchar_t) == sizeof(mk_lang_bi_uchar_t));
	mk_lang_static_assert(sizeof(mk_lang_bi_to_unsigned_schar_t) == sizeof(mk_lang_bi_schar_t));
	mk_lang_static_assert(sizeof(mk_lang_bi_to_unsigned_ushort_t) == sizeof(mk_lang_bi_ushort_t));
	mk_lang_static_assert(sizeof(mk_lang_bi_to_unsigned_sshort_t) == sizeof(mk_lang_bi_sshort_t));
	mk_lang_static_assert(sizeof(mk_lang_bi_to_unsigned_uint_t) == sizeof(mk_lang_bi_uint_t));
	mk_lang_static_assert(sizeof(mk_lang_bi_to_unsigned_sint_t) == sizeof(mk_lang_bi_sint_t));
	mk_lang_static_assert(sizeof(mk_lang_bi_to_unsigned_ulong_t) == sizeof(mk_lang_bi_ulong_t));
	mk_lang_static_assert(sizeof(mk_lang_bi_to_unsigned_slong_t) == sizeof(mk_lang_bi_slong_t));
	mk_lang_static_assert(sizeof(mk_lang_bi_to_unsigned_ullong_t) == sizeof(mk_lang_bi_ullong_t));
	mk_lang_static_assert(sizeof(mk_lang_bi_to_unsigned_sllong_t) == sizeof(mk_lang_bi_sllong_t));
	mk_lang_static_assert(sizeof(mk_lang_bi_to_unsigned_ulllong_t) == sizeof(mk_lang_bi_ulllong_t));
	mk_lang_static_assert(sizeof(mk_lang_bi_to_unsigned_slllong_t) == sizeof(mk_lang_bi_slllong_t));
	mk_lang_static_assert(sizeof(mk_lang_bi_to_unsigned_uintptr_t) == sizeof(mk_lang_bi_uintptr_t));
	mk_lang_static_assert(sizeof(mk_lang_bi_to_unsigned_sintptr_t) == sizeof(mk_lang_bi_sintptr_t));
	mk_lang_static_assert(sizeof(mk_lang_bi_to_unsigned_uintmax_t) == sizeof(mk_lang_bi_uintmax_t));
	mk_lang_static_assert(sizeof(mk_lang_bi_to_unsigned_sintmax_t) == sizeof(mk_lang_bi_sintmax_t));
	mk_lang_static_assert(sizeof(mk_lang_bi_to_unsigned_size_t) == sizeof(mk_lang_bi_size_t));

	mk_lang_static_assert(sizeof(mk_lang_bi_pchar_t*) == sizeof(void*));
	mk_lang_static_assert(sizeof(mk_lang_bi_uchar_t*) == sizeof(void*));
	mk_lang_static_assert(sizeof(mk_lang_bi_schar_t*) == sizeof(void*));
	mk_lang_static_assert(sizeof(mk_lang_bi_ushort_t*) == sizeof(void*));
	mk_lang_static_assert(sizeof(mk_lang_bi_sshort_t*) == sizeof(void*));
	mk_lang_static_assert(sizeof(mk_lang_bi_uint_t*) == sizeof(void*));
	mk_lang_static_assert(sizeof(mk_lang_bi_sint_t*) == sizeof(void*));
	mk_lang_static_assert(sizeof(mk_lang_bi_ulong_t*) == sizeof(void*));
	mk_lang_static_assert(sizeof(mk_lang_bi_slong_t*) == sizeof(void*));
	mk_lang_static_assert(sizeof(mk_lang_bi_ullong_t*) == sizeof(void*));
	mk_lang_static_assert(sizeof(mk_lang_bi_sllong_t*) == sizeof(void*));
	mk_lang_static_assert(sizeof(mk_lang_bi_ulllong_t*) == sizeof(void*));
	mk_lang_static_assert(sizeof(mk_lang_bi_slllong_t*) == sizeof(void*));
	mk_lang_static_assert(sizeof(mk_lang_bi_uintptr_t*) == sizeof(void*));
	mk_lang_static_assert(sizeof(mk_lang_bi_sintptr_t*) == sizeof(void*));
	mk_lang_static_assert(sizeof(mk_lang_bi_uintmax_t*) == sizeof(void*));
	mk_lang_static_assert(sizeof(mk_lang_bi_sintmax_t*) == sizeof(void*));
	mk_lang_static_assert(sizeof(mk_lang_bi_size_t*) == sizeof(void*));
}
