#include "mk_lang_limits_test.h"

#include "mk_lang_arch.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"


mk_lang_jumbo void mk_lang_limits_test(void) mk_lang_noexcept
{
	/* Beware, might fail on different platform than mine. */

#if mk_lang_lllong_has
#define ulllong_max ((mk_lang_ulllong_t)(((mk_lang_ulllong_t)(((mk_lang_ulllong_t)(mk_lang_ullong_c(0xffffffffffffffff))) << 64)) | ((mk_lang_ulllong_t)(mk_lang_ullong_c(0xffffffffffffffff)))))
#define slllong_min ((mk_lang_slllong_t)(((mk_lang_slllong_t)(((mk_lang_slllong_t)(mk_lang_sllong_c(-9223372036854775807) - mk_lang_sllong_c(1))) << 64)) | ((mk_lang_slllong_t)(mk_lang_ullong_c(0x0000000000000000)))))
#define slllong_max ((mk_lang_slllong_t)(((mk_lang_slllong_t)(((mk_lang_slllong_t)(mk_lang_ullong_c(9223372036854775807))) << 64)) | ((mk_lang_slllong_t)(mk_lang_ullong_c(0xffffffffffffffff)))))
#else
#define ulllong_max (mk_lang_ullong_c(0xffffffffffffffff))
#define slllong_min ((mk_lang_sllong_c(-9223372036854775807) - mk_lang_sllong_c(1)))
#define slllong_max (mk_lang_ullong_c(9223372036854775807))
#endif

#if mk_lang_bitness == mk_lang_bitness_16
	todo
#elif mk_lang_bitness == mk_lang_bitness_32
	mk_lang_static_assert(mk_lang_limits_uchar_min   == mk_lang_ullong_c(0));
	mk_lang_static_assert(mk_lang_limits_ushort_min  == mk_lang_ullong_c(0));
	mk_lang_static_assert(mk_lang_limits_uint_min    == mk_lang_ullong_c(0));
	mk_lang_static_assert(mk_lang_limits_ulong_min   == mk_lang_ullong_c(0));
	mk_lang_static_assert(mk_lang_limits_ullong_min  == mk_lang_ullong_c(0));
	mk_lang_static_assert(mk_lang_limits_ulllong_min == mk_lang_ullong_c(0));
	mk_lang_static_assert(mk_lang_limits_uinptr_min  == mk_lang_ullong_c(0));
	mk_lang_static_assert(mk_lang_limits_uintmax_min == mk_lang_ullong_c(0));
	mk_lang_static_assert(mk_lang_limits_usize_min   == mk_lang_ullong_c(0));

	mk_lang_static_assert(mk_lang_limits_uchar_max   == mk_lang_ullong_c(0xff));
	mk_lang_static_assert(mk_lang_limits_ushort_max  == mk_lang_ullong_c(0xffff));
	mk_lang_static_assert(mk_lang_limits_uint_max    == mk_lang_ullong_c(0xffffffff));
	mk_lang_static_assert(mk_lang_limits_ulong_max   == mk_lang_ullong_c(0xffffffff));
	mk_lang_static_assert(mk_lang_limits_ullong_max  == mk_lang_ullong_c(0xffffffffffffffff));
	mk_lang_static_assert(mk_lang_limits_ulllong_max == mk_lang_ullong_c(0xffffffffffffffff));
	mk_lang_static_assert(mk_lang_limits_uintptr_max == mk_lang_ullong_c(0xffffffff));
	mk_lang_static_assert(mk_lang_limits_uintmax_max == mk_lang_ullong_c(0xffffffffffffffff));
	mk_lang_static_assert(mk_lang_limits_usize_max   == mk_lang_ullong_c(0xffffffff));

	mk_lang_static_assert(mk_lang_limits_schar_min   == (mk_lang_sllong_c(-127)                 - mk_lang_sllong_c(1)));
	mk_lang_static_assert(mk_lang_limits_sshort_min  == (mk_lang_sllong_c(-32767)               - mk_lang_sllong_c(1)));
	mk_lang_static_assert(mk_lang_limits_sint_min    == (mk_lang_sllong_c(-2147483647)          - mk_lang_sllong_c(1)));
	mk_lang_static_assert(mk_lang_limits_slong_min   == (mk_lang_sllong_c(-2147483647)          - mk_lang_sllong_c(1)));
	mk_lang_static_assert(mk_lang_limits_sllong_min  == (mk_lang_sllong_c(-9223372036854775807) - mk_lang_sllong_c(1)));
	mk_lang_static_assert(mk_lang_limits_slllong_min == (mk_lang_sllong_c(-9223372036854775807) - mk_lang_sllong_c(1)));
	mk_lang_static_assert(mk_lang_limits_sintptr_min == (mk_lang_sllong_c(-2147483647)          - mk_lang_sllong_c(1)));
	mk_lang_static_assert(mk_lang_limits_sintmax_min == (mk_lang_sllong_c(-9223372036854775807) - mk_lang_sllong_c(1)));
	mk_lang_static_assert(mk_lang_limits_ssize_min   == (mk_lang_sllong_c(-2147483647)          - mk_lang_sllong_c(1)));

	mk_lang_static_assert(mk_lang_limits_schar_max   == mk_lang_sllong_c(127));
	mk_lang_static_assert(mk_lang_limits_sshort_max  == mk_lang_sllong_c(32767));
	mk_lang_static_assert(mk_lang_limits_sint_max    == mk_lang_sllong_c(2147483647));
	mk_lang_static_assert(mk_lang_limits_slong_max   == mk_lang_sllong_c(2147483647));
	mk_lang_static_assert(mk_lang_limits_sllong_max  == mk_lang_sllong_c(9223372036854775807));
	mk_lang_static_assert(mk_lang_limits_slllong_max == mk_lang_sllong_c(9223372036854775807));
	mk_lang_static_assert(mk_lang_limits_sintptr_max == mk_lang_sllong_c(2147483647));
	mk_lang_static_assert(mk_lang_limits_sintmax_max == mk_lang_sllong_c(9223372036854775807));
	mk_lang_static_assert(mk_lang_limits_ssize_max   == mk_lang_sllong_c(2147483647));
#elif mk_lang_bitness == mk_lang_bitness_64
	mk_lang_static_assert(mk_lang_limits_uchar_min   == mk_lang_ullong_c(0));
	mk_lang_static_assert(mk_lang_limits_ushort_min  == mk_lang_ullong_c(0));
	mk_lang_static_assert(mk_lang_limits_uint_min    == mk_lang_ullong_c(0));
	mk_lang_static_assert(mk_lang_limits_ulong_min   == mk_lang_ullong_c(0));
	mk_lang_static_assert(mk_lang_limits_ullong_min  == mk_lang_ullong_c(0));
	mk_lang_static_assert(mk_lang_limits_ulllong_min == mk_lang_ullong_c(0));
	mk_lang_static_assert(mk_lang_limits_uinptr_min  == mk_lang_ullong_c(0));
	mk_lang_static_assert(mk_lang_limits_uintmax_min == mk_lang_ullong_c(0));
	mk_lang_static_assert(mk_lang_limits_usize_min   == mk_lang_ullong_c(0));

	mk_lang_static_assert(mk_lang_limits_uchar_max   == mk_lang_ullong_c(0xff));
	mk_lang_static_assert(mk_lang_limits_ushort_max  == mk_lang_ullong_c(0xffff));
	mk_lang_static_assert(mk_lang_limits_uint_max    == mk_lang_ullong_c(0xffffffff));
	mk_lang_static_assert(mk_lang_limits_ulong_max   == mk_lang_ullong_c(0xffffffff));
	mk_lang_static_assert(mk_lang_limits_ullong_max  == mk_lang_ullong_c(0xffffffffffffffff));
	mk_lang_static_assert(mk_lang_limits_ulllong_max == ulllong_max);
	mk_lang_static_assert(mk_lang_limits_uintptr_max == mk_lang_ullong_c(0xffffffffffffffff));
	mk_lang_static_assert(mk_lang_limits_uintmax_max == mk_lang_ullong_c(0xffffffffffffffff));
	mk_lang_static_assert(mk_lang_limits_usize_max   == mk_lang_ullong_c(0xffffffffffffffff));

	mk_lang_static_assert(mk_lang_limits_schar_min   == (mk_lang_sllong_c(-127)                 - mk_lang_sllong_c(1)));
	mk_lang_static_assert(mk_lang_limits_sshort_min  == (mk_lang_sllong_c(-32767)               - mk_lang_sllong_c(1)));
	mk_lang_static_assert(mk_lang_limits_sint_min    == (mk_lang_sllong_c(-2147483647)          - mk_lang_sllong_c(1)));
	mk_lang_static_assert(mk_lang_limits_slong_min   == (mk_lang_sllong_c(-2147483647)          - mk_lang_sllong_c(1)));
	mk_lang_static_assert(mk_lang_limits_sllong_min  == (mk_lang_sllong_c(-9223372036854775807) - mk_lang_sllong_c(1)));
	mk_lang_static_assert(mk_lang_limits_slllong_min == slllong_min);
	mk_lang_static_assert(mk_lang_limits_sintptr_min == (mk_lang_sllong_c(-9223372036854775807) - mk_lang_sllong_c(1)));
	mk_lang_static_assert(mk_lang_limits_sintmax_min == (mk_lang_sllong_c(-9223372036854775807) - mk_lang_sllong_c(1)));
	mk_lang_static_assert(mk_lang_limits_ssize_min   == (mk_lang_sllong_c(-9223372036854775807) - mk_lang_sllong_c(1)));

	mk_lang_static_assert(mk_lang_limits_schar_max   == mk_lang_sllong_c(127));
	mk_lang_static_assert(mk_lang_limits_sshort_max  == mk_lang_sllong_c(32767));
	mk_lang_static_assert(mk_lang_limits_sint_max    == mk_lang_sllong_c(2147483647));
	mk_lang_static_assert(mk_lang_limits_slong_max   == mk_lang_sllong_c(2147483647));
	mk_lang_static_assert(mk_lang_limits_sllong_max  == mk_lang_sllong_c(9223372036854775807));
	mk_lang_static_assert(mk_lang_limits_slllong_max == slllong_max);
	mk_lang_static_assert(mk_lang_limits_sintptr_max == mk_lang_sllong_c(9223372036854775807));
	mk_lang_static_assert(mk_lang_limits_sintmax_max == mk_lang_sllong_c(9223372036854775807));
	mk_lang_static_assert(mk_lang_limits_ssize_max   == mk_lang_sllong_c(9223372036854775807));
#endif
}
