#define mk_lang_assert_want 1


#include "../src/mk_clib_app_vc.h"


mk_lang_types_sint_t main(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	return mk_clib_app_vc_arg(argc, argv);
}
