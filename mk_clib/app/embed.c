#include "../src/mk_clib_app_embed.h"


#if (mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows_51 || mk_lang_platform == mk_lang_platform_windows) && (defined mk_lang_nodefaultlib_want && mk_lang_nodefaultlib_want == 1)

mk_lang_extern_c mk_lang_types_void_t mkentry(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_clib_app_embed_peb(peb);
	mk_win_kernel_process_exit(((mk_lang_types_uint_t)(err)));
}

#elif mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows

mk_lang_nodiscard mk_lang_types_sint_t mk_win_base_stdcall wWinMain(mk_win_base_instance_t const instance, mk_win_base_instance_t const prev, mk_win_base_wchar_lpct const cmd_line, mk_lang_types_sint_t const show) mk_lang_noexcept
{
	return mk_clib_app_embed_arg(mk_lang_true, instance, prev, cmd_line, show);
}

#elif mk_lang_platform == mk_lang_platform_linux || mk_lang_platform == mk_lang_platform_portable

#error xxxxxxxxxx

#else

#error todo xxxxxxxxxx

#endif
