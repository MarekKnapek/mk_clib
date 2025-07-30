#ifndef mk_include_guard_mk_clib_app_iip_c
#define mk_include_guard_mk_clib_app_iip_c
#include "mk_clib_app_iip.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_command_line.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_entry_point.h"
#include "mk_lang_exe_name.h"
#include "mk_lang_extern.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_roundup.h"
#include "mk_lang_stdout.h"
#include "mk_lang_string.h"
#include "mk_lang_tchar.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_sha2_256.h"
#include "mk_lib_fmt.h"
#include "mk_lib_iip_base32_encoder.h"
#include "mk_lib_iip_base64_encoder.h"
#include "mk_lib_iip_buffer.h"
#include "mk_lib_iip_cp_client_types.h"
#include "mk_lib_iip_cp_client_wrapper.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_lib_iip_cp_types.h"
#include "mk_lib_iip_http.h"
#include "mk_lib_iip_key_enc_elgamal_pri.h"
#include "mk_lib_iip_key_enc_elgamal_pub.h"
#include "mk_lib_iip_key_sgn_dsa_sha1_pri.h"
#include "mk_lib_iip_key_sgn_dsa_sha1_pub.h"
#include "mk_lib_net.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_io_reader_file.h"
#include "mk_sl_io_writer_file.h"
#include "mk_sl_random.h"
#include "mk_sl_time.h"
#include "mk_sl_uint_convert.h"
#include "mk_sl_uint_more.h"
#include "mk_win_dll_kernel_console.h"
#include "mk_win_dll_kernel_handle.h"
#include "mk_win_dll_kernel_process.h"
#include "mk_win_dll_kernel_synchronization.h"
#include "mk_win_dll_ws2.h"


