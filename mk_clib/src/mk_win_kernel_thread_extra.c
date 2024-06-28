#include "mk_win_kernel_thread_extra.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_cpp.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_win_advapi_types.h"
#include "mk_win_base.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_hresult_t mk_win_base_stdcall SetThreadDescription(mk_win_base_handle_t const thread, mk_win_base_wchar_lpct const description) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_module_t mk_win_base_stdcall GetModuleHandleA(mk_win_base_pchar_lpct const name) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_proc_t mk_win_base_stdcall GetProcAddress(mk_win_base_module_t const module, mk_win_base_pchar_lpct const name) mk_lang_noexcept;


#if mk_lang_version_at_least_cpp_17
typedef mk_win_base_hresult_t(mk_win_base_stdcall*SetThreadDescription_fn_t)(mk_win_base_handle_t const thread, mk_win_base_wchar_lpct const description) mk_lang_noexcept;
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
typedef decltype(& SetThreadDescription) SetThreadDescription_fn_t;
#else
typedef mk_win_base_hresult_t(mk_win_base_stdcall*SetThreadDescription_fn_t)(mk_win_base_handle_t const thread, mk_win_base_wchar_lpct const description) mk_lang_noexcept;
#endif


static SetThreadDescription_fn_t g_mk_win_kernel_thread_extra_description_set;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_win_kernel_thread_extra_inited_description_set(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	ret = g_mk_win_kernel_thread_extra_description_set != mk_lang_null;
	return ret;
}

static mk_lang_inline mk_lang_types_void_t mk_win_kernel_thread_extra_init_description_set(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_module_t kernel32;
	mk_win_base_proc_t proc;

	mk_lang_assert(!mk_win_kernel_thread_extra_inited_description_set());

	kernel32 = GetModuleHandleA("kernel32.dll"); mk_lang_assert(!mk_win_base_module_is_null(kernel32));
	proc = GetProcAddress(kernel32, "SetThreadDescription");
	g_mk_win_kernel_thread_extra_description_set = ((SetThreadDescription_fn_t)(proc));
	if(!g_mk_win_kernel_thread_extra_description_set)
	{
		g_mk_win_kernel_thread_extra_description_set = ((SetThreadDescription_fn_t)(((mk_lang_types_usize_pct)(mk_lang_null)) + 1));
	}
}

static mk_lang_inline mk_lang_types_void_t mk_win_kernel_thread_extra_init_if_not_description_set(mk_lang_types_void_t) mk_lang_noexcept
{
	if(!mk_win_kernel_thread_extra_inited_description_set())
	{
		mk_win_kernel_thread_extra_init_description_set();
	}
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_win_kernel_thread_extra_description_set(mk_win_base_handle_t const thread, mk_win_base_wchar_lpct const description, mk_win_base_hresult_pt const ret) mk_lang_noexcept
{
	mk_win_base_hresult_t r;

	mk_win_kernel_thread_extra_init_if_not_description_set();
	if(g_mk_win_kernel_thread_extra_description_set != ((SetThreadDescription_fn_t)(((mk_lang_types_usize_pct)(mk_lang_null)) + 1)))
	{
		r = g_mk_win_kernel_thread_extra_description_set(thread, description);
		*ret = r;
		return mk_lang_true;
	}
	else
	{
		return mk_lang_false;
	}
}
