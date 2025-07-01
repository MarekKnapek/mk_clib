#include "../src/mk_clib_app_iip.h"
#include "../src/mk_lang_external_zlib.h"


#if mk_lang_entry_point_have


mk_lang_extern_force_c mk_lang_types_sint_t mk_lang_entry_point(mk_lang_types_void_pt const peb) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_types_sint_t mk_lang_entry_point(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_clib_app_iip_peb(peb);
	return ret;
}


#else


mk_lang_types_sint_t main(mk_lang_types_sint_t const argc, mk_lang_types_pchar_ppt const argv)
{
	mk_lang_types_sint_t ret;

	ret = mk_clib_app_iip_args(argc, argv);
	return ret;
}


#endif
