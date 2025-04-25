#include "../src/mk_clib_app_info.h"


#if mk_lang_entry_point_have


mk_lang_extern_force_c mk_lang_types_sint_t mk_lang_entry_point(mk_lang_types_void_pt const peb) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_types_sint_t mk_lang_entry_point(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_clib_app_info_peb(peb);
	return ret;
}


#else


mk_lang_types_sint_t main(mk_lang_types_void_t)
{
	mk_lang_types_sint_t ret;

	ret = mk_clib_app_info_void();
	return ret;
}


#endif
