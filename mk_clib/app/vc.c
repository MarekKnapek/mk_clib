#include "../src/mk_clib_app_vc.h"


#if mk_lang_os == mk_lang_os_windows

mk_lang_types_sint_t wmain(mk_lang_types_sint_t const argc, mk_lang_types_wchar_pcpct const argv) mk_lang_noexcept
{
	return mk_clib_app_vc_arg(mk_lang_true, argc, ((mk_lang_types_pchar_pcpct)(argv)));
}

#elif mk_lang_os == mk_lang_os_c

mk_lang_types_sint_t main(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	return mk_clib_app_vc_arg(mk_lang_false, argc, ((mk_lang_types_pchar_pcpct)(argv)));
}

#else

#error toto xxxxxxxxxx

#endif
