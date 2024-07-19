#include "mk_lib_win_statistics.h"

#include "mk_lang_stringify.h"
#include "mk_lang_version.h"
#include "mk_lang_static_param.h"
#include "mk_lang_countof.h"
#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_handle.h"
#include "mk_win_kernel_dll.h"
#include "mk_win_kernel_process.h"
#include "mk_win_kernel_thread.h"
#include "mk_win_user_base.h"
#include "mk_win_user_class.h"
#include "mk_win_user_icon.h"
#include "mk_win_user_cursor.h"
#include "mk_win_user_window.h"
#include "mk_lib_crypto_hash_stream_sha1.h"
#include "mk_lib_cpp_constexpr.hpp"
#include "mk_sl_uint8.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint.h"


#define mk_lib_win_statistics_class_name_n  "mk_lib_win_statistics"
#define mk_lib_win_statistics_class_name_w L"mk_lib_win_statistics"


struct mk_lib_win_statistics_s
{
	mk_win_user_base_atom_t m_atom;
	mk_win_user_base_wnd_t m_wnd;
};
typedef struct mk_lib_win_statistics_s mk_lib_win_statistics_t;
typedef mk_lib_win_statistics_t const mk_lib_win_statistics_ct;
typedef mk_lib_win_statistics_t* mk_lib_win_statistics_pt;
typedef mk_lib_win_statistics_t const* mk_lib_win_statistics_pct;


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_win_statistics_window_class_name_generate(mk_lang_static_param(mk_lang_types_wchar_t, res, 4 * 2)) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint8_t arr[mk_lang_countstr(mk_lib_win_statistics_class_name_n)] mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_sha1_t hasher mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_sha1_digest_t digest mk_lang_constexpr_init;
	mk_sl_cui_uint32_t u32 mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(res);

	n = mk_lang_countstr(mk_lib_win_statistics_class_name_n);
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_from_bi_pchar(&arr[i], &mk_lib_win_statistics_class_name_n[i]);
	}
	mk_lib_crypto_hash_stream_sha1_init(&hasher);
	mk_lib_crypto_hash_stream_sha1_append_u8(&hasher, &arr[0], n);
	mk_lib_crypto_hash_stream_sha1_finish(&hasher, &digest);
	mk_sl_uint_32_from_8_le(&u32, &digest.m_uint8s[0]);
	len = mk_sl_cui_uint32_to_str_hexf_w(&u32, res, 4 * 2); mk_lang_assert(len == 4 * 2);
}

#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

mk_lang_constexpr static mk_lang_inline auto mk_lib_win_statistics_window_class_name_return(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_lang_types_wchar_t, 4 * 2 + 1> arr mk_lang_constexpr_init;

	mk_lib_win_statistics_window_class_name_generate(arr.arr());
	arr[4 * 2 + 0] = L'\0';
	return arr;
}

mk_lang_constexpr_static_inline auto const s_mk_lib_win_statistics_window_class_name = mk_lib_win_statistics_window_class_name_return();

#endif

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_wchar_pct mk_lib_win_statistics_window_class_name_get(mk_lang_types_void_t) mk_lang_noexcept
{
#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
	return s_mk_lib_win_statistics_window_class_name.cdata();
#else
	return mk_lib_win_statistics_class_name_w;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_win_statistics_show(mk_lib_win_statistics_pt const statistics) mk_lang_noexcept
{
	mk_lang_assert(statistics);
	return 0;
}

mk_lang_nodiscard static mk_win_user_base_lresult_t mk_win_base_stdcall mk_lib_win_statistics_on_raw_msg(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const msg, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam) mk_lang_noexcept
{
	mk_win_user_base_lresult_t lr;

	lr = mk_win_user_window_w_def_proc(wnd, msg, wparam, lparam);
	return lr;
}


static mk_lib_win_statistics_t g_mk_lib_win_statistics;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_win_statistics_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_win_statistics_pt statistics;
	mk_win_base_bool_t b;
	mk_win_base_module_t this_module;
	mk_win_user_class_exw_t cls;
	mk_win_user_base_atom_t atom;

	statistics = &g_mk_lib_win_statistics;
	b = mk_win_kernel_dll_w_get_module_handle_ex(((mk_win_base_dword_t)(mk_win_kernel_dll_get_module_handle_ex_flags_e_from_address)), ((mk_win_base_wchar_pct)(((mk_win_base_void_pt)(&mk_lib_win_statistics_on_raw_msg)))), &this_module); mk_lang_check_return(b != 0); mk_lang_check_return(!mk_win_base_module_is_null(this_module));
	cls.m_len = ((mk_win_base_uint_t)(sizeof(cls)));
	cls.m_style = ((mk_win_base_uint_t)(mk_win_user_class_style_id_e_vredraw | mk_win_user_class_style_id_e_hredraw));
	cls.m_callback = &mk_lib_win_statistics_on_raw_msg;
	cls.m_extra_cls = ((mk_win_base_sint_t)(0));
	cls.m_extra_wnd = ((mk_win_base_sint_t)(sizeof(statistics)));
	cls.m_instance = mk_win_base_instance_from(this_module.m_data);
	cls.m_icon_big = mk_win_user_icon_w_load(mk_win_base_instance_get_null(), ((mk_win_base_wchar_lpct)(((mk_win_base_uintptr_t)(((mk_win_base_ushort_t)(mk_win_user_icon_id_e_application)))))));
	cls.m_cursor = mk_win_user_cursor_w_load(mk_win_base_instance_get_null(), ((mk_win_base_wchar_lpct)(((mk_win_base_uintptr_t)(((mk_win_base_ushort_t)(mk_win_user_cursor_id_e_arrow)))))));
	cls.m_background = mk_win_user_brush_from_color_id(mk_win_user_base_color_id_e_window);
	cls.m_menu = ((mk_win_base_wchar_lpct)(mk_win_base_null));
	cls.m_name = mk_lib_win_statistics_window_class_name_get();
	cls.m_icon_smol = cls.m_icon_big;
	atom = mk_win_user_class_register_exw(&cls); mk_lang_check_return(atom != 0);
	statistics->m_atom = atom;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_win_statistics_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_win_statistics_pt statistics;
	mk_win_base_bool_t b;
	mk_win_base_module_t this_module;

	statistics = &g_mk_lib_win_statistics;
	mk_lang_assert(statistics->m_atom != 0);
	b = mk_win_kernel_dll_w_get_module_handle_ex(((mk_win_base_dword_t)(mk_win_kernel_dll_get_module_handle_ex_flags_e_from_address)), ((mk_win_base_wchar_pct)(((mk_win_base_void_pt)(&mk_lib_win_statistics_on_raw_msg)))), &this_module); mk_lang_check_return(b != 0); mk_lang_check_return(!mk_win_base_module_is_null(this_module));
	b = mk_win_user_class_w_unregister(((mk_win_base_wchar_pct)(((mk_win_base_uintptr_t)(statistics->m_atom)))), mk_win_base_instance_from(this_module.m_data)); mk_lang_check_return(b != 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_win_statistics_display(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_win_statistics_pt statistics;
	mk_lang_types_sint_t err;

	statistics = &g_mk_lib_win_statistics;
	err = mk_lib_win_statistics_show(statistics); mk_lang_check_rereturn(err);
	return 0;
}
