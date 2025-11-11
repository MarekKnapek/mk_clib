#ifndef mk_include_guard_mk_clib_app_forwarder_c
#define mk_include_guard_mk_clib_app_forwarder_c
#include "mk_clib_app_forwarder.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
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
#include "mk_lang_runtime_bool.h"
#include "mk_lang_stdout.h"
#include "mk_lang_str_lit.h"
#include "mk_lang_tchar.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_app_cryptor.h"
#include "mk_lib_app_cryptor_alg_names.h"
#include "mk_lib_app_cryptor_mode_names.h"
#include "mk_lib_crypto_hash_names.h"
#include "mk_lib_crypto_padding_names.h"
#include "mk_lib_fmt.h"
#include "mk_lib_net.h"
#include "mk_lib_net_buffers.h"
#include "mk_lib_net_forwarder.h"
#include "mk_lib_net_iocp.h"
#include "mk_lib_net_listener.h"
#include "mk_lib_net_redirector.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_io_reader_file.h"
#include "mk_sl_io_writer_file.h"
#include "mk_sl_mallocator.h"
#include "mk_sl_random.h"
#include "mk_sl_speedometer.h"
#include "mk_sl_stopwatch.h"
#include "mk_win_dll_kernel_console.h"


#define mk_clib_app_forwarder_k_src_ip_address "0.0.0.0"
#define mk_clib_app_forwarder_k_src_tcp_port 9009
#define mk_clib_app_forwarder_k_dst_ip_address "127.0.0.1"
#define mk_clib_app_forwarder_k_dst_tcp_port 7654


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_clib_app_forwarder_s
{
	//mk_lib_net_forwarder_t m_forwarder;
	mk_lib_net_redirector_t m_forwarder;
};
typedef struct mk_clib_app_forwarder_s mk_clib_app_forwarder_t;
mk_lang_typedef(mk_clib_app_forwarder);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_forwarder_pr_on_ctrlc_callback(mk_clib_app_forwarder_pt const forwarder, mk_win_base_dword_t const type, mk_lang_types_bool_pt const handled) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(forwarder);
	mk_lang_assert(type >= 0);
	mk_lang_assert(type < mk_win_dll_kernel_console_ctrl_event_id_e_dummy_end);
	mk_lang_assert(handled);
	#include "mk_lang_warning_msvc_pop.h"

	if(type == mk_win_dll_kernel_console_ctrl_event_id_e_c)
	{
		err = mk_lang_stdout_no_redirect_println_color_n(mk_lang_stdout_color_text_e_light_red, mk_lang_str_lit("CTRL+C detected")); mk_lang_check_rereturn(err);
		err = mk_lib_net_redirector_rw_request_stop(&forwarder->m_forwarder); mk_lang_check_rereturn(err);
		*handled = mk_lang_true;
	}
	else if(type == mk_win_dll_kernel_console_ctrl_event_id_e_break)
	{
		err = mk_lang_stdout_no_redirect_println_color_n(mk_lang_stdout_color_text_e_light_red, mk_lang_str_lit("CTRL+Break detected")); mk_lang_check_rereturn(err);
		err = mk_lib_net_redirector_rw_request_stop(&forwarder->m_forwarder); mk_lang_check_rereturn(err);
		*handled = mk_lang_true;
	}
	else
	{
		*handled = mk_lang_false;
	}
	return 0;
}

static mk_clib_app_forwarder_pt mk_clib_app_forwarder_g_ctrlc_state;

