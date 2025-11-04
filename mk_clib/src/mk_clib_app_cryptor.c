#ifndef mk_include_guard_mk_clib_app_cryptor_c
#define mk_include_guard_mk_clib_app_cryptor_c
#include "mk_clib_app_cryptor.h"

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
#include "mk_sl_cui_uint8.h"
#include "mk_sl_io_reader_file.h"
#include "mk_sl_io_writer_file.h"
#include "mk_sl_random.h"
#include "mk_sl_speedometer.h"
#include "mk_sl_stopwatch.h"


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_clib_app_cryptor_s
{
	mk_lib_app_cryptor_command_line_t m_command_line;
	mk_sl_io_reader_file_t m_input_file;
	mk_sl_io_writer_file_t m_output_file;
	mk_lib_app_cryptor_t m_lib_cryptor;
};
typedef struct mk_clib_app_cryptor_s mk_clib_app_cryptor_t;
mk_lang_typedef(mk_clib_app_cryptor);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_pr_error(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_tchar_t msg_buf[512];
	mk_lang_types_sint_t msg_len;
	mk_lang_types_sint_t err;

	mk_lang_assert(str_buf);
	mk_lang_assert(str_len >= 1);

	msg_len = mk_lib_fmt_t_snnprintf(&msg_buf[0], mk_lang_countof(msg_buf), mk_lang_str_lit(mk_lang_tchar_c("%n\n")), str_buf, str_len); mk_lang_assert(msg_len >= 1); mk_lang_assert(msg_len < mk_lang_countof(msg_buf));
	err = mk_lang_stdout_print_t(&msg_buf[0], msg_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_pr_arg_error(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_tchar_t msg_buf[512];
	mk_lang_types_sint_t msg_len;
	mk_lang_types_sint_t err;

	mk_lang_assert(str_buf);
	mk_lang_assert(str_len >= 1);

	msg_len = mk_lib_fmt_t_snnprintf(&msg_buf[0], mk_lang_countof(msg_buf), mk_lang_str_lit(mk_lang_tchar_c("Error proessing the %n argument.\n")), str_buf, str_len); mk_lang_assert(msg_len >= 1); mk_lang_assert(msg_len < mk_lang_countof(msg_buf));
	err = mk_lang_stdout_print_t(&msg_buf[0], msg_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_prrw_parse_cmdline_all(mk_clib_app_cryptor_pt const cryptor, mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_app_cryptor_param_id_t failed;

	mk_lang_assert(cryptor);
	mk_lang_assert(argc >= 1);
	mk_lang_assert(argv);
	mk_lang_assert(lens);

	err = mk_lib_app_cryptor_rw_construct_cmd_line(&cryptor->m_lib_cryptor, &cryptor->m_command_line, argc, argv, lens, &failed); mk_lang_check_rereturn(err);
	switch(failed)
	{
		case mk_lib_app_cryptor_param_id_e_direction: err = mk_clib_app_cryptor_pr_arg_error(mk_lang_str_lit("direction")); mk_lang_check_rereturn(err); mk_lang_check_return(mk_lang_runtime_bool_fn_false); break;
		case mk_lib_app_cryptor_param_id_e_mode     : err = mk_clib_app_cryptor_pr_arg_error(mk_lang_str_lit("mode"     )); mk_lang_check_rereturn(err); mk_lang_check_return(mk_lang_runtime_bool_fn_false); break;
		case mk_lib_app_cryptor_param_id_e_alg      : err = mk_clib_app_cryptor_pr_arg_error(mk_lang_str_lit("alg"      )); mk_lang_check_rereturn(err); mk_lang_check_return(mk_lang_runtime_bool_fn_false); break;
		case mk_lib_app_cryptor_param_id_e_padding  : err = mk_clib_app_cryptor_pr_arg_error(mk_lang_str_lit("padding"  )); mk_lang_check_rereturn(err); mk_lang_check_return(mk_lang_runtime_bool_fn_false); break;
		case mk_lib_app_cryptor_param_id_e_kdf      : err = mk_clib_app_cryptor_pr_arg_error(mk_lang_str_lit("kdf"      )); mk_lang_check_rereturn(err); mk_lang_check_return(mk_lang_runtime_bool_fn_false); break;
		case mk_lib_app_cryptor_param_id_e_hash     : err = mk_clib_app_cryptor_pr_arg_error(mk_lang_str_lit("hash"     )); mk_lang_check_rereturn(err); mk_lang_check_return(mk_lang_runtime_bool_fn_false); break;
		case mk_lib_app_cryptor_param_id_e_cost     : err = mk_clib_app_cryptor_pr_arg_error(mk_lang_str_lit("cost"     )); mk_lang_check_rereturn(err); mk_lang_check_return(mk_lang_runtime_bool_fn_false); break;
		case mk_lib_app_cryptor_param_id_e_password : err = mk_clib_app_cryptor_pr_arg_error(mk_lang_str_lit("password" )); mk_lang_check_rereturn(err); mk_lang_check_return(mk_lang_runtime_bool_fn_false); break;
		case mk_lib_app_cryptor_param_id_e_salt     : err = mk_clib_app_cryptor_pr_arg_error(mk_lang_str_lit("salt"     )); mk_lang_check_rereturn(err); mk_lang_check_return(mk_lang_runtime_bool_fn_false); break;
		case mk_lib_app_cryptor_param_id_e_input    : err = mk_clib_app_cryptor_pr_arg_error(mk_lang_str_lit("input"    )); mk_lang_check_rereturn(err); mk_lang_check_return(mk_lang_runtime_bool_fn_false); break;
		case mk_lib_app_cryptor_param_id_e_output   : err = mk_clib_app_cryptor_pr_arg_error(mk_lang_str_lit("output"   )); mk_lang_check_rereturn(err); mk_lang_check_return(mk_lang_runtime_bool_fn_false); break;
		case mk_lib_app_cryptor_param_id_e_dummy_end: break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_rw_construct_void(mk_clib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(cryptor);

	err = mk_sl_io_reader_file_rw_construct_void(&cryptor->m_input_file); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_rw_construct_void(&cryptor->m_output_file); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_rw_destroy(mk_clib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(cryptor);

	err = mk_sl_io_reader_file_close(&cryptor->m_input_file); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_close(&cryptor->m_output_file); mk_lang_check_rereturn(err);
	err = mk_lib_app_cryptor_rw_destroy(&cryptor->m_lib_cryptor); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_pr_construct_cmdline(mk_clib_app_cryptor_pt const cryptor, mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(cryptor);

	err = mk_clib_app_cryptor_rw_construct_void(cryptor); mk_lang_check_rereturn(err);
	err = mk_clib_app_cryptor_prrw_parse_cmdline_all(cryptor, argc, argv, lens); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_pr_report_speed(mk_clib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_tchar_t progress_str_a[64]; /* todo max */
	mk_lang_tchar_t progress_str_b[2 * mk_lang_countof(progress_str_a)]; /* todo max */
	mk_lang_types_bool_t want;
	mk_lang_types_sint_t len;

	mk_lang_assert(cryptor);

	err = mk_sl_speedometer_rw_report(&cryptor->m_lib_cryptor.m_speedometer, &progress_str_a[0], mk_lang_countof(progress_str_a), &want, &len); mk_lang_check_rereturn(err); mk_lang_assert(!want || len >= 1); mk_lang_assert(!want || len <= mk_lang_countof(progress_str_a));
	if(want)
	{
		len = mk_lib_fmt_t_snnprintf(&progress_str_b[0], mk_lang_countof(progress_str_b), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("\x0d                                                            \x0d%t ")), &progress_str_a[0], len); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(progress_str_b));
		err = mk_lang_stdout_no_redirect_print_t(&progress_str_b[0], len); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_pr_report_clear(mk_clib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	mk_lang_types_sint_t len;
	mk_lang_tchar_t progress_str_a[64]; /* todo max */
	mk_lang_types_sint_t err;

	mk_lang_assert(cryptor);

	((mk_lang_types_void_t)(cryptor));
	len = mk_lib_fmt_t_snnprintf(&progress_str_a[0], mk_lang_countof(progress_str_a), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("\x0d                                                            \x0d"))); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(progress_str_a));
	err = mk_lang_stdout_no_redirect_print_t(&progress_str_a[0], len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_pr_work(mk_clib_app_cryptor_pt const cryptor, mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pt ptr_a;
	mk_lang_types_sint_t len_a;
	mk_sl_cui_uint8_pt ptr_b;
	mk_lang_types_sint_t len_b;
	mk_lang_types_sint_t read;
	mk_lang_types_sint_t consumed_in;
	mk_lang_types_sint_t input_consumed;
	mk_lang_types_sint_t output_consumed;
	mk_lang_types_sint_t written;
	mk_lang_types_bool_t gud;

	mk_lang_assert(cryptor);
	mk_lang_assert(argc >= 2);
	mk_lang_assert(argv);
	mk_lang_assert(lens);

	err = mk_clib_app_cryptor_pr_construct_cmdline(cryptor, argc, argv, lens); mk_lang_check_rereturn(err);
	err = mk_lib_app_cryptor_rw_construct_config(&cryptor->m_lib_cryptor, &cryptor->m_command_line.m_config); mk_lang_check_rereturn(err);
	err = mk_lib_app_cryptor_rw_init_objects(&cryptor->m_lib_cryptor); mk_lang_check_rereturn(err);
	ptr_a = mk_lib_app_cryptor_rw_get_buffer_1_ptr(&cryptor->m_lib_cryptor); mk_lang_assert(ptr_a);
	len_a = mk_lib_app_cryptor_rw_get_buffer_1_len(&cryptor->m_lib_cryptor); mk_lang_assert(len_a >= 1024);
	ptr_b = mk_lib_app_cryptor_rw_get_buffer_2_ptr(&cryptor->m_lib_cryptor); mk_lang_assert(ptr_b);
	len_b = mk_lib_app_cryptor_rw_get_buffer_2_len(&cryptor->m_lib_cryptor); mk_lang_assert(len_b >= 2 * 1024); mk_lang_assert(len_b >= len_a + 1024);
	err = mk_sl_io_reader_file_open_t(&cryptor->m_input_file, cryptor->m_command_line.m_input_ptr); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_open_t(&cryptor->m_output_file, cryptor->m_command_line.m_output_ptr); mk_lang_check_rereturn(err);
	for(;;)
	{
		err = mk_sl_io_reader_file_read(&cryptor->m_input_file, ptr_a, len_a, &read); mk_lang_check_rereturn(err);
		if(read == 0)
		{
			break;
		}
		consumed_in = 0;
		do
		{
			err = mk_lib_app_cryptor_rw_append_chunk(&cryptor->m_lib_cryptor, ptr_a + consumed_in, read - consumed_in, ptr_b, len_b, &input_consumed, &output_consumed); mk_lang_check_rereturn(err);
			err = mk_sl_io_writer_file_write(&cryptor->m_output_file, ptr_b, output_consumed, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == ((mk_lang_types_sint_t)(output_consumed)));
			consumed_in += input_consumed;
		}while(consumed_in != read);
		err = mk_sl_speedometer_rw_append(&cryptor->m_lib_cryptor.m_speedometer, output_consumed); mk_lang_check_rereturn(err);
		err = mk_clib_app_cryptor_pr_report_speed(cryptor); mk_lang_check_rereturn(err);
	}
	err = mk_lib_app_cryptor_rw_finish(&cryptor->m_lib_cryptor, ptr_b, len_b, &output_consumed, &gud); mk_lang_check_rereturn(err);
	mk_lang_check_return(gud);
	err = mk_sl_io_writer_file_write(&cryptor->m_output_file, ptr_b, output_consumed, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == ((mk_lang_types_sint_t)(output_consumed)));
	err = mk_sl_speedometer_rw_append(&cryptor->m_lib_cryptor.m_speedometer, output_consumed); mk_lang_check_rereturn(err);
	err = mk_clib_app_cryptor_pr_report_speed(cryptor); mk_lang_check_rereturn(err);
	err = mk_clib_app_cryptor_rw_destroy(cryptor); mk_lang_check_rereturn(err);
	err = mk_clib_app_cryptor_pr_report_clear(cryptor); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_print_directions(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t slen;
	mk_lang_tchar_t buf[0xff];
	mk_lang_types_sint_t err;

	slen = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c(" %n")), mk_lang_str_lit("encrypt")); mk_lang_check_return(slen >= 1); err = mk_lang_stdout_print_t(&buf[0], slen); mk_lang_check_rereturn(err);
	slen = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c(" %n")), mk_lang_str_lit("decrypt")); mk_lang_check_return(slen >= 1); err = mk_lang_stdout_print_t(&buf[0], slen); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_print_modes(mk_lang_types_void_t) mk_lang_noexcept
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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_print_algs(mk_lang_types_void_t) mk_lang_noexcept
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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_print_paddings(mk_lang_types_void_t) mk_lang_noexcept
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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_print_kdfs(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t slen;
	mk_lang_tchar_t buf[0xff];
	mk_lang_types_sint_t err;

	slen = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c(" %n")), mk_lang_str_lit("PBKDF2")); mk_lang_check_return(slen >= 1); err = mk_lang_stdout_print_t(&buf[0], slen); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_print_hashes(mk_lang_types_void_t) mk_lang_noexcept
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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_pr_usage(mk_clib_app_cryptor_pt const cryptor, mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_tchar_pct exe_name;
	mk_lang_types_sint_t exe_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;
	mk_lang_tchar_t buf[512];

	mk_lang_assert(cryptor);
	mk_lang_assert(argc == 1);
	mk_lang_assert(argv);
	mk_lang_assert(lens);
	mk_lang_assert(argv[0]);
	mk_lang_assert(argv[0][0] != mk_lang_tchar_c('\0'));
	mk_lang_assert(lens[0] >= 1);

	((mk_lang_types_void_t)(cryptor));
	exe_name = mk_lang_exe_name_get_t(argv[0]); mk_lang_check_return(exe_name); mk_lang_check_return(exe_name[0] != mk_lang_tchar_c('\0'));
	exe_len = lens[0] - ((mk_lang_types_sint_t)(exe_name - argv[0])); mk_lang_check_return(exe_len >= 1);
	err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("\tExample usage:")); mk_lang_check_rereturn(err);
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("\t%t /direction encrypt /mode CTR /alg AES-256 /padding PKCS#7 /kdf PBKDF2 /hash SHA-512 /cost 1000 /password Hunter2 /salt cryptor /input message.txt /output message.dat")), exe_name, exe_len); mk_lang_check_return(len >= 1); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("\t%t /direction decrypt /mode CBC /alg Serpent /padding ISO-9797pm2 /kdf PBKDF2 /hash SHA3-256 /cost 1000 /password Hunter2 /salt cryptor /input message.dat /output message.txt")), exe_name, exe_len); mk_lang_check_return(len >= 1); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_t(mk_lang_tchar_c("\tDirections:")); mk_lang_check_rereturn(err); err = mk_clib_app_cryptor_print_directions(); mk_lang_check_rereturn(err); err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("")); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_t(mk_lang_tchar_c("\tModes:")); mk_lang_check_rereturn(err); err = mk_clib_app_cryptor_print_modes(); mk_lang_check_rereturn(err); err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("")); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_t(mk_lang_tchar_c("\tAlgs:")); mk_lang_check_rereturn(err); err = mk_clib_app_cryptor_print_algs(); mk_lang_check_rereturn(err); err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("")); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_t(mk_lang_tchar_c("\tPaddings:")); mk_lang_check_rereturn(err); err = mk_clib_app_cryptor_print_paddings(); mk_lang_check_rereturn(err); err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("")); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_t(mk_lang_tchar_c("\tKDFs:")); mk_lang_check_rereturn(err); err = mk_clib_app_cryptor_print_kdfs(); mk_lang_check_rereturn(err); err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("")); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_t(mk_lang_tchar_c("\tHashes:")); mk_lang_check_rereturn(err); err = mk_clib_app_cryptor_print_hashes(); mk_lang_check_rereturn(err); err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("")); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_pr_run(mk_clib_app_cryptor_pt const cryptor, mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(cryptor);

	if(argc == 1){ err = mk_clib_app_cryptor_pr_usage(cryptor, argc, argv, lens); mk_lang_check_rereturn(err); }
	else         { err = mk_clib_app_cryptor_pr_work (cryptor, argc, argv, lens); mk_lang_check_rereturn(err); }
	return 0;
}

