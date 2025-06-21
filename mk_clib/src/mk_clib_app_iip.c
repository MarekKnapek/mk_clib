#ifndef mk_include_guard_mk_clib_app_iip_c
#define mk_include_guard_mk_clib_app_iip_c
#include "mk_clib_app_iip.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_version.h"
#include "mk_lang_command_line.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_entry_point.h"
#include "mk_lang_exe_name.h"
#include "mk_lang_extern.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stdout.h"
#include "mk_lang_str_len.h"
#include "mk_lang_tchar.h"
#include "mk_lang_types.h"
#include "mk_lib_fmt.h"
#include "mk_lib_iip_cp_message.h"
#include "mk_lib_iip_cp_message_str.h"
#include "mk_lib_iip_time.h"
#include "mk_sl_cui_uint64.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14


#include "mk_lang_constexpr.h"
#include "mk_lib_cpp_constexpr_array.hpp"
#include "mk_lib_cpp_constexpr_array_u8.hpp"


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t xxx_fn_len(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_iip_cp_message_t obj mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf[4 * 1024] mk_lang_constexpr_init;
	mk_lang_types_sint_t out_len mk_lang_constexpr_init;

	err = mk_lib_iip_cp_message_construct(&obj, mk_lib_iip_cp_message_message_type_id_e_create_session); mk_lang_check_recrash(err);
	str_len = mk_lang_countof(str_buf);
	err = mk_lib_iip_cp_message_str_to_json_message(&str_buf[0], str_len, &out_len, &obj); mk_lang_check_recrash(err);
	err = mk_lib_iip_cp_message_destroy(&obj); mk_lang_check_recrash(err);
	return out_len;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline auto xxx_fn_arr(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_iip_cp_message_t obj mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_pchar_t, xxx_fn_len()> arr mk_lang_constexpr_init;
	mk_lang_types_sint_t out_len mk_lang_constexpr_init;

	err = mk_lib_iip_cp_message_construct(&obj, mk_lib_iip_cp_message_message_type_id_e_create_session); mk_lang_check_recrash(err);
	str_len = ((mk_lang_types_sint_t)(arr.size()));
	err = mk_lib_iip_cp_message_str_to_json_message(arr.data(), str_len, &out_len, &obj); mk_lang_check_recrash(err); mk_lang_check_crash(out_len == str_len);
	err = mk_lib_iip_cp_message_destroy(&obj); mk_lang_check_recrash(err);

	return arr;
}


mk_lang_constexpr_static_inline auto const xxx_k_arr = xxx_fn_arr();


#else

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t xxx_fn_buf(mk_lang_types_pchar_pt const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_iip_cp_message_t obj mk_lang_constexpr_init;
	mk_lang_types_sint_t out_len mk_lang_constexpr_init;

	err = mk_lib_iip_cp_message_construct(&obj, mk_lib_iip_cp_message_message_type_id_e_create_session); mk_lang_check_recrash(err);
	err = mk_lib_iip_cp_message_str_to_json_message(buf, len, &out_len, &obj); mk_lang_check_recrash(err);
	err = mk_lib_iip_cp_message_destroy(&obj); mk_lang_check_recrash(err);

	return out_len;
}

#endif


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_work(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(argc == 3);
	mk_lang_assert(argv);
	mk_lang_assert(lens);

	n = argc;
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(argv[i]);
		mk_lang_assert(argv[i][0] != mk_lang_tchar_c('\0'));
		mk_lang_assert(lens[i] >= 1);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_usage(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_tchar_pct exe_name;
	mk_lang_types_sint_t exe_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;
	mk_lang_tchar_t buf[4 * 1024];
	mk_sl_cui_uint64_t time_val;
	mk_lang_types_pchar_t time_str[24];
	mk_lang_types_sint_t time_len;

	mk_lang_assert(argc == 1);
	mk_lang_assert(argv);
	mk_lang_assert(lens);
	mk_lang_assert(argv[0]);
	mk_lang_assert(argv[0][0] != mk_lang_tchar_c('\0'));
	mk_lang_assert(lens[0] >= 1);

	exe_name = mk_lang_exe_name_get_t(argv[0]); mk_lang_check_return(exe_name); mk_lang_check_return(exe_name[0] != mk_lang_tchar_c('\0'));
	exe_len = lens[0] - ((mk_lang_types_sint_t)(exe_name - argv[0])); mk_lang_check_return(exe_len >= 1);
	err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("iip")); mk_lang_check_rereturn(err);
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("exe name: %t")), exe_name, exe_len); mk_lang_check_return(len >= 1); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);

	mk_lib_iip_time_get_now(&time_val);
	mk_lib_iip_time_to_text(&time_val, &time_str[0], mk_lang_countof(time_str), &time_len);
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("time: %ht")), &time_str[0], time_len); mk_lang_check_return(len >= 1); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("msg: %ht")), xxx_k_arr.data(), ((mk_lang_types_sint_t)(xxx_k_arr.size()))); mk_lang_check_return(len >= 1); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	#else
	{
		mk_lang_types_sint_t lll;
		mk_lang_types_pchar_t buff[4*1024];

		lll = xxx_fn_buf(&buff[0], mk_lang_countof(buff));
		len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("msg: %ht")), &buff[0], lll); mk_lang_check_return(len >= 1); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	}
	#endif

	err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("")); mk_lang_check_rereturn(err);
	return 0;
}


#if mk_lang_entry_point_have


#include "mk_win_dll_kernel_process.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_wargs(mk_lang_types_sint_t const argc, mk_lang_types_wchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	if(argc == 1)
	{
		err = mk_clib_app_iip_usage(argc, argv, lens); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_lang_check_return(argc == 3);
		err = mk_clib_app_iip_work(argc, argv, lens); mk_lang_check_rereturn(err);
	}
	return 0;
}


mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t mk_clib_app_iip_peb(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_wchar_pct argv[16];
	mk_lang_types_sint_t lens[mk_lang_countof(argv)];
	mk_lang_types_sint_t argc;

	mk_lang_assert(peb);

	mk_lang_cpuid_init();
	err = mk_lang_stdout_init(); mk_lang_check_rereturn(err);
	err = mk_lang_command_line_parse(mk_win_dll_kernel_process_get_command_line(), &argv[0], &lens[0], mk_lang_countof(argv), &argc); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_wargs(argc, &argv[0], &lens[0]);
	return 0;
}


#else


mk_lang_extern_c mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_iip_args(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t lens[3];

	mk_lang_cpuid_init();
	err = mk_lang_stdout_init(); mk_lang_check_rereturn(err);
	if(argc == 1)
	{
		lens[0] = mk_lang_str_len_n(argv[0]);
		err = mk_clib_app_iip_usage(argc, argv, &lens[0]); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_lang_check_return(argc == 3);
		lens[0] = mk_lang_str_len_t(argv[0]);
		lens[1] = mk_lang_str_len_t(argv[1]);
		lens[2] = mk_lang_str_len_t(argv[2]);
		err = mk_clib_app_iip_work(argc, argv, &lens[0]); mk_lang_check_rereturn(err);
	}
	return 0;
}


#endif


#endif