mk_win_base_bool_t mk_win_base_far mk_win_base_stdcall mk_clib_app_forwarder_pr_ctrlc_callback(mk_win_base_dword_t const type) mk_lang_noexcept
{
	mk_clib_app_forwarder_pt forwarder;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t handled;

	mk_lang_assert(mk_clib_app_forwarder_g_ctrlc_state);

	forwarder = mk_clib_app_forwarder_g_ctrlc_state;
	err = mk_clib_app_forwarder_pr_on_ctrlc_callback(forwarder, type, &handled); mk_lang_check_recrash(err);
	return handled ? mk_win_base_true : mk_win_base_false;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_forwarder_pr_register_ctrlc_callback(mk_clib_app_forwarder_pt const forwarder) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(forwarder);
	mk_lang_assert(!mk_clib_app_forwarder_g_ctrlc_state);

	mk_clib_app_forwarder_g_ctrlc_state = forwarder;
	b = mk_win_dll_kernel_console_set_ctrl_handler(&mk_clib_app_forwarder_pr_ctrlc_callback, mk_win_base_true); mk_lang_check_return(b != mk_win_base_false);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_forwarder_pr_unregister_ctrlc_callback(mk_clib_app_forwarder_pt const forwarder) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(forwarder);
	mk_lang_assert(mk_clib_app_forwarder_g_ctrlc_state == forwarder);

	b = mk_win_dll_kernel_console_set_ctrl_handler(&mk_clib_app_forwarder_pr_ctrlc_callback, mk_win_base_false); mk_lang_check_return(b != mk_win_base_false);
	mk_clib_app_forwarder_g_ctrlc_state = mk_lang_null;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_forwarder_pr_loop(mk_clib_app_forwarder_pt const forwarder) mk_lang_noexcept
{
	//mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);

	/*err = mk_clib_app_forwarder_pr_register_ctrlc_callback(forwarder); mk_lang_check_rereturn(err);
	err = mk_lib_net_forwarder_rw_run(&forwarder->m_forwarder); mk_lang_check_rereturn(err);
	err = mk_clib_app_forwarder_pr_unregister_ctrlc_callback(forwarder); mk_lang_check_rereturn(err);*/
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_forwarder_pr_add_listener(mk_clib_app_forwarder_pt const forwarder) mk_lang_noexcept
{
	/*mk_lang_types_sint_t err;
	mk_lib_net_destination_t src;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t consumed;

	mk_lang_assert(forwarder);

	err = mk_lib_net_ipv4_address_parse_pc(&src.m_ipv4_address, mk_lang_str_lit(mk_clib_app_forwarder_k_src_ip_address), &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_assert(gud); mk_lang_assert(consumed == mk_lang_countstr(mk_clib_app_forwarder_k_src_ip_address)); src.m_tcp_port.m_elements[0].m_elements[0] = mk_clib_app_forwarder_k_src_tcp_port;
	err = mk_lib_net_forwarder_rw_add_listener(&forwarder->m_forwarder, &src); mk_lang_check_rereturn(err);
	return 0;*/


	mk_lang_types_sint_t err;
	mk_lib_net_destination_t src;
	mk_lib_net_destination_t dst;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t consumed;

	mk_lang_assert(forwarder);

	err = mk_lib_net_ipv4_address_parse_pc(&src.m_ipv4_address, mk_lang_str_lit(mk_clib_app_forwarder_k_src_ip_address), &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_assert(gud); mk_lang_assert(consumed == mk_lang_countstr(mk_clib_app_forwarder_k_src_ip_address)); src.m_tcp_port.m_elements[0].m_elements[0] = mk_clib_app_forwarder_k_src_tcp_port;
	err = mk_lib_net_ipv4_address_parse_pc(&dst.m_ipv4_address, mk_lang_str_lit(mk_clib_app_forwarder_k_dst_ip_address), &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_assert(gud); mk_lang_assert(consumed == mk_lang_countstr(mk_clib_app_forwarder_k_dst_ip_address)); dst.m_tcp_port.m_elements[0].m_elements[0] = mk_clib_app_forwarder_k_dst_tcp_port;
	err = mk_lib_net_redirector_rw_add_redirect(&forwarder->m_forwarder, &src, &dst); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_forwarder_pr_work(mk_clib_app_forwarder_pt const forwarder, mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	/*mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);
	mk_lang_assert(argc >= 2);
	mk_lang_assert(argv);
	mk_lang_assert(lens);

	err = mk_lib_net_forwarder_rw_construct(&forwarder->m_forwarder); mk_lang_check_rereturn(err);
	err = mk_clib_app_forwarder_pr_add_listener(forwarder); mk_lang_check_rereturn(err);
	err = mk_clib_app_forwarder_pr_loop(forwarder); mk_lang_check_rereturn(err);
	err = mk_lib_net_forwarder_rw_destroy(&forwarder->m_forwarder); mk_lang_check_rereturn(err);*/

	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);
	mk_lang_assert(argc >= 2);
	mk_lang_assert(argv);
	mk_lang_assert(lens);

	err = mk_lib_net_redirector_rw_construct(&forwarder->m_forwarder); mk_lang_check_rereturn(err);
	err = mk_clib_app_forwarder_pr_add_listener(forwarder); mk_lang_check_rereturn(err);
	err = mk_clib_app_forwarder_pr_register_ctrlc_callback(forwarder); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_rw_run(&forwarder->m_forwarder); mk_lang_check_rereturn(err);
	err = mk_clib_app_forwarder_pr_unregister_ctrlc_callback(forwarder); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_rw_destroy(&forwarder->m_forwarder); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_forwarder_print_directions(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t slen;
	mk_lang_tchar_t buf[0xff];
	mk_lang_types_sint_t err;

	slen = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c(" %n")), mk_lang_str_lit("encrypt")); mk_lang_check_return(slen >= 1); err = mk_lang_stdout_print_t(&buf[0], slen); mk_lang_check_rereturn(err);
	slen = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c(" %n")), mk_lang_str_lit("decrypt")); mk_lang_check_return(slen >= 1); err = mk_lang_stdout_print_t(&buf[0], slen); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_forwarder_print_modes(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_app_cryptor_mode_names_id_t id;
	mk_lang_types_pchar_pct str;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t slen;
	mk_lang_tchar_t buf[0xff];
	mk_lang_types_sint_t err;

	n = mk_lib_app_cryptor_mode_names_id_e_dummy_end;
	for(i = 0; i != n; ++i)
	{
		id = ((mk_lib_app_cryptor_mode_names_id_t)(i));
		str = mk_lib_app_cryptor_mode_names_get_str_buf(id); mk_lang_assert(str); mk_lang_assert(str[0] != '\0');
		len = mk_lib_app_cryptor_mode_names_get_str_len(id); mk_lang_assert(len >= 1); mk_lang_assert(len <= 0xff);
		slen = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c(" %n")), str, len); mk_lang_check_return(slen >= 1);
		err = mk_lang_stdout_print_t(&buf[0], slen); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_forwarder_print_algs(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_app_cryptor_alg_names_id_t id;
	mk_lang_types_pchar_pct str;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t slen;
	mk_lang_tchar_t buf[0xff];
	mk_lang_types_sint_t err;

	n = mk_lib_app_cryptor_alg_names_id_e_dummy_end;
	for(i = 0; i != n; ++i)
	{
		id = ((mk_lib_app_cryptor_alg_names_id_t)(i));
		str = mk_lib_app_cryptor_alg_names_get_str_buf(id); mk_lang_assert(str); mk_lang_assert(str[0] != '\0');
		len = mk_lib_app_cryptor_alg_names_get_str_len(id); mk_lang_assert(len >= 1); mk_lang_assert(len <= 0xff);
		slen = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c(" %n")), str, len); mk_lang_check_return(slen >= 1);
		err = mk_lang_stdout_print_t(&buf[0], slen); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_forwarder_print_paddings(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_crypto_padding_names_id_t id;
	mk_lang_types_pchar_pct str;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t slen;
	mk_lang_tchar_t buf[0xff];
	mk_lang_types_sint_t err;

	n = mk_lib_crypto_padding_names_id_e_dummy_end;
	for(i = 0; i != n; ++i)
	{
		id = ((mk_lib_crypto_padding_names_id_t)(i));
		str = mk_lib_crypto_padding_names_get_str_buf(id); mk_lang_assert(str); mk_lang_assert(str[0] != '\0');
		len = mk_lib_crypto_padding_names_get_str_len(id); mk_lang_assert(len >= 1); mk_lang_assert(len <= 0xff);
		slen = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c(" %n")), str, len); mk_lang_check_return(slen >= 1);
		err = mk_lang_stdout_print_t(&buf[0], slen); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_forwarder_print_kdfs(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t slen;
	mk_lang_tchar_t buf[0xff];
	mk_lang_types_sint_t err;

	slen = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c(" %n")), mk_lang_str_lit("PBKDF2")); mk_lang_check_return(slen >= 1); err = mk_lang_stdout_print_t(&buf[0], slen); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_forwarder_print_hashes(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_crypto_hash_names_id_t id;
	mk_lang_types_pchar_pct str;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t slen;
	mk_lang_tchar_t buf[0xff];
	mk_lang_types_sint_t err;

	n = mk_lib_crypto_hash_names_id_e_dummy_end;
	for(i = 0; i != n; ++i)
	{
		id = ((mk_lib_crypto_hash_names_id_t)(i));
		str = mk_lib_crypto_hash_names_get_str_buf(id); mk_lang_assert(str); mk_lang_assert(str[0] != '\0');
		len = mk_lib_crypto_hash_names_get_str_len(id); mk_lang_assert(len >= 1); mk_lang_assert(len <= 0xff);
		slen = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c(" %n")), str, len); mk_lang_check_return(slen >= 1);
		err = mk_lang_stdout_print_t(&buf[0], slen); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_forwarder_pr_usage(mk_clib_app_forwarder_pt const forwarder, mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_tchar_pct exe_name;
	mk_lang_types_sint_t exe_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;
	mk_lang_tchar_t buf[512];

	mk_lang_assert(forwarder);
	mk_lang_assert(argc == 1);
	mk_lang_assert(argv);
	mk_lang_assert(lens);
	mk_lang_assert(argv[0]);
	mk_lang_assert(argv[0][0] != mk_lang_tchar_c('\0'));
	mk_lang_assert(lens[0] >= 1);

	((mk_lang_types_void_t)(forwarder));
	exe_name = mk_lang_exe_name_get_t(argv[0]); mk_lang_check_return(exe_name); mk_lang_check_return(exe_name[0] != mk_lang_tchar_c('\0'));
	exe_len = lens[0] - ((mk_lang_types_sint_t)(exe_name - argv[0])); mk_lang_check_return(exe_len >= 1);
	err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("\tExample usage:")); mk_lang_check_rereturn(err);
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("\t%t /direction encrypt /mode CTR /alg AES-256 /padding PKCS#7 /kdf PBKDF2 /hash SHA-512 /cost 1000 /password Hunter2 /salt cryptor /input message.txt /output message.dat")), exe_name, exe_len); mk_lang_check_return(len >= 1); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("\t%t /direction decrypt /mode CBC /alg Serpent /padding ISO-9797pm2 /kdf PBKDF2 /hash SHA3-256 /cost 1000 /password Hunter2 /salt cryptor /input message.dat /output message.txt")), exe_name, exe_len); mk_lang_check_return(len >= 1); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_t(mk_lang_tchar_c("\tDirections:")); mk_lang_check_rereturn(err); err = mk_clib_app_forwarder_print_directions(); mk_lang_check_rereturn(err); err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("")); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_t(mk_lang_tchar_c("\tModes:")); mk_lang_check_rereturn(err); err = mk_clib_app_forwarder_print_modes(); mk_lang_check_rereturn(err); err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("")); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_t(mk_lang_tchar_c("\tAlgs:")); mk_lang_check_rereturn(err); err = mk_clib_app_forwarder_print_algs(); mk_lang_check_rereturn(err); err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("")); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_t(mk_lang_tchar_c("\tPaddings:")); mk_lang_check_rereturn(err); err = mk_clib_app_forwarder_print_paddings(); mk_lang_check_rereturn(err); err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("")); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_t(mk_lang_tchar_c("\tKDFs:")); mk_lang_check_rereturn(err); err = mk_clib_app_forwarder_print_kdfs(); mk_lang_check_rereturn(err); err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("")); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_t(mk_lang_tchar_c("\tHashes:")); mk_lang_check_rereturn(err); err = mk_clib_app_forwarder_print_hashes(); mk_lang_check_rereturn(err); err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("")); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_forwarder_pr_run(mk_clib_app_forwarder_pt const forwarder, mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);

	if(argc == 1){ err = mk_clib_app_forwarder_pr_usage(forwarder, argc, argv, lens); mk_lang_check_rereturn(err); }
	else         { err = mk_clib_app_forwarder_pr_work (forwarder, argc, argv, lens); mk_lang_check_rereturn(err); }
	return 0;
}

