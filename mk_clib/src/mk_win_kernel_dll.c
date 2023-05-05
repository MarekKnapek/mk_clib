#include "mk_win_kernel_dll.h"

#include "mk_lang_assert.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_tstring.h"
#include "mk_win_tstring.h"
#include "mk_win_unicode_api.h"


mk_win_base_dll_import mk_win_kernel_dll_module_t mk_win_base_stdcall GetModuleHandleA(mk_win_base_pchar_lpct) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetModuleHandleExA(mk_win_base_dword_t, mk_win_base_pchar_lpct, mk_win_kernel_dll_module_lpt) mk_lang_noexcept;

mk_win_base_dll_import mk_win_kernel_dll_module_t mk_win_base_stdcall GetModuleHandleW(mk_win_base_wchar_lpct) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetModuleHandleExW(mk_win_base_dword_t, mk_win_base_wchar_lpct, mk_win_kernel_dll_module_lpt) mk_lang_noexcept;

mk_win_base_dll_import mk_win_base_proc_t mk_win_base_stdcall GetProcAddress(mk_win_kernel_dll_module_t, mk_win_base_pchar_lpct) mk_lang_noexcept;


typedef mk_win_base_bool_t(mk_win_base_far mk_win_base_stdcall*mk_win_kernel_dll_GetModuleHandleExA)(mk_win_base_dword_t, mk_win_base_pchar_lpct, mk_win_kernel_dll_module_lpt) mk_lang_noexcept;
typedef mk_win_base_bool_t(mk_win_base_far mk_win_base_stdcall*mk_win_kernel_dll_GetModuleHandleExW)(mk_win_base_dword_t, mk_win_base_wchar_lpct, mk_win_kernel_dll_module_lpt) mk_lang_noexcept;


static mk_win_base_proc_t g_mk_win_kernel_dll_GetModuleHandleExA;
static mk_win_base_proc_t g_mk_win_kernel_dll_GetModuleHandleExW;