static mk_clib_app_cryptor_t mk_clib_app_cryptor_g;

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_main(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(argc >= 1);
	mk_lang_assert(argv);
	mk_lang_assert(lens);

	err = mk_clib_app_cryptor_pr_run(&mk_clib_app_cryptor_g, argc, argv, lens); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_cpuid_init();
	err = mk_sl_stopwatch_init(); mk_lang_check_rereturn(err);
	err = mk_sl_random_init(); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_init(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_sl_stopwatch_deinit(); mk_lang_check_rereturn(err);
	err = mk_sl_random_deinit(); mk_lang_check_rereturn(err);
	return 0;
}


#if mk_lang_entry_point_have


#include "mk_win_dll_kernel_process.h"


mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t mk_clib_app_cryptor_peb(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_wchar_pct args[32];
	mk_lang_types_sint_t lens[mk_lang_countof(args)];
	mk_lang_types_sint_t count;

	mk_lang_check_return(peb);
	err = mk_clib_app_cryptor_init(); mk_lang_check_rereturn(err);
	err = mk_lang_command_line_parse_win(mk_win_dll_kernel_process_get_command_line(), &args[0], &lens[0], mk_lang_countof(args), &count); mk_lang_check_rereturn(err); mk_lang_check_return(count >= 1);
	err = mk_clib_app_cryptor_main(count, &args[0], &lens[0]); mk_lang_check_rereturn(err);
	err = mk_clib_app_cryptor_deinit(); mk_lang_check_rereturn(err);
	return 0;
}


#else


mk_lang_extern_c mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_cryptor_args(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct args[32];
	mk_lang_types_sint_t lens[mk_lang_countof(args)];
	mk_lang_types_sint_t count;

	mk_lang_check_return(argc >= 1);
	mk_lang_check_return(argc <= mk_lang_countof(lens));
	mk_lang_check_return(argv);
	err = mk_clib_app_cryptor_init(); mk_lang_check_rereturn(err);
	err = mk_lang_command_line_parse_std(argc, argv, &args[0], &lens[0], mk_lang_countof(args), &count); mk_lang_check_rereturn(err);
	err = mk_clib_app_cryptor_main(count, &args[0], &lens[0]); mk_lang_check_rereturn(err);
	err = mk_clib_app_cryptor_deinit(); mk_lang_check_rereturn(err);
	return 0;
}


#endif


#endif
