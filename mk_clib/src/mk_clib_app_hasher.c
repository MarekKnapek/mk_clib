#ifndef mk_include_guard_mk_clib_app_hasher_c
#define mk_include_guard_mk_clib_app_hasher_c
#include "mk_clib_app_hasher.h"

#include "mk_lang_alignas.h"
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
#include "mk_lang_roundup.h"
#include "mk_lang_stdout.h"
#include "mk_lang_str_len.h"
#include "mk_lang_str_match.h"
#include "mk_lang_tchar.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_any1.h"
#include "mk_lib_crypto_hash_stream_any2.h"
#include "mk_lib_fmt.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_io_reader_file.h"


#define mk_clib_app_hasher_buff_size 4 * 1024
#define mk_clib_app_hasher_buff_algn 4 * 1024
union mk_clib_app_hasher_buff_data_u
{
	mk_lang_types_uchar_t m_uchars[mk_lang_roundup_add(mk_clib_app_hasher_buff_size, mk_clib_app_hasher_buff_algn)];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_clib_app_hasher_buff_data_u mk_clib_app_hasher_buff_data_t;
struct mk_clib_app_hasher_buff_s
{
	mk_lang_alignas(mk_clib_app_hasher_buff_algn) mk_clib_app_hasher_buff_data_t m_data;
};
typedef struct mk_clib_app_hasher_buff_s mk_clib_app_hasher_buff_t;
mk_lang_typedef(mk_clib_app_hasher_buff);


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hasher_print_digest(mk_lib_crypto_hash_stream_any1_id_t const id, mk_sl_cui_uint8_pct const digest) mk_lang_noexcept
{
	mk_lang_types_sint_t count;
	mk_lang_types_sint_t len;
	mk_lang_tchar_t str[((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_any1_digest_max_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))];
	mk_lang_types_sint_t err;

	mk_lang_assert(id >= 0 && id < mk_lib_crypto_hash_stream_any1_id_e_dummy_end);
	mk_lang_assert(digest);

	count = mk_lib_crypto_hash_stream_any1_get_digest_len(id); mk_lang_assert(count * mk_sl_cui_uint8_strlen_hex_v <= mk_lang_countof(str));
	len = mk_lang_tchar_dispatch(mk_sl_cui_uint8_to_str_hexf_many_)(&digest[0], count, &str[0], mk_lang_countof(str)); mk_lang_assert(len == count * mk_sl_cui_uint8_strlen_hex_v);
	err = mk_lang_stdout_println_t(&str[0], count * mk_sl_cui_uint8_strlen_hex_v); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lib_crypto_hash_stream_any1_id_t mk_clib_app_hasher_find_hash(mk_lang_tchar_pct const hash_buf, mk_lang_types_sint_t const hash_len) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_crypto_hash_stream_any1_id_t id;
	mk_lang_types_pchar_pct str;
	mk_lang_types_sint_t len;

	mk_lang_assert(hash_buf || hash_len == 0);
	mk_lang_assert(hash_len >= 0);
	mk_lang_assert(hash_len == 0 || hash_buf[0] != mk_lang_tchar_c('\0'));

	n = mk_lib_crypto_hash_stream_any1_id_e_dummy_end;
	for(i = 0; i != n; ++i)
	{
		id = ((mk_lib_crypto_hash_stream_any1_id_t)(i));
		str = mk_lib_crypto_hash_stream_any1_get_str_buf(id); mk_lang_assert(str); mk_lang_assert(str[0] != '\0');
		len = mk_lib_crypto_hash_stream_any1_get_str_len(id); mk_lang_assert(len >= 1); mk_lang_assert(len <= 0xff);
		if(mk_lang_str_match_t(hash_buf, hash_len, str, len))
		{
			break;
		}
	}
	id = ((mk_lib_crypto_hash_stream_any1_id_t)(i));
	return id;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hasher_work(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_tchar_pct arg_hash_buf;
	mk_lang_tchar_pct arg_file_buf;
	mk_lang_types_sint_t arg_hash_len;
	mk_lang_types_sint_t arg_file_len;
	mk_lib_crypto_hash_stream_any1_id_t id;
	mk_lib_crypto_hash_stream_any2_t hasher;
	mk_sl_cui_uint8_pt ptr;
	mk_clib_app_hasher_buff_t buff;
	mk_lang_types_sint_t err;
	mk_sl_io_reader_file_t input_file;
	mk_lang_types_sint_t read;
	mk_sl_cui_uint8_t digest[mk_lib_crypto_hash_stream_any1_digest_max_len_v];

	mk_lang_assert(argc == 3);
	mk_lang_assert(argv);
	mk_lang_assert(lens);

	n = argc;
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(argv[i]);
		mk_lang_assert(argv[i][0] != mk_lang_tchar_c('\0'));
		mk_lang_assert(lens[i] >= 0);
	}
	arg_hash_buf = argv[1];
	arg_file_buf = argv[2];
	arg_hash_len = lens[1];
	arg_file_len = lens[2]; ((mk_lang_types_void_t)(arg_file_len)); /* todo file reader not zero terminated */
	id = mk_clib_app_hasher_find_hash(arg_hash_buf, arg_hash_len);
	mk_lang_check_return(id != mk_lib_crypto_hash_stream_any1_id_e_dummy_end);
	mk_lib_crypto_hash_stream_any2_init(&hasher, id);
	ptr = ((mk_sl_cui_uint8_pt)(mk_lang_roundup_align(&buff.m_data.m_uchars[0], mk_clib_app_hasher_buff_algn)));
	err = mk_sl_io_reader_file_open_t(&input_file, arg_file_buf); mk_lang_check_rereturn(err);
	for(;;)
	{
		err = mk_sl_io_reader_file_read(&input_file, ptr, mk_clib_app_hasher_buff_size, &read); mk_lang_check_rereturn(err);
		if(read == 0)
		{
			break;
		}
		mk_lib_crypto_hash_stream_any2_append_u8s(&hasher, ptr, ((mk_lang_types_usize_t)(read)));
	}
	err = mk_sl_io_reader_file_close(&input_file); mk_lang_check_rereturn(err);
	mk_lib_crypto_hash_stream_any2_finish(&hasher, &digest[0]);
	err = mk_clib_app_hasher_print_digest(id, &digest[0]); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hasher_print_algs(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_crypto_hash_stream_any1_id_t id;
	mk_lang_types_pchar_pct str;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t slen;
	mk_lang_tchar_t buf[0xff];
	mk_lang_types_sint_t err;

	n = mk_lib_crypto_hash_stream_any1_id_e_dummy_end;
	for(i = 0; i != n; ++i)
	{
		id = ((mk_lib_crypto_hash_stream_any1_id_t)(i));
		str = mk_lib_crypto_hash_stream_any1_get_str_buf(id); mk_lang_assert(str); mk_lang_assert(str[0] != '\0');
		len = mk_lib_crypto_hash_stream_any1_get_str_len(id); mk_lang_assert(len >= 1); mk_lang_assert(len <= 0xff);
		slen = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c(" %n")), str, len); mk_lang_check_return(slen >= 1);
		err = mk_lang_stdout_print_t(&buf[0], slen); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hasher_usage(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
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
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("%t SHA-1 message.txt")), exe_name, exe_len); mk_lang_check_return(len >= 1); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("%t SHA3-512 video.avi")), exe_name, exe_len); mk_lang_check_return(len >= 1); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_t(mk_lang_tchar_c("Available algorithms:")); mk_lang_check_rereturn(err);
	err = mk_clib_app_hasher_print_algs(); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("")); mk_lang_check_rereturn(err);
	return 0;
}


