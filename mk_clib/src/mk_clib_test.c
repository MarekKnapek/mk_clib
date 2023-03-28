#include "mk_clib_test.h"

#include "mk_lang_bi_test.h"
#include "mk_lang_constexpr_test.hpp"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof_test.h"


mk_lang_jumbo void mk_clib_test(void) mk_lang_noexcept
{
	mk_lang_bi_test();
	mk_lang_constexpr_test();
	mk_lang_sizeof_test();
}
