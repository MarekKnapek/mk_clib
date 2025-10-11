#ifndef mk_include_guard_mk_clib_app_cryptor_c
#define mk_include_guard_mk_clib_app_cryptor_c
#include "mk_clib_app_cryptor.h"

#include "mk_lang_static_assert.h"
#include "mk_lib_crypto_alg_stream_names.h"
#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_bitness.h"
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
#include "mk_lang_roundup.h"
#include "mk_lang_stdout.h"
#include "mk_lang_str_len.h"
#include "mk_lang_str_match.h"
#include "mk_lang_tchar.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_stream.h"
#include "mk_lib_crypto_hash_stream_any1.h"
#include "mk_lib_crypto_hash_stream_any2.h"
#include "mk_lib_crypto_alg_stream_any1.h"
#include "mk_lib_crypto_alg_stream_any2.h"
#include "mk_lib_fmt.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_io_reader_file.h"
#include "mk_sl_io_writer_file.h"
#include "mk_sl_speedometer.h"
#include "mk_sl_stopwatch.h"


#if mk_lang_bitness_is_16
#define mk_clib_app_cryptor_buff_size 4 * 1024
#define mk_clib_app_cryptor_buff_algn 4 * 1024
#elif mk_lang_bitness_is_32
#define mk_clib_app_cryptor_buff_size 64 * 1024
#define mk_clib_app_cryptor_buff_algn 64 * 1024
#elif mk_lang_bitness_is_64
#define mk_clib_app_cryptor_buff_size 256 * 1024
#define mk_clib_app_cryptor_buff_algn 256 * 1024
#endif
union mk_clib_app_cryptor_buff_data_u
{
	mk_lang_types_uchar_t m_uchars[mk_lang_roundup_add(mk_clib_app_cryptor_buff_size + mk_lib_crypto_alg_stream_any2_msg_len_v, mk_clib_app_cryptor_buff_algn)];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_clib_app_cryptor_buff_data_u mk_clib_app_cryptor_buff_data_t;
struct mk_clib_app_cryptor_buff_s
{
	mk_clib_app_cryptor_buff_data_t m_data;
};
typedef struct mk_clib_app_cryptor_buff_s mk_clib_app_cryptor_buff_t;
mk_lang_typedef(mk_clib_app_cryptor_buff);


mk_lang_nodiscard static mk_lang_inline mk_lib_crypto_alg_stream_any1_id_t mk_clib_app_cryptor_find_alg(mk_lang_tchar_pct const alg_buf, mk_lang_types_sint_t const alg_len) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_crypto_alg_stream_names_id_t name_id;
	mk_lang_types_pchar_pct str;
	mk_lang_types_sint_t len;
	mk_lib_crypto_alg_stream_any1_id_t alg_id;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_alg_stream_any1_id_e_dummy_end)) == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_stream_names_id_e_dummy_end)));

	mk_lang_assert(alg_buf || alg_len == 0);
	mk_lang_assert(alg_len >= 0);
	mk_lang_assert(alg_len == 0 || alg_buf[0] != mk_lang_tchar_c('\0'));

	n = mk_lib_crypto_alg_stream_names_id_e_dummy_end;
	for(i = 0; i != n; ++i)
	{
		name_id = ((mk_lib_crypto_alg_stream_names_id_t)(i));
		str = mk_lib_crypto_alg_stream_names_get_str_buf(name_id); mk_lang_assert(str); mk_lang_assert(str[0] != '\0');
		len = mk_lib_crypto_alg_stream_names_get_str_len(name_id); mk_lang_assert(len >= 1); mk_lang_assert(len <= 0xff);
		if(mk_lang_str_match_t(alg_buf, alg_len, str, len))
		{
			break;
		}
	}
	alg_id = ((mk_lib_crypto_alg_stream_any1_id_t)(i));
	return alg_id;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_work(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t key_len;
	mk_lang_tchar_pct arg_alg_buf;
	mk_lang_tchar_pct arg_input_name_buf;
	mk_lang_tchar_pct arg_output_name_buf;
	mk_lang_types_sint_t arg_alg_len;
	mk_lang_types_sint_t arg_input_name_len;
	mk_lang_types_sint_t arg_output_name_len;
	mk_sl_speedometer_t speedometer;
	mk_lang_types_bool_t want;
	mk_lib_crypto_alg_stream_any1_id_t id;
	mk_sl_cui_uint8_pt ptr;
	mk_clib_app_cryptor_buff_t buff;
	mk_lang_types_sint_t err;
	mk_sl_io_reader_file_t input_file;
	mk_sl_io_writer_file_t output_file;
	mk_lang_types_sint_t read;
	mk_lang_types_sint_t written;
	mk_lang_types_usize_t encrypted;
	mk_lang_types_sint_t len;
	mk_lang_tchar_t progress_str_a[64]; /* todo max */
	mk_lang_tchar_t progress_str_b[2 * mk_lang_countof(progress_str_a)]; /* todo max */
	mk_sl_cui_uint8_t ff;
	mk_lib_crypto_alg_stream_any2_key_t key;
	mk_lib_crypto_alg_stream_any2_t stream;

	mk_lang_assert(argc == 4);
	mk_lang_assert(argv);
	mk_lang_assert(lens);

	n = argc;
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(argv[i]);
		mk_lang_assert(argv[i][0] != mk_lang_tchar_c('\0'));
		mk_lang_assert(lens[i] >= 0);
	}
	arg_alg_buf = argv[1];
	arg_input_name_buf = argv[2];
	arg_output_name_buf = argv[3];
	arg_alg_len = lens[1];
	arg_input_name_len = lens[2]; ((mk_lang_types_void_t)(arg_input_name_len)); /* todo file reader not zero terminated */
	arg_output_name_len = lens[3]; ((mk_lang_types_void_t)(arg_output_name_len)); /* todo file reader not zero terminated */
	err = mk_sl_speedometer_rw_construct(&speedometer); mk_lang_check_rereturn(err);
	id = mk_clib_app_cryptor_find_alg(arg_alg_buf, arg_alg_len);
	mk_lang_check_return(id != mk_lib_crypto_alg_stream_any1_id_e_dummy_end);
	mk_lib_crypto_alg_stream_any2_rw_construct(&stream, id);
	key_len = mk_lib_crypto_alg_stream_any2_ro_get_key_len(&stream); mk_lang_assert(key_len == 16 || key_len == 24 || key_len == 32);
	mk_sl_cui_uint8_set_max(&ff);
	mk_sl_cui_uint8_memset_fn(&key.m_data.m_uint8s[0], &ff, ((mk_lang_types_usize_t)(key_len)));
	mk_lib_crypto_alg_stream_any2_rw_construct_encrypt(&stream, &key);
	ptr = ((mk_sl_cui_uint8_pt)(mk_lang_roundup_align(&buff.m_data.m_uchars[0], mk_clib_app_cryptor_buff_algn)));
	err = mk_sl_io_reader_file_open_t(&input_file, arg_input_name_buf); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_open_t(&output_file, arg_output_name_buf); mk_lang_check_rereturn(err);
	for(;;)
	{
		err = mk_sl_io_reader_file_read(&input_file, ptr, mk_clib_app_cryptor_buff_size, &read); mk_lang_check_rereturn(err);
		if(read == 0)
		{
			break;
		}
		mk_lib_crypto_alg_stream_any2_rw_encrypt(&stream, ptr, ((mk_lang_types_usize_t)(read)), ptr, mk_clib_app_cryptor_buff_size + mk_lib_crypto_alg_stream_any2_msg_len_v, &encrypted);
		err = mk_sl_io_writer_file_write(&output_file, ptr, read, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written = read);
		err = mk_sl_speedometer_rw_append(&speedometer, read); mk_lang_check_rereturn(err);
		err = mk_sl_speedometer_rw_report(&speedometer, &progress_str_a[0], mk_lang_countof(progress_str_a), &want, &len); mk_lang_check_rereturn(err); mk_lang_assert(!want || len >= 1); mk_lang_assert(!want || len <= mk_lang_countof(progress_str_a));
		if(want)
		{
			len = mk_lib_fmt_t_snnprintf(&progress_str_b[0], mk_lang_countof(progress_str_b), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("\x0d                                                            \x0d%t ")), &progress_str_a[0], len); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(progress_str_b));
			err = mk_lang_stdout_no_redirect_print_t(&progress_str_b[0], len); mk_lang_check_rereturn(err);
		}
	}
	len = mk_lib_fmt_t_snnprintf(&progress_str_b[0], mk_lang_countof(progress_str_b), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("\x0d                                                            \x0d"))); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(progress_str_b));
	err = mk_lang_stdout_no_redirect_print_t(&progress_str_b[0], len); mk_lang_check_rereturn(err);
	err = mk_sl_io_writer_file_close(&output_file); mk_lang_check_rereturn(err);
	err = mk_sl_io_reader_file_close(&input_file); mk_lang_check_rereturn(err);
	err = mk_sl_speedometer_rw_destroy(&speedometer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_print_algs(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_crypto_alg_stream_names_id_t id;
	mk_lang_types_pchar_pct str;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t slen;
	mk_lang_tchar_t buf[0xff];
	mk_lang_types_sint_t err;

	n = mk_lib_crypto_alg_stream_any1_id_e_dummy_end;
	for(i = 0; i != n; ++i)
	{
		id = ((mk_lib_crypto_alg_stream_names_id_t)(i));
		str = mk_lib_crypto_alg_stream_names_get_str_buf(id); mk_lang_assert(str); mk_lang_assert(str[0] != '\0');
		len = mk_lib_crypto_alg_stream_names_get_str_len(id); mk_lang_assert(len >= 1); mk_lang_assert(len <= 0xff);
		slen = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c(" %n")), str, len); mk_lang_check_return(slen >= 1);
		err = mk_lang_stdout_print_t(&buf[0], slen); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_usage(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_tchar_pct exe_name;
	mk_lang_types_sint_t exe_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;
	mk_lang_tchar_t buf[512];

	mk_lang_assert(argc == 1);
	mk_lang_assert(argv);
	mk_lang_assert(lens);
	mk_lang_assert(argv[0]);
	mk_lang_assert(argv[0][0] != mk_lang_tchar_c('\0'));
	mk_lang_assert(lens[0] >= 1);

	exe_name = mk_lang_exe_name_get_t(argv[0]); mk_lang_check_return(exe_name); mk_lang_check_return(exe_name[0] != mk_lang_tchar_c('\0'));
	exe_len = lens[0] - ((mk_lang_types_sint_t)(exe_name - argv[0])); mk_lang_check_return(exe_len >= 1);
	err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("Example usage:")); mk_lang_check_rereturn(err);
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("%t AES-256 message.txt message.dat")), exe_name, exe_len); mk_lang_check_return(len >= 1); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("%t Serpent video.avi video.dat")), exe_name, exe_len); mk_lang_check_return(len >= 1); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_t(mk_lang_tchar_c("Available algorithms:")); mk_lang_check_rereturn(err);
	err = mk_clib_app_cryptor_print_algs(); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("")); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_cpuid_init();
	err = mk_sl_stopwatch_init(); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_init(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_sl_stopwatch_deinit(); mk_lang_check_rereturn(err);
	return 0;
}


