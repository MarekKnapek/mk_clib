#include "../src/mk_clib_app_defrag.h"


#if (mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows) && (defined mk_lang_nodefaultlib_want && mk_lang_nodefaultlib_want == 1)

mk_lang_extern_c mk_lang_types_sint_t mkentry(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	return mk_clib_app_defrag_peb(peb);
}

#elif mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows

mk_lang_types_sint_t wmain(mk_lang_types_sint_t const argc, mk_lang_types_wchar_pcpct const argv) mk_lang_noexcept
{
	return mk_clib_app_defrag_arg(mk_lang_true, argc, ((mk_lang_types_pchar_pcpct)(argv)));
}

#elif mk_lang_platform == mk_lang_platform_linux || mk_lang_platform == mk_lang_platform_portable

mk_lang_types_sint_t main(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	return mk_clib_app_defrag_arg(mk_lang_false, argc, ((mk_lang_types_pchar_pcpct)(argv)));
}

#else

#error toto xxxxxxxxxx

#endif
