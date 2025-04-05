#include "../src/mk_clib_app_hasher.h"


mk_lang_types_sint_t main(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv)
{
	mk_lang_types_sint_t ret;

	ret = mk_clib_app_hasher_args(argc, argv);
	return ret;
}