static mk_clib_app_forwarder_t mk_clib_app_forwarder_g;

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_forwarder_main(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(argc >= 1);
	mk_lang_assert(argv);
	mk_lang_assert(lens);

	err = mk_clib_app_forwarder_pr_run(&mk_clib_app_forwarder_g, argc, argv, lens); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_forwarder_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_cpuid_init();
	err = mk_lang_stdout_init(); mk_lang_check_rereturn(err);
	err = mk_sl_stopwatch_init(); mk_lang_check_rereturn(err);
	err = mk_sl_random_init(); mk_lang_check_rereturn(err);
	err = mk_sl_mallocator_init(); mk_lang_check_rereturn(err);
	err = mk_lib_net_buffers_rw_init(); mk_lang_check_rereturn(err);
	err = mk_lib_net_init(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_forwarder_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_lib_net_deinit(); mk_lang_check_rereturn(err);
	err = mk_lib_net_buffers_rw_deinit(); mk_lang_check_rereturn(err);
	err = mk_sl_mallocator_deinit(); mk_lang_check_rereturn(err);
	err = mk_sl_random_deinit(); mk_lang_check_rereturn(err);
	err = mk_sl_stopwatch_deinit(); mk_lang_check_rereturn(err);
	return 0;
}


#if mk_lang_entry_point_have


#include "mk_win_dll_kernel_process.h"


mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t mk_clib_app_forwarder_peb(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_wchar_pct args[32];
	mk_lang_types_sint_t lens[mk_lang_countof(args)];
	mk_lang_types_sint_t count;

	mk_lang_check_return(peb);
	err = mk_clib_app_forwarder_init(); mk_lang_check_rereturn(err);
	err = mk_lang_command_line_parse_win(mk_win_dll_kernel_process_get_command_line(), &args[0], &lens[0], mk_lang_countof(args), &count); mk_lang_check_rereturn(err); mk_lang_check_return(count >= 1);
	err = mk_clib_app_forwarder_main(count, &args[0], &lens[0]); mk_lang_check_rereturn(err);
	err = mk_clib_app_forwarder_deinit(); mk_lang_check_rereturn(err);
	return 0;
}


#else


mk_lang_extern_c mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_forwarder_args(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct args[32];
	mk_lang_types_sint_t lens[mk_lang_countof(args)];
	mk_lang_types_sint_t count;

	mk_lang_check_return(argc >= 1);
	mk_lang_check_return(argc <= mk_lang_countof(lens));
	mk_lang_check_return(argv);
	err = mk_clib_app_forwarder_init(); mk_lang_check_rereturn(err);
	err = mk_lang_command_line_parse_std(argc, argv, &args[0], &lens[0], mk_lang_countof(args), &count); mk_lang_check_rereturn(err);
	err = mk_clib_app_forwarder_main(count, &args[0], &lens[0]); mk_lang_check_rereturn(err);
	err = mk_clib_app_forwarder_deinit(); mk_lang_check_rereturn(err);
	return 0;
}


#endif


#endif