static mk_lib_iip_cp_client_wrapper_task_pt mk_clib_app_iip_g_wrp;
static mk_lang_types_bool_t mk_clib_app_iip_g_stop_requested;
static mk_win_base_handle_t mk_clib_app_iip_g_main_thread;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_destination_elgamal_dsa_sha1_generate_new_random(mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pt const destination) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(destination);

	err = mk_lib_iip_key_enc_elgamal_pri_generate_random(&destination->m_key_elgamal_pri); mk_lang_check_rereturn(err);
	err = mk_lib_iip_key_sgn_dsa_sha1_pri_generate_random(&destination->m_key_dsa_sha1_pri); mk_lang_check_rereturn(err);
	mk_lib_iip_key_enc_elgamal_pri_compute_public(&destination->m_key_elgamal_pri, &destination->m_key_elgamal_pub);
	mk_lib_iip_key_sgn_dsa_sha1_pri_compute_public(&destination->m_key_dsa_sha1_pri, &destination->m_key_dsa_sha1_pub);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_destination_elgamal_dsa_sha1_save_pri_only(mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pct const destination, mk_lang_types_pchar_pct const file_name) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_io_writer_file_t writer;
	mk_lang_types_sint_t str_len;
	mk_lang_types_pchar_t str_buf[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pri_integer_single_strlen_hex_v)), ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_strlen_hex_v)))];
	mk_sl_cui_uint8_t bin_buf[mk_lang_countof(str_buf)];
	mk_lang_types_sint_t written;

	mk_lang_assert(destination);
	mk_lang_assert(file_name);
	mk_lang_assert(file_name[0] != '\0');

	err = mk_sl_io_writer_file_open_n(&writer, file_name); mk_lang_check_rereturn(err);

	str_len = mk_lib_iip_key_enc_elgamal_pri_integer_single_to_str_hexf_n(&destination->m_key_elgamal_pri.m_data.m_integer, &str_buf[0], mk_lang_countof(str_buf)); mk_lang_assert(str_len == mk_lib_iip_key_enc_elgamal_pri_integer_single_strlen_hex_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_buf[0] = '\x0a'; str_len = 1;
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_len = mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_str_hexf_n(&destination->m_key_dsa_sha1_pri.m_data.m_integer, &str_buf[0], mk_lang_countof(str_buf)); mk_lang_assert(str_len == mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_strlen_hex_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	err = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_destination_elgamal_dsa_sha1_save_pri_pub(mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pct const destination, mk_lang_types_pchar_pct const file_name) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_io_writer_file_t writer;
	mk_lang_types_sint_t str_len;
	mk_lang_types_pchar_t str_buf[mk_lang_max(mk_lang_max(mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pri_integer_single_strlen_hex_v)), ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_strlen_hex_v))), ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pub_integer_single_strlen_hex_v))), ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_strlen_hex_v)))];
	mk_sl_cui_uint8_t bin_buf[mk_lang_countof(str_buf)];
	mk_lang_types_sint_t written;

	mk_lang_assert(destination);
	mk_lang_assert(file_name);
	mk_lang_assert(file_name[0] != '\0');

	err = mk_sl_io_writer_file_open_n(&writer, file_name); mk_lang_check_rereturn(err);

	str_len = mk_lib_iip_key_enc_elgamal_pri_integer_single_to_str_hexf_n(&destination->m_key_elgamal_pri.m_data.m_integer, &str_buf[0], mk_lang_countof(str_buf)); mk_lang_assert(str_len == mk_lib_iip_key_enc_elgamal_pri_integer_single_strlen_hex_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_buf[0] = '\x0a'; str_len = 1;
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_len = mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_str_hexf_n(&destination->m_key_dsa_sha1_pri.m_data.m_integer, &str_buf[0], mk_lang_countof(str_buf)); mk_lang_assert(str_len == mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_strlen_hex_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_buf[0] = '\x0a'; str_len = 1;
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_len = mk_lib_iip_key_enc_elgamal_pub_integer_single_to_str_hexf_n(&destination->m_key_elgamal_pub.m_data.m_integer, &str_buf[0], mk_lang_countof(str_buf)); mk_lang_assert(str_len == mk_lib_iip_key_enc_elgamal_pub_integer_single_strlen_hex_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_buf[0] = '\x0a'; str_len = 1;
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_len = mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_str_hexf_n(&destination->m_key_dsa_sha1_pub.m_data.m_integer, &str_buf[0], mk_lang_countof(str_buf)); mk_lang_assert(str_len == mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_strlen_hex_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_buf[0] = '\x0a'; str_len = 1;
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	err = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_destination_elgamal_dsa_sha1_generate_new_random_and_save_pri_only(mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pt const destination, mk_lang_types_pchar_pct const file_name) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(destination);
	mk_lang_assert(file_name);
	mk_lang_assert(file_name[0] != '\0');

	err = mk_clib_app_iip_destination_elgamal_dsa_sha1_generate_new_random(destination); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_destination_elgamal_dsa_sha1_save_pri_only(destination, file_name); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_destination_elgamal_dsa_sha1_generate_new_random_and_save_pri_pub(mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pt const destination, mk_lang_types_pchar_pct const file_name) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(destination);
	mk_lang_assert(file_name);
	mk_lang_assert(file_name[0] != '\0');

	err = mk_clib_app_iip_destination_elgamal_dsa_sha1_generate_new_random(destination); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_destination_elgamal_dsa_sha1_save_pri_pub(destination, file_name); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_destination_elgamal_dsa_sha1_load_pri_only(mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pt const destination, mk_lang_types_pchar_pct const file_name) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_io_reader_file_t reader;
	mk_lang_types_sint_t str_len;
	mk_sl_cui_uint8_t bin_buf[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pri_integer_single_strlen_hex_v)), ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_strlen_hex_v)))];
	mk_lang_types_sint_t read;
	mk_lang_types_pchar_t str_buf[mk_lang_countof(bin_buf)];
	mk_lang_types_bool_t is_valid;

	mk_lang_assert(destination);
	mk_lang_assert(file_name);
	mk_lang_assert(file_name[0] != '\0');

	err = mk_sl_io_reader_file_open_n(&reader, file_name); mk_lang_check_rereturn(err);

	str_len = mk_lib_iip_key_enc_elgamal_pri_integer_single_strlen_hex_v;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	str_len = mk_lib_iip_key_enc_elgamal_pri_integer_single_from_str_hex_n(&destination->m_key_elgamal_pri.m_data.m_integer, &str_buf[0], str_len); mk_lang_assert(str_len == mk_lib_iip_key_enc_elgamal_pri_integer_single_strlen_hex_v);

	str_len = 1;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	mk_lang_check_return(str_buf[0] == '\x0a');

	str_len = mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_strlen_hex_v;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	str_len = mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_from_str_hex_n(&destination->m_key_dsa_sha1_pri.m_data.m_integer, &str_buf[0], str_len); mk_lang_assert(str_len == mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_strlen_hex_v);

	err = mk_sl_io_reader_file_close(&reader); mk_lang_check_rereturn(err);

	is_valid = mk_lib_iip_key_sgn_dsa_sha1_pri_is_valid(&destination->m_key_dsa_sha1_pri); mk_lang_check_return(is_valid);
	mk_lib_iip_key_enc_elgamal_pri_compute_public(&destination->m_key_elgamal_pri, &destination->m_key_elgamal_pub);
	mk_lib_iip_key_sgn_dsa_sha1_pri_compute_public(&destination->m_key_dsa_sha1_pri, &destination->m_key_dsa_sha1_pub);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_destination_elgamal_dsa_sha1_load_pri_pub(mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pt const destination, mk_lang_types_pchar_pct const file_name) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_io_reader_file_t reader;
	mk_lang_types_sint_t str_len;
	mk_sl_cui_uint8_t bin_buf[mk_lang_max(mk_lang_max(mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pri_integer_single_strlen_hex_v)), ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_strlen_hex_v))), ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pub_integer_single_strlen_hex_v))), ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_strlen_hex_v)))];
	mk_lang_types_sint_t read;
	mk_lang_types_pchar_t str_buf[mk_lang_countof(bin_buf)];

	mk_lang_assert(destination);
	mk_lang_assert(file_name);
	mk_lang_assert(file_name[0] != '\0');

	err = mk_sl_io_reader_file_open_n(&reader, file_name); mk_lang_check_rereturn(err);

	str_len = mk_lib_iip_key_enc_elgamal_pri_integer_single_strlen_hex_v;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	str_len = mk_lib_iip_key_enc_elgamal_pri_integer_single_from_str_hex_n(&destination->m_key_elgamal_pri.m_data.m_integer, &str_buf[0], str_len); mk_lang_assert(str_len == mk_lib_iip_key_enc_elgamal_pri_integer_single_strlen_hex_v);

	str_len = 1;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	mk_lang_check_return(str_buf[0] == '\x0a');

	str_len = mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_strlen_hex_v;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	str_len = mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_from_str_hex_n(&destination->m_key_dsa_sha1_pri.m_data.m_integer, &str_buf[0], str_len); mk_lang_assert(str_len == mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_strlen_hex_v);

	str_len = 1;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	mk_lang_check_return(str_buf[0] == '\x0a');

	str_len = mk_lib_iip_key_enc_elgamal_pub_integer_single_strlen_hex_v;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	str_len = mk_lib_iip_key_enc_elgamal_pub_integer_single_from_str_hex_n(&destination->m_key_elgamal_pub.m_data.m_integer, &str_buf[0], str_len); mk_lang_assert(str_len == mk_lib_iip_key_enc_elgamal_pub_integer_single_strlen_hex_v);

	str_len = 1;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	mk_lang_check_return(str_buf[0] == '\x0a');

	str_len = mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_strlen_hex_v;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	str_len = mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_from_str_hex_n(&destination->m_key_dsa_sha1_pub.m_data.m_integer, &str_buf[0], str_len); mk_lang_assert(str_len == mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_strlen_hex_v);

	err = mk_sl_io_reader_file_close(&reader); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_destination_elgamal_dsa_sha1_save_base64(mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pt const destination, mk_lang_types_pchar_pct const file_name) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_io_writer_file_t writer;
	mk_lang_types_sint_t ptr;
	mk_sl_cui_uint8_t bin_buf[256 + 128 + 1 + 2];
	mk_lang_types_sint_t tsi;
	mk_sl_cui_uint16_t u16;
	mk_lang_types_pchar_t str_b64_buf[mk_lang_roundup_div(mk_lang_countof(bin_buf), 3) * 4];
	mk_lang_types_sint_t str_len;
	mk_lang_types_sint_t written;

	mk_lang_assert(destination);
	mk_lang_assert(file_name);
	mk_lang_assert(file_name[0] != '\0');

	err = mk_sl_io_writer_file_open_n(&writer, file_name); mk_lang_check_rereturn(err);
	ptr = 0;
	mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s(&destination->m_key_elgamal_pub.m_data.m_integer, &bin_buf[ptr]); ptr += 256;
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_u8s(&destination->m_key_dsa_sha1_pub.m_data.m_integer, &bin_buf[ptr]); ptr += 128;
	tsi = mk_lib_iip_cp_types_certificate_type_e_null; mk_sl_cui_uint8_from_bi_sint(&bin_buf[ptr], &tsi); ptr += 1;
	tsi = 0; mk_sl_cui_uint16_from_bi_sint(&u16, &tsi); mk_sl_uint_convert_16_8_be_to_sml(&u16, &bin_buf[ptr]); ptr += 2;
	mk_lib_iip_base64_encoder_fn(&bin_buf[0], mk_lang_countof(bin_buf), &str_b64_buf[0], mk_lang_countof(str_b64_buf), &str_len); mk_lang_check_return(str_len == mk_lang_countof(str_b64_buf));
	err = mk_sl_io_writer_file_write(&writer, ((mk_sl_cui_uint8_pct)(&str_b64_buf[0])), str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);
	err = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_parse_settings_from_cmd_line(mk_lib_iip_cp_client_types_connection_settings_pt const settings, mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t param_idx;
	mk_lang_tchar_pct param_buf;
	mk_lang_types_sint_t param_len;
	mk_lang_types_pchar_t param_store[64];
	mk_lang_types_pchar_pct param_ptr;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t consumed;

	mk_lang_assert(settings);
	mk_lang_assert(argc >= 0);
	mk_lang_assert(argv);
	mk_lang_assert(lens);

	mk_lang_check_return(argc == 3);
	n = argc;
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(argv[i]);
		mk_lang_assert(argv[i][0] != mk_lang_tchar_c('\0'));
		mk_lang_assert(lens[i] >= 1);
	}

	param_idx = 1;
	param_buf = argv[param_idx];
	param_len = lens[param_idx];
	param_len = mk_lang_min(param_len, mk_lang_countof(param_store) - 1);
	mk_lang_tchar_to_bi_pchar_many(&param_buf[0], &param_store[0], param_len);
	param_store[param_len] = '\0';
	param_ptr = &param_store[0];

	err = mk_lib_net_ipv4_address_parse_pc(&settings->m_destination.m_ipv4_address, param_ptr, param_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(consumed >= 1); mk_lang_assert(consumed <= param_len);
	mk_lang_check_return(!mk_lib_net_ipv4_address_is_any(&settings->m_destination.m_ipv4_address));
	mk_lang_check_return(!mk_lib_net_ipv4_address_is_none(&settings->m_destination.m_ipv4_address));

	param_idx = 2;
	param_buf = argv[param_idx];
	param_len = lens[param_idx];
	param_len = mk_lang_min(param_len, mk_lang_countof(param_store));
	mk_lang_tchar_to_bi_pchar_many(&param_buf[0], &param_store[0], param_len);
	param_ptr = &param_store[0];

	err = mk_lib_net_tcp_port_parse_pc(&settings->m_destination.m_tcp_port, param_ptr, param_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(consumed >= 1); mk_lang_assert(consumed <= param_len);
	mk_lang_check_return(!mk_lib_net_tcp_port_is_zero(&settings->m_destination.m_tcp_port));
	mk_lang_check_return(!mk_lib_net_tcp_port_is_max(&settings->m_destination.m_tcp_port));

	settings->m_authentication.m_username.m_len = 0;

	settings->m_authentication.m_password.m_len = 0;

	return 0;
}

mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_clib_app_iip_parse_settings_from_hardcoded_k_ip[] = "127.0.0.1";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_clib_app_iip_parse_settings_from_hardcoded_k_port[] = "7654";

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_parse_settings_from_hardcoded(mk_lib_iip_cp_client_types_connection_settings_pt const settings) mk_lang_noexcept
{
	mk_lang_types_pchar_pct param_ptr;
	mk_lang_types_sint_t param_len;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t consumed;

	mk_lang_assert(settings);

	param_ptr = &mk_clib_app_iip_parse_settings_from_hardcoded_k_ip[0];
	param_len = mk_lang_countstr(mk_clib_app_iip_parse_settings_from_hardcoded_k_ip);

	err = mk_lib_net_ipv4_address_parse_pc(&settings->m_destination.m_ipv4_address, param_ptr, param_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(consumed >= 1); mk_lang_assert(consumed <= param_len);
	mk_lang_check_return(!mk_lib_net_ipv4_address_is_any(&settings->m_destination.m_ipv4_address));
	mk_lang_check_return(!mk_lib_net_ipv4_address_is_none(&settings->m_destination.m_ipv4_address));

	param_ptr = &mk_clib_app_iip_parse_settings_from_hardcoded_k_port[0];
	param_len = mk_lang_countstr(mk_clib_app_iip_parse_settings_from_hardcoded_k_port);

	err = mk_lib_net_tcp_port_parse_pc(&settings->m_destination.m_tcp_port, param_ptr, param_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(consumed >= 1); mk_lang_assert(consumed <= param_len);
	mk_lang_check_return(!mk_lib_net_tcp_port_is_zero(&settings->m_destination.m_tcp_port));
	mk_lang_check_return(!mk_lib_net_tcp_port_is_max(&settings->m_destination.m_tcp_port));

	settings->m_authentication.m_username.m_len = 0;

	settings->m_authentication.m_password.m_len = 0;

	return 0;
}

mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_clib_app_iip_parse_settings_local_from_hardcoded_1_k_addr[] = "0.0.0.0";
mk_lang_constexpr_static_inline mk_lang_types_sint_t const mk_clib_app_iip_parse_settings_local_from_hardcoded_1_k_port = 6969;

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_parse_settings_local_from_hardcoded_1(mk_lib_iip_cp_client_types_local_settings_pt const settings) mk_lang_noexcept
{
	mk_lang_types_pchar_pct addr_str_buf;
	mk_lang_types_sint_t addr_str_len;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t consumed;
	mk_lang_types_sint_t port;

	mk_lang_assert(settings);

	addr_str_buf = &mk_clib_app_iip_parse_settings_local_from_hardcoded_1_k_addr[0];
	addr_str_len = mk_lang_countstr(mk_clib_app_iip_parse_settings_local_from_hardcoded_1_k_addr);
	err = mk_lib_net_ipv4_address_parse_pc(&settings->m_destination.m_ipv4_address, addr_str_buf, addr_str_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(consumed >= 1); mk_lang_assert(consumed <= addr_str_len);
	mk_lang_check_return(!mk_lib_net_ipv4_address_is_none(&settings->m_destination.m_ipv4_address));
	port = mk_clib_app_iip_parse_settings_local_from_hardcoded_1_k_port;
	mk_lib_net_tcp_port_from_bi_sint(&settings->m_destination.m_tcp_port, &port);
	return 0;
}

mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_clib_app_iip_parse_settings_local_from_hardcoded_2_k_addr[] = "0.0.0.0";
mk_lang_constexpr_static_inline mk_lang_types_sint_t const mk_clib_app_iip_parse_settings_local_from_hardcoded_2_k_port = 8080;

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_parse_settings_local_from_hardcoded_2(mk_lib_iip_cp_client_types_local_settings_pt const settings) mk_lang_noexcept
{
	mk_lang_types_pchar_pct addr_str_buf;
	mk_lang_types_sint_t addr_str_len;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t consumed;
	mk_lang_types_sint_t port;

	mk_lang_assert(settings);

	addr_str_buf = &mk_clib_app_iip_parse_settings_local_from_hardcoded_2_k_addr[0];
	addr_str_len = mk_lang_countstr(mk_clib_app_iip_parse_settings_local_from_hardcoded_2_k_addr);
	err = mk_lib_net_ipv4_address_parse_pc(&settings->m_destination.m_ipv4_address, addr_str_buf, addr_str_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(consumed >= 1); mk_lang_assert(consumed <= addr_str_len);
	mk_lang_check_return(!mk_lib_net_ipv4_address_is_none(&settings->m_destination.m_ipv4_address));
	port = mk_clib_app_iip_parse_settings_local_from_hardcoded_2_k_port;
	mk_lib_net_tcp_port_from_bi_sint(&settings->m_destination.m_tcp_port, &port);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_win_base_bool_t mk_win_base_stdcall mk_clib_app_iip_pr_ctrl_c_handler(mk_win_base_dword_t const type) mk_lang_noexcept
{
	mk_lang_types_bool_t interesting;
	mk_lang_types_bool_t wait;
	mk_lang_types_sint_t err;
	mk_win_base_dword_t waited;

	switch(type)
	{
		case mk_win_dll_kernel_console_ctrl_event_id_e_c:
		case mk_win_dll_kernel_console_ctrl_event_id_e_break:
		case mk_win_dll_kernel_console_ctrl_event_id_e_close:
		case mk_win_dll_kernel_console_ctrl_event_id_e_logoff:
		case mk_win_dll_kernel_console_ctrl_event_id_e_shutdown:
			interesting = mk_lang_true;
			break;
		default:
			interesting = mk_lang_false;
			break;
	}
	switch(type)
	{
		case mk_win_dll_kernel_console_ctrl_event_id_e_close:
		case mk_win_dll_kernel_console_ctrl_event_id_e_logoff:
		case mk_win_dll_kernel_console_ctrl_event_id_e_shutdown:
			wait = mk_lang_true;
			break;
		default:
			wait = mk_lang_false;
			break;
	}
	if(interesting)
	{
		mk_clib_app_iip_g_stop_requested = mk_lang_true;
		err = mk_lib_iip_cp_client_wrapper_task_rw_poke(mk_clib_app_iip_g_wrp); mk_lang_check_recrash(err);
		if(wait)
		{
			mk_lang_assert(!mk_win_base_handle_is_null(mk_clib_app_iip_g_main_thread));
			mk_lang_assert(!mk_win_base_handle_is_invalid(mk_clib_app_iip_g_main_thread));
			waited = mk_win_dll_kernel_synchronization_wait_one(mk_clib_app_iip_g_main_thread, mk_win_base_infinite); ((mk_lang_types_void_t)(waited));
			/* do not close that thread handle */
		}
	}
	return interesting ? mk_win_base_true : mk_win_base_false;
}

struct web_servers_s
{
	mk_lib_iip_cp_client_wrapper_task_pt m_wrp;
	mk_lib_iip_cp_client_types_handle_session_t m_session_1;
	mk_lib_iip_cp_client_types_handle_session_t m_session_2;
	mk_lib_iip_cp_client_types_handle_session_t m_session_3;
	mk_lib_iip_cp_client_types_handle_socket_listener_t m_socket_1;
	mk_lib_iip_cp_client_types_handle_socket_listener_t m_socket_2;
	mk_lib_iip_cp_client_types_handle_socket_listener_t m_socket_3;
	mk_lib_iip_http_t m_http_1;
	mk_lib_iip_http_t m_http_2;
	mk_lib_iip_http_t m_http_3;
};
typedef struct web_servers_s web_servers_t;
mk_lang_typedef(web_servers);

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_web_servers_init(web_servers_pt const web_servers) mk_lang_noexcept
{
	mk_lib_iip_cp_client_types_socket_listener_settings_t settings;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t err;

	mk_lang_assert(web_servers);

	settings.m_session = web_servers->m_session_1;
	tsi = 80; mk_sl_cui_uint16_from_bi_sint(&settings.m_port, &tsi);
	err = mk_lib_iip_cp_client_wrapper_task_rw_new_socket_listener(web_servers->m_wrp, &settings, &web_servers->m_socket_1); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_rw_construct(&web_servers->m_http_1); mk_lang_check_rereturn(err);

	settings.m_session = web_servers->m_session_2;
	tsi = 80; mk_sl_cui_uint16_from_bi_sint(&settings.m_port, &tsi);
	err = mk_lib_iip_cp_client_wrapper_task_rw_new_socket_listener(web_servers->m_wrp, &settings, &web_servers->m_socket_2); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_rw_construct(&web_servers->m_http_2); mk_lang_check_rereturn(err);

	settings.m_session = web_servers->m_session_3;
	tsi = 80; mk_sl_cui_uint16_from_bi_sint(&settings.m_port, &tsi);
	err = mk_lib_iip_cp_client_wrapper_task_rw_new_socket_listener(web_servers->m_wrp, &settings, &web_servers->m_socket_3); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_rw_construct(&web_servers->m_http_3); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_clib_app_iip_web_servers_k_uri_root[] = "/";

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_clib_app_iip_web_servers_compare(mk_lib_iip_http_buffer_pct const buf, mk_lang_types_pchar_pct const str) mk_lang_noexcept
{
	mk_lang_types_bool_t eq;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_sl_cui_uint8_t u8;

	mk_lang_assert(buf);
	mk_lang_assert(str);

	eq = mk_lang_true;
	n = mk_lib_iip_http_buffer_ro_size(buf);
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_from_bi_pchar(&u8, &str[i]);
		if(!mk_sl_cui_uint8_eq(&u8, mk_lib_iip_http_buffer_ro_at(buf, i)))
		{
			eq = mk_lang_false;
			break;
		}
	}
	return eq;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_web_servers_check_one(web_servers_pt const web_servers, mk_lib_iip_cp_client_types_handle_socket_listener_pt const socket, mk_lib_iip_http_pt const http) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_t data_buf[4 * 1024];
	mk_lang_types_sint_t data_len;
	mk_lib_iip_http_parse_error_code_t code;
	mk_lang_types_sint_t consumed;
	mk_lang_types_sint_t data_transferred;

	mk_lang_assert(web_servers);
	mk_lang_assert(socket);
	mk_lang_assert(http);

	err = mk_lib_iip_cp_client_wrapper_task_rw_socket_recv(web_servers->m_wrp, socket, &data_buf[0], mk_lang_countof(data_buf), &data_len); mk_lang_check_rereturn(err);
	code = mk_lib_iip_http_parse_error_code_e_ok;
	err = mk_lib_iip_http_rw_on_incoming_data(http, &data_buf[0], data_len, &code, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(consumed == data_len);
	if
	(
		(http->m_hdrs_done) &&
		(http->m_method == mk_lib_iip_http_method_id_e_get) &&
		(mk_lib_iip_http_buffer_ro_size(&http->m_uri) == mk_lang_countstr(mk_clib_app_iip_web_servers_k_uri_root)) &&
		(mk_clib_app_iip_web_servers_compare(&http->m_uri, &mk_clib_app_iip_web_servers_k_uri_root[0])) &&
		(mk_lang_true)
	)
	{
		err = mk_lib_iip_http_rw_destroy(http); mk_lang_check_rereturn(err);
		err = mk_lib_iip_http_rw_construct(http); mk_lang_check_rereturn(err);
		/*response*/
		err = mk_lib_iip_cp_client_wrapper_task_rw_socket_send(web_servers->m_wrp, socket, &data_buf[0], data_len, &data_transferred); mk_lang_check_rereturn(err);
		mk_lang_check_return(data_transferred == data_len);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_web_servers_check(web_servers_pt const web_servers) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(web_servers);

	err = mk_clib_app_iip_web_servers_check_one(web_servers, &web_servers->m_socket_1, &web_servers->m_http_1); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_web_servers_check_one(web_servers, &web_servers->m_socket_2, &web_servers->m_http_2); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_web_servers_check_one(web_servers, &web_servers->m_socket_3, &web_servers->m_http_3); mk_lang_check_rereturn(err);
	return 0;
}

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_clib_app_iip_example1_s
{
	mk_lib_iip_cp_client_wrapper_task_pt m_wrp;
	mk_lib_iip_cp_client_types_handle_session_pt m_session;
	mk_lang_types_bool_t m_resolve_request_sent;
	mk_lang_types_bool_t m_resolve_request_finished;
	mk_lang_types_bool_t m_remote_address_has;
	mk_lang_types_bool_t m_connect_sent;
	mk_lib_iip_cp_client_types_lookup_host_name_t m_request;
	mk_lib_iip_cp_types_remote_destination_t m_destination;
};
typedef struct mk_clib_app_iip_example1_s mk_clib_app_iip_example1_t;
mk_lang_typedef(mk_clib_app_iip_example1);
#include "mk_lang_warning_msvc_pop.h"

static mk_clib_app_iip_example1_t mk_clib_app_iip_example1_g;

mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_clib_app_iip_example1_k_domain[] = "reg.i2p";
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_clib_app_iip_example1_k_b32_suffix[] = ".b32.i2p";

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_example1_rw_construct(mk_clib_app_iip_example1_pt const example1, mk_lib_iip_cp_client_wrapper_task_pt const wrp, mk_lib_iip_cp_client_types_handle_session_pt const session) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(example1);
	mk_lang_assert(wrp);
	mk_lang_assert(session);

	example1->m_wrp = wrp;
	example1->m_session = session;
	example1->m_resolve_request_sent = mk_lang_false;
	example1->m_resolve_request_finished = mk_lang_false;
	example1->m_remote_address_has = mk_lang_false;
	example1->m_connect_sent = mk_lang_false;
	example1->m_request.m_done = mk_lang_false;
	err = mk_lib_iip_buffer_rw_construct(&example1->m_request.m_destination); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_example1_rw_destroy(mk_clib_app_iip_example1_pt const example1) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(example1);

	err = mk_lib_iip_buffer_rw_destroy(&example1->m_request.m_destination); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_example1_rw_on_idle_send_request(mk_clib_app_iip_example1_pt const example1) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(example1);

	if(!example1->m_resolve_request_sent)
	{
		example1->m_resolve_request_sent = mk_lang_true;
		example1->m_request.m_session = *example1->m_session;
		example1->m_request.m_host_name_buf = &mk_clib_app_iip_example1_k_domain[0];
		example1->m_request.m_host_name_len = mk_lang_countstr(mk_clib_app_iip_example1_k_domain);
		err = mk_lib_iip_cp_client_wrapper_task_rw_lookup_host_name(example1->m_wrp, &example1->m_request); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_example1_rw_on_idle_print_address(mk_clib_app_iip_example1_pt const example1) mk_lang_noexcept
{
	mk_lang_types_pchar_pt b32_ptr;
	mk_lang_types_pchar_t b32_buf[mk_lang_roundup_div(mk_lib_crypto_hash_block_sha2_256_digest_len_v * 8, 5) + mk_lang_countstr(mk_clib_app_iip_example1_k_b32_suffix)];
	mk_lang_types_sint_t b32_cap;
	mk_lang_types_pchar_pt b64_ptr;
	mk_lang_types_pchar_t b64_buf[4 * 1024];
	mk_lang_types_sint_t b64_cap;
	mk_lang_tchar_pt str_ptr;
	mk_lang_tchar_t str_buf[4 * 1024];
	mk_lang_types_sint_t str_cap;
	mk_lib_crypto_hash_stream_sha2_256_t hasher;
	mk_lib_crypto_hash_stream_sha2_256_digest_t digest;
	mk_lang_types_sint_t b32_len;
	mk_lang_types_sint_t b64_len;
	mk_lang_types_sint_t str_len;
	mk_lang_types_sint_t err;

	mk_lang_assert(example1);
	mk_lang_assert(example1->m_resolve_request_finished);
	mk_lang_assert(example1->m_request.m_done);

	if(example1->m_request.m_result_code == 0)
	{
		b32_ptr = &b32_buf[0];
		b32_cap = mk_lang_countof(b32_buf);
		b64_ptr = &b64_buf[0];
		b64_cap = mk_lang_countof(b64_buf);
		str_ptr = &str_buf[0];
		str_cap = mk_lang_countof(str_buf);
		mk_lib_crypto_hash_stream_sha2_256_init(&hasher);
		mk_lib_crypto_hash_stream_sha2_256_append_u8s(&hasher, mk_lib_iip_buffer_ro_data(&example1->m_request.m_destination), mk_lib_iip_buffer_ro_size(&example1->m_request.m_destination));
		mk_lib_crypto_hash_stream_sha2_256_finish(&hasher, &digest);
		mk_lib_iip_base32_encoder_fn(&digest.m_data.m_uint8s[0], mk_lib_crypto_hash_block_sha2_256_digest_len_v, b32_ptr, b32_cap, &b32_len); mk_lang_assert(b32_len == mk_lang_roundup_div(mk_lib_crypto_hash_block_sha2_256_digest_len_v * 8, 5));
		mk_lang_string_memcpy_pc_fn(&b32_ptr[b32_len], &mk_clib_app_iip_example1_k_b32_suffix[0], mk_lang_countstr(mk_clib_app_iip_example1_k_b32_suffix)); b32_len += mk_lang_countstr(mk_clib_app_iip_example1_k_b32_suffix);
		mk_lib_iip_base64_encoder_fn(mk_lib_iip_buffer_ro_data(&example1->m_request.m_destination), mk_lib_iip_buffer_ro_sise(&example1->m_request.m_destination), b64_ptr, b64_cap, &b64_len);
		str_len = mk_lib_fmt_t_snnprintf(str_ptr, str_cap, mk_lib_fmt_lit_and_len(mk_lang_tchar_c("Resolved domain name %ht to b32: %ht and to b64: %ht.")), &mk_clib_app_iip_example1_k_domain[0], mk_lang_countstr(mk_clib_app_iip_example1_k_domain), b32_ptr, b32_len, b64_ptr, b64_len); mk_lang_check_return(str_len >= 1); mk_lang_check_return(str_len <= str_cap);
		err = mk_lang_stdout_println_t(str_ptr, str_len); mk_lang_check_rereturn(err);
	}
	else
	{
		err = mk_lang_stdout_println_lit_t("Failed to resolve domain name."); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_example1_rw_on_idle_process_address(mk_clib_app_iip_example1_pt const example1) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt dst_data;
	mk_lang_types_sint_t dst_sise;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t consumed;

	mk_lang_assert(example1);

	if(!example1->m_resolve_request_finished)
	{
		if(example1->m_request.m_done)
		{
			example1->m_resolve_request_finished = mk_lang_true;
			err = mk_clib_app_iip_example1_rw_on_idle_print_address(example1); mk_lang_check_rereturn(err);
			if(example1->m_request.m_result_code == 0)
			{
				example1->m_remote_address_has = mk_lang_true;
				dst_data = mk_lib_iip_buffer_rw_data(&example1->m_request.m_destination); mk_lang_assert(dst_data);
				dst_sise = mk_lib_iip_buffer_rw_sise(&example1->m_request.m_destination); mk_lang_assert(dst_sise >= 1);
				gud = mk_lang_true;
				err = mk_lib_iip_cp_types_remote_destination_rw_from_bytes(&example1->m_destination, dst_data, dst_sise, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_check_return(consumed == dst_sise);
				err = mk_lib_iip_buffer_rw_reconstruct(&example1->m_request.m_destination); mk_lang_check_rereturn(err);
			}
			else
			{
				example1->m_remote_address_has = mk_lang_false;
			}
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_example1_rw_on_idle_connect(mk_clib_app_iip_example1_pt const example1) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(example1);

	if(example1->m_resolve_request_finished && !example1->m_connect_sent)
	{
		example1->m_connect_sent = mk_lang_true;

		example1->m_request.m_session = *example1->m_session;
		example1->m_request.m_host_name_buf = &mk_clib_app_iip_example1_k_domain[0];
		example1->m_request.m_host_name_len = mk_lang_countstr(mk_clib_app_iip_example1_k_domain);
		err = mk_lib_iip_buffer_rw_construct(&example1->m_request.m_destination); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_client_wrapper_task_rw_lookup_host_name(example1->m_wrp, &example1->m_request); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_example1_rw_on_idle(mk_clib_app_iip_example1_pt const example1) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(example1);

	err = mk_clib_app_iip_example1_rw_on_idle_send_request(example1); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_example1_rw_on_idle_process_address(example1); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_example1_rw_on_idle_connect(example1); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_clib_app_iip_k_session_nickname[] = "iip";

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_work(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_wrapper_task_result_t step_result;

	mk_lib_iip_cp_client_types_application_settings_t app_settings;
	mk_lib_iip_cp_client_types_connection_settings_t connection_settings_1;
	mk_lib_iip_cp_client_types_session_settings_t session_settings_1;
	mk_lib_iip_cp_client_types_connection_settings_t connection_settings_2;
	mk_lib_iip_cp_client_types_session_settings_t session_settings_2;
	mk_lib_iip_cp_client_types_session_settings_t session_settings_3;

	mk_lib_iip_cp_client_types_local_settings_t local_settings_1;
	mk_lib_iip_cp_client_types_local_settings_t local_settings_2;

	mk_lib_iip_cp_client_wrapper_task_t wrp;
	mk_lib_iip_cp_client_types_handle_local_t local_1;
	mk_lib_iip_cp_client_types_handle_local_t local_2;
	mk_lib_iip_cp_client_types_handle_connection_t connection_1;
	mk_lib_iip_cp_client_types_handle_session_t session_1;
	mk_lib_iip_cp_client_types_handle_connection_t connection_2;
	mk_lib_iip_cp_client_types_handle_session_t session_2;
	mk_lib_iip_cp_client_types_handle_session_t session_3;

	web_servers_t web_servers;
	mk_clib_app_iip_example1_t example1;

	/*mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_t destination;*/
	/*err = mk_clib_app_iip_destination_elgamal_dsa_sha1_generate_new_random_and_save_pri_only(&destination, "destination.txt"); mk_lang_check_rereturn(err);*/
	/*err = mk_clib_app_iip_destination_elgamal_dsa_sha1_generate_new_random_and_save_pri_pub(&destination, "destination3.txt"); mk_lang_check_rereturn(err);*/
	/*err = mk_clib_app_iip_destination_elgamal_dsa_sha1_load_pri_only(&destination, "destination2.txt"); mk_lang_check_rereturn(err);*/
	/*err = mk_clib_app_iip_destination_elgamal_dsa_sha1_save_base64(&destination, "destination2b64.txt"); mk_lang_check_rereturn(err);*/
	/*err = mk_clib_app_iip_destination_elgamal_dsa_sha1_save_pri_only(&destination, "destination.txt"); mk_lang_check_rereturn(err);*/
	/*err = mk_clib_app_iip_destination_elgamal_dsa_sha1_save_pri_pub(&destination, "destination.txt"); mk_lang_check_rereturn(err);*/

	app_settings.m_dummy = 0;
	app_settings.m_iocp_settings.m_dummy = 0;
	err = mk_clib_app_iip_parse_settings_from_cmd_line(&connection_settings_1, argc, argv, lens); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_destination_elgamal_dsa_sha1_load_pri_pub(&session_settings_1.m_destination, "destination1.txt"); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_parse_settings_from_hardcoded(&connection_settings_2); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_destination_elgamal_dsa_sha1_load_pri_pub(&session_settings_2.m_destination, "destination2.txt"); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_destination_elgamal_dsa_sha1_load_pri_pub(&session_settings_3.m_destination, "destination3.txt"); mk_lang_check_rereturn(err);
	session_settings_3.m_destination.m_key_elgamal_pri = session_settings_2.m_destination.m_key_elgamal_pri;
	session_settings_3.m_destination.m_key_elgamal_pub = session_settings_2.m_destination.m_key_elgamal_pub;
	err = mk_clib_app_iip_parse_settings_local_from_hardcoded_1(&local_settings_1); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_parse_settings_local_from_hardcoded_2(&local_settings_2); mk_lang_check_rereturn(err);

	err = mk_lib_iip_cp_client_wrapper_task_rw_construct(&wrp, &app_settings); mk_lang_check_rereturn(err);

	err = mk_lib_iip_cp_client_wrapper_task_rw_new_local_listener(&wrp, &local_settings_1, &local_1); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_wrapper_task_rw_new_local_listener(&wrp, &local_settings_2, &local_2); mk_lang_check_rereturn(err);

	err = mk_lib_iip_cp_client_wrapper_task_rw_new_connection(&wrp, &connection_settings_1, &connection_1); mk_lang_check_rereturn(err);

	mk_lib_iip_cp_client_types_handle_session_set_zero(&session_settings_1.m_master_session);
	session_settings_1.m_connection = connection_1;
	err = mk_lib_iip_cp_client_types_session_settings_options_rw_construct(&session_settings_1.m_options); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_types_session_settings_options_rw_set_i2cp_fast_receive(&session_settings_1.m_options, mk_lang_false); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_types_session_settings_options_rw_set_inbound_nickname(&session_settings_1.m_options, &mk_clib_app_iip_k_session_nickname[0], mk_lang_countstr(mk_clib_app_iip_k_session_nickname)); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_wrapper_task_rw_new_session(&wrp, &session_settings_1, &session_1); mk_lang_check_rereturn(err);

	err = mk_lib_iip_cp_client_wrapper_task_rw_new_connection(&wrp, &connection_settings_2, &connection_2); mk_lang_check_rereturn(err);

	mk_lib_iip_cp_client_types_handle_session_set_zero(&session_settings_2.m_master_session);
	session_settings_2.m_connection = connection_2;
	err = mk_lib_iip_cp_client_types_session_settings_options_rw_construct(&session_settings_2.m_options); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_types_session_settings_options_rw_set_i2cp_fast_receive(&session_settings_2.m_options, mk_lang_false); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_types_session_settings_options_rw_set_inbound_nickname(&session_settings_2.m_options, &mk_clib_app_iip_k_session_nickname[0], mk_lang_countstr(mk_clib_app_iip_k_session_nickname)); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_wrapper_task_rw_new_session(&wrp, &session_settings_2, &session_2); mk_lang_check_rereturn(err);

	session_settings_3.m_master_session = session_2;
	session_settings_3.m_connection = connection_2;
	err = mk_lib_iip_cp_client_types_session_settings_options_rw_construct(&session_settings_3.m_options); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_types_session_settings_options_rw_set_i2cp_fast_receive(&session_settings_3.m_options, mk_lang_false); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_types_session_settings_options_rw_set_inbound_nickname(&session_settings_3.m_options, &mk_clib_app_iip_k_session_nickname[0], mk_lang_countstr(mk_clib_app_iip_k_session_nickname)); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_wrapper_task_rw_new_session(&wrp, &session_settings_3, &session_3); mk_lang_check_rereturn(err);

	web_servers.m_wrp = &wrp;
	web_servers.m_session_1 = session_1;
	web_servers.m_session_2 = session_2;
	web_servers.m_session_3 = session_3;
	err = mk_clib_app_iip_web_servers_init(&web_servers); mk_lang_check_rereturn(err);

	err = mk_clib_app_iip_example1_rw_construct(&example1, &wrp, &session_1); mk_lang_check_rereturn(err);

	mk_clib_app_iip_g_wrp = &wrp;
	mk_clib_app_iip_g_stop_requested = mk_lang_false;
	b = mk_win_dll_kernel_handle_duplicate(mk_win_dll_kernel_process_get_current_process(), mk_win_dll_kernel_process_get_current_thread(), mk_win_dll_kernel_process_get_current_process(), &mk_clib_app_iip_g_main_thread, 0, mk_win_base_false, mk_win_dll_kernel_handle_duplicate_same_access); mk_lang_check_return(b != mk_win_base_false); mk_lang_check_return(!mk_win_base_handle_is_null(mk_clib_app_iip_g_main_thread)); mk_lang_check_return(!mk_win_base_handle_is_invalid(mk_clib_app_iip_g_main_thread));
	b = mk_win_dll_kernel_console_set_ctrl_handler(&mk_clib_app_iip_pr_ctrl_c_handler, mk_win_base_true); mk_lang_check_return(b != mk_win_base_false);

	for(;;)
	{
		step_result = mk_lib_iip_cp_client_wrapper_task_result_e_dummy_end;
		err = mk_lib_iip_cp_client_wrapper_task_rw_run_no_block(&wrp, &step_result); mk_lang_check_rereturn(err);
		if(step_result == mk_lib_iip_cp_client_wrapper_task_result_e_did_nothing)
		{
			break;
		}
		err = mk_clib_app_iip_web_servers_check(&web_servers); mk_lang_check_rereturn(err);
		err = mk_clib_app_iip_example1_rw_on_idle(&example1); mk_lang_check_rereturn(err);
		step_result = mk_lib_iip_cp_client_wrapper_task_result_e_dummy_end;
		err = mk_lib_iip_cp_client_wrapper_task_rw_step(&wrp, mk_lang_true, 10 * 1000, &step_result); mk_lang_check_rereturn(err);
		if(step_result == mk_lib_iip_cp_client_wrapper_task_result_e_did_nothing)
		{
			break;
		}
		if(mk_clib_app_iip_g_stop_requested)
		{
			break;
		}
	}

	/* do not uninstall ctrl+c handler */

	err = mk_lib_iip_cp_client_wrapper_task_rw_request_close(&wrp); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_wrapper_task_rw_run_do_block(&wrp); mk_lang_check_rereturn(err);

	err = mk_clib_app_iip_example1_rw_destroy(&example1); mk_lang_check_rereturn(err);

	err = mk_lib_iip_cp_client_wrapper_task_rw_destroy(&wrp); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_usage(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_tchar_pct exe_name;
	mk_lang_types_sint_t exe_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;
	mk_lang_tchar_t buf[4 * 1024];
	mk_sl_time_timestamp_t time_val;
	mk_lang_types_sint_t time_len;
	mk_lang_types_pchar_t time_str[mk_sl_time_k_str_len];

	mk_lang_assert(argc == 1);
	mk_lang_assert(argv);
	mk_lang_assert(lens);
	mk_lang_assert(argv[0]);
	mk_lang_assert(argv[0][0] != mk_lang_tchar_c('\0'));
	mk_lang_assert(lens[0] >= 1);

	exe_name = mk_lang_exe_name_get_t(argv[0]); mk_lang_check_return(exe_name); mk_lang_check_return(exe_name[0] != mk_lang_tchar_c('\0'));
	exe_len = lens[0] - ((mk_lang_types_sint_t)(exe_name - argv[0])); mk_lang_check_return(exe_len >= 1);
	err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("iip")); mk_lang_check_rereturn(err);
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("exe name: %t")), exe_name, exe_len); mk_lang_check_return(len >= 1); mk_lang_check_return(len <= mk_lang_countof(buf)); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	mk_sl_time_timestamp_get_now(&time_val);
	time_len = mk_sl_time_to_text(&time_val, &time_str[0], mk_lang_countof(time_str)); mk_lang_assert(time_len == mk_lang_countof(time_str));
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("time: %ht")), &time_str[0], time_len); mk_lang_check_return(len >= 1); mk_lang_check_return(len <= mk_lang_countof(buf)); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_global_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_cpuid_init();
	err = mk_lang_stdout_init(); mk_lang_check_rereturn(err);
	err = mk_sl_random_init(); mk_lang_check_rereturn(err);
	err = mk_lib_net_init(); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_mallocator_global_init(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_global_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_lib_iip_cp_mallocator_global_deinit(); mk_lang_check_rereturn(err);
	err = mk_lib_net_deinit(); mk_lang_check_rereturn(err);
	err = mk_sl_random_deinit(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_global_main(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
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

#if mk_lang_entry_point_have


#include "mk_win_dll_kernel_process.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_peb_2(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_wchar_pct argv[16];
	mk_lang_types_sint_t lens[mk_lang_countof(argv)];
	mk_lang_types_sint_t argc;

	mk_lang_assert(peb);

	err = mk_clib_app_iip_global_init(); mk_lang_check_rereturn(err);
	err = mk_lang_command_line_parse_win(mk_win_dll_kernel_process_get_command_line(), &argv[0], &lens[0], mk_lang_countof(argv), &argc); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_global_main(argc, &argv[0], &lens[0]);
	err = mk_clib_app_iip_global_deinit(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t mk_clib_app_iip_peb(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t err_b;
	mk_lang_types_sint_t err;

	err_b = mk_clib_app_iip_peb_2(peb);
	if(err_b == 0)
	{
		err = mk_lang_stdout_println_lit_n("Gud."); mk_lang_check_rereturn(err);
	}
	else
	{
		err = mk_lang_stdout_println_lit_n("Bad."); mk_lang_check_rereturn(err);
	}
	mk_lang_check_rereturn(err_b);
	return 0;
}


#else


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_args_2(mk_lang_types_sint_t const std_argc, mk_lang_types_pchar_pcpct const std_argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct argv[16];
	mk_lang_types_sint_t lens[mk_lang_countof(argv)];
	mk_lang_types_sint_t argc;

	err = mk_clib_app_iip_global_init(); mk_lang_check_rereturn(err);
	err = mk_lang_command_line_parse_std(std_argc, std_argv, &argv[0], &lens[0], mk_lang_countof(argv), &argc); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_global_main(argc, &argv[0], &lens[0]);
	err = mk_clib_app_iip_global_deinit(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_extern_c mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_iip_args(mk_lang_types_sint_t const std_argc, mk_lang_types_pchar_pcpct const std_argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err_b;
	mk_lang_types_sint_t err;

	err_b = mk_clib_app_iip_args_2(std_argc, std_argv);
	if(err_b == 0)
	{
		err = mk_lang_stdout_println_lit_n("Gud."); mk_lang_check_rereturn(err);
	}
	else
	{
		err = mk_lang_stdout_println_lit_n("Bad."); mk_lang_check_rereturn(err);
	}
	mk_lang_check_rereturn(err_b);
	return 0;
}


#endif


#endif
