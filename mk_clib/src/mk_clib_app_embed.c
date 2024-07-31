#include "mk_clib_app_embed.h"

#include "mk_lang_check.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


struct mk_clib_app_embed_s
{
	int x;
};
typedef struct mk_clib_app_embed_s mk_clib_app_embed_t;
typedef mk_clib_app_embed_t const mk_clib_app_embed_ct;
typedef mk_clib_app_embed_t* mk_clib_app_embed_pt;
typedef mk_clib_app_embed_t const* mk_clib_app_embed_pct;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_embed_run_args(mk_lang_types_sint_t const argc, mk_lang_types_wchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_check_return(argc == 3);
	mk_lang_check_return(argv);
	n = 3;
	for(i = 0; i != n; ++i)
	{
		mk_lang_check_return(argv[i]);
		mk_lang_check_return(argv[i][0] != L'\0');
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_embed_run_line(mk_lang_types_bool_t const wide, mk_win_base_wchar_lpct const cmd_line) mk_lang_noexcept
{
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_embed_arg(mk_lang_types_bool_t const wide, mk_win_base_instance_t const instance, mk_win_base_instance_t const prev, mk_win_base_wchar_lpct const cmd_line, mk_lang_types_sint_t const show) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t res;

	res = 0;
	return res;
}


#if defined mk_lang_nodefaultlib_want && mk_lang_nodefaultlib_want == 1


#include "mk_win_base.h"
#include "mk_win_kernel_dll.h"
#include "mk_win_kernel_process.h"
#include "mk_win_user_window.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_embed_peb(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(peb);

	err = mk_clib_app_embed_arg(mk_lang_true, mk_win_base_instance_from(mk_win_kernel_dll_w_get_module_handle(mk_win_base_null).m_data), mk_win_base_instance_get_null(), mk_win_kernel_process_get_command_line(), ((mk_lang_types_sint_t)(mk_win_user_window_show_e_showdefault)));
	return err;
}


#endif