#if mk_lang_entry_point_have


#include "mk_win_dll_kernel_process.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_cryptor_wargs(mk_lang_types_sint_t const argc, mk_lang_types_wchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	if(argc == 1)
	{
		err = mk_clib_app_cryptor_usage(argc, argv, lens); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_lang_check_return(argc == 4);
		err = mk_clib_app_cryptor_work(argc, argv, lens); mk_lang_check_rereturn(err);
	}
	return 0;
}


mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t mk_clib_app_cryptor_peb(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_wchar_pct argv[16];
	mk_lang_types_sint_t lens[mk_lang_countof(argv)];
	mk_lang_types_sint_t argc;

	mk_lang_assert(peb);

	err = mk_clib_app_cryptor_init(); mk_lang_check_rereturn(err);
	err = mk_lang_command_line_parse_win(mk_win_dll_kernel_process_get_command_line(), &argv[0], &lens[0], mk_lang_countof(argv), &argc); mk_lang_check_rereturn(err);
	err = mk_clib_app_cryptor_wargs(argc, &argv[0], &lens[0]);
	err = mk_clib_app_cryptor_deinit(); mk_lang_check_rereturn(err);
	return 0;
}


#else


mk_lang_extern_c mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_cryptor_args(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t lens[4];

	err = mk_clib_app_cryptor_init(); mk_lang_check_rereturn(err);
	if(argc == 1)
	{
		lens[0] = mk_lang_str_len_n(argv[0]);
		err = mk_clib_app_cryptor_usage(argc, argv, &lens[0]); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_lang_check_return(argc == 4);
		lens[0] = mk_lang_str_len_t(argv[0]);
		lens[1] = mk_lang_str_len_t(argv[1]);
		lens[2] = mk_lang_str_len_t(argv[2]);
		lens[3] = mk_lang_str_len_t(argv[3]);
		err = mk_clib_app_cryptor_work(argc, argv, &lens[0]); mk_lang_check_rereturn(err);
	}
	err = mk_clib_app_cryptor_deinit(); mk_lang_check_rereturn(err);
	return 0;
}


#endif


#endif
