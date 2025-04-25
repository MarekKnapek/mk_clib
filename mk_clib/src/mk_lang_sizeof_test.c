#ifndef mk_include_guard_mk_lang_sizeof_test_c
#define mk_include_guard_mk_lang_sizeof_test_c
#include "mk_lang_sizeof_test.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"


mk_lang_jumbo mk_lang_types_void_t mk_lang_sizeof_test(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_sizeof_bi_bool_t    == sizeof(mk_lang_types_bool_t   ));
	mk_lang_static_assert(mk_lang_sizeof_bi_pchar_t   == sizeof(mk_lang_types_pchar_t  ));
	mk_lang_static_assert(mk_lang_sizeof_bi_wchar_t   == sizeof(mk_lang_types_wchar_t  ));
	mk_lang_static_assert(mk_lang_sizeof_bi_uchar_t   == sizeof(mk_lang_types_uchar_t  ));
	mk_lang_static_assert(mk_lang_sizeof_bi_schar_t   == sizeof(mk_lang_types_schar_t  ));
	mk_lang_static_assert(mk_lang_sizeof_bi_ushort_t  == sizeof(mk_lang_types_ushort_t ));
	mk_lang_static_assert(mk_lang_sizeof_bi_sshort_t  == sizeof(mk_lang_types_sshort_t ));
	mk_lang_static_assert(mk_lang_sizeof_bi_uint_t    == sizeof(mk_lang_types_uint_t   ));
	mk_lang_static_assert(mk_lang_sizeof_bi_sint_t    == sizeof(mk_lang_types_sint_t   ));
	mk_lang_static_assert(mk_lang_sizeof_bi_ulong_t   == sizeof(mk_lang_types_ulong_t  ));
	mk_lang_static_assert(mk_lang_sizeof_bi_slong_t   == sizeof(mk_lang_types_slong_t  ));
	mk_lang_static_assert(mk_lang_sizeof_bi_ullong_t  == sizeof(mk_lang_types_ullong_t ));
	mk_lang_static_assert(mk_lang_sizeof_bi_sllong_t  == sizeof(mk_lang_types_sllong_t ));
	mk_lang_static_assert(mk_lang_sizeof_bi_ulllong_t == sizeof(mk_lang_types_ulllong_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_slllong_t == sizeof(mk_lang_types_slllong_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_uintptr_t == sizeof(mk_lang_types_uintptr_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_sintptr_t == sizeof(mk_lang_types_sintptr_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_uintmax_t == sizeof(mk_lang_types_uintmax_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_sintmax_t == sizeof(mk_lang_types_sintmax_t));
	mk_lang_static_assert(mk_lang_sizeof_bi_usize_t   == sizeof(mk_lang_types_usize_t  ));
	mk_lang_static_assert(mk_lang_sizeof_bi_ssize_t   == sizeof(mk_lang_types_ssize_t  ));
}


#endif