#if mk_lang_entry_point_have


#include "mk_win_dll_kernel_process.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_hasher_wargs(mk_lang_types_sint_t const argc, mk_lang_types_wchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	if(argc == 1)
	{
		err = mk_clib_app_hasher_usage(argc, argv, lens); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_lang_check_return(argc == 3);
		err = mk_clib_app_hasher_work(argc, argv, lens); mk_lang_check_rereturn(err);
	}
	return 0;
}


mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t mk_clib_app_hasher_peb(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_wchar_pct argv[16];
	mk_lang_types_sint_t lens[mk_lang_countof(argv)];
	mk_lang_types_sint_t argc;

	mk_lang_assert(peb);

	mk_lang_cpuid_init();
	err = mk_lang_stdout_init(); mk_lang_check_rereturn(err);
	err = mk_lang_command_line_parse_win(mk_win_dll_kernel_process_get_command_line(), &argv[0], &lens[0], mk_lang_countof(argv), &argc); mk_lang_check_rereturn(err);
	err = mk_clib_app_hasher_wargs(argc, &argv[0], &lens[0]);
	return 0;
}


#else


mk_lang_extern_c mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_hasher_args(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t lens[3];

	mk_lang_cpuid_init();
	err = mk_lang_stdout_init(); mk_lang_check_rereturn(err);
	if(argc == 1)
	{
		lens[0] = mk_lang_str_len_n(argv[0]);
		err = mk_clib_app_hasher_usage(argc, argv, &lens[0]); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_lang_check_return(argc == 3);
		lens[0] = mk_lang_str_len_t(argv[0]);
		lens[1] = mk_lang_str_len_t(argv[1]);
		lens[2] = mk_lang_str_len_t(argv[2]);
		err = mk_clib_app_hasher_work(argc, argv, &lens[0]); mk_lang_check_rereturn(err);
	}
	return 0;
}


#endif


#endif