mk_lang_nodiscard mk_lang_jumbo mk_win_kernel_dll_module_t mk_win_kernel_dll_a_get_handle(mk_win_base_pchar_lpct const name) mk_lang_noexcept
{
	mk_win_kernel_dll_module_t module;

	module = GetModuleHandleA(name);
	return module;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_dll_a_get_handle_ex(mk_win_kernel_dll_get_handle_ex_t const flags, mk_win_base_pchar_lpct const name, mk_win_kernel_dll_module_lpt const module) mk_lang_noexcept
{
	#if defined _MSC_VER && _MSC_VER == 1935
	#pragma warning(push)
	#pragma warning(disable:4191) /* warning C4191: 'type cast': unsafe conversion from 'xxx' to 'xxx' */
	#endif

	mk_win_base_bool_t got;

	if(!g_mk_win_kernel_dll_GetModuleHandleExA)
	{
		g_mk_win_kernel_dll_GetModuleHandleExA = mk_win_kernel_dll_get_proc_address(mk_win_kernel_dll_t_get_handle(mk_win_tstring_tchar_c("kernel32")), "GetModuleHandleExA");
		if(!g_mk_win_kernel_dll_GetModuleHandleExA)
		{
			g_mk_win_kernel_dll_GetModuleHandleExA = mk_win_base_proc_not_found;
		}
	}
	mk_lang_assert(g_mk_win_kernel_dll_GetModuleHandleExA);
	if(g_mk_win_kernel_dll_GetModuleHandleExA != mk_win_base_proc_not_found)
	{
		got = ((mk_win_kernel_dll_GetModuleHandleExA)(g_mk_win_kernel_dll_GetModuleHandleExA))(((mk_win_base_dword_t)(flags)), name, module);
		return got;
	}
	else
	{
		/* todo return current dll instead of current exe */
		*module = mk_win_kernel_dll_t_get_handle(mk_win_base_null);
		return mk_win_base_true;
	}

	#if defined _MSC_VER && _MSC_VER == 1935
	#pragma warning(pop)
	#endif
}


mk_lang_nodiscard mk_lang_jumbo mk_win_kernel_dll_module_t mk_win_kernel_dll_w_get_handle(mk_win_base_wchar_lpct const name) mk_lang_noexcept
{
	mk_win_kernel_dll_module_t module;

	module = GetModuleHandleW(name);
	return module;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_dll_w_get_handle_ex(mk_win_kernel_dll_get_handle_ex_t const flags, mk_win_base_wchar_lpct const name, mk_win_kernel_dll_module_lpt const module) mk_lang_noexcept
{
	#if defined _MSC_VER && _MSC_VER == 1935
	#pragma warning(push)
	#pragma warning(disable:4191) /* warning C4191: 'type cast': unsafe conversion from 'xxx' to 'xxx' */
	#endif

	mk_win_base_bool_t got;

	if(!g_mk_win_kernel_dll_GetModuleHandleExW)
	{
		g_mk_win_kernel_dll_GetModuleHandleExW = mk_win_kernel_dll_get_proc_address(mk_win_kernel_dll_t_get_handle(mk_win_tstring_tchar_c("kernel32")), "GetModuleHandleExW");
		if(!g_mk_win_kernel_dll_GetModuleHandleExW)
		{
			g_mk_win_kernel_dll_GetModuleHandleExW = mk_win_base_proc_not_found;
		}
	}
	mk_lang_assert(g_mk_win_kernel_dll_GetModuleHandleExW);
	if(g_mk_win_kernel_dll_GetModuleHandleExW != mk_win_base_proc_not_found)
	{
		got = ((mk_win_kernel_dll_GetModuleHandleExW)(g_mk_win_kernel_dll_GetModuleHandleExW))(((mk_win_base_dword_t)(flags)), name, module);
		return got;
	}
	else
	{
		/* todo return current dll instead of current exe */
		*module = mk_win_kernel_dll_t_get_handle(mk_win_base_null);
		return mk_win_base_true;
	}

	#if defined _MSC_VER && _MSC_VER == 1935
	#pragma warning(pop)
	#endif
}

mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_dll_t_get_handle_ex(mk_win_kernel_dll_get_handle_ex_t const flags, mk_win_tstring_tchar_lpct const name, mk_win_kernel_dll_module_lpt const module) mk_lang_noexcept
{
	mk_lang_assert((flags & mk_win_kernel_dll_get_handle_ex_e_from_address) == 0);

#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_kernel_dll_a_get_handle_ex(flags, name, module);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_kernel_dll_a_get_handle_ex(flags, mk_win_tstring_tstr_to_ansi_zt_nofail(name).m_str, module);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_kernel_dll_w_get_handle_ex(flags, name, module);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_kernel_dll_w_get_handle_ex(flags, mk_win_tstring_tstr_to_wide_zt_nofail(name).m_str, module);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_kernel_dll_a_get_handle_ex(flags, name, module);
		#else
			return mk_win_kernel_dll_a_get_handle_ex(flags, mk_win_tstring_tstr_to_ansi_zt_nofail(name).m_str, module);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_kernel_dll_w_get_handle_ex(flags, name, module);
		#else
			return mk_win_kernel_dll_w_get_handle_ex(flags, mk_win_tstring_tstr_to_wide_zt_nofail(name).m_str, module);
		#endif
	}
#endif
}

mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_dll_t_get_handle_from_address(mk_win_base_void_lpct const address, mk_win_kernel_dll_module_lpt const module) mk_lang_noexcept
{
	mk_lang_assert(address);

#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_kernel_dll_a_get_handle_ex(mk_win_kernel_dll_get_handle_ex_e_unchanged_refcount | mk_win_kernel_dll_get_handle_ex_e_from_address, ((mk_win_base_pchar_lpct)(address)), module);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_kernel_dll_a_get_handle_ex(mk_win_kernel_dll_get_handle_ex_e_unchanged_refcount | mk_win_kernel_dll_get_handle_ex_e_from_address, ((mk_win_base_pchar_lpct)(address)), module);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_kernel_dll_w_get_handle_ex(mk_win_kernel_dll_get_handle_ex_e_unchanged_refcount | mk_win_kernel_dll_get_handle_ex_e_from_address, ((mk_win_base_wchar_lpct)(address)), module);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_kernel_dll_w_get_handle_ex(mk_win_kernel_dll_get_handle_ex_e_unchanged_refcount | mk_win_kernel_dll_get_handle_ex_e_from_address, ((mk_win_base_wchar_lpct)(address)), module);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_kernel_dll_a_get_handle_ex(mk_win_kernel_dll_get_handle_ex_e_unchanged_refcount | mk_win_kernel_dll_get_handle_ex_e_from_address, ((mk_win_base_pchar_lpct)(address)), module);
		#else
			return mk_win_kernel_dll_a_get_handle_ex(mk_win_kernel_dll_get_handle_ex_e_unchanged_refcount | mk_win_kernel_dll_get_handle_ex_e_from_address, ((mk_win_base_pchar_lpct)(address)), module);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_kernel_dll_w_get_handle_ex(mk_win_kernel_dll_get_handle_ex_e_unchanged_refcount | mk_win_kernel_dll_get_handle_ex_e_from_address, ((mk_win_base_wchar_lpct)(address)), module);
		#else
			return mk_win_kernel_dll_w_get_handle_ex(mk_win_kernel_dll_get_handle_ex_e_unchanged_refcount | mk_win_kernel_dll_get_handle_ex_e_from_address, ((mk_win_base_wchar_lpct)(address)), module);
		#endif
	}
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_win_kernel_dll_module_t mk_win_kernel_dll_t_get_handle(mk_win_tstring_tchar_lpct const name) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_kernel_dll_a_get_handle(name);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_kernel_dll_a_get_handle(mk_win_tstring_tstr_to_ansi_zt_nofail(name));
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_kernel_dll_w_get_handle(name);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_kernel_dll_w_get_handle(mk_win_tstring_tstr_to_wide_zt_nofail(name));
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_kernel_dll_a_get_handle(name);
		#else
			return mk_win_kernel_dll_a_get_handle(mk_win_tstring_tstr_to_ansi_zt_nofail(name).m_str);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_kernel_dll_w_get_handle(name);
		#else
			return mk_win_kernel_dll_w_get_handle(mk_win_tstring_tstr_to_wide_zt_nofail(name).m_str);
		#endif
	}
#endif
}


mk_lang_nodiscard mk_lang_jumbo mk_win_base_proc_t mk_win_kernel_dll_get_proc_address(mk_win_kernel_dll_module_t const module, mk_win_base_pchar_lpct const name) mk_lang_noexcept
{
	mk_win_base_proc_t proc;

	proc = GetProcAddress(module, name);
	return proc;
}
