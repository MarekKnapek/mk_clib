#include "mk_clib_app_info.h"

#include "mk_lang_bi_info.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"


mk_lang_jumbo int mk_clib_app_info_void(void) mk_lang_noexcept
{
	mk_lang_bi_info_print_sizes();
	return 0;
}
